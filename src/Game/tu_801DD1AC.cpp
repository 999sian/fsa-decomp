#include "types.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Vec.h"
extern "C" s32 fn_801F285C(void*, void*, s32*, s32, s32);
extern "C" u8 fn_80235448(s32);
extern "C" f32* fn_8023E724(s32);
extern "C" s32 fn_8023B6CC(s32);
extern "C" void fn_80237948(s32, void*);
extern "C" u8 fn_801EAC20(void*, s32);
extern "C" void fn_801F0E34(void*, s32, s32);
extern "C" void fn_801E62D4(void*);
extern "C" void fn_801D9C58(void*, s32);
extern const u8 lbl_8053F1C8;
extern const f32 lbl_8053F38C;
extern const f32 lbl_8053F3B4;
extern const f32 lbl_8053F3B8;
extern const f32 lbl_8053F3BC;
extern const f32 lbl_8053F3C0;
extern f32 lbl_8053F3C4;
extern const f32 lbl_8053F3C8;

extern "C" u8 fn_801F37AC(void*, s32, void*, s32, s32, s32);
extern "C" void fn_801CB538(s32, void*, s32, s32);

static inline bool canHitPlayer(u8* p, s32 idx) {
    bool result = false;
    if (idx >= 0 && idx < 4 && !fn_80235448(idx)) {
        if (*(s32*)(p + 0x248) == 0x11) {
            result = true;
        } else if (lbl_8053F3C8 + fn_8023E724(idx)[1] >= *(f32*)(p + 0x10) + *(f32*)(p + 0x64)) {
            switch (*(s32*)(p + 0x248)) {
            case 12:
                result = true;
                break;
            case 11: case 13: case 14:
                if (fn_8023E724(idx)[1] - lbl_8053F3C8 > *(f32*)(p + 0x10) + *(f32*)(p + 0x6c)) {
                    result = true;
                } else if (*(u32*)(p + 0x230) & 0x2000) {
                    if (*(f32*)(p + 0xc) < fn_8023E724(idx)[0]) result = true;
                } else if (fn_8023E724(idx)[0] < *(f32*)(p + 0xc)) {
                    result = true;
                }
                break;
            default:
                break;
            }
        }
    }
    return result;
}

static inline void onPlayerHit(u8* p) {
    *(s32*)(p + 0xf8) = 0;
    f32 zero = lbl_8053F38C;
    *(f32*)(p + 0x44) = zero;
    *(f32*)(p + 0x14) = zero;
    fn_801F0E34(p, 0x40005, 0);
    fn_801E62D4(p);
    if (*(s32*)(p + 0x248) != 0x11) {
        ++p[0x33f];
        if (p[0x33f] >= lbl_8053F1C8) {
            f32 vx = *(f32*)(p + 0x3c);
            f32 scale = 2.0f;
            *(f32*)(p + 0x3c) = vx * scale;
            *(f32*)(p + 0x40) *= scale;
            fn_801D9C58(p, 15);
        }
    }
}
extern const f32 lbl_8053F3A4;
extern const f32 lbl_8053F3A8;
extern const f32 lbl_8053F3AC;
extern const f32 lbl_8053F3B0;
extern "C" void fn_801D9C58(void*, s32);

extern f32 lbl_8053F388;
extern const f32 lbl_8053F38C;
extern f32 lbl_8053F390;
extern f32 lbl_8053F394;
extern f32 lbl_8053F398;
extern f32 lbl_8053F39C;
extern f32 lbl_8053F3A0;
extern "C" u8 fn_801DA904(void* p);
extern "C" s32 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" s32 fn_801DD1AC(u8* this_) {
    s32 result = 0;
    if (!(*(u32*)(this_ + 0x230) & 0x1000)) {
        if (*(f32*)(this_ + 0xc) < *(f32*)(this_ + 0x2d4)) {
            *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x2d4);
            result = 1;
            f32 b = lbl_8053F38C;
            f32 a = lbl_8053F388;
            *(f32*)(this_ + 0x264) = a;
            *(f32*)(this_ + 0x268) = b;
            *(f32*)(this_ + 0x26c) = b;
        } else if (*(f32*)(this_ + 0x2ec) < *(f32*)(this_ + 0xc)) {
            *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x2ec);
            result = 1;
            f32 b = lbl_8053F38C;
            f32 a = lbl_8053F390;
            *(f32*)(this_ + 0x264) = a;
            *(f32*)(this_ + 0x268) = b;
            *(f32*)(this_ + 0x26c) = b;
        }
        if (*(f32*)(this_ + 0x10) > *(f32*)(this_ + 0x2d0)) {
            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x2d0);
            result = 1;
            f32 b = lbl_8053F390;
            f32 a = lbl_8053F38C;
            *(f32*)(this_ + 0x264) = a;
            *(f32*)(this_ + 0x268) = b;
            *(f32*)(this_ + 0x26c) = a;
        } else if (*(s32*)(this_ + 0x248) < 0x11 && *(s32*)(this_ + 0x248) > 10 && *(f32*)(this_ + 0x10) < *(f32*)(this_ + 0x2d8)) {
            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x2d8);
            result = 1;
            f32 b = lbl_8053F388;
            f32 a = lbl_8053F38C;
            *(f32*)(this_ + 0x264) = a;
            *(f32*)(this_ + 0x268) = b;
            *(f32*)(this_ + 0x26c) = a;
        }
    }
    return result;
}

extern "C" s32 fn_801DD28C(u8* this_) {
    s32 result = 0;
    f32 x0 = lbl_8053F388;
    f32 y0 = x0;
    f32 x1 = lbl_8053F390;
    f32 y1 = x1;
    switch (*(s32*)(this_ + 0x248)) {
    case 9:
        x0 = lbl_8053F394;
        y0 = lbl_8053F398;
        x1 = lbl_8053F39C;
        y1 = lbl_8053F3A0;
        if (x1 - x0 > lbl_8053F38C && (*(u32*)(this_ + 0x230) & 0x2000) && fn_801DA904(this_ + 0x2a8)) {
            f32 tmp = x0;
            x0 = -x1;
            x1 = -tmp;
        }
        if (x1 - x0 > lbl_8053F38C && y1 - y0 > lbl_8053F38C) {
            f32 sx0 = *(f32*)(this_ + 0x60);
            f32 sy0 = *(f32*)(this_ + 0x64);
            f32 sx1 = *(f32*)(this_ + 0x68);
            f32 sy1 = *(f32*)(this_ + 0x6c);
            *(f32*)(this_ + 0x60) = x0;
            *(f32*)(this_ + 0x64) = y0;
            *(f32*)(this_ + 0x68) = x1;
            *(f32*)(this_ + 0x6c) = y1;
            result = fn_801F2B7C(this_, *(s32*)(this_ + 0x114), -1, 1);
            *(f32*)(this_ + 0x60) = sx0;
            *(f32*)(this_ + 0x64) = sy0;
            *(f32*)(this_ + 0x68) = sx1;
            *(f32*)(this_ + 0x6c) = sy1;
        }
        break;
    default:
        break;
    }
    return result;
}

extern "C" u8 fn_801DD410(u8* p) {
    u8 hit = 0;
    s32 i;
    u8 effect;
    s32 hitType;
    f32 contact[2];
    bool check = false;
    switch (*(s32*)(p + 0x248)) {
    case 4: case 6: case 7: check = true; break;
    case 5: default: break;
    }
    if (check) {
        f32 x0 = *(f32*)(p + 0x60);
        f32 y0 = *(f32*)(p + 0x64);
        f32 x1 = *(f32*)(p + 0x68);
        f32 y1 = *(f32*)(p + 0x6c);
        *(f32*)(p + 0x60) = lbl_8053F3A4;
        *(f32*)(p + 0x64) = lbl_8053F3A8;
        *(f32*)(p + 0x68) = lbl_8053F3AC;
        *(f32*)(p + 0x6c) = lbl_8053F3B0;
        if (fn_801F285C(p, 0, 0, 1, -1) >= 0) fn_801D9C58(p, 5);
        *(f32*)(p + 0x60) = x0;
        *(f32*)(p + 0x64) = y0;
        *(f32*)(p + 0x68) = x1;
        *(f32*)(p + 0x6c) = y1;
    }
    switch (*(s32*)(p + 0x248)) {
    case 0x11: {
        f32 x0 = *(f32*)(p + 0x60);
        f32 y0 = *(f32*)(p + 0x64);
        f32 x1 = *(f32*)(p + 0x68);
        f32 y1 = *(f32*)(p + 0x6c);
        *(f32*)(p + 0x60) = lbl_8053F3B4;
        *(f32*)(p + 0x64) = lbl_8053F3B8;
        *(f32*)(p + 0x68) = lbl_8053F3BC;
        *(f32*)(p + 0x6c) = lbl_8053F3C0;
        if (*(f32*)(p + 0x68) - *(f32*)(p + 0x60) > lbl_8053F38C &&
            (*(u32*)(p + 0x230) & 0x2000) && fn_801DA904(p + 0x2a8)) {
            f32 lo = *(f32*)(p + 0x60);
            f32 hi = *(f32*)(p + 0x68);
            *(f32*)(p + 0x60) = -hi;
            *(f32*)(p + 0x68) = -lo;
        }
        for (i = 0; i < 4; ++i) {
            if (i == fn_801F285C(p, 0, &hitType, 1, i) && fn_80235448(i) &&
                fn_801F37AC(p, 0, fn_8023E724(i), 0, hitType, i)) {
                hit = 1;
                break;
            }
        }
        if (hit) {
            *(s32*)(p + 0x108) = 0;
            onPlayerHit(p);
            fn_801D9C58(p, 19);
        }
        *(f32*)(p + 0x60) = x0;
        *(f32*)(p + 0x64) = y0;
        *(f32*)(p + 0x68) = x1;
        *(f32*)(p + 0x6c) = y1;
        if (!hit && *(f32*)(p + 0x68) - *(f32*)(p + 0x60) > lbl_8053F38C &&
            *(f32*)(p + 0x6c) - *(f32*)(p + 0x64) > lbl_8053F38C) {
            for (i = 0; i < 4; ++i) {
                if (i == fn_801F285C(p, 0, &hitType, 1, i) && canHitPlayer(p, i)) {
                    if (fn_801F37AC(p, fn_8023B6CC(i), fn_8023E724(i), 0, hitType, i)) hit = 1;
                }
            }
            if (hit) {
                onPlayerHit(p);
                if (*(s32*)(p + 0x108) <= 0) fn_801D9C58(p, 19);
            }
        }
        break;
    }
    case 11: case 12: case 13: case 14:
        if (*(f32*)(p + 0x68) - *(f32*)(p + 0x60) > lbl_8053F38C &&
            *(f32*)(p + 0x6c) - *(f32*)(p + 0x64) > lbl_8053F38C) {
            effect = 0;
            for (i = 0; i < 4; ++i) {
                if (i == fn_801F285C(p, contact, &hitType, 1, i)) {
                    fn_8023B6CC(i);
                    if (canHitPlayer(p, i)) {
                        if (fn_801F37AC(p, 0, fn_8023E724(i), 0, hitType, i)) hit = 1;
                    } else {
                        fn_80237948(i, p + 0xc);
                        if (hitType == 1 && fn_801EAC20(p + 0x1dc, i)) {
                            JGeometry::TVec3f pos(contact[0], contact[1], lbl_8053F38C);
                            fn_801CB538(*(s32*)(p + 4), &pos, 0, 0);
                            effect = 1;
                        }
                    }
                }
            }
            if (effect) fn_801F0E34(p, 0x400d1, 0);
            if (hit) onPlayerHit(p);
        }
        break;
    default:
        break;
    }
    return hit;
}

extern "C" void* fn_801F856C();
extern "C" s32 fn_801F82CC(void*, void*, u8, f32);
extern "C" void* fn_801F666C(void*, s32);
extern "C" u8 fn_801F37AC(void*, s32, void*, s32, s32, s32);
extern "C" void fn_801F0E34(void*, s32, s32);
extern "C" void fn_801E62D4(void*);
extern "C" u8 fn_801EAC54(void*, s32);
extern "C" void fn_801CB538(s32, void*, s32, s32);
extern "C" void* fn_8013CC50(s32, void*, f32, s32, s32, s32, s32, s32, s32);
extern f32 lbl_8053F3CC;
extern f32 lbl_8053F3C4;
extern f64 lbl_8053F3D0;
extern const u8 lbl_8053F1C8;
static inline u8 canHitFire(u8* p, u8* other) {
    switch (*(s32*)(other + 0x1a0)) {
    case 'SWBM': case 'FIRE': break;
    default: return 0;
    }
    if (*(s32*)(p + 0x248) == 0x11) return 1;
    u8 result = 0;
    if (!(*(f32*)(other + 0x40) > lbl_8053F38C)) {
        switch (*(s32*)(p + 0x248)) {
        case 12: result = 1; break;
        case 11: case 13: case 14:
            if (*(f32*)(other + 0x40) < 0.0f) result = 1;
            else if (*(u32*)(p + 0x230) & 0x2000) {
                if (*(f32*)(other + 0x3c) < lbl_8053F3D0) result = 1;
            } else if (*(f32*)(other + 0x3c) > lbl_8053F3D0) result = 1;
            break;
        default: break;
        }
    }
    return result;
}

extern "C" u8 fn_801DDBE4(u8* p) {
    u8 hit = 0;
    bool check = false;
    switch (*(s32*)(p + 0x248)) {
    case 4: case 6: case 7: check = true; break;
    case 5: default: break;
    }
    if (check) {
        f32 x0 = *(f32*)(p + 0x60);
        f32 y0 = *(f32*)(p + 0x64);
        f32 x1 = *(f32*)(p + 0x68);
        f32 y1 = *(f32*)(p + 0x6c);
        *(f32*)(p + 0x60) = -40.0f;
        *(f32*)(p + 0x64) = -16.0f;
        *(f32*)(p + 0x68) = 40.0f;
        *(f32*)(p + 0x6c) = 50.0f;
        s32 found = fn_801F82CC(fn_801F856C(), p, p[0x195], lbl_8053F3CC);
        if (found >= 0 && found != *(s32*)(p + 0x198)) fn_801D9C58(p, 5);
        *(f32*)(p + 0x60) = x0;
        *(f32*)(p + 0x64) = y0;
        *(f32*)(p + 0x68) = x1;
        *(f32*)(p + 0x6c) = y1;
    }
    if (*(f32*)(p + 0x68) - *(f32*)(p + 0x60) > lbl_8053F38C &&
        *(f32*)(p + 0x6c) - *(f32*)(p + 0x64) > lbl_8053F38C) {
        s32 found = fn_801F82CC(fn_801F856C(), p, p[0x195], lbl_8053F3CC);
        if (found >= 0 && found != *(s32*)(p + 0x198)) {
            u8* other = (u8*)fn_801F666C(fn_801F856C(), found);
            if ((u8)canHitFire(p, other)) {
                s32 oldPriority = *(s32*)(p + 0x108);
                JGeometry::TVec3f pos = *(JGeometry::TVec3f*)(p + 0xc);
                pos -= *(JGeometry::TVec3f*)(other + 0x3c);
                if (fn_801F37AC(p, *(s32*)(other + 0x118), &pos, 0, *(s32*)(other + 0x168), *(s32*)(other + 0x110)) &&
                    oldPriority != *(s32*)(p + 0x108)) {
                    hit = 1;
                    if (*(s32*)(p + 0x248) != 0x11) *(s32*)(p + 0x108) = oldPriority;
                }
            }
            if (hit) {
                *(s32*)(p + 0xf8) = 0;
                f32 zero = 0.0f;
                *(f32*)(p + 0x44) = zero;
                *(f32*)(p + 0x14) = zero;
                fn_801F0E34(p, 0x40005, 0);
                fn_801E62D4(p);
                if (*(s32*)(p + 0x248) != 0x11) {
                    ++p[0x33f];
                    if (p[0x33f] >= lbl_8053F1C8) {
                        f32 vx = *(f32*)(p + 0x3c);
                        f32 scale = 2.0f;
                        *(f32*)(p + 0x3c) = vx * scale;
                        *(f32*)(p + 0x40) *= scale;
                        fn_801D9C58(p, 15);
                    }
                }
                if (*(s32*)(p + 0x108) <= 0) fn_801D9C58(p, 19);
            } else if (fn_801EAC54(p + 0x1dc, *(s32*)(other + 0x198))) {
                fn_801F0E34(p, 0x400d1, 0);
                switch (*(u32*)(other + 0x1a0)) {
                case 'SWBM': fn_801CB538(*(s32*)(p + 4), other + 0xc, 0, 0); break;
                case 'FIRE':
                    fn_801CB538(*(s32*)(p + 4), other + 0xc, 0, 0);
                    fn_8013CC50(*(s32*)(p + 4), other + 0xc, lbl_8053F388, 0x19d, 0, 0, 0, 0, 1);
                    break;
                }
            }
            other[0x164] = 1;
        }
    }
    return hit;
}

extern "C" s32 fn_8023AE34(f32* pos, s32 arg, f32* out);
extern "C" s32 fn_8023AA18(f32* pos, s32 arg, f32* out);
extern "C" s32 fn_8023AC74(f32* pos, s32 arg, f32* out);
extern "C" s32 fn_8023AD54(f32* pos, s32 arg, f32* out);
extern "C" void fn_801D9C58(void* this_, s32 state);
extern const f32 lbl_8053F3B0;
extern const f32 lbl_8053F3A8;
extern const f32 lbl_8053F3AC;
extern const f32 lbl_8053F3A4;
extern "C" s32 fn_801DE018(char* this_) {
    s32 r = 0;
    s32 state = *(s32*)(this_ + 0x248);
    bool ok = false;
    if (state != 5) {
        if (state < 5) {
            if (state < 4) {
                goto skip;
            }
        } else if (state > 7) {
            goto skip;
        }
        ok = true;
    }
skip:
    if (ok) {
        f32 tmp[2];
        f32 pos[4];
        s32 res;
        pos[0] = lbl_8053F3A4 + *(f32*)(this_ + 0xc);
        pos[1] = lbl_8053F3A8 + *(f32*)(this_ + 0x10);
        pos[2] = lbl_8053F3AC + *(f32*)(this_ + 0xc);
        pos[3] = lbl_8053F3B0 + *(f32*)(this_ + 0x10);
        res = fn_8023AE34(pos, *(s32*)(this_ + 4), tmp);
        if (res >= 0) {
            res = fn_8023AA18(pos, *(s32*)(this_ + 4), tmp);
            if (res >= 0) {
                res = fn_8023AC74(pos, *(s32*)(this_ + 4), tmp);
                if (res >= 0) {
                    res = fn_8023AD54(pos, *(s32*)(this_ + 4), tmp);
                }
            }
        }
        if (res >= 0) {
            fn_801D9C58(this_, 5);
            r = 1;
        }
    }
    return r;
}

extern f32 lbl_8053F398;
extern const f32 lbl_8053F3B4;
extern const f32 lbl_8053F3C0;
extern const f32 lbl_8053F3C8;
extern f32 lbl_8053F3D8;
extern f32 lbl_8053F3DC;
extern f32 lbl_8053F3E0;
extern f32 lbl_8053F3E4;
extern f32 lbl_8053F3E8;
extern f32 lbl_8053F3EC;
extern f32 lbl_8053F3F0;
extern f32 lbl_8053F3F4;
extern f32 lbl_8053F3F8;
extern f32 lbl_8053F3FC;
extern f32 lbl_8053F400;
extern f32 lbl_8053F404;
extern f32 lbl_8053F408;
extern f32 lbl_8053F40C;
extern f32 lbl_8053F410;
extern f32 lbl_8053F414;
extern f32 lbl_8053F418;
extern f32 lbl_8053F41C;
extern f32 lbl_8053F420;
extern f32 lbl_8053F424;
extern f32 lbl_8053F428;
extern f32 lbl_8053F42C;
extern f32 lbl_8053F430;
extern f32 lbl_8053F434;
extern f32 lbl_8053F438;
extern f32 lbl_8053F43C;
extern f32 lbl_8053F440;
extern f32 lbl_8053F444;
extern f32 lbl_8053F448;
extern "C" u8 fn_801DA904(void* p);
extern "C" s32 fn_801DA96C(void* p);
extern "C" void fn_801DE12C(u8* this_) {
    s32 state = *(s32*)(this_ + 0x248);
    s32 frame;

    if (state >= 0x13) {
        if (state >= 0x15) {
            goto frame_anim;
        }
    } else if (state >= 4 || state < 0) {
        goto frame_anim;
    }

    *(f32*)(this_ + 0x60) = 1.0f;
    *(f32*)(this_ + 0x64) = 1.0f;
    *(f32*)(this_ + 0x68) = -1.0f;
    *(f32*)(this_ + 0x6c) = -1.0f;
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
    return;

frame_anim:
    frame = fn_801DA96C(this_ + 0x2a8);
    switch (frame) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 11: case 12:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -16.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 16.0f;
        break;
    case 6: case 7:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -22.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 10.0f;
        break;
    case 8:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -25.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 7.0f;
        break;
    case 9:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -28.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 4.0f;
        break;
    case 10:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -31.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 1.0f;
        break;
    case 13: case 14: case 15: case 16:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -48.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 16.0f;
        break;
    case 17: case 23:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -40.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 16.0f;
        break;
    case 18: case 19: case 20: case 21: case 22:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -32.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 16.0f;
        break;
    case 24:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -52.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 16.0f;
        break;
    case 25:
        *(f32*)(this_ + 0x60) = -41.0f;
        *(f32*)(this_ + 0x64) = -41.0f;
        *(f32*)(this_ + 0x68) = 6.0f;
        *(f32*)(this_ + 0x6c) = 9.0f;
        break;
    case 26:
        *(f32*)(this_ + 0x60) = -41.0f;
        *(f32*)(this_ + 0x64) = -47.0f;
        *(f32*)(this_ + 0x68) = 6.0f;
        *(f32*)(this_ + 0x6c) = 3.0f;
        break;
    case 27:
        *(f32*)(this_ + 0x60) = -38.0f;
        *(f32*)(this_ + 0x64) = -61.0f;
        *(f32*)(this_ + 0x68) = 8.0f;
        *(f32*)(this_ + 0x6c) = -8.0f;
        break;
    case 28:
        *(f32*)(this_ + 0x60) = -38.0f;
        *(f32*)(this_ + 0x64) = -66.0f;
        *(f32*)(this_ + 0x68) = 10.0f;
        *(f32*)(this_ + 0x6c) = -12.0f;
        break;
    case 29:
        *(f32*)(this_ + 0x60) = -35.0f;
        *(f32*)(this_ + 0x64) = -68.0f;
        *(f32*)(this_ + 0x68) = 14.0f;
        *(f32*)(this_ + 0x6c) = -16.0f;
        break;
    case 30:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -72.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = -36.0f;
        break;
    case 31:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -76.0f;
        *(f32*)(this_ + 0x68) = 28.0f;
        *(f32*)(this_ + 0x6c) = -36.0f;
        break;
    case 32:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -68.0f;
        *(f32*)(this_ + 0x68) = 28.0f;
        *(f32*)(this_ + 0x6c) = -28.0f;
        break;
    case 33:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -60.0f;
        *(f32*)(this_ + 0x68) = 28.0f;
        *(f32*)(this_ + 0x6c) = -20.0f;
        break;
    case 34: case 35: case 36: case 37: case 38: case 39: case 40:
    case 41: case 42: case 43: case 44: case 45: case 46: case 47:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -36.0f;
        *(f32*)(this_ + 0x68) = 28.0f;
        *(f32*)(this_ + 0x6c) = 16.0f;
        break;
    }

    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > 0.0f &&
        (*(u32*)(this_ + 0x230) & 0x2000) && fn_801DA904(this_ + 0x2a8)) {
        f32 x0 = *(f32*)(this_ + 0x60);
        f32 x1 = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x60) = -x1;
        *(f32*)(this_ + 0x68) = -x0;
    }
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
}

void __sinit_tu_801DD1AC_cpp(void) {}

