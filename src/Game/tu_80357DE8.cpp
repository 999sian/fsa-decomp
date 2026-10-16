#include "types.h"

extern "C" void __dt__5ActorFv(void* self, s32 del);
extern "C" void __dl__FPv(void* p);
extern char lbl_804AD278[];
extern f32 lbl_80542854;
extern f32 lbl_80542858;
extern f32 lbl_8054285C;
extern f32 lbl_80542860;

extern "C" void* fn_80357DE8(void* self, s16 del)
{
    if (self != NULL) {
        *(char**)self = lbl_804AD278;
        __dt__5ActorFv(self, 0);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
