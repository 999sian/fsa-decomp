struct Vec3f_802D { float x, y, z; };
struct VObj_802D {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

extern "C" void fn_802D14DC(VObj_802D* p) {
    p->m7();
}

extern "C" void fn_801F132C(void*, int, int, void*);
extern "C" void fn_802D1508(char* this_, int a, int b) {
    fn_801F132C(this_, a, b, this_ + 0x248);
}

extern "C" char lbl_804A9428[];
extern "C" Vec3f_802D lbl_804C0EA0;
extern "C" unsigned int lbl_8053AB68;
extern "C" unsigned int fn_8022461C(void*, unsigned int);
extern "C" void fn_801EE434(void*);
extern "C" void __dt__5ActorFv(void*, int);
void operator delete(void*);
extern "C" void* fn_802D26F8(void* this_, short freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)this_ = lbl_804A9428;
        if ((unsigned short)fn_8022461C(p + 0xc, *(unsigned int*)(p + 4)) != 0xd) {
            lbl_804C0EA0.x = *(float*)(p + 0xc);
            lbl_804C0EA0.y = *(float*)(p + 0x10);
            lbl_804C0EA0.z = *(float*)(p + 0x14);
            lbl_8053AB68 = *(unsigned int*)(p + 4);
        }
        void* h = *(void**)(p + 0x230);
        if (h != 0) {
            fn_801EE434(h);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

