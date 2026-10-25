#include "types.h"
#include "JSystem/J3D/J3DModel.h"
#include "JSystem/J3D/J3DMaterialAnm.h"
#include "JSystem/J3D/J3DModelLoader.h"
#include "JSystem/J3D/J3DSys.h"
#include "JSystem/JKernel/JKRArchive.h"
#include "JSystem/JKernel/JKRHeap.h"
extern "C" void* fn_800CECCC(const void*, u32);
#include "Game/SinitPoolChain.h"
#include "dolphin/mtx.h"
#include "JSystem/JGeometry/Vec.h"

#pragma auto_inline off

extern u8* lbl_8053AAF8;
extern const f32 lbl_8053D93C;
extern const f32 lbl_8053D940;
extern const f32 lbl_8053D944;
extern const f32 lbl_8053D950;
extern const f32 lbl_8053D958;
extern const f32 lbl_8053D95C;
extern const f32 lbl_8053D960;
extern const f32 lbl_8053D988;
extern const f32 lbl_8053D964;
extern const f32 lbl_8053D938;
extern const f32 lbl_8053D93C;
extern const f32 lbl_8053D940;
extern const f32 lbl_8053D944;
extern const u32 lbl_80543F38;
extern u8* lbl_8053AB10;
extern u8* sManager__8JUTVideo;
extern "C" void fn_8013B460(void*);
extern "C" void fn_8013B1E8(void*);
extern "C" void load__10JUTTextureF11_GXTexMapID(void*, s32);

extern "C" void* fn_8013C824();
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*, void*);
extern "C" void fn_8016A7DC(void*, void*, const Vec*, s32, u8, u8, f32, f32);
extern "C" void fn_8016ADE0(void*);
extern "C" void* fn_8013CC50(s32, void*, s32, s32, s32, s32, s32, s32, f32);
extern const f32 lbl_8053D970;
extern const f32 lbl_8053D9BC;
extern const f32 lbl_8053D9C0;
extern const f32 lbl_8053D9C4;
extern const f32 lbl_8053D9C8;
extern const f32 lbl_8053D9CC;
extern const f32 lbl_8053D9D0;
extern const f32 lbl_8053D9D4;
extern const f32 lbl_8053D9D8;
extern const f32 lbl_8053D9DC;
extern const f32 lbl_8053D9E0;
extern const f32 lbl_8053D9E4;
extern const f32 lbl_8053D9E8;
extern const f32 lbl_8053D9EC;
extern const f32 lbl_8053D9F0;
extern const f32 lbl_8053D9F4;
extern const f32 lbl_8053D9F8;

extern "C" void fn_8016A2B4(u8* self) {
    if (*(void**)(self + 0x124) != 0) {
        void* manager = *(void**)((u8*)fn_8013C824() + 0xC);
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(self + 0x124));
    }
    if (*(void**)(self + 0x128) != 0) {
        void* manager = *(void**)((u8*)fn_8013C824() + 0xC);
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(self + 0x128));
    }
    if (*(void**)(self + 0x12C) != 0) {
        void* manager = *(void**)((u8*)fn_8013C824() + 0xC);
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(self + 0x12C));
    }
}

extern "C" void fn_8016A330(u8* self) {
    self[0x1EC] = 0;
    self[0x1ED] = 0;
    self[0x1EE] = 0;
    self[0x1EF] = 0;
    self[0x1F0] = 0;
    self[0x1F1] = 0;
    self[0x1F2] = 0;
    self[0x1F3] = 0;
    self[0x1F4] = 0;
    self[0x1F5] = 0;
    self[0x1C4] = 0;
    self[0x1C5] = 0;
    self[0x1C6] = 0;
    self[0x1C7] = 0;
    self[0x1C8] = 0;
    self[0x1C9] = 0;
    self[0x1CA] = 0;
    self[0x1CB] = 0;
    self[0x1CC] = 0;
    self[0x1CD] = 0;
    self[0x1CE] = 0;
    self[0x1CF] = 0;
    self[0x1D1] = 0;
    self[0x1D2] = 0;
    self[0x1D3] = 0;
    *(s32*)(self + 0x1D8) = -1;
    self[0x1DC] = 0;
    self[0x1DD] = 0;
}

extern "C" void* fn_8016A3AC() {
    return *(void**)(*(u8**)(lbl_8053AAF8 + 4) + 0x24);
}

extern "C" void fn_8016A3BC(JKRArchive* archive, const char* modelName, const char* tex1, const char* tex2, const char* tev1, const char* tev2, u32 flags, JKRHeap* heap, J3DModel** model, J3DAnmTextureSRTKey** outTex1, J3DAnmTextureSRTKey** outTex2, J3DAnmTevRegKey** outTev1, J3DAnmTevRegKey** outTev2)
{
    J3DMaterialAnm* anm;
    J3DModelData* data;
    void* resource = 0;
    if (archive) resource = archive->getResource(0x4a334420, modelName);
    if (resource) {
        data = J3DModelLoaderDataBase::load(resource, flags);
        if (tex1) {
            *outTex1 = (J3DAnmTextureSRTKey*)fn_800CECCC(archive->getResource(0x4a334420, tex1), 0);
            (*outTex1)->searchUpdateMaterialID(data);
        } else if (outTex1) {
            *outTex1 = 0;
        }
        if (tex2) {
            *outTex2 = (J3DAnmTextureSRTKey*)fn_800CECCC(archive->getResource(0x4a334420, tex2), 0);
            (*outTex2)->searchUpdateMaterialID(data);
        } else if (outTex2) {
            *outTex2 = 0;
        }
        if (tev1) {
            *outTev1 = (J3DAnmTevRegKey*)fn_800CECCC(archive->getResource(0x4a334420, tev1), 0);
            (*outTev1)->searchUpdateMaterialID(data);
        } else if (outTev1) {
            *outTev1 = 0;
        }
        if (tev2) {
            *outTev2 = (J3DAnmTevRegKey*)fn_800CECCC(archive->getResource(0x4a334420, tev2), 0);
            (*outTev2)->searchUpdateMaterialID(data);
        } else if (outTev2) {
            *outTev2 = 0;
        }
        for (u16 i = 0; i < data->getMaterialNum(); i++) {
            anm = new (heap, 0) J3DMaterialAnm;
            data->getMaterialNodePointer(i)->change();
            data->getMaterialNodePointer(i)->setMaterialAnm(anm);
        }
        if (tex1) j3dSys.ErrorReport(data->mMaterialTable.entryTexMtxAnimator(*outTex1));
        if (tex2) j3dSys.ErrorReport(data->mMaterialTable.entryTexMtxAnimator(*outTex2));
        if (tev1) j3dSys.ErrorReport(data->mMaterialTable.entryTevRegAnimator(*outTev1));
        if (tev2) j3dSys.ErrorReport(data->mMaterialTable.entryTevRegAnimator(*outTev2));
        *model = new (heap, 0) J3DModel(data, 0, 1);
    } else {
        if (outTex1) *outTex1 = 0;
        if (outTex2) *outTex2 = 0;
        if (outTev1) *outTev1 = 0;
        if (outTev2) *outTev2 = 0;
        *model = 0;
    }
}

extern "C" void fn_8016A9EC(u8* self) {
    if (self[0x1DD]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0xEC), &offset, -1, 1, 1, lbl_8053D940, lbl_8053D95C);
    }
}

extern "C" void fn_8016AA48(u8* self) {
    if (self[0x1F5]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0xE0), &offset, 1, 1, 1, lbl_8053D950, lbl_8053D960);
    }
}

extern "C" void fn_8016AAA4(u8* self) {
    if (self[0x1DC]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0xCC), &offset, 1, 1, 1, lbl_8053D950, lbl_8053D93C);
    }
}

extern "C" void fn_8016AB00(u8* self) {
    if (self[0x1F4]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0xD4), &offset, 1, 1, 1, lbl_8053D93C, lbl_8053D95C);
    }
}

extern "C" void fn_8016AB5C(u8* self) {
    if (*(s32*)(self + 0x1D8) > 0) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0xC0), &offset, 1, 1, 1, lbl_8053D93C, lbl_8053D95C);
    }
}

extern "C" void fn_8016ABB8(u8* self) {
    if (self[0x1F3]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0xB4), &offset, 1, 1, 1, lbl_8053D93C, lbl_8053D95C);
    }
}

extern "C" void fn_8016AC14(u8* self) {
    if (self[0x1F2]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0x9C), &offset, 1, 1, 1, lbl_8053D93C, lbl_8053D95C);
    }
}

extern "C" void fn_8016AC70(u8* self) {
    if (self[0x1F1]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0x90), &offset, 1, 1, 1, lbl_8053D950, lbl_8053D95C);
    }
}

extern "C" void fn_8016ACCC(u8* self) {
    if (self[0x1F0]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0x84), &offset, 1, 1, 1, lbl_8053D93C, lbl_8053D95C);
    }
}

extern "C" void fn_8016AD28(u8* self) {
    if (self[0x1EF]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0x28), &offset, 1, 1, 1, lbl_8053D93C, lbl_8053D95C);
    }
}

extern "C" void fn_8016AD84(u8* self) {
    if (self[0x1ED]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0x1C), &offset, 1, 1, 1, lbl_8053D950, lbl_8053D960);
    }
}

extern "C" void fn_8016ADE0(void* param_1) {
    u8* p = (u8*)param_1;
    if (p[0x1ec] != 0) {
        u8* r8 = *(u8**)(lbl_8053AB10 + 0x24);
        u8* r7 = *(u8**)(sManager__8JUTVideo + 0x4);
        u32 a = *(u32*)(*(u8**)(lbl_8053AB10 + 0x20) + 0x2380);
        u32 b = *(u32*)(*(u8**)(lbl_8053AB10 + 0x20) + 0x2384);
        f32 fa = (f32)a;
        f32 fb = (f32)b;
        f32 fw = (f32)*(u16*)(r7 + 0x4);
        f32 fh = (f32)*(u16*)(r7 + 0x6);
        f32 v = (f32)(*(u32*)(p + 0x1c0) & 0x7ff);
        f32 sx = lbl_8053D938 / fa;
        f32 sy = lbl_8053D938 / fb;
        f32 k = lbl_8053D93C / *(f32*)(r8 + 0x858);
        f32 f4 = lbl_8053D964 * v;
        f32 f29 = -*(f32*)(r8 + 0x10) * sx - f4;
        f32 f28 = -*(f32*)(r8 + 0x20) * sy - f4;
        f32 f31 = k * (lbl_8053D940 * (sx * fw));
        f32 f30 = k * (lbl_8053D940 * (sy * fh));
        GXColor color = *(GXColor*)&lbl_80543F38;
        fn_8013B460(lbl_8053AB10);
        fn_8013B1E8(lbl_8053AB10);
        load__10JUTTextureF11_GXTexMapID(*(void**)(p + 0xf4), 0);
        color.a = p[0x1ec];
        GXSetTevColor((GXTevRegID)1, color);
        GXSetZMode(GX_FALSE, GX_LEQUAL, GX_FALSE);
        GXSetZCompLoc(GX_FALSE);
        GXBegin(GX_QUADS, GX_VTXFMT0, 4);
        GXPosition3f32(0.0f, 0.0f, 0.0f);
        GXTexCoord2f32(f29 - f31, f28 - f30);
        GXPosition3f32(fw, 0.0f, 0.0f);
        GXTexCoord2f32(f29 + f31, f28 - f30);
        GXPosition3f32(fw, fh, 0.0f);
        GXTexCoord2f32(f29 + f31, f28 + f30);
        GXPosition3f32(0.0f, fh, 0.0f);
        GXTexCoord2f32(f29 - f31, f28 + f30);
    }
}

extern "C" void fn_8016B054(u8* self) {
    if (self[0x1D3]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0xA8), &offset, -1, 1, 1, lbl_8053D93C, lbl_8053D95C);
    }
}

extern "C" void fn_8016B0B0(u8* self) {
    extern u8* lbl_8053AB10;
    extern f32 lbl_8053D968;
    extern const f32 lbl_8053D96C;
    extern const f32 lbl_8053D970;
    extern const f32 lbl_8053D974;
    if (self[0x1CF]) {
        u8* p = *(u8**)(lbl_8053AB10 + 0x24);
        f32 scale = lbl_8053D968 / *(f32*)(p + 0x858);
        for (s32 i = 0; i < 6; i++) {
            if (*(u8**)(self + 0x3C + i * 4) == NULL) continue;
            if (i == 3 && self[0x1D0] == 0) continue;
            if ((i == 1 || i == 2) && self[0x1D0] != 0) continue;
            f32 fi = (f32)i;
            f32 f4 = lbl_8053D96C - lbl_8053D970 * fi;
            Mtx m;
            m[0][0] = lbl_8053D93C;
            m[0][1] = 0.0f;
            m[0][2] = 0.0f;
            m[0][3] = -*(f32*)(p + 0x10);
            m[1][0] = 0.0f;
            m[1][1] = 0.0f;
            m[1][2] = lbl_8053D93C;
            m[1][3] = lbl_8053D974 + (f4 - *(f32*)(p + 0x20));
            m[2][0] = 0.0f;
            m[2][1] = lbl_8053D93C;
            m[2][2] = 0.0f;
            m[2][3] = f4;
            *(f32*)(*(u8**)(self + 0x3C + i * 4) + 0x18) = scale;
            *(f32*)(*(u8**)(self + 0x3C + i * 4) + 0x1C) = scale;
            *(f32*)(*(u8**)(self + 0x3C + i * 4) + 0x20) = scale;
            PSMTXCopy(m, (MtxPtr)(*(u8**)(self + 0x3C + i * 4) + 0x24));
            ((void (*)(void*))((void**)*(void**)(*(u8**)(self + 0x3C + i * 4)))[4])(*(u8**)(self + 0x3C + i * 4));
            ((void (*)(void*))((void**)*(void**)(*(u8**)(self + 0x3C + i * 4)))[3])(*(u8**)(self + 0x3C + i * 4));
            ((void (*)(void*))((void**)*(void**)(*(u8**)(self + 0x3C + i * 4)))[7])(*(u8**)(self + 0x3C + i * 4));
        }
    }
}

extern "C" void fn_8016B4D4(u8* self) {
    extern f32 lbl_8053D980;
    extern f32 lbl_8053D984;
    if (self[0x1CC] == 0 || *(void**)(self + 0x110) == 0) {
        if (self[0x1CD] == 0) return;
        if (*(void**)(self + 0x118) == 0) return;
    }
    u8* r3 = lbl_8053AB10;
    u8* r7 = *(u8**)(r3 + 0x20);
    u8* r8 = *(u8**)(r3 + 0x24);
    u32 a = *(u32*)(r7 + 0x2380);
    u32 b = *(u32*)(r7 + 0x2384);
    u8* vid = *(u8**)(sManager__8JUTVideo + 0x4);
    f32 sx = lbl_8053D938 / (f32)a;
    f32 k = lbl_8053D93C / *(f32*)(r8 + 0x858);
    f32 sy = lbl_8053D938 / (f32)b;
    f32 fw = (f32)*(u16*)(vid + 0x4);
    f32 fh = (f32)*(u16*)(vid + 0x6);
    f32 v = (f32)(*(u32*)(self + 0x1c0) & 0xfff);
    f32 hx = k * (lbl_8053D940 * (sx * fw));
    f32 hy = k * (lbl_8053D940 * (sy * fh));
    f32 cx = -*(f32*)(r8 + 0x10) * sx - lbl_8053D980 * v;
    f32 cy = -*(f32*)(r8 + 0x20) * sy - lbl_8053D984 * v;
    fn_8013B460(r3);
    fn_8013B1E8(r3);
    load__10JUTTextureF11_GXTexMapID(*(void**)(self + 0x114), 0);
    GXSetZMode(GX_FALSE, GX_LEQUAL, GX_FALSE);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition3f32(0.0f, 0.0f, 0.0f);
    GXTexCoord2f32(cx - hx, cy - hy);
    GXPosition3f32(fw, 0.0f, 0.0f);
    GXTexCoord2f32(cx + hx, cy - hy);
    GXPosition3f32(fw, fh, 0.0f);
    GXTexCoord2f32(cx + hx, cy + hy);
    GXPosition3f32(0.0f, fh, 0.0f);
    GXTexCoord2f32(cx - hx, cy + hy);
}

extern "C" void fn_8016B8AC(u8* self) {
    if (self[0x1CB]) {
        JGeometry::TVec3<f32> offset(lbl_8053D958, lbl_8053D958 + *(f32*)(self + 0x1E4), lbl_8053D944);
        fn_8016A7DC(self, *(void**)(self + 0x34), &offset, 1, 1, 0, lbl_8053D93C, lbl_8053D988);
    }
}

extern "C" void fn_8016B910(u8* self) {
    if (self[0x1C9]) {
        if (*(void**)(self + 0x108) == 0) {
            if (self[0x1CA] && *(void**)(self + 0x10C) != 0) {
                J3DModel* dummy = 0;
                (void)dummy;
            }
        } else {
            if (self[0x1CA]) {
                fn_8013B460(lbl_8053AB10);
            }
        }
    }
}

extern "C" void fn_8016C2FC(u8* self) {
    extern f32 lbl_8053D980;
    extern f32 lbl_8053D984;
    extern const u32 lbl_8053D918;
    extern const u32 lbl_8053D91C;
    extern const u32 lbl_8053D920;
    if (self[0x1C8] == 0 || *(void**)(self + 0x104) == 0) return;
    u8* r3 = lbl_8053AB10;
    u8* r6 = *(u8**)(r3 + 0x20);
    u8* r7 = *(u8**)(r3 + 0x24);
    s32 a = *(s32*)(r6 + 0x2380);
    s32 b = *(s32*)(r6 + 0x2384);
    u8* vid = *(u8**)(sManager__8JUTVideo + 0x4);
    f32 sx = lbl_8053D938 / (f32)a;
    f32 k = lbl_8053D93C / *(f32*)(r7 + 0x858);
    f32 sy = lbl_8053D938 / (f32)b;
    f32 fw = (f32)*(u16*)(vid + 0x4);
    f32 fh = (f32)*(u16*)(vid + 0x6);
    f32 hx = k * (lbl_8053D940 * (sx * fw));
    f32 hy = k * (lbl_8053D940 * (sy * fh));
    f32 cx = -*(f32*)(r7 + 0x10) * sx;
    f32 cy = -*(f32*)(r7 + 0x20) * sy;
    fn_8013B460(r3);
    fn_8013B1E8(r3);
    load__10JUTTextureF11_GXTexMapID(*(void**)(self + 0x104), 0);
    GXSetZMode(GX_FALSE, GX_LEQUAL, GX_FALSE);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition3f32(0.0f, 0.0f, 0.0f);
    GXTexCoord2f32(cx - hx, cy - hy);
    GXPosition3f32(fw, 0.0f, 0.0f);
    GXTexCoord2f32(cx + hx, cy - hy);
    GXPosition3f32(fw, fh, 0.0f);
    GXTexCoord2f32(cx + hx, cy + hy);
    GXPosition3f32(0.0f, fh, 0.0f);
    GXTexCoord2f32(cx - hx, cy + hy);
    fn_8013B460(r3);
    fn_8013B1E8(r3);
    load__10JUTTextureF11_GXTexMapID(*(void**)(self + 0xF4), 0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_TEXC);
    GXSetTevColor(GX_TEVREG1, *(GXColor*)&lbl_8053D918);
    GXSetZMode(GX_FALSE, GX_LEQUAL, GX_FALSE);
    GXSetZCompLoc(GX_FALSE);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition3f32(0.0f, 0.0f, 0.0f);
    GXTexCoord2f32(cx - hx, cy - hy);
    GXPosition3f32(fw, 0.0f, 0.0f);
    GXTexCoord2f32(cx + hx, cy - hy);
    GXPosition3f32(fw, fh, 0.0f);
    GXTexCoord2f32(cx + hx, cy + hy);
    GXPosition3f32(0.0f, fh, 0.0f);
    GXTexCoord2f32(cx - hx, cy + hy);
    GXSetTevColor(GX_TEVREG1, *(GXColor*)&lbl_8053D91C);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition3f32(0.0f, 0.0f, 0.0f);
    GXTexCoord2f32(cx - hx, cy - hy);
    GXPosition3f32(fw, 0.0f, 0.0f);
    GXTexCoord2f32(cx + hx, cy - hy);
    GXPosition3f32(fw, fh, 0.0f);
    GXTexCoord2f32(cx + hx, cy + hy);
    GXPosition3f32(0.0f, fh, 0.0f);
    GXTexCoord2f32(cx - hx, cy + hy);
    GXSetTevColor(GX_TEVREG1, *(GXColor*)&lbl_8053D920);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition3f32(0.0f, 0.0f, 0.0f);
    GXTexCoord2f32(cx - hx, cy - hy);
    GXPosition3f32(fw, 0.0f, 0.0f);
    GXTexCoord2f32(cx + hx, cy - hy);
    GXPosition3f32(fw, fh, 0.0f);
    GXTexCoord2f32(cx + hx, cy + hy);
    GXPosition3f32(0.0f, fh, 0.0f);
    GXTexCoord2f32(cx - hx, cy + hy);
}

extern "C" void fn_8016CB14(void* param_1) {
    u8* p = (u8*)param_1;
    if (p[0x1c7] != 0) {
        u8* r8 = *(u8**)(lbl_8053AB10 + 0x24);
        u8* r7 = *(u8**)(sManager__8JUTVideo + 0x4);
        u32 a = *(u32*)(*(u8**)(lbl_8053AB10 + 0x20) + 0x2380);
        u32 b = *(u32*)(*(u8**)(lbl_8053AB10 + 0x20) + 0x2384);
        f32 fa = (f32)a;
        f32 fb = (f32)b;
        f32 fw = (f32)*(u16*)(r7 + 0x4);
        f32 fh = (f32)*(u16*)(r7 + 0x6);
        f32 v1 = (f32)(*(u32*)(p + 0x1c0) & 0xfff);
        f32 v2 = (f32)(*(u32*)(p + 0x1c0) & 0x3ff);
        f32 sx = lbl_8053D938 / fa;
        f32 sy = lbl_8053D938 / fb;
        f32 k = lbl_8053D93C / *(f32*)(r8 + 0x858);
        f32 f4 = lbl_8053D940 * v1;
        f32 f29 = -*(f32*)(r8 + 0x10) * sx - f4;
        f32 f28 = -*(f32*)(r8 + 0x20) * sy - f4;
        f32 f31 = k * (lbl_8053D940 * (sx * fw));
        f32 f30 = k * (lbl_8053D940 * (sy * fh));
        fn_8013B460(lbl_8053AB10);
        fn_8013B1E8(lbl_8053AB10);
        GXClearVtxDesc();
        GXSetVtxDesc((GXAttr)9, GX_DIRECT);
        GXSetVtxDesc((GXAttr)13, GX_DIRECT);
        GXSetVtxDesc((GXAttr)14, GX_DIRECT);
        GXSetVtxDesc((GXAttr)15, GX_DIRECT);
        GXSetVtxAttrFmt(GX_VTXFMT0, (GXAttr)9, GX_POS_XYZ, GX_F32, 0);
        GXSetVtxAttrFmt(GX_VTXFMT0, (GXAttr)13, GX_TEX_ST, GX_F32, 0);
        GXSetVtxAttrFmt(GX_VTXFMT0, (GXAttr)14, GX_TEX_ST, GX_F32, 0);
        GXSetVtxAttrFmt(GX_VTXFMT0, (GXAttr)15, GX_TEX_ST, GX_F32, 0);
        GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_TEXMTX0, GX_FALSE, GX_PTTEXMTX0);
        GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX2x4, GX_TG_TEX1, GX_TEXMTX0, GX_FALSE, GX_PTTEXMTX0);
        GXSetTexCoordGen2(GX_TEXCOORD2, GX_TG_MTX2x4, GX_TG_TEX2, GX_TEXMTX0, GX_FALSE, GX_PTTEXMTX0);
        GXSetNumTexGens(3);
        load__10JUTTextureF11_GXTexMapID(*(void**)(p + 0xfc), 0);
        load__10JUTTextureF11_GXTexMapID(*(void**)(p + 0xf4), 1);
        load__10JUTTextureF11_GXTexMapID(*(void**)(p + 0x100), 2);
        GXSetNumIndStages(2);
        GXSetIndTexOrder(GX_INDTEXSTAGE0, GX_TEXCOORD2, GX_TEXMAP2);
        GXSetIndTexOrder(GX_INDTEXSTAGE1, GX_TEXCOORD2, GX_TEXMAP2);
        GXSetTevIndWarp(GX_TEVSTAGE0, GX_INDTEXSTAGE0, GX_TRUE, GX_FALSE, GX_ITM_1);
        GXSetTevIndWarp(GX_TEVSTAGE1, GX_INDTEXSTAGE1, GX_TRUE, GX_FALSE, GX_ITM_1);
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
        GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR_NULL);
        GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_TEXC, GX_CC_RASC, GX_CC_ZERO);
        GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_KONST);
        GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
        GXSetNumTevStages(2);
        GXColor color = *(GXColor*)&lbl_80543F38;
        color.a = p[0x1ec];
        GXSetTevColor(GX_TEVREG1, color);
        GXSetZMode(GX_FALSE, GX_LEQUAL, GX_FALSE);
        GXSetZCompLoc(GX_FALSE);
        GXBegin(GX_QUADS, GX_VTXFMT0, 4);
        GXPosition3f32(0.0f, 0.0f, 0.0f);
        GXTexCoord2f32(f29 - f31, f28 - f30);
        GXTexCoord2f32(f29 - f31, f28 - f30);
        GXTexCoord2f32(f29 - f31, f28 - f30);
        GXPosition3f32(fw, 0.0f, 0.0f);
        GXTexCoord2f32(f29 + f31, f28 - f30);
        GXTexCoord2f32(f29 + f31, f28 - f30);
        GXTexCoord2f32(f29 + f31, f28 - f30);
        GXPosition3f32(fw, fh, 0.0f);
        GXTexCoord2f32(f29 + f31, f28 + f30);
        GXTexCoord2f32(f29 + f31, f28 + f30);
        GXTexCoord2f32(f29 + f31, f28 + f30);
        GXPosition3f32(0.0f, fh, 0.0f);
        GXTexCoord2f32(f29 - f31, f28 + f30);
        GXTexCoord2f32(f29 - f31, f28 + f30);
        GXTexCoord2f32(f29 - f31, f28 + f30);
    }
}

extern "C" void fn_8016D284(u8* self) {
    if (self[0x1C6]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0x14), &offset, -1, 1, 1, lbl_8053D940, lbl_8053D960);
    }
}

extern "C" void fn_8016D2E0(u8* self) {
    if (self[0x1C5]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0xC), &offset, -1, 1, 1, lbl_8053D940, lbl_8053D960);
    }
}

extern "C" void fn_8016D33C(u8* self) {
    if (self[0x1C4]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 4), &offset, -1, 1, 1, lbl_8053D940, lbl_8053D960);
    }
}

extern "C" void fn_8016D398(void* a1, void* a2, s32 a3, s32 a4, void* a5, void* a6, void* a7, void* a8, void* a9, void* a10, f32 scale) {
    u8* g;
    u8* p;
    u8* base = (u8*)a1;
    s32 i;
    Vec neg;
    u32 seed;
    u32 bits;

    neg.x = -*(f32*)(base + 0xc);
    neg.y = -*(f32*)(base + 0x1c);
    neg.z = lbl_8053D944;

    if ((u8)a4) {
        if (*(s32*)a6 > 0) {
            (*(s32*)a6)--;
        } else {
            g = (u8*)lbl_8053AAF8;
            seed = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
            *(u32*)(g + 0xb4) = seed;
            bits = (seed >> 9) | 0x3f800000;
            *(s32*)a6 = (s32)(lbl_8053D9BC * (*(f32*)&bits - lbl_8053D93C));
            p = (u8*)a5;
            for (i = 0; i < 4; i++, p += 0x1c) {
                if (*(s32*)(p + 0x14) == 0) {
                    f32 ry, rx;
                    Vec z;
                    *(s32*)(p + 0x14) = 0x3c;
                    *(u16*)(p + 0x10) = 0x288;
                    seed = *(u32*)(lbl_8053AAF8 + 0xb4) * 0x19660d + 0x3c6ef35f;
                    *(u32*)(lbl_8053AAF8 + 0xb4) = seed;
                    bits = (seed >> 9) | 0x3f800000;
                    ry = *(f32*)&bits - lbl_8053D93C;
                    seed = *(u32*)(lbl_8053AAF8 + 0xb4) * 0x19660d + 0x3c6ef35f;
                    *(u32*)(lbl_8053AAF8 + 0xb4) = seed;
                    bits = (seed >> 9) | 0x3f800000;
                    rx = *(f32*)&bits - lbl_8053D93C;
                    *(f32*)(p + 0x4) = lbl_8053D9C0 * rx - lbl_8053D9C4;
                    *(f32*)(p + 0x8) = lbl_8053D9C8 * ry + lbl_8053D970;
                    *(f32*)(p + 0xc) = lbl_8053D944;
                    z.x = lbl_8053D944;
                    z.y = lbl_8053D944;
                    z.z = lbl_8053D944;
                    *(void**)p = fn_8013CC50(0, &z, *(u16*)(p + 0x10), 0, 0, 0, 0, 1, lbl_8053D9CC);
                    if (*(void**)p != 0) {
                        *(u32*)((u8*)*(void**)p + 0xf4) |= 0x40;
                    }
                }
            }
        }
    }
}

// Retail keeps individual comparisons rather than folding consecutive modes.
#pragma optimization_level 3
extern "C" void fn_8016DA6C(u8* self) {
    bool enabled;
    if (lbl_8053AAF8[0x7F]) {
        u8 selected = 0;
        if (*(s32*)(lbl_8053AAF8 + 0x4C) == 7 || *(s32*)(lbl_8053AAF8 + 0x4C) == 8 || *(s32*)(lbl_8053AAF8 + 0x4C) == 9 || *(s32*)(lbl_8053AAF8 + 0x4C) == 22 || *(s32*)(lbl_8053AAF8 + 0x4C) == 10 || *(s32*)(lbl_8053AAF8 + 0x4C) == 11) selected = 1;
        enabled = selected;
    } else {
        u8 selected = 0;
        if (*(s32*)(lbl_8053AAF8 + 0x4C) == 7 || *(s32*)(lbl_8053AAF8 + 0x4C) == 8 || *(s32*)(lbl_8053AAF8 + 0x4C) == 9 || *(s32*)(lbl_8053AAF8 + 0x4C) == 22 || *(s32*)(lbl_8053AAF8 + 0x4C) == 10 || *(s32*)(lbl_8053AAF8 + 0x4C) == 11 || *(s32*)(lbl_8053AAF8 + 0x4C) == 12) selected = 1;
        enabled = selected;
    }
    if (enabled) {
        fn_8016ADE0(self);
        fn_8016AD84(self);
    }
}

#pragma optimization_level 3
extern "C" void fn_8016DB60(u8* self) {
    extern void fn_8016D33C(u8*);
    extern void fn_8016D2E0(u8*);
    extern void fn_8016D284(u8*);
    extern void fn_8016CB14(u8*);
    extern void fn_8016C2FC(u8*);
    extern void fn_8016B910(u8*);
    extern void fn_8016B8AC(u8*);
    extern void fn_8016B4D4(u8*);
    extern void fn_8016B248(u8*);
    extern void fn_8016B0B0(u8*);
    extern void fn_8016ACCC(u8*);
    extern void fn_8016AD28(u8*);
    extern void fn_8016AC70(u8*);
    extern void fn_8016AC14(u8*);
    extern void fn_8016B054(u8*);
    extern void fn_8016ABB8(u8*);
    extern void fn_8016AB5C(u8*);
    extern void fn_8016AAA4(u8*);
    extern void fn_8016A9EC(u8*);
    extern void fn_8016AB00(u8*);
    extern void fn_8016AA48(u8*);
    bool enabled;
    if (lbl_8053AAF8[0x7F]) {
        u8 selected = 0;
        s32 mode = *(s32*)(lbl_8053AAF8 + 0x4C);
        if (mode == 7) selected = 1;
        if (mode == 8) selected = 1;
        if (mode == 9) selected = 1;
        if (mode == 22) selected = 1;
        if (mode == 10) selected = 1;
        if (mode == 11) selected = 1;
        enabled = selected;
    } else {
        u8 selected = 0;
        s32 mode = *(s32*)(lbl_8053AAF8 + 0x4C);
        if (mode == 7) selected = 1;
        if (mode == 8) selected = 1;
        if (mode == 9) selected = 1;
        if (mode == 22) selected = 1;
        if (mode == 10) selected = 1;
        if (mode == 11) selected = 1;
        if (mode == 12) selected = 1;
        enabled = selected;
    }
    if (enabled) {
        fn_8016D33C(self);
        fn_8016D2E0(self);
        fn_8016D284(self);
        fn_8016CB14(self);
        fn_8016C2FC(self);
        fn_8016B910(self);
        fn_8016B8AC(self);
        fn_8016B4D4(self);
        fn_8016B248(self);
        fn_8016B0B0(self);
        fn_8016ACCC(self);
        fn_8016AD28(self);
        fn_8016AC70(self);
        fn_8016AC14(self);
        fn_8016B054(self);
        fn_8016ABB8(self);
        fn_8016AB5C(self);
        fn_8016AAA4(self);
        fn_8016A9EC(self);
        fn_8016AB00(self);
        fn_8016AA48(self);
    }
}
#pragma optimization_level 4

#pragma optimization_level 3
extern "C" void fn_8016DCEC(u8* self) {
    extern u8* lbl_8053AB10;
    extern f32 lbl_8053D968;
    extern void fn_8016D398(void*, void*, s32, s32, void*, void*, void*, void*, void*, void*, f32);
    bool enabled;
    u8* mgr;
    if (lbl_8053AAF8[0x7F]) {
        s32 mode = *(s32*)(lbl_8053AAF8 + 0x4C);
        u8 selected = 0;
        if (mode == 7) selected = 1;
        if (mode == 8) selected = 1;
        if (mode == 9) selected = 1;
        if (mode == 22) selected = 1;
        if (mode == 10) selected = 1;
        if (mode == 11) selected = 1;
        enabled = selected;
    } else {
        s32 mode = *(s32*)(lbl_8053AAF8 + 0x4C);
        u8 selected = 0;
        if (mode == 7) selected = 1;
        if (mode == 8) selected = 1;
        if (mode == 9) selected = 1;
        if (mode == 22) selected = 1;
        if (mode == 10) selected = 1;
        if (mode == 11) selected = 1;
        if (mode == 12) selected = 1;
        enabled = selected;
    }
    if (enabled && self[0x1CF] != 0 && *(s32*)(lbl_8053AAF8 + 0x4C) != 11) {
        mgr = *(u8**)(lbl_8053AB10 + 0x24);
        fn_8016D398(mgr + 4, *(void**)(self + 0x1C0), 0, self[0x1D0] == 0, self + 0x140, self + 0x1B0, self + 0x1B8, self + 0x1B4, self + 0x54, self + 0x6C, lbl_8053D968 / *(f32*)(mgr + 0x858));
    }
}
#pragma optimization_level 4

extern "C" void fn_8016ED88(u8* self) {
    *(void**)(self + 0x00) = 0;
    *(void**)(self + 0x14) = 0;
    *(void**)(self + 0x1C) = 0;
    *(void**)(self + 0x30) = 0;
    *(void**)(self + 0x38) = 0;
    *(void**)(self + 0x4C) = 0;
    *(void**)(self + 0x54) = 0;
    *(void**)(self + 0x68) = 0;
}

extern "C" void fn_8016EDB0(u8* self) {
    self[0x1EC] = 0;
    self[0x1ED] = 0;
    self[0x1EE] = 0;
    self[0x1EF] = 0;
    self[0x1F0] = 0;
    self[0x1F1] = 0;
    self[0x1F2] = 0;
    self[0x1F3] = 0;
    self[0x1F4] = 0;
    self[0x1F5] = 0;
    self[0x1C4] = 0;
    self[0x1C5] = 0;
    self[0x1C6] = 0;
    self[0x1C7] = 0;
    self[0x1C8] = 0;
    self[0x1C9] = 0;
    self[0x1CA] = 0;
    self[0x1CB] = 0;
    self[0x1CC] = 0;
    self[0x1CD] = 0;
    self[0x1CE] = 0;
    self[0x1CF] = 0;
    self[0x1D1] = 0;
    self[0x1D2] = 0;
    self[0x1D3] = 0;
    *(s32*)(self + 0x1D8) = -1;
    self[0x1DC] = 0;
    self[0x1DD] = 0;
    *(void**)(self + 0x130) = 0;
    *(void**)(self + 0x134) = 0;
    *(void**)(self + 0x124) = 0;
    *(void**)(self + 0x128) = 0;
    *(void**)(self + 0x12C) = 0;
    *(void**)(self + 0x13C) = 0;
    *(void**)(self + 0x138) = 0;
    *(s32*)(self + 0x1B0) = 120;
    *(s32*)(self + 0x1B8) = 60;
    self[0x1B4] = 0;
    *(void**)(self + 0x140) = 0;
    *(void**)(self + 0x154) = 0;
    *(void**)(self + 0x15C) = 0;
    *(void**)(self + 0x170) = 0;
    *(void**)(self + 0x178) = 0;
    *(void**)(self + 0x18C) = 0;
    *(void**)(self + 0x194) = 0;
    *(void**)(self + 0x1A8) = 0;
    self[0x1BC] = 0;
    *(s32*)(self + 0x1C0) = 0;
}

extern "C" void* fn_8013C824(void);
extern "C" void __dt__10JUTTextureFv(void*, s32);
extern "C" void destroy__7JKRHeapFv(void*);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_8016EE84(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        u8* p;
        s32 i = 0;
        p = (u8*)this_;
        for (; i < 4; i++) {
            void* emitter = *(void**)(p + 0x140);
            if (emitter != 0) {
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), emitter);
            }
            if (*(void**)(p + 0x158) != 0) {
                void* obj = *(void**)(p + 0x158);
                if (obj != 0) {
                    void (**vt)(void*, s32) = *(void (***)(void*, s32))((u8*)obj + 8);
                    vt[12](obj, 1);
                }
            }
            p += 0x1c;
        }
        if (*(u32*)((u8*)this_ + 0x138) != 0) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void**)((u8*)this_ + 0x138));
        }
        if (*(u32*)((u8*)this_ + 0x13c) != 0) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void**)((u8*)this_ + 0x13c));
        }
        if (*(u32*)((u8*)this_ + 0x130) != 0) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void**)((u8*)this_ + 0x130));
        }
        if (*(u32*)((u8*)this_ + 0x134) != 0) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void**)((u8*)this_ + 0x134));
        }
        if (*(u32*)((u8*)this_ + 0x124) != 0) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void**)((u8*)this_ + 0x124));
        }
        if (*(u32*)((u8*)this_ + 0x128) != 0) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void**)((u8*)this_ + 0x128));
        }
        if (*(u32*)((u8*)this_ + 0x12c) != 0) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void**)((u8*)this_ + 0x12c));
        }
        if (*(void**)((u8*)this_ + 0x120) != 0) {
            __dt__10JUTTextureFv(*(void**)((u8*)this_ + 0x120), 1);
        }
        if (*(void**)((u8*)this_ + 0x11c) != 0) {
            __dt__10JUTTextureFv(*(void**)((u8*)this_ + 0x11c), 1);
        }
        if (*(void**)((u8*)this_ + 0x118) != 0) {
            __dt__10JUTTextureFv(*(void**)((u8*)this_ + 0x118), 1);
        }
        if (*(void**)((u8*)this_ + 0x114) != 0) {
            __dt__10JUTTextureFv(*(void**)((u8*)this_ + 0x114), 1);
        }
        if (*(void**)((u8*)this_ + 0x110) != 0) {
            __dt__10JUTTextureFv(*(void**)((u8*)this_ + 0x110), 1);
        }
        if (*(void**)((u8*)this_ + 0x10c) != 0) {
            __dt__10JUTTextureFv(*(void**)((u8*)this_ + 0x10c), 1);
        }
        if (*(void**)((u8*)this_ + 0x108) != 0) {
            __dt__10JUTTextureFv(*(void**)((u8*)this_ + 0x108), 1);
        }
        if (*(void**)((u8*)this_ + 0x104) != 0) {
            __dt__10JUTTextureFv(*(void**)((u8*)this_ + 0x104), 1);
        }
        __dt__10JUTTextureFv(*(void**)((u8*)this_ + 0x100), 1);
        __dt__10JUTTextureFv(*(void**)((u8*)this_ + 0xfc), 1);
        __dt__10JUTTextureFv(*(void**)((u8*)this_ + 0xf8), 1);
        __dt__10JUTTextureFv(*(void**)((u8*)this_ + 0xf4), 1);
        destroy__7JKRHeapFv(*(void**)this_);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern u8 lbl_80529DEC[];
extern u8 lbl_80466368[];
extern u8 lbl_804A0790[];
extern u8 lbl_8053DA04[];
extern "C" void fn_8016FDE0(void);
extern "C" void __construct_array(void*, void*, void*, u32, u32);
extern "C" void* __nw__FUlP7JKRHeapi(u32, JKRHeap*, s32);
extern "C" void* __nw__FUl(u32);
extern "C" void __ct__14WaveControllerFlll(void*, s32, s32, s32);
extern "C" void storeTIMG__10JUTTextureFPC7ResTIMGUc(char* self, const void* timg, u8 palette);
extern "C" void* fn_8016F0BC(u8* self, JKRHeap* heap) {
    u32 strs = (u32)lbl_80466368;
    __construct_array(self + 0x140, (void*)fn_8016FDE0, 0, 0x1c, 4);
    *(JKRSolidHeap**)self = JKRSolidHeap::create(0xffffffff, heap, false);
    (*(JKRHeap**)self)->becomeCurrentHeap();
    u8* tbl = lbl_80529DEC;
    fn_8016A3BC(*(JKRArchive**)(tbl + 0x14), (const char*)(strs + 0xb4), (const char*)(strs + 0xc0), 0, 0, 0, 0x240000, *(JKRHeap**)self, (J3DModel**)(self + 4), (J3DAnmTextureSRTKey**)(self + 8), 0, 0, 0);
    fn_8016A3BC(*(JKRArchive**)(tbl + 0x14), (const char*)(strs + 0xcc), (const char*)(strs + 0xdc), 0, 0, 0, 0x240000, *(JKRHeap**)self, (J3DModel**)(self + 0xc), (J3DAnmTextureSRTKey**)(self + 0x10), 0, 0, 0);
    fn_8016A3BC(*(JKRArchive**)(tbl + 0x14), (const char*)(strs + 0xec), (const char*)(strs + 0xfc), 0, 0, 0, 0x240000, *(JKRHeap**)self, (J3DModel**)(self + 0x14), (J3DAnmTextureSRTKey**)(self + 0x18), 0, 0, 0);
    fn_8016A3BC(*(JKRArchive**)(tbl + 0x14), (const char*)(strs + 0x10c), (const char*)(strs + 0x118), 0, (const char*)(strs + 0x124), 0, 0x240000, *(JKRHeap**)self, (J3DModel**)(self + 0x1c), (J3DAnmTextureSRTKey**)(self + 0x20), 0, (J3DAnmTevRegKey**)(self + 0x24), 0);
    fn_8016A3BC(*(JKRArchive**)(tbl + 0x14), (const char*)(strs + 0x130), (const char*)(strs + 0x144), 0, (const char*)(strs + 0x158), 0, 0x11240000, *(JKRHeap**)self, (J3DModel**)(self + 0x28), (J3DAnmTextureSRTKey**)(self + 0x2c), 0, (J3DAnmTevRegKey**)(self + 0x30), 0);
    fn_8016A3BC(*(JKRArchive**)(tbl + 0x14), (const char*)(strs + 0x16c), (const char*)(strs + 0x17c), 0, (const char*)(strs + 0x18c), 0, 0x11240000, *(JKRHeap**)self, (J3DModel**)(self + 0x90), (J3DAnmTextureSRTKey**)(self + 0x94), 0, (J3DAnmTevRegKey**)(self + 0x98), 0);
    fn_8016A3BC(*(JKRArchive**)(tbl + 0x14), (const char*)(strs + 0x19c), (const char*)(strs + 0x1b4), 0, (const char*)(strs + 0x1cc), 0, 0x11240000, *(JKRHeap**)self, (J3DModel**)(self + 0x9c), (J3DAnmTextureSRTKey**)(self + 0xa0), 0, (J3DAnmTevRegKey**)(self + 0xa4), 0);
    fn_8016A3BC(*(JKRArchive**)(tbl + 0x14), (const char*)(strs + 0x1e4), (const char*)(strs + 0x1f8), 0, (const char*)(strs + 0x20c), 0, 0x11240000, *(JKRHeap**)self, (J3DModel**)(self + 0xa8), (J3DAnmTextureSRTKey**)(self + 0xac), 0, (J3DAnmTevRegKey**)(self + 0xb0), 0);
    fn_8016A3BC(*(JKRArchive**)(tbl + 0x14), (const char*)(strs + 0x220), (const char*)(strs + 0x238), 0, (const char*)(strs + 0x250), 0, 0x11240000, *(JKRHeap**)self, (J3DModel**)(self + 0xb4), (J3DAnmTextureSRTKey**)(self + 0xb8), 0, (J3DAnmTevRegKey**)(self + 0xbc), 0);
    fn_8016A3BC(*(JKRArchive**)(tbl + 0x14), (const char*)(strs + 0x268), (const char*)(strs + 0x278), 0, 0, 0, 0x1240000, *(JKRHeap**)self, (J3DModel**)(self + 0x34), (J3DAnmTextureSRTKey**)(self + 0x38), 0, 0, 0);
    u8* tbl2 = lbl_80529DEC;
    fn_8016A3BC(*(JKRArchive**)(tbl2 + 0x10), (const char*)(strs + 0x288), 0, 0, 0, 0, 0x220000, *(JKRHeap**)self, (J3DModel**)(self + 0xec), 0, 0, 0, 0);
    *(void**)(self + 0xf0) = 0;
    if (*(void**)(self + 0xec) == 0) {
        fn_8016A3BC(*(JKRArchive**)(tbl2 + 0x10), (const char*)(strs + 0x294), 0, 0, 0, 0, 0x220000, *(JKRHeap**)self, (J3DModel**)(self + 0xec), 0, 0, 0, 0);
    }
    if (*(void**)(self + 0xec) == 0) {
        fn_8016A3BC(*(JKRArchive**)(tbl2 + 0x10), (const char*)(strs + 0x2a0), (const char*)(strs + 0x2ac), 0, 0, 0, 0x220000, *(JKRHeap**)self, (J3DModel**)(self + 0xec), (J3DAnmTextureSRTKey**)(self + 0xf0), 0, 0, 0);
    }
    if (*(void**)(self + 0xec) == 0) {
        fn_8016A3BC(*(JKRArchive**)(tbl2 + 0x10), (const char*)(strs + 0x2b8), 0, 0, 0, 0, 0x220000, *(JKRHeap**)self, (J3DModel**)(self + 0xec), 0, 0, 0, 0);
    }
    if (*(void**)(self + 0xec) == 0) {
        fn_8016A3BC(*(JKRArchive**)(tbl2 + 0x10), (const char*)(strs + 0x2c4), 0, 0, 0, 0, 0x220000, *(JKRHeap**)self, (J3DModel**)(self + 0xec), 0, 0, 0, 0);
    }
    {
        const char** ent = (const char**)lbl_804A0790;
        u8* p = self;
        for (s32 i = 0; i < 6; i++) {
            fn_8016A3BC(*(JKRArchive**)(tbl2 + 0x10), ent[0], ent[1], 0, ent[2], 0, 0x10240000, *(JKRHeap**)self, (J3DModel**)(p + 0x3c), (J3DAnmTextureSRTKey**)(p + 0x54), 0, (J3DAnmTevRegKey**)(p + 0x6c), 0);
            ent += 3;
            p += 4;
        }
    }
    fn_8016A3BC(*(JKRArchive**)(tbl2 + 0x10), (const char*)(strs + 0x2d0), (const char*)(strs + 0x2e4), 0, (const char*)(strs + 0x2f8), 0, 0x11240000, *(JKRHeap**)self, (J3DModel**)(self + 0x84), (J3DAnmTextureSRTKey**)(self + 0x88), 0, (J3DAnmTevRegKey**)(self + 0x8c), 0);
    fn_8016A3BC(*(JKRArchive**)(tbl2 + 0x10), (const char*)(strs + 0x30c), (const char*)(strs + 0x320), 0, (const char*)(strs + 0x334), 0, 0x240000, *(JKRHeap**)self, (J3DModel**)(self + 0xc0), (J3DAnmTextureSRTKey**)(self + 0xc4), 0, (J3DAnmTevRegKey**)(self + 0xc8), 0);
    fn_8016A3BC(*(JKRArchive**)(tbl2 + 0x10), (const char*)(strs + 0x348), (const char*)(strs + 0x358), 0, 0, 0, 0x240000, *(JKRHeap**)self, (J3DModel**)(self + 0xcc), (J3DAnmTextureSRTKey**)(self + 0xd0), 0, 0, 0);
    fn_8016A3BC(*(JKRArchive**)(tbl2 + 0x10), (const char*)(strs + 0x368), (const char*)(strs + 0x378), 0, (const char*)(strs + 0x388), 0, 0x11240000, *(JKRHeap**)self, (J3DModel**)(self + 0xd4), (J3DAnmTextureSRTKey**)(self + 0xd8), 0, (J3DAnmTevRegKey**)(self + 0xdc), 0);
    fn_8016A3BC(*(JKRArchive**)(tbl + 0x14), (const char*)(strs + 0x398), (const char*)(strs + 0x3a8), 0, (const char*)(strs + 0x3b8), 0, 0x240000, *(JKRHeap**)self, (J3DModel**)(self + 0xe0), (J3DAnmTextureSRTKey**)(self + 0xe4), 0, (J3DAnmTevRegKey**)(self + 0xe8), 0);
    ((JKRSolidHeap*)*(void**)self)->adjustSize();
    heap->becomeCurrentHeap();
    {
        u8* tex = (u8*)__nw__FUlP7JKRHeapi(0x40, heap, 0);
        if (tex) {
            void* res = ((JKRArchive*)*(void**)(lbl_8053AAF8 + 0xa4))->getResource(0x3f3f3f3f, (const char*)(strs + 0x3c8));
            *(void**)(tex + 0x28) = 0;
            storeTIMG__10JUTTextureFPC7ResTIMGUc((char*)tex, res, 0);
            tex[0x3b] &= 2;
        }
        *(u8**)(self + 0xf4) = tex;
    }
    {
        u8* tex = (u8*)__nw__FUlP7JKRHeapi(0x40, heap, 0);
        if (tex) {
            void* res = ((JKRArchive*)*(void**)(lbl_8053AAF8 + 0xa4))->getResource(0x3f3f3f3f, (const char*)(strs + 0x3d8));
            *(void**)(tex + 0x28) = 0;
            storeTIMG__10JUTTextureFPC7ResTIMGUc((char*)tex, res, 0);
            tex[0x3b] &= 2;
        }
        *(u8**)(self + 0xf8) = tex;
    }
    {
        u8* tex = (u8*)__nw__FUlP7JKRHeapi(0x40, heap, 0);
        if (tex) {
            void* res = ((JKRArchive*)*(void**)(lbl_8053AAF8 + 0xa4))->getResource(0x3f3f3f3f, (const char*)(strs + 0x3e4));
            *(void**)(tex + 0x28) = 0;
            storeTIMG__10JUTTextureFPC7ResTIMGUc((char*)tex, res, 0);
            tex[0x3b] &= 2;
        }
        *(u8**)(self + 0xfc) = tex;
    }
    {
        u8* tex = (u8*)__nw__FUlP7JKRHeapi(0x40, heap, 0);
        if (tex) {
            void* res = ((JKRArchive*)*(void**)(lbl_8053AAF8 + 0xa4))->getResource(0x3f3f3f3f, (const char*)(strs + 0x3f4));
            *(void**)(tex + 0x28) = 0;
            storeTIMG__10JUTTextureFPC7ResTIMGUc((char*)tex, res, 0);
            tex[0x3b] &= 2;
        }
        *(u8**)(self + 0x100) = tex;
    }
    {
        u8* tex = 0;
        JKRArchive* arc = *(JKRArchive**)(tbl2 + 0x10);
        if (arc && arc->getResource(0x54494d47, (const char*)(strs + 0x40c))) {
            tex = (u8*)__nw__FUlP7JKRHeapi(0x40, heap, 0);
            if (tex) {
                void* res = arc->getResource(0x54494d47, (const char*)(strs + 0x40c));
                *(void**)(tex + 0x28) = 0;
                storeTIMG__10JUTTextureFPC7ResTIMGUc((char*)tex, res, 0);
                tex[0x3b] &= 2;
            }
        }
        *(u8**)(self + 0x104) = tex;
    }
    {
        u8* tex = 0;
        JKRArchive* arc = *(JKRArchive**)(tbl2 + 0x10);
        if (arc && arc->getResource(0x54494d47, (const char*)(strs + 0x418))) {
            tex = (u8*)__nw__FUlP7JKRHeapi(0x40, heap, 0);
            if (tex) {
                void* res = arc->getResource(0x54494d47, (const char*)(strs + 0x418));
                *(void**)(tex + 0x28) = 0;
                storeTIMG__10JUTTextureFPC7ResTIMGUc((char*)tex, res, 0);
                tex[0x3b] &= 2;
            }
        }
        *(u8**)(self + 0x108) = tex;
    }
    {
        u8* tex = 0;
        JKRArchive* arc = *(JKRArchive**)(tbl2 + 0x10);
        if (arc && arc->getResource(0x54494d47, (const char*)(strs + 0x424))) {
            tex = (u8*)__nw__FUlP7JKRHeapi(0x40, heap, 0);
            if (tex) {
                void* res = arc->getResource(0x54494d47, (const char*)(strs + 0x424));
                *(void**)(tex + 0x28) = 0;
                storeTIMG__10JUTTextureFPC7ResTIMGUc((char*)tex, res, 0);
                tex[0x3b] &= 2;
            }
        }
        *(u8**)(self + 0x10c) = tex;
    }
    {
        u8* tex = 0;
        JKRArchive* arc = *(JKRArchive**)(tbl2 + 0x10);
        if (arc && arc->getResource(0x54494d47, (const char*)(strs + 0x434))) {
            tex = (u8*)__nw__FUlP7JKRHeapi(0x40, heap, 0);
            if (tex) {
                void* res = arc->getResource(0x54494d47, (const char*)(strs + 0x434));
                *(void**)(tex + 0x28) = 0;
                storeTIMG__10JUTTextureFPC7ResTIMGUc((char*)tex, res, 0);
                tex[0x3b] &= 2;
            }
        }
        *(u8**)(self + 0x110) = tex;
    }
    {
        u8* tex = 0;
        JKRArchive* arc = *(JKRArchive**)(tbl2 + 0x10);
        if (arc && arc->getResource(0x54494d47, (const char*)lbl_8053DA04)) {
            tex = (u8*)__nw__FUlP7JKRHeapi(0x40, heap, 0);
            if (tex) {
                void* res = arc->getResource(0x54494d47, (const char*)lbl_8053DA04);
                *(void**)(tex + 0x28) = 0;
                storeTIMG__10JUTTextureFPC7ResTIMGUc((char*)tex, res, 0);
                tex[0x3b] &= 2;
            }
        }
        *(u8**)(self + 0x114) = tex;
    }
    {
        u8* tex = 0;
        JKRArchive* arc = *(JKRArchive**)(tbl2 + 0x10);
        if (arc && arc->getResource(0x54494d47, (const char*)(strs + 0x440))) {
            tex = (u8*)__nw__FUlP7JKRHeapi(0x40, heap, 0);
            if (tex) {
                void* res = arc->getResource(0x54494d47, (const char*)(strs + 0x440));
                *(void**)(tex + 0x28) = 0;
                storeTIMG__10JUTTextureFPC7ResTIMGUc((char*)tex, res, 0);
                tex[0x3b] &= 2;
            }
        }
        *(u8**)(self + 0x118) = tex;
    }
    {
        u8* tex = 0;
        JKRArchive* arc = *(JKRArchive**)(tbl2 + 0x10);
        if (arc && arc->getResource(0x54494d47, (const char*)(strs + 0x450))) {
            tex = (u8*)__nw__FUlP7JKRHeapi(0x40, heap, 0);
            if (tex) {
                void* res = arc->getResource(0x54494d47, (const char*)(strs + 0x450));
                *(void**)(tex + 0x28) = 0;
                storeTIMG__10JUTTextureFPC7ResTIMGUc((char*)tex, res, 0);
                tex[0x3b] &= 2;
            }
        }
        *(u8**)(self + 0x11c) = tex;
    }
    {
        u8* tex = 0;
        JKRArchive* arc = *(JKRArchive**)(tbl2 + 0x10);
        if (arc && arc->getResource(0x54494d47, (const char*)(strs + 0x460))) {
            tex = (u8*)__nw__FUlP7JKRHeapi(0x40, heap, 0);
            if (tex) {
                void* res = arc->getResource(0x54494d47, (const char*)(strs + 0x460));
                *(void**)(tex + 0x28) = 0;
                storeTIMG__10JUTTextureFPC7ResTIMGUc((char*)tex, res, 0);
                tex[0x3b] &= 2;
            }
        }
        *(u8**)(self + 0x120) = tex;
    }
    {
        s32 i = 0;
        u8* p = self;
        do {
            void* w = __nw__FUl(0x5c);
            if (w) {
                __ct__14WaveControllerFlll(w, 0, 0, 8);
            }
            i++;
            *(void**)(p + 0x158) = w;
            p += 0x1c;
        } while (i < 4);
    }
    return self;
}

extern "C" void fn_8016FDE0(void) {
}

void __sinit_tu_8016A2B4_cpp(void) {}

