// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"
#include <dolphin/gx.h>

struct J3DMaterialDLBlock {
    u32 _00;
    u32 _04;
    u16 mEntries;                   // _08
    void* mPacketOffset;            // _0C
    void* mSubPacketLocationOffset; // _10
    void* mMatrixIndexOffset;       // _14
    void* mPixelEngineModesOffset;  // _18
    void* mIndexesOffset;           // _1C
    void* mStringTableOffset;       // _20
};

struct J3DMaterialBlock {
    u32 _00;
    u32 _04;
    u16 mNumMaterials;                 // _08
    void* mMatEntryDataOffset;         // _0C
    void* mMatRemapTableOffset;        // _10
    void* mStringTableOffset;          // _14
    void* mIndTextureInfoOffset;       // _18
    void* mCullModeInfoOffset;         // _1C
    void* mMatColorsOffset;            // _20
    void* mNumColorChansOffset;        // _24
    void* mColorChanInfoOffset;        // _28
    void* mAmbientColorOffset;         // _2C
    void* mLightInfoOffset;            // _30
    void* mNumTexCoordsOffset;         // _34
    void* mTexCoordInfoOffset;         // _38
    void* mTexCoord2InfoOffset;        // _3C
    void* mTexMtxInfoOffset;           // _40
    void* mTexMtxInfo2Offset;          // _44
    void* mTextureRemapTableOffset;    // _48
    void* mTevOrderInfoOffset;         // _4C
    void* mTevColorsOffset;            // _50
    void* mTevKColorsOffset;           // _54
    void* mNumTevStagesOffset;         // _58
    void* mTevStageInfoOffset;         // _5C
    void* mTevSwapModeInfoOffset;      // _60
    void* mTevSwapModeTableInfoOffset; // _64
    void* mFogInfoOffset;              // _68
    void* mAlphaCompInfoOffset;        // _6C
    void* mBlendInfoOffset;            // _70
    void* mZModeInfoOffset;            // _74
    void* mZCompareInfoOffset;         // _78
    void* mDitherInfoOffset;           // _7C
    void* mNBTScaleInfoOffset;         // _80
};

class J3DIndTexMtxInfo {
public:
    J3DIndTexMtxInfo& operator=(const J3DIndTexMtxInfo&);
    f32 mMtx[2][3]; // _00
    s8 mScaleExp;   // _18
};
extern J3DIndTexMtxInfo j3dDefaultIndTexMtxInfo;

class J3DFogInfo {
public:
    J3DFogInfo& operator=(const J3DFogInfo&);
    u8 _00[0x2c];
};
extern J3DFogInfo j3dDefaultFogInfo;

struct J3DIndTevStageInfo {
    u8 mIndStage;  // _00
    u8 mIndFormat; // _01
    u8 mBiasSel;   // _02
    u8 mMtxSel;    // _03
    u8 mWrapS;     // _04
    u8 mWrapT;     // _05
    u8 mPrev;      // _06
    u8 mLod;       // _07
    u8 mAlphaSel;  // _08
    u8 _09;
    u8 _0A;
    u8 _0B;
};
extern J3DIndTevStageInfo j3dDefaultIndTevStageInfo;

class J3DIndTevStage {
public:
    J3DIndTevStage() {
        mInfo = 0;
        setIndTevStageInfo(j3dDefaultIndTevStageInfo);
    }
    void setIndTevStageInfo(const J3DIndTevStageInfo& info) {
        setIndStage(info.mIndStage);
        setIndFormat(info.mIndFormat);
        setBiasSel(info.mBiasSel);
        setMtxSel(info.mMtxSel);
        setWrapS(info.mWrapS);
        setWrapT(info.mWrapT);
        setPrev(info.mPrev);
        setLod(info.mLod);
        setAlphaSel(info.mAlphaSel);
    }
    void setIndStage(u32 stage) { mInfo = mInfo & ~0x03 | stage; }
    void setIndFormat(u32 format) { mInfo = mInfo & ~0x0C | format << 2; }
    void setBiasSel(u32 sel) { mInfo = mInfo & ~0x70 | sel << 4; }
    void setAlphaSel(u32 sel) { mInfo = mInfo & ~0x0180 | sel << 7; }
    void setMtxSel(u32 sel) { mInfo = mInfo & ~0x1E00 | sel << 9; }
    void setWrapS(u32 wrap) { mInfo = mInfo & ~0xE000 | wrap << 13; }
    void setWrapT(u32 wrap) { mInfo = mInfo & ~0x070000 | wrap << 16; }
    void setLod(u32 lod) { mInfo = mInfo & ~0x080000 | lod << 19; }
    void setPrev(u32 prev) { mInfo = mInfo & ~0x100000 | prev << 20; }

    u32 mInfo;
};

class J3DMaterial {
public:
    void initialize();
};
class J3DLockedMaterial : public J3DMaterial {
public:
    void initialize();
};
class J3DDisplayListObj {
public:
    void setSingleDisplayList(void*, u32);
};
class J3DMaterialFactory {
public:
    enum MaterialType {
        NORMAL = 0,
        LOCKED = 1,
        PATCHED = 2,
    };
    J3DMaterialFactory(const J3DMaterialBlock& block);
    J3DMaterialFactory(const J3DMaterialDLBlock& block);
    size_t calcSize(J3DMaterial*, MaterialType, int, u32) const;
    size_t calcSizeNormalMaterial(J3DMaterial*, int, u32) const;
    size_t calcSizePatchedMaterial(J3DMaterial*, int, u32) const;
    size_t calcSizeLockedMaterial(J3DMaterial*, int, u32) const;
    u32 countUniqueMaterials();
          J3DMaterial* create(J3DMaterial*, MaterialType, int, u32) const;
      void modifyPatchedCurrentMtx(J3DMaterial*, int) const;


    u16 mMaterialNum;    // _00
    void* mInitData;     // _04
    u16* mMatRemapTable; // _08
    void* unk_0C[27];    // _0C
    void* mDisplayLists; // _78
    void* mPatchInfo;    // _7C
    void* mCurrMtxInfo;  // _80
    u8* mPEModes;        // _84
};

extern volatile s32 lbl_8053BC70;

template <typename T>
T* JSUConvertOffsetToPtr(const void* ptr, const void* offset)
{
    if (offset == NULL) {
        return NULL;
    }
    return (T*)((s32)ptr + (s32)offset);
}

extern "C" void* fn_800CBEC0(const void* base, const void* offset);
extern "C" void* fn_800CBED8(const void* base, const void* offset);
extern "C" void* fn_800CBEF0(const void* base, const void* offset);
extern "C" J3DMaterial* fn_800CA7F0(const J3DMaterialFactory* self, J3DMaterial* material, int idx, u32 flags);
extern "C" J3DMaterial* fn_800C92E8(const J3DMaterialFactory* self, J3DMaterial* material, int idx, u32 flags);
extern "C" J3DMaterial* fn_800C9D20(const J3DMaterialFactory* self, J3DMaterial* material, int idx, u32 flags);
extern "C" char __vt__11J3DMaterial[];
extern "C" char __vt__17J3DLockedMaterial[];
extern "C" char __vt__13J3DColorBlock[];
extern "C" char lbl_8049ABFC[];
extern "C" char __vt__14J3DTexGenBlock[];
extern "C" char lbl_8049AB90[];
extern "C" char __vt__11J3DTevBlock[];
extern "C" char lbl_8049AAB4[];
extern "C" void fn_800D36E0(void* tev);
extern "C" char __vt__11J3DIndBlock[];
extern "C" char __vt__15J3DIndBlockNull[];
extern "C" char __vt__10J3DPEBlock[];
extern "C" char lbl_8049AA38[];

struct J3DNBTScaleInfo {
    u8 mHasScale;
    f32 mScale[3];
};
extern "C" J3DNBTScaleInfo j3dDefaultNBTScaleInfo;
extern u32 j3dDefaultTexCoordInfo[];
extern "C" void fn_800CB194(u32* out, u8* p, s32 idx, s32 b);
extern "C" char lbl_8049AA38[];
extern "C" char __vt__10J3DPEBlock[];
extern "C" void* fn_800CC070(const void* base, const void* offset);
extern "C" void* fn_800CC058(const void* base, const void* offset);
extern "C" void* fn_800CC040(const void* base, const void* offset);
extern "C" void* fn_800CC028(const void* base, const void* offset);
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
extern "C" u32 calcSizeColorBlock__11J3DMaterialFUl(u32);
extern "C" u32 calcSizeTexGenBlock__11J3DMaterialFUl(u32);
extern "C" u32 calcSizeTevBlock__11J3DMaterialFi(int);
extern "C" u32 calcSizeIndBlock__11J3DMaterialFi(int);
extern "C" u32 calcSizePEBlock__11J3DMaterialFUlUl(u32, u32);
extern "C" s32 fn_800CAEC8(void* self, void* mat, s32 idx, u32 flags);

#include <types.h>

J3DMaterialFactory::J3DMaterialFactory(const J3DMaterialBlock& block)
{
    mMaterialNum = block.mNumMaterials;
    mInitData = fn_800CC070(&block, block.mMatEntryDataOffset);
    mMatRemapTable = JSUConvertOffsetToPtr<u16>(&block, block.mMatRemapTableOffset);
    if (block.mIndTextureInfoOffset != NULL && (u32)block.mIndTextureInfoOffset - (u32)block.mStringTableOffset > 4) {
        unk_0C[0] = fn_800CC058(&block, block.mIndTextureInfoOffset);
    } else {
        unk_0C[0] = NULL;
    }
    unk_0C[12] = JSUConvertOffsetToPtr<GXCullMode>(&block, block.mCullModeInfoOffset);
    unk_0C[1] = JSUConvertOffsetToPtr<GXColor>(&block, block.mMatColorsOffset);
    unk_0C[2] = JSUConvertOffsetToPtr<u8>(&block, block.mNumColorChansOffset);
    unk_0C[3] = fn_800CC040(&block, block.mColorChanInfoOffset);
    unk_0C[4] = JSUConvertOffsetToPtr<GXColor>(&block, block.mAmbientColorOffset);
    unk_0C[5] = fn_800CC028(&block, block.mLightInfoOffset);
    unk_0C[6] = JSUConvertOffsetToPtr<u8>(&block, block.mNumTexCoordsOffset);
    unk_0C[7] = fn_800CC010(&block, block.mTexCoordInfoOffset);
    unk_0C[8] = fn_800CBFF8(&block, block.mTexCoord2InfoOffset);
    unk_0C[9] = fn_800CBFE0(&block, block.mTexMtxInfoOffset);
    unk_0C[10] = fn_800CBFE0(&block, block.mTexMtxInfo2Offset);
    unk_0C[11] = JSUConvertOffsetToPtr<u16>(&block, block.mTextureRemapTableOffset);
    unk_0C[13] = fn_800CBFC8(&block, block.mTevOrderInfoOffset);
    unk_0C[14] = JSUConvertOffsetToPtr<GXColorS10>(&block, block.mTevColorsOffset);
    unk_0C[15] = JSUConvertOffsetToPtr<GXColor>(&block, block.mTevKColorsOffset);
    unk_0C[16] = JSUConvertOffsetToPtr<u8>(&block, block.mNumTevStagesOffset);
    unk_0C[17] = fn_800CBFB0(&block, block.mTevStageInfoOffset);
    unk_0C[18] = fn_800CBF98(&block, block.mTevSwapModeInfoOffset);
    unk_0C[19] = fn_800CBF80(&block, block.mTevSwapModeTableInfoOffset);
    unk_0C[20] = fn_800CBF68(&block, block.mFogInfoOffset);
    unk_0C[21] = fn_800CBF50(&block, block.mAlphaCompInfoOffset);
    unk_0C[22] = fn_800CBF38(&block, block.mBlendInfoOffset);
    unk_0C[23] = fn_800CBF20(&block, block.mZModeInfoOffset);
    unk_0C[24] = JSUConvertOffsetToPtr<u8>(&block, block.mZCompareInfoOffset);
    unk_0C[25] = JSUConvertOffsetToPtr<u8>(&block, block.mDitherInfoOffset);
    unk_0C[26] = fn_800CBF08(&block, block.mNBTScaleInfoOffset);
    mDisplayLists = NULL;
    mPatchInfo = NULL;
    mCurrMtxInfo = NULL;
    mPEModes = NULL;
}

J3DMaterialFactory::J3DMaterialFactory(const J3DMaterialDLBlock& block)
{
    mMaterialNum = block.mEntries;
    mInitData = NULL;
    mDisplayLists = fn_800CBEF0(&block, block.mPacketOffset);
    mPatchInfo = fn_800CBED8(&block, block.mSubPacketLocationOffset);
    mCurrMtxInfo = fn_800CBEC0(&block, block.mMatrixIndexOffset);
    mPEModes = JSUConvertOffsetToPtr<u8>(&block, block.mPixelEngineModesOffset);
}

u32 J3DMaterialFactory::countUniqueMaterials()
{
    u32 count = 0;
    s32 max = -1;
    for (u16 i = 0; i < mMaterialNum; i++) {
        u16 id = mMatRemapTable[i];
        if (max < id) {
            max = id;
            count++;
        }
    }
    return count;
}

J3DMaterial* J3DMaterialFactory::create(J3DMaterial* material, MaterialType type, int idx, u32 flags) const
{
    switch (type) {
    case NORMAL:
        material = fn_800C92E8(this, material, idx, flags);
        break;
    case LOCKED:
        material = fn_800CA7F0(this, material, idx, flags);
        break;
    case PATCHED:
        material = fn_800C9D20(this, material, idx, flags);
        break;
    }
    return material;
}

extern "C" void fn_800C9CF4(void)
{
}

extern "C" void fn_800C9CF8() {
}

extern "C" void fn_800C9CFC(void) {
}

extern "C" void fn_800C9D00(void) {}

extern "C" void fn_800C9D04(void) {
}

extern "C" void fn_800C9D08(void) {
}

extern "C" s32 fn_800C9D0C(void) {
    return 0;
}

extern "C" void fn_800C9D14(void) {
}

extern "C" void fn_800C9D18(void) {}

extern "C" s32 lbl_8053BC74;
extern "C" void fn_800C9D1C(void) {
}

extern "C" void** __dt__11J3DMaterialFv(void** param_1, short param_2)
{
    if (param_1 != NULL) {
        *param_1 = __vt__11J3DMaterial;
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

void J3DMaterialFactory::modifyPatchedCurrentMtx(J3DMaterial* material, int idx) const {
    u8 buf[8][6];
    u32 tmp[2];
    u8 count;
    u8 gen;
    u32 def = j3dDefaultTexCoordInfo[0];

    for (int k = 0; k < 8; k++) {
        *(u32*)buf[k] = def;
        ((u16*)buf[k])[2] = buf[k][2];
    }

    gen = ((u8*)mInitData)[mMatRemapTable[idx] * 0x14c + 3];
    if (gen != 0xff) {
        count = ((u8*)unk_0C[6])[gen];
    } else {
        count = 0;
    }
    for (u8 i = 0; i < count; i++) {
        fn_800CB194(tmp, (u8*)this, idx, i);
        *(u32*)buf[i] = tmp[0];
    }

    *(u32*)((u8*)material + 0x40) = (buf[0][2] << 6) | (buf[1][2] << 12) | (buf[2][2] << 18) | (buf[3][2] << 24);
    *(u32*)((u8*)material + 0x44) = buf[4][2] | (buf[5][2] << 6) | (buf[6][2] << 12) | (buf[7][2] << 18);
}

extern "C" void fn_800CAAA8(void) {
}

extern "C" void fn_800CAAAC(void* a, s32 v) {
    *(s32*)((u8*)a + 0x4) = v;
}

size_t J3DMaterialFactory::calcSize(J3DMaterial* mat, MaterialType type, int idx, u32 flags) const {
    size_t size = 0;
    switch (type) {
    case NORMAL:
        size = calcSizeNormalMaterial(mat, idx, flags);
        break;
    case LOCKED:
        size = calcSizeLockedMaterial(mat, idx, flags);
        break;
    case PATCHED:
        size = calcSizePatchedMaterial(mat, idx, flags);
        break;
    }
    return size;
}

extern "C" u32 fn_800CAB34(u8* p, void* mat, s32 idx, u32 flags) {
    u32 size = 0;
    if (*(void**)(p + 0x78) != NULL) {
        fn_800CAEC8(p, mat, idx, flags);
    } else {
        u32 tevNum = 0;
        u32 texGenNum = 0;
        u32 tevStageNum;
        u8 indNum = 0;
        u32 texGenFlags;
        u32 peFlags;
        u32 indFlag;
        {
            u8* entry = *(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c;

            if (entry[4] != 0xff) {
                tevNum = (*(u8**)(p + 0x4c))[entry[4]];
            }
            if (*(u16*)(entry + 0x84) != 0xffff) {
                texGenNum = 1;
            }
            if (*(u16*)(entry + 0x86) != 0xffff) {
                texGenNum++;
            }
            if (*(u16*)(entry + 0x88) != 0xffff) {
                texGenNum++;
            }
            if (*(u16*)(entry + 0x8a) != 0xffff) {
                texGenNum++;
            }
            if (*(u16*)(entry + 0x8c) != 0xffff) {
                texGenNum++;
            }
            if (*(u16*)(entry + 0x8e) != 0xffff) {
                texGenNum++;
            }
            if (*(u16*)(entry + 0x90) != 0xffff) {
                texGenNum++;
            }
            if (*(u16*)(entry + 0x92) != 0xffff) {
                texGenNum++;
            }
            if (tevNum != texGenNum && texGenNum != 0) {
                if (tevNum > texGenNum) {
                    texGenNum = tevNum;
                }
            } else {
                texGenNum = tevNum;
            }
            tevStageNum = (flags >> 0x10) & 0x1f;
            if (texGenNum > tevStageNum) {
                tevStageNum = texGenNum;
            }
            if (entry[3] != 0xff) {
                indNum = (*(u8**)(p + 0x24))[entry[3]];
            }
        }
        peFlags = flags & 0x30000000;
        texGenFlags = flags & 0x0C000000 & ~-(u32)(4 < indNum);
        indFlag = (flags >> 24) & 1;

        if (mat == NULL) {
            size = 0x4c;
        }
        size += calcSizeColorBlock__11J3DMaterialFUl(flags & 0xC0000000);
        size += calcSizeTexGenBlock__11J3DMaterialFUl(texGenFlags);
        size += calcSizeTevBlock__11J3DMaterialFi((u16)tevStageNum);
        size += calcSizeIndBlock__11J3DMaterialFi(indFlag);
        size += calcSizePEBlock__11J3DMaterialFUlUl(peFlags, *(u8*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c));

        if (*(u16*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x48) != 0xffff) {
            size += 0x94;
        }
        if (*(u16*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x4a) != 0xffff) {
            size += 0x94;
        }
        if (*(u16*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x4c) != 0xffff) {
            size += 0x94;
        }
        if (*(u16*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x4e) != 0xffff) {
            size += 0x94;
        }
        if (*(u16*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x50) != 0xffff) {
            size += 0x94;
        }
        if (*(u16*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x52) != 0xffff) {
            size += 0x94;
        }
        if (*(u16*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x54) != 0xffff) {
            size += 0x94;
        }
        if (*(u16*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x56) != 0xffff) {
            size += 0x94;
        }
    }
    return size;
}

extern "C" u32 calcSizeColorBlock__11J3DMaterialFUl(u32);
extern "C" u32 calcSizeIndBlock__11J3DMaterialFi(int);
extern "C" u32 calcSizePEBlock__11J3DMaterialFUlUl(u32, u32);
extern "C" u32 fn_800CAD8C(u8* p, void* mat, s32 idx, u32 flags) {
    u32 size = mat == NULL ? 0x4c : 0;
    u32 ind = (flags & 0x03000000) != 0;
    size += calcSizeColorBlock__11J3DMaterialFUl(0x40000000);
    size += 0x134;
    size += calcSizeIndBlock__11J3DMaterialFi(ind);
    size += calcSizePEBlock__11J3DMaterialFUlUl(0x10000000, *(u8*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c));
    if (*(u16*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x48) != 0xffff) {
        size += 0x94;
    }
    if (*(u16*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x4a) != 0xffff) {
        size += 0x94;
    }
    if (*(u16*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x4c) != 0xffff) {
        size += 0x94;
    }
    if (*(u16*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x4e) != 0xffff) {
        size += 0x94;
    }
    if (*(u16*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x50) != 0xffff) {
        size += 0x94;
    }
    if (*(u16*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x52) != 0xffff) {
        size += 0x94;
    }
    if (*(u16*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x54) != 0xffff) {
        size += 0x94;
    }
    if (*(u16*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x56) != 0xffff) {
        size += 0x94;
    }
    return size;
}

extern "C" s32 fn_800CAEC8(void* self, void* mat, s32 idx, u32 flags) {
    s32 result = 0;
    if (mat == 0) {
        result = 100;
    }
    return result + 0x10;
}

extern "C" void fn_800CAEE0(s32 *param_1, int param_2, int param_3, int param_4) {
    struct Col { s32 v; };
    u8* p = (u8*)param_2;
    Col def = *(Col*)&lbl_8053BC70;
    u16 i = ((u16*)(*(u8**)(p + 4) + (*(u16**)(p + 8))[param_3] * 0x14c + 8))[param_4];
    if (i != 0xffff) {
        *param_1 = (*(s32**)(p + 0x10))[i];
    } else {
        *(Col*)param_1 = def;
    }
}

extern "C" u8 fn_800CAF38(u8* p, s32 idx) {
    u8 b = *(u8*)(*(u8**)(p + 4) + (*(u16**)(p + 8))[idx] * 0x14c + 2);
    if (b != 0xff) {
        return (*(u8**)(p + 0x14))[b];
    }
    return 0;
}

extern "C" void fn_800CB104(s32* out, u8* p, s32 a, s32 b) {
    u16* ids = *(u16**)(p + 8);
    u8* base = *(u8**)(p + 4);
    u16 v = *(u16*)(base + ids[a] * 0x14c + 0x14 + b * 2);
    if (v == 0xffff) {
        *out = lbl_8053BC74;
    } else {
        *out = (*(s32**)(p + 0x1c))[v];
    }
}

extern "C" u8 fn_800CB15C(u8* p, s32 idx) {
    u8 b = *(u8*)(*(u8**)(p + 4) + (*(u16**)(p + 8))[idx] * 0x14c + 3);
    if (b != 0xff) {
        return (*(u8**)(p + 0x24))[b];
    }
    return 0;
}

extern u32 j3dDefaultTexCoordInfo[];
extern "C" void fn_800CB194(u32* out, u8* p, s32 idx, s32 b) {
    u16* tbl = (u16*)(*(u8**)(p + 4) + (*(u16**)(p + 8))[idx] * 0x14c + 0x28);
    if (tbl[b] != 0xffff) {
        *out = (*(u32**)(p + 0x28))[tbl[b]];
        ((u16*)out)[2] = ((u8*)out)[2];
        return;
    }
    *out = j3dDefaultTexCoordInfo[0];
    ((u16*)out)[2] = ((u8*)out)[2];
}

extern "C" void* __nw__FUl(u32);
extern "C" void __as__13J3DTexMtxInfoFRC13J3DTexMtxInfo(void*, const void*);
extern "C" void* fn_800CB1F4(u8* p, s32 idx, s32 b) {
    u16* ids = *(u16**)(p + 8);
    u8* base = *(u8**)(p + 4);
    u32 off = ids[idx] * 0x14c + 0x48 + b * 2;
    void* ret = NULL;
    if (*(u16*)(base + off) != 0xffff) {
        ret = __nw__FUl(0x94);
        if (ret != NULL) {
            __as__13J3DTexMtxInfoFRC13J3DTexMtxInfo(ret, *(u8**)(p + 0x30) + *(u16*)(base + off) * 0x64);
        }
    }
    return ret;
}

extern "C" u8 fn_800CB28C(u8* p, s32 idx) {
    u8 b = *(u8*)(*(u8**)(p + 4) + (*(u16**)(p + 8))[idx] * 0x14c + 1);
    if (b != 0xff) {
        return (*(u32**)(p + 0x3c))[b];
    }
    return 0xff;
}

extern "C" u16 fn_800CB2CC(u8* p, s32 idx, s32 b) {
    u16 v = *(u16*)((*(u8**)(p + 4)) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x84 + b * 2);
    if (v != 0xffff) {
        return (*(u16**)(p + 0x38))[v];
    }
    return 0xffff;
}

extern unsigned int j3dDefaultTevOrderInfoNull;
extern "C" void fn_800CB314(u32* out, u8* p, s32 idx, s32 b) {
    u16* ids = *(u16**)(p + 8);
    u32 off = ids[idx] * 0x14c + 0xbc;
    u16 v = *(u16*)(*(u8**)(p + 4) + (b * 2 + off));
    if (v != 0xffff) {
        *out = (*(u32**)(p + 0x40))[v];
        return;
    }
    *out = j3dDefaultTevOrderInfoNull;
}

extern u32 lbl_80543F08;
extern u32 lbl_80543F0C;
extern u32 lbl_8053BC78;
extern "C" void fn_800CB4C0(void* out, u8* e);
extern "C" void __ct__11J3DTevStageFv(void* self);
extern "C" void fn_800CB360(u32* out, u8* p, s32 idx, s32 b) {
    u32 def[2] = {lbl_80543F08, lbl_80543F0C};
    u32 off = ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0xdc;
    u16 v = *(u16*)(*(u8**)(p + 4) + off + b * 2);
    if (v != 0xffff) {
        u32* e = (u32*)(*(u8**)(p + 0x44) + v * 8);
        out[0] = e[0];
        out[1] = e[1];
        return;
    }
    out[0] = def[0];
    out[1] = def[1];
}

extern "C" void fn_800CB3D0(u32* out, u8* p, s32 idx, s32 b) {
    u32 off = ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x94;
    u16 v = *(u16*)(*(u8**)(p + 4) + off + b * 2);
    if (v != 0xffff) {
        *out = (*(u32**)(p + 0x48))[v];
        return;
    }
    *out = lbl_8053BC78;
}

extern "C" u8 fn_800CB428(u8* p, s32 idx) {
    u32 off = ((u16*)*(u8**)(p + 8))[idx] * 0x14c;
    u8* base = *(u8**)(p + 4);
    u8 v = *(u8*)(base + off + 4);
    if (v != 0xff) {
        return (*(u8**)(p + 0x4c))[v];
    }
    return 0xff;
}

extern "C" void fn_800CB460(void* out, u8* p, s32 idx, s32 b) {
    u32 off = ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0xe4;
    u16 v = *(u16*)(*(u8**)(p + 4) + off + b * 2);
    if (v != 0xffff) {
        fn_800CB4C0(out, *(u8**)(p + 0x50) + v * 0x14);
        return;
    }
    __ct__11J3DTevStageFv(out);
}

struct J3DTevSwapModeInfo {
    u8 mRasSel; // _00
    u8 mTexSel; // _01
};
struct J3DTevSwapModeTableInfo {
    u8 mR; // _00
    u8 mG; // _01
    u8 mB; // _02
    u8 mA; // _03
};
extern J3DTevSwapModeInfo j3dDefaultTevSwapMode;
extern const J3DTevSwapModeTableInfo j3dDefaultTevSwapModeTable;
extern u32 j3dDefaultIndTexOrderNull;
extern "C" void setTevStageInfo__11J3DTevStageFRC15J3DTevStageInfo(void* self, const void* info);
extern "C" void fn_800CB4C0(void* out, u8* e) {
    u8* p = (u8*)out;
    setTevStageInfo__11J3DTevStageFRC15J3DTevStageInfo(out, e);
    u8 v = p[7];
    v = (v & ~0x0C) | (j3dDefaultTevSwapMode.mTexSel << 2);
    p[7] = v;
    v = p[7];
    p[7] = (v & ~0x03) | j3dDefaultTevSwapMode.mRasSel;
}

extern "C" void fn_800CB520(u8* out, u8* p, s32 idx, s32 stage) {
    u16* ids = *(u16**)(p + 8);
    u16 v = *(u16*)(*(u8**)(p + 4) + (ids[idx] * 0x14c + 0x124 + stage * 2));
    if (v != 0xffff) {
        J3DTevSwapModeTableInfo* e = (J3DTevSwapModeTableInfo*)(*(u8**)(p + 0x58) + v * 4);
        *out = (e->mG * 0x10 + e->mB * 4 + e->mA) + e->mR * 0x40;
        return;
    }
    *out = (j3dDefaultTevSwapModeTable.mG * 0x10 + j3dDefaultTevSwapModeTable.mB * 4 + j3dDefaultTevSwapModeTable.mA) + j3dDefaultTevSwapModeTable.mR * 0x40;
}

extern "C" u8 fn_800CB5BC(u8* p, s32 idx) {
    u8* base = *(u8**)(p + 0xc);
    s32 off = idx * 0x138;
    if (base[off] == 1) {
        return base[off + 1];
    }
    return 0;
}

extern "C" void fn_800CB5E4(u32* out, u8* p, s32 idx, s32 stage) {
    u32 def = j3dDefaultIndTexOrderNull;
    u32* defp = &def;
    u8* e = *(u8**)(p + 0xc) + idx * 0x138;
    if (e[0] == 1) {
        *out = *(u32*)(e + stage * 4 + 4);
        return;
    }
    *out = *defp;
}

extern "C" J3DIndTexMtxInfo fn_800CB628(u8* param_2, s32 param_3, s32 param_4) {
    J3DIndTexMtxInfo local;
    local = j3dDefaultIndTexMtxInfo;
    u8* pcVar1 = *(u8**)(param_2 + 0xc) + param_3 * 0x138;
    if (*pcVar1 == 1) {
        local = *(J3DIndTexMtxInfo*)(pcVar1 + param_4 * 0x1c + 0x14);
    }
    return local;
}

extern "C" void fn_800CB6F0(J3DIndTevStage* out, u8* p, s32 idx, s32 stage) {
    J3DIndTevStage dflt;
    u8* data = *(u8**)(p + 0xc) + idx * 0x138;
    if (data[0] == 1) {
        out->mInfo = 0;
        out->setIndTevStageInfo(*(J3DIndTevStageInfo*)(data + stage * 0xc + 0x78));
    } else {
        *out = dflt;
    }
}

struct J3DIndTexCoordScaleInfo {
    void operator=(const J3DIndTexCoordScaleInfo& other) { *(u32*)this = *(u32*)&other; }

    u8 mScaleS; // _00
    u8 mScaleT; // _01
    u8 _02;
    u8 _03;
} __attribute__((aligned(4)));
extern const J3DIndTexCoordScaleInfo j3dDefaultIndTexCoordScaleInfo;
struct J3DIndTexCoordScale : J3DIndTexCoordScaleInfo {
    J3DIndTexCoordScale() { *(J3DIndTexCoordScaleInfo*)this = j3dDefaultIndTexCoordScaleInfo; }
};
extern "C" void fn_800CB884(J3DIndTexCoordScaleInfo* out, u8* p, s32 idx, s32 no) {
    u8* data = *(u8**)(p + 0xc) + idx * 0x138;
    J3DIndTexCoordScale dflt;
    if (data[0] == 1) {
        *out = *(J3DIndTexCoordScaleInfo*)(data + (no * 4 + 0x68));
    } else {
        *out = dflt;
    }
}

extern "C" J3DFogInfo fn_800CB8C8(u8* p, s32 idx)
{
    J3DFogInfo fog;
    fog = j3dDefaultFogInfo;
    u8* base = *(u8**)(p + 4);
    u16 id = ((u16*)*(u8**)(p + 8))[idx];
    u16 v = *(u16*)(base + id * 0x14c + 0x144);
    if (v != 0xffff) {
        J3DFogInfo tmp = ((J3DFogInfo*)*(u8**)(p + 0x5c))[v];
        fog = tmp;
    }
    return fog;
}

extern unsigned int j3dDefaultBlendInfo;
extern "C" void fn_800CBA88(unsigned int* out, void* self, int idx) {
    unsigned char* p = (unsigned char*)self;
    unsigned short i = *(unsigned short*)(*(unsigned char**)(p + 4) + (*(unsigned short**)(p + 8))[idx] * 0x14c + 0x148);
    if (i != 0xffff) {
        *out = (*(unsigned int**)(p + 0x64))[i];
        return;
    }
    *out = j3dDefaultBlendInfo;
}

extern unsigned short j3dDefaultZModeID;
extern unsigned int j3dDefaultTevOrderInfoNull;
extern "C" void fn_800CBACC(unsigned short* out, void* self, int idx) {
    unsigned char* p = (unsigned char*)self;
    unsigned char i = *(unsigned char*)(*(unsigned char**)(p + 4) + (*(unsigned short**)(p + 8))[idx] * 0x14c + 6);
    if (i != 0xff) {
        unsigned char* z = *(unsigned char**)(p + 0x68) + i * 4;
        *out = z[1] * 2 + z[0] * 16 + z[2];
        return;
    }
    *out = j3dDefaultZModeID;
}

extern "C" unsigned char fn_800CBB2C(void* self, int idx) {
    unsigned char* p = (unsigned char*)self;
    unsigned char i = *(unsigned char*)(*(unsigned char**)(p + 4) + (*(unsigned short**)(p + 8))[idx] * 0x14c + 5);
    if (i != 0xff) {
        return (*(unsigned char**)(p + 0x6c))[i];
    }
    return 0;
}

extern "C" u8 fn_800CBB64(u8* param_1, s32 param_2) {
    u8 bVar1;

    bVar1 = *(u8*)(*(u8**)(param_1 + 4) + (u32)*(u16*)(*(u8**)(param_1 + 8) + param_2 * 2) * 0x14c + 7);
    if (bVar1 != 0xff) {
        return *(u8*)(*(u8**)(param_1 + 0x70) + bVar1);
    }
    return 1;
}

extern "C" void fn_800CBB9C(J3DNBTScaleInfo* param_1, u8* param_2, s32 param_3) {
    J3DNBTScaleInfo local;
    u32 uVar4;
    u8* puVar5;

    local.mHasScale = j3dDefaultNBTScaleInfo.mHasScale;
    local.mScale[0] = j3dDefaultNBTScaleInfo.mScale[0];
    local.mScale[1] = j3dDefaultNBTScaleInfo.mScale[1];
    local.mScale[2] = j3dDefaultNBTScaleInfo.mScale[2];
    uVar4 = *(u16*)(*(u8**)(param_2 + 4) + (u32)*(u16*)(*(u8**)(param_2 + 8) + param_3 * 2) * 0x14c + 0x14a);
    if (uVar4 != 0xffff) {
        puVar5 = *(u8**)(param_2 + 0x74) + (uVar4 << 4);
        param_1->mHasScale = *puVar5;
        param_1->mScale[0] = *(f32*)(puVar5 + 4);
        param_1->mScale[1] = *(f32*)(puVar5 + 8);
        param_1->mScale[2] = *(f32*)(puVar5 + 0xc);
    } else {
        *param_1 = local;
    }
}

extern "C" void fn_800CBC44(void) {
}

extern "C" u32 fn_800CBC48(void) {
    return 0x50454E4C;
}

extern "C" void** fn_800CBC54(void** param_1, short param_2) {
    if (param_1 != NULL) {
        *param_1 = lbl_8049AA38;
        if (param_1 != NULL) {
            *param_1 = __vt__10J3DPEBlock;
        }
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_800CBCB0(void) {
}

extern "C" void fn_800CBCB4(void) {
}

extern "C" void fn_800D9FE4(int param_1, int param_2);
extern "C" void fn_800CBCB8(int param_1) {
    fn_800D9FE4(param_1, *(int*)(param_1 + 4));
}

extern "C" u32 fn_800CBCDC(void) {
    return 0x54564E4C;
}

extern "C" char lbl_8049AAB4[];
extern "C" char __vt__11J3DTevBlock[];
extern "C" void** fn_800CBCE8(void** param_1, short param_2) {
    if (param_1 != NULL) {
        *param_1 = lbl_8049AAB4;
        if (param_1 != NULL) {
            *param_1 = __vt__11J3DTevBlock;
        }
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_800CBD44(void) {}

extern "C" void fn_800CBD48(void) {}

extern "C" void fn_800CBD4C(void) {}

extern "C" void fn_800CBD50(void) {}

extern "C" void fn_800CBD54(void) {}

extern "C" void fn_800CBD58(void) {
}

extern "C" void fn_800CBD5C(void) {
}

extern "C" void fn_800CBD60(void) {
}

extern "C" void fn_800CBD64(void) {
}

extern "C" void fn_800CBD68(void) {
}

extern "C" s32 fn_800CBD6C(void) {
    return 0;
}

extern "C" void fn_800CBD74(void) {
}

extern "C" void fn_800CBD78(void)
{
}

extern "C" void fn_800CBD7C(void)
{
}

extern "C" s32 fn_800CBD80(void)
{
    return 0;
}

extern "C" void fn_800CBD88(void)
{
}

extern "C" s32 fn_800CBD8C(void) {
    return 0;
}

extern "C" void fn_800CBD94(void) {
}

extern "C" void fn_800CBD98(void) {
}

extern "C" void fn_800CBD9C(void) {
}

extern "C" void fn_800CBDA0(void) {
}

extern "C" void fn_800CBDA4(void) {
}

extern "C" int fn_800CBDA8(void) {
    return 0;
}

extern "C" void fn_800CBDB0(void) {
}

extern "C" int fn_800CBDB4(void) {
    return 0;
}

extern "C" int fn_800CBDBC(void) {
    return 0;
}

extern "C" int fn_800CBDC4(void) {
    return 0;
}

extern "C" void fn_800CBDCC(void) {
}

extern "C" void fn_800CBDD0(void) {}

extern "C" void fn_800CBDD4(void) {}

extern "C" void fn_800CBDD8(void) {}

extern "C" void fn_800CBDDC(void) {
}

extern "C" void fn_800CBDE0(void) {
}

extern "C" void fn_800CBDE4(void) {
}

extern "C" void fn_800CBDE8(void) {
}

extern "C" void fn_800CBDEC(void) {
}

extern "C" u32 fn_800CBDF0(void) {
    return 0x54474E4C;
}

extern "C" char lbl_8049ABFC[];
extern "C" char __vt__13J3DColorBlock[];
extern "C" void __dl__FPv(void*);
extern "C" char lbl_8049AB90[];
extern "C" char __vt__14J3DTexGenBlock[];
extern "C" void** fn_800CBDFC(void** param_1, short param_2) {
    if (param_1 != NULL) {
        *param_1 = lbl_8049AB90;
        if (param_1 != NULL) {
            *param_1 = __vt__14J3DTexGenBlock;
        }
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" u32 fn_800CBE58(void) {
    return 0x434c4e4c;
}

extern "C" void** fn_800CBE64(void** param_1, short param_2) {
    if (param_1 != NULL) {
        *param_1 = lbl_8049ABFC;
        if (param_1 != NULL) {
            *param_1 = __vt__13J3DColorBlock;
        }
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_800CBEC0(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CBED8(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CBEF0(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CBF08(const void* base, const void* offset) {
    if (offset == 0) return 0;
    return (void*)((int)base + (int)offset);
}

extern "C" void* fn_800CBF20(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((int)base + (int)offset);
}

extern "C" void* fn_800CBF38(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((int)base + (int)offset);
}

extern "C" void* fn_800CBF50(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((int)base + (int)offset);
}

extern "C" void* fn_800CBF68(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((int)base + (int)offset);
}

extern "C" void* fn_800CBF80(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CBF98(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CBFB0(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CBFC8(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CBFE0(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CBFF8(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CC010(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CC028(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CC040(const void* base, const void* offset) {
    if (offset == 0) return 0;
    return (void*)((int)base + (int)offset);
}

extern "C" void* fn_800CC058(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

extern "C" void* fn_800CC070(const void* base, const void* offset) {
    if (offset == 0) {
        return 0;
    }
    return (void*)((unsigned int)base + (unsigned int)offset);
}

