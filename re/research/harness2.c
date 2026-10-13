// Full enroll/identify harness for the Goodix vendor algorithm under Wine.
// build: x86_64-w64-mingw32-gcc harness2.c -o harness2.exe
// run:   wine harness2.exe
#include <windows.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// --- logger hook: the DLL's logger FUN_180057ac0 (RVA 0x57ac0) is a stub.
// We overwrite it with a jump to our hook which prints the format string (RCX),
// giving the DLL's own decision log during enroll/identify.
static FILE* g_logf;
#include <stdarg.h>
__attribute__((ms_abi)) void my_log_hook(const char* fmt, ...){
    if(!g_logf || !fmt) return;
    va_list ap; va_start(ap, fmt);
    char buf[1024]; vsnprintf(buf, sizeof buf, fmt, ap);
    va_end(ap);
    fprintf(g_logf, "%s\n", buf); fflush(g_logf);
}
// --- breakpoint to read iVar14 (correspondence count) at the cmp $0x4,%edi ---
static void* g_bp;           // RVA 0x9faef (FUN_18009bf60 output = R13D)
static unsigned char g_orig;
static int g_last_corr=-1, g_geo_pass=0, g_geo_total=0;
LONG CALLBACK veh(EXCEPTION_POINTERS* ep){
    DWORD code=ep->ExceptionRecord->ExceptionCode;
    if(code==EXCEPTION_BREAKPOINT && ep->ExceptionRecord->ExceptionAddress==g_bp){
        int r13=(int)ep->ContextRecord->R13;     // FUN_18009bf60 geometric result
        g_geo_total++; if(r13==1) g_geo_pass++;
        if(r13>g_last_corr) g_last_corr=r13;
        if(g_logf){ fprintf(g_logf,">>> [BP] FUN_18009bf60 geo result R13D = %d\n", r13); fflush(g_logf); }
        DWORD old; VirtualProtect(g_bp,1,PAGE_EXECUTE_READWRITE,&old);
        *(unsigned char*)g_bp=g_orig; VirtualProtect(g_bp,1,old,&old);
        ep->ContextRecord->Rip=(DWORD64)g_bp;          // re-execute original cmp
        ep->ContextRecord->EFlags |= 0x100;            // single-step to re-arm
        return EXCEPTION_CONTINUE_EXECUTION;
    }
    if(code==EXCEPTION_SINGLE_STEP){
        DWORD old; VirtualProtect(g_bp,1,PAGE_EXECUTE_READWRITE,&old);
        *(unsigned char*)g_bp=0xCC; VirtualProtect(g_bp,1,old,&old);  // re-arm INT3
        return EXCEPTION_CONTINUE_EXECUTION;
    }
    return EXCEPTION_CONTINUE_SEARCH;
}
static void install_bp(HMODULE H){
    AddVectoredExceptionHandler(1, veh);
    g_bp=(unsigned char*)H + 0x9faef;
    DWORD old; VirtualProtect(g_bp,1,PAGE_EXECUTE_READWRITE,&old);
    g_orig=*(unsigned char*)g_bp; *(unsigned char*)g_bp=0xCC; VirtualProtect(g_bp,1,old,&old);
}

static void install_log_hook(HMODULE H){
    g_logf=fopen("dll_log.txt","w");
    unsigned char* lg=(unsigned char*)H + 0x57ac0;
    DWORD old; VirtualProtect(lg,16,PAGE_EXECUTE_READWRITE,&old);
    lg[0]=0x48; lg[1]=0xB8; *(void**)(lg+2)=(void*)my_log_hook;  // mov rax,hook
    lg[10]=0xFF; lg[11]=0xE0;                                     // jmp rax
    VirtualProtect(lg,16,old,&old);
}

typedef int   (*fn_ppp)(int);
typedef int   (*fn_v)(void);
typedef int   (*fn_mode)(int);
typedef void  (*fn_ppi)(void*);
typedef void  (*fn_pre)(void*, void*, void*, void*, void*, unsigned*, char);
typedef void* (*fn_estart)(int*);
typedef void  (*fn_eadd)(void*, void*, void*, void*, unsigned*);
typedef int   (*fn_eget)(void*, void**);
typedef int   (*fn_efin)(void**);
typedef void  (*fn_idf)(void*, void*, void*, unsigned, unsigned*, int*, unsigned*, int, char, uint64_t);
typedef void  (*fn_q)(void*, int*);

static HMODULE H;
static void* R(const char* n){ void* p=(void*)GetProcAddress(H,n); if(!p) printf("[!]%s MISSING\n",n); return p; }

// descriptor field accessors (offsets from decompilation)
#define PTR(d)  (*(void**)((d)+0x00))
#define DIMA(d) (*(short*)((d)+0x08))
#define DIMB(d) (*(short*)((d)+0x0a))
#define FMT(d)  (*(char*)((d)+0x0e))
#define CH(d)   (*(char*)((d)+0x0f))
#define LEN(d)  (*(int*)((d)+0x14))
#define FCNT(d) (*(short*)((d)+0x18))
#define IDXF(d) (*(int*)((d)+0x1c))
#define QUAL(d) (*(uint8_t*)((d)+0x28))
#define COV(d)  (*(uint8_t*)((d)+0x29))

static fn_pre preprocessor;
#define NPX 5120
static uint8_t outbufs[32][NPX];
static int nout=0;

// load a raw uint16 frame, preprocess, fill an 8-bit out descriptor (0x40 bytes)
static int preprocess_file(const char* path, uint8_t* out /*0x40*/, int idx){
    static uint16_t raw[NPX];
    FILE* f=fopen(path,"rb"); if(!f){printf("open %s fail\n",path);return 0;}
    size_t n=fread(raw,2,NPX,f); fclose(f);
    if(n!=NPX){printf("short read %s (%zu)\n",path,n);return 0;}
    uint8_t in[0x40]; memset(in,0,0x40);
    PTR(in)=raw; DIMA(in)=64; DIMB(in)=80; FMT(in)=16; CH(in)=1; LEN(in)=NPX*2; FCNT(in)=1; IDXF(in)=idx;
    memset(out,0,0x40);
    uint8_t* ob=outbufs[nout++];
    PTR(out)=ob; DIMA(out)=64; DIMB(out)=80; FMT(out)=8; CH(out)=1; LEN(out)=atoi(getenv("OUTLEN")?getenv("OUTLEN"):"3216"); FCNT(out)=1; IDXF(out)=idx;
    unsigned q[2]={0,0};
    static uint8_t sb2[65536],sb3[65536],sb4[65536];
    memset(sb2,0,sizeof sb2); memset(sb3,0,sizeof sb3); memset(sb4,0,sizeof sb4);
    preprocessor(in,sb2,sb3,sb4,out,q,0);
    printf("   preprocess %s: q=%u cov=%u | descQ=%u descCov=%u\n",path,q[0],q[1],QUAL(out),COV(out));
    if(getenv("DUMPIMG")){   // dump each preprocessed out image by idx
        char fn[64]; sprintf(fn,"pp_idx%d.raw",idx);
        FILE* o=fopen(fn,"wb"); fwrite(ob,1,NPX,o); fclose(o);
    }
    return 1;
}

int main(void){
    setvbuf(stdout,NULL,_IONBF,0);
    H=LoadLibraryA("GoodixEngineAdapter.dll");
    if(!H){printf("load fail %lu\n",GetLastError());return 1;} printf("DLLBASE %p\n",(void*)H);
    install_log_hook(H);
    fn_ppp ppp=(fn_ppp)R("ppp_param_init");
    fn_v cdi=(fn_v)R("preprocess_init_calidata");
    fn_mode sm=(fn_mode)R("preprocess_set_mode");
    fn_ppi ppi=(fn_ppi)R("preprocessor_init");
    preprocessor=(fn_pre)R("preprocessor");
    fn_estart estart=(fn_estart)R("enrolStartEx");
    fn_eadd eadd=(fn_eadd)R("enrolAddImage");
    fn_eget eget=(fn_eget)R("enrolGetTemplate");
    fn_efin efin=(fn_efin)R("enrolFinish");
    fn_idf idf=(fn_idf)R("identifyImage");

    printf("ppp(10)=%d\n", ppp(10));
    // load the full calibration blob (base frames + CRC + version)
    typedef int (*fn_load)(void*, unsigned);
    fn_load load=(fn_load)R("preprocess_load_calidata");
    static uint8_t blob[0x224b0];
    FILE* bl=fopen("frames/calidata.blob","rb"); fread(blob,1,0x224b0,bl); fclose(bl);
    printf("load_calidata -> %d\n", load(blob,0x224b0));
    // base frame for preprocessor_init
    static uint16_t base[NPX];
    FILE* bf=fopen("frames/base.raw","rb"); fread(base,2,NPX,bf); fclose(bf);
    uint8_t cfg[0x40]; memset(cfg,0,0x40);
    *(void**)(cfg+0x18)=base; *(int*)(cfg+0x24)=64; *(int*)(cfg+0x28)=80;
    ppi(cfg);
    printf("mode=%d\n", sm(1));     // set mode AFTER preprocessor_init
    printf("init done.\n");

    // ---- determinism check: preprocess the same frame twice, compare ----
    {
        uint8_t d1[0x40], d2[0x40];
        preprocess_file("frames/enroll/0.raw", d1, 0);
        uint8_t* b1 = (uint8_t*)PTR(d1);
        uint8_t save[NPX]; memcpy(save, b1, NPX);
        preprocess_file("frames/enroll/0.raw", d2, 0);
        uint8_t* b2 = (uint8_t*)PTR(d2);
        int diff=0, lastdiff=-1;
        for(int i=0;i<NPX;i++){ if(save[i]!=b2[i]){diff++; lastdiff=i;} }
        printf(">>> DETERMINISM: %d/%d bytes differ, last diff at %d\n", diff, NPX, lastdiff);
    }

    // ---- enroll 8 thumb frames ----
    int maxt=50; void* sess=estart(&maxt);
    printf("enrolStartEx -> sess=%p maxt=%d\n", sess, maxt);
    if(!sess){printf("no session\n");return 1;}
    for(int i=0;i<1;i++){
        char p[128]; sprintf(p,"frames/probe/genuine2.raw");  // enroll ONLY genuine2
        uint8_t d[0x40];
        if(!preprocess_file(p,d,i)) continue;
        unsigned st[2]={0,0};
        eadd(sess,d,0,0,st);
        // progress stored at sess+0xc (from decomp)
        int prog=*(int*)((uint8_t*)sess+0xc);
        printf("  enrolAddImage[%d] st={%u,%u} progress=%d%%\n",i,st[0],st[1],prog);
    }
    void* tmpl=0; int gr=eget(sess,&tmpl);
    printf("enrolGetTemplate=%d tmpl=%p\n",gr,tmpl);
    if(!tmpl){printf("no template\n");return 1;}
    { void* node=*(void**)tmpl; printf(">>> template node ptr=%p\n",node); if(node){int*ni=(int*)node; printf(">>> node type=%d a1=%d a2=%d a3=%d a4=%d a5=%d\n",ni[0],ni[1],ni[2],ni[3],ni[4],ni[5]);} }

    // RESET preprocessor adaptive state before identify (enroll & verify are
    // separate sessions in the real driver; the preprocessor drifts per frame).
    if(getenv("RESET")){
        ppp(10); load(blob,0x224b0);
        uint8_t cfg2[0x40]; memset(cfg2,0,0x40);
        *(void**)(cfg2+0x18)=base; *(int*)(cfg2+0x24)=64; *(int*)(cfg2+0x28)=80;
        ppi(cfg2); sm(1);
        printf(">>> [dbg] preprocessor state RESET before identify\n");
    }

    // ---- identify probes ----
    void* cand[1]={tmpl};
    // first a SELF-MATCH sanity probe (an enrolled frame must match strongly)
    const char* probes[9]={"../enroll/0","genuine0","genuine1","genuine2","genuine3",
                           "impostor0","impostor1","impostor2","impostor3"};
    printf("\n--- identify (first probe = enrolled frame 0, self-match) ---\n");
    if(g_logf) fprintf(g_logf,"\n===== IDENTIFY PHASE STARTS =====\n");
    install_bp(H);   // arm the correspondence-count breakpoint
    if(getenv("FORCE_MATURE")){ void* at=*(void**)tmpl; if(at){ *(int*)((unsigned char*)at+0x8E00)=1; printf(">>> FORCED template maturity[0x2380]=1\n"); } }
    for(int i=0;i<9;i++){
        if(g_logf) fprintf(g_logf,"\n--- probe %d (%s) ---\n", i, probes[i]);
        char p[128]; sprintf(p,"frames/probe/%s.raw",probes[i]);
        if(probes[i][0]==0x2e) sprintf(p,"frames/probe/genuine2.raw");
        uint8_t d[0x40];
        if(!preprocess_file(p,d,100+i)) continue;
        unsigned score=0xffffffff, out7=0; int mf=-1;
        g_geo_pass=0; g_geo_total=0;
        idf(d,0,cand,1,&score,&mf,&out7,0,0,0);
        printf("  %-10s geo_pass=%d/%d  (raw match=%d)\n", probes[i], g_geo_pass, g_geo_total, mf);
        if(i==0){   // DYNAMIC INSPECTION after the self-match probe
            unsigned char* base=(unsigned char*)H;
            void* pf = *(void**)(base+0x153e80);     // probe feature container
            void* matched = *(void**)(base+0x153e88);
            printf(">>> [dbg] probe_feat(0x153e80)=%p  matched(0x153e88)=%p\n", pf, matched);
            if(pf){ unsigned char* p=(unsigned char*)pf; int* pi=(int*)pf;
                printf(">>> [dbg] probe_feat: dims=%dx%d  +0xf0(featcount?)=%d  +0xf8=%p\n",
                    pi[0],pi[1], *(int*)(p+0xf0), *(void**)(p+0xf8)); }
            void* at = *(void**)tmpl;                // actual_template
            if(at){ unsigned char* t=(unsigned char*)at;
                int ncount=*(int*)(t+0x20);
                int filled=*(int*)(t+0x1c);          // nodes actually added
                void* node0 = *(void**)(t+0x28);
                printf(">>> [dbg] template type=%d node_slots=%d FILLED=%d node0=%p\n", *(int*)t, ncount, filled, node0);
                printf(">>> [dbg] SCORING GATES: template[0x2380](maturity)=%d | probe[0x43](q)=%d probe[0x44](q)=%d probe[0x53]=%d\n",
                    *(int*)(t+0x8E00),
                    pf?*(int*)((unsigned char*)pf+0x10c):-999,
                    pf?*(int*)((unsigned char*)pf+0x110):-999,
                    pf?*(int*)((unsigned char*)pf+0x14c):-999);
                unsigned char* rb=(unsigned char*)H+0x153e90;  // lVar5 = matcher result buffer
                printf(">>> [dbg] result buf(0x153e90): +0x688(highconf)=%d +0x684=%d +0x644=%d +0x64c(maxscore)=%d +0x668=%d\n",
                    *(int*)(rb+0x688),*(int*)(rb+0x684),*(int*)(rb+0x644),*(int*)(rb+0x64c),*(int*)(rb+0x668));
                if(node0){ unsigned char* n=(unsigned char*)node0; int* ni=(int*)node0;
                    printf(">>> [dbg] node0 ints[0..18]:");
                    for(int k=0;k<18;k++) printf(" %d",ni[k]);
                    printf("\n>>> [dbg] node0 +0xf0=%d +0x104=%d +0x11c=%d\n",
                        *(int*)(n+0xf0),*(int*)(n+0x104),*(int*)(n+0x11c)); }
                // compare: probe feature data (first coords) vs ...
                if(pf){ unsigned char* p=(unsigned char*)pf; void* fdata=*(void**)(p+0xf8);
                    if(fdata){ short* fs=(short*)fdata; printf(">>> [dbg] probe first feats (shorts):");
                        for(int k=0;k<12;k++) printf(" %d",fs[k]); printf("\n"); } }
            }
        }
    }
    // --- MATURATION TEST: identify genuine2 repeatedly, watch template[0x2380] + score ---
    if(getenv("MATURE")){
        void* at=*(void**)tmpl;
        printf("\n=== maturation loop (identify genuine2 x25) ===\n");
        for(int r=0;r<25;r++){
            uint8_t d[0x40];
            if(!preprocess_file("frames/probe/genuine2.raw",d,200+r)) continue;
            unsigned score=0xffffffff,out7=0; int mf=-1; g_last_corr=-1;
            idf(d,0,cand,1,&score,&mf,&out7,0,0,0);
            int mat = at?*(int*)((unsigned char*)at+0x8E00):-1;
            printf("  iter %2d: corr=%-3d maturity[0x2380]=%d match=%d score=%u\n",r,g_last_corr,mat,mf,score);
        }
    }

    efin(&sess);
    printf("DONE\n");
    return 0;
}
