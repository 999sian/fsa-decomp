// DEAL_80108414: .text 0x80108414-0x80108A6C (actor DEAL)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_80108414_dtor.cpp

extern "C" void dtor_801F593C(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049CD48[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80108414(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049CD48;
        if (p + 0x238 != 0) {
            if (p + 0x25c != 0) {
                *(void**)(p + 0x25c) = lbl_8049CC34;
            }
        }
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- from Game/fn_801087F4_ctor.cpp

struct Actor {
    Actor();
    ~Actor();
};

extern "C" void fn_801D267C(void*);
extern void* lbl_8049CD48[];

class fn_801087F4_actor : public Actor {
public:
    fn_801087F4_actor();
};

fn_801087F4_actor::fn_801087F4_actor() : Actor() {
    *(void**)this = lbl_8049CD48;
    char* p = (char*)this;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = -1;
    fn_801D267C(p + 0x238);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
