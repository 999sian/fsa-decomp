// TU 0x8036d7f8-0x8036dd6c (actor LFGN: spawns LEAF actors on matching tiles).
#include "types.h"
#include "dolphin/mtx.h"


extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AE288[];

extern "C" void* fn_8036D7F8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AE288;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct LfgnMgr {
    u8 pad0[8];
    char* mActors[0x400];
    s32 mCount;
};
extern "C" LfgnMgr* fn_801F856C(void);

// NOTE: ~96% - loop counter/actor register assignment differs.
extern "C" void fn_8036D858(void* thisPtr, Vec* pos) {
    s32 n = fn_801F856C()->mCount;
    for (s32 i = 0; i < n; i++) {
        char* a = fn_801F856C()->mActors[i];
        if (a != NULL && *(u32*)(a + 0x1a0) == 'LEAF' && *(u8*)(a + 0x11c) == 1
            && PSVECDistance(pos, (Vec*)(a + 0xc)) <= 57.0f
            && (f32)__fabs(*(f32*)(a + 0xc) - pos->x) <= 42.0f) {
            *(u8*)(a + 0x230) = 1;
            return;
        }
    }
}

extern "C" void fn_8036D91C(void) {}

extern "C" void fn_8036D920(void) {}

extern "C" u8 fn_802DEBA0(void* actor);
extern "C" u32 fn_80226BC4(Vec* pos, u32 id);
extern "C" u32 fn_802F9908(void* map, u32 id, u32 tile);
extern "C" void Actor_CreateByID(void* mgr, u32 type, u32 id, Vec* pos, u32 p5, s32 a, s32 b);
extern "C" char* lbl_8053AB10;

// NOTE: ~95.7% - callee-saved register assignment (this/row/col) differs.
extern "C" void fn_8036D924(void* thisPtr) {
    char* p = (char*)thisPtr;
    if (fn_802DEBA0(p)) {
        return;
    }
    f32 baseX = 512.0f * (f32)(s32)(*(f32*)(p + 0xc) * (1.0f / 512.0f));
    f32 baseY = 384.0f * (f32)(s32)(*(f32*)(p + 0x10) / 384.0f);
    for (s32 row = 0; row < 24; row++) {
        s32 y = 16.0f * (f32)row + baseY;
        for (s32 col = 0; col < 32; col++) {
            s32 x = 16.0f * (f32)col + baseX;
            Vec q;
            q.y = y;
            q.x = x;
            u32 tile = fn_80226BC4(&q, *(u32*)(p + 0x4));
            u32 kind = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), *(u32*)(p + 0x4), tile) & 0x3FF;
            if ((u16)(kind - 0x1e1) <= 1 || kind == 0x1f1 || kind == 0x1f2) {
                Vec pos;
                pos.x = x;
                pos.y = y;
                pos.z = 0.0f;
                Actor_CreateByID(fn_801F856C(), 'LEAF', *(u32*)(p + 0x4), &pos, kind, -1, -1);
            }
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
