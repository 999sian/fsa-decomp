

#include "types.h"

extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* em);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* this_);
extern "C" char lbl_804AE338[];

extern "C" void fn_8036E544(void* this_) {
    char* p = (char*)this_;
    int i = 0;
    do {
        if (*(void**)(p + 0x258)) {
            void* base = fn_8013C824();
            void* mgr = *(void**)((char*)base + 0xc);
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(p + 0x258));
            *(void**)(p + 0x258) = 0;
        }
        i++;
        p += 4;
    } while (i < 0x14);
    if (*(void**)((char*)this_ + 0x2a8)) {
        void* base = fn_8013C824();
        void* mgr = *(void**)((char*)base + 0xc);
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)((char*)this_ + 0x2a8));
        *(void**)((char*)this_ + 0x2a8) = 0;
    }
}

extern "C" void fn_8036E5E4(void) {
}

extern "C" void fn_80230498(s32 i, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_8023077C(void);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_8013CC50(s32 room, void* p, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_8036F5BC(void* this_) {
    s32 i;
    s32 n;
    s32 off;
    f32 v[3];

    *(s32*)((char*)this_ + 0x230) = 0;
    *(s32*)((char*)this_ + 0x234) = 0;
    *(s32*)((char*)this_ + 0x238) = -1;
    *(s32*)((char*)this_ + 0x23c) = 0;
    *(s32*)((char*)this_ + 0x240) = 0;
    *(s32*)((char*)this_ + 0x244) = 0;
    *(s32*)((char*)this_ + 0x248) = 0;
    *(s32*)((char*)this_ + 0x24c) = 0;
    *(s32*)((char*)this_ + 0x2a8) = 0;
    *(s32*)((char*)this_ + 0x2ac) = 0;
    *(s32*)((char*)this_ + 0x2b0) = 0;
    *(s32*)((char*)this_ + 0x258) = 0;
    *(s32*)((char*)this_ + 0x25c) = 0;
    *(s32*)((char*)this_ + 0x260) = 0;
    *(s32*)((char*)this_ + 0x264) = 0;
    *(s32*)((char*)this_ + 0x268) = 0;
    *(s32*)((char*)this_ + 0x26c) = 0;
    *(s32*)((char*)this_ + 0x270) = 0;
    *(s32*)((char*)this_ + 0x274) = 0;
    *(s32*)((char*)this_ + 0x278) = 0;
    *(s32*)((char*)this_ + 0x27c) = 0;
    *(s32*)((char*)this_ + 0x280) = 0;
    *(s32*)((char*)this_ + 0x284) = 0;
    *(s32*)((char*)this_ + 0x288) = 0;
    *(s32*)((char*)this_ + 0x28c) = 0;
    *(s32*)((char*)this_ + 0x290) = 0;
    *(s32*)((char*)this_ + 0x294) = 0;
    *(s32*)((char*)this_ + 0x298) = 0;
    *(s32*)((char*)this_ + 0x29c) = 0;
    *(s32*)((char*)this_ + 0x2a0) = 0;
    *(s32*)((char*)this_ + 0x2a4) = 0;
    *(s32*)((char*)this_ + 0x2b4) = 0;
    *(s32*)((char*)this_ + 0x254) = 0;
    *(s32*)((char*)this_ + 0x250) = 0;
    *(s32*)((char*)this_ + 0x230) = 0;
    *(f32*)((char*)this_ + 0x3c) = 0.0f;
    *(f32*)((char*)this_ + 0x40) = -0.35f;
    *(f32*)((char*)this_ + 0x44) = 0.0f;
    *(s32*)((char*)this_ + 0x24c) = 0x18;
    *(s32*)((char*)this_ + 0x240) = 10;
    *(s32*)((char*)this_ + 0x23c) = 10;
    *(s32*)((char*)this_ + 0x244) = 0;

    fn_8023077C();
    fn_80230498(0, (char*)this_ + 0xc, *(s32*)((char*)this_ + 0x24c) + *(s32*)((char*)this_ + 0x244), 0xff, -0x80, -0x80, 1);
    for (i = 1; i < 4; i++) {
        fn_80230498(i, (char*)this_ + 0xc, 0, 0, -0x80, -0x80, 1);
    }

    s32 ty = (s32)(*(f32*)((char*)this_ + 0x10) / 384.0f);
    s32 tx = (s32)(*(f32*)((char*)this_ + 0xc) * 0.001953125f);
    v[1] = (f32)ty * 384.0f + 192.0f;
    v[0] = (f32)tx * 512.0f + 256.0f;
    v[2] = 0.0f;
    *(void**)((char*)this_ + 0x2a8) = fn_8013CC50(*(s32*)((char*)this_ + 4), v, 1.0f, 0x274, 0, 0, 0, 0, 1);

    n = *(s32*)((char*)fn_801F856C() + 0x1008);
    for (i = 0, off = 0; i < n; i++, off += 4) {
        void* a = *(void**)((char*)fn_801F856C() + off + 8);
        if (a && *(s32*)((char*)a + 0x1a0) == 0x454F574C && *(u8*)((char*)a + 0x11c) == 1) {
            *(void**)((char*)this_ + 0x250) = a;
            break;
        }
    }

    n = *(s32*)((char*)fn_801F856C() + 0x1008);
    for (i = 0, off = 0; i < n; i++, off += 4) {
        void* a = *(void**)((char*)fn_801F856C() + off + 8);
        if (a && *(s32*)((char*)a + 0x1a0) == 0x454E444D && *(u8*)((char*)a + 0x11c) == 1) {
            *(void**)((char*)this_ + 0x254) = a;
            break;
        }
    }
}

extern "C" void* fn_8036F880(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AE338;
        char* p = (char*)this_;
        int i = 0;
        do {
            if (*(void**)(p + 0x258)) {
                void* base = fn_8013C824();
                void* mgr = *(void**)((char*)base + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(p + 0x258));
                *(void**)(p + 0x258) = 0;
            }
            i++;
            p += 4;
        } while (i < 0x14);
        if (*(void**)((char*)this_ + 0x2a8)) {
            void* base = fn_8013C824();
            void* mgr = *(void**)((char*)base + 0xc);
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)((char*)this_ + 0x2a8));
            *(void**)((char*)this_ + 0x2a8) = 0;
        }
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"


