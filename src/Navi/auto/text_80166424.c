

#include "types.h"
extern void* lbl_80298390[];


extern "C" void fn_8015AB1C(void* p);
extern "C" s32 fn_80166A54(void);
extern "C" void fn_801667B4(void* a, u32 b, u32 c, u32 d);
extern "C" void fn_80166970(void* a, u32 b, u32 c, u32 d);

typedef void VFn_80169B1C(u32*, int);
struct UnkVObj_80166424 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u8);
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual u8 vf18(void*);
};
struct DtorVObj_80166424 {
    virtual void Destroy(int);
};
extern "C" void* lbl_80298644[];
extern "C" void* lbl_80298600[];
extern "C" u8 lbl_80298660[];
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_8016B170(u32*, int);
extern "C" void fn_8015D29C(void*, int);
extern "C" void* fn_8015D13C(void*, int, int, void*);
extern "C" void fn_801C0EEC(void*);
extern "C" u8 lbl_80298304[];

struct Unk80174858Pair {
    u8 x;
    u8 y;
};

struct UnkVObj_801671B0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u32 vf5();
    virtual s32 vf6(u32, u32);
    virtual u32 vf7();
    virtual s32 vf8(u32, u32);
};

struct UnkVObj_80167128 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual u32 vf5(void*, u32);
};

struct UnkVObj_801670D0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual u32 vf5();
};

extern "C" void fn_801BDDBC(void*, void*, int);
extern "C" u8* fn_80166ACC(u8* p);
extern "C" void* fn_80166B1C(void* ptr, s16 param_2);
extern "C" void* fn_8015A9A8(int, void*, int);
extern "C" void fn_801BDE1C(void*, void*, int);
extern "C" void fn_801BDEE4(void*, void*, int);
extern "C" u8 lbl_802982A0[];
extern "C" void* lbl_802FF540;
extern "C" void* lbl_802FF688;
extern "C" void* fn_801664D8(void* ptr, void* param_2);
extern "C" void fn_80166C08(void*, int);
extern "C" void* fn_80166424(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_80166478(void* param_1) {
    if (lbl_802FF688 == nullptr) {
        void* p = fn_8015A9A8(0x7c, lbl_802FF540, 0);
        if (p != nullptr) {
            p = fn_801664D8(p, param_1);
        }
        lbl_802FF688 = p;
    }
    return lbl_802FF688;
}

extern "C" void* fn_801664D8(void* ptr, void* param_2)
{
    void* r31 = ptr;
    fn_8015D13C(ptr, 0x4000, 0x10, param_2);
    *(void**)r31 = (void*)lbl_80298304;
    fn_801C0EEC(((void**)r31)[0xb]);
    return r31;
}

extern "C" void* fn_80166528(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80298304;
        fn_8015D29C(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80166650(void* p)
{
    fn_801BDE1C(lbl_802982A0, p, 1);
}

#pragma use_lmw_stmw off
extern "C" s32 fn_80166680(u32 a, u32 b, u32 c, u32 d)
{
    u8 buf[0x8];
    u8* p = (u8*)fn_8015A9A8(0x4c, lbl_802FF540, -4);
    if (p != nullptr) {
        p = (u8*)fn_80166ACC(p);
    }
    *(u32*)(p + 0x4) = a;
    *(u32*)(p + 0x8) = b;
    *(u32*)(p + 0xc) = c;
    *(u32*)(p + 0x10) = d;
    *(u32*)(p + 0x14) = 0;
    fn_801BDE1C(lbl_802982A0, p, 1);
    fn_801BDEE4(p + 0x28, buf, 1);
    fn_80166B1C(p, 1);
    return 1;
}

extern "C" void fn_80166728(void* a, u32 b, u32 c, u32 d)
{
    s32 r = fn_80166A54();
    if (r == 1) {
        fn_801667B4(a, b, c, d);
    } else if (r == 2) {
        fn_80166970(a, b, c, d);
    }
}

#pragma use_lmw_stmw reset

extern "C" u8* fn_80166ACC(u8* p)
{
    fn_801BDDBC(p + 0x28, p + 0x48, 1);
    *(u32*)(p + 0x14) = 0;
    *(u32*)(p + 0x1c) = 0;
    *(u8**)(p + 0x18) = p;
    *(u32*)(p + 0x20) = 0;
    return p;
}

extern "C" void* fn_80166B1C(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80166B58(u32* param_1, u32 param_2)
{
	param_1[1] = 0;
	*param_1 = param_2;
	param_1[2] = 0;
	param_1[3] = 0;
}

extern "C" u32 fn_80166FC4(void*, void*);
extern "C" void* fn_80166B70(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        if (*(void**)((u8*)param_1 + 4) != nullptr) {
            fn_80166FC4(*(void**)((u8*)param_1 + 4), param_1);
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80166C70(void* param_1) {
    *(u32*)param_1 = 0;
    *(u32*)((u8*)param_1 + 4) = 0;
    *(u32*)((u8*)param_1 + 8) = 0;
}

extern "C" u32 fn_80166D3C(void** param_1, void* param_2) {
    u32 uVar1 = (*(void**)((u8*)param_2 + 4) == nullptr);
    if (!uVar1) {
        uVar1 = fn_80166FC4(*(void**)((u8*)param_2 + 4), param_2);
    }
    if ((uVar1 & 0xff) != 0) {
        if ((u32)param_1[2] == 0) {
            *(void***)((u8*)param_2 + 4) = param_1;
            *(u32*)((u8*)param_2 + 8) = 0;
            *(u32*)((u8*)param_2 + 0xc) = 0;
            param_1[1] = param_2;
            *param_1 = param_2;
            param_1[2] = (void*)1;
        } else {
            *(void***)((u8*)param_2 + 4) = param_1;
            *(u32*)((u8*)param_2 + 8) = 0;
            *(void**)((u8*)param_2 + 0xc) = *param_1;
            *(void**)((u8*)*param_1 + 8) = param_2;
            *param_1 = param_2;
            param_1[2] = (void*)((u32)param_1[2] + 1);
        }
    }
    return uVar1;
}

extern "C" u32 fn_80166FC4(void* p_list, void* p_node)
{
    u32* list = (u32*)p_list;
    u32* node = (u32*)p_node;
    u32 r = __cntlzw((u32)list - node[1]);
    if ((u8)(r >> 5)) {
        if (list[2] == 1) {
            list[0] = 0;
            list[1] = 0;
        } else if ((u32)node == list[0]) {
            ((u32*)node[3])[2] = 0;
            list[0] = node[3];
        } else if ((u32)node == list[1]) {
            ((u32*)node[2])[3] = 0;
            list[1] = node[2];
        } else {
            ((u32*)node[2])[3] = node[3];
            ((u32*)node[3])[2] = node[2];
        }
        node[1] = 0;
        list[2] = list[2] - 1;
    }
    return r >> 5;
}

extern "C" void* fn_80167074(void* ptr, s16 param_2) {
    extern void* lbl_8029839C[];
    extern void* lbl_80298390[];
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029839C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80298390;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801670D0(UnkVObj_801670D0* self, u32 unused, s32 n)
{
    s32 v = self->vf5();
    if (v != n) {
        *((u8*)self + 4) |= 1;
    }
}

extern "C" s32 fn_80167128(UnkVObj_80167128* self, s32 n)
{
    s32 i;
    u8 buf[8];
    for (i = 0; i < n; i++) {
        if (self->vf5(buf, 1) != 1) {
            *((u8*)self + 4) |= 1;
            break;
        }
    }
    return i;
}

extern "C" s32 fn_801671B0(UnkVObj_801671B0* param_1, u32 param_2) {
    u32 size = param_1->vf5();
    u32 aligned = param_2 + size;
    aligned = (aligned - 1) & ~(param_2 - 1);
    s32 diff = aligned - size;
    if (diff != 0) {
        s32 r = param_1->vf6(aligned, 0);
        if (r != diff) {
            *((u8*)param_1 + 4) |= 1;
        }
    }
    return diff;
}

extern "C" void* fn_80167404(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80298390;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_801679DC(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80168280(void);
extern "C" void* fn_80167E08(void);
extern "C" void fn_80167CB8(void) {
    fn_80168280();
}

extern "C" void* fn_80167CD8(u8* param_1, u32* param_2, u32* param_3) {
    u32* dst = param_2;
    u32 n = ((u32)*(u32**)(param_1 + 8) + 3 - (u32)param_3) >> 2;
    if (param_3 < *(u32**)(param_1 + 8)) {
        for (u32 i = n >> 3; i != 0; i--) {
            dst[0] = param_3[0];
            dst[1] = param_3[1];
            dst[2] = param_3[2];
            dst[3] = param_3[3];
            dst[4] = param_3[4];
            dst[5] = param_3[5];
            dst[6] = param_3[6];
            dst[7] = param_3[7];
            param_3 += 8;
            dst += 8;
        }
        n &= 7;
        for (; n != 0; n--) {
            *dst++ = *param_3++;
        }
    }
    for (u32* p = dst; p != *(u32**)(param_1 + 8); p++) {
    }
    *(u32**)(param_1 + 8) = dst;
    return param_2;
}

extern "C" void fn_80167D90(u8* param_1, u32 param_2, u32 param_3, u32* param_4) {
    if (param_3 != 0) {
        u32* p = (u32*)fn_80167E08();
        if (p != *(u32**)(param_1 + 8)) {
            u32 v = *param_4;
            for (u32 i = param_3; i != 0; i--) {
                if (p != nullptr) {
                    *p = v;
                }
                p++;
            }
        }
    }
}

extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_80298520[];
extern "C" void* fn_80168D68(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80298520;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80168E00(void)
{
}

extern "C" void fn_801DE01C(u8 a, u8 b, u8 c);
extern "C" void fn_8016991C(u8* p, s32 x)
{
    fn_801DE01C((u8)x, p[0], p[1]);
}

extern "C" void fn_801DE160(u8 a, u8 b, u8 c);
extern "C" void fn_8016994C(u8* p, s32 x)
{
    fn_801DE160((u8)x, p[0], p[1]);
}

extern "C" int fn_8016997C()
{
	return 0;
}

extern "C" int fn_8016999C()
{
	return 0;
}

extern "C" int fn_801699A4()
{
	return 0;
}

extern "C" int fn_801699AC()
{
	return 0;
}

extern "C" int fn_801699B4(void) {
    return 0xFFFF;
}

extern "C" int fn_801699C0(void) {
    return 0xFFFF;
}

extern "C" int fn_801699CC(void)
{
    return 1;
}

extern "C" int fn_801699D4()
{
	return 0;
}

extern "C" int fn_801699DC()
{
	return 0;
}

extern "C" int fn_801699E4()
{
	return 0;
}

extern "C" int fn_801699EC()
{
	return 0;
}

extern "C" u32* fn_80169B1C(u32* self, short param_2)
{
    if (self != NULL) {
        self[0] = (u32)lbl_80298644;
        u32* p = (u32*)self[0x1c];
        if (p != NULL) {
            VFn_80169B1C** vt = (VFn_80169B1C**)*p;
            vt[0xb8 / 4](p, 1);
        }
        p = (u32*)self[0x1d];
        if (p != NULL) {
            ((VFn_80169B1C**)*p)[0x34 / 4](p, 1);
        }
        fn_8015AB1C((void*)self[0x21]);
        fn_8016B170(self + 10, -1);
        if ((u8*)self + 0x10 != NULL) {
            self[9] = (u32)lbl_80298660;
        }
        if (param_2 > 0) {
            fn_8015AB1C(self);
        }
    }
    return self;
}

extern "C" void* fn_8016ABEC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80298600;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80298B14[];
extern "C" void* fn_8016AC34(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80298B14;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8016AC7C(void)
{
}

extern "C" void fn_8016AC80(void)
{
}

extern "C" void fn_8016AC84(void)
{
}

extern "C" void fn_8016AC88(void)
{
}

extern "C" void fn_8016AC8C(void)
{
}

extern "C" void fn_8016AC90(void)
{
}

extern void* lbl_802985C8[];
extern void* lbl_80298600[];
extern "C" void* fn_8016ACA0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802985C8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80298600;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8016ACFC(void) {
}

extern "C" void fn_8016AD00(void) {
}

extern "C" void fn_8016AD04() {}

extern "C" void fn_8016AD08() {}

extern "C" void fn_8016AD0C() {}

extern const u8 lbl_80202218[3];
extern "C" void fn_8016AD10(u8* p) {
    p[0] = lbl_80202218[0];
    p[1] = lbl_80202218[1];
    p[2] = lbl_80202218[2];
}

extern "C" void* fn_8016AD40(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern u8 lbl_80301AC0[2];
extern "C" void fn_8016AD7C(u8* p) {
    p[0] = lbl_80301AC0[0];
    p[1] = lbl_80301AC0[1];
}

extern "C" void* fn_8016AD94(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern u8 lbl_80301AB4[2];
extern "C" void fn_8016AE10(u8* p) {
    p[0] = lbl_80301AB4[0];
    p[1] = lbl_80301AB4[1];
}

extern "C" void fn_8016AE28(void) {
}

extern "C" void fn_80118BD0(void*, int);
extern "C" int fn_8016BC8C(u8* p, void* a, void* b)
{
    if (a != 0) {
        return 0;
    }
    if (p[0x5c] & 1) {
        fn_80118BD0(*(void**)(p + 0x50), 1);
    }
    *(void**)(p + 0x50) = b;
    p[0x5c] &= 0x80;
    fn_8015AB1C(*(void**)(p + 0x54));
    *(void**)(p + 0x54) = 0;
    *(u16*)(p + 4) = 0xffff;
    return 1;
}

extern "C" int fn_8016BD18(u8* p, u32 a)
{
    if (a >= 1) {
        return 0;
    }
    if (p[0x5c] & 1) {
        fn_80118BD0(*(void**)(p + 0x50), 1);
    }
    *(void**)(p + 0x50) = 0;
    p[0x5c] &= 0x80;
    fn_8015AB1C(*(void**)(p + 0x54));
    *(u16*)(p + 4) = 0xffff;
    return 1;
}

extern "C" void* fn_8015A90C(u32);
extern "C" void* fn_80119904(void*, void*, int);
extern "C" int fn_8016BD94(u8* p, void* src)
{
    void* obj;
    DtorVObj_80166424* old;
    if (src == 0) {
        return 0;
    }
    obj = fn_8015A90C(0x70);
    if (obj != 0) {
        obj = fn_80119904(obj, src, 0);
    }
    if (obj == 0) {
        return 0;
    }
    if (p[0x5c] & 0x80) {
        old = *(DtorVObj_80166424**)(p + 0x58);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0x58) = obj;
    p[0x5c] = (p[0x5c] & 0x7f) | 0x80;
    return 1;
}

extern "C" int fn_8016BE50(u8* p, void* obj)
{
    DtorVObj_80166424* old;
    if (obj == 0) {
        return 0;
    }
    if (p[0x5c] & 0x80) {
        old = *(DtorVObj_80166424**)(p + 0x58);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0x58) = obj;
    p[0x5c] &= 0x7f;
    return 1;
}

extern "C" void fn_8016BF98(u8* p)
{
    p[0x5c] &= 0x80;
}

extern "C" void fn_801191F0(void*);
extern "C" void fn_8016C1F4(u8* p, int unused, u32 idx)
{
    u8* obj;
    if (idx != 0) {
        return;
    }
    obj = ((u8**)(p + 0x50))[idx];
    if (obj != 0 && *(void**)(obj + 0x20) != 0) {
        fn_801191F0(obj);
    }
}

#pragma use_lmw_stmw off
extern "C" int fn_8016CEB4(u8* p, u32 idx, void* val)
{
    int mask;
    if (idx >= 2) {
        return 0;
    }
    if (p[0x78] & (mask = 1 << idx)) {
        fn_80118BD0(((void**)(p + 0x64))[idx], 1);
    }
    ((void**)(p + 0x64))[idx] = val;
    p[0x78] &= ~mask;
    fn_8015AB1C(((void**)(p + 0x6c))[idx]);
    ((void**)(p + 0x6c))[idx] = 0;
    ((u16*)(p + 4))[idx] = 0xFFFF;
    return 1;
}
#pragma use_lmw_stmw reset

extern "C" int fn_8016D038(u8* p, void* src)
{
    void* obj;
    DtorVObj_80166424* old;
    if (src == 0) {
        return 0;
    }
    obj = fn_8015A90C(0x70);
    if (obj != 0) {
        obj = fn_80119904(obj, src, 0);
    }
    if (obj == 0) {
        return 0;
    }
    if (p[0x78] & 0x80) {
        old = *(DtorVObj_80166424**)(p + 0x74);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0x74) = obj;
    p[0x78] = (p[0x78] & 0x7f) | 0x80;
    return 1;
}

extern "C" int fn_8016D0F4(u8* p, void* obj)
{
    DtorVObj_80166424* old;
    if (obj == 0) {
        return 0;
    }
    if (p[0x78] & 0x80) {
        old = *(DtorVObj_80166424**)(p + 0x74);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0x74) = obj;
    p[0x78] &= 0x7f;
    return 1;
}

extern "C" void fn_8016D24C(u8* p, u8 n, u8 flag)
{
    u8 top = p[0x78] & 0x80;
    p[0x78] &= 0x7f;
    if (flag) {
        int mask = (1 << n) - 1;
        p[0x78] = (p[0x78] & mask) | ((p[0x78] & ~mask) << 1);
    } else {
        p[0x78] = (p[0x78] & ((1 << n) - 1)) | ((int)(p[0x78] & ~((1 << (n + 1)) - 1)) >> 1);
    }
    p[0x78] |= top;
}

extern "C" void fn_8016D5BC(u8* p, int unused, u32 idx)
{
    u8* obj;
    if (idx >= 2) {
        return;
    }
    obj = ((u8**)(p + 0x64))[idx];
    if (obj != 0 && *(void**)(obj + 0x20) != 0) {
        fn_801191F0(obj);
    }
}

#pragma push
#pragma use_lmw_stmw off
extern "C" int fn_8016E4E0(u8* p, u32 idx, void* val)
{
    int mask;
    if (idx >= 4) {
        return 0;
    }
    if (p[0xb0] & (mask = 1 << idx)) {
        fn_80118BD0(((void**)(p + 0x8c))[idx], 1);
    }
    ((void**)(p + 0x8c))[idx] = val;
    p[0xb0] &= ~mask;
    fn_8015AB1C(((void**)(p + 0x9c))[idx]);
    ((void**)(p + 0x9c))[idx] = 0;
    ((u16*)(p + 4))[idx] = 0xFFFF;
    return 1;
}

extern "C" int fn_8016E7A0(u8* p, void* src)
{
    void* obj;
    DtorVObj_80166424* old;
    if (src == 0) {
        return 0;
    }
    obj = fn_8015A90C(0x70);
    if (obj != 0) {
        obj = fn_80119904(obj, src, 0);
    }
    if (obj == 0) {
        return 0;
    }
    if (p[0xb0] & 0x80) {
        old = *(DtorVObj_80166424**)(p + 0xac);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0xac) = obj;
    p[0xb0] = (p[0xb0] & 0x7f) | 0x80;
    return 1;
}

extern "C" int fn_8016E85C(u8* p, void* obj)
{
    DtorVObj_80166424* old;
    if (obj == 0) {
        return 0;
    }
    if (p[0xb0] & 0x80) {
        old = *(DtorVObj_80166424**)(p + 0xac);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0xac) = obj;
    p[0xb0] &= 0x7f;
    return 1;
}

extern "C" void fn_8016E9B4(u8* p, u8 n, u8 flag)
{
    u8 top = p[0xb0] & 0x80;
    p[0xb0] &= 0x7f;
    if (flag) {
        int mask = (1 << n) - 1;
        p[0xb0] = (p[0xb0] & mask) | ((p[0xb0] & ~mask) << 1);
    } else {
        p[0xb0] = (p[0xb0] & ((1 << n) - 1)) | ((int)(p[0xb0] & ~((1 << (n + 1)) - 1)) >> 1);
    }
    p[0xb0] |= top;
}

extern "C" void fn_8016ED24(u8* p, int unused, u32 idx)
{
    u8* obj;
    if (idx >= 4) {
        return;
    }
    obj = ((u8**)(p + 0x8c))[idx];
    if (obj != 0 && *(void**)(obj + 0x20) != 0) {
        fn_801191F0(obj);
    }
}

#pragma use_lmw_stmw off
extern "C" int fn_8016FD58(u8* p, u32 idx, void* val)
{
    int mask;
    if (idx >= 8) {
        return 0;
    }
    if (p[0x120] & (mask = 1 << idx)) {
        fn_80118BD0(((void**)(p + 0xdc))[idx], 1);
    }
    ((void**)(p + 0xdc))[idx] = val;
    p[0x120] &= ~mask;
    fn_8015AB1C(((void**)(p + 0xfc))[idx]);
    ((void**)(p + 0xfc))[idx] = 0;
    ((u16*)(p + 4))[idx] = 0xFFFF;
    return 1;
}
#pragma use_lmw_stmw reset

extern "C" int fn_80170018(u8* p, void* src)
{
    void* obj;
    DtorVObj_80166424* old;
    if (src == 0) {
        return 0;
    }
    obj = fn_8015A90C(0x70);
    if (obj != 0) {
        obj = fn_80119904(obj, src, 0);
    }
    if (obj == 0) {
        return 0;
    }
    if (p[0x121]) {
        old = *(DtorVObj_80166424**)(p + 0x11c);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0x11c) = obj;
    p[0x121] = 1;
    return 1;
}

extern "C" int fn_801700CC(u8* p, void* obj)
{
    DtorVObj_80166424* old;
    if (obj == 0) {
        return 0;
    }
    if (p[0x121]) {
        old = *(DtorVObj_80166424**)(p + 0x11c);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0x11c) = obj;
    p[0x121] = 0;
    return 1;
}

extern "C" void fn_80170220(u8* p, u32 bit, u8 flag) {
    if (flag != 0) {
        u32 mask = (1 << (u8)bit) - 1;
        u8 v = p[0x120];
        p[0x120] = (v & mask) | ((v & ~mask) << 1);
        return;
    }
    {
        u32 mask = (1 << ((u8)bit + 1)) - 1;
        u8 v = p[0x120];
        p[0x120] = (v & ((1 << (u8)bit) - 1)) | ((s32)(v & ~mask) >> 1);
    }
}

extern "C" void fn_80170574(u8* p, int unused, u32 idx) {
    u8* obj;
    if (idx >= 8) {
        return;
    }
    obj = ((u8**)(p + 0xdc))[idx];
    if (obj != 0 && *(void**)(obj + 0x20) != 0) {
        fn_801191F0(obj);
    }
}

extern "C" int fn_80171640(u8* p, u32 idx, void* val)
{
    int mask;
    if (idx >= 8) {
        return 0;
    }
    if (p[0x1b0] & (mask = 1 << idx)) {
        fn_80118BD0(((void**)(p + 0x16c))[idx], 1);
    }
    ((void**)(p + 0x16c))[idx] = val;
    p[0x1b0] &= ~mask;
    fn_8015AB1C(((void**)(p + 0x18c))[idx]);
    ((void**)(p + 0x18c))[idx] = 0;
    ((u16*)(p + 4))[idx] = 0xFFFF;
    return 1;
}

extern "C" int fn_80171900(u8* p, void* src)
{
    void* obj;
    DtorVObj_80166424* old;
    if (src == 0) {
        return 0;
    }
    obj = fn_8015A90C(0x70);
    if (obj != 0) {
        obj = fn_80119904(obj, src, 0);
    }
    if (obj == 0) {
        return 0;
    }
    if (p[0x1b1]) {
        old = *(DtorVObj_80166424**)(p + 0x1ac);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0x1ac) = obj;
    p[0x1b1] = 1;
    return 1;
}

#pragma pop
extern "C" int fn_801719B4(u8* p, DtorVObj_80166424* obj) {
    DtorVObj_80166424* old;
    if (obj == 0) {
        return 0;
    }
    if (p[0x1b1]) {
        old = *(DtorVObj_80166424**)(p + 0x1ac);
        if (old != 0) {
            old->Destroy(1);
        }
    }
    *(void**)(p + 0x1ac) = obj;
    p[0x1b1] = 0;
    return 1;
}

extern "C" void fn_801191F0(void* p);
extern "C" void fn_80171B08(u8* p, u32 bit, u8 flag) {
    if (flag != 0) {
        u32 mask = (1 << (u8)bit) - 1;
        u8 v = p[0x1b0];
        p[0x1b0] = (v & mask) | ((v & ~mask) << 1);
        return;
    }
    {
        u32 mask = (1 << ((u8)bit + 1)) - 1;
        u8 v = p[0x1b0];
        p[0x1b0] = (v & ((1 << (u8)bit) - 1)) | ((s32)(v & ~mask) >> 1);
    }
}

extern "C" void fn_80171E5C(u8* p, u32 unused, u32 idx) {
    u8* obj;
    if (idx >= 8) {
        return;
    }
    obj = ((u8**)(p + 0x16c))[idx];
    if (obj != 0 && *(void**)(obj + 0x20) != 0) {
        fn_801191F0(obj);
    }
}

extern "C" u8 lbl_80301ADC;
extern "C" void fn_801721F0(u8* p) {
    *p = lbl_80301ADC;
}

extern "C" void fn_80172464(void)
{
}

extern "C" u32 fn_801725E4(void) { return 0x10; }

extern "C" void fn_801725EC(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" unsigned short fn_80172614(int param_1) {
    return *(unsigned short*)(param_1 + 0x14);
}

extern "C" void fn_8017261C(u8* p1, s32 p2, u8* p3) {
    u8* p = p1 + p2 * 4;
    p[0x16] = p3[0];
    p[0x17] = p3[1];
    p[0x18] = p3[2];
}

extern "C" s32 fn_80172640(s32 p, s32 i) {
    return p + i * 4 + 0x16;
}

extern "C" void fn_8017288C(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" unsigned short fn_801728B4(int param_1) {
    return *(unsigned short*)(param_1 + 0x14);
}

extern "C" s32 fn_801728E0(s32 p, s32 i) {
    return p + i * 4 + 0x16;
}

extern "C" void fn_80172974(u8* p, s32 i, u8 v) {
    p[i + 0xa8] = v;
}

extern "C" u8 fn_80172980(u8* p, s32 i) {
    return p[i + 0xa8];
}

extern "C" void fn_8017298C(u8* p, s32 i, u8 v) {
    p[i + 0xb0] = v;
}

extern "C" unsigned char fn_80172998(int param_1, int param_2) {
    return ((unsigned char*)(param_1 + 0xb0))[param_2];
}

extern "C" void fn_801729A4(int param_1, unsigned char param_2) {
    *(unsigned char*)(param_1 + 0x56) = param_2;
}

extern "C" unsigned char fn_801729AC(int param_1) {
    return *(unsigned char*)(param_1 + 0x56);
}

extern "C" void fn_801729B4(u8* p, s32 i, u8* src) {
    u8* d = p + i * 8;
    d[0x58] = src[1];
    d[0x59] = src[2];
    d[0x5a] = src[3];
    d[0x5c] = src[5];
    d[0x5d] = src[6];
    d[0x5e] = src[7];
}

extern "C" s32 fn_801729F0(s32 p, s32 i) {
    return p + i * 8 + 0x57;
}

extern "C" void fn_80172A04(u8* p, s32 i, s8* src) {
    p += i * 8;
    u8 a = src[0];
    p[0x5e] = (p[0x5e] & ~0xC) | ((u8)src[1] << 2);
    p[0x5e] = (p[0x5e] & ~0x3) | a;
}

extern "C" void fn_80172A3C(u8* p1, s32 p2, u8* p3) {
    p1[p2 + 0xb8] = *p3;
}

extern "C" s32 fn_80172A4C(s32 p1, s32 p2) {
    return p1 + p2 + 0xb8;
}

extern "C" void fn_80172A5C(u8* p1, s32 p2, u32* p3) {
    ((u32*)(p1 + 0xbc))[p2] = *p3;
}

extern "C" s32 fn_80172A70(s32 p, s32 i)
{
    return p + i * 4 + 0xbc;
}

extern "C" void fn_80172B2C(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" s32 fn_80172B80(s32 p, s32 i)
{
    return p + i * 4 + 0xe;
}

extern "C" void fn_80172B94(u8* self, s32 idx, s16* src) {
    s16* p = (s16*)(self + (idx << 3));
    p[0xf] = src[0];
    p[0x10] = src[1];
    p[0x11] = src[2];
    p[0x12] = src[3];
}

extern "C" s32 fn_80172BC0(s32 param_1, s32 param_2) {
    return param_1 + param_2 * 8 + 0x1e;
}

extern "C" s32 fn_80172C00(s32 param_1, s32 param_2) {
    return param_1 + param_2 * 4 + 0x60;
}

extern "C" void fn_80172C2C(u8* param_1, u32 param_2, u8 param_3) {
    (param_1 + param_2)[0x74] = param_3;
}

extern "C" u8 fn_80172C38(u8* param_1, u32 param_2) {
    return (param_1 + param_2)[0x74];
}

extern "C" void fn_80172C44(u8* self, u8 v) {
    *(u8*)(self + 0x3e) = v;
}

extern "C" u8 fn_80172C4C(u8* self) {
    return *(u8*)(self + 0x3e);
}

extern "C" void fn_80172C54(s32 param_1, s32 param_2, u8* param_3) {
    s32 p = param_1 + param_2 * 8;
    *(u8*)(p + 0x40) = param_3[1];
    *(u8*)(p + 0x41) = param_3[2];
    *(u8*)(p + 0x42) = param_3[3];
    *(u8*)(p + 0x44) = param_3[5];
    *(u8*)(p + 0x45) = param_3[6];
    *(u8*)(p + 0x46) = param_3[7];
}

extern "C" s32 fn_80172C90(s32 param_1, s32 param_2) {
    return param_1 + param_2 * 8 + 0x3f;
}

extern "C" void fn_80172CA4(u8* param_1, s32 param_2, u8* param_3) {
    u8* p = param_1 + param_2 * 8;
    u32 b = param_3[1];
    u32 a = param_3[0];
    p[0x46] = (p[0x46] & 0xf3) | (b << 2);
    p[0x46] = (p[0x46] & 0xfc) | a;
}

extern "C" void fn_80172CDC(u8* p, s32 i, u8* src) {
    p[i + 0x78] = *src;
}

extern "C" s32 fn_80172CEC(s32 p, s32 i) {
    return p + i + 0x78;
}

extern "C" void fn_80172CFC(u8* p1, int p2, u32* p3) { ((u32*)(p1 + 0x7c))[p2] = *p3; }

extern "C" s32 fn_80172D10(s32 p, s32 i) {
    return p + i * 4 + 0x7c;
}

extern "C" u32 fn_80172DBC(void) { return 0x54564232; }

extern "C" void fn_80172DD0(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" u8* fn_80172E24(u8* p, s32 i) { return p + i * 4 + 10; }

extern "C" u8 fn_80172EC4(u8* p, s32 i) { return *(p + i + 0x54); }

extern "C" void fn_80172ED0(u8* p, s32 i, u8 v) { *(p + i + 0x56) = v; }

extern "C" u8 fn_80172EDC(u8* p, s32 i) { return *(p + i + 0x56); }

extern "C" void fn_80172EE8(u8* p, u8 v) {
    p[0x32] = v;
}

extern "C" u8 fn_80172EF0(u8* p)
{
    return p[0x32];
}

extern "C" void fn_80172EF8(s32 param_1, s32 param_2, u8* param_3) {
    s32 p = param_1 + param_2 * 8;
    *(u8*)(p + 0x34) = param_3[1];
    *(u8*)(p + 0x35) = param_3[2];
    *(u8*)(p + 0x36) = param_3[3];
    *(u8*)(p + 0x38) = param_3[5];
    *(u8*)(p + 0x39) = param_3[6];
    *(u8*)(p + 0x3a) = param_3[7];
}

extern "C" s32 fn_80172F34(s32 p, s32 i)
{
    return p + i * 8 + 0x33;
}

extern "C" void fn_80172FA0(u8* p, s32 i, u32* src)
{
	((u32*)(p + 0x5c))[i] = *src;
}

extern "C" s32 fn_80172FB4(s32 p, s32 i)
{
	return p + i * 4 + 0x5c;
}

extern "C" u32 fn_80172FF8(int param_1, u32 param_2) {
    if (param_2 >= 2) {
        return 0;
    }
    u32* p = (u32*)(param_1 + param_2 * 4);
    return p[0x64 / 4];
}

extern "C" u32 fn_80173018(int param_1, u32 param_2) {
    if (param_2 >= 2) {
        return 0;
    }
    u8* p = (u8*)param_1 + param_2 * 4;
    return *(u32*)(p + 0x6c);
}

extern "C" unsigned int fn_80173060(void) {
    return 0x54564231;
}

extern "C" void fn_80173074(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" void fn_801730A4(int param_1, int param_2, u8* param_3) {
    u8 uVar0 = param_3[0];
    u8* p = (u8*)(param_1 + param_2 * 4);
    p[8] = uVar0;
    p[9] = param_3[1];
    p[10] = param_3[2];
}

extern "C" s32 fn_801730C8(s32 p, s32 i)
{
	return p + i * 4 + 8;
}

extern "C" void fn_801730DC(u8* p, s32 i, s16* src)
{
	s16 v0;
	s16 v1;
	s16 v2;
	s16 v3;
	s16* q;

	v0 = src[0];
	q = (s16*)(p + i * 8);
	v1 = src[1];
	q[6] = v0;
	v2 = src[2];
	q[7] = v1;
	v3 = src[3];
	q[8] = v2;
	q[9] = v3;
}

extern "C" u8* fn_80173108(u8* p, s32 i)
{
    return p + i * 8 + 0xc;
}

extern "C" void fn_8017311C(u8* p, s32 i, u8* src)
{
    u8* dst = p + i * 4;
    dst[0x34] = src[0];
    dst[0x35] = src[1];
    dst[0x36] = src[2];
    dst[0x37] = src[3];
}

extern "C" void fn_8017318C(void)
{
}

extern "C" BOOL fn_80173190(void)
{
    return TRUE;
}

extern "C" void fn_80173300(void)
{
}

extern "C" void fn_80173304(void)
{
}

extern "C" void fn_80173308(void)
{
}

extern "C" void fn_8017330C(void)
{
}

extern "C" void fn_80173310(void)
{
}

extern "C" void fn_80173314(void)
{
}

extern "C" void fn_80173318(void) {
}

extern "C" int fn_8017334C()
{
	return 0;
}

extern "C" int fn_80173354()
{
	return 0;
}

extern "C" int fn_8017335C()
{
	return 0;
}

extern "C" int fn_80173364()
{
	return 0;
}

extern "C" int fn_8017336C()
{
	return 0;
}

extern "C" int fn_80173374()
{
	return 0;
}

extern "C" int fn_8017337C()
{
	return 0;
}

extern "C" void fn_80173384(void)
{
}

extern "C" u8 lbl_80301ACC[4];
extern "C" void fn_801744EC(u8* p, u8* s, u32 a, u32 b) {
    u32 idx = *(u16*)(*(u8**)(s + 4) + (((u16*)*(u8**)(s + 8))[a] * 0xe8 + 0xda) + b * 2);
    u8* t;
    if (idx != 0xffff) {
        t = *(u8**)(s + 0x4c) + idx * 4;
    } else {
        t = lbl_80301ACC;
    }
    p[0] = (t[0] << 6) + (t[1] << 4) + (t[2] << 2) + t[3];
}

extern "C" void fn_80174858(Unk80174858Pair* out, void* ptr, u32 index, u32 subindex) {
    Unk80174858Pair fallback;
    fallback.x = lbl_80301AC0[0];
    fallback.y = lbl_80301AC0[1];
    u8* data = *(u8**)((u8*)ptr + 0xc);
    if (data != nullptr && data[index * 0x128] == 1) {
        Unk80174858Pair* entry = (Unk80174858Pair*)(data + index * 0x128 + subindex * 2 + 0x60);
        out->x = entry->x;
        out->y = entry->y;
    } else {
        *(u16*)out = *(u16*)&fallback;
    }
}

extern "C" u16 lbl_80301ADE;
extern "C" void fn_801748C0(u16* out, void* ptr, u32 index) {
    u8* data = *(u8**)((u8*)ptr + 4);
    u16* indices = *(u16**)((u8*)ptr + 8);
    u16 value = *(u16*)(data + indices[index] * 0xe8 + 0xe2);
    if (value != 0xffff) {
        u8* entry = *(u8**)((u8*)ptr + 0x50) + (u16)value * 8;
        out[0] = ((u8)entry[0] << 5 | (u8)entry[2] << 3) | entry[3];
        ((u8*)out)[2] = entry[1];
        ((u8*)out)[3] = entry[4];
    } else {
        out[0] = lbl_80301ADE;
        ((u8*)out)[2] = 0;
        ((u8*)out)[3] = 0;
    }
}

extern "C" void* fn_80174A50(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174A68(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174A80(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174A98(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174AB0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174AC8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174AE0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174AF8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B10(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B28(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B40(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B58(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B70(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B88(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174BA0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174BB8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern void* lbl_80298C5C[];
extern "C" void* fn_80174C64(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80298C5C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* lbl_802FF540;
extern "C" void* lbl_802FF690;
extern "C" void* lbl_802FF698;
extern "C" u8 lbl_802FF694;
extern "C" int fn_8015AAB0(void*, void*, int);
extern "C" void* fn_80174E9C(void* param_1) {
    void* old = lbl_802FF690;
    if (lbl_802FF694 != 0) {
        fn_8015AB1C(lbl_802FF690);
    }
    lbl_802FF690 = (void*)fn_8015AAB0(param_1, lbl_802FF540, 0);
    lbl_802FF698 = param_1;
    lbl_802FF694 = 1;
    return old;
}

extern "C" u8 fn_80177F0C(char* self, void* arg)
{
    char* n = *(char**)(self + 0xdc);
    if (n != 0) {
        n -= 0xc;
    }
    while (n != 0) {
        if ((*(UnkVObj_80166424**)(n + 0xc))->vf18(arg)) {
            return 1;
        }
        n = *(char**)(n + 0x18);
        if (n != 0) {
            n -= 0xc;
        }
    }
    return 0;
}

extern "C" void fn_801780D4(char* self, u8 v)
{
    char* n;
    *(u8*)(self + 0xb1) = v;
    n = *(char**)(self + 0xdc);
    if (n != 0) {
        n -= 0xc;
    }
    while (n != 0) {
        (*(UnkVObj_80166424**)(n + 0xc))->vf6(v);
        n = *(char**)(n + 0x18);
        if (n != 0) {
            n -= 0xc;
        }
    }
}

extern "C" void* fn_80178424(char* self)
{
    char* l = *(char**)(self + 0xdc);
    char* n = l;
    if (l != 0) {
        n = l - 0xc;
    }
    if (n == 0) {
        return 0;
    }
    if (l != 0) {
        l -= 0xc;
    }
    return *(void**)(l + 0xc);
}

extern "C" void fn_80178DA4(void* param_1)
{
}

extern "C" void fn_80178DA8(void)
{
}

extern "C" void fn_80178DAC(void)
{
}

extern "C" void fn_80178DB0(void* param_1) {
    register void* vtable = *(void**)param_1;
    void (*func)(void) = *(void(**)(void))((u8*)vtable + 0x74);
    func();
}

extern "C" u32 fn_80178E08(void) { return 0x10; }

extern "C" int fn_80178E4C(int param_1) {
    *(u8*)(param_1 + 0xb5) = 0;
    return 0;
}

extern "C" void fn_80178E5C(void* param_1)
{
}

extern "C" void fn_80178E60(void) {
}

