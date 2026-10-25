#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"


extern "C" char lbl_804B16E0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void* fn_8013C824();
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*, void*);
extern "C" u8 lbl_80529DEC[];
extern "C" u8 lbl_8050DB0C[];
extern "C" const u16 lbl_80543C00[4];
extern "C" void* lbl_8053AB10;
extern "C" void* lbl_8053AED0;
extern "C" void* sManager__8JUTVideo;
extern "C" void* fn_8023E724(s32);
extern "C" void fn_8030C5F0(void*, void*, s32, s32, void*);
extern "C" void fn_8030C210(void*, void*);
extern "C" void* fn_8013CC50(u32, void*, u16, s32, s32, s32, s32, s32, f32);
extern "C" void fn_8013CB44(void*, void*, s32, s32, s32);
extern "C" void fn_8043E7CC(void*, JGeometry::TVec3f);
extern "C" f32 lbl_80543C0C;
extern "C" f32 lbl_80543C10;
extern "C" f32 lbl_80543C14;

static inline void setMarkerPosition(u8* cfg, const JGeometry::TVec3f& pos) {
    JGeometry::TVec3f copy(pos);
    JGeometry::TVec3f value(copy);
    ((JGeometry::TVec3f*)(cfg + 0x1c4))->set(value);
}
extern "C" void fn_80437F78(u8* p) {
    f32* v = (f32*)fn_8023E724(0);
    *(f32*)(p + 0xc) = v[0];
    *(f32*)(p + 0x10) = v[1];
    *(f32*)(p + 0x14) = v[2];
    for (int i = 0; i < 4; i++) {
        u8* cfg = lbl_80529DEC + i * 12;
        if (lbl_80529DEC[0x236] & (u8)(1 << i)) {
            JGeometry::TVec3f tmp;
            JGeometry::TVec3f out;
            tmp = *(JGeometry::TVec3f*)(cfg + 0x1c4);
            fn_8030C5F0(*(void**)((u8*)lbl_8053AB10 + 0x24), cfg + 0x1c4, 0, 0, &out);
            if (p[0x240 + i] == 0xff) {
                if (out.y > lbl_80543C0C * (f32)(s32)*(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 6)) {
                    p[0x240 + i] = 0;
                    tmp.y += *(f32*)(lbl_8050DB0C + 0x34);
                } else {
                    p[0x240 + i] = 1;
                    tmp.y -= *(f32*)(lbl_8050DB0C + 0x34);
                }
            } else {
                if (out.y > lbl_80543C10 * (f32)(s32)*(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 6)) {
                    p[0x240 + i] = 0;
                    tmp.y += *(f32*)(lbl_8050DB0C + 0x34);
                } else if (out.y < lbl_80543C14 * (f32)(s32)*(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 6)) {
                    p[0x240 + i] = 1;
                    tmp.y -= *(f32*)(lbl_8050DB0C + 0x34);
                }
            }
            setMarkerPosition(cfg, tmp);
            if (*(s32*)(p + 4) < 8) {
                fn_8030C210(*(void**)((u8*)lbl_8053AB10 + 0x24), cfg + 0x1c4);
            }
            if (*(void**)(p + 0x230 + i * 4) == 0) {
                *(void**)(p + 0x230 + i * 4) = fn_8013CC50(*(u32*)(p + 4), cfg + 0x1c4, lbl_80543C00[i], 1, 1, 0, 0, 1, *(f32*)(lbl_8050DB0C + 0x30));
                *(u32*)((u8*)*(void**)(p + 0x230 + i * 4) + 0xf4) |= 0x40;
            } else {
                fn_8013CB44(*(void**)(p + 0x230 + i * 4), cfg + 0x1c4, 1, 1, 1);
            }
            JGeometry::TVec3f effect(*(JGeometry::TVec3f*)(cfg + 0x1c4));
            fn_8043E7CC(lbl_8053AED0, effect);
        } else if (*(void**)(p + 0x230 + i * 4)) {
            void* mgr = *(void**)((u8*)fn_8013C824() + 0xc);
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(p + 0x230 + i * 4));
            *(void**)(p + 0x230 + i * 4) = 0;
        }
    }
}

extern "C" void fn_8043824C(u8* p) {
    for (int i = 0; i < 4; i++) {
        *(void**)(p + 0x230 + i * 4) = 0;
        p[0x240 + i] = 0xff;
    }
    p[0x11e] = 1;
    p[0x11f] = 1;
}

extern "C" Actor* fn_80438284(Actor* a, s16 n) {
    if (a) {
        *(void**)a = lbl_804B16E0;
        void** p = (void**)a;
        for (int i = 0; i < 4; i++) {
            if (p[0x8c]) {
                void* mgr = *(void**)((u8*)fn_8013C824() + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, p[0x8c]);
                p[0x8c] = 0;
            }
            p++;
        }
        __dt__5ActorFv(a, 0);
        if (n > 0) operator delete(a);
    }
    return a;
}


