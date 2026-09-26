// tu_801E4A18: .text 0x801E4A18-0x801E4D54 (damped sine oscillator helper)
#include "types.h"
#include "JSystem/JMath/JMath.h"

struct DampedWave {
    f32 mValue;
    u16 mCount;
    u16 mPeriod;
    s16 mStep;
    f32 mAmp;
    f32 mDecay;

    void reset() {
        mValue = 0.0f;
        mCount = 0;
        mPeriod = 0;
        mStep = 0;
        mAmp = 0.0f;
        mDecay = 0.0f;
    }
};

extern "C" f32 fn_801E4A18(DampedWave* w) {
    if (w->mCount != 0) {
        w->mCount--;
        if (w->mCount == 0) {
            w->mValue = 0.0f;
            w->mCount = 0;
            w->mPeriod = 0;
            w->mStep = 0;
            w->mAmp = 0.0f;
            w->mDecay = 0.0f;
        } else {
            w->mAmp -= w->mDecay;
            w->mValue = w->mAmp * JMath::sincosTable_.mTable[(u16)(s16)(w->mStep * (w->mPeriod - w->mCount)) >> 5].first;
        }
    } else {
        w->mValue = 0.0f;
    }
    return w->mValue;
}

extern "C" void fn_801E4AB0(DampedWave* w, f32 amp, u16 period, s16 step) {
    if (period != 0) {
        w->mValue = 0.0f;
        w->mPeriod = period;
        w->mCount = period;
        w->mStep = step;
        w->mAmp = amp;
        w->mDecay = w->mAmp * (1.0f / w->mPeriod);
    }
}

extern "C" void fn_801E4B0C(DampedWave* w) {
    w->reset();
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
