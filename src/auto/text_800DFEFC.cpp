#include "JSystem/J3D/J3DMaterialFactory.h"
#include "JSystem/JSupport.h"

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
	u16 count = 0;
	u16 num = mMaterialNum;
	if (num != 0) {
		if (num > 8) {
			for (; count < (u16)(num - 8); count += 8) {}
		}
		for (; count < num; count++) {}
	}
	return count;
}

extern "C" J3DGXColor fn_800E0960(const J3DMaterialFactory_v21* self, int idx, int no)
{
	J3DMaterialInitData_v21* initData = &self->mInitData[self->mMatRemapTable[idx]];
	if (initData->mMatColorIndex[no] != 0xffff) {
		return J3DGXColor(self->mColorData[initData->mMatColorIndex[no]]);
	}
	return J3DGXColor();
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
	J3DMaterialInitData_v21* initData = &self->mInitData[self->mMatRemapTable[idx]];
	if (initData->mTexMatrixIndex[no] != 0xffff) {
		texMtx = new J3DTexMtx(self->mTexMtxInfo[initData->mTexMatrixIndex[no]]);
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

extern "C" J3DGXColorS10 fn_800E0D88(const J3DMaterialFactory_v21* self, int idx, int no)
{
	J3DMaterialInitData_v21* initData = &self->mInitData[self->mMatRemapTable[idx]];
	if (initData->mTevColorIndex[no] != 0xffff) {
		return J3DGXColorS10(self->mTevColors[initData->mTevColorIndex[no]]);
	}
	return j3dDefaultTevColor;
}

extern "C" GXColor fn_800E0DF8(const J3DMaterialFactory_v21* self, int idx, int no)
{
	GXColor defaultColor = j3dDefaultTevKColor;
	J3DMaterialInitData_v21* initData = &self->mInitData[self->mMatRemapTable[idx]];
	if (initData->mTevKColorIndex[no] != 0xffff) {
		return self->mTevKColors[initData->mTevKColorIndex[no]];
	}
	return defaultColor;
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

extern "C" J3DFogInfo fn_800E0F84(const J3DMaterialFactory_v21* self, int idx)
{
	J3DFogInfo fog;
	fog = j3dDefaultFogInfo;
	J3DMaterialInitData_v21* initData = &self->mInitData[self->mMatRemapTable[idx]];
	if (initData->mFogInfoIndex != 0xffff) {
		J3DFogInfo tmp = self->mFogInfo[initData->mFogInfoIndex];
		fog = tmp;
	}
	return fog;
}

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
