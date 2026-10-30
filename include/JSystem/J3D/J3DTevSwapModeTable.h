#ifndef J3D_TEV_SWAP_MODE_TABLE_H
#define J3D_TEV_SWAP_MODE_TABLE_H
#include "types.h"
extern u8 j3dTevSwapTableTable[1024];
struct J3DTevSwapModeTableInfo {
	u8 mR; // _00
	u8 mG; // _01
	u8 mB; // _02
	u8 mA; // _03
};

extern const J3DTevSwapModeTableInfo j3dDefaultTevSwapModeTable;
extern const u8 j3dDefaultTevSwapTableID;

/**
 * @size{0x1}
 */
struct J3DTevSwapModeTable {
	J3DTevSwapModeTable() { mTevSwapID = j3dDefaultTevSwapTableID; }
	J3DTevSwapModeTable(const J3DTevSwapModeTableInfo& info) { mTevSwapID = calcTevSwapTableID(info.mR, info.mG, info.mB, info.mA); }

	u8 calcTevSwapTableID(u32 r, u32 g, u32 b, u32 a) { return 0x40 * r + 0x10 * g + 4 * b + a; }

	u8 getR() { return j3dTevSwapTableTable[mTevSwapID * 4]; }
	u8 getG() { return j3dTevSwapTableTable[mTevSwapID * 4 + 1]; }
	u8 getB() { return j3dTevSwapTableTable[mTevSwapID * 4 + 2]; }
	u8 getA() { return j3dTevSwapTableTable[mTevSwapID * 4 + 3]; }

	u8 mTevSwapID; // _00
};
#endif
