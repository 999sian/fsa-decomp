// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801663e0-0x80166424 (1 functions). split_file divides it into the game's real files.

extern char lbl_802EE334[];
extern char lbl_802EE328[];
extern "C" void fn_80166C70(void*);
extern "C" void fn_80166424(void*);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);
extern "C" void fn_801663E0(void) {
    fn_80166C70(&lbl_802EE334);
    __register_global_object(&lbl_802EE334, (void*)fn_80166424, &lbl_802EE328);
}
