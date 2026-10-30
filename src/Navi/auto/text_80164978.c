// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80164978-0x801649bc (1 functions). split_file divides it into the game's real files.

extern char lbl_802EE2EC[];
extern char lbl_802EE2E0[];
extern "C" void fn_80166C70(void*);
extern "C" void fn_801649BC(void*);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);
extern "C" void fn_80164978(void) {
    fn_80166C70(&lbl_802EE2EC);
    __register_global_object(&lbl_802EE2EC, (void*)fn_801649BC, &lbl_802EE2E0);
}
