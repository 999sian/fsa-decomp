// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8015ffac-0x8015fff0 (1 functions). split_file divides it into the game's real files.

extern char lbl_802EE2D4[];
extern char lbl_802EE2C8[];
extern "C" void fn_80166C70(void*);
extern "C" void fn_8015FFF0(void*);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);
extern "C" void fn_8015FFAC(void) {
    fn_80166C70(&lbl_802EE2D4);
    __register_global_object(&lbl_802EE2D4, (void*)fn_8015FFF0, &lbl_802EE2C8);
}
