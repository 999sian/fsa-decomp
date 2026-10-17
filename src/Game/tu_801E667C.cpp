#include "types.h"
#include "Game/SinitPoolChain.h"

extern "C" void fn_801E67C4(s32* this_, s32 flag);
extern "C" void fn_801D1C18(s32* this_);
extern "C" u8 fn_801D21F0(s32* this_);
extern "C" s32 fn_8023E724(s32 idx);
extern "C" void fn_80230498(s32 idx, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" void fn_801D267C(void* this_);
extern "C" void fn_801D2608(void* this_, void* tbl, s32 n);
extern "C" char lbl_8053A158;
extern "C" s32 fn_801E667C(s32* this_)
{
    s32 i;
    s32 val;
    s32 ret = 0;
    this_[1]++;
    if (this_[1] < 0) {
        this_[1] = 0;
    }
    switch (this_[0]) {
    case 0:
        break;
    case 1:
        if (this_[1] >= 400) {
            fn_801E67C4(this_, 2);
        }
        break;
    case 2:
        fn_801D1C18(this_ + 4);
        val = this_[8];
        for (i = 0; i < 4; i++) {
            if (*(u8*)((u8*)this_ + (i + 0xc)) != 0) {
                fn_80230498(i, fn_8023E724(i), val, 0xff, -0x80, -0x80, 1);
            }
        }
        if (fn_801D21F0(this_ + 4) != 0) {
            fn_801E67C4(this_, 3);
        }
        break;
    case 3:
        if (this_[1] >= 0x82) {
            fn_801E67C4(this_, 4);
        }
        break;
    case 4:
        ret = 1;
        break;
    }
    return ret;
}

extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053AF80;
extern "C" f32 lbl_8053F5B0;
extern "C" f32 lbl_8053F5B4;
extern "C" f32 lbl_8053F5B8;
extern "C" s32 fn_80138A30(void* mgr);
extern "C" void fn_80136798(void* mgr, s32 a, s32 b);
extern "C" u8 fn_8023F264(s32 idx);
extern "C" u8 fn_8022F514(s32 idx);
extern "C" s32 fn_8022F3DC(s32 idx);
extern "C" u8 fn_802349EC(s32 idx);
extern "C" s32 fn_8023DE58(s32 idx);
extern "C" s32 fn_8013CC50(u32 id, void* p, f32 f, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);
extern "C" void fn_80230FD0(s32 idx, s32 v);
extern "C" void fn_80458F9C(void* mgr, s32 v);
extern "C" void fn_80458F04(void* mgr, s32 v);
extern "C" void fn_801D22DC(void* this_, s32 a, s32 b, s32 c);
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D9FF4(void* mgr, s32 a, s32 b);
extern "C" void fn_801E67C4(s32* this_, s32 flag)
{
    s32 i;
    s32 j;
    s32 count;
    if (flag == 3) {
        for (i = 0; i < 4; i++) {
            if (*(u8*)((u8*)this_ + (i + 0xc)) != 0) {
                f32* p = (f32*)fn_8023E724(i);
                f32 pos[3];
                pos[0] = p[0] + lbl_8053F5B0;
                pos[1] = p[1] + lbl_8053F5B4;
                pos[2] = p[2];
                fn_8013CC50(fn_8023DE58(i), pos, lbl_8053F5B8, 0xcb, 1, 0, 0, 0, 1);
                fn_8013CC50(fn_8023DE58(i), pos, lbl_8053F5B8, 0xcc, 1, 0, 0, 0, 1);
                fn_80230FD0(i, 0x2000e);
            }
        }
    } else if (flag < 3) {
        if (flag == 1) {
            ((u8*)this_)[0xc] = 0;
            ((u8*)this_)[0xd] = 0;
            ((u8*)this_)[0xe] = 0;
            ((u8*)this_)[0xf] = 0;
            count = fn_80138A30(lbl_8053AAF8);
            for (i = 0; i < count; i++) {
                if (fn_8023F264(i) != 0 && fn_8022F514(i) == 0) {
                    *(u8*)((u8*)this_ + (i + 0xc)) = 1;
                }
                for (j = i + 1; j < 4; j++) {
                    if (fn_8023F264(j) != 0 && fn_8022F514(j) != 0 && fn_8022F3DC(j) == i && fn_802349EC(j) == 0) {
                        *(u8*)((u8*)this_ + (j + 0xc)) = 1;
                    }
                }
            }
            for (i = 0; i < 4; i++) {
                if (*(u8*)((u8*)this_ + (i + 0xc)) != 0) {
                    fn_80230498(i, (s32)fn_8023E724(i), 0x3e, 0xff, -0x80, -0x80, 1);
                }
            }
            fn_80458F9C(lbl_8053AF80, 0);
            fn_80458F04(lbl_8053AF80, 0x1000001);
        } else if (flag > 0) {
            fn_801D22DC(this_ + 4, 0, 0, 0);
            for (i = 0; i < 4; i++) {
                if (*(u8*)((u8*)this_ + (i + 0xc)) != 0) {
                    fn_80230FD0(i, 0x10001);
                }
            }
        }
    } else if (flag < 5 && this_[2] == 0) {
        void* mgr = fn_802D6A9C();
        fn_802D9FF4(mgr, 9, 0);
        fn_80136798(lbl_8053AAF8, 0xd, 0);
    }
    this_[1] = 0;
    this_[0] = flag;
}

extern "C" void fn_801E6A84(s32* this_, s32 val) {
    if (this_[0] == 0) {
        this_[2] = val;
        fn_801E67C4(this_, 1);
    }
}

extern "C" s32* fn_801E6AB8(s32* this_) {
    this_[0] = 0;
    this_[1] = 0;
    this_[2] = 1;
    fn_801D267C(this_ + 4);
    ((u8*)this_)[0xc] = 0;
    ((u8*)this_)[0xd] = 0;
    ((u8*)this_)[0xe] = 0;
    ((u8*)this_)[0xf] = 0;
    fn_801D2608(this_ + 4, &lbl_8053A158, 1);
    return this_;
}

void __sinit_tu_801E667C_cpp(void) {}

