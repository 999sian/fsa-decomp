

extern "C" void fn_8022CA6C(int a, int b, int c);
extern "C" void fn_8022CDD4(int a);
extern "C" void fn_80134FE0(void* p, int b);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* p);
extern void* lbl_804A7BE8[];
extern void* lbl_8053AAF8;
extern "C" void* fn_8029CF44(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A7BE8;
        if (*(unsigned char*)((char*)this_ + 0x244) == 0) {
            if (*(int*)((char*)this_ + 0x240) != *(int*)((char*)this_ + 0x23c)) {
                fn_8022CA6C(*(int*)((char*)this_ + 0x90) & 3, *(int*)((char*)this_ + 0x23c), 1);
            }
        }
        if (*(unsigned char*)((char*)lbl_8053AAF8 + 0x7e) == 0) {
            fn_80134FE0(lbl_8053AAF8, 0);
        }
        fn_8022CDD4(*(int*)((char*)this_ + 0x90) & 3);
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
