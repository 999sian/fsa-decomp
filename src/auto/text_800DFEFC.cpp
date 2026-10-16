#include "JSystem/J3D/J3DMaterialFactory.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

u16 J3DMaterialFactory_v21::countUniqueMaterials()
{
	u16 count = 0;
	u16 num = mMaterialNum;
	if (num == 0) {
		return 0;
	}
	if (num > 8) {
		for (; count < (u16)(num - 8); count += 8) {}
	}
	for (; count < num; count++) {}
	return count;
}

extern "C" J3DGXColor fn_800E0960(const J3DMaterialFactory_v21* self, int idx, int no)
{
	J3DMaterialInitData_v21* initData = &self->mInitData[self->mMatRemapTable[idx]];
	if (initData->mMatColorIndex[no] != 0xffff) {
		return J3DGXColor(self->mColorData[initData->mMatColorIndex[no]]);
	}
	return j3dDefaultColInfo;
}

u8 J3DMaterialFactory_v21::newColorChanNum(int idx) const
{
    u8 bVar1 = ((u8*)&mInitData[mMatRemapTable[idx]])[2];
    if (bVar1 != 0xff) {
        return mNumColorChans[bVar1];
    }
    return 0;
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
	J3DMaterialInitData_v21* initData = &self->mInitData[self->mMatRemapTable[idx]];
	J3DTexMtx* texMtx = NULL;
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

J3DZMode J3DMaterialFactory_v21::newZMode(int idx) const
{
    u8 bVar1 = ((u8*)&mInitData[mMatRemapTable[idx]])[6];
    if (bVar1 != 0xff) {
        return J3DZMode(mZModeInfo[bVar1]);
    }
    return J3DZMode();
}

extern "C" void* fn_800E1300(const void* base, const void* offset)
{
	if (offset == 0) {
		return 0;
	}
	return (void*)((int)base + (int)offset);
}
