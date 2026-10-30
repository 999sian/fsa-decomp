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

struct BootLoad {
    u8 pad0[4];
    u8 ready;
    u8 pad5[3];
    DtorSlot2 dtor;
    void destroy() { ((void (*)(BootLoad*, int))(*(void***)(this + 0))[2])(this, 1); }
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
extern "C" u32 OSGetResetCode();
extern "C" u32 VIGetDTVStatus();
extern "C" void OSSetProgressiveMode(u32);
extern "C" void* fn_80401E10(void*,s32,u32);
extern void* lbl_8053ACA8;

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

extern "C" void fn_803FFAA8(void* this_) {
 u8* p=(u8*)this_;
 u8* strings=lbl_80479AC0;
 if(p[0x79]==0) {
  BootLoad* load=*(BootLoad**)(p+0x44);
  if(load->ready==1) {
   *(void**)(lbl_80529DEC+0x58)=load->resource;
   if(load) load->dtor.destroy(1);
   fn_803007D0();
   void* a=operator new(0xec); if(a) fn_8030AC4C(a);
   *(void**)(p+4)=a; *(void**)(lbl_80529DEC+0x5c)=*(void**)(p+4);
   a=operator new(4); if(a) fn_8030905C(a);
   *(void**)(p+8)=a; *(void**)(lbl_80529DEC+0x60)=*(void**)(p+8);
   fn_8030AB38(*(void**)(p+4)); fn_80308E90(*(void**)(p+8));
   *(void**)(p+0x34)=fn_80401E10(strings,0,*(u32*)(lbl_80529DEC+8));
   p[0x79]=1;
  }
  if(fn_802B1DCC(lbl_8053ACA8)) fn_802B1BE0(lbl_8053ACA8,0,0,0);
  return;
 }
 if(p[0x79]==1) {
  BootLoad* load=*(BootLoad**)(p+0x34);
  if(load->ready==1) {
   *(void**)(lbl_80529DEC+0x18)=load->resource;
   if(load) load->dtor.destroy(1);
   *(J2DScreen**)(p+0x18)=new J2DScreen;
   (*(J2DScreen**)(p+0x18))->setPriority((char*)strings+0x18,0,*(JKRArchive**)(lbl_80529DEC+0x18));
   ((J2DPicture*)(*(J2DScreen**)(p+0x18))->search(0x4e494e5f4c6f676fULL))->setBlackWhite(JUtility::TColor(0,0,0,0),JUtility::TColor(220,0,0,255));
   {const ResTIMG* img=fn_80403244(0x54494d47,(char*)strings+44); *(J2DPicture**)(p+28)=new J2DPicture(img);}
   {const ResTIMG* img=fn_80403244(0x54494d47,(char*)strings+68); *(J2DPicture**)(p+32)=new J2DPicture(img);}
   {const ResTIMG* img=fn_80403244(0x54494d47,(char*)strings+92); *(J2DPicture**)(p+36)=new J2DPicture(img);}
   {const ResTIMG* img=fn_80403244(0x54494d47,(char*)strings+112); *(J2DPicture**)(p+40)=new J2DPicture(img);}
   {const ResTIMG* img=fn_80403244(0x54494d47,(char*)strings+132); *(J2DPicture**)(p+44)=new J2DPicture(img);}
   {const ResTIMG* img=fn_80403244(0x54494d47,(char*)strings+132); *(J2DPicture**)(p+44)=new J2DPicture(img);}
   {const ResTIMG* img=fn_80403244(0x54494d47,(char*)strings+152); *(J2DPicture**)(p+48)=new J2DPicture(img);}
   if(!((lbl_80529DEC[0x21a]==0xa7)||(lbl_80529DEC[0x21b]==0xa5))||p[0x7a]!=0) {
    *(s16*)(p+0x6c)=0;
    if(VIGetDTVStatus()!=0) {
     if(OSGetResetCode()==0||p[0x7a]!=0) lbl_80529DEC[0x238]=0;
     else if(lbl_80529DEC[0x238]!=255) lbl_80529DEC[0x238]=0;
    } else {lbl_80529DEC[0x238]=255;lbl_80529DEC[0x226]=1;OSSetProgressiveMode(0);}
   } else {*(s16*)(p+0x6c)=4;lbl_80529DEC[0x238]=255;lbl_80529DEC[0x226]=1;lbl_80529DEC[0x249]=1;}
   p[0x79]=2;
  } else {
   if(fn_802B1DCC(lbl_8053ACA8)) fn_802B1BE0(lbl_8053ACA8,0,0,0);
   return;
  }
 }
 if(fn_802B1DCC(lbl_8053ACA8)) fn_802B1BE0(lbl_8053ACA8,0,0,0);
 fn_80442810(*(void**)(p+0x14));
 if((*(u8**)(p+0x14))[4]!=0) {fn_8030A43C(*(void**)(p+4));fn_80304FB0(*(void**)(p+8));}
 if((*(u8**)(p+0x14))[4]!=0&&fn_804580DC(*(void**)(lbl_80529DEC+0xc),0)&&fn_804580DC(*(void**)(lbl_80529DEC+0xc),1)&&p[0x79]==2) {
  OSReport((char*)strings+0xac);
  *(void**)(p+56)=fn_80401E10(strings+188,0,*(u32*)(lbl_80529DEC+8));
  *(void**)(p+60)=fn_80401E10(strings+212,0,*(u32*)(lbl_80529DEC+8));
  *(void**)(p+64)=fn_80401E10(strings+236,0,*(u32*)(lbl_80529DEC+8));
  *(void**)(p+72)=fn_80401BA4(strings+264,0,0,*(u32*)(lbl_80529DEC+8));
  *(void**)(p+84)=fn_80401BA4(strings+288,0,0,*(u32*)(lbl_80529DEC+8));
  *(void**)(p+88)=fn_80401BA4(strings+316,0,0,*(u32*)(lbl_80529DEC+8));
  *(void**)(p+92)=fn_80401BA4(strings+344,0,0,*(u32*)(lbl_80529DEC+8));
  p[0x79]=3;
 }
 if((*(u8**)(p+0x14))[4]==0) return;
 u8* cfg=lbl_80529DEC;
 if(cfg[0x238]==1) {
  if(SIProbe(0)!=0x40000) {
   ++*(s16*)(p+0x74);
   if(*(s16*)(p+0x74)>=48) {cfg[0x238]=255;lbl_80529DEC[0x226]=1;OSSetProgressiveMode(0);}
  } else *(s16*)(p+0x74)=0;
 } else if(cfg[0x238]==0) {
  if(SIProbe(0)==0x40000) {*(s16*)(p+0x74)=0;cfg[0x238]=1;}
  else if(*(s16*)(p+0x74)>0) {
   --*(s16*)(p+0x74);
   if(*(s16*)(p+0x74)<=0&&(OSGetProgressiveMode()==1||fn_80309D24(lbl_8053AD30,fn_8030AAF4(0),0x200)!=0)) {cfg[0x238]=2;*(s16*)(p+0x72)=0;}
  } else {cfg[0x238]=255;lbl_80529DEC[0x226]=1;OSSetProgressiveMode(0);*(s16*)(p+0x72)=0;}
 }
 switch(*(s16*)(p+0x6c)) {
 case 0:
  *(f32*)(p+0x64)+=8.5f;
  if(*(f32*)(p+0x64)>=255.0f) {*(f32*)(p+0x64)=255.0f;*(s16*)(p+0x6c)=1;} break;
 case 1:
  ++*(s16*)(p+0x6e);
  if(*(s16*)(p+0x6e)>=60) {
   if(cfg[0x238]==255||cfg[0x238]==1||cfg[0x238]==4||cfg[0x238]==11) {*(s16*)(p+0x6e)=0;*(s16*)(p+0x6c)=2;}
   else *(s16*)(p+0x6e)=60;
  } break;
 case 2:
  *(f32*)(p+0x64)-=8.5f;
  if(*(f32*)(p+0x64)<=0.0f) {*(f32*)(p+0x64)=0.0f;*(s16*)(p+0x6c)=3;} break;
 case 3:
  *(f32*)(p+0x64)=0.0f;
  if(cfg[0x238]==255||cfg[0x238]==1) *(s16*)(p+0x6c)=4;
 }
 if(p[0x79]==3&&(*(BootLoad**)(p+56))->ready==1&&(*(BootLoad**)(p+60))->ready==1&&(*(BootLoad**)(p+64))->ready==1&&(*(BootLoad**)(p+72))->ready==1&&(*(BootLoad**)(p+84))->ready==1&&(*(BootLoad**)(p+88))->ready==1&&(*(BootLoad**)(p+92))->ready==1) {
  *(void**)(lbl_80529DEC+20)=(*(BootLoad**)(p+56))->resource;
  *(void**)(lbl_80529DEC+28)=(*(BootLoad**)(p+60))->resource;
  *(void**)(lbl_80529DEC+32)=(*(BootLoad**)(p+64))->resource;
  *(void**)(lbl_80529DEC+36)=(*(BootLoad**)(p+72))->resource;
  *(void**)(lbl_80529DEC+56)=(*(BootLoad**)(p+84))->resource;
  *(void**)(lbl_80529DEC+64)=(*(BootLoad**)(p+88))->resource;
  *(void**)(lbl_80529DEC+68)=(*(BootLoad**)(p+92))->resource;
  {BootLoad* l=*(BootLoad**)(p+56);if(l) l->dtor.destroy(1);}
  {BootLoad* l=*(BootLoad**)(p+64);if(l) l->dtor.destroy(1);}
  {BootLoad* l=*(BootLoad**)(p+60);if(l) l->dtor.destroy(1);}
  {BootLoad* l=*(BootLoad**)(p+72);if(l) l->dtor.destroy(1);}
  {BootLoad* l=*(BootLoad**)(p+84);if(l) l->dtor.destroy(1);}
  {BootLoad* l=*(BootLoad**)(p+88);if(l) l->dtor.destroy(1);}
  {BootLoad* l=*(BootLoad**)(p+92);if(l) l->dtor.destroy(1);}
  p[0x79]=4;p[0x78]=1;
 }
 if(p[0x78]==1) {fn_803B9B3C(lbl_8051C1A0);p[0x78]=2;}
 else if(p[0x78]==2&&fn_803B9A24(lbl_8051C1A0)!=0) p[0x78]=3;
 if(*(s16*)(p+0x6c)>=4&&p[0x78]==3) p[0x78]=4;
 switch(cfg[0x238]) {
 case 2:
  *(f32*)(p+0x68)+=8.5f;
  if(*(f32*)(p+0x68)>=255.0f) {*(f32*)(p+0x68)=255.0f;cfg[0x238]=3;} break;
 case 3:
  ++*(s16*)(p+0x72);
  if(fn_80309D6C(lbl_8053AD30,fn_8030AAF4(0),0x100)!=0||*(s16*)(p+0x72)>=600) cfg[0x238]=4;
  else if(fn_80309D6C(lbl_8053AD30,fn_8030AAF4(0),2)!=0) {p[0x76]=1;*(s16*)(p+0x70)=30;}
  else if(fn_80309D6C(lbl_8053AD30,fn_8030AAF4(0),1)!=0) {p[0x76]=0;*(s16*)(p+0x70)=30;}
  ++*(s16*)(p+0x70);if(*(s16*)(p+0x70)>60) *(s16*)(p+0x70)=0;
  break;
 case 4:
  if(*(s16*)(p+0x6c)==2) {
   *(f32*)(p+0x68)-=8.5f;
   if(*(f32*)(p+0x68)<=0.0f) {
    *(f32*)(p+0x68)=0.0f;
    if(p[0x76]==0) {
     *(s16*)(p+0x70)=0;
     if(OSGetProgressiveMode()==1) {cfg[0x238]=6;OSSetProgressiveMode(1);}
     else {cfg[0x238]=5;OSSetProgressiveMode(1);}
    } else {
     if(OSGetProgressiveMode()==1) {cfg[0x238]=9;*(s16*)(p+0x6e)=0;*(s16*)(p+0x6c)=0;OSSetProgressiveMode(0);}
     else {cfg[0x238]=9;*(s16*)(p+0x6e)=0;*(s16*)(p+0x6c)=0;}
    }
   }
  } break;
 case 5:cfg[0x238]=7;break;
 case 6:cfg[0x238]=8;break;
 case 7:case 8:
  ++*(s16*)(p+0x70);
  if(lbl_80529DEC[0x251]>90&&*(s16*)(p+0x70)>=90) {cfg[0x238]=9;*(s16*)(p+0x6e)=0;*(s16*)(p+0x6c)=0;lbl_80529DEC[0x251]=0;} break;
 case 9:
  *(f32*)(p+0x68)+=8.5f;
  if(*(f32*)(p+0x68)>=255.0f) {*(f32*)(p+0x68)=255.0f;cfg[0x238]=10;*(s16*)(p+0x70)=0;} break;
 case 10:
  ++*(s16*)(p+0x70);
  if(*(s16*)(p+0x70)>=120) {*(f32*)(p+0x68)=255.0f;cfg[0x238]=11;} break;
 case 11:
  *(f32*)(p+0x68)-=8.5f;
  if(*(f32*)(p+0x68)<=0.0f) {*(f32*)(p+0x68)=0.0f;cfg[0x238]=255;lbl_80529DEC[0x226]=1;} break;
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
