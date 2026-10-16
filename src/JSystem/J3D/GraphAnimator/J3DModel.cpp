#include "JSystem/J3D/J3DDisplayListObj.h"
#include "JSystem/J3D/J3DModel.h"
#include "JSystem/J3D/J3DMtxBuffer.h"
#include "JSystem/J3D/J3DPacket.h"
#include "JSystem/J3D/J3DSys.h"
#include "JSystem/J3D/J3DTexGenBlock.h"
#include "JSystem/J3D/J3DTexMtx.h"
#include "JSystem/J3D/J3DTypes.h"
#include "JSystem/J3D/J3DSkinDeform.h"
#include "JSystem/J3D/J3DVtxColorCalc.h"
#include "JSystem/J3D/J3DTransform.h"
#include "JSystem/J3D/J3DMaterialAnm.h"
#include "JSystem/J3D/J3DJoint.h"
#include "dolphin/os.h"

void J3DModel::initialize()
{
	mModelData    = nullptr;
	mFlags        = 0;
	mDiffFlag     = 0;
	mCalcCallBack = nullptr;
	mUserArea     = 0;

	mModelScale.x = 1.0f;
	mModelScale.y = 1.0f;
	mModelScale.z = 1.0f;

	PSMTXIdentity(mPosMtx);
	PSMTXIdentity(mInternalView);

	mMtxBuffer    = nullptr;
	mMatPackets   = nullptr;
	mShapePackets = nullptr;
	mDeformData   = nullptr;
	mSkinDeform   = nullptr;
	mVtxColorCalc = nullptr;
	mUnkCalc1     = nullptr;
	mUnkCalc2     = nullptr;
}

int J3DModel::entryModelData(J3DModelData* pModelData, u32 mdlFlags, u32 mtxNum)
{
	int ret = JET_Success;

	mModelData = pModelData;
	mMtxBuffer = new J3DMtxBuffer();

	ret = mMtxBuffer->create(pModelData, mtxNum);
	if (ret != JET_Success) {
		return ret;
	}

	ret = createShapePacket(pModelData);
	if (ret != JET_Success) {
		return ret;
	}

	ret = createMatPacket(pModelData, mdlFlags);
	if (ret != JET_Success) {
		return ret;
	}

	mVertexBuffer.setVertexData(&pModelData->mVertexData);
	prepareShapePackets();

	if (mdlFlags & 0x1) {
		onFlag(0x1);
	}
	if (mdlFlags & 0x2) {
		onFlag(0x2);
	}
	if (mdlFlags & 0x10) {
		onFlag(0x10);
	}
	if (mdlFlags & 0x20000) {
		onFlag(0x20000);
	}
	if (mdlFlags & 0x40000) {
		onFlag(0x40000);
	}
	if (mdlFlags & 0x80000) {
		onFlag(0x80000);
	}
	if (mdlFlags & 0x4) {
		onFlag(0x4);
	}
	if (mdlFlags & 0x8) {
		onFlag(0x8);
	}

	return JET_Success;
}

int J3DModel::createShapePacket(J3DModelData* pModelData)
{
	if (pModelData->getShapeNum() != 0) {
		mShapePackets = new J3DShapePacket[pModelData->getShapeNum()];

		if (mShapePackets == nullptr) {
			return JET_OutOfMemory;
		}

		for (int i = 0; i < pModelData->getShapeNum(); i++) {
			mShapePackets[i].setShape(pModelData->getShapeNodePointer(i));
			mShapePackets[i].setModel(this);
		}
	}

	return JET_Success;
}

int J3DModel::createMatPacket(J3DModelData* pModelData, u32 mdlFlags)
{
	int ret = 0;

	if (pModelData->getMaterialNum() != 0) {
		mMatPackets = new J3DMatPacket[pModelData->getMaterialNum()];

		if (mMatPackets == nullptr) {
			return JET_OutOfMemory;
		}
	}

	u16 matNum = pModelData->getMaterialNum();
	for (u16 i = 0; i < matNum; i++) {
		J3DMaterial* materialNode   = pModelData->getMaterialNodePointer(i);
		J3DMatPacket* matPacket     = mMatPackets + i;
		J3DShapePacket* shapePacket = mShapePackets + materialNode->getShape()->getIndex();

		matPacket->setMaterial(materialNode);
		matPacket->setInitShapePacket(shapePacket);
		matPacket->addShapePacket(shapePacket);
		matPacket->setTexture(pModelData->getTexture());
		matPacket->setMaterialID(materialNode->mDiffFlag);

		if (pModelData->getModelDataType() == 1) {
			matPacket->lock();
		}

		if (mdlFlags & 0x20000) {
			J3DDisplayListObj* dlobj = materialNode->getSharedDisplayListObj();
			matPacket->setDisplayListObj(dlobj);
		} else {
			if (pModelData->getModelDataType() == 1) {
				if (mdlFlags & 0x40000) {
					J3DDisplayListObj* dlobj = materialNode->getSharedDisplayListObj();
					matPacket->setDisplayListObj(dlobj);
				} else {
					J3DDisplayListObj* dlobj = materialNode->getSharedDisplayListObj();
					ret                      = dlobj->single_To_Double();
					if (ret != JET_Success)
						return ret;

					matPacket->setDisplayListObj(dlobj);
				}
			} else if (mdlFlags & 0x80000) {
				if (mdlFlags & 0x40000) {
					ret = materialNode->newSingleSharedDisplayList(materialNode->countDLSize());
					if (ret != JET_Success)
						return ret;

					J3DDisplayListObj* dlobj = materialNode->getSharedDisplayListObj();
					matPacket->setDisplayListObj(dlobj);
				} else {
					ret = materialNode->newSharedDisplayList(materialNode->countDLSize());
					if (ret != JET_Success)
						return ret;

					J3DDisplayListObj* dlobj = materialNode->getSharedDisplayListObj();
					ret                      = dlobj->single_To_Double();
					if (ret != JET_Success)
						return ret;

					matPacket->setDisplayListObj(dlobj);
				}
			} else {
				if (mdlFlags & 0x40000) {
					ret = matPacket->newSingleDisplayList(materialNode->countDLSize());
					if (ret != JET_Success)
						return ret;
				} else {
					ret = matPacket->newDisplayList(materialNode->countDLSize());
					if (ret != JET_Success)
						return ret;
				}
			}
		}
	}

	return JET_Success;
}

void J3DModel::calcMaterial()
{
	j3dSys.setModel(this);

	if (checkFlag(4)) {
		j3dSys.onFlag(4);
	} else {
		j3dSys.offFlag(4);
	}

	if (checkFlag(8)) {
		j3dSys.onFlag(8);
	} else {
		j3dSys.offFlag(8);
	}

	mModelData->syncJ3DSysFlags();
	j3dSys.setTexture(mModelData->getTexture());

	u16 matNum = mModelData->getMaterialNum();
	for (u16 i = 0; i < matNum; i++) {
		j3dSys.setMatPacket(&mMatPackets[i]);

		J3DMaterial* material = mModelData->getMaterialNodePointer(i);
		if (material->getMaterialAnm() != nullptr) {
			material->getMaterialAnm()->calc(material);
		}

		material->calc(getAnmMtx(material->getJoint()->getJntNo()));
	}
}

void J3DModel::calcDiffTexMtx()
{
	j3dSys.setModel(this);

	u16 matNum = mModelData->getMaterialNum();
	for (u16 i = 0; i < matNum; i++) {
		j3dSys.setMatPacket(&mMatPackets[i]);
		J3DMaterial* materialNode = mModelData->getMaterialNodePointer(i);
		materialNode->calcDiffTexMtx(getAnmMtx(materialNode->getJoint()->getJntNo()));
	}

	for (u16 i = 0; i < getModelData()->getShapeNum(); i++) {
		J3DShapePacket* shapePacket = getShapePacket(i);
		J3DTexGenBlock* texGenBlock = mModelData->getShapeNodePointer(i)->getMaterial()->getTexGenBlock();

		for (u16 j = 0; (int)j < 8; j++) {
			J3DTexMtx* texMtxNode   = texGenBlock->getTexMtx(j);
			J3DTexMtxObj* texMtxObj = shapePacket->getTexMtxObj();
			if (texMtxNode != nullptr && texMtxObj != nullptr) {
				PSMTXCopy(texMtxNode->getMtx(), texMtxObj->mTexMtx[j]);
			}
		}
	}
}

void J3DModel::calcAnmMtx()
{
	j3dSys.setModel(this);

	if (checkFlag(2)) {
		getModelData()->getJointTree().calc(mMtxBuffer, j3dDefaultScale, j3dDefaultMtx);
	} else {
		getModelData()->getJointTree().calc(mMtxBuffer, mModelScale, mPosMtx);
	}
}

void J3DModel::calcWeightEnvelopeMtx()
{
	if (getModelData()->getWEvlpMtxNum() != 0 && !checkFlag(0x10)) {
		if (!getModelData()->checkFlag(0x100)) {
			mMtxBuffer->calcWeightEnvelopeMtx();
		}
	}
}

void J3DModel::update()
{
	calc();
	entry();
}

void J3DModel::calc()
{
	j3dSys.setModel(this);

	if (checkFlag(4)) {
		j3dSys.onFlag(4);
	} else {
		j3dSys.offFlag(4);
	}

	if (checkFlag(8)) {
		j3dSys.onFlag(8);
	} else {
		j3dSys.offFlag(8);
	}

	mModelData->syncJ3DSysFlags();
	mVertexBuffer.frameInit();

	if (mUnkCalc2 != nullptr) {
		mUnkCalc2->calc(mModelData);
	}

	if (mDeformData != nullptr) {
		mDeformData->deform(this);
	}

	if (mVtxColorCalc != nullptr) {
		mVtxColorCalc->calc(this);
	}

	if (mUnkCalc1 != nullptr) {
		mUnkCalc1->calc(this);
	}

	calcAnmMtx();
	calcWeightEnvelopeMtx();

	if (mSkinDeform != nullptr) {
		mSkinDeform->deform(this);
	}

	if (mCalcCallBack != nullptr) {
		mCalcCallBack(this, 0);
	}
}

void J3DModel::entry()
{
	j3dSys.setModel(this);

	if (checkFlag(4)) {
		j3dSys.onFlag(4);
	} else {
		j3dSys.offFlag(4);
	}

	if (checkFlag(8)) {
		j3dSys.onFlag(8);
	} else {
		j3dSys.offFlag(8);
	}

	mModelData->syncJ3DSysFlags();
	j3dSys.setTexture(mModelData->getTexture());

	for (u16 i = 0; i < mModelData->getJointNum(); i++) {
		J3DJoint* joint = mModelData->getJointNodePointer(i);
		if (joint->getMesh() != nullptr) {
			joint->entryIn();
		}
	}
}

void J3DModel::viewCalc()
{
	mMtxBuffer->swapDrawMtx();
	mMtxBuffer->swapNrmMtx();

	if (getModelData()->checkFlag(0x10)) {
		if (getMtxCalcMode() == 2) {
			J3DCalcViewBaseMtx(*j3dSys.getViewMtx(), mModelScale, mPosMtx, (MtxPtr)&mInternalView);
		}
	} else if (isCpuSkinningOn()) {
		if (getMtxCalcMode() == 2) {
			J3DCalcViewBaseMtx(*j3dSys.getViewMtx(), mModelScale, mPosMtx, (MtxPtr)&mInternalView);
		}
	} else if (checkFlag(4)) {
		mMtxBuffer->calcDrawMtx(getMtxCalcMode(), mModelScale, mPosMtx);
		calcNrmMtx();
		calcBumpMtx();
		DCStoreRangeNoSync(getDrawMtxPtr(), mModelData->getDrawMtxNum() * sizeof(Mtx));
		DCStoreRange(getNrmMtxPtr(), mModelData->getDrawMtxNum() * sizeof(Mtx33));
	} else if (checkFlag(8)) {
		mMtxBuffer->calcDrawMtx(getMtxCalcMode(), mModelScale, mPosMtx);
		calcBBoardMtx();
		DCStoreRange(getDrawMtxPtr(), mModelData->getDrawMtxNum() * sizeof(Mtx));
	} else {
		mMtxBuffer->calcDrawMtx(getMtxCalcMode(), mModelScale, mPosMtx);
		calcNrmMtx();
		calcBBoardMtx();
		calcBumpMtx();
		DCStoreRangeNoSync(getDrawMtxPtr(), mModelData->getDrawMtxNum() * sizeof(Mtx));
		DCStoreRange(getNrmMtxPtr(), mModelData->getDrawMtxNum() * sizeof(Mtx33));
	}

	prepareShapePackets();
}

void J3DModel::calcNrmMtx()
{
	mMtxBuffer->calcNrmMtx();
}

void J3DModel::calcBumpMtx()
{
	if (getModelData()->checkBumpFlag() == 1) {
		s32 bumpMtxIdx  = 0;
		u16 materialNum = getModelData()->getMaterialNum();

		for (u16 i = 0; i < (u32)materialNum; i++) {
			J3DMaterial* material = getModelData()->getMaterialNodePointer(i);
			if (material->getNBTScale()->mHasScale == TRUE) {
				material->getShape()->calcNBTScale(*material->getNBTScale()->getScale(), getNrmMtxPtr(), getBumpMtxPtr(bumpMtxIdx));
				DCStoreRange(getBumpMtxPtr(bumpMtxIdx), mModelData->getDrawMtxNum() * sizeof(Mtx33));
				bumpMtxIdx += 1;
			}
		}
	}
}

void J3DModel::calcBBoardMtx()
{
	if (getModelData()->checkBBoardFlag()) {
		mMtxBuffer->calcBBoardMtx();
	}
}

void J3DModel::prepareShapePackets()
{
	u16 shapeNum = mModelData->getShapeNum();

	for (u16 i = 0; i < shapeNum; i++) {
		J3DShape* shapeNode         = mModelData->getShapeNodePointer(i);
		J3DShapePacket* shapePacket = &mShapePackets[i];
		shapePacket->setMtxBuffer(mMtxBuffer);

		if (getMtxCalcMode() == 2) {
			shapePacket->setBaseMtxPtr(&mInternalView);
		} else {
			shapePacket->setBaseMtxPtr(j3dSys.getViewMtx());
		}
	}
}
