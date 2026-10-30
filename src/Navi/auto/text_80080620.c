// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80080620-0x8008065c (1 functions). split_file divides it into the game's real files.

extern char lbl_802C5024[];
extern char lbl_802C5018[];
extern "C" void* fn_8007BCD0(void* p);
extern "C" void fn_800805AC(void* p, short param_2);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);
extern "C" void fn_80080620(void) {
    __register_global_object(fn_8007BCD0(lbl_802C5024), (void*)fn_800805AC, lbl_802C5018);
}
