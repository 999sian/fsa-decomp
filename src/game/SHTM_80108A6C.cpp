// SHTM_80108A6C: .text 0x80108A6C-0x80109534 (actor SHTM)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_80108A6C_dtor.cpp

extern "C" void dtor_801F593C(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049CDC0[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80108A6C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049CDC0;
        if (p + 0x230 != 0) {
            if (p + 0x254 != 0) {
                *(void**)(p + 0x254) = lbl_8049CC34;
            }
        }
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- from Game/fn_801092B0_ctor.cpp

struct Actor {
    Actor();
    ~Actor();
};

extern "C" void fn_801D267C(void*);
extern void* lbl_8049CDC0[];

class fn_801092B0_actor : public Actor {
public:
    fn_801092B0_actor();
};

fn_801092B0_actor::fn_801092B0_actor() : Actor() {
    *(void**)this = lbl_8049CDC0;
    char* p = (char*)this;
    fn_801D267C(p + 0x230);
    *(s32*)(p + 0x268) = 8;
    *(s32*)(p + 0x26c) = 0;
    *(s32*)(p + 0x270) = -1;
    *(s32*)(p + 0x274) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
