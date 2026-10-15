// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8015f638-0x8015f67c (1 functions). split_file divides it into the game's real files.

extern char lbl_802EE2A4[];
extern char lbl_802EE298[];
extern "C" void fn_80166C70(void*);
extern "C" void fn_8015EABC(void*);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);
extern "C" void fn_8015F638(void) {
    fn_80166C70(&lbl_802EE2A4);
    __register_global_object(&lbl_802EE2A4, (void*)fn_8015EABC, &lbl_802EE298);
}
