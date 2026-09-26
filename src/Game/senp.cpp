// TU 0x802e40a8-0x802e43e0 (actor SENP).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- fn_802E40A8_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A9C78[];

extern "C" void* fn_802E40A8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A9C78;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Senp_EmptyHook.cpp ----
// SENP cluster, part 2/4. Senp_EmptyHook - empty override (bare blr), no
// extab.
extern "C" {

void Senp_EmptyHook(void) {}

}

// ---- fn_802E410C ----
extern "C" void* fn_801F1184(void* this_);
extern "C" void fn_804561D8(void* obj, u32* id, u8 a, s32 b, u8 c);
extern const u32 lbl_8046F0B8[4];
extern const u8 lbl_805411F8[8];

extern "C" void fn_802E410C(void* this_) {
    char* p = (char*)this_;
    void* obj = fn_801F1184(this_);
    u32 id = lbl_8046F0B8[*(s32*)(p + 0x234)];
    fn_804561D8(obj, &id, lbl_805411F8[*(s32*)(p + 0x238)], 0, *(u8*)(p + 0x23c));
}

// ---- SpawnParamBits_802E416C.cpp ----
// SENP cluster, part 4/4. setParams-like - extracts 3 bitfields from
// the spawn parameter (this->0x90) into this->0x234/0x238/0x23c, then
// makes a virtual call to this object's own vtable slot 5 (byte
// offset 0x14). See [[reference_fsa_virtual_dispatch_codegen_trick]]
// for why this calls through a real `virtual` member rather than a
// manual cast.
struct ActorSlot5 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void slot5();
};

extern "C" void fn_802E416C(void* this_) {
    *(u32*)((char*)this_ + 0x234) = *(u32*)((char*)this_ + 0x90) & 0xFFF;
    *(u32*)((char*)this_ + 0x238) = (*(u32*)((char*)this_ + 0x90) >> 24) & 0x7;
    *(u8*)((char*)this_ + 0x23c) = (*(u32*)((char*)this_ + 0x90) >> 23) & 0x1;
    ((ActorSlot5*)this_)->slot5();
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
