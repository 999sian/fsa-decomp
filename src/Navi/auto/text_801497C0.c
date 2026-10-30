// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801497c0-0x80149854 (1 functions). split_file divides it into the game's real files.
#include "dolphin/types.h"

struct Unk802FF414 {
    u32 unk0;
    u16 unk4;
};
extern Unk802FF414 lbl_802FF414;

extern "C" void* fn_80157334(void* key, void* base, u32 count, u32 size, void* cmp);
extern "C" void fn_801497B0(void);
extern u8 lbl_802D75A8[];
extern volatile u32 lbl_802FF410;
extern volatile u32 lbl_802FF40C;
extern u32* volatile lbl_802FF41C;
extern "C" u32 fn_801497C0(u32 id) {
    u8* entry;
    u16 count;
    lbl_802FF410 = (id >> 6) & 0x3ff;
    entry = lbl_802D75A8 + lbl_802FF410 * 4;
    count = *(u16*)(entry + 0x5a00);
    if (count != 0) {
        lbl_802FF40C = *(u16*)(entry + 0x5a02);
        lbl_802FF414.unk4 = id;
        if ((lbl_802FF41C = (u32*)fn_80157334(&lbl_802FF414, lbl_802D75A8 + lbl_802FF40C * 8 + 0x6200, count, 8, (void*)fn_801497B0)) != 0) {
            return *lbl_802FF41C;
        }
    }
    return 0;
}
