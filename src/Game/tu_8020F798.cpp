#include "JSystem/JGeometry/Vec.h"
struct Vec3f { float x, y, z; };
struct TblEnt { char pad[0xc]; char* p; char pad2[4]; };
extern TblEnt lbl_8046A238[];
extern "C" void fn_8020F80C(void* self, char* p);
extern "C" u16 fn_8022461C(void* pos, u32 room);
extern "C" void fn_801F0E34(void* self, u32 id, s32 flag);
extern "C" void* fn_8013CC50(u32 id, void* pos, u16 kind, s32 a, f32 scale, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801CB7A0(void* obj);
extern "C" void fn_801CB71C(void* a, void* b, s32 c, s32 d);

extern "C" void fn_8020F798(char* self)
{
    JGeometry::TVec3f v(*(JGeometry::TVec3f*)(self + 0xc));
    fn_8020F80C(self, lbl_8046A238[*(int*)(self + 0x350)].p + *(int*)(self + 0x280));
    ((JGeometry::TVec3f*)(self + 0xc))->set(v);
}

extern "C" void fn_8020FADC(char* self)
{
    bool bVar2 = false;

    if (fn_8022461C(self + 0xc, *(u32*)(self + 4)) == 0x39) {
        bool bVar1 = false;
        if (*(u8*)(self + 0xc4) == 0 && *(f32*)(self + 0x14) <= 0.0f) {
            if (__fabsf(*(f32*)(self + 0xc) - *(f32*)(self + 0x18)) > 0.001f ||
                __fabsf(*(f32*)(self + 0x10) - *(f32*)(self + 0x1c)) > 0.001f) {
                bVar1 = true;
            }
        }
        if (bVar1) {
            fn_801F0E34(self, 0x4007f, 0);
            if (*(void**)(self + 0x358) == 0) {
                *(void**)(self + 0x358) = fn_8013CC50(*(u32*)(self + 4), self + 0xc, 0x4d2, 0, 1.0f, 0, 0, 0, 1);
            }
        } else {
            bVar2 = true;
        }
    } else {
        bVar2 = true;
    }
    if (bVar2) {
        void* obj = *(void**)(self + 0x358);
        if (obj != 0 && !(*(u32*)((char*)obj + 0xf4) & 0x40)) {
            fn_801CB7A0(obj);
        }
    }
    if (*(void**)(self + 0x358) != 0) {
        fn_801CB71C(self + 0x358, self + 0xc, 0, 0);
    }
}

