#ifndef JAUDIO_JAUSOUNDOBJECT_H
#define JAUDIO_JAUSOUNDOBJECT_H

#include "JSystem/JAudio/Interface/JAISound.h"
#include "JSystem/JAudio/Interface/JAISoundHandles.h"
#include "JSystem/JGeometry.h"
#include "JSystem/JGeometry/Vec.h"
#include "types.h"

// FSA's JAUSoundObject differs from mkdd's: it has an "active" flag that
// dispose() clears, index-based startSound/startLevelSound overloads and
// stopSound. The reserved-handle mask moved to 0x10. There is no
// JAUDopplerSoundObject in the FSA binary.
class JAUSoundObject : public JAISoundHandles
{
public:
    JAUSoundObject(JGeometry::TVec3f *, u8, JKRHeap *);
    ~JAUSoundObject();

    virtual void process();
    virtual void dispose();
    virtual bool stopOK(JAISoundHandle &);
    virtual JAISoundHandle *startSound(JAISoundID);
    virtual JAISoundHandle *startSound(JAISoundID, u8);
    virtual JAISoundHandle *startLevelSound(JAISoundID);
    virtual JAISoundHandle *startLevelSound(JAISoundID, u8);

    void stopSound(JAISoundID, u32);
    JAISoundHandle *getLowPrioSound(JAISoundID);
    JAISoundHandle *getFreeHandleNotReserved();

    u8 mIsActive;                     // 0C
    u32 mReservedHandles;             // 10, bit i set = handle i is reserved
    JGeometry::TVec3<f32> *mSoundPos; // 14
};

#endif
