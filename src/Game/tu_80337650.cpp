#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
#include "JSystem/JMath/JMath.h"
extern "C" u8 fn_801F6758(void* pos, u32 room, f32 r);
extern "C" void fn_80239914(f32* box, u32 room, s32 id);
extern "C" u8 fn_8023A30C(void);
extern "C" void fn_8022FEB8(f32* box, u32 room, s32 id, s32 a, s32 b);
extern "C" s32 fn_8022FD8C(s32 id);
extern "C" f32* fn_8023E724(s32 i);
extern "C" u8 fn_802300EC(s32 i);
extern "C" u8 fn_8038C678(s32 i, s32 a, s32 id, u32 room, JGeometry::TVec3<f32>* pos, s32 b);
static inline u8 TryLand(s32 i, s32 a, s32 id, u32 room, const JGeometry::TVec3<f32>& pos) {
    return fn_8038C678(i, a, id, room, (JGeometry::TVec3<f32>*)&pos, 0);
}
static inline u8 TryLandAt(s32 i, s32 a, s32 id, u32 room, JGeometry::TVec3<f32> pos) {
    return fn_8038C678(i, a, id, room, &pos, 0);
}
// Per-kind animation table at lbl_80471BB8 (0x10 bytes per kind).
struct AnimKindTbl {
    s32* idle;
    s32* move;
    s32* a08;
    s32* a0c;
};
extern char lbl_80471BB8[];
static inline AnimKindTbl* GetAnimKind(s32 kind) { return (AnimKindTbl*)(lbl_80471BB8 + (kind << 4)); }
static inline JGeometry::TVec3<f32> JumpVel(const f32* target, const f32* pos, f32 time, f32 vz) {
    return JGeometry::TVec3<f32>((target[0] - pos[0]) / time, (target[1] - pos[1]) / time, vz);
}
static inline s32 AnimMoveFirst(s32 kind) {
    const AnimKindTbl* __restrict base = (const AnimKindTbl*)lbl_80471BB8;
    return *base[kind].move;
}
static inline s32 AnimIdleFirst(s32 kind) {
    const AnimKindTbl* __restrict base = (const AnimKindTbl*)lbl_80471BB8;
    return *base[kind].idle;
}
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802DCD0C(void* mgr);
extern "C" void fn_802D79E8(void* mgr, u32 room, s32 a, f32 x, f32 y);
extern "C" u8 fn_80388CAC(s32 i, s32 id);
extern "C" void fn_80337A08(u8* this_);
extern "C" void fn_803376B0(u8* this_);
extern const f32 lbl_80542068;
extern const f32 lbl_8054206C;
extern const f32 lbl_80542070;
extern const f32 lbl_80542074;
extern const f32 lbl_80542078;

extern char lbl_80471BB8[];
extern u8* lbl_8053AAF8;
extern f32 lbl_80542058;
extern f32 lbl_8054205C;


extern "C" char lbl_804AC010[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE558(void* this_, void* p, f32* len, s32 p4);
extern f32 lbl_80542060;
extern f32 lbl_80542064;
extern "C" Actor* fn_80337650(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AC010;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

#pragma opt_propagation off
extern "C" void fn_803376B0(u8* this_) {
    *(s32*)(this_ + 0x234) = *(s32*)(this_ + 0x234) - 1;
    if (*(s32*)(this_ + 0x234) > 0) {
        return;
    }
    *(s32*)(this_ + 0x238) = *(s32*)(this_ + 0x238) + 1;
    switch (*(s32*)(this_ + 0x250)) {
    case 0:
    case 1:
    case 5:
    case 6:
    case 7:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14: {
        s32 mode = *(s32*)(this_ + 0x230);
        if (mode == 0) goto idle1;
        if (mode == 1) goto idle1;
        if (mode == 3) goto idle1;
        if (mode != 4) goto active1;
        idle1: {
            *(s32*)(this_ + 0x238) = *(s32*)(this_ + 0x238) & 1;
            *(s32*)(this_ + 0x234) = ((s32*)*(char**)(lbl_80471BB8 + *(s32*)(this_ + 0x250) * 16))[*(s32*)(this_ + 0x238)];
            break;
        }
        active1:
        if (mode == 5) {
            s32 kind;
            const AnimKindTbl* __restrict base;
            *(s32*)(this_ + 0x238) = *(s32*)(this_ + 0x238) & 3;
            kind = *(s32*)(this_ + 0x250);
            base = (const AnimKindTbl*)lbl_80471BB8;
            *(s32*)(this_ + 0x234) = base[kind].move[*(s32*)(this_ + 0x238)];
        }
        break;
    }
    case 2:
    case 3: {
        s32 mode = *(s32*)(this_ + 0x230);
        if (mode == 0) goto idle2;
        if (mode == 1) goto idle2;
        if (mode == 3) goto idle2;
        if (mode != 4) goto active2;
        idle2: {
            *(s32*)(this_ + 0x238) = *(s32*)(this_ + 0x238) & 3;
            *(s32*)(this_ + 0x234) = ((s32*)*(char**)(lbl_80471BB8 + *(s32*)(this_ + 0x250) * 16))[*(s32*)(this_ + 0x238)];
            break;
        }
        active2:
        if (mode == 5) {
            s32 kind;
            const AnimKindTbl* __restrict base;
            *(s32*)(this_ + 0x238) = *(s32*)(this_ + 0x238) & 3;
            kind = *(s32*)(this_ + 0x250);
            base = (const AnimKindTbl*)lbl_80471BB8;
            *(s32*)(this_ + 0x234) = base[kind].move[*(s32*)(this_ + 0x238)];
        }
        break;
    }
    case 4: {
        s32 mode = *(s32*)(this_ + 0x230);
        if (mode == 0) goto idle3;
        if (mode == 1) goto idle3;
        if (mode == 3) goto idle3;
        if (mode != 4) goto active3;
        idle3: {
            *(s32*)(this_ + 0x238) = *(s32*)(this_ + 0x238) & 1;
            *(s32*)(this_ + 0x234) = ((s32*)*(char**)(lbl_80471BB8 + *(s32*)(this_ + 0x250) * 16))[*(s32*)(this_ + 0x238)];
            break;
        }
        active3:
        if (mode == 5) {
            if (*(s32*)(this_ + 0x248) < 2) {
                *(s32*)(this_ + 0x238) = *(s32*)(this_ + 0x238) & 1;
                *(s32*)(this_ + 0x234) = ((s32*)*(char**)(lbl_80471BB8 + *(s32*)(this_ + 0x250) * 16))[*(s32*)(this_ + 0x238)];
            } else {
                s32 kind;
                const AnimKindTbl* __restrict base;
                *(s32*)(this_ + 0x238) = *(s32*)(this_ + 0x238) & 3;
                kind = *(s32*)(this_ + 0x250);
                base = (const AnimKindTbl*)lbl_80471BB8;
                *(s32*)(this_ + 0x234) = base[kind].move[*(s32*)(this_ + 0x238)];
            }
        }
        break;
    }
    case 8:
    case 9:
    case 15: {
        s32 mode = *(s32*)(this_ + 0x230);
        if (mode == 0) goto idle4;
        if (mode == 1) goto idle4;
        if (mode == 3) goto idle4;
        if (mode != 4) goto active4;
        idle4: {
            *(s32*)(this_ + 0x238) = *(s32*)(this_ + 0x238) & 1;
            *(s32*)(this_ + 0x234) = ((s32*)*(char**)(lbl_80471BB8 + *(s32*)(this_ + 0x250) * 16))[*(s32*)(this_ + 0x238)];
            break;
        }
        active4:
        if (mode == 5) {
            s32 kind;
            const AnimKindTbl* __restrict base;
            *(s32*)(this_ + 0x238) = *(s32*)(this_ + 0x238) & 1;
            kind = *(s32*)(this_ + 0x250);
            base = (const AnimKindTbl*)lbl_80471BB8;
            *(s32*)(this_ + 0x234) = base[kind].move[*(s32*)(this_ + 0x238)];
        }
        break;
    }
    }

    if (*(s32*)(this_ + 0x238) == 0) {
        f32 one;
        f32 random;
        f32 range;
        one = lbl_8054205C;
        range = lbl_80542058;
        u32* seed = (u32*)(lbl_8053AAF8 + 0xb4);
        *seed = *seed * 0x19660du + 0x3c6ef35fu;
        u32 bits = (*seed >> 9) | 0x3f800000u;
        random = *(f32*)&bits;
        *(s32*)(this_ + 0x234) += (s32)(range * (random - one));
    }
}
#pragma opt_propagation reset
extern "C" void fn_80337A08(u8* this_) {
    s32 state = *(s32*)(this_ + 0x250);
    s32 prev = *(s32*)(this_ + 0x248);

    switch (state) {
    case 5:
    case 6:
    case 14:
        *(s32*)(this_ + 0x248) = 0;
        return;
    }

    switch (*(s32*)(this_ + 0x230)) {
    case 0:
    case 1:
    case 4: {
        s32 timer = *(s32*)(this_ + 0x244);
        f32 v[3];
        f32 len;

        if (timer != 0) {
            *(s32*)(this_ + 0x244) = timer - 1;
            return;
        }
        *(s32*)(this_ + 0x244) = 0x14;
        fn_801EE558(this_, v, &len, 0);
        if (len < lbl_80542060) {
            f32 a = JMath::atanTable_.atan2_(-v[0], -v[1]);
            u16 ang = (s32)(a * lbl_80542064);
            if (ang < 0x2000 || ang >= 0xe000) {
                *(s32*)(this_ + 0x248) = 3;
            } else if (ang >= 0x2000 && ang < 0x6000) {
                *(s32*)(this_ + 0x248) = 1;
            } else if (ang >= 0x6000 && ang <= 0xa000) {
                *(s32*)(this_ + 0x248) = 2;
            } else {
                *(s32*)(this_ + 0x248) = 0;
            }
        } else {
            *(s32*)(this_ + 0x248) = 3;
        }
        break;
    }
    case 3:
    case 5: {
        s32 a = *(s32*)(this_ + 0x258);
        s32 b = *(s32*)(this_ + 0x25c);
        s32 a2 = a * a;
        s32 b2 = b * b;

        if (state != 14 && state >= 7 && state < 16) {
            if (a > 0) {
                *(s32*)(this_ + 0x248) = 0;
            } else {
                *(s32*)(this_ + 0x248) = 1;
            }
        } else if (a2 == 0 && b2 == 0) {
            *(s32*)(this_ + 0x248) = 2;
        } else if (a2 > b2) {
            if (a > 0) {
                *(s32*)(this_ + 0x248) = 0;
            } else {
                *(s32*)(this_ + 0x248) = 1;
            }
        } else {
            if (b > 0) {
                *(s32*)(this_ + 0x248) = 2;
            } else {
                *(s32*)(this_ + 0x248) = 3;
            }
        }
        if (*(s32*)(this_ + 0x230) == 5) {
            *(s32*)(this_ + 0x248) ^= 1;
        }
        break;
    }
    }

    if (*(s32*)(this_ + 0x250) == 4) {
        s32 cur = *(s32*)(this_ + 0x248);
        if ((cur >= 2 && prev < 2) || (cur < 2 && prev >= 2)) {
            *(s32*)(this_ + 0x238) = 0;
            *(s32*)(this_ + 0x234) = 0x14;
        }
    }
}

extern char lbl_80471BB8[];
extern f32 lbl_8054205C;
extern "C" void fn_801F06F0(void* this_, void* p, s32 id, u32 p4, s32 p5, f32 a, f32 b);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_80337C88(char* this_) {
    char* base = lbl_80471BB8;
    s32 state = *(s32*)(this_ + 0x230);
    if (state != 2) {
        char* t = base + 0x100;
        s32 idx = *(s32*)(this_ + 0x250);
        char* p = base + 0x194;
        s32 val;
        if (*(s32*)(t + idx * 8) == 2) {
            p = base + 0x180;
        }
        switch (state) {
        case 1:
            val = *(s32*)(t + idx * 8 + 4) +
                  *(s32*)(*(char**)(base + idx * 16 + 8) + *(s32*)(this_ + 0x248) * 16 + *(s32*)(this_ + 0x238) * 4);
            break;
        case 0:
        case 3:
        case 4:
        default:
            val = *(s32*)(t + idx * 8 + 4) +
                  *(s32*)(*(char**)(base + idx * 16 + 0xc) + *(s32*)(this_ + 0x248) * 16 + *(s32*)(this_ + 0x238) * 4);
            break;
        }
        if (*(s32*)(this_ + 0x250) == 2) {
            fn_801F06F0(this_, p, val, 0, 3, lbl_8054205C, lbl_8054205C);
        }
        if (*(s32*)(this_ + 0x250) < 4 && *(s32*)(this_ + 0x250) >= 0) {
            fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, val, 0, 2, -1, 0, 0, 0);
        }
    }
}

extern "C" void fn_80337DEC(u8* this_) {
    typedef JGeometry::TVec3<f32> V3;
    JGeometry::TBox2<f32> box = *(JGeometry::TBox2<f32>*)(this_ + 0x60);
    box.i.x = box.i.x - lbl_80542074;
    box.f.x = lbl_80542074 + box.f.x;
    if (*(s32*)(this_ + 0x254) == 1 &&
        (*(s32*)(this_ + 0x230) == 0 || *(s32*)(this_ + 0x230) == 4 || *(s32*)(this_ + 0x230) == 1)) {
        box.addPos(*(JGeometry::TVec2<f32>*)(this_ + 0x26c));
    } else {
        box.addPos(*(JGeometry::TVec2<f32>*)(this_ + 0xc));
    }
    if (*(s32*)(this_ + 0x230) != 2) {
        fn_80239914((f32*)&box, *(u32*)(this_ + 4), *(s32*)(this_ + 0x198));
    }
    ((V3*)(this_ + 0xc))->add(*(V3*)(this_ + 0x3c));

    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        if (*(u8*)(this_ + 0x268) == 0 && fn_8023A30C()) {
            *(V3*)(this_ + 0x3c) = JumpVel((f32*)(this_ + 0x278), (f32*)(this_ + 0xc), lbl_80542068, lbl_8054206C);
            *(f32*)(this_ + 0x260) = lbl_80542070;
            *(s32*)(this_ + 0x230) = 3;
        } else {
            fn_8022FEB8((f32*)&box, *(u32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
            *(s32*)(this_ + 0x24c) = fn_8022FD8C(*(s32*)(this_ + 0x198));
            if (*(s32*)(this_ + 0x24c) >= 0 && lbl_80542078 == fn_8023E724(*(s32*)(this_ + 0x24c))[2] &&
                fn_802300EC(*(s32*)(this_ + 0x24c))) {
                s32 id = *(s32*)(this_ + 0x198);
                u32 room = *(u32*)(this_ + 4);
                V3 pos = *(V3*)(this_ + 0xc);
                if (fn_8038C678(*(s32*)(this_ + 0x24c), *(s32*)(this_ + 0x264), id, room, &pos, 0)) {
                    *(s32*)(this_ + 0x230) = 4;
                }
            }
        }
        break;
    case 1:
        fn_8022FEB8((f32*)&box, *(u32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
        *(s32*)(this_ + 0x24c) = fn_8022FD8C(*(s32*)(this_ + 0x198));
        if (*(s32*)(this_ + 0x24c) >= 0) {
            if (lbl_80542078 != fn_8023E724(*(s32*)(this_ + 0x24c))[2]) {
                break;
            }
            if (!fn_802300EC(*(s32*)(this_ + 0x24c))) {
                break;
            }
            s32 id = *(s32*)(this_ + 0x198);
            u32 room = *(u32*)(this_ + 4);
            V3 pos = *(V3*)(this_ + 0xc);
            if (fn_8038C678(*(s32*)(this_ + 0x24c), *(s32*)(this_ + 0x264), id, room, &pos, 0)) {
                *(s32*)(this_ + 0x230) = 4;
                break;
            }
        }
    case 2:
        if ((u8)((Actor*)this_)->v11() == 1 && !fn_802DCD0C(fn_802D6A9C())) {
            *(s32*)(this_ + 0x254) = 1;
            *(s32*)(this_ + 0x23c) = ((*(u32*)(this_ + 0x90) >> 16) & 3) * 0x46 + 0x1e;
            *(V3*)(this_ + 0xc) = *(V3*)(this_ + 0x278);
            V3 v((*(f32*)(this_ + 0x24) - *(f32*)(this_ + 0xc)) / (f32)*(s32*)(this_ + 0x23c),
                 (*(f32*)(this_ + 0x28) - *(f32*)(this_ + 0x10)) / (f32)*(s32*)(this_ + 0x23c), lbl_80542078);
            *(V3*)(this_ + 0x3c) = v;
            *(s32*)(this_ + 0x240) = *(s32*)(this_ + 0x23c);
            *(s32*)(this_ + 0x230) = 5;
            *(s32*)(this_ + 0x238) = 0;
            switch (*(s32*)(this_ + 0x250)) {
            case 4:
                if (*(s32*)(this_ + 0x248) >= 2) {
                    *(s32*)(this_ + 0x234) = AnimMoveFirst(*(s32*)(this_ + 0x250));
                } else {
                    *(s32*)(this_ + 0x234) = AnimIdleFirst(*(s32*)(this_ + 0x250));
                }
                break;
            default:
                *(s32*)(this_ + 0x234) = AnimMoveFirst(*(s32*)(this_ + 0x250));
                break;
            }
        }
        break;
    case 3:
        if (*(f32*)(this_ + 0x14) > lbl_80542078) {
            *(f32*)(this_ + 0x44) = *(f32*)(this_ + 0x44) - *(f32*)(this_ + 0x260);
        } else if (*(f32*)(this_ + 0x14) <= lbl_80542078 && *(f32*)(this_ + 0x44) < lbl_80542078) {
            *(f32*)(this_ + 0x14) = lbl_80542078;
            *(s32*)(this_ + 0x23c) = ((*(u32*)(this_ + 0x90) >> 16) & 3) * 0x46 + 0x1e;
            *(V3*)(this_ + 0xc) = *(V3*)(this_ + 0x278);
            V3 v((*(f32*)(this_ + 0x24) - *(f32*)(this_ + 0xc)) / (f32)*(s32*)(this_ + 0x23c),
                 (*(f32*)(this_ + 0x28) - *(f32*)(this_ + 0x10)) / (f32)*(s32*)(this_ + 0x23c), lbl_80542078);
            *(V3*)(this_ + 0x3c) = v;
            *(s32*)(this_ + 0x240) = *(s32*)(this_ + 0x23c);
            *(s32*)(this_ + 0x230) = 5;
            *(s32*)(this_ + 0x238) = 0;
            switch (*(s32*)(this_ + 0x250)) {
            case 2:
                fn_802D79E8(fn_802D6A9C(), *(u32*)(this_ + 4), 0, lbl_8054206C, lbl_80542078);
                *(s32*)(this_ + 0x234) = AnimMoveFirst(*(s32*)(this_ + 0x250));
                break;
            case 4:
                if (*(s32*)(this_ + 0x248) >= 2) {
                    *(s32*)(this_ + 0x234) = AnimMoveFirst(*(s32*)(this_ + 0x250));
                } else {
                    *(s32*)(this_ + 0x234) = AnimIdleFirst(*(s32*)(this_ + 0x250));
                }
                break;
            case 3:
            default:
                *(s32*)(this_ + 0x234) = AnimMoveFirst(*(s32*)(this_ + 0x250));
                break;
            }
        }
        break;
    case 5:
        if (*(u8*)(this_ + 0x268) == 0 && fn_8023A30C()) {
            *(V3*)(this_ + 0x3c) = JumpVel((f32*)(this_ + 0x278), (f32*)(this_ + 0xc), lbl_80542068, lbl_8054206C);
            *(f32*)(this_ + 0x260) = lbl_80542070;
            *(s32*)(this_ + 0x240) = 0;
            *(s32*)(this_ + 0x230) = 3;
            *(s32*)(this_ + 0x238) = 0;
            *(s32*)(this_ + 0x234) = AnimMoveFirst(*(s32*)(this_ + 0x250));
        } else if (*(s32*)(this_ + 0x240) <= 0 ||
                   (*(f32*)(this_ + 0xc) == *(f32*)(this_ + 0x24) && *(f32*)(this_ + 0x10) == *(f32*)(this_ + 0x28))) {
            *(V3*)(this_ + 0xc) = *(V3*)(this_ + 0x24);
            *(f32*)(this_ + 0x44) = lbl_80542078;
            *(f32*)(this_ + 0x40) = lbl_80542078;
            *(f32*)(this_ + 0x3c) = lbl_80542078;
            *(s32*)(this_ + 0x230) = 0;
            *(s32*)(this_ + 0x238) = 0;
            *(s32*)(this_ + 0x234) = AnimIdleFirst(*(s32*)(this_ + 0x250));
        }
        break;
    case 4:
        fn_8022FEB8((f32*)&box, *(u32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(this_ + 0x24c), *(s32*)(this_ + 0x198))) {
            if (*(s32*)(this_ + 0x254) == 1) {
                *(s32*)(this_ + 0x230) = 0;
            } else {
                *(s32*)(this_ + 0x230) = 1;
            }
        }
        break;
    }
    fn_80337A08(this_);
    fn_803376B0(this_);
    if (*(s32*)(this_ + 0x240) > 0) {
        *(s32*)(this_ + 0x240) = *(s32*)(this_ + 0x240) - 1;
    }
}

extern "C" void fn_80338570(u8* this_) {
    union {
        f32 f;
        u32 s;
    } out;
    u8* g;
    *(s32*)(this_ + 0x230) = 0;
    *(s32*)(this_ + 0xb0) = 0;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(s32*)(this_ + 0x108) = 10000;
    *(s32*)(this_ + 0x23c) = 0;
    *(JGeometry::TVec3f*)(this_ + 0x26c) = *(JGeometry::TVec3f*)(this_ + 0x24);
    g = lbl_8053AAF8;
    *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
    out.s = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
    *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0xc) + (f32)((s32)(7.0f * (out.f - 1.0f)) - 3);
    g = lbl_8053AAF8;
    *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
    out.s = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
    *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x10) + (f32)((s32)(7.0f * (out.f - 1.0f)) - 3);
    *(JGeometry::TVec3f*)(this_ + 0x24) = *(JGeometry::TVec3f*)(this_ + 0xc);
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 3;
    *(s32*)(this_ + 0x258) = (*(u32*)(this_ + 0x90) >> 22) & 7;
    if ((*(u32*)(this_ + 0x90) >> 25) & 1) {
        *(s32*)(this_ + 0x258) = -*(s32*)(this_ + 0x258);
    }
    *(f32*)(this_ + 0x278) = *(f32*)(this_ + 0x24) + 16.0f * (f32)*(s32*)(this_ + 0x258);
    *(s32*)(this_ + 0x25c) = (*(u32*)(this_ + 0x90) >> 18) & 7;
    if ((*(u32*)(this_ + 0x90) >> 21) & 1) {
        *(s32*)(this_ + 0x25c) = -*(s32*)(this_ + 0x25c);
    }
    *(f32*)(this_ + 0x27c) = *(f32*)(this_ + 0x28) + 16.0f * (f32)*(s32*)(this_ + 0x25c);
    *(f32*)(this_ + 0x280) = 0.0f;
    *(s32*)(this_ + 0x24c) = -1;
    *(s32*)(this_ + 0x264) = (*(u32*)(this_ + 0x90) & 0xfff) + 0x12b;
    *(s32*)(this_ + 0x250) = (*(u32*)(this_ + 0x90) >> 12) & 0xf;
    *(s32*)(this_ + 0x240) = 0;
    *(f32*)(this_ + 0x260) = 0.0f;
    *(s32*)(this_ + 0x254) = 1;
    *(u8*)(this_ + 0x268) = (*(u32*)(this_ + 0x90) >> 26) & 1;
    if (*(u8*)(this_ + 0x268) == 1) {
        *(s32*)(this_ + 0x230) = 2;
        *(s32*)(this_ + 0x254) = 0;
        if (fn_801F6758(this_ + 0x278, *(u32*)(this_ + 4), 0.0f) == 0) {
            *(s32*)(this_ + 0x230) = 1;
            *(JGeometry::TVec3f*)(this_ + 0xc) = *(JGeometry::TVec3f*)(this_ + 0x278);
        }
    }
    fn_80337A08(this_);
    switch (*(s32*)(this_ + 0x250)) {
    case 2:
        *(f32*)(this_ + 0x80) = -16.0f;
        *(f32*)(this_ + 0x84) = -16.0f;
        *(f32*)(this_ + 0x88) = 16.0f;
        *(f32*)(this_ + 0x8c) = 8.0f;
        *(f32*)(this_ + 0x60) = -16.0f;
        *(f32*)(this_ + 0x64) = -16.0f;
        *(f32*)(this_ + 0x68) = 16.0f;
        *(f32*)(this_ + 0x6c) = 8.0f;
    *(s32*)(this_ + 0x234) = ((s32*)*(char**)(lbl_80471BB8 + *(s32*)(this_ + 0x250) * 16))[0];
        break;
    default:
        *(f32*)(this_ + 0x80) = -8.0f;
        *(f32*)(this_ + 0x84) = -8.0f;
        *(f32*)(this_ + 0x88) = 8.0f;
        *(f32*)(this_ + 0x8c) = 8.0f;
        *(f32*)(this_ + 0x60) = -8.0f;
        *(f32*)(this_ + 0x64) = -8.0f;
        *(f32*)(this_ + 0x68) = 8.0f;
        *(f32*)(this_ + 0x6c) = 8.0f;
    *(s32*)(this_ + 0x234) = ((s32*)*(char**)(lbl_80471BB8 + *(s32*)(this_ + 0x250) * 16))[0];
    }

    *(u8*)(this_ + 0x194) = 1;
}

extern "C" void fn_803388BC(void) {
}

