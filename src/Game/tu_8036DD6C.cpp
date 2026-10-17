#include "types.h"
#include "dolphin/mtx.h"


extern "C" void fn_8036DDCC(void) {}

extern "C" u32 fn_80226BC4(f32* pos, s32 room);
extern "C" u16 fn_802F9908(void* mgr, s32 room, s32 idx);
extern "C" u8 fn_8023A51C(s32 i);
extern "C" s32 fn_802373EC(s32 i);
extern "C" void* fn_8023E724(s32 i);
extern "C" void fn_8013CC50(s32 id, void* pos, f32 scale, u16 kind, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 a);
extern u8* lbl_8053AB10;
extern u16 lbl_80542D38[];
extern f32 lbl_80542D40;
extern f32 lbl_80542D44;
extern f32 lbl_80542D48;
extern u16 lbl_80542D38[2];
extern "C" void fn_8036DDD0(u8* this_) {
    u32 tile = fn_80226BC4((f32*)(this_ + 0x244), *(s32*)(this_ + 4));
    u16 kind = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), *(s32*)(this_ + 4), tile) & 0x3ff;
    if (kind != *(u16*)(this_ + 0x240)) {
        this_[0x250] = 1;
        return;
    }
    if (*(s32*)(this_ + 0x234) == 1 && this_[0x250] == 1) {
        this_[0x250] = 0;
        fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_80542D40, lbl_80542D38[*(s32*)(this_ + 0x234)], 0, 2, 0, 0, 1);
        if (*(s32*)(this_ + 0x23c) != -1) {
            fn_801F0E34(this_, *(s32*)(this_ + 0x23c), 0);
        }
    } else {
        this_[0x250] = 0;
        for (s32 i = 0; i < 4; i++) {
            if (fn_8023A51C(i)) {
                if (fn_802373EC(i) != 1) {
                    fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_80542D40, lbl_80542D38[*(s32*)(this_ + 0x234)], 0, 2, 0, 0, 1);
                    if (*(s32*)(this_ + 0x23c) != -1) {
                        fn_801F0E34(this_, *(s32*)(this_ + 0x23c), 0);
                    }
                    break;
                }
                Vec tmp = *(Vec*)fn_8023E724(i);
                if (!(PSVECDistance((Vec*)(this_ + 0xc), &tmp) <= lbl_80542D44 && __fabsf(*(f32*)(this_ + 0xc) - tmp.x) <= lbl_80542D48)) {
                    continue;
                }
                fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_80542D40, lbl_80542D38[*(s32*)(this_ + 0x234)], 0, 2, 0, 0, 1);
                if (*(s32*)(this_ + 0x23c) != -1) {
                    fn_801F0E34(this_, *(s32*)(this_ + 0x23c), 0);
                }
                break;
            }
        }
    }
    if (this_[0x230] == 1) {
        this_[0x230] = 0;
        fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_80542D40, lbl_80542D38[*(s32*)(this_ + 0x234)], 0, 2, 0, 0, 1);
        if (*(s32*)(this_ + 0x23c) != -1) {
            fn_801F0E34(this_, *(s32*)(this_ + 0x23c), 0);
        }
    }
}

