// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8011695c-0x80116a14 (1 functions). split_file divides it into the game's real files.

extern "C" void* __register_global_object(void* obj, void* dtor, void* reg);
extern "C" void fn_80111E64(void);
extern "C" char lbl_802C5F38[];
extern "C" short lbl_802FF240;
extern "C" short lbl_802FF244;
extern "C" short lbl_802FF248;
extern "C" short lbl_802FF24C;
extern "C" short lbl_802FF250;
extern "C" void fn_8011695C(void) {
    char* p = (char*)&lbl_802C5F38;
    lbl_802FF240 = 0;
    __register_global_object(&lbl_802FF240, (void*)fn_80111E64, p + 0x0);
    lbl_802FF244 = 0xb6;
    __register_global_object(&lbl_802FF244, (void*)fn_80111E64, p + 0xc);
    lbl_802FF248 = 0x4000;
    __register_global_object(&lbl_802FF248, (void*)fn_80111E64, p + 0x18);
    lbl_802FF24C = -0x8000;
    __register_global_object(&lbl_802FF24C, (void*)fn_80111E64, p + 0x24);
    lbl_802FF250 = -0x4000;
    __register_global_object(&lbl_802FF250, (void*)fn_80111E64, p + 0x30);
}
