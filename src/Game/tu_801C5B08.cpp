#include "types.h"

struct Unk801C5B08 {
    u8 unk_00[0x4];
    s32 field_04;
    u8 unk_08[0x4];
    f32 field_0C;
    u8 unk_10[0x33C - 0x10];
    s16 field_33C;
    u8 unk_33E[0x590 - 0x33E];
    s32 field_590;
};
s16 fn_801D0280(void* p, s32 idx);
u8 fn_801CC9F8(void* p, s32 idx);
u8* fn_802D6A9C(void);
extern "C" void fn_801C6784(void* p) {
    Unk801C5B08* self = (Unk801C5B08*)p;
    s32 off = self->field_04;
    u8* base = fn_802D6A9C();
    if (base[0x10000 + off + 0x31df] != 0 && fn_801CC9F8(&self->field_0C, self->field_04) == 0) {
        if (self->field_0C < *(f32*)((char*)p + self->field_590 * 12 + 0x1ac)) {
            self->field_33C = 0x4000;
        } else {
            self->field_33C = -0x4000;
        }
    } else {
        self->field_33C = fn_801D0280(p, self->field_590);
    }
}
