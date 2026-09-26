// TU 0x802188b0-0x80218cf4.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- fn_80218A8C.cpp ----
extern "C" s32 fn_801CD664(s32 range);

// fn_80218A8C(this) - zeroes +0x0, then sets a randomized u16 at +0x4
// via the confirmed fn_801CD664 PRNG helper (see
// reference_fsa_global_prng.md): a random int in [0x3c,0x3c+0x79) =
// [60,181]. Embedded by SLK2 at its own +0x540.
extern "C" {
extern f32 lbl_8053EDF0;
u16* fn_801C0D70();
u8 fn_801C5348(void* actor, f32 range);
void* fn_801F856C();
void* Actor_CreateByID(void* mgr, u32 id, u32 owner, void* pos, s32 a, s32 b, s32 c);
s32 fn_801F7818(void* mgr, u32 id, u32 owner, void** out, s32 max);
}

struct HbmbSpawner {
    char* mActor;
    u16 mTimer;
};

extern "C" void fn_802188B0(HbmbSpawner* s) {
    if (!(*fn_801C0D70() & 0x400)) {
        char* a = s->mActor;
        if (*(s32*)(a + 0x564) != 3) {
            if (s->mTimer > 1) {
                s->mTimer--;
            } else if (*(f32*)(a + 0x14) <= 0.0f && *(f32*)(a + 0x254) >= lbl_8053EDF0 - 0.001f) {
                if (!fn_801C5348(a, 64.0f)) {
                    a = s->mActor;
                    switch (*(s32*)(a + 0x248)) {
                    case 0x11:
                    case 0x1b:
                        Actor_CreateByID(fn_801F856C(), 'HBMB', *(u32*)(a + 0x4), a + 0xc, 10, -1, -1);
                        s->mTimer = fn_801CD664(0x79) + 0xf0;
                        break;
                    }
                }
            }
        }
    }
}

extern "C" bool fn_802189AC(HbmbSpawner* s) {
    bool found = false;
    void* list[0x400];
    s32 n = fn_801F7818(fn_801F856C(), 'HBMB', *(u32*)(s->mActor + 0x4), list, -1);
    for (s32 i = 0; i < n; i++) {
        char* h = (char*)list[i];
        if (h != NULL && *(u8*)(h + 0x11c) != 0 && *(u16*)(h + 0x94) != 1 && *(s32*)(h + 0x238) < 5) {
            f32 dx = *(f32*)(h + 0xc) - *(f32*)(s->mActor + 0xc);
            f32 dz = *(f32*)(h + 0x10) - *(f32*)(s->mActor + 0x10);
            f32 dx2 = dx * dx;
            f32 dz2 = dz * dz;
            if (dx2 + dz2 <= 1024.0f) {
                found = true;
                break;
            }
        }
    }
    return found;
}

extern "C" void* fn_80218A8C(void* this_) {
    *(s32*)((char*)this_ + 0x0) = 0;
    s32 r = fn_801CD664(0x79);
    *(u16*)((char*)this_ + 0x4) = (u16)(r + 0x3c);
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
