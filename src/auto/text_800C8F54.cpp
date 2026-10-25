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

struct J3DColorChanInfo {
    u8 mEnable;    // _00
    u8 mMatSrc;    // _01
    u8 mLightMask; // _02
    u8 mDiffuseFn; // _03
    u8 mAttnFn;    // _04
    u8 mAmbSrc;    // _05
    u8 _06;        // _06
    u8 _07;        // _07
};
extern J3DColorChanInfo j3dDefaultColorChanInfo;

struct J3DMaterialInitData {
    u8 _00[0x08];
    u16 mMatColorIndex[2];         // _08
    u16 mColorChanControlIndex[4]; // _0C
    u8 _14[0xBC - 0x14];
    u16 mTevOrderInfoIndex[16]; // _BC
    u8 _DC[8];
    u16 mTevStageInfoIndex[16]; // _E4
    u8 _104[0x14C - 0x104];
};

inline u16 calcColorChanID(u16 enable, u8 matSrc, u32 lightMask, u8 diffuseFn, GXAttnFn attnFn, u8 ambSrc)
{
    u32 reg = 0;
    reg = reg & ~0x0002 | enable << 1;
    reg = reg & ~0x0001 | matSrc;
    reg = reg & ~0x0040 | ambSrc << 6;
    reg = reg & ~0x0004 | bool(lightMask & 0x01) << 2;
    reg = reg & ~0x0008 | bool(lightMask & 0x02) << 3;
    reg = reg & ~0x0010 | bool(lightMask & 0x04) << 4;
    reg = reg & ~0x0020 | bool(lightMask & 0x08) << 5;
    reg = reg & ~0x0800 | bool(lightMask & 0x10) << 11;
    reg = reg & ~0x1000 | bool(lightMask & 0x20) << 12;
    reg = reg & ~0x2000 | bool(lightMask & 0x40) << 13;
    reg = reg & ~0x4000 | bool(lightMask & 0x80) << 14;
    reg = reg & ~0x0180 | (attnFn == GX_AF_SPEC ? 0 : diffuseFn) << 7;
    reg = reg & ~0x0200 | (attnFn != GX_AF_NONE) << 9;
    reg = reg & ~0x0400 | (attnFn != GX_AF_SPEC) << 10;
    return reg;
}

struct J3DColorChan {
    J3DColorChan() { setColorChanInfo(j3dDefaultColorChanInfo); }
    J3DColorChan(const J3DColorChanInfo& info)
    {
        mChanCtrl = calcColorChanID(info.mEnable, info.mMatSrc, info.mLightMask, info.mDiffuseFn, (GXAttnFn)info.mAttnFn,
                                    info.mAmbSrc == 0xFF ? 0 : info.mAmbSrc);
    }
    void setColorChanInfo(const J3DColorChanInfo& info)
    {
        mChanCtrl = calcColorChanID(info.mEnable, info.mMatSrc, info.mLightMask, info.mDiffuseFn, (GXAttnFn)info.mAttnFn,
                                    info.mAmbSrc == 0xFFFF ? 0 : info.mAmbSrc);
    }

    u16 mChanCtrl;
};

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

class J3DColorBlock {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(u32, void*);
    virtual void v14();
    virtual void v15();
    virtual void v16(u32, void*);
    virtual void v17();
    virtual void v18(u8);
    virtual void v19();
    virtual void v20();
    virtual void v21(u32, void*);
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27(u8);
};
class J3DTexGenBlock {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(u8);
    virtual void v16();
    virtual void v17(u32, void*);
    virtual void v18();
    virtual void v19(u32, void*);
    virtual void v20();
    virtual void v21();
    virtual void v22(void*);
};
class J3DTevBlock {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19(u32, u16);
    virtual void v20();
    virtual void v21();
    virtual void v22(u32, void*);
    virtual void v23();
    virtual void v24();
    virtual void v25(u32, void*);
    virtual void v26();
    virtual void v27();
    virtual void v28(u32, void*);
    virtual void v29();
    virtual void v30();
    virtual void v31(u32, u8);
    virtual void v32();
    virtual void v33();
    virtual void v34(u32, u8);
    virtual void v35();
    virtual void v36();
    virtual void v37(u8);
    virtual void v38();
    virtual void v39();
    virtual void v40(u32, void*);
    virtual u8* v41(u32);
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45(u32, void*);
    virtual void v46();
    virtual void v47();
    virtual void v48(u32, void*);
};
class J3DIndBlock {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(u8);
    virtual void v8();
    virtual void v9(u32, void*);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(u32, void*);
    virtual void v14();
    virtual void v15();
    virtual void v16(u32, void*);
};
class J3DPEBlock {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(void*);
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14(void*);
    virtual void v15();
    virtual void v16();
    virtual void v17(void*);
    virtual void v18();
    virtual void v19();
    virtual void v20(void*);
    virtual void v21();
    virtual void v22();
    virtual void v23(u8);
    virtual void v24();
    virtual void v25();
    virtual void v26(u8);
};

class J3DMaterial {
public:
    void initialize();
};
class J3DLockedMaterial : public J3DMaterial {
public:
    void initialize();
};
class J3DPatchedMaterial : public J3DMaterial {
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

extern s32 lbl_8053BC70;

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

struct J3DNBTScale : public J3DNBTScaleInfo {
    J3DNBTScale() {
        mHasScale = j3dDefaultNBTScaleInfo.mHasScale;
        mScale[0] = j3dDefaultNBTScaleInfo.mScale[0];
        mScale[1] = j3dDefaultNBTScaleInfo.mScale[1];
        mScale[2] = j3dDefaultNBTScaleInfo.mScale[2];
    }
};
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
extern "C" void* createColorBlock__11J3DMaterialFUl(u32);
extern "C" void* createIndBlock__11J3DMaterialFi(int);
extern "C" void* createPEBlock__11J3DMaterialFUlUl(u32, u32);
extern "C" void fn_800D36EC(void* tev);
extern "C" char __vt__18J3DPatchedMaterial[];
extern "C" char __vt__21J3DTexGenBlockPatched[];
extern "C" char lbl_8049B440[];
extern "C" void __construct_array(void* p, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void initialize__21J3DTexGenBlockPatchedFv(void* p);
extern "C" void __ct__11J3DTexCoordFv(void* self);
extern "C" void __ct__11J3DTevOrderFv(void* self);
extern "C" void __ct__11J3DTevStageFv(void* self);
extern "C" u8 fn_800CB428(u8* p, s32 idx);
extern "C" u8 fn_800CAF38(u8* p, s32 idx);
extern "C" u8 fn_800CB28C(u8* p, s32 idx);
extern "C" void fn_800CBACC(unsigned short* out, void* self, int idx);
extern "C" unsigned char fn_800CBB2C(void* self, int idx);
extern "C" u8 fn_800CBB64(u8* p, s32 idx);
extern "C" u16 fn_800CB2CC(u8* p, s32 idx, s32 b);
extern "C" J3DFogInfo fn_800CB8C8(u8* p, s32 idx);
extern "C" void fn_800CBA08(u16* param_1, u8* param_2, s32 param_3);
extern "C" void fn_800CBA88(unsigned int* out, void* self, int idx);
extern "C" void fn_800CB314(u32* out, u8* p, s32 idx, s32 b);
extern "C" void fn_800CB3D0(u32* out, u8* p, s32 idx, s32 b);
extern "C" void fn_800CB360(u32* out, u8* p, s32 idx, s32 b);
extern "C" void fn_800CB460(void* out, u8* p, s32 idx, s32 b);
extern "C" u8 fn_800CB5BC(u8* p, s32 idx);
extern "C" J3DIndTexMtxInfo fn_800CB628(u8* p, s32 idx, s32 b);
extern "C" void fn_800CB5E4(u32* out, u8* p, s32 idx, s32 stage);
extern "C" void fn_800CB6F0(J3DIndTevStage* out, u8* p, s32 idx, s32 stage);
extern "C" void fn_800CAEE0(s32* param_1, int param_2, int param_3, int param_4);
extern "C" u8 fn_800CB15C(u8* p, s32 idx);
extern "C" void* fn_800CB1F4(u8* p, s32 idx, s32 b);
struct J3DIndTexCoordScaleInfo;
extern "C" J3DColorChan fn_800CAF70(const J3DMaterialFactory* self, int idx, int no);
extern "C" void fn_800CB884(J3DIndTexCoordScaleInfo* out, u8* p, s32 idx, s32 no);
extern "C" void __ct__14J3DIndTevStageFv(void* self);
extern "C" void __ct__13J3DGXColorS10Fv(void* self);
extern "C" void __ct__10J3DGXColorFv(void* self);

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

extern "C" void* createTexGenBlock__11J3DMaterialFUl(u32);
extern "C" void* createTevBlock__11J3DMaterialFi(int);
extern "C" void fn_800CBB9C(J3DNBTScaleInfo* out, u8* p, s32 idx);
extern "C" void fn_800CB104(s32* out, u8* p, s32 idx, s32 no);
extern "C" void fn_800CB520(u8* out, u8* p, s32 idx, s32 no);
extern "C" J3DMaterial* fn_800C92E8(const J3DMaterialFactory* self, J3DMaterial* material, int idx, u32 flags) {
    u32 nTev, colorFlag, nTex, peFlag, texFlag, indFlag, nTexNo;
    u8 nInd;
    u8 swapAlpha;
    u8 swapColor;
    J3DFogInfo fog;
    J3DIndTexMtxInfo imtx;
    J3DNBTScaleInfo nbtCopy, nbt;
    u32 texCoordCopy[2], stageCopy[2], stage[2], color[2], texCoord[2];
    u16 alpha[2];
    unsigned int blend;
    u32 orderCopy, order, kcolor;
    s32 ambient, matcolor;
    u32 indOrderCopy, indOrder, indScale, indStageCopy, indStage;
    u16 chanCopy[2], zCopy[2], z[2], chan[2];
    u8 kselCopy[4], ksel[4];
    if (self->mDisplayLists != 0) return fn_800CA7F0(self,material,idx,flags);
    u16 remapped=self->mMatRemapTable[idx];
    u8* init=(u8*)self->mInitData+remapped*0x14c;
    u32 textures=0;
    u32 stages=textures;
    if (init[4]!=0xff) stages=((u8*)self->unk_0C[16])[init[4]];
    for (u32 j=0; j<8; j++) {
        if (*(u16*)(init+0x84+j*2)!=0xffff) textures++;
    }
    if (stages!=textures && textures!=0) {
        if (stages>textures) textures=stages;
    } else textures=stages;
    nTev=(flags>>16)&0x1f;
    if (textures>nTev) nTev=textures;
    nTexNo=nTev>8?8:nTev;
    if (init[3]!=0xff) nTex=((u8*)self->unk_0C[6])[init[3]];
    else nTex=0;
    indFlag=(flags>>24)&1;
    peFlag=flags&0x30000000;
    colorFlag=flags&0xc0000000;
    texFlag=nTex>4?0:flags&0x0c000000;
    if (!material) {
        material=(J3DMaterial*)operator new(0x4c);
        if (material) {
            *(void**)material=__vt__11J3DMaterial;
            *(u32*)((u8*)material+0x40)=0x3cf3cf00;
            *(u32*)((u8*)material+0x44)=0x00f3cf3c;
            material->initialize();
        }
    }
    *(void**)((u8*)material + 0x24)=createColorBlock__11J3DMaterialFUl(colorFlag);
    *(void**)((u8*)material + 0x28)=createTexGenBlock__11J3DMaterialFUl(texFlag);
    *(void**)((u8*)material + 0x2c)=createTevBlock__11J3DMaterialFi((u16)nTev);
    *(void**)((u8*)material + 0x30)=createIndBlock__11J3DMaterialFi(indFlag);
    *(void**)((u8*)material + 0x34)=createPEBlock__11J3DMaterialFUlUl(peFlag,((u8*)self->mInitData)[self->mMatRemapTable[idx]*0x14c]);
    *(u16*)((u8*)material+0x14)=idx;
    *(u32*)((u8*)material+0x10)=((u8*)self->mInitData)[self->mMatRemapTable[idx]*0x14c];
    ((J3DColorBlock*)*(void**)((u8*)material + 0x24))->v18(((u8 (*)(const J3DMaterialFactory*, int))fn_800CAF38)(self,idx));
    ((J3DColorBlock*)*(void**)((u8*)material + 0x24))->v27(((u8 (*)(const J3DMaterialFactory*, int))fn_800CB28C)(self,idx));
    ((J3DTexGenBlock*)*(void**)((u8*)material + 0x28))->v15(((u8 (*)(const J3DMaterialFactory*, int))fn_800CB15C)(self,idx));
    ((void (*)(void*, const J3DMaterialFactory*, int))fn_800CBB9C)(&nbt,self,idx);
    ((u32*)&nbtCopy)[0]=((u32*)&nbt)[0];
    ((u32*)&nbtCopy)[1]=((u32*)&nbt)[1];
    ((u32*)&nbtCopy)[2]=((u32*)&nbt)[2];
    ((u32*)&nbtCopy)[3]=((u32*)&nbt)[3];
    ((J3DTexGenBlock*)*(void**)((u8*)material + 0x28))->v22(&nbtCopy);
    ((void (*)(void*,const J3DMaterialFactory*,int))fn_800CB8C8)(&fog,self,idx);
    ((J3DPEBlock*)*(void**)((u8*)material + 0x34))->v10(&fog);
    ((void (*)(void*, const J3DMaterialFactory*, int))fn_800CBA08)(alpha,self,idx);
    ((J3DPEBlock*)*(void**)((u8*)material + 0x34))->v14(alpha);
    fn_800CBA88(&blend,(void*)self,idx);
    ((J3DPEBlock*)*(void**)((u8*)material + 0x34))->v17(&blend);
    fn_800CBACC(z,(void*)self,idx);
    zCopy[0]=z[0];
    ((J3DPEBlock*)*(void**)((u8*)material + 0x34))->v20(zCopy);
    ((J3DPEBlock*)*(void**)((u8*)material + 0x34))->v23(fn_800CBB2C((void*)self,idx));
    ((J3DPEBlock*)*(void**)((u8*)material + 0x34))->v26(((u8 (*)(const J3DMaterialFactory*, int))fn_800CBB64)(self,idx));
    ((J3DTevBlock*)*(void**)((u8*)material + 0x2c))->v37(((u8 (*)(const J3DMaterialFactory*, int))fn_800CB428)(self,idx));
    for(u8 i=0;i<nTexNo;i++) {
        ((J3DTevBlock*)*(void**)((u8*)material + 0x2c))->v19(i,((u16 (*)(const J3DMaterialFactory*, int, int))fn_800CB2CC)(self,idx,i));
    }
    for(u8 i=0;i<nTev;i++) {
        ((void (*)(void*, const J3DMaterialFactory*, int, int))fn_800CB314)(&order,self,idx,i); orderCopy=order;
        ((J3DTevBlock*)*(void**)((u8*)material + 0x2c))->v22(i, &orderCopy);
    }
    u32 no;
    u16* swap;
    u32 stageIndex;
    u8* entry;
    u8* data=(u8*)self->mInitData;
    u16* remap=self->mMatRemapTable;
    for(stageIndex=0;(u8)stageIndex<nTev;stageIndex++) {
        entry=data+remap[idx]*0x14c;
        ((void (*)(void*, const J3DMaterialFactory*, int, int))fn_800CB460)(stage,self,idx,(u8)stageIndex);
        no=(u8)stageIndex;
        stageCopy[0]=stage[0];stageCopy[1]=stage[1];
        ((J3DTevBlock*)*(void**)((u8*)material + 0x2c))->v40(no, stageCopy);
        swap=(u16*)(entry+0x104+no*2);
        if (*swap!=0xffff) {
            swapAlpha=((u8*)self->unk_0C[18])[*swap*4+1];
            u8* st=((J3DTevBlock*)*(void**)((u8*)material + 0x2c))->v41(no);
            st[7]=(st[7]&~0xc)|(swapAlpha<<2);
            u8* swapTable=(u8*)self->unk_0C[18];
            swapColor=swapTable[*swap*4];
            st=((J3DTevBlock*)*(void**)((u8*)material + 0x2c))->v41(no);
            st[7]=(st[7]&~3)|swapColor;
        }
    }
    for(u8 i=0;i<4;i++) {
        ((void (*)(void*, const J3DMaterialFactory*, int, int))fn_800CB3D0)(&kcolor,self,idx,i);
        ((J3DTevBlock*)*(void**)((u8*)material + 0x2c))->v28(i, &kcolor);
    }
    for(u8 i=0;i<4;i++) {
        ((void (*)(void*, const J3DMaterialFactory*, int, int))fn_800CB360)(color,self,idx,i);
        ((J3DTevBlock*)*(void**)((u8*)material + 0x2c))->v25(i, color);
    }
    for(u8 i=0;i<4;i++) {
        ((void (*)(void*, const J3DMaterialFactory*, int, int))fn_800CB520)(ksel,self,idx,i);kselCopy[0]=ksel[0];
        ((J3DTevBlock*)*(void**)((u8*)material + 0x2c))->v45(i, kselCopy);
    }
    for(u8 i=0;i<2;i++) {
        ((void (*)(void*, const J3DMaterialFactory*, int, int))fn_800CB104)(&ambient,self,idx,i);
        ((J3DColorBlock*)*(void**)((u8*)material + 0x24))->v16(i, &ambient);
    }
    for(u8 i=0;i<2;i++) {
        ((void (*)(void*,const J3DMaterialFactory*,int,int))fn_800CAEE0)(&matcolor,self,idx,i);
        ((J3DColorBlock*)*(void**)((u8*)material + 0x24))->v13(i, &matcolor);
    }
    for(u8 i=0;i<4;i++) {
        ((void (*)(void*,const J3DMaterialFactory*,int,int))fn_800CAF70)(chan,self,idx,i);
        chanCopy[0]=chan[0];
        ((J3DColorBlock*)*(void**)((u8*)material + 0x24))->v21(i, chanCopy);
    }
    for(u8 i=0;i<nTex;i++) {
        ((void (*)(u32*,const J3DMaterialFactory*,int,int))fn_800CB194)(texCoord,self,idx,i);
        texCoordCopy[0]=texCoord[0];*(u16*)&texCoordCopy[1]=*(u16*)&texCoord[1];
        ((J3DTexGenBlock*)*(void**)((u8*)material + 0x28))->v17(i, texCoordCopy);
    }
    for(u8 i=0;i<8;i++) {
        ((J3DTexGenBlock*)*(void**)((u8*)material + 0x28))->v19(i,((void* (*)(const J3DMaterialFactory*, int, int))fn_800CB1F4)(self,idx,i));
    }
    init=(u8*)self->mInitData+self->mMatRemapTable[idx]*0x14c;
    for(u8 i=0;i<nTev;i++) {
        u32 no=i;
        u8 v=init[0x9c+no];
        if(v!=0xff) ((J3DTevBlock*)*(void**)((u8*)material + 0x2c))->v31(no,v);
        else ((J3DTevBlock*)*(void**)((u8*)material + 0x2c))->v31(no,0xc);
    }
    for(u8 i=0;i<nTev;i++) {
        u32 no=i;
        u8 v=init[0xac+no];
        if(v!=0xff) ((J3DTevBlock*)*(void**)((u8*)material + 0x2c))->v34(no,v);
        else ((J3DTevBlock*)*(void**)((u8*)material + 0x2c))->v34(no,0x1c);
    }
    if(self->unk_0C[0]) {
        nInd=((u8 (*)(const J3DMaterialFactory*, int))fn_800CB5BC)(self,idx);
        ((J3DIndBlock*)*(void**)((u8*)material + 0x30))->v7(((u8 (*)(const J3DMaterialFactory*, int))fn_800CB5BC)(self,idx));
        for(u8 i=0;i<nInd;i++) {
            ((void (*)(void*,const J3DMaterialFactory*,int,int))fn_800CB628)(&imtx,self,idx,i);
            ((J3DIndBlock*)*(void**)((u8*)material + 0x30))->v13(i, &imtx);
        }
        for(u8 i=0;i<nInd;i++) {
            ((void (*)(void*, const J3DMaterialFactory*, int, int))fn_800CB5E4)(&indOrder,self,idx,i);indOrderCopy=indOrder;
            ((J3DIndBlock*)*(void**)((u8*)material + 0x30))->v9(i, &indOrderCopy);
        }
        for(u8 i=0;i<nInd;i++) {
            ((void (*)(void*, const J3DMaterialFactory*, int, int))fn_800CB884)((J3DIndTexCoordScaleInfo*)&indScale,self,idx,i);
            ((J3DIndBlock*)*(void**)((u8*)material + 0x30))->v16(i, &indScale);
        }
        for(u8 i=0;i<nTev;i++) {
            ((void (*)(void*, const J3DMaterialFactory*, int, int))fn_800CB6F0)((J3DIndTevStage*)&indStage,self,idx,i);indStageCopy=indStage;
            ((J3DTevBlock*)*(void**)((u8*)material + 0x2c))->v48(i, &indStageCopy);
        }
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

extern "C" J3DMaterial* fn_800C9D20(const J3DMaterialFactory* self, J3DMaterial* material, int idx, u32 flags)
{
    u8 nStages;
    u8 i;
    u32 hasInd;
    void* blk;
    void* tg;
    J3DFogInfo s88;
    u16 s40[2];
    unsigned int s3c;
    u16 s0c;
    u16 s10;
    u32 s34;
    u32 s38;
    u32 s30;
    u32 s5c;
    u32 s4c[2];
    u32 s54[2];
    u32 s2c;
    u16 s08;
    u16 s14;
    u8 s44[8];
    u8 s64[8];
    u8 nTex;
    u8 nInd;
    u16 ci;
    u8 gen;

    if (material == NULL) {
        J3DMaterial* newMat = (J3DMaterial*)operator new(0x4c);
        if (newMat != NULL) {
            *(void**)newMat = __vt__11J3DMaterial;
            *(u32*)((u8*)newMat + 0x40) = 0x3CF3CF00;
            *(u32*)((u8*)newMat + 0x44) = 0x00F3CF3C;
            newMat->initialize();
            *(void**)newMat = __vt__18J3DPatchedMaterial;
            ((J3DPatchedMaterial*)newMat)->initialize();
            material = newMat;
        }
    }
    hasInd = (flags & 0x03000000) != 0;
    *(void**)((u8*)material + 0x24) = createColorBlock__11J3DMaterialFUl(0x40000000);

    blk = operator new(0x5c);
    if (blk != NULL) {
        tg = blk;
        *(void**)tg = __vt__14J3DTexGenBlock;
        *(void**)tg = __vt__21J3DTexGenBlockPatched;
        __construct_array((u8*)tg + 8, __ct__11J3DTexCoordFv, 0, 6, 8);
        initialize__21J3DTexGenBlockPatchedFv(tg);
    }
    *(void**)((u8*)material + 0x28) = blk;

    blk = operator new(0xd8);
    if (blk != NULL) {
        *(void**)blk = __vt__11J3DTevBlock;
        *(void**)blk = lbl_8049B440;
        __construct_array((u8*)blk + 0x18, __ct__11J3DTevOrderFv, 0, 4, 8);
        __construct_array((u8*)blk + 0x38, __ct__11J3DTevStageFv, 0, 8, 8);
        __construct_array((u8*)blk + 0x78, __ct__14J3DIndTevStageFv, 0, 4, 8);
        __construct_array((u8*)blk + 0x98, __ct__13J3DGXColorS10Fv, 0, 8, 4);
        __construct_array((u8*)blk + 0xb8, __ct__10J3DGXColorFv, 0, 4, 4);
        fn_800D36EC(blk);
    }
    *(void**)((u8*)material + 0x2c) = blk;
    *(void**)((u8*)material + 0x30) = createIndBlock__11J3DMaterialFi(hasInd);
    *(void**)((u8*)material + 0x34) = createPEBlock__11J3DMaterialFUlUl(0x10000000, ((u8*)self->mInitData)[((u16*)self->mMatRemapTable)[idx] * 0x14c]);
    *(u16*)((u8*)material + 0x14) = idx;
    *(u32*)((u8*)material + 0x10) = ((u8*)self->mInitData)[((u16*)self->mMatRemapTable)[idx] * 0x14c];
    (*(void (***)(void*, u32))*(void**)((u8*)material + 0x2c))[37](*(void**)((u8*)material + 0x2c), fn_800CB428((u8*)self, idx));
    (*(void (***)(void*, u32))*(void**)((u8*)material + 0x24))[18](*(void**)((u8*)material + 0x24), fn_800CAF38((u8*)self, idx));
    (*(void (***)(void*, u32))*(void**)((u8*)material + 0x24))[27](*(void**)((u8*)material + 0x24), fn_800CB28C((u8*)self, idx));
    s88 = fn_800CB8C8((u8*)self, idx);
    (*(void (***)(void*, void*))*(void**)((u8*)material + 0x34))[10](*(void**)((u8*)material + 0x34), &s88);
    fn_800CBA08(s40, (u8*)self, idx);
    (*(void (***)(void*, void*))*(void**)((u8*)material + 0x34))[14](*(void**)((u8*)material + 0x34), s40);
    fn_800CBA88(&s3c, (void*)self, idx);
    (*(void (***)(void*, void*))*(void**)((u8*)material + 0x34))[17](*(void**)((u8*)material + 0x34), &s3c);
    fn_800CBACC(&s0c, (void*)self, idx);
    s10 = s0c;
    (*(void (***)(void*, void*))*(void**)((u8*)material + 0x34))[20](*(void**)((u8*)material + 0x34), &s10);
    (*(void (***)(void*, u32))*(void**)((u8*)material + 0x34))[23](*(void**)((u8*)material + 0x34), fn_800CBB2C((void*)self, idx));
    (*(void (***)(void*, u32))*(void**)((u8*)material + 0x34))[26](*(void**)((u8*)material + 0x34), fn_800CBB64((u8*)self, idx));
    nStages = (*(u8 (***)(void*))*(void**)((u8*)material + 0x2c))[38](*(void**)((u8*)material + 0x2c));
    for (i = 0; i < 8; i++) {
        (*(void (***)(void*, u32, u16))*(void**)((u8*)material + 0x2c))[19](*(void**)((u8*)material + 0x2c), i, fn_800CB2CC((u8*)self, idx, i));
    }
    for (i = 0; i < nStages; i++) {
        fn_800CB314(&s34, (u8*)self, idx, i);
        s38 = s34;
        (*(void (***)(void*, u32, void*))*(void**)((u8*)material + 0x2c))[22](*(void**)((u8*)material + 0x2c), i, &s38);
    }
    for (i = 0; i < 4; i++) {
        fn_800CB3D0(&s30, (u8*)self, idx, i);
        (*(void (***)(void*, u32, void*))*(void**)((u8*)material + 0x2c))[28](*(void**)((u8*)material + 0x2c), i, &s30);
    }
    for (i = 0; i < 4; i++) {
        fn_800CB360(&s5c, (u8*)self, idx, i);
        (*(void (***)(void*, u32, void*))*(void**)((u8*)material + 0x2c))[25](*(void**)((u8*)material + 0x2c), i, &s5c);
    }
    for (i = 0; i < nStages; i++) {
        u8* initData = (u8*)self->mInitData + ((u16*)self->mMatRemapTable)[idx] * 0x14c;
        fn_800CB460(s4c, (u8*)self, idx, i);
        s54[0] = s4c[0];
        s54[1] = s4c[1];
        (*(void (***)(void*, u32, void*))*(void**)((u8*)material + 0x2c))[40](*(void**)((u8*)material + 0x2c), i, s54);
        ci = *(u16*)(initData + 0x104 + i * 2);
        if (ci != 0xffff) {
            u8* obj = (u8*)(*(void* (***)(void*, u32))*(void**)((u8*)material + 0x2c))[41](*(void**)((u8*)material + 0x2c), i);
            obj[7] = (obj[7] & 0xf3) | (((u8*)*(void**)((u8*)self + 0x54))[ci * 4 + 1] << 2);
            u8 v = ((u8*)*(void**)((u8*)self + 0x54))[ci * 4];
            obj = (u8*)(*(void* (***)(void*, u32))*(void**)((u8*)material + 0x2c))[41](*(void**)((u8*)material + 0x2c), i);
            obj[7] = (obj[7] & 0xfc) | v;
        }
    }
    {
        u8* initData = (u8*)self->mInitData + ((u16*)self->mMatRemapTable)[idx] * 0x14c;
        for (i = 0; i < nStages; i++) {
            u8 v = initData[0x9c + i];
            (*(void (***)(void*, u32, u32))*(void**)((u8*)material + 0x2c))[31](*(void**)((u8*)material + 0x2c), i, v == 0xff ? 0xc : v);
        }
    }
    for (i = 0; i < 2; i++) {
        fn_800CAEE0((s32*)&s2c, (int)self, idx, i);
        (*(void (***)(void*, u32, void*))*(void**)((u8*)material + 0x24))[13](*(void**)((u8*)material + 0x24), i, &s2c);
    }
    for (i = 0; i < 4; i++) {
        ((void (*)(void*, const void*, u32, u32))fn_800CAF70)(&s08, self, idx, i);
        s14 = s08;
        (*(void (***)(void*, u32, void*))*(void**)((u8*)material + 0x24))[21](*(void**)((u8*)material + 0x24), i, &s14);
    }
    gen = ((u8*)self->mInitData)[((u16*)self->mMatRemapTable)[idx] * 0x14c + 3];
    if (gen != 0xff) {
        nTex = ((u8*)*(void**)((u8*)self + 0x24))[gen];
    } else {
        nTex = 0;
    }
    (*(void (***)(void*, u32))*(void**)((u8*)material + 0x28))[15](*(void**)((u8*)material + 0x28), fn_800CB15C((u8*)self, idx));
    for (i = 0; i < 8; i++) {
        (*(void (***)(void*, u32, void*))*(void**)((u8*)material + 0x28))[19](*(void**)((u8*)material + 0x28), i, fn_800CB1F4((u8*)self, idx, i));
    }
    for (i = 0; i < nTex; i++) {
        ((void (*)(u32*, u8*, s32))fn_800CB194)((u32*)s44, (u8*)self, idx);
        *(u32*)s64 = *(u32*)s44;
        *(u16*)(s64 + 4) = *(u16*)(s44 + 4);
        (*(void (***)(void*, u32, void*))*(void**)((u8*)material + 0x28))[17](*(void**)((u8*)material + 0x28), i, s64);
    }
    if (hasInd != 0 && *(void**)((u8*)self + 0x0c) != NULL) {
        u32 s_cc;
        u32 s_c8;
        u32 s_d0;
        u32 s_d4;
        u32 s_d8;
        nInd = fn_800CB5BC((u8*)self, idx);
        (*(void (***)(void*, u32))*(void**)((u8*)material + 0x30))[7](*(void**)((u8*)material + 0x30), fn_800CB5BC((u8*)self, idx));
        for (i = 0; i < nInd; i++) {
            J3DIndTexMtxInfo s84 = fn_800CB628((u8*)self, idx, i);
            (*(void (***)(void*, u32, void*))*(void**)((u8*)material + 0x30))[13](*(void**)((u8*)material + 0x30), i, &s84);
        }
        for (i = 0; i < nInd; i++) {
            fn_800CB5E4(&s_cc, (u8*)self, idx, i);
            s_c8 = s_cc;
            (*(void (***)(void*, u32, void*))*(void**)((u8*)material + 0x30))[9](*(void**)((u8*)material + 0x30), i, &s_c8);
        }
        for (i = 0; i < nInd; i++) {
            fn_800CB884((J3DIndTexCoordScaleInfo*)&s_d0, (u8*)self, idx, i);
            (*(void (***)(void*, u32, void*))*(void**)((u8*)material + 0x30))[16](*(void**)((u8*)material + 0x30), i, &s_d0);
        }
        for (i = 0; i < nStages; i++) {
            fn_800CB6F0((J3DIndTevStage*)&s_d8, (u8*)self, idx, i);
            s_d4 = s_d8;
            (*(void (***)(void*, u32, void*))*(void**)((u8*)material + 0x2c))[48](*(void**)((u8*)material + 0x2c), i, &s_d4);
        }
    }
    return material;
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

extern "C" J3DMaterial* fn_800CA7F0(const J3DMaterialFactory* self, J3DMaterial* material, int idx, u32 flags)
{
    void** tev;
    u8* data;
    if (material == NULL) {
        material = (J3DMaterial*)operator new(0x4c);
        if (material != NULL) {
            *(void**)material = __vt__11J3DMaterial;
            *(u32*)((u8*)material + 0x40) = 0x3CF3CF00;
            *(u32*)((u8*)material + 0x44) = 0x00F3CF3C;
            material->initialize();
            *(void**)material = __vt__17J3DLockedMaterial;
            ((J3DLockedMaterial*)material)->initialize();
        }
        void** blk = (void**)operator new(4);
        if (blk != NULL) {
            *blk = __vt__13J3DColorBlock;
            *blk = lbl_8049ABFC;
            *(void***)((u8*)material + 0x24) = blk;
        }
        void** tex = (void**)operator new(4);
        if (tex != NULL) {
            *tex = __vt__14J3DTexGenBlock;
            *tex = lbl_8049AB90;
            *(void***)((u8*)material + 0x28) = tex;
        }
        tev = (void**)operator new(8);
        if (tev != NULL) {
            *tev = __vt__11J3DTevBlock;
            *tev = lbl_8049AAB4;
            fn_800D36E0(tev);
            *(void***)((u8*)material + 0x2c) = tev;
        }
        void** ind = (void**)operator new(4);
        if (ind != NULL) {
            *ind = __vt__11J3DIndBlock;
            *ind = __vt__15J3DIndBlockNull;
            *(void***)((u8*)material + 0x30) = ind;
        }
        void** pe = (void**)operator new(4);
        if (pe != NULL) {
            *pe = __vt__10J3DPEBlock;
            *pe = lbl_8049AA38;
            *(void***)((u8*)material + 0x34) = pe;
        }
        *(u16*)((u8*)material + 0x14) = idx;
        *(u32*)((u8*)material + 0x10) = ((u8*)self->mPEModes)[idx];
    }
    data = (u8*)self->mCurrMtxInfo + idx * 8;
    *(u32*)((u8*)material + 0x40) = ((u32*)data)[0];
    *(u32*)((u8*)material + 0x44) = ((u32*)data)[1];
    (*(void (***)(void*, u16))*(void**)((u8*)material + 0x24))[31](*(void**)((u8*)material + 0x24), *(u16*)((u8*)self->mPatchInfo + idx * 16));
    (*(void (***)(void*, u16))*(void**)((u8*)material + 0x24))[32](*(void**)((u8*)material + 0x24), *(u16*)((u8*)self->mPatchInfo + idx * 16 + 2));
    (*(void (***)(void*, u16))*(void**)((u8*)material + 0x28))[25](*(void**)((u8*)material + 0x28), *(u16*)((u8*)self->mPatchInfo + idx * 16 + 4));
    (*(void (***)(void*, u16))*(void**)((u8*)material + 0x2c))[52](*(void**)((u8*)material + 0x2c), *(u16*)((u8*)self->mPatchInfo + idx * 16 + 6));
    (*(void (***)(void*, u16))*(void**)((u8*)material + 0x2c))[53](*(void**)((u8*)material + 0x2c), *(u16*)((u8*)self->mPatchInfo + idx * 16 + 8));
    (*(void (***)(void*, u16))*(void**)((u8*)material + 0x34))[29](*(void**)((u8*)material + 0x34), *(u16*)((u8*)self->mPatchInfo + idx * 16 + 10));
    if (*(void**)((u8*)material + 0x48) == NULL) {
        void** dl = (void**)operator new(0x10);
        if (dl != NULL) {
            dl[0] = NULL;
            dl[1] = NULL;
            dl[2] = NULL;
            dl[3] = NULL;
        }
        *(void***)((u8*)material + 0x48) = dl;
        u32* piVar3 = (u32*)((u8*)self->mDisplayLists + idx * 8);
        ((J3DDisplayListObj*)dl)->setSingleDisplayList((u8*)piVar3 + piVar3[0], piVar3[1]);
    }
    return material;
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
        u32 texGenNum = 0;
        u32 tevNum = 0;
        u32 tevStageNum;
        u32 indNum;
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
            } else {
                indNum = 0;
            }
        }
        peFlags = flags & 0x30000000;
        texGenFlags = flags & 0x0C000000 & ~-(u32)(indNum > 4);
        indFlag = (flags >> 24) & 1;

        if (mat == NULL) {
            size = 0x4c;
        }
        size += calcSizeColorBlock__11J3DMaterialFUl(flags & 0xC0000000);
        size += calcSizeTexGenBlock__11J3DMaterialFUl(texGenFlags);
        size += calcSizeTevBlock__11J3DMaterialFi((u16)tevStageNum);
        size += calcSizeIndBlock__11J3DMaterialFi(indFlag);
        size += calcSizePEBlock__11J3DMaterialFUlUl(peFlags, *(u8*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c));

        u8* cur = *(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c;
        if (*(u16*)(cur + 0x48) != 0xffff) {
            size += 0x94;
        }
        if (*(u16*)(cur + 0x4a) != 0xffff) {
            size += 0x94;
        }
        if (*(u16*)(cur + 0x4c) != 0xffff) {
            size += 0x94;
        }
        if (*(u16*)(cur + 0x4e) != 0xffff) {
            size += 0x94;
        }
        if (*(u16*)(cur + 0x50) != 0xffff) {
            size += 0x94;
        }
        if (*(u16*)(cur + 0x52) != 0xffff) {
            size += 0x94;
        }
        if (*(u16*)(cur + 0x54) != 0xffff) {
            size += 0x94;
        }
        if (*(u16*)(cur + 0x56) != 0xffff) {
            size += 0x94;
        }
    }
    return size;
}

extern "C" u32 calcSizeColorBlock__11J3DMaterialFUl(u32);
extern "C" u32 calcSizeIndBlock__11J3DMaterialFi(int);
extern "C" u32 calcSizePEBlock__11J3DMaterialFUlUl(u32, u32);
extern "C" u32 fn_800CAD8C(u8* p, void* mat, s32 idx, u32 flags) {
    u32 ind = (flags & 0x03000000) != 0;
    u32 size = mat == NULL ? 0x4c : 0;
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
    const J3DMaterialFactory* self = (const J3DMaterialFactory*)param_2;
    Col def = *(Col*)&lbl_8053BC70;
    J3DMaterialInitData* initData = &((J3DMaterialInitData*)self->mInitData)[self->mMatRemapTable[param_3]];
    if (initData->mMatColorIndex[param_4] != 0xffff) {
        *param_1 = (*(s32**)((u8*)self + 0x10))[initData->mMatColorIndex[param_4]];
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

extern "C" J3DColorChan fn_800CAF70(const J3DMaterialFactory* self, int idx, int no)
{
    J3DMaterialInitData* initData = &((J3DMaterialInitData*)self->mInitData)[self->mMatRemapTable[idx]];
    if (initData->mColorChanControlIndex[no] != 0xffff) {
        J3DColorChanInfo* chanInfo = *(J3DColorChanInfo**)((u8*)self + 0x18);
        return J3DColorChan(chanInfo[initData->mColorChanControlIndex[no]]);
    }
    return J3DColorChan();
}

extern "C" void fn_800CB104(s32* out, u8* p, s32 a, s32 b) {
    s32 def = lbl_8053BC74;
    s32* pdef = &def;
    s32 boff = b * 2;
    u16* ids = *(u16**)(p + 8);
    u8* base = *(u8**)(p + 4);
    s32 idx = ids[a] * 0x14c + 0x14;
    idx += boff;
    u16 v = *(u16*)(base + idx);
    if (v != 0xffff) {
        *out = (*(s32**)(p + 0x1c))[v];
    } else {
        *out = *pdef;
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
    void* ret;
    u32 off = ids[idx] * 0x14c + 0x48;
    off += b * 2;
    if (*(u16*)(base + off) == 0xffff) {
        return NULL;
    }
    ret = __nw__FUl(0x94);
    if (ret != NULL) {
        __as__13J3DTexMtxInfoFRC13J3DTexMtxInfo(ret, *(u8**)(p + 0x30) + *(u16*)(base + off) * 0x64);
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
    u8* data = (u8*)&((J3DMaterialInitData*)*(void**)(p + 4))[(*(u16**)(p + 8))[idx]] + 0x84;
    u16 v = *(u16*)(data + b * 2);
    if (v != 0xffff) return (*(u16**)(p + 0x38))[v];
    return 0xffff;
}

extern unsigned int j3dDefaultTevOrderInfoNull;
extern "C" void fn_800CB314(u32* out, u8* p, s32 idx, s32 b) {
    const u16* ids = *(const u16**)(p + 8);
    unsigned int off = ids[idx] * 0x14c;
    unsigned int i = off + 0xbc;
    const u8* base = *(const u8**)(p + 4);
    i += b * 2;
    u16 v = *(const u16*)(base + i);
    if (v != 0xffff) {
        *out = (*(const u32**)(p + 0x40))[v];
        return;
    }
    *out = j3dDefaultTevOrderInfoNull;
}

struct FsaTevColorS10 {
    u32 rg, ba;
};
extern u32 lbl_80543F08;
extern u32 lbl_80543F0C;
extern u32 lbl_8053BC78;
extern "C" void* fn_800CB4C0(void* out, u8* e);
extern "C" void __ct__11J3DTevStageFv(void* self);
extern "C" void fn_800CB360(u32* out, u8* p, s32 idx, s32 b) {
    FsaTevColorS10 def = *(FsaTevColorS10*)&lbl_80543F08;
    u8* base = *(u8**)(p + 4);
    u16* ids = *(u16**)(p + 8);
    u32 off = ids[idx] * 0x14c + 0xdc;
    off += b * 2;
    u16 v = *(u16*)(base + off);
    if (v != 0xffff) {
        FsaTevColorS10 e = ((FsaTevColorS10*)*(u8**)(p + 0x44))[v];
        *(FsaTevColorS10*)out = e;
        return;
    }
    *(FsaTevColorS10*)out = def;
}

extern "C" void fn_800CB3D0(u32* out, u8* p, s32 idx, s32 b) {
    u32 off = ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x94;
    u16 v = *(u16*)(*(u8**)(p + 4) + off + (b << 1));
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
    idx = (*(u16**)(p + 8))[idx];
    J3DMaterialInitData* initData = &((J3DMaterialInitData*)*(void**)(p + 4))[idx];
    u16 v = initData->mTevStageInfoIndex[b];
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
extern "C" void* fn_800CB4C0(void* out, u8* e) {
    u8* p = (u8*)out;
    setTevStageInfo__11J3DTevStageFRC15J3DTevStageInfo(out, e);
    p[7] = (p[7] & ~0x0C) | (j3dDefaultTevSwapMode.mTexSel << 2);
    p[7] = (p[7] & ~0x03) | j3dDefaultTevSwapMode.mRasSel;
    return out;
}

extern "C" void fn_800CB520(u8* out, u8* p, s32 idx, s32 stage) {
    u16* ids = *(u16**)(p + 8);
    u8* base = *(u8**)(p + 4);
    u16 v = *(u16*)(base + ids[idx] * 0x14c + 0x124 + stage * 2);
    if (v != 0xffff) {
        u8* e = *(u8**)(p + 0x58) + v * 4;
        *out = e[0] * 0x40 + e[1] * 0x10 + e[2] * 4 + e[3];
        return;
    }
    u8* d = (u8*)&j3dDefaultTevSwapModeTable;
    *out = d[0] * 0x40 + d[1] * 0x10 + d[2] * 4 + d[3];
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
        s32 off = no * 4 + 0x68;
        *out = *(J3DIndTexCoordScaleInfo*)(data + off);
    } else {
        *out = dflt;
    }
}

extern "C" J3DFogInfo fn_800CB8C8(u8* p, s32 idx)
{
    J3DFogInfo fog;
    fog = j3dDefaultFogInfo;
    u16 v = *(u16*)(*(u8**)(p + 4) + ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x144);
    if (v != 0xffff) {
        J3DFogInfo tmp = ((J3DFogInfo*)*(u8**)(p + 0x5c))[v];
        fog = tmp;
    }
    return fog;
}

extern "C" void fn_800CBA08(u16* param_1, u8* param_2, s32 param_3) {
    u16 uVar1;
    u8* pbVar2;

    uVar1 = *(u16*)(*(u8**)(param_2 + 4) + ((u16*)*(u8**)(param_2 + 8))[param_3] * 0x14c + 0x146);
    if (uVar1 != 0xffff) {
        pbVar2 = *(u8**)(param_2 + 0x60) + uVar1 * 8;
        param_1[0] = pbVar2[0] * 0x20 + pbVar2[2] * 8 + pbVar2[3];
        ((u8*)param_1)[2] = pbVar2[1];
        ((u8*)param_1)[3] = pbVar2[4];
        return;
    }
    param_1[0] = -1;
    ((u8*)param_1)[2] = 0;
    ((u8*)param_1)[3] = 0;
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
    J3DNBTScale local;
    u8* puVar5;
    u16 uVar4;

    uVar4 = *(u16*)(*(u8**)(param_2 + 4) + (u32)*(u16*)(*(u8**)(param_2 + 8) + param_3 * 2) * 0x14c + 0x14a);
    if (uVar4 != 0xffff) {
        puVar5 = *(u8**)(param_2 + 0x74) + (uVar4 << 4);
        param_1->mHasScale = *puVar5;
        param_1->mScale[0] = *(f32*)(puVar5 + 4);
        param_1->mScale[1] = *(f32*)(puVar5 + 8);
        param_1->mScale[2] = *(f32*)(puVar5 + 0xc);
    } else {
        volatile u32* src = (volatile u32*)&local;
        u32* dst = (u32*)param_1;
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
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

