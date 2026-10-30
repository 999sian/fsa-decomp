// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800275d8-0x80027638 (1 functions). split_file divides it into the game's real files.

extern "C" void fn_801E0DB8(void* arr, void* ctor, void* dtor, unsigned int size, unsigned int n);
extern "C" void fn_80026E50(void);
extern "C" void fn_80026E54(void);
extern "C" void fn_80025170(void);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);
extern char lbl_802BB924[];
extern char lbl_802BB918[];
extern "C" void fn_800275D8(void) {
    fn_801E0DB8(lbl_802BB924 + 0x40, (void*)fn_80026E50, (void*)fn_80026E54, 0xd4, 4);
    __register_global_object(lbl_802BB924, (void*)fn_80025170, lbl_802BB918);
}
