#include "Game/Actor.h"


extern "C" char lbl_804B19E0[];
extern "C" void fn_80441778(void* p) {
    *(void**)p = lbl_804B19E0;
    *(s16*)((u8*)p + 0xc) = 0;
    *(u8*)((u8*)p + 0xe) = 0;
    *(u8*)((u8*)p + 0xf) = 0;
    *(s32*)((u8*)p + 0x4) = -1;
    *(s32*)((u8*)p + 0x8) = 0;
}
