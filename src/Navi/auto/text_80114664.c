// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80114664-0x801146e4 (1 functions). split_file divides it into the game's real files.

extern "C" void __register_global_object(void*, void*, void*);
extern "C" void fn_8000CEC4(void);
extern "C" void* fn_80111CDC(void*);
extern "C" void fn_8011461C(void);
extern char lbl_802C5B90[];
extern "C" void fn_80114664(void) {
    char* p = (char*)&lbl_802C5B90;
    __register_global_object(p + 0x24, (void*)fn_8000CEC4, p + 0x18);
    __register_global_object(p + 0x3c, (void*)fn_8000CEC4, p + 0x30);
    __register_global_object(p + 0x54, (void*)fn_8000CEC4, p + 0x48);
    __register_global_object(fn_80111CDC(p + 0x6c), (void*)fn_8011461C, p + 0x60);
}
__declspec(section ".ctors") void (*lbl_801F0CD4)(void) = fn_80114664;
