// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800868f4-0x80086930 (1 functions). split_file divides it into the game's real files.

extern char lbl_802C5144[];
extern char lbl_802C5138[];
extern "C" void* fn_8008065C(void* p);
extern "C" void fn_80086880(void* p, short param_2);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);
extern "C" void fn_800868F4(void) {
    __register_global_object(fn_8008065C(lbl_802C5144), (void*)fn_80086880, lbl_802C5138);
}
