// Game TU 801D8400-801DA7C0 (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void fn_801D9C58(void* this_, s32 newState);
extern "C" {
}
extern "C" void fn_801CE2BC(void* this_);
extern "C" void fn_801E61C4(void* this_);
struct ActorSlot37 {
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void slot37();
};

extern "C" void fn_801D8400(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x248);
    if (state < 8) {
        fn_801D9C58(this_, 8);
    }
}

extern "C" void fn_801D84E0(void)
{
}

extern "C" void fn_801D89BC(void* this_) {
    u32 flags = *(u32*)((char*)this_ + 0x230);
    if ((flags & 7) == 0) {
        fn_801CE2BC(this_);
    } else {
        s32 state = *(s32*)((char*)this_ + 0x248);
        if (state == 0xf) {
            ((ActorSlot37*)this_)->slot37();
        }
    }
    u16 timer = *(u16*)((char*)this_ + 0x336);
    if (timer != 0) {
        *(u16*)((char*)this_ + 0x336) = timer - 1;
    }
    fn_801E61C4(this_);
}
