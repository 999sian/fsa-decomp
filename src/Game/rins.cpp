// TU 0x803578d8-0x80357de8 (actor RINS).
#include "types.h"
#include "JSystem/JGeometry/Box.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AD220[];

class RinsActorV {
public:
    virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
    virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
    virtual void s08(); virtual void s09(); virtual void s10(int a, int b); virtual u8 s11();
};

extern "C" void* fn_803578D8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AD220;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_80357938(void) {}

extern "C" s32 fn_801F2718(void* actor, u32 type);
extern "C" void* fn_801F856C(void);
extern "C" char* fn_801F666C(void* mgr, s32 id);

static inline bool rinsIsStill(char* a) {
    if (*(s32*)(a + 0x230) == 0 && ((JGeometry::TVec3<f32>*)(a + 0x2d4))->isZero() == true) {
        return true;
    }
    return false;
}

// NOTE: ~91% - r30/r31 swap for this/id and box-center FP scheduling differ.
extern "C" void fn_8035793C(void* thisPtr) {
    char* p = (char*)thisPtr;
    s32 id = fn_801F2718(p, 'MRTA');
    if (id >= 0) {
        char* a = fn_801F666C(fn_801F856C(), id);
        if (a != NULL) {
            if (rinsIsStill(a) == true) {
                JGeometry::TBox2<f32> box = *(JGeometry::TBox2<f32>*)(a + 0x60);
                box.addPos(*(JGeometry::TVec2<f32>*)(a + 0xc));
                f32 dx = *(f32*)(p + 0xc) - (0.5f * (box.i.x - box.f.x) + box.f.x);
                f32 dy = *(f32*)(p + 0x10) - (0.5f * (box.i.y - box.f.y) + box.f.y);
                if (JGeometry::TUtil<f32>::sqrt(dx * dx + dy * dy) < 4.0f) {
                    if (!((RinsActorV*)p)->s11()) {
                        ((RinsActorV*)p)->s10(0xff, 1);
                    }
                    return;
                }
            }
        }
    }
    if (((RinsActorV*)p)->s11() == 1) {
        ((RinsActorV*)p)->s10(0xff, 0);
    }
}

extern "C" void fn_80357B14(void* thisPtr) {
    char* p = (char*)thisPtr;
    *(f32*)(p + 0x80) = -12.0f;
    *(f32*)(p + 0x84) = -12.0f;
    *(f32*)(p + 0x88) = 12.0f;
    *(f32*)(p + 0x8c) = 12.0f;
    *(f32*)(p + 0x60) = -12.0f;
    *(f32*)(p + 0x64) = -12.0f;
    *(f32*)(p + 0x68) = 12.0f;
    *(f32*)(p + 0x6c) = 12.0f;
    *(f32*)(p + 0xc) = 16.0f * (f32)((s32)*(f32*)(p + 0xc) / 16);
    *(f32*)(p + 0x10) = 16.0f * (f32)((s32)*(f32*)(p + 0x10) / 16);
    *(s32*)(p + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
