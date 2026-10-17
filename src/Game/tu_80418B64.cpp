#include "types.h"
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/JUtility/JUTVideo.h"


extern u8* lbl_8053AAF8;
extern u8 lbl_80529DEC[];
extern "C" u32 fn_80237774(s32 i);
extern "C" u8 fn_8022F514(s32 i);
extern "C" s32 fn_8022F3DC(s32 i);
extern "C" u32 fn_80236100(s32 i);
extern "C" u32 fn_802375B0(s32 i);
extern u8* lbl_8053AED0;
extern u8* lbl_8053AEC8;
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_8022AF5C(void);
extern "C" u8 fn_8022B1AC(void);
extern "C" u8 fn_8022B160(void);
extern "C" s32 fn_80138A30(u8* game);
extern "C" void fn_8022EA0C(s32);
extern "C" void* fn_8023E724();
extern "C" void fn_8030C5F0(void*, void*, s32, s32, f32*);
extern "C" s32 fn_8023DE58(s32);
extern "C" u8* lbl_8053AB10;
extern "C" u8* sManager__8JUTVideo;
extern "C" s32 fn_80418B64(u8* self) {
    f32 buf[3];
    fn_8022EA0C(0);
    void* p = fn_8023E724();
    fn_8030C5F0(*(void**)(lbl_8053AB10 + 0x24), p, 0, 0, buf);
    if (fn_8023DE58(0) >= 8) {
        self[0x218] = 1;
    } else {
        if (buf[1] < 0.33333334f * (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 6)) {
            self[0x218] = 0;
        } else if (buf[1] > 0.6666667f * (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 6)) {
            self[0x218] = 1;
        }
    }
    s32 r;
    if (self[0x218] != 0) {
        u8 b = lbl_8053AED0[0xdc];
        if (((b >> 0) & 1) == 1) {
            if (((b >> 1) & 1) == 1) {
                if (((b >> 2) & 1) == 1) {
                    if (((b >> 3) & 1) == 1) r = 4;
                    else r = 3;
                } else r = 1;
            } else r = 2;
        } else r = 0;
    } else {
        u8 b = lbl_8053AED0[0xdc];
        if (((b >> 2) & 1) == 1) {
            if (((b >> 3) & 1) == 1) {
                if (((b >> 0) & 1) == 1) {
                    if (((b >> 1) & 1) == 1) r = 4;
                    else r = 2;
                } else r = 0;
            } else r = 3;
        } else r = 1;
    }
    return r;
}

extern "C" void fn_8041E3B4(u8* this_, u32 idx) {
    u8 mask;
    u32 bit;
    s32 i;
    BOOL flag;

    bit = 1 << idx;
    mask = bit;

    flag = (lbl_8053AAF8[0x82] & mask) != 0;
    if (!flag) {
        this_[0x28f] &= ~mask;
        return;
    }
    flag = (lbl_8053AED0[0xdd] & mask) != 0;
    if (flag && (this_[0x290] & mask) == 0) {
        this_[0x290] |= mask;
        this_[0x28f] |= mask;
        return;
    }
    if ((lbl_8053AED0[0xdc] & 0x10) != 0) {
        this_[0x28f] &= ~mask;
        return;
    }
    if (((u8*)fn_802D6A9C())[0x131ef] != 0 || fn_8022AF5C() != 0 || fn_8022B1AC() != 0 || fn_8022B160() != 0) {
        this_[0x28f] &= ~mask;
        this_[0x293] |= (u8)bit;
        return;
    }
    if (lbl_8053AEC8[0x5e] == 1) {
        for (i = 0; i < fn_80138A30(lbl_8053AAF8); i++) {
            this_[0x28f] |= (u8)(1 << i);
        }
        lbl_8053AEC8[0x5e] = 0;
        return;
    }
    if (*(s32*)(lbl_8053AAF8 + 0x4c) == 0xb) {
        this_[0x28f] &= ~mask;
        return;
    }
    if (fn_8022B1AC() == 0 && fn_8022B160() == 0 && (this_[0x293] & mask) != 0) {
        this_[0x28f] |= (u8)bit;
        this_[0x293] &= ~mask;
    }
}

extern "C" void fn_8041E58C(u8* this_) {
    s32 i;
    s32 j;
    s32 bit;
    s32 flag;
    u32* table;

    table = (u32*)lbl_80529DEC;
    for (i = 0; i < 4; i++) {
        bit = 1 << i;
        flag = (lbl_8053AAF8[0x82] & (u8)bit) != 0;
        if (flag != 0) {
            table[0x36 + i] = fn_80237774(i);
            for (j = 0; j < 4; j++) {
                if (j != i && fn_8022F514(j) && fn_8022F3DC(j) == i) {
                    table[0x36 + j] = table[0x36 + i];
                }
            }
            this_[0x28a] |= (u8)bit;
            *(u32*)(this_ + 0x198 + i * 4) = 0;
            table[0x3a + i] = fn_80236100(i);
            this_[0x28b] |= (u8)bit;
            *(u32*)(this_ + 0x1a8 + i * 4) = 0;
            table[0x42 + i] = fn_802375B0(i);
            for (j = 0; j < 4; j++) {
                if (j != i && fn_8022F514(j) && fn_8022F3DC(j) == i) {
                    table[0x42 + j] = table[0x42 + i];
                }
            }
            this_[0x289] |= (u8)bit;
            *(u32*)(this_ + 0x1b8 + i * 4) = 0;
        }
    }
}

extern "C" void fn_80230FD0(s32 i, s32 arg);
extern "C" s32 fn_80236228(s32 i);
extern "C" void fn_802362C4(s32 i, s32 val);
extern "C" void fn_8023619C(s32 i, s32 val);
extern "C" void fn_8041E708(u8* this_, s32 i, s32 val, u8 flag) {
    s32 idx;
    if (fn_8022F514(i)) {
        idx = fn_8022F3DC(i);
    } else {
        idx = i;
    }
    if (flag) {
        s32 sum = val + (s32)fn_80236100(idx);
        if (sum > 9999) {
            val = 9999 - fn_80236228(idx);
        } else if (sum < -5000) {
            val = -5000 - fn_80236228(idx);
        }
    } else {
        s32 sum = val + fn_80236228(idx);
        if (sum > 9999) {
            val = 9999 - fn_80236228(idx);
        } else if (sum < 0) {
            if (fn_80236228(idx) <= 0) {
                val = 0;
            } else {
                val = -fn_80236228(idx);
            }
        }
    }
    if (val >= 1000 || val <= -1000) {
        *(s16*)(this_ + i * 2 + 0x224) = (s16)((val < 0 ? -val : val) / 100);
        *(s16*)(this_ + i * 2 + 0x22C) = 0;
    } else {
        fn_80230FD0(i, 0x20034);
    }
    if (flag) {
        fn_8023619C(idx, val);
    } else {
        fn_802362C4(idx, val);
    }
    u32* table = (u32*)lbl_80529DEC;
    table[0x3A + idx] = fn_80236100(idx);
    u32* counts = (u32*)(this_ + idx * 4);
    counts[0x1A8 / 4] = 0;
    this_[0x28B] |= (u8)(1 << idx);
}

extern "C" void fn_8013B490(void*);
extern "C" void fn_8044148C(void);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(J2DScreen*, f32, f32, const J2DGrafContext*);
extern u8* lbl_8053AB10;
extern f32 lbl_80543A00;
extern "C" void fn_8041F5FC(void* this_) {
    u8* p = (u8*)this_;
    s32 mode = *(s32*)(lbl_80529DEC + 0x118);
    if (mode == 9 && *(s32*)(lbl_80529DEC + 0x11c) == 3) return;
    if (mode == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 2) return;
    if (mode == 1 && *(s32*)(lbl_80529DEC + 0x11c) == 2) return;
    if (mode == 2 && *(s32*)(lbl_80529DEC + 0x11c) == 2) return;
    if (mode == 4 && *(s32*)(lbl_80529DEC + 0x11c) == 2) return;
    if (mode == 5 && *(s32*)(lbl_80529DEC + 0x11c) == 2) return;
    if (mode == 10) {
        if (*(s32*)(lbl_80529DEC + 0x11c) == 2) {
            fn_8044148C();
            return;
        }
    }
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543A00;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(p + 0x18), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
    if (*(void**)(p + 0x50) != 0) {
        fn_8044148C();
    }
}

