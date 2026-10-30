#include "types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"
#include "Game/ItemBase.h"
#include "JSystem/JKernel/JKRFileLoader.h"
#include "dolphin/mtx.h"
#include "JSystem/JGeometry/Vec.h"

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

extern "C" void* fn_802D6A9C();
extern "C" void fn_801EF830(s32 idx, f32* pos, u8* p3, u32 mask, u8* p5, u32 p6, u8* p7);
extern "C" void fn_801EF574(u8* a, void* b, u8* c, u8* d);
extern "C" void fn_801CD0D0(void* a, u8* b);
extern "C" void fn_802F86CC(void* mgr, void* pos, void* name, void* p3, void* rec, f32 f1, f32 f2);
extern "C" void fn_801F06F0(void* a, void* p2, void* p3, const void* p4, u32 p5, f32 f6, f32 f7);
extern "C" void fn_80307830(void* h, s32 room, void* pos, void* p3, u32 a, u32 b, u32 c, u32 k);
extern u8 lbl_80469488[];
extern s32 lbl_8053EDF8;
extern s32 lbl_8053EDFC;
extern f32 lbl_8053F0A0;
extern f32 lbl_8053F0A4;
extern void* lbl_8053AAF8;
extern void* lbl_8053AB10;
extern "C" void fn_801D3DAC(void* this_, void* p2) {
    s32 room;
    u8* self=(u8*)this_;
    void* arg=p2;
    u8 buf[12];
    DrawRec rec;
    rec.w30 = 0xe;
    rec.b2e = 0x40;
    room=*(s32*)(self+4);
    u8* mgr = (u8*)fn_802D6A9C();
    if (mgr[room + 0x131df] != 0) {
        rec.b1f = 0;
    }
    s32 type=*(s32*)(self+0x560);
    if (type != 4 && (*(s32*)(self + 0x248) == 8 || *(s32*)(self + 0x248) == 9)) {
        if (*(s32*)(self + 0x248) == 8) {
            ((u8*)&rec.w10)[3] = 0xff;
        } else {
            ((u8*)&rec.w10)[3] = (u8)(s32)(lbl_8053F0A0 - (lbl_8053F0A0 * (f32)*(s32*)(self + 0x24c)) / (f32)lbl_8053EDF8);
        }
        if (((u8*)&rec.w10)[3] != 0) {
            fn_801F06F0(this_, lbl_80469488, arg, &rec, 7, lbl_8053F0A4, lbl_8053F0A4);
        }
        s32 kind = *(s32*)(self + 0x560);
        s32 state = *(s32*)(self + 0x248);
        kind += 0xc;
        rec.ids[7] = kind;
        if (state == 8) {
            ((u8*)&rec.w10)[3] = (u8)(s32)((lbl_8053F0A0 * (f32)*(s32*)(self + 0x24c)) / (f32)lbl_8053EDFC);
        } else {
            ((u8*)&rec.w10)[3] = 0xff;
        }
        if (((u8*)&rec.w10)[3] != 0) {
            fn_801F06F0(this_, lbl_80469488, arg, &rec, 7, lbl_8053F0A4, lbl_8053F0A4);
        }
    } else {
        if (type != 4 && *(s32*)(self + 0x248) > 8 && *(s32*)(self + 0x248) != 0x29) {
            rec.ids[7] = type + 0xc;
        }
        if (*(s32*)(self + 0x248) == 0x10) {
            if (*(u32*)(self + 0x138) == 0) {
                fn_801EF830(*(s32*)(self+4), (f32*)(self + 0xc), rec.ids, 7, lbl_80469488, (u32)arg, NULL);
            }
            if (*(s32*)(self+4) < 8) {
                void* res = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
                void* name = ((JKRFileLoader*)res)->getResource(0x534f4220, (const char*)lbl_80469488);
                fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), self + 0xc, name, arg, &rec, lbl_8053F0A4, lbl_8053F0A4);
            }
            if (*(s32*)(self+4) == 8) {
                fn_801CD0D0(self + 0xc, buf);
                fn_801EF574(lbl_80469488, arg, buf, rec.ids);
            }
        } else {
            fn_801F06F0(this_, lbl_80469488, arg, &rec, 7, lbl_8053F0A4, lbl_8053F0A4);
        }
    }
    u32 k = *(u32*)(self + 0x560) & 0xff;
    if (*(s32*)(self + 0x248) == 0x29) {
        k = 4;
    }
    fn_80307830(*(void**)(self + 0x198), *(s32*)(self+4), self + 0xc, arg, 0, 1, 0, k);
}

extern s32 lbl_8053EE00;
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" u16 fn_80226850(void* pos, s32 room);
#pragma opt_propagation off
extern "C" void fn_801D41B8(void* __restrict this_) {
    f32 pos[3];
    s32 mode;
    s32 alpha;
    u8 flag;
    u16 t;

    pos[0] = 0.0f;
    pos[1] = 0.0f;
    pos[2] = 0.0f;
    flag = FALSE;
    if (fn_801CD2F8(*(s32*)((u8*)this_ + 0x56c))) {
        f32 z, y, x;
        x = *(f32*)((u8*)this_ + 0xc);
        y = *(f32*)((u8*)this_ + 0x10);
        z = *(f32*)((u8*)this_ + 0x14);
        alpha = (s32)(lbl_8053F0A0 * (f32)*(s32*)((u8*)this_ + 0x24c) * (lbl_8053F0A4 / (f32)lbl_8053EE00));
        mode = 0x3e;
        pos[0] = x;
        pos[1] = y;
        pos[2] = z;
    } else {
        f32 z, y, x;
        x = *(f32*)((u8*)this_ + 0x570);
        y = *(f32*)((u8*)this_ + 0x574);
        z = *(f32*)((u8*)this_ + 0x578);
        alpha = (s32)(lbl_8053F0A0 - (lbl_8053F0A0 * (f32)*(s32*)((u8*)this_ + 0x24c)) * (lbl_8053F0A4 / (f32)lbl_8053EE00));
        mode = 0x3f;
        pos[0] = x;
        pos[1] = y;
        pos[2] = z;
    }

    if (fn_8022461C(pos, 0) == 1) {
        t = fn_80226850(pos, 0);
        switch (t) { case 0x9b: case 0x9c:
            flag = TRUE; break;
        }
    }

    if (flag && (u8)alpha) {
        DrawRec rec;
        s32 room;
        u8* mgr;

        rec.w30 = 0xe;
        rec.b2e = 0;
        ((u8*)&rec.w10)[3] = alpha;
        room = *(s32*)((u8*)this_ + 4);
        mgr = (u8*)fn_802D6A9C();
        if (mgr[room + 0x131df] != 0) {
            rec.b1f = 0;
        }
        if (*(s32*)((u8*)this_ + 0x560) != 4) {
            rec.ids[7] = *(s32*)((u8*)this_ + 0x560) + 0xc;
        }
        {
            JKRFileLoader* res = *(JKRFileLoader**)((u8*)lbl_8053AAF8 + 0xa4);
            void* name = res->getResource(0x534f4220, (const char*)lbl_80469488);
            fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), pos, name, (void*)mode, &rec, lbl_8053F0A4, lbl_8053F0A4);
        }
    }
}
#pragma opt_propagation reset
