// TU 0x80390818-0x80391ce4.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/Dtor_lbl804AF490_80391974.cpp ----
// fn_80391974 - actor@lbl_804AF490: destructor. Reinstalls the base
// vtable, calls own virtual slot 0 (byte offset 0x8) on this->0x48 and
// this->0x4c if set, clearing each afterward, then conditionally
// forwards to __dl__FPv. See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why this calls
// through a real `virtual` member rather than a manual cast.
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF490[];

struct Slot0 {
    virtual void slot0(s32 arg);
};

extern "C" void* fn_80391974(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF490;
        void* p1 = *(void**)((char*)this_ + 0x48);
        if (p1 != 0) {
            ((Slot0*)p1)->slot0(1);
        }
        *(void**)((char*)this_ + 0x48) = 0;
        void* p2 = *(void**)((char*)this_ + 0x4c);
        if (p2 != 0) {
            ((Slot0*)p2)->slot0(1);
        }
        *(void**)((char*)this_ + 0x4c) = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/fn_80391A1C_ctor.cpp ----
class ArchiveHolder_803973E8 {
public:
    ArchiveHolder_803973E8(void* owner, s32 val, const char* name);
private:
    unsigned char pad[0x3c4];
};

extern void* lbl_804AF490[];
extern char lbl_804756D8[];
extern char lbl_804756F4[];

extern "C" void* fn_80391A1C(void* this_, s32 param2) {
    char* p = (char*)this_;
    *(void**)p = lbl_804AF490;
    *(s32*)(p + 0x18) = param2;
    ArchiveHolder_803973E8* obj1 = new ArchiveHolder_803973E8(this_, *(s32*)(p + 0x18), lbl_804756D8);
    *(ArchiveHolder_803973E8**)(p + 0x48) = obj1;
    ArchiveHolder_803973E8* obj2 = new ArchiveHolder_803973E8(this_, *(s32*)(p + 0x18), lbl_804756F4);
    *(ArchiveHolder_803973E8**)(p + 0x4c) = obj2;
    *(char*)(p + 0x44) = 0;
    *(s32*)(p + 0x1c) = 1;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
