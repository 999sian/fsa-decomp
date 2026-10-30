// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8004e9f4-0x8004ea68 (1 functions). split_file divides it into the game's real files.

extern char lbl_802BF75C[];
extern char lbl_802BF750[];
extern void* lbl_80222428[];
extern void* lbl_80247244[];
extern void* lbl_80247270[];
extern "C" void fn_8004E980(void*);
extern "C" void __register_global_object(void*, void*, void*);
extern "C" void fn_8004E9F4(void) {
    *(void**)lbl_802BF75C = lbl_80222428;
    *(void**)lbl_802BF75C = lbl_80247244;
    *(void**)(lbl_802BF75C + 8) = lbl_80247270;
    lbl_802BF75C[0xd] = 1;
    lbl_802BF75C[0xe] = 0;
    lbl_802BF75C[0xf] = 1;
    lbl_802BF75C[0x10] = 0;
    lbl_802BF75C[0x14] = 1;
    __register_global_object(lbl_802BF75C, (void*)fn_8004E980, lbl_802BF750);
}
