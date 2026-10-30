// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8015eef4-0x8015ef38 (1 functions). split_file divides it into the game's real files.

extern char lbl_802EE28C[];
extern char lbl_802EE280[];
extern "C" void fn_80166C70(void*);
extern "C" void fn_8015EF38(void*);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);
extern "C" void fn_8015EEF4(void) {
    fn_80166C70(&lbl_802EE28C);
    __register_global_object(&lbl_802EE28C, (void*)fn_8015EF38, &lbl_802EE280);
}
