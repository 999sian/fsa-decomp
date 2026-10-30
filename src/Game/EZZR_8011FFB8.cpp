#include "types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

class GateRegistry;
extern "C" GateRegistry* fn_80131F0C(void);
extern "C" u8* fn_80131E30(GateRegistry*, s32);

struct EzzrMgr {
    u8 flag(u32 i) { return mFlags[i]; }
    u8 pad[0x131df];
    u8 mFlags[1];
};

static inline f32 EZZR_Sqr(f32 x) {
    return x * x;
}

static inline f32 EZZR_Sqrt(f32 x) {
    if (x <= 0.0f) {
        return x;
    }
    f32 y = __frsqrte(x);
    y = 0.5f * y * __fnmsubs(x, y * y, 3.0f);
    return x * y;
}

class EZZR : public Actor {
public:
    virtual void v19();
    virtual u8 v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25(s32);
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36(s32, f32, s32);
    virtual void v37(s32, f32, f32, f32, f32, f32);
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual u8 v48(Vec*, f32);
    u8 field_230[0x38];
};

extern "C" void fn_80123394(void*);
extern "C" void fn_80124278(void*);
extern "C" void fn_80124448(void*);
extern "C" void fn_80131EC0(GateRegistry*, void*);
extern "C" void fn_8011FFCC(void* p) {
}

extern "C" bool fn_8011FFD0(Actor* p) {
    if (*(s32*)fn_80131F0C() < 2) {
        return false;
    }
    Actor* other = (Actor*)fn_80131E30(fn_80131F0C(), 1);
    if (other == 0) {
        return false;
    }
    return p->field_198 == other->field_198;
}

extern "C" s32 fn_80120040(void* p) {
    return 1;
}

extern "C" void fn_80120048(void* p) {
    fn_80123394(p);
}

extern "C" void fn_80120068(void* p) {
    ((EZZR*)p)->v25(12);
}

extern "C" void fn_80120098(void* p) {
    ((EZZR*)p)->v25(9);
}

extern "C" void fn_801200C8(void* p) {
    ((EZZR*)p)->v25(11);
}

extern "C" void fn_80121DB0(void);
extern "C" void fn_801200F8(void)
{
	fn_80121DB0();
}

class GateRegistry;
extern "C" GateRegistry* fn_80131F0C(void);
extern "C" u8* fn_80131E30(GateRegistry*, s32);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern u8 lbl_8049DF40[];
extern f32 lbl_8053C964;
extern "C" void fn_80120118(EZZR* p) {
    fn_801D2608(p->field_230, lbl_8049DF40, 14);
    fn_801D22DC(p->field_230, 7, 2, 0);
    fn_801D1F14(p->field_230, lbl_8053C964);
}

extern "C" void fn_801220C4(void*);
extern "C" void fn_8012202C(void*);
extern "C" void fn_80121FA8(void*);
extern "C" void fn_80121D68(void*);
extern "C" s32 fn_8012285C(void*);
extern "C" s32 fn_80230CFC(s32);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7A08(void*, u32);
extern "C" void* fn_801F666C(void*, s32);
extern "C" s32 fn_801F78F4(void*, u32, s32);
extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_802D8050(void*, s32, s32, s32);
extern "C" void fn_80131EE4(void);
extern "C" void* fn_801283E8(void);
extern "C" void fn_80127ED8(void*, void*);
extern "C" void fn_80127E20(void*, void*);
extern "C" s32 fn_80123E80(u8*, s32);
extern "C" s32 Actor_CreateByID(void*, u32, u32, f32*, u32, s32, s32);
extern s32 lbl_80539F30;
#pragma fp_contract off
extern "C" void fn_80120174(EZZR* p, s32 param) {
    *((u8*)p + 0x330) = 0;
    switch (param) {
    case 0:
        *((u8*)p + 0x330) = 1;
        fn_801D22DC((u8*)p + 0x230, 7, 2, 0);
        break;
    case 2:
        *(s32*)((u8*)p + 0x3c8) = 0;
        *((u8*)p + 0x330) = 1;
        fn_801220C4(p);
        break;
    case 3:
        *((u8*)p + 0x330) = 1;
        break;
    case 4:
        *((u8*)p + 0x331) = 0;
        break;
    case 5:
        *((u8*)p + 0x330) = 1;
        if (((EzzrMgr*)fn_802D6A9C())->flag(p->field_04) != 0) {
            fn_801D22DC((u8*)p + 0x230, 6, 2, 0);
        } else {
            fn_801D22DC((u8*)p + 0x230, 7, 2, 0);
        }
        break;
    case 7:
        *((u8*)p + 0x11e) = 1;
        break;
    case 8: {
        p->detach();
        u32 flags = *(u32*)((u8*)p + 0x90);
        flags |= 4;
        flags |= fn_8012285C(p) << 3;
        Actor_CreateByID(fn_801F856C(), 0x46415A52, *(u32*)((u8*)p + 0x4), (f32*)((u8*)p + 0xc), flags, -1, -1);
        break;
    }
    case 9:
        fn_8012202C(p);
        break;
    case 10:
        fn_80121FA8(p);
        fn_801D22DC((u8*)p + 0x230, 2, 2, 0);
        break;
    case 11:
        fn_801D22DC((u8*)p + 0x230, fn_80230CFC(fn_8012285C(p)), 2, 0);
        break;
    case 12:
        fn_801D22DC((u8*)p + 0x230, fn_80230CFC(fn_8012285C(p)), 2, 0);
        break;
    case 13: {
        JGeometry::TVec3f b, a;
        a = *(JGeometry::TVec3f*)&p->field_0C;
        b = *(JGeometry::TVec3f*)&p->field_0C;
        s32 id = fn_801F7A08(fn_801F856C(), 0x5241494c);
        while (id != -1) {
            void* other = fn_801F666C(fn_801F856C(), id);
            if (other == 0) {
                break;
            }
            s32 kind = (*(u32*)((u8*)other + 0x90) >> 8) & 0xff;
            if (kind == *(s32*)((u8*)p + 0x35c)) {
                a = *(JGeometry::TVec3f*)((u8*)other + 0xc);
            } else if (kind == *(s32*)((u8*)p + 0x3d0)) {
                b = *(JGeometry::TVec3f*)((u8*)other + 0xc);
            }
            id = fn_801F78F4(fn_801F856C(), 0x5241494c, id);
        }
        f32 dx = p->field_0C.x - a.x;
        f32 dy = p->field_0C.y - a.y;
        f32 distA = EZZR_Sqrt(dx * dx + dy * dy);
        dx = p->field_0C.x - b.x;
        dy = p->field_0C.y - b.y;
        if (distA > EZZR_Sqrt(dx * dx + dy * dy)) {
            if (*((u8*)p + 0x3c4) != 0) {
                fn_80127ED8(fn_801283E8(), &b);
            } else {
                fn_80127E20(fn_801283E8(), &b);
            }
            *(s32*)((u8*)p + 0x35c) = *(s32*)((u8*)p + 0x3d0);
        } else {
            if (*((u8*)p + 0x3c4) != 0) {
                fn_80127ED8(fn_801283E8(), &a);
            } else {
                fn_80127E20(fn_801283E8(), &a);
            }
        }
        fn_80121D68(p);
        fn_801220C4(p);
        break;
    }
    case 14:
        *(s32*)((u8*)p + 0x3c8) = 0;
        break;
    case 15:
        fn_802D8050(fn_802D6A9C(), p->v13(), 1, 0xff);
        *((u8*)p + 0x11e) = 0;
        *((u8*)p + 0x11d) = 0;
        *((u8*)p + 0x11c) = 0;
        lbl_80539F30 = -1;
        fn_80131F0C();
        fn_80131EE4();
        break;
    }
    fn_801D1F14((u8*)p + 0x230, lbl_8053C964);
    fn_80123E80((u8*)p, param);
}
#pragma fp_contract reset
extern "C" void fn_801EEC98(void* unused, s32 idx, u16* angOut, s32* quadOut, f32* distOut, s32* idxOut, s32 sel, s32 mode);
extern "C" u8 fn_8023F264(s32);
extern "C" u8 fn_802300EC(s32);
extern "C" u8 fn_802308E0(s32);
extern "C" u8 fn_8022F514(s32);
extern "C" s32 fn_8022F3DC(s32);
extern "C" s32 fn_80122898(void*, s32);
extern "C" void fn_8022FF8C(s32, void*, s32, s32, s32, s32);
extern "C" u8 fn_80388CAC(s32, s32);
extern "C" void fn_8022FE80(s32, s32, s32, s32, s32);
extern "C" s32 fn_8022FD8C(s32);
extern "C" u8 fn_8038AD24(s32, u16, s32, s32, JGeometry::TVec3f*, s32);
extern "C" JGeometry::TVec3f* fn_8023E724(s32);
extern "C" s32 ClassifyBamAngleToQuadrant(u32 ang);
extern "C" s32 fn_801CD950(f32*, f32, f32);
extern "C" void fn_80122730(void*, s32, s32, s32);
extern "C" void fn_8023061C(s32, s32);
extern "C" s32 fn_801F778C(void*, u32, Vec*, f32*);
extern "C" u8 fn_802DCD0C(u8*);
extern "C" u8* fn_8011921C(void);
extern "C" u8 fn_801186B0(u8*, s32);
extern "C" void fn_80118454(u8*);
extern "C" void fn_8037AE00(void*);
extern "C" s32 fn_80138A30(void*);
extern "C" u8 fn_8022D75C(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u8 fn_80122804(void*);
extern "C" void fn_80122548(void*);
extern "C" s32 fn_801216D0(void*, s32);
extern "C" void fn_80122148(void*);
extern void* lbl_8053AD70;
extern void* lbl_8053AAF8;
extern f32 lbl_8053C968;
extern f32 lbl_8053C96C;
extern f32 lbl_8053C970;
extern f32 lbl_8053C97C;
extern f32 lbl_8053C980;
extern f32 lbl_8053C984;
extern f32 lbl_8053C988;
extern f32 lbl_8053C98C;
extern f32 lbl_8053C990;
extern f32 lbl_8053C994;
extern f32 lbl_8053C998;
extern f32 lbl_8053C99C;
extern f32 lbl_8053C9A0;
extern f32 lbl_8053C9A4;

static inline bool EZZR_MoveToGate(EZZR* p) {
    JGeometry::TVec3f t = *fn_8023E724(*(s32*)((u8*)p + 0x3cc));
    t.z = lbl_8053C964;
    if (((EzzrMgr*)fn_802D6A9C())->flag(p->field_04) != 0) {
        t.x += lbl_8053C968;
    } else {
        t.y -= lbl_8053C968;
    }
    f32 rad = JMath::atanTable_.atan2_(t.x - p->field_0C.x, t.y - p->field_0C.y);
    u16 ang = (s32)(rad * lbl_8053C96C);
    p->field_98 = ClassifyBamAngleToQuadrant(ang);
    f32 sy;
    f32 sx;
    sx = lbl_8053C970 * JMath::sincosTable_.mTable[ang >> 5].first;
    sy = lbl_8053C970 * JMath::sincosTable_.mTable[ang >> 5].second;
    bool done = true;
    if (fn_801CD950(&p->field_0C.x, t.x, sx) != 0 && lbl_8053C964 != sx) {
        done = false;
    }
    if (((EzzrMgr*)fn_802D6A9C())->flag(p->field_04) == 0) {
        if (fn_801CD950(&p->field_0C.y, t.y, sy) != 0 && lbl_8053C964 != sy) {
            done = false;
        }
    }
    return done;
}
extern "C" void fn_80120570(EZZR* p) {
    f32 box[4];
    box[0] = p->field_60;
    box[1] = p->field_64;
    box[2] = p->field_68;
    box[3] = p->field_6C;
    box[0] += p->field_0C.x;
    box[1] += p->field_0C.y;
    box[2] += p->field_0C.x;
    box[3] += p->field_0C.y;

    switch (*(u32*)((u8*)p + 0x33c)) {
    case 0: {
        p->v36(0, lbl_8053C988, 1);
        s32 idx;
        if (*(s32*)((u8*)p + 0x33c) != 0) {
            idx = -1;
        } else {
            u16 ang;
            f32 dist;
            s32 out;
            s32 quad;
            ang = 0;
            quad = 0;
            out = 0;
            dist = lbl_8053C964;
            fn_801EEC98(p, p->field_198, &ang, &quad, &dist, &out, 0, 0);
            idx = out;
            if (idx < 0 || idx >= 4) {
                idx = -1;
            } else if (dist >= lbl_8053C97C) {
                idx = -1;
            }
        }
        if (idx >= 0 && idx != *(s32*)((u8*)p + 0x3cc)) {
            if (!fn_8023F264(idx)) {
                return;
            }
            if (!fn_802300EC(idx)) {
                return;
            }
            if (fn_802308E0(idx)) {
                *(s32*)((u8*)p + 0x3cc) = idx;
                if (fn_8022F514(idx)) {
                    fn_8022F3DC(idx);
                }
                *(s32*)((u8*)p + 0x344) = idx;
                p->v25(2);
                return;
            }
        }
        s32 msg = 0x2b7;
        if (*(s32*)fn_80131F0C() == 1) {
            msg = 0x2b4;
        }
        idx = fn_80122898(p, msg);
        if (idx < 0) {
            return;
        }
        if (fn_8022F514(idx)) {
            idx = fn_8022F3DC(idx);
        }
        *(s32*)((u8*)p + 0x344) = idx;
        p->v25(1);
        break;
    }
    case 1:
        fn_8022FF8C(*(s32*)((u8*)p + 0x34c), box, p->field_04, p->field_198, 1, 0);
        if (fn_80388CAC(*(s32*)((u8*)p + 0x34c), p->field_198)) {
            p->v25(8);
        }
        break;
    case 2:
        (*(s32*)((u8*)p + 0x3c8))++;
        if (*(s32*)((u8*)p + 0x3c8) < 60) {
            break;
        }
        if (*(s32*)fn_80131F0C() == 1) {
            p->v25(4);
            break;
        }
        fn_8022FE80(*(s32*)((u8*)p + 0x3cc), p->field_04, p->field_198, 0, 0);
        if (*(s32*)((u8*)p + 0x3cc) == fn_8022FD8C(p->field_198)) {
            if (fn_8038AD24(*(s32*)((u8*)p + 0x3cc), 0x2b3, p->field_198, p->field_04, (JGeometry::TVec3f*)&(const JGeometry::TVec3f&)JGeometry::TVec3f(lbl_8053C964, lbl_8053C964, lbl_8053C964), 2)) {
                p->v25(3);
                *(s32*)((u8*)p + 0x3c8) = 0;
            }
        }
        break;
    case 3:
        fn_8022FE80(*(s32*)((u8*)p + 0x3cc), p->field_04, p->field_198, 0, 0);
        if (fn_80388CAC(*(s32*)((u8*)p + 0x3cc), p->field_198)) {
            p->v25(4);
        }
        break;
    case 4: {
        JGeometry::TVec3f t = *fn_8023E724(*(s32*)((u8*)p + 0x3cc));
        t.z = lbl_8053C964;
        if (((EzzrMgr*)fn_802D6A9C())->flag(p->field_04) != 0) {
            t.x += lbl_8053C968;
        } else {
            t.y -= lbl_8053C968;
        }
        f32 rad = JMath::atanTable_.atan2_(t.x - p->field_0C.x, t.y - p->field_0C.y);
        u16 ang = (s32)(rad * lbl_8053C96C);
        p->field_98 = ClassifyBamAngleToQuadrant(ang);
        f32 sy;
        f32 sx;
        sx = lbl_8053C970 * JMath::sincosTable_.mTable[ang >> 5].first;
        sy = lbl_8053C970 * JMath::sincosTable_.mTable[ang >> 5].second;
        bool done = true;
        if (fn_801CD950(&p->field_0C.x, t.x, sx) != 0 && lbl_8053C964 != sx) {
            done = false;
        }
        if (((EzzrMgr*)fn_802D6A9C())->flag(p->field_04) == 0) {
            if (fn_801CD950(&p->field_0C.y, t.y, sy) != 0 && lbl_8053C964 != sy) {
                done = false;
            }
        }
        if (!done) {
            fn_80122730(p, p->field_98, 0, 0);
            break;
        }
        fn_8022FE80(*(s32*)((u8*)p + 0x3cc), p->field_04, p->field_198, 0, 0);
        if (*(s32*)((u8*)p + 0x3cc) == fn_8022FD8C(p->field_198)) {
            s32 msg = 0x2b7;
            if (*(s32*)fn_80131F0C() == 1) {
                msg = 0x2b4;
            }
            if (fn_8038AD24(*(s32*)((u8*)p + 0x3cc), msg, p->field_198, p->field_04, (JGeometry::TVec3f*)&(const JGeometry::TVec3f&)JGeometry::TVec3f(lbl_8053C964, lbl_8053C964, lbl_8053C964), 2)) {
                p->v25(5);
            }
        }
        break;
    }
    case 5:
        fn_8022FE80(*(s32*)((u8*)p + 0x3cc), p->field_04, p->field_198, 0, 0);
        if (fn_80388CAC(*(s32*)((u8*)p + 0x3cc), p->field_198)) {
            fn_8023061C(*(s32*)((u8*)p + 0x3cc), 0);
            p->v25(8);
        }
        break;
    case 7: {
        if (fn_8012285C(p) < 0) {
            p->v25(0);
            break;
        }
        bool near;
        if (*(s32*)fn_80131F0C() <= 1) {
            near = false;
        } else {
            f32 dist = lbl_8053C980;
            s32 id = fn_801F778C(fn_801F856C(), 0x42415249, &p->field_0C, &dist);
            if (id < 0) {
                near = false;
            } else if (dist > lbl_8053C984) {
                near = false;
            } else {
                Actor* a = (Actor*)fn_801F666C(fn_801F856C(), id);
                if (a == 0) {
                    near = false;
                } else if (*((u8*)a + 0x11c) == 0) {
                    near = false;
                } else {
                    near = true;
                }
            }
        }
        if (near && !fn_802DCD0C(fn_802D6A9C()) && fn_801186B0(fn_8011921C(), 0xe)) {
            fn_8011921C()[2] = true;
            fn_80118454(fn_8011921C());
            fn_8037AE00(lbl_8053AD70);
            for (s32 i = 0; i < *(s32*)fn_80131F0C(); i++) {
                EZZR* a = (EZZR*)fn_80131E30(fn_80131F0C(), i);
                if (a != 0) {
                    a->v25(13);
                }
            }
            break;
        }
        if (fn_80138A30(lbl_8053AAF8) > 1) {
            p->v37(fn_8012285C(p), lbl_8053C98C, lbl_8053C990, lbl_8053C994, lbl_8053C998, lbl_8053C99C);
        } else {
            p->v37(fn_8012285C(p), lbl_8053C98C, lbl_8053C990, lbl_8053C994, lbl_8053C998, lbl_8053C9A0);
        }
        break;
    }
    case 9:
        if (fn_8012285C(p) < 0) {
            p->v25(0);
            break;
        }
        if (fn_8022D75C(fn_8012285C(p))) {
            break;
        }
        if ((s32)p->field_04 != fn_8023DE58(fn_8012285C(p))) {
            break;
        }
        p->v25(10);
        break;
    case 10:
        if (fn_8012285C(p) < 0) {
            p->v25(0);
        }
        if (fn_80122804(p)) {
            p->v25(7);
        }
        break;
    case 11:
        fn_80122548(p);
        if (!fn_802DCD0C(fn_802D6A9C())) {
            p->v25(7);
        }
        break;
    case 12:
        p->field_04 = fn_8023DE58(fn_8012285C(p));
        if (!fn_8022D75C(fn_8012285C(p)) && fn_801216D0(p, fn_8012285C(p)) < 0) {
            p->v25(7);
            break;
        }
        fn_80122148(p);
        break;
    case 13:
        (*(s32*)((u8*)p + 0x3c8))++;
        if (*(s32*)((u8*)p + 0x3c8) >= 60) {
            p->v25(14);
        }
        break;
    case 14:
        if (p->v13() == 0) {
            p->v25(7);
            break;
        }
        *(f32*)((u8*)p + 0x380) = lbl_8053C970;
        *(f32*)((u8*)p + 0x37c) = lbl_8053C9A4;
        if (p->v48((Vec*)&(const JGeometry::TVec3f&)JGeometry::TVec3f(lbl_8053C964, lbl_8053C964, lbl_8053C964), *(f32*)((u8*)p + 0x380))) {
            p->v25(15);
        }
        break;
    case 15:
        break;
    }
}

extern "C" void fn_80120F38(int param_1)
{
    if ((*(unsigned int *)(param_1 + 0x90) & 1) != 0) {
        *(u8 *)(param_1 + 0x3c4) = 1;
    }
    *(unsigned int *)(param_1 + 0x35c) = (*(unsigned int *)(param_1 + 0x90) >> 8) & 0xff;
    *(unsigned int *)(param_1 + 0x3d0) = (*(unsigned int *)(param_1 + 0x90) >> 16) & 0xff;
}

extern "C" s32 fn_80120F68(char* p) {
    u8 r;
    s32 ret;
    s32 state = *(s32*)(p + 0x33c);
    if (state == 0 || state == 0xf) {
        return 3;
    }
    r = ((EZZR*)p)->v20();
    ret = 1;
    if (r) {
        ret = 2;
    }
    return ret;
}

extern "C" f32 fn_80121DC8(void*, s32);
extern f32 lbl_8053C9A8;
extern "C" bool fn_80120FC0(void* p) {
    s32 state = *(s32*)((u8*)p + 0x33c);
    switch (state) {
    case 7:
    case 0xb:
    case 0xc:
        return fn_80121DC8(p, fn_8012285C(p)) <= lbl_8053C9A8;
    case 0xd:
    case 0xe:
    default:
        return false;
    }
}

extern "C" s32 fn_80121040(void* p)
{
	switch (*(s32*)((u8*)p + 0x33c)) {
	case 7:
	case 9:
	case 10:
	case 11:
	case 12:
		return 1;
	}
	return 0;
}

extern "C" void fn_80121074(void* p)
{
	if (*(s32*)((u8*)p + 0x33c) != 0xf) {
		fn_80124278(p);
	}
}

extern "C" void fn_80124278(void*);
extern "C" void fn_80124448(void*);
extern "C" void fn_80131EC0(GateRegistry*, void*);
extern "C" void fn_801210A0(void* p)
{
	fn_80124448(p);
	u32 flags = *(u32*)((u8*)p + 0x90);
	if ((flags >> 2) & 1) {
		*(u32*)((u8*)p + 0x344) = (flags >> 3) & 0xf;
		fn_80131EC0(fn_80131F0C(), p);
		((EZZR*)p)->v25(7);
	}
}

extern u8 lbl_8049DF78[];
extern "C" void fn_80124740(void*, s32);
extern "C" void* fn_80121104(void* p, s16 flag) {
    if (p != 0) {
        *(u8**)p = lbl_8049DF78;
        fn_80124740(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_801247C8(void*, void*, s32, s32);
extern u8 lbl_80464CC0[];
extern "C" void* fn_80121164(u8* p) {
    fn_801247C8(p, lbl_80464CC0, 0x242, 0);
    *(void**)p = lbl_8049DF78;
    *(u8*)(p + 0x3c4) = 0;
    *(s32*)(p + 0x3c8) = 0;
    *(s32*)(p + 0x3cc) = -1;
    *(s32*)(p + 0x3d0) = 0;
    return p;
}

void __sinit_EZZR_8011FFB8_cpp(void) {
}

extern "C" s32 fn_8011FFB8(void)
{
	return 0;
}

extern "C" s32 fn_8011FFC0(void)
{
	return 0;
}

extern "C" void fn_8011FFC8(void) {}
class JASGenericMemPool {
public:
    void* mRunner;
    s32 mFreeMemCount;
    s32 mTotalMemCount;
    u32 mUsedMemCount;
    JASGenericMemPool();
    ~JASGenericMemPool();
};

template <typename T>
class JASMemPool_MultiThreaded : public JASGenericMemPool {
public:
    ~JASMemPool_MultiThreaded();
};

template <typename T>
class JASMemPool : public JASGenericMemPool {
public:
    ~JASMemPool();
};

template <typename T>
class JASPoolAllocObject_MultiThreaded {
public:
    static JASMemPool_MultiThreaded<T> memPool_;
};

template <typename T>
class JASPoolAllocObject {
public:
    static JASMemPool<T> memPool_;
};

class JASTrack {
public:
    class TChannelMgr;
};
class JASChannel;
class JAIStream;
class JAISoundChild;
class JAISeq;
class JAISe;
class JASPoolObj3_FSA;
class JASPoolObj4_FSA;

template <> JASMemPool_MultiThreaded<JASTrack::TChannelMgr> JASPoolAllocObject_MultiThreaded<JASTrack::TChannelMgr>::memPool_;
template <> JASMemPool_MultiThreaded<JASTrack> JASPoolAllocObject_MultiThreaded<JASTrack>::memPool_;
template <> JASMemPool_MultiThreaded<JASChannel> JASPoolAllocObject_MultiThreaded<JASChannel>::memPool_;
template <> JASMemPool<JASPoolObj3_FSA> JASPoolAllocObject<JASPoolObj3_FSA>::memPool_;
template <> JASMemPool<JASPoolObj4_FSA> JASPoolAllocObject<JASPoolObj4_FSA>::memPool_;
template <> JASMemPool<JAIStream> JASPoolAllocObject<JAIStream>::memPool_;
template <> JASMemPool<JAISoundChild> JASPoolAllocObject<JAISoundChild>::memPool_;
template <> JASMemPool<JAISeq> JASPoolAllocObject<JAISeq>::memPool_;
template <> JASMemPool<JAISe> JASPoolAllocObject<JAISe>::memPool_;
