#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "Game/SinitPoolChain.h"

struct SwbmDrawParam {
    SwbmDrawParam() : m40(-1), m44(-1) {
        for (u8 i = 0; i < 16; i++) {
            mIdx[i] = i;
        }
    }
    void reset() {
        m40 = -1;
        m44 = 0;
        mMtx = NULL;
        m4C = 0;
        m4D = 0;
        m4E = 0;
        m4F = 1;
        m50 = 1;
        m51 = 0;
        m52 = 0;
        m53 = 0;
        m54 = 0;
        m55 = 0;
        m56 = 1;
        m58 = 3;
        m5C = 1;
        m5D = 0;
        m5E = 0;
        m60 = -1;
        m64 = 0;
        m68 = 2;
    }
    u8 mIdx[16];
    s32 m40;
    s32 m44;
    f32 (*mMtx)[4];
    u8 m4C, m4D, m4E, m4F, m50, m51, m52, m53, m54, m55, m56;
    s32 m58;
    u8 m5C, m5D, m5E;
    s32 m60;
    s32 m64;
    s32 m68;
};

struct SwbmResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* getRes(u32 type, const char* name);
};

extern "C" void fn_8010DF58(void);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_801EF830(s32 room, void* pos, SwbmDrawParam* prm, s32 a, void* name, s32 id, s32 e);
extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, f32 sx, f32 sy, SwbmDrawParam* prm);
extern u8* lbl_8053AAF8;
extern u8* lbl_8053AB10;
extern char lbl_80464AC0[];
extern f32 lbl_8053C754;
extern f32 lbl_8053C78C;

extern "C" char lbl_8049DA0C[];
extern "C" char lbl_8049CC34[];
extern "C" f32 lbl_8053C75C;
extern "C" void fn_801EE434(void*);
extern "C" void __dt__13Base_8010E074Fv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" void fn_8010E074(void*);
extern "C" void fn_801D267C(void*);
extern "C" u8* lbl_8053AB10;
extern "C" f32 lbl_8053C748;
extern "C" const f32 lbl_8053C74C;
extern "C" const f32 lbl_8053C750;
extern "C" f32 lbl_8053C754;
extern "C" const f32 lbl_8053C758;
extern "C" void fn_801CD950(f32* value, f32 target, f32 step);
extern "C" void fn_8030C210(void* p, void* q);
extern "C" void* fn_8011921C(void);
extern "C" void* fn_80119DD0(void);
extern "C" void fn_80119998(void* a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern "C" void fn_80234810(void);
extern "C" void fn_802382D0(s32, s32);
extern "C" void fn_80458FF0(void* a, s32 b, s32 c, s32 d);
extern "C" void* lbl_8053AF80;
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 i);
extern "C" void fn_80230FD0(s32 player, s32 id);
extern "C" void fn_80230BF4(s32 a, s32 b);
extern "C" void fn_80230498(s32 i, JGeometry::TVec3<f32>* pos, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_80118454(void*);
extern "C" void fn_801183BC(void*);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern "C" void* fn_8013CC50(s32, void*, s32, s32, s32, s32, s32, s32, f32);
extern "C" const u16 lbl_8053C740[4];
extern "C" f32 lbl_8053C788;
extern "C" f32 lbl_8053C790;

struct Vec3 {
	f32 x, y, z;
};
extern "C" void fn_80116E8C(char* p) {
	if (*(s32*)(p + 0x234) >= 2 && *(s32*)(p + 0x234) <= 0xb) {
		if (*(s32*)((char*)fn_8011921C() + 8) >= 0x32) {
			u8* mgr = *(u8**)(lbl_8053AB10 + 0x30);
			if (mgr[0x284] == 0) {
				mgr[0x284] = 1;
				*(f32*)(mgr + 0x28c) = lbl_8053C748;
			}
		}
	}

	switch (*(s32*)(p + 0x234)) {
	case 9: {
		JGeometry::TVec3<f32> xy = *(JGeometry::TVec3<f32>*)(p + 0xc);
		xy.y += *(f32*)(p + 0x240);
		fn_801CD950((f32*)(p + 0x240), lbl_8053C74C + *(f32*)(p + 0x10), lbl_8053C750);
		u8* mgr = *(u8**)(lbl_8053AB10 + 0x24);
		if (mgr[0x840] == 0) {
			f32 c758;
			f32 c754;
			f32 x;
			f32 y;
			mgr[0x840] = 1;
			x = xy.x;
			y = xy.y;
			*(f32*)(mgr + 0x84c) = x;
			*(f32*)(mgr + 0x844) = x;
			c754 = lbl_8053C754;
			c758 = lbl_8053C758;
			*(f32*)(mgr + 0x850) = y;
			*(f32*)(mgr + 0x848) = y;
			*(f32*)(mgr + 0x854) = c754;
			*(f32*)(mgr + 0x1d4) = c758;
			*(f32*)(mgr + 0x1d8) = c758;
		}
		break;
	}
	case 10:
	case 11: {
		JGeometry::TVec3<f32> xy = *(JGeometry::TVec3<f32>*)(p + 0xc);
		xy.y += *(f32*)(p + 0x240);
		u8* mgr = *(u8**)(lbl_8053AB10 + 0x24);
		if (mgr[0x840] == 0) {
			f32 c758;
			f32 c754;
			f32 x;
			f32 y;
			mgr[0x840] = 1;
			x = xy.x;
			*(f32*)(mgr + 0x84c) = x;
			*(f32*)(mgr + 0x844) = x;
			c754 = lbl_8053C754;
			c758 = lbl_8053C758;
			y = xy.y;
			*(f32*)(mgr + 0x850) = y;
			*(f32*)(mgr + 0x848) = y;
			*(f32*)(mgr + 0x854) = c754;
			*(f32*)(mgr + 0x1d4) = c758;
			*(f32*)(mgr + 0x1d8) = c758;
		}
		break;
	}
	case 12:
		break;
	case 0:
	case 1:
	case 2:
		break;
	default: {
		u8* mgr = *(u8**)(lbl_8053AB10 + 0x24);
		if (mgr[0x840] == 0) {
			f32 c758;
			f32 c754;
			f32 x;
			f32 y;
			mgr[0x840] = 1;
			c754 = lbl_8053C754;
			c758 = lbl_8053C758;
			x = *(f32*)(p + 0xc);
			*(f32*)(mgr + 0x84c) = x;
			*(f32*)(mgr + 0x844) = x;
			y = *(f32*)(p + 0x10);
			*(f32*)(mgr + 0x850) = y;
			*(f32*)(mgr + 0x848) = y;
			*(f32*)(mgr + 0x854) = c754;
			*(f32*)(mgr + 0x1d4) = c758;
			*(f32*)(mgr + 0x1d8) = c758;
		}
		fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), p + 0xc);
		break;
	}
	}
}

extern "C" void fn_80117074(char* p, s32 n) {
    JGeometry::TVec3<f32>* out7;
    int k;
    JGeometry::TVec3<f32>* out;
    int i;
    const u16* ids;
    void** fx;
    int j;
    JGeometry::TVec3<f32> pos5;
    JGeometry::TVec3<f32> pos7;
    f32 dy7;
    f32 dx7;
    JGeometry::TVec3<f32> pos11;
    switch (n) {
    case 2: {
        fn_80119998(fn_80119DD0(), 0x78, 0, 2, 0, 1, 0, 0);
        fn_80234810();
        fn_802382D0(0, 0);
        fn_80458FF0(lbl_8053AF80, 0x1000020, 1, 0);
        u8* e = *(u8**)(p + 0x2a8);
        if (e) {
            *(u32*)(e + 0xf4) |= 1;
            *(s32*)(e + 0x24) = 1;
            *(u8**)(p + 0x2a8) = 0;
        }
        break;
    }
    case 4:
        *(f32*)(p + 0x280) = lbl_8053C754;
        break;
    case 5: {
        out = &pos5;
        for (i = 0, ids = lbl_8053C740, fx = (void**)p; i < 4; i++, ids++, fx++) {
            *out = *fn_8023E724(i);
            fx[0x288 / 4] = fn_8013CC50(*(s32*)(p + 4), out, *ids, 0, -1, 0, 0, 1, 1.0f);
            fx[0x298 / 4] = fn_8013CC50(*(s32*)(p + 4), &pos5, 0x475, 0, -1, 0, 0, 1, 1.0f);
        }
        for (j = 0; j < 4; j++) {
            fn_80230FD0(j, 0x20048);
        }
        *(f32*)(p + 0x23c) = lbl_8053C75C;
        fn_80118454(fn_8011921C());
        break;
    }
    case 6:
        fn_801183BC(fn_8011921C());
        break;
    case 7: {
        out7 = &pos7;
        dx7 = lbl_8053C78C;
        dy7 = lbl_8053C790;
        for (k = 0; k < 4; k++) {
            *out7 = *fn_8023E724(k);
            pos7.x += dx7;
            pos7.y += dy7;
            fn_8013CC50(*(s32*)(p + 4), out7, 0xcb, 0, 0, 0, 0, 1, 1.0f);
            fn_8013CC50(*(s32*)(p + 4), &pos7, 0xcc, 0, 0, 0, 0, 1, 1.0f);
        }
        for (k = 0; k < 4; k++) {
            fx = (void**)(p + k * 4);
            u8* e = (u8*)fx[0x288 / 4];
            if (e) {
                *(u32*)(e + 0xf4) |= 1;
                *(s32*)(e + 0x24) = 1;
                fx[0x288 / 4] = 0;
            }
            e = (u8*)fx[0x298 / 4];
            if (e) {
                *(u32*)(e + 0xf4) |= 1;
                *(s32*)(e + 0x24) = 1;
                fx[0x298 / 4] = 0;
            }
        }
        break;
    }
    case 8:
        fn_801D22DC(p + 0x250, 2, 0, 0);
        fn_801D1F14(p + 0x250, lbl_8053C75C);
        *(f32*)(p + 0x280) = lbl_8053C754;
        for (i = 0; i < 4; i++) {
            fn_80230FD0(i, 0x20047);
        }
        break;
    case 11: {
        pos11 = *(JGeometry::TVec3<f32>*)(p + 0xc);
        dy7 = lbl_8053C788;
        for (i = 0; i < 4; i++) {
            JGeometry::TVec3<f32>* v = fn_8023E724(i);
            pos11.x = v->x;
            pos11.y = v->y;
            pos11.z = v->z;
            pos11.y += dy7;
            fn_8013CC50(*(s32*)(p + 4), &pos11, 0x33a, 0, 0, 0, 0, 1, 1.0f);
        }
        for (i = 0; i < 4; i++) {
            fn_80230BF4(i, 3);
            fn_80230498(i, fn_8023E724(i), 0x3f, 0xff, -0x80, -0x80, 1);
            fn_80230FD0(i, 0x10015);
        }
        break;
    }
    case 12:
        break;
    }
    *(s32*)(p + 0x234) = n;
}

extern "C" s32 fn_80117498(char* p) {
    switch (*(s32*)(p + 0x234)) {
    case 12:
        return 1;
    }
    return 0;
}

extern "C" s32 fn_801174B8(char* p) {
    return *(s32*)(p + 0x234);
}

extern s32 lbl_80464A7C[];
extern "C" void* fn_8011921C(void);
extern "C" void fn_801174C0(char* param_1) {
    if (*(s32*)((char*)fn_8011921C() + 4) == 2) {
        s32 v = *(s32*)((char*)fn_8011921C() + 8);
        if (v == lbl_80464A7C[2]) {
            fn_80117074(param_1, 2);
        } else if (v == lbl_80464A7C[3]) {
            fn_80117074(param_1, 3);
        } else if (v == lbl_80464A7C[4]) {
            fn_80117074(param_1, 4);
        } else if (v == lbl_80464A7C[5]) {
            fn_80117074(param_1, 5);
        } else if (v == lbl_80464A7C[7]) {
            fn_80117074(param_1, 7);
        } else if (v == lbl_80464A7C[8]) {
            fn_80117074(param_1, 8);
        } else if (v == lbl_80464A7C[9]) {
            fn_80117074(param_1, 9);
        } else if (v == lbl_80464A7C[11]) {
            fn_80117074(param_1, 11);
        } else if (v == lbl_80464A7C[12]) {
            fn_80117074(param_1, 12);
        }
    }
}

extern "C" void fn_80117600(char* this_) {
    fn_8010DF58();
    SwbmDrawParam prm;
    prm.reset();
    if (*(u32*)(this_ + 0x138) == 0) {
        fn_801EF830(*(s32*)(this_ + 4), this_ + 0xc, &prm, 1, lbl_80464AC0, 0x179, 0);
    }
    JGeometry::TVec3f pos = *(JGeometry::TVec3f*)(this_ + 0xc);
    pos.y += lbl_8053C78C;
    if (*(s32*)(this_ + 4) < 8) {
        void* res = (*(SwbmResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_80464AC0);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), &pos, res, 0x179, lbl_8053C754, lbl_8053C754, 0);
    }
}

extern "C" void fn_8010DF78(char* p);
extern "C" s32 fn_8023561C(s32 i);
extern "C" s32 fn_80230CFC(s32 i);
extern "C" void fn_801EEC98(char* p, s32 h, s32* a, s32* b, f32* c, s32* d, s32 e, s32 f);
extern "C" void fn_8023077C(void);
extern "C" void fn_8022FE80(s32 a, s32 room, s32 h, s32 b, s32 c);
extern "C" void fn_8022FD8C(s32 h);
extern "C" u8 fn_8038BD08(s32 a, s32 id, s32 room, f32* v, s32 c);
extern "C" s32 fn_803865B8(s32 a);
extern "C" s32 fn_8037EFB4(s32 a);
extern "C" void fn_80388CAC(s32 a, s32 h);
extern "C" void fn_80230534(s32 a);
extern "C" void fn_801186B0(void* p, s32 n);
extern "C" void fn_801F0E34(char* p, s32 a, s32 b);
extern "C" void fn_801D1C18(void* p);
extern "C" void fn_802303FC(s32 i, JGeometry::TVec3<f32>* v, s32 c);
extern "C" void fn_80239914(f32* box, s32 room, s32 h);
extern "C" u32 lbl_80464AB0[];
extern "C" f32 lbl_8053C760;
extern "C" f32 lbl_8053C764;
extern "C" const f32 lbl_8053C768;
extern "C" const f32 lbl_8053C76C;
extern "C" f32 lbl_8053C770;
extern "C" f32 lbl_8053C774;
extern "C" const f32 lbl_8053C778;
extern "C" f32 lbl_8053C77C;
extern "C" f32 lbl_8053C780;

struct DmswRect {
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
};

static inline u8 dmswCanSwitch(char* this_) {
    s32 kind;
    s32 type;
    s32 id;
    f32 dist;
    for (s32 i = 0; i < 4; i++) {
        if (!(u8)fn_8023561C(i)) {
            return 0;
        }
    }
    if (fn_80230CFC(0) != 3) {
        return 0;
    }
    fn_801EEC98(this_, *(s32*)(this_ + 0x198), &kind, &type, &dist, &id, 0, 0);
    if (type != 2) {
        return 0;
    }
    if (dist <= lbl_8053C764) {
        return 1;
    }
    return 0;
}
extern "C" void fn_801177C0(char* this_) {
    f32 box[4];
    s32 i;
    fn_8010DF78(this_);
    box[0] = *(f32*)(this_ + 0x60);
    box[1] = *(f32*)(this_ + 0x64);
    box[2] = *(f32*)(this_ + 0x68);
    box[3] = *(f32*)(this_ + 0x6c);
    box[0] += *(f32*)(this_ + 0xc);
    box[2] += *(f32*)(this_ + 0xc);
    box[1] += *(f32*)(this_ + 0x10);
    box[3] += *(f32*)(this_ + 0x10);
    fn_80116E8C(this_);
    switch (*(s32*)(this_ + 0x234)) {
    case 0:
        if (*(u8*)fn_8011921C() != 0) {
            break;
        }
        fn_80239914(box, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198));
        if (dmswCanSwitch(this_)) {
            if (*(u8*)(this_ + 0x231) != 0) {
                break;
            }
            fn_8023077C();
            fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
            fn_8022FD8C(*(s32*)(this_ + 0x198));
            s32 id = 0x4b2;
            if (*(u8*)(this_ + 0x230) != 0) {
                id = 0x4b3;
            }
            f32 v[3];
            v[0] = lbl_8053C75C;
            v[1] = lbl_8053C760;
            v[2] = lbl_8053C75C;
            bool ok = fn_8038BD08(0, (u16)id, *(s32*)(this_ + 4), v, 0x22);
            if (ok) {
                fn_80117074(this_, 1);
            }
        } else {
            *(u8*)(this_ + 0x231) = 0;
        }
        break;
    case 1:
        fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
        if ((u8)fn_803865B8(0)) {
            switch (fn_8037EFB4(0)) {
            case 0:
                fn_80388CAC(0, *(s32*)(this_ + 0x198));
                for (i = 0; i < 4; i++) {
                    fn_80230BF4(i, 3);
                    fn_80230498(i, fn_8023E724(i), 0x3f, 0xff, -0x80, -0x80, 1);
                }
                fn_80230534(0);
                fn_801186B0(fn_8011921C(), 2);
                break;
            case 1:
            default:
                fn_80388CAC(0, *(s32*)(this_ + 0x198));
                fn_80230534(0);
                fn_80117074(this_, 0);
                *(u8*)(this_ + 0x230) = 1;
                *(u8*)(this_ + 0x231) = 1;
                break;
            }
        }
        break;
    case 2:
        if (*(s32*)((char*)fn_8011921C() + 8) == 0x3c) {
            i = 0;
            *(u8*)(this_ + 0x11d) = i;
            *(f32*)(this_ + 0x244) = *(f32*)(this_ + 0xc);
            *(f32*)(this_ + 0x248) = *(f32*)(this_ + 0x10);
            *(f32*)(this_ + 0x24c) = *(f32*)(this_ + 0x14);
            *(f32*)(this_ + 0x248) = *(f32*)(this_ + 0x248) + lbl_8053C74C;
            for (; i < 4; i++) {
                fn_80230BF4(i, 2);
                fn_80230498(i, (JGeometry::TVec3<f32>*)(this_ + 0x244), 0x31a, 0xff, -0x80, -0x80, 1);
            }
            fn_801D22DC(this_ + 0x250, 1, 0, 0);
            fn_801D1F14(this_ + 0x250, lbl_8053C75C);
            *(f32*)(this_ + 0x280) = lbl_8053C75C;
        }
        if (*(s32*)((char*)fn_8011921C() + 8) > 0x3c) {
            u8* mgr = *(u8**)(lbl_8053AB10 + 0x24);
            if (mgr[0x840] == 0) {
                mgr[0x840] = 1;
                *(f32*)(mgr + 0x84c) = *(f32*)(this_ + 0xc);
                *(f32*)(mgr + 0x844) = *(f32*)(this_ + 0xc);
                *(f32*)(mgr + 0x850) = *(f32*)(this_ + 0x10);
                *(f32*)(mgr + 0x848) = *(f32*)(this_ + 0x10);
                *(f32*)(mgr + 0x854) = lbl_8053C754;
                *(f32*)(mgr + 0x1d4) = lbl_8053C758;
                *(f32*)(mgr + 0x1d8) = lbl_8053C758;
            }
            fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), this_ + 0xc);
        }
        if (*(s32*)((char*)fn_8011921C() + 8) >= 0x32) {
            *(u8*)((char*)fn_8011921C() + 2) = 1;
        }
        break;
    case 5: {
        u8 flag;
        for (i = flag = 0; i < 4; i++) {
            JGeometry::TVec3<f32> tmp = *fn_8023E724(i);
            fn_801CD950((f32*)(this_ + 0x23c), lbl_8053C770, lbl_8053C774);
            s32 n = lbl_80464AB0[i];
            fn_801CD950((f32*)&tmp, lbl_8053C778 * n + *(f32*)(this_ + 0x244), *(f32*)(this_ + 0x23c) * n);
            fn_80230BF4(i, 2);
            fn_80230498(i, &tmp, *(s32*)(this_ + 0x260), 0xff, -0x80, -0x80, 1);
            char* o = *(char**)(this_ + 0x288 + i * 4);
            *(f32*)(o + 0xa4) = tmp.x;
            *(f32*)(o + 0xa8) = tmp.y;
            *(f32*)(o + 0xac) = tmp.z;
            o = *(char**)(this_ + 0x298 + i * 4);
            *(f32*)(o + 0xa4) = tmp.x;
            *(f32*)(o + 0xa8) = tmp.y;
            *(f32*)(o + 0xac) = tmp.z;
            if (i == 0 && *(f32*)(this_ + 0x244) - tmp.x >= lbl_8053C77C) {
                flag = 1;
            }
        }
        if (flag) {
            fn_80117074(this_, 6);
        }
        break;
    }
    case 8: {
        for (i = 0; i < 4; i++) {
            fn_80230498(i, fn_8023E724(i), *(s32*)(this_ + 0x260), 0xff, -0x80, -0x80, 1);
            if (*(s32*)(this_ + 0x260) == 0xdc) {
                fn_80230FD0(i, 0x10001);
            }
        }
        if (*(s32*)((char*)fn_8011921C() + 8) != lbl_80464A7C[9] - 0x1e) {
            break;
        }
        JGeometry::TVec3<f32> vv;
        DmswRect r = *(DmswRect*)((char*)fn_802D6A9C() + 0xcc);
        vv.x = lbl_8053C750 * (r.x0 - r.x1) + r.x1;
        vv.y = lbl_8053C750 * (r.y0 - r.y1) + r.y1;
        vv.z = lbl_8053C75C;
        fn_8013CC50(*(s32*)(this_ + 4), &vv, 0x102, 0, 0, 0, 0, 1, lbl_8053C754);
        fn_8013CC50(*(s32*)(this_ + 4), &vv, 0x103, 0, 0, 0, 0, 1, lbl_8053C754);
        fn_8013CC50(*(s32*)(this_ + 4), &vv, 0x104, 0, 0, 0, 0, 1, lbl_8053C754);
        *(s32*)(this_ + 0x238) = 0;
        break;
    }
    case 9: {
        u8 flag;
        for (i = flag = 0; i < 4; i++) {
            JGeometry::TVec3<f32> tmp = *fn_8023E724(i);
            tmp.y += lbl_8053C768;
            f32 lim = lbl_8053C76C + *(f32*)(this_ + 0x10);
            if (tmp.y >= lim) {
                tmp.y = lim;
                flag = 1;
            }
            fn_802303FC(i, &tmp, 0xff);
        }
        if (flag) {
            fn_80117074(this_, 0xa);
        }
        break;
    }
    case 12:
        break;
    }
    s32 t238 = *(s32*)(this_ + 0x238);
    if (t238 >= 0) {
        *(s32*)(this_ + 0x238) = t238 + 1;
        if (*(s32*)(this_ + 0x238) <= 0x474) {
            fn_801F0E34(this_, 0x3007a, 0);
            fn_801D1C18(this_ + 0x250);
        }
    }
}

extern "C" void fn_8010DF98(void*);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" char lbl_8049DA00[];
struct DMSWBox4 { f32 a, b, c, d; };
static inline void spawnDMSWInner(char* p) {
    DMSWBox4 box = *(DMSWBox4*)((char*)fn_802D6A9C() + 0xCC);
    f32 pos[3];
    f32 cy = box.d;
    f32 cx = box.c;
    f32 k = lbl_8053C750;
    f32 x, y;
    x = box.a - cx;
    x = k * x + cx;
    y = box.b - cy;
    y = k * y + cy;
    pos[0] = x;
    pos[1] = y;
    pos[2] = lbl_8053C75C;
    *(void**)(p + 0x2a8) = fn_8013CC50(*(s32*)(p + 4), pos, 0x33e, 0, 0, 0, 0, 1, lbl_8053C754);
}
extern "C" void fn_80117F34(char* p) {
    fn_8010DF98(p);
    fn_801D2608(p + 0x250, lbl_8049DA00, 3);
    fn_801D22DC(p + 0x250, 0, 2, 0);
    fn_801D1F14(p + 0x250, lbl_8053C75C);
    spawnDMSWInner(p);
}

extern "C" void* fn_80118018(char* p, s16 flag) {
    if (p != 0) {
        *(void**)p = lbl_8049DA0C;
        for (s32 i = 0; i < 4; i++) {
            fn_801EE434(*(void**)(p + 0x288 + i * 4));
            *(void**)(p + 0x288 + i * 4) = 0;
            fn_801EE434(*(void**)(p + 0x298 + i * 4));
            *(void**)(p + 0x298 + i * 4) = 0;
            fn_801EE434(*(void**)(p + 0x2a8));
            *(void**)(p + 0x2a8) = 0;
        }
        if (p + 0x250 != 0 && p + 0x274 != 0) {
            *(void**)(p + 0x274) = lbl_8049CC34;
        }
        __dt__13Base_8010E074Fv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void* fn_801180D0(char* p) {
    fn_8010E074(p);
    *(void**)p = lbl_8049DA0C;
    f32 f = lbl_8053C75C;
    *(u8*)(p + 0x230) = 0;
    *(u8*)(p + 0x231) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = -1;
    *(f32*)(p + 0x23c) = f;
    *(f32*)(p + 0x240) = f;
    fn_801D267C(p + 0x250);
    *(s32*)(p + 0x2a8) = 0;
    for (s32 i = 0; i < 4; i++) {
        *(s32*)(p + 0x288 + i * 4) = 0;
        *(s32*)(p + 0x298 + i * 4) = 0;
    }
    return p;
}

