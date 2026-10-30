// TU 0x803b8970-0x803b8c74 — Actor 'TLK2' (Colored Speech Bubble / Text Trigger).
#include "types.h"
#include "JSystem/JUtility/TColor.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AFAD8[];

struct Tlk2Actor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPosX;
    /* 0x010 */ f32 mPosY;
    /* 0x014 */ f32 mPosZ;
    /* 0x018 */ u8 _pad18[0x90 - 0x18];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x234 - 0x94];
    /* 0x234 */ u32 mMessageId;  // Unpacked from spawnParam & 0xFFFF
    /* 0x238 */ u32 mSubId;      // Unpacked from (spawnParam >> 16) & 0xFFF
    /* 0x23C */ u8 mWindowStyle; // Unpacked from spawnParam >> 28
};

extern "C" void* fn_803B8970(Tlk2Actor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804AFAD8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" {
void fn_803B89D0(void) {}
void fn_803B89D4(void) {}
}

extern "C" void fn_8037F2FC(u32 a, u32 b, u8 c, JUtility::TColor color, f32 x, f32 y, f32 z, f32 w);

// TLK2 init (vtable slot 1)
extern "C" void fn_803B89D8(Tlk2Actor* p) {
    p->mMessageId = p->mSpawnParam & 0xFFFF;
    p->mWindowStyle = p->mSpawnParam >> 28;
    p->mSubId = (p->mSpawnParam >> 16) & 0xFFF;
    fn_8037F2FC(p->mMessageId, p->mSubId, p->mWindowStyle, JUtility::TColor(0xFF0000FF),
                p->mPosX, p->mPosY, p->mPosZ, p->mPosZ);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
