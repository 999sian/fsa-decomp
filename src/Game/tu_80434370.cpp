#include "types.h"
class J2DGrafContext;
class J2DScreen {
public:
    void draw(float, float, const J2DGrafContext*);
};

class Unk80434370 {
public:
    unsigned char pad[0x6b];
    unsigned char m_state;
};
typedef void (Unk80434370::*Unk80434370Fn)();
extern Unk80434370Fn lbl_804B1690[];

extern "C" char* lbl_8053AB10;
extern "C" void* lbl_8053AED8;
extern "C" const float lbl_80543BD8;
extern "C" void fn_8013B490(void*);
extern "C" void fn_80440EE8(void*);
extern "C" Unk80434370Fn lbl_804B1690[];
extern "C" u8 fn_80402940(void* obj, s32 type, f32 a, f32 b, s32 c);
extern "C" void fn_8043651C(u8* self) {
    u8 a = 0;
    u8 b = 0;
    u8 c = 0;
    *(s16*)(self + 0x58) += 1;
    if (*(s16*)(self + 0x58) > 0) {
        a = fn_80402940(*(void**)(self + 0x8), 0x10, -150.0f, 0.0f, 0);
        for (int i = 0; i < 2; i++) {
            fn_80402940(*(void**)(self + 0xc + i * 4), 0x10, -150.0f + *(f32*)(self + 0x44), *(f32*)(self + 0x44), 0);
        }
        fn_80402940(*(void**)(self + 0x14), 0x10, -150.0f, 0.0f, 0);
        fn_80402940(*(void**)(self + 0x18), 0x10, -150.0f, 0.0f, 0);
    }
    if (*(s16*)(self + 0x58) > 0) {
        b = fn_80402940(*(void**)(self + 0x34), 0x14, 200.0f, 0.0f, 0);
    }
    if (*(s16*)(self + 0x58) > 10) {
        c = fn_80402940(*(void**)(self + 0x38), 0x16, 200.0f, 0.0f, 0);
    }
    if (a && b && c) {
        *(u8*)(self + 0x6b) = 1;
    }
}

extern "C" void fn_80436668(char* param_1)
{
    fn_8013B490(lbl_8053AB10);
    (*(J2DScreen**)(param_1 + 4))->draw(lbl_80543BD8, lbl_80543BD8, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
    fn_80440EE8(lbl_8053AED8);
}

extern "C" int fn_804366B8(Unk80434370* param_1)
{
    (param_1->*lbl_804B1690[param_1->m_state])();
    return 2 == param_1->m_state;
}
