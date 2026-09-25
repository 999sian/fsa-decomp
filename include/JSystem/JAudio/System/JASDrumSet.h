#ifndef JAUDIO_JASDRUMSET_H
#define JAUDIO_JASDRUMSET_H

#include "JSystem/JAudio/System/JASInst.h"
#include "JSystem/JKernel/JKRHeap.h"

struct JASDrumSet : public JASInst
{
    class TPerc
    {
    public:
        TPerc();
        void setVolume(f32 vol) { mVolume = vol; }
        void setPitch(f32 pitch) { mPitch = pitch; }
        void setPan(f32 pan) { mPan = pan; }

        void setVeloRegionCount(u32 count, JKRHeap *heap);
        JASVelo *getVeloRegion(int index);
        void appendEffect(JASInstEffectLink *link);
        void setRelease(u32 release);

        f32 mVolume;                     // 00
        f32 mPitch;                      // 04
        f32 mPan;                        // 08
        u16 mRelease;                    // 0c
        JASInstEffectLink *mEffectList;  // 10
        u32 mVelomapCount;               // 14
        JASVelo *mVelomap;               // 18
    };

    JASDrumSet();
    virtual ~JASDrumSet();
    virtual bool getParam(int, int, JASInstParam *) const;
    void setPerc(int index, JASDrumSet::TPerc *perc);
    virtual u32 getType() const { return 'PERC'; }

    static const u32 sPercCount = 0x80;
    TPerc *mPercArray[sPercCount]; // 04
};

#endif
