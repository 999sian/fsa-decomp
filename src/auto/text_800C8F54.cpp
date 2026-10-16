// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"

class J3DMaterial;
class J3DMaterialFactory {
public:
    enum MaterialType {
        NORMAL = 0,
        LOCKED = 1,
        PATCHED = 2,
    };
    size_t calcSize(J3DMaterial*, MaterialType, int, u32) const;
    size_t calcSizeNormalMaterial(J3DMaterial*, int, u32) const;
    size_t calcSizePatchedMaterial(J3DMaterial*, int, u32) const;
    size_t calcSizeLockedMaterial(J3DMaterial*, int, u32) const;
};

extern volatile s32 lbl_8053BC70;

struct J3DNBTScaleInfo {
    u8 mHasScale;
    f32 mScale[3];
};
extern "C" J3DNBTScaleInfo j3dDefaultNBTScaleInfo;
extern "C" char lbl_8049AA38[];
extern "C" char __vt__10J3DPEBlock[];

#include <types.h>

extern "C" void fn_800C9CF4(void)
{
}

void fn_800C9CF8(void)
{
}

void fn_800C9CFC(void)
{
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
    u8* base = *(u8**)(p + 4);
    u32 off = ((u16*)*(u8**)(p + 8))[idx] * 0x14c;
    u16 v = *(u16*)(base + off + 0x84 + b * 2);
    if (v != 0xffff) {
        return (*(u16**)(p + 0x38))[v];
    }
    return 0xffff;
}

extern unsigned int j3dDefaultTevOrderInfoNull;
extern "C" void fn_800CB314(u32* out, u8* p, s32 idx, s32 b) {
    u32 off = ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0xbc;
    u16 v = *(u16*)(*(u8**)(p + 4) + off + b * 2);
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
    u32 off = ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0xdc + b * 2;
    u16 v = *(u16*)(*(u8**)(p + 4) + off);
    if (v != 0xffff) {
        u32* e = (u32*)(*(u8**)(p + 0x44) + v * 8);
        out[0] = e[0];
        out[1] = e[1];
        return;
    }
    out[0] = lbl_80543F08;
    out[1] = lbl_80543F0C;
}

extern "C" void fn_800CB3D0(u32* out, u8* p, s32 idx, s32 b) {
    u32 off = ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0x94 + b * 2;
    u16 v = *(u16*)(*(u8**)(p + 4) + off);
    if (v != 0xffff) {
        *out = (*(u32**)(p + 0x48))[v];
        return;
    }
    *out = lbl_8053BC78;
}

extern "C" u8 fn_800CB428(u8* p, s32 idx) {
    u16 i = ((u16*)*(u8**)(p + 8))[idx];
    u8* base = *(u8**)(p + 4);
    u8 v = base[i * 0x14c + 4];
    if (v != 0xff) {
        return (*(u8**)(p + 0x4c))[v];
    }
    return 0xff;
}

extern "C" void fn_800CB460(void* out, u8* p, s32 idx, s32 b) {
    u32 off = ((u16*)*(u8**)(p + 8))[idx] * 0x14c + 0xe4 + b * 2;
    u16 v = *(u16*)(*(u8**)(p + 4) + off);
    if (v != 0xffff) {
        fn_800CB4C0(out, *(u8**)(p + 0x50) + v * 0x14);
        return;
    }
    __ct__11J3DTevStageFv(out);
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

