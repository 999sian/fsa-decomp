// TU 0x802e794c-0x802e7db4 (actor PNP2).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Mjgr_dtor_802E794C.cpp ----
extern "C" void dtor_801F593C(void* this_, int how);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A9F58[];

extern "C" void* fn_802E794C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A9F58;
        dtor_801F593C(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Mjgr_EmptyHook.cpp ----
// Mjgr_EmptyHook - MJGR: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Mjgr_EmptyHook(void) {}

}

// ---- RoomBitfieldClearParams_802E7B04.cpp ----
extern "C" void* GetRoomConfigRecord(void);
extern "C" u8 fn_802D7544(void*, void*);

// fn_802E7B04 - MJGR: setParams. Extracts 4 bitfields from this->0x90
// into this->0x230/0x234/0x238/0x23c, calls GetRoomConfigRecord then
// fn_802D7544(this->0x16c); if that query returns true, clears
// 0x238/0x23c; finally calls own virtual slot 5 (byte offset 0x14,
// notify/draw call). See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why this calls
// through a real `virtual` member rather than a manual cast.
struct ActorSlot5 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void slot5();
};

extern "C" void fn_802E7B04(void* this_) {
    *(u32*)((char*)this_ + 0x230) = *(u32*)((char*)this_ + 0x90) & 0xFFF;
    *(u32*)((char*)this_ + 0x234) = (*(u32*)((char*)this_ + 0x90) >> 12) & 0xFFF;
    *(u32*)((char*)this_ + 0x238) = (*(u32*)((char*)this_ + 0x90) >> 24) & 0x1;
    *(u32*)((char*)this_ + 0x23c) = (*(u32*)((char*)this_ + 0x90) >> 25) & 0x1;
    void* configRecord = GetRoomConfigRecord();
    if (fn_802D7544(configRecord, *(void**)((char*)this_ + 0x16c)) != 0) {
        *(u32*)((char*)this_ + 0x23c) = 0;
        *(u32*)((char*)this_ + 0x238) = 0;
    }
    ((ActorSlot5*)this_)->slot5();
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
