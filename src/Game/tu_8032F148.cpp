extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* p);
extern void* lbl_804AB8C0[];

extern "C" void* fn_803336B0(char* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AB8C0;
        fn_801EE434(*(void**)(this_ + 0x2f4));
        fn_801EE434(*(void**)(this_ + 0x2f8));
        fn_801EE434(*(void**)(this_ + 0x2fc));
        fn_801EE434(*(void**)(this_ + 0x300));
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
