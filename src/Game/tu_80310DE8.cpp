#include "Game/esd/types.h"


extern "C" void fn_802A3948(void* mgr, void* pos, s32 player, u32 room, s32 id);
extern "C" void fn_802A3884(void* mgr, void* pos, s32 player, u32 room, s32 id);
extern "C" void fn_801F0E34(void* this_, u32 id, s32 c);
extern "C" void fn_8023061C(s32 p, s32 a);
extern "C" char lbl_804AAAE8[];
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern void* lbl_8053AC98;
extern "C" void fn_80310E48(void* this_) {
    fn_802A3948(lbl_8053AC98, (u8*)this_ + 0xc, 0, *(u32*)((u8*)this_ + 4), 0x10);
    *(s32*)((u8*)this_ + 0x234) = -1;
    *(s32*)((u8*)this_ + 0x230) = 0;
}
