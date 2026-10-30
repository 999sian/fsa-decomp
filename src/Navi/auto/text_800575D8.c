// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800575d8-0x80057614 (1 functions). split_file divides it into the game's real files.

extern char lbl_802C050C[];
extern char lbl_802C0500[];
extern "C" void* fn_8004FA34(void* p);
extern "C" void fn_8005757C(void* p, short param_2);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);
extern "C" void fn_800575D8(void) {
    __register_global_object(fn_8004FA34(lbl_802C050C), (void*)fn_8005757C, lbl_802C0500);
}
