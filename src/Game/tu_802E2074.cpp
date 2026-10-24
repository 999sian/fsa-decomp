// TU 0x802e2074-0x802e2990.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

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
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- EmptyHook_802E20D4.cpp ----
// Unnamed actor cluster, part 2/4. EmptyHook_802E20D4 - empty override (bare
// blr), no extab.
struct Box4 {
    f32 x0, y0, x1, y1;
};

extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" s32 fn_801F7818(void* mgr, u32 name, u32 room, void* list, s32 max);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 room, f32* pos, u32 param, s32 a, s32 b);
extern "C" void detach__5ActorFv(void* actor);
extern u16 lbl_8046E9D8[][4];

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

void fn_802E20D8(u8* this_) {}

void fn_802E20D8(u8* this_) {}

extern "C" void fn_802E2548(u8* param_1)
{
  u32* puVar8 = (u32*)lbl_804D4768;
  s32 i;
  char buf[56];
  for (i = 0; i < 2; i++) {
    puVar8[0x00] = 0xffffffff;
    puVar8[0x01] = 0xffffffff;
    puVar8[0x02] = 0xffffffff;
    puVar8[0x03] = 0xffffffff;
    puVar8[0x04] = 0xffffffff;
    puVar8[0x05] = 0xffffffff;
    puVar8[0x06] = 0xffffffff;
    puVar8[0x07] = 0xffffffff;
    puVar8[0x08] = 0xffffffff;
    puVar8[0x09] = 0xffffffff;
    puVar8[0x0a] = 0xffffffff;
    puVar8[0x0b] = 0xffffffff;
    puVar8[0x0c] = 0xffffffff;
    puVar8[0x0d] = 0xffffffff;
    puVar8[0x0e] = 0xffffffff;
    puVar8[0x0f] = 0xffffffff;
    puVar8[0x10] = 0xffffffff;
    puVar8[0x11] = 0xffffffff;
    puVar8[0x12] = 0xffffffff;
    puVar8[0x13] = 0xffffffff;
    puVar8[0x14] = 0xffffffff;
    puVar8[0x15] = 0xffffffff;
    puVar8[0x16] = 0xffffffff;
    puVar8[0x17] = 0xffffffff;
    puVar8[0x18] = 0xffffffff;
    puVar8[0x19] = 0xffffffff;
    puVar8[0x1a] = 0xffffffff;
    puVar8[0x1b] = 0xffffffff;
    puVar8[0x1c] = 0xffffffff;
    puVar8[0x1d] = 0xffffffff;
    puVar8[0x1e] = 0xffffffff;
    puVar8[0x1f] = 0xffffffff;
    puVar8[0x20] = 0xffffffff;
    puVar8[0x21] = 0xffffffff;
    puVar8[0x22] = 0xffffffff;
    puVar8[0x23] = 0xffffffff;
    puVar8[0x24] = 0xffffffff;
    puVar8[0x25] = 0xffffffff;
    puVar8[0x26] = 0xffffffff;
    puVar8[0x27] = 0xffffffff;
    puVar8 += 0x28;
  }
  lbl_8053ACB0 = 0;
  *(u32*)(param_1 + 0x234) = (*(u32*)(param_1 + 0x90) >> 23) & 0xf;
  *(u32*)(param_1 + 0x238) = (*(u32*)(param_1 + 0x90) >> 19) & 0xf;
  u8* a = (u8*)fn_802D6A9C();
  u32 uVar7 = *(u32*)(a + 4);
  u8* b = (u8*)fn_802D6A9C();
  void* c = fn_802D6A9C();
  char* pcVar5 = fn_802D9C7C(c, uVar7, *(u32*)(b + 8));
  s32 iVar3 = *(s32*)(param_1 + 0x234);
  s32 iVar6 = (s32)fn_802D6A9C();
  u8 bVar1 = *(u8*)(iVar3 + iVar6 + *(s32*)(param_1 + 0x238) * 10 + 0x60);
  u32 uVar2 = bVar1;
  if (bVar1 == 0xff) {
    uVar2 = 0;
  }
  sprintf(buf, lbl_8046E9F8, pcVar5, uVar2 / 10, uVar2 % 10);
  u32 uVar7b = fn_804032E8((pcVar5[0] - 0x20) * 0x10000 + (pcVar5[1] - 0x20) * 0x100 + pcVar5[2] + 0x42202000, buf);
  *(u32*)(param_1 + 0x244) = uVar7b;
  *(u32*)(param_1 + 0x248) = 0;
  *(u32*)(param_1 + 0x23c) = (*(u32*)(param_1 + 0x90) >> 16) & 7;
  *(u16*)(param_1 + 0x24c) = 0;
  *(u16*)(param_1 + 0x24e) = 8;
  *(u32*)(param_1 + 0x240) = 0;
  *(u32*)(param_1 + 0x230) = 2;
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
