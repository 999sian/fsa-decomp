#include "JSystem/JAudio/System/JASCalc.h"
#include "JSystem/JAudio/System/JASChannel.h"
#include "JSystem/JAudio/System/JASInst.h"
#include "JSystem/JUtility/JUTAssert.h"

JASBasicInst::JASBasicInst() {
    mVolume = 1.0f;
    mPitch = 1.0f;
    mEffectList = NULL;
    mKeyRegionCount = 0;
    mKeymap = NULL;
    JASCalc::bzero(mOsc, sizeof(mOsc));
}

JASBasicInst::~JASBasicInst() {
    delete[] mKeymap;
}

bool JASBasicInst::getParam(int key, int veloKey, JASInstParam *instParam) const {
    instParam->_14 = 0;
    instParam->_24 = 0;
    instParam->_1c = (JASOscillator::Data **)&mOsc;
    instParam->_20 = 2;
    instParam->mVolume = mVolume;
    instParam->mPitch = mPitch;

    for (JASInstEffectLink *link = mEffectList; link; link = link->mNext) {
        link->mEffect->effect(key, veloKey, instParam);
    }

    const TKeymap *keyMap = NULL;
    for (u32 i = 0; i < mKeyRegionCount; i++) {
        if (key <= mKeymap[i].mHighKey) {
            keyMap = &mKeymap[i];
            break;
        }
    }
    if (!keyMap) {
        return false;
    }

    for (u32 j = 0; j < keyMap->mVeloRegionCount; j++) {
        const JASVelo *velo = keyMap->getVeloRegion(j);
        if (veloKey <= velo->_0) {
            instParam->mVolume *= velo->_8;
            instParam->mPitch *= velo->_c;
            instParam->_18 = velo->_4;
            return true;
        }
    }
    return false;
}

void JASBasicInst::setKeyRegionCount(u32 count, JKRHeap *pHeap) {
    delete[] mKeymap;
    mKeymap = new (pHeap, 0) TKeymap[count];
    mKeyRegionCount = count;
}

void JASBasicInst::appendEffect(JASInstEffectLink *link) {
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

void JASBasicInst::setOsc(int index, JASOscillator::Data *osc) {
    mOsc[index] = osc;
}

JASBasicInst::TKeymap *JASBasicInst::getKeyRegion(int index) {
    if (index >= mKeyRegionCount) {
        return NULL;
    }
    return &mKeymap[index];
}

JASBasicInst::TKeymap::~TKeymap() {
    delete[] mVelomap;
}

void JASBasicInst::TKeymap::setVeloRegionCount(u32 count, JKRHeap *pHeap) {
    delete[] mVelomap;
    mVelomap = new (pHeap, 0) JASVelo[count];
    mVeloRegionCount = count;
}

JASVelo *JASBasicInst::TKeymap::getVeloRegion(int index) {
    if (index >= mVeloRegionCount) {
        return NULL;
    }
    return &mVelomap[index];
}

JASVelo *JASBasicInst::TKeymap::getVeloRegion(int index) const {
    if (index >= mVeloRegionCount) {
        return NULL;
    }
    return &mVelomap[index];
}

#ifdef MATCHING
template <>
JASMemPool_MultiThreaded<JASChannel> JASPoolAllocObject_MultiThreaded<JASChannel>::memPool_;
#endif
