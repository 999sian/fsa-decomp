// TU 0x802242F4-0x8022461C.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

struct Box {
    f32 x0, y0, x1, y1;
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

extern "C" BOOL fn_802242F4(u8* this_) {
    s32 id;
    BOOL ret = FALSE;
    s32 player;
    if (this_[0x1a8] != 0 && this_[0x196] == 0) {
        Box box;
        u8 out[8];
        fn_801F31C4(this_, &box);
        if (box.x1 - box.x0 > 0.0f && box.y1 - box.y0 > 0.0f) {
            player = fn_8023A7BC(&box, *(s32*)(this_ + 4), out);
            if (player >= 0 && player < 4) {
                id = *(s32*)(this_ + 4);
                if (fn_802D6A9C()->flag(id) != 0 ||
                    !(__fabsf(*(f32*)(this_ + 0x14) - fn_8023E724(player)[2]) > 32.0f)) {
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
