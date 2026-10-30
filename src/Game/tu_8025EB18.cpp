#include "types.h"
#define JGEOMETRY_VEC2_EXPLICIT_COPY
#include "JSystem/JGeometry/Vec.h"
#include "Game/ItemBase.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"

#pragma auto_inline off

#define S32(p, off) (*(s32*)((p) + (off)))
#define U32(p, off) (*(u32*)((p) + (off)))
#define U8(p, off) (*(u8*)((p) + (off)))
#define F32(p, off) (*(f32*)((p) + (off)))
#define VEC(p, off) (*(JGeometry::TVec3<f32>*)((p) + (off)))

static inline bool isAttached(char* p) {
    if (((S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4) || S32(p, 0xd68) >= 0) && U8(p, 0xd64) == 0)
        return true;
    return false;
}

static inline u8 isCarried(char* p) {
    return U8(p, 0xd64) == 1;
}

static inline u8 isCarriedByPlayer(char* p, u8 flag) {
    if ((u8)(flag == 1) == 1 && S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4)
        return 1;
    return 0;
}

static inline u8 isCarriedByPlayer(char* p) {
    if (isCarried(p) == 1 && S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4)
        return 1;
    return 0;
}

extern "C" {
void* fn_801F856C();
char* fn_801F666C(void*, s32);
u8 fn_801F36D4(char*, s32);
s32 fn_8022F340(u32);
bool Player_IsLinked(char*);
s32 fn_802486A0(char*);
void fn_80248FF0(char*);
void fn_8024F0E8(char*, s32);
u8 fn_80251AEC(char*, s32);
void fn_80258BBC(char*);
void fn_80259660(char*);
bool fn_8025EB18(char*);
void fn_8025F698(char*, u8);
void fn_8026022C(char*);
u8 fn_802604CC(char*);
u8 fn_80260C08(char*);
void fn_80268B3C(char*);
s32 fn_80270A8C(char*);
void fn_8027221C(char*, s32);
void fn_80283D2C(char*);
u8 Player_GetField_0xce8(char*);
u8 Player_GetField_0x454(char*);
u8 fn_80241230(char*);
s32 Actor_CreateByID(void*, u32, u32, void*, u32, s32, s32);
void* fn_8023E724(s32);
void fn_8028414C(char*);
u16 fn_802265FC(void*, s32);
s32 fn_8023DE58(s32);
char* fn_802D6A9C();
u16 fn_8022461C(JGeometry::TVec3<f32>*, s32);
u8 fn_802265DC(JGeometry::TVec3<f32>*, s32, s32);
u8 fn_802684A4(char*, JGeometry::TVec3<f32>*, s32);
u8 fn_802412A4(char*);
u8 fn_801F3744(char*, s32);
u8 fn_8022B1F8(char*);
u8 fn_8022AF10();
u8 fn_8022C0A0(s32);
u8 fn_8023F264(s32);
u8 fn_8023EFEC(s32);
u8 fn_8023EA28(s32);
u8 fn_80233DA4(s32);
u8 fn_80230188(s32);
u8 fn_80236AB4(s32);
u8 fn_802354E4(s32);
u8 fn_8022D894(s32);
s32 fn_8022CAF8(s32);
u8 fn_8022F514(s32);
u8 fn_80236B50(s32);
u8 fn_80239C9C(s32, JGeometry::TVec3<f32>*, s32);
u8 fn_802260DC(JGeometry::TVec3<f32>*, s32, s32);
f32 fn_80246F28(char*);
void fn_80231230(s32, s32);
void fn_802312CC(s32, s32);
void fn_802702A4(char*);
u8 fn_80251BFC(char*, s32);
}
extern const f32 lbl_80540150;
extern const f32 lbl_80540154;
extern const f32 lbl_80540180;
extern JGeometry::TVec3<f32> lbl_8046B400[];
extern char* lbl_8053AAF8;
extern JGeometry::TVec3<f32> lbl_8046B490[20];
extern JGeometry::TVec3<f32> lbl_8046B580[];
extern const f32 lbl_80540188;
extern const f32 lbl_805401E0;
extern const f32 lbl_80540178;
extern const f32 lbl_8054019C;
extern const f32 lbl_805401A0;
extern const f32 lbl_805401A4;
extern const f32 lbl_805401A8;
extern const f32 lbl_805401AC;
extern const f32 lbl_805401B0;
extern const f32 lbl_805401B4;
extern const f32 lbl_805401B8;
extern const f32 lbl_805401BC;
extern const f32 lbl_805401C0;
extern "C" void fn_801F3708(char*, JGeometry::TVec3<f32>*);

static inline bool canReleaseCarried(char* p, u8 flag) {
    s32 state = S32(p, 0x1244);
    if (state == 0x11 || (u32)(state - 0x12) <= 4 || state == 0x18 || (u32)(state - 0x1b) <= 2)
        goto blocked;
    if (flag == 1 && !isCarriedByPlayer(p, flag) && (u32)(state - 0x20) <= 5)
        goto blocked;
    if (S32(p, 0xd6c) == 'KEY0' && (u32)(state - 0x1e) <= 1)
        goto blocked;
    if (flag != 1)
        goto allowed;
    if (isCarriedByPlayer(p, flag))
        goto allowed;
    if (state == 0x4c)
        goto blocked;
    if (state != 0x4d)
        goto allowed;
blocked:
    return false;
allowed:
    return true;
}

extern "C" s32 fn_8024189C(char*);
extern "C" void fn_80230D80(s32, JGeometry::TVec3<f32>*);
extern "C" s32 fn_8023EF50(s32);
extern "C" u8 fn_8022E438(s32, u32);
extern "C" void fn_80230C6C(s32);
extern "C" void fn_802808E8(char*, f32);
extern "C" void fn_8027EB04(char*);
extern "C" void fn_8027FA08(char*, JGeometry::TVec3<f32>*);
extern "C" u8 fn_8022C13C(s32);
extern "C" s32 fn_802416C4(char*);
extern "C" u8 fn_8024B24C(char*);
extern "C" u8 fn_802466B4(char*);
extern "C" u8 fn_8022C0A0(s32);
extern const f32 lbl_8054017C;
extern const f32 lbl_805401E4;
extern "C" int __float_epsilon[];
extern u8 lbl_8046B790[];
extern "C" f32 lbl_8046B7B0[];

static inline void fn_80263C64_snap(char* p) {
    f32 thr = lbl_8054017C * (*(f32*)__float_epsilon);
    f32 nthr = -thr;
    f32 dx = F32(p, 0x8) - F32(p, 0x14);
    f32 dy = F32(p, 0xc) - F32(p, 0x18);
    f32 dz = F32(p, 0x10) - F32(p, 0x1c);
    if (nthr <= dx && dx <= thr && nthr <= dy && dy <= thr && nthr <= dz && dz <= thr) {
        f32 x = F32(p, 0x368);
        f32 y = F32(p, 0x36c);
        f32 z = F32(p, 0x370);
        if (x * x + y * y + z * z <= thr) {
            U8(p, 0x3f8) = U8(p, 0x3f8) + 1;
            if (U8(p, 0x3f8) >= 0x18) {
                U8(p, 0x3f8) = 0;
            }
        } else {
            U8(p, 0x3f8) = 0;
        }
        U8(p, 0x3f9) = lbl_8046B790[(S32(p, 0x3dc) << 3) + U8(p, 0x3f8) / 3];
        char* e = (char*)lbl_8046B7B0 + U8(p, 0x3f9) * 0x14;
        F32(p, 0x2f4) = F32(e, 0) + F32(p, 0x8);
        F32(p, 0x2f8) = F32(e, 4) + F32(p, 0xc);
        F32(p, 0x2fc) = F32(e, 8) + F32(p, 0x10);
    }
}

extern JGeometry::TVec3<f32> lbl_8046B8FC[];
extern JGeometry::TVec3<f32> lbl_8046B92C[];
extern const f32 lbl_80540158;
extern const f32 lbl_8054015C;
extern const f32 lbl_80540160;
extern const f32 lbl_80540164;
extern const f32 lbl_80540168;

extern "C" bool fn_8025EB18(char* p) {
    u8 held = isCarriedByPlayer(p);
    if (held && S32(p, 0x3b4) == 8 && fn_8023DE58(S32(p, 0xd70)) < 8) {
        JGeometry::TVec3<f32> pos = VEC(p, 0x2f4);
        s32 room = fn_8023DE58(S32(p, 0xd70));
        char* a = fn_802D6A9C();
        if (room < 8)
            a += 0xcc;
        else
            a += 0xdc;
        f32 ax = F32(a, 0);
        f32 ay = F32(a, 4);
        s32 id = S32(p, 0x3b4);
        char* b = fn_802D6A9C();
        if (id < 8)
            b += 0xcc;
        else
            b += 0xdc;
        f32 bx = F32(b, 0);
        f32 by = F32(b, 4);
        pos.x += ax - bx;
        pos.y += ay - by;
        u16 t = fn_8022461C(&pos, fn_8023DE58(S32(p, 0xd70)));
        if ((fn_802265DC(&pos, fn_8023DE58(S32(p, 0xd70)), 1) && t != 0xe && t != 0x39 && t != 0xd) ||
            fn_802684A4(p, &pos, fn_8023DE58(S32(p, 0xd70)))) {
            F32(p, 0x2f4) = F32(p, 0x8);
            F32(p, 0x2f8) = F32(p, 0xc);
            return true;
        }
    } else {
    u16 t2 = fn_8022461C(&VEC(p, 0x2f4), S32(p, 0x3b4));
    u8 held2 = isCarriedByPlayer(p);
    if (held2) {
        if ((fn_802265DC(&VEC(p, 0x2f4), S32(p, 0x3b4), 1) && t2 != 0xe && t2 != 0x39 && t2 != 0xd) ||
            fn_802684A4(p, &VEC(p, 0x2f4), S32(p, 0x3b4))) {
            F32(p, 0x2f4) = F32(p, 0x8);
            F32(p, 0x2f8) = F32(p, 0xc);
            return true;
        }
    } else {
    char* actor = fn_801F666C(fn_801F856C(), S32(p, 0xd68));
    if (actor && ((ItemBase*)actor)->v17(S32(p, 0x3b4), (f32*)&VEC(p, 0x2f4))) {
        F32(p, 0x2f4) = F32(p, 0x8);
        F32(p, 0x2f8) = F32(p, 0xc);
        return true;
    }
    }
    }
    return false;
}

extern "C" bool fn_8025EDD4(char* p, s32 id, const JGeometry::TVec3<f32>* pos) {
    if (S32(p, 0xd68) == id) {
        S32(p, 0xd68) = -1;
        VEC(p, 0xd78) = *pos;
        return true;
    }
    return false;
}

extern "C" void fn_8025EE0C(char* p, s32 id, const JGeometry::TVec3<f32>* pos) {
    if (S32(p, 0xd68) == id) {
        f32 x = pos->x;
        f32 y = pos->y;
        f32 z = pos->z;
        F32(p, 0x300) = x;
        F32(p, 0x304) = y;
        F32(p, 0x308) = z;
    }
}

extern "C" bool fn_8025EE34(char* p, s32 id) {
    return S32(p, 0xd68) == id;
}

extern "C" bool fn_8025EE48(char* p, s32 id) {
    bool ok;
    s32 ok2;
    if ((u8)fn_80270A8C(p))
        return false;
    if ((u8)(U8(p, 0xd64) == 1) == 1)
        return false;
    if (((S32(p, 0xd70) < 0 || S32(p, 0xd70) >= 4) && S32(p, 0xd68) < 0) || U8(p, 0xd64) != 0)
        ok = true;
    else
        ok = false;
    if (ok == 0)
        return false;
    if (Player_GetField_0xce8(p))
        return false;
    if (fn_80241230(p))
        return false;
    if (Player_GetField_0x454(p))
        return false;
    if (S32(p, 0xd68) < 0 && fn_80251AEC(p, 0x19)) {
        S32(p, 0xd68) = id;
        return true;
    }
    return false;
}

extern "C" bool fn_8025EF68(char* p, s32 id) {
    if (S32(p, 0xd88) == id)
        return true;
    if (S32(p, 0xd88) >= 0)
        return false;
    char* actor = fn_801F666C(fn_801F856C(), id);
    if (actor) {
        if (fn_801F36D4(actor, S32(p, 4))) {
            S32(p, 0xd88) = id;
            return true;
        }
        return false;
    }
    return false;
}

#pragma opt_propagation off
extern "C" bool fn_8025EFFC(char* p, s32 id, u8 flag, u8 force) {
    char* actor;
    bool held;
    u8 good;
    if (force == 0) {
        goto zero;
    }
    held = U8(p, 0xd64) == 1;
    if (held) {
        goto main;
    }
    good = isAttached(p);
    if (good) {
        goto main;
    }
    if ((u8)fn_80241230(p)) {
        goto main;
    }
    if (!(u8)fn_802412A4(p)) {
        goto search;
    }
main:
    if (S32(p, 0xd88) != id && S32(p, 0xd88) < 0) {
        actor = fn_801F666C(fn_801F856C(), id);
        if (actor != 0 && fn_801F36D4(actor, S32(p, 4))) {
            S32(p, 0xd88) = id;
        }
    }
    return true;
zero:
    if ((u8)fn_80270A8C(p)) {
        good = 0;
        goto eligibility;
    }
    held = U8(p, 0xd64) == 1;
    if (held) {
        good = 0;
        goto eligibility;
    }
    good = isAttached(p);
    if (good) {
        good = 0;
        goto eligibility;
    }
    if ((u8)Player_GetField_0xce8(p)) {
        good = 0;
        goto eligibility;
    }
    if ((u8)fn_80241230(p)) {
        good = 0;
        goto eligibility;
    }
    if ((u8)fn_802412A4(p)) {
        good = 0;
        goto eligibility;
    }
    if ((u8)Player_GetField_0x454(p)) {
        good = 0;
        goto eligibility;
    }
    if (F32(p, 0x10) > lbl_80540150) {
        good = 0;
        goto eligibility;
    }
    if (S32(p, 0xd88) < 0 && Player_IsLinked(p) && fn_802486A0(p) == 5) {
        good = 0;
        goto eligibility;
    }
    good = 1;
eligibility:
    if (!good) return false;
search:
    actor = fn_801F666C(fn_801F856C(), id);
    if (actor != 0) {
        char* self = p;
        s32 state = 0x12;
        if (flag) state = 0x11;
        if (fn_80251AEC(self, state)) {
        S32(p, 0xd88) = -1;
        U32(p, 0xd6c) = U32(actor, 0x1a0);
        VEC(p, 0x2f4) = VEC(actor, 0xc);
        U8(p, 0xd64) = 1;
        S32(p, 0xd68) = id;
        fn_801F3744(actor, S32(p, 4));
        S32(p, 0xd74) = 3;
        U8(p, 0x1174) = 1;
        fn_8024F0E8(p, 0x20022);
        return true;
    }
    }
    return false;
}
#pragma opt_propagation reset
extern "C" bool fn_8025F2CC(char* p) {
    bool bVar1;
    if ((u8)fn_80270A8C(p) != 0) {
        return false;
    }
    u8 d64 = U8(p, 0xd64);
    if (d64 == 1) {
        return false;
    }
    if (!(((S32(p, 0xd70) < 0 || S32(p, 0xd70) >= 4) && S32(p, 0xd68) < 0) || d64 != 0)) {
        bVar1 = true;
    } else {
        bVar1 = false;
    }
    if (bVar1) {
        return false;
    }
    if (Player_GetField_0xce8(p) != 0) {
        return false;
    }
    if (fn_80241230(p) != 0) {
        return false;
    }
    if (fn_802412A4(p) != 0) {
        return false;
    }
    if (Player_GetField_0x454(p) != 0) {
        return false;
    }
    if (F32(p, 0x10) > lbl_80540150) {
        return false;
    }
    if (S32(p, 0xd88) < 0 && Player_IsLinked(p) && fn_802486A0(p) == 5) {
        return false;
    }
    return true;
}

extern "C" bool fn_8025F418(char* p) {
    if (S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4 && U8(p, 0xd64) == 0)
        return true;
    return false;
}

extern "C" bool fn_8025F448(char* p) {
    if (((S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4) || S32(p, 0xd68) >= 0) && U8(p, 0xd64) == 0)
        return true;
    return false;
}

extern "C" bool fn_8025F484(const char* p) {
    if ((u8)(*(const u8*)(p + 0xd64) == 1) == 1) {
        s32 id = *(const s32*)(p + 0xd68);
        if (id >= 0) {
            char* actor = fn_801F666C(fn_801F856C(), id);
            if (actor && S32(actor, 0x1a4) > 0)
                return true;
            return false;
        }
    }
    return false;
}

extern "C" bool fn_8025F500(char* p) {
    if ((u8)(U8(p, 0xd64) == 1) == 1 && S32(p, 0xd68) >= 0)
        return true;
    return false;
}

extern "C" s32 fn_8025F534(char* p) {
    if (U8(p, 0xd64) != 1) {
        s32 id = S32(p, 0xd70);
        if (id >= 0 && id < 4)
            return id;
    }
    return -1;
}

extern "C" s32 fn_8025F55C(char* p) {
    if ((u8)(U8(p, 0xd64) == 1) == 1) {
        s32 id = S32(p, 0xd70);
        if (id >= 0 && id < 4)
            return id;
    }
    return -1;
}

extern "C" bool fn_8025F590(char* p) {
    if ((u8)(U8(p, 0xd64) == 1) == 1 && S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4)
        return true;
    return false;
}

extern "C" void fn_8025F5CC(char* p) {
    if (U8(p, 0xd64) != 0) {
        s32 id = S32(p, 0xd68);
        if (id >= 0) {
            char* actor = fn_801F666C(fn_801F856C(), id);
            if (actor) {
                actor[0x11c] = 0;
                U32(p, 0xd6c) = 'NULL';
                p[0xd64] = 0;
                S32(p, 0xd68) = -1;
            }
        }
    }
}

extern "C" u32 fn_8025F648(char* p) {
    if (U8(p, 0xd64) == 1)
        return U32(p, 0xd6c);
    return 'NULL';
}

extern "C" s32 fn_8025F668(char* p) {
    if (U8(p, 0xd64) == 1)
        return S32(p, 0xd68);
    return -1;
}

extern "C" int fn_8025F684(char* p) {
    return (u8)(U8(p, 0xd64) == 1);
}

#pragma opt_common_subs off
extern "C" void fn_8025F698(char* p, u8 check) {
    u8 flag = U8(p, 0xd64);
    if (flag == 0)
        return;
    if (check && !canReleaseCarried(p, flag))
        return;
    u8 notify = 1;
    if (U32(p, 0xd6c) == 'NULL')
        notify = 0;
    if (isCarriedByPlayer(p, flag)) {
        JGeometry::TVec3<f32> vel;
        JGeometry::TVec3<f32> dir;
        dir.set(lbl_8046B8FC[S32(p, 0x3dc)]);
        dir.scale(lbl_80540154);
        s32 st = S32(p, 0x1244);
        if (st == 0x1e || st == 0x32 || fn_8024189C(p) <= 0) {
            vel.x = lbl_80540150;
            vel.y = lbl_80540150;
            vel.z = lbl_80540150;
        } else {
            JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)fn_8023E724(S32(p, 0xd70));
            s32 count = 0;
            for (s32 i = 0; i < 3; i++) {
                pos += dir;
                u16 t = fn_8022461C(&pos, fn_8023DE58(S32(p, 0xd70)));
                if (t == 3 || t == 0xe || t == 0x3a)
                    count++;
            }
            vel.set(lbl_8046B8FC[S32(p, 0x3dc)]);
            if (count >= 2) {
                s32 d = S32(p, 0x3dc);
                if (d == 0 || d == 1) {
                    pos.x = (s32)pos.x / 16 * 16 + 8;
                } else {
                    pos.y = (s32)pos.y / 16 * 16 + 8;
                }
                JGeometry::TVec3<f32> diff = pos - *(JGeometry::TVec3<f32>*)fn_8023E724(S32(p, 0xd70));
                vel.set(diff);
                vel.scale(lbl_80540158);
            } else {
                vel.scale(lbl_8054015C);
            }
        }
        fn_80230D80(S32(p, 0xd70), &vel);
        S32(p, 0xd70) = -1;
        fn_8024F0E8(p, 0x20014);
    } else {
        char* actor = fn_801F666C(fn_801F856C(), S32(p, 0xd68));
        if (actor) {
            JGeometry::TVec3<f32> v;
            v.set(lbl_8046B92C[S32(p, 0x3dc)]);
            u32 kind = U32(actor, 0x1a0);
            if (kind == 'CRTL' || kind == 'BMTY') {
                v *= lbl_80540160;
            } else if (kind == 'GRAS') {
                v *= lbl_80540164;
            } else if (S32(actor, 0x1a4) == 0) {
                v *= lbl_80540168;
            } else {
                v *= lbl_80540164;
            }
            fn_801F3708(actor, &v);
            fn_8024F0E8(p, 0x20014);
        }
        S32(p, 0xd68) = -1;
    }
    p[0xd64] = 0;
    U32(p, 0xd6c) = 'NULL';
    S32(p, 0xd74) = 3;
    if (notify == 1 && fn_802486A0(p) != 4 && (U8(lbl_8053AAF8, 0x82) & (u8)(1 << S32(p, 4)))) {
        for (s32 i = 0; i < 4; i++) {
            if (fn_8022E438(S32(p, 4), i) && i != S32(p, 4)) {
                char* a = fn_801F666C(fn_801F856C(), fn_8023EF50(i));
                if (a && S32(a, 0x1a4) <= 0)
                    fn_80230C6C(i);
            }
        }
    }
}
#pragma opt_common_subs reset

#pragma opt_common_subs off
extern "C" bool fn_8025FCC8(char* p) {
    s32 state = S32(p, 0x1244);
    if (state == 0x11 || (u32)(state - 0x12) <= 4 || state == 0x18 || (u32)(state - 0x1b) <= 2)
        goto blocked;
    u8 flag = U8(p, 0xd64);
    switch ((u8)(flag == 1)) {
    case 0: break;
    default:
        if (!isCarriedByPlayer(p, flag) && (u32)(state - 0x20) <= 5) goto blocked;
        break;
    }
    if (S32(p, 0xd6c) == 0x4b455930 && (u32)(state - 0x1e) <= 1)
        goto blocked;
    if (flag != 1) goto allowed;
    if (isCarriedByPlayer(p, flag)) goto allowed;
    if (state == 0x4c) goto blocked;
    if (state != 0x4d) goto allowed;
blocked:
    return false;
allowed:
    return true;
}
#pragma opt_common_subs reset
extern "C" char* fn_8023E7B0(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" char* fn_802D6A9C();
extern "C" bool fn_8025FDD0(char* p, const JGeometry::TVec3<f32>* v) {
    *(JGeometry::TVec3<f32>*)(p + 0x8) = *(JGeometry::TVec3<f32>*)fn_8023E7B0(S32(p, 0xd70));
    s32 idx = fn_8023DE58(S32(p, 0xd70));
    char* r = fn_802D6A9C();
    f32* o = idx < 8 ? (f32*)(r + 0xcc) : (f32*)(r + 0xdc);
    f32 ox = o[0];
    f32 oy = o[1];
    s32 idx2 = S32(p, 0x3b4);
    r = fn_802D6A9C();
    o = idx2 < 8 ? (f32*)(r + 0xcc) : (f32*)(r + 0xdc);
    f32 x = o[0];
    f32 y = o[1];
    F32(p, 0x8) += x - ox;
    F32(p, 0xc) += y - oy;
    S32(p, 0xd70) = -1;
    S32(p, 0xd58) = 5;
    *(JGeometry::TVec3<f32>*)(p + 0xd78) = *v;
    return true;
}

extern "C" bool fn_8025FEDC(char* p) {
    u8 attached;
    if (((S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4) || S32(p, 0xd68) >= 0) && U8(p, 0xd64) == 0)
        attached = true;
    else
        attached = false;
    if (!attached)
        return false;
    fn_80251AEC(p, 0);
    f32 height = lbl_80540150;
    S32(p, 0xd70) = -1;
    bool ok = true;
    S32(p, 0xd68) = -1;
    F32(p, 0x10) = height;
    return ok;
}

extern "C" bool fn_8025FF70(char* p) {
    u8 carrying;
    if ((u8)(U8(p, 0xd64) == 1) == 1 && S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4)
        carrying = true;
    else
        carrying = false;
    if (!carrying)
        return false;
    fn_80251AEC(p, 0);
    p[0xd64] = 0;
    S32(p, 0xd70) = -1;
    U32(p, 0xd6c) = 'NULL';
    return true;
}

extern "C" void fn_8026000C(char* p) {
    fn_8025F698(p, 0);
    fn_80251AEC(p, 0);
}

extern "C" bool fn_80260048(char* p, s32 id) {
    if (!(u8)fn_80270A8C(p))
        return false;
    S32(p, 0xd70) = id;
    fn_80248FF0(p);
    return true;
}

s32 fn_8023DE58(u32);
s32 Player_GetLinkTargetIndex(char*);
void fn_80233F78(s32);
u8 fn_80243194(char*, s32);
extern "C" u8 fn_802600A0(char* p, u32 id) {
    if ((u8)fn_80270A8C(p)) {
        return 0;
    }
    if ((U8(lbl_8053AAF8, 0x82) & (u8)(1 << S32(p, 4))) == 0 && !fn_8022E438(S32(p, 4), id) &&
        (U8(lbl_8053AAF8, 0x7e) == 0 || fn_802486A0(p) != 4) &&
        (fn_8023DE58(id) != 8 || S32(p, 0x3b4) >= 8)) {
        S32(p, 0xd60) = fn_8022F340(id);
        S32(p, 0x11ec) = fn_8022F340(id);
        Actor_CreateByID(fn_801F856C(), 'TSNO', S32(p, 0x3b4), p + 8, (id & 3) | (S32(p, 4) << 2), -1, id);
        if ((s32)id > S32(p, 4)) {
            fn_80233F78(Player_GetLinkTargetIndex(p));
        }
    } else if (fn_80251AEC(p, 0x19)) {
        S32(p, 0xd70) = id;
        if (fn_802486A0(p) != 4) {
            for (s32 i = 0; i < 4; i++) {
                if (fn_80243194(p, i) && i != S32(p, 4)) {
                    fn_80230C6C(i);
                }
            }
        }
    } else {
        return 0;
    }
    fn_80248FF0(p);
    return 1;
}

extern JGeometry::TVec3<f32> lbl_8046B89C[];
extern JGeometry::TVec3<f32> lbl_8046B8CC[];
extern "C" u8 fn_8022BF68(s32);
extern "C" u8 fn_8022C004(s32);
extern "C" u8 fn_8022B244(char*);
extern "C" u8 fn_80272B4C(char*, JGeometry::TVec3<f32>);
extern "C" u8 fn_8025190C(char*, s32);
extern "C" u8 fn_802517F8(char*, s32);
extern "C" u8 fn_8025197C(char*, s32);
#pragma opt_common_subs off
extern "C" void fn_8026022C(char* p) {
 JGeometry::TVec3<f32> a,b;
 a.set(lbl_8046B89C[(*(s32*)(p+0x3dc))]);

 a.add((*(JGeometry::TVec3<f32>*)(p+8))); a.z=lbl_80540150; b.set(lbl_8046B8CC[(*(s32*)(p+0x3dc))]); b.add((*(JGeometry::TVec3<f32>*)(p+8)));
 if((*(u8*)(p+0x1174))==0 && (*(u8*)(p+0xd64))==0 && (*(s32*)(p+0xd74))==0) {
 if(fn_8022BF68((*(s32*)(p+4)))) {
 if(!fn_802265DC(&b,(*(s32*)(p+0x3b4)),1) && !fn_802684A4(p,&b,(*(s32*)(p+0x3b4))) && !fn_8024B24C(p) &&
 (fn_802265DC(&a,(*(s32*)(p+0x3b4)),1) || fn_80272B4C(p,a))) { fn_80251AEC(p,0x1a); }
 else if(lbl_80540150==fn_80246F28(p)) {
 if(!((u8(*)())fn_8022B1F8)() && fn_80251AEC(p,0x11)) { (*(u8*)(p+0xd64))=1; (*(s32*)(p+0xd68))=-1; (*(u32*)(p+0xd6c))='NULL'; }
 } else if(!((u8(*)())fn_8022B244)() || fn_802416C4(p)==5) {fn_80251AEC(p,0x4f);}
 } else if((*(s32*)(p+0x1240))==0x4f && fn_8022C004((*(s32*)(p+4))) && !fn_8024B24C(p)) {
 s32 room=(*(s32*)(p+0x3b4));
 u8* __restrict data=(u8*)fn_802D6A9C()+0x10000;
 data+=room; if(data[0x31df]) {
 if(fn_8025190C(p,1) || fn_802517F8(p,0)) fn_80251AEC(p,0x1a);
 } else if(fn_8025197C(p,1)) fn_80251AEC(p,0x1a);
 }
 }
}
#pragma opt_common_subs reset
extern JGeometry::TVec3<f32> lbl_8046B86C[];

static inline char* carryRoomOrigin(s32 room)
{
    char* mgr = fn_802D6A9C();
    if (room < 8) return mgr + 0xcc;
    return mgr + 0xdc;
}
static inline u8 carryPointOverlaps(s32 player, s32 room, const JGeometry::TVec3f& base)
{
    f32 bounds[4];
    bounds[0] = base.x; bounds[1] = base.y;
    bounds[2] = base.x; bounds[3] = base.y;
    return fn_80239C9C(player, (JGeometry::TVec3f*)bounds, room);
}
#pragma opt_propagation off
static inline JGeometry::TVec2f carryAdd(const JGeometry::TVec2f& a, const JGeometry::TVec2f& b)
{
    JGeometry::TVec2f v(a);
    v.x += b.x;
    v.y += b.y;
    return v;
}
static inline JGeometry::TVec2f carrySub(const JGeometry::TVec2f& a, const JGeometry::TVec2f& b)
{
    JGeometry::TVec2f v(a);
    v.x -= b.x;
    v.y -= b.y;
    return v;
}
#pragma opt_propagation reset
extern "C" u8 fn_802604CC(char* p) {
    if (fn_8022B1F8(p)) return 0;
    if (fn_8022AF10()) return 0;
    if (fn_802486A0(p) != 4 && Player_IsLinked(p)) return 0;
    if (U8(lbl_8053AAF8, 0x7e) == 0 && fn_802486A0(p) != 4) return 0;
    if (fn_8022C0A0(S32(p, 4))) {
        JGeometry::TVec3<f32> base;
        base.set(lbl_8046B86C[S32(p, 0x3dc)]);
        base += VEC(p, 8);
        base.z = lbl_80540150;
        for (s32 i = 0; i < 4; i++) {
            if (i == S32(p, 4) || !fn_8023F264(i) || fn_8023EFEC(i) || fn_8023EA28(i) ||
                fn_80233DA4(i) || fn_80230188(i) || fn_80236AB4(i) || fn_802354E4(i) || fn_8022D894(i)) continue;
            if (S32(p, 0x3b4) == 8 && fn_8023DE58(i) < 8 && fn_8022CAF8(i) != 4 && fn_8022F514(i)) continue;
            if (fn_802486A0(p) != 4 && fn_8022E438(S32(p, 4), i) && fn_80246F28(p) > lbl_80540150) continue;
            char* a = carryRoomOrigin(fn_8023DE58(i));
            char* b = carryRoomOrigin(S32(p, 0x3b4));
            JGeometry::TVec2f v = (*(JGeometry::TVec2f*)(p + 8) - *(JGeometry::TVec2f*)b) + *(JGeometry::TVec2f*)a;
            if ((fn_802260DC((JGeometry::TVec3f*)&v, fn_8023DE58(i), 1) ||
                 fn_802684A4(p, (JGeometry::TVec3f*)&v, fn_8023DE58(i))) &&
                fn_802265FC(&v, fn_8023DE58(i)) != 0x20) continue;
            a = carryRoomOrigin(fn_8023DE58(i));
            char* target = (char*)fn_8023E724(i);
            b = carryRoomOrigin(S32(p, 0x3b4));
            JGeometry::TVec2f mid = (*(JGeometry::TVec2f*)(p + 8) - *(JGeometry::TVec2f*)b + *(JGeometry::TVec2f*)target) - *(JGeometry::TVec2f*)a;
            mid.scale(0.5f);
            f32 x = mid.x;
            f32 y = mid.y;
            a = carryRoomOrigin(fn_8023DE58(i));
            v = mid + *(JGeometry::TVec2f*)a;
            if ((fn_802260DC((JGeometry::TVec3f*)&v, fn_8023DE58(i), 1) ||
                 fn_802684A4(p, (JGeometry::TVec3f*)&v, fn_8023DE58(i))) &&
                fn_802265FC(&v, fn_8023DE58(i)) != 0x20) continue;
            s32 ownRoom = S32(p, 0x3b4);
            if (ownRoom != fn_8023DE58(i)) {
                b = carryRoomOrigin(S32(p, 0x3b4));
                v = mid + *(JGeometry::TVec2f*)b;
                if ((fn_802260DC((JGeometry::TVec3f*)&v, S32(p, 0x3b4), 1) ||
                     fn_802684A4(p, (JGeometry::TVec3f*)&v, S32(p, 0x3b4))) &&
                    fn_802265FC(&v, fn_8023DE58(i)) != 0x20) continue;
            }
            if (!carryPointOverlaps(i, S32(p, 0x3b4), base)) continue;
            if ((U8(lbl_8053AAF8, 0x82) & (u8)(1 << i)) ||
                fn_8022E438(S32(p, 4), i) ||
                (U8(lbl_8053AAF8, 0x7e) && fn_8022CAF8(i) == 4) ||
                (S32(p, 0x3b4) == 8 && fn_8023DE58(i) < 8)) {
                if (!fn_80236B50(i) && !fn_80251BFC(p, 0x19)) continue;
                if (!fn_80251AEC(p, 0x11)) continue;
                if (fn_80236B50(i)) fn_80231230(i, S32(p, 4));
                else fn_802312CC(i, S32(p, 4));
                VEC(p, 0x2f4) = base;
                U8(p, 0xd64) = 1;
                S32(p, 0xd70) = i;
                U32(p, 0xd6c) = 'PLAY';
                fn_8024F0E8(p, 0x20022);
                fn_802702A4(p);
                return 1;
            } else {
                if (fn_80236B50(i)) {
                    if (fn_80251AEC(p, 0x11)) {
                        fn_80231230(i, S32(p, 4));
                        VEC(p, 0x2f4) = base;
                        U8(p, 0xd64) = 1;
                        S32(p, 0xd70) = i;
                        U32(p, 0xd6c) = 'PLAY';
                        fn_8024F0E8(p, 0x20022);
                        fn_802702A4(p);
                    }
                } else fn_802312CC(i, S32(p, 4));
                return 1;
            }
        }
    }
    return 0;
}

extern JGeometry::TVec3<f32> lbl_8046B83C[];
extern "C" u8 fn_8022C1D8(s32);
extern "C" u8 fn_802A01F0(char*, JGeometry::TVec3<f32>*, s32, s32);
extern "C" s32 fn_802A02A8(char*, JGeometry::TVec3<f32>*, s32, s32);
extern "C" u32 fn_80226AE0(JGeometry::TVec3<f32>*, s32);
extern "C" u8 fn_8029E888(char*, JGeometry::TVec3<f32>*, s32, s32);
extern "C" f32 fn_80247330(char*);
extern "C" f32 fn_8024712C(char*);
extern "C" u8 fn_802D6AC4(char*, s32);
extern "C" void fn_802D6B24(char*, s32, u8);
extern char* lbl_8053AC98;
static inline u8 carryRoomFlag(const s32 room) {
    u8* table = (u8*)fn_802D6A9C() + 0x10000;
    return table[room + 0x31df];
}
static inline u8 carryCheckOffsetTile(s32 player, s32 room, f32 x, f32 y, f32 z) {
    JGeometry::TVec3<f32> pos(x, y, z);
    return fn_8029E888(lbl_8053AC98, &pos, player, room);
}

extern "C" u8 fn_80260C08(char* p) {
    u32 r29;
    s32 r30;
    if (fn_8022B1F8(p))
        return 0;
    if (!fn_80251BFC(p, 0x11))
        return 0;
    JGeometry::TVec3<f32>* tp = &lbl_8046B83C[S32(p, 0x3dc)];
    JGeometry::TVec3<f32> v;
    v.x = tp->x;
    v.y = tp->y;
    v.z = tp->z;
    v += VEC(p, 0x8);
    v.z = lbl_80540150;
    if (fn_8022C1D8(S32(p, 0x4)) || fn_8022C0A0(S32(p, 0x4))) {
        if (carryRoomFlag(S32(p, 0x3b4)) != 0) {
            if (S32(p, 0x3dc) == 3 || S32(p, 0x3dc) == 1 || S32(p, 0x3dc) == 0) {
                if (fn_8029E888(lbl_8053AC98, &v, S32(p, 0x4), S32(p, 0x3b4)) == 1)
                    return 1;
            }
        } else if (S32(p, 0x3dc) == 3) {
            if (fn_80247330(p) < lbl_80540150) {
                if (carryCheckOffsetTile(S32(p, 0x4), S32(p, 0x3b4), v.x - lbl_80540154, v.y, v.z) == 1)
                    return 1;
            } else if (fn_80247330(p) > lbl_80540150) {
                if (carryCheckOffsetTile(S32(p, 0x4), S32(p, 0x3b4), lbl_80540154 + v.x, v.y, v.z) == 1)
                    return 1;
            }
            if (fn_8029E888(lbl_8053AC98, &v, S32(p, 0x4), S32(p, 0x3b4)) == 1)
                return 1;
        } else if (S32(p, 0x3dc) == 1 || S32(p, 0x3dc) == 0) {
            if (fn_8024712C(p) > lbl_80540150) {
                if (carryCheckOffsetTile(S32(p, 0x4), S32(p, 0x3b4), v.x, v.y - lbl_80540154, v.z) == 1)
                    return 1;
            }
        }
    }
    if (fn_8022C1D8(S32(p, 0x4)) && fn_802A01F0(lbl_8053AC98, &v, S32(p, 0x4), S32(p, 0x3b4)))
        return 1;
    if (!fn_8022C0A0(S32(p, 0x4)))
        goto done;
    r30 = fn_802A02A8(lbl_8053AC98, &v, S32(p, 0x4), S32(p, 0x3b4));
    r29 = fn_80226AE0(&v, S32(p, 0x3b4));
    switch (r30) {
    case 0:
    case 1:
    case 2:
    case 3: {
        s32 act;
        if (r30 == 3) {
            if (!fn_802D6AC4(fn_802D6A9C(), r29)) {
                act = Actor_CreateByID(fn_801F856C(), 0x47524153, S32(p, 0x3b4), &v, 3, -1, S32(p, 0x4));
                fn_802D6B24(fn_802D6A9C(), r29, 1);
            } else {
                act = Actor_CreateByID(fn_801F856C(), 0x47524153, S32(p, 0x3b4), &v, 4, -1, S32(p, 0x4));
            }
        } else {
            act = Actor_CreateByID(fn_801F856C(), 0x47524153, S32(p, 0x3b4), &v, r30, -1, S32(p, 0x4));
        }
        r30 = (s32)fn_801F666C(fn_801F856C(), act);
        if (r30 && fn_80251AEC(p, 0x11)) {
            S32(p, 0xd6c) = 0x47524153;
            VEC(p, 0x2f4) = v;
            U8(p, 0xd64) = 1;
            S32(p, 0xd68) = act;
            fn_801F3744((char*)r30, S32(p, 0x4));
        }
        return 1;
    }
    case 5: {
        r30 = Actor_CreateByID(fn_801F856C(), 0x53544f4e, S32(p, 0x3b4), &v, 0, -1, S32(p, 0x4));
        r29 = (u32)fn_801F666C(fn_801F856C(), r30);
        if (r29 && fn_80251AEC(p, 0x11)) {
            S32(p, 0xd6c) = 0x53544f4e;
            VEC(p, 0x2f4) = v;
            U8(p, 0xd64) = 1;
            S32(p, 0xd68) = r30;
            fn_801F3744((char*)r29, S32(p, 0x4));
        }
        return 1;
    }
    case 6: {
        r29 = S32(p, 0x4);
        r29 = Actor_CreateByID(fn_801F856C(), 0x5353544e, S32(p, 0x3b4), &v, r29 << 4, -1, r29);
        r30 = (s32)fn_801F666C(fn_801F856C(), r29);
        if (r30 && fn_80251AEC(p, 0x11)) {
            S32(p, 0xd6c) = 0x5353544e;
            VEC(p, 0x2f4) = v;
            U8(p, 0xd64) = 1;
            S32(p, 0xd68) = r29;
            fn_801F3744((char*)r30, S32(p, 0x4));
        }
        return 1;
    }
    case 7: {
        r29 = Actor_CreateByID(fn_801F856C(), 0x424f5244, S32(p, 0x3b4), &v, 0, -1, S32(p, 0x4));
        r30 = (s32)fn_801F666C(fn_801F856C(), r29);
        if (r30 && fn_80251AEC(p, 0x11)) {
            S32(p, 0xd6c) = 0x424f5244;
            VEC(p, 0x2f4) = v;
            U8(p, 0xd64) = 1;
            S32(p, 0xd68) = r29;
            fn_801F3744((char*)r30, S32(p, 0x4));
        }
        return 1;
    }
    case 8: {
        r29 = Actor_CreateByID(fn_801F856C(), 0x524f434b, S32(p, 0x3b4), &v, 0, -1, S32(p, 0x4));
        r30 = (s32)fn_801F666C(fn_801F856C(), r29);
        if (r30 && fn_80251AEC(p, 0x11)) {
            S32(p, 0xd6c) = 0x524f434b;
            VEC(p, 0x2f4) = v;
            U8(p, 0xd64) = 1;
            S32(p, 0xd68) = r29;
            fn_801F3744((char*)r30, S32(p, 0x4));
            U8((char*)r30, 0x11d) = 0;
        }
        return 1;
    }
    case 12: {
        r29 = S32(p, 0x4);
        r29 = Actor_CreateByID(fn_801F856C(), 0x5353544e, S32(p, 0x3b4), &v, (r29 << 4) + 1, -1, r29);
        r30 = (s32)fn_801F666C(fn_801F856C(), r29);
        if (r30 && fn_80251AEC(p, 0x11)) {
            S32(p, 0xd6c) = 0x524f434b;
            VEC(p, 0x2f4) = v;
            U8(p, 0xd64) = 1;
            S32(p, 0xd68) = r29;
            fn_801F3744((char*)r30, S32(p, 0x4));
            U8((char*)r30, 0x11d) = 0;
        }
        return 1;
    }
    case 39: {
        r29 = Actor_CreateByID(fn_801F856C(), 0x59415349, S32(p, 0x3b4), &v, 0, -1, S32(p, 0x4));
        r30 = (s32)fn_801F666C(fn_801F856C(), r29);
        if (r30 && fn_80251AEC(p, 0x11)) {
            S32(p, 0xd6c) = 0x59415349;
            VEC(p, 0x2f4) = v;
            U8(p, 0xd64) = 1;
            S32(p, 0xd68) = r29;
            fn_801F3744((char*)r30, S32(p, 0x4));
        }
        return 1;
    }
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35: {
        u32 k28 = 0;
        if (r30 == 0x22)
            k28 = 1;
        else if (r30 == 0x23)
            k28 = 2;
        s32 k29 = r30 - 0x18;
        if (r30 >= 0x1d)
            k29 = r30 - 0x1d;
        r29 = Actor_CreateByID(fn_801F856C(), 0x5455424f, S32(p, 0x3b4), &v, (k28 << 7) | k29, -1, S32(p, 0x4));
        r30 = (s32)fn_801F666C(fn_801F856C(), r29);
        if (r30 && fn_80251AEC(p, 0x11)) {
            S32(p, 0xd6c) = 0x5455424f;
            VEC(p, 0x2f4) = v;
            U8(p, 0xd64) = 1;
            S32(p, 0xd68) = r29;
            fn_801F3744((char*)r30, S32(p, 0x4));
        }
        return 1;
    }
    default:
        break;
    }
done:
    return 0;
}

extern "C" void fn_80261468(char* p) {
    if (S32(p, 0xd74) > 0)
        --S32(p, 0xd74);
}

extern "C" void fn_80261480(char* p) {
    if (S32(p, 0xc9c) > 0)
        return;
    if (S32(p, 0xd74) != 0)
        return;
    if (Player_IsLinked(p) && fn_802486A0(p) == 5)
        return;
    if (fn_80260C08(p)) {
        S32(p, 0xd74) = 3;
        p[0x1174] = 1;
    } else if (fn_802604CC(p)) {
        S32(p, 0xd74) = 3;
        p[0x1174] = 1;
    } else {
        fn_8026022C(p);
    }
}


extern "C" u8 lbl_8046B790[];
extern "C" f32 lbl_8046B7B0[];
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" void fn_8026152C(char* p, u8 flag) {
    bool inX;
    bool inY;
    bool inZ;
    inZ = false;
    inY = inZ;
    inX = inZ;
    f32 eps;
    f32 neg;
    f32 d;
    f32 machineEps = *(f32*)__float_epsilon;
    eps = lbl_8054017C * machineEps;
    neg = -eps;
    d = F32(p, 0x8) - F32(p, 0x14);
    if (neg <= d && d <= eps) {
        inX = 1;
    }
    if (inX) {
        inX = 0;
        d = F32(p, 0xc) - F32(p, 0x18);
        if (neg <= d && d <= eps) {
            inX = 1;
        }
        if (inX) {
            inY = 1;
        }
    }
    if (inY) {
        inY = 0;
        d = F32(p, 0x10) - F32(p, 0x1c);
        if (neg <= d && d <= eps) {
            inY = 1;
        }
        if (inY) {
            inZ = 1;
        }
    }
    if (inZ) {
        if (VEC(p, 0x368).squared() <= lbl_8054017C * *(f32*)__float_epsilon) {
            U8(p, 0x3f8) = 0;
            goto done;
        }
    }
    U8(p, 0x3f8)++;
    if (flag != 0) {
        if (U8(p, 0x3f8) >= 0x30) {
            U8(p, 0x3f8) = 0;
        }
    } else if (U8(p, 0x3f8) >= 0x18) {
        U8(p, 0x3f8) = 0;
    }
done:
    if (flag != 0) {
        U8(p, 0x3f9) = (lbl_8046B790 + S32(p, 0x3dc) * 8)[U8(p, 0x3f8) / 6];
    } else {
        U8(p, 0x3f9) = (lbl_8046B790 + S32(p, 0x3dc) * 8)[U8(p, 0x3f8) / 3];
    }
    JGeometry::TVec3<f32>* pos = (JGeometry::TVec3<f32>*)((char*)lbl_8046B7B0 + U8(p, 0x3f9) * 0x14);
    f32 x = pos->x;
    f32 y = pos->y;
    F32(p,0x2f4) = x;
    f32 z = pos->z;
    F32(p,0x2f8) = y;
    F32(p,0x2fc) = z;
    VEC(p, 0x2f4).add(VEC(p, 0x8));
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
extern "C" void fn_8026173C(char* p) {
    p[0x121c] = 0;
    S32(p, 0xd84) = 20;
}

#include "JSystem/JGeometry/Box.h"
extern JGeometry::TVec3<f32> lbl_8046B760[];
extern const f32 lbl_80540184;
extern const f64 lbl_80540190;
extern const f32 lbl_80540198;
extern "C" {
u8 fn_8022D75C(s32);
u8 fn_80234ECC(s32);
u8 fn_80234BC0(s32);
void* fn_8013CC50(s32, void*, f32, s32, s32, s32, s32, s32, s32);
u8 fn_80241E28(char*, s32, void*);
void fn_80248004(char*, s32, s32);
void* fn_8023E2A0(s32);
s32 fn_8023E190(s32);
u8 fn_8022BC38(s32, s32, void*);
u32 fn_8022C5EC(s32, s32);
void fn_8026E464(void*);
u8 fn_802518AC(char*, s32);
void fn_8024BAEC(char*);
void fn_80231194(s32);
void fn_8030BD3C(void*, s32);
s32 fn_80230CFC(s32);
void fn_802685D4(char*);
}



static inline bool isAttachedPlayer(char* p) {
    if (S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4 && U8(p, 0xd64) == 0)
        return true;
    return false;
}

static inline f32* roomOffset(s32 room) {
    char* r = fn_802D6A9C();
    return room < 8 ? (f32*)(r + 0xcc) : (f32*)(r + 0xdc);
}

static inline u8 isSideView(s32 room) {
    return *(u8*)(fn_802D6A9C() + 0x10000 + room + 0x31df);
}

static inline bool playerBoxContains(const JGeometry::TBox2f& b, const JGeometry::TVec3<f32>& v) {
    f32 x;
    f32 y;
    bool in = false;
    if ((x = v.x) >= b.i.x && (y = v.y) >= b.i.y && x < b.f.x && y < b.f.y) {
        in = true;
    }
    return in;
}

static inline bool anyBtn(char* p) {
    u8* s = (u8*)S32(p, 0xbf0);
    for (s32 i = 0; i < 8; i++) {
        if (s[0xb4] == 1 && (i == 2 || i == 4 || i == 5)) {
            continue;
        }
        if (s[i + 0x48] == 1) {
            return true;
        }
    }
    return false;
}

extern "C" void fn_802685D4(char*);
#pragma opt_lifetimes off
extern "C" void fn_80261750(Actor* this_) {
    char* p = (char*)this_;
    s32 id = S32(p, 0xd70);
    bool attached;
    if (((id >= 0 && id < 4) || S32(p, 0xd68) >= 0) && U8(p, 0xd64) == 0)
        attached = true;
    else
        attached = false;
    if (attached) {
        bool attachedPlayer;
        if (id >= 0 && id < 4 && U8(p, 0xd64) == 0)
            attachedPlayer = true;
        else
            attachedPlayer = false;
        if (attachedPlayer) {
            if (!fn_8023EFEC(id)) {
                if (F32(p, 0x10) <= lbl_80540164) {
                    f32 zero = lbl_80540150;
                    F32(p, 0xd78) = zero;
                    F32(p, 0xd7c) = zero;
                    F32(p, 0xd80) = zero;
                } else {
                    const JGeometry::TVec3<f32>& v = lbl_8046B760[S32(p, 0x3dc)];
                    f32 x = v.x;
                    f32 y = v.y;
                    F32(p, 0xd78) = x;
                    f32 z = v.z;
                    F32(p, 0xd7c) = y;
                    F32(p, 0xd80) = z;
                }
                fn_8024F0E8(p, 0x20014);
                S32(p, 0xd70) = -1;
                S32(p, 0xd58) = 5;
            } else {
                if (!fn_8022D75C(S32(p, 0xd70)) || !fn_80234ECC(S32(p, 0xd70)) || S32(p, 0x3b4) >= 8 ||
                    fn_8023DE58(S32(p, 0xd70)) != 8) {
                    S32(p, 0x3b4) = fn_8023DE58(S32(p, 0xd70));
                }
                VEC(p, 0x8) = *(JGeometry::TVec3<f32>*)fn_8023E7B0(S32(p, 0xd70));
                s32 idx = fn_8023DE58(S32(p, 0xd70));
                char* r = fn_802D6A9C();
                f32* o = idx < 8 ? (f32*)(r + 0xcc) : (f32*)(r + 0xdc);
                f32 ox = o[0];
                f32 oy = o[1];
                s32 idx2 = S32(p, 0x3b4);
                r = fn_802D6A9C();
                o = idx2 < 8 ? (f32*)(r + 0xcc) : (f32*)(r + 0xdc);
                f32 x = o[0];
                f32 y = o[1];
                F32(p, 0x8) += x - ox;
                F32(p, 0xc) += y - oy;
                F32(p, 0xc) += lbl_80540180;
                F32(p, 0x10) += lbl_80540180;
                if (U8(p, 0x121c) == 0 && !(U8(lbl_8053AAF8, 0x82) & (u8)(1 << S32(p, 4))) &&
                    !fn_80234BC0(S32(p, 0xd70)) && S32(p, 0xd60) < 0 && F32(p, 0x10) >= lbl_80540184) {
                    fn_8013CC50(S32(p, 0x3b4), p + 8, lbl_80540188, 0x28f, 1, 1, 0, 0, 1);
                    U8(p, 0x121c) = 1;
                }
                if (fn_8022D75C(S32(p, 0xd70)) && !fn_80234ECC(S32(p, 0xd70))) {
                    if (!fn_80241E28(p, S32(p, 0x3b4), p + 8)) {
                        if (S32(p, 0x3b8) < 8) {
                            VEC(p, 0xcb0) = VEC(p, 0x14);
                        }
                        VEC(p, 0xcc8) = VEC(p, 0x14);
                        S32(p, 0xce0) = S32(p, 0x3b8);
                        VEC(p, 0xcd4) = VEC(p, 0x8);
                        S32(p, 0xce4) = S32(p, 0x3b4);
                        s32 room = S32(p, 0x3b4);
                        if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + room + 0x31df)) {
                            if (fn_802486A0(p) != 5 && fn_802486A0(p) != 4) {
                                fn_80248004(p, 5, 0);
                            }
                        }
                    }
                    if (!fn_8022BC38(S32(p, 0xd70), fn_8023E190(S32(p, 0xd70)), fn_8023E2A0(S32(p, 0xd70)))) {
                        VEC(p, 0xd1c) = VEC(p, 0xcbc) = VEC(p, 0xcd4) = VEC(p, 0x8);
                        F32(p, 0xcdc) = lbl_80540150;
                        F32(p, 0xcc4) = lbl_80540150;
                        F32(p, 0xd24) = lbl_80540150;
                        U8(p, 0x1216) = 0;
                        fn_8024BAEC(p);
                    }
                    fn_8030BD3C((void*)S32(p, 0xbec), S32(p, 4));
                    S32(p, 0x3e8) = S32(p, 0x3dc) = fn_80230CFC(S32(p, 0xd70));
                }
                if (!fn_8022D75C(S32(p, 0xd70))) {
                    if (!fn_80243194(p, S32(p, 0xd70)) && fn_8022C5EC(S32(p, 4), 0xf)) {
                        U8(p, 0x3fa) += 1;
                        U8(p, 0x3fc) += 6;
                    } else {
                        U8(p, 0x3fc) += 1;
                    }
                    if (U8(p, 0x3fa) > 0x10) {
                        fn_80231194(S32(p, 0xd70));
                    }
                }
            }
            if (S32(p, 0x3b4) < 8 && S32(p, 0xd70) >= 0 && fn_8023DE58(S32(p, 0xd70)) > 8) {
                fn_80230C6C(S32(p, 0xd70));
            }
        } else {
            char* actor = fn_801F666C(fn_801F856C(), S32(p, 0xd68));
            if (actor) {
                F32(p, 0x8) = F32(p, 0x300);
                F32(p, 0xc) = F32(p, 0x304);
                F32(p, 0x10) = F32(p, 0x308);
                if (fn_8022C5EC(S32(p, 4), 0xf)) {
                    U8(p, 0x3fc) += 6;
                } else {
                    U8(p, 0x3fc) += 1;
                }
            } else {
                f32 zero = lbl_80540150;
                S32(p, 0xd68) = -1;
                F32(p, 0xd78) = zero;
                F32(p, 0xd7c) = zero;
                F32(p, 0xd80) = zero;
            }
        }
        fn_8026E464((void*)S32(p, 0xbf0));
        S32((char*)S32(p, 0xbf0), 0xa0) = 0;
    } else {
        fn_8027221C(p, 4);
        u8 flag31 = 0;
        VEC(p, 0x8) += VEC(p, 0xd78);
        F32(p, 0xd80) -= lbl_80540190;
        s32 area = S32(p, 0x3b4);
        char* world = fn_802D6A9C();
        JGeometry::TBox2f box;
        JGeometry::TBox2f* bounds = area < 8 ? (JGeometry::TBox2f*)(world + 0xcc) : (JGeometry::TBox2f*)(world + 0xdc);
        ((u32*)&box)[0] = ((u32*)bounds)[0];
        ((u32*)&box)[1] = ((u32*)bounds)[1];
        ((u32*)&box)[2] = ((u32*)bounds)[2];
        ((u32*)&box)[3] = ((u32*)bounds)[3];
        f32 m = lbl_80540198;
        box.i.x -= m;
        box.i.y -= m;
        box.f.x += m;
        box.f.y += m;
        s32 area2 = S32(p, 0x3b4);
        if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + area2 + 0x31df)) {
            if (!playerBoxContains(box, VEC(p, 0x8))) {
                F32(p, 0x10) = lbl_80540150;
                flag31 = 1;
            }
        }
        if (F32(p, 0x10) <= lbl_80540150) {
            s32 area3 = S32(p, 0x3b4);
            if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + area3 + 0x31df)) {
                if (flag31 || fn_802518AC(p, 1)) {
                    F32(p, 0x10) = lbl_80540150;
                } else {
                    F32(p, 0xc) += lbl_80540188 - F32(p, 0x10);
                    F32(p, 0x10) = lbl_80540188;
                }
            }
            if (F32(p, 0x10) <= lbl_80540150) {
                VEC(p, 0x368).set(F32(p, 0xd78), F32(p, 0xd7c), lbl_80540150);
                F32(p, 0xd78) = lbl_80540150;
                F32(p, 0xd7c) = lbl_80540150;
                F32(p, 0xd80) = lbl_80540150;
                F32(p, 0x10) = lbl_80540150;
                if (U8(lbl_8053AAF8, 0x7e) != 0 && !(U8(lbl_8053AAF8, 0x82) & (u8)(1 << S32(p, 4))) && S32(p, 0xd60) < 0) {
                    fn_80251AEC(p, 1);
                } else {
                    fn_80251AEC(p, 0);
                }
            }
        } else if (fn_802466B4(p) && fn_80251AEC(p, 7)) {
            VEC(p, 0x344).set(VEC(p, 0xd78));
            VEC(p, 0x368).set(F32(p, 0xd78), F32(p, 0xd7c), lbl_80540150);
            F32(p, 0xd78) = lbl_80540150;
            F32(p, 0xd7c) = lbl_80540150;
            F32(p, 0xd80) = lbl_80540150;
            fn_802685D4(p);
        }
        s32 area4 = S32(p, 0x3b4);
        if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + area4 + 0x31df)) {
            char* bf0 = (char*)S32(p, 0xbf0);
            bool hit;
            if (U8(bf0, 0x49) == 1) {
                hit = true;
            } else if (U8(bf0, 0x48) == 1) {
                hit = true;
            } else {
                hit = false;
            }
            if (hit) {
                F32(p, 0xd78) = -F32(p, 0xd78) * lbl_80540178;
            }
        } else {
            if (anyBtn(p)) {
                f32 scale = lbl_80540178;
                F32(p, 0xd78) = -F32(p, 0xd78) * scale;
                F32(p, 0xd7c) = -F32(p, 0xd7c) * scale;
            }
        }
    }
    if (U8(p, 0x3fc) >= 0x24) {
        U8(p, 0x3fc) = 0;
    }
    if (U8(p, 0x3fc) < 0x6) {
        U8(p, 0x3fd) = 0;
    } else if (U8(p, 0x3fc) < 0xc) {
        U8(p, 0x3fd) = 1;
    } else if (U8(p, 0x3fc) < 0x12) {
        U8(p, 0x3fd) = 0;
    } else if (U8(p, 0x3fc) < 0x18) {
        U8(p, 0x3fd) = 2;
    } else if (U8(p, 0x3fc) < 0x1e) {
        U8(p, 0x3fd) = 3;
    } else {
        U8(p, 0x3fd) = 2;
    }
}
#pragma opt_lifetimes reset
extern "C" void fn_80262188(char* p) {
    p[0x458] = 0;
    if (S32(p, 0x1248) != 0x33 && U8(p, 0xcfe) == 0)
        fn_8024F0E8(p, 0x10007);
    s32 id = S32(p, 0xd70);
    if (id >= 0 && U8(lbl_8053AAF8, 0x7e) != 0 &&
        !((u8)lbl_8053AAF8[0x82] & (u8)(1U << U32(p, 4))) && S32(p, 0xd60) < 0) {
        S32(p, 0x11ec) = fn_8022F340(id);
        S32(p, 0xd60) = fn_8022F340(S32(p, 0xd70));
    }
}

extern "C" void fn_80262234(char* p) {
    fn_80258BBC(p);
}

extern "C" f32 fn_8022C6AC(s32);
extern "C" f32 fn_8022C82C(s32);
extern "C" f32 fn_8022C76C(s32);
extern "C" u8 fn_8022C274(s32);
extern "C" u8 fn_8022C310(s32);
extern "C" void fn_80259778(char*);
extern "C" u8 fn_80245938(char*);
extern "C" s32 fn_802415CC(char*);
extern const f32 lbl_805401C4;
extern const f32 lbl_805401C8;
extern JGeometry::TVec3<f32> lbl_8046B670[];
extern "C" void fn_8024B298(char*,s32,JGeometry::TVec3<f32>*);
static inline f32 playerVelocitySquared(const JGeometry::TVec3<f32>& velocity) {
    return velocity.squared();
}
#pragma opt_common_subs off
#pragma opt_propagation on
extern "C" void fn_80262254(char* self) {
 char* p = self;
 if (fn_8022C6AC(U32(p,4)) > lbl_80540150) {
if (lbl_80540150 == F32(p,0x344)) {
 F32(p,0x344) = lbl_8054019C * fn_8022C82C(S32(p,4));
} else if (F32(p,0x344) > lbl_80540150) {
 if (F32(p,0x34c) >= lbl_80540150) F32(p,0x344) += lbl_805401A0 * fn_8022C82C(S32(p,4));
 else F32(p,0x344) += lbl_805401A4 * fn_8022C82C(S32(p,4));
 if (F32(p,0x344) <= lbl_805401A8 || U8(((char*)S32(p,0xbf0)),0x48)) F32(p,0x344) = lbl_805401A8;
} else if (F32(p,0x344) < lbl_80540150) {
 if (F32(p,0x34c) >= lbl_80540150) F32(p,0x344) += lbl_805401A0 * fn_8022C82C(S32(p,4));
 else F32(p,0x344) += lbl_805401A4 * fn_8022C82C(S32(p,4));
 if (F32(p,0x344) >= lbl_805401AC || U8(((char*)S32(p,0xbf0)),0x49)) F32(p,0x344) = lbl_805401AC;
}
if (lbl_80540150 == F32(p,0x348)) {
 F32(p,0x348) = lbl_8054019C * -fn_8022C76C(S32(p,4));
} else if (F32(p,0x348) > lbl_80540150) {
 if (F32(p,0x34c) >= lbl_80540150) F32(p,0x348) -= lbl_805401A0 * fn_8022C76C(S32(p,4));
 else F32(p,0x348) -= lbl_805401A4 * fn_8022C76C(S32(p,4));
 if (F32(p,0x348) <= lbl_805401A8 || U8(((char*)S32(p,0xbf0)),0x4a)) F32(p,0x348) = lbl_805401A8;
} else if (F32(p,0x348) < lbl_80540150) {
 if (F32(p,0x34c) >= lbl_80540150) F32(p,0x348) -= lbl_805401A0 * fn_8022C76C(S32(p,4));
 else F32(p,0x348) -= lbl_805401A4 * fn_8022C76C(S32(p,4));
 if (F32(p,0x348) >= lbl_805401AC || U8(((char*)S32(p,0xbf0)),0x4b)) F32(p,0x348) = lbl_805401AC;
}
f32 savedZ = F32(p,0x34c);
 F32(p,0x34c)=lbl_80540150;
 f32 mag=VEC(p,0x344).length();
 if(mag>=lbl_805401B0)mag=lbl_805401B0;
 VEC(p,0x344).normalize(); VEC(p,0x344).scale(mag);
 F32(p,0x34c)=savedZ;
 } else {
 JGeometry::TVec3<f32>& velocity = VEC(p,0x344);
 f32 xSquared=velocity.x*velocity.x;
 f32 ySquared=velocity.y*velocity.y;
 f32 sq=xSquared+ySquared;
 if (!(sq<=lbl_8054017C * *(f32*)__float_epsilon)) {
 f32 savedZ=F32(p,0x34c);
 F32(p,0x34c)=lbl_80540150;
 f32 mag=velocity.length();
 if(fn_8022C274(U32(p,4))) {
 if(savedZ>=lbl_80540150) {
 mag+=lbl_805401A0; if(mag>=lbl_805401B0)mag=lbl_805401B0;
 }else {mag+=lbl_805401A4;if(mag>=lbl_805401B0)mag=lbl_805401B0;}
 }else {mag-=lbl_805401B8;if(mag<=lbl_805401A8)mag=lbl_805401A8;}
 VEC(p,0x344).normalize(); VEC(p,0x344).scale(mag);
 F32(p,0x34c)=savedZ;
 }
 }

 if (playerVelocitySquared(VEC(p,0x344)) <= lbl_8054017C * *(f32*)__float_epsilon) {
     if (!(F32(p,0x10) > lbl_80540150)) goto afterPhysics;
 }
 if (U8(p,0x3fa) < 1) goto afterPhysics;
 F32(p,0x34c) -= lbl_805401BC;
 if (F32(p,0x34c) < lbl_805401C0) F32(p,0x34c) = lbl_805401C0;
 {
     s32 room = S32(p,0x3b4);
     u8* rooms = (u8*)fn_802D6A9C();
     if (U8(rooms,0x131df + room)) {
         F32(p,8) += F32(p,0x344);
         F32(p,0xc) -= F32(p,0x34c);
         F32(p,0x10) = lbl_80540178;
         if (F32(p,0x34c) < lbl_80540150 && U8((char*)S32(p,0xbf0),0x4a)) {
             VEC(p,0x368).set(F32(p,0x344),F32(p,0x348),lbl_80540150);
             F32(p,0x344)=lbl_80540150; F32(p,0x348)=lbl_80540150; F32(p,0x34c)=lbl_80540150; F32(p,0x10)=lbl_80540150;
         }
     } else {
         VEC(p,8).add(VEC(p,0x344));
         if (F32(p,0x34c) < lbl_80540150 && F32(p,0x10) <= lbl_80540150) {
             F32(p,0x10)=lbl_80540150;
             VEC(p,0x368).set(F32(p,0x344),F32(p,0x348),lbl_80540150);
             F32(p,0x344)=lbl_80540150; F32(p,0x348)=lbl_80540150; F32(p,0x34c)=lbl_80540150;
         }
     }
 }
 afterPhysics:
 if (fn_80245938(p)) U8(p,0x3fb)=1;
 if (U8(p,0x3fb)==1) {
     ++U8(p,0x3fc);
     if (U8(p,0x3fc)<8) U8(p,0x3fd)=0;
     else if (U8(p,0x3fc)<9) { fn_8025F698(p,0); U8(p,0x3fd)=1; }
     else if (U8(p,0x3fc)<11) U8(p,0x3fd)=2;
     else if (U8(p,0x3fc)<21) U8(p,0x3fd)=3;
     else if (U8(p,0x3fc)<25) U8(p,0x3fd)=4;
     else U8(p,0x3fd)=2;
     VEC(p,0x2f4).set(lbl_8046B670[S32(p,0x3dc)*5+U8(p,0x3fd)]);
     VEC(p,0x2f4).add(VEC(p,8));
     fn_80268B3C(p);
 }
 if(U8(p,0xb79)==0 && F32(p,0x10)>lbl_80540150 && fn_802415CC(p)>=2 && fn_8022C310(S32(p,4))) {
     U8(p,0x3fa)=0; fn_80259778(p); U8(p,0xb79)=1;
 }
 if(U8(p,0x3fa)>=2 && F32(p,0x10)<=lbl_80540150) {
     F32(p,0x10)=lbl_80540150;
     if(U8(p,0xd64)==1) fn_80251AEC(p,0x12); else fn_80251AEC(p,0);
 }
 if(U8(p,0x3fa)>=8) {
     s32 room=S32(p,0x3b4);
     u8* rooms=(u8*)fn_802D6A9C();
     if(U8(rooms,0x131df+room) && F32(p,0x34c)<lbl_80540150 && F32(p,0x10)<=lbl_80540188) {
         JGeometry::TVec3<f32> pos;
         fn_8024B298(p,2,&pos);
         pos.y+=lbl_80540180;
         if(fn_8022461C(&pos,S32(p,0x3b4))!=2) {
             if(U8(p,0xd64)==1) fn_80251AEC(p,0x12); else fn_80251AEC(p,0);
         }
     }
 }
 ++U8(p,0x3fa);
 fn_802685D4(p);
 VEC(p,0x2f4).set(lbl_80540150,lbl_80540150,lbl_805401C4);
 VEC(p,0x2f4).add(VEC(p,8));
 if(F32(p,0x34c)<lbl_805401C8) U8(p,0x3f9)=1; else U8(p,0x3f9)=0;
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
extern "C" void fn_80262B6C(char* p) {
    fn_80259660(p);
}

extern "C" void fn_80262B8C(char* p) {
    fn_80283D2C(p);
}

extern const f32 lbl_80540178;
extern const f32 lbl_805401CC;
extern const f32 lbl_805401BC;
extern const f32 lbl_805401C0;
extern const f32 lbl_805401D0;
extern const f32 lbl_805401B8;
extern const f32 lbl_805401C4;
extern const f32 lbl_805401D4;
extern const f32 lbl_805401D8;
extern const f32 lbl_805401DC;

#pragma opt_common_subs off
#pragma opt_propagation off
static inline f32 carriedPositionDelta(f32 goal, f32 value) {
    return goal - value;
}

static inline f32 stepCarriedPosition(f32* pos, const f32 target, const f32 step) {
    f32 delta = carriedPositionDelta(target, *pos);
    if (delta >= step) {
        *pos += step;
    } else if (delta <= lbl_805401CC) {
        *pos -= step;
    } else if (lbl_80540150 != delta) {
        *pos = target;
    }
    return delta;
}

static inline bool carriedPositionUnchanged(char* p) {
    bool inZ;
    bool inX;
    bool inY;
    inZ = false;
    inY = inZ;
    inX = inZ;
    f32 neg;
    f32 d;
    f32 eps;
    f32 machineEps = *(f32*)__float_epsilon;
    eps = lbl_8054017C * machineEps;
    neg = -eps;
    d = F32(p, 0x8) - F32(p, 0x14);
    if (neg <= d && d <= eps) {
        inX = 1;
    }
    if (inX) {
        inX = 0;
        d = F32(p, 0xc) - F32(p, 0x18);
        if (neg <= d && d <= eps) {
            inX = 1;
        }
        if (inX) {
            inY = 1;
        }
    }
    if (inY) {
        inY = 0;
        d = F32(p, 0x10) - F32(p, 0x1c);
        if (neg <= d && d <= eps) {
            inY = 1;
        }
        if (inY) {
            inZ = 1;
        }
    }

    return inZ;
}
#pragma opt_propagation reset
#pragma opt_common_subs reset

#pragma optimization_level 3
#pragma opt_common_subs off
extern "C" void fn_80262BAC(char* p) {
    if (U32(p, 0xd6c) == 0x4e495741 && U8(p, 0x441) == 0) {
        f32 d = stepCarriedPosition((f32*)(p + 8), F32(p, 0x324), lbl_80540178);
        if (lbl_80540150 != d) {
            F32(p, 0x34c) -= lbl_805401BC;
            if (F32(p, 0x34c) <= lbl_80540150)
                F32(p, 0x34c) = lbl_80540150;
            F32(p, 0x10) += F32(p, 0x34c);
            s32 ang = (s32)(lbl_805401D0 * d);
            F32(p, 0x10) += lbl_805401B8 * JMath::sincosTable_.mTable[(u16)ang >> 5].first;
        } else {
            F32(p, 0x34c) -= lbl_805401BC;
            if (F32(p, 0x34c) <= lbl_805401C0)
                F32(p, 0x34c) = lbl_805401C0;
            F32(p, 0x10) += F32(p, 0x34c);
            if (F32(p, 0x10) <= lbl_80540150) {
                F32(p, 0x10) = lbl_80540150;
                if (fn_80251AEC(p, 0x12)) U8(p, 0xce8) = 0;
            }
        }
        F32(p, 0x2f4) = lbl_80540150;
        F32(p, 0x2f8) = lbl_80540150;
        F32(p, 0x2fc) = lbl_805401C4;
        VEC(p, 0x2f4) += VEC(p, 0x8);
        goto end;
    }
    if (F32(p, 0x10) >= lbl_80540150)
        VEC(p, 0x8) += VEC(p, 0x344);
    if (U8(p, 0x43f) != 0 || U8(p, 0x441) != 0) {
        if (F32(p, 0x34c) >= lbl_805401D4) {
            F32(p, 0x34c) -= lbl_805401D8;
            if (F32(p, 0x34c) < lbl_805401D4)
                F32(p, 0x34c) = lbl_805401D4;
        }
    } else {
        F32(p, 0x34c) -= lbl_805401BC;
    }
    if (F32(p, 0x10) <= lbl_80540150) {
        if ((U8(p, 0x43f) != 0 || U8(p, 0x441) != 0) && F32(p, 0xc) < F32(p, 0x328)) {
            F32(p, 0x10) = lbl_805401DC;
        } else {
            F32(p, 0x10) = lbl_80540150;
            U8(p, 0x124d) = 0;
            fn_80251AEC(p, 0x12);
        }
    }
    bool inZ = carriedPositionUnchanged(p);
    if (inZ && VEC(p, 0x368).squared() <= lbl_8054017C * *(f32*)__float_epsilon) {
        U8(p, 0x3f8) = 0;
    } else {
        U8(p, 0x3f8)++;
        if (U8(p, 0x3f8) >= 0x18)
            U8(p, 0x3f8) = 0;
    }
    U8(p, 0x3f9) = (lbl_8046B790 + S32(p, 0x3dc) * 8)[U8(p, 0x3f8) / 3];
    JGeometry::TVec3<f32>* pos = (JGeometry::TVec3<f32>*)((char*)lbl_8046B7B0 + U8(p, 0x3f9) * 0x14);
    f32* src = &pos->x;
    f32 x = *src++;
    f32 y = *src++;
    F32(p,0x2f4) = x;
    f32 z = *src;
    F32(p,0x2f8) = y;
    F32(p,0x2fc) = z;
    VEC(p, 0x2f4).add(VEC(p, 0x8));
    if (U8(p, 0x440) != 0 && F32(p, 0x34c) < lbl_80540150) {
        fn_8024F0E8(p, 0x1000d);
        fn_8024F0E8(p, 0x2003e);
    }
end:
    if (F32(p, 0x34c) < lbl_805401E0) {
        U8(p, 0x3f9) = 1;
    } else {
        U8(p, 0x3f9) = 0;
    }
}
#pragma opt_common_subs reset
#pragma optimization_level reset
extern "C" void fn_80263078(char* p) {
    JGeometry::TVec2<f32> pos;
    fn_8028414C(p);
    if (U32(p, 0xd6c) == 0x4E495741 && U8(p, 0x441) == 0) {
        char* a = fn_801F666C(fn_801F856C(), S32(p, 0xd68));
        if (a != NULL && *(s8*)(a + 0x2a1) == 1) {
            s32 id;
            s32 n = 2;
            pos.x = F32(p, 0x8);
            pos.y = F32(p, 0xc);
            do {
                if (F32(p, 0x344) > lbl_80540150) {
                    pos.x += lbl_80540154;
                } else {
                    pos.x -= lbl_80540154;
                }
                id = S32(p, 0x3b4);
                char* base = fn_802D6A9C();
                if (id < 8) {
                    base += 0xcc;
                } else {
                    base += 0xdc;
                }
                f32 y;
                f32 x;
                u8 inside = 0;
                if ((x = pos.x) >= F32(base, 0) && (y = pos.y) >= F32(base, 4) && x < F32(base, 8) && y < F32(base, 0xc)) {
                    inside = 1;
                }
                if (!inside) {
                    break;
                }
                u16 r = fn_802265FC(&pos, S32(p, 0x3b4));
                if (r >= 0x10 && r <= 0x17) {
                    n--;
                }
            } while (n > 0);
            if (n == 0) {
                if (F32(p, 0x344) > lbl_80540150) {
                    pos.x += lbl_80540154;
                } else {
                    pos.x -= lbl_80540154;
                }
                F32(p, 0x324) = pos.x;
                F32(p, 0x328) = pos.y;
                F32(p, 0x34c) = lbl_80540180;
            } else {
                F32(p, 0x34c) = lbl_80540180;
                F32(p, 0x10) = F32(p, 0x328) - F32(p, 0xc);
                F32(p, 0xc) = F32(p, 0x328);
            }
        } else {
            F32(p, 0x34c) = lbl_80540180;
            F32(p, 0x10) = F32(p, 0x328) - F32(p, 0xc);
            F32(p, 0xc) = F32(p, 0x328);
        }
        if (F32(p, 0x344) > lbl_80540150) {
            S32(p, 0x3dc) = 0;
            S32(p, 0x3e8) = 0;
        } else if (F32(p, 0x344) < lbl_80540150) {
            S32(p, 0x3dc) = 1;
            S32(p, 0x3e8) = 1;
        }
    }
}

extern "C" void fn_802632A4(void) {}

extern "C" void fn_802632A8(char* p) {
    U8(p, 0x3fc)++;
    if (U8(p, 0x3fc) < 8) {
        U8(p, 0x3fd) = 0;
    } else if (U8(p, 0x3fc) < 10) {
        U8(p, 0x3fd) = 1;
    } else if (U8(p, 0x3fc) < 11) {
        U8(p, 0x3fd) = 2;
    } else if (U8(p, 0x3fc) < 12) {
        if (isCarriedByPlayer(p)) U8(p, 0x3fd) = 4;
        else U8(p, 0x3fd) = 3;
    } else {
        U8(p, 0x3fc) = 12;
        if (fn_80251AEC(p, 0)) {
            if (isCarriedByPlayer(p)) {
                U8(p, 0x3fd) = 4;
            } else {
                U8(p, 0x3fd) = 3;
                char* actor = fn_801F666C(fn_801F856C(), S32(p, 0xd68));
                if (actor) {
                    JGeometry::TVec3<f32> zero(0.0f, 0.0f, 0.0f);
                    fn_801F3708(actor, &zero);
                }
            }
            S32(p, 0xd70) = -1;
            S32(p, 0xd68) = -1;
            U8(p, 0xd64) = 0;
            S32(p, 0xd6c) = 0x4e554c4c;
            S32(p, 0xd74) = 3;
        }
    }
    const volatile Vec* a = &lbl_8046B580[S32(p, 0x3dc)*5 + U8(p, 0x3fd)];
    f32 ax = a->x;
    f32 ay = a->y;
    F32(p, 0x2f4) = ax;
    f32 az = a->z;
    F32(p, 0x2f8) = ay;
    F32(p, 0x2fc) = az;
    VEC(p, 0x2f4).add(VEC(p, 0x8));
    if (fn_8025EB18(p) && VEC(p, 0x35c).length() < lbl_80540188) {
        const volatile Vec* b = &lbl_8046B580[S32(p, 0x3dc)*5 + 3];
        f32 bx = b->x;
        f32 by = b->y;
        F32(p, 0x35c) = bx;
        f32 bz = b->z;
        F32(p, 0x360) = by;
        F32(p, 0x364) = bz;
        F32(p, 0x364) = 0.0f;
        VEC(p, 0x35c).normalize();
        VEC(p, 0x35c).scale(lbl_805401E0);
    }
    fn_80268B3C(p);
}

extern "C" void fn_802635C8(char* p) {
    p[0x458] = 0;
}

extern "C" void fn_802635D4(void) {
}

#pragma opt_propagation off
extern "C" void fn_802635D8(char* p) {
    ++U8(p, 0x3fc);
    if (U8(p, 0x3fc) < 2) {
        p[0x3fd] = 2;
    } else if (U8(p, 0x3fc) < 10) {
        p[0x3fd] = 3;
    } else if (U8(p, 0x3fc) < 14) {
        p[0x3fd] = 4;
    } else {
        p[0x3fd] = 2;
        fn_80251AEC(p, 0);
    }
    const JGeometry::TVec3<f32>& pos = lbl_8046B490[S32(p, 0x3dc) * 5 + U8(p, 0x3fd)];
    f32 x;
    f32 y;
    x = pos.x;
    y = pos.y;
    F32(p, 0x2f4) = x;
    f32 z = pos.z;
    F32(p, 0x2f8) = y;
    F32(p, 0x2fc) = z;
    VEC(p, 0x2f4).add(VEC(p, 8));
    fn_8025EB18(p);
    fn_80268B3C(p);
}
#pragma opt_propagation reset
extern "C" void fn_802636C4(char* p) {
    p[0x458] = 0;
}

extern "C" void fn_80263848(char* p) {
    p[0x458] = 0;
}

extern "C" void fn_80263854(char* p) {
    p[0x459] = 0;
}

extern "C" void fn_80206168(char*);
extern "C" u8 fn_802A3164(char*, JGeometry::TVec3<f32>*, s32, s32);
extern JGeometry::TVec3<f32> lbl_8046B310[];
extern char* lbl_8053AC98;
extern const f32 lbl_80540188;
extern const f32 lbl_805401E0;
extern "C" void fn_80263860(char* p) {
    U8(p, 0x3fc)++;
    if (U8(p, 0x3fc) < 8) {
        p[0x3fd] = 0;
    } else if (U8(p, 0x3fc) < 9) {
        p[0x3fd] = 1;
    } else if (U8(p, 0x3fc) < 10) {
        p[0x459] = 1;
        p[0x3fd] = 2;
    } else if (U8(p, 0x3fc) < 0x12) {
        p[0x3fd] = 3;
        if (U8(p, 0x3fc) == 0xb && U32(p, 0xd6c) == 'TZOK') {
            char* actor = fn_801F666C(fn_801F856C(), S32(p, 0xd68));
            if (actor)
                fn_80206168(actor);
        }
    } else if (U8(p, 0x3fc) < 0x16) {
        p[0x3fd] = 4;
    } else {
        p[0x3fd] = 2;
        fn_80251AEC(p, 0x12);
    }
    const volatile JGeometry::TVec3<f32>& pos = lbl_8046B310[S32(p, 0x3dc) * 5 + U8(p, 0x3fd)];
    f32 x = pos.x;
    f32 y = pos.y;
    F32(p, 0x2f4) = x;
    f32 z = pos.z;
    F32(p, 0x2f8) = y;
    F32(p, 0x2fc) = z;
    VEC(p, 0x2f4).add(VEC(p, 8));
    if (U8(p, 0x3fd) == 2) {
        JGeometry::TVec3<f32> v = VEC(p, 0x2f4);
        v.z = 0.0f;
        if (fn_802A3164(lbl_8053AC98, &v, S32(p, 4), S32(p, 0x3b4))) {
            char* actor = fn_801F666C(fn_801F856C(), S32(p, 0xd68));
            if (actor)
                ((Actor*)actor)->v16();
        }
    }
    if (fn_8025EB18(p)) {
        p[0x3fd] = 1;
        p[0x459] = 0;
        const volatile JGeometry::TVec3<f32>& pos2 = lbl_8046B310[S32(p, 0x3dc) * 5 + U8(p, 0x3fd)];
        f32 x2 = pos2.x;
        f32 y2 = pos2.y;
        F32(p, 0x2f4) = x2;
        f32 z2 = pos2.z;
        F32(p, 0x2f8) = y2;
        F32(p, 0x2fc) = z2;
        VEC(p, 0x2f4).add(VEC(p, 8));
        if (VEC(p, 0x35c).length() < lbl_80540188) {
            const volatile JGeometry::TVec3<f32>& pos3 = lbl_8046B310[S32(p, 0x3dc) * 5 + 2];
            f32 x3 = pos3.x;
            f32 y3 = pos3.y;
            F32(p, 0x35c) = x3;
            f32 z3 = pos3.z;
            F32(p, 0x360) = y3;
            F32(p, 0x364) = z3;
            VEC(p, 0x35c).z = 0.0f;
            VEC(p, 0x35c).normalize();
            VEC(p, 0x35c).scale(lbl_805401E0);
        }
    }
    fn_80268B3C(p);
}

extern "C" void fn_80263BA0(char* p) {
    p[0x458] = 0;
    p[0x459] = 0;
    u8 carrying;
    if ((u8)(U8(p, 0xd64) == 1) == 1 && S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4)
        carrying = true;
    else
        carrying = false;
    if (carrying) {
        fn_8027221C(p, 4);
    } else {
        char* actor = fn_801F666C(fn_801F856C(), S32(p, 0xd68));
        if (actor)
            fn_8027221C(p, S32(actor, 0x118));
        else
            fn_8027221C(p, 0);
    }
    fn_8024F0E8(p, 0x1000e);
}

static inline void updateCarrySnap(char* p) {
    bool inZ = carriedPositionUnchanged(p);
    if (inZ && VEC(p, 0x368).squared() <= lbl_8054017C * *(f32*)__float_epsilon) {
        U8(p, 0x3f8) = 0;
    } else {
        U8(p, 0x3f8)++;
        if (U8(p, 0x3f8) >= 0x18)
            U8(p, 0x3f8) = 0;
    }
    U8(p, 0x3f9) = (lbl_8046B790 + S32(p, 0x3dc) * 8)[(s32)U8(p, 0x3f8) / 3];
    JGeometry::TVec3<f32>* pos = (JGeometry::TVec3<f32>*)((char*)lbl_8046B7B0 + U8(p, 0x3f9) * 0x14);
    f32* src = &pos->x;
    f32 x = *src++;
    f32 y = *src++;
    F32(p,0x2f4) = x;
    f32 z = *src;
    F32(p,0x2f8) = y;
    F32(p,0x2fc) = z;
    VEC(p, 0x2f4).add(VEC(p, 0x8));
}

extern const f32 lbl_805401E8;
extern "C" void fn_80263C64(char* p) {
    JGeometry::TVec3<f32> v;
    char* actor;
    fn_8027FA08(p, &v);
    if (lbl_80540150 == v.z && lbl_80540150 != F32(p, 0x10) && U8(p, 0x434) == 0)
        F32(p, 0x10) = lbl_80540150;
    actor = fn_801F666C(fn_801F856C(), S32(p, 0xd68));
    if (fn_8022C13C(S32(p, 4))) {
        if (fn_802416C4(p) != 7) {
            if (fn_8024B24C(p)) goto play16;
            {
                if ((isCarriedByPlayer(p) && !fn_80236B50(S32(p, 0xd70))) ||
                    (U8(p, 0xd64) == 1 ? U32(p, 0xd6c) : (u32)'NULL') == 'HBMB' ||
                    (U8(p, 0xd64) == 1 ? U32(p, 0xd6c) : (u32)'NULL') == 'KEY0') {
                    fn_80251AEC(p, 0x18);
                } else {
play16:
                    fn_80251AEC(p, 0x16);
                }
            }
        }
    } else if (fn_8022C0A0(S32(p, 4))) {
        fn_80251AEC(p, 0x16);
    } else if (fn_802466B4(p)) {
        if (!actor || S32(actor, 0x1a4) < 2)
            fn_80251AEC(p, 0x15);
    }
    if (isCarriedByPlayer(p)) {
        if (fn_8023EA28(S32(p, 0xd70))) {
            fn_802808E8(p, lbl_805401E4);
            fn_8027EB04(p);
            updateCarrySnap(p);
        } else {
            fn_80251AEC(p, 0);
            S32(p, 0xd70) = -1;
        }
    } else if (actor) {
        if (S32(actor, 0x1a4) == 0) {
            fn_802808E8(p, lbl_805401E8);
            fn_8027EB04(p);
            updateCarrySnap(p);
        } else {
            fn_8027EB04(p);
            updateCarrySnap(p);
        }
    } else {
        fn_80251AEC(p, 0);
        U8(p, 0xd64) = 0;
        S32(p, 0xd68) = -1;
        U32(p, 0xd6c) = 'NULL';
    }
    fn_80268B3C(p);
}

extern "C" void fn_80264410(char* p) {
    p[0x458] = 0;
}

extern JGeometry::TVec3<f32> lbl_8046B250[];
#pragma opt_propagation off
extern "C" void fn_8026441C(char* p) {
    s32 iVar6 = 0;
    U8(p, 0x3fc)++;
    char* actor = fn_801F666C(fn_801F856C(), S32(p, 0xd68));
    u8 held = isCarriedByPlayer(p);
    if (held) {
        if (U8(p, 0x3fc) < 8) {
            iVar6 = 0;
            U8(p, 0x3fd) = 0;
        } else if (U8(p, 0x3fc) < 0x10) {
            iVar6 = 0;
            U8(p, 0x3fd) = 1;
        } else if (U8(p, 0x3fc) < 0x18) {
            iVar6 = 1;
            U8(p, 0x3fd) = 2;
        } else {
            U8(p, 0x3fd) = 3;
            iVar6 = 2;
            fn_80251AEC(p, 0x12);
        }
    } else if (S32(p, 0xd68) < 0) {
        iVar6=0;
        if (U8(p, 0x3fc) >= 0x16) {
            U8(p, 0x3fd) = 1;
            fn_80251AEC(p, 0);
        } else if (U8(p, 0x3fc) <= 8) {
            U8(p, 0x3fd) = 0;
        } else {
            U8(p, 0x3fd) = 1;
        }
    } else if (actor == 0) {
        fn_80251AEC(p, 0);
        U8(p, 0xd64) = 0;
        U32(p, 0xd6c) = 0x4e554c4c;
        S32(p, 0xd68) = -1;
    } else if (S32(actor, 0x1a4) != 0) {
        if (U8(p, 0x3fc) <= 8) {
            iVar6 = 3;
            U8(p, 0x3fd) = 0;
        } else if (U8(p, 0x3fc) <= 0x18) {
            iVar6 = 3;
            U8(p, 0x3fd) = 1;
        } else if (U8(p, 0x3fc) <= 0x20) {
            iVar6 = 3;
            U8(p, 0x3fd) = 0;
        } else if (U8(p, 0x3fc) < 0x30) {
            iVar6 = 3;
            U8(p, 0x3fd) = 1;
        } else if (U8(p, 0x3fc) == 0x30) {
            iVar6 = 0;
            U8(p, 0x3fd) = 0;
        } else if (U8(p, 0x3fc) <= 0x38) {
            iVar6 = 0;
            U8(p, 0x3fd) = 0;
        } else if (U8(p, 0x3fc) <= 0x40) {
            iVar6 = 0;
            U8(p, 0x3fd) = 1;
        } else if (U8(p, 0x3fc) <= 0x48) {
            iVar6 = 1;
            U8(p, 0x3fd) = 2;
        } else if (U8(p, 0x3fc) <= 0x50) {
            iVar6 = 2;
            U8(p, 0x3fd) = 3;
        } else {
            U8(p, 0x3fd) = 3;
            iVar6 = 2;
            fn_80251AEC(p, 0x12);
        }
    } else {
        if (U8(p, 0x3fc) < 8) {
            iVar6 = 0;
            U8(p, 0x3fd) = 0;
        } else if (U8(p, 0x3fc) < 0x10) {
            iVar6 = 0;
            U8(p, 0x3fd) = 1;
        } else if (U8(p, 0x3fc) < 0x18) {
            iVar6 = 1;
            U8(p, 0x3fd) = 2;
        } else {
            U8(p, 0x3fd) = 3;
            iVar6 = 2;
            fn_80251AEC(p, 0x12);
        }
    }
    if (iVar6 >= 0) {
        JGeometry::TVec3<f32>* v = &lbl_8046B250[iVar6 + S32(p, 0x3dc) * 4];
        f32 x=v->x;
        f32 y=v->y;
        F32(p,0x2f4)=x;
        f32 z=v->z;
        F32(p,0x2f8)=y;
        F32(p,0x2fc)=z;
        VEC(p, 0x2f4) += VEC(p, 0x8);
    }
    fn_8025EB18(p);
    fn_80268B3C(p);
}
#pragma opt_propagation reset
extern "C" void fn_80264768(char* p) {
    p[0x458] = 0;
}



#if !defined(VERSION_G4SJ01)
extern "C" void fn_802636D4(char* p) {
    U8(p, 0x3fc)++;
    if (U8(p, 0x3fc) < 8) {
        U8(p, 0x3fd) = 0;
    } else if (U8(p, 0x3fc) < 10) {
        U8(p, 0x3fd) = 1;
    } else {
        U8(p, 0x3fd) = 2;
        if (fn_80251AEC(p, 0x17)) {
            u8 carrying;
            if ((u8)(U8(p, 0xd64) == 1) == 1 && S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4)
                carrying = true;
            else
                carrying = false;
            if (carrying) {
                void* pos;
                u32 param;
                s32 id;
                param = U32(p, 0x4) & 0xffff;
                id = S32(p, 0xd70);
                pos = fn_8023E724(id);
                Actor_CreateByID(fn_801F856C(), 0x5448434c, S32(p, 0x3b4), pos, id, -1, param);
            }
        }
    }
    const JGeometry::TVec3<f32>& pos = lbl_8046B400[S32(p, 0x3dc) * 3 + U8(p, 0x3fd)];
    f32 y = pos.y;
    f32 x = pos.x;
    F32(p, 0x2f4) = x;
    f32 z = pos.z;
    F32(p, 0x2f8) = y;
    F32(p, 0x2fc) = z;
    VEC(p, 0x2f4).add(VEC(p, 8));
    fn_8025EB18(p);
    fn_80268B3C(p);
}
#endif


extern "C" void fn_802636D0(void) {}

// Keep regional definitions that were present before source-tree consolidation.
#if defined(VERSION_G4SJ01)
extern "C" void fn_802636D4(char* p) {
    U8(p, 0x3fc)++;
    if (U8(p, 0x3fc) < 8) {
        U8(p, 0x3fd) = 0;
    } else if (U8(p, 0x3fc) < 10) {
        U8(p, 0x3fd) = 1;
    } else {
        U8(p, 0x3fd) = 2;
        u8 carrying;
        if (fn_80251AEC(p, 0x17)) {
            if (U8(p, 0xd64) == 1 && S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4)
                carrying = true;
            else
                carrying = false;
        } else {
            carrying = false;
        }
        if (carrying) {
            u32 param = U32(p, 0x4) & 0xffff;
            s32 id = S32(p, 0xd70);
            void* pos = fn_8023E724(id);
            void* mgr = fn_801F856C();
            Actor_CreateByID(mgr, 0x5448434c, S32(p, 0x3b4), pos, id, -1, param);
        }
    }
    VEC(p, 0x2f4) = lbl_8046B400[U8(p, 0x3fd) + S32(p, 0x3dc) * 3];
    VEC(p, 0x2f4) += VEC(p, 0x8);
    fn_8025EB18(p);
    fn_80268B3C(p);
}

#endif
#undef S32
#undef U8
#undef U32
#undef F32
#undef VEC
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JMath/JMath.h"
