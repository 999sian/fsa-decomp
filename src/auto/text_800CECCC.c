// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* lbl_8049AE38[];
extern void* lbl_8049AE10[];
extern void* lbl_8049AE24[];
void __dl__FPv(void*);
extern "C" void fn_800CF2B0(void** p) {
    void** volatile* vp = (void** volatile*)p;
    *vp = lbl_8049AE38;
    *vp = lbl_8049AE24;
}

#include "JSystem/JSupport.h"
#include "JSystem/J3D/J3DAnmColor.h"
#include "JSystem/J3D/J3DAnmVtxColor.h"
#include "JSystem/J3D/J3DAnmVisibilityFull.h"

extern "C" void** fn_800CF2CC(void** p, short del) {
    if (p != 0) {
        *p = lbl_8049AE38;
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void** fn_800CF314(void** p, short del) {
    if (p != 0) {
        *p = lbl_8049AE24;
        if (p != 0) {
            *p = lbl_8049AE38;
        }
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void fn_800CF370(void** p) {
    void** volatile* vp = (void** volatile*)p;
    *vp = lbl_8049AE38;
    *vp = lbl_8049AE10;
}

struct J3DAnmVisibilityFullTable;
extern "C" void fn_800CF8F4(void* param_1, unsigned char* anm, const J3DAnmVisibilityFullData* data) {
    *(short*)(anm + 6) = data->mTotalFrameCount;
    anm[4] = data->mAttribute;
    *(float*)(anm + 8) = 0.0f;
    *(unsigned short*)(anm + 12) = data->mExtraInfo1;
    *(unsigned short*)(anm + 14) = data->mExtraInfo2;
    *(J3DAnmVisibilityFullTable**)(anm + 0x10) = JSUConvertOffsetToPtr<J3DAnmVisibilityFullTable>(data, (void*)data->mTableOffset);
    *(unsigned char**)(anm + 0x14) = JSUConvertOffsetToPtr<unsigned char>(data, (void*)data->mValuesOffset);
}

extern "C" void fn_800CF998(void* param_1, unsigned char* anm, const unsigned char* data);
extern "C" void fn_800CFA2C(void* param_1, void* anm, const void* data);
extern "C" void* fn_800D06D0(const void* data, void* offset);
extern "C" void fn_800CF970(void** self, const unsigned char* data) {
    fn_800CF998(self, (unsigned char*)self[1], data);
}

extern "C" void fn_800CF998(void* param_1, unsigned char* anm, const unsigned char* data) {
    *(short*)(anm + 6) = *(const short*)(data + 10);
    anm[4] = data[8];
    *(float*)(anm + 8) = 0.0f;
    *(void**)(anm + 0x10) = fn_800D06D0(data, (void*)*(const unsigned int*)(data + 0x10));
    *(float**)(anm + 0xc) = JSUConvertOffsetToPtr<float>(data, (void*)*(const unsigned int*)(data + 0x14));
}

extern float lbl_8053BC80;
void fn_800CFA2C(void* param_1, void* param_3, void* param_2) {
    unsigned char val8 = *(unsigned char*)((unsigned char*)param_3 + 8);
    unsigned short val10 = *(unsigned short*)((unsigned char*)param_3 + 10);
    unsigned short val12 = *(unsigned short*)((unsigned char*)param_3 + 12);
    unsigned short val14 = *(unsigned short*)((unsigned char*)param_3 + 14);
    
    *(unsigned short*)((unsigned char*)param_2 + 6) = val10;
    *(unsigned char*)((unsigned char*)param_2 + 4) = val8;
    *(float*)((unsigned char*)param_2 + 8) = lbl_8053BC80;
    *(unsigned short*)((unsigned char*)param_2 + 12) = val12;
    *(unsigned short*)((unsigned char*)param_2 + 14) = val14;
    
    unsigned int offset18 = *(unsigned int*)((unsigned char*)param_3 + 0x18);
    void* ptr18 = JSUConvertOffsetToPtr<J3DAnmColorFullTable>((const void*)param_3, (void*)offset18);
    *(void**)((unsigned char*)param_2 + 0x18) = ptr18;
    
    unsigned int offset1c = *(unsigned int*)((unsigned char*)param_3 + 0x1c);
    void* ptr1c = JSUConvertOffsetToPtr<J3DAnmColorFullTable>((const void*)param_3, (void*)offset1c);
    *(void**)((unsigned char*)param_2 + 0x1c) = ptr1c;
    
    unsigned int offset20 = *(unsigned int*)((unsigned char*)param_3 + 0x20);
    void* ptr20 = JSUConvertOffsetToPtr<J3DAnmVtxColorIndexData>((const void*)param_3, (void*)offset20);
    *(void**)((unsigned char*)param_2 + 0x10) = ptr20;
    
    unsigned int offset24 = *(unsigned int*)((unsigned char*)param_3 + 0x24);
    void* ptr24 = JSUConvertOffsetToPtr<J3DAnmVtxColorIndexData>((const void*)param_3, (void*)offset24);
    *(void**)((unsigned char*)param_2 + 0x14) = ptr24;
    
    unsigned int offset28 = *(unsigned int*)((unsigned char*)param_3 + 0x28);
    void* ptr28 = JSUConvertOffsetToPtr<unsigned short>((const void*)param_3, (void*)offset28);
    
    unsigned int offset2c = *(unsigned int*)((unsigned char*)param_3 + 0x2c);
    void* ptr2c = JSUConvertOffsetToPtr<unsigned short>((const void*)param_3, (void*)offset2c);
    
    unsigned short count12 = *(unsigned short*)((unsigned char*)param_2 + 0xc);
    for (unsigned int i = 0; i < count12; i++) {
        unsigned int idx = *(unsigned int*)((unsigned char*)ptr20 + i * 8 + 4);
        unsigned int val = *(unsigned int*)((unsigned char*)ptr28 + idx * 2);
        *(unsigned int*)((unsigned char*)ptr20 + i * 8 + 4) = val;
    }
    
    unsigned short count14 = *(unsigned short*)((unsigned char*)param_2 + 0xe);
    for (unsigned int i = 0; i < count14; i++) {
        unsigned int idx = *(unsigned int*)((unsigned char*)ptr24 + i * 8 + 4);
        unsigned int val = *(unsigned int*)((unsigned char*)ptr2c + idx * 2);
        *(unsigned int*)((unsigned char*)ptr24 + i * 8 + 4) = val;
    }
    
    unsigned int offset30 = *(unsigned int*)((unsigned char*)param_3 + 0x30);
    void* ptr30 = JSUConvertOffsetToPtr<unsigned char>((const void*)param_3, (void*)offset30);
    *(void**)((unsigned char*)param_2 + 0x20) = ptr30;
    
    unsigned int offset34 = *(unsigned int*)((unsigned char*)param_3 + 0x34);
    void* ptr34 = JSUConvertOffsetToPtr<unsigned char>((const void*)param_3, (void*)offset34);
    *(void**)((unsigned char*)param_2 + 0x24) = ptr34;
    
    unsigned int offset38 = *(unsigned int*)((unsigned char*)param_3 + 0x38);
    void* ptr38 = JSUConvertOffsetToPtr<unsigned char>((const void*)param_3, (void*)offset38);
    *(void**)((unsigned char*)param_2 + 0x28) = ptr38;
    
    unsigned int offset3c = *(unsigned int*)((unsigned char*)param_3 + 0x3c);
    void* ptr3c = JSUConvertOffsetToPtr<unsigned char>((const void*)param_3, (void*)offset3c);
    *(void**)((unsigned char*)param_2 + 0x2c) = ptr3c;
}

