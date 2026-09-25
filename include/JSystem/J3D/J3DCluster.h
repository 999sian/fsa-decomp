#ifndef _JSYSTEM_J3D_J3DCLUSTER_H
#define _JSYSTEM_J3D_J3DCLUSTER_H

#include "JSystem/J3D/J3DTypes.h"
#include "types.h"

struct J3DDeformer;
struct J3DClusterKey;
struct J3DClusterVertex;

struct J3DCluster {
    J3DDeformer* getDeformer() { return mDeformer; }
    void setDeformer(J3DDeformer* deformer) { mDeformer = deformer; }

    f32 mMaxAngle;                     // _00
    f32 mMinAngle;                     // _04
    J3DClusterKey* mClusterKey;        // _08
    u8 mFlags;                         // _0C
    u8 _0D[3];                         // _0D
    u16 mKeyNum;                       // _10
    u16 mPosNum;                       // _12
    u16 mNrmNum;                       // _14
    u16 mClusterVertexNum;             // _16
    u16* mPosDstIdx;                   // _18
    J3DClusterVertex* mClusterVertex;  // _1C
    J3DDeformer* mDeformer;            // _20
};

struct J3DClusterKey {
    u16 mPosNum;    // _00
    u16 mNrmNum;    // _02
    u16* mPosFlag;  // _04
    u16* mNrmFlag;  // _08
};

struct J3DClusterVertex {
    u16 mNum;       // _00
    u16* mSrcIdx;   // _04
    u16* mDstIdx;   // _08
};

#endif
