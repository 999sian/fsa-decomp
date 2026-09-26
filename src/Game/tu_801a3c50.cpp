// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801A3C50-801A6690 (unknown). Remaining functions are not yet decompiled.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "std/math.h"

class SayaActor {
public:
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44();
};

extern "C" void fn_801F4694(void* this_);
extern s32 lbl_8053A100;

static inline void Saya_setTarget(u8* this_, s32 id) {
    *(s32*)(this_ + 0x108) = 0;
    *(s32*)(this_ + 0x10C) = id;
    JGeometry::TVec3<f32> v(1.4f, 0.4f, 0.4f);
    *(s32*)(this_ + 0xA0) = id;
    *(JGeometry::TVec3<f32>*)(this_ + 0x48) = v;
    *(s32*)(this_ + 0xD8) = 0;
    *(s32*)(this_ + 0xDC) = 0;
    *(s32*)(this_ + 0xA4) = 0;
    fn_801F4694(this_);
    if (*(s32*)(this_ + 4) >= 8) {
        *(s32*)(this_ + 0xA8) = 0x1E;
    } else {
        *(s32*)(this_ + 0xA8) = 0x23;
    }
    lbl_8053A100 = id;
    ((SayaActor*)this_)->v44();
}

extern "C" void fn_801A3C50(u8* this_, s32 id) {
    Saya_setTarget(this_, id);
}

// from src/Game/Saya_ForceState1_801A46FC.cpp
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* base, u32 id);
extern "C" s32 fn_801A41D8(void* this_, void* a4, void* a5);

// SAYA cluster, part 4/18 (88B). Vtable-slot wrapper that directly
// invokes state-handler fn_801A41D8 (an external "force-run this
// specific behavior" entry point, separate from the update() dispatch
// chain through fn_801A6160). Return value is passed through to callers
// that check it (e.g. extab_80145f60.s).
extern "C" s32 fn_801A46FC(void* this_, void* a4, void* a5) {
    void* base = fn_801F856C();
    void* target = fn_801F666C(base, (u32)this_);
    return fn_801A41D8(target, a4, a5);
}

// from src/Game/Saya_ForceState2_801A4D1C.cpp
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* base, u32 id);
extern "C" s32 fn_801A4754(void* this_, void* a4, void* a5);

// SAYA cluster, part 6/18 (88B). Vtable-slot wrapper directly invoking
// state-handler fn_801A4754 (same external-entry-point pattern as
// fn_801A46FC). Return value is passed through to callers that check it.
extern "C" s32 fn_801A4D1C(void* this_, void* a4, void* a5) {
    void* base = fn_801F856C();
    void* target = fn_801F666C(base, (u32)this_);
    return fn_801A4754(target, a4, a5);
}

extern "C" u8* fn_802D6A9C(void);
extern "C" s32 fn_8023AA18(void* a, s32 room, void* b);
extern "C" s32 fn_8023B520(void);
extern "C" void* fn_8023E724(s32 player);
extern "C" void fn_801F37AC(void* this_, s32 a, void* pos, s32 b, s32 c, s32 d);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 flag);

extern "C" s32 fn_801A4D74(u8* this_, void* a4, void* a5) {
    s32 room; u8* mgr; s32 t; s32 kind; s32 id;
    kind = (*(u32*)(this_ + 0xB0) >> 8) & 0xF;
    if (kind == 0) {
        return 0;
    }
    room = *(s32*)(this_ + 4);
    mgr = fn_802D6A9C();
    if (mgr[room + 0x131DF] == 0 && *(f32*)(this_ + 0x14) > 32.0f) {
        return 0;
    }
    id = fn_8023AA18(a4, *(s32*)(this_ + 4), a5);
    if (id < 0) {
        return 0;
    }
    if (kind != 3) {
        if (*(s32*)(this_ + 0xD8) == 0) {
            t = *(s32*)(this_ + 0x108);
            s32 d = t - fn_8023B520();
            *(s32*)(this_ + 0x10C) = id;
            if (d <= 0) {
                d = 0;
                if (*(s32*)(this_ + 0xBC) != 3) {
                    Saya_setTarget(this_, id);
                    return 0x28;
                }
            }
            *(s32*)(this_ + 0x108) = d;
            fn_801F37AC(this_, 0, fn_8023E724(id), 0, 4, -1);
            if (*(s32*)(this_ + 0xBC) == 3) {
                *(JGeometry::TVec3<f32>*)(this_ + 0x3C) = JGeometry::TVec3<f32>(0.0f, 0.0f, 0.0f);
            }
            if (id >= 0) {
                lbl_8053A100 = id;
            }
            ((SayaActor*)this_)->v44();
        }
    } else {
        return 0xFF;
    }
    fn_801F0E34(this_, 0x4001E, 0);
    return 0x1E;
}

// from src/Game/Saya_ForceState3_801A4F5C.cpp
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* base, u32 id);
extern "C" s32 fn_801A4D74(u8* this_, void* a4, void* a5);

// SAYA cluster, part 8/18 (88B). Vtable-slot wrapper directly invoking
// state-handler fn_801A4D74 (same external-entry-point pattern). Return
// value is passed through to callers that check it.
#pragma dont_inline on
extern "C" s32 fn_801A4F5C(void* this_, void* a4, void* a5) {
    void* base = fn_801F856C();
    void* target = fn_801F666C(base, (u32)this_);
    return fn_801A4D74((u8*)target, a4, a5);
}
#pragma dont_inline reset

struct SayaRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct SayaGame { u8 pad[0xb4]; SayaRandom rnd; };
extern SayaGame* lbl_8053AAF8;
extern "C" u8 fn_8023F264(s32 player);
extern "C" s32 fn_8023DE58(s32 player);
extern "C" u8 fn_8023A51C(s32 player);
extern "C" s32 fn_8023725C(s32 player);
extern "C" f32* fn_8023A478(s32 player);
extern "C" void fn_801F3780(void* this_, s32 a);

extern "C" s32 fn_801A4FB4(u8* this_) {
    s32 room;
    s32 i;
    s32 mode = (*(u32*)(this_ + 0xB0) >> 12) & 0xF;
    if (mode == 0) {
        return 0;
    }
    if (*(u8*)(this_ + 0xD4) == 0) {
        f32 range = 0.0f;
        for (i = 0; i < 4; i++) {
            if (!fn_8023F264(i)) {
                continue;
            }
            room = *(s32*)(this_ + 4);
            if (room == fn_8023DE58(i) && fn_8023A51C(i) && *(f32*)(this_ + 0x14) == 0.0f) {
                if (fn_8023725C(i) == 1) {
                    range = 50.0f;
                } else if (fn_8023725C(i) == 2) {
                    range = 777.0f;
                }
                if (range > 0.0f) {
                    f32 dx = fn_8023A478(i)[0] - *(f32*)(this_ + 0xC);
                    f32 dy = fn_8023A478(i)[1] - *(f32*)(this_ + 0x10);
                    f32 d = std::sqrtf(dx * dx + dy * dy);
                    if (d < range || range == 777.0f) {
                        *(u8*)(this_ + 0xD4) = 1;
                        if (i >= 0) {
                            lbl_8053A100 = i;
                        }
                        ((SayaActor*)this_)->v44();
                    }
                }
            }
        }
    }
    f32 vz = 0.0f;
    if (*(u8*)(this_ + 0xD4) == 1) {
        switch (mode) {
        case 1:
            vz = 5.0f + (1.0f - 2.0f * lbl_8053AAF8->rnd.get_ufloat_1());
            break;
        case 2:
            vz = 2.0f + (1.0f - 2.0f * lbl_8053AAF8->rnd.get_ufloat_1());
            break;
        case 3:
            if (*(s32*)(this_ + 0x108) - 10 <= 0) {
                *(s32*)(this_ + 0x108) = 0;
            }
            *(u8*)(this_ + 0xD4) = 0;
            break;
        }
        *(JGeometry::TVec3<f32>*)(this_ + 0x3C) = JGeometry::TVec3<f32>(*(f32*)(this_ + 0x3C), *(f32*)(this_ + 0x40), vz);
        *(u8*)(this_ + 0xD4) = 2;
    }
    if (*(u8*)(this_ + 0xD4) == 2) {
        *(JGeometry::TVec3<f32>*)(this_ + 0xC) = JGeometry::TVec3<f32>(*(f32*)(this_ + 0xC), *(f32*)(this_ + 0x10), *(f32*)(this_ + 0x14) + *(f32*)(this_ + 0x44));
        *(JGeometry::TVec3<f32>*)(this_ + 0x3C) = JGeometry::TVec3<f32>(*(f32*)(this_ + 0x3C), *(f32*)(this_ + 0x40), *(f32*)(this_ + 0x44) - 0.5f);
        if (*(f32*)(this_ + 0x14) <= 0.0f) {
            *(JGeometry::TVec3<f32>*)(this_ + 0x3C) = JGeometry::TVec3<f32>(*(f32*)(this_ + 0x3C), *(f32*)(this_ + 0x40), 0.0f);
            *(JGeometry::TVec3<f32>*)(this_ + 0xC) = JGeometry::TVec3<f32>(*(f32*)(this_ + 0xC), *(f32*)(this_ + 0x10), 0.0f);
            *(u8*)(this_ + 0xD4) = 0;
            if ((s32)((*(u32*)(this_ + 0xB0) >> 16) & 0xFF) == 1) {
                fn_801F3780(this_, 0x12C);
            }
        }
    }
    return *(u8*)(this_ + 0xD4);
}

// from src/Game/Saya_ForceState4_801A6108.cpp
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* base, u32 id);
extern "C" s32 fn_801A5400(void* this_, void* a4, void* a5);

// SAYA cluster, part 11/18 (88B). Vtable-slot wrapper directly invoking
// state-handler fn_801A5400 (same external-entry-point pattern). Return
// value is passed through to callers that check it.
extern "C" s32 fn_801A6108(void* this_, void* a4, void* a5) {
    void* base = fn_801F856C();
    void* target = fn_801F666C(base, (u32)this_);
    return fn_801A5400(target, a4, a5);
}

static u8 lbl_804C6640[0x30];

extern "C" f32 fn_801EE4F0(void);
extern "C" void* fn_8013CC50(s32 id, void* pos, s32 kind, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" u8 fn_802242F4(void* this_);
extern "C" u8 fn_801F305C(void* this_);
extern "C" void fn_801F2618(void* this_, s32 a, s32 b);

struct SayaOfs;
struct SayaBox {
    inline void add(const SayaOfs& o);
    f32 x0, y0, x1, y1;
};
struct SayaOfs {
    SayaOfs(f32 ax, f32 ay) { x = ax; y = ay; }
    f32 x, y;
};
inline void SayaBox::add(const SayaOfs& o) {
    x0 += o.x;
    y0 += o.y;
    x1 += o.x;
    y1 += o.y;
}

// SAYA update
extern "C" s32 fn_801A6160(u8* this_) {
    s32 cnt;
    s32 res = 0;
    SayaBox box;
    box.x0 = ((SayaBox*)(this_ + 0x70))->x0;
    box.y0 = ((SayaBox*)(this_ + 0x70))->y0;
    box.x1 = ((SayaBox*)(this_ + 0x70))->x1;
    box.y1 = ((SayaBox*)(this_ + 0x70))->y1;
    SayaOfs ofs(*(f32*)(this_ + 0xC), *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x14));
    cnt = *(s32*)(this_ + 0xA8);
    if (cnt != 0) {
        if (cnt == 0x1E) {
            f32 sc = fn_801EE4F0();
            if (sc < 1.0f) {
                sc = 1.0f;
            }
            fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xC, 0x17C, 0, 1, 0, 0, 1, sc);
        }
        if (cnt - 1 <= 0) {
            ((SayaActor*)this_)->v24();
        }
        *(s32*)(this_ + 0xA8) = cnt - 1;
        return 1;
    }
    if (*(s32*)(this_ + 0x108) > 0 && fn_802242F4(this_)) {
        return 1;
    }
    if (*(u32*)(this_ + 0xB0) == 0 || *(s32*)(this_ + 0x108) <= 0) {
        return 0;
    }
    lbl_8053A100 = -1;
    box.add(ofs);
    s32 r;
    if ((r = fn_801A5400(this_, &box, &ofs)) != 0) {
        res = 3;
    } else if ((r = fn_801A4D74(this_, &box, &ofs)) != 0) {
        res = 3;
    } else if ((r = fn_801A4754(this_, &box, &ofs)) != 0) {
        res = 1;
    } else if ((r = fn_801A41D8(this_, &box, &ofs)) == 0x32) {
        res = 1;
    }
    if (r == 0xFF) {
        return 0;
    }
    if (res <= 1 && fn_801A4FB4(this_)) {
        res = 2;
    }
    s32 a4 = *(s32*)(this_ + 0xA4);
    if (a4 != 0) {
        if (*(f32*)(this_ + 0x14) > 0.0f) {
            *(JGeometry::TVec3<f32>*)(this_ + 0x3C) = JGeometry::TVec3<f32>(*(f32*)(this_ + 0x3C), *(f32*)(this_ + 0x40), 0.0f);
            *(JGeometry::TVec3<f32>*)(this_ + 0xC) = JGeometry::TVec3<f32>(*(f32*)(this_ + 0xC), *(f32*)(this_ + 0x10), *(f32*)(this_ + 0x14) - 1.0f);
        } else {
            *(JGeometry::TVec3<f32>*)(this_ + 0xC) = JGeometry::TVec3<f32>(*(f32*)(this_ + 0xC), *(f32*)(this_ + 0x10), 0.0f);
        }
        *(s32*)(this_ + 0xA4) = a4 - 1;
        res = 1;
        if (fn_801F305C(this_)) {
            if (*(s32*)(this_ + 0xBC) == 3) {
                *(JGeometry::TVec3<f32>*)(this_ + 0x3C) = JGeometry::TVec3<f32>(0.0f, 0.0f, 0.0f);
            }
            res = 2;
            fn_801F2618(this_, 0, 0);
        }
    }
    if (res > 1) {
        *(s32*)(this_ + 0xA4) = 0;
    }
    return res;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
