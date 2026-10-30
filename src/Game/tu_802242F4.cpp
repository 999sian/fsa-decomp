// TU 0x802242F4-0x8022461C — Player Bounding-Box / Height Proximity Hit Check.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

struct Box {
    f32 x0, y0, x1, y1;
};

struct ProximityCheckActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ s32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPosX;
    /* 0x010 */ f32 mPosY;
    /* 0x014 */ f32 mPosZ;
    /* 0x018 */ u8 _pad18[0x196 - 0x18];
    /* 0x196 */ u8 mDisableCheckFlag;
    /* 0x197 */ u8 _pad197[0x1A8 - 0x197];
    /* 0x1A8 */ u8 mEnableCheckFlag;
};

extern "C" void fn_801F31C4(void* this_, Box* box);
extern "C" s32 fn_8023A7BC(Box* box, s32 id, void* out);
extern "C" f32* fn_8023E724(s32 player);
struct Mgr {
    u8 flag(u32 i) { return mFlags[i]; }
    u8 pad[0x131df];
    u8 mFlags[1];
};
extern "C" Mgr* fn_802D6A9C(void);
extern "C" void fn_801A3C50(void* this_, s32 player);

extern "C" BOOL fn_802242F4(ProximityCheckActor* this_) {
    s32 id;
    BOOL ret = FALSE;
    s32 player;
    if (this_->mEnableCheckFlag != 0 && this_->mDisableCheckFlag == 0) {
        Box box;
        u8 out[8];
        fn_801F31C4(this_, &box);
        if (box.x1 - box.x0 > 0.0f && box.y1 - box.y0 > 0.0f) {
            player = fn_8023A7BC(&box, this_->mRoomId, out);
            if (player >= 0 && player < 4) {
                id = this_->mRoomId;
                if (fn_802D6A9C()->flag(id) != 0 ||
                    !(__fabsf(this_->mPosZ - fn_8023E724(player)[2]) > 32.0f)) {
                    fn_801A3C50(this_, player);
                    ret = TRUE;
                }
            }
        }
    }
    return ret;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804CF0CC[0x94];
