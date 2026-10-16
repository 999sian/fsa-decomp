#include "JSystem/JUtility/JUTFader.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" void __dt__10JSUPtrListFv(void *, int);
extern "C" void *fn_8008CAEC(void *self, short flags) {
    if (self != 0) {
        __dt__10JSUPtrListFv(self, 0);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}

void JUTFader::control()
{
    if (0 <= mEStatus && mEStatus-- == 0)
        mStatus = mNextStatus;

    if (mStatus == Status_In)
        return;

    switch (mStatus)
    {
    case Status_Out:
        mColor.a = 0xFF;
        break;
    case Status_FadingIn:
        mColor.a = 0xFF - ((++mTicksRun * 0xFF) / mTicksTarget);
        if (mTicksRun >= mTicksTarget)
            mStatus = Status_In;
        break;
    case Status_FadingOut:
        mColor.a = ((++mTicksRun * 0xFF) / mTicksTarget);
        if (mTicksRun >= mTicksTarget)
            mStatus = Status_Out;
        break;
    }
    draw();
}

