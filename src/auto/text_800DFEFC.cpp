#include "JSystem/J3D/J3DMaterialFactory.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" J3DTevOrder fn_800E0D3C(const J3DMaterialFactory_v21* self, int idx, int no)
{
	J3DMaterialInitData_v21* initData = &self->mInitData[self->mMatRemapTable[idx]];
	if (initData->mTevOrderInfoIndex[no] != 0xffff) {
		return J3DTevOrder(self->mTevOrderInfo[initData->mTevOrderInfoIndex[no]]);
	}
	return J3DTevOrder();
}

extern "C" void* fn_800E1300(const void* base, const void* offset)
{
	if (offset == 0) {
		return 0;
	}
	return (void*)((int)base + (int)offset);
}
