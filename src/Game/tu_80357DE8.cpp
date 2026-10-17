#include "types.h"
#include "Game/Actor.h"

extern "C" void __dt__5ActorFv(void* self, s32 del);
extern "C" void __dl__FPv(void* p);
extern char lbl_804AD278[];
extern "C" void* fn_801F856C(void);
extern "C" void fn_801F31C4(const Actor* a, f32* out);
extern "C" void fn_801F0D20(Actor* a, u32 p);
static s32 fn_80357E4C_findHit(Actor* self);
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
static s32 fn_80357E4C_findHit(Actor* self)
{
    f32 boxA[4];
    f32 boxB[4];
    s32 hit = -1;
    s32 count = *(s32*)((u8*)fn_801F856C() + 0x1008);
    for (s32 i = 0, off = 0; i < count; i++, off += 4) {
        Actor* other = *(Actor**)((u8*)fn_801F856C() + off + 8);
        if (other != NULL && other->field_1A0 == 0x4D525441) {
            if (other != NULL) {
                fn_801F31C4(self, boxA);
                fn_801F31C4(other, boxB);
                f32 x0 = boxA[0];
                if (x0 <= boxB[0]) {
                    x0 = boxB[0];
                }
                f32 y0 = boxA[1];
                if (y0 <= boxB[1]) {
                    y0 = boxB[1];
                }
                f32 x1 = boxA[2];
                if (x1 >= boxB[2]) {
                    x1 = boxB[2];
                }
                f32 y1 = boxA[3];
                if (y1 >= boxB[3]) {
                    y1 = boxB[3];
                }
                bool overlap = false;
                if (x1 >= x0 && y1 >= y0) {
                    overlap = true;
                }
                if (overlap && other->field_0C.z <= 0.0f) {
                    hit = *(s32*)((u8*)other + 0x198);
                    break;
                }
            }
        }
    }
    return hit;
}
