

extern "C" void fn_80124AD8(void* this_) {
    register void** vtable = (void**)*(void**)this_;
    typedef void (*method_t)(void*, int);
    method_t method = (method_t)vtable[0x6c / sizeof(void*)];
    method(this_, 0x9);
}

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

extern "C" void fn_8012562C(void* this_) {
    char* p = (char*)this_;
    *(unsigned int*)(p + 0x35c) = *(unsigned int*)(p + 0x90) & 0xFF;
    *(unsigned int*)(p + 0x3cc) = (*(unsigned int*)(p + 0x90) >> 22) & 0x1F;
}

extern "C" void fn_80124448(void*);
extern "C" int fn_8012285C(void*);
extern "C" float fn_80121DC8(void*, int);
extern float lbl_8053CA6C;
extern "C" void fn_80125858(void* s)
{
  fn_80124448(s);
}

