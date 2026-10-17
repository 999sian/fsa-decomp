#include "types.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "Game/Actor.h"


extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AC760[];
extern "C" void* fn_803481B8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AC760;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_80348218(void) {}

extern "C" char* fn_802D6A9C();
extern "C" bool fn_802D800C(char* p, s32 bit);
extern "C" void fn_80348698(s32* this_) {
    this_[0x8D] = this_[0x24] & 0xF;
    this_[0x8E] = (u32)this_[0x24] >> 22 & 0x1F;
    this_[0x8F] = (u32)this_[0x24] >> 17 & 0x1F;
    this_[0x91] = 0;
    *(u8*)(this_ + 0x92) = 0;
    this_[0x90] = 0;
    char* rooms = fn_802D6A9C();
    if (fn_802D800C(rooms, this_[0x8E]) == 1) {
        switch (this_[0x8D]) {
        case 0:
            this_[0x90] = 0x78;
            break;
        case 1:
            this_[0x90] = 0x1E;
            break;
        case 2:
            this_[0x90] = 0x78;
            break;
        }
        this_[0x8C] = 1;
    } else {
        this_[0x90] = 0;
        this_[0x8C] = 0;
    }
    reinterpret_cast<Actor*>(this_)->v03();
}

void fn_80348780(void) {}

