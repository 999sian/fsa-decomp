// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80030740-0x80030778 (1 functions). split_file divides it into the game's real files.

extern "C" void __register_global_object(void*, void*, void*);
extern "C" void fn_8000CEC4(void);
extern char lbl_802BEDF4[];
extern char lbl_802BEDE8[];
extern "C" void fn_80030740(void) {
    __register_global_object(lbl_802BEDF4, (void*)fn_8000CEC4, lbl_802BEDE8);
}
