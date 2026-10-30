// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80149afc-0x80149ba4 (1 functions). split_file divides it into the game's real files.
#include "dolphin/types.h"

typedef struct { u16 pad; u16 len; void* data; } Unk80149AFCEntry;

extern u8 lbl_802D75A8[];
extern u16 lbl_802FF40A;
extern "C" void fn_80149AEC(void);
extern "C" void* fn_80157334(void*, void*, u16, s32, void*);
extern "C" void* fn_80149AFC(u16 id) {
    s32 i;
    Unk80149AFCEntry* e;
    void* r;
    *(u16*)(lbl_802D75A8 + 0xA62C) = id;
    e = (Unk80149AFCEntry*)(lbl_802D75A8 + 0xA200);
    for (i = 0; i < lbl_802FF40A; i++, e++) {
        r = fn_80157334(lbl_802D75A8 + 0xA62C, e->data, e->len, 10, (void*)fn_80149AEC);
        if (r != 0) {
            return r;
        }
    }
    return 0;
}
