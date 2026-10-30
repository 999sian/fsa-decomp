

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
#include "JSystem/JUtility/JUTVideo.h"
extern "C" void* fn_8013CC50(s32 room, void* p, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" s32 fn_801CD664(s32 n);
extern "C" void* fn_801F856C(void);
extern "C" void fn_80230498(s32 i, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" u8* sManager__8JUTVideo;
extern "C" const u16 lbl_80474EC0[];
extern "C" const f32 lbl_80542D58;
extern u8 lbl_8050C700[0x40];

static inline void spawnBubble(char* p, const s32& slot, JGeometry::TVec3f& pos, s32 id) {
    void* em = fn_8013CC50(0, &pos, lbl_80542D58, id, 0, 0, 0, 0, 1);
    char* e = p + slot * 4;
    *(void**)(e + 0x258) = em;
    if (*(void**)(e + 0x258)) {
        *(u32*)(*(char**)(e + 0x258) + 0xf4) |= 0x40;
    }
}

static inline bool canDeleteEmitter(char* em) {
    bool del = false;
    if (*(u32*)(em + 0xf4) & 8) {
        if (*(s32*)(em + 0xd0) + *(s32*)(em + 0xdc) == 0) del = true;
    }
    return del;
}

static inline void killEmitter(void** slot) {
    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *slot);
    *slot = 0;
}

struct BubbleArea {
    f32 x0, y0, x1, y1;
};

static inline bool inArea(const BubbleArea& area, const JGeometry::TVec3f& v) {
    bool inside = false;
    if (v.x >= area.x0 && v.y >= area.y0 && v.x < area.x1 && v.y < area.y1) inside = true;
    return inside;
}

static inline bool inArea(const JGeometry::TBox2f& area, const JGeometry::TVec3f& v) {
    bool inside = false;
    if (v.x >= area.i.x && v.y >= area.i.y && v.x < area.f.x && v.y < area.f.y) inside = true;
    return inside;
}

static inline bool spawnTriple(char* p, JGeometry::TVec3f pos) {
    s32* out;
    char* q;
    s32 slots[3];
    s32 i;
    s32 n;
    slots[0] = slots[1] = slots[2] = 0;
    n = 0;
    out = slots;
    for (i = 0, q = p; i < 20; q += 4, i++) {
        if (*(void**)(q + 0x258) == 0) {
            n++;
            *out++ = i;
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
    s32* out;
    char* q;
    s32 slots[2];
    s32 i;
    s32 n;
    slots[0] = slots[1] = 0;
    n = 0;
    out = slots;
    for (i = 0, q = p; i < 20; q += 4, i++) {
        if (*(void**)(q + 0x258) == 0) {
            n++;
            *out++ = i;
            if (n == 2) break;
        }
    }
    if (n != 2) return false;
    spawnBubble(p, slots[0], pos, 0x56c);
    spawnBubble(p, slots[1], pos, lbl_80474EC0[kind]);
    return true;
}

extern "C" const f32 lbl_80542D5C;
extern "C" const f32 lbl_80542D60;
extern "C" const f32 lbl_80542D64;
extern "C" const f32 lbl_80542D68;
extern "C" const f32 lbl_80542D6C;
extern "C" const f32 lbl_80542D70;
extern "C" const f32 lbl_80542D74;
extern "C" const f32 lbl_80542D78;
extern "C" const f32 lbl_80542D7C;
extern "C" const f32 lbl_80542D80;
extern "C" const f32 lbl_80542D84;
extern "C" const f32 lbl_80542D88;
extern "C" const f32 lbl_80542D8C;
extern "C" const f32 lbl_80542D90;
extern "C" const f32 lbl_80542D94;
extern "C" const f32 lbl_80542D98;
#pragma opt_common_subs off
extern "C" void fn_8036E5E8(void* this_) {
    char* q;
    s32 i;
    s32 count;
    char* p = (char*)this_;
    JGeometry::TVec3f pos;
    if (*(s32*)(p + 0x234)) {
        *(s32*)(p + 0x234) = *(s32*)(p + 0x234) - 1;
    }
    if (*(s32*)(p + 0x23c)) {
        *(s32*)(p + 0x23c) = *(s32*)(p + 0x23c) - 1;
    }
    if (*(s32*)(p + 0x2b0)) {
        *(s32*)(p + 0x2b0) = *(s32*)(p + 0x2b0) - 1;
    }
    *(JGeometry::TVec3f*)(*(char**)(p + 0x250) + 0xc) = *(JGeometry::TVec3f*)(p + 0xc);
    u16* rm = *(u16**)(sManager__8JUTVideo + 4);
    JGeometry::TVec3f center;
    center.x = (f32)(s32)rm[2] * lbl_80542D5C;
    center.y = (f32)(s32)rm[3] * lbl_80542D5C;
    center.z = lbl_80542D60;
    count = 0;
    q = p;
    for (i = 0; i < 20; i++, q += 4) {
        char* em = *(char**)(q + 0x258);
        if (em) {
            count++;
            if (canDeleteEmitter(em)) {
                killEmitter((void**)(q + 0x258));
            }
        }
    }
    if (count >= *(s32*)(p + 0x2b4)) {
        *(s32*)(p + 0x2b4) = count;
    }
    switch (*(s32*)(p + 0x230)) {
    case 0: {
        ((JGeometry::TVec3f*)(p + 0xc))->add(*(JGeometry::TVec3f*)(p + 0x3c));
        if (*(s32*)(p + 0x23c) == 0) {
            *(s32*)(p + 0x23c) = *(s32*)(p + 0x240);
            *(s32*)(p + 0x244) = *(s32*)(p + 0x244) + 1;
            if (*(s32*)(p + 0x244) >= 8) {
                *(s32*)(p + 0x244) = 0;
            }
        }
        if (*(s32*)(p + 0x238) < 0) {
            s32 n;
            s32 k;
            s32 j;
            void* mgr = fn_801F856C();
            j = 0;
            n = *(s32*)((char*)mgr + 0x1008);
            k = j;
            for (; j < n; k += 4, j++) {
                char* a = *(char**)((char*)fn_801F856C() + k + 8);
                if (a && *(s32*)(a + 0x1a0) == 'EETC' && *(s32*)(a + 0x234) == 4) {
                    s32 s = *(s32*)(a + 0x238);
                    if (s == 0x26 || (u32)(s - 0x27) <= 1 || s == 0x29) {
                        *(s32*)(p + 0x238) = j;
                        break;
                    }
                }
            }
        }
        s32 idx = *(s32*)(p + 0x238);
        if (idx >= 0) {
            char* a = ((char**)((char*)fn_801F856C() + 8))[idx];
            if (*(f32*)(p + 0x10) - *(f32*)(a + 0x10) < lbl_80542D64) {
                *(s32*)(p + 0x230) = *(s32*)(p + 0x230) + 1;
                *(s32*)(p + 0x234) = 0x32;
                *(s32*)(p + 0x244) = 0;
            }
        }
        break;
    }
    case 1:
        if (*(s32*)(p + 0x234) == 0) {
            *(s32*)(p + 0x24c) = 0x10;
            *(s32*)(p + 0x244) = 0;
            *(s32*)(p + 0x230) = *(s32*)(p + 0x230) + 1;
            *(s32*)(p + 0x234) = 0x41;
            pos = center + JGeometry::TVec3f(lbl_80542D68, lbl_80542D6C, lbl_80542D60);
            spawnTriple(p, pos);
        }
        break;
    case 2:
    case 3:
        if (*(s32*)(p + 0x234) != 0) return;
        if (*(s32*)(p + 0x230) == 2) {
            *(s32*)(p + 0x234) = 0x41;
            pos = center + JGeometry::TVec3f(lbl_80542D70, lbl_80542D60, lbl_80542D60);
            spawnPair(p, pos, 1);
        } else {
            *(s32*)(p + 0x234) = 0x5a;
            pos = center + JGeometry::TVec3f(lbl_80542D74, lbl_80542D78, lbl_80542D60);
            spawnTriple(p, pos);
        }
        *(s32*)(p + 0x230) = *(s32*)(p + 0x230) + 1;
        break;
    case 4:
        if (*(s32*)(p + 0x234) != 0) return;
        *(s32*)(p + 0x230) = *(s32*)(p + 0x230) + 1;
        *(s32*)(p + 0x234) = 0x91;
        *(s32*)(p + 0x2b0) = 0;
    case 5: {
        char* e = *(char**)(p + 0x254);
        if (*(s32*)(e + 0x234) >= 0x4a49) {
            *(s32*)(*(char**)(p + 0x250) + 0x230) = 3;
            *(u8*)(e + 0x231) = 1;
            *(s32*)(p + 0x230) = *(s32*)(p + 0x230) + 1;
        }
    }
    case 6:
        if (*(s32*)(p + 0x2b0) == 0) {
            s32 r;
            do {
                r = fn_801CD664(4);
            } while (r == *(s32*)(p + 0x2ac));
            static s8 sAreasInit;
            if (!sAreasInit) {
                BubbleArea* areas = (BubbleArea*)lbl_8050C700;
                areas[0].x0 = lbl_80542D7C; areas[0].y0 = lbl_80542D7C; areas[0].x1 = lbl_80542D80; areas[0].y1 = lbl_80542D84;
                areas[1].x0 = lbl_80542D88; areas[1].y0 = lbl_80542D7C; areas[1].x1 = lbl_80542D8C; areas[1].y1 = lbl_80542D84;
                areas[2].x0 = lbl_80542D7C; areas[2].y0 = lbl_80542D90; areas[2].x1 = lbl_80542D80; areas[2].y1 = lbl_80542D94;
                areas[3].x0 = lbl_80542D98; areas[3].y0 = lbl_80542D90; areas[3].x1 = lbl_80542D8C; areas[3].y1 = lbl_80542D94;
                sAreasInit = 1;
            }
            JGeometry::TVec3f pt;
            BubbleArea area = ((BubbleArea*)lbl_8050C700)[r];
            do {
                f32 y = (f32)fn_801CD664(0x1a2);
                f32 x = (f32)fn_801CD664(0x242);
                pt.set(x, y, lbl_80542D60);
            } while (!inArea(area, pt));
            s32 kind = fn_801CD664(8);
            bool ok;
            if (kind >= 5) {
                ok = spawnTriple(p, pt);
            } else {
                ok = spawnPair(p, pt, kind);
            }
            if (ok == true) {
                *(s32*)(p + 0x2b0) = fn_801CD664(6) + 30;
                *(s32*)(p + 0x2ac) = r;
            } else {
                *(s32*)(p + 0x2b0) = 0;
            }
        }
        break;
    }
    fn_80230498(0, p + 0xc, *(s32*)(p + 0x24c) + *(s32*)(p + 0x244), 0xff, -0x80, -0x80, 1);
}
#pragma opt_common_subs reset
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


