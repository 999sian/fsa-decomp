// tu_8013C5C8: .text 0x8013C5C8-0x8013F9A8
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/dtor_8013C5C8.cpp

extern "C" void fn_800EB208(void* this_, s32 flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049F140[];

extern "C" void* dtor_8013C5C8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F140;
        fn_800EB208(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- from Game/fn_8013C86C_dtor.cpp

extern "C" void fn_800EB208(void* this_, s32 flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049F15C[];

extern "C" void* fn_8013C86C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F15C;
        fn_800EB208(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- from Game/fn_8013D5B0.cpp

// fn_8013D5B0(this) - the first method of the this->0x28 sub-object's own
// class (forward-referenced from fn_8013B4C0/fn_8013B71C/etc in the
// camera-cue-manager cluster; this class's own dtor is dtor_8013C5C8,
// already landed). Thin forwarder: fn_800EC188(this->0xc).
extern "C" s32 fn_800EC188(void* subObj);

extern "C" s32 fn_8013D5B0(void* this_) {
    return fn_800EC188(*(void**)((char*)this_ + 0xc));
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

extern u8* lbl_8053AB10;
extern "C" void fn_8013C958(void*);
extern "C" void calc__17JPAEmitterManagerFUc(void*, u8);
extern "C" void clearResourceManager__17JPAEmitterManagerFUc(void*, u8);
extern "C" void destroy__7JKRHeapFv(void*);
extern "C" void __dt__18JPAEmitterCallBackFv(void*, s32);
extern "C" void PSMTXCopy(const void*, void*);
extern void* lbl_8049F178[];
extern void* lbl_8049F184[];

extern "C" void* fn_8013C824(void) {
    return *(void**)(lbl_8053AB10 + 0x28);
}

struct RGB3 { u8 r, g, b; };
inline void setRGB(u8* d, u8 r, u8 g, u8 b) { d[0xb8] = r; d[0xb9] = g; d[0xba] = b; }
extern "C" void fn_8013C830(u8* this_, s32 idx, u8* dst) {
    if (dst == 0) return;
    if (idx < 0) return;
    if (idx >= 4) return;
    setRGB(dst, this_[idx * 3 + 0x4110], this_[idx * 3 + 0x4111], this_[idx * 3 + 0x4112]);
}

extern "C" void fn_8013DC1C(void* this_) {
    calc__17JPAEmitterManagerFUc(*(void**)((char*)this_ + 0xc), 10);
}

extern "C" void* fn_8013F378(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F178;
        clearResourceManager__17JPAEmitterManagerFUc(*(void**)((char*)this_ + 0xc), 0);
        destroy__7JKRHeapFv(*(void**)((char*)this_ + 0x4));
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void fn_8013F584(void) {}

extern "C" void fn_8013F588(void) {
    fn_8013C958(*(void**)(lbl_8053AB10 + 0x28));
}

extern "C" void PSMTXScale(f32 (*m)[4], f32 x, f32 y, f32 z);
extern "C" void PSMTXTrans(f32 (*m)[4], f32 x, f32 y, f32 z);
extern "C" void PSMTXConcat(const f32 (*a)[4], const f32 (*b)[4], f32 (*ab)[4]);
extern "C" void fn_8013F5B0(void* this_, u8* p) {
    f32 a[3][4];
    f32 s[3][4];
    u8* obj = (u8*)*(void**)((u8*)*(void**)((u8*)*(void**)(lbl_8053AB10 + 0x28) + 0xc) + 0x20);
    PSMTXCopy(obj + 0x184, a);
    PSMTXScale(s, 1.0f, 1.0f, 1.0f);
    PSMTXConcat(a, s, a);
    PSMTXTrans(s, 0.0f, *(f32*)(p + 0xa8), *(f32*)(p + 0xac));
    PSMTXConcat(a, s, a);
    PSMTXCopy(a, obj + 0x184);
}

extern "C" void fn_8013F6BC(void) {
    PSMTXCopy((u8*)*(void**)(lbl_8053AB10 + 0x24) + 0xe4, (u8*)*(void**)((u8*)*(void**)((u8*)*(void**)(lbl_8053AB10 + 0x28) + 0xc) + 0x20) + 0x184);
}

extern "C" void* fn_8013F6F8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F184;
        __dt__18JPAEmitterCallBackFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void deleteAllParticle__14JPABaseEmitterFv(void*);

struct PtclMgr_ { u8 pad[0x4010]; void* emitters[0x19]; u16 ids[0x4c]; s32 count; };
inline bool isKeep(u16 id) { return id == 0x349 || id == 0x34a || id == 0x34b; }
extern "C" void fn_8013C8CC(PtclMgr_* this_) {
    for (int i = 0; i < this_->count; i++) {
        if (this_->ids[i] == 0x349 || this_->ids[i] == 0x34a || this_->ids[i] == 0x34b) deleteAllParticle__14JPABaseEmitterFv(this_->emitters[i]);
    }
}

struct Vec3_ { f32 x, y, z; };inline f32 addPI(f32 a) { return a + 3.1415927f; }static const f32 kPI = 3.1415927f;
extern "C" void fn_8010F668(f32 (*m)[4], Vec3_* axis, f32 rad);
extern "C" void JPASetRMtxfromMtx__FPA4_CfPA4_f(f32 (*src)[4], void* dst);

extern "C" u8 fn_8013CAA4(u8* this_, f32 angle) {
    int ret = 0;
    if (this_ != 0) {
    f32 m[3][4];
    Vec3_ axis;
    m[0][3] = 0.0f;
    m[1][3] = 0.0f;
    m[2][3] = 0.0f;
    axis.x = 0.0f;
    axis.y = 1.0f;
    axis.z = 1.0f;
    fn_8010F668(m, &axis, kPI + angle);
    m[0][0] *= -1.0f;
    m[0][1] *= -1.0f;
    m[0][2] *= -1.0f;
    JPASetRMtxfromMtx__FPA4_CfPA4_f(m, this_ + 0x68);
    ret = 1;
    }
    return ret;
}

extern "C" void PSMTXIdentity(f32 (*m)[4]);
extern "C" void C_MTXLightOrtho(f32 (*m)[4], f32 t, f32 b, f32 l, f32 r, f32 sS, f32 sT, f32 tS, f32 tT);
extern "C" void draw__17JPAEmitterManagerFPC11JPADrawInfoUc(void*, const void*, u8);
extern "C" u8 fn_80134CC8(void*);
extern "C" void fn_8013B490(void*);
extern void* lbl_8053AAF8;
struct RenderMode_ { u32 tvMode; u16 fbWidth; u16 efbHeight; };
class JUTVideo {
public:
    static JUTVideo* sManager;
    u32 _0;
    RenderMode_* mRenderMode;
    s32 getFbWidth() const { return mRenderMode->fbWidth; }
    s32 getEfbHeight() const { return mRenderMode->efbHeight; }
};
struct DrawInfo_ {
    DrawInfo_() {
        PSMTXIdentity(mCamMtx);
        PSMTXIdentity(mPrjMtx);
    }
    void setOrtho(f32 t, f32 b, f32 l, f32 r) { C_MTXLightOrtho(mPrjMtx, t, b, l, r, 0.5f, 0.5f, 0.5f, 0.5f); }
    f32 mCamMtx[3][4];
    f32 mPrjMtx[3][4];
};

extern "C" void fn_8013DB2C(u8* this_) {
    if (fn_80134CC8(lbl_8053AAF8)) {
        return;
    }
    DrawInfo_ info;
    fn_8013B490(lbl_8053AB10);
    DrawInfo_ info2;
    PSMTXCopy((u8*)*(void**)(lbl_8053AB10 + 0x10) + 0x80, info.mCamMtx);
    info.setOrtho(0.0f, JUTVideo::sManager->getEfbHeight(), 0.0f, JUTVideo::sManager->getFbWidth());
    draw__17JPAEmitterManagerFPC11JPADrawInfoUc(*(void**)(this_ + 0xc), &info, 4);
}

struct MtxS_ { f32 m[3][4]; };
struct DrawInfoPOD_ { MtxS_ cam; MtxS_ prj; };
extern "C" void fn_8013B438(void*);

extern "C" void fn_8013D908(u8* this_) {
    DrawInfoPOD_ info;
    DrawInfoPOD_* src = (DrawInfoPOD_*)((u8*)*(void**)(lbl_8053AB10 + 0x24) + 0xe4);
    info.cam = src->cam;
    info.prj = src->prj;
    fn_8013B438(lbl_8053AB10);
    draw__17JPAEmitterManagerFPC11JPADrawInfoUc(*(void**)(this_ + 0xc), &info, 7);
}

extern "C" void fn_8013DA10(u8* this_) {
    DrawInfoPOD_ info;
    DrawInfoPOD_* src;
    if (fn_80134CC8(lbl_8053AAF8) == 0) {
        src = (DrawInfoPOD_*)((u8*)*(void**)(lbl_8053AB10 + 0x24) + 0xe4);
        info.cam = src->cam;
        info.prj = src->prj;
        fn_8013B438(lbl_8053AB10);
        GXSetAlphaUpdate(0);
        draw__17JPAEmitterManagerFPC11JPADrawInfoUc(*(void**)(this_ + 0xc), &info, 9);
    }
}

extern "C" f32 fn_802F5E9C(void*, const f32*);

extern "C" u8 fn_8013CB44(u8* this_, f32* pos, s32 a, s32 b, u8 flag) {
    s32 ret = 0;
    if (this_ != 0) {
        if (flag) {
            flag = pos[2] > 0.0f;
        }
        if (flag && a < 1) {
            a++;
            b--;
        }
        f32 off = (a << 10) + (b << 7);
        f32 x = pos[0];
        f32 y = pos[1] + off;
        f32 z = pos[2] + off;
        f32 g = fn_802F5E9C(*(void**)(lbl_8053AB10 + 0x20), pos);
        f32 d = g - pos[2];
        ret = 1;
        *(f32*)(this_ + 0xa4) = x;
        *(f32*)(this_ + 0xa8) = y;
        *(f32*)(this_ + 0xac) = z + d;
    }
    return ret;
}
