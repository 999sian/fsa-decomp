#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/J2D/J2DPane.h"
#include "JSystem/J2D/J2DScreen.h"

extern "C" const char* lbl_804B1900[];
extern "C" void* fn_804030C4(u32 type, const char* name);
extern "C" void* fn_804032E8(u32 type, const char* name);

struct Fn8043ABCC_Obj {
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void* v15(u32 a, s32 b, u32 c);
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
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
    virtual void v36();
    virtual void v37();
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
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68(void* a, s32 b);
};

extern const f32 lbl_80543C88;
extern const f32 lbl_80543CC4;
extern const f32 lbl_80543CC8;
extern const f32 lbl_80543CE8;
extern const f32 lbl_80543CEC;


extern void* lbl_8053AED0;
extern "C" void* fn_8043DF8C(void* game);
extern char* lbl_8053AAF8;
extern s32 lbl_8053AEF0;
extern u8 lbl_80529DEC[];
extern u8 lbl_8050EC80[];
extern "C" void fn_8043A450(void* param_1, s32 param_2, s32 param_3);
extern const f32 lbl_80543CFC;
extern const f32 lbl_80543CF8;
extern const f32 lbl_80543CF0;
extern const f32 lbl_80543CF4;
extern "C" void fn_8041E708(void* p);
extern "C" void fn_80425234(void* p);
extern "C" void fn_8043E7CC(void* game, void* v);
extern "C" void fn_8041E58C(void* p);
extern "C" void fn_80425128(void* p);
extern "C" void fn_8041FC2C(void* p);
extern "C" void fn_8041F5FC(void* p);
extern "C" void fn_80425F24(void* p);
extern "C" void fn_8043E80C(u8* self, s32 digit, s32 alpha, u32 c1, u32 c2, f32 a, f32 b, f32 c);
extern const f32 lbl_80543CA0;
extern const f32 lbl_80543CD0;
extern const f32 lbl_80543CD4;
extern const f32 lbl_80543CD8;
extern const f32 lbl_80543CDC;
extern const f32 lbl_80543CE0;
extern const f32 lbl_80543CE4;
extern "C" void fn_8044A06C(void* p);
extern "C" void fn_80445D24(void* p);
extern "C" void fn_80448334(void* p);
extern "C" void fn_8044AFD8(void* p);
extern "C" void fn_804490B8(void* p);
extern "C" void fn_804479A0(void* p);
extern "C" u8 fn_80402940(void* p, s32 a, f32 x, f32 y, s32 b);
extern "C" void fn_80446DB0(void* p);
extern "C" void fn_804263A8(void* p);
extern "C" void fn_80443688(s32 p);
extern "C" void fn_8043A0E8(u8 param_1) {
    if (((u8*)lbl_8053AAF8)[0x7f] != 0 && (*(u32*)(lbl_8050EC80 + 0x28 + 0xc8 * *(s32*)(lbl_8050EC80 + 0x10)) & 1) == 0 &&
        *(s32*)(lbl_80529DEC + 0x118) == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 0) {
        if (param_1 == 0) {
            return;
        }
    }
    if (*(s32*)(lbl_80529DEC + 0x118) == 10 && *(s32*)(lbl_80529DEC + 0x11c) == 2) {
        return;
    }
    *((u8*)lbl_8053AED0 + 0xdd) = 0xf;
}

extern "C" void fn_8043A170(u32 param_1, u8 param_2) {
    if (((u8*)lbl_8053AAF8)[0x7f] != 0 && (*(u32*)(lbl_8050EC80 + 0x28 + 0xc8 * *(s32*)(lbl_8050EC80 + 0x10)) & 1) == 0 &&
        *(s32*)(lbl_80529DEC + 0x118) == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 0) {
        if (param_2 == 0) {
            return;
        }
    }
    if (*(s32*)(lbl_80529DEC + 0x118) == 10 && *(s32*)(lbl_80529DEC + 0x11c) == 2) {
        return;
    }
    *((u8*)lbl_8053AED0 + 0xdd) = *((u8*)lbl_8053AED0 + 0xdd) | (u8)(1 << param_1);
}

extern "C" void fn_8043A208(u8* param_1, f32 param_2, f32 param_3, f32 param_4, f32 param_5) {
    struct VObj {
        virtual void v00();
        virtual void v01();
        virtual void v02();
        virtual void v03();
        virtual void v04();
        virtual void v05();
        virtual void v06();
        virtual void v07();
        virtual void v08();
        virtual void v09();
    };
    if (*(void**)(param_1 + 0x10) != NULL) {
        *(f32*)(param_1 + 0x1c0) = param_2;
        *(f32*)(param_1 + 0x1c4) = param_3;
        *(f32*)(param_1 + 0x1c8) = param_4;
        *(f32*)(param_1 + 0x1cc) = param_5;
        ((VObj*)*(void**)(param_1 + 0x10))->v07();
        *(u8*)(param_1 + 0x254) = 1;
    }
}

extern "C" void fn_8043A608(void* param_1) {
    fn_8043A450(param_1, *(s32*)(lbl_80529DEC + 0x118), *(s32*)(lbl_80529DEC + 0x11c));
}

extern "C" void fn_8043ABCC(u8* param_1, s32 param_2) {
    void* uVar1;
    Fn8043ABCC_Obj* piVar2;
    s32 idx = param_2 & ~(param_2 >> 31);
    if (idx != 1) {
        uVar1 = fn_804032E8(0x54494D47, lbl_804B1900[idx]);
    } else {
        uVar1 = fn_804030C4(0x54494D47, lbl_804B1900[idx]);
    }
    piVar2 = (Fn8043ABCC_Obj*)(*(Fn8043ABCC_Obj**)(param_1 + 8))->v15(0x64660000, 0x50, 0x64663031);
    piVar2->v68(uVar1, 0);
    u8* p = (u8*)(*(Fn8043ABCC_Obj**)(param_1 + 8))->v15(0x64660000, 0x50, 0x64663031);
    p[0xb0] = 1;
    u8* q = (u8*)(*(Fn8043ABCC_Obj**)(param_1 + 8))->v15(0x30310000, 0x5077, 0x30313031);
    q[0xb0] = 0;
    *(s16*)(param_1 + 0x106) = 1;
    param_1[0x10d] = 0;
}

extern "C" void fn_8043CDA0(u8* self) {
	f32 x;
	f32 y;
	u8 done;
	if (self[0x10c] == 0) {
		x = lbl_80543C88;
		y = lbl_80543CC4;
	} else {
		f32 pane_y = *(f32*)(*(u8**)(self + 0x64) + 0xc);
		x = lbl_80543CC8 - pane_y;
		y = x - lbl_80543CC4;
	}
	done = fn_80402940(*(void**)(self + 0x40), 0xb, x, y, 0);
	for (int i = 1; i < 12; i++) {
		fn_80402940(*(void**)(self + 0x40 + i * 4), 0xb, x, y, 0);
	}
	if (done) {
		u8* game = (u8*)lbl_8053AED0;
		game[0x10a] = 0;
		*(u32*)(game + 0xfc) = 0;
		*(u32*)(game + 0xe8) = 0;
		*(u32*)(game + 0x100) = 0;
		self[0x10b] = 0;
	}
}

extern "C" void fn_8043CEA0(u8* self) {
    *(s16*)(self + 0x104) = *(s16*)(self + 0x104) - 1;
    if (*(s32*)(lbl_8053AAF8 + 0x4c) != 7) {
        *(s16*)(self + 0x104) = 0;
    }
    if (*(s16*)(self + 0x104) > 0) {
        return;
    }
    *(s16*)(*(u8**)(self + 0x40) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x44) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x48) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x4c) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x50) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x54) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x58) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x5c) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x60) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x64) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x68) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x6c) + 0x22) = 0;
    self[0x10b] = 3;
}

extern "C" void fn_8043CF40(u8* self) {
    f32 f31;
    f32 f30;
    u8 r;
    s32 i;
    if (self[0x10c] == 0) {
        f31 = lbl_80543CC4;
        f30 = lbl_80543C88;
    } else {
        f30 = lbl_80543CC8 - *(f32*)(*(u8**)(self + 0x64) + 0xc);
        f31 = f30 - lbl_80543CC4;
    }
    r = fn_80402940(*(void**)(self + 0x40), 0x13, f31, f30, 0);
    for (i = 1; i < 12; i++) {
        fn_80402940(*(void**)(self + 0x40 + i * 4), 0x13, f31, f30, 0);
    }
    if (r) {
        *(s16*)(self + 0x104) = 0xa0;
        self[0x10b] = 2;
    }
}

extern "C" f32 fn_8043D514(u8* param_1) {
    f32 ret = lbl_80543C88;
    if (param_1[0x10b] != 0 && param_1[0x10c] == 1) {
        J2DPane* pane = *(J2DPane**)(*(u8**)(param_1 + 0x64) + 4);
        ret = (lbl_80543CE8 * (lbl_80543CEC - (pane->getBounds()->i.y - lbl_80543CC8))) / lbl_80543CC4;
    }
    return ret;
}

extern "C" f32 fn_8043D57C(u8* param_1) {
    f32 ret = lbl_80543C88;
    if (param_1[0x10b] != 0 && param_1[0x10c] == 0) {
        J2DPane* pane = *(J2DPane**)(*(u8**)(param_1 + 0x40) + 4);
        f32 dy = pane->getBounds()->i.y - *(f32*)(*(u8**)(param_1 + 0x40) + 0xc);
        ret = (lbl_80543CE8 * (lbl_80543CC4 - dy)) / lbl_80543CC4;
    }
    return ret;
}

extern void* lbl_8053AB10;
extern "C" void fn_8013B490(void* p);
extern "C" void fn_8043D5F0(u8* param_1) {
    fn_8013B490(lbl_8053AB10);
    *(u8*)(*(u8**)(param_1 + 4) + 0x100) = 1;
    (*(J2DScreen**)(param_1 + 4))->draw(lbl_80543C88, lbl_80543C88, *(J2DGrafContext**)((u8*)lbl_8053AB10 + 0x10));
}

extern "C" void fn_8043D834(u8* self) {
    if (((u8*)lbl_8053AAF8)[0x7f] != 0) {
        fn_8041E58C(*(void**)(self + 0x290));
    } else {
        fn_80425128(*(void**)(self + 0x294));
    }
}

extern "C" void fn_8043D874(u8* param_1) {
    u8* game = (u8*)lbl_8053AAF8;
    if (game[0x7f] != 0) {
        fn_8041E708(*(void**)(param_1 + 0x290));
    } else {
        fn_80425234(*(void**)(param_1 + 0x294));
    }
}

extern "C" void fn_8043DB58(u8* param_1) {
	struct VObj {
		virtual void v00();
		virtual void v01();
		virtual void v02();
		virtual void v03();
		virtual void v04();
		virtual void v05();
		virtual void v06();
		virtual void v07();
		virtual void v08();
		virtual void v09();
		virtual void v10();
		virtual void v11();
		virtual void v12();
		virtual void v13();
		virtual void v14();
		virtual void v15();
		virtual void v16();
		virtual void v17();
		virtual void v18();
		virtual void v19();
		virtual void v20();
		virtual void v21();
		virtual void v22();
		virtual void v23();
		virtual void v24();
		virtual void v25();
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
		virtual void v36();
		virtual void v37();
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
		virtual void v48();
		virtual void v49();
		virtual void v50();
		virtual void v51();
		virtual void v52();
		virtual void v53();
		virtual void v54();
		virtual void v55(s32 a, f32 b, s32 c, f32 d, s32 e);
	};
	fn_8013B490(lbl_8053AB10);
	if (param_1[0x256] != 0xff) {
		switch (param_1[0x256]) {
		case 0:
			((VObj*)*(void**)(param_1 + 0x14))->v55(0, lbl_80543CF0, 0, lbl_80543CF4, 0);
			break;
		case 1:
			((VObj*)*(void**)(param_1 + 0x18))->v55(0, lbl_80543CF0, 0, lbl_80543CF4, 0);
			break;
		case 2:
			((VObj*)*(void**)(param_1 + 0x1c))->v55(0, lbl_80543CF0, 0, lbl_80543CF4, 0);
			break;
		case 3:
			((VObj*)*(void**)(param_1 + 0x20))->v55(0, lbl_80543CF0, 0, lbl_80543CF4, 0);
			break;
		case 4:
			((VObj*)*(void**)(param_1 + 0x24))->v55(0, lbl_80543CF0, 0, lbl_80543CF4, 0);
			break;
		}
	}
}

extern "C" s32 fn_8043DF24(f32 x, f32 y, f32 px, f32 py, f32 r) {
    f32 a = lbl_80543CFC;
    f32 b = lbl_80543CF8;
    f32 dx = x - a;
    f32 dy = y - b;
    f32 sx = a + x;
    f32 left = dx - r;
    f32 sy = b + y;
    f32 bottom = dy - r;
    f32 right = r + sx;
    f32 top = r + sy;
    if (px >= left && px <= right && py >= bottom && py <= top) {
        return 0;
    }
    return 1;
}

extern "C" void fn_8043EDE8(char* param_1, s32 param_2) {
    *(s32*)(param_1 + 0xe0) = param_2;
    *(s32*)(param_1 + 0xe4) = 0x1e;
}

extern "C" void fn_8043EDF8(u8* param_1) {
    param_1[0xdd] = 0;
    param_1[0xdc] = 0;
    param_1[0x255] = 0;
    if (((u8*)lbl_8053AAF8)[0x7f] != 0) {
        fn_8041FC2C(*(void**)(param_1 + 0x290));
        if (*(u32*)(param_1 + 0x2b0) != 0) {
            fn_8044A06C(*(void**)(param_1 + 0x2b0));
        }
        if (*(u32*)(param_1 + 0x29c) != 0) {
            fn_80445D24(*(void**)(param_1 + 0x29c));
        }
        if (*(u32*)(param_1 + 0x2a8) != 0) {
            fn_80448334(*(void**)(param_1 + 0x2a8));
        }
        if (*(u32*)(param_1 + 0x2b4) != 0) {
            fn_8044AFD8(*(void**)(param_1 + 0x2b4));
        }
        if (*(u32*)(param_1 + 0x2ac) != 0) {
            fn_804490B8(*(void**)(param_1 + 0x2ac));
        }
        if (*(u32*)(param_1 + 0x2a4) != 0) {
            fn_804479A0(*(void**)(param_1 + 0x2a4));
        }
        if (*(u32*)(param_1 + 0x2a0) != 0) {
            fn_80446DB0(*(void**)(param_1 + 0x2a0));
        }
    } else {
        fn_804263A8(*(void**)(param_1 + 0x294));
    }
    if (*(u32*)(param_1 + 0x298) != 0) {
        fn_80443688(lbl_8053AEF0);
    }
}

extern "C" void fn_804408F0(JGeometry::TVec3<f32>* self) {
    JGeometry::TVec3<f32> v;
    v.x = self->x;
    v.y = self->y;
    v.z = self->z;
    fn_8043E7CC(lbl_8053AED0, &v);
}

extern "C" void* fn_80440928(void) { return fn_8043DF8C(lbl_8053AED0); }
