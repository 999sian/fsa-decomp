#include "types.h"
#include "Game/Actor.h"

extern "C" void __dt__5ActorFv(void* self, s32 del);
extern "C" void __dl__FPv(void* p);
extern char lbl_804AD278[];
extern f32 lbl_80542854;
extern f32 lbl_80542858;
extern f32 lbl_8054285C;
extern f32 lbl_80542860;

static inline void setRect(f32* r, f32 a, f32 b)
{
    r[0] = a;
    r[1] = a;
    r[2] = b;
    r[3] = b;
}

static inline void setBounds(char* self, f32 a, f32 b)
{
    setRect((f32*)(self + 0x80), a, b);
    setRect((f32*)(self + 0x60), a, b);
}

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

extern "C" void fn_80357E48(void)
{
}

extern "C" void fn_803581AC(char* self)
{
    *(s32*)(self + 0x234) = *(u32*)(self + 0x90) & 0xf;
    switch (*(s32*)(self + 0x234)) {
    case 0:
    case 2:
    case 3:
        setBounds(self, lbl_80542854, lbl_80542858);
        break;
    case 1:
        setBounds(self, lbl_8054285C, lbl_80542860);
        break;
    }
    *(s32*)(self + 0x230) = 0;
}

