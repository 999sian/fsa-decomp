#include "JSystem/J3D/J3DTypes.h"
#include "JSystem/J3D/J3DTexMtx.h"
#include "JSystem/J3D/J3DInd.h"
#include "JSystem/J3D/J3DPE.h"
#include "types.h"

// Paired-single block copies (JMath::gekko_ps_copyN in later JSystem).
static inline void J3DPSCopy3(register void* dst, register const void* src)
{
	register f32 src0;
	register f32 src1;
	asm {
		psq_l src0, 0(src), 0, 0
		lfs src1, 8(src)
		psq_st src0, 0(dst), 0, 0
		stfs src1, 8(dst)
	}
}

static inline void J3DPSCopy6(register void* dst, register const void* src)
{
	register f32 src0;
	register f32 src1;
	register f32 src2;
	asm {
		psq_l src0, 0(src), 0, 0
		psq_l src1, 8(src), 0, 0
		psq_l src2, 16(src), 0, 0
		psq_st src0, 0(dst), 0, 0
		psq_st src1, 8(dst), 0, 0
		psq_st src2, 16(dst), 0, 0
	}
}

static inline void J3DPSCopy16(register void* dst, register const void* src)
{
	register f32 src0;
	register f32 src1;
	register f32 src2;
	register f32 src3;
	register f32 src4;
	register f32 src5;
	register f32 src6;
	register f32 src7;
	asm {
		psq_l src0, 0(src), 0, 0
		psq_l src1, 8(src), 0, 0
		psq_l src2, 16(src), 0, 0
		psq_l src3, 24(src), 0, 0
		psq_l src4, 32(src), 0, 0
		psq_l src5, 40(src), 0, 0
		psq_l src6, 48(src), 0, 0
		psq_l src7, 56(src), 0, 0
		psq_st src0, 0(dst), 0, 0
		psq_st src1, 8(dst), 0, 0
		psq_st src2, 16(dst), 0, 0
		psq_st src3, 24(dst), 0, 0
		psq_st src4, 32(dst), 0, 0
		psq_st src5, 40(dst), 0, 0
		psq_st src6, 48(dst), 0, 0
		psq_st src7, 56(dst), 0, 0
	}
}

J3DTexMtxInfo& J3DTexMtxInfo::operator=(J3DTexMtxInfo const& other)
{
	mProjection = other.mProjection;
	mInfo       = other.mInfo;
	J3DPSCopy3(&mCenter, &other.mCenter);
	mSRT = other.mSRT;
	J3DPSCopy16(&mEffectMtx, &other.mEffectMtx);
	return *this;
}

J3DIndTexMtxInfo& J3DIndTexMtxInfo::operator=(J3DIndTexMtxInfo const& other)
{
	J3DPSCopy6(mOffsetMtx, other.mOffsetMtx);
	mScaleExp = other.mScaleExp;
	return *this;
}

J3DFogInfo& J3DFogInfo::operator=(const J3DFogInfo& other)
{
	mType      = other.mType;
	mAdjEnable = other.mAdjEnable;
	mCenter    = other.mCenter;
	mStartZ    = other.mStartZ;
	mEndZ      = other.mEndZ;
	mNearZ     = other.mNearZ;
	mFarZ      = other.mFarZ;
	mColor.r   = other.mColor.r;
	mColor.g   = other.mColor.g;
	mColor.b   = other.mColor.b;
	mColor.a   = other.mColor.a;
	for (int i = 0; i < 10; i++) {
		mFogAdjTable[i] = other.mFogAdjTable[i];
	}
	return *this;
}

J3DNBTScaleInfo& J3DNBTScaleInfo::operator=(const J3DNBTScaleInfo& other)
{
	mHasScale = other.mHasScale;
	mScale.x  = other.mScale.x;
	mScale.y  = other.mScale.y;
	mScale.z  = other.mScale.z;
	return *this;
}
