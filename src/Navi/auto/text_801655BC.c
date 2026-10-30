// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801655bc-0x80165600 (1 functions). split_file divides it into the game's real files.

extern char lbl_802EE304[];
extern char lbl_802EE2F8[];
extern "C" void fn_80166C70(void*);
extern "C" void fn_80165600(void*);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);
extern "C" void fn_801655BC(void) {
    fn_80166C70(&lbl_802EE304);
    __register_global_object(&lbl_802EE304, (void*)fn_80165600, &lbl_802EE2F8);
}
