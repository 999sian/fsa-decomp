// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8004e8fc-0x8004e938 (1 functions). split_file divides it into the game's real files.

extern char lbl_802BF4C4[];
extern char lbl_802BF4B8[];
extern "C" void* fn_8004E5F0(void* p);
extern "C" void fn_8004E83C(void* p, short param_2);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);
extern "C" void fn_8004E8FC(void) {
    __register_global_object(fn_8004E5F0(lbl_802BF4C4), (void*)fn_8004E83C, lbl_802BF4B8);
}
