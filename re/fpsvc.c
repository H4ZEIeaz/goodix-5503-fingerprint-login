// fpsvc: Goodix vendor matcher under Wine. usage: fpsvc enroll <dir> | verify <probe.raw> | serve
#include <windows.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <io.h>

typedef int(*fn_i)(int); typedef void(*fn_ppi)(void*);
typedef void(*fn_pre)(void*,void*,void*,void*,void*,unsigned*,char);
typedef void*(*fn_es)(int*); typedef void(*fn_ea)(void*,void*,void*,void*,unsigned*);
typedef int(*fn_eg)(void*,void**);
typedef void(*fn_idf)(void*,void*,void*,unsigned,unsigned*,int*,unsigned*,int,char,uint64_t);
typedef int(*fn_tsz)(void*); typedef void(*fn_tp)(void*,void*); typedef void(*fn_tu)(void*,int,void*,void**);
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

// correspondence-count breakpoint (RVA 0x9f79f, EDI=count)
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
static void arm_bp(void){
    AddVectoredExceptionHandler(1,veh);
    g_bp=(unsigned char*)H+0x9f79f; DWORD o; VirtualProtect(g_bp,1,PAGE_EXECUTE_READWRITE,&o);
    g_orig=*(unsigned char*)g_bp; *(unsigned char*)g_bp=0xCC; VirtualProtect(g_bp,1,o,&o);
}

static void preprocess_buffer(const uint16_t* raw, uint8_t* out, int idx){
    uint8_t in[0x40]; memset(in,0,0x40);
    PTR(in)=(void*)raw; DIMA(in)=64; DIMB(in)=80; FMT(in)=16; CH(in)=1; LEN(in)=NPX*2; FCNT(in)=1; IDXF(in)=idx;
    memset(out,0,0x40); uint8_t* ob=outbufs[nout%64]; nout++;
    PTR(out)=ob; DIMA(out)=64; DIMB(out)=80; FMT(out)=8; CH(out)=1; LEN(out)=NPX; FCNT(out)=1; IDXF(out)=idx;
    unsigned q[2]={0,0};
    static uint8_t sb2[65536],sb3[65536],sb4[65536];
    memset(sb2,0,sizeof sb2); memset(sb3,0,sizeof sb3); memset(sb4,0,sizeof sb4);
    preprocessor(in,sb2,sb3,sb4,out,q,0);
}
static int preprocess_file(const char* path, uint8_t* out, int idx){
    static uint16_t raw[NPX];
    FILE* f=fopen(path,"rb"); if(!f) return 0; size_t n=fread(raw,2,NPX,f); fclose(f);
    if(n!=NPX) return 0;
    preprocess_buffer(raw,out,idx); return 1;
}

static fn_i ppp,sm; static fn_ppi ppi; static fn_load load;
static void init(void){
    ppp=(fn_i)R("ppp_param_init"); load=(fn_load)R("preprocess_load_calidata");
    sm=(fn_i)R("preprocess_set_mode"); ppi=(fn_ppi)R("preprocessor_init"); preprocessor=(fn_pre)R("preprocessor");
    static uint16_t base[NPX]; FILE* bf=fopen("frames/base.raw","rb"); fread(base,2,NPX,bf); fclose(bf);
    static uint8_t blob[0x224b0]; FILE* bl=fopen("frames/calidata.blob","rb"); fread(blob,1,0x224b0,bl); fclose(bl);
    ppp(10); load(blob,0x224b0);
    uint8_t cfg[0x40]; memset(cfg,0,0x40); *(void**)(cfg+0x18)=base; *(int*)(cfg+0x24)=64; *(int*)(cfg+0x28)=80;
    ppi(cfg); sm(1);
}

static const char* tmpl_path(void){ const char* t=getenv("FP_TEMPLATE"); return t?t:"template.bin"; }

int main(int argc, char** argv){
    setvbuf(stdout,NULL,_IONBF,0);
    if(argc<2){ printf("usage: fpsvc enroll <dir> | verify <probe.raw> | serve\n"); return 2; }
    H=LoadLibraryA("GoodixEngineAdapter.dll"); if(!H){ printf("ERROR load dll\n"); return 1; }
    init();

    if(!strcmp(argv[1],"serve")){
        fn_tu tu=(fn_tu)R("templateUnPack"); fn_idf idf=(fn_idf)R("identifyImage");
        FILE* tf=fopen(tmpl_path(),"rb"); if(!tf){ printf("ERROR no template %s\n",tmpl_path()); fflush(stdout); return 1; }
        int sz=0; fread(&sz,4,1,tf); uint8_t* buf=malloc(sz); fread(buf,1,sz,tf); fclose(tf);
        void* tmpl=0; tu(buf,sz,0,&tmpl); if(!tmpl){ printf("ERROR unpack\n"); fflush(stdout); return 1; }
        void* cand[1]={tmpl}; arm_bp();
        int thr=getenv("FP_THRESHOLD")?atoi(getenv("FP_THRESHOLD")):3;
        _setmode(_fileno(stdin),_O_BINARY);
        printf("READY\n"); fflush(stdout);
        static uint16_t raw[NPX]; int idx=5000;
        while(fread(raw,2,NPX,stdin)==NPX){
            uint8_t dd[0x40]; preprocess_buffer(raw,dd,idx++);
            unsigned sc=0,o7=0; int mf=0; g_maxcorr=-1;
            idf(dd,0,cand,1,&sc,&mf,&o7,0,0,0);
            printf("RESULT corr=%d verdict=%s\n", g_maxcorr, g_maxcorr>=thr?"ACCEPT":"REJECT");
            fflush(stdout);
        }
        return 0;
    }
    if(argc<3){ printf("usage: fpsvc enroll <dir> | verify <probe.raw> | serve\n"); return 2; }

    if(!strcmp(argv[1],"enroll")){
        fn_es es=(fn_es)R("enrolStartEx"); fn_ea ea=(fn_ea)R("enrolAddImage");
        fn_eg eg=(fn_eg)R("enrolGetTemplate"); fn_tsz tsz=(fn_tsz)R("templateGetPackedSize"); fn_tp tp=(fn_tp)R("templatePack");
        int maxt=50; void* sess=es(&maxt);
        DIR* d=opendir(argv[2]); if(!d){ printf("ERROR opendir %s\n",argv[2]); return 1; }
        struct dirent* e; int n=0; char p[512];
        while((e=readdir(d))){ if(!strstr(e->d_name,".raw")) continue;
            snprintf(p,sizeof p,"%s/%s",argv[2],e->d_name);
            uint8_t dd[0x40]; if(preprocess_file(p,dd,n)){ unsigned st[2]={0,0}; ea(sess,dd,0,0,st); n++; } }
        closedir(d);
        void* tmpl=0; eg(sess,&tmpl);
        void* at=*(void**)tmpl; int filled=at?*(int*)((unsigned char*)at+0x1c):-1;
        int sz=tsz(tmpl); void* buf=malloc(sz); memset(buf,0,sz); tp(tmpl,buf);
        FILE* o=fopen(tmpl_path(),"wb"); fwrite(&sz,4,1,o); fwrite(buf,1,sz,o); fclose(o);
        printf("RESULT enrolled=%d nodes=%d template=%s size=%d\n", n, filled, tmpl_path(), sz);
        return 0;
    }
    if(!strcmp(argv[1],"verify")){
        fn_tu tu=(fn_tu)R("templateUnPack"); fn_idf idf=(fn_idf)R("identifyImage");
        FILE* tf=fopen(tmpl_path(),"rb"); if(!tf){ printf("ERROR no template %s\n",tmpl_path()); return 1; }
        int sz=0; fread(&sz,4,1,tf); uint8_t* buf=malloc(sz); fread(buf,1,sz,tf); fclose(tf);
        void* tmpl=0; tu(buf,sz,0,&tmpl); if(!tmpl){ printf("ERROR unpack\n"); return 1; }
        void* cand[1]={tmpl};
        uint8_t dd[0x40]; if(!preprocess_file(argv[2],dd,1000)){ printf("ERROR preprocess %s\n",argv[2]); return 1; }
        arm_bp();
        unsigned sc=0,o7=0; int mf=0; g_maxcorr=-1;
        idf(dd,0,cand,1,&sc,&mf,&o7,0,0,0);
        int thr=getenv("FP_THRESHOLD")?atoi(getenv("FP_THRESHOLD")):3;
        printf("RESULT corr=%d threshold=%d verdict=%s\n", g_maxcorr, thr, g_maxcorr>=thr?"ACCEPT":"REJECT");
        return 0;
    }
    printf("usage: fpsvc enroll <dir> | verify <probe.raw> | serve\n"); return 2;
}
