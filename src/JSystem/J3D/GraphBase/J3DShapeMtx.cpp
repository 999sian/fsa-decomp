#include <dolphin/gx.h>
#include <dolphin/mtx.h>
#include "JSystem/J3D/J3DGD.h"
#include "JSystem/J3D/J3DMaterial.h"
#include "JSystem/J3D/J3DModel.h"
#include "JSystem/J3D/J3DMtxBuffer.h"
#include "JSystem/J3D/J3DPacket.h"
#include "JSystem/J3D/J3DShape.h"
#include "JSystem/J3D/J3DSys.h"
#include "JSystem/J3D/J3DTexGenBlock.h"
#include "JSystem/J3D/J3DTexMtx.h"
#include "JSystem/J3D/J3DTransform.h"
#include "types.h"

J3DShapeMtx::LoadMtxIndxFunction J3DShapeMtx::sMtxLoadPipeline[4] = {
	&J3DShapeMtx::loadMtxIndx_PNGP,
	&J3DShapeMtx::loadMtxIndx_PCPU,
	&J3DShapeMtx::loadMtxIndx_NCPU,
	&J3DShapeMtx::loadMtxIndx_PNCPU,
};
J3DShapeMtxConcatView::LoadMtxConcatViewFunction J3DShapeMtxConcatView::sMtxLoadPipeline[4] = {
	&J3DShapeMtxConcatView::loadMtxConcatView_PNGP,
	&J3DShapeMtxConcatView::loadMtxConcatView_PCPU,
	&J3DShapeMtxConcatView::loadMtxConcatView_NCPU,
	&J3DShapeMtxConcatView::loadMtxConcatView_PNCPU,
};

J3DShapeMtxConcatView::LoadMtxConcatViewFunction J3DShapeMtxConcatView::sMtxLoadLODPipeline[4] = {
	&J3DShapeMtxConcatView::loadMtxConcatView_PNGP_LOD,
	&J3DShapeMtxConcatView::loadMtxConcatView_PCPU,
	&J3DShapeMtxConcatView::loadMtxConcatView_NCPU,
	&J3DShapeMtxConcatView::loadMtxConcatView_PNCPU,
};

u32 J3DShapeMtx::sCurrentPipeline;
u8* J3DShapeMtx::sCurrentScaleFlag;
bool J3DShapeMtx::sNBTFlag;
bool J3DShapeMtx::sLODFlag;
u32 J3DShapeMtx::sTexMtxLoadType;
MtxP J3DShapeMtxConcatView::sMtxPtrTbl[2];
J3DTexGenBlock* J3DDifferedTexMtx::sTexGenBlock;
J3DTexMtxObj* J3DDifferedTexMtx::sTexMtxObj;

u16 J3DShapeMtx::sMtxLoadCache[10];

/**
 * @note Address: 0x80086104
 * @note Size: 0x3C
 */
void J3DShapeMtx::resetMtxLoadCache()
{
	sMtxLoadCache[9] = 0xFFFF;
	sMtxLoadCache[8] = 0xFFFF;
	sMtxLoadCache[7] = 0xFFFF;
	sMtxLoadCache[6] = 0xFFFF;
	sMtxLoadCache[5] = 0xFFFF;
	sMtxLoadCache[4] = 0xFFFF;
	sMtxLoadCache[3] = 0xFFFF;
	sMtxLoadCache[2] = 0xFFFF;
	sMtxLoadCache[1] = 0xFFFF;
	sMtxLoadCache[0] = 0xFFFF;
}

/**
 * @note Address: 0x80086140
 * @note Size: 0x44
 */
void J3DShapeMtx::loadMtxIndx_PNGP(int slot, u16 indx) const
{
	J3DFifoLoadIndx(GX_CMD_LOAD_INDX_A, indx, 0xB000 | ((u16)(slot * 0x0C)));
	J3DFifoLoadIndx(GX_CMD_LOAD_INDX_B, indx, 0x8000 | ((u16)((slot * 0x09) + 0x400)));
}

/**
 * @note Address: 0x80086184
 * @note Size: 0x60
 */
void J3DShapeMtx::loadMtxIndx_PCPU(int p1, u16 p2) const
{
	J3DFifoLoadPosMtxImm(*j3dSys.mShapePacket->mBaseMtxPtr, p1 * 3);
	j3dSys.loadNrmMtxIndx(p1, p2);
}

/**
 * @note Address: 0x800861E4
 * @note Size: 0x4C
 */
void J3DShapeMtx::loadMtxIndx_NCPU(int p1, u16 p2) const
{
	j3dSys.loadPosMtxIndx(p1, p2);
	J3DFifoLoadNrmMtxImm(*j3dSys.mShapePacket->mBaseMtxPtr, p1 * 3);
}

/**
 * @note Address: 0x80086230
 * @note Size: 0x58
 */
void J3DShapeMtx::loadMtxIndx_PNCPU(int p1, u16 p2) const
{
	J3DFifoLoadPosMtxImm(*j3dSys.mShapePacket->mBaseMtxPtr, p1 * 3);
	J3DFifoLoadNrmMtxImm(*j3dSys.mShapePacket->mBaseMtxPtr, p1 * 3);
}

/**
 * @note Address: 0x80086288
 * @note Size: 0x588
 */
void J3DDifferedTexMtx::loadExecute(const Mtx param_0)
{
	static Mtx qMtx  = { { 0.5f, 0.0f, 0.5f, 0.0f }, { 0.0f, -0.5f, 0.5f, 0.0f }, { 0.0f, 0.0f, 1.0f, 0.0f } };
	static Mtx qMtx2 = { { 0.5f, 0.0f, 0.0f, 0.5f }, { 0.0f, -0.5f, 0.0f, 0.5f }, { 0.0f, 0.0f, 1.0f, 0.0f } };

	Mtx* mtx;
	Mtx sp_e8;
	Mtx44 sp_a8, sp_68;

	J3DTexGenBlock* tex_gen_block = sTexGenBlock;
	J3DTexMtxObj* tex_mtx_obj     = sTexMtxObj;

	J3DTexMtxInfo* tex_mtx_info_1;
	int tex_gen_type;
	J3DTexMtx* tex_mtx_2;

	u16 tex_mtx_num = tex_mtx_obj->getNumTexMtx();

	if (j3dSys.checkFlag(J3DSysFlag_PostTexMtx)) {
		for (u16 i = 0; i < tex_mtx_num; i++) {
			tex_gen_type = tex_gen_block->getTexCoord(i)->getTexGenType();
			if (tex_gen_type == 1 || tex_gen_type == 0) {
				tex_mtx_2      = tex_gen_block->getTexMtx(i);
				tex_mtx_info_1 = &tex_mtx_2->getTexMtxInfo();

				u32 sp_4c = tex_mtx_info_1->mInfo & 0x3f;
				switch (sp_4c) {
				case 3:
				case 9: {
					mtx = &tex_mtx_obj->getMtx(i);
					break;
				}
				case 1:
				case 6:
				case 7: {
					mtx = &tex_mtx_obj->getMtx(i);
					break;
				}
				case 2:
				case 8: {
					PSMTXInverse(j3dSys.mViewMtx, sp_e8);
					PSMTXConcat(tex_mtx_obj->getMtx(i), sp_e8, sp_e8);
					mtx = &sp_e8;
					break;
				}
				case 5: {
					J3DTexMtxInfo* tex_mtx_info_2 = &tex_mtx_2->getTexMtxInfo();
					u32 sp_44                     = (u32)(tex_mtx_info_2->mInfo & 0x80) >> 7;
					if (sp_44 == 0) {
						J3DGetTextureMtxOld(tex_mtx_info_2->mSRT, tex_mtx_info_2->mCenter, sp_68);
					} else if (sp_44 == 1) {
						J3DGetTextureMtxMayaOld(tex_mtx_info_2->mSRT, sp_68);
					}
					J3DMtxProjConcat(sp_68, tex_mtx_obj->getEffectMtx(i), sp_e8);
					PSMTXInverse(j3dSys.mViewMtx, sp_a8);
					PSMTXConcat(sp_e8, sp_a8, sp_e8);
					sp_e8[0][3] = sp_e8[1][3] = sp_e8[2][3] = 0.0f;
					mtx                                     = &sp_e8;
					break;
				}
				case 11: {
					J3DTexMtxInfo* tex_mtx_info_2 = &tex_mtx_2->getTexMtxInfo();
					u32 sp_3c                     = (u32)(tex_mtx_info_2->mInfo & 0x80) >> 7;
					if (sp_3c == 0) {
						J3DGetTextureMtx(tex_mtx_info_2->mSRT, tex_mtx_info_2->mCenter, sp_68);
					} else if (sp_3c == 1) {
						J3DGetTextureMtxMaya(tex_mtx_info_2->mSRT, sp_68);
					}

					PSMTXConcat(sp_68, qMtx, sp_68);
					J3DMtxProjConcat(sp_68, tex_mtx_obj->getEffectMtx(i), sp_e8);
					PSMTXInverse(j3dSys.mViewMtx, sp_a8);
					PSMTXConcat(sp_e8, sp_a8, sp_e8);
					sp_e8[0][3] = sp_e8[1][3] = sp_e8[2][3] = 0.0f;
					mtx                                     = &sp_e8;
					break;
				}
				case 10: {
					J3DTexMtxInfo* tex_mtx_info_2 = &tex_mtx_2->getTexMtxInfo();
					u32 sp_34                     = (u32)(tex_mtx_info_2->mInfo & 0x80) >> 7;
					if (sp_34 == 0) {
						J3DGetTextureMtx(tex_mtx_info_2->mSRT, tex_mtx_info_2->mCenter, sp_68);
					} else if (sp_34 == 1) {
						J3DGetTextureMtxMaya(tex_mtx_info_2->mSRT, sp_68);
					}

					PSMTXConcat(sp_68, qMtx2, sp_68);
					J3DMtxProjConcat(sp_68, tex_mtx_obj->getEffectMtx(i), sp_e8);
					PSMTXInverse(j3dSys.mViewMtx, sp_a8);
					PSMTXConcat(sp_e8, sp_a8, sp_e8);
					sp_e8[0][3] = sp_e8[1][3] = sp_e8[2][3] = 0.0f;
					mtx                                     = &sp_e8;
					break;
				}
				case 0:
				case 4:
				default: {
					mtx = &tex_mtx_obj->getMtx(i);
				}
				}
				GXLoadTexMtxImm(*mtx, i * 3 + 0x40, GX_MTX3x4);
			}
		}
	} else {
		for (u16 i = 0; i < tex_mtx_num; i++) {
			int tex_gen_type = tex_gen_block->getTexCoord(i)->getTexGenType();
			if (tex_gen_type == 1 || tex_gen_type == 0) {
				J3DTexMtx* tex_mtx = tex_gen_block->getTexMtx(i);
				tex_mtx_info_1     = &tex_mtx->getTexMtxInfo();

				u32 tex_gen_src = tex_mtx_info_1->mInfo & 0x3f;
				switch (tex_gen_src) {
				case 3:
				case 9:
					PSMTXConcat(tex_mtx_obj->getMtx(i), param_0, sp_e8);
					mtx = &sp_e8;
					break;
				case 1:
				case 6:
				case 7:
					PSMTXCopy(param_0, sp_a8);
					sp_a8[0][3] = sp_a8[1][3] = sp_a8[2][3] = 0.0f;
					PSMTXConcat(tex_mtx_obj->getMtx(i), sp_a8, sp_e8);
					mtx = &sp_e8;
					break;
				case 2:
				case 8:
					mtx = &tex_mtx_obj->getMtx(i);
					break;
				case 5: {
					J3DTexMtxInfo* tex_mtx_info_2 = &tex_mtx->getTexMtxInfo();
					u32 sp_24                     = (u32)(tex_mtx_info_2->mInfo & 0x80) >> 7;
					if (sp_24 == 0) {
						J3DGetTextureMtxOld(tex_mtx_info_2->mSRT, tex_mtx_info_2->mCenter, sp_68);
					} else if (sp_24 == 1) {
						J3DGetTextureMtxMayaOld(tex_mtx_info_2->mSRT, sp_68);
					}

					J3DMtxProjConcat(sp_68, tex_mtx_obj->getEffectMtx(i), sp_e8);
					PSMTXInverse(j3dSys.mViewMtx, sp_a8);
					PSMTXConcat(sp_e8, sp_a8, sp_e8);
					PSMTXConcat(sp_e8, param_0, sp_e8);
					sp_e8[0][3] = sp_e8[1][3] = sp_e8[2][3] = 0.0f;
					mtx                                     = &sp_e8;
					break;
				}
				case 11: {
					J3DTexMtxInfo* tex_mtx_info_2 = &tex_mtx->getTexMtxInfo();
					u32 sp_18                     = (u32)(tex_mtx_info_2->mInfo & 0x80) >> 7;
					if (sp_18 == 0) {
						J3DGetTextureMtx(tex_mtx_info_2->mSRT, tex_mtx_info_2->mCenter, sp_68);
					} else if (sp_18 == 1) {
						J3DGetTextureMtxMaya(tex_mtx_info_2->mSRT, sp_68);
					}

					PSMTXConcat(sp_68, qMtx, sp_68);
					J3DMtxProjConcat(sp_68, tex_mtx_obj->getEffectMtx(i), sp_e8);
					PSMTXInverse(j3dSys.mViewMtx, sp_a8);
					PSMTXConcat(sp_e8, sp_a8, sp_e8);
					PSMTXConcat(sp_e8, param_0, sp_e8);
					sp_e8[0][3] = sp_e8[1][3] = sp_e8[2][3] = 0.0f;
					mtx                                     = &sp_e8;
					break;
				}
				case 10: {
					J3DTexMtxInfo* tex_mtx_info_2 = &tex_mtx->getTexMtxInfo();
					u32 sp_10                     = (u32)(tex_mtx_info_2->mInfo & 0x80) >> 7;
					if (sp_10 == 0) {
						J3DGetTextureMtx(tex_mtx_info_2->mSRT, tex_mtx_info_2->mCenter, sp_68);
					} else if (sp_10 == 1) {
						J3DGetTextureMtxMaya(tex_mtx_info_2->mSRT, sp_68);
					}

					PSMTXConcat(sp_68, qMtx2, sp_68);
					J3DMtxProjConcat(sp_68, tex_mtx_obj->getEffectMtx(i), sp_e8);
					PSMTXInverse(j3dSys.mViewMtx, sp_a8);
					PSMTXConcat(sp_e8, sp_a8, sp_e8);
					PSMTXConcat(sp_e8, param_0, sp_e8);
					sp_e8[0][3] = sp_e8[1][3] = sp_e8[2][3] = 0.0f;
					mtx                                     = &sp_e8;
					break;
				}
				case 0:
				case 4:
				default: {
					mtx = &tex_mtx_obj->getMtx(i);
					break;
				}
				}
				GXLoadTexMtxImm(*mtx, i * 3 + 30, (GXTexMtxType)tex_mtx_info_1->mProjection);
			}
		}
	}
}

/**
 * @note Address: 0x80086810
 * @note Size: 0xA8
 */
void J3DShapeMtxConcatView::loadMtxConcatView_PNGP(int slot, u16 drawIdx) const
{
	Mtx mtx;
	PSMTXConcat(*j3dSys.getShapePacket()->getBaseMtxPtr(), j3dSys.getModelDrawMtx(drawIdx), mtx);
	J3DDifferedTexMtx::load(mtx);
	J3DFifoLoadPosMtxImm(mtx, slot * 3);
	loadNrmMtx(slot, drawIdx, mtx);
}

/**
 * @note Address: 0x800868B8
 * @note Size: 0xB4
 */
void J3DShapeMtxConcatView::loadMtxConcatView_PCPU(int slot, u16 drawIdx) const
{
	Mtx mtx;
	PSMTXConcat(*j3dSys.getShapePacket()->getBaseMtxPtr(), j3dSys.getModelDrawMtx(drawIdx), mtx);
	J3DDifferedTexMtx::load(mtx);
	J3DFifoLoadPosMtxImm(*j3dSys.getShapePacket()->getBaseMtxPtr(), slot * 3);
	loadNrmMtx(slot, drawIdx, mtx);
}

/**
 * @note Address: 0x8008696C
 * @note Size: 0xA8
 */
void J3DShapeMtxConcatView::loadMtxConcatView_NCPU(int slot, u16 drawIdx) const
{
	Mtx mtx;
	PSMTXConcat(*j3dSys.getShapePacket()->getBaseMtxPtr(), j3dSys.getModelDrawMtx(drawIdx), mtx);
	J3DDifferedTexMtx::load(mtx);
	J3DFifoLoadPosMtxImm(mtx, slot * 3);

	J3DFifoLoadNrmMtxImm(*j3dSys.getShapePacket()->getBaseMtxPtr(), slot * 3);
	if (sTexMtxLoadType == 0x2000) {
		J3DFifoLoadNrmMtxToTexMtx(*j3dSys.getShapePacket()->getBaseMtxPtr(), slot * 3 + 0x1E);
	}
}

/**
 * @note Address: 0x80086A14
 * @note Size: 0xB4
 */
void J3DShapeMtxConcatView::loadMtxConcatView_PNCPU(int slot, u16 drawIdx) const
{
	if (J3DDifferedTexMtx::sTexGenBlock) {
		Mtx mtx;
		PSMTXConcat(*j3dSys.getShapePacket()->getBaseMtxPtr(), j3dSys.getModelDrawMtx(drawIdx), mtx);
		J3DDifferedTexMtx::loadExecute(mtx);
	}
	J3DFifoLoadPosMtxImm(*j3dSys.getShapePacket()->getBaseMtxPtr(), slot * 3);
	J3DFifoLoadNrmMtxImm(*j3dSys.getShapePacket()->getBaseMtxPtr(), slot * 3);
	if (sTexMtxLoadType == 0x2000) {
		J3DFifoLoadNrmMtxToTexMtx(*j3dSys.getShapePacket()->getBaseMtxPtr(), slot * 3 + 0x1E);
	}
}

/**
 * @note Address: 0x80086AC8
 * @note Size: 0xD4
 */
void J3DShapeMtxConcatView::loadMtxConcatView_PNGP_LOD(int slot, u16 drawIdx) const
{
	Mtx mtx;
	PSMTXConcat(*j3dSys.getShapePacket()->getBaseMtxPtr(), j3dSys.getModelDrawMtx(drawIdx), mtx);
	PSMTXConcat(mtx, j3dSys.mModel->getModelData()->getInvJointMtx(drawIdx), mtx);
	J3DDifferedTexMtx::load(mtx);
	J3DFifoLoadPosMtxImm(mtx, slot * 3);
	loadNrmMtx(slot, drawIdx, mtx);
}

/**
 * @note Address: 0x80086B9C
 * @note Size: 0x5C
 */
void J3DShapeMtx::load() const
{
	LoadMtxIndxFunction function = sMtxLoadPipeline[sCurrentPipeline];
	(this->*function)(0, mUseMtxIndex);
}

/**
 * @note Address: 0x80086BF8
 * @note Size: 0x64
 */
void J3DShapeMtx::calcNBTScale(const Vec& scale, Mtx33* srcArray, Mtx33* dstArray)
{
	J3DPSMtx33Copy(srcArray[mUseMtxIndex], dstArray[mUseMtxIndex]);
	J3DScaleNrmMtx33(dstArray[mUseMtxIndex], scale);
}

/**
 * @note Address: 0x80086C5C
 * @note Size: 0xD4
 */
void J3DShapeMtxConcatView::load() const
{
	sMtxPtrTbl[0]                      = j3dSys.getModel()->mMtxBuffer->mUserAnmMtx[0];
	sMtxPtrTbl[1]                      = j3dSys.getModel()->mMtxBuffer->getWeightAnmMtx(0);
	LoadMtxConcatViewFunction function = sMtxLoadPipeline[sCurrentPipeline];
	j3dSys.mModelDrawMtx               = (Mtx*)sMtxPtrTbl[j3dSys.mModel->mModelData->mJointTree.mMtxData.mDrawMtxFlag[mUseMtxIndex]];
	GXSetArray(GX_POS_MTX_ARRAY, j3dSys.mModelDrawMtx, sizeof(Mtx));
	(this->*function)(0, j3dSys.mModel->mModelData->mJointTree.mMtxData.mDrawMtxIdx[mUseMtxIndex]);
}

/**
 * @note Address: 0x80086D30
 * @note Size: 0x124
 */
void J3DShapeMtxConcatView::loadNrmMtx(int slot, u16 drawIdx, Mtx nrmMtx) const
{
	if (sCurrentScaleFlag[drawIdx] == 1) {
		if (sTexMtxLoadType == 0x2000) {
			J3DFifoLoadNrmMtxToTexMtx(nrmMtx, GX_TEXMTX0);
		}
		if (!sNBTFlag) {
			J3DFifoLoadNrmMtxImm(nrmMtx, 0);
		} else {
			Mtx33 mtx;
			Vec* scale = j3dSys.getNBTScale();
			J3DPSMtx33CopyFrom34(nrmMtx, mtx);
			J3DScaleNrmMtx33(mtx, *scale);
			J3DFifoLoadNrmMtxImm3x3(mtx, 0);
		}
	} else {
		Mtx33 mtx;
		J3DPSCalcInverseTranspose(nrmMtx, mtx);
		if (sTexMtxLoadType == 0x2000) {
			J3DFifoLoadNrmMtxToTexMtx3x3(mtx, GX_TEXMTX0);
		}
		if (!sNBTFlag) {
			J3DFifoLoadNrmMtxImm3x3(mtx, 0);
		} else {
			Vec* scale = j3dSys.getNBTScale();
			J3DScaleNrmMtx33(mtx, *scale);
			J3DFifoLoadNrmMtxImm3x3(mtx, 0);
		}
	}
}

/**
 * @note Address: 0x80086E54
 * @note Size: 0xAC
 */
void J3DShapeMtxMulti::load() const
{
	LoadMtxIndxFunction function = sMtxLoadPipeline[sCurrentPipeline];
	u16 count                    = mUseMtxNum;
	for (int i = 0; i < count; i++) {
		if (mUseMtxIndexTable[i] != 0xFFFF) {
			(this->*function)(i, mUseMtxIndexTable[i]);
		}
	}
}

/**
 * @note Address: 0x80086F00
 * @note Size: 0xB0
 */
void J3DShapeMtxMulti::calcNBTScale(const Vec& scale, Mtx33* srcArray, Mtx33* dstArray)
{
	u16 count = mUseMtxNum;
	for (int i = 0; i < count; i++) {
		if (mUseMtxIndexTable[i] != 0xFFFF) {
			J3DPSMtx33Copy(srcArray[mUseMtxIndexTable[i]], dstArray[mUseMtxIndexTable[i]]);
			J3DScaleNrmMtx33(dstArray[mUseMtxIndexTable[i]], scale);
		}
	}
}

/**
 * @note Address: 0x80086FB0
 * @note Size: 0x1EC
 */
void J3DShapeMtxMultiConcatView::load() const
{
	sMtxPtrTbl[0] = j3dSys.getModel()->mMtxBuffer->mUserAnmMtx[0];
	sMtxPtrTbl[1] = j3dSys.getModel()->mMtxBuffer->getWeightAnmMtx(0);
	if (!sLODFlag) {
		LoadMtxConcatViewFunction func = sMtxLoadPipeline[sCurrentPipeline];
		int use_mtx_num                = mUseMtxNum;
		for (int i = 0; i < use_mtx_num; i++) {
			u16 use_mtx_index = mUseMtxIndexTable[i];
			if (use_mtx_index != 0xffff) {
				u16 draw_mtx_index = j3dSys.getModel()->getModelData()->mJointTree.getDrawMtxIndex(use_mtx_index);
				u8 draw_mtx_flag   = j3dSys.getModel()->getModelData()->mJointTree.getDrawMtxFlag(use_mtx_index);
				j3dSys.setModelDrawMtx((Mtx*)sMtxPtrTbl[draw_mtx_flag]);
				(this->*func)(i, draw_mtx_index);
			}
		}
	} else {
		u16* important_mtx_indices = j3dSys.getModel()->getModelData()->mJointTree.getWEvlpImportantMtxIndex();
		j3dSys.setModelDrawMtx((Mtx*)sMtxPtrTbl[0]);
		int use_mtx_num = mUseMtxNum;
		for (int i = 0; i < use_mtx_num; i++) {
			u32 current_pipeline           = sCurrentPipeline;
			LoadMtxConcatViewFunction func = sMtxLoadLODPipeline[current_pipeline];
			u16 use_mtx_index              = mUseMtxIndexTable[i];
			if (use_mtx_index != 0xffff) {
				u16 important_mtx_index = important_mtx_indices[use_mtx_index];
				if (important_mtx_index != sMtxLoadCache[i]) {
					u8 draw_mtx_flag = j3dSys.getModel()->getModelData()->mJointTree.getDrawMtxFlag(use_mtx_index);
					if (draw_mtx_flag == 0) {
						func = sMtxLoadPipeline[current_pipeline];
					}
					(this->*func)(i, important_mtx_index);
					sMtxLoadCache[i] = important_mtx_index;
				}
			}
		}
	}
}

/**
 * @note Address: 0x8008719C
 * @note Size: 0x138
 */
void J3DShapeMtxMultiConcatView::loadNrmMtx(int slot, u16 drawIdx, Mtx nrmMtx) const
{
	Mtx33 mtx1, mtx2;
	if (sCurrentScaleFlag[drawIdx] == 1) {
		if (sTexMtxLoadType == 0x2000) {
			J3DFifoLoadNrmMtxToTexMtx(nrmMtx, slot * 3 + GX_TEXMTX0);
		}
		if (!sNBTFlag) {
			J3DFifoLoadNrmMtxImm(nrmMtx, slot * 3);
		} else {
			Vec* nbt_scale = j3dSys.getNBTScale();
			J3DPSMtx33CopyFrom34(nrmMtx, mtx1);
			J3DScaleNrmMtx33(mtx1, *nbt_scale);
			J3DFifoLoadNrmMtxImm3x3(mtx1, 0);
		}
	} else {
		J3DPSCalcInverseTranspose(nrmMtx, mtx2);
		if (sTexMtxLoadType == 0x2000) {
			J3DFifoLoadNrmMtxToTexMtx3x3(mtx2, slot * 3 + GX_TEXMTX0);
		}
		if (!sNBTFlag) {
			J3DFifoLoadNrmMtxImm3x3(mtx2, slot * 3);
		} else {
			Vec* nbt_scale = j3dSys.getNBTScale();
			J3DScaleNrmMtx33(mtx2, *nbt_scale);
			J3DFifoLoadNrmMtxImm3x3(mtx2, slot * 3);
		}
	}
}

/**
 * @note Address: 0x800872D4
 * @note Size: 0x134
 */
void J3DShapeMtxBBoardConcatView::load() const
{
	Mtx v1;
	u16 v2 = j3dSys.mModel->mModelData->mJointTree.mMtxData.mDrawMtxIdx[mUseMtxIndex];
	if (j3dSys.mModel->mModelData->mJointTree.mMtxData.mDrawMtxFlag[mUseMtxIndex] == 0) {
		PSMTXConcat(j3dSys.mViewMtx, j3dSys.mModel->mMtxBuffer->mUserAnmMtx[v2], v1);
	} else {
		PSMTXConcat(j3dSys.mViewMtx, j3dSys.mModel->mMtxBuffer->mWeightEnvelopeMatrices[v2], v1);
	}
	J3DCalcBBoardMtx(v1);
	J3DFifoLoadPosMtxImm(v1, 0);
	v1[0][0] = 1.0f / v1[0][0];
	v1[1][1] = 1.0f / v1[1][1];
	v1[2][2] = 1.0f / v1[2][2];
	v1[0][3] = 0.0f;
	v1[1][3] = 0.0f;
	v1[2][3] = 0.0f;
	if (sNBTFlag == false) {
		J3DFifoLoadNrmMtxImm(v1, 0);
	} else {
		J3DScaleNrmMtx(v1, *j3dSys.mNBTScale);
		J3DFifoLoadNrmMtxImm(v1, 0);
	}
}

/**
 * @note Address: 0x80087408
 * @note Size: 0x13C
 */
void J3DShapeMtxYBBoardConcatView::load() const
{
	Mtx v1;
	u16 v2 = j3dSys.mModel->mModelData->mJointTree.mMtxData.mDrawMtxIdx[mUseMtxIndex];
	if (j3dSys.mModel->mModelData->mJointTree.mMtxData.mDrawMtxFlag[mUseMtxIndex] == 0) {
		PSMTXConcat(j3dSys.mViewMtx, j3dSys.mModel->mMtxBuffer->mUserAnmMtx[v2], v1);
	} else {
		PSMTXConcat(j3dSys.mViewMtx, j3dSys.mModel->mMtxBuffer->mWeightEnvelopeMatrices[v2], v1);
	}
	J3DCalcYBBoardMtx(v1);
	J3DFifoLoadPosMtxImm(v1, 0);
	if (sCurrentScaleFlag[mUseMtxIndex] == 1) {
		if (sNBTFlag == false) {
			J3DFifoLoadNrmMtxImm(v1, 0);
		} else {
			J3DScaleNrmMtx(v1, *j3dSys.mNBTScale);
			J3DFifoLoadNrmMtxImm(v1, 0);
		}
	} else {
		Mtx33 v3;
		J3DPSCalcInverseTranspose(v1, v3);
		if (sNBTFlag == false) {
			J3DFifoLoadNrmMtxImm3x3(v3, 0);
		} else {
			J3DScaleNrmMtx33(v3, *j3dSys.mNBTScale);
			J3DFifoLoadNrmMtxImm3x3(v3, 0);
		}
	}
}

// this doesn't seem to be used anywhere, and this file doesn't have any unused functions?
static u8 mtxCache[20] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};
