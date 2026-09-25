#include "JSystem/JAudio/System/JASDrumSet.h"
#include "JSystem/JAudio/System/JASCalc.h"
#include "JSystem/JAudio/System/JASChannel.h"
#include "JSystem/JAudio/System/JASInst.h"
#include "JSystem/JUtility/JUTAssert.h"

JASDrumSet::JASDrumSet() {
    JASCalc::bzero(mPercArray, sizeof(mPercArray));
}

JASDrumSet::~JASDrumSet() {}

bool JASDrumSet::getParam(int key, int veloKey, JASInstParam *param) const {
    if (key >= sPercCount) {
        return false;
    }

    TPerc *perc = mPercArray[key];
    if (perc == NULL) {
        return false;
    }

    param->_14 = 0;
    param->_24 = 1;
    param->mVolume = perc->mVolume;
    param->mPitch = perc->mPitch;
    param->mPan = perc->mPan;
    param->_26 = perc->mRelease;

    static JASOscillator::Data osc;

    osc.mTarget = 0;
    osc._04 = 1.0f;
    osc.mTable = NULL;
    osc.rel_table = NULL;
    osc.mScale = 1.0f;
    osc._14 = 0.0f;

    static JASOscillator::Data *oscp = &osc;

    param->_1c = &oscp;
    param->_20 = 1;

    for (JASInstEffectLink *link = perc->mEffectList; link; link = link->mNext) {
        link->mEffect->effect(key, veloKey, param);
    }

    for (u32 i = 0; i < perc->mVelomapCount; i++) {
        JASVelo *velo = &perc->mVelomap[i];
        if (veloKey <= velo->_0) {
            param->mVolume *= velo->_8;
            param->mPitch *= velo->_c;
            param->_18 = velo->_4;
            return true;
        }
    }

    return false;
}

void JASDrumSet::setPerc(int index, JASDrumSet::TPerc *pperc) {
    mPercArray[index] = pperc;
}

JASDrumSet::TPerc::TPerc() {
    mVolume = 1.0f;
    mPitch = 1.0f;
    mPan = 0.5f;
    mRelease = 1000;
    mEffectList = NULL;
    mVelomapCount = 0;
    mVelomap = NULL;
}

void JASDrumSet::TPerc::setVeloRegionCount(u32 count, JKRHeap *pHeap) {
    delete[] mVelomap;
    mVelomap = new (pHeap, 0) JASVelo[count];
    mVelomapCount = count;
}

JASVelo *JASDrumSet::TPerc::getVeloRegion(int index) {
    return &mVelomap[index];
}

void JASDrumSet::TPerc::appendEffect(JASInstEffectLink *link) {
    JASInstEffectLink *p = mEffectList;
    if (p == NULL) {
        mEffectList = link;
        return;
    }
    while (p->mNext) {
        p = p->mNext;
    }
    p->mNext = link;
}

void JASDrumSet::TPerc::setRelease(u32 release) {
    mRelease = release;
}

#ifdef MATCHING
template <>
JASMemPool_MultiThreaded<JASChannel> JASPoolAllocObject_MultiThreaded<JASChannel>::memPool_;
#endif
