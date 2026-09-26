// DBMS_8010DA6C: .text 0x8010DA6C-0x8010DF44 (actor DBMS)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/Dbms_ctor_8010DCDC.cpp
struct Actor {
    Actor();
    ~Actor();
};

extern "C" void fn_801D267C(void*);
extern void* lbl_8049D0E8[];

class Dbms : public Actor {
public:
    Dbms();
};

Dbms::Dbms() : Actor() {
    *(void**)this = lbl_8049D0E8;
    fn_801D267C((char*)this + 0x230);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
