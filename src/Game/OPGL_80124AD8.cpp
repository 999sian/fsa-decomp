

extern "C" void fn_80124B90(void* this_) {
    register void** vtable = (void**)*(void**)this_;
    typedef void (*method_t)(void*, int);
    register method_t method = (method_t)vtable[0x6c / sizeof(void*)];
    method(this_, 0x5);
}

extern "C" void fn_80124BC0(void* this_) {
    register void** vtable = (void**)*(void**)this_;
    typedef void (*method_t)(void*, int);
    method_t method = (method_t)vtable[0x6c / sizeof(void*)];
    method(this_, 0x7);
}

extern "C" void fn_80121DB0(void);
extern "C" void fn_80124C2C(void) {
    fn_80121DB0();
}

