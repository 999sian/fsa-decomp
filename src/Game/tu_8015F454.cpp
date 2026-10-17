#include "types.h"
#include "Game/SinitPoolChain.h"
#include <dolphin/gx.h>

extern "C" const float lbl_8053D628;
extern "C" const float lbl_8053D63C;
extern "C" void* lbl_8053AF80;
extern "C" void fn_80457E04(u8* this_, u8 flag);
extern "C" char lbl_804A03A8[];
extern "C" char lbl_804661B0[];
extern "C" char lbl_804661BC[];
extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053AB10;
extern "C" void fn_8013B490(void* this_);
extern "C" void fn_8013B1E8(void* this_);
extern "C" void load__10JUTTextureF11_GXTexMapID(u8* self, s32 id);
extern "C" const float lbl_8053D638;
struct FsaResMgr {
    virtual ~FsaResMgr() {}
    virtual void* slot2() { return 0; }
    virtual void* slot3() { return 0; }
    virtual void* slot4() { return 0; }
    virtual void* getRes(u32 id, const char* name) { return 0; }
};
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void __ct__Q29JGeometry8TVec3_f_Fv();
extern "C" void getTotalFreeSize__7JKRHeapFv(void* heap);
extern "C" void* __nw__FUlP7JKRHeapi(u32 size, void* heap, s32 align);
extern "C" void storeTIMG__10JUTTextureFPC7ResTIMGUc(char* self, const void* timg, u8 palette);
extern "C" void __dt__10JUTTextureFv(void*, int);
void operator delete(void*);
extern "C" void fn_8015F454(u8* this_, f32* pos, f32* uv, GXColor* color, GXColorS10* color10, u8* tex, u8 useTex1, u8 useBlend) {
    f32 s0 = uv[0];
    f32 t0 = uv[1];
    f32 s1 = uv[2];
    f32 t1 = uv[3];
    fn_8013B490(lbl_8053AB10);
    fn_8013B1E8(lbl_8053AB10);
    load__10JUTTextureF11_GXTexMapID(this_, 0);
    if (tex != 0) {
        GXClearVtxDesc();
        GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
        GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
        GXSetVtxDesc(GX_VA_TEX1, GX_DIRECT);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX1, GX_TEX_ST, GX_F32, 0);
        GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
        GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX2x4, GX_TG_TEX1, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
        GXSetNumTexGens(2);
        load__10JUTTextureF11_GXTexMapID(tex, 1);
        GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR_NULL);
        GXSetTevColorIn(GX_TEVSTAGE1, (GXTevColorArg)0xf, (GXTevColorArg)0xf, (GXTevColorArg)0xf, (GXTevColorArg)0);
        GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevAlphaIn(GX_TEVSTAGE1, (GXTevAlphaArg)7, (GXTevAlphaArg)0, (GXTevAlphaArg)4, (GXTevAlphaArg)7);
        GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        if ((s32)*(u8*)*(u8**)(tex + 0x20) == 0xe) {
            GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP1);
            GXSetTevSwapModeTable(GX_TEV_SWAP1, GX_CH_ALPHA, GX_CH_ALPHA, GX_CH_ALPHA, GX_CH_RED);
        }
        GXSetNumTevStages(2);
    }
    GXSetTevColor(GX_TEVREG0, *color);
    if (color10 != 0) {
        GXSetTevColorS10(GX_TEVREG1, *color10);
    }
    GXSetZMode(GX_FALSE, GX_LEQUAL, GX_FALSE);
    if (useBlend != 0) {
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_SET);
    }
    u8* img = *(u8**)(this_ + 0x20);
    s0 = s0 / (f32)*(u16*)(img + 2);
    t0 = t0 / (f32)*(u16*)(img + 4);
    s1 = s1 / (f32)*(u16*)(img + 2);
    t1 = t1 / (f32)*(u16*)(img + 4);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    if (tex != 0) {
        if (useTex1 != 0) {
            GXPosition3f32(pos[0], pos[1], 0.0f);
            GXTexCoord2f32(s0, t0);
            GXTexCoord2f32(-1.0f, -1.0f);
            GXPosition3f32(pos[2], pos[1], 0.0f);
            GXTexCoord2f32(s1, t0);
            GXTexCoord2f32(1.0f, -1.0f);
            GXPosition3f32(pos[2], pos[3], 0.0f);
            GXTexCoord2f32(s1, t1);
            GXTexCoord2f32(1.0f, 1.0f);
            GXPosition3f32(pos[0], pos[3], 0.0f);
            GXTexCoord2f32(s0, t1);
            GXTexCoord2f32(-1.0f, 1.0f);
        } else {
            GXPosition3f32(pos[0], pos[1], 0.0f);
            GXTexCoord2f32(s0, t0);
            GXTexCoord2f32(0.0f, 0.0f);
            GXPosition3f32(pos[2], pos[1], 0.0f);
            GXTexCoord2f32(s1, t0);
            GXTexCoord2f32(1.0f, 0.0f);
            GXPosition3f32(pos[2], pos[3], 0.0f);
            GXTexCoord2f32(s1, t1);
            GXTexCoord2f32(1.0f, 1.0f);
            GXPosition3f32(pos[0], pos[3], 0.0f);
            GXTexCoord2f32(s0, t1);
            GXTexCoord2f32(0.0f, 1.0f);
        }
    } else {
        GXPosition3f32(pos[0], pos[1], 0.0f);
        GXTexCoord2f32(s0, t0);
        GXPosition3f32(pos[2], pos[1], 0.0f);
        GXTexCoord2f32(s1, t0);
        GXPosition3f32(pos[2], pos[3], 0.0f);
        GXTexCoord2f32(s1, t1);
        GXPosition3f32(pos[0], pos[3], 0.0f);
        GXTexCoord2f32(s0, t1);
    }
}

extern "C" u8 fn_8015F8FC(char* p, s32 room, f32* pos, s32 flag) {
    u8 ret = 0;
    if (room < 8) {
        for (s32 i = 0; i < 0x20; i++) {
            if (*(s32*)(p + i * 4 + 0x204) == 0) {
                *(s32*)(p + i * 4 + 4) = flag;
                ret = 1;
                *(f32*)(p + i * 12 + 0x84) = pos[0];
                *(f32*)(p + i * 12 + 0x88) = pos[1];
                *(f32*)(p + i * 12 + 0x8c) = pos[2];
                switch (flag) {
                case 0:
                case 1:
                    *(s32*)(p + i * 4 + 0x204) = 0x1e;
                    break;
                case 4:
                    *(s32*)(p + i * 4 + 0x204) = 0x73;
                    break;
                default:
                    *(s32*)(p + i * 4 + 0x204) = 1;
                    break;
                }
                break;
            }
        }
    }
    return ret;
}

extern "C" void fn_8016005C(u8* p) {
    u8* q = p;
    s32 j = 0;
    for (int i = 0; i < 4; i++) {
        if (*(s32*)(q + 0x204) > 0) {
            *(s32*)(q + 0x204) = *(s32*)(q + 0x204) - 1;
        }
        if (*(s32*)(q + 0x208) > 0) {
            *(s32*)(q + 0x208) = *(s32*)(q + 0x208) - 1;
        }
        if (*(s32*)(q + 0x20c) > 0) {
            *(s32*)(q + 0x20c) = *(s32*)(q + 0x20c) - 1;
        }
        if (*(s32*)(q + 0x210) > 0) {
            *(s32*)(q + 0x210) = *(s32*)(q + 0x210) - 1;
        }
        if (*(s32*)(q + 0x214) > 0) {
            *(s32*)(q + 0x214) = *(s32*)(q + 0x214) - 1;
        }
        if (*(s32*)(q + 0x218) > 0) {
            *(s32*)(q + 0x218) = *(s32*)(q + 0x218) - 1;
        }
        if (*(s32*)(q + 0x21c) > 0) {
            *(s32*)(q + 0x21c) = *(s32*)(q + 0x21c) - 1;
        }
        if (*(s32*)(q + 0x220) > 0) {
            *(s32*)(q + 0x220) = *(s32*)(q + 0x220) - 1;
        }
        q += 0x20;
        j += 7;
    }
    f32 old = *(f32*)(p + 0x288);
    if (*(u8*)(p + 0x284) != 0) {
        f32 v = old + *(f32*)(p + 0x28c);
        if (v >= lbl_8053D63C) {
            v = lbl_8053D63C;
        }
        *(f32*)(p + 0x288) = v;
    } else {
        f32 v = old - *(f32*)(p + 0x28c);
        f32 min = lbl_8053D628;
        if (v >= lbl_8053D628) {
            min = v;
        }
        *(f32*)(p + 0x288) = min;
    }
    *(u8*)(p + 0x284) = 0;
    if (*(f32*)(p + 0x288) > lbl_8053D628 && lbl_8053D628 == old) {
        fn_80457E04((u8*)lbl_8053AF80, 1);
    } else if (lbl_8053D628 == *(f32*)(p + 0x288) && old > lbl_8053D628) {
        fn_80457E04((u8*)lbl_8053AF80, 0);
    }
}

extern "C" void fn_801601E0(char* p) {
    u32* w = (u32*)(p + 0x204);
    for (int i = 0; i < 32; i++) w[i] = 0;
    p[0x284] = 0;
    *(float*)(p + 0x288) = lbl_8053D628;
    *(float*)(p + 0x28c) = lbl_8053D628;
}

extern "C" void* fn_80160278(void* p, s16 flag) {
    if (p != 0) {
        *(void**)p = lbl_804A03A8;
        __dt__10JUTTextureFv(*(void**)((char*)p + 0x294), 1);
        __dt__10JUTTextureFv(*(void**)((char*)p + 0x290), 1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void* fn_801602E8(u8* p, void* heap) {
    *(void**)p = lbl_804A03A8;
    __construct_array(p + 0x84, (void*)__ct__Q29JGeometry8TVec3_f_Fv, 0, 0xc, 0x20);
    getTotalFreeSize__7JKRHeapFv(heap);
    u8* tex = (u8*)__nw__FUlP7JKRHeapi(0x40, heap, 0);
    if (tex != 0) {
        FsaResMgr* mgr = *(FsaResMgr**)((u8*)lbl_8053AAF8 + 0xa4);
        void* res = mgr->getRes(0x3f3f3f3f, lbl_804661B0);
        *(u32*)(tex + 0x28) = 0;
        storeTIMG__10JUTTextureFPC7ResTIMGUc((char*)tex, res, 0);
        tex[0x3b] &= 2;
    }
    *(u8**)(p + 0x290) = tex;
    tex = (u8*)__nw__FUlP7JKRHeapi(0x40, heap, 0);
    if (tex != 0) {
        FsaResMgr* mgr = *(FsaResMgr**)((u8*)lbl_8053AAF8 + 0xa4);
        void* res = mgr->getRes(0x3f3f3f3f, lbl_804661BC);
        *(u32*)(tex + 0x28) = 0;
        storeTIMG__10JUTTextureFPC7ResTIMGUc((char*)tex, res, 0);
        tex[0x3b] &= 2;
    }
    *(u8**)(p + 0x294) = tex;
    return p;
}

