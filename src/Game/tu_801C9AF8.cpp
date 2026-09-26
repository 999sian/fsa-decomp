// Game TU 801C9AF8-801CB270 (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"


extern "C" bool fn_801CAED4(void* thisObj, s32 value) {
	s32 v = *(s32*)((char*)thisObj + 0x560);
	return v != 4 && v != value;
}

extern "C" u8 v17__5ActorFv(void* this_, s32 room, const f32* pos);
extern const f32 lbl_8053EF38;

static inline u8 tuCheckAt(void* this_, s32 room, const f32* pos, f32 y, f32 x) {
    f32 z = pos[2];
    JGeometry::TVec3f v(x, y, z);
    return v17__5ActorFv(this_, room, &v.x);
}

// near-match (98%): float register assignment differs
extern "C" BOOL fn_801CAEF4(void* this_, const f32* pos, s32 room) {
    BOOL r = FALSE;
    if (v17__5ActorFv(this_, room, pos)
        || tuCheckAt(this_, room, pos, pos[1] - lbl_8053EF38, pos[0] - lbl_8053EF38)
        || tuCheckAt(this_, room, pos, pos[1] - lbl_8053EF38, lbl_8053EF38 + pos[0])
        || tuCheckAt(this_, room, pos, lbl_8053EF38 + pos[1], pos[0] - lbl_8053EF38)
        || tuCheckAt(this_, room, pos, lbl_8053EF38 + pos[1], lbl_8053EF38 + pos[0])) {
        r = TRUE;
    }
    return r;
}

extern const f32 lbl_8053EF20;
extern const f32 lbl_8053EF2C;
extern "C" u8 fn_801C53C4(void* p);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F82CC(void* mgr, void* self, u8 room, f32 r);
extern "C" char* fn_801F666C(void* mgr, s32 id);
extern "C" u8 fn_801F37AC(void* p, s32 a, JGeometry::TVec3f* d, s32 b, s32 c, s32 e);
extern "C" void fn_801C3B7C(void* p, s32 st);

extern "C" u8 fn_801CA0F8(char* p) {
    if (*(f32*)(p + 0x68) - *(f32*)(p + 0x60) <= lbl_8053EF20
        || *(f32*)(p + 0x6c) - *(f32*)(p + 0x64) <= lbl_8053EF20
        || fn_801C53C4(p)) {
        return 0;
    }
    u8 r = 0;
    s32 id = fn_801F82CC(fn_801F856C(), p, *(u8*)(p + 0x195), lbl_8053EF2C);
    if (id >= 0 && id != *(s32*)(p + 0x198)) {
        char* a = fn_801F666C(fn_801F856C(), id);
        if (a != 0) {
            switch (*(s32*)(a + 0x1a0)) {
            case 'SWBM':
            case 'FLME':
                return 0;
            }
            JGeometry::TVec3f d(*(JGeometry::TVec3f*)(p + 0xc));
            d.sub(*(JGeometry::TVec3f*)(a + 0x3c));
            r = fn_801F37AC(p, 0, &d, 0, *(s32*)(a + 0x168), *(s32*)(a + 0x110));
            if (r) {
                *(u8*)(a + 0x164) = 1;
                if (*(s32*)(p + 0x248) == 0x10) {
                    *(u32*)(p + 0x230) |= 0x800000;
                } else {
                    fn_801C3B7C(p, 0x10);
                }
            }
        }
    }
    return r;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
