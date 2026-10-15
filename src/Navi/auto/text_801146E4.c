// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801146e4-0x801149f8 (15 functions). split_file divides it into the game's real files.

extern "C" void* lbl_802FF218;
extern "C" void fn_801147B8();
extern "C" void* lbl_802FF210;
extern "C" int fn_80159C40(void*, void*, void*);
extern "C" int fn_801146E4() {
    return 1;
}

extern "C" int fn_80114890() {
    return 1;
}

extern "C" int fn_801148A0() {
    lbl_802FF210 = (void*)fn_801147B8;
    return 4;
}

extern "C" void fn_801148B4(void* p) {
    lbl_802FF218 = p;
}
