struct Vtable800D8248 {
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m3() = 0;
    virtual void m4() = 0;
    virtual void m5() = 0;
    virtual void m6() = 0;
    virtual void m7() = 0;
    virtual void m8() = 0;
    virtual void m9() = 0;
    virtual void m10() = 0;
};
#include "types.h"
#include "JSystem/J3D/J3DTypes.h"

static inline void setBits2_3(u8* p, u8 v) { *p = (*p & ~0xC) | (v << 2); }
static inline void setBits0_1(u8* p, u8 v) { *p = (*p & ~0x3) | v; }

struct Unk800DE29CBits {
    u8 pad : 4;
    u8 hi : 2;
    u8 lo : 2;
};

struct Unk800DE29CEntry {
    u8 pad0[0x28];
    Unk800DE29CBits bits;
};

struct Unk800DE210 {
    u8 a, b, c;
};

struct Unk800DE6DCStage {
    u8 pad[7];
    u8 mSwap;
    void setTexSel(int sel) { mSwap = (mSwap & ~0x0c) | (sel << 2); }
    void setRasSel(u8 sel) { mSwap = (mSwap & ~0x03) | sel; }
    void setSwapModeInfo(const u8* info) {
        setTexSel(info[1]);
        setRasSel(info[0]);
    }
};

struct Unk800DE6DC {
    u8 pad[0x35];
    Unk800DE6DCStage mStage[1];
};

struct Unk800DDA5C {
    u16 a;
    u8 b;
    u8 c;
};
#include "JSystem/J3D/J3DSys.h"
#include "dolphin/gd.h"
#include "JSystem/J3D/J3DTevBlock.h"
#include "dolphin/os/OSCache.h"
#include "JSystem/J3D/J3DPE.h"
#include "JSystem/J3D/J3DInd.h"
extern "C" char __vt__13J3DTevBlock16[];
extern "C" char __vt__11J3DTevBlock[];
extern "C" char __vt__22J3DColorBlockAmbientOn[];
extern "C" char __vt__21J3DColorBlockLightOff[];
extern "C" char __vt__13J3DColorBlock[];
extern "C" char __vt__15J3DIndBlockFull[];
extern "C" char __vt__11J3DIndBlock[];
extern "C" char __vt__20J3DColorBlockLightOn[];
extern "C" char __vt__16J3DPEBlockFogOff[];
extern "C" char __vt__19J3DTexGenBlockBasic[];
extern "C" char __vt__21J3DTexGenBlockPatched[];
extern "C" char __vt__14J3DTexGenBlock[];
extern "C" char __vt__14J3DPEBlockFull[];
extern "C" char __vt__13J3DPEBlockOpa[];
extern "C" char __vt__10J3DPEBlock[];
extern "C" char __vt__13J3DPEBlockXlu[];
extern "C" char __vt__17J3DPEBlockTexEdge[];
extern "C" void __dl__FPv(void*);
extern "C" void __destroy_arr(void*, void*, u32, u32);
extern "C" void __dt__19J3DIndTexCoordScaleFv(void*);
extern "C" u8 sTexCoordScaleTable__6J3DSys[64];
extern "C" void J3DGDSetTexCoordScale2__F13_GXTexCoordIDUsUcUcUsUcUc(unsigned char, unsigned short, unsigned char, unsigned char, unsigned short, unsigned char, unsigned char);
extern "C" void loadTexNo__FUlRCUs(unsigned long, unsigned short*);
extern "C" void loadTexCoordGens__FUlP11J3DTexCoord(unsigned long, void*);
extern "C" void load__9J3DTexMtxCFUl(void*, unsigned long);
extern "C" void DCStoreRange(void*, unsigned long);
extern "C" void __dt__12J3DIndTexMtxFv(void*);
extern "C" void __as__16J3DIndTexMtxInfoFRC16J3DIndTexMtxInfo(J3DIndTexMtxInfo*, const J3DIndTexMtxInfo&);
struct ActorBox;
struct J3DColorBlockAmbientOn {
    void initialize();
    void* __vt;
    J3DGXColor mMatColor[2];
    u8 mColorChanNum;
    u16 mColorChan[4];
    u32 mMatColorOffset;
    u32 mColorChanOffset;
    J3DGXColor mAmbColor[2];
};
struct UnkDC8C;
struct UnkDCF8;
struct Unk800DDC8C {
    u8 _0[0xda];
    s16 a[4][4];
    u8 b[4][4];
};
struct Unk800DF13C {
    u8 _0[0x16];
    u16 a[1];
};
struct Unk800DE50C { s16 a, b, c, d; };
struct Unk800DE4D0 {
    u8 _0[0xc];
    u32 a[2];
    Unk800DE50C b[1];
};
struct Unk800DE578 { u8 a, b, c, d; };
struct Unk800DE5D0 {
    u8 _0[0x45];
    Unk800DE578 a[4];
    u8 b[1];
};
struct Unk800DE0CC {
    u8 _0[0x42];
    Unk800DE50C a[4];
    Unk800DE578 b[4];
};
struct Unk800DEC3C {
    u8 _0[0x38];
    Unk800DE50C a[8];
    u32 b[8];
    Unk800DE50C c[1];
};
struct Actor {
    Actor();
    virtual ~Actor();
    void setBox70(const ActorBox& box);                 /* 0x801FF630 */
    void setPos(const JGeometry::TVec3<f32>& pos);      /* 0x801FF704 */
    u8 _base[0x22c];
};
struct QuadHalf {
    QuadHalf() {}
    f32 x, y;
};
struct Quad {
    Quad() {}
    QuadHalf a, b;
};
struct ActorBox {
    Quad q;
};


struct UnkDC8C {
    s16 m_a;
    s16 m_b;
    s16 m_c;
    s16 m_d;
};

struct UnkDCF8 {
    u8 m_a;
    u8 m_b;
    u8 m_c;
    u8 m_d;
};
struct Unk800DBCCCSrc {
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m3() = 0;
    virtual void m4() = 0;
    virtual void m5() = 0;
    virtual void m6() = 0;
    virtual void m7() = 0;
    virtual void m8() = 0;
    virtual void m9() = 0;
    virtual void m10() = 0;
    virtual void m11() = 0;
    virtual u8* getMatColor(u32) = 0;
    virtual void m13() = 0;
    virtual void m14() = 0;
    virtual void m15() = 0;
    virtual void m16() = 0;
    virtual void m17() = 0;
    virtual u8 getColorChanNum() = 0;
    virtual void m19() = 0;
    virtual void m20() = 0;
    virtual u16* getColorChan(u32) = 0;
};
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void J3DTexGenBlockPatched::initialize()
{
	mTexGenCnt = 0;
	for (int i = 0; i < 8; i++) {
		mTexMatrices[i] = nullptr;
	}
	mTexMtxOffset = 0;
}

void J3DTexGenBlockBasic::initialize()
{
	mTexGenCnt = 0;
	for (int i = 0; i < 8; i++) {
		mTexMatrices[i] = nullptr;
	}
	mTexMtxOffset = 0;
}

void J3DTevBlock1::initialize()
{
	mTexIndices[0] = 0xffff;
	mStages[0].mBPCommand1 = 0xc0;
	mStages[0].mBPCommand2 = 0xc1;
	mTexNoOffset = 0;
}

extern "C" void fn_800D36E0(u32* param_1) {
    param_1[1] = 0;
}

extern "C" int fn_800D3E10(void) {
    return 0x22;
}

extern "C" u32 fn_800D3E18(void) {
    return 0x2f;
}

extern "C" u32 fn_800D3E20(void) {
    return 0x26f;
}

extern "C" int fn_800D3E28(void) { return 0x1a8; }

extern "C" int fn_800D3E30(void) { return 0xfe; }

extern "C" int fn_800D3E38(void) { return 0x1f2; }

extern "C" u32 fn_800D3E40(void)
{
  return 0x230;
}

void J3DColorBlockAmbientOn::initialize()
{
	mColorChanNum = 0;
	for (int i = 0; i < 2; i++) {
		GXColor c = j3dDefaultColInfo;
		mMatColor[i] = *(J3DGXColor*)&c;
	}
	for (int i = 0; i < 2; i++) {
		GXColor c = j3dDefaultAmbInfo;
		mAmbColor[i] = *(J3DGXColor*)&c;
	}
	mMatColorOffset = 0;
	mColorChanOffset = 0;
}

extern "C" int fn_800D3E48(void) { return 0x69; }

extern "C" int fn_800D3E50(void) { return 0x14f; }

extern "C" int fn_800D3E58(void) { return 0x244; }

extern "C" int fn_800D3E60(void) { return 0x3e8; }

extern "C" int fn_800D3E68(void) { return 0x8c; }

extern "C" int fn_800D3E70(void) { return 0x1e; }

extern "C" int fn_800D3E78(void) { return 0x1e; }

extern "C" int fn_800D3E80(void) { return 0x1e; }

extern "C" int fn_800D3E88(void) { return 0x1e; }

extern "C" int fn_800D3E90(void) { return 0x55; }

extern "C" void fn_800D5120(Vtable800D8248* obj)
{
  obj->m3();
  obj->m4();
}

extern "C" void fn_800D5750(Vtable800D8248* obj)
{
  obj->m3();
  obj->m4();
}

extern "C" void fn_800D5DAC(Vtable800D8248* param_1, u32 param_2)
{
  if ((param_2 & 1) != 0) {
    param_1->m6();
  }
  if ((param_2 & 2) != 0) {
    param_1->m7();
  }
}

extern "C" u32 lbl_80539E10;
extern "C" void fn_800D5E14(void* param) {
    GDOverflowCheck(lbl_80539E10);

    __GDWrite(0x10);
    __GDWrite(0x00);
    __GDWrite(0x01);
    __GDWrite(0x10);
    __GDWrite(0x0c);

    u32 val1 = *(u32*)((char*)param + 4);
    __GDWrite((u8)(val1 >> 24));
    __GDWrite((u8)(val1 >> 16));
    __GDWrite((u8)(val1 >> 8));
    __GDWrite((u8)val1);

    u32 val2 = *(u32*)((char*)param + 8);
    __GDWrite((u8)(val2 >> 24));
    __GDWrite((u8)(val2 >> 16));
    __GDWrite((u8)(val2 >> 8));
    __GDWrite((u8)val2);
}

extern "C" void fn_800D6394(int* param_1, u32 param_2)
{
  int* vtable = *(int**)param_1;
  if ((param_2 & 1) != 0) {
    (*(void(**)(void))(vtable + 0x20))();
  }
  if (((param_2 & 2) != 0) || (((param_2 >> 4) & 0xf) != 0)) {
    (*(void(**)(int*))(vtable + 0x24))(param_1);
  }
}

extern "C" void fn_800D6404(void* param) {
    GDOverflowCheck(lbl_80539E10);

    __GDWrite(0x10);
    __GDWrite(0x00);
    __GDWrite(0x01);
    __GDWrite(0x10);
    __GDWrite(0x0c);

    u32 val1 = *(u32*)((char*)param + 4);
    __GDWrite((u8)(val1 >> 24));
    __GDWrite((u8)(val1 >> 16));
    __GDWrite((u8)(val1 >> 8));
    __GDWrite((u8)val1);

    u32 val2 = *(u32*)((char*)param + 8);
    __GDWrite((u8)(val2 >> 24));
    __GDWrite((u8)(val2 >> 16));
    __GDWrite((u8)(val2 >> 8));
    __GDWrite((u8)val2);
}

extern "C" void fn_800D69B4(void* p) {
    u8* mtx = (u8*)p;
    u8* gen = (u8*)p;
    u32 i = 0;
    *(u32*)((u8*)p + 0x58) = (u8*)__GDCurrentDL->pDisplayListData - (u8*)__GDCurrentDL->begin;
    for (; i < 4; i++) {
        void* obj = *(void**)(mtx + 0x38);
        if (obj != 0 && *(u8*)(gen + 0xa) != 0x3c) {
            load__9J3DTexMtxCFUl(obj, i);
        }
        mtx += 4;
        gen += 6;
    }
    u32 val = *(u32*)((u8*)p + 4);
    if (val != 0) {
        loadTexCoordGens__FUlP11J3DTexCoord(val, (u8*)p + 8);
    }
}

extern "C" void fn_800D6A5C(void* p) {
    u8* mtx = (u8*)p;
    u8* gen = (u8*)p;
    u32 i = 0;
    *(u32*)((u8*)p + 0x58) = (u8*)__GDCurrentDL->pDisplayListData - (u8*)__GDCurrentDL->begin;
    for (; i < 8; i++) {
        void* obj = *(void**)(mtx + 0x38);
        if (obj != 0 && *(u8*)(gen + 0xa) != 0x3c) {
            load__9J3DTexMtxCFUl(obj, i);
        }
        mtx += 4;
        gen += 6;
    }
    u32 val = *(u32*)((u8*)p + 4);
    if (val != 0) {
        loadTexCoordGens__FUlP11J3DTexCoord(val, (u8*)p + 8);
    }
}

extern "C" void fn_800D6B04(void* p) {
    __GDCurrentDL->pDisplayListData = (u8*)__GDCurrentDL->begin + *(u32*)((u8*)p + 0x58);
    u8* dlStart = __GDCurrentDL->pDisplayListData;

    u8* mtx = (u8*)p;
    for (u32 i = 0; i < 8; i++) {
        void* obj = *(void**)(mtx + 0x38);
        if (obj != 0) {
            load__9J3DTexMtxCFUl(obj, i);
        }
        mtx += 4;
    }

    u8* dlEnd = __GDCurrentDL->pDisplayListData;
    DCStoreRange(dlStart, (u32)(dlEnd - dlStart));
}

extern "C" void fn_800D6B94(u8* this_) {
    u8* start;
    u8* q = this_;
    u8* p = this_;
    u32 i = 0;
    __GDCurrentDL->pDisplayListData = __GDCurrentDL->begin + *(u32*)(this_ + 0x58);
    start = __GDCurrentDL->pDisplayListData;
    do {
        if (*(void**)(q + 0x38) != 0 && p[0xa] != 0x3c) {
            load__9J3DTexMtxCFUl(*(void**)(q + 0x38), i);
        }
        i++;
        q += 4;
        p += 6;
    } while (i < 4);
    DCStoreRange(start, __GDCurrentDL->pDisplayListData - start);
}

extern "C" void fn_800D6C40(u8* this_) {
    u8* start;
    u8* q = this_;
    u8* p = this_;
    u32 i = 0;
    __GDCurrentDL->pDisplayListData = __GDCurrentDL->begin + *(u32*)(this_ + 0x58);
    start = __GDCurrentDL->pDisplayListData;
    do {
        if (*(void**)(q + 0x38) != 0 && p[0xa] != 0x3c) {
            load__9J3DTexMtxCFUl(*(void**)(q + 0x38), i);
        }
        i++;
        q += 4;
        p += 6;
    } while (i < 8);
    DCStoreRange(start, __GDCurrentDL->pDisplayListData - start);
}

extern "C" void fn_800D6CEC(void* r3, u32 r4) {
    if ((r4 >> 8) & 0xf) {
        (*(void(**)(void*))(*(void***)r3 + 0xa))(r3);
        
        if (r4 & (1 << 12)) {
            (*(void(**)(void*))(*(void***)r3 + 0xb))(r3);
        }
    }
}

extern "C" void fn_800D6D54(void* p) {
    u8* addr = (u8*)p;
    for (u32 i = 0; i < 8; i++) {
        void* obj = *(void**)((u8*)addr + 0x38);
        if (obj != 0) {
            load__9J3DTexMtxCFUl(obj, i);
        }
        addr += 4;
    }
}

extern "C" void fn_800D6DAC(void* param_1) {
    u32 val = *(u32*)((u8*)param_1 + 4);
    if (val != 0) {
        loadTexCoordGens__FUlP11J3DTexCoord(val, (u8*)param_1 + 8);
    }
}

extern "C" void fn_800D7F78(void* p) {
    __GDCurrentDL->pDisplayListData = __GDCurrentDL->begin + *(u32*)((u8*)p + 4);
    u8* saved = __GDCurrentDL->pDisplayListData;
    
    u8* addr = (u8*)p;
    for (u32 i = 0; i < 8; i++) {
        if (*(u16*)(addr + 8) != 0xffff) {
            loadTexNo__FUlRCUs(i, (u16*)(addr + 8));
        }
        addr += 2;
    }
    
    u8* now = __GDCurrentDL->pDisplayListData;
    DCStoreRange(saved, (u32)(now - saved));
}

extern "C" void fn_800D800C(u8* self) {
    u8* p = self;
    __GDCurrentDL->pDisplayListData = __GDCurrentDL->begin + *(s32*)(self + 0xd4);
    u8* start = __GDCurrentDL->pDisplayListData;
    for (u32 i = 0; i < 3; i++) {
        GXColorS10 c = *(GXColorS10*)(p + 0x98);
        J3DGDSetTevColorS10(GXTevRegID(i + 1), c);
        p += 8;
    }
    p = self;
    for (u32 i = 0; i < 4; i++) {
        GXColor c = *(GXColor*)(p + 0xb8);
        J3DGDSetTevKColor(GXTevKColorID(i), c);
        p += 4;
    }
    DCStoreRange(start, __GDCurrentDL->pDisplayListData - start);
}

struct Vtable800D8248;
extern "C" void fn_800D8248(Vtable800D8248* p) {
    p->m9();
    p->m10();
}

extern "C" void fn_800D8294(void* p) {
    __GDCurrentDL->pDisplayListData = (u8*)__GDCurrentDL->begin + *(u32*)((u8*)p + 4);
    u8* saved = __GDCurrentDL->pDisplayListData;

    u8* addr = (u8*)p;
    if (*(u16*)(addr + 8) != 0xffff) {
        loadTexNo__FUlRCUs(0, (u16*)(addr + 8));
    }

    u8* now = __GDCurrentDL->pDisplayListData;
    DCStoreRange(saved, (u32)(now - saved));
}

extern "C" void fn_800D8300(void) {
}

extern "C" void fn_800D83E8(Vtable800D8248* p) {
    p->m9();
}

extern "C" void fn_800D8414(void* param_1) {
    __GDCurrentDL->pDisplayListData = (u8*)__GDCurrentDL->begin + *(u32*)((u8*)param_1 + 4);
    u8* dlStart = __GDCurrentDL->pDisplayListData;
    
    u8* addr = (u8*)param_1;
    for (u32 i = 0; i < 2; i++) {
        if (*(u16*)(addr + 8) != 0xffff) {
            loadTexNo__FUlRCUs(i, (u16*)(addr + 8));
        }
        addr += 2;
    }
    
    u8* dlEnd = __GDCurrentDL->pDisplayListData;
    DCStoreRange(dlStart, (u32)(dlEnd - dlStart));
}

extern "C" void fn_800D84A8(u8* this_) {
    u32 col[2];
    u32 kcol;
    u8* base;
    u32 i;
    u8* p;

    __GDCurrentDL->pDisplayListData = __GDCurrentDL->begin + *(u32*)(this_ + 0x68);
    base = __GDCurrentDL->pDisplayListData;
    for (i = 0; i < 3; i++) {
        p = this_ + i * 8;
        col[0] = *(u32*)(p + 0x14);
        col[1] = *(u32*)(p + 0x18);
        J3DGDSetTevColorS10((GXTevRegID)(i + 1), *(GXColorS10*)col);
    }
    for (i = 0; i < 4; i++) {
        p = this_ + i * 4;
        kcol = *(u32*)(p + 0x45);
        J3DGDSetTevKColor((GXTevKColorID)i, *(GXColor*)&kcol);
    }
    DCStoreRange(base, __GDCurrentDL->pDisplayListData - base);
}

extern "C" void fn_800D86D4(Vtable800D8248* p) {
    p->m9();
    p->m10();
}

extern "C" void fn_800D8720(void* param_1) {
    __GDCurrentDL->pDisplayListData = (u8*)__GDCurrentDL->begin + *(u32*)((u8*)param_1 + 4);
    u8* dlStart = __GDCurrentDL->pDisplayListData;
    
    u8* addr = (u8*)param_1;
    for (u32 i = 0; i < 4; i++) {
        if (*(u16*)(addr + 8) != 0xffff) {
            loadTexNo__FUlRCUs(i, (u16*)(addr + 8));
        }
        addr += 2;
    }
    
    u8* dlEnd = __GDCurrentDL->pDisplayListData;
    DCStoreRange(dlStart, (u32)(dlEnd - dlStart));
}

extern "C" void fn_800D87B4(u8* self) {
    u32 i = 0;
    u8* p = self;
    u8* start;
    __GDCurrentDL->pDisplayListData = __GDCurrentDL->begin + *(s32*)(self + 0x90);
    start = __GDCurrentDL->pDisplayListData;
    for (; i < 3; i++) {
        GXColorS10 c = *(GXColorS10*)(p + 0x42);
        J3DGDSetTevColorS10(GXTevRegID(i + 1), c);
        p += 8;
    }
    i = 0;
    p = self;
    for (; i < 4; i++) {
        GXColor c = *(GXColor*)(p + 0x62);
        J3DGDSetTevKColor(GXTevKColorID(i), c);
        p += 4;
    }
    DCStoreRange(start, __GDCurrentDL->pDisplayListData - start);
}

extern "C" void fn_800D89F0(Vtable800D8248* p) {
    p->m9();
    p->m10();
}

extern "C" void fn_800D8A3C(void* p) {
    __GDCurrentDL->pDisplayListData = __GDCurrentDL->begin + *(u32*)((u8*)p + 4);
    u8* saved = __GDCurrentDL->pDisplayListData;
    
    u8* addr = (u8*)p;
    for (u32 i = 0; i < 8; i++) {
        if (*(u16*)(addr + 8) != 0xffff) {
            loadTexNo__FUlRCUs(i, (u16*)(addr + 8));
        }
        addr += 2;
    }
    
    u8* now = __GDCurrentDL->pDisplayListData;
    DCStoreRange(saved, (u32)(now - saved));
}

extern "C" void fn_800D8AD0(u8* this_) {
    __GDCurrentDL->pDisplayListData = __GDCurrentDL->begin + *(u32*)(this_ + 0x170);
    u8* base = __GDCurrentDL->pDisplayListData;
    u8* p = this_;
    for (u32 i = 0; i < 3; i++) {
        J3DGDSetTevColorS10((GXTevRegID)(i + 1), *(GXColorS10*)(p + 0xda));
        p += 8;
    }
    p = this_;
    for (u32 i = 0; i < 4; i++) {
        J3DGDSetTevKColor((GXTevKColorID)i, *(GXColor*)(p + 0xfa));
        p += 4;
    }
    DCStoreRange(base, __GDCurrentDL->pDisplayListData - base);
}

extern "C" void fn_800D8D0C(Vtable800D8248* p) {
    p->m9();
    p->m10();
}

#if defined(VERSION_G4SJ01)
extern "C" void fn_800D8D58(Vtable800D8248* obj, u32 flags) {
    if ((flags >> 16) & 0xf) {
        obj->m3();
    }
    if (flags & 0x4000000) {
        obj->m5();
    }
    if ((flags >> 20) & 0xf) {
        obj->m6();
        if (flags & 0x8000000) {
            obj->m7();
        }
    }
    if (flags & 0x1000000) {
        obj->m4();
    }
}
#else
extern "C" void fn_800D8D58(int* param_1, u32 param_4) {
    if ((param_4 >> 0x10) & 0xf) {
        (*(void(**)(void))(*(int*)param_1 + 0x14))();
    }
    if (param_4 & 0x04000000) {
        (*(void(**)(int*))(*(int*)param_1 + 0x1c))(param_1);
    }
    if ((param_4 >> 0x14) & 0xf) {
        (*(void(**)(int*))(*(int*)param_1 + 0x20))(param_1);
        if (param_4 & 0x08000000) {
            (*(void(**)(int*))(*(int*)param_1 + 0x24))(param_1);
        }
    }
    if (param_4 & 0x01000000) {
        (*(void(**)(int*))(*(int*)param_1 + 0x18))(param_1);
    }
}
#endif

extern "C" void fn_800D8E14(u8* self) {
    for (u32 i = 0; i < 8; i++) {
        if (*(u16*)(self + 8 + i * 2) != 0xffff) {
            loadTexNo(i, *(u16*)(self + 8 + i * 2));
        }
    }
}

extern "C" void fn_800D8F78(u8* self) {
    u8 count = *(u8*)(self + 0xd0);
    if (count == 0) return;
    
    u32 accumulator = 0;
    for (u32 i = 0; i < count; i++) {
        u32 value = *(u32*)(self + 0x78);
        accumulator = (value & 0xff000000) | ((i + 0x10) << 24);
        
        __GDWrite(0x61);
        __GDWrite(accumulator >> 24);
        __GDWrite((accumulator >> 16) & 0xff);
        __GDWrite((accumulator >> 8) & 0xff);
        __GDWrite(accumulator & 0xff);
    }
}

extern "C" void fn_800D9020(u8* self) {
    for (u32 i = 0; i < 3; i++) {
        J3DGDSetTevColorS10((GXTevRegID)(i + 1), *(GXColorS10*)(self + 0x98 + i * 8));
    }
    for (u32 i = 0; i < 4; i++) {
        J3DGDSetTevKColor((GXTevKColorID)i, *(GXColor*)(self + 0xb8 + i * 4));
    }
}

extern "C" void fn_800D90B8(u8* p) {
    u8* e;
    u32 i;
    u8 n;
    u8* f;
    u16* s;
    e = p;
    n = p[0xd0];
    for (i = 0; i < n; i += 2) {
        s = (u16*)((u8*)&sTexCoordScaleTable__6J3DSys + (e[0x19] & 7) * 8);
        J3DGDSetTexCoordScale2__F13_GXTexCoordIDUsUcUcUsUcUc(e[0x18] & 7, s[0], s[2] == 1, 0, s[1], s[3] == 1, 0);
        f = p + (i + 1) * 4;
        s = (u16*)((u8*)&sTexCoordScaleTable__6J3DSys + (f[0x19] & 7) * 8);
        J3DGDSetTexCoordScale2__F13_GXTexCoordIDUsUcUcUsUcUc(f[0x18] & 7, s[0], s[2] == 1, 0, s[1], s[3] == 1, 0);
        e += 8;
    }
}

extern "C" void fn_800D91A4(u8* self) {
    if (*(u16*)(self + 8) != 0xffff) {
        loadTexNo(0, *(u16*)(self + 8));
    }
}

extern "C" void fn_800D91D8(void) {
}

extern "C" void fn_800D91DC(void* param) {
    u32 val1 = *(u32*)((char*)param + 0xe);
    __GDWrite(0x61);
    __GDWrite((u8)(val1 >> 24));
    __GDWrite((u8)(val1 >> 16));
    __GDWrite((u8)(val1 >> 8));
    __GDWrite((u8)val1);

    u32 val2 = *(u32*)((char*)param + 0x12);
    __GDWrite(0x61);
    __GDWrite((u8)(val2 >> 24));
    __GDWrite((u8)(val2 >> 16));
    __GDWrite((u8)(val2 >> 8));
    __GDWrite((u8)val2);
}

extern "C" void fn_800D92CC(u8* self) {
    u32 value = *(u32*)(self + 0x18);
    u32 combined = value | 0x10000000;
    
    u8* dl = __GDCurrentDL->pDisplayListData;
    
    dl[0] = 0x61;
    dl[1] = (combined >> 24) & 0xff;
    dl[2] = (combined >> 16) & 0xff;
    dl[3] = (combined >> 8) & 0xff;
    dl[4] = combined & 0xff;
    
    __GDCurrentDL->pDisplayListData = dl + 5;
}

extern "C" void fn_800D934C(void* param_1) {
    unsigned char texCoordID = *(unsigned char*)param_1;
    unsigned char scaleIdx = *((unsigned char*)param_1 + 1);
    
    unsigned short* entry = (unsigned short*)(&sTexCoordScaleTable__6J3DSys) + ((scaleIdx & 7) * 4);
    
    unsigned short v0 = entry[0];
    unsigned short v1 = entry[1];
    unsigned short v2 = entry[2];
    unsigned short v3 = entry[3];
    
    unsigned int lz0 = __cntlzw(1 - v1);
    unsigned int lz1 = __cntlzw(1 - v3);
    unsigned char s0 = (lz0 >> 12) & 0xFF;
    unsigned char s1 = (lz1 >> 12) & 0xFF;
    
    J3DGDSetTexCoordScale2__F13_GXTexCoordIDUsUcUcUsUcUc(texCoordID, v0, s0, (unsigned char)0, v2, s1, (unsigned char)0);
}

extern "C" void fn_800D93B4(void* param_1) {
    u8* addr = (u8*)param_1;
    for (u32 i = 0; i < 2; i++) {
        if (*(u16*)(addr + 8) != 0xffff) {
            loadTexNo__FUlRCUs(i, (u16*)(addr + 8));
        }
        addr += 2;
    }
}

extern "C" void fn_800D9410(u8* this_) {
    u32 i;
    u8* p = this_;
    for (i = 0; i < 3; i++) {
        GXColorS10 c = *(GXColorS10*)(p + 0x14);
        J3DGDSetTevColorS10(GXTevRegID(i + 1), c);
        p += 8;
    }
    i = 0;
    p = this_;
    for (; i < 4; i++) {
        GXColor c = *(GXColor*)(p + 0x45);
        J3DGDSetTevKColor(GXTevKColorID(i), c);
        p += 4;
    }
}

extern "C" void fn_800D971C(u8* self) {
	for (u32 i = 0; i < 4; i++) {
		if (*(u16*)(self + 8 + i * 2) != 0xffff) {
			loadTexNo(i, *(u16*)(self + 8 + i * 2));
		}
	}
}

extern "C" void fn_800D9778(u8* self) {
	for (u32 i = 0; i < 3; i++) {
		J3DGDSetTevColorS10((GXTevRegID)(i + 1), *(GXColorS10*)(self + 0x42 + i * 8));
	}
	for (u32 i = 0; i < 4; i++) {
		J3DGDSetTevKColor((GXTevKColorID)i, *(GXColor*)(self + 0x62 + i * 4));
	}
}

extern "C" void fn_800D9918(u8* self) {
    u32 count = self[0x20];
    u32 accumulator;
    u32 i = 0;
    for (; i < count; i++) {
        u32 value = *(u32*)(self + 0x80);
        accumulator = value | ((i + 0x10) << 24);
        __GDWrite(0x61);
        __GDWrite(accumulator >> 24);
        __GDWrite((accumulator >> 16) & 0xff);
        __GDWrite((accumulator >> 8) & 0xff);
        __GDWrite(accumulator & 0xff);
        self += 4;
    }
}

extern "C" void fn_800D9AAC(u8* self) {
    for (u32 i = 0; i < 8; i++) {
        if (*(u16*)(self + 8 + i * 2) != 0xffff) {
            loadTexNo(i, *(u16*)(self + 8 + i * 2));
        }
    }
}

extern "C" void fn_800D9B08(u8* self) {
    for (u32 i = 0; i < 3; i++) {
        GXColorS10 c = *(GXColorS10*)(self + 0xda + i * 8);
        J3DGDSetTevColorS10(GXTevRegID(i + 1), c);
    }
    for (u32 i = 0; i < 4; i++) {
        GXColor c = *(GXColor*)(self + 0xfa + i * 4);
        J3DGDSetTevKColor(GXTevKColorID(i), c);
    }
}

extern "C" void fn_800D9CA8(void* param_1) {
    u8 count = *(u8*)((u8*)param_1 + 0x58);
    if (count == 0) {
        return;
    }
    
    u32* gd = (u32*)&__GDCurrentDL;
    
    for (u32 i = 0; i < count; i++) {
        u32 val = *(u32*)((u8*)param_1 + 0x4 + i * 4);
        u8* dl = (u8*)(gd[2]);
        
        u8 high_nibble = (i + 0x10) & 0xff;
        u32 combined = val | (high_nibble << 24);
        
        *dl = 0x61;
        gd[2]++;
        
        dl = (u8*)(gd[2]);
        *dl = (combined >> 24) & 0xff;
        gd[2]++;
        
        dl = (u8*)(gd[2]);
        *dl = (combined >> 16) & 0xff;
        gd[2]++;
        
        dl = (u8*)(gd[2]);
        *dl = (combined >> 8) & 0xff;
        gd[2]++;
        
        dl = (u8*)(gd[2]);
        *dl = combined & 0xff;
        gd[2]++;
    }
}

extern "C" void fn_800D9D50(u8* p) {
    u8* e = p;
    u32 n = p[0x58];
    for (u32 i = 0; i < n; i += 2) {
        u16* t = (u16*)((u8*)&sTexCoordScaleTable__6J3DSys + (e[0x19] & 7) * 8);
        J3DGDSetTexCoordScale2__F13_GXTexCoordIDUsUcUcUsUcUc(e[0x18] & 7, t[0], t[2] == 1, 0, t[1], t[3] == 1, 0);
        u8* f = p + (i + 1) * 4;
        t = (u16*)((u8*)&sTexCoordScaleTable__6J3DSys + (f[0x19] & 7) * 8);
        J3DGDSetTexCoordScale2__F13_GXTexCoordIDUsUcUcUsUcUc(f[0x18] & 7, t[0], t[2] == 1, 0, t[1], t[3] == 1, 0);
        e += 8;
    }
}

extern "C" void fn_800D9E3C(void* p) {
    u8* saved;
    u8* addr;
    u32 byteCount;
    u32 i;

    byteCount = 0;
    addr = (u8*)p;
    __GDCurrentDL->pDisplayListData = __GDCurrentDL->begin + *(u32*)((u8*)p + 4);
    saved = __GDCurrentDL->pDisplayListData;

    for (i = 0; i < 8; i++) {
        if (*(u16*)(addr + 8) != 0xffff) {
            __GDCurrentDL->pDisplayListData = __GDCurrentDL->begin + (*(u32*)((u8*)p + 4) + byteCount);
            patchTexNo_PtrToIdx(i, *(const u16*)(addr + 8));
            byteCount += 0x14;
            if (((u8*)(*(u32*)((u8*)j3dSys.mTexture + 4)))[(*(u16*)(addr + 8) << 5) + 8] == 1) {
                byteCount += 0x23;
            }
        }
        addr += 2;
    }

    DCStoreRange(saved, (u32)(__GDCurrentDL->pDisplayListData - saved));
}

extern "C" void fn_800D9F10(void* p) {
    u8* saved;
    u8* addr;
    u32 byteCount;
    u32 i;

    byteCount = 0;
    addr = (u8*)p;
    __GDCurrentDL->pDisplayListData = __GDCurrentDL->begin + *(u32*)((u8*)p + 4);
    saved = __GDCurrentDL->pDisplayListData;

    for (i = 0; i < 8; i++) {
        if (*(u16*)(addr + 8) != 0xffff) {
            __GDCurrentDL->pDisplayListData = __GDCurrentDL->begin + (*(u32*)((u8*)p + 4) + byteCount);
            patchTexNo_PtrToIdx(i, *(const u16*)(addr + 8));
            byteCount += 0x14;
            if (((u8*)(*(u32*)((u8*)j3dSys.mTexture + 4)))[(*(u16*)(addr + 8) << 5) + 8] == 1) {
                byteCount += 0x23;
            }
        }
        addr += 2;
    }

    DCStoreRange(saved, (u32)(__GDCurrentDL->pDisplayListData - saved));
}

extern "C" u8 isTexNoReg__FPv(void*);
extern "C" u16 getTexNoReg__FPv(void*);
extern "C" void fn_800D9FE4(int param_1, int param_2) {
    GDSetCurrOffset(param_2);
    u8* start = GDGetCurrPointer();
    u8* cur = __GDCurrentDL->pDisplayListData;
    u32 i = 0;
    while (true) {
        if (!isTexNoReg(cur)) break;
        loadTexNo(i, getTexNoReg(cur));
        i++;
    }
    DCStoreRange(start, GDGetCurrPointer() - start);
}

extern "C" void fn_800DA280(u8* this_, u32 flags) {
    if (flags & 0x08000000) {
        u8 stageNum = this_[4];
        ((J3DIndTexMtx*)(this_ + 0x18))->load(0);
        J3DGDSetIndTexCoordScale(GX_INDTEXSTAGE0, (GXIndTexScale)this_[0x6c], (GXIndTexScale)this_[0x6d], (GXIndTexScale)this_[0x70], (GXIndTexScale)this_[0x71]);

        unsigned short* entry = (unsigned short*)(&sTexCoordScaleTable__6J3DSys) + ((this_[6] & 7) * 4);
        unsigned int lzS = __cntlzw(1 - entry[2]);
        unsigned int lzT = __cntlzw(1 - entry[3]);

        J3DGDSetTexCoordScale2__F13_GXTexCoordIDUsUcUcUsUcUc(this_[5], entry[0], (unsigned char)(lzS >> 5), (unsigned char)0, entry[1], (unsigned char)(lzT >> 5), (unsigned char)0);

        J3DGDSetIndTexOrder(stageNum, (GXTexCoordID)this_[5], (GXTexMapID)this_[6], (GXTexCoordID)this_[9], (GXTexMapID)this_[0xa], (GXTexCoordID)this_[0xd], (GXTexMapID)this_[0xe], (GXTexCoordID)this_[0x11], (GXTexMapID)this_[0x12]);
    }
}

extern "C" void fn_800DB844(void* param_1) {
    u32* gd = (u32*)&__GDCurrentDL;
    u32 size = *(u32*)((u8*)param_1 + 0x3c);
    u32 cur = *(u32*)gd;
    gd[2] = cur + size;
    
    u32 cur2 = gd[2];
    u32 cap = gd[3];
    if (cur2 > cap + 0x37) {
        GDOverflowed();
    }
    
    gd = (u32*)&__GDCurrentDL;
    u32 dl_ptr = gd[2];
    
    GXFogType fog_type = (GXFogType)*(u8*)((u8*)param_1 + 0x4);
    f32 f1 = *(f32*)((u8*)param_1 + 0x8);
    f32 f2 = *(f32*)((u8*)param_1 + 0xc);
    f32 f3 = *(f32*)((u8*)param_1 + 0x10);
    f32 f4 = *(f32*)((u8*)param_1 + 0x14);
    GXColor color = *(GXColor*)((u8*)param_1 + 0x18);
    
    J3DGDSetFog(fog_type, f1, f2, f3, f4, color);
    
    GXFogAdjTable* adj_tbl = (GXFogAdjTable*)((u8*)param_1 + 0x1c);
    u8 adj_type = *(u8*)((u8*)param_1 + 0x5);
    u16 adj_val = *(u16*)((u8*)param_1 + 0x6);
    
    J3DGDSetFogRangeAdj(adj_type, adj_val, adj_tbl);
    
    gd = (u32*)&__GDCurrentDL;
    u32 dl_end = gd[2];
    DCStoreRange((void*)dl_ptr, dl_end - dl_ptr);
}

extern "C" void GDOverflowed(void);
extern "C" void J3DGDSetFog__F10_GXFogTypeffff8_GXColor(u8, u32, float, float, float, float);
extern "C" void J3DGDSetFogRangeAdj__FUcUsP14_GXFogAdjTable(u8, u16, void*);
extern "C" void fn_800DB8F4(void* param_1) {
    u32* gd = (u32*)&__GDCurrentDL;
    u32 cur = gd[2];
    u32 max = gd[3];
    
    if (cur + 0x37 > max) {
        GDOverflowed();
    }
    
    u8* p = (u8*)param_1;
    u32 color = *(u32*)(p + 0x18);
    u8 type = p[4];
    float f1 = *(float*)(p + 0x8);
    float f2 = *(float*)(p + 0xc);
    float f3 = *(float*)(p + 0x10);
    float f4 = *(float*)(p + 0x14);
    
    J3DGDSetFog__F10_GXFogTypeffff8_GXColor(type, color, f1, f2, f3, f4);
    
    u8 uc = p[5];
    u16 us = *(u16*)(p + 6);
    J3DGDSetFogRangeAdj__FUcUsP14_GXFogAdjTable(uc, us, p + 0x1c);
}

extern "C" void fn_800DBC64(void* obj, u32 flags) {
    if (flags & 0x10000000) {
        typedef void (*FuncPtr)(void);
        void* vtable = *(void**)obj;
        FuncPtr fn = *(FuncPtr*)((u8*)vtable + 0x18);
        fn();
    }
    if (flags & 0x20000000) {
        typedef void (*FuncPtr)(void*);
        void* vtable = *(void**)obj;
        FuncPtr fn = *(FuncPtr*)((u8*)vtable + 0x1c);
        fn(obj);
    }
}

extern "C" void fn_800DBCCC(u8* self, Unk800DBCCCSrc* src) {
    *(u8*)(self + 0xc) = src->getColorChanNum();
    u8* dst = self;
    for (u32 i = 0; i < 2; i++) {
        u8* c = src->getMatColor(i);
        dst[4] = c[0];
        dst[5] = c[1];
        dst[6] = c[2];
        dst[7] = c[3];
        dst += 4;
    }
    u32 i;
    for (i = 0, dst = self; i < 4; i++) {
        *(u16*)(dst + 0xe) = *src->getColorChan(i);
        dst += 2;
    }
}

extern "C" void fn_800DC574(u8* param_1, int* param_2) {
    int* obj = param_2;
    *(u16*)(param_1 + 8) = (*(u16(**)(int*, int))(*(u8**)obj + 0x50))(obj, 0);
    *(u32*)(param_1 + 0xa) = *(u32*)((*(u32*(**)(int*, int))(*(u8**)obj + 0x5c))(obj, 0));
    u8* p = (*(u8*(**)(int*, int))(*(u8**)obj + 0xa4))(obj, 0);
    param_1[0xf] = p[1];
    param_1[0x10] = p[2];
    param_1[0x11] = p[3];
    param_1[0x13] = p[5];
    param_1[0x14] = p[6];
    param_1[0x15] = p[7];
    *(u32*)(param_1 + 0x18) = *(u32*)((*(u32*(**)(int*, int))(*(u8**)obj + 0xc4))(obj, 0));
}

extern "C" void fn_800DD148(u8* this_, void* obj) {
    void** vt = *(void***)obj;
    u32 id = ((u32 (*)(void*))vt[9])(obj);
    if (id == 0x5045464c || (id < 0x5045464c && id == 0x50454647)) {
        u8* p = (u8*)((void* (*)(void*))vt[15])(obj);
        *(u16*)(this_ + 0x4) = *(u16*)p;
        this_[0x6] = p[2];
        this_[0x7] = p[3];
        u32* q = (u32*)((void* (*)(void*))vt[18])(obj);
        *(u32*)(this_ + 0x8) = *q;
        u16* r = (u16*)((void* (*)(void*))vt[21])(obj);
        *(u16*)(this_ + 0xc) = *r;
        this_[0xe] = ((u8 (*)(void*))vt[24])(obj);
    }
}

extern "C" u32 fn_800DD89C() {
    return 'PEFL';
}

extern "C" void fn_800DD8A8(u8* self, const J3DFogInfo* other) {
    *(J3DFogInfo*)(self + 4) = *other;
}

extern "C" void fn_800DD8CC(u8* self, const J3DFogInfo* other) {
    *(J3DFogInfo*)(self + 4) = *other;
}

extern "C" int fn_800DD8F0(int param_1) {
    return param_1 + 4;
}

extern "C" void fn_800DD8F8(u8* self, const u8* other) {
    *(u16*)(self + 0x30) = *(const u16*)other;
    self[0x32] = other[2];
    self[0x33] = other[3];
}

extern "C" void fn_800DD914(u8* self, const u8* other) {
    *(u16*)(self + 0x30) = *(const u16*)other;
    self[0x32] = other[2];
    self[0x33] = other[3];
}

extern "C" void* fn_800DD930(u8* this_) {
    return this_ + 0x30;
}

extern "C" void fn_800DD938(u8* this_, const u32* src) {
    *(u32*)(this_ + 0x34) = *src;
}

extern "C" void fn_800DD944(u8* this_, const u32* src) {
    *(u32*)(this_ + 0x34) = *src;
}

extern "C" u32* fn_800DD950(u8* this_) {
    return (u32*)(this_ + 0x34);
}

extern "C" void fn_800DD958(u8* this_, const u16* src) {
    *(u16*)(this_ + 0x38) = *src;
}

extern "C" void fn_800DD964(u8* this_, const u16* src) {
    *(u16*)(this_ + 0x38) = *src;
}

extern "C" u8* fn_800DD970(u8* self) {
    return self + 0x38;
}

extern "C" void fn_800DD978(int param_1, u8 param_2) {
    *(u8*)(param_1 + 0x3a) = param_2;
}

extern "C" void fn_800DD980(int param_1, u8* param_2) {
    *(u8*)(param_1 + 0x3a) = *param_2;
}

extern "C" u8 fn_800DD98C(u8* param_1) {
    return *(u8*)(param_1 + 0x3a);
}

extern "C" void fn_800DD994(u8* param_1, u8 param_2) {
    *(u8*)(param_1 + 0x3b) = param_2;
}

extern "C" void fn_800DD99C(u8* param_1, u8* param_2) {
    *(u8*)(param_1 + 0x3b) = *param_2;
}

extern "C" u8 fn_800DD9A8(u8* p) { return p[0x3b]; }

extern "C" u32 fn_800DD9B0(u8* p) { return *(u32*)(p + 0x3c); }

extern "C" void fn_800DD9B8(u8* p, u32 v) { *(u32*)(p + 0x3c) = v; }

extern "C" void* fn_800DD9C0(void* param_1, short param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = &__vt__14J3DPEBlockFull;
        if (param_2 != 0) {
            *(void**)param_1 = &__vt__10J3DPEBlock;
        }
        if ((short)param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_800DDA1C(void* obj, u32 flags) {
    if (flags & 0x20000000) {
        typedef void (*FuncPtr)(void);
        register void* vtable = *(void**)obj;
        FuncPtr fn = *(FuncPtr*)((u8*)vtable + 0x1c);
        fn();
    }
}

extern "C" u32 fn_800DDA50(void) {
    return 0x50454647;
}

#if defined(VERSION_G4SJ01)
extern "C" void fn_800DDA5C(u8* this_, u8* src) {
    u16 id = *(u16*)src;
    *(u16*)(this_ + 0x4) = id;
    u8 ref0 = src[2];
    *(u8*)(this_ + 0x6) = ref0;
    *(u8*)(this_ + 0x7) = src[3];
}
#else
extern "C" void fn_800DDA5C(u8* this_, u8* src) {
    u16 w = *(u16*)src;
    u8 b2 = src[2];
    *(u16*)(this_ + 0x4) = w;
    u8 b3 = src[3];
    *(u8*)(this_ + 0x6) = b2;
    *(u8*)(this_ + 0x7) = b3;
}
#endif

extern "C" void* fn_800DDA94(u8* this_) {
    return this_ + 4;
}

extern "C" void fn_800DDA9C(void* dst, const void* src) {
    *(u32*)((u8*)dst + 8) = *(const u32*)src;
}

extern "C" void fn_800DDAA8(void* dst, const void* src) {
    *(u32*)((u8*)dst + 8) = *(const u32*)src;
}

extern "C" u32* fn_800DDAB4(u8* this_) {
    return (u32*)(this_ + 8);
}

extern "C" void fn_800DDABC(u8* this_, const u16* src) {
    *(u16*)(this_ + 0xc) = *src;
}

extern "C" void fn_800DDAC8(u8* this_, const u16* src) {
    *(u16*)(this_ + 0xc) = *src;
}

extern "C" Vec* fn_800DDAD4(Actor* a);
extern "C" Vec* fn_800DDAD4(Actor* a) { return (Vec*)((u8*)a + 0xC); }

extern "C" void fn_800DDADC(u8* this_, u8 val) {
    this_[0xe] = val;
}

extern "C" void fn_800DDAE4(u8* this_, u8* src) {
    *(u8*)(this_ + 0xe) = *src;
}

extern "C" u8 fn_800DDAF0(u8* self) {
    return *(u8*)(self + 0xe);
}

extern "C" void fn_800DDAF8(u8* self, u8 val) {
    *(u8*)(self + 0xf) = val;
}

extern "C" void fn_800DDB00(int param_1, u8* param_2)
{
  *(u8*)(param_1 + 0xf) = *param_2;
}

extern "C" u8 fn_800DDB0C(int param_1)
{
  return *(u8*)(param_1 + 0xf);
}

extern "C" void* fn_800DDB14(void* param_1, short param_2)
{
  if (param_1 != nullptr) {
    void* vt1 = &__vt__16J3DPEBlockFogOff;
    *(void**)param_1 = vt1;
    void* vt2 = &__vt__10J3DPEBlock;
    *(void**)param_1 = vt2;
    if (param_2 > 0) {
      __dl__FPv(param_1);
    }
  }
  return param_1;
}

extern "C" bool isTexNoReg(void*);
extern "C" u16 getTexNoReg(void*);
extern "C" void loadTexNo(u32, const u16&);
extern "C" void DCStoreRange(void* addr, u32 nBytes);
extern "C" void fn_800DDB70(void* param_1)
{
  u32 i = 0;
  __GDCurrentDL->pDisplayListData = __GDCurrentDL->begin + *(u32*)((u8*)param_1 + 4);
  void* pStart = GDGetCurrPointer();
  for (;;) {
    void* pCurr = GDGetCurrPointer();
    if (!isTexNoReg(pCurr)) break;
    u16 texNo = getTexNoReg(pCurr);
    loadTexNo(i, texNo);
    i++;
  }
  DCStoreRange(pStart, (u8*)__GDCurrentDL->pDisplayListData - (u8*)pStart);
}

extern "C" u32 fn_800DDC10() {
    return 'TV16';
}

extern "C" void fn_800DDC1C(u16* this_, s32 idx, u16 val) {
    this_[idx + 4] = val;
}

extern "C" void fn_800DDC2C(u16* this_, s32 idx, u16* src) {
    this_[idx + 4] = *src;
}

extern "C" u16 fn_800DDC40(u16* this_, s32 idx) {
    return this_[idx + 4];
}

extern "C" void fn_800DDC50(u8* this_, s32 idx, u32* src) {
    *(u32*)(this_ + 0x18 + idx * 4) = *src;
}

extern "C" void fn_800DDC64(u8* this_, s32 idx, u32* src) {
    *(u32*)(this_ + 0x18 + idx * 4) = *src;
}

extern "C" u32* fn_800DDC78(u8* this_, s32 idx) {
    return (u32*)(this_ + 0x18 + idx * 4);
}

extern "C" void fn_800DDC8C(Unk800DDC8C* this_, s32 idx, const s16* src) {
    this_->a[idx][0] = src[0];
    this_->a[idx][1] = src[1];
    this_->a[idx][2] = src[2];
    this_->a[idx][3] = src[3];
}

extern "C" void fn_800DDCB8(Unk800DDC8C* this_, s32 idx, const s16* src) {
    this_->a[idx][0] = src[0];
    this_->a[idx][1] = src[1];
    this_->a[idx][2] = src[2];
    this_->a[idx][3] = src[3];
}

extern "C" void* fn_800DDCE4(u8* this_, s32 idx) {
    return this_ + 0xda + idx * 8;
}

extern "C" void fn_800DDCF8(Unk800DDC8C* this_, s32 idx, const u8* src) {
    this_->b[idx][0] = src[0];
    this_->b[idx][1] = src[1];
    this_->b[idx][2] = src[2];
    this_->b[idx][3] = src[3];
}

extern "C" void fn_800DDD24(Unk800DDC8C* this_, s32 idx, const u8* src) {
    this_->b[idx][0] = src[0];
    this_->b[idx][1] = src[1];
    this_->b[idx][2] = src[2];
    this_->b[idx][3] = src[3];
}

extern "C" u8* fn_800DDD50(Unk800DDC8C* this_, s32 idx) {
    return this_->b[idx];
}

#if defined(VERSION_G4SJ01)
extern "C" void fn_800DDD64(u8* param_1, int param_2, u8 param_3) {
    param_1[param_2 + 0x10a] = param_3;
}
#else
extern "C" void fn_800DDD64(int param_1, int param_2, u8 param_3) {
    ((u8*)param_1 + param_2)[0x10a] = param_3;
}
#endif

extern "C" void fn_800DDD70(u8* param_1, int param_2, u8* param_3) {
    u8 v = *param_3;
    (param_1 + param_2)[0x10a] = v;
}

extern "C" u8 fn_800DDD80(int param_1, int param_2) {
    param_1 += param_2;
    return *(u8 *)(param_1 + 0x10a);
}

extern "C" void fn_800DDD8C(int param_1, int param_2, u8 param_3) {
    param_1 += param_2;
    *(u8 *)(param_1 + 0x11a) = param_3;
}

extern "C" void fn_800DDD98(int param_1, int param_2, u8 *param_3) {
    u8 v0 = param_3[0];
    param_1 += param_2;
    *(u8 *)(param_1 + 0x11a) = v0;
}

extern "C" u8 fn_800DDDA8(int param_1, int param_2) {
    param_1 += param_2;
    return *(u8 *)(param_1 + 0x11a);
}

extern "C" void fn_800DDDB4(int param_1, u8 param_2) {
    *(u8 *)(param_1 + 0x58) = param_2;
}

extern "C" void fn_800DDDBC(int param_1, u8 *param_2) {
    *(u8 *)(param_1 + 0x58) = *param_2;
}

extern "C" unsigned char fn_800DDDC8(int param_1) {
    return *(unsigned char *)(param_1 + 0x58);
}

extern "C" void fn_800DDDD0(int param_1, int param_2, u8 *param_3) {
    u8 v1 = param_3[1];
    param_1 = param_1 + param_2 * 8;
    u8 v2 = param_3[2];
    *(u8 *)(param_1 + 0x5a) = v1;
    u8 v3 = param_3[3];
    *(u8 *)(param_1 + 0x5b) = v2;
    u8 v5 = param_3[5];
    *(u8 *)(param_1 + 0x5c) = v3;
    u8 v6 = param_3[6];
    *(u8 *)(param_1 + 0x5e) = v5;
    u8 v7 = param_3[7];
    *(u8 *)(param_1 + 0x5f) = v6;
    *(u8 *)(param_1 + 0x60) = v7;
}

extern "C" int fn_800DDE48(int param_1, int param_2) {
    return param_1 + param_2 * 8 + 0x59;
}

extern "C" void fn_800DDE5C(u8* param_1, int param_2, u8* param_3) {
    u8 b0 = param_3[0];
    param_1[param_2 * 8 + 0x60] = (param_1[param_2 * 8 + 0x60] & ~0xC) | (param_3[1] << 2);
    param_1[param_2 * 8 + 0x60] = (param_1[param_2 * 8 + 0x60] & ~0x3) | b0;
}

extern "C" void fn_800DDECC(u8* this_, s32 idx, u8* src) {
    this_[idx + 0x12a] = *src;
}

extern "C" void fn_800DDEDC(u8* this_, s32 idx, u8* src) {
    this_[idx + 0x12a] = *src;
}

extern "C" u8* fn_800DDEEC(u8* this_, s32 idx) {
    return this_ + 0x12a + idx;
}

extern "C" void fn_800DDEFC(u32* this_, s32 idx, u32* src) {
    this_[idx + 0x4c] = *src;
}

extern "C" void fn_800DDF10(u32* this_, s32 idx, u32* src) {
    this_[idx + 0x4c] = *src;
}

extern "C" u32* fn_800DDF24(u8* this_, s32 idx) {
    return (u32*)(this_ + 0x130 + idx * 4);
}

extern "C" u32 fn_800DDF38(int param_1) {
    return *(u32*)(param_1 + 4);
}

extern "C" u32 fn_800DDF40(int param_1) {
    return *(u32*)(param_1 + 0x170);
}

extern "C" void fn_800DDF48(Actor* a, u32 v);
extern "C" void fn_800DDF48(Actor* a, u32 v) { *(u32*)((u8*)a + 0x170) = v; }

extern "C" void** fn_800DDF50(void** param_1, short param_2) {
    if (param_1 != NULL) {
        *param_1 = __vt__13J3DTevBlock16;
        if (param_1 != NULL) {
            *param_1 = __vt__11J3DTevBlock;
        }
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_800DDFAC(void) {
}

extern "C" void fn_800DDFB0(void* param_1)
{
  u32 i = 0;
  __GDCurrentDL->pDisplayListData = __GDCurrentDL->begin + *(u32*)((u8*)param_1 + 4);
  void* pStart = GDGetCurrPointer();
  for (;;) {
    void* pCurr = GDGetCurrPointer();
    if (!isTexNoReg(pCurr)) break;
    u16 texNo = getTexNoReg(pCurr);
    loadTexNo(i, texNo);
    i++;
  }
  DCStoreRange(pStart, (u8*)__GDCurrentDL->pDisplayListData - (u8*)pStart);
}

extern "C" u32 fn_800DE050(void) {
    return 'TVB4';
}

extern "C" void fn_800DE05C(u16* this_, s32 idx, u16 val) {
    this_[idx + 4] = val;
}

extern "C" void fn_800DE06C(u16* this_, s32 idx, u16* src) {
    this_[idx + 4] = *src;
}

extern "C" u16 fn_800DE080(u16* this_, s32 idx) {
    return this_[idx + 4];
}

extern "C" void fn_800DE090(u8* this_, u32 idx, const u32* src) {
    *(u32*)(this_ + idx * 4 + 0x10) = *src;
}

extern "C" void fn_800DE0A4(u8* this_, u32 idx, const u32* src) {
    *(u32*)(this_ + idx * 4 + 0x10) = *src;
}

extern "C" u32* fn_800DE0B8(u32* this_, u32 idx) {
    return &this_[4] + idx;
}

extern "C" void fn_800DE0CC(Unk800DE0CC* p, int i, const Unk800DE50C& v) {
    p->a[i] = v;
}

extern "C" void fn_800DE0F8(Unk800DE0CC* p, int i, const Unk800DE50C& v) {
    p->a[i] = v;
}

extern "C" Unk800DE50C* fn_800DE124(Unk800DE0CC* p, int i) {
    return &p->a[i];
}

extern "C" void fn_800DE138(Unk800DE0CC* p, int i, const Unk800DE578& v) {
    p->b[i] = v;
}

extern "C" void fn_800DE164(u8* this_, u32 idx, const u8* src) {
    (this_ + idx * 4)[0x62] = src[0];
    (this_ + idx * 4)[0x63] = src[1];
    (this_ + idx * 4)[0x64] = src[2];
    (this_ + idx * 4)[0x65] = src[3];
}

extern "C" Unk800DE578* fn_800DE190(Unk800DE0CC* p, int i) {
    return &p->b[i];
}

extern "C" char __vt__13J3DTevBlock16[];
extern "C" void fn_800DE1A4(u8* param_1, int param_2, u8 param_3) {
    param_1[param_2 + 0x72] = param_3;
}

extern "C" void fn_800DE1B0(int param_1, int param_2, u8* param_3)
{
  u8* ptr = (u8*)param_1;
  *(ptr + param_2 + 0x72) = *param_3;
}

extern "C" u8 fn_800DE1C0(int param_1, int param_2)
{
  u8* ptr = (u8*)param_1;
  return *(ptr + param_2 + 0x72);
}

extern "C" void fn_800DE1CC(int param_1, int param_2, u8 param_3)
{
  u8* ptr = (u8*)param_1;
  *(ptr + param_2 + 0x76) = param_3;
}

extern "C" void fn_800DE1D8(int param_1, int param_2, u8* param_3)
{
  u8* ptr = (u8*)param_1;
  *(ptr + param_2 + 0x76) = *param_3;
}

extern "C" u8 fn_800DE1E8(int param_1, int param_2)
{
  int sum = param_1 + param_2;
  return *(u8*)(sum + 0x76);
}

extern "C" void fn_800DE1F4(u8* param_1, u8 param_2)
{
  *(u8*)(param_1 + 0x20) = param_2;
}

extern "C" void fn_800DE1FC(u8* param_1, u8* param_2)
{
  *(u8*)(param_1 + 0x20) = *param_2;
}

extern "C" u8 fn_800DE208(int param_1)
{
  return *(u8*)(param_1 + 0x20);
}

extern "C" void fn_800DE210(int param_1, int param_2, u8* param_3)
{
  int offset = param_1 + param_2 * 8;
  *(u8*)(offset + 0x22) = param_3[1];
  *(u8*)(offset + 0x23) = param_3[2];
  *(u8*)(offset + 0x24) = param_3[3];
  *(u8*)(offset + 0x26) = param_3[5];
  *(u8*)(offset + 0x27) = param_3[6];
  *(u8*)(offset + 0x28) = param_3[7];
}

extern "C" int fn_800DE288(int param_1, int param_2)
{
  return param_1 + param_2 * 8 + 0x21;
}

struct fn_800DE29C_Bits2 {
  u8 hi : 4;
  u8 b : 2;
  u8 a : 2;
};

extern "C" void fn_800DE29C(u8* param_1, int param_2, u8* param_3)
{
  u8* e = &param_1[param_2 * 8];
  u8 b1 = param_3[1];
  u8 b0 = param_3[0];
  e[0x28] = (b1 << 2) | (e[0x28] & ~0xC);
  e[0x28] = b0 | (e[0x28] & ~0x3);
}

extern "C" void fn_800DE30C(u8* this_, s32 idx, u8* src) {
    this_[idx + 0x7a] = *src;
}

extern "C" void fn_800DE31C(u8* this_, s32 idx, u8* src) {
    this_[idx + 0x7a] = *src;
}

extern "C" u8* fn_800DE32C(u8* this_, s32 idx) {
    return this_ + 0x7a + idx;
}

extern "C" void fn_800DE33C(u32* this_, s32 idx, u32* src) {
    this_[idx + 0x20] = *src;
}

extern "C" void fn_800DE350(u32* this_, s32 idx, u32* src) {
    this_[idx + 0x20] = *src;
}

extern "C" u32* fn_800DE364(u8* this_, s32 idx) {
    return (u32*)(this_ + 0x80 + idx * 4);
}

extern "C" void* fn_800DE378(u8* this_) {
    return *(void**)(this_ + 4);
}

extern "C" void* fn_800DE380(u8* this_) {
    return *(void**)(this_ + 0x90);
}

extern "C" void fn_800DE388(Actor* a, u32 v);
extern "C" void fn_800DE388(Actor* a, u32 v) { *(u32*)((u8*)a + 0x90) = v; }

extern "C" void fn_800DE3EC(void) {
}

extern "C" void fn_800DE3F0(void* param_1)
{
  u32 i = 0;
  __GDCurrentDL->pDisplayListData = __GDCurrentDL->begin + *(u32*)((u8*)param_1 + 4);
  void* pStart = GDGetCurrPointer();
  for (;;) {
    void* pCurr = GDGetCurrPointer();
    if (!isTexNoReg(pCurr)) break;
    u16 texNo = getTexNoReg(pCurr);
    loadTexNo(i, texNo);
    i++;
  }
  DCStoreRange(pStart, (u8*)__GDCurrentDL->pDisplayListData - (u8*)pStart);
}

extern "C" u32 fn_800DE490(void) {
    return 'TVB2';
}

extern "C" void fn_800DE49C(u16* this_, s32 idx, u16 val) {
    this_[idx + 4] = val;
}

extern "C" void fn_800DE4AC(u16* this_, s32 idx, u16* src) {
    this_[idx + 4] = *src;
}

extern "C" u16 fn_800DE4C0(u16* this_, s32 idx) {
    return this_[idx + 4];
}

extern "C" void fn_800DE4D0(Unk800DE4D0* p, int i, const u32& v) {
    ((u32*)p)[i + 3] = v;
}

extern "C" void fn_800DE4E4(Unk800DE4D0* p, int i, const u32& v) {
    ((u32*)p)[i + 3] = v;
}

extern "C" u32* fn_800DE4F8(Unk800DE4D0* p, int i) {
    return &p->a[i];
}

extern "C" void fn_800DE50C(Unk800DE4D0* p, int i, const Unk800DE50C& v) {
    p->b[i] = v;
}

extern "C" void fn_800DE538(Unk800DE4D0* p, int i, const Unk800DE50C& v) {
    p->b[i] = v;
}

extern "C" Unk800DE50C* fn_800DE564(Unk800DE4D0* p, int i) {
    return &p->b[i];
}

extern "C" void fn_800DE578(Unk800DE5D0* p, int i, const Unk800DE578& v) {
    p->a[i] = v;
}

extern "C" void fn_800DE5A4(Unk800DE5D0* p, int i, const Unk800DE578& v) {
    p->a[i] = v;
}

extern "C" Unk800DE578* fn_800DE5D0(Unk800DE5D0* p, int i) {
    return &p->a[i];
}

extern "C" void fn_800DE5E4(Unk800DE5D0* p, int i, u8 v) {
    p->b[i] = v;
}

extern "C" void fn_800DE5F0(Unk800DE5D0* p, int i, const u8& v) {
    p->b[i] = v;
}

extern "C" u8 fn_800DE600(int param_1, int param_2)
{
  u8* ptr = (u8*)(param_1 + param_2);
  return *((u8*)ptr + 0x55);
}

extern "C" void fn_800DE60C(int param_1, int param_2, u8 param_3)
{
  u8* ptr = (u8*)(param_1 + param_2);
  *((u8*)ptr + 0x57) = param_3;
}

extern "C" void fn_800DE618(int param_1, int param_2, u8* param_3)
{
  u8* ptr = (u8*)(param_1 + param_2);
  *((u8*)ptr + 0x57) = *param_3;
}

extern "C" u8 fn_800DE628(int param_1, int param_2) {
    return *(u8*)((unsigned)param_1 + (unsigned)param_2 + 0x57);
}

extern "C" void fn_800DE634(u8* param_1, u8 param_2) {
    *(u8*)(param_1 + 0x34) = param_2;
}

extern "C" void fn_800DE63C(u8* param_1, u8* param_2) {
    *(u8*)(param_1 + 0x34) = *param_2;
}

extern "C" u8 fn_800DE648(int param_1) {
    return *(u8*)(param_1 + 0x34);
}

extern "C" void fn_800DE650(u8* this_, s32 idx, GXColor* src) {
    u8* p = this_ + idx * 8;
    u8 t;
    t = src[0].g; p[0x36] = t;
    t = src[0].b; p[0x37] = t;
    t = src[0].a; p[0x38] = t;
    t = src[1].g; p[0x3a] = t;
    t = src[1].b; p[0x3b] = t;
    t = src[1].a; p[0x3c] = t;
}

extern "C" int fn_800DE6C8(int param_1, int param_2) {
    return param_1 + param_2 * 8 + 0x35;
}

extern "C" void fn_800DE6DC(Unk800DE6DC* param_1, int param_2, const u8* param_3) {
    param_1->mStage[param_2].setSwapModeInfo(param_3);
}

extern "C" void fn_800DE714(Unk800DE6DC* param_1, int param_2, const u8* param_3) {
    param_1->mStage[param_2].setSwapModeInfo(param_3);
}

extern "C" void fn_800DE74C(u8* this_, u32 idx, const u8* src) {
    this_[idx + 0x59] = *src;
}

extern "C" void fn_800DE75C(u8* this_, u32 idx, const u8* src) {
    this_[idx + 0x59] = *src;
}

extern "C" u8* fn_800DE76C(u8* this_, u32 idx) {
    return &this_[0x59] + idx;
}

extern "C" void fn_800DE77C(u32* this_, u32 idx, const u32* src) {
    this_[idx + 0x18] = *src;
}

extern "C" void fn_800DE790(u32* this_, u32 idx, const u32* src) {
    this_[idx + 0x18] = *src;
}

extern "C" u32* fn_800DE7A4(u32* this_, u32 idx) {
    return &this_[0x18] + idx;
}

extern "C" u32 fn_800DE7B8(u8* p) { return *(u32*)(p + 4); }

extern "C" u32 fn_800DE7C0(u8* p) { return *(u32*)(p + 0x68); }

extern "C" void fn_800DE7C8(u8* p, u32 v) { *(u32*)(p + 0x68) = v; }

extern "C" char __vt__12J3DTevBlock4[];
extern "C" char __vt__12J3DTevBlock2[];
extern "C" char __vt__11J3DTevBlock[];
extern "C" void* fn_800DE7D0(void* p, s16 del) {
    if (p) {
        *(void**)p = __vt__12J3DTevBlock2;
        if (p) {
            *(void**)p = __vt__11J3DTevBlock;
        }
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void fn_800DE82C(void) {}

extern "C" void fn_800DE830(void* param_1)
{
  u32 i = 0;
  __GDCurrentDL->pDisplayListData = __GDCurrentDL->begin + *(u32*)((u8*)param_1 + 4);
  void* pStart = GDGetCurrPointer();
  for (;;) {
    void* pCurr = GDGetCurrPointer();
    if (!isTexNoReg(pCurr)) break;
    u16 texNo = getTexNoReg(pCurr);
    loadTexNo(i, texNo);
    i++;
  }
  DCStoreRange(pStart, (u8*)__GDCurrentDL->pDisplayListData - (u8*)pStart);
}

extern "C" u32 fn_800DE8D0() {
    return 0x54564231;
}

extern "C" void fn_800DE8DC(u16* this_, s32 idx, u16 val) {
    this_[idx + 4] = val;
}

extern "C" void fn_800DE8EC(u16* this_, s32 idx, u16* src) {
    this_[idx + 4] = *src;
}

extern "C" u16 fn_800DE900(u16* this_, s32 idx) {
    return this_[idx + 4];
}

extern "C" void fn_800DE910(char* p, int i, u32* v) {
    *(u32*)(p + i * 4 + 10) = *v;
}

extern "C" void fn_800DE924(char* p, int i, u32* v) {
    *(u32*)(p + i * 4 + 10) = *v;
}

extern "C" u8* fn_800DE938(u8* this_, u32 idx) {
    return this_ + idx * 4 + 10;
}

extern "C" void fn_800DE94C(void) {}

extern "C" void fn_800DE950(void) {}

extern "C" u32 fn_800DE954() {
    return 1;
}

extern "C" void fn_800DE95C(u8* this_, s32 idx, const u8* src) {
    this_[idx * 8 + 0xf] = src[1];
    this_[idx * 8 + 0x10] = src[2];
    this_[idx * 8 + 0x11] = src[3];
    this_[idx * 8 + 0x13] = src[5];
    this_[idx * 8 + 0x14] = src[6];
    this_[idx * 8 + 0x15] = src[7];
}

extern "C" void fn_800DE998(u8* this_, s32 idx, const u8* src) {
    this_[idx * 8 + 0xf] = src[1];
    this_[idx * 8 + 0x10] = src[2];
    this_[idx * 8 + 0x11] = src[3];
    this_[idx * 8 + 0x13] = src[5];
    this_[idx * 8 + 0x14] = src[6];
    this_[idx * 8 + 0x15] = src[7];
}

extern "C" u8* fn_800DE9D4(u8* this_, s32 idx) {
    return this_ + idx * 8 + 0xe;
}

extern "C" void fn_800DE9E8(u8* this_, s32 idx, u32* src) {
    ((u32*)(this_ + 0x18))[idx] = *src;
}

extern "C" void fn_800DE9FC(u8* this_, s32 idx, u32* src) {
    ((u32*)(this_ + 0x18))[idx] = *src;
}

extern "C" u32* fn_800DEA10(u8* this_, s32 idx) {
    return (u32*)(this_ + 0x18 + idx * 4);
}

extern "C" u32 fn_800DEA24(u8* this_) {
    return *(u32*)(this_ + 4);
}

extern "C" void fn_800DEA88(void) {}

extern "C" void fn_800DEA8C(void* param_1)
{
  u32 i = 0;
  __GDCurrentDL->pDisplayListData = __GDCurrentDL->begin + *(u32*)((u8*)param_1 + 4);
  void* pStart = GDGetCurrPointer();
  for (;;) {
    void* pCurr = GDGetCurrPointer();
    if (!isTexNoReg(pCurr)) break;
    u16 texNo = getTexNoReg(pCurr);
    loadTexNo(i, texNo);
    i++;
  }
  DCStoreRange(pStart, (u8*)__GDCurrentDL->pDisplayListData - (u8*)pStart);
}

unsigned int fn_800DEB2C(void) {
    return 0x54565054U;
}

extern "C" void fn_800DEB38(u8* p, u8 v) {
    p[0xd0] = v;
}

extern "C" void fn_800DEB40(u8* p, const u8* v) {
    p[0xd0] = *v;
}

extern "C" u8 fn_800DEB4C(u8* p) {
    return p[0xd0];
}

extern "C" void fn_800DEB54(u16* this_, s32 idx, u16 val) {
    this_[idx + 4] = val;
}

extern "C" void fn_800DEB64(u16* this_, s32 idx, u16* src) {
    this_[idx + 4] = *src;
}

extern "C" u16 fn_800DEB78(u16* this_, s32 idx) {
    return this_[idx + 4];
}

extern "C" void fn_800DEB88(u8* this_, s32 idx, u32* src) {
    *(u32*)(this_ + 0x18 + idx * 4) = *src;
}

extern "C" void fn_800DEB9C(u8* this_, s32 idx, u32* src) {
    *(u32*)(this_ + 0x18 + idx * 4) = *src;
}

extern "C" u32* fn_800DEBB0(u8* this_, s32 idx) {
    return (u32*)(this_ + 0x18 + idx * 4);
}

extern "C" void fn_800DEBC4(u8* p, int i, const u8* v) {
    (p + i * 8)[0x39] = v[1];
    (p + i * 8)[0x3a] = v[2];
    (p + i * 8)[0x3b] = v[3];
    (p + i * 8)[0x3d] = v[5];
    (p + i * 8)[0x3e] = v[6];
    (p + i * 8)[0x3f] = v[7];
}

extern "C" void fn_800DEC00(u8* p, int i, const u8* v) {
    (p + i * 8)[0x39] = v[1];
    (p + i * 8)[0x3a] = v[2];
    (p + i * 8)[0x3b] = v[3];
    (p + i * 8)[0x3d] = v[5];
    (p + i * 8)[0x3e] = v[6];
    (p + i * 8)[0x3f] = v[7];
}

extern "C" Unk800DE50C* fn_800DEC3C(Unk800DEC3C* p, int i) {
    return &p->a[i];
}

extern "C" void fn_800DEC50(Unk800DEC3C* p, int i, const u32& v) {
    p->b[i] = v;
}

extern "C" void fn_800DEC64(u8* p, int i, const u32& v) {
    ((u32*)(p + 0x78))[i] = v;
}

extern "C" u32* fn_800DEC78(Unk800DEC3C* p, int i) {
    return &p->b[i];
}

extern "C" void fn_800DEC8C(Unk800DEC3C* p, int i, const Unk800DE50C& v) {
    p->c[i] = v;
}

extern "C" void fn_800DECB8(Unk800DEC3C* p, int i, const Unk800DE50C& v) {
    p->c[i] = v;
}

extern "C" int fn_800DECE4(int p, int i) {
    return p + i * 8 + 0x98;
}

extern "C" void fn_800DECF8(int p, int i, const u8* v)
{
    u8* base = (u8*)p;
    int offset = i << 2;
    base[offset + 0xb8] = v[0];
    base[offset + 0xb9] = v[1];
    base[offset + 0xba] = v[2];
    base[offset + 0xbb] = v[3];
}

extern "C" void fn_800DED24(int p, int i, const u8* v)
{
    u8* base = (u8*)p;
    int offset = i << 2;
    base[offset + 0xb8] = v[0];
    base[offset + 0xb9] = v[1];
    base[offset + 0xba] = v[2];
    base[offset + 0xbb] = v[3];
}

extern "C" int fn_800DED50(int p, int i) {
    return p + i * 4 + 0xb8;
}

extern "C" void fn_800DED64(int p, int i, int v) {
    int addr = p + i;
    *(u8*)(addr + 0xc8) = v;
}

extern "C" void fn_800DED70(int param_1, int param_2, const u8* param_3)
{
    u8* base = (u8*)param_1;
    base[param_2 + 0xc8] = param_3[0];
}

extern "C" u8 fn_800DED80(int param_1, int param_2)
{
    u8* base = (u8*)param_1;
    return base[param_2 + 0xc8];
}

extern "C" u32 fn_800DED8C(int param_1)
{
    return *(u32*)(param_1 + 4);
}

extern "C" u32 fn_800DED94(u8* param_1) {
    return *(u32*)(param_1 + 0xd4);
}

extern "C" void fn_800DED9C(u8* param_1, u32 param_2) {
    *(u32*)(param_1 + 0xd4) = param_2;
}

extern char lbl_8049B440[];
extern char __vt__11J3DTevBlock[];
extern "C" u32* fn_800DEDA4(u32* self, short flag) {
    if (self != NULL) {
        u32 tmp;
        tmp = (u32)lbl_8049B440;
        self[0] = tmp;
        tmp = (u32)&__vt__11J3DTevBlock;
        self[0] = tmp;
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

extern "C" u32 fn_800DEE00(void) {
    return 0x54474243;
}

extern "C" void fn_800DEE0C(u8* self, const J3DNBTScaleInfo* other) {
    *(J3DNBTScaleInfo*)(self + 0x5c) = *other;
}

extern "C" void fn_800DEE30(u8* self, const J3DNBTScaleInfo* other) {
    *(J3DNBTScaleInfo*)(self + 0x5c) = *other;
}

extern "C" u8* fn_800DEE54(u8* self) {
    return self + 0x5c;
}

extern "C" void* fn_800DEE5C(void* param_1, short param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)&__vt__19J3DTexGenBlockBasic;
        if (param_2 != 0) {
            *(void**)param_1 = (void*)&__vt__21J3DTexGenBlockPatched;
        }
        if (param_2 != 0) {
            *(void**)param_1 = (void*)&__vt__14J3DTexGenBlock;
        }
        if ((short)param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_800DEEC8(Actor* a, s32 v);
extern "C" void fn_800DEEC8(Actor* a, s32 v) { *(s32*)((u8*)a + 0x4) = v; }

extern "C" void fn_800DEED0(int param_1, u32* param_2)
{
  *(u32*)(param_1 + 4) = *param_2;
}

extern "C" u32 fn_800DEEDC(int param_1)
{
  return *(u32*)(param_1 + 4);
}

extern "C" void fn_800DEEE4(int param_1, int param_2, u32* param_3)
{
  *(u32*)(param_1 + param_2 * 6 + 8) = *param_3;
}

extern "C" int fn_800DEEF8(int param_1, int param_2)
{
  return param_1 + param_2 * 6 + 8;
}

extern "C" void fn_800DEF0C(u8* self, int i, u32 val) {
    self = self + i * 4;
    *(u32*)(self + 0x38) = val;
}

extern "C" u32 fn_800DEF1C(u8* self, int i) {
    self = self + i * 4;
    return *(u32*)(self + 0x38);
}

extern "C" u32 fn_800DEF2C(u8* self) {
    return *(u32*)(self + 0x58);
}

extern "C" void fn_800DEF34(u8* param_1, u32 param_2) {
    *(u32*)(param_1 + 0x58) = param_2;
}

extern "C" u32 fn_800DEF3C(void) {
    return 0x54474234;
}

extern "C" void fn_800DEF48(u8* self, const J3DNBTScaleInfo* other) {
    *(J3DNBTScaleInfo*)(self + 0x5c) = *other;
}

extern "C" void fn_800DEF6C(u8* self, const J3DNBTScaleInfo* other) {
    *(J3DNBTScaleInfo*)(self + 0x5c) = *other;
}

extern "C" u8* fn_800DEF90(u8* self) {
    return self + 0x5c;
}

extern "C" char __vt__15J3DTexGenBlock4[];
extern "C" char __vt__21J3DTexGenBlockPatched[];
extern "C" char __vt__14J3DTexGenBlock[];
extern "C" void* fn_800DEF98(void* self, short flag) {
    if (self) {
        *(void**)self = __vt__15J3DTexGenBlock4;
        if (self) {
            *(void**)self = __vt__21J3DTexGenBlockPatched;
            if (self) {
                *(void**)self = __vt__14J3DTexGenBlock;
            }
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

extern "C" void fn_800DF004(void) {}

extern "C" int fn_800DF008(void) { return 0x54475054; }

extern "C" int fn_800DF014(void) { return 0x434c4f4e; }

extern "C" void fn_800DF020(GXColor* param_1, int param_2, const GXColor* param_3) {
    param_1[param_2 + 1] = *param_3;
}

extern "C" void fn_800DF04C(GXColor* param_1, int param_2, const GXColor* param_3) {
    param_1[param_2 + 1] = *param_3;
}

extern "C" u8* fn_800DF078(u8* self, int i) {
    return self + i * 4 + 4;
}

#if defined(VERSION_G4SJ01)
extern "C" void fn_800DF08C(u8* self, int i, const u8* c) {
    u8 c0 = c[0];
    u8* p = self + (i << 2);
    p[0xc] = c0;
    p[0xd] = c[1];
    p[0xe] = c[2];
    p[0xf] = c[3];
}
#else
extern "C" void fn_800DF08C(u8* self, int i, const u8* c) {
    u8* p = self + i * 4;
    u8 c0 = c[0];
    p[0xc] = c0;
    p[0xd] = c[1];
    p[0xe] = c[2];
    p[0xf] = c[3];
}
#endif

extern "C" u32* fn_800DF0E4(Unk800DE4D0* p, int i) {
    return &p->a[i];
}

extern "C" void fn_800DF0F8(u8* self, const u8* v) {
    self[0x14] = *v;
}

extern "C" void fn_800DF104(u8* self, u8 v) {
    self[0x14] = v;
}

extern "C" u8 fn_800DF10C(u8* self) {
    return self[0x14];
}

extern "C" void fn_800DF114(u8* self, int i, const u16* v) {
    ((u16*)(self + 0x16))[i] = *v;
}

extern "C" void fn_800DF128(u8* self, int i, const u16* v) {
    ((u16*)(self + 0x16))[i] = *v;
}

extern "C" u16* fn_800DF13C(Unk800DF13C* self, int i) {
    return &self->a[i];
}

extern "C" void fn_800DF150(u8* self, int i, void* v) {
    ((void**)(self + 0x20))[i] = v;
}

extern "C" u32 fn_800DF160(u8* self, int i) {
    self = self + i * 4;
    return *(u32*)(self + 0x20);
}

extern "C" void fn_800DF170(u8* self, u8 val) {
    *(u8*)(self + 0x40) = val;
}

extern "C" void fn_800DF178(u8* self, u8* src) {
    *(u8*)(self + 0x40) = *src;
}

extern "C" u8 fn_800DF184(int param_1) {
    return *(u8*)(param_1 + 0x40);
}

extern "C" u32 fn_800DF18C(int param_1) {
    return *(u32*)(param_1 + 0x44);
}

extern "C" u32 fn_800DF194(int param_1) {
    return *(u32*)(param_1 + 0x48);
}

extern "C" void fn_800DF19C(int param_1, u32 param_2) {
    *(u32*)(param_1 + 0x44) = param_2;
}

extern "C" void fn_800DF1A4(int param_1, u32 param_2) {
    *(u32*)(param_1 + 0x48) = param_2;
}

extern "C" void* fn_800DF1AC(void* self, short flag) {
    if (self) {
        *(void**)self = __vt__20J3DColorBlockLightOn;
        if (self) {
            *(void**)self = __vt__13J3DColorBlock;
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

extern "C" u32 fn_800DF208(void) {
    return 0x434c4142;
}

extern "C" void fn_800DF214(GXColor* param_1, int param_2, const GXColor* param_3) {
    param_1[param_2 + 8] = *param_3;
}

extern "C" void fn_800DF240(GXColor* param_1, int param_2, const GXColor* param_3) {
    param_1[param_2 + 8] = *param_3;
}

extern "C" int fn_800DF26C(int param_1, int param_2) {
    return param_1 + param_2 * 4 + 0x20;
}

extern "C" void* fn_800DF280(void* self, short flag) {
    if (self) {
        *(void**)self = __vt__22J3DColorBlockAmbientOn;
        if (self) {
            *(void**)self = __vt__21J3DColorBlockLightOff;
            if (self) {
                *(void**)self = __vt__13J3DColorBlock;
            }
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

extern "C" void fn_800DF2EC(GXColor* param_1, int param_2, const GXColor* param_3) {
    param_1[param_2 + 1] = *param_3;
}

extern "C" void fn_800DF318(GXColor* param_1, int param_2, const GXColor* param_3) {
    param_1[param_2 + 1] = *param_3;
}

extern "C" u8* fn_800DF344(u8* self, int i) {
    return self + i * 4 + 4;
}

extern "C" void fn_800DF374(u8* this_, s32 idx, u16* src) {
    u16* p = (u16*)(this_ + 0xe);
    p[idx] = *src;
}

extern "C" void fn_800DF388(u8* this_, s32 idx, u16* src) {
    u16* p = (u16*)(this_ + 0xe);
    p[idx] = *src;
}

extern "C" u8* fn_800DF39C(u8* this_, s32 idx) {
    return this_ + idx * 2 + 0xe;
}

extern "C" void fn_800DF3B0(u8* this_, u8 val) {
    *(u8*)(this_ + 0x16) = val;
}

extern "C" void fn_800DF3B8(u8* this_, u8* src) {
    *(u8*)(this_ + 0x16) = *src;
}

extern "C" u8 fn_800DF3C4(u8* this_) {
    return *(u8*)(this_ + 0x16);
}

extern "C" u32 fn_800DF3CC(u8* this_) { return *(u32*)(this_ + 0x18); }

extern "C" u32 fn_800DF3D4(u8* this_) { return *(u32*)(this_ + 0x1c); }

extern "C" void fn_800DF3DC(u8* this_, u32 val) { *(u32*)(this_ + 0x18) = val; }

extern "C" void fn_800DF3E4(u8* this_, u32 val) { *(u32*)(this_ + 0x1c) = val; }

extern "C" u32 fn_800DF3EC(void) {
    return 0x5045584c;
}

extern "C" void* fn_800DF3F8(void* self, short flag) {
    if (self) {
        *(void**)self = __vt__13J3DPEBlockXlu;
        if (self) {
            *(void**)self = __vt__10J3DPEBlock;
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

extern "C" u32 fn_800DF454(void) {
    return 0x50454544;
}

extern "C" void* fn_800DF460(void* self, short flag) {
    if (self) {
        *(void**)self = __vt__17J3DPEBlockTexEdge;
        if (self) {
            *(void**)self = __vt__10J3DPEBlock;
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

extern "C" u32 fn_800DF4BC(void) {
    return 0x50454f50;
}

extern "C" void* fn_800DF4C8(void* param_1, short param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = &__vt__13J3DPEBlockOpa;
        *(void**)param_1 = &__vt__10J3DPEBlock;
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}

extern "C" unsigned long fn_800DF524(void) {
    return 'IBLF';
}

extern "C" void fn_800DF530(void* self, unsigned char num) {
    *((unsigned char*)self + 4) = num;
}

extern "C" unsigned char fn_800DF538(void* self) {
    return *((unsigned char*)self + 4);
}

extern "C" void fn_800DF540(int param_1, int param_2, u32* param_3) {
    *(u32*)(param_1 + param_2 * 4 + 5) = *param_3;
}

extern "C" void fn_800DF554(int param_1, int param_2, u32* param_3) {
    *(u32*)(param_1 + param_2 * 4 + 5) = *param_3;
}

extern "C" int fn_800DF568(int param_1, int param_2) {
    return param_1 + param_2 * 4 + 5;
}

extern "C" void fn_800DF57C(int param_1, int param_2, J3DIndTexMtxInfo param_3) {
    __as__16J3DIndTexMtxInfoFRC16J3DIndTexMtxInfo((J3DIndTexMtxInfo*)(param_1 + param_2 * 0x1c + 0x18), param_3);
}

extern "C" void fn_800DF5B0(int param_1, int param_2, J3DIndTexMtxInfo param_3) {
    __as__16J3DIndTexMtxInfoFRC16J3DIndTexMtxInfo((J3DIndTexMtxInfo*)(param_1 + param_2 * 0x1c + 0x18), param_3);
}

extern "C" int fn_800DF5E4(int param_1, int param_2)
{
  return param_1 + param_2 * 0x1c + 0x18;
}

extern "C" void fn_800DF5F8(int param_1, int param_2, u32* param_3)
{
  *(u32*)(param_1 + param_2 * 4 + 0x6c) = *param_3;
}

extern "C" void fn_800DF60C(int param_1, int param_2, u32* param_3)
{
  *(u32*)(param_1 + param_2 * 4 + 0x6c) = *param_3;
}

extern "C" int fn_800DF620(int param_1, int param_2)
{
  return param_1 + param_2 * 4 + 0x6c;
}

extern "C" void* fn_800DF634(void* param_1, short param_2)
{
  if (param_1 != nullptr) {
    *(void**)param_1 = &__vt__15J3DIndBlockFull;
    __destroy_arr((u8*)param_1 + 0x6c, &__dt__19J3DIndTexCoordScaleFv, 4, 4);
    __destroy_arr((u8*)param_1 + 0x18, &__dt__12J3DIndTexMtxFv, 0x1c, 3);
    if (param_1 != nullptr) {
      *(void**)param_1 = &__vt__11J3DIndBlock;
    }
    if (0 < param_2) {
      __dl__FPv(param_1);
    }
  }
  return param_1;
}

extern "C" unsigned long fn_800DF6D0(void) {
    return 'CLOF';
}

struct UnkVtableTest8248 {
    int x;
};struct fn_800DE29C_Bits {
  u8 hi : 4;
  u8 b : 2;
  u8 a : 2;
};

extern "C" void fn_800D9658(u8* p) {
    u16* e = (u16*)((u8*)&sTexCoordScaleTable__6J3DSys + (p[0xd] & 7) * 8);
    J3DGDSetTexCoordScale2__F13_GXTexCoordIDUsUcUcUsUcUc(p[0xc], e[0], e[2] == 1, 0, e[1], e[3] == 1, 0);
    e = (u16*)((u8*)&sTexCoordScaleTable__6J3DSys + (p[0x11] & 7) * 8);
    J3DGDSetTexCoordScale2__F13_GXTexCoordIDUsUcUcUsUcUc(p[0x10] & 7, e[0], e[2] == 1, 0, e[1], e[3] == 1, 0);
}

// Keep regional definitions that were present before source-tree consolidation.
#if defined(VERSION_G4SJ01)
extern "C" fn_800DF364(void* param_1, u8 param_2) {
*(u8*)((u32)param_1 + 0xc) param_2;
}

extern "C" u8 fn_800DF36C(void* param_1) {
return *(u8*)((u32)param_1 + 0xc);
}

extern "C" void fn_800DF358(void* param_1, u8* param_2) {
    *(u8*)((u32)param_1 + 0xc) = *param_2;
}

void J3DIndBlockFull::initialize() {
    mIndTexStageNum = 0;
}

extern "C" void fn_800DDA78(u8* self, const u8* src) {
    *(u16*)(self + 4) = *(const u16*)src;
    self[6] = src[2];
    self[7] = src[3];
}

void J3DTexGenBlock4::initialize() {
    mTexGenCnt = 0;
    mTexMatrices[0] = nullptr;
    mTexMatrices[1] = nullptr;
    mTexMatrices[2] = nullptr;
    mTexMatrices[3] = nullptr;
    mTexMtxOffset = 0;
}

extern "C" void fn_800DF0B8(u8* self, int i, const u8* c) {
    self[i * 4 + 0xc] = c[0];
    self[i * 4 + 0xd] = c[1];
    self[i * 4 + 0xe] = c[2];
    self[i * 4 + 0xf] = c[3];
}

extern "C" void fn_800D95B0(u8* p)
{
    u8 n = p[0x34];
    for (u32 i = 0; i < n; i++) {
        J3DGDWriteBPCmd(*(u32*)(p + 0x60) | ((i + 0x10) << 24));
        p += 4;
    }
}

#endif
struct Rgb3_800DE210 {
    u8 r, g, b;
};
