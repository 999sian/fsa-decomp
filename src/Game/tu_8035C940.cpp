#include "JSystem/JMath/JMath.h"
#include "dolphin/mtx.h"

struct Unk8035CD00 {
    u8 pad0[0x14];
    f32 m14;
    u8 pad18[0x25c - 0x18];
    f32 m25C;
    s16 m260;
    u8 pad262[2];
    f32 m264;
    f32 m268;
    u8 pad26c[4];
    s16 m270;
};

extern "C" Vec fn_8035CD00(Unk8035CD00* p) {
    s16 old = p->m260;
    p->m260 += 0x400;
    Vec pos;
    pos.x = 25.0f * JMACosShort(p->m260) + (0.0f + p->m264);
    pos.y = 25.0f * JMASinShort(p->m260) + (25.0f + (p->m268 - p->m25C));
    pos.z = p->m14;
    Vec ret = pos;
    if ((u16)p->m260 >= 0xC000 && (u16)old < 0xC000) {
        if (p->m270 < 0) {
            p->m270 = -0x4000;
        } else {
            p->m270 = -0x8000;
        }
    }
    return ret;
}

extern "C" void fn_8035D6C4(char* p) {
    if (*(int*)(p + 0x238) == 0) return;
    *(int*)(p + 0x234) = 0x400;
    *(int*)(p + 0x230) = 1;
    *(int*)(p + 0x244) = 0x38;
    *(int*)(p + 0x238) = 4;
}

struct Unk8035DA78;
typedef void (Unk8035DA78::*Unk8035DA78Func)();
extern Unk8035DA78Func lbl_804AD528[];
extern "C" void fn_8035DA78(Unk8035DA78* self) {
    char* p = (char*)self;
    if (*(int*)(p + 0x234) != 0) *(int*)(p + 0x234) -= 1;
    if (*(int*)(p + 0x244) != 0) *(int*)(p + 0x244) -= 1;
    (self->*lbl_804AD528[*(int*)(p + 0x230)])();
}

