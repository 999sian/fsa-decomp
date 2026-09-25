// tu_80134C04: .text 0x80134C04-0x80139BE8
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/oscluster_80134dc0.cpp

extern "C" {

// fn_80134DC0(this) - a byte-flag toggle: this->0x86 = !this->0x86.
void fn_80134DC0(void* thisPtr)
{
    char* t = (char*)thisPtr;
    if (*(u8*)(t + 0x86) == 0) {
        *(u8*)(t + 0x86) = 1;
    } else {
        *(u8*)(t + 0x86) = 0;
    }
}

} // extern "C"

// ---- from Game/DiscErrorStateSetter_80134DE4.cpp

extern "C" void* fn_8008E328(s32 p1);
extern "C" void fn_8008E1FC(void* p1, void* p2, s32 p3, s32 p4);

extern u8 lbl_80529DEC[];
extern u8 lbl_8049ED88[];

// fn_80134DE4(this, code, param) - a "set disc-error/status code" method.
// No-op if the boot-config struct's byte (lbl_80529DEC->0x246, the SAME
// struct main() itself reads/writes) is 0. Otherwise re-fetches the DVD
// drive status object (fn_8008E328) and dispatches on `code`: 1-4 set a
// fixed retry-wait timer; 5-9 display a disc-error message string via
// fn_8008E1FC (each code picks a different message-table entry) then set
// a follow-up code; 10 uses `param` (or a default); anything else stores
// `code` verbatim.
extern "C" void fn_80134DE4(void* this_, s32 code, s32 param) {
    char* t = (char*)this_;
    u8* msgTable = lbl_8049ED88;
    if (*(u8*)(lbl_80529DEC + 0x246) == 0) {
        return;
    }

    char* drive = (char*)fn_8008E328(0);
    *(s32*)(t + 0x10c) = 0;

    if (code == 1) {
        *(s32*)(t + 0x108) = 0x1e;
    } else if (code == 2) {
        *(s32*)(t + 0x108) = 0x3c;
    } else if (code == 3) {
        *(s32*)(t + 0x108) = 0x5a;
    } else if (code == 4) {
        *(s32*)(t + 0x108) = 0x78;
    } else if (code == 5) {
        fn_8008E1FC(drive + 0x68, msgTable + 0xd0, 0, 0x3c);
        *(s32*)(t + 0x10c) = 1;
        *(s32*)(t + 0x108) = 0x41a;
    } else if (code == 6) {
        fn_8008E1FC(drive + 0x68, msgTable + 0x158, 0, 0x3c);
        *(s32*)(t + 0x10c) = 1;
        *(s32*)(t + 0x108) = 0x5b;
    } else if (code == 7) {
        fn_8008E1FC(drive + 0x68, msgTable + 0x168, 0, 0x3c);
        *(s32*)(t + 0x10c) = 1;
        *(s32*)(t + 0x108) = 0x5b;
    } else if (code == 8) {
        fn_8008E1FC(drive + 0x68, msgTable + 0x178, 0, 0x3c);
        *(s32*)(t + 0x10c) = 1;
        *(s32*)(t + 0x108) = 0x5b;
    } else if (code == 9) {
        fn_8008E1FC(drive + 0x68, msgTable + 0x188, 0, 0x3c);
        *(s32*)(t + 0x10c) = 1;
        *(s32*)(t + 0x108) = 0x5b;
    } else if (code == 10) {
        s32 val10 = param;
        if (param == 0) {
            val10 = 0x78;
        }
        *(s32*)(t + 0x108) = val10;
    } else {
        *(s32*)(t + 0x108) = code;
    }
}

// ---- from Game/oscluster_80134fbc.cpp

extern "C" {

// fn_80134FBC(this, val) - trivial setter, this->0x96 = val.
// fn_80134FC4(this, val) - setter with a side effect: this->0x94 = val;
// if the new value isn't 1, also sets this->0x95 = 1 (a "changed away
// from mode 1" latch).
void fn_80134FBC(void* thisPtr, u8 val)
{
    *(u8*)((char*)thisPtr + 0x96) = val;
}

void fn_80134FC4(void* thisPtr, u8 val)
{
    char* t = (char*)thisPtr;
    *(u8*)(t + 0x94) = val;
    if (*(u8*)(t + 0x94) != 1) {
        *(u8*)(t + 0x95) = 1;
    }
}

} // extern "C"

#include "JSystem/JAudio/JASFakeMatchFSA.h"
