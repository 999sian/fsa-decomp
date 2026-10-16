#include "Game/Actor.h"


extern "C" char lbl_804A7F38[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802A6A4C(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804A7F38;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void* lbl_8053AC98;
extern "C" void fn_802A3948(void* mgr, void* pos, s32 player, u32 room, s32 id);
extern "C" void fn_802A6AAC(Actor* p, s32 player) {
    switch (*(u16*)((u8*)p + 0x258)) {
    case 0x41:
    case 0x12:
    case 0x68:
        fn_802A3948(lbl_8053AC98, (u8*)p + 0xc, player, p->field_04, 0x13);
        break;
    case 0x50:
    case 0x43:
    case 0x6a:
        fn_802A3948(lbl_8053AC98, (u8*)p + 0xc, player, p->field_04, 0x51);
        break;
    case 0x14:
    case 0x52:
        fn_802A3948(lbl_8053AC98, (u8*)p + 0xc, player, p->field_04, 0x15);
        break;
    case 0x15a:
        fn_802A3948(lbl_8053AC98, (u8*)p + 0xc, player, p->field_04, 0x360);
        break;
    }
}

extern "C" void fn_802A6BC0(void) {}

