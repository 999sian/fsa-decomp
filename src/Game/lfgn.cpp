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
    int getNum() { return mCount; }
    char* get(int i) { return mActors[i]; }
};
extern "C" LfgnMgr* fn_801F856C(void);

extern "C" void fn_8036D858(void* thisPtr, Vec* pos) {
    char* a;
    int n = fn_801F856C()->getNum();
    for (int i = 0; i < n; i++) {
        a = fn_801F856C()->get(i);
        if (a != NULL && *(u32*)(a + 0x1a0) == 'LEAF' && *(u8*)(a + 0x11c) == 1
            && PSVECDistance(pos, (Vec*)(a + 0xc)) <= 57.0f
            && __fabsf(*(f32*)(a + 0xc) - pos->x) <= 42.0f) {
            *(u8*)(a + 0x230) = 1;
            return;
        }
    }
}

extern "C" void fn_8036D91C(void) {}

extern "C" void fn_8036D920(void) {}

extern "C" u8 fn_802DEBA0(void* actor);
struct LfgnVec2 { f32 x, y; };
extern "C" u32 fn_80226BC4(LfgnVec2* pos, u32 id);
extern "C" u32 fn_802F9908(void* map, u32 id, u32 tile);
extern "C" void Actor_CreateByID(void* mgr, u32 type, u32 id, Vec* pos, u32 p5, s32 a, s32 b);
extern "C" char* lbl_8053AB10;

extern "C" void fn_8036D924(void* thisPtr) {
    char* p = (char*)thisPtr;
    u16 kind;
    s32 x;
    s32 y;
    if (fn_802DEBA0(p)) {
        return;
    }
    f32 baseX = 512.0f * (f32)(s32)(*(f32*)(p + 0xc) / 512.0f);
    f32 baseY = 384.0f * (f32)(s32)(*(f32*)(p + 0x10) / 384.0f);
    for (s32 row = 0; row < 24; row++) {
        y = 16.0f * (f32)row + baseY;
        for (s32 col = 0; col < 32; col++) {
            x = 16.0f * (f32)col + baseX;
            LfgnVec2 q;
            q.x = x;
            q.y = y;
            u32 tile = fn_80226BC4(&q, *(u32*)(p + 0x4));
            kind = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), *(u32*)(p + 0x4), tile) & 0x3FF;
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
