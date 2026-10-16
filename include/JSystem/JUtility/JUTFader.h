#ifndef _JUTFADER_H
#define _JUTFADER_H

#include "JSystem/JGeometry.h"
#include "JSystem/JUtility/TColor.h"
#include "JSystem/JUtility/JUTVideo.h"
#include "types.h"

struct JUTFader
{
    enum EStatus
    {
        Status_Out = 0,
        Status_In = 1,
        Status_FadingIn = 2,
        Status_FadingOut = 3
    };

    JUTFader(int, int, int, int, JUtility::TColor);

    virtual ~JUTFader() {}                   // _08 (weak)
    virtual bool startFadeIn(int duration);  // _0C
    virtual bool startFadeOut(int duration); // _10
    virtual void draw();                     // _14

    void control();

    // unused/inlined:
    void start(int);
    void setStatus(EStatus, int);
    void setResetState(bool reset) { mResetting = reset; }

    EStatus getStatus() const { return mStatus; }

    void setColor(JUtility::TColor color) { mColor.set(color.r, color.g, color.b, mColor.a); }

    // _00 VTBL
    EStatus mStatus;            // _04 - current status
    u16 mTicksTarget;           // _08 - ticks (calls to control()) to run a fade in/out for
    u16 mTicksRun;              // _0A - ticks the current fade has run
    JUtility::TColor mColor;    // _0C - color of fade
    bool mResetting;            // _10 - probably exclusive to mkdd, holds true when starting the fadeout for reset, sets back to false when fading in
    u8 _11[3];                  // padding
    u8 _14[0xC];                // _14 - ortho box to render within (TBox2f?)
    int mEStatus;               // _20 - countdown before the next status is applied
    EStatus mNextStatus;        // _24 - status to switch to when the countdown ends
};

#endif