#include "JSystem/JGeometry/Vec.h"
struct Vec3f { float x, y, z; };
struct TblEnt { char pad[0xc]; char* p; char pad2[4]; };
extern TblEnt lbl_8046A238[];
extern "C" void fn_8020F80C(void* self, char* p);

extern "C" void fn_8020F798(char* self)
{
    JGeometry::TVec3f v(*(JGeometry::TVec3f*)(self + 0xc));
    fn_8020F80C(self, lbl_8046A238[*(int*)(self + 0x350)].p + *(int*)(self + 0x280));
    ((JGeometry::TVec3f*)(self + 0xc))->set(v);
}
