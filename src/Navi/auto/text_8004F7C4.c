// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8004f7c4-0x8004f844 (1 functions). split_file divides it into the game's real files.

extern char lbl_802C01B4[];
extern char lbl_802C01A8[];
extern void* lbl_80222428[];
extern void* lbl_80247684[];
extern "C" void fn_801E0DB8(void* arr, void* ctor, void* dtor, unsigned int size, unsigned int n);
extern "C" void fn_8004F6C4(void);
extern "C" void fn_8004F77C(void);
extern "C" void fn_8004F844(void);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);
extern "C" void fn_8004F7C4(void) {
    void** obj = (void**)lbl_802C01B4;
    *obj = lbl_80222428;
    *obj = lbl_80247684;
    fn_801E0DB8((char*)obj + 8, (void*)fn_8004F6C4, (void*)fn_8004F77C, 0x90, 5);
    __register_global_object(obj, (void*)fn_8004F844, lbl_802C01A8);
}
