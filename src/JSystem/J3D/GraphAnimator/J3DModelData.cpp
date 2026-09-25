#include "JSystem/J3D/J3DDisplayListObj.h"
#include "JSystem/J3D/J3DMaterial.h"
#include "JSystem/J3D/J3DModel.h"
#include "JSystem/J3D/J3DSys.h"
#include "JSystem/J3D/J3DTevBlock.h"
#include "JSystem/J3D/J3DTypes.h"

/**
 * @note Address: 0x80083794
 * @note Size: 0x18
 */
void J3DModelData::clear()
{
	mBmd              = nullptr;
	mModelLoaderFlags = 0;
	mBumpFlag         = 0;
	mBillboardFlag    = 0;
}

/**
 * @note Address: 0x800837AC
 * @note Size: 0x80
 */
J3DModelData::J3DModelData()
    : mJointTree()
    , mMaterialTable()
    , mShapeTable()
    , mVertexData()
{
	clear();
}

/**
 * @note Address: 0x8008396C
 * @note Size: 0xC4
 */
void J3DModelData::indexToPtr()
{
	j3dSys.mTexture = getMaterialTable().getTexture();
	static int sInterruptFlag = OSDisableInterrupts();
	OSDisableScheduler();

	u32 count = getMaterialNum();
	for (u16 i = 0; i < count; i++) {
		J3DMaterial* mat = getMaterialNodePointer(i);

		GDCurrentDL currentDL;
		GDInitGDLObj(&currentDL, mat->getSharedDisplayListObj()->getDisplayList(0), mat->getSharedDisplayListObj()->getDisplayListSize());
		__GDSetCurrent(&currentDL);
		mat->getTevBlock()->indexToPtr();
	}

	__GDSetCurrent(nullptr);
	OSEnableScheduler();
	OSRestoreInterrupts(sInterruptFlag);
}

/**
 * @note Address: 0x80083B78
 * @note Size: 0x3C
 */
void J3DModelData::syncJ3DSysFlags() const
{
	if (mModelLoaderFlags & J3DMLF_UsePostTexMtx) {
		j3dSys.mFlags |= 0x40000000;
	} else {
		j3dSys.mFlags &= ~0x40000000;
	}
}
