#include "types.h"
#include "JSystem/JGeometry/Vec.h"

#pragma auto_inline off

#define S32(p, off) (*(s32*)((p) + (off)))
#define U32(p, off) (*(u32*)((p) + (off)))
#define U8(p, off) (*(u8*)((p) + (off)))
#define F32(p, off) (*(f32*)((p) + (off)))
#define VEC(p, off) (*(JGeometry::TVec3<f32>*)((p) + (off)))

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
u16 fn_802265FC(JGeometry::TVec3<f32>*, s32);
s32 fn_8023DE58(s32);
char* fn_802D6A9C();
u16 fn_8022461C(JGeometry::TVec3<f32>*, s32);
u8 fn_802265DC(JGeometry::TVec3<f32>*, s32, s32);
u8 fn_802684A4(char*, JGeometry::TVec3<f32>*, s32);
u8 fn_802412A4(char*);
u8 fn_801F3744(char*, s32);
u8 fn_8022B1F8(char*);
u8 fn_8022AF10(char*);
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
extern f32 lbl_8054017C;
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
    bool held = (u8)(U8(p, 0xd64) == 1) == 1 && S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4;
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
        return false;
    }
    u16 t2 = fn_8022461C(&VEC(p, 0x2f4), S32(p, 0x3b4));
    bool held2 = (u8)(U8(p, 0xd64) == 1) == 1 && S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4;
    if (held2) {
        if ((fn_802265DC(&VEC(p, 0x2f4), S32(p, 0x3b4), 1) && t2 != 0xe && t2 != 0x39 && t2 != 0xd) ||
            fn_802684A4(p, &VEC(p, 0x2f4), S32(p, 0x3b4))) {
            F32(p, 0x2f4) = F32(p, 0x8);
            F32(p, 0x2f8) = F32(p, 0xc);
            return true;
        }
        return false;
    }
    char* actor = fn_801F666C(fn_801F856C(), S32(p, 0xd68));
    if (actor && ((u8(*)(char*, s32, JGeometry::TVec3<f32>*))(*(void***)actor)[19])(actor, S32(p, 0x3b4), &VEC(p, 0x2f4))) {
        F32(p, 0x2f4) = F32(p, 0x8);
        F32(p, 0x2f8) = F32(p, 0xc);
        return true;
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
    if ((u8)fn_80270A8C(p))
        return false;
    if ((u8)(U8(p, 0xd64) == 1) == 1)
        return false;
    if (((S32(p, 0xd70) < 0 || S32(p, 0xd70) >= 4) && S32(p, 0xd68) < 0) || U8(p, 0xd64) != 0)
        ok = true;
    else
        ok = false;
    if (!ok)
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

extern "C" bool fn_8025EFFC(char* p, s32 id, u8 flag, u8 force) {
    char* actor;
    bool held;
    bool good;
    if (force == 0) {
        goto zero;
    }
    held = U8(p, 0xd64) == 1;
    if (held) {
        goto main;
    }
    good = ((S32(p, 0xd70) < 0 || S32(p, 0xd70) >= 4) && S32(p, 0xd68) < 0) || U8(p, 0xd64) != 0;
    if (!good) {
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
        return false;
    }
    held = U8(p, 0xd64) == 1;
    if (held) {
        return false;
    }
    good = ((S32(p, 0xd70) < 0 || S32(p, 0xd70) >= 4) && S32(p, 0xd68) < 0) || U8(p, 0xd64) != 0;
    if (!good) {
        return false;
    }
    if ((u8)Player_GetField_0xce8(p)) {
        return false;
    }
    if ((u8)fn_80241230(p)) {
        return false;
    }
    if ((u8)fn_802412A4(p)) {
        return false;
    }
    if ((u8)Player_GetField_0x454(p)) {
        return false;
    }
    if (F32(p, 0x10) > lbl_80540150) {
        return false;
    }
    if (S32(p, 0xd88) < 0 && Player_IsLinked(p) && fn_802486A0(p) == 5) {
        return false;
    }
search:
    actor = fn_801F666C(fn_801F856C(), id);
    if (actor == 0) {
        return false;
    }
    if (!fn_80251AEC(p, flag != 0 ? 0x11 : 0x12)) {
        return false;
    }
    S32(p, 0xd88) = -1;
    U32(p, 0xd6c) = U32(actor, 0x1a0);
    VEC(p, 0x2f4) = VEC(actor, 0xc);
    U8(p, 0xd64) = 1;
    S32(p, 0xd68) = id;
    fn_801F3744(p, S32(p, 4));
    S32(p, 0xd74) = 3;
    U8(p, 0x1174) = 1;
    fn_8024F0E8(p, 0x20022);
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

extern "C" bool fn_8025F484(char* p) {
    if ((u8)(U8(p, 0xd64) == 1) == 1) {
        s32 id = S32(p, 0xd68);
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

extern JGeometry::TVec3<f32> lbl_8046B86C[];

extern "C" u8 fn_802604CC(char* p) {
    if (fn_8022B1F8(p))
        return 0;
    if (fn_8022AF10(p))
        return 0;
    if (fn_802486A0(p) != 4 && Player_IsLinked(p))
        return 0;
    if (U8(lbl_8053AAF8, 0x7e) == 0 && fn_802486A0(p) != 4)
        return 0;
    if (!fn_8022C0A0(S32(p, 4)))
        return 0;
    JGeometry::TVec3<f32> base = VEC(p, 8);
    base += lbl_8046B86C[S32(p, 0x3dc)];
    for (s32 i = 0; i < 4; i++) {
        if (i == S32(p, 4))
            continue;
        if (!fn_8023F264(i))
            continue;
        if (fn_8023EFEC(i))
            continue;
        if (fn_8023EA28(i))
            continue;
        if (fn_80233DA4(i))
            continue;
        if (fn_80230188(i))
            continue;
        if (fn_80236AB4(i))
            continue;
        if (fn_802354E4(i))
            continue;
        if (fn_8022D894(i))
            continue;
        if (S32(p, 0x3b4) == 8 && fn_8023DE58(i) < 8 && fn_8022CAF8(i) != 4 && fn_8022F514(i))
            continue;
        if (fn_802486A0(p) != 4 && fn_8022E438(S32(p, 4), i) && fn_80246F28(p) > 0)
            continue;
        s32 room = fn_8023DE58(i);
        char* a = fn_802D6A9C();
        if (room < 8)
            a += 0xcc;
        else
            a += 0xdc;
        s32 id = S32(p, 0x3b4);
        char* b = fn_802D6A9C();
        if (id < 8)
            b += 0xcc;
        else
            b += 0xdc;
        JGeometry::TVec3<f32> v;
        v.x = F32(p, 8) - F32(b, 0) + F32(a, 0);
        v.y = F32(p, 0xc) - F32(b, 4) + F32(a, 4);
        v.z = 0.0f;
        if (fn_802260DC(&v, fn_8023DE58(i), 1))
            continue;
        if (fn_802684A4(p, &v, fn_8023DE58(i)))
            continue;
        if (fn_802265FC(&v, fn_8023DE58(i)) != 0x20)
            continue;
        if (!fn_80239C9C(i, &v, S32(p, 0x3b4)))
            continue;
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
extern "C" u8 fn_80260C08(char* p) {
    s32 r30;
    u32 r29;
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
        s32 id = S32(p, 0x3b4);
        if (U8(fn_802D6A9C() + 0x10000 + id, 0x31df) != 0) {
            if (S32(p, 0x3dc) == 3 || S32(p, 0x3dc) == 1 || S32(p, 0x3dc) == 0) {
                if (fn_8029E888(lbl_8053AC98, &v, S32(p, 0x4), S32(p, 0x3b4)) == 1)
                    return 1;
            }
        } else if (S32(p, 0x3dc) == 3) {
            if (fn_80247330(p) < lbl_80540150) {
                JGeometry::TVec3<f32> t;
                t.x = v.x - lbl_80540154;
                t.y = v.y;
                t.z = v.z;
                if (fn_8029E888(lbl_8053AC98, &t, S32(p, 0x4), S32(p, 0x3b4)) == 1)
                    return 1;
            } else if (fn_80247330(p) > lbl_80540150) {
                JGeometry::TVec3<f32> t;
                t.x = lbl_80540154 + v.x;
                t.y = v.y;
                t.z = v.z;
                if (fn_8029E888(lbl_8053AC98, &t, S32(p, 0x4), S32(p, 0x3b4)) == 1)
                    return 1;
            }
            if (fn_8029E888(lbl_8053AC98, &v, S32(p, 0x4), S32(p, 0x3b4)) == 1)
                return 1;
        } else if (S32(p, 0x3dc) == 1 || S32(p, 0x3dc) == 0) {
            if (fn_8024712C(p) > lbl_80540150) {
                JGeometry::TVec3<f32> t;
                t.x = v.x;
                t.y = v.y - lbl_80540154;
                t.z = v.z;
                if (fn_8029E888(lbl_8053AC98, &t, S32(p, 0x4), S32(p, 0x3b4)) == 1)
                    return 1;
            }
        }
    }
    if (fn_8022C1D8(S32(p, 0x4)) && fn_802A01F0(lbl_8053AC98, &v, S32(p, 0x4), S32(p, 0x3b4)))
        return 1;
    if (!fn_8022C0A0(S32(p, 0x4)))
        return 0;
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
        char* q = fn_801F666C(fn_801F856C(), act);
        if (q && fn_80251AEC(p, 0x11)) {
            S32(p, 0xd6c) = 0x47524153;
            VEC(p, 0x2f4) = v;
            F32(p, 0x2fc) = v.z;
            U8(p, 0xd64) = 1;
            S32(p, 0xd68) = act;
            fn_801F3744(q, S32(p, 0x4));
            return 1;
        }
    }
    case 5: {
        s32 act = Actor_CreateByID(fn_801F856C(), 0x54534f4e, S32(p, 0x3b4), &v, 0, -1, S32(p, 0x4));
        char* q = fn_801F666C(fn_801F856C(), act);
        if (q && fn_80251AEC(p, 0x11)) {
            S32(p, 0xd6c) = 0x54534f4e;
            VEC(p, 0x2f4) = v;
            F32(p, 0x2fc) = v.z;
            U8(p, 0xd64) = 1;
            S32(p, 0xd68) = act;
            fn_801F3744(q, S32(p, 0x4));
            return 1;
        }
    }
    case 6: {
        s32 act = Actor_CreateByID(fn_801F856C(), 0x5353544e, S32(p, 0x3b4), &v, S32(p, 0x4) << 4, -1, S32(p, 0x4));
        char* q = fn_801F666C(fn_801F856C(), act);
        if (q && fn_80251AEC(p, 0x11)) {
            S32(p, 0xd6c) = 0x5353544e;
            VEC(p, 0x2f4) = v;
            F32(p, 0x2fc) = v.z;
            U8(p, 0xd64) = 1;
            S32(p, 0xd68) = act;
            fn_801F3744(q, S32(p, 0x4));
            return 1;
        }
    }
    case 7: {
        s32 act = Actor_CreateByID(fn_801F856C(), 0x424f5244, S32(p, 0x3b4), &v, 0, -1, S32(p, 0x4));
        char* q = fn_801F666C(fn_801F856C(), act);
        if (q && fn_80251AEC(p, 0x11)) {
            S32(p, 0xd6c) = 0x424f5244;
            VEC(p, 0x2f4) = v;
            F32(p, 0x2fc) = v.z;
            U8(p, 0xd64) = 1;
            S32(p, 0xd68) = act;
            fn_801F3744(q, S32(p, 0x4));
            return 1;
        }
    }
    case 8: {
        s32 act = Actor_CreateByID(fn_801F856C(), 0x524f434b, S32(p, 0x3b4), &v, 0, -1, S32(p, 0x4));
        char* q = fn_801F666C(fn_801F856C(), act);
        if (q && fn_80251AEC(p, 0x11)) {
            S32(p, 0xd6c) = 0x524f434b;
            VEC(p, 0x2f4) = v;
            F32(p, 0x2fc) = v.z;
            U8(p, 0xd64) = 1;
            S32(p, 0xd68) = act;
            fn_801F3744(q, S32(p, 0x4));
            U8(q, 0x11d) = 0;
            return 1;
        }
    }
    case 12: {
        s32 act = Actor_CreateByID(fn_801F856C(), 0x5353544e, S32(p, 0x3b4), &v, (S32(p, 0x4) << 4) + 1, -1, S32(p, 0x4));
        char* q = fn_801F666C(fn_801F856C(), act);
        if (q && fn_80251AEC(p, 0x11)) {
            S32(p, 0xd6c) = 0x524f434b;
            VEC(p, 0x2f4) = v;
            F32(p, 0x2fc) = v.z;
            U8(p, 0xd64) = 1;
            S32(p, 0xd68) = act;
            fn_801F3744(q, S32(p, 0x4));
            U8(q, 0x11d) = 0;
            return 1;
        }
    }
    {
        s32 act = Actor_CreateByID(fn_801F856C(), 0x59415349, S32(p, 0x3b4), &v, 0, -1, S32(p, 0x4));
        char* q = fn_801F666C(fn_801F856C(), act);
        if (q && fn_80251AEC(p, 0x11)) {
            S32(p, 0xd6c) = 0x59415349;
            VEC(p, 0x2f4) = v;
            F32(p, 0x2fc) = v.z;
            U8(p, 0xd64) = 1;
            S32(p, 0xd68) = act;
            fn_801F3744(q, S32(p, 0x4));
            return 1;
        }
    }
    {
        u32 k28 = 0;
        s32 k29 = r30 - 0x18;
        if (r30 == 0x22)
            k28 = 1;
        else if (r30 == 0x23)
            k28 = 2;
        if (r30 >= 0x1d)
            k29 = r30 - 0x1d;
        s32 act = Actor_CreateByID(fn_801F856C(), 0x5455424f, S32(p, 0x3b4), &v, (k28 << 7) | k29, -1, S32(p, 0x4));
        char* q = fn_801F666C(fn_801F856C(), act);
        if (q && fn_80251AEC(p, 0x11)) {
            S32(p, 0xd6c) = 0x5455424f;
            VEC(p, 0x2f4) = v;
            F32(p, 0x2fc) = v.z;
            U8(p, 0xd64) = 1;
            S32(p, 0xd68) = act;
            fn_801F3744(q, S32(p, 0x4));
            return 1;
        }
    }
    default:
        break;
    }
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

extern "C" f32 lbl_8054017C;
extern "C" u8 lbl_8046B790[];
extern "C" f32 lbl_8046B7B0[];
extern "C" void fn_8026152C(char* p, u8 flag) {
    u8 inX = 0;
    u8 inY = 0;
    u8 inZ = 0;
    f32 eps = *(f32*)__float_epsilon * lbl_8054017C;
    f32 d = F32(p, 0x8) - F32(p, 0x14);
    if (-eps <= d && d <= eps) {
        inX = 1;
    }
    if (inX) {
        inX = 0;
        d = F32(p, 0xc) - F32(p, 0x18);
        if (-eps <= d && d <= eps) {
            inX = 1;
        }
        if (inX) {
            inY = 1;
        }
    }
    if (inY) {
        inY = 0;
        d = F32(p, 0x10) - F32(p, 0x1c);
        if (-eps <= d && d <= eps) {
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
    if (flag == 0) {
        if (U8(p, 0x3f8) >= 0x18) {
            U8(p, 0x3f8) = 0;
        }
    } else if (U8(p, 0x3f8) >= 0x30) {
        U8(p, 0x3f8) = 0;
    }
done:
    if (flag == 0) {
        U8(p, 0x3f9) = ((u8*)lbl_8046B790)[U8(p, 0x3f8) / 3 + S32(p, 0x3dc) * 8];
    } else {
        U8(p, 0x3f9) = ((u8*)lbl_8046B790)[U8(p, 0x3f8) / 6 + S32(p, 0x3dc) * 8];
    }
    s32 idx = U8(p, 0x3f9) * 5;
    F32(p, 0x2f4) = ((f32*)lbl_8046B7B0)[idx] + F32(p, 0x8);
    F32(p, 0x2f8) = ((f32*)lbl_8046B7B0)[idx + 1] + F32(p, 0xc);
    F32(p, 0x2fc) = ((f32*)lbl_8046B7B0)[idx + 2] + F32(p, 0x10);
}

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

static inline bool isAttached(char* p) {
    if (((S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4) || S32(p, 0xd68) >= 0) && U8(p, 0xd64) == 0)
        return true;
    return false;
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
extern "C" void fn_80261750(void* this_) {
    u8 flag31;
    char* p = (char*)this_;
    s32 area;
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
                    f32 y = v.y;
                    f32 x = v.x;
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
                f32 d = lbl_80540180;
                F32(p, 0xc) += d;
                F32(p, 0x10) += d;
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
                    void* a = fn_8023E2A0(S32(p, 0xd70));
                    s32 b = fn_8023E190(S32(p, 0xd70));
                    if (!fn_8022BC38(S32(p, 0xd70), b, a)) {
                        f32 zero = lbl_80540150;
                        VEC(p, 0xcd4) = VEC(p, 0x8);
                        VEC(p, 0xcbc) = VEC(p, 0xcd4);
                        VEC(p, 0xd1c) = VEC(p, 0xcbc);
                        F32(p, 0xcdc) = zero;
                        F32(p, 0xcc4) = zero;
                        F32(p, 0xd24) = zero;
                    }
                }
            }
            for (s32 i = 0; i < 4; i++) {
                if (fn_80243194(p, i) && i != S32(p, 4)) {
                    fn_80230C6C(i);
                }
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
        flag31 = 0;
        VEC(p, 0x8) += VEC(p, 0xd78);
        F32(p, 0xd80) -= lbl_80540190;
        area = S32(p, 0x3b4);
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
        area = S32(p, 0x3b4);
        if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + area + 0x31df)) {
            if (!playerBoxContains(box, VEC(p, 0x8))) {
                F32(p, 0x10) = lbl_80540150;
                flag31 = 1;
            }
        }
        if (F32(p, 0x10) <= lbl_80540150) {
            area = S32(p, 0x3b4);
            if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + area + 0x31df)) {
                if (flag31 || fn_802518AC(p, 1)) {
                    F32(p, 0x10) = lbl_80540150;
                } else {
                    f32 c = lbl_80540188;
                    F32(p, 0xc) += c - F32(p, 0x10);
                    F32(p, 0x10) = c;
                }
            }
            if (F32(p, 0x10) <= lbl_80540150) {
                f32 zero = lbl_80540150;
                VEC(p, 0x368).set(F32(p, 0xd78), F32(p, 0xd7c), zero);
                F32(p, 0xd78) = zero;
                F32(p, 0xd7c) = zero;
                F32(p, 0xd80) = zero;
                F32(p, 0x10) = zero;
                if (U8(lbl_8053AAF8, 0x7e) != 0 && !(U8(lbl_8053AAF8, 0x82) & (u8)(1 << S32(p, 4))) && S32(p, 0xd60) < 0) {
                    fn_80251AEC(p, 1);
                } else {
                    fn_80251AEC(p, 0);
                }
            }
        } else if (fn_802466B4(p) && fn_80251AEC(p, 7)) {
            f32 zero = lbl_80540150;
            VEC(p, 0x344).set(VEC(p, 0xd78));
            VEC(p, 0x368).set(F32(p, 0xd78), F32(p, 0xd7c), zero);
            F32(p, 0xd78) = zero;
            F32(p, 0xd7c) = zero;
            F32(p, 0xd80) = zero;
            fn_802685D4(p);
        }
        area = S32(p, 0x3b4);
        if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + area + 0x31df)) {
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
extern "C" void fn_80262254(char* p) {
    if (fn_8022C6AC(S32(p, 0x4)) > lbl_80540150) {
        if (F32(p, 0x344) == lbl_80540150) {
            F32(p, 0x344) = lbl_8054019C * fn_8022C82C(S32(p, 0x4));
        } else {
            bool skip = false;
            if (F32(p, 0x344) > lbl_80540150) {
                if (F32(p, 0x34c) >= lbl_80540150) {
                    F32(p, 0x344) = lbl_805401A0 * fn_8022C82C(S32(p, 0x4)) + F32(p, 0x344);
                } else {
                    F32(p, 0x344) = lbl_805401A4 * fn_8022C82C(S32(p, 0x4)) + F32(p, 0x344);
                }
                if (F32(p, 0x344) > lbl_805401A8) {
                    if (U8((char*)S32(p, 0xbf0), 0x48)) {
                        F32(p, 0x344) = lbl_805401A8;
                    }
                    skip = true;
                } else if (F32(p, 0x344) == lbl_805401A8) {
                    skip = true;
                }
            }
            if (!skip) {
                if (F32(p, 0x34c) >= lbl_80540150) {
                    F32(p, 0x344) = lbl_805401A0 * fn_8022C82C(S32(p, 0x4)) + F32(p, 0x344);
                } else {
                    F32(p, 0x344) = lbl_805401A4 * fn_8022C82C(S32(p, 0x4)) + F32(p, 0x344);
                }
                if (F32(p, 0x344) < lbl_805401AC) {
                    if (U8((char*)S32(p, 0xbf0), 0x49)) {
                        F32(p, 0x344) = lbl_805401AC;
                    }
                }
            }
        }

        if (F32(p, 0x348) == lbl_80540150) {
            F32(p, 0x348) = lbl_8054019C * -fn_8022C76C(S32(p, 0x4));
        } else {
            bool skip = false;
            if (F32(p, 0x348) > lbl_80540150) {
                if (F32(p, 0x34c) >= lbl_80540150) {
                    F32(p, 0x348) = F32(p, 0x348) - lbl_805401A0 * fn_8022C76C(S32(p, 0x4));
                } else {
                    F32(p, 0x348) = F32(p, 0x348) - lbl_805401A4 * fn_8022C76C(S32(p, 0x4));
                }
                if (F32(p, 0x348) < lbl_805401A8) {
                    if (U8((char*)S32(p, 0xbf0), 0x4a)) {
                        F32(p, 0x348) = lbl_805401A8;
                    }
                    skip = true;
                } else if (F32(p, 0x348) == lbl_805401A8) {
                    skip = true;
                }
            }
            if (!skip) {
                if (F32(p, 0x34c) >= lbl_80540150) {
                    F32(p, 0x348) = F32(p, 0x348) - lbl_805401A0 * fn_8022C76C(S32(p, 0x4));
                } else {
                    F32(p, 0x348) = F32(p, 0x348) - lbl_805401A4 * fn_8022C76C(S32(p, 0x4));
                }
                if (F32(p, 0x348) > lbl_805401AC) {
                    if (U8((char*)S32(p, 0xbf0), 0x4b)) {
                        F32(p, 0x348) = lbl_805401AC;
                    }
                }
            }
        }
    }
}

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
extern "C" void fn_80262BAC(char* p) {
    f32 z = F32(p, 0x370);
    if (U32(p, 0xd6c) == 0x4e495741 && U8(p, 0x441) == 0) {
        f32 d = F32(p, 0x324) - F32(p, 0x8);
        if (d >= lbl_80540178) {
            F32(p, 0x8) += lbl_80540178;
        } else if (d <= lbl_805401CC) {
            F32(p, 0x8) -= lbl_80540178;
        } else if (d != lbl_80540150) {
            F32(p, 0x8) = F32(p, 0x324);
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
            if (F32(p, 0x10) <= lbl_80540150)
                F32(p, 0x10) = lbl_80540150;
        }
        if (fn_80251AEC(p, 0x12)) {
            U8(p, 0xce8) = 0;
            F32(p, 0x2f4) = lbl_80540150;
            F32(p, 0x2f8) = lbl_80540150;
            F32(p, 0x2fc) = lbl_805401C4;
            VEC(p, 0x2f4) += VEC(p, 0x8);
            return;
        }
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
        if (U8(p, 0x43f) == 0 && U8(p, 0x441) != 0 && F32(p, 0xc) < F32(p, 0x328)) {
            F32(p, 0x10) = lbl_805401DC;
        } else {
            F32(p, 0x10) = lbl_80540150;
            U8(p, 0x124d) = 0;
            fn_80251AEC(p, 0x12);
        }
    }
    f32 eps = lbl_8054017C * *(f32*)__float_epsilon;
    f32 dx = F32(p, 0x8) - F32(p, 0x14);
    f32 dy = F32(p, 0xc) - F32(p, 0x18);
    f32 dz = F32(p, 0x10) - F32(p, 0x1c);
    bool near = -eps <= dx && dx <= eps && -eps <= dy && dy <= eps && -eps <= dz && dz <= eps;
    if (near && VEC(p, 0x368).squared() <= lbl_8054017C * *(f32*)__float_epsilon) {
        U8(p, 0x3f8) = 0;
    } else {
        U8(p, 0x3f8)++;
        if (U8(p, 0x3f8) >= 0x18)
            U8(p, 0x3f8) = 0;
    }
    U8(p, 0x3f9) = ((u8*)lbl_8046B790)[U8(p, 0x3f8) / 3 + S32(p, 0x3dc) * 8];
    s32 idx = U8(p, 0x3f9) * 5;
    F32(p, 0x2f4) = ((f32*)lbl_8046B7B0)[idx] + F32(p, 0x8);
    F32(p, 0x2f8) = ((f32*)lbl_8046B7B0)[idx + 1] + F32(p, 0xc);
    F32(p, 0x2fc) = ((f32*)lbl_8046B7B0)[idx + 2] + F32(p, 0x10);
    if (U8(p, 0x440) != 0 && F32(p, 0x34c) < lbl_80540150) {
        fn_8024F0E8(p, 0x1000d);
        fn_8024F0E8(p, 0x2003e);
        U8(p, 0x3f9) = F32(p, 0x34c) < lbl_805401E0 ? 1 : 0;
    }
}

extern "C" void fn_80263078(char* p) {
    JGeometry::TVec3<f32> pos;
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
                u8 inside = 0;
                if (pos.x > F32(base, 0) && pos.y > F32(base, 4) && pos.x < F32(base, 8) && pos.y < F32(base, 0xc)) {
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
            if (F32(p, 0x344) > lbl_80540150) {
                S32(p, 0x3dc) = 0;
                S32(p, 0x3e8) = 0;
            } else if (F32(p, 0x344) < lbl_80540150) {
                S32(p, 0x3dc) = 1;
                S32(p, 0x3e8) = 1;
            }
        }
    }
}

extern "C" void fn_802632A4(void) {}

extern "C" void fn_802632A8(char* p) {
    U8(p, 0x3fc) = U8(p, 0x3fc) + 1;
    if (U8(p, 0x3fc) < 8) {
        U8(p, 0x3fd) = 0;
        return;
    }
    if (U8(p, 0x3fc) < 10) {
        U8(p, 0x3fd) = 1;
        return;
    }
    if (U8(p, 0x3fc) < 11) {
        U8(p, 0x3fd) = 2;
        return;
    }
    if (U8(p, 0x3fc) < 12) {
        bool held = (u8)(U8(p, 0xd64) == 1) == 1 && S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4;
        U8(p, 0x3fd) = held ? 4 : 3;
        return;
    }
    U8(p, 0x3fc) = 12;
    if (!fn_80251AEC(p, 0)) {
        return;
    }
    bool held = (u8)(U8(p, 0xd64) == 1) == 1 && S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4;
    if (held) {
        U8(p, 0x3fd) = 4;
        return;
    }
    U8(p, 0x3fd) = 3;
    char* actor = fn_801F666C(fn_801F856C(), S32(p, 0xd68));
    if (actor == 0) {
        return;
    }
    JGeometry::TVec3<f32> zero(0.0f, 0.0f, 0.0f);
    fn_801F3708(actor, &zero);
    S32(p, 0xd70) = -1;
    S32(p, 0xd68) = -1;
    U8(p, 0xd64) = 0;
    S32(p, 0xd6c) = 0x4e554c4c;
    S32(p, 0xd74) = 3;
    VEC(p, 0x2f4) = lbl_8046B580[S32(p, 0x3dc) * 5 + U8(p, 0x3fd)];
    F32(p, 0x2f4) += F32(p, 0x8);
    F32(p, 0x2f8) += F32(p, 0xc);
    F32(p, 0x2fc) += F32(p, 0x10);
    if (fn_8025EB18(p)) {
        if (VEC(p, 0x35c).length() < lbl_80540188) {
            VEC(p, 0x35c) = lbl_8046B580[S32(p, 0x3dc) * 5 + 3];
            F32(p, 0x364) = lbl_80540150;
            PSVECNormalize(&VEC(p, 0x35c), &VEC(p, 0x35c));
        }
    }
    fn_80268B3C(p);
}

extern "C" void fn_802635C8(char* p) {
    p[0x458] = 0;
}

extern "C" void fn_802635D4(void) {
}

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
    f32 x = pos.x;
    f32 y = pos.y;
    F32(p, 0x2f4) = x;
    f32 z = pos.z;
    F32(p, 0x2f8) = y;
    F32(p, 0x2fc) = z;
    VEC(p, 0x2f4).add(VEC(p, 8));
    fn_8025EB18(p);
    fn_80268B3C(p);
}

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
    const JGeometry::TVec3<f32>& pos = lbl_8046B310[S32(p, 0x3dc) * 5 + U8(p, 0x3fd)];
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
                ((void (*)(void*))(*(void***)actor)[18])(actor);
        }
    }
    if (fn_8025EB18(p)) {
        p[0x3fd] = 1;
        p[0x459] = 0;
        const JGeometry::TVec3<f32>& pos2 = lbl_8046B310[S32(p, 0x3dc) * 5 + U8(p, 0x3fd)];
        f32 x2 = pos2.x;
        f32 y2 = pos2.y;
        F32(p, 0x2f4) = x2;
        f32 z2 = pos2.z;
        F32(p, 0x2f8) = y2;
        F32(p, 0x2fc) = z2;
        VEC(p, 0x2f4).add(VEC(p, 8));
        if (VEC(p, 0x35c).length() < lbl_80540188) {
            const JGeometry::TVec3<f32>& pos3 = lbl_8046B310[S32(p, 0x3dc) * 5 + 2];
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

extern "C" void fn_80263C64(char* p) {
    JGeometry::TVec3<f32> v;
    char* actor;
    fn_8027FA08(p, &v);
    if (lbl_80540150 == v.z && lbl_80540150 != F32(p, 0x10) && U8(p, 0x434) == 0) {
        F32(p, 0x10) = lbl_80540150;
        actor = fn_801F666C(fn_801F856C(), S32(p, 0xd68));
        if (fn_8022C13C(S32(p, 0x4))) {
            if (fn_802416C4(p) == 7) {
                goto end;
            }
            if (fn_8024B24C(p) == 0) {
                if (isCarriedByPlayer(p)) {
                    if (fn_80236B50(S32(p, 0xd70))) {
                        fn_80251AEC(p, 0x16);
                        goto end;
                    }
                }
            } else if (fn_8022C0A0(S32(p, 0x4))) {
                fn_80251AEC(p, 0x16);
                goto end;
            }
        }
        if (isCarriedByPlayer(p)) {
            if (fn_8023EA28(S32(p, 0xd70))) {
                fn_802808E8(p, lbl_805401E4);
                fn_8027EB04(p);
                fn_80263C64_snap(p);
            }
        }
    }
end:
    fn_80268B3C(p);
}

extern "C" void fn_80264410(char* p) {
    p[0x458] = 0;
}

extern JGeometry::TVec3<f32> lbl_8046B250[];
extern "C" void fn_8026441C(char* p) {
    s32 iVar6 = 0;
    U8(p, 0x3fc)++;
    char* actor = fn_801F666C(fn_801F856C(), S32(p, 0xd68));
    bool held = (u8)(U8(p, 0xd64) == 1) == 1 && S32(p, 0xd70) >= 0 && S32(p, 0xd70) < 4;
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
        VEC(p, 0x2f4) = lbl_8046B250[iVar6 + S32(p, 0x3dc) * 4];
        VEC(p, 0x2f4) += VEC(p, 0x8);
    }
    fn_8025EB18(p);
    fn_80268B3C(p);
}

extern "C" void fn_80264768(char* p) {
    p[0x458] = 0;
}

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

#undef S32
#undef U8
#undef U32
#undef F32
#undef VEC

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
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JMath/JMath.h"
