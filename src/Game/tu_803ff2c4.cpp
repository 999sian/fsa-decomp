// TU 0x803ff2c4-0x80400dc4.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"
#include "JSystem/J2D/J2DGrafContext.h"

struct _GXRenderModeObj;
extern "C" u32 OSGetProgressiveMode();
extern "C" u8 lbl_8048C17C[];
extern "C" u8 lbl_8048C1B8[];
extern "C" u8* sManager__8JUTVideo;
extern "C" u8* sManager__10JFWDisplay;
extern "C" void setRenderMode__8JUTVideoFPC16_GXRenderModeObj(void* self, const _GXRenderModeObj* mode);

#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/J2D/J2DPicture.h"
#include "JSystem/JFramework/JFWDisplay.h"


// ---- from src/Game/fn_804007C4.cpp ----
// vtable slot 2 (byte offset 8) - see [[reference_fsa_virtual_dispatch_codegen_trick]].
struct DtorSlot2 {
	virtual void destroy(s32 freeFlag);
};

// manager sub-object with 2 virtual slots (dummy v0 at offset 8, real
// slot1 at offset 0xc) - same shape as fn_803A87A8's SlotB.
struct SlotB {
	virtual void v0();
	virtual void slot1();
};

extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B0F50[];
extern u8 lbl_80529DEC[];

static inline void DispatchSlot2(char* slot) {
	DtorSlot2* obj = *(DtorSlot2**)slot;
	if (obj != 0) {
		obj->destroy(1);
	}
	*(void**)slot = 0;
}

// SafeDestroy(obj) - own internal null check. RESOLVES a pattern
// previously filed as an unfixable "redundant-branch-preservation"
// wall (see extab_8013a27c.s's banner): retail's bytes for each of the
// 7 array slots below show an OUTER caller-side null check wrapping a
// call whose callee does its OWN (inlined) null check again - a
// genuine, readable 2-layer safety idiom, not a compiler peephole
// artifact. Getting the doubled `beq` requires BOTH (1) this small
// static-inline wrapper with its own `if (obj)` guard, called from an
// already-guarded call site, AND (2) each of the 7 slots written out as
// a LITERAL repeated block (a real `for` loop over the array compiles
// to an actual small loop here, NOT unrolled - confirmed by a failed
// first attempt that produced a 0x10C-byte function instead of
// retail's 0x208; retail's own bytes show no back-branch at all, i.e.
// the original source itself did not use a loop for this array).
static inline void SafeDestroy(void* obj) {
	if (obj != 0) {
		((DtorSlot2*)obj)->destroy(1);
	}
}

// fn_803FF2C4 - releases the 7 sub-objects at 0x18-0x30.
extern "C" void fn_803FF2C4(void* this_) {
	char* p = (char*)this_;
	{
		void* obj = *(void**)(p + 0x18);
		if (obj != 0) {
			SafeDestroy(obj);
			*(void**)(p + 0x18) = 0;
		}
	}
	{
		void* obj = *(void**)(p + 0x1c);
		if (obj != 0) {
			SafeDestroy(obj);
			*(void**)(p + 0x1c) = 0;
		}
	}
	{
		void* obj = *(void**)(p + 0x20);
		if (obj != 0) {
			SafeDestroy(obj);
			*(void**)(p + 0x20) = 0;
		}
	}
	{
		void* obj = *(void**)(p + 0x24);
		if (obj != 0) {
			SafeDestroy(obj);
			*(void**)(p + 0x24) = 0;
		}
	}
	{
		void* obj = *(void**)(p + 0x28);
		if (obj != 0) {
			SafeDestroy(obj);
			*(void**)(p + 0x28) = 0;
		}
	}
	{
		void* obj = *(void**)(p + 0x2c);
		if (obj != 0) {
			SafeDestroy(obj);
			*(void**)(p + 0x2c) = 0;
		}
	}
	{
		void* obj = *(void**)(p + 0x30);
		if (obj != 0) {
			SafeDestroy(obj);
			*(void**)(p + 0x30) = 0;
		}
	}
}

extern "C" void fn_803FF420(void* this_) {
	u8* p = (u8*)this_;
	if (p[0x79] > 1) {
		if (!((lbl_80529DEC[0x21a] == 0xa7) || (lbl_80529DEC[0x21b] == 0xa5)) || p[0x7a] != 0) {
			J2DOrthoGraph ortho(0.0f, 0.0f, (f32)(int)JUTVideo::getManager()->getFbWidth(), (f32)(int)JUTVideo::getManager()->getEfbHeight(), -1.0f, 1.0f);
			JFWDisplay::getManager()->setClearColor(JUtility::TColor(0, 0, 0, 0));
			ortho.setPort();
			J2DPane* o = ((J2DScreen*)*(void**)(p + 0x18))->search(0x4e494e5f4c6f676fULL);
            o->setAlpha(*(f32*)(p + 0x64));
			((J2DScreen*)*(void**)(p + 0x18))->draw(0.0f, 0.0f, &ortho);
			switch (lbl_80529DEC[0x238]) {
			case 2:
			case 3:
			case 4: {
				(*(J2DPicture**)(p + 0x1c))->setAlpha(*(f32*)(p + 0x68));
				(*(J2DPicture**)(p + 0x1c))->draw(113.0f, 281.0f, false, false, false);
				s16 sv = *(s16*)(p + 0x70);
				f32 t = (sv < 30) ? ((f32)sv / 30.0f) : ((60.0f - (f32)sv) / 30.0f);
				s32 r30 = (s32)(255.0f * t);
				s32 r29 = (s32)(200.0f * t);
                if (p[0x76] == 0) {
                    (*(J2DPicture**)(p + 0x28))->setBlackWhite(JUtility::TColor((u8)r30,(u8)r29,0,0), JUtility::TColor(255,200,0,255));
                    (*(J2DPicture**)(p + 0x2c))->setBlackWhite(JUtility::TColor(0,0,0,0), JUtility::TColor(160,160,160,255));
                } else {
                    (*(J2DPicture**)(p + 0x28))->setBlackWhite(JUtility::TColor(0,0,0,0), JUtility::TColor(160,160,160,255));
                    (*(J2DPicture**)(p + 0x2c))->setBlackWhite(JUtility::TColor((u8)r30,(u8)r29,0,0), JUtility::TColor(255,200,0,255));
                }
                (*(J2DPicture**)(p + 0x28))->setAlpha(*(f32*)(p + 0x68));
				(*(J2DPicture**)(p + 0x28))->draw(211.0f, 372.0f, false, false, false);
				(*(J2DPicture**)(p + 0x2c))->setAlpha(*(f32*)(p + 0x68));
				(*(J2DPicture**)(p + 0x2c))->draw(350.0f, 372.0f, false, false, false);
				goto endDraw;
			}
            case 5:
            case 6:
                setRenderMode__8JUTVideoFPC16_GXRenderModeObj(sManager__8JUTVideo, (const _GXRenderModeObj*)lbl_8048C1B8);
                lbl_80529DEC[0x251] = 1;
                goto endDraw;
            case 9:
                if (OSGetProgressiveMode() == 0) {
                    setRenderMode__8JUTVideoFPC16_GXRenderModeObj(sManager__8JUTVideo, (const _GXRenderModeObj*)lbl_8048C17C);
                }
                break;
            case 10:
            case 11:
                break;
			default:
				goto endDraw;
			}
			if (p[0x76] == 0) {
				(*(J2DPicture**)(p + 0x24))->setAlpha(*(f32*)(p + 0x68));
				(*(J2DPicture**)(p + 0x24))->draw(153.0f, 309.0f, false, false, false);
			} else {
				(*(J2DPicture**)(p + 0x20))->setAlpha(*(f32*)(p + 0x68));
				(*(J2DPicture**)(p + 0x20))->draw(153.0f, 309.0f, false, false, false);
			}
endDraw:
            ;
		} else {
			J2DOrthoGraph ortho(0.0f, 0.0f, (f32)(int)JUTVideo::getManager()->getFbWidth(), (f32)(int)JUTVideo::getManager()->getEfbHeight(), -1.0f, 1.0f);
			JFWDisplay::getManager()->setClearColor(JUtility::TColor(0, 0, 0, 0));
			ortho.setPort();
            (*(J2DPicture**)(p + 0x30))->draw(105.0f,78.0f,400.0f,240.0f,false,false,false);
			lbl_80529DEC[0x225] = 1;
		}
	}
}

// fn_804007C4 - actor@lbl_804B0F50: destructor (0x208). Unconditionally
// dispatches through a global manager sub-object first
// (lbl_80529DEC->0x18's own vtable, slot1() at offset 0xc, no arg - the
// SlotB shape), then tears down 2 plain singles (0xc/0x14, standard
// vtable-slot-2 dispatch with an unconditional clear), then a 7-element
// array (0x18-0x30, stride 4) each guarded by an OUTER null check (only
// cleared if non-null) wrapping a call to SafeDestroy() (which redoes
// its own null check internally - the source of the doubled `beq`).
// Finishes by unconditionally clearing boot-config->0x225, then the
// standard "> 0 means also deallocate" conditional chain to
// __dl__FPv.
extern "C" void* fn_804007C4(void* this_, s16 how) {
	if (this_ != 0) {
		*(void**)this_ = lbl_804B0F50;

		void* mgr = *(void**)(lbl_80529DEC + 0x18);
		((SlotB*)mgr)->slot1();

		char* p = (char*)this_;

		DispatchSlot2(p + 0xc);
		DispatchSlot2(p + 0x14);

		{
			void* obj = *(void**)(p + 0x18);
			if (obj != 0) {
				SafeDestroy(obj);
				*(void**)(p + 0x18) = 0;
			}
		}
		{
			void* obj = *(void**)(p + 0x1c);
			if (obj != 0) {
				SafeDestroy(obj);
				*(void**)(p + 0x1c) = 0;
			}
		}
		{
			void* obj = *(void**)(p + 0x20);
			if (obj != 0) {
				SafeDestroy(obj);
				*(void**)(p + 0x20) = 0;
			}
		}
		{
			void* obj = *(void**)(p + 0x24);
			if (obj != 0) {
				SafeDestroy(obj);
				*(void**)(p + 0x24) = 0;
			}
		}
		{
			void* obj = *(void**)(p + 0x28);
			if (obj != 0) {
				SafeDestroy(obj);
				*(void**)(p + 0x28) = 0;
			}
		}
		{
			void* obj = *(void**)(p + 0x2c);
			if (obj != 0) {
				SafeDestroy(obj);
				*(void**)(p + 0x2c) = 0;
			}
		}
		{
			void* obj = *(void**)(p + 0x30);
			if (obj != 0) {
				SafeDestroy(obj);
				*(void**)(p + 0x30) = 0;
			}
		}

		lbl_80529DEC[0x225] = 0;
		if (how > 0) {
			__dl__FPv(this_);
		}
	}
	return this_;
}


struct _GXRenderModeObj;
class J2DPrint {
public:
	static void* setBuffer(u32 size);
};

extern "C" u32 OSGetResetCode();
extern "C" u32 VIGetDTVStatus();
extern "C" void OSSetProgressiveMode(u32 on);
extern "C" u8 lbl_8048C17C[];
extern "C" void fn_802B1EFC(void* p);
extern "C" void fn_804429B4(void* p);
extern "C" void fn_802B1EB0(void* p);
extern "C" void fn_802B1DE8(void* p);
extern "C" void* fn_80401E10(void* a, s32 b, u32 c);
extern "C" void fn_80139994();
extern u8 lbl_80479C34[];
extern void* lbl_8053ACA8;
extern void* lbl_8053AAF0;
extern void (*lbl_8053A93C)();
extern s32 lbl_8053A940;
extern u8 lbl_8053A951;

struct SubA {
	SubA() { fn_802B1EFC(this); }
	u8 pad[8];
};
struct SubB {
	SubB() { fn_804429B4(this); }
	u8 pad[8];
};

struct BootLoad {
    u8 pad0[4];
    u8 ready;
    u8 pad5[3];
    DtorSlot2 dtor;
    u8 padC[8];
    void* resource;
};
extern "C" void fn_803007D0();
extern "C" void fn_8030AC4C(void*);
extern "C" void fn_8030905C(void*);
extern "C" void fn_8030AB38(void*);
extern "C" void fn_80308E90(void*);
extern "C" bool fn_802B1DCC(void*);
extern "C" void fn_802B1BE0(void*,int,int,int);
extern "C" void fn_80442810(void*);
extern "C" void fn_8030A43C(void*);
extern "C" void fn_80304FB0(void*);
extern "C" bool fn_804580DC(void*,int);
extern "C" void* fn_80401BA4(void*,int,int,u32);
extern "C" const ResTIMG* fn_80403244(u32,const char*);
extern "C" u32 SIProbe(s32);
extern "C" u32 fn_8030AAF4(int);
extern "C" u32 fn_80309D24(void*,u32,u32);
extern "C" u32 fn_80309D6C(void*,u32,u32);
extern "C" void fn_803B9B3C(void*);
extern "C" int fn_803B9A24(void*);
extern "C" void OSReport(const char*,...);
extern u8 lbl_80479AC0[];
extern u8 lbl_8051C1A0[];
extern void* lbl_8053AD30;

// fn_804009CC - constructor of the game object at lbl_804B0F50.
extern "C" void* fn_804009CC(void* this_) {
	u8* p = (u8*)this_;
	u8* cfg = lbl_80529DEC;
	lbl_8053AAF0 = p;
	*(void**)this_ = lbl_804B0F50;
	if (cfg[0x223] == 1) {
		p[0x7a] = 1;
		cfg[0x223] = 0;
	} else {
		p[0x7a] = 0;
	}
	if (lbl_80529DEC[0x224] == 1) {
		if (lbl_80529DEC[0x225] != 1) {
			p[0x7a] = 1;
		}
		lbl_80529DEC[0x224] = 0;
	}
	J2DPrint::setBuffer(0x400);
	if (OSGetResetCode() == 0 || p[0x7a] != 0) {
		if (VIGetDTVStatus() == 0) {
			OSSetProgressiveMode(0);
			JUTVideo::sManager->setRenderMode((_GXRenderModeObj*)lbl_8048C17C);
		} else {
			JUTVideo::sManager->setRenderMode((_GXRenderModeObj*)lbl_8048C17C);
		}
	}
	p[0x60] = 0;
	*(s16*)(p + 0x6e) = 0;
	*(f32*)(p + 0x64) = 0.0f;
	p[0x76] = 0;
	*(s16*)(p + 0x70) = 0;
	*(s16*)(p + 0x72) = 0;
	*(f32*)(p + 0x68) = 0.0f;
	*(s16*)(p + 0x74) = 0x30;
	p[0x79] = 0;
	p[0x78] = 0;
	*(s32*)(p + 0x4) = 0;
	*(s32*)(p + 0x8) = 0;
	*(s32*)(p + 0x10) = 0;
	*(SubA**)(p + 0xc) = new SubA;
	*(SubB**)(p + 0x14) = new SubB;
	*(void**)(p + 0x18) = 0;
	*(void**)(p + 0x1c) = 0;
	*(void**)(p + 0x20) = 0;
	*(void**)(p + 0x24) = 0;
	*(void**)(p + 0x28) = 0;
	*(void**)(p + 0x2c) = 0;
	*(void**)(p + 0x30) = 0;
	fn_802B1EB0(*(void**)(p + 0xc));
	*(void**)(p + 0x44) = fn_80401E10(lbl_80479C34, 0, *(u32*)(lbl_80529DEC + 8));
	fn_802B1DE8(lbl_8053ACA8);
	lbl_8053A951 = 0;
	lbl_8053A93C = fn_80139994;
	lbl_8053A940 = 0;
	return p;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
