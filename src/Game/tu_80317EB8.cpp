#include "Game/Actor.h"

struct Tu80317Rect { f32 x0, y0, x1, y1; };
struct Tu80317Vec3 { f32 x, y, z; };


extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void*, s32);
extern "C" s32 Actor_CreateByID(void*, u32, s32, char*, u32, s32, s32);
extern "C" char lbl_804AAFB8[];
extern "C" void (Actor::*lbl_804AAED4[])();
extern "C" Actor* fn_80317EB8(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804AAFB8;
        param_1->Actor::~Actor();
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80319870(Actor* this_)
{
    extern char lbl_80471638[];
    extern f32 lbl_80541900;
    extern void fn_801F06F0(void*, char*, s32, s32, s32, f32, f32);
    extern void fn_80307AC8(void*, s32, void*, s32, s32, s32, s32);
    extern void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
    char* tbl = lbl_80471638;
    s32 off;

    if (*((u8*)this_ + 0x270) != 0) {
        switch (*(s32*)((u8*)this_ + 0x23c) & 3) {
        case 1:
            off = 0;
            fn_801F06F0(this_, tbl + off, *(s32*)((u8*)this_ + 0x26c) + *(s32*)((u8*)this_ + 0x25c), 0, 7, lbl_80541900, lbl_80541900);
            fn_80307AC8(*(void**)((u8*)this_ + 0x198), *(s32*)((u8*)this_ + 4), (u8*)this_ + 0xc, *(s32*)((u8*)this_ + 0x26c) + *(s32*)((u8*)this_ + 0x25c), 0, 0, -1);
            break;
        case 2:
            fn_801F06F0(this_, tbl + 0x14, *(s32*)((u8*)this_ + 0x26c) + *(s32*)((u8*)this_ + 0x25c), 0, 7, lbl_80541900, lbl_80541900);
            fn_803075AC(*(void**)((u8*)this_ + 0x198), *(s32*)((u8*)this_ + 4), (u8*)this_ + 0xc, *(s32*)((u8*)this_ + 0x26c) + *(s32*)((u8*)this_ + 0x25c), 0, 2, -1, 0, 0, 0);
            break;
        case 3:
            fn_801F06F0(this_, tbl + 0x28, *(s32*)((u8*)this_ + 0x26c) + *(s32*)((u8*)this_ + 0x25c), 0, 7, lbl_80541900, lbl_80541900);
            break;
        }
    }
}

extern "C" void fn_803199AC(u32* param_1)
{
    u32 state;
    u8 cVar1;
    if (param_1[0x90] != 0) {
        cVar1 = ((u8 (*)(Actor*))((void**)*param_1)[13])((Actor*)param_1);
        state = param_1[0x90];
        if ((state == 1 && cVar1 == 1) || (state == 2 && cVar1 == 0)) {
            *(u8*)(param_1 + 0x9c) = 0;
        } else {
            *(u8*)(param_1 + 0x9c) = 1;
        }
    }
    if (*(u8*)(param_1 + 0x9c) == 1) {
        (((Actor*)param_1)->*lbl_804AAED4[param_1[0x8e]])();
    }
}

extern "C" void fn_80319A58(char* param_1) {
    if (*(u32*)(param_1 + 0x238) == 0) {
        s32 count = *(s32*)((char*)fn_801F856C() + 0x1008);
        s32 off = 0;
        s32 i = 0;
        for (; i < count; i++) {
            char* actor = *(char**)((char*)fn_801F856C() + off + 8);
            if (actor != 0 && *(s32*)(actor + 0x1a0) == 0x4a494a49 && *(s32*)(actor + 4) == *(s32*)(param_1 + 4) &&
                ((*(u32*)(actor + 0x90) >> 16) & 0xff) == 0x2a) {
                u32 flags = *(u32*)(actor + 0x90);
                *(s32*)(param_1 + 0x258) = Actor_CreateByID(fn_801F856C(), 0x534e5043, *(s32*)(param_1 + 4), actor + 0xc,
                                                            (flags & 0xfff) | 0x90000, -1, -1);
                s32 id = *(s32*)(param_1 + 0x258);
                if (id < 0) {
                    return;
                }
                char* obj = (char*)fn_801F666C(fn_801F856C(), id);
                *(s32*)(obj + 0x258) = *(s32*)(param_1 + 0x198);
                actor[0x11c] = 0;
                return;
            }
            off += 4;
        }
    }
}

