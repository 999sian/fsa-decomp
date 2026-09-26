// TU 0x8021FDB8-0x802201D8.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

typedef JGeometry::TVec3<f32> Vec3f;

extern "C" void* fn_801F856C(void);
extern "C" u8* fn_801F666C(void* mgr, s32 handle);
extern "C" bool fn_801E1D9C(void* this_);

// NonMatching: retail schedules "lwz r31, 0x2bc(r3)" before the r30 save.
extern "C" void fn_8021FDB8(u8* this_) {
    s32 handle = *(s32*)(this_ + 0x2bc);
    u8* child;
    if (handle >= 0 && (child = fn_801F666C(fn_801F856C(), handle)) != NULL) {
    f32 dz = 0.0f;
    switch (*(u32*)(this_ + 0x280)) {
    case 0:
    case 3:
    case 6:
        dz = 1.0f;
        break;
    case 2:
    case 5:
        dz = -1.0f;
        break;
    }
    Vec3f pos;
    pos.z = *(f32*)(this_ + 0x14) + dz;
    pos.y = *(f32*)(this_ + 0x10);
    pos.x = *(f32*)(this_ + 0xc);
    switch ((s32)(*(u32*)(child + 0x90) & 0xff)) {
    case 0:
    case 1:
        pos.z -= 3.0f;
        if (!fn_801E1D9C(this_)) {
            switch (*(s32*)(this_ + 0x98)) {
            case 0:
                pos.x += 3.0f;
                break;
            case 1:
                pos.x -= 3.0f;
                break;
            }
        }
        break;
    case 2:
    case 3:
        pos.z -= 5.0f;
        if (!fn_801E1D9C(this_)) {
            switch (*(s32*)(this_ + 0x98)) {
            case 0:
                pos.x += 3.0f;
                break;
            case 1:
                pos.x -= 3.0f;
                break;
            }
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        pos.z -= 13.0f;
        if (!fn_801E1D9C(this_)) {
            switch (*(s32*)(this_ + 0x98)) {
            case 0:
                pos.x += 3.0f;
                break;
            case 1:
                pos.x -= 3.0f;
                break;
            }
        }
        break;
    }
    *(Vec3f*)(child + 0xc) = pos;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804CE8CC[0x94];
