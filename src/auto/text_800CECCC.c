#include "JSystem/J3D/J3DAnmTransform.h"
#include "JSystem/J3D/J3DAnmColor.h"
#include "JSystem/JUtility/JUTNameTab.h"
#include "JSystem/J3D/J3DAnmTevRegKey.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/J3D/J3DAnmVtxColor.h"
#include "JSystem/J3D/J3DAnmCluster.h"
#include "JSystem/J3D/J3DAnmTexPattern.h"
#include "JSystem/J3D/J3DAnmTextureSRTKey.h"
#include "JSystem/J3D/J3DAnmVisibilityFull.h"

extern "C" void fn_800CF370(void** p);
extern "C" void** fn_800CF2B0(void** p);
extern "C" void** fn_800CF38C(void** p, short del);
extern "C" void** fn_800CF314(void** p, short del);
extern "C" void* fn_800CF3E8(void** self, unsigned char* data);
extern "C" void* fn_800CFB9C(void** self, unsigned char* data);

template <typename T> T* JSUConvertOffsetToPtr(const void* ptr, const void* offset);
extern const f32 lbl_8053BC80;
extern void* lbl_8049AE38[];
extern void* lbl_8049AE24[];
extern void* lbl_8049AE10[];
extern void* lbl_8049AE4C[];
extern void* lbl_8049AE5C[];
extern void* __vt__10J3DAnmBase[];
extern void* __vt__15J3DAnmTransform[];
extern "C" void __dl__FPv(void*);
extern "C" void fn_800CFE2C(void*, void*, void*);
extern "C" void fn_800CF8F4(void*, J3DAnmVisibilityFull*, const J3DAnmVisibilityFullData*);
static inline int texturePatternAttribute(const J3DAnmTexPatternFullData* data) { return data->mAttribute; }

extern "C" void fn_800CF828(void*, void*, void*);
extern "C" void fn_800D0204(void*, unsigned char*, const unsigned char*);
extern "C" void fn_800D00F0(void*, J3DAnmColorKey*, const J3DAnmColorKeyData*);
extern "C" void fn_800CFEF0(void*, void*, void*);
extern "C" void fn_800CF678(void*, void*, void*);
extern "C" void fn_800CF734(void*, unsigned char*, const unsigned char*);
extern "C" void fn_800CF998(void*, unsigned char*, const unsigned char*);
extern "C" void fn_800CFA2C(void**, void*, const void*);
extern "C" J3DAnmColorKey* __ct__14J3DAnmColorKeyFv(J3DAnmColorKey*);
extern "C" J3DAnmTextureSRTKey* __ct__19J3DAnmTextureSRTKeyFv(J3DAnmTextureSRTKey*);
extern "C" J3DAnmTevRegKey* __ct__15J3DAnmTevRegKeyFv(J3DAnmTevRegKey*);
extern "C" J3DAnmVtxColorKey* __ct__17J3DAnmVtxColorKeyFv(J3DAnmVtxColorKey*);
extern "C" J3DAnmColorFull* __ct__15J3DAnmColorFullFv(J3DAnmColorFull*);
extern "C" J3DAnmTexPattern* __ct__16J3DAnmTexPatternFv(J3DAnmTexPattern*);
extern "C" J3DAnmVtxColorFull* __ct__18J3DAnmVtxColorFullFv(J3DAnmVtxColorFull*);
#pragma opt_lifetimes reset
extern "C" void* fn_800CECCC(unsigned char* data, register u32 flags) {
    if (data == 0) {
        return 0;
    }
    if (*(u32*)data == 0x4a334431) {
        switch (*(u32*)(data + 4)) {
        case 0x62636b31: {
            void* self[2];
            fn_800CF370(self);
            self[1] = new J3DAnmTransformKey();
            flags = (u32)fn_800CFB9C(self, data);
            fn_800CF38C(self, -1);
            return (void*)flags;
        }
        case 0x62706b31: {
            void* self[2];
            fn_800CF370(self);
            J3DAnmColorKey* value = (J3DAnmColorKey*)operator new(sizeof(J3DAnmColorKey));
            if (value != 0) value = __ct__14J3DAnmColorKeyFv(value);
            self[1] = value;
            flags = (u32)fn_800CFB9C(self, data);
            fn_800CF38C(self, -1);
            return (void*)flags;
        }
        case 0x626c6b31: {
            void* self[2];
            fn_800CF370(self);
            self[1] = new J3DAnmClusterKey();
            flags = (u32)fn_800CFB9C(self, data);
            fn_800CF38C(self, -1);
            return (void*)flags;
        }
        case 0x62746b31: {
            void* self[2];
            fn_800CF370(self);
            J3DAnmTextureSRTKey* value = (J3DAnmTextureSRTKey*)operator new(sizeof(J3DAnmTextureSRTKey));
            if (value != 0) value = __ct__19J3DAnmTextureSRTKeyFv(value);
            self[1] = value;
            flags = (u32)fn_800CFB9C(self, data);
            fn_800CF38C(self, -1);
            return (void*)flags;
        }
        case 0x62726b31: {
            void* self[2];
            fn_800CF370(self);
            J3DAnmTevRegKey* value = (J3DAnmTevRegKey*)operator new(sizeof(J3DAnmTevRegKey));
            if (value != 0) value = __ct__15J3DAnmTevRegKeyFv(value);
            self[1] = value;
            flags = (u32)fn_800CFB9C(self, data);
            fn_800CF38C(self, -1);
            return (void*)flags;
        }
        case 0x62786b31: {
            void* self[2];
            fn_800CF370(self);
            J3DAnmVtxColorKey* value = (J3DAnmVtxColorKey*)operator new(sizeof(J3DAnmVtxColorKey));
            if (value != 0) value = __ct__17J3DAnmVtxColorKeyFv(value);
            self[1] = value;
            flags = (u32)fn_800CFB9C(self, data);
            fn_800CF38C(self, -1);
            return (void*)flags;
        }
        case 0x62636131: {
            void* self[2];
            fn_800CF2B0(self);
            if (flags & 1) {
                self[1] = new J3DAnmTransformFullWithLerp();
            } else {
                self[1] = new J3DAnmTransformFull();
            }
            flags = (u32)fn_800CF3E8(self, data);
            fn_800CF314(self, -1);
            return (void*)flags;
        }
        case 0x62706131: {
            void* self[2];
            fn_800CF2B0(self);
            J3DAnmColorFull* value = (J3DAnmColorFull*)operator new(sizeof(J3DAnmColorFull));
            if (value != 0) value = __ct__15J3DAnmColorFullFv(value);
            self[1] = value;
            flags = (u32)fn_800CF3E8(self, data);
            fn_800CF314(self, -1);
            return (void*)flags;
        }
        case 0x62747031: {
            void* self[2];
            fn_800CF2B0(self);
            J3DAnmTexPattern* value = (J3DAnmTexPattern*)operator new(sizeof(J3DAnmTexPattern));
            if (value != 0) value = __ct__16J3DAnmTexPatternFv(value);
            self[1] = value;
            flags = (u32)fn_800CF3E8(self, data);
            fn_800CF314(self, -1);
            return (void*)flags;
        }
        case 0x62766131: {
            void* self[2];
            fn_800CF2B0(self);
            self[1] = new J3DAnmVisibilityFull();
            flags = (u32)fn_800CF3E8(self, data);
            fn_800CF314(self, -1);
            return (void*)flags;
        }
        case 0x626c6131: {
            void* self[2];
            fn_800CF2B0(self);
            self[1] = new J3DAnmClusterFull();
            flags = (u32)fn_800CF3E8(self, data);
            fn_800CF314(self, -1);
            return (void*)flags;
        }
        case 0x62786131: {
            void* self[2];
            fn_800CF2B0(self);
            J3DAnmVtxColorFull* value = (J3DAnmVtxColorFull*)operator new(sizeof(J3DAnmVtxColorFull));
            if (value != 0) value = __ct__18J3DAnmVtxColorFullFv(value);
            self[1] = value;
            flags = (u32)fn_800CF3E8(self, data);
            fn_800CF314(self, -1);
            return (void*)flags;
        }
        default:
            return 0;
        }
    }
    return 0;
}

#pragma opt_lifetimes reset
#pragma peephole off
extern "C" void** fn_800CF2B0(void** p) {
    struct VBase { void* vt; };
    struct VDerived { void* vt; };
    ((VBase*)p)->vt = lbl_8049AE38;
    ((VDerived*)p)->vt = lbl_8049AE24;
    return p;
}
#pragma peephole reset
extern "C" void** fn_800CF2CC(void** p, short del) {
    if (p != 0) {
        *p = &lbl_8049AE38;
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void** fn_800CF314(void** p, short del) {
    if (p != 0) {
        *p = &lbl_8049AE24;
        if (p != 0) {
            *p = &lbl_8049AE38;
        }
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

#pragma peephole off
extern "C" void fn_800CF370(void** p) {
    void** q = p;
    *q = lbl_8049AE38;
    *p = lbl_8049AE10;
}
#pragma peephole reset
extern "C" void** fn_800CF38C(void** p, short del) {
    if (p != 0) {
        *p = &lbl_8049AE10;
        if (p != 0) {
            *p = &lbl_8049AE38;
        }
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void fn_800CF650(void** self, void* data);
extern "C" void fn_800CF70C(void** self, void* data);
extern "C" void fn_800CF800(void** self, void* data);
extern "C" void fn_800CF8CC(void** self, void* data);
extern "C" void fn_800CF970(void** self, const unsigned char* data);
extern "C" void fn_800CFA04(void** self, const void* data);
extern "C" void* fn_800CF3E8(void** self, unsigned char* data) {
    const u32 count = *(const u32*)(data + 0xc);
    unsigned char* entry = data + 0x20;
    u32 i;
    for (i = 0; i < count; i++) {
        s32 tag = *(s32*)entry;
        switch (tag) {
        case 0x414e4631:
            fn_800CF650(self, entry);
            break;
        case 0x50414631:
            fn_800CF70C(self, entry);
            break;
        case 0x54505431:
            fn_800CF800(self, entry);
            break;
        case 0x434c4631:
            fn_800CF970(self, entry);
            break;
        case 0x56414631:
            fn_800CF8CC(self, entry);
            break;
        case 0x56434631:
            fn_800CFA04(self, entry);
            break;
        }
        entry = entry + *(u32*)(entry + 4);
    }
    return self[1];
}

extern "C" void fn_800CF510(void* param_1, unsigned char* param_2, unsigned char* param_3) {
    unsigned int count = *(unsigned int*)(param_3 + 0xc);
    unsigned char* chunk = param_3 + 0x20;
    unsigned int i;
    for (i = 0; i < count; i++) {
        switch (*(s32*)chunk) {
        case 0x414e4631:
            fn_800CF678(param_1, param_2, chunk);
            break;
        case 0x50414631:
            fn_800CF734(param_1, param_2, chunk);
            break;
        case 0x54505431:
            fn_800CF828(param_1, param_2, chunk);
            break;
        case 0x434c4631:
            fn_800CF998(param_1, param_2, chunk);
            break;
        case 0x56414631:
            fn_800CF8F4(param_1, (J3DAnmVisibilityFull*)param_2, (const J3DAnmVisibilityFullData*)chunk);
            break;
        case 0x56434631:
            fn_800CFA2C((void**)param_1, param_2, chunk);
            break;
        }
        chunk += *(u32*)(chunk + 4);
    }
}

extern "C" void fn_800CF678(void*, void*, void*);
extern "C" void fn_800CF734(void*, unsigned char*, const unsigned char*);
extern "C" void fn_800CF650(void** p, void* a) {
    fn_800CF678(p, p[1], a);
}

extern "C" void fn_800CF678(void* param_1, void* param_2, void* param_3) {
    unsigned char* anm = (unsigned char*)param_2;
    unsigned char* data = (unsigned char*)param_3;

    *(s16*)(anm + 6) = *(const s16*)(data + 0xa);
    anm[4] = data[8];
    *(float*)(anm + 8) = lbl_8053BC80;
    *(u16*)(anm + 0x1e) = *(const u16*)(data + 0xc);
    *(void**)(anm + 0x20) = JSUConvertOffsetToPtr<J3DAnmTransformFullTable>(data, (void*)*(const u32*)(data + 0x14));
    *(void**)(anm + 0xc) = JSUConvertOffsetToPtr<f32>(data, (void*)*(const u32*)(data + 0x18));
    *(void**)(anm + 0x10) = JSUConvertOffsetToPtr<s16>(data, (void*)*(const u32*)(data + 0x1c));
    *(void**)(anm + 0x14) = JSUConvertOffsetToPtr<f32>(data, (void*)*(const u32*)(data + 0x20));
}

extern "C" void fn_800CF70C(void** p, void* a) {
    fn_800CF734(p, (unsigned char*)p[1], (const unsigned char*)a);
}

extern "C" void fn_800CF734(void* param_1, unsigned char* anm, const unsigned char* data) {
    *(short*)(anm + 6) = *(const short*)(data + 12);
    anm[4] = data[8];
    *(float*)(anm + 8) = 0.0f;
    *(unsigned short*)(anm + 0x14) = *(const unsigned short*)(data + 14);
    *(J3DAnmColorFullTable**)(anm + 0x3c) = JSUConvertOffsetToPtr<J3DAnmColorFullTable>(data, (void*)*(const unsigned int*)(data + 0x18));
    *(void**)(anm + 0x2c) = JSUConvertOffsetToPtr<unsigned char>(data, (void*)*(const unsigned int*)(data + 0x24));
    *(void**)(anm + 0x30) = JSUConvertOffsetToPtr<unsigned char>(data, (void*)*(const unsigned int*)(data + 0x28));
    *(void**)(anm + 0x34) = JSUConvertOffsetToPtr<unsigned char>(data, (void*)*(const unsigned int*)(data + 0x2c));
    *(void**)(anm + 0x38) = JSUConvertOffsetToPtr<unsigned char>(data, (void*)*(const unsigned int*)(data + 0x30));
    *(void**)(anm + 0x18) = JSUConvertOffsetToPtr<unsigned short>(data, (void*)*(const unsigned int*)(data + 0x1c));
    ((JUTNameTab*)(anm + 0x1c))->setResource(JSUConvertOffsetToPtr<ResNTAB>(data, (void*)*(const unsigned int*)(data + 0x20)));
}

extern "C" void fn_800CF800(void** self, void* data)
{
    fn_800CF828(self, self[1], data);
}

#pragma opt_propagation off
extern "C" void fn_800CF828(void*, void* anm_, void* data_) {
    f32 zero = lbl_8053BC80;
    int attr = *(volatile u8*)((u8*)data_+8);
    const J3DAnmTexPatternFullData* data = (const J3DAnmTexPatternFullData*)data_;
    J3DAnmTexPattern* anm = (J3DAnmTexPattern*)anm_;
    int frame = data->mTotalFrameCount;
    anm->mMaxFrame = frame;
    u32 count = data->mExtraInfo1;
    anm->mAttribute = attr;
    u32 info = data->mExtraInfo2;
    anm->mCurrentFrame = zero;
    anm->mUpdateMaterialNum = count;
    u32 offset = data->mTableOffset;
    anm->_14 = info;
    anm->mAnmTable = JSUConvertOffsetToPtr<J3DAnmTexPatternFullTable>(data, (void*)offset);
    anm->_0C = JSUConvertOffsetToPtr<u16>(data, (void*)data->mValuesOffset);
    anm->mUpdateMaterialID = JSUConvertOffsetToPtr<u16>(data, (void*)data->mUpdateMaterialIDOffset);
    anm->mNameTab.setResource(JSUConvertOffsetToPtr<ResNTAB>(data, (void*)data->mNameTabOffset));
}
#pragma opt_propagation reset
extern "C" void fn_800CF8CC(void** self, void* data)
{
    fn_800CF8F4(self, (J3DAnmVisibilityFull*)self[1], (const J3DAnmVisibilityFullData*)data);
}

extern "C" void fn_800CF8F4(void* loader, J3DAnmVisibilityFull* anm, const J3DAnmVisibilityFullData* data) {
    anm->mMaxFrame=data->mTotalFrameCount;
    anm->mAttribute=data->mAttribute;
    anm->mCurrentFrame=lbl_8053BC80;
    anm->_0C=data->mExtraInfo1;
    anm->_0E=data->mExtraInfo2;
    anm->mTable=JSUConvertOffsetToPtr<J3DAnmVisibilityFullTable>(data,(void*)data->mTableOffset);
    anm->mValues=JSUConvertOffsetToPtr<u8>(data,(void*)data->mValuesOffset);
}

extern "C" void fn_800CF998(void*, unsigned char*, const unsigned char*);
extern "C" void fn_800CF970(void** self, const unsigned char* data) {
    fn_800CF998(self, (unsigned char*)self[1], data);
}

extern "C" void* fn_800D06D0(const void* ptr, const void* offset);
template <typename T> T* JSUConvertOffsetToPtr(const void* ptr, const void* offset);
extern "C" void fn_800CF998(void* param_1, unsigned char* anm, const unsigned char* data) {
    *(short*)(anm + 6) = *(const short*)(data + 10);
    anm[4] = data[8];
    *(float*)(anm + 8) = 0.0f;
    *(void**)(anm + 0x10) = fn_800D06D0(data, (void*)*(const unsigned int*)(data + 0x10));
    *(float**)(anm + 0xc) = JSUConvertOffsetToPtr<float>(data, (void*)*(const unsigned int*)(data + 0x14));
}

extern "C" void fn_800CFA2C(void** self, void* res, const void* data);
extern "C" void fn_800CFA04(void** self, const void* data) {
    fn_800CFA2C(self, self[1], data);
}

extern "C" void fn_800CFA2C(void** self, void* res, const void* data) {
#define anm ((J3DAnmVtxColorFull*)res)
#define src ((const J3DAnmVtxColorFullData*)data)
    anm->mMaxFrame = src->mTotalFrameCount;
    anm->mAttribute = src->mAttribute;
    anm->mCurrentFrame = 0.0f;
    anm->mAnmTableNum[0] = src->mExtraInfo1;
    anm->mAnmTableNum[1] = src->mExtraInfo2;
    anm->mTable[0] = JSUConvertOffsetToPtr<J3DAnmColorFullTable>(src, (void*)src->mTableOffsets[0]);
    anm->mTable[1] = JSUConvertOffsetToPtr<J3DAnmColorFullTable>(src, (void*)src->mTableOffsets[1]);
    anm->mAnmVtxColorIndexData[0] = JSUConvertOffsetToPtr<J3DAnmVtxColorIndexData>(src, (void*)src->mVtxColorIndexDataOffsets[0]);
    anm->mAnmVtxColorIndexData[1] = JSUConvertOffsetToPtr<J3DAnmVtxColorIndexData>(src, (void*)src->mVtxColorIndexDataOffsets[1]);
    void* ptr28 = JSUConvertOffsetToPtr<u16>(src, (void*)src->mVtxColorIndexPointerOffsets[0]);
    void* ptr2c = JSUConvertOffsetToPtr<u16>(src, (void*)src->mVtxColorIndexPointerOffsets[1]);
    for (s32 i = 0; i < anm->mAnmTableNum[0]; i++) {
        anm->mAnmVtxColorIndexData[0][i].mData = (void*)((s32)ptr28 + (s32)anm->mAnmVtxColorIndexData[0][i].mData * 2);
    }
    for (s32 i = 0; i < anm->mAnmTableNum[1]; i++) {
        anm->mAnmVtxColorIndexData[1][i].mData = (void*)((s32)ptr2c + (s32)anm->mAnmVtxColorIndexData[1][i].mData * 2);
    }
    anm->mRedVals = JSUConvertOffsetToPtr<u8>(src, (void*)src->mRValuesOffset);
    anm->mGreenVals = JSUConvertOffsetToPtr<u8>(src, (void*)src->mGValuesOffset);
    anm->mBlueVals = JSUConvertOffsetToPtr<u8>(src, (void*)src->mBValuesOffset);
    anm->mAlphaVals = JSUConvertOffsetToPtr<u8>(src, (void*)src->mAValuesOffset);
#undef anm
#undef src
}

extern "C" void fn_800CFE04(void** self, void* data);
extern "C" void fn_800D01DC(void** self, void* data);
extern "C" void fn_800D00C8(void** self, void* data);
extern "C" void fn_800D0270(void** self, void* data);
extern "C" void fn_800CFEC8(void** self, void* data);
extern "C" void fn_800D0424(void** self, const void* data);
extern "C" void* fn_800CFB9C(void** self, unsigned char* data) {
    unsigned char* base = data;
    unsigned int count = *(unsigned int*)(base + 0xc);
    unsigned char* chunk = base + 0x20;
    unsigned int i;
    for (i = 0; i < count; i++) {
        switch (*(unsigned int*)chunk) {
        case 0x414e4b31:
            fn_800CFE04(self, chunk);
            break;
        case 0x50414b31:
            fn_800D00C8(self, chunk);
            break;
        case 0x434c4b31:
            fn_800D01DC(self, chunk);
            break;
        case 0x54544b31:
            fn_800CFEC8(self, chunk);
            break;
        case 0x54524b31:
            fn_800D0270(self, chunk);
            break;
        case 0x56434b31:
            fn_800D0424(self, chunk);
            break;
        }
        chunk += *(unsigned int*)(chunk + 4);
    }
    return self[1];
}

extern "C" void fn_800CFCC4(void* param_1, void* param_2, unsigned char* param_3) {
    void fn_800D0298(void*, void*, void*);
    void fn_800D044C(void**, void*, const void*);
    u32 count = *(u32*)(param_3 + 0xc);
    unsigned char* p = param_3 + 0x20;
    u32 tag = 0x54524b31;
    for (u32 i = 0; i < count; i++) {
        switch (*(u32*)p) {
        case 0x414e4b31:
            fn_800CFE2C(param_1, param_2, p);
            break;
        case 0x50414b31:
            fn_800D00F0(param_1, (J3DAnmColorKey*)param_2, (const J3DAnmColorKeyData*)p);
            break;
        case 0x434c4b31:
            fn_800D0204(param_1, (unsigned char*)param_2, p);
            break;
        case 0x54544b31:
            fn_800CFEF0(param_1, param_2, p);
            break;
        case 0x54524b31:
            fn_800D0298(param_1, param_2, p);
            break;
        case 0x56434b31:
            fn_800D044C((void**)param_1, param_2, p);
            break;
        }
        p += *(u32*)(p + 4);
    }
}

extern "C" void fn_800CFE04(void** self, void* data)
{
    fn_800CFE2C(self, self[1], data);
}

#pragma optimization_level 3
extern "C" void fn_800CFE2C(void* self, void* anm, void* src) {
    u8* a = (u8*)anm;
    u8* s = (u8*)src;
    f32 f = lbl_8053BC80;
    int h;
    int w;
    h = *(s16*)(s + 0xa);
    w = *(u16*)(s + 0xc);
    *(u16*)(a + 0x1e) = w;
    w = s[8];
    *(s16*)(a + 6) = h;
    h = s[9];
    a[4] = w;
    void* p = *(void**)(s + 0x14);
    *(u32*)(a + 0x20) = h;
    *(f32*)(a + 8) = f;
    *(void**)(a + 0x24) = JSUConvertOffsetToPtr<J3DAnmTransformKeyTable>(s, p);
    *(void**)(a + 0xc) = JSUConvertOffsetToPtr<f32>(s, *(void**)(s + 0x18));
    *(void**)(a + 0x10) = JSUConvertOffsetToPtr<s16>(s, *(void**)(s + 0x1c));
    *(void**)(a + 0x14) = JSUConvertOffsetToPtr<f32>(s, *(void**)(s + 0x20));
}
#pragma optimization_level 4
extern "C" void fn_800CFEC8(void** self, void* data)
{
    fn_800CFEF0(self, self[1], data);
}

extern "C" void fn_800CFEF0(void* param_1, void* param_2, void* param_3) {
    const unsigned char* data = (const unsigned char*)param_3;
    unsigned char* anm = (unsigned char*)param_2;
    *(unsigned short*)(anm + 0x14) = *(const unsigned short*)(data + 12);
    *(short*)(anm + 6) = *(const short*)(data + 10);
    anm[4] = data[8];
    *(unsigned int*)(anm + 0xc) = data[9];
    *(float*)(anm + 8) = 0.0f;
    *(unsigned short*)(anm + 0x14) = *(const unsigned short*)(data + 12);
    *(unsigned short*)(anm + 0x16) = *(const unsigned short*)(data + 14);
    *(unsigned short*)(anm + 0x18) = *(const unsigned short*)(data + 16);
    *(unsigned short*)(anm + 0x1a) = *(const unsigned short*)(data + 18);
    *(void**)(anm + 0x10) = JSUConvertOffsetToPtr<J3DAnmTransformKeyTable>(data, (void*)*(const unsigned int*)(data + 0x14));
    *(void**)(anm + 0x2c) = JSUConvertOffsetToPtr<unsigned short>(data, (void*)*(const unsigned int*)(data + 0x18));
    ((JUTNameTab*)(anm + 0x30))->setResource(JSUConvertOffsetToPtr<ResNTAB>(data, (void*)*(const unsigned int*)(data + 0x1c)));
    *(void**)(anm + 0x28) = JSUConvertOffsetToPtr<unsigned char>(data, (void*)*(const unsigned int*)(data + 0x20));
    *(void**)(anm + 0x40) = JSUConvertOffsetToPtr<Vec>(data, (void*)*(const unsigned int*)(data + 0x24));
    *(void**)(anm + 0x1c) = JSUConvertOffsetToPtr<float>(data, (void*)*(const unsigned int*)(data + 0x28));
    *(void**)(anm + 0x20) = JSUConvertOffsetToPtr<short>(data, (void*)*(const unsigned int*)(data + 0x2c));
    *(void**)(anm + 0x24) = JSUConvertOffsetToPtr<float>(data, (void*)*(const unsigned int*)(data + 0x30));
    if (*(const unsigned int*)(data + 0x44) != 0) {
        ((JUTNameTab*)(anm + 0x64))->setResource(JSUConvertOffsetToPtr<ResNTAB>(data, (void*)*(const unsigned int*)(data + 0x44)));
    }
    *(unsigned short*)(anm + 0x4a) = *(const unsigned short*)(data + 0x34);
    *(unsigned short*)(anm + 0x44) = *(const unsigned short*)(data + 0x36);
    *(unsigned short*)(anm + 0x46) = *(const unsigned short*)(data + 0x38);
    *(unsigned short*)(anm + 0x48) = *(const unsigned short*)(data + 0x3a);
    *(void**)(anm + 0x58) = JSUConvertOffsetToPtr<J3DAnmTransformKeyTable>(data, (void*)*(const unsigned int*)(data + 0x3c));
    *(void**)(anm + 0x60) = JSUConvertOffsetToPtr<unsigned short>(data, (void*)*(const unsigned int*)(data + 0x40));
    *(void**)(anm + 0x5c) = JSUConvertOffsetToPtr<unsigned char>(data, (void*)*(const unsigned int*)(data + 0x48));
    *(void**)(anm + 0x74) = JSUConvertOffsetToPtr<Vec>(data, (void*)*(const unsigned int*)(data + 0x4c));
    *(void**)(anm + 0x4c) = JSUConvertOffsetToPtr<float>(data, (void*)*(const unsigned int*)(data + 0x50));
    *(void**)(anm + 0x50) = JSUConvertOffsetToPtr<short>(data, (void*)*(const unsigned int*)(data + 0x54));
    *(void**)(anm + 0x54) = JSUConvertOffsetToPtr<float>(data, (void*)*(const unsigned int*)(data + 0x58));
    s32 flag = *(const s32*)(data + 0x5c);
    if (flag < 2 && flag >= 0) {
        *(s32*)(anm + 0x78) = flag;
    } else {
        *(s32*)(anm + 0x78) = 0;
    }
}

extern "C" void fn_800D00C8(void** self, void* data)
{
    fn_800D00F0(self, (J3DAnmColorKey*)self[1], (const J3DAnmColorKeyData*)data);
}

#pragma opt_common_subs off
extern "C" void fn_800D00F0(void* loader, J3DAnmColorKey* anm, const J3DAnmColorKeyData* data) {
    anm->mMaxFrame = data->mTotalFrameCount;
    anm->mAttribute = data->mAttribute;
    anm->mCurrentFrame = lbl_8053BC80;
    anm->mUpdateMaterialNum = data->mUpdateMaterialNum;
    anm->_0C = data->_10;
    anm->_0E = data->_12;
    anm->_10 = data->_14;
    anm->_12 = data->_16;
    anm->mTable = JSUConvertOffsetToPtr<J3DAnmColorKeyTable>(data, (void*)data->mTableOffset);
    anm->_2C = JSUConvertOffsetToPtr<s16>(data, (void*)data->mRValOffset);
    anm->_30 = JSUConvertOffsetToPtr<s16>(data, (void*)data->mGValOffset);
    anm->_34 = JSUConvertOffsetToPtr<s16>(data, (void*)data->mBValOffset);
    anm->_38 = JSUConvertOffsetToPtr<s16>(data, (void*)data->mAValOffset);
    anm->mUpdateMaterialID = JSUConvertOffsetToPtr<u16>(data, (void*)data->mUpdateMaterialIDOffset);
    anm->mNameTab.setResource(JSUConvertOffsetToPtr<ResNTAB>(data, (void*)data->mNameTabOffset));
}
#pragma opt_common_subs reset
extern "C" void fn_800D01DC(void** self, void* data)
{
    fn_800D0204(self, (unsigned char*)self[1], (const unsigned char*)data);
}

extern "C" void* fn_800D06B8(const void* ptr, const void* offset);
extern "C" void fn_800D0204(void* param_1, unsigned char* anm, const unsigned char* data) {
    *(short*)(anm + 6) = *(const short*)(data + 10);
    anm[4] = data[8];
    *(float*)(anm + 8) = 0.0f;
    *(void**)(anm + 0x10) = fn_800D06B8(data, (void*)*(const unsigned int*)(data + 0x10));
    *(float**)(anm + 0xc) = JSUConvertOffsetToPtr<float>(data, (void*)*(const unsigned int*)(data + 0x14));
}

extern "C" void fn_800D0298(void* self, void* res, void* data);
extern "C" void fn_800D0298(void*, void*, void*);
extern "C" void fn_800D0270(void** self, void* data)
{
    fn_800D0298(self, self[1], data);
}

#pragma opt_propagation off
extern "C" void fn_800D0298(void* param_1, void* param_2, void* param_3) {
    const unsigned char* data = (const unsigned char*)param_3;
    unsigned char* anm = (unsigned char*)param_2;
    *(float*)(anm + 8) = 0.0f;
    *(short*)(anm + 6) = *(const short*)(data + 10);
    anm[4] = data[8];
    *(unsigned short*)(anm + 0xc) = *(const unsigned short*)(data + 12);
    *(void**)(anm + 0x48) = JSUConvertOffsetToPtr<J3DAnmCRegKeyTable>(data, (void*)*(const unsigned int*)(data + 0x20));
    *(void**)(anm + 0x20) = JSUConvertOffsetToPtr<unsigned short>(data, (void*)*(const unsigned int*)(data + 0x28));
    ((JUTNameTab*)(anm + 0x24))->setResource(JSUConvertOffsetToPtr<ResNTAB>(data, (void*)*(const unsigned int*)(data + 0x30)));
    *(unsigned short*)(anm + 0xe) = *(const unsigned short*)(data + 14);
    *(void**)(anm + 0x4c) = JSUConvertOffsetToPtr<J3DAnmKRegKeyTable>(data, (void*)*(const unsigned int*)(data + 0x24));
    *(void**)(anm + 0x34) = JSUConvertOffsetToPtr<unsigned short>(data, (void*)*(const unsigned int*)(data + 0x2c));
    ((JUTNameTab*)(anm + 0x38))->setResource(JSUConvertOffsetToPtr<ResNTAB>(data, (void*)*(const unsigned int*)(data + 0x34)));
    *(unsigned short*)(anm + 0x10) = *(const unsigned short*)(data + 0x10);
    *(unsigned short*)(anm + 0x12) = *(const unsigned short*)(data + 0x12);
    *(unsigned short*)(anm + 0x14) = *(const unsigned short*)(data + 0x14);
    *(unsigned short*)(anm + 0x16) = *(const unsigned short*)(data + 0x16);
    *(void**)(anm + 0x50) = JSUConvertOffsetToPtr<short>(data, (void*)*(const unsigned int*)(data + 0x38));
    *(void**)(anm + 0x54) = JSUConvertOffsetToPtr<short>(data, (void*)*(const unsigned int*)(data + 0x3c));
    *(void**)(anm + 0x58) = JSUConvertOffsetToPtr<short>(data, (void*)*(const unsigned int*)(data + 0x40));
    *(void**)(anm + 0x5c) = JSUConvertOffsetToPtr<short>(data, (void*)*(const unsigned int*)(data + 0x44));
    *(unsigned short*)(anm + 0x18) = *(const unsigned short*)(data + 0x18);
    *(unsigned short*)(anm + 0x1a) = *(const unsigned short*)(data + 0x1a);
    *(unsigned short*)(anm + 0x1c) = *(const unsigned short*)(data + 0x1c);
    *(unsigned short*)(anm + 0x1e) = *(const unsigned short*)(data + 0x1e);
    *(void**)(anm + 0x60) = JSUConvertOffsetToPtr<short>(data, (void*)*(const unsigned int*)(data + 0x48));
    *(void**)(anm + 0x64) = JSUConvertOffsetToPtr<short>(data, (void*)*(const unsigned int*)(data + 0x4c));
    *(void**)(anm + 0x68) = JSUConvertOffsetToPtr<short>(data, (void*)*(const unsigned int*)(data + 0x50));
    *(void**)(anm + 0x6c) = JSUConvertOffsetToPtr<short>(data, (void*)*(const unsigned int*)(data + 0x54));
}
#pragma opt_propagation reset
extern "C" void fn_800D044C(void** self, void* res, const void* data);
extern "C" void fn_800D0424(void** self, const void* data) {
    fn_800D044C(self, self[1], data);
}

extern "C" void fn_800D044C(void** self, void* res, const void* data) {
#define anm ((J3DAnmVtxColorKey*)res)
#define src ((const J3DAnmVtxColorKeyData*)data)
    anm->mMaxFrame = src->mTotalFrameCount;
    anm->mAttribute = src->mAttribute;
    anm->mCurrentFrame = 0.0f;
    anm->mAnmTableNum[0] = src->mAnmTableNum[0];
    anm->mAnmTableNum[1] = src->mAnmTableNum[1];
    anm->mTable[0] = JSUConvertOffsetToPtr<J3DAnmColorKeyTable>(src, (void*)src->mTableOffsets[0]);
    anm->mTable[1] = JSUConvertOffsetToPtr<J3DAnmColorKeyTable>(src, (void*)src->mTableOffsets[1]);
    anm->mAnmVtxColorIndexData[0] = JSUConvertOffsetToPtr<J3DAnmVtxColorIndexData>(src, (void*)src->mVtxColoIndexDataOffset[0]);
    anm->mAnmVtxColorIndexData[1] = JSUConvertOffsetToPtr<J3DAnmVtxColorIndexData>(src, (void*)src->mVtxColoIndexDataOffset[1]);
    void* ptr28 = JSUConvertOffsetToPtr<u16>(src, (void*)src->mVtxColorIndexPointerOffset[0]);
    void* ptr2c = JSUConvertOffsetToPtr<u16>(src, (void*)src->mVtxColorIndexPointerOffset[1]);
    for (s32 i = 0; i < anm->mAnmTableNum[0]; i++) {
        anm->mAnmVtxColorIndexData[0][i].mData = (void*)((s32)ptr28 + (s32)anm->mAnmVtxColorIndexData[0][i].mData * 2);
    }
    for (s32 i = 0; i < anm->mAnmTableNum[1]; i++) {
        anm->mAnmVtxColorIndexData[1][i].mData = (void*)((s32)ptr2c + (s32)anm->mAnmVtxColorIndexData[1][i].mData * 2);
    }
    anm->mRedVals = JSUConvertOffsetToPtr<s16>(src, (void*)src->mRValOffset);
    anm->mGreenVals = JSUConvertOffsetToPtr<s16>(src, (void*)src->mGValOffset);
    anm->mBlueVals = JSUConvertOffsetToPtr<s16>(src, (void*)src->mBValOffset);
    anm->mAlphaVals = JSUConvertOffsetToPtr<s16>(src, (void*)src->mAValOffset);
#undef anm
#undef src
}

extern "C" void* fn_800D05BC(void* param_1, short param_2)
{
    if (param_1 != 0) {
        void** p = (void**)param_1;
        *p = &lbl_8049AE4C;
        if (param_1 != 0) {
            p = (void**)param_1;
            *p = &__vt__10J3DAnmBase;
        }
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}

extern "C" int fn_800D0618(void)
{
    return 6;
}

#if !defined(VERSION_G4SJ01) && !defined(VERSION_G4SP01)
extern "C" void* fn_800D0620(void* param_1, short param_2)
{
    if (param_1 != 0) {
        ((void**)param_1)[0] = &lbl_8049AE5C;
        if (param_1 != 0) {
            ((void**)param_1)[0] = &__vt__15J3DAnmTransform;
            if (param_1 != 0) {
                ((void**)param_1)[0] = &__vt__10J3DAnmBase;
            }
        }
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}
#elif defined(VERSION_G4SJ01)
extern "C" void* fn_800D0620(void* param_1, short param_2)
{
    s32 p = (s32)param_1;
    if (p != 0) {
        *(void**)p = &lbl_8049AE5C;
        if (p != 0) {
            *(void**)p = &__vt__15J3DAnmTransform;
            if (p != 0) {
                *(void**)p = &__vt__10J3DAnmBase;
            }
        }
        if (param_2 > 0) {
            __dl__FPv((void*)p);
        }
    }
    return (void*)p;
}
#elif defined(VERSION_G4SP01)
extern "C" void** fn_800D0620(void** p, short del) {
    if (p) {
        *p = lbl_8049AE5C;
        if (p) {
            *p = __vt__15J3DAnmTransform;
            if (p) {
                *p = __vt__10J3DAnmBase;
            }
        }
        if (del > 0) {
            __dl__FPv(p);
        }
    }
            return p;
}
#endif

extern "C" int fn_800D068C(void)
{
    return 8;
}

extern "C" void fn_800D0694(const J3DAnmTransformKey* p1, unsigned short p2, J3DTransformInfo* p3) {
    p1->calcTransform(p1->mCurrentFrame, p2, p3);
}

extern "C" void fn_800D00F0(void*, J3DAnmColorKey*, const J3DAnmColorKeyData*);
extern "C" void fn_800CFEF0(void*, void*, void*);
extern "C" void* fn_800D06B8(const void* ptr, const void* offset)
{
    if (offset == 0) {
        return 0;
    }
    return (unsigned char*)ptr + (unsigned int)offset;
}

extern "C" void* fn_800D06D0(const void* ptr, const void* offset)
{
    if (offset == 0) {
        return 0;
    }
    return (unsigned char*)ptr + (unsigned int)offset;
}

