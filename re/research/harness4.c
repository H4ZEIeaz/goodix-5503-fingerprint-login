// Vendor-matcher genuine/impostor test via the correspondence-count metric.
// Enrolls testset/enroll/*.raw into a template, then for each probe reads the
// MAX correspondence count (vendor matcher's own discrimination signal) via a
// breakpoint at the cmp $0x4,%edi in FUN_18009f4a0 (RVA 0x9f79f, EDI=count).
//   wine harness4.exe
#include <windows.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

typedef int(*fn_ppp)(int); typedef int(*fn_mode)(int); typedef void(*fn_ppi)(void*);
typedef void(*fn_pre)(void*,void*,void*,void*,void*,unsigned*,char);
typedef void*(*fn_estart)(int*); typedef void(*fn_eadd)(void*,void*,void*,void*,unsigned*);
typedef int(*fn_eget)(void*,void**);
typedef void(*fn_idf)(void*,void*,void*,unsigned,unsigned*,int*,unsigned*,int,char,uint64_t);
typedef int(*fn_load)(void*,unsigned);

static HMODULE H;
static void* R(const char* n){ return (void*)GetProcAddress(H,n); }
#define PTR(d)(*(void**)((d)+0x00))
#define DIMA(d)(*(short*)((d)+0x08))
#define DIMB(d)(*(short*)((d)+0x0a))
#define FMT(d)(*(char*)((d)+0x0e))
#define CH(d)(*(char*)((d)+0x0f))
#define LEN(d)(*(int*)((d)+0x14))
#define FCNT(d)(*(short*)((d)+0x18))
#define IDXF(d)(*(int*)((d)+0x1c))
#define NPX 5120

static fn_pre preprocessor;
static uint8_t outbufs[64][NPX]; static int nout=0;

// --- correspondence-count breakpoint (RVA 0x9f79f, EDI = count) ---
static void* g_bp; static unsigned char g_orig; static int g_maxcorr=-1;
LONG CALLBACK veh(EXCEPTION_POINTERS* ep){
    DWORD c=ep->ExceptionRecord->ExceptionCode;
    if(c==EXCEPTION_BREAKPOINT && ep->ExceptionRecord->ExceptionAddress==g_bp){
        int v=(int)ep->ContextRecord->Rdi; if(v>g_maxcorr) g_maxcorr=v;
        DWORD o; VirtualProtect(g_bp,1,PAGE_EXECUTE_READWRITE,&o); *(unsigned char*)g_bp=g_orig; VirtualProtect(g_bp,1,o,&o);
        ep->ContextRecord->Rip=(DWORD64)g_bp; ep->ContextRecord->EFlags|=0x100; return EXCEPTION_CONTINUE_EXECUTION;
    }
    if(c==EXCEPTION_SINGLE_STEP){ DWORD o; VirtualProtect(g_bp,1,PAGE_EXECUTE_READWRITE,&o); *(unsigned char*)g_bp=0xCC; VirtualProtect(g_bp,1,o,&o); return EXCEPTION_CONTINUE_EXECUTION; }
    return EXCEPTION_CONTINUE_SEARCH;
}

static int preprocess_file(const char* path, uint8_t* out, int idx){
    static uint16_t raw[NPX];
    FILE* f=fopen(path,"rb"); if(!f) return 0; size_t n=fread(raw,2,NPX,f); fclose(f);
    if(n!=NPX) return 0;
    uint8_t in[0x40]; memset(in,0,0x40);
    PTR(in)=raw; DIMA(in)=64; DIMB(in)=80; FMT(in)=16; CH(in)=1; LEN(in)=NPX*2; FCNT(in)=1; IDXF(in)=idx;
    memset(out,0,0x40); uint8_t* ob=outbufs[nout%64]; nout++;
    PTR(out)=ob; DIMA(out)=64; DIMB(out)=80; FMT(out)=8; CH(out)=1; LEN(out)=NPX; FCNT(out)=1; IDXF(out)=idx;
    unsigned q[2]={0,0};
    static uint8_t sb2[65536],sb3[65536],sb4[65536];
    memset(sb2,0,sizeof sb2); memset(sb3,0,sizeof sb3); memset(sb4,0,sizeof sb4);
    preprocessor(in,sb2,sb3,sb4,out,q,0);
    return 1;
}

static int list_raws(const char* dir, char out[][256], int max){
    DIR* d=opendir(dir); if(!d) return 0; struct dirent* e; int n=0;
    while((e=readdir(d)) && n<max){ if(strstr(e->d_name,".raw")) snprintf(out[n++],256,"%s/%s",dir,e->d_name); }
    closedir(d); return n;
}

int cmp_int(const void* a, const void* b){ return *(int*)a-*(int*)b; }

int main(void){
    setvbuf(stdout,NULL,_IONBF,0);
    H=LoadLibraryA("GoodixEngineAdapter.dll"); if(!H){printf("load fail\n");return 1;}
    fn_ppp ppp=(fn_ppp)R("ppp_param_init"); fn_load load=(fn_load)R("preprocess_load_calidata");
    fn_mode sm=(fn_mode)R("preprocess_set_mode"); fn_ppi ppi=(fn_ppi)R("preprocessor_init");
    preprocessor=(fn_pre)R("preprocessor");
    fn_estart estart=(fn_estart)R("enrolStartEx"); fn_eadd eadd=(fn_eadd)R("enrolAddImage");
    fn_eget eget=(fn_eget)R("enrolGetTemplate"); fn_idf idf=(fn_idf)R("identifyImage");
    static uint16_t base[NPX]; FILE* bf=fopen("frames/base.raw","rb"); fread(base,2,NPX,bf); fclose(bf);
    static uint8_t blob[0x224b0]; FILE* bl=fopen("frames/calidata.blob","rb"); fread(blob,1,0x224b0,bl); fclose(bl);
    int rp=ppp(10); int rl=load(blob,0x224b0);
    uint8_t cfg[0x40]; memset(cfg,0,0x40); *(void**)(cfg+0x18)=base; *(int*)(cfg+0x24)=64; *(int*)(cfg+0x28)=80;
    ppi(cfg); sm(1);
    printf("init: ppp=%d load=%d\n", rp, rl);

    // ---- enroll ----
    static char ef[64][256]; int ne=list_raws("testset/enroll",ef,64);
    int maxt=50; void* sess=estart(&maxt);
    for(int i=0;i<ne;i++){ uint8_t d[0x40]; if(preprocess_file(ef[i],d,i)){ unsigned st[2]={0,0}; eadd(sess,d,0,0,st); } }
    void* tmpl=0; eget(sess,&tmpl);
    void* at=*(void**)tmpl; int filled=at?*(int*)((unsigned char*)at+0x1c):-1;
    printf("enrolled %d frames -> template nodes FILLED=%d\n", ne, filled);
    void* cand[1]={tmpl};

    // arm BP
    AddVectoredExceptionHandler(1,veh);
    g_bp=(unsigned char*)H+0x9f79f; DWORD o; VirtualProtect(g_bp,1,PAGE_EXECUTE_READWRITE,&o);
    g_orig=*(unsigned char*)g_bp; *(unsigned char*)g_bp=0xCC; VirtualProtect(g_bp,1,o,&o);

    // ---- probe both sets ----
    char gf[64][256],imf[64][256]; int ng=list_raws("testset/genuine",gf,64), ni=list_raws("testset/impostor",imf,64);
    int gcorr[64], icorr[64];
    printf("\n-- GENUINE probes (same thumb) --\n");
    for(int i=0;i<ng;i++){ uint8_t d[0x40]; if(!preprocess_file(gf[i],d,1000+i)){gcorr[i]=-1;continue;}
        unsigned sc=0,o7=0; int mf=0; g_maxcorr=-1; idf(d,0,cand,1,&sc,&mf,&o7,0,0,0);
        gcorr[i]=g_maxcorr; printf("  genuine %2d: corr=%d\n", i, g_maxcorr); }
    printf("\n-- IMPOSTOR probes (other fingers) --\n");
    for(int i=0;i<ni;i++){ uint8_t d[0x40]; if(!preprocess_file(imf[i],d,2000+i)){icorr[i]=-1;continue;}
        unsigned sc=0,o7=0; int mf=0; g_maxcorr=-1; idf(d,0,cand,1,&sc,&mf,&o7,0,0,0);
        icorr[i]=g_maxcorr; printf("  impostor %2d: corr=%d\n", i, g_maxcorr); }

    // summary
    qsort(gcorr,ng,sizeof(int),cmp_int); qsort(icorr,ni,sizeof(int),cmp_int);
    printf("\n=== SUMMARY (correspondence count) ===\n");
    printf("genuine : min=%d max=%d  (sorted:", gcorr[0], gcorr[ng-1]); for(int i=0;i<ng;i++)printf(" %d",gcorr[i]); printf(")\n");
    printf("impostor: min=%d max=%d  (sorted:", icorr[0], icorr[ni-1]); for(int i=0;i<ni;i++)printf(" %d",icorr[i]); printf(")\n");
    printf("=> %s (genuine_max=%d vs impostor_max=%d)\n",
        gcorr[ng-1]>icorr[ni-1]?"SEPARATED at top":"overlap", gcorr[ng-1], icorr[ni-1]);
    return 0;
}
