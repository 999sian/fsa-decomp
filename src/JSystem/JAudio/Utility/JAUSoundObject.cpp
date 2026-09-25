#include "JSystem/JAudio/JAUSoundObject.h"

#include "JSystem/JAudio/Interface/JAISeMgr.h"
#include "JSystem/JAudio/Interface/JAISound.h"
#include "JSystem/JAudio/Interface/JAISoundHandles.h"
#include "JSystem/JAudio/JASFakeMatch2.h"
#include "JSystem/JUtility/JUTAssert.h"

JAUSoundObject::JAUSoundObject(JGeometry::TVec3f *pos, u8 numHandles, JKRHeap *heap) : JAISoundHandles(new (heap, 0) JAISoundHandle[numHandles], numHandles) {
    mReservedHandles = 0;
    mSoundPos = pos;
    mIsActive = true;
}

JAUSoundObject::~JAUSoundObject() {
    dispose();
    delete[] handles_;
}

void JAUSoundObject::dispose() {
    for (u32 i = 0; i < numHandles_; i++) {
        if (handles_[i]) {
            if (stopOK(handles_[i])) {
                handles_[i]->stop();
            }
            else {
                handles_[i].releaseSound();
            }
        }
    }
    mIsActive = false;
}

bool JAUSoundObject::stopOK(JAISoundHandle &) {
    return true;
}

void JAUSoundObject::process() {
    if (mIsActive) {
        setPos(*mSoundPos);
    }
}

JAISoundHandle *JAUSoundObject::startSound(JAISoundID soundID) {
    if (!mIsActive) {
        return NULL;
    }
    JAISoundStarter *starter = JAISoundStarter::getInstance();
    JAISoundHandle *handle = getHandleSoundID(soundID);
    if (handle == NULL) {
        handle = getFreeHandleNotReserved();
    }
    if (handle == NULL) {
        handle = getLowPrioSound(soundID);
    }

    if (handle) {
        starter->startSound(soundID, handle, mSoundPos);
    }
    return handle;
}

JAISoundHandle *JAUSoundObject::startSound(JAISoundID soundID, u8 index) {
    if (!mIsActive) {
        return NULL;
    }
    JAISoundHandle *handle = &handles_[index];
    JAISoundStarter::getInstance()->startSound(soundID, handle, mSoundPos);
    return handle;
}

JAISoundHandle *JAUSoundObject::startLevelSound(JAISoundID soundID) {
    if (!mIsActive) {
        return NULL;
    }
    JAISeMgr *seMgr = JAISeMgr::getInstance();
    JAISoundHandle *handle = getHandleSoundID(soundID);

    if (handle) {
        (*handle)->updateLifeTime(1);
    }
    else {
        handle = getFreeHandleNotReserved();
        if (!handle) {
            handle = getLowPrioSound(soundID);
        }
        if (handle) {
            seMgr->startSound(soundID, handle, mSoundPos);
            if (*handle) {
                (*handle)->setLifeTime(1, false);
            }
        }
    }
    return handle;
}

JAISoundHandle *JAUSoundObject::startLevelSound(JAISoundID soundID, u8 index) {
    if (!mIsActive) {
        return NULL;
    }
    JAISeMgr *seMgr = JAISeMgr::getInstance();
    JAISoundHandle *handle = getHandleSoundID(soundID);

    if (handle) {
        (*handle)->updateLifeTime(1);
        return handle;
    }

    JAISoundHandle *indexHandle = &handles_[index];
    seMgr->startSound(soundID, indexHandle, mSoundPos);
    if (*indexHandle) {
        (*indexHandle)->setLifeTime(1, false);
    }
    return indexHandle;
}

void JAUSoundObject::stopSound(JAISoundID soundID, u32 fadeTime) {
    JAISoundHandle *handle = getHandleSoundID(soundID);
    if (handle) {
        (*handle)->stop(fadeTime);
    }
}

JAISoundHandle *JAUSoundObject::getLowPrioSound(JAISoundID soundID) {
    JAISoundInfo *soundInfo = JAISoundInfo::getInstance();
    u32 curHighestPrio = 0xffff;
    JAISoundHandle *ret = NULL;
    for (s32 i = 0; i < numHandles_; i++) {
        if (mReservedHandles & (1 << i))
            continue;

        JAISoundHandle &handle = (*this)[i];
        u32 prio = soundInfo->getPriority(handle->soundID_);
        if (prio < curHighestPrio) {
            curHighestPrio = prio;
            ret = &handle;
        }
    }

    if (soundInfo->getPriority(soundID) >= curHighestPrio) {
        return ret;
    }
    return NULL;
}

JAISoundHandle *JAUSoundObject::getFreeHandleNotReserved() {
    for (s32 i = 0; i < numHandles_; i++) {
        if (mReservedHandles & (1 << i))
            continue;

        JAISoundHandle &handle = (*this)[i];
        if (!handle) {
            return &handle;
        }
    }
    return NULL;
}
