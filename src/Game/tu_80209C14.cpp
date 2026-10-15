#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry/Box.h"


extern void* lbl_804A5D60[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void* fn_80209C14(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5D60;
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
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_80209D44(ItemBase* this_) {
    this_->m230 |= 0x2000;
}

extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" void fn_802075D8(void*, u16);
extern "C" void v07__5ActorFv(void*);
extern "C" u32 fn_801F2DB4(void*, u32, u32, void*);
extern "C" void fn_8020A008(ItemBase* this_) {
    this_->m230 |= 0x80;
}

extern "C" s32 fn_8020A0E8(u8* this_) {
    fn_801F2DB4(this_, *(u32*)(this_ + 0x1A0), 'NULL', 0);
    return 0;
}

