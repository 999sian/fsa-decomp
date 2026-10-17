#include "types.h"

extern "C" void fn_801D41B8(void* this_);
extern "C" void fn_801D3DAC(void* this_, void* p2);
extern "C" bool fn_801CD2F8(s32 id);
extern "C" void fn_801CD150(void* src, void* dst);
extern "C" void fn_803075AC(s32 a, s32 b, void* c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern "C" void fn_801D3CBC(void* this_) {
    s32 state = *(s32*)((u8*)this_ + 0x248);
    u8 buf[16];
    s32 arg;

    switch (state) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 0xd:
        return;
    case 0x17:
        if ((*(u32*)((u8*)this_ + 0x524) & 0x200) != 0) {
            fn_801D41B8(this_);
        }
        return;
    }

    arg = *(s32*)((u8*)this_ + 0x348);
    switch (state) {
    case 0x18:
    case 0x19:
    case 0x1a:
        arg = *(s32*)((u8*)this_ + 0x98) + 0x3c;
        break;
    }
    fn_801D3DAC(this_, (void*)arg);
    if ((*(u32*)((u8*)this_ + 0x230) & 0x10000) != 0 && !fn_801CD2F8(*(s32*)((u8*)this_ + 4))) {
        fn_801CD150((u8*)this_ + 0xc, buf);
        fn_803075AC(*(s32*)((u8*)this_ + 0x198), 8, buf, 0x176, 0, 2, -1, 0, 0, 0);
    }
}
