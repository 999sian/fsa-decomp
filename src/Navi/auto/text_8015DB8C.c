// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8015db8c-0x8015dbf4 (1 functions). split_file divides it into the game's real files.

extern "C" void fn_80166BD0(void*, int);
extern "C" void fn_80166C70(void*);
extern "C" void fn_8015DC48(void*);
extern "C" void fn_8015DBF4(void*);
extern "C" void __register_global_object(void*, void*, void*);
extern char lbl_802EE200[];
extern "C" void fn_8015DB8C(void) {
    char* p = lbl_802EE200;
    fn_80166BD0(p + 0xc, 0);
    __register_global_object(p + 0xc, (void*)fn_8015DC48, p);
    fn_80166C70(p + 0x24);
    __register_global_object(p + 0x24, (void*)fn_8015DBF4, p + 0x18);
}
