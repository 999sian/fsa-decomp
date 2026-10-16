// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8007bc94-0x8007bcd0 (1 functions). split_file divides it into the game's real files.

extern char lbl_802C4F3C[];
extern char lbl_802C4F30[];
extern "C" void* fn_80077DA0(void* p);
extern "C" void fn_8007BC20(void* p, short param_2);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);
extern "C" void fn_8007BC94(void) {
    __register_global_object(fn_80077DA0(lbl_802C4F3C), (void*)fn_8007BC20, lbl_802C4F30);
}
