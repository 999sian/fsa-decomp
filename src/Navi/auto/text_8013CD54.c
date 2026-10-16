#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8013cd54-0x8013d9a4 (28 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_80133414(void*, int);
extern char lbl_80293318[];
extern "C" void fn_8013BC94(void*, void*, void*, void*, void*);
extern "C" void fn_8013D5DC(void*, void*);
extern "C" void fn_8013D7E0(void*, void*);
struct Entry_802C67C4 { s32 unk0; s32 id; u8 pad[0x18]; };
extern Entry_802C67C4 lbl_802C67C4[];
extern u8 lbl_802FF378[];
struct VObj_8013D304 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual u32 vf4();
    virtual void vf5(u32);
};
extern "C" void* fn_8013CD6C(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80293318;
        fn_80133414(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}
