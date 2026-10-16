#ifndef JAUDIO_JAUSOUNDMGR_H
#define JAUDIO_JAUSOUNDMGR_H

#include "JSystem/JAudio/Interface/JAISeMgr.h"
#include "JSystem/JAudio/Interface/JAISeqMgr.h"
#include "JSystem/JAudio/Interface/JAISound.h"
#include "JSystem/JAudio/Interface/JAIStreamMgr.h"

class JAUSoundMgr : public JAISoundStarter {
public:
    JAUSoundMgr();
#ifdef JAUSOUNDMGR_DTOR_OUT_OF_LINE
    ~JAUSoundMgr();
#else
    ~JAUSoundMgr() {}
#endif

    bool startSound(JAISoundID soundID, JAISoundHandle *handlePtr, const JGeometry::TVec3f *pos);
    void calc();
    void mixOut();
    void stop();

    // FABRICATED {
    JAISeMgr& getSeMgr() {
        return mSeMgr;
    }
    // } FABRICATED

private:
    JAISeMgr mSeMgr;
    JAISeqMgr mSeqMgr;
    JAIStreamMgr mStreamMgr;
};

#endif
