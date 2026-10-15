// tu_8013AAD4: .text 0x8013AAD4-0x8013C5C8
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

#include <dolphin/gx.h>
#include "JSystem/JUtility/JUTVideo.h"
#include "JSystem/J3D/J3DSys.h"
#include "JSystem/J3D/J3DDrawBuffer.h"
#include "JSystem/JGeometry.h"
#include "JSystem/J2D/J2DGrafContext.h"


extern void* lbl_8053AB10;

struct AADGameState {
    u8 pad0[0x4c];
    s32 mode;       // 0x4c
    u8 pad50[0x7f - 0x50];
    u8 b7f;         // 0x7f
};
extern AADGameState* lbl_8053AAF8;

static inline bool inModeA(AADGameState* g) {
    return g->mode == 7 || g->mode == 8 || g->mode == 9 || g->mode == 22 || g->mode == 10 || g->mode == 11;
}
static inline bool inModeB(AADGameState* g) {
    return g->mode == 7 || g->mode == 8 || g->mode == 9 || g->mode == 22 || g->mode == 10 || g->mode == 11 || g->mode == 12;
}
static inline bool inModeAm(s32 m) {
    bool r = false;
    if (m == 7 || m == 8 || m == 9 || m == 0x16 || m == 10 || m == 11) {
        r = true;
    }
    return r;
}
static inline bool inModeBm(s32 m) {
    bool r = false;
    if (m == 7 || m == 8 || m == 9 || m == 0x16 || m == 10 || m == 11 || m == 12) {
        r = true;
    }
    return r;
}
static inline bool isM12(s32 m) { return m == 12; }
static inline bool isNot12() { return lbl_8053AAF8->mode != 12; }
static inline bool evModeA(s32 m) { return m == 7 || m == 8 || m == 9 || m == 0x16 || m == 10 || m == 11; }
static inline bool evModeB(s32 m) { return m == 7 || m == 8 || m == 9 || m == 0x16 || m == 10 || m == 11 || m == 12; }
static inline bool evMode(u8 b, s32 m) {
    if (b) {
        return evModeA(m) != 0;
    } else {
        return evModeB(m) != 0;
    }
}
static inline bool isMode12() {
    AADGameState* g = lbl_8053AAF8;
    return g->b7f && g->mode == 12;
}
static inline bool isEventMode() {
    AADGameState* g = lbl_8053AAF8;
    if (g->b7f) {
        return inModeA(g) != 0;
    } else {
        return inModeB(g) != 0;
    }
}

extern "C" void fn_802FF0EC(void* p);
extern "C" s32 fn_8013D5D4(void* subObj);


extern "C" void fn_8030E154(void* p);
extern "C" void fn_802FF568(void* p);
extern "C" void fn_8013DC44(void* p);
extern "C" void fn_80159330(void* p);
extern "C" void fn_8016005C(void* p);
extern "C" u32* fn_8013C394();
extern "C" u8 fn_80239D38();



extern "C" s32 fn_8030DFE8(void* subObj, void* matrix);
extern "C" void fn_802FF3B0(void* p);
extern "C" void fn_802FF2D8(void* p);
extern "C" void fn_8013DA10(void* p);
extern "C" void fn_80158F70(void* p);
extern "C" void fn_8013D908(void* p);
extern "C" void __sinit_tu_8013C5C8_cpp_8013D6E4(void* p);
extern "C" void fn_8015F9C0(void* p);

static inline bool isDrawMode(u8* this_) {
    return this_[0x39] == 0 || lbl_8053AAF8->mode == 4 || lbl_8053AAF8->mode == 6;
}


extern _GXRenderModeObj lbl_8049F090;
extern _GXRenderModeObj lbl_8049F0CC;

extern "C" void fn_8013AAD4() {
    JUTVideo::getManager()->setRenderMode(&lbl_8049F090);
}

extern "C" void fn_8013AB00() {
    JUTVideo::getManager()->setRenderMode(&lbl_8049F0CC);
}

extern "C" void fn_8013AB2C() {
    J3DDrawBuffer* opa = *(J3DDrawBuffer**)((char*)lbl_8053AB10 + 0x8);
    J3DDrawBuffer* xlu = *(J3DDrawBuffer**)((char*)lbl_8053AB10 + 0xc);
    j3dSys.drawInit();
    j3dSys.reinitGX();
    GXSetColorUpdate(1);
    GXSetAlphaUpdate(0);
    j3dSys.mDrawMode = J3DSys::SYSDRAW_Unk3;
    opa->draw();
    j3dSys.mDrawMode = J3DSys::SYSDRAW_Unk4;
    xlu->draw();
    opa->frameInit();
    xlu->frameInit();
}

struct CamViewBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    f32 _pad[5];
    Vec mPos;
    Mtx mMtx;
};

extern "C" void fn_8013ABCC(CamViewBase* this_, Vec* pos, Mtx mtx) {
    this_->mPos.x = pos->x;
    this_->mPos.y = pos->y;
    this_->mPos.z = pos->z;
    PSMTXCopy(mtx, this_->mMtx);
    this_->v2();
    this_->v1();
    this_->v5();
}

extern "C" void fn_8013AC54(Mtx mtx) {
    char* mgr = (char*)lbl_8053AB10;
    j3dSys.setDrawBuffer(*(J3DDrawBuffer**)(mgr + 0x8), 0);
    j3dSys.setDrawBuffer(*(J3DDrawBuffer**)(mgr + 0xc), 1);
    j3dSys.setViewMtx(mtx);
}

extern "C" void fn_8013B004(f32* rect, GXColor* color) {
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XY, GX_F32, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, GX_SRC_REG, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetNumTexGens(0);
    GXSetTevColor(GX_TEVREG0, *color);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_C0);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_A0);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevDirect(GX_TEVSTAGE0);
    GXSetNumTevStages(1);
    GXSetNumIndStages(0);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
    GXSetZMode(GX_FALSE, GX_LEQUAL, GX_FALSE);
    GXSetZCompLoc(GX_FALSE);
    GXSetAlphaCompare(GX_GREATER, 0, GX_AOP_AND, GX_ALWAYS, 0);
    GXSetColorUpdate(GX_TRUE);
    GXSetAlphaUpdate(GX_FALSE);
    GXSetCullMode(GX_CULL_NONE);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    f32 x1 = rect[2];
    f32 x0 = rect[0];
    f32 y0 = rect[1];
    GXPosition2f32(x0, y0);
    f32 y1 = rect[3];
    GXPosition2f32(x1, y0);
    GXPosition2f32(x1, y1);
    GXPosition2f32(x0, y1);
    GXEnd();
}

extern GXColor lbl_8053CDD8;
extern GXColor lbl_80543F20;

extern "C" void fn_8013B1E8() {
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, GX_SRC_REG, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetNumTexGens(1);
    GXSetTevColor(GX_TEVREG0, lbl_8053CDD8);
    GXSetTevColor(GX_TEVREG1, lbl_80543F20);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
    GXSetTevColorIn(GX_TEVSTAGE0, (GXTevColorArg)0xf, (GXTevColorArg)8, (GXTevColorArg)2, (GXTevColorArg)4);
    GXSetTevAlphaIn(GX_TEVSTAGE0, (GXTevAlphaArg)7, (GXTevAlphaArg)4, (GXTevAlphaArg)1, (GXTevAlphaArg)2);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevDirect(GX_TEVSTAGE0);
    GXSetNumTevStages(1);
    GXSetNumIndStages(0);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetZCompLoc(GX_FALSE);
    GXSetAlphaCompare(GX_GREATER, 0, GX_AOP_AND, GX_ALWAYS, 0);
    GXSetColorUpdate(GX_TRUE);
    GXSetAlphaUpdate(GX_FALSE);
    GXSetCullMode(GX_CULL_NONE);
    GXSetClipMode(GX_CLIP_DISABLE);
}

// ---- from Game/fn_8013B3CC.cpp

// Family of thin forwarding methods on the camera/cutscene-cue-manager
// class (lbl_8053AB10's class): each reads a sub-object pointer off
// `this` and forwards to a method on it, discarding/passing through the
// result untouched.
extern "C" s32 fn_8030DD20(void* subObj);
extern "C" s32 fn_8030DD68(void* subObj);
extern "C" s32 fn_8030DD8C(void* subObj);

// fn_8013B3CC(this) - forwards to fn_8030DD20(this->0x24), the same 3rd
// sub-object fn_8013AC90 reads off the singleton.
extern "C" s32 fn_8013B3CC(void* this_) {
    return fn_8030DD20(*(void**)((char*)this_ + 0x24));
}

// fn_8013B3F0(this) - sibling of fn_8013B3CC: forwards to fn_8030DD68
// instead of fn_8030DD20, same this->0x24 sub-object.
extern "C" s32 fn_8013B3F0(void* this_) {
    return fn_8030DD68(*(void**)((char*)this_ + 0x24));
}

// fn_8013B414(this) - sibling of fn_8013B3CC/3F0: forwards to
// fn_8030DD8C, same this->0x24 sub-object.
extern "C" s32 fn_8013B414(void* this_) {
    return fn_8030DD8C(*(void**)((char*)this_ + 0x24));
}

// ---- from Game/fn_8013B438.cpp

extern "C" s32 fn_8030DFE8(void* subObj, void* matrix);

// fn_8013B438(this) - forwards to fn_8030DFE8(this->0x24, NULL) - same
// callee fn_8013AC90 uses with a live matrix pointer; NULL here likely
// means "reset to identity/no override".
extern "C" s32 fn_8013B438(void* this_) {
    return fn_8030DFE8(*(void**)((char*)this_ + 0x24), 0);
}

// ---- from Game/SubObjectForward_8013B460.cpp

// See [[reference_fsa_virtual_dispatch_codegen_trick]] for why these call
// through a real `virtual` member rather than a manual cast.
struct ActorSlot5 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void slot5();
};

// fn_8013B460(this) - forwards to this->0x14's OWN vtable slot 0x14 (a 4th
// polymorphic sub-object, distinct from the 0x8/0xc/0x24 ones seen so far).
extern "C" void fn_8013B460(void* this_) {
    ActorSlot5* sub = *(ActorSlot5**)((char*)this_ + 0x14);
    sub->slot5();
}

// fn_8013B490(this) - sibling of fn_8013B460: same vtable-slot-0x14 forward,
// but on this->0x10 (a 5th polymorphic sub-object).
extern "C" void fn_8013B490(void* this_) {
    ActorSlot5* sub = *(ActorSlot5**)((char*)this_ + 0x10);
    sub->slot5();
}

// ---- from Game/fn_8013B4C0.cpp

extern "C" s32 fn_8013D5B0(void* subObj);
extern "C" void fn_802FF548(void* subObj);

// fn_8013B4C0(this) - calls fn_8013D5B0(this->0x28) (a 6th sub-object,
// forward-referenced) then fn_802FF548(this->0x20) (a 7th sub-object,
// external).
extern "C" void fn_8013B4C0(void* this_) {
    fn_8013D5B0(*(void**)((char*)this_ + 0x28));
    fn_802FF548(*(void**)((char*)this_ + 0x20));
}

// ---- from Game/fn_8013B4F8.cpp

extern "C" s32 fn_8013D5D4(void* subObj);
extern "C" void fn_800C1EA4(void* subObj);

// fn_8013B4F8(this) - an "update all tracked sub-objects" style method:
// calls fn_8013D5D4(this->0x28) (sibling of fn_8013B4C0's fn_8013D5B0
// call) then fn_800C1EA4 on BOTH this->0x8 AND this->0xc - the same
// camera-pair fn_8013AB2C registers. Confirms this->0x8/0xc get
// touched by more than one method here, consistent with a per-frame
// refresh/update.
extern "C" void fn_8013B4F8(void* this_) {
    fn_8013D5D4(*(void**)((char*)this_ + 0x28));
    fn_800C1EA4(*(void**)((char*)this_ + 0x8));
    fn_800C1EA4(*(void**)((char*)this_ + 0xc));
}

extern "C" void fn_8013B538(void* this_) {
    if (isEventMode()) {
        fn_802FF0EC(*(void**)((char*)this_ + 0x20));
    }
}

extern "C" void fn_8013B618(void* this_) {
    if (isEventMode()) {
        fn_802FF0EC(*(void**)((char*)this_ + 0x20));
        fn_8013D5D4(*(void**)((char*)this_ + 0x28));
    }
    (*(J3DDrawBuffer**)((char*)this_ + 0x8))->frameInit();
    (*(J3DDrawBuffer**)((char*)this_ + 0xc))->frameInit();
}
extern "C" void fn_8013B71C(u8* this_) {
    if (this_[0x39] == 0 || lbl_8053AAF8->mode == 4 || lbl_8053AAF8->mode == 6) {
        fn_8030DFE8(*(void**)((char*)lbl_8053AB10 + 0x24), 0);
        j3dSys.drawInit();
        j3dSys.reinitGX();
        GXSetColorUpdate(GX_TRUE);
        GXSetAlphaUpdate(GX_FALSE);
        j3dSys.mDrawMode = J3DSys::SYSDRAW_Unk3;
        (*(J3DDrawBuffer**)(this_ + 0x8))->draw();
        j3dSys.reinitGX();
        if (isEventMode() && lbl_8053AAF8->mode != 12) {
            fn_802FF3B0(*(void**)(this_ + 0x20));
        }
        fn_8030DFE8(*(void**)((char*)lbl_8053AB10 + 0x24), 0);
        j3dSys.drawInit();
        j3dSys.reinitGX();
        GXSetColorUpdate(GX_TRUE);
        GXSetAlphaUpdate(GX_FALSE);
        GXSetBlendMode(GX_BM_BLEND, GX_BL_ONE, GX_BL_ONE, GX_LO_NOOP);
        j3dSys.mDrawMode = J3DSys::SYSDRAW_Unk4;
        (*(J3DDrawBuffer**)(this_ + 0xc))->draw();
        j3dSys.reinitGX();
        if (isEventMode() && lbl_8053AAF8->mode != 12) {
            fn_802FF2D8(*(void**)(this_ + 0x20));
        }
        fn_8013DA10(*(void**)(this_ + 0x28));
        j3dSys.drawInit();
        fn_80158F70(*(void**)(this_ + 0x2c));
    }
    fn_8013D908(*(void**)(this_ + 0x28));
    if (this_[0x39] == 0 || lbl_8053AAF8->mode == 4 || lbl_8053AAF8->mode == 6) {
        __sinit_tu_8013C5C8_cpp_8013D6E4(*(void**)(this_ + 0x28));
        if (isEventMode() || lbl_8053AAF8->mode == 12) {
            fn_8015F9C0(*(void**)(this_ + 0x30));
        }
    }
}
// ---- from Game/fn_8013BAF4.cpp

extern "C" s32 fn_8013DB2C(void* subObj);

// fn_8013BAF4(this) - another thin forwarder to the this->0x28
// sub-object family: fn_8013DB2C(this->0x28).
extern "C" s32 fn_8013BAF4(void* this_) {
    return fn_8013DB2C(*(void**)((char*)this_ + 0x28));
}

// ---- from Game/fn_8013BB18.cpp

extern "C" void fn_802FF3F0(void* subObj);
extern "C" void fn_8030E150(void* subObj);
extern "C" void fn_80158E88(void* subObj);

// fn_8013BB18(this) - gated on the SAME this->0x39 instance flag
// fn_8013B71C uses: if 0 (cutscene/transition NOT active), calls
// fn_802FF3F0(this->0x20) (sibling of fn_802FF0EC/802FF3B0/802FF2D8)
// and fn_8030E150(this->0x24) (sibling of the fog/color object's
// fn_8030DFE8/DD20/DD68/DD8C/DFE8 family). Always calls
// fn_80158E88(this->0x2c).
extern "C" void fn_8013BB18(void* this_) {
    u8 flag = *(u8*)((char*)this_ + 0x39);
    if (flag == 0) {
        fn_802FF3F0(*(void**)((char*)this_ + 0x20));
        fn_8030E150(*(void**)((char*)this_ + 0x24));
    }
    fn_80158E88(*(void**)((char*)this_ + 0x2c));
}

// ---- from Game/fn_8013BB64.cpp

extern char lbl_80536C50[];

extern "C" s32 fn_8030DFE8(void* subObj, void* matrix);
// PSMTXCopy from dolphin/mtx.h

// fn_8013BB64(this) - resets the fog/color object (this->0x24) via
// fn_8030DFE8(obj,NULL), refreshes lbl_80536C50->0x48/0x4c from this
// instance's own camera pair (this->0x8/0xc - the same fields
// fn_8013AC54 mirrors from the singleton itself, confirming
// lbl_80536C50 tracks WHICHEVER instance last ran this refresh), then
// copies a Mtx from this->0x24+4 (skipping a leading 4-byte field,
// likely a vtable ptr) into lbl_80536C50 via PSMTXCopy.
extern "C" void fn_8013BB64(void* this_) {
    fn_8030DFE8(*(void**)((char*)this_ + 0x24), 0);
    j3dSys.setDrawBuffer(*(J3DDrawBuffer**)((char*)this_ + 0x8), 0);
    j3dSys.setDrawBuffer(*(J3DDrawBuffer**)((char*)this_ + 0xc), 1);
    j3dSys.setViewMtx(*(Mtx*)(*(char**)((char*)this_ + 0x24) + 0x4));
}

// ---- from Game/fn_8013BBBC.cpp

extern "C" s32 fn_8013DC1C(void* subObj);

// fn_8013BBBC(this) - another thin forwarder to the this->0x28 family:
// fn_8013DC1C(this->0x28).
extern "C" s32 fn_8013BBBC(void* this_) {
    return fn_8013DC1C(*(void**)((char*)this_ + 0x28));
}

extern "C" void fn_8013BBE0(u8* this_) {
    if (lbl_8053AAF8->mode == 9) {
        return;
    }
    fn_8030E154(*(void**)(this_ + 0x24));
    fn_802FF568(*(void**)(this_ + 0x20));
    fn_8013DC44(*(void**)(this_ + 0x28));
    fn_80159330(*(void**)(this_ + 0x2c));
    fn_8016005C(*(void**)(this_ + 0x30));
    u32* vp = fn_8013C394();
    JGeometry::TBox2f box((f32)vp[0], (f32)vp[1], (f32)vp[2], (f32)vp[3]);
    (*(J2DGrafContext**)(this_ + 0x14))->place(box);
    (*(J2DGrafContext**)(this_ + 0x14))->scissor(box);
    if (!lbl_8053AAF8->b7f || !isNot12()) {
        this_[0x39] = 0;
        return;
    }
        if (!isEventMode()) {
            this_[0x39] = 1;
        } else {
        u8 r = 0;
        if (this_[0x38] >= 0xff) {
            bool ok = true;
            if (lbl_8053AAF8->mode != 11 && !fn_80239D38()) {
                ok = false;
            }
            if (ok) {
                r = 1;
            }
        }
        this_[0x39] = r;
        }
}
// ---- from Game/fn_8013BE04.cpp

extern "C" void fn_802FF798(void* subObj);
extern "C" void fn_8030E5BC(void* subObj);
extern "C" void fn_8013DDEC(void* subObj);
extern "C" void fn_8015945C(void* subObj);
extern "C" void fn_801601E0(void* subObj);

// fn_8013BE04(this) - a reset() method: calls a "reset" sibling on 5
// sub-objects (this->0x20 -> fn_802FF798, ->0x24 -> fn_8030E5BC, ->0x28
// -> fn_8013DDEC, ->0x2c -> fn_8015945C, ->0x30 -> fn_801601E0 - each a
// further sibling of that sub-object's already-seen method family),
// then clears both this->0x39 (the transition-active flag) and
// this->0x38 (the frame-counter fn_8013BBE0 checks against 0xff).
extern "C" void fn_8013BE04(void* this_) {
    fn_802FF798(*(void**)((char*)this_ + 0x20));
    fn_8030E5BC(*(void**)((char*)this_ + 0x24));
    fn_8013DDEC(*(void**)((char*)this_ + 0x28));
    fn_8015945C(*(void**)((char*)this_ + 0x2c));
    fn_801601E0(*(void**)((char*)this_ + 0x30));
    *(u8*)((char*)this_ + 0x39) = 0;
    *(u8*)((char*)this_ + 0x38) = 0;
}

// ---- from Game/CutsceneManagerCue_dtor_8013BE60.cpp

// fn_8013BE60(this, freeFlag) - the camera/cutscene-cue-manager
// class's real destructor. Rebinds the vtable to lbl_8049F108, then
// destructs 9 embedded polymorphic sub-objects in reverse-of-
// construction order via own vtable slot 0 (byte offset 0x8) with a
// "free=1" flag: this->0x1c/0x30/0x2c/0x28/0x24/0x20, then this->0x34
// via a direct (non-virtual) call to dtor_80092364, then
// this->0x18/0x14/0x10. Reads this->0x4 and calls fn_8008383C on it.
// Finally, if freeFlag > 0, calls the base class destructor
// dtor_80084580. See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why the sub-
// object releases go through a real `virtual` member rather than a
// manual cast.
extern "C" void dtor_80092364(void* p, s32 flag);
extern "C" void fn_8008383C(void* p);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049F108[];

struct Slot0 {
    virtual void slot0(s32 arg);
};

extern "C" void* fn_8013BE60(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F108;
        void* p;
        p = *(void**)((char*)this_ + 0x1c);
        if (p != 0) { ((Slot0*)p)->slot0(1); }
        p = *(void**)((char*)this_ + 0x30);
        if (p != 0) { ((Slot0*)p)->slot0(1); }
        p = *(void**)((char*)this_ + 0x2c);
        if (p != 0) { ((Slot0*)p)->slot0(1); }
        p = *(void**)((char*)this_ + 0x28);
        if (p != 0) { ((Slot0*)p)->slot0(1); }
        p = *(void**)((char*)this_ + 0x24);
        if (p != 0) { ((Slot0*)p)->slot0(1); }
        p = *(void**)((char*)this_ + 0x20);
        if (p != 0) { ((Slot0*)p)->slot0(1); }
        dtor_80092364(*(void**)((char*)this_ + 0x34), 1);
        p = *(void**)((char*)this_ + 0x18);
        if (p != 0) { ((Slot0*)p)->slot0(1); }
        p = *(void**)((char*)this_ + 0x14);
        if (p != 0) { ((Slot0*)p)->slot0(1); }
        p = *(void**)((char*)this_ + 0x10);
        if (p != 0) { ((Slot0*)p)->slot0(1); }
        fn_8008383C(*(void**)((char*)this_ + 0x4));
        if (flag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" u32* fn_8013C394() {
    return (u32*)(*(char**)((char*)lbl_8053AB10 + 0x24) + 0x144);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
