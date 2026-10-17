#include "Game/Actor.h"


extern "C" char lbl_804B16E0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void* fn_8013C824();
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*, void*);
extern "C" u8 lbl_80529DEC[];
extern "C" u8 lbl_8050DB0C[];
extern "C" u16 lbl_80543C00[];
extern "C" void* lbl_8053AB10;
extern "C" void* lbl_8053AED0;
extern "C" void* sManager__8JUTVideo;
extern "C" void* fn_8023E724(s32);
extern "C" void fn_8030C5F0(void*, void*, s32, s32, void*);
extern "C" void fn_8030C210(void*, void*);
extern "C" void* fn_8013CC50(u32, void*, u16, s32, s32, s32, s32, s32, f32);
extern "C" void fn_8013CB44(void*, s32, s32, s32);
extern "C" void fn_8043E7CC(void*, void*);
extern "C" void fn_80437F78(u8* p) {
    f32* v = (f32*)fn_8023E724(0);
    *(f32*)(p + 0xc) = v[0];
    *(f32*)(p + 0x10) = v[1];
    *(f32*)(p + 0x14) = v[2];
    for (int i = 0; i < 4; i++) {
        u8* cfg = lbl_80529DEC + i * 12;
        if (lbl_80529DEC[0x236] & (1 << i)) {
            if (p[0x240 + i] == 0xff) {
            }
        } else if (*(void**)(p + 0x230 + i * 4)) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void**)(p + 0x230 + i * 4));
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
#include "JSystem/JAudio/JASFakeMatchFSA.h"
