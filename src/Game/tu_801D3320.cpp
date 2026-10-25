#include "types.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include <float.h>

typedef JGeometry::TVec3<f32> Vec3f;

extern "C" void* GetCurrentSlotPtr(void* thisPtr);
extern "C" u8 fn_800FD894(void* ring, s32 id, u8* buf, s32 n);
extern "C" u8 fn_800FD5E8(void* ring, u8 i);
extern "C" u8 fn_800FD4C0(void* ring, u8 a, u8 b);
extern "C" s32 fn_800FE25C(void* ring, u8 i);
extern "C" Vec3f fn_800FE294(void* ring, u8 i);
extern "C" u8 fn_801CCBD0(const void* pos, s32 room);
extern "C" u8 fn_801CCB1C(const void* pos, s32 room);
extern "C" u8 fn_801CF888(void* this_, void* a, void* b, s32 room);
extern "C" u8 fn_801CAEF4(char* this_, void* p, s32 room);
extern "C" u8 fn_801C976C(char* this_);
extern "C" s32 fn_801CD664(s32 n);
extern "C" void* lbl_8053AAF8;
extern "C" f32 lbl_8053F080;
extern "C" f32 lbl_8053F084;
extern "C" f32 lbl_8053F088;
extern "C" f32 lbl_8053F08C;
extern "C" f32 lbl_8053F090;
extern "C" f32 lbl_8053F094;
extern "C" f32 lbl_8053F098;

static inline u8 tu801D3320_isFree(Vec3f* pos, s32 room) {
    u8 ok = 1;
    if (fn_801CCBD0(pos, room) || fn_801CCB1C(pos, room)) {
        ok = 0;
    }
    return ok;
}

static inline f32 tu801D3320_invSqrt(f32 x) {
    if (x <= lbl_8053F084) {
        return x;
    }
    f32 y = __frsqrte(x);
    y = lbl_8053F094 * y * (lbl_8053F098 - x * (y * y));
    return y;
}

static inline void tu801D3320_normalize(Vec3f& v) {
    f32 sq = v.squared();
    if (sq <= lbl_8053F088 * FLT_EPSILON) {
        return;
    }
    v.scale(tu801D3320_invSqrt(sq));
}

void __sinit_tu_801D3320_cpp(void) {}
