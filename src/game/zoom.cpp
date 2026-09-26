// TU 0x802e694c-0x802e6ec4 (actor ZOOM).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Zoom_dtor_802E694C.cpp ----
extern "C" void dtor_801F593C(void* this_, int how);
extern void* lbl_804A9DF8[];

extern "C" void* fn_802E694C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A9DF8;
        dtor_801F593C(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- Zoom_EmptyHook.cpp ----
// Zoom_EmptyHook - ZOOM: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Zoom_EmptyHook(void) {}

}

// fn_802E69B0 / fn_802E6BCC - ZOOM: zone trigger (update / setParams).
struct ZoomPt { f32 x, y; };
struct ZoomBox {
    ZoomPt min, max;
};
struct ZoomTarget {
    u8 pad[0x7f4];
    u8 busy;
    u8 request;
    inline bool tryRequest() {
        bool ok = false;
        if (busy == 0) {
            ok = true;
            request = 1;
        }
        return ok;
    }
};
struct ZoomVT {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void notify(s32 a, s32 b);
};
extern char* lbl_8053AB10;
#define ZOOM_TARGET (*(ZoomTarget**)(lbl_8053AB10 + 0x24))
extern const u32 lbl_8046F260[];
extern "C" s32 fn_8023AF14(ZoomBox* box, u32 room, s32 a, f32 f);
extern "C" void fn_801F0D20(void* this_, u32 id);
extern "C" u8 fn_8023077C();
extern "C" u8 fn_80230534(s32 a);
extern "C" void fn_801F3668(void* this_);

extern "C" void fn_802E69B0(char* p) {
    switch (*(s32*)(p + 0x230)) {
    case 0: {
        f32 y = *(f32*)(p + 0x10);
        f32 x = *(f32*)(p + 0xc);
        ZoomBox box;
        box.min.x = *(f32*)(p + 0x60);
        box.min.y = *(f32*)(p + 0x64);
        box.max.x = *(f32*)(p + 0x68);
        box.max.y = *(f32*)(p + 0x6c);
        box.min.x += x;
        box.min.y += y;
        box.max.x += x;
        box.max.y += y;
        if (fn_8023AF14(&box, *(u32*)(p + 0x4), 0, 0.0f) >= 0 &&
            ZOOM_TARGET->tryRequest() == true) {
            if (*(u32*)(p + 0x90) >> 27) {
                ((ZoomVT*)p)->notify(0xff, 1);
            }
            *(s32*)(p + 0x230) = 1;
            *(s32*)(p + 0x240) = *(s32*)(p + 0x23c);
            if (*(s32*)(p + 0x234) != 0) {
                fn_801F0D20(p, lbl_8046F260[*(s32*)(p + 0x234)]);
            }
        }
        break;
    }
    case 1:
        if (*(s32*)(p + 0x238) == 0) {
            if (fn_8023077C() == 1) {
                *(s32*)(p + 0x230) = 2;
                fn_801F0D20(p, 0x3c);
            }
        } else {
            *(s32*)(p + 0x230) = 2;
            fn_801F0D20(p, 0x3c);
        }
        break;
    case 2:
        ZOOM_TARGET->tryRequest();
        if (*(s32*)(p + 0x240) == 0) {
            *(s32*)(p + 0x230) = 3;
        } else {
            *(s32*)(p + 0x240) = *(s32*)(p + 0x240) - 1;
        }
        break;
    case 3:
        ZOOM_TARGET->tryRequest();
        if (*(s32*)(p + 0x238) == 0) {
            if (fn_80230534(0) == 1) {
                fn_801F3668(p);
            }
        } else {
            fn_801F3668(p);
        }
        break;
    }
}

extern "C" void fn_802E6BCC(char* p) {
    *(u32*)(p + 0x234) = (*(u32*)(p + 0x90) >> 23) & 3;
    *(u32*)(p + 0x238) = (*(u32*)(p + 0x90) >> 22) & 1;
    *(u32*)(p + 0x23c) = *(u32*)(p + 0x90) & 0xFFF;
    *(s32*)(p + 0x244) = ((*(u32*)(p + 0x90) >> 17) & 0x1f) + 1;
    *(s32*)(p + 0x248) = ((*(u32*)(p + 0x90) >> 12) & 0x1f) + 1;
    *(s32*)(p + 0x240) = 0;
    *(f32*)(p + 0xc) += 8.0f;
    *(f32*)(p + 0x10) += 8.0f;
    f32 h = 16.0f * *(s32*)(p + 0x248);
    f32 w = 16.0f * *(s32*)(p + 0x244);
    *(f32*)(p + 0x60) = -w;
    *(f32*)(p + 0x64) = -h;
    *(f32*)(p + 0x68) = w;
    *(f32*)(p + 0x6c) = h;
    *(s32*)(p + 0x230) = 0;
}

// Shared JAudio pool __sinit (docs/game/sinit_pools.md). Drop the ESD
// macros/typedefs that clash with the JSystem headers first.
#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
