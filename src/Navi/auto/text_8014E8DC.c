// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014e8dc-0x8014e9c4 (1 functions). split_file divides it into the game's real files.

extern "C" unsigned char* lbl_802FF3E0;
extern "C" unsigned long fn_8014E080(void*, int, int, int);
extern "C" void fn_8014D95C(unsigned char*);
extern "C" int fn_8015766C(unsigned long);
extern "C" void fn_80157854(unsigned long);
extern "C" void fn_8014D3BC(unsigned char*, int);
extern "C" void fn_8014DEF0(unsigned char*, void*);
extern "C" unsigned long fn_8014E8DC(void* arg) {
    unsigned long idx = fn_8014E080(arg, 0xff, 0xffff, 1);
    if (idx != 0xffffffff) {
        int off = idx * 0x404;
        lbl_802FF3E0[off + 0x11c] = 1;
        lbl_802FF3E0[off + 0x11d] = 1;
        fn_8014D95C(lbl_802FF3E0 + off);
        *(unsigned long*)(lbl_802FF3E0 + off + 0xf4) = idx | 0xffffff00;
        if (fn_8015766C(idx) != 0) {
            fn_80157854(idx);
        }
        fn_8014D3BC(lbl_802FF3E0 + off, 2);
        *(unsigned long*)(lbl_802FF3E0 + off + 0x34) = 0;
        fn_8014DEF0(lbl_802FF3E0 + off, arg);
    }
    return idx;
}
