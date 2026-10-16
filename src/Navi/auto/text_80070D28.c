// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80070d28-0x80070d78 (1 functions). split_file divides it into the game's real files.
extern char lbl_80280CEC[];
extern char lbl_802C4E50[];
extern char lbl_802C4E5C[];
extern "C" void fn_80070CE0(void*);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);

extern "C" void fn_80070D28(void) {
    *(void**)lbl_802C4E5C = lbl_80280CEC;
    lbl_802C4E5C[4] = -1;
    *(int*)(lbl_802C4E5C + 8) = 0;
    __register_global_object(lbl_802C4E5C, (void*)fn_80070CE0, lbl_802C4E50);
}
