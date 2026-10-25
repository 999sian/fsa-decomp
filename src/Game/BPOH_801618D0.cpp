#include "types.h"
#include "Game/TlwpDrawParam.h"
extern const f32 lbl_8053D6E0;
extern const f32 lbl_8053D6E4;
extern const char lbl_80466274[];
extern "C" void fn_801F02BC(void*, const char*, s32, TlwpDrawParam*, s32, s32, s32, f32, f32);
#include "Game/SinitPoolChain.h"
struct BPOHV {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setAnim(s32, float, float);
};

struct BPOHVt {
    char pad[0x28];
    void (*fn28)(void*, s32, float, float);
};

extern "C" void fn_801F0E34(void*, u32, u32);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D8050(void*, void*, s32, s32);
extern "C" void fn_801EE434(void*);
extern "C" void fn_802D7440(void*, s32);
extern "C" void fn_8022ADCC(void);
extern "C" void __dt__5ActorFv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" char __vt__4BPOH[];
extern const float lbl_8053D6C0;
extern const float lbl_8053D6D0;
extern const float lbl_8053D6BC;
extern const float lbl_8053D6C4;
extern "C" u8 lbl_804661E0[];
extern "C" void* fn_804032E8(u32 type, const char* name);
extern "C" void storeTIMG__10JUTTextureFPC7ResTIMGUc(char* self, const void* timg, u8 palette);
extern "C" void load__10JUTTextureF11_GXTexMapID(char* self, s32 id);
extern "C" void __dt__10JUTTextureFv(void* self, s32 flags);
extern "C" void fn_802F5040(f32* pos, u8* ent, f32* out);
extern "C" u32 lbl_8053D6B8;
extern "C" u32 lbl_80543F30;
extern "C" void fn_801618D0(char* this_, f32* pos, u8* ent) {
    char* names = (char*)lbl_804661E0;
    char tex0[0x40];
    char tex1[0x40];
    char tex2[0x40];
    f32 out[3];
    f32 w;
    f32 h;
    void* timg;

    timg = fn_804032E8(0x42504F48, names + 0x60);
    *(void**)(tex0 + 0x28) = nullptr;
    storeTIMG__10JUTTextureFPC7ResTIMGUc(tex0, timg, 0);
    tex0[0x3b] &= 2;
    timg = fn_804032E8(0x42504F48, names + 0x74);
    *(void**)(tex1 + 0x28) = nullptr;
    storeTIMG__10JUTTextureFPC7ResTIMGUc(tex1, timg, 0);
    tex1[0x3b] &= 2;
    timg = fn_804032E8(0x42504F48, names + 0x84);
    *(void**)(tex2 + 0x28) = nullptr;
    storeTIMG__10JUTTextureFPC7ResTIMGUc(tex2, timg, 0);
    tex2[0x3b] &= 2;

    w = (f32)(s32) * (u16*)(*(char**)(tex0 + 0x20) + 0x2);
    h = (f32)(s32) * (u16*)(*(char**)(tex0 + 0x20) + 0x4);
    fn_802F5040(pos, ent, out);

    GXClearVtxDesc();
    GXSetVtxDesc((GXAttr)9, (GXAttrType)1);
    GXSetVtxDesc((GXAttr)0xd, (GXAttrType)1);
    GXSetVtxAttrFmt((GXVtxFmt)0, (GXAttr)9, (GXCompCnt)1, (GXCompType)4, 0);
    GXSetVtxAttrFmt((GXVtxFmt)0, (GXAttr)0xd, (GXCompCnt)1, (GXCompType)4, 0);
    GXSetChanCtrl((GXChannelID)4, (GXBool)0, (GXColorSrc)0, (GXColorSrc)0, (GXLightID)0, (GXDiffuseFn)0, (GXAttnFn)2);
    GXSetNumChans(1);
    GXSetTexCoordGen2((GXTexCoordID)0, (GXTexGenType)1, (GXTexGenSrc)4, 0x3c, (GXBool)0, 0x7d);
    GXSetNumTexGens(1);
    load__10JUTTextureF11_GXTexMapID(tex0, 0);
    load__10JUTTextureF11_GXTexMapID(tex1, 1);
    load__10JUTTextureF11_GXTexMapID(tex2, 2);

    GXSetTevOrder((GXTevStageID)0, (GXTexCoordID)0, (GXTexMapID)0, (GXChannelID)0xff);
    GXSetTevColorIn((GXTevStageID)0, (GXTevColorArg)2, (GXTevColorArg)0xe, (GXTevColorArg)8, (GXTevColorArg)0xf);
    GXSetTevColorOp((GXTevStageID)0, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
    GXSetTevAlphaIn((GXTevStageID)0, (GXTevAlphaArg)4, (GXTevAlphaArg)7, (GXTevAlphaArg)7, (GXTevAlphaArg)7);
    GXSetTevAlphaOp((GXTevStageID)0, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
    GXSetTevSwapMode((GXTevStageID)0, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevKColorSel((GXTevStageID)0, (GXTevKColorSel)0xc);
    GXSetTevKAlphaSel((GXTevStageID)0, (GXTevKAlphaSel)0x1c);
    GXSetTevOrder((GXTevStageID)1, (GXTexCoordID)0, (GXTexMapID)1, (GXChannelID)0xff);
    GXSetTevColorIn((GXTevStageID)1, (GXTevColorArg)0xf, (GXTevColorArg)0, (GXTevColorArg)8, (GXTevColorArg)0xf);
    GXSetTevColorOp((GXTevStageID)1, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
    GXSetTevAlphaIn((GXTevStageID)1, (GXTevAlphaArg)7, (GXTevAlphaArg)6, (GXTevAlphaArg)0, (GXTevAlphaArg)7);
    GXSetTevAlphaOp((GXTevStageID)1, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
    GXSetTevSwapMode((GXTevStageID)1, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevKColorSel((GXTevStageID)1, (GXTevKColorSel)0xc);
    GXSetTevKAlphaSel((GXTevStageID)1, (GXTevKAlphaSel)0x1c);
    GXSetTevOrder((GXTevStageID)2, (GXTexCoordID)0, (GXTexMapID)2, (GXChannelID)0xff);
    GXSetTevColorIn((GXTevStageID)2, (GXTevColorArg)0xf, (GXTevColorArg)4, (GXTevColorArg)8, (GXTevColorArg)0);
    GXSetTevColorOp((GXTevStageID)2, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
    GXSetTevAlphaIn((GXTevStageID)2, (GXTevAlphaArg)7, (GXTevAlphaArg)2, (GXTevAlphaArg)4, (GXTevAlphaArg)0);
    GXSetTevAlphaOp((GXTevStageID)2, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
    GXSetTevSwapMode((GXTevStageID)2, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevKColorSel((GXTevStageID)2, (GXTevKColorSel)0xc);
    GXSetTevKAlphaSel((GXTevStageID)2, (GXTevKAlphaSel)0x1c);
    GXSetTevOrder((GXTevStageID)3, (GXTexCoordID)0xff, (GXTexMapID)0xff, (GXChannelID)0xff);
    GXSetTevColorIn((GXTevStageID)3, (GXTevColorArg)0xf, (GXTevColorArg)0, (GXTevColorArg)6, (GXTevColorArg)0xe);
    GXSetTevAlphaIn((GXTevStageID)3, (GXTevAlphaArg)7, (GXTevAlphaArg)0, (GXTevAlphaArg)3, (GXTevAlphaArg)6);
    GXSetTevColorOp((GXTevStageID)3, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
    GXSetTevAlphaOp((GXTevStageID)3, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
    GXSetTevSwapMode((GXTevStageID)3, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevKColorSel((GXTevStageID)3, (GXTevKColorSel)0xd);
    GXSetTevKAlphaSel((GXTevStageID)3, (GXTevKAlphaSel)0x1d);
    GXSetTevDirect((GXTevStageID)3);
    GXSetNumTevStages(4);
    GXSetBlendMode((GXBlendMode)1, (GXBlendFactor)4, (GXBlendFactor)5, (GXLogicOp)0xf);
    GXSetZCompLoc((GXBool)0);
    GXSetAlphaCompare((GXCompare)4, 0, (GXAlphaOp)0, (GXCompare)7, 0);
    GXSetColorUpdate((GXBool)1);
    GXSetCullMode((GXCullMode)0);

    GXSetTevColor((GXTevRegID)1, *(GXColor*)(this_ + 0x2f4));
    GXSetTevKColor((GXTevKColorID)0, *(GXColor*)(this_ + 0x2f8));
    GXSetTevColor((GXTevRegID)2, *(GXColor*)(this_ + 0x2fc));
    if (ent != nullptr) {
        GXSetTevColor((GXTevRegID)3, *(GXColor*)(ent + 0x10));
        GXSetTevKColor((GXTevKColorID)1, *(GXColor*)(ent + 0x14));
    } else {
        GXSetTevColor((GXTevRegID)3, *(GXColor*)&lbl_8053D6B8);
        GXSetTevKColor((GXTevKColorID)1, *(GXColor*)&lbl_80543F30);
    }

    out[0] -= lbl_8053D6BC * w;
    out[2] -= lbl_8053D6BC * h;
    GXBegin((GXPrimitive)0x80, (GXVtxFmt)0, 4);
    f32 x0 = out[0];
    *(volatile f32*)0xCC008000 = x0;
    f32 zero = lbl_8053D6C0;
    f32 x1 = x0 + w;
    f32 y = out[1];
    *(volatile f32*)0xCC008000 = y;
    f32 z0 = out[2];
    f32 z1 = z0 + h;
    *(volatile f32*)0xCC008000 = z1;
    *(volatile f32*)0xCC008000 = zero;
    *(volatile f32*)0xCC008000 = zero;
    *(volatile f32*)0xCC008000 = x1;
    *(volatile f32*)0xCC008000 = y;
    *(volatile f32*)0xCC008000 = z1;
    f32 one = lbl_8053D6C4;
    *(volatile f32*)0xCC008000 = one;
    *(volatile f32*)0xCC008000 = zero;
    *(volatile f32*)0xCC008000 = x1;
    *(volatile f32*)0xCC008000 = y;
    *(volatile f32*)0xCC008000 = z0;
    *(volatile f32*)0xCC008000 = one;
    *(volatile f32*)0xCC008000 = one;
    *(volatile f32*)0xCC008000 = x0;
    *(volatile f32*)0xCC008000 = y;
    *(volatile f32*)0xCC008000 = z0;
    *(volatile f32*)0xCC008000 = zero;
    *(volatile f32*)0xCC008000 = one;

    __dt__10JUTTextureFv(tex2, -1);
    __dt__10JUTTextureFv(tex1, -1);
    __dt__10JUTTextureFv(tex0, -1);
}

extern "C" void fn_80161F20(char* this_) {
    fn_801F0E34(this_, 0x40015, 0);
    ((BPOHV*)this_)->setAnim(7, lbl_8053D6C0, lbl_8053D6D0);
    s32 p = *(s32*)(this_ + 0x270);
    if (p != 0) {
        fn_802D8050(fn_802D6A9C(), (void*)p, 1, 0xff);
    }
}

extern u8 lbl_804661E0[];
extern const float lbl_8053D6C4;
extern "C" void fn_80161F98(char* this_, s32 arg, s32 param3) {
    if (*(s32*)(this_ + 0x2ec) != arg) {
        if (*(s32*)(this_ + 0x2ec) < 0) {
            u32 w0 = *(u32*)(lbl_804661E0 + arg * 12);
            u32 w1 = *(u32*)(lbl_804661E0 + arg * 12 + 4);
            u32 w2 = *(u32*)(lbl_804661E0 + arg * 12 + 8);
            u8* s0 = (u8*)&w0;
            u8* s1 = (u8*)&w1;
            u8* s2 = (u8*)&w2;
            this_[0x2f4] = s0[0];
            this_[0x2f5] = s0[1];
            this_[0x2f6] = s0[2];
            this_[0x2f7] = s0[3];
            this_[0x2f8] = s1[0];
            this_[0x2f9] = s1[1];
            this_[0x2fa] = s1[2];
            this_[0x2fb] = s1[3];
            this_[0x2fc] = s2[0];
            this_[0x2fd] = s2[1];
            this_[0x2fe] = s2[2];
            this_[0x2ff] = s2[3];
        }
        *(s32*)(this_ + 0x2ec) = arg;
        if (*(s32*)(this_ + 0x2f0) < 0) {
            *(s32*)(this_ + 0x2f0) = 0;
        } else {
            *(s32*)(this_ + 0x2f0) = param3;
        }
    } else {
        if (*(s32*)(this_ + 0x2f0) > 0) {
            f32 n = (f32)*(s32*)(this_ + 0x2f0);
            f32 a = 1.0f / n;
            f32 b = 1.0f - a;
            s32 j = 0;
            u8* p = (u8*)this_;
            for (s32 i = 0; i < 3; i++, p += 4, j += 4) {
                p[0x2f4] = (u8)(s32)((f32)p[0x2f4] * b + a * (f32)lbl_804661E0[*(s32*)(this_ + 0x2ec) * 12 + j]);
                p[0x2f5] = (u8)(s32)((f32)p[0x2f5] * b + a * (f32)lbl_804661E0[*(s32*)(this_ + 0x2ec) * 12 + j + 1]);
                p[0x2f6] = (u8)(s32)((f32)p[0x2f6] * b + a * (f32)lbl_804661E0[*(s32*)(this_ + 0x2ec) * 12 + j + 2]);
                p[0x2f7] = (u8)(s32)((f32)p[0x2f7] * b + a * (f32)lbl_804661E0[*(s32*)(this_ + 0x2ec) * 12 + j + 3]);
            }
            *(s32*)(this_ + 0x2f0) -= 1;
        }
    }
}

extern "C" f32 lbl_804A0410[];
extern "C" s32 lbl_8053AB58;
extern "C" void fn_80163E80(char* this_)
{
    u8* p = (u8*)this_;

    *(u16*)(p + 0x94) = 0;
    *(f32*)(p + 0x60) = -60.0f;
    *(f32*)(p + 0x64) = -60.0f;
    *(f32*)(p + 0x68) = 60.0f;
    *(f32*)(p + 0x6c) = 60.0f;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x258) = 0;
    *(s32*)(p + 0x25c) = 5;
    *(f32*)(p + 0x27c) = 1.0f;
    *(f32*)(p + 0x280) = 1.0f;
    *(f32*)(p + 0x284) = 0.4f;
    *(f32*)(p + 0x274) = 0.0f;
    *(f32*)(p + 0x278) = 0.05f;
    *(s32*)(p + 0x254) = 0;
    *(f32*)(p + 0x2a8) = 0.0f;
    *(f32*)(p + 0x2a4) = 0.0f;
    *(f32*)(p + 0x2a0) = 0.0f;
    *(f32*)(p + 0x294) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x298) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x29c) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x2ac) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x2b0) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x2b4) = *(f32*)(p + 0x14);
    *(s32*)(p + 0x260) = 0;
    *(f32*)(p + 0x288) = 0.0f;
    *(f32*)(p + 0x28c) = 0.0f;
    lbl_8053AB58 = 0;
    *(s32*)(p + 0x2e8) = 0;
    *(f32*)(p + 0x2b8) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x2bc) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x2c0) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x2b8) = *(f32*)(p + 0x2b8) + lbl_804A0410[0];
    *(f32*)(p + 0x2bc) = *(f32*)(p + 0x2bc) + lbl_804A0410[1];
    *(f32*)(p + 0x2c4) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x2c8) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x2cc) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x2c4) = *(f32*)(p + 0x2c4) + lbl_804A0410[2];
    *(f32*)(p + 0x2c8) = *(f32*)(p + 0x2c8) + lbl_804A0410[3];
    *(f32*)(p + 0x2d0) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x2d4) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x2d8) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x2d0) = *(f32*)(p + 0x2d0) + lbl_804A0410[4];
    *(f32*)(p + 0x2d4) = *(f32*)(p + 0x2d4) + lbl_804A0410[5];
    *(f32*)(p + 0x2dc) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x2e0) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x2e4) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x2dc) = *(f32*)(p + 0x2dc) + lbl_804A0410[6];
    *(f32*)(p + 0x2e0) = *(f32*)(p + 0x2e0) + lbl_804A0410[7];
    *(s32*)(p + 0x2ec) = -1;
    *(s32*)(p + 0x2f0) = -1;
    *(s32*)(p + 0x2f4) = 0;
    *(s32*)(p + 0x2f8) = 0;
    *(s32*)(p + 0x2fc) = 0;
    *(s32*)(p + 0x26c) = -1;
    *(u16*)(p + 0x290) = 0;
    *(s32*)(p + 0x270) = (*(u32*)(p + 0x90) >> 2) & 0x1f;
    *(u8*)(p + 0x196) = 1;
    *(s32*)(p + 0x268) = *(u32*)(p + 0x90) & 3;
    *(s32*)(p + 0x108) = 10000;
    switch (*(s32*)(p + 0x268)) {
    case 0:
        fn_802D7440(fn_802D6A9C(), 0);
        *(s32*)(p + 0x230) = 0;
        break;
    case 1:
        *(u16*)(p + 0x290) = 0x8000;
        *(f32*)(p + 0x60) = -12.0f;
        *(f32*)(p + 0x64) = -12.0f;
        *(f32*)(p + 0x68) = 12.0f;
        *(f32*)(p + 0x6c) = 12.0f;
        *(f32*)(p + 0x288) = 1.0f;
        *(s32*)(p + 0x230) = 12;
        break;
    case 2:
        *(s32*)(p + 0x230) = 14;
        break;
    }
}

extern "C" void* fn_80164118(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = __vt__4BPOH;
        fn_801EE434(*(void**)(this_ + 0x2e8));
        if (*(s32*)(this_ + 0x268) == 2) {
            fn_802D7440(fn_802D6A9C(), 1);
            fn_8022ADCC();
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

void __sinit_BPOH_801618D0_cpp(void) {}

