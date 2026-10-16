#include "Game/Actor.h"


struct Unk8035DA78;
typedef void (Unk8035DA78::*Unk8035DA78Func)();
extern Unk8035DA78Func lbl_804AD6A8[];
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* base, int id);
extern "C" void fn_8035C1C4(void* self, int a, int b);
extern "C" char lbl_804AD6F0[];
extern "C" char lbl_804A5958[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" u8 fn_8035C15C(void* self, int a);
extern const f32 lbl_80542988;
extern float lbl_8054298C;
extern "C" Actor* fn_8035DED8(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AD6F0;
        if (p != 0) {
            *(void**)p = lbl_804A5958;
            __dt__5ActorFv(p, 0);
        }
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_8035DF48(Actor* a) {
    char* p = (char*)a;
    if (*(f32*)(p + 0x10) < lbl_80542988) {
        if (fn_8035C15C(p, 6) == 1) {
            fn_8035C1C4(p, 6, 0x9b);
        }
        *(f32*)(p + 0x10) += lbl_8054298C;
    } else {
        char* found = (char*)fn_801F666C(fn_801F856C(), *(int*)(p + 0x23c));
        if (found != 0) {
            *(int*)(found + 0x230) = 7;
            *(int*)(found + 0x234) = 0;
        }
        *(u8*)(p + 0x11c) = 0;
    }
}

extern "C" void fn_8035DFE4(int param_1) {
    char* p = (char*)param_1;
    if (*(int*)(p + 0x234) == 0) {
        if (*(int*)(p + 0x238) == 0) {
            char* found = (char*)fn_801F666C(fn_801F856C(), *(int*)(p + 0x23c));
            if (found != 0) {
                *(int*)(found + 0x234) = 1;
            }
        } else {
            fn_8035C1C4(p, 6, 0x9b);
            *(int*)(p + 0x230) += 1;
        }
    } else if (*(int*)(p + 0x234) < 0xf0) {
        *(int*)(p + 0x248) = 0x18;
    }
}

extern "C" void fn_8035E238(int param_1) {
    char* p = (char*)param_1;
    if (*(int*)(p + 0x244) == 0) {
        *(int*)(p + 0x248) = 0;
    }
    if (*(int*)(p + 0x238) == 0) return;
    *(int*)(p + 0x230) = 3;
    *(int*)(p + 0x234) = 100;
    *(int*)(p + 0x238) = 0;
}

extern "C" void fn_8035E274(int param_1) {
    char* p = (char*)param_1;
    int iVar1 = *(int*)(p + 0x238);
    if (iVar1 == 0) {
        if (fn_8035C15C(p, 0) == 1) {
            fn_8035C1C4(p, 1, 0x21b);
            *(int*)(p + 0x240) = 0;
            *(int*)(p + 0x238) = 4;
        }
    } else if (iVar1 == 4) {
        if (fn_8035C15C(p, 1) == 1) {
            fn_8035C1C4(p, 1, 0x21b);
        }
    } else if (iVar1 == 1) {
        fn_8035C1C4(p, 3, 0x274);
        *(int*)(p + 0x240) = 1;
        *(int*)(p + 0x238) = 2;
    } else if (iVar1 == 2) {
        if (fn_8035C15C(p, 2) == 1) {
            fn_8035C1C4(p, 2, 0x274);
        }
    } else if (iVar1 == 3) {
        *(int*)(p + 0x248) = 3;
        *(int*)(p + 0x244) = 0x45;
        *(int*)(p + 0x24c) = 0;
        *(int*)(p + 0x230) = 2;
        *(int*)(p + 0x238) = 0;
    }
}

extern "C" void fn_8035E394(int param_1) {
    char* p = (char*)param_1;
    if (*(int*)(p + 0x238) != 0) {
        *(int*)(p + 0x230) = 1;
        fn_8035C1C4(p, 0, 0x274);
        *(int*)(p + 0x238) = 0;
    }
}

extern "C" void fn_8035E57C(Unk8035DA78* self) {
    char* p = (char*)self;
    if (*(int*)(p + 0x234) != 0) *(int*)(p + 0x234) -= 1;
    if (*(int*)(p + 0x244) != 0) *(int*)(p + 0x244) -= 1;
    (self->*lbl_804AD6A8[*(int*)(p + 0x230)])();
}

extern "C" void fn_8035E5DC(int param_1) {
    char* p = (char*)param_1;
    *(int*)(p + 0x230) = 0;
    *(int*)(p + 0x234) = 0;
    *(int*)(p + 0x238) = 0;
    *(int*)(p + 0x240) = 1;
    *(int*)(p + 0x244) = 0;
    *(int*)(p + 0x248) = 0;
    *(int*)(p + 0x24c) = 0;
    *(int*)(p + 0x250) = 0x274;
}

