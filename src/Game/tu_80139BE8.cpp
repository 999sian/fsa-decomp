#include "types.h"
#include "Game/SinitPoolChain.h"

extern unsigned char* lbl_8053AAF8;
extern unsigned char lbl_80529DEC[];
extern void* lbl_8053AC98;
extern "C" void fn_80136500(void*);
extern "C" void fn_8023F390(void);
extern "C" void fn_801914C4(void*);
extern "C" void fn_8016DE30(void*);
extern "C" void fn_801F871C(void*);
extern "C" void fn_80190DC8(void*);
extern "C" void fn_8016DCEC(void*);
extern "C" void fn_802A3A0C(void*);
extern "C" void fn_8038D570(void);
extern "C" void fn_80136364(void*);
extern "C" void fn_8044B960(void*);
extern "C" void fn_80118E20(void);
extern "C" void* fn_80236100(s32);
extern "C" void* fn_80237774(s32);
extern "C" void* fn_80235A30(s32);
extern "C" void* fn_8023587C(s32);
extern "C" void* fn_80235ACC(s32);

static inline bool isStateLocked() {
    bool locked;
    if (lbl_8053AAF8[0x7f] != 0 && *(s32*)(lbl_80529DEC + 0x118) == 9 && *(s32*)(lbl_80529DEC + 0x11c) == 3) {
        locked = true;
    } else {
        locked = false;
    }
    return locked;
}

static inline void setStateWord(s32 off, void* v) {
    if (!isStateLocked()) {
        *(void**)(lbl_80529DEC + off) = v;
    }
}

static inline void setStateByte(s32 off, u8 v) {
    if (!isStateLocked()) {
        lbl_80529DEC[off] = v;
    }
}

static inline void setUpdateWord(s32 off, void* value, unsigned char* player, unsigned char* base) {
    bool locked;
    if (player[0x7f] != 0 && *(s32*)(base + 0x118) == 9 && *(s32*)(base + 0x11c) == 3) locked = true;
    else locked = false;
    if (!locked) *(void**)(lbl_80529DEC + off) = value;
}
static inline void setUpdateByte(s32 off, u8 value, unsigned char* player, unsigned char* base) {
    bool locked;
    if (player[0x7f] != 0 && *(s32*)(base + 0x118) == 9 && *(s32*)(base + 0x11c) == 3) locked = true;
    else locked = false;
    if (!locked) lbl_80529DEC[off] = value;
}

struct VObj2 {
        virtual void v00();
        virtual void v04();
        virtual void v08();
        virtual void v0C();
        virtual void v10();
    };

struct ManagerDtorObj {
    virtual void v08(int);
    virtual void v0C();
};

class VObj {
public:
    virtual void v00();
    virtual void v0C();
};

extern "C" void fn_8043D644(void*);
extern "C" void fn_8043D8B4(void*);
extern "C" void fn_8016DB60(void*);
extern void* lbl_8053AED0;
extern unsigned char* lbl_8053AB10;
extern "C" void fn_801F857C(void*);
extern "C" void fn_8030361C(void);
extern "C" void fn_8038D454(void);
extern "C" void* fn_8011921C(void);
extern "C" void fn_801184F0(void*, int);
extern unsigned char lbl_8053ACD0;
extern "C" void fn_80139BE8(unsigned char* p) {
    fn_801F857C(*(void**)(p + 8));
    lbl_8053ACD0 = 0;
    fn_8030361C();
    fn_8038D454();
    fn_801184F0(fn_8011921C(), 1);
    (*(unsigned char**)(lbl_8053AB10 + 0x20))[0x235c] = 0;
    (*(unsigned char**)(lbl_8053AB10 + 0x20))[0x235d] = 0;
    (*(unsigned char**)(lbl_8053AB10 + 0x20))[0x235e] = 0;
    (*(unsigned char**)(lbl_8053AB10 + 0x20))[0x235f] = 0;
}

extern "C" void fn_8043D5F0(void*);
extern "C" void fn_8038D4A8(void);
extern "C" void fn_8043DC98(void*);
extern "C" void fn_8044B8EC(void*);
extern "C" void fn_8013B438(void*);
extern "C" void fn_8023F2BC(void);
extern "C" void fn_801F8658(void*);
extern "C" void fn_801902D0(void*);
extern "C" void fn_8016DA6C(void*);
extern "C" void fn_80139C5C(void) {
    fn_8043D5F0(lbl_8053AED0);
    fn_8038D4A8();
}

extern "C" void fn_80139C84(unsigned char* p) {
    fn_8043DC98(lbl_8053AED0);
    if (*(void**)(p + 0x2c) != 0) {
        fn_8044B8EC(*(void**)(p + 0x2c));
    }
}

extern "C" void fn_80139CC4(unsigned char* p) {
    struct VObj { virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C(); };
    fn_8013B438(lbl_8053AB10);
    (*(VObj**)(p + 0xc))->v0C();
    fn_8013B438(lbl_8053AB10);
    fn_8023F2BC();
    fn_801F8658(*(void**)(p + 8));
    fn_801902D0(*(void**)(p + 0x20));
    if (lbl_8053AB10[0x39] == 0) {
        fn_8016DA6C(*(void**)(p + 0x24));
    }
}

extern "C" void fn_80139D3C(unsigned char* p) {
    if (lbl_8053AB10[0x39] == 0) {
        fn_8016DB60(*(void**)(p + 0x24));
    }
}

extern "C" void fn_80139D70(void) {
    fn_8043D644(lbl_8053AED0);
    fn_8043D8B4(lbl_8053AED0);
}

extern "C" void fn_80139D9C(unsigned char* p) {
    bool bVar1;
    s32 iVar3 = *(s32*)(lbl_8053AAF8 + 0x4c);
    if (iVar3 != 7 || *(s32*)(lbl_8053AAF8 + 0x60) < 4) {
        if (*(s32*)(lbl_8053AAF8 + 0x4c) == 0xb) {
            bVar1 = true;
        } else {
            bVar1 = lbl_8053AAF8[0x88] == 2;
        }
        if (!bVar1 && (lbl_8053AAF8[0x7f] != 0 || (iVar3 != 0xa && iVar3 != 0xc))) {
            goto SKIP;
        }
    }
    fn_80136500(lbl_8053AAF8);
    ((VObj2*)*(void**)(p + 0xc))->v08();
    fn_8023F390();
    fn_801914C4(*(void**)(p + 0x20));
    fn_8016DE30(*(void**)(p + 0x24));
    fn_801F871C(*(void**)(p + 8));
    fn_80190DC8(*(void**)(p + 0x20));
    fn_8016DCEC(*(void**)(p + 0x24));
    fn_802A3A0C(lbl_8053AC98);
    fn_8038D570();
    fn_80136364(lbl_8053AAF8);
    if (*(void**)(p + 0x2c) != 0) {
        fn_8044B960(*(void**)(p + 0x2c));
    }
    goto END;
SKIP:
    fn_8023F390();
    fn_802A3A0C(lbl_8053AC98);
END:
    fn_8011921C();
    fn_80118E20();
    *(s32*)(p + 0x34) += 1;
    unsigned char* base = lbl_80529DEC;
    unsigned char* q = lbl_80529DEC;
    for (s32 i = 0; i < 4; i++) {
        void* r = fn_80236100(i);
        if (lbl_8053AAF8[0x7f] != 0 && *(s32*)(base + 0x118) == 9 && *(s32*)(base + 0x11c) == 3) {
            bVar1 = true;
        } else {
            bVar1 = false;
        }
        if (!bVar1) {
            *(void**)(q + 0x150) = r;
        }
        r = fn_80237774(i);
        if (lbl_8053AAF8[0x7f] != 0 && *(s32*)(base + 0x118) == 9 && *(s32*)(base + 0x11c) == 3) {
            bVar1 = true;
        } else {
            bVar1 = false;
        }
        if (!bVar1) {
            *(void**)(q + 0x160) = r;
        }
        r = fn_80235A30(i);
        if (lbl_8053AAF8[0x7f] != 0 && *(s32*)(base + 0x118) == 9 && *(s32*)(base + 0x11c) == 3) {
            bVar1 = true;
        } else {
            bVar1 = false;
        }
        if (!bVar1) {
            *(void**)(q + 0x170) = r;
        }
        r = fn_8023587C(i);
        if (lbl_8053AAF8[0x7f] != 0 && *(s32*)(base + 0x118) == 9 && *(s32*)(base + 0x11c) == 3) {
            bVar1 = true;
        } else {
            bVar1 = false;
        }
        if (!bVar1) {
            *(void**)(q + 0x180) = r;
        }
        r = fn_80235ACC(i);
        if (lbl_8053AAF8[0x7f] != 0 && *(s32*)(base + 0x118) == 9 && *(s32*)(base + 0x11c) == 3) {
            bVar1 = true;
        } else {
            bVar1 = false;
        }
        if (!bVar1) {
            *(void**)(q + 0x190) = r;
        }
        q += 4;
    }
    unsigned char* pl = lbl_8053AAF8;
    setUpdateWord(0x1b0, *(void**)(pl + 0xf8), pl, base);
    setUpdateByte(0x214, pl[0xfc], pl, base);
    if ((lbl_80529DEC[0x24a] & 1) == 0 && (lbl_80529DEC[0x24a] & 2) == 0 && (lbl_80529DEC[0x24a] & 4) == 0 && (lbl_80529DEC[0x24a] & 8) == 0) {
        setUpdateByte(0x215, 1, pl, base);
    } else {
        setUpdateByte(0x215, 0, pl, base);
    }
}

extern "C" void fn_8016EDB0(void*);
extern "C" void fn_801F8E4C(void*);
extern "C" void fn_8023F088(void);
extern "C" void fn_8023F78C(void);
extern "C" void fn_8023F728(void);
extern "C" void fn_802A3D80(void*);
extern "C" void fn_8043EDF8(void*);
extern "C" void fn_80439AB0(void*);
extern "C" void fn_8037AFC0(void*);
extern "C" void fn_8019169C(void*);
extern "C" void fn_8038D870(void);
extern "C" unsigned char fn_803B8C90(void);
extern unsigned char* lbl_8053AAF8;
extern unsigned char lbl_80529DEC[];
extern "C" void fn_8013A1A4(unsigned char* p) {
    fn_8016EDB0(*(void**)(p + 0x24));
    fn_801F8E4C(*(void**)(p + 8));
    ((VObj*)*(void**)(p + 0xc))->v0C();
    if (lbl_8053AAF8[0x7e] == 1) {
        fn_8023F088();
    }
    fn_8023F78C();
    fn_8023F728();
    lbl_8053ACD0 = 1;
    fn_802A3D80(*(void**)(p + 0x10));
    fn_8043EDF8(*(void**)(p + 0x14));
    fn_80439AB0(*(void**)(p + 0x18));
    fn_8037AFC0(*(void**)(p + 0x1c));
    fn_8019169C(*(void**)(p + 0x20));
    fn_8038D870();
    *(void**)(p + 0x34) = 0;
    lbl_80529DEC[0x240] = 0;
    *(short*)(lbl_80529DEC + 0x1f4) = 0;
    *(short*)(lbl_80529DEC + 0x1f6) = 0;
    *(short*)(lbl_80529DEC + 0x1f8) = 0;
    *(short*)(lbl_80529DEC + 0x1fa) = 0;
    lbl_80529DEC[0x24f] = fn_803B8C90();
    lbl_80529DEC[0x253] = 0;
}

extern unsigned char lbl_8049F080[];
extern void* lbl_8053AB00;
extern s32 lbl_8053AB04;
extern s8 lbl_8053AB08;
extern "C" void fn_8013A884(const unsigned char* src);
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteAllEmitter__17JPAEmitterManagerFv(void*);
extern "C" void fn_8016EE84(void*, int);
extern "C" void fn_80191744(void*, int);
extern "C" void freeAll__7JKRHeapFv(void*);
extern "C" void destroy__7JKRHeapFv(void*);
extern "C" s32 getTotalFreeSize__7JKRHeapFv(void*);
extern "C" s32 getFreeSize__7JKRHeapFv(void*);
extern "C" void* becomeCurrentHeap__7JKRHeapFv(void*);
extern "C" void* __nw__FUlP7JKRHeapi(u32, JKRHeap*, int);
extern "C" void* create__10JKRExpHeapFUlP7JKRHeapb(u32, JKRHeap*, bool);
extern "C" void* fn_802DE64C(void*);
extern "C" void* __ct__9PlayerMgrFv(void*);
extern "C" void* fn_801F9078(void*, JKRHeap*);
extern "C" void* fn_802A3E2C(void*);
extern "C" void* fn_8043F504(void*);
extern "C" void* fn_80439C78(void*);
extern "C" void* fn_8037B0B8(void*);
extern "C" void* fn_801917E0(void*, JKRHeap*);
extern "C" void* fn_8016F0BC(void*, JKRHeap*);
extern "C" void* fn_8044BDCC(void*);
extern "C" void OSReport(const char*, ...);
extern char lbl_80465920[];
extern char lbl_80465960[];
extern "C" void __dl__FPv(void* this_);
#pragma opt_propagation off
extern "C" void* fn_8013A27C(unsigned char* this_, s16 how) {

	if (this_ != 0) {
		*(void**)this_ = lbl_8049F080;
		s32 buf = -0x100;
		fn_8013A884((const unsigned char*)&buf);

		void* mgr = fn_8013C824();
		forceDeleteAllEmitter__17JPAEmitterManagerFv(*(void**)((char*)mgr + 0xc));

		if (((u8*)lbl_80529DEC)[0x24b] != 0) {
			((u8*)lbl_80529DEC)[0x24b] = 0;
		}

		if (*(void**)(this_ + 0x2c) != 0) {
			if (*(void**)(this_ + 0x2c) != 0) {
				((ManagerDtorObj*)*(void**)(this_ + 0x2c))->v08(1);
			}
			*(void**)(this_ + 0x2c) = 0;
		}

		if (*(void**)(this_ + 0x30) != 0) {
			freeAll__7JKRHeapFv(*(void**)(this_ + 0x30));
			destroy__7JKRHeapFv(*(void**)(this_ + 0x30));
		}

		getTotalFreeSize__7JKRHeapFv(lbl_8053AB00);
		fn_8016EE84(*(void**)(this_ + 0x24), 1);
		*(void**)(this_ + 0x24) = 0;

		getTotalFreeSize__7JKRHeapFv(lbl_8053AB00);
		fn_80191744(*(void**)(this_ + 0x20), 1);
		*(void**)(this_ + 0x20) = 0;

		getTotalFreeSize__7JKRHeapFv(lbl_8053AB00);
		if (*(void**)(this_ + 0x1c) != 0) {
			((ManagerDtorObj*)*(void**)(this_ + 0x1c))->v08(1);
		}
		*(void**)(this_ + 0x1c) = 0;

		getTotalFreeSize__7JKRHeapFv(lbl_8053AB00);
		if (*(void**)(this_ + 0x18) != 0) {
			((ManagerDtorObj*)*(void**)(this_ + 0x18))->v08(1);
		}
		*(void**)(this_ + 0x18) = 0;

		getTotalFreeSize__7JKRHeapFv(lbl_8053AB00);
		if (*(void**)(this_ + 0x14) != 0) {
			((ManagerDtorObj*)*(void**)(this_ + 0x14))->v08(1);
		}
		*(void**)(this_ + 0x14) = 0;

		getTotalFreeSize__7JKRHeapFv(lbl_8053AB00);
		if (*(void**)(this_ + 0x10) != 0) {
			((ManagerDtorObj*)*(void**)(this_ + 0x10))->v08(1);
		}
		*(void**)(this_ + 0x10) = 0;

		getTotalFreeSize__7JKRHeapFv(lbl_8053AB00);
		if (*(void**)(this_ + 0x8) != 0) {
			((ManagerDtorObj*)*(void**)(this_ + 0x8))->v08(1);
		}
		*(void**)(this_ + 0x8) = 0;

		getTotalFreeSize__7JKRHeapFv(lbl_8053AB00);
		if (*(void**)(this_ + 0x4) != 0) {
			((ManagerDtorObj*)*(void**)(this_ + 0x4))->v08(1);
		}
		*(void**)(this_ + 0x4) = 0;

		getTotalFreeSize__7JKRHeapFv(lbl_8053AB00);
		if (*(void**)(this_ + 0xc) != 0) {
			((ManagerDtorObj*)*(void**)(this_ + 0xc))->v08(1);
		}
		*(void**)(this_ + 0xc) = 0;

		u8* g = (u8*)lbl_80529DEC;
		if (*(void**)(g + 0x10) != 0) {
			((ManagerDtorObj*)*(void**)(g + 0x10))->v0C();
			*(void**)(g + 0x10) = 0;
		}

		g = (u8*)lbl_80529DEC;
		if (*(void**)(g + 0x4c) != 0) {
			((ManagerDtorObj*)*(void**)(g + 0x4c))->v0C();
			*(void**)(g + 0x4c) = 0;
		}

		if (how > 0) {
			__dl__FPv(this_);
		}
	}
	return this_;
}
#pragma opt_propagation reset
extern "C" void* fn_8013A538(u8* p, JKRHeap* heap) {
    *(void**)p = lbl_8049F080;
    lbl_8053AB00 = heap;
    getTotalFreeSize__7JKRHeapFv(heap);
    {
        void* obj = __nw__FUlP7JKRHeapi(78480, heap, 0);
        if (obj) obj = fn_802DE64C(obj);
        *(void**)(p + 12) = obj;
    }
    getTotalFreeSize__7JKRHeapFv(heap);
    {
        void* obj = __nw__FUlP7JKRHeapi(116, heap, 0);
        if (obj) obj = __ct__9PlayerMgrFv(obj);
        *(void**)(p + 4) = obj;
    }
    getTotalFreeSize__7JKRHeapFv(heap);
    {
        void* obj = __nw__FUlP7JKRHeapi(12384, heap, 0);
        if (obj) obj = fn_801F9078(obj, heap);
        *(void**)(p + 8) = obj;
    }
    getTotalFreeSize__7JKRHeapFv(heap);
    {
        void* obj = __nw__FUlP7JKRHeapi(40, heap, 0);
        if (obj) obj = fn_802A3E2C(obj);
        *(void**)(p + 16) = obj;
    }
    getTotalFreeSize__7JKRHeapFv(heap);
    getTotalFreeSize__7JKRHeapFv(heap);
    {
        void* obj = __nw__FUlP7JKRHeapi(704, heap, 0);
        if (obj) obj = fn_8043F504(obj);
        *(void**)(p + 20) = obj;
    }
    getTotalFreeSize__7JKRHeapFv(heap);
    {
        void* obj = __nw__FUlP7JKRHeapi(96, heap, 0);
        if (obj) obj = fn_80439C78(obj);
        *(void**)(p + 24) = obj;
    }
    getTotalFreeSize__7JKRHeapFv(heap);
    {
        void* obj = __nw__FUlP7JKRHeapi(16, heap, 0);
        if (obj) obj = fn_8037B0B8(obj);
        *(void**)(p + 28) = obj;
    }
    getTotalFreeSize__7JKRHeapFv(heap);
    {
        void* obj = __nw__FUlP7JKRHeapi(2032, heap, 0);
        if (obj) obj = fn_801917E0(obj, heap);
        *(void**)(p + 32) = obj;
    }
    getTotalFreeSize__7JKRHeapFv(heap);
    {
        void* obj = __nw__FUlP7JKRHeapi(504, heap, 0);
        if (obj) obj = fn_8016F0BC(obj, heap);
        *(void**)(p + 36) = obj;
    }
    if ((*(s32*)(lbl_80529DEC + 0x118) == 9 && *(s32*)(lbl_80529DEC + 0x11c) == 3) ||
        (*(s32*)(lbl_80529DEC + 0x118) == 8 && *(s32*)(lbl_80529DEC + 0x11c) == 2)) {
        *(void**)(p + 0x30) = create__10JKRExpHeapFUlP7JKRHeapb(0x86470, heap, false);
        if (*(void**)(p + 0x30) == 0) {
            if (lbl_8053AB08 == 0) {
                lbl_8053AB04 = 0;
                lbl_8053AB08 = 1;
            }
            if (lbl_8053AB04 == 0) {
                lbl_8053AB04 = 1;
                f32 total = (f32)getTotalFreeSize__7JKRHeapFv(heap) / 1024.0f;
                OSReport(lbl_80465920, 585.9375, (f32)getFreeSize__7JKRHeapFv(heap) / 1024.0f, total);
            }
        } else {
            OSReport(lbl_80465960);
        }
        becomeCurrentHeap__7JKRHeapFv(heap);
        void* obj = __nw__FUlP7JKRHeapi(0x18, heap, 0);
        if (obj) obj = fn_8044BDCC(obj);
        *(void**)(p + 0x2c) = obj;
    } else {
        *(void**)(p + 0x30) = 0;
        *(void**)(p + 0x2c) = 0;
    }
    return p;
}

extern "C" void fn_8013A884(const unsigned char* src) {
    unsigned char* dst = *(unsigned char**)(lbl_8053AB10 + 0x2c);
    dst[4] = src[0];
    dst[5] = src[1];
    dst[6] = src[2];
    dst[7] = src[3];
}

