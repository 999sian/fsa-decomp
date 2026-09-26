// TU 0x80207548-0x80207d84.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "Game/ItemBase.h"

// ---- fn_80207548_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A5B28[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80207548(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5B28;
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- small members ----
class Obj_80207548 : public ItemBase {
public:
    virtual void v39();
    virtual void v40();
};

extern "C" {
void fn_80207A60(void* this_) {
    char* p = (char*)this_;
    if (*(u8*)(p + 0x2aa) != 0) {
        (*(u8*)(p + 0x2aa))--;
        if (*(u8*)(p + 0x2aa) == 0 && *(u8*)(p + 0x2a8) == 0) {
            ((Obj_80207548*)this_)->v39();
        }
    }
}

void fn_80207AB8(void) {}

void fn_80207ABC(void) {}

struct Entry_80207548 {
    s32 m00;
    u8 m04;
    s32 m08;
    s32 m0C;
    f32 m10[3];
    s32 m1C;
    u8 m20;
};

Entry_80207548* fn_80207B2C(Entry_80207548* e) {
    e->m00 = -1;
    e->m04 = 0;
    e->m08 = -1;
    e->m0C = 0;
    e->m10[0] = 0.0f;
    e->m10[1] = 0.0f;
    e->m10[2] = 0.0f;
    e->m1C = 0;
    e->m20 = 0;
    return e;
}
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
