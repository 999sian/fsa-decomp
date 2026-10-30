// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800cddd0-0x800cde98 (1 functions). split_file divides it into the game's real files.
struct Unk800CDDD0Obj { void* vtbl; signed char a; int b; signed char c; float d; float e; signed char f; float g; float h; signed char i; };
struct Unk800CDDD0Copy { int w[6]; };

extern "C" void* __register_global_object(void* obj, void* dtor, void* reg);
extern "C" void fn_800CDD88(void);
extern "C" char lbl_80288B0C[];
extern "C" char lbl_802C5708[];
extern "C" char lbl_802889F0[];
extern "C" float lbl_80300EE0;
extern "C" float lbl_80300EE4;
extern "C" float lbl_80300EE8;
extern "C" float lbl_80300EEC;
extern "C" Unk800CDDD0Obj lbl_802C5714;

extern "C" void fn_800CDDD0(void) {
    char* p = lbl_802889F0;
    lbl_802C5714.vtbl = lbl_80288B0C;
    lbl_802C5714.a = -1;
    lbl_802C5714.b = 0;
    lbl_802C5714.c = 30;
    lbl_802C5714.d = lbl_80300EE0;
    lbl_802C5714.e = lbl_80300EE4;
    lbl_802C5714.f = 10;
    lbl_802C5714.g = lbl_80300EE8;
    lbl_802C5714.h = lbl_80300EEC;
    lbl_802C5714.i = 30;
    __register_global_object(&lbl_802C5714, (void*)fn_800CDD88, lbl_802C5708);
    *(Unk800CDDD0Copy*)(p + 0x60) = *(Unk800CDDD0Copy*)(p + 0x48);
}
