

#include "types.h"

extern "C" u32* fn_80169B1C(u32* self, short param_2)
{
    if (self != NULL) {
        self[0] = (u32)lbl_80298644;
        register u32* p = (u32*)self[0x1c];
        if (p != NULL) {
            (*(VFn_80169B1C*)(p[0] + 0xb8))(p, 1);
        }
        p = (u32*)self[0x1d];
        if (p != (uInt)NULL) {
            (*(VFn_80169B1C*)(p[0] + 0x34))(p, 1);
        }
        fn_8016B170(self + 10, -1);
        fn_8015AB1C((void*)self[0x21]);
        if ((u8*)self + 0x10 != NULL) {
            self[9] = lbl_80298660;
        }
        if (param_2 > 0) {
            fn_8015AB1C(self);
        }
    }
    register return self;
}

extern "C" void fn_80178DB0(void* param_1) {
    register void* vtable = *(void**)param_1;
    void (*func)(void) = *(void(**)(void))((u8*)vtable + 0x74);
    func();
}
#include "types.h"
