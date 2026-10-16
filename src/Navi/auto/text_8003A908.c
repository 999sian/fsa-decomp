// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8003a908-0x8003a944 (1 functions). split_file divides it into the game's real files.

extern char lbl_802BEF44[];
extern char lbl_802BEF38[];
extern "C" void* fn_8003A2B0(void* p);
extern "C" void fn_8003A830(void* p, short param_2);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);
extern "C" void fn_8003A908(void) {
    __register_global_object(fn_8003A2B0(lbl_802BEF44), (void*)fn_8003A830, lbl_802BEF38);
}
