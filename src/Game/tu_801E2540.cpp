#include "types.h"
#include <JSystem/JGeometry/Box.h>

extern "C" void fn_802397B4(void* rect, u32 id, s32 v);
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" const f32 lbl_8053F4D0;

extern "C" void fn_802397B4(void* rect, u32 id, s32 v);
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" const f32 lbl_8053F4D0;
extern "C" u8* fn_802D6A9C(void);
extern "C" const f32 lbl_8053F4D4;
extern "C" void fn_801F317C(u8* this_, void* buf);
extern "C" s32 fn_8023AE34(void* buf, s32 room, void* out);
extern "C" s32 fn_8023AA18(void* buf, s32 room, void* out);
extern "C" s32 fn_8023AC74(void* buf, s32 room, void* out);
extern "C" s32 fn_8023AD54(void* buf, s32 room, void* out);
extern "C" u8 fn_801CC820(s32 h, void* pos);
extern "C" u8 fn_801CC538(s32 h, void* a, void* b, s32 c);
extern "C" s32 fn_801CC640(s32 h, s32 c, void* pos);
extern "C" u8 fn_801E1DE8(u8* this_);
extern "C" void fn_801E1594(u8* this_, s32 id);
extern "C" u8 fn_801E1CF8(u8* this_);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* p, s32 idx);
extern "C" void* fn_8023E724(s32 h);
extern "C" u8 fn_801F37AC(u8* this_, s32 a, void* v, s32 b, s32 mode, s32 h);
extern "C" s32 fn_801E2540(u8* this_) {
    s32 kind;
    s32 ret = 0;

    if ((*(u32*)(this_ + 0x230) & 0x1000) == 0) {
        u8* p;
        f32 lo;
        f32 hi;

        kind = *(s32*)(this_ + 4);
        p = fn_802D6A9C();
        if (kind < 8) {
            p += 0xcc;
        } else {
            p += 0xdc;
        }
        lo = *(f32*)(p + 0xc) - 8.0f;
        if (*(f32*)(this_ + 0x10) > lo) {
            *(f32*)(this_ + 0x10) = lo;
            ret = 1;
            *(f32*)(this_ + 0x264) = 0.0f;
            *(f32*)(this_ + 0x268) = -1.0f;
            *(f32*)(this_ + 0x26c) = 0.0f;
        } else {
            hi = 24.0f + *(f32*)(p + 0x4);
            if (*(f32*)(this_ + 0x10) < hi) {
                *(f32*)(this_ + 0x10) = hi;
                ret = 1;
                *(f32*)(this_ + 0x264) = 0.0f;
                *(f32*)(this_ + 0x268) = 1.0f;
                *(f32*)(this_ + 0x26c) = 0.0f;
            }
        }
    }
    return ret;
}

extern "C" s32 fn_801F285C(u8* this_, s32 a, s32 b, s32 c, s32 d);
extern "C" u8 fn_801E1CF8(u8* this_);
extern "C" u8 fn_80235448(s32 id);
extern "C" u8 fn_80235310(s32 id);
extern "C" void fn_801CB688(s32 a, void* b, s32 c, s32 d);
extern "C" u8 fn_801E1DE8(u8* this_);
extern "C" void fn_801E1594(u8* this_, s32 a);
extern "C" void fn_801F0E34(u8* this_, s32 a, s32 b);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* a, s32 b);
extern "C" u8 fn_801E1D7C(u8* this_);
extern "C" void fn_8023B6CC(s32 id);
extern "C" void fn_802379E4(s32 id, void* pos);
extern "C" u8 lbl_8053AC30;
extern "C" s32 fn_801E2610(u8* this_) {
    s32 ret = 0;
    s32 id = fn_801F285C(this_, 0, 0, 1, -1);
    s32 i;

    if (id >= 0) {
        if (fn_801E1CF8(this_) && (fn_80235448(id) || fn_80235310(id))) {
            fn_801CB688(*(s32*)(this_ + 4), this_ + 0xc, 0, 0);
            if (*(s32*)(this_ + 0x248) == 0xc && *(s32*)(this_ + 0x24c) >= 6 && !fn_801E1DE8(this_)) {
                fn_801E1594(this_, 0xd);
            } else if (fn_801E1CF8(this_) && (*(u32*)(this_ + 0x230) & 0x10000) == 0) {
                *(u32*)(this_ + 0x230) |= 0x10000;
                fn_801F0E34(this_, 0x4003d, 0);
                lbl_8053AC30++;
                if (lbl_8053AC30 >= 5) {
                    lbl_8053AC30 = 0;
                }
                *(u32*)(this_ + 0x230) &= ~0x100000;
                if ((*(u32*)(this_ + 0x230) & 0x80000) == 0 && *(s32*)(this_ + 0x2bc) >= 0) {
                    void* p;
                    fn_801F0E34(this_, 0x5001a, 0);
                    p = fn_801F666C(fn_801F856C(), *(s32*)(this_ + 0x2bc));
                    if (p != 0) {
                        *(u16*)((u8*)p + 0x94) = 0;
                        *(u8*)((u8*)p + 0x194) = 0;
                    }
                    *(s32*)(this_ + 0x2bc) = -1;
                    *(s32*)(this_ + 0x2c0) = 0;
                    *(u32*)(this_ + 0x230) &= ~0x8000;
                }
            }
            ret = 1;
        } else if (fn_801E1D7C(this_)) {
            for (i = 0; i < 4; i++) {
                if (fn_801F285C(this_, 0, 0, 1, i) == i) {
                    fn_8023B6CC(i);
                    fn_802379E4(i, this_ + 0xc);
                }
            }
            if (*(s32*)(this_ + 0x248) == 0xc && *(s32*)(this_ + 0x24c) >= 6 && !fn_801E1DE8(this_)) {
                fn_801E1594(this_, 0xd);
            }
            ret = 1;
        }
    }
    return ret;
}

extern "C" s32 fn_801E2A98(u8* this_) {
    s32 h;
    u8 b30 = 0;
    u8 b29 = 0;
    u8 b28 = 0;
    s32 b26 = 0;
    s32 mode;
    JGeometry::TVec3<f32> a50;
    JGeometry::TVec3<f32> a44;
    u8 buf34[0x10];
    JGeometry::TVec3<f32> v28;
    s32 buf8[2];

    a44.x = lbl_8053F4D4;
    a44.y = lbl_8053F4D4;
    a44.z = lbl_8053F4D4;
    fn_801F317C(this_, buf34);
    h = fn_8023AE34(buf34, *(s32*)(this_ + 4), buf8);
    if (h >= 0) {
        b30 = fn_801CC820(h, &a44);
    } else if ((h = fn_8023AA18(buf34, *(s32*)(this_ + 4), buf8)) >= 0) {
        b29 = 1;
    } else if ((h = fn_8023AC74(buf34, *(s32*)(this_ + 4), buf8)) >= 0) {
        b28 = fn_801CC538(h, buf8, &a50, 0);
    } else if ((h = fn_8023AD54(buf34, *(s32*)(this_ + 4), buf8)) >= 0) {
        b26 = fn_801CC640(h, 0, &a44);
    }
    if (b30 || b28 || (u8)b26) {
        if (*(s32*)(this_ + 0x248) == 0xc && *(s32*)(this_ + 0x24c) >= 6 && !fn_801E1DE8(this_)) {
            fn_801E1594(this_, 0xd);
        } else if (fn_801E1CF8(this_) && (*(u32*)(this_ + 0x230) & 0x10000) == 0) {
            *(u32*)(this_ + 0x230) |= 0x10000;
            fn_801F0E34(this_, 0x4003d, 0);
            lbl_8053AC30++;
            if (lbl_8053AC30 >= 5) {
                lbl_8053AC30 = 0;
            }
            *(u32*)(this_ + 0x230) &= ~0x100000;
            if ((*(u32*)(this_ + 0x230) & 0x80000) == 0 && *(s32*)(this_ + 0x2bc) >= 0) {
                void* p;
                fn_801F0E34(this_, 0x5001a, 0);
                p = fn_801F666C(fn_801F856C(), *(s32*)(this_ + 0x2bc));
                if (p != 0) {
                    *(u16*)((u8*)p + 0x94) = 0;
                    *(u8*)((u8*)p + 0x194) = 0;
                }
                *(s32*)(this_ + 0x2bc) = -1;
                *(s32*)(this_ + 0x2c0) = 0;
                *(u32*)(this_ + 0x230) &= ~0x8000;
            }
        }
    }
    b26 = 0;
    if (h >= 0) {
        v28 = *(JGeometry::TVec3<f32>*)fn_8023E724(h);
        mode = 0;
        if (b29) {
            mode = 4;
        } else if (b28) {
            v28 = a50;
        } else {
            v28 = *(JGeometry::TVec3<f32>*)(this_ + 0xc) - a44;
            if (b30) {
                mode = 3;
            }
        }
        if (*(u32*)(this_ + 0x230) & 0x10000) {
            b26 = fn_801F37AC(this_, 0, &v28, 0, mode, h);
        }
    }
    return b26;
}

extern "C" u8 fn_801E1DB4(u8* this_);
extern "C" u8 fn_801D0DD4(u8* this_);
extern "C" const f32 lbl_8053F4D8;
extern "C" const f32 lbl_8053F4E0;
extern "C" const f32 lbl_8053F4EC;
extern "C" const f32 lbl_8053F4F0;
extern "C" const f32 lbl_8053F4F4;
extern "C" const f32 lbl_8053F4F8;
extern "C" const f32 lbl_8053F4FC;
extern "C" const f32 lbl_8053F500;
extern "C" const f32 lbl_8053F504;
extern "C" void fn_801E2D88(u8* this_) {
    switch (*(s32*)(this_ + 0x248)) {
    case 0:
    case 0xe:
        *(f32*)(this_ + 0x60) = lbl_8053F4E0;
        *(f32*)(this_ + 0x64) = lbl_8053F4E0;
        *(f32*)(this_ + 0x68) = lbl_8053F4D8;
        *(f32*)(this_ + 0x6c) = lbl_8053F4D8;
        *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
        *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
        *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
        return;
    case 0xc:
        *(f32*)(this_ + 0x60) = lbl_8053F4EC;
        *(f32*)(this_ + 0x64) = lbl_8053F4EC;
        *(f32*)(this_ + 0x68) = lbl_8053F4D0;
        *(f32*)(this_ + 0x6c) = lbl_8053F4D0;
        *(f32*)(this_ + 0x70) = lbl_8053F4EC;
        *(f32*)(this_ + 0x74) = lbl_8053F4F0;
        *(f32*)(this_ + 0x78) = lbl_8053F4D0;
        *(f32*)(this_ + 0x7c) = lbl_8053F4D0;
        return;
    }
    if (fn_801E1DB4(this_)) {
        *(f32*)(this_ + 0x60) = lbl_8053F4F4;
        *(f32*)(this_ + 0x64) = lbl_8053F4F8;
        *(f32*)(this_ + 0x68) = lbl_8053F4FC;
        *(f32*)(this_ + 0x6c) = lbl_8053F500;
    } else {
        *(f32*)(this_ + 0x60) = lbl_8053F4EC;
        *(f32*)(this_ + 0x64) = lbl_8053F504;
        *(f32*)(this_ + 0x68) = lbl_8053F4D0;
        *(f32*)(this_ + 0x6c) = lbl_8053F500;
    }
    if (fn_801D0DD4(this_)) {
        *(f32*)(this_ + 0x64) += lbl_8053F500;
        *(f32*)(this_ + 0x6c) += lbl_8053F500;
    }
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
}

extern "C" void fn_801E2EE4(u8* this_) {
    f32 c = lbl_8053F4D0;
    f32 x = *(f32*)(this_ + 0xc);
    f32 y = *(f32*)(this_ + 0x10);
    f32 rect[4];
    rect[0] = x - c;
    rect[1] = y - c;
    rect[2] = x + c;
    rect[3] = y + c;
    fn_802397B4(rect, *(u32*)(this_ + 4), *(s32*)(this_ + 0x198));
}

extern "C" s32 fn_801E2F40(u8* this_) {
    s32 result = 0;
    u16 kind = fn_8022461C(this_ + 0xc, *(s32*)(this_ + 4));
    switch (kind) {
    case 3:
    case 13:
    case 14:
        result = 1;
        break;
    }
    return result;
}

