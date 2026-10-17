// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800618fc-0x80061948 (1 functions). split_file divides it into the game's real files.

extern char lbl_8027EC78[];
extern char lbl_8027ED20[];
extern char lbl_802C2D70[];
extern char lbl_802C2D7C[];
extern "C" void fn_8006178C(void*);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);
extern "C" void fn_800618FC(void) {
    *(void**)lbl_802C2D7C = lbl_8027EC78;
    *(void**)lbl_802C2D7C = lbl_8027ED20;
    __register_global_object(lbl_802C2D7C, (void*)fn_8006178C, lbl_802C2D70);
}
