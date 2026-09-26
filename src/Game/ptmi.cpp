// TU 0x80376b4c-0x80376fa0 (actor PTMI).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

#include "JSystem/JGeometry/Box.h"

extern void* lbl_804AE780[];

extern "C" void* fn_80376B4C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AE780;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

class PtmiActorV {
public:
    virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
    virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
    virtual void s08(); virtual void s09(); virtual void s10(); virtual u8 s11();
};
extern "C" void fn_80239914(JGeometry::TBox2<f32>* box, u32 id, u32 p3);

extern "C" void fn_80376BAC(void* thisPtr) {
    char* p = (char*)thisPtr;
    if (*(s32*)(p + 0x230) == 0 || ((PtmiActorV*)p)->s11()) {
        JGeometry::TBox2<f32> box = *(JGeometry::TBox2<f32>*)(p + 0x60);
        box.addPos(*(JGeometry::TVec2<f32>*)(p + 0xc));
        fn_80239914(&box, *(u32*)(p + 0x4), *(u32*)(p + 0x198));
    }
}

static inline u32 ptmiMode(char* p) { return *(u32*)(p + 0x90) >> 27; }

extern "C" void fn_80376C50(void* thisPtr) {
    char* p = (char*)thisPtr;
    *(f32*)(p + 0x3c) = 0.0f;
    *(f32*)(p + 0x40) = 0.0f;
    *(f32*)(p + 0x44) = 0.0f;
    u32 flags = *(u32*)(p + 0x90);
    f32 w = (u32)(((flags & 0xFF) + 1) * 8);
    f32 h = (u32)((((flags >> 8) & 0xFF) + 1) * 8);
    if ((flags >> 16) & 1) {
        *(f32*)(p + 0xc) += w;
        *(f32*)(p + 0x10) += h;
    } else {
        *(f32*)(p + 0xc) = w + (f32)((s32)*(f32*)(p + 0xc) / 16 * 16);
        *(f32*)(p + 0x10) = h + (f32)((s32)*(f32*)(p + 0x10) / 16 * 16);
    }
    *(f32*)(p + 0x60) = -w;
    *(f32*)(p + 0x64) = -h;
    *(f32*)(p + 0x68) = w;
    *(f32*)(p + 0x6c) = h;
    *(f32*)(p + 0x80) = -w;
    *(f32*)(p + 0x84) = -h;
    *(f32*)(p + 0x88) = w;
    *(f32*)(p + 0x8c) = h;
    *(u32*)(p + 0x230) = ptmiMode(p);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
