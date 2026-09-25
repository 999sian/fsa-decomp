#include <dolphin/os.h>
#include "JSystem/J3D/J3DDrawMtxData.h"
#include "JSystem/J3D/J3DTypes.h"
#include "JSystem/J3D/J3DVertexBuffer.h"
#include "JSystem/J3D/J3DVertexData.h"
#include "JSystem/J3D/J3DSys.h"
#include "JSystem/JKernel/JKRHeap.h"
#include <string.h>

/**
 * @note Address: 0x8005EB80
 * @note Size: 0x68
 */
J3DVertexData::J3DVertexData()
{
	mVtxNum         = 0;
	mNormNum        = 0;
	mColorNum       = 0;
	mTexCoordNum    = 0;
	mPacketNum      = 0;
	mVtxAttrFmtList = nullptr;
	mVtxPos         = nullptr;
	mVtxNorm        = nullptr;
	mVtxNBT         = nullptr;
	mVtxColor[0]    = nullptr;
	mVtxColor[1]    = nullptr;
	for (int i = 0; i < 8; i++) {
		mVtxTexCoord[i] = nullptr;
	}
	mVtxPosFrac = 0;
	mVtxPosType = GX_F32;
	mVtxNrmFrac = 0;
	mVtxNrmType = GX_F32;
}

/**
 * @note Address: 0x8005EBE8
 * @note Size: 0x60
 */
void J3DVertexBuffer::setVertexData(J3DVertexData* data)
{
	mVtxData     = data;
	mVtxPos[0]   = data->mVtxPos;
	mVtxNorm[0]  = data->mVtxNorm;
	mVtxColor[0] = data->mVtxColor[0];

	mVtxPos[1]   = nullptr;
	mVtxNorm[1]  = nullptr;
	mVtxColor[1] = nullptr;

	mTransformedVtxPos[0]  = data->mVtxPos;
	mTransformedVtxNorm[0] = data->mVtxNorm;
	mTransformedVtxPos[1]  = nullptr;
	mTransformedVtxNorm[1] = nullptr;

	mCurrentVtxPos   = mVtxPos[0];
	mCurrentVtxNorm  = mVtxNorm[0];
	mCurrentVtxColor = mVtxColor[0];
}

/**
 * @note Address: 0x8005EC48
 * @note Size: 0x58
 */
void J3DVertexBuffer::init()
{
	mVtxData = nullptr;

	mVtxPos[1]   = nullptr;
	mVtxPos[0]   = nullptr;
	mVtxNorm[1]  = nullptr;
	mVtxNorm[0]  = nullptr;
	mVtxColor[1] = nullptr;
	mVtxColor[0] = nullptr;

	mTransformedVtxPos[1]  = nullptr;
	mTransformedVtxPos[0]  = nullptr;
	mTransformedVtxNorm[1] = nullptr;
	mTransformedVtxNorm[0] = nullptr;

	mCurrentVtxPos   = nullptr;
	mCurrentVtxNorm  = nullptr;
	mCurrentVtxColor = nullptr;

	mCurrentVtxPos   = mVtxPos[0];
	mCurrentVtxNorm  = mVtxNorm[0];
	mCurrentVtxColor = mVtxColor[0];
}

/**
 * @note Address: 0x8005ECA0
 * @note Size: 0x3C
 */
J3DVertexBuffer::~J3DVertexBuffer()
{
}

/**
 * @note Address: 0x8005ECDC
 * @note Size: 0x24
 */
void J3DVertexBuffer::setArray() const
{
	j3dSys.mVtxPos   = mCurrentVtxPos;
	j3dSys.mVtxNorm  = mCurrentVtxNorm;
	j3dSys.mVtxColor = mCurrentVtxColor;
}

/**
 * @note Address: 0x8005EE28
 * @note Size: 0x14
 */
J3DDrawMtxData::J3DDrawMtxData()
    : mCount(0)
    , mDrawMtxFlag(nullptr)
    , mDrawMtxIdx(nullptr)
{
}

/**
 * @note Address: 0x8005EE3C
 * @note Size: 0x3C
 */
J3DDrawMtxData::~J3DDrawMtxData()
{
}
