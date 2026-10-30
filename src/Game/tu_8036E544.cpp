

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

#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
extern "C" void* fn_8013CC50(s32 room, void* p, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" s32 fn_801CD664(s32 n);
extern "C" void* fn_801F856C(void);
extern "C" void fn_80230498(s32 i, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" u8* sManager__8JUTVideo;
extern "C" const u16 lbl_80474EC0[];
extern "C" const f32 lbl_80542D58;

static inline void spawnBubble(char* p, s32 slot, JGeometry::TVec3f& pos, s32 id) {
    *(void**)(p + 0x258 + slot * 4) = fn_8013CC50(0, &pos, lbl_80542D58, id, 0, 0, 0, 0, 1);
    if (*(void**)(p + 0x258 + slot * 4)) {
        *(u32*)(*(char**)(p + 0x258 + slot * 4) + 0xf4) |= 0x40;
    }
}

static inline bool spawnTriple(char* p, JGeometry::TVec3f pos) {
    s32 slots[3] = {0, 0, 0};
    s32 n = 0;
    for (s32 i = 0; i < 20; i++) {
        if (*(void**)(p + 0x258 + i * 4) == 0) {
            slots[n++] = i;
            if (n == 3) break;
        }
    }
    if (n != 3) return false;
    spawnBubble(p, slots[0], pos, 0x569);
    spawnBubble(p, slots[1], pos, 0x56a);
    spawnBubble(p, slots[2], pos, 0x56b);
    return true;
}

static inline bool spawnPair(char* p, JGeometry::TVec3f pos, s32 kind) {
    s32 slots[2] = {0, 0};
    s32 n = 0;
    for (s32 i = 0; i < 20; i++) {
        if (*(void**)(p + 0x258 + i * 4) == 0) {
            slots[n++] = i;
            if (n == 2) break;
        }
    }
    if (n != 2) return false;
    spawnBubble(p, slots[0], pos, 0x56c);
    spawnBubble(p, slots[1], pos, lbl_80474EC0[kind]);
    return true;
}

extern "C" void fn_8036E5E8(void* this_) {
    char* p = (char*)this_;
    if (*(s32*)(p + 0x234)) {
        *(s32*)(p + 0x234) = *(s32*)(p + 0x234) - 1;
    }
    if (*(s32*)(p + 0x23c)) {
        *(s32*)(p + 0x23c) = *(s32*)(p + 0x23c) - 1;
    }
    if (*(s32*)(p + 0x2b0)) {
        *(s32*)(p + 0x2b0) = *(s32*)(p + 0x2b0) - 1;
    }
    *(f32*)(*(char**)(p + 0x250) + 0xc) = *(f32*)(p + 0xc);
    *(f32*)(*(char**)(p + 0x250) + 0x14) = *(f32*)(p + 0x14);
}

extern "C" void fn_80230498(s32 i, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_8023077C(void);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_8013CC50(s32 room, void* p, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" const f32 lbl_80542DBC;
extern "C" void fn_8036F5BC(void* this_) {
    s32 i;
    s32 n;
    s32 off;
    f32 v[3];
    void* mgr;

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
    for (s32 j = 1; j < 4; j++) {
        fn_80230498(j, (char*)this_ + 0xc, 0, 0, -0x80, -0x80, 1);
    }

    f32 cy = 384.0f;
    f32 y = *(f32*)((char*)this_ + 0x10);
    f32 x = *(f32*)((char*)this_ + 0xc);
    f32 dy = y / cy;
    f32 dx = x * lbl_80542DBC;
    v[1] = cy * (f32)(s32)dy + 192.0f;
    v[0] = (f32)(s32)dx * 512.0f + 256.0f;
    v[2] = 0.0f;
    *(void**)((char*)this_ + 0x2a8) = fn_8013CC50(*(s32*)((char*)this_ + 4), v, 1.0f, 0x274, 0, 0, 0, 0, 1);

    mgr = fn_801F856C();
    i = 0;
    n = *(s32*)((char*)mgr + 0x1008);
    for (; i < n; i++) {
        void* a = *(void**)((char*)fn_801F856C() + i * 4 + 8);
        if (a && *(s32*)((char*)a + 0x1a0) == 0x454F574C && *(u8*)((char*)a + 0x11c) == 1) {
            *(void**)((char*)this_ + 0x250) = a;
            break;
        }
    }

    mgr = fn_801F856C();
    i = 0;
    n = *(s32*)((char*)mgr + 0x1008);
    for (; i < n; i++) {
        void* a = *(void**)((char*)fn_801F856C() + i * 4 + 8);
        if (a && *(s32*)((char*)a + 0x1a0) == 0x454E444D && *(u8*)((char*)a + 0x11c) == 1) {
            *(void**)((char*)this_ + 0x254) = a;
            break;
        }
    }
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
#pragma opt_loop_invariants reset
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

static u8 lbl_8050C700[0x40];
#include "JSystem/JAudio/JASFakeMatchFSA.h"


