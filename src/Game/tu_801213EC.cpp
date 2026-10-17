#include "types.h"
#include "JSystem/JGeometry/Box.h"
#include "JSystem/JGeometry/Vec.h"
#include <string.h>
#include "JSystem/JMath/JMath.h"
#include "Game/SinitPoolChain.h"

#pragma auto_inline off

typedef JGeometry::TVec3<f32> GameLowVec;

extern "C" void v01__5ActorFv(void* this_);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* p, s32 x);

namespace {
// Call-only vtable view for the two companion slots at 0x7C and 0xC4.
// This does not define an Actor layout or construct companion objects.
class CompanionCalls {
public:
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41(f32*, f32*, s32*);
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual u8 v47();
    virtual u8 v48();
    virtual u8 v49();
};

// Call-only vtable view for the seek/turn slots 0x78 and 0x94.
class SeekCalls {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual u8 v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37();
};

struct CompanionSlots {
    u8 pad[0x360];
    s32 count;
    s32 handles[4];
};
}

extern "C" {
u8 fn_8023E98C(s32);
u8 fn_8023ED8C(s32);
s32 fn_8023ECF0(s32);
u8 fn_8022D75C(s32);
s32 fn_800FDEA0(void*, f32*, GameLowVec*, s32*, s16*, s32);
u8 fn_800FD894(void*, s32, s32, s32);
s32 ClassifyBamAngleToQuadrant(u16);
void* fn_801F856C();
u8* fn_801F666C(void*, s32);
s32 Actor_CreateByID(void*, u32, u32, const GameLowVec*, s32, s32, s32);
void fn_800FE3EC(void*, s32, const GameLowVec*, u32);
const GameLowVec* fn_8023E724(s32);
void fn_801CD950(f32*, f32, f32);
void fn_8013CC50(u32, const GameLowVec*, s32, s32, s32, s32, s32, s32, f32);
void fn_801F0E34(void*, u32, s32);
void fn_801D22DC(void*, s32, s32, s32);
void fn_801D1F14(void*, f32);
s32 fn_8022EA0C(s32);
u8 fn_8022E438(s32, s32);
s32 fn_8022E970(s32);
s32 fn_8023AE34(const f32*, u32, f32*);
s32 fn_8023AB94(const f32*, u32, f32*);
s32 fn_80230CFC(s32);
void fn_801EEC98(void*, s32, s32*, s32*, f32*, f32*, s32, s32);
s32 fn_80138A30(void*);
u8 fn_80230188(s32);
u8 fn_8023F264(s32);
u16 fn_8022461C(f32*);
s32 v17__5ActorFiPf(void*, s32, f32*);
void* __dt__5ActorFv(void*, s32);
void __dl__FPv(void*);
void* __ct__5ActorFv(void*);
void fn_801D267C(void*);
void fn_8022FEB8(void*, s32, void*, s32, s32);
s32 fn_8022FD8C(void*);
u8 fn_802300EC(void);
u8 fn_8038AD24(s32, u16, void*, s32, GameLowVec, s32);

extern u8 lbl_8053AAA0;
extern void* lbl_8053AAF8;
extern s32 lbl_80539F30;
extern const u16 lbl_80464D84[];
extern void* lbl_8049E0C8[];
extern void* lbl_8049CC34[];
extern const f32 lbl_8053C9B0;
extern const f32 lbl_8053C9B4;
extern const f32 lbl_8053C9B8;
extern const f32 lbl_8053C9BC;
extern const f32 lbl_8053C9C0;
extern const f32 lbl_8053C9C4;
extern const f64 lbl_8053C9D0;
extern const f32 lbl_8053C9C8;
extern const f32 lbl_8053C9DC;
extern const f32 lbl_8053C9E0;
extern const f32 lbl_8053C9E4;
extern const f32 lbl_8053C9E8;
extern const f32 lbl_8053C9EC;
extern const f32 lbl_8053C9F4;
extern const f32 lbl_8053C9F8;
}

extern "C" s32 fn_801213EC() { return 0; }
extern "C" s32 fn_801213F4() { return 0; }
extern "C" s32 fn_801213FC() { return 0; }

extern "C" void fn_80121414() {}

extern "C" void fn_80121418() {
    return;
}

extern "C" void fn_8012141C() {}

extern "C" void fn_80121420() {}

extern "C" void fn_80121424() {}

extern "C" s32 fn_80121428() { return 1; }
extern "C" s32 fn_80121430() { return 0; }

extern "C" s32 fn_801216D0(void*, s32 player) {
  if (!fn_8023E98C(player)) {
    return -1;
  }
  for (s32 i = 0; i < 4; ++i) {
    if (fn_8023ED8C(i) && player == fn_8023ECF0(i) && fn_8022D75C(i)) {
      return i;
    }
  }
  return -1;
}

extern "C" void fn_80121764(u8* self) {
    if (self[0x332]) {
        for (s32 i = 0; i < ((CompanionSlots*)self)->count; ++i) {
            u8* actor = fn_801F666C(fn_801F856C(), ((CompanionSlots*)self)->handles[i]);
            if (actor && *(u32*)(actor + 0x1A0) == 'LIMT') {
                actor[0x11C] = 0;
                ((CompanionSlots*)self)->handles[i] = -1;
            }
        }
    }
}

extern const f32 lbl_8053C9D8;
extern "C" void fn_801217EC(u8* self, s32 flag) {
    if (self[0x332]) {
        s32 i = 0;
        u8* p = self;
        for (; i < *(s32*)(self + 0x360); i++) {
            if (*(s32*)(p + 0x364) < 0 && self[0x332] && i < *(s32*)(self + 0x360) && i >= 0) {
                GameLowVec pos(*(GameLowVec*)(self + 0xC));
                pos.x -= lbl_8053C9B0 * (f32)i + lbl_8053C9BC;
                *(s32*)(p + 0x364) = Actor_CreateByID(fn_801F856C(), 'LIMT', *(u32*)(self + 4), &pos, 0, -1, -1);
                s32 handle = *(s32*)(p + 0x364);
                if (handle >= 0) {
                    u8* actor = fn_801F666C(fn_801F856C(), handle);
                    if (actor) {
                        actor[0x11D] = 0;
                    }
                }
            }
            p += 4;
        }
        s32 off = 0;
        u8* q = self;
        for (i = 0; i < *(s32*)(self + 0x360); i++) {
            u8* actor = fn_801F666C(fn_801F856C(), *(s32*)(q + 0x364));
            if (!actor) {
                *(s32*)(q + 0x364) = -1;
            } else {
                if (self[0x333] != 0 || (u8)flag != 0 || self[0x335] != 0) {
                    actor[0x11D] = 1;
                } else {
                    actor[0x11D] = 0;
                }
                if ((u8)flag != 0) {
                    if (*(s32*)(self + 0x24C) < 8) {
                        s32 n = *(s32*)(self + 0x108) + 2 - off;
                        if (n < 0) {
                            n = 0;
                        }
                        if (n >= 4) {
                            n = 4;
                        }
                        *(u32*)(actor + 0x250) = *(u32*)(self + 0x198);
                        *(f32*)(actor + 0x254) = lbl_8053C9D8;
                        *(s32*)(actor + 0x24C) = n;
                    } else if (*(s32*)(self + 0x24C) < 0xC) {
                        s32 v = *(s32*)(self + 0x108);
                        *(u32*)(actor + 0x250) = *(u32*)(self + 0x198);
                        *(f32*)(actor + 0x254) = lbl_8053C9D8;
                        *(s32*)(actor + 0x24C) = v;
                    } else {
                        actor[0x11D] = 0;
                    }
                } else if (self[0x335] != 0) {
                    s32 n = *(s32*)(self + 0x108) - off;
                    if (n < 0) {
                        n = 0;
                    }
                    if (n >= 4) {
                        n = 4;
                    }
                    *(u32*)(actor + 0x250) = *(u32*)(self + 0x198);
                    *(f32*)(actor + 0x254) = lbl_8053C9D8;
                    *(s32*)(actor + 0x24C) = n;
                } else if (self[0x333] != 0) {
                    if (*(s32*)(self + 0x354) < 0x2D) {
                        s32 n = *(s32*)(self + 0x108) + 2 - off;
                        if (n < 0) {
                            n = 0;
                        }
                        if (n >= 4) {
                            n = 4;
                        }
                        *(u32*)(actor + 0x250) = *(u32*)(self + 0x198);
                        *(f32*)(actor + 0x254) = lbl_8053C9D8;
                        *(s32*)(actor + 0x24C) = n;
                    } else {
                        s32 n = *(s32*)(self + 0x108) - off;
                        if (n < 0) {
                            n = 0;
                        }
                        if (n >= 4) {
                            n = 4;
                        }
                        *(u32*)(actor + 0x250) = *(u32*)(self + 0x198);
                        *(f32*)(actor + 0x254) = lbl_8053C9D8;
                        *(s32*)(actor + 0x24C) = n;
                    }
                }
            }
            q += 4;
            off += 4;
        }
    }
}

extern "C" void fn_80121ABC(u8* self) {
    lbl_8053AAA0 = 0;
    ((CompanionCalls*)self)->v29();
    if (self[0x332]) {
        u8* p = self;
        GameLowVec position(*(GameLowVec*)(self + 0xC));
        position.x -= lbl_8053C9BC;
        CompanionSlots* slots = (CompanionSlots*)self;
        s32 i = 0;
        for (; i < slots->count; i++) {
            position.x += lbl_8053C9B0;
            *(s32*)(p + 0x364) = Actor_CreateByID(fn_801F856C(), 'LIMT',
                *(u32*)(self + 4), &position, 0, -1, -1);
            s32 handle = *(s32*)(p + 0x364);
            if (handle < 0) {
                break;
            }
            u8* actor = fn_801F666C(fn_801F856C(), handle);
            if (actor) {
                actor[0x11D] = 0;
            }
            p += 4;
        }
    }
}

s32 fn_800FDEA0(void*, JGeometry::TVec2<f32>*, GameLowVec*, s32*, s16*, s32);
extern "C" s32 fn_80121BB8(u8* self, f32* pt) {
    if (*(s32*)(self + 0x35c) <= 0) {
        return 1;
    }
    s16 angle = 0;
    GameLowVec vel(lbl_8053C9B4, lbl_8053C9B4, lbl_8053C9B4);
    s32 player = *(s32*)(self + 4);
    GameLowVec pos(*(GameLowVec*)(self + 0xC));
    pos.x += pt[0];
    pos.y += pt[1];
    JGeometry::TVec2<f32> p2(pos.x, pos.y);
    s32 r31 = fn_800FDEA0(self + 0x268, (f32*)&p2, &vel, &player, &angle, 0x200);
    *(f32*)(self + 0x3C) = vel.x;
    *(f32*)(self + 0x40) = vel.y;
    *(f32*)(self + 0x44) = vel.z;
    *(GameLowVec*)(self + 0xC) += *(GameLowVec*)(self + 0x3C);
    s32 quadrant = ClassifyBamAngleToQuadrant((u16)angle);
    if (quadrant >= 0) {
        *(s32*)(self + 0x374) += 1;
        if (*(s32*)(self + 0x374) >= 10) {
            *(s32*)(self + 0x374) = 10;
        }
        if (*(s32*)(self + 0x374) >= 10) {
            *(s32*)(self + 0x374) = 0;
            *(s32*)(self + 0x98) = quadrant;
            if (quadrant != *(s32*)(self + 0x238)) {
                fn_801D22DC(self + 0x230, quadrant, 2, 0);
                fn_801D1F14(self + 0x230, lbl_8053C9B4);
            }
        }
    }
    if (r31 == 3 || (r31 == 1 && fn_800FD894(self + 0x268, -1, 0, 0) == 1)) {
        return 1;
    }
    return 0;
}

extern "C" s32 fn_80121D68(u8* self) {
    GameLowVec position(*(GameLowVec*)(self + 0xC));
    fn_800FE3EC(self + 0x268, *(s32*)(self + 0x35C), &position,
        *(u32*)(self + 4));
    return 1;
}

extern "C" s32 fn_80121DB0(u8* self) {
    self[0x26A] = 0;
    self[0x26B] = 0;
    self[0x269] = 0;
    return 1;
}

#pragma fp_contract off
extern "C" f32 fn_80121DC8(u8* self, s32 player) {
    GameLowVec pos;
    pos = *fn_8023E724(player);
    f32 x = pos.x - *(f32*)(self + 0xC);
    f32 y = pos.y - *(f32*)(self + 0x10);
    f32 distance = x * x + y * y;
    if (distance > lbl_8053C9B4) {
        f32 inv = __frsqrte(distance);
        distance = inv * distance;
    }
    return distance;
}
#pragma fp_contract reset

extern "C" s32 fn_80121E40(u8* self) {
    switch (*(s32*)(self + 0x98)) {
    case 0:
        fn_801CD950((f32*)(self + 0x3C), lbl_8053C9B4, lbl_8053C9DC);
        break;
    case 1:
        fn_801CD950((f32*)(self + 0x3C), lbl_8053C9B4, lbl_8053C9E0);
        break;
    case 2:
        fn_801CD950((f32*)(self + 0x40), lbl_8053C9B4, lbl_8053C9DC);
        break;
    case 3:
        fn_801CD950((f32*)(self + 0x40), lbl_8053C9B4, lbl_8053C9E0);
        break;
    }
    *(f32*)(self + 0x44) -= lbl_8053C9E4;
    *(GameLowVec*)(self + 0xC) += *(GameLowVec*)(self + 0x3C);
    if (*(f32*)(self + 0x14) <= 0.0f) {
        *(f32*)(self + 0x14) = 0.0f;
        return 1;
    }
    return 0;
}

extern "C" void fn_80121F34(u8* self) {
    *(f32*)(self + 0x44) = lbl_8053C9B4;
    *(f32*)(self + 0x40) = lbl_8053C9B4;
    *(f32*)(self + 0x3C) = lbl_8053C9B4;
    switch (*(s32*)(self + 0x98)) {
    case 0: *(f32*)(self + 0x3C) = lbl_8053C9E8; break;
    case 1: *(f32*)(self + 0x3C) = lbl_8053C9EC; break;
    case 2: *(f32*)(self + 0x40) = lbl_8053C9E8; break;
    case 3: *(f32*)(self + 0x40) = lbl_8053C9EC; break;
    }
    *(f32*)(self + 0x44) = lbl_8053C9C8;
}

extern "C" void fn_80121FA8(u8* self) {
    GameLowVec position(*(GameLowVec*)(self + 0xC));
    position.y += lbl_8053C9F4;
    fn_8013CC50(*(u32*)(self + 4), &position, 0x33A, 0, 0, 0, 0, 1, lbl_8053C9F8);
    fn_801F0E34(self, 0x400ED, 0);
}

extern "C" void fn_8012202C(u8* self) {
    GameLowVec position(*(GameLowVec*)(self + 0xC));
    position.y += lbl_8053C9F4;
    fn_8013CC50(*(u32*)(self + 4), &position, 0x33A, 0, 0, 0, 0, 1, lbl_8053C9F8);
    fn_801F0E34(self, 0x400ED, 0);
    fn_801D22DC(self + 0x230, 9, 0, 0);
}

extern "C" void fn_801220C4(u8* self) {
    GameLowVec position(*(GameLowVec*)(self + 0xC));
    position.y += lbl_8053C9F4;
    fn_8013CC50(*(u32*)(self + 4), &position, 0x33A, 0, 0, 0, 0, 1, lbl_8053C9F8);
    fn_801F0E34(self, 0x400ED, 0);
}

extern "C" void fn_80122548(u8* self) {
    s32 player = *(s32*)(self + 0x344);
    s32 idx;
    if (player < 0 || player >= 4) {
        idx = -1;
    } else {
        idx = fn_8022EA0C(player);
    }
    if (idx >= 0) {
        self[0x331] = 0;
        player = *(s32*)(self + 0x344);
        if (player < 0 || player >= 4) {
            idx = -1;
        } else {
            idx = fn_8022EA0C(player);
        }
        GameLowVec pos = *fn_8023E724(idx);
        player = *(s32*)(self + 0x344);
        if (player < 0 || player >= 4) {
            player = -1;
        }
        *(s32*)(self + 0x98) = fn_80230CFC(fn_8022EA0C(player));
        switch (*(s32*)(self + 0x98)) {
        case 0:
            pos.x -= lbl_8053C9BC;
            break;
        case 1:
            pos.x += lbl_8053C9BC;
            break;
        case 2:
            pos.y -= lbl_8053C9BC;
            break;
        case 3:
            pos.y += lbl_8053C9BC;
            break;
        }
        *(f32*)(self + 0x37c) = 0.5f;
        fn_801CD950((f32*)(self + 0xc), pos.x, 2.0f);
        fn_801CD950((f32*)(self + 0x10), pos.y, 2.0f);
        player = *(s32*)(self + 0x344);
        if (player < 0 || player >= 4) {
            idx = -1;
        } else {
            idx = fn_8022EA0C(player);
        }
        s32 n = fn_80230CFC(idx);
        if (n < 0) {
            return;
        }
        *(s32*)(self + 0x374) += 1;
        if (*(s32*)(self + 0x374) >= 10) {
            *(s32*)(self + 0x374) = 10;
        }
        if (*(s32*)(self + 0x374) < 10) {
            return;
        }
        *(s32*)(self + 0x374) = 0;
        *(s32*)(self + 0x98) = n;
        if (n == *(s32*)(self + 0x238)) {
            return;
        }
        fn_801D22DC(self + 0x230, n, 2, 0);
        fn_801D1F14(self + 0x230, 0.0f);
    }
}

extern "C" void fn_80122730(u8* self, s32 direction, u8 alternate, u8 throttle) {
    if (direction < 0) {
        return;
    }
    if (throttle) {
        ++*(s32*)(self + 0x374);
        if (*(s32*)(self + 0x374) >= 10) {
            *(s32*)(self + 0x374) = 10;
        }
        if (*(s32*)(self + 0x374) < 10) {
            return;
        }
        *(s32*)(self + 0x374) = 0;
    }
    *(s32*)(self + 0x98) = direction;
    if (alternate) {
        direction += 5;
    }
    if (direction != *(s32*)(self + 0x238)) {
        fn_801D22DC(self + 0x230, direction, 2, 0);
        fn_801D1F14(self + 0x230, lbl_8053C9B4);
    }
}

extern "C" s32 fn_801227D4(u8* self) {
    ++*(s32*)(self + 0x350);
    if (*(s32*)(self + 0x350) >= 90) {
        *(s32*)(self + 0x350) = 0;
        return 1;
    }
    return 0;
}

extern "C" s32 fn_80122804(u8* self) {
    ++*(s32*)(self + 0x358);
    if (*(s32*)(self + 0x358) >= 15) {
        *(s32*)(self + 0x358) = 0;
        return 1;
    }
    return 0;
}

extern "C" s32 fn_80122834(u8* self) {
    if (*(s32*)(self + 0x108) == 0 && self[0x333] == 0) {
        return 1;
    }
    return 0;
}

extern "C" s32 fn_8012285C(u8* self) {
    s32 player = ((s32*)self)[0x344 / 4];
    if (player < 0 || player >= 4) {
        return -1;
    }
    return fn_8022EA0C(player);
}

extern "C" s32 fn_80122898(u8* self, s32 msg) {
    JGeometry::TBox2<f32> box = *(JGeometry::TBox2<f32>*)(self + 0x60);
    box.addPos(*(JGeometry::TVec2<f32>*)(self + 0xC));
    GameLowVec position(*(GameLowVec*)(self + 0xC));
    position.y -= lbl_8053C9C0;
    fn_8022FEB8(&box, *(s32*)(self + 4), *(void**)(self + 0x198), 1, 0);
    s32 slot = fn_8022FD8C(*(void**)(self + 0x198));
    if (slot < 0 || slot >= 4) {
        *(s32*)(self + 0x34C) = -1;
        return -1;
    }
    if (!fn_802300EC()) {
        *(s32*)(self + 0x34C) = -1;
        return -1;
    }
    void* room = *(void**)(self + 0x198);
    s32 player = *(s32*)(self + 4);
    if (fn_8038AD24(slot, (u16)msg, room, player, position, 0x28)) {
        *(s32*)(self + 0x34C) = slot;
        return slot;
    }
    *(s32*)(self + 0x34C) = -1;
    return -1;
}

extern "C" u8 fn_801229E4(u8* self) {
    JGeometry::TVec2<f32> position;
    JGeometry::TBox2<f32> box = *(JGeometry::TBox2<f32>*)(self + 0x60);
    box.addPos(*(JGeometry::TVec2<f32>*)(self + 0xC));
    position.set(lbl_8053C9B4, lbl_8053C9B4);
    if (fn_8023AE34((f32*)&box, *(u32*)(self + 4), (f32*)&position) >= 0) {
        return 1;
    }
    return fn_8023AB94((f32*)&box, *(u32*)(self + 4), (f32*)&position) >= 0;
}

extern "C" void fn_80122A9C(u8* self, f32* x, f32* y, s32* player) {
    f32 offset = lbl_8053C9B4;
    if (((CompanionCalls*)self)->v47()) {
        offset = lbl_8053C9BC;
    }
    switch (fn_80230CFC(*player)) {
    case 0: *x = lbl_8053C9B8 - offset; *y = lbl_8053C9B4; break;
    case 1: *x = lbl_8053C9BC + offset; *y = lbl_8053C9B4; break;
    case 2: *x = lbl_8053C9B4; *y = lbl_8053C9B8 - offset; break;
    case 3: *x = lbl_8053C9B4; *y = lbl_8053C9BC + offset; break;
    }
}

extern "C" u8 fn_8022E438(s32, s32);
extern "C" void fn_80122B98(u8* self, f32* a, f32* b, s32* out) {
  *a = lbl_8053C9B4;
  *b = lbl_8053C9B4;
  s32 idx = *out;
  s32 sel;
  if (idx < 0 || idx < 4) {
    if (idx < 0) {
      sel = idx;
    }
    for (s32 i = 0; i < 4; ++i) {
      if (fn_8022E438(i, idx)) {
        sel = i;
      }
    }
  } else {
    sel = idx;
  }
  *out = sel;
  f32 v = lbl_8053C9B4;
  if (((CompanionCalls*)self)->v47()) {
    v = lbl_8053C9BC;
  }
  switch (fn_80230CFC(*out)) {
    case 0:
      *a = -v;
      break;
    case 1:
      *a = v;
      break;
    case 2:
      *b = -v;
      break;
    case 3:
      *b = v;
      break;
  }
}

extern "C" void fn_80122CAC(u8* self, f32* x, f32* y, s32* player) {
    f32 offset = lbl_8053C9B4;
    if (((CompanionCalls*)self)->v47()) {
        offset = lbl_8053C9BC;
    }
    *player = fn_8022EA0C(*player);
    *x = offset;
    *y = lbl_8053C9BC + offset;
}

extern "C" void fn_80122D38(u8* self, f32* x, f32* y, s32* player) {
    f32 offset = lbl_8053C9B4;
    if (((CompanionCalls*)self)->v47()) {
        offset = lbl_8053C9BC;
    }
    switch (fn_80230CFC(*player)) {
    case 0: *x = lbl_8053C9B8 - offset; *y = lbl_8053C9B0; break;
    case 1: *x = lbl_8053C9C0 + offset; *y = lbl_8053C9B0; break;
    case 2: *x = lbl_8053C9B0; *y = lbl_8053C9B8 - offset; break;
    case 3: *x = lbl_8053C9B0; *y = lbl_8053C9C0 + offset; break;
    }
}

extern "C" void fn_80122E34(u8* self, f32* x, f32* y, s32* player) {
    f32 offset = lbl_8053C9B4;
    f32 t;

    if (((CompanionCalls*)self)->v47()) {
        offset = lbl_8053C9BC;
    }
    t = lbl_8053C9C4 * (f32)(fn_8022E970(*player) - 1) - lbl_8053C9C4;
    switch (fn_80230CFC(*player)) {
    case 0:
        *x = lbl_8053C9B8;
        *y = lbl_8053C9BC * t + offset;
        break;
    case 1:
        *x = lbl_8053C9BC;
        *y = lbl_8053C9BC * t + offset;
        break;
    case 2:
        *x = lbl_8053C9B8;
        *y = lbl_8053C9BC * t + offset;
        break;
    case 3:
        *x = lbl_8053C9B8;
        *y = lbl_8053C9BC * t + offset;
        break;
    }
}

extern "C" void fn_80123AB4(u8* self, s32 arg1, s32 arg2, f32 distance) {
    s32 direction;
    f32 otherDistance;
    f32 nearDistance;
    s32 result;
    fn_801EEC98(self, *(s32*)(self + 0x198), &result, &direction,
        &nearDistance, &otherDistance, arg1, arg2);
    s32 selectedDirection = direction;
    if (selectedDirection < 0) {
        return;
    }
    if (nearDistance > distance) {
        return;
    }
    if (selectedDirection < 0) {
        return;
    }
    ++*(s32*)(self + 0x374);
    if (*(s32*)(self + 0x374) >= 10) {
        *(s32*)(self + 0x374) = 10;
    }
    if (*(s32*)(self + 0x374) < 10) {
        return;
    }
    *(s32*)(self + 0x374) = 0;
    *(s32*)(self + 0x98) = selectedDirection;
    s32 animation = selectedDirection + 5;
    if (animation != *(s32*)(self + 0x238)) {
        fn_801D22DC(self + 0x230, animation, 2, 0);
        fn_801D1F14(self + 0x230, lbl_8053C9B4);
    }
}

extern "C" s32 fn_801F26CC(u8*, const void*);
extern "C" s32 ClassifyBamAngleToQuadrant(u16 angle);
extern const u8 lbl_80464CD8[];
extern const f32 lbl_8053C9F0;
extern "C" s32 fn_80123B94(u8* self) {
    if (!((SeekCalls*)self)->v28()) {
        return 0;
    }
    s32 handle = fn_801F26CC(self, lbl_80464CD8);
    if (handle < 0) {
        return 0;
    }
    u8* actor = fn_801F666C(fn_801F856C(), handle);
    if (actor != 0) {
        switch (*(s32*)(actor + 0x1a0)) {
        case 0x46495245: {
            s32 st = (*(u32*)(actor + 0x90) >> 6) & 0xf;
            if ((u32)st <= 1 || st == 5 || st == 6) {
                return 0;
            }
        }
        case 0x4f4b544d:
            switch (*(s32*)(actor + 0x230)) {
            case 2:
                return 0;
            }
            break;
        }
    }
    *(s32*)(self + 0x108) -= 2;
    if (*(s32*)(self + 0x108) > 0) {
        if (handle >= 0) {
            u8* a = fn_801F666C(fn_801F856C(), handle);
            if (a != 0) {
                GameLowVec pos = *(GameLowVec*)(a + 0xc);
                f32 ang = JMath::atanTable_.atan2_(pos.x - *(f32*)(self + 0xc),
                    (pos.y - pos.z) - (*(f32*)(self + 0x10) - *(f32*)(self + 0x14)));
                *(s32*)(self + 0x98) = ClassifyBamAngleToQuadrant((u16)(s32)(ang * lbl_8053C9F0));
            }
        }
        ((SeekCalls*)self)->v35();
    }
    return 1;
}

extern "C" void fn_80123D30(u8* self) {
    if (fn_80138A30(lbl_8053AAF8) == 1) {
        *(s32*)(self + 0x360) = 1;
    } else {
        *(s32*)(self + 0x360) = 4;
    }
    *(s32*)(self + 0x108) = *(s32*)(self + 0x360) << 2;
}

extern "C" s32 fn_80123D88(u8* self) {
    if (self[0x333]) {
        return 0;
    }
    s32 player = *(s32*)(self + 0x344);
    s32 mapped;
    if (player < 0 || player >= 4) {
        mapped = -1;
    } else {
        mapped = fn_8022EA0C(player);
    }
    if (mapped >= 0) {
        player = *(s32*)(self + 0x344);
        if (player < 0 || player >= 4) {
            mapped = -1;
        } else {
            mapped = fn_8022EA0C(player);
        }
        if (mapped < 4) {
            player = *(s32*)(self + 0x344);
            if (player < 0 || player >= 4) {
                mapped = -1;
            } else {
                mapped = fn_8022EA0C(player);
            }
            if (fn_80230188(mapped)) {
                return 0;
            }
            player = *(s32*)(self + 0x344);
            if (player < 0 || player >= 4) {
                mapped = -1;
            } else {
                mapped = fn_8022EA0C(player);
            }
            if (!fn_8023F264(mapped)) {
                return 0;
            }
        }
    }
    return 1;
}

extern "C" s32 fn_80123E80(u8* self, s32 state) {
    *(s32*)(self + 0x340) = *(s32*)(self + 0x33C);
    *(s32*)(self + 0x33C) = state;
    return 1;
}

extern "C" s32 fn_80123E94() { return 3; }

extern "C" s32 fn_80123E9C(u8* self, s32 arg, f32* data) {
    u16 kind = fn_8022461C(data);
    for (s32 i = 0; i < 8; ++i) {
        if (kind == lbl_80464D84[i]) {
            return 0;
        }
    }
    return v17__5ActorFiPf(self, arg, data);
}

extern "C" void v03__5ActorFv(void* this_);
extern "C" void fn_801217EC(u8* self, s32 flag);
extern "C" void fn_801D1C18(void* p);
extern "C" void fn_80239914(void* box, s32 player, void* room);
extern "C" void fn_801F2618(u8* self, GameLowVec* out, s32 mode);
extern "C" u8 fn_80121438(u8* self, GameLowVec* vel);
extern "C" void fn_8030C210(void* a, void* b);
extern void* lbl_8053AB10;
extern "C" void fn_80124278(u8* self) {
    v03__5ActorFv(self);
    *(f32*)(self + 0x37c) = lbl_8053C9F8;
    self[0x331] = 1;
    JGeometry::TBox2<f32> box(*(JGeometry::TBox2<f32>*)(self + 0x60));
    box.addPos(*(JGeometry::TVec2<f32>*)(self + 0xC));
    ((CompanionCalls*)self)->v30();
    if (self[0x333] != 0) {
        *(s32*)(self + 0x354) += 1;
        if (*(s32*)(self + 0x354) >= 300) {
            self[0x333] = 0;
            *(s32*)(self + 0x354) = 0;
        }
    }
    if (self[0x335] != 0) {
        *(s32*)(self + 0x378) += 1;
        if (*(s32*)(self + 0x378) >= 90) {
            self[0x335] = 0;
            *(s32*)(self + 0x378) = 0;
        }
    }
    ((CompanionCalls*)self)->v24();
    if (self[0x330] != 0) {
        fn_80239914(&box, *(s32*)(self + 4), *(void**)(self + 0x198));
    }
    if (self[0x331] != 0) {
        GameLowVec out;
        fn_801F2618(self, &out, 0);
    }
    GameLowVec vel(lbl_8053C9B4, lbl_8053C9B4, lbl_8053C9B4);
    if (fn_80121438(self, &vel)) {
        *(GameLowVec*)(self + 0xC) += vel;
    }
    *(f32*)(self + 0x260) = *(f32*)(self + 0x37c);
    fn_801D1C18(self + 0x230);
    fn_801217EC(self, *(s32*)(self + 0x108) ? 0 : 1);
    fn_8030C210(*(void**)((u8*)lbl_8053AB10 + 0x24), self + 0xC);
    ((CompanionCalls*)self)->v34();
}

void v01__5ActorFv(void*);
void* fn_802D6A9C(void);
void fn_802D7440(void*, s32);
extern "C" void v01__5ActorFv(void*);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void*, s32);
extern "C" void fn_80124448(u8* self) {
    v01__5ActorFv(self);
    lbl_80539F30 = *(s32*)(self + 0x198);
    ((CompanionCalls*)self)->v23();
    *(f32*)(self + 0x60) = -7.0f;
    *(f32*)(self + 0x64) = -7.0f;
    *(f32*)(self + 0x68) = 7.0f;
    *(f32*)(self + 0x6c) = 7.0f;
    *(f32*)(self + 0x70) = *(f32*)(self + 0x60);
    *(f32*)(self + 0x74) = *(f32*)(self + 0x64);
    *(f32*)(self + 0x78) = *(f32*)(self + 0x68);
    *(f32*)(self + 0x7c) = *(f32*)(self + 0x6c);
    *(f32*)(self + 0x80) = *(f32*)(self + 0x60);
    *(f32*)(self + 0x84) = *(f32*)(self + 0x64);
    *(f32*)(self + 0x88) = *(f32*)(self + 0x68);
    *(f32*)(self + 0x8c) = *(f32*)(self + 0x6c);
    *(s32*)(self + 0xb8) = 2;
    ((CompanionCalls*)self)->v26();
    ((CompanionCalls*)self)->v27();
    fn_802D7440(fn_802D6A9C(), 0);
    if (self[0x332]) {
        ((CompanionCalls*)self)->v29();
        if (self[0x332]) {
            s32 i = 0;
            u8* p = self;
            GameLowVec position(*(GameLowVec*)(self + 0xC));
            position.x -= lbl_8053C9BC;
            CompanionSlots* slots = (CompanionSlots*)self;
            for (; i < slots->count; i++) {
                position.x += lbl_8053C9B0;
                *(s32*)(p + 0x364) = Actor_CreateByID(fn_801F856C(), 'LIMT',
                    *(u32*)(self + 4), &position, 0, -1, -1);
                s32 handle = *(s32*)(p + 0x364);
                if (handle < 0) {
                    break;
                }
                u8* actor = fn_801F666C(fn_801F856C(), handle);
                if (actor) {
                    actor[0x11D] = 0;
                }
                p += 4;
            }
        }
    }
}

extern "C" void* fn_80131F0C(void);
extern "C" u8* fn_80131E30(void*, s32);
extern "C" void* fn_801F856C();
extern "C" u8* fn_801F666C(void*, s32);
extern "C" s32 lbl_80539F30;
extern "C" s32 fn_80124600(u8* self) {
    s32 count;
    u8 flag;
    s32 i;
    s32 ret;

    count = *(s32*)fn_80131F0C();
    if (count == 0) {
        count = lbl_80539F30;
        if (count < 0) {
            return 3;
        }
        {
            u8* actor = fn_801F666C(fn_801F856C(), count);
            if (actor == 0) {
                return 3;
            }
            actor[0x334] = 1;
            return ((s32 (**)(u8*, u8*))(*(void***)actor))[23](actor, self);
        }
    }
    flag = 0;
    for (i = 0; i < count; i++) {
        u8* p = fn_80131E30(fn_80131F0C(), i);
        if (p != 0 && *(s32*)(p + 0x1a0) == 0x46415a52) {
            s32 r;
            p[0x334] = 1;
            r = ((s32 (**)(u8*, u8*))(*(void***)p))[23](p, self);
            switch (r) {
            case 1:
                return 1;
            case 2:
                flag = 0;
                break;
            case 3:
                break;
            default:
                flag = 0;
                break;
            }
        }
    }
    ret = 2;
    if (flag) {
        ret = 3;
    }
    return ret;
}

extern "C" void* fn_80124740(u8* self, s16 deleting) {
    if (self) {
        *(void***)(self) = lbl_8049E0C8;
        lbl_80539F30 = -1;
        if (self + 0x230) {
            if (self + 0x254) {
                *(void***)(self + 0x254) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(self, 0);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

extern "C" void* fn_801247C8(u8* self, const char* name, s32 kind, u8 companions) {
    __ct__5ActorFv(self);
    *(void***)(self) = lbl_8049E0C8;
    fn_801D267C(self + 0x230);
    self[0x330] = 1;
    self[0x331] = 1;
    self[0x332] = companions;
    self[0x333] = 0;
    self[0x334] = 0;
    self[0x335] = 0;
    *(u16*)(self + 0x336) = 0;
    *(s32*)(self + 0x338) = kind;
    *(s32*)(self + 0x33C) = 0;
    *(s32*)(self + 0x340) = 0;
    *(s32*)(self + 0x344) = -1;
    *(s32*)(self + 0x348) = -1;
    *(s32*)(self + 0x34C) = -1;
    *(s32*)(self + 0x350) = 0;
    *(s32*)(self + 0x354) = 0;
    *(s32*)(self + 0x358) = 0;
    *(s32*)(self + 0x360) = 1;
    *(s32*)(self + 0x374) = -1;
    *(s32*)(self + 0x378) = 0;
    *(f32*)(self + 0x37C) = lbl_8053C9F8;
    *(f32*)(self + 0x380) = lbl_8053C9B4;
    *(s32*)(self + 0x364) = -1;
    *(s32*)(self + 0x368) = -1;
    *(s32*)(self + 0x36C) = -1;
    *(s32*)(self + 0x370) = -1;
    strcpy((char*)(self + 0x384), name);
    return self;
}

extern "C" void __sinit_tu_801213EC_cpp(void) {
}

// Keep regional definitions that were present before source-tree consolidation.
#if defined(VERSION_G4SE01)
extern "C" void fn_80121404(void) {
}

extern "C" void fn_80121408(void) {
}

extern "C" void fn_8012140C(void) {
}

extern "C" void fn_80121410(void) {
}
#endif
#if defined(VERSION_G4SJ01)
extern "C" void fn_80121404(void) {
    return;
}
#endif
#if defined(VERSION_G4SP01)
extern "C" void fn_80121404(void) {
}

extern "C" void fn_80121408(void) {
}

extern "C" void fn_8012140C(void) {
}

extern "C" void fn_80121410(void) {
}
#endif
