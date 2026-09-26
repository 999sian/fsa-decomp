// tu_801D2918: .text 0x801D2918-0x801D2C60 (knockback velocity helper)
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Util.h"
#include <float.h>

struct Knockback {
    s32 mTimer;
    JGeometry::TVec2<f32> mVel;
};

extern "C" BOOL fn_801D2918(Knockback* k) {
    BOOL done = FALSE;
    if (k->mTimer > 0) {
        k->mTimer--;
        k->mVel.x *= 0.78f;
        k->mVel.y *= 0.78f;
    }
    if (k->mTimer <= 0) {
        k->mTimer = 0;
        k->mVel.x = 0.0f;
        k->mVel.y = 0.0f;
        done = TRUE;
    }
    return done;
}

extern "C" void fn_801D2978(Knockback* k, const JGeometry::TVec2<f32>& a, const JGeometry::TVec2<f32>& b,
                            s32 timer, f32 speed) {
    k->mVel.set(a.x - b.x, a.y - b.y);
    k->mVel.normalize();
    k->mVel.scale(16.0f * speed);
    k->mTimer = timer;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
