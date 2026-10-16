#include "types.h"

s16 fn_801D0280(void* p, s32 idx);
u8 fn_801CC9F8(void* p, s32 idx);
u8* fn_802D6A9C(void);
extern "C" void fn_801C6784(void* p) {
    s32 off = *(s32*)((char*)p + 4);
    u8* base = fn_802D6A9C();
    if (base[0x10000 + off + 0x31df] != 0 && fn_801CC9F8((char*)p + 0xc, *(s32*)((char*)p + 4)) == 0) {
        if (*(f32*)((char*)p + 0xc) < *(f32*)((char*)p + *(s32*)((char*)p + 0x590) * 12 + 0x1ac)) {
            *(s16*)((char*)p + 0x33c) = 0x4000;
        } else {
            *(s16*)((char*)p + 0x33c) = -0x4000;
        }
    } else {
        *(s16*)((char*)p + 0x33c) = fn_801D0280(p, *(s32*)((char*)p + 0x590));
    }
}
