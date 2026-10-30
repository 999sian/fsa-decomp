#define J3D_GX_COLOR_WORD_COPY
#include "JSystem/J3D/J3DMaterialFactory.h"
#include "JSystem/JSupport.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/J3D/J3DMaterial.h"
#include "JSystem/J3D/J3DColorBlock.h"
#include "JSystem/J3D/J3DTexGenBlock.h"
#include "JSystem/J3D/J3DTevBlock.h"
#include "JSystem/J3D/J3DInd.h"
#include "JSystem/J3D/J3DPE.h"

extern "C" J3DFog fn_800E0F84(const J3DMaterialFactory_v21* self, int idx);
extern "C" J3DBlend fn_800E1144(const J3DMaterialFactory_v21* self, int idx);
extern "C" J3DTexMtx* fn_800E0C1C(const J3DMaterialFactory_v21* self, int idx, int no);
extern "C" J3DTexCoord fn_800E0BBC(const J3DMaterialFactory_v21* self, int idx, int no);
extern "C" J3DTevOrder fn_800E0D3C(const J3DMaterialFactory_v21* self, int idx, int no);
// Packed tev konst colour returned by fn_800E0DF8 (word copies, sret).
typedef J3DGXColor TevKColorWord;
extern "C" TevKColorWord fn_800E0DF8(const J3DMaterialFactory_v21* self, int idx, int no);
struct TevColorWords {
	TevColorWords(u32 first, u32 second) { mWords[0] = first; mWords[1] = second; }
	operator const J3DGXColorS10&() const { return *(const J3DGXColorS10*)mWords; }
	u32 mWords[2];
};
extern "C" TevColorWords fn_800E0D88(const J3DMaterialFactory_v21* self, int idx, int no);
extern "C" u32 lbl_80543F10;
extern "C" u32 lbl_80543F14;
extern "C" TevKColorWord fn_800E0960(const J3DMaterialFactory_v21* self, int idx, int no);
extern "C" J3DColorChan fn_800E09F0(const J3DMaterialFactory_v21* self, int idx, int no);
extern "C" void* fn_800E1300(const void* base, const void* offset);
extern "C" void* fn_800CC040(const void* base, const void* offset);
extern "C" void* fn_800CC010(const void* base, const void* offset);
extern "C" void* fn_800CBFF8(const void* base, const void* offset);
extern "C" void* fn_800CBFE0(const void* base, const void* offset);
extern "C" void* fn_800CBFC8(const void* base, const void* offset);
extern "C" void* fn_800CBFB0(const void* base, const void* offset);
extern "C" void* fn_800CBF98(const void* base, const void* offset);
extern "C" void* fn_800CBF80(const void* base, const void* offset);
extern "C" void* fn_800CBF68(const void* base, const void* offset);
extern "C" void* fn_800CBF50(const void* base, const void* offset);
extern "C" void* fn_800CBF38(const void* base, const void* offset);
extern "C" void* fn_800CBF20(const void* base, const void* offset);
extern "C" void* fn_800CBF08(const void* base, const void* offset);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

J3DMaterialFactory_v21::J3DMaterialFactory_v21(const J3DMaterialBlock_v21& block)
{
	mMaterialNum = block.mNumMaterials;
	mInitData = (J3DMaterialInitData_v21*)fn_800E1300(&block, block.mMatEntryDataOffset);
	mMatRemapTable = JSUConvertOffsetToPtr<u16>(&block, block.mMatRemapTableOffset);
	mCullModeInfo = JSUConvertOffsetToPtr<GXCullMode>(&block, block.mCullModeInfoOffset);
	mColorData = JSUConvertOffsetToPtr<GXColor>(&block, block.mMatColorsOffset);
	mNumColorChans = JSUConvertOffsetToPtr<u8>(&block, block.mNumColorChansOffset);
	mColorChanInfo = (J3DColorChanInfo*)fn_800CC040(&block, block.mColorChanInfoOffset);
	mTexGenNums = JSUConvertOffsetToPtr<u8>(&block, block.mNumTexCoordsOffset);
	mTexCoordInfo = (J3DTexCoordInfo*)fn_800CC010(&block, block.mTexCoordInfoOffset);
	mTexCoord2Info = (J3DTexCoord2Info*)fn_800CBFF8(&block, block.mTexCoord2InfoOffset);
	mTexMtxInfo = (J3DTexMtxInfo*)fn_800CBFE0(&block, block.mTexMtxInfoOffset);
	mTexMtxInfo2 = (J3DTexMtxInfo*)fn_800CBFE0(&block, block.mTexMtxInfo2Offset);
	mTextureRemapTable = JSUConvertOffsetToPtr<u16>(&block, block.mTextureRemapTableOffset);
	mTevOrderInfo = (J3DTevOrderInfo*)fn_800CBFC8(&block, block.mTevOrderInfoOffset);
	mTevColors = JSUConvertOffsetToPtr<GXColorS10>(&block, block.mTevColorsOffset);
	mTevKColors = JSUConvertOffsetToPtr<GXColor>(&block, block.mTevKColorsOffset);
	mTevStageNums = JSUConvertOffsetToPtr<u8>(&block, block.mNumTevStagesOffset);
	mTevStageInfo = (J3DTevStageInfo*)fn_800CBFB0(&block, block.mTevStageInfoOffset);
	mTevSwapModeInfo = (J3DTevSwapModeInfo*)fn_800CBF98(&block, block.mTevSwapModeInfoOffset);
	mTevSwapModeTableInfo = (J3DTevSwapModeTableInfo*)fn_800CBF80(&block, block.mTevSwapModeTableInfoOffset);
	mFogInfo = (J3DFogInfo*)fn_800CBF68(&block, block.mFogInfoOffset);
	mAlphaCompInfo = (J3DAlphaCompInfo*)fn_800CBF50(&block, block.mAlphaCompInfoOffset);
	mBlendInfo = (J3DBlendInfo*)fn_800CBF38(&block, block.mBlendInfoOffset);
	mZModeInfo = (J3DZModeInfo*)fn_800CBF20(&block, block.mZModeInfoOffset);
	mZCompareInfo = JSUConvertOffsetToPtr<u8>(&block, block.mZCompareInfoOffset);
	mDitherInfo = JSUConvertOffsetToPtr<u8>(&block, block.mDitherInfoOffset);
	mNBTScaleInfo = (J3DNBTScaleInfo*)fn_800CBF08(&block, block.mNBTScaleInfoOffset);
}

u16 J3DMaterialFactory_v21::countUniqueMaterials()
{
	u16 i;
	for (i = 0; i < mMaterialNum; i++) {
	}
	return i;
}

J3DMaterial* J3DMaterialFactory_v21::create(J3DMaterial* pMaterial, int idx, u32 flags) const
{
	J3DMaterial* material = pMaterial;
	u32 numTextures = 0;
	J3DMaterialInitData_v21* initData = &mInitData[mMatRemapTable[idx]];
	u32 numTevStages = numTextures;
	if (initData->mNumTevStagesIndex != 0xff) {
		numTevStages = mTevStageNums[initData->mNumTevStagesIndex];
	}
	if (initData->mTextureIndex[0] != 0xffff) { numTextures++; }
	if (initData->mTextureIndex[1] != 0xffff) { numTextures++; }
	if (initData->mTextureIndex[2] != 0xffff) { numTextures++; }
	if (initData->mTextureIndex[3] != 0xffff) { numTextures++; }
	if (initData->mTextureIndex[4] != 0xffff) { numTextures++; }
	if (initData->mTextureIndex[5] != 0xffff) { numTextures++; }
	if (initData->mTextureIndex[6] != 0xffff) { numTextures++; }
	if (initData->mTextureIndex[7] != 0xffff) { numTextures++; }
	if (numTevStages != numTextures && numTextures != 0) {
		if (numTevStages > numTextures) {
			numTextures = numTevStages;
		}
	} else {
		numTextures = numTevStages;
	}
	u32 tevStageNum = (flags >> 16) & 0x1f;
	if (numTextures > tevStageNum) {
		tevStageNum = numTextures;
	}
	u32 texNoNum = tevStageNum > 8 ? 8 : tevStageNum;
	u32 texGenNum;
	if (initData->mNumTexGensIndex != 0xff) {
		texGenNum = mTexGenNums[initData->mNumTexGensIndex];
	} else {
		texGenNum = 0;
	}
	u32 peFlag = flags & 0x30000000;
	u32 texGenFlag;
	u32 colorFlag = flags & 0xc0000000;
	texGenFlag = texGenNum > 4 ? 0 : flags & 0x0c000000;
	u32 indFlag = (flags >> 24) & 1;
	if (material == NULL) {
		material = (J3DMaterial*)operator new(sizeof(J3DMaterial));
		new (material) J3DMaterial;
	}
	material->mColorBlock = J3DMaterial::createColorBlock(colorFlag);
	material->mTexGenBlock = J3DMaterial::createTexGenBlock(texGenFlag);
	material->mTevBlock = J3DMaterial::createTevBlock((u16)tevStageNum);
	material->mIndBlock = J3DMaterial::createIndBlock(indFlag);
	material->mPEBlock = J3DMaterial::createPEBlock(peFlag, mInitData[mMatRemapTable[idx]].mPixelEngineMode);
	material->mIndex = idx;
	material->mMaterialMode = mInitData[mMatRemapTable[idx]].mPixelEngineMode;

	material->mColorBlock->setColorChanNum(newColorChanNum(idx));
	material->mColorBlock->setCullMode(newCullMode(idx));
	material->mTexGenBlock->setTexGenNum(newTexGenNum(idx));
	material->mTexGenBlock->setNBTScale(newNBTScale(idx));
	material->mPEBlock->setFog(fn_800E0F84(this, idx));
	material->mPEBlock->setAlphaComp(newAlphaComp(idx));
	material->mPEBlock->setBlend(fn_800E1144(this, idx));
	material->mPEBlock->setZMode(newZMode(idx));
	material->mPEBlock->setZCompLoc(newZCompLoc(idx));
	material->mPEBlock->setDither(newDither(idx));
	material->mTevBlock->setTevStageNum(newTevStageNum(idx));

	for (u8 i = 0; i < texNoNum; i++) {
		material->mTevBlock->setTexNo(i, newTexNo(idx, i));
	}
	for (u8 i = 0; i < tevStageNum; i++) {
		material->mTevBlock->setTevOrder(i, fn_800E0D3C(this, idx, i));
	}
	for (u8 i = 0; i < tevStageNum; i++) {
		J3DMaterialInitData_v21* data = &mInitData[mMatRemapTable[idx]];
		material->mTevBlock->setTevStage(i, newTevStage(idx, i));
		if (data->mTevSwapModeInfoIndex[i] != 0xffff) {
			material->mTevBlock->getTevStage(i)->setTexSel(mTevSwapModeInfo[data->mTevSwapModeInfoIndex[i]].mTexSel);
			material->mTevBlock->getTevStage(i)->setRasSel(mTevSwapModeInfo[data->mTevSwapModeInfoIndex[i]].mRasSel);
		}
	}
	for (u8 i = 0; i < 4; i++) {
		material->mTevBlock->setTevKColor(i, fn_800E0DF8(this, idx, i));
	}
	for (u8 i = 0; i < 4; i++) {
		material->mTevBlock->setTevColor(i, reinterpret_cast<J3DGXColorS10 (*)(const J3DMaterialFactory_v21*, int, int)>(fn_800E0D88)(this, idx, i));
	}
	for (u8 i = 0; i < 4; i++) {
		material->mTevBlock->setTevSwapModeTable(i, newTevSwapModeTable(idx, i));
	}
	for (u8 i = 0; i < 2; i++) {
		material->mColorBlock->setMatColor(i, fn_800E0960(this, idx, i));
	}
	for (u8 i = 0; i < 4; i++) {
		J3DColorChan chan(fn_800E09F0(this, idx, i));
		material->mColorBlock->setColorChan(i, chan);
	}
	for (u8 i = 0; i < texGenNum; i++) {
		J3DTexCoord texCoord(fn_800E0BBC(this, idx, i));
		material->mTexGenBlock->setTexCoord(i, &texCoord);
	}
	for (u8 i = 0; i < 8; i++) {
		material->mTexGenBlock->setTexMtx(i, fn_800E0C1C(this, idx, i));
	}
	J3DMaterialInitData_v21* data = &mInitData[mMatRemapTable[idx]];
	for (u8 i = 0; i < tevStageNum; i++) {
		if (data->mTevKColorSels[i] != 0xff) {
			material->mTevBlock->setTevKColorSel(i, data->mTevKColorSels[i]);
		} else {
			material->mTevBlock->setTevKColorSel(i, 0xc);
		}
	}
	for (u8 i = 0; i < tevStageNum; i++) {
		if (data->mTevKAlphaSels[i] != 0xff) {
			material->mTevBlock->setTevKAlphaSel(i, data->mTevKAlphaSels[i]);
		} else {
			material->mTevBlock->setTevKAlphaSel(i, 0x1c);
		}
	}
	return material;
}

extern "C" TevKColorWord fn_800E0960(const J3DMaterialFactory_v21* self, int idx, int no)
{
	GXColor dflt = j3dDefaultColInfo;
	J3DMaterialInitData_v21* initData = &self->mInitData[self->mMatRemapTable[idx]];
	if (initData->mMatColorIndex[no] != 0xffff) {
		return TevKColorWord(*(u32*)&self->mColorData[initData->mMatColorIndex[no]]);
	}
	return TevKColorWord(*(u32*)&dflt);
}

u8 J3DMaterialFactory_v21::newColorChanNum(int idx) const
{
    u8 bVar1 = ((u8*)&mInitData[mMatRemapTable[idx]])[2];
    if (bVar1 != 0xff) {
        return mNumColorChans[bVar1];
    }
    return 0;
}

extern "C" J3DColorChan fn_800E09F0(const J3DMaterialFactory_v21* self, int idx, int no)
{
	J3DMaterialInitData_v21* initData = &self->mInitData[self->mMatRemapTable[idx]];
	if (initData->mColorChanControlIndex[no] != 0xffff) {
		return J3DColorChan(self->mColorChanInfo[initData->mColorChanControlIndex[no]]);
	}
	return J3DColorChan();
}

u32 J3DMaterialFactory_v21::newTexGenNum(int idx) const
{
    u8 bVar1 = ((u8*)&mInitData[mMatRemapTable[idx]])[3];
    if (bVar1 != 0xff) {
        return mTexGenNums[bVar1];
    }
    return 0;
}

extern "C" J3DTexCoord fn_800E0BBC(const J3DMaterialFactory_v21* self, int idx, int no)
{
	J3DMaterialInitData_v21* initData = &self->mInitData[self->mMatRemapTable[idx]];
	if (initData->mTexGenInfoIndex[no] != 0xffff) {
		return J3DTexCoord(self->mTexCoordInfo[initData->mTexGenInfoIndex[no]]);
	}
	return J3DTexCoord();
}

extern "C" J3DTexMtx* fn_800E0C1C(const J3DMaterialFactory_v21* self, int idx, int no)
{
	J3DTexMtx* texMtx = NULL;
	J3DMaterialInitData_v21& initData = self->mInitData[self->mMatRemapTable[idx]];
	if (initData.mTexMatrixIndex[no] != 0xffff) {
		J3DTexMtx* newMtx = (J3DTexMtx*)operator new(sizeof(J3DTexMtx));
		if (newMtx != NULL) {
			newMtx->mTexMtxInfo = self->mTexMtxInfo[initData.mTexMatrixIndex[no]];
		}
		texMtx = newMtx;
	}
	return texMtx;
}

u8 J3DMaterialFactory_v21::newCullMode(int idx) const
{
    u8 bVar1 = ((u8*)&mInitData[mMatRemapTable[idx]])[1];
    if (bVar1 != 0xff) {
        return mCullModeInfo[bVar1];
    }
    return 0xff;
}

u16 J3DMaterialFactory_v21::newTexNo(int idx, int no) const
{
    u8* pTexNo = (u8*)&mInitData[mMatRemapTable[idx]] + 0x70;
    u16 uVar1 = *(u16*)(pTexNo + no * 2);
    if (uVar1 != 0xffff) {
        return mTextureRemapTable[uVar1];
    }
    return 0xffff;
}

extern "C" J3DTevOrder fn_800E0D3C(const J3DMaterialFactory_v21* self, int idx, int no)
{
	J3DMaterialInitData_v21* initData = &self->mInitData[self->mMatRemapTable[idx]];
	if (initData->mTevOrderInfoIndex[no] != 0xffff) {
		return J3DTevOrder(self->mTevOrderInfo[initData->mTevOrderInfoIndex[no]]);
	}
	return J3DTevOrder();
}

extern "C" TevColorWords fn_800E0D88(const J3DMaterialFactory_v21* self, int idx, int no)
{
	u32 defaultColor[2];
	defaultColor[0] = lbl_80543F10;
	defaultColor[1] = lbl_80543F14;
	J3DMaterialInitData_v21* initData = &self->mInitData[self->mMatRemapTable[idx]];
	if (initData->mTevColorIndex[no] != 0xffff) {
		return *(TevColorWords*)&self->mTevColors[initData->mTevColorIndex[no]];
	}
	return *(TevColorWords*)defaultColor;
}

extern "C" u32 lbl_80543F10;
extern "C" u32 lbl_80543F14;

extern "C" TevKColorWord fn_800E0DF8(const J3DMaterialFactory_v21* self, int idx, int no)
{
	GXColor defaultColor = {0xff, 0xff, 0xff, 0xff};
	J3DMaterialInitData_v21* initData = &self->mInitData[self->mMatRemapTable[idx]];
	if (initData->mTevKColorIndex[no] != 0xffff) {
		return TevKColorWord(*(u32*)&self->mTevKColors[initData->mTevKColorIndex[no]]);
	}
	return TevKColorWord(*(u32*)&defaultColor);
}


u8 J3DMaterialFactory_v21::newTevStageNum(int idx) const
{
    u8 bVar1 = ((u8*)&mInitData[mMatRemapTable[idx]])[4];
    if (bVar1 != 0xff) {
        return mTevStageNums[bVar1];
    }
    return 0xff;
}

J3DTevStage J3DMaterialFactory_v21::newTevStage(int idx, int stage) const
{
    J3DMaterialInitData_v21* initData = &mInitData[mMatRemapTable[idx]];
    if (initData->mTevStageInfoIndex[stage] != 0xffff) {
        return J3DTevStage(mTevStageInfo[initData->mTevStageInfoIndex[stage]]);
    }
    return J3DTevStage();
}

J3DTevSwapModeTable J3DMaterialFactory_v21::newTevSwapModeTable(int idx, int stage) const
{
    J3DMaterialInitData_v21* initData = &mInitData[mMatRemapTable[idx]];
    if (initData->mTevSwapModeTableIndex[stage] != 0xffff) {
        return J3DTevSwapModeTable(mTevSwapModeTableInfo[initData->mTevSwapModeTableIndex[stage]]);
    }
    return J3DTevSwapModeTable(j3dDefaultTevSwapModeTable);
}

#pragma use_lmw_stmw off
extern "C" J3DFog fn_800E0F84(const J3DMaterialFactory_v21* self, const int idx)
{
    J3DFog fog;
    J3DMaterialInitData_v21* initData = &self->mInitData[self->mMatRemapTable[idx]];
    if (initData->mFogInfoIndex != 0xffff) {
        fog.setFogInfo(self->mFogInfo[initData->mFogInfoIndex]);
    }
    return fog;
}
#pragma use_lmw_stmw reset

J3DAlphaComp J3DMaterialFactory_v21::newAlphaComp(int idx) const
{
    J3DMaterialInitData_v21* initData = &mInitData[mMatRemapTable[idx]];
    if (initData->mAlphaCompareIndex != 0xffff) {
        return J3DAlphaComp(mAlphaCompInfo[initData->mAlphaCompareIndex]);
    }
    return J3DAlphaComp(0xffff);
}

extern "C" J3DBlend fn_800E1144(const J3DMaterialFactory_v21* self, int idx)
{
	J3DMaterialInitData_v21* initData = &self->mInitData[self->mMatRemapTable[idx]];
	if (initData->mBlendModeIndex != 0xffff) {
		return J3DBlend(self->mBlendInfo[initData->mBlendModeIndex]);
	}
	return J3DBlend();
}

J3DZMode J3DMaterialFactory_v21::newZMode(int idx) const
{
    u8 bVar1 = ((u8*)&mInitData[mMatRemapTable[idx]])[6];
    if (bVar1 != 0xff) {
        return J3DZMode(mZModeInfo[bVar1]);
    }
    return J3DZMode();
}

u8 J3DMaterialFactory_v21::newZCompLoc(int idx) const
{
	u8 bVar1 = ((u8*)&mInitData[mMatRemapTable[idx]])[5];
	if (bVar1 != 0xff) {
		return mZCompareInfo[bVar1];
	}
	return 0;
}

u8 J3DMaterialFactory_v21::newDither(int idx) const
{
	u8 bVar1 = ((u8*)&mInitData[mMatRemapTable[idx]])[7];
	if (bVar1 != 0xff) {
		return mDitherInfo[bVar1];
	}
	return 1;
}

J3DNBTScale J3DMaterialFactory_v21::newNBTScale(int idx) const
{
	J3DNBTScale defaultScale;
	u16 index = *(u16*)((u8*)&mInitData[mMatRemapTable[idx]] + 0x136);
	if (index != 0xffff) {
		return J3DNBTScale(mNBTScaleInfo[index]);
	}
	return defaultScale;
}

extern "C" void* fn_800E1300(const void* base, const void* offset)
{
	if (offset == 0) {
		return 0;
	}
	return (void*)((int)base + (int)offset);
}
