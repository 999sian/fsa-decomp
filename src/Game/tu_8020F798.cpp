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
