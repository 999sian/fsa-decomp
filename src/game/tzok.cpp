// TU 0x80204d44-0x80206b30 (actor TZOK).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- fn_802064E0.cpp ----
extern "C" void* GetRoomConfigRecord(void);
extern "C" u8 fn_802D7F40(void* record, s32 roomIdx);

// NEW ACTOR (vtable lbl_804A5A30). Room-membership predicate: true
// when this->0x354 (a room index) is set and matches via the confirmed
// GetRoomConfigRecord/fn_802D7F40 pair.
extern "C" s32 fn_802064E0(void* this_) {
    s32 result = 0;
    s32 roomIdx = *(s32*)((char*)this_ + 0x354);
    if (roomIdx != 0) {
        if (fn_802D7F40(GetRoomConfigRecord(), roomIdx)) {
            result = 1;
        }
    }
    return result;
}

// ---- fn_80206758_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void* fn_80204638(void);
extern "C" void fn_802049E0(void* base, void* this_);
extern void* lbl_804A5A30[];
extern void* lbl_804A46F4[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80206758(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5A30;
        fn_801EE434(*(void**)(p + 0x358));
        void* base = fn_80204638();
        fn_802049E0(base, this_);
        if (this_ != 0) {
            *(void**)p = lbl_804A46F4;
            if (this_ != 0) {
                *(void**)p = lbl_804A4808;
                if (p + 0x270 != 0) {
                    if (p + 0x294 != 0) {
                        *(void**)(p + 0x294) = lbl_8049CC34;
                    }
                }
                dtor_801F593C(this_, 0);
            }
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}
