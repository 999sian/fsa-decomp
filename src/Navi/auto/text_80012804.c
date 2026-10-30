#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80012804-0x8001287c (1 functions). split_file divides it into the game's real files.

extern "C" char lbl_8029FDB4[];
extern "C" char lbl_8029FDA8[];
extern "C" char lbl_80204AC4[];
extern "C" char lbl_80204AEC[];
extern "C" void fn_800129AC(u8* self);
extern "C" void* fn_80012970(void* ptr, s16 param_2);
extern "C" void fn_8001287C(void);
extern "C" void fn_801E0DB8(void* self, void* a, void* b, s32 size, s32 count);
extern "C" void __register_global_object(void* obj, void* dtor, void* reg);
extern "C" void fn_80012804(void) {
    void** obj = (void**)lbl_8029FDB4;
    *(void**)lbl_8029FDB4 = lbl_80204AEC;
    *(void**)(lbl_8029FDB4 + 4) = lbl_80204AC4;
    fn_801E0DB8(lbl_8029FDB4 + 8, (void*)fn_800129AC, (void*)fn_80012970, 0x20, 0x40);
    __register_global_object(lbl_8029FDB4, (void*)fn_8001287C, lbl_8029FDA8);
}
