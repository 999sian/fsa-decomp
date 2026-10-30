#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "Game/TlwpDrawParam.h"


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

extern "C" const char* lbl_804B16C0[];
extern "C" const char* lbl_804B16D0[];
extern "C" const f32 lbl_80543C08;
extern "C" void* fn_804030C4(u32, const char*);
extern "C" void fn_802F745C(void*, void*, void*, TlwpDrawParam*);
#pragma opt_lifetimes off
#pragma opt_lifetimes on
extern "C" void fn_80437C10(u8* self) {
    u8* cfg;
    u8* globals = lbl_80529DEC;
    cfg = globals;
    u8* settings = lbl_8050DB0C;
    int i;
    for (i = 0; i < 4; i++, cfg += 12) {
        u8 mask = (u8)(1 << i);
        u32 active = (bool)(globals[0x236] & mask);
        if (active != 0U) {
            f32 ss;
            f32 cz;
            f32 cs, a0, a1, a2, a3, a4, a5, a6, a7, a8;
            f32 sx;
            f32 cx;
            f32 sz;
            f32 cy;
            f32 scale;
            f32 sy;
            TlwpDrawParam rec;
            f32 mtx[3][4];
            scale = *(f32*)(settings + 0x30);
            rec.color = 2;
            rec.palette = 2;
            rec.f2d = 1;
            sx = sin(lbl_80543C08);
            sy = sin(lbl_80543C08);
            sz = sin(lbl_80543C08);
            cx = cos(lbl_80543C08);
            cy = cos(lbl_80543C08);
            cz = cos(lbl_80543C08);
            f32 cc = cx * cz;
            ss = sx * sy;
            cs = cx * sz;
            a0 = cy * cz;
            a1 = cy * sz;
            a2 = -sy;
            a3 = ss * cz - cs;
            a4 = ss * sz + cc;
            a5 = sx * cy;
            a6 = cc * sy + sx * sz;
            a7 = cs * sy - sx * cz;
            a8 = cx * cy;
            mtx[0][0] = scale * a0;
            mtx[1][0] = scale * a1;
            mtx[2][0] = scale * a2;
            mtx[0][1] = scale * a3;
            mtx[1][1] = scale * a4;
            mtx[2][1] = scale * a5;
            mtx[0][2] = scale * a6;
            mtx[1][2] = scale * a7;
            mtx[2][2] = scale * a8;
            mtx[0][3] = lbl_80543C08;
            mtx[1][3] = lbl_80543C08;
            mtx[2][3] = lbl_80543C08;
            rec.c = mtx;
            if (self[0x240 + i] == 0) {
                void* res = fn_804030C4('TIMG', lbl_804B16C0[i]);
                if (*(s32*)(self + 4) < 8) fn_802F745C(*(void**)((u8*)lbl_8053AB10 + 0x20), cfg + 0x1c4, res, &rec);
            } else if (self[0x240 + i] == 1) {
                void* res = fn_804030C4('TIMG', lbl_804B16D0[i]);
                if (*(s32*)(self + 4) < 8) fn_802F745C(*(void**)((u8*)lbl_8053AB10 + 0x20), cfg + 0x1c4, res, &rec);
            }
            globals[0x236] &= ~mask;
        } else self[0x240 + i] = 0xff;
    }
}
#pragma opt_lifetimes reset
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
            JGeometry::TVec3f copy;
            JGeometry::TVec3f effect;
            JGeometry::TVec3f value;
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
            copy = tmp;
            value = copy;
            ((JGeometry::TVec3f*)(cfg + 0x1c4))->set(value);
            if (*(s32*)(p + 4) < 8) {
                fn_8030C210(*(void**)((u8*)lbl_8053AB10 + 0x24), cfg + 0x1c4);
            }
            if (*(void**)(p + 0x230 + i * 4) == 0) {
                *(void**)(p + 0x230 + i * 4) = fn_8013CC50(*(u32*)(p + 4), cfg + 0x1c4, lbl_80543C00[i], 1, 1, 0, 0, 1, *(f32*)(lbl_8050DB0C + 0x30));
                *(u32*)((u8*)*(void**)(p + 0x230 + i * 4) + 0xf4) |= 0x40;
            } else {
                fn_8013CB44(*(void**)(p + 0x230 + i * 4), cfg + 0x1c4, 1, 1, 1);
            }
            effect = *(JGeometry::TVec3f*)(cfg + 0x1c4);
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


