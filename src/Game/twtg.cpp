// TU 0x80313c20-0x80316e34 (actor TWTG).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"
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
#ifndef unknown
#define unknown jsys_unknown
#endif
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "Game/AnimEffectRec.h"

// ---- Twtg_ctor_80316A60.cpp ----
// fn_80316A60 - "TWTG" real constructor. Identical shape to FTGL/JIJI -
// see Ftgl_ctor_80317C38.cpp for the full technique writeup. Base Actor
// ctor + own vtable install, allocates a 0x1c-byte resource handle and
// resets it via ResetResourceHandleRecord if allocation succeeded,
// storing the handle (or null) at +0x278.



struct Actor {
    Actor();
    ~Actor();
};

extern "C" void ResetResourceHandleRecord(void* h);

class ResourceHandle {
public:
    ResourceHandle() { ResetResourceHandleRecord(this); }
    ~ResourceHandle();
private:
    unsigned char pad[0x1c];
};

extern "C" void* lbl_804AAD60[];

class Twtg : public Actor {
public:
    Twtg();
    void update();
};

extern "C" void fn_80315C80(void) {}

// fn_8031662C - TWTG: draw(). Picks the frame from the animated effect
// record while it runs (playing its sound on mode changes), else from the
// idle table, then draws the model and its effect.
extern const s32 lbl_80471518[];
extern const char lbl_80471528[];
extern const f32 lbl_80541888;
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, s32 a, s32 b, f32 s0, f32 s1);
extern "C" void fn_803075AC(u32 callerID, u32 ownerID, void* posPtr, s32 effectRef, s32 flag,
                            s32 mode, s32 targetPlayerIdx, s32 kind, s32 stackArg9, s32 stackArg10);

extern "C" void fn_8031662C(char* p) {
    s32 frame;
    if (*(s32*)(p + 0x230) == 3) {
        return;
    }
    if (*(s32*)(p + 0x234) == 1 && *(s32*)(p + 0x254) >= 0) {
        s32 snd = fn_80316E74(*(AnimEffectRec**)(p + 0x278), *(s32*)(p + 0x254));
        if (fn_80316E34(*(AnimEffectRec**)(p + 0x278)) >= 0) {
            frame = fn_80316E34(*(AnimEffectRec**)(p + 0x278));
            if ((u32)snd != 0xFFFFFFFF) {
                fn_801F0E34(p, snd, 0);
            }
        } else {
            frame = lbl_80471518[*(s32*)(p + 0x270)];
        }
    } else {
        frame = lbl_80471518[*(s32*)(p + 0x270)];
    }
    fn_801F06F0(p, lbl_80471528, frame + 0xc0, 0, 7, lbl_80541888, lbl_80541888);
    fn_803075AC(*(u32*)(p + 0x198), *(u32*)(p + 0x4), p + 0xc, frame + 0xc0, 0, 2, -1, 0, 0, 0);
}

struct TwtgPt { f32 x, y; };
struct TwtgBox { TwtgPt min, max; };
extern "C" void fn_80239914(TwtgBox* box, u32 room, u32 id);
typedef void (Twtg::*TwtgStateFn)();
extern TwtgStateFn lbl_804AACDC[];

// fn_80316754 - TWTG: update(). Refreshes the collision box and runs the
// state handler from the member-function table lbl_804AACDC.
void Twtg::update() {
    char* p = (char*)this;
    TwtgBox box;
    box.min.x = *(f32*)(p + 0x60);
    box.min.y = *(f32*)(p + 0x64);
    box.max.x = *(f32*)(p + 0x68);
    box.max.y = *(f32*)(p + 0x6c);
    box.min.x += *(f32*)(p + 0xc);
    box.min.y += *(f32*)(p + 0x10);
    box.max.x += *(f32*)(p + 0xc);
    box.max.y += *(f32*)(p + 0x10);
    fn_80239914(&box, *(u32*)(p + 0x4), *(u32*)(p + 0x198));
    (this->*lbl_804AACDC[*(s32*)(p + 0x230)])();
}

extern "C" void fn_8022FEB8(TwtgBox*, s32, void*, s32, s32);
extern "C" s32 fn_8022FD8C(void*);
extern "C" u8 fn_802300EC(void);
extern "C" s32 fn_80230CFC(s32);
extern "C" u8 fn_8038AD24(s32, s32, void*, s32, JGeometry::TVec3f, s32);
extern "C" void fn_8022FF8C(s32, TwtgBox*, s32, void*, s32, s32);
extern "C" u8 fn_80388CAC(s32, void*);

extern "C" void fn_80313C20(char* p) {
    TwtgBox b;
    b.min.x = *(f32*)(p + 0x60);
    b.min.y = *(f32*)(p + 0x64);
    b.max.x = *(f32*)(p + 0x68);
    b.max.y = *(f32*)(p + 0x6c);
    b.min.x += *(f32*)(p + 0xc);
    b.min.y += *(f32*)(p + 0x10);
    b.max.x += *(f32*)(p + 0xc);
    b.max.y += *(f32*)(p + 0x10);
    s32 msg;
    s32 slot;
    if (*(s32*)(p + 0x234) != 1) {
        fn_8022FEB8(&b, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
        slot = fn_8022FD8C(*(void**)(p + 0x198));
        if (slot >= 0 && fn_802300EC() && fn_80230CFC(slot) == 3) {
            msg = *(s32*)(p + 0x268);
            void* room = *(void**)(p + 0x198);
            s32 player = *(s32*)(p + 4);
            if (fn_8038AD24(slot, msg, room, player, *(JGeometry::TVec3f*)(p + 0xc), 0x220)) {
                *(s32*)(p + 0x254) = slot;
                *(s32*)(p + 0x268) = msg;
                *(s32*)(p + 0x234) = 1;
            }
        }
    } else {
        fn_8022FF8C(*(s32*)(p + 0x254), &b, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(p + 0x254), *(void**)(p + 0x198))) {
            *(s32*)(p + 0x254) = -1;
            *(s32*)(p + 0x234) = 0;
        }
    }
}

extern const f32 lbl_80541880;
extern const f32 lbl_80541884;
extern char* lbl_8053AAF8;
extern "C" s32 fn_8023DE58(s32);
extern "C" void fn_801EE558(void* p, JGeometry::TVec3f* out, f32* dist, s32 idx);
extern "C" void fn_8013665C(void* game, s32 a, s32 b);

static inline void twtgUpdateDir(char* p, JGeometry::TVec3f& v, f32& dist) {
    if (*(s32*)(p + 0x274) <= 0) {
        *(s32*)(p + 0x274) = 20;
        s32 room;
        if (*(s32*)(p + 0x254) < 0 || (room = *(s32*)(p + 0x4), fn_8023DE58(*(s32*)(p + 0x254)) != room)) {
            fn_801EE558(p, &v, &dist, 0);
        } else {
            fn_801EE558(p, &v, &dist, *(s32*)(p + 0x254) + 1);
        }
        if (dist < lbl_80541880) {
            f32 ang = JMAAtan2Radian(-v.x, -v.y);
            u16 a = (s32)(ang * lbl_80541884);
            if (a < 0x2000 || a >= 0xe000) {
                *(s32*)(p + 0x270) = 3;
            } else if (a >= 0x2000 && a < 0x6000) {
                *(s32*)(p + 0x270) = 1;
            } else if (a >= 0x6000 && a <= 0xa000) {
                *(s32*)(p + 0x270) = 2;
            } else {
                *(s32*)(p + 0x270) = 0;
            }
        } else {
            *(s32*)(p + 0x270) = 2;
        }
    } else {
        (*(s32*)(p + 0x274))--;
    }
}

extern "C" void fn_80315C84(char* p) {
    TwtgBox b;
    JGeometry::TVec3f v;
    f32 dist;
    twtgUpdateDir(p, v, dist);
    b.min.x = *(f32*)(p + 0x258);
    b.min.y = *(f32*)(p + 0x25c);
    b.max.x = *(f32*)(p + 0x260);
    b.max.y = *(f32*)(p + 0x264);
    b.min.x += *(f32*)(p + 0xc);
    b.min.y += *(f32*)(p + 0x10);
    b.max.x += *(f32*)(p + 0xc);
    b.max.y += *(f32*)(p + 0x10);
    s32 slot;
    if (*(s32*)(p + 0x234) == 0) {
        fn_8022FEB8(&b, *(s32*)(p + 4), *(void**)(p + 0x198), 0, 0);
        slot = fn_8022FD8C(*(void**)(p + 0x198));
        if (slot >= 0 && fn_802300EC()) {
            void* room = *(void**)(p + 0x198);
            s32 player = *(s32*)(p + 4);
            if (fn_8038AD24(slot, 0x480, room, player, *(JGeometry::TVec3f*)(p + 0xc), 0x110)) {
                *(s32*)(p + 0x254) = slot;
                *(s32*)(p + 0x268) = 0x480;
                *(s32*)(p + 0x234) = 1;
            }
        }
    } else {
        fn_8022FF8C(*(s32*)(p + 0x254), &b, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(p + 0x254), *(void**)(p + 0x198))) {
            fn_8013665C(lbl_8053AAF8, 10, 2);
            *(s32*)(p + 0x234) = 2;
        }
    }
}

extern "C" s32 fn_80138A30(void* game);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_8038470C(s32 slot, s32 msg);
extern "C" void fn_803894BC(s32 slot, s32 v);
extern "C" u8 fn_803865B8(s32 slot);
extern void* lbl_8053AED0;
extern "C" void fn_8043D874(void* mgr, s32 k, s32 a, s32 b);

static inline u8 twtgPlayerFlag(s32 i) {
    char* rec = (char*)fn_802D6A9C();
    if (i >= 0 && i < 4) {
        return rec[0x131d8 + i];
    }
    return 0;
}

static inline u8 twtgAsk(char* p, s32 msg) {
    if (fn_8038470C(*(s32*)(p + 0x254), msg)) {
        *(s32*)(p + 0x268) = msg;
        *(s32*)(p + 0x234) = 1;
        return 1;
    }
    return 0;
}

struct TwtgRandom {
    u32 seed;
    f32 get() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - lbl_80541888;
    }
};

extern "C" void fn_803142E4(char* p) {
    TwtgBox b;
    JGeometry::TVec3f v;
    f32 dist;
    twtgUpdateDir(p, v, dist);
    b.min.x = *(f32*)(p + 0x258);
    b.min.y = *(f32*)(p + 0x25c);
    b.max.x = *(f32*)(p + 0x260);
    b.max.y = *(f32*)(p + 0x264);
    b.min.x += *(f32*)(p + 0xc);
    b.min.y += *(f32*)(p + 0x10);
    b.max.x += *(f32*)(p + 0xc);
    b.max.y += *(f32*)(p + 0x10);
    s32 slot;
    if (*(s32*)(p + 0x234) == 0) {
        switch (*(s32*)(p + 0x238)) {
        case 0:
            fn_8022FEB8(&b, *(s32*)(p + 4), *(void**)(p + 0x198), 0, 0);
            slot = fn_8022FD8C(*(void**)(p + 0x198));
            if (slot >= 0 && fn_802300EC()) {
                void* room = *(void**)(p + 0x198);
                s32 player = *(s32*)(p + 4);
                if (fn_8038AD24(slot, 0x4ce, room, player, *(JGeometry::TVec3f*)(p + 0xc), 0x110)) {
                    *(s32*)(p + 0x254) = slot;
                    *(s32*)(p + 0x268) = 0x4ce;
                    *(s32*)(p + 0x234) = 1;
                }
            }
            break;
        case 1:
            fn_8022FF8C(*(s32*)(p + 0x254), &b, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
            twtgAsk(p, 0x4cf);
            break;
        case 2: {
            fn_8022FF8C(*(s32*)(p + 0x254), &b, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
            s32 n = fn_80138A30(lbl_8053AAF8);
            s32 i = (s32)(n * ((TwtgRandom*)(lbl_8053AAF8 + 0xb4))->get()) & 3;
            fn_803894BC(*(s32*)(p + 0x254), i + 1);
            if (twtgAsk(p, 0x4da)) {
                fn_8043D874(lbl_8053AED0, i, 300, 0);
            }
            break;
        }
        default:
            *(s32*)(p + 0x230) = 4;
            *(s32*)(p + 0x238) = 5;
            *(s32*)(p + 0x254) = 0;
            *(s32*)(p + 0x234) = 0;
            break;
        }
    } else if (*(s32*)(p + 0x234) == 1) {
        fn_8022FF8C(*(s32*)(p + 0x254), &b, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
        if (fn_803865B8(*(s32*)(p + 0x254))) {
            if (*(s32*)(p + 0x238) < 2) {
                (*(s32*)(p + 0x238))++;
                *(s32*)(p + 0x234) = 0;
            } else {
                *(s32*)(p + 0x230) = 4;
                *(s32*)(p + 0x238) = 0;
                *(s32*)(p + 0x234) = 0;
            }
        }
    }
}

extern "C" void fn_80315080(char* p) {
    TwtgBox b;
    JGeometry::TVec3f v;
    f32 dist;
    twtgUpdateDir(p, v, dist);
    b.min.x = *(f32*)(p + 0x258);
    b.min.y = *(f32*)(p + 0x25c);
    b.max.x = *(f32*)(p + 0x260);
    b.max.y = *(f32*)(p + 0x264);
    b.min.x += *(f32*)(p + 0xc);
    b.min.y += *(f32*)(p + 0x10);
    b.max.x += *(f32*)(p + 0xc);
    b.max.y += *(f32*)(p + 0x10);
    s32 slot;
    if (*(s32*)(p + 0x234) == 0) {
        s32 n = fn_80138A30(lbl_8053AAF8);
        switch (*(s32*)(p + 0x238)) {
        case 0:
            fn_8022FEB8(&b, *(s32*)(p + 4), *(void**)(p + 0x198), 0, 0);
            slot = fn_8022FD8C(*(void**)(p + 0x198));
            if (slot >= 0 && fn_802300EC()) {
                void* room = *(void**)(p + 0x198);
                s32 player = *(s32*)(p + 4);
                if (fn_8038AD24(slot, 0x4ce, room, player, *(JGeometry::TVec3f*)(p + 0xc), 0x110)) {
                    *(s32*)(p + 0x254) = slot;
                    *(s32*)(p + 0x268) = 0x4ce;
                    *(s32*)(p + 0x234) = 1;
                }
            }
            break;
        case 1:
            fn_8022FF8C(*(s32*)(p + 0x254), &b, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
            twtgAsk(p, 0x4cf);
            break;
        case 2: {
            fn_8022FF8C(*(s32*)(p + 0x254), &b, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
            s32 i;
            for (i = 0; i < n; i++) {
                if (twtgPlayerFlag(i)) {
                    break;
                }
            }
            i &= 3;
            fn_803894BC(*(s32*)(p + 0x254), i + 1);
            if (twtgAsk(p, 0x4d2)) {
                fn_8043D874(lbl_8053AED0, i, 300, 0);
            }
            break;
        }
        default:
            *(s32*)(p + 0x230) = 4;
            *(s32*)(p + 0x238) = 5;
            *(s32*)(p + 0x254) = 0;
            *(s32*)(p + 0x234) = 0;
            break;
        }
    } else if (*(s32*)(p + 0x234) == 1) {
        fn_8022FF8C(*(s32*)(p + 0x254), &b, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
        if (fn_803865B8(*(s32*)(p + 0x254))) {
            if (*(s32*)(p + 0x238) < 2) {
                (*(s32*)(p + 0x238))++;
                *(s32*)(p + 0x234) = 0;
            } else {
                *(s32*)(p + 0x230) = 4;
                *(s32*)(p + 0x238) = 0;
                *(s32*)(p + 0x234) = 0;
            }
        }
    }
}

extern "C" void fn_80315460(char* p) {
    TwtgBox b;
    JGeometry::TVec3f v;
    f32 dist;
    twtgUpdateDir(p, v, dist);
    b.min.x = *(f32*)(p + 0x258);
    b.min.y = *(f32*)(p + 0x25c);
    b.max.x = *(f32*)(p + 0x260);
    b.max.y = *(f32*)(p + 0x264);
    b.min.x += *(f32*)(p + 0xc);
    b.min.y += *(f32*)(p + 0x10);
    b.max.x += *(f32*)(p + 0xc);
    b.max.y += *(f32*)(p + 0x10);
    s32 slot;
    if (*(s32*)(p + 0x234) == 0) {
        s32 n = fn_80138A30(lbl_8053AAF8);
        switch (*(s32*)(p + 0x238)) {
        case 0:
            fn_8022FEB8(&b, *(s32*)(p + 4), *(void**)(p + 0x198), 0, 0);
            slot = fn_8022FD8C(*(void**)(p + 0x198));
            if (slot >= 0 && fn_802300EC()) {
                void* room = *(void**)(p + 0x198);
                s32 player = *(s32*)(p + 4);
                if (fn_8038AD24(slot, 0x4ce, room, player, *(JGeometry::TVec3f*)(p + 0xc), 0x110)) {
                    *(s32*)(p + 0x254) = slot;
                    *(s32*)(p + 0x268) = 0x4ce;
                    *(s32*)(p + 0x234) = 1;
                }
            }
            break;
        case 1:
            fn_8022FF8C(*(s32*)(p + 0x254), &b, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
            twtgAsk(p, 0x4cf);
            break;
        case 2: {
            fn_8022FF8C(*(s32*)(p + 0x254), &b, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
            s32 i;
            for (i = 0; i < n; i++) {
                if (twtgPlayerFlag(i)) {
                    break;
                }
            }
            if (i < n) {
                *(s32*)(p + 0x268) = 0x4d0;
                fn_803894BC(*(s32*)(p + 0x254), i + 1);
            } else {
                *(s32*)(p + 0x268) = 0x4d1;
            }
            if (twtgAsk(p, *(s32*)(p + 0x268)) && *(u32*)(p + 0x268) == 0x4d0) {
                fn_8043D874(lbl_8053AED0, i, 500, 0);
            }
            break;
        }
        default:
            *(s32*)(p + 0x230) = 4;
            *(s32*)(p + 0x238) = 5;
            *(s32*)(p + 0x254) = 0;
            *(s32*)(p + 0x234) = 0;
            break;
        }
    } else if (*(s32*)(p + 0x234) == 1) {
        fn_8022FF8C(*(s32*)(p + 0x254), &b, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
        if (fn_803865B8(*(s32*)(p + 0x254))) {
            if (*(s32*)(p + 0x238) < 2) {
                (*(s32*)(p + 0x238))++;
                *(s32*)(p + 0x234) = 0;
            } else {
                *(s32*)(p + 0x230) = 4;
                *(s32*)(p + 0x238) = 0;
                *(s32*)(p + 0x234) = 0;
            }
        }
    }
}

extern "C" s32 fn_80235ACC(s32 i);
extern "C" void fn_8038938C(s32 slot, s32 v);
extern "C" void fn_80389254(s32 slot, s32 v);

extern "C" void fn_803146DC(char* p) {
    TwtgBox b;
    JGeometry::TVec3f v;
    f32 dist;
    twtgUpdateDir(p, v, dist);
    b.min.x = *(f32*)(p + 0x258);
    b.min.y = *(f32*)(p + 0x25c);
    b.max.x = *(f32*)(p + 0x260);
    b.max.y = *(f32*)(p + 0x264);
    b.min.x += *(f32*)(p + 0xc);
    b.min.y += *(f32*)(p + 0x10);
    b.max.x += *(f32*)(p + 0xc);
    b.max.y += *(f32*)(p + 0x10);
    s32 slot;
    if (*(s32*)(p + 0x234) == 0) {
        switch (*(s32*)(p + 0x238)) {
        case 0: {
            fn_8022FEB8(&b, *(s32*)(p + 4), *(void**)(p + 0x198), 0, 0);
            slot = fn_8022FD8C(*(void**)(p + 0x198));
            s32 cmp = fn_8023DE58(*(s32*)(p + 4));
            if (cmp == *(s32*)(p + 4) && slot >= 0 && fn_802300EC()) {
                void* room = *(void**)(p + 0x198);
                s32 player = *(s32*)(p + 4);
                if (fn_8038AD24(slot, 0x481, room, player, *(JGeometry::TVec3f*)(p + 0xc), 0x110)) {
                    *(s32*)(p + 0x254) = slot;
                    *(s32*)(p + 0x268) = 0x481;
                    *(s32*)(p + 0x234) = 1;
                }
            }
            break;
        }
        case 1:
        case 2:
        case 3:
        case 4: {
            fn_8022FF8C(*(s32*)(p + 0x254), &b, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
            s32 n = fn_80235ACC(*(s32*)(p + 0x238) - 1);
            fn_8038938C(*(s32*)(p + 0x254), n);
            if (n != 0) {
                if (*(s32*)(p + 0x23c) == 3) {
                    fn_80389254(*(s32*)(p + 0x254), n * 5);
                } else if (*(s32*)(p + 0x23c) == 6) {
                    fn_80389254(*(s32*)(p + 0x254), n * 10);
                } else {
                    fn_80389254(*(s32*)(p + 0x254), n * 20);
                }
                twtgAsk(p, *(s32*)(p + 0x238) + 0x481);
            } else {
                twtgAsk(p, *(s32*)(p + 0x238) + 0x486);
            }
            break;
        }
        default:
            *(s32*)(p + 0x230) = 4;
            *(s32*)(p + 0x238) = 5;
            *(s32*)(p + 0x254) = 0;
            *(s32*)(p + 0x234) = 0;
            break;
        }
    } else if (*(s32*)(p + 0x234) == 1) {
        fn_8022FF8C(*(s32*)(p + 0x254), &b, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
        if (fn_803865B8(*(s32*)(p + 0x254))) {
            if (*(s32*)(p + 0x238) >= 1 && *(s32*)(p + 0x238) <= 4) {
                s32 n = fn_80235ACC(*(s32*)(p + 0x238) - 1);
                if (n != 0) {
                    if (*(s32*)(p + 0x23c) == 3) {
                        fn_8043D874(lbl_8053AED0, *(s32*)(p + 0x238) - 1, n * 5, 0);
                    } else if (*(s32*)(p + 0x23c) == 6) {
                        fn_8043D874(lbl_8053AED0, *(s32*)(p + 0x238) - 1, n * 10, 0);
                    } else {
                        fn_8043D874(lbl_8053AED0, *(s32*)(p + 0x238) - 1, n * 20, 0);
                    }
                }
            }
            if (*(s32*)(p + 0x238) >= fn_80138A30(lbl_8053AAF8)) {
                *(s32*)(p + 0x238) = 4;
            }
            if (*(s32*)(p + 0x238) < 4) {
                (*(s32*)(p + 0x238))++;
                *(s32*)(p + 0x234) = 0;
            } else {
                *(s32*)(p + 0x230) = 4;
                *(s32*)(p + 0x238) = 0;
                *(s32*)(p + 0x234) = 0;
            }
        }
    }
}

extern "C" s32 fn_80236228(s32 i);
extern "C" void fn_80458F04(void* mgr, u32 id);
extern "C" void fn_8038911C(s32 slot);
extern "C" void fn_80384C58(s32 slot, void* room);
extern "C" void fn_803B8C74(u8 v);
extern void* lbl_8053AF80;
extern u8 lbl_80529DEC[];

struct TwtgOrd { u8 pad[0x244]; s32 order[4]; };
extern "C" void fn_80315864(char* p) {
    TwtgBox b;
    b.min.x = *(f32*)(p + 0x258);
    b.min.y = *(f32*)(p + 0x25c);
    b.max.x = *(f32*)(p + 0x260);
    b.max.y = *(f32*)(p + 0x264);
    b.min.x += *(f32*)(p + 0xc);
    b.min.y += *(f32*)(p + 0x10);
    b.max.x += *(f32*)(p + 0xc);
    b.max.y += *(f32*)(p + 0x10);
    fn_8022FF8C(*(s32*)(p + 0x254), &b, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
    if (*(s32*)(p + 0x234) == 0) {
        switch (*(s32*)(p + 0x238)) {
        case 0:
            if (twtgAsk(p, 0x486)) {
                for (s32 k = fn_80138A30(lbl_8053AAF8) - 1; k > 0; k--) {
                    TwtgOrd* o = (TwtgOrd*)p;
                    for (s32 j = 0; j < k; j++) {
                        s32 nv = fn_80236228(o->order[1]);
                        if (fn_80236228(o->order[0]) < nv) {
                            s32 t = o->order[0];
                            o->order[0] = o->order[1];
                            o->order[1] = t;
                        }
                        o = (TwtgOrd*)((char*)o + 4);
                    }
                }
            }
            break;
        case 1:
        case 2:
        case 3:
        case 4: {
            s32 i;
            s32 v;
            s32 rank;
            s32 id;
            id = *(s32*)(p + (4 - *(s32*)(p + 0x238)) * 4 + 0x244);
            v = fn_80236228(id);
            rank = 0;
            for (i = rank; i < 4; i++) {
                if (i != id && (*(u8*)(lbl_8053AAF8 + 0x82) & (u8)(1 << i)) && v < fn_80236228(i)) {
                    rank++;
                }
            }
            fn_803894BC(*(s32*)(p + 0x254), rank + 1);
            fn_8038938C(*(s32*)(p + 0x254), fn_80236228(*(s32*)(p + (4 - *(s32*)(p + 0x238)) * 4 + 0x244)));
            if (rank != 0) {
                twtgAsk(p, *(s32*)(p + (4 - *(s32*)(p + 0x238)) * 4 + 0x244) + 0x48b);
            } else if (twtgAsk(p, *(s32*)(p + (4 - *(s32*)(p + 0x238)) * 4 + 0x244) + 0x48f)) {
                fn_80458F04(lbl_8053AF80, 0x1000027);
            }
            break;
        }
        case 5:
        default: {
            s32 n = fn_80138A30(lbl_8053AAF8);
            s32 sum = 0;
            for (s32 i = 0; i < n; i++) {
                sum += fn_80236228(i);
            }
            fn_80389254(*(s32*)(p + 0x254), sum);
            s32 q = sum / 999;
            if (q != 0) {
                u8 c = lbl_80529DEC[0x24f];
                for (s32 i = 0; i < q; i++) {
                    c = c < 99 ? (u8)(c + 1) : (u8)99;
                }
                lbl_80529DEC[0x24f] = c;
                fn_8038911C(*(s32*)(p + 0x254));
                twtgAsk(p, 0x493);
            } else {
                twtgAsk(p, 0x495);
            }
            break;
        }
        }
    } else if (*(s32*)(p + 0x234) == 1) {
        fn_8022FF8C(*(s32*)(p + 0x254), &b, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
        if (fn_803865B8(*(s32*)(p + 0x254))) {
            if (*(s32*)(p + 0x238) < 5) {
                if (*(s32*)(p + 0x238) == 0) {
                    *(s32*)(p + 0x238) = 5 - fn_80138A30(lbl_8053AAF8);
                } else {
                    (*(s32*)(p + 0x238))++;
                }
                *(s32*)(p + 0x234) = 0;
            } else {
                fn_80384C58(*(s32*)(p + 0x254), *(void**)(p + 0x198));
                fn_803B8C74(lbl_80529DEC[0x24f]);
                fn_8013665C(lbl_8053AAF8, 10, 2);
                *(s32*)(p + 0x234) = 2;
            }
        }
    }
}

// fn_803167F4 - TWTG: setParams().
extern const f32 lbl_80541898;
extern const f32 lbl_8054189C;
extern const f32 lbl_805418A0;
extern const f32 lbl_805418A4;
extern const f32 lbl_805418A8;
extern const f32 lbl_805418AC;
extern const f32 lbl_805418B0;
extern const f32 lbl_805418B4;
extern const s32 lbl_804714F8[];
extern const s32 lbl_804714D8[];
extern u8 lbl_8050EC80[];
extern "C" void fn_802D7844(void* rec, s32 a, s32 b);

static inline u8 twtgHasItem(s32 k) {
    u8* g = lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8;
    s32 r = (u8)(1 << k) & g[0x7a];
    return r != 0;
}

extern "C" void fn_803167F4(char* p) {
    *(u32*)(p + 0x230) = *(u32*)(p + 0x90) & 3;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x240) = 0;
    *(u32*)(p + 0x23c) = (*(u32*)(p + 0x90) >> 4) & 7;
    if (*(s32*)(p + 0x230) == 0) {
        *(f32*)(p + 0x60) = lbl_80541898;
        *(f32*)(p + 0x64) = lbl_80541898;
        *(f32*)(p + 0x68) = lbl_8054189C;
        *(f32*)(p + 0x6c) = lbl_8054189C;
        *(f32*)(p + 0x258) = lbl_805418A0;
        *(f32*)(p + 0x25c) = lbl_805418A4;
        *(f32*)(p + 0x260) = lbl_805418A8;
        *(f32*)(p + 0x264) = lbl_805418AC;
        for (s32 i = 0; i < 4; i++) {
            fn_802D7844(fn_802D6A9C(), 0, i);
        }
    } else if (*(s32*)(p + 0x230) == 3) {
        *(f32*)(p + 0x60) = lbl_805418B0;
        *(f32*)(p + 0x64) = lbl_805418B0;
        *(f32*)(p + 0x68) = lbl_805418B4;
        *(f32*)(p + 0x6c) = lbl_805418B4;
        *(f32*)(p + 0x258) = lbl_805418B0;
        *(f32*)(p + 0x25c) = lbl_805418B0;
        *(f32*)(p + 0x260) = lbl_805418B4;
        *(f32*)(p + 0x264) = lbl_805418B4;
    } else {
        *(s32*)(p + 0x230) = lbl_804714F8[*(s32*)(p + 0x23c)];
        *(f32*)(p + 0x60) = lbl_80541898;
        *(f32*)(p + 0x64) = lbl_80541898;
        *(f32*)(p + 0x68) = lbl_8054189C;
        *(f32*)(p + 0x6c) = lbl_8054189C;
        *(f32*)(p + 0x258) = lbl_805418A0;
        *(f32*)(p + 0x25c) = lbl_805418A0;
        *(f32*)(p + 0x260) = lbl_805418A8;
        *(f32*)(p + 0x264) = lbl_805418A8;
    }
    s32 k = *(s32*)(p + 0x23c);
    // NONMATCHING (99.1%): retail tests the bool with srwi. (no cmplwi).
    if (twtgHasItem(k) == 1) {
        *(s32*)(p + 0x268) = lbl_804714D8[k];
    } else {
        *(s32*)(p + 0x268) = 0x473;
    }
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 1;
    *(s32*)(p + 0x24c) = 2;
    *(s32*)(p + 0x250) = 3;
    *(s32*)(p + 0x254) = -1;
    *(s32*)(p + 0x238) = 0;
    *(u8*)(p + 0x26c) = 0;
    *(s32*)(p + 0x270) = 2;
    *(s32*)(p + 0x274) = 0;
    s32 room = *(s32*)(p + 0x4);
    JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(p + 0xc));
    fn_80316E50(*(AnimEffectRec**)(p + 0x278), room, pos);
}

// fn_803169E0 - TWTG: destructor.
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void* fn_803169E0(char* p, s16 how) {
    if (p != 0) {
        *(void**)p = lbl_804AAD60;
        AnimEffectRec* r = *(AnimEffectRec**)(p + 0x278);
        if (r != 0) {
            delete r;
            *(AnimEffectRec**)(p + 0x278) = 0;
        }
        __dt__5ActorFv(p, 0);
        if (how > 0) {
            operator delete(p);
        }
    }
    return p;
}

Twtg::Twtg() : Actor() {
    *(void**)this = lbl_804AAD60;
    ResourceHandle* h = new ResourceHandle();
    *(ResourceHandle**)((char*)this + 0x278) = h;
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
