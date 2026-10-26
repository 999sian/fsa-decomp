// TU 0x802e2074-0x802e2990.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"

// ---- fn_802E2074_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A9BC8[];
extern "C" void* fn_802D6A9C(void);
extern "C" char* fn_802D9C7C(void* a, u32 b, u32 c);
extern "C" u32 fn_804032E8(u32 tag, char* buf);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern const char lbl_8046E9F8[];
extern u32 lbl_8053ACB0;
extern u8 lbl_804D4768[];

extern "C" void* fn_802E2074(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A9BC8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- EmptyHook_802E20D4.cpp ----
// Unnamed actor cluster, part 2/4. EmptyHook_802E20D4 - empty override (bare
// blr), no extab.
static inline s32 genDestinationRoom(const u8 destination) { return destination + 7; }
static inline void genSetPosition(JGeometry::TVec3<f32>& pos, const u16 x, const u16 y, f32 baseX, f32 baseY) {
    pos.set(8.0f * x + baseX, 8.0f * y + baseY, 0.0f);
}

struct Box4 {
    f32 x0, y0, x1, y1;
};

extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" s32 fn_801F7818(void* mgr, u32 name, u32 room, void* list, s32 max);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 room, f32* pos, u32 param, s32 a, s32 b);
extern "C" void detach__5ActorFv(void* actor);
extern u16 lbl_8046E9D8[][4];

extern "C" {

void EmptyHook_802E20D4(void) {}

void fn_802E20D8(u8* this_)
{
    s32 room = *(s32*)(this_ + 4);
    u8* game = (u8*)fn_802D6A9C();
    Box4* bounds;
    if (room < 8) bounds=(Box4*)(game+0xcc); else bounds=(Box4*)(game+0xdc);
    Box4 box = *bounds;
    s32 offset = 0;
    u8 finished = 0;
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        if ((s32)lbl_8053ACB0 != 0) {
            s32* entry = (s32*)lbl_804D4768;
            s32 id;
            for (s32 i = 0; i < 80; i++, entry++) {
                id = *entry;
                if (id >= 0 && fn_801F666C(fn_801F856C(), id) == 0) {
                    *entry = -1;
                    if (--lbl_8053ACB0 == 0) {
                        u8* list[1024];
                        s32 count = fn_801F7818(fn_801F856C(), 0x47454e32, *(u32*)(this_ + 4), list, -1);
                        for (s32 j = 0; j < count; j++) {
                            u8* actor = list[j];
                            if (actor != 0) {
                                if (actor != 0) *(s32*)(actor + 0x230) = 1;
                            }
                        }
                        *(s32*)(this_ + 0x230) = 1;
                        return;
                    }
                }
            }
            return;
        }
        *(s32*)(this_ + 0x230) = 1;
    case 1:
        *(s32*)(this_ + 0x240) = 0;
        do {
            u8 found = 1;
            u32 name;
            for (;;) {
                u8* data = *(u8**)(this_ + 0x244) + offset;
                name = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
                if (name == 0x20202020) {
                    *(u16*)(this_ + 0x24c) += 2;
                    offset = 0;
                    found = 0;
                    ++*(s32*)(this_ + 0x240);
                    if (*(u16*)(this_ + 0x24c) != *(u16*)(this_ + 0x24e)) continue;
                    finished = 1;
                    if (*(u16*)(this_ + 0x24c) == 64) detach__5ActorFv(this_);
                    else *(u16*)(this_ + 0x24e) += 8;
                    break;
                }
                if (*(s32*)(this_ + 0x23c) < 2) {
                    if (*(u16*)(this_ + 0x24c) == data[6]) break;
                } else {
                    if (*(u16*)(this_ + 0x24c) == data[5]) break;
                }
                offset += 11;
            }
            if (found == 1) {
                u8 destination;
                u8 y, x;
                u8* data = *(u8**)(this_ + 0x244) + offset;
                offset += 11;
                s32 room;
                u32 param = (data[7] << 24) | (data[8] << 16) | (data[9] << 8) | data[10];
                destination = data[4];
                x = data[5];
                y = data[6];
                f32 baseX, baseY;
                if (destination == 0) {
                    baseX = box.x0; baseY = box.y0; room = 0;
                } else {
                    baseX = baseY = 0.0f; room = genDestinationRoom(destination);
                }
                s32 direction = *(s32*)(this_ + 0x23c);
                if (direction < 2) {
                    JGeometry::TVec3<f32> pos;
                    genSetPosition(pos, x, lbl_8046E9D8[direction][*(s32*)(this_ + 0x240)], baseX, baseY);
                    ((s32*)lbl_804D4768)[lbl_8053ACB0] = Actor_CreateByID(fn_801F856C(), name, room, (f32*)&pos, param, 0, -1);
                } else {
                    JGeometry::TVec3<f32> pos;
                    genSetPosition(pos, lbl_8046E9D8[direction][*(s32*)(this_ + 0x240)], y, baseX, baseY);
                    ((s32*)lbl_804D4768)[lbl_8053ACB0] = Actor_CreateByID(fn_801F856C(), name, room, (f32*)&pos, param, 0, -1);
                }
                if (((s32*)lbl_804D4768)[lbl_8053ACB0] >= 0) {
                    if ((s32)++lbl_8053ACB0 >= 80) { detach__5ActorFv(this_); break; }
                }
            }
        } while (finished != 1);
        *(s32*)(this_ + 0x230) = 0;
        break;
    case 2:
        if ((*(u32*)(this_ + 0x90) >> 27) == 0 || (u8)((Actor*)this_)->v11() == 1) *(s32*)(this_ + 0x230) = 1;
        break;
    }
}

extern "C" void fn_802E2548(u8* param_1)
{
  u8* base = param_1;
  u8* p = lbl_804D4768;
  s32 i;
  for (i = 0; i < 2; i++) {
    *(u32*)(p + 0x00) = 0xffffffff;
    *(u32*)(p + 0x04) = 0xffffffff;
    *(u32*)(p + 0x08) = 0xffffffff;
    *(u32*)(p + 0x0c) = 0xffffffff;
    *(u32*)(p + 0x10) = 0xffffffff;
    *(u32*)(p + 0x14) = 0xffffffff;
    *(u32*)(p + 0x18) = 0xffffffff;
    *(u32*)(p + 0x1c) = 0xffffffff;
    *(u32*)(p + 0x20) = 0xffffffff;
    *(u32*)(p + 0x24) = 0xffffffff;
    *(u32*)(p + 0x28) = 0xffffffff;
    *(u32*)(p + 0x2c) = 0xffffffff;
    *(u32*)(p + 0x30) = 0xffffffff;
    *(u32*)(p + 0x34) = 0xffffffff;
    *(u32*)(p + 0x38) = 0xffffffff;
    *(u32*)(p + 0x3c) = 0xffffffff;
    *(u32*)(p + 0x40) = 0xffffffff;
    *(u32*)(p + 0x44) = 0xffffffff;
    *(u32*)(p + 0x48) = 0xffffffff;
    *(u32*)(p + 0x4c) = 0xffffffff;
    *(u32*)(p + 0x50) = 0xffffffff;
    *(u32*)(p + 0x54) = 0xffffffff;
    *(u32*)(p + 0x58) = 0xffffffff;
    *(u32*)(p + 0x5c) = 0xffffffff;
    *(u32*)(p + 0x60) = 0xffffffff;
    *(u32*)(p + 0x64) = 0xffffffff;
    *(u32*)(p + 0x68) = 0xffffffff;
    *(u32*)(p + 0x6c) = 0xffffffff;
    *(u32*)(p + 0x70) = 0xffffffff;
    *(u32*)(p + 0x74) = 0xffffffff;
    *(u32*)(p + 0x78) = 0xffffffff;
    *(u32*)(p + 0x7c) = 0xffffffff;
    *(u32*)(p + 0x80) = 0xffffffff;
    *(u32*)(p + 0x84) = 0xffffffff;
    *(u32*)(p + 0x88) = 0xffffffff;
    *(u32*)(p + 0x8c) = 0xffffffff;
    *(u32*)(p + 0x90) = 0xffffffff;
    *(u32*)(p + 0x94) = 0xffffffff;
    *(u32*)(p + 0x98) = 0xffffffff;
    *(u32*)(p + 0x9c) = 0xffffffff;
    p += 0xa0;
  }
  lbl_8053ACB0 = 0;
  *(u32*)(base + 0x234) = (*(u32*)(base + 0x90) >> 23) & 0xf;
  *(u32*)(base + 0x238) = (*(u32*)(base + 0x90) >> 19) & 0xf;
  u8* a = (u8*)fn_802D6A9C();
  u32 uVar7 = *(u32*)(a + 4);
  u8* b = (u8*)fn_802D6A9C();
  void* c = fn_802D6A9C();
  char* pcVar5 = fn_802D9C7C(c, uVar7, *(u32*)(b + 8));
  s32 iVar3 = *(s32*)(base + 0x234);
  s32 iVar6 = (s32)fn_802D6A9C();
  u8 bVar1 = *(u8*)(iVar3 + iVar6 + *(s32*)(base + 0x238) * 10 + 0x60);
  u32 uVar2 = bVar1;
  if (bVar1 == 0xff) {
    uVar2 = 0;
  }
  char buf[44];
  sprintf(buf, lbl_8046E9F8, pcVar5, uVar2 / 10, uVar2 % 10);
  u32 uVar7b = fn_804032E8((pcVar5[0] - 0x20) * 0x10000 + (pcVar5[1] - 0x20) * 0x100 + pcVar5[2] + 0x42202000, buf);
  *(u32*)(base + 0x244) = uVar7b;
  *(u32*)(base + 0x248) = 0;
  *(u32*)(base + 0x23c) = (*(u32*)(base + 0x90) >> 16) & 7;
  *(u16*)(base + 0x24c) = 0;
  *(u16*)(base + 0x24e) = 8;
  *(u32*)(base + 0x240) = 0;
  *(u32*)(base + 0x230) = 2;
}

}

static u8 lbl_804D4768[0x140];

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
