

extern "C" void __dt__5ActorFv(void* this_, int how);
void operator delete(void* p);
extern "C" char lbl_804AD1C8[];
extern "C" void* fn_803567AC(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AD1C8;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" char lbl_80472390[];
extern "C" float lbl_805427E4;
extern "C" void fn_801F06F0(void* this_, void* p2, int p3, int p4, int p5, float f6, float f7);
extern "C" void fn_80307AC8(void* obj, unsigned int id, void* pos, int kind, unsigned int a, unsigned int b, int c);
struct FsaTblEntry {
    int m0;
    int m4;
    char* m8;
    char* mc;
};

struct FsaPoolEntry {
    int flag;
    int mem;
};

extern "C" void fn_80356A24(char* this_) {
    char* base = lbl_80472390;
    int mode = *(int*)(this_ + 0x230);
    if (mode != 2) {
        int idx = *(int*)(this_ + 0x250);
        int off = idx * 8;
        char* pool = base + 0xb0;
        char* res = base + 0x11c;
        int val;
        if (*(int*)(pool + off) == 1) {
            res = base + 0x108;
        }
        if (mode == 0 || (unsigned int)(mode - 3) <= 1 || mode == 1) {
            int a248 = *(int*)(this_ + 0x248);
            int a238 = *(int*)(this_ + 0x238);
            char* tbl = ((char**)(base + idx * 16))[2];
            val = *(int*)(pool + off + 4) + *(int*)(tbl + a248 * 16 + a238 * 4);
        } else {
            int a248 = *(int*)(this_ + 0x248);
            int a238 = *(int*)(this_ + 0x238);
            char* tbl = ((char**)(base + idx * 16))[3];
            val = *(int*)(pool + off + 4) + *(int*)(tbl + a248 * 16 + a238 * 4);
        }
        fn_801F06F0(this_, res, val, 0, 0, lbl_805427E4, lbl_805427E4);
        if (*(int*)(this_ + 0x250) == 5) {
            fn_80307AC8(*(void**)(this_ + 0x198), *(unsigned int*)(this_ + 4), this_ + 0xc, val, 0, 0, -1);
        }
    }
}

