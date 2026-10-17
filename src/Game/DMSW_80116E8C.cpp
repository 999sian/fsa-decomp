#include "types.h"
#include "Game/Actor.h"

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
extern "C" f32 lbl_8053C74C;
extern "C" f32 lbl_8053C750;
extern "C" f32 lbl_8053C754;
extern "C" f32 lbl_8053C758;
extern "C" void fn_801CD950(f32* value, f32 target, f32 step);
extern "C" void fn_8030C210(void* p, void* q);
extern "C" void* fn_8011921C(void);

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
	case 0:
	case 1:
	case 2:
	case 12:
		break;
	default:
		break;
	}
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
extern "C" void fn_80117074(void* p, s32 n);
extern "C" void fn_801174C0(void* param_1) {
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
    Vec pos;
    pos = *(Vec*)(this_ + 0xc);
    pos.y += lbl_8053C78C;
    if (*(s32*)(this_ + 4) < 8) {
        void* res = (*(SwbmResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_80464AC0);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), &pos, res, 0x179, lbl_8053C754, lbl_8053C754, 0);
    }
}

extern "C" void fn_8010DF98(void*);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern "C" void* fn_802D6A9C(void);
extern "C" void* fn_8013CC50(s32, void*, s32, s32, s32, s32, s32, s32, f32);
extern "C" char lbl_8049DA00[];
extern "C" f32 lbl_8053C750;
extern "C" f32 lbl_8053C754;
extern "C" void fn_80117F34(char* p) {
    struct Box4 {
        f32 a, b, c, d;
    };
    f32 pos[3];

    fn_8010DF98(p);
    fn_801D2608(p + 0x250, lbl_8049DA00, 3);
    fn_801D22DC(p + 0x250, 0, 2, 0);
    fn_801D1F14(p + 0x250, lbl_8053C75C);
    Box4 box = *(Box4*)((char*)fn_802D6A9C() + 0xCC);
    pos[0] = (box.a - box.c) * lbl_8053C750 + box.c;
    pos[1] = (box.b - box.d) * lbl_8053C750 + box.d;
    pos[2] = lbl_8053C75C;
    *(void**)(p + 0x2a8) = fn_8013CC50(*(s32*)(p + 4), pos, 0x33e, 0, 0, 0, 0, 1, lbl_8053C754);
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

