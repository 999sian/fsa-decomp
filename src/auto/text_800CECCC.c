#include "JSystem/J3D/J3DAnmTransform.h"
#include "JSystem/J3D/J3DAnmColor.h"
#include "JSystem/JUtility/JUTNameTab.h"

template <typename T> T* JSUConvertOffsetToPtr(const void* ptr, const void* offset);
extern f32 lbl_8053BC80;


extern float lbl_8053BC80;
extern void* lbl_8049AE38[];
extern void* lbl_8049AE24[];
extern void* lbl_8049AE10[];
extern void* lbl_8049AE4C[];
extern void* lbl_8049AE5C[];
extern void* __vt__10J3DAnmBase[];
extern void* __vt__15J3DAnmTransform[];
extern "C" void __dl__FPv(void*);
extern "C" void fn_800CFE2C(void*, void*, void*);
extern "C" void fn_800CF8F4(void*, void*, void*);
extern "C" void fn_800CF828(void*, void*, void*);
extern "C" void fn_800D0204(void*, unsigned char*, const unsigned char*);
extern "C" void fn_800D00F0(void*, void*, void*);
extern "C" void fn_800CFEF0(void*, void*, void*);
extern "C" void fn_800CF2B0(void** p) {
    *p = lbl_8049AE38;
    *p = lbl_8049AE24;
}

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

extern "C" void fn_800CF370(void** p) {
    *p = lbl_8049AE10;
    *p = lbl_8049AE38;
}

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

extern "C" void fn_800CF678(void*, void*, void*);
extern "C" void fn_800CF734(void*, unsigned char*, const unsigned char*);
extern "C" void fn_800CF650(void** p, void* a) {
    fn_800CF678(p, p[1], a);
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

extern "C" void fn_800CF8CC(void** self, void* data)
{
    fn_800CF8F4(self, self[1], data);
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

extern "C" void fn_800CFE04(void** self, void* data)
{
    fn_800CFE2C(self, self[1], data);
}

extern "C" void fn_800CFEC8(void** self, void* data)
{
    fn_800CFEF0(self, self[1], data);
}

extern "C" void fn_800D00C8(void** self, void* data)
{
    fn_800D00F0(self, (unsigned char*)self[1], (unsigned char*)data);
}

extern "C" void fn_800D00F0(void* param_1, void* param_2, void* param_3) {
    unsigned char* anm = (unsigned char*)param_2;
    const unsigned char* data = (const unsigned char*)param_3;
    *(short*)(anm + 6) = *(const short*)(data + 12);
    anm[4] = data[8];
    *(float*)(anm + 8) = 0.0f;
    *(unsigned short*)(anm + 0x14) = *(const unsigned short*)(data + 14);
    *(unsigned short*)(anm + 0xc) = *(const unsigned short*)(data + 16);
    *(unsigned short*)(anm + 0xe) = *(const unsigned short*)(data + 18);
    *(unsigned short*)(anm + 0x10) = *(const unsigned short*)(data + 20);
    *(unsigned short*)(anm + 0x12) = *(const unsigned short*)(data + 22);
    *(void**)(anm + 0x3c) = JSUConvertOffsetToPtr<J3DAnmColorKeyTable>(data, (void*)*(const unsigned int*)(data + 0x18));
    *(void**)(anm + 0x2c) = JSUConvertOffsetToPtr<short>(data, (void*)*(const unsigned int*)(data + 0x24));
    *(void**)(anm + 0x30) = JSUConvertOffsetToPtr<short>(data, (void*)*(const unsigned int*)(data + 0x28));
    *(void**)(anm + 0x34) = JSUConvertOffsetToPtr<short>(data, (void*)*(const unsigned int*)(data + 0x2c));
    *(void**)(anm + 0x38) = JSUConvertOffsetToPtr<short>(data, (void*)*(const unsigned int*)(data + 0x30));
    *(void**)(anm + 0x18) = JSUConvertOffsetToPtr<unsigned short>(data, (void*)*(const unsigned int*)(data + 0x1c));
    ((JUTNameTab*)(anm + 0x1c))->setResource(JSUConvertOffsetToPtr<ResNTAB>(data, (void*)*(const unsigned int*)(data + 0x20)));
}

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

void fn_800D0298(void* self, void* res, void* data);
extern "C" void fn_800D0298(void*, void*, void*);
extern "C" void fn_800D0270(void** self, void* data)
{
    fn_800D0298(self, self[1], data);
}

extern "C" void fn_800D044C(void** self, void* res, const void* data);
extern "C" void fn_800D0424(void** self, const void* data) {
    fn_800D044C(self, self[1], data);
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

#if defined(VERSION_G4SJ01)
extern "C" void** fn_800D0620(void** p, short flag)
{
    if (p != 0) {
        *p = lbl_8049AE5C;
        if (p != 0) {
            *p = __vt__15J3DAnmTransform;
            if (p != 0) {
                *p = __vt__10J3DAnmBase;
            }
        }
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
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
#else
extern "C" void* fn_800D0620(void* param_1, short param_2)
{
    if (param_1 != 0) {
        ((void**)param_1)[0] = &lbl_8049AE5C;
        if (param_1 != 0) {
            ((void**)param_1)[0] = &__vt__15J3DAnmTransform;
        }
        if (param_1 != 0) {
            ((void**)param_1)[0] = &__vt__10J3DAnmBase;
        }
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}
#endif

extern "C" int fn_800D068C(void)
{
    return 8;
}

extern "C" void fn_800D0694(const J3DAnmTransformKey* p1, unsigned short p2, J3DTransformInfo* p3) {
    p1->calcTransform(p1->mCurrentFrame, p2, p3);
}

extern "C" void fn_800D00F0(void*, void*, void*);
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

