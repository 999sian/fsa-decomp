// TU 0x802eec50-0x802ef0a0 (actor CHSW).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Chsw_dtor_802EEC50.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804AA3E8[];

extern "C" void* fn_802EEC50(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA3E8;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Chsw_EmptyHook.cpp ----
// Chsw_EmptyHook - CHSW: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Chsw_EmptyHook(void) {}

}

// ---- NotifyCountdown_802EECB4.cpp ----
// fn_802EECB4 - CHSW: update(). Countdown timer at this->0x230; on
// expiry, dispatches a notify via own virtual slot 10 (byte offset
// 0x30, args 0xff + 1 or 0) depending on the mode byte at
// this->0x23e; then, depending on this->0x23d, notifies the per-room
// config via fn_802D6A9C with this->0x240 and args (1 or 0,
// 0xff); finally calls own virtual slot 7 (byte offset 0x24) if
// this->0x23c==1. When the countdown was already at 0 on entry,
// instead gates a possible countdown reset on own virtual slot 13
// (byte offset 0x34) and always refreshes this->0x234 with a second
// call to the same slot. See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why these
// calls go through real `virtual` members rather than manual casts.
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D8050(void*, s32, s32, s32);

struct ActorVT {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void slot7();
    virtual void v8();
    virtual void v9();
    virtual void slot10(s32 a, s32 b);
    virtual u8 slot13();
};

extern "C" void fn_802EECB4(void* this_) {
    s32 countdown = *(s32*)((char*)this_ + 0x230);
    if (countdown != 0) {
        *(s32*)((char*)this_ + 0x230) = countdown - 1;
        if (*(s32*)((char*)this_ + 0x230) == 0) {
            u8 mode1 = *(u8*)((char*)this_ + 0x23e);
            if (mode1 == 1) {
                ((ActorVT*)this_)->slot10(0xff, 1);
            } else if (mode1 == 2) {
                ((ActorVT*)this_)->slot10(0xff, 0);
            }
            u8 mode2 = *(u8*)((char*)this_ + 0x23d);
            if (mode2 == 0) {
                void* configRecord = fn_802D6A9C();
                fn_802D8050(configRecord, *(u16*)((char*)this_ + 0x240), 1, 0xff);
            } else if (mode2 == 1) {
                void* configRecord = fn_802D6A9C();
                fn_802D8050(configRecord, *(u16*)((char*)this_ + 0x240), 0, 0xff);
            }
            if (*(u8*)((char*)this_ + 0x23c) == 1) {
                ((ActorVT*)this_)->slot7();
            }
        }
    } else {
        if (*(u8*)((char*)this_ + 0x234) == 0) {
            if (((ActorVT*)this_)->slot13() == 1) {
                *(s32*)((char*)this_ + 0x230) = *(s32*)((char*)this_ + 0x238);
            }
        }
        u8 result = ((ActorVT*)this_)->slot13();
        *(u8*)((char*)this_ + 0x234) = result;
    }
}

// ---- RoomBitfieldParams_802EEDF0.cpp ----
// fn_802EEDF0 - CHSW: setParams. Extracts 6 bitfields from this->0x90
// into this->0x238/0x23c/0x23d/0x23e/0x240/0x242, zeroes this->0x230,
// then calls own virtual slot 13 (byte offset 0x34, room-config gate)
// and stores the result at this->0x234. See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why this calls
// through a real `virtual` member rather than a manual cast.
struct ActorSlot13 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual u8 slot13();
};

extern "C" void fn_802EEDF0(void* this_) {
    u32 sp = *(u32*)((char*)this_ + 0x90);
    *(u32*)((char*)this_ + 0x238) = sp & 0x1FFFF;
    sp = *(u32*)((char*)this_ + 0x90);
    *(u8*)((char*)this_ + 0x23c) = (sp >> 17) & 0x1;
    sp = *(u32*)((char*)this_ + 0x90);
    *(u8*)((char*)this_ + 0x23d) = (sp >> 18) & 0x3;
    sp = *(u32*)((char*)this_ + 0x90);
    *(u8*)((char*)this_ + 0x23e) = (sp >> 20) & 0x3;
    sp = *(u32*)((char*)this_ + 0x90);
    *(u16*)((char*)this_ + 0x240) = (sp >> 22) & 0x1F;
    sp = *(u32*)((char*)this_ + 0x90);
    *(u16*)((char*)this_ + 0x242) = sp >> 27;
    *(u32*)((char*)this_ + 0x230) = 0;
    u8 result = ((ActorSlot13*)this_)->slot13();
    *(u8*)((char*)this_ + 0x234) = result;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
