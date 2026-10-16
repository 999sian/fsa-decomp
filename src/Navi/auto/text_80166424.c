#include "types.h"
extern void* lbl_80298600[];


struct S16Quad { s16 v[4]; };

extern "C" void fn_80178C9C(void*, void*);


extern "C" void fn_80168280(void);
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_80166C70(void* param_1);
extern "C" u8 fn_80166FC4(void*);
extern "C" void* fn_80166BD0(void* param_1, u8 param_2) {
    if (param_2) {
        fn_80166C70(param_1);
    }
    return param_1;
}

extern "C" void* fn_80166C08(void* param_1, s16 param_2) {
    if (param_1) {
        u8* node = *(u8**)param_1;
        for (u32 i = 0; i < *(u32*)((u8*)param_1 + 8); i++) {
            *(u32*)(node + 4) = 0;
            node = *(u8**)(node + 0xc);
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

extern "C" void fn_80166C70(void* param_1);
extern "C" u8 fn_80166C84(u8* list, u8* node) {
    u8 ok = *(void**)(node + 4) == 0;
    if (!ok) {
        ok = fn_80166FC4(*(void**)(node + 4));
    }
    if (ok) {
        if (*(u32*)(list + 8) == 0) {
            *(u8**)(node + 4) = list;
            *(u32*)(node + 8) = 0;
            *(u32*)(node + 0xc) = 0;
            *(u8**)(list + 4) = node;
            *(u8**)list = node;
            *(u32*)(list + 8) = 1;
        } else {
            *(u8**)(node + 4) = list;
            *(u8**)(node + 8) = *(u8**)(list + 4);
            *(u32*)(node + 0xc) = 0;
            *(u8**)(*(u8**)(list + 4) + 0xc) = node;
            *(u8**)(list + 4) = node;
            *(u32*)(list + 8) = *(u32*)(list + 8) + 1;
        }
    }
    return ok;
}

extern "C" void fn_80167CB8(void) {
    fn_80168280();
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

extern "C" BOOL fn_801699CC(void)
{
    return TRUE;
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

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_8016B170(void*, int);
extern u8 lbl_80298644[];
extern u8 lbl_80298660[];
typedef void (*VFn_80169B1C)(void*, int);
extern "C" u32* fn_80169B1C(u32* self, short param_2)
{
    if (self != NULL) {
        self[0] = (u32)lbl_80298644;
        u32* p = (u32*)self[0x1c];
        if (p != NULL) {
            (*(VFn_80169B1C*)(p[0] + 0xb8))(p, 1);
        }
        p = (u32*)self[0x1d];
        if (p != NULL) {
            (*(VFn_80169B1C*)(p[0] + 0x34))(p, 1);
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

extern "C" u32 fn_8016AC94(void) {
    return 0x49424C4E;
}

extern void* lbl_802985C8[];
extern void* lbl_80298600[];
extern "C" void fn_8015AB1C(void* ptr);
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

extern "C" void fn_8016AD04(void) {
}

extern "C" void fn_8016AD08(void) {
}

struct ListNode;
extern "C" void fn_801719B4_dummy(void);
extern "C" int fn_801719B4(void* param_1, void* param_2) {
    if (param_2 == 0) {
        return 0;
    }
    if (*(u8*)((u8*)param_1 + 0x1b1) != 0) {
        void* obj = *(void**)((u8*)param_1 + 0x1ac);
        if (obj != 0) {
            void (*fn)(void*, int) = *(void (**)(void*, int))((u8*)*(void**)obj + 8);
            fn(obj, 1);
        }
    }
    *(void**)((u8*)param_1 + 0x1ac) = param_2;
    *(u8*)((u8*)param_1 + 0x1b1) = 0;
    return 1;
}

extern "C" void fn_80171B08(u8* param_1, u8 param_2, u8 param_3) {
    s32 mask;
    s32 b;
    if (param_3) {
        mask = (1 << param_2) - 1;
        b = param_1[0x1b0];
        param_1[0x1b0] = (b & mask) | ((b & ~mask) << 1);
    } else {
        s32 mask2 = (1 << (param_2 + 1)) - 1;
        mask = (1 << param_2) - 1;
        b = param_1[0x1b0];
        param_1[0x1b0] = (b & mask) | ((b & ~mask2) >> 1);
    }
}

extern "C" void fn_801191F0(void* param_1);
extern "C" void fn_80171E5C(void* param_1, int param_2, u32 param_3)
{
    if (param_3 < 8) {
        void* p = *(void**)(((u8*)param_1 + (param_3 * 4)) + 0x16c);
        if (p != NULL && *(void**)((u8*)p + 0x20) != NULL) {
            fn_801191F0(p);
        }
    }
}

extern u16 lbl_80301ADE;
extern u8 lbl_80301AD0[4];
extern u8 lbl_80301AD4;
extern "C" void fn_801720B8(u8* param_1)
{
    *(u16*)param_1 = lbl_80301ADE;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = lbl_80301AD0[0];
    param_1[5] = lbl_80301AD0[1];
    param_1[6] = lbl_80301AD0[2];
    param_1[7] = lbl_80301AD0[3];
    param_1[8] = lbl_80301AD4;
}

extern "C" u32 fn_80172468(void)
{
    return 0x49424c46;
}

extern "C" void fn_801724B4(u8* p, s32 i, f32* src)
{
    u8 d = *((u8*)src + 0x18);
    f32* dst = (f32*)(p + i * 0x1c);

    dst[4] = src[0];
    dst[5] = src[1];
    dst[6] = src[2];
    dst[7] = src[3];
    dst[8] = src[4];
    dst[9] = src[5];
    *(u8*)((u8*)dst + 0x28) = d;
}

extern "C" void fn_801725EC(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" s32 fn_80172640(s32 p, s32 i) {
    return p + i * 4 + 0x16;
}

extern "C" s32 fn_80172750(s32 p, s32 i)
{
    return p + i * 8 + 0x77;
}

extern "C" void fn_8017288C(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" s32 fn_801728E0(s32 p, s32 i) {
    return p + i * 4 + 0x16;
}

extern "C" void fn_8017298C(int param_1, int param_2, u8 param_3) {
    u8* p = (u8*)(param_1 + param_2);
    *(p + 0xb0) = param_3;
}

extern "C" u8 fn_80172998(int param_1, int param_2) {
    u8* p = (u8*)(param_1 + param_2);
    return *(p + 0xb0);
}

extern "C" void fn_801729A4(int param_1, u8 param_2) {
    *(u8*)(param_1 + 0x56) = param_2;
}

extern "C" u8 fn_801729AC(void* p) {
    return *(u8*)((u8*)p + 0x56);
}

extern "C" void fn_801729B4(u8* p, s32 idx, u8* src) {
    u8 a;
    u8 b;
    p = p + idx * 8;
    a = src[2];
    p[0x58] = src[1];
    b = src[3];
    p[0x59] = a;
    a = src[5];
    p[0x5a] = b;
    b = src[6];
    p[0x5c] = a;
    a = src[7];
    p[0x5d] = b;
    p[0x5e] = a;
}

extern "C" s32 fn_801729F0(s32 p, s32 i) {
    return p + i * 8 + 0x57;
}

extern "C" void fn_80172A04(u8* p, s32 i, u8* src) {
    u8* d = p + (i << 3);
    u32 a = src[1];
    u8 b = src[0];
    d[0x5e] = (d[0x5e] & 0xfffffff3) | ((a & 0xff) << 2);
    d[0x5e] = (d[0x5e] & 0xfffffffc) | b;
}

extern "C" void fn_80172A3C(u8* p1, s32 p2, u8* p3) {
    p1[p2 + 0xb8] = *p3;
}

extern "C" u8* fn_80172A4C(u8* p, s32 i) {
    return p + i + 0xb8;
}

extern "C" void fn_80172A5C(u8* p, s32 i, u32* src) {
    ((u32*)(p + 0xbc))[i] = *src;
}

extern "C" s32 fn_80172A70(s32 p, s32 i) {
    return p + i * 4 + 0xbc;
}

extern "C" s32 fn_80172AB4(s32 p, u32 i) {
    if (i >= 8) {
        return 0;
    }
    i = i * 4;
    p = p + i;
    return *(s32*)(p + 0xdc);
}

extern "C" s32 fn_80172AD4(s32 p, u32 i) {
    if (i >= 8) {
        return 0;
    }
    i = i * 4;
    p = p + i;
    return *(s32*)(p + 0xfc);
}

extern "C" s32 fn_80172B18(void) {
    return 0x54564234;
}

extern "C" void fn_80172B2C(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" void fn_80172B5C(s32 p, s32 i, u8* src) {
    u8* dst = (u8*)(p + i * 4);
    dst[0xe] = src[0];
    dst[0xf] = src[1];
    dst[0x10] = src[2];
}

extern "C" s32 fn_80172B80(s32 p, s32 i) {
    return p + i * 4 + 0xe;
}

extern "C" void fn_80172B94(u8* p, s32 i, S16Quad* v) {
    S16Quad* d = (S16Quad*)(p + 0x1e) + i;
    d->v[0] = v->v[0];
    d->v[1] = v->v[1];
    d->v[2] = v->v[2];
    d->v[3] = v->v[3];
}

extern "C" s32 fn_80172BC0(s32 p, s32 i) {
    i = i * 8;
    return p + (i + 0x1e);
}

extern "C" s32 fn_80172C00(s32 p, s32 i) {
    s32 q = p;
    i = i * 4 + 0x60;
    return q + i;
}

extern "C" void fn_80172C2C(s32 p, s32 i, u8 v) {
    p = p + i;
    *(u8*)(p + 0x74) = v;
}

extern "C" u8 fn_80172C38(s32 p, s32 i) {
    p = p + i;
    return *(u8*)(p + 0x74);
}

extern "C" void fn_80172C44(u8* p, u8 v) { p[0x3e] = v; }

extern "C" u8 fn_80172C4C(u8* p) { return p[0x3e]; }

extern "C" s32 fn_80172CEC(s32 p, s32 i) {
    return p + i + 0x78;
}

extern "C" void fn_80172CFC(s32 p, s32 i, s32* v) {
    s32 off = i * 4;
    p += off;
    *(s32*)(p + 0x7c) = *v;
}

extern "C" s32 fn_80172D10(s32 p, s32 i) {
    return p + i * 4 + 0x7c;
}

extern "C" u32 fn_80172DBC(void) {
    return 0x54564232;
}

extern "C" void fn_80172DD0(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" u8* fn_80172E24(u8* p, s32 i) { return p + i * 4 + 10; }

extern "C" int fn_80172EA4(int p, int index) {
    return p + index * 4 + 0x44;
}

extern "C" u8 fn_80172EC4(u8* p, s32 i) { return *(p + i + 0x54); }

extern "C" void fn_80172ED0(u8* p, s32 i, u8 v) { *(p + i + 0x56) = v; }

extern "C" u8 fn_80172EDC(u8* p, s32 i) { return *(p + i + 0x56); }

extern "C" unsigned int fn_80172FF8(unsigned char* self, unsigned int idx) {
    if (idx >= 2) {
        return 0;
    }
    return ((unsigned int*)(self + 0x64))[idx];
}

extern "C" unsigned int fn_80173018(unsigned char* self, unsigned int idx) {
    if (idx >= 2) {
        return 0;
    }
    return ((unsigned int*)(self + 0x6c))[idx];
}

extern "C" unsigned int fn_80173060(void) {
    return 0x54564231;
}

extern "C" void fn_80173074(u8* p, s32 i, u16 v) { ((u16*)(p + 4))[i] = v; }

extern "C" void fn_801730A4(unsigned char* self, int idx, unsigned char* src) {
    unsigned char* p = self + idx * 4;
    p[8] = src[0];
    p[9] = src[1];
    p[10] = src[2];
}

extern "C" u8 fn_80173180(int param_1, int param_2)
{
    int addr = param_1 + param_2;
    return ((u8*)addr)[0x45];
}

extern "C" void fn_8017318C(void)
{
}

extern "C" BOOL fn_80173190(void)
{
    return TRUE;
}

extern "C" void fn_80173198(int param_1, int param_2, int param_3)
{
    u8* base = (u8*)(param_1 + param_2 * 8);
    u8* src = (u8*)param_3;
    base[0x2d] = src[1];
    base[0x2e] = src[2];
    base[0x2f] = src[3];
    base[0x31] = src[5];
    base[0x32] = src[6];
    base[0x33] = src[7];
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

extern u8 lbl_802FF694;
extern void* lbl_802FF690;
extern void* lbl_802FF698;
extern void* lbl_802FF540;
extern "C" void* fn_8015AAB0(void* a, void* p, int b);
extern f32 lbl_80301AF8;
extern "C" void* fn_80174E9C(void* param_1) {
    void* old = lbl_802FF690;
    if (lbl_802FF694 != 0) {
        fn_8015AB1C(old);
    }
    lbl_802FF690 = fn_8015AAB0(param_1, lbl_802FF540, 0);
    lbl_802FF698 = param_1;
    lbl_802FF694 = 1;
    return old;
}

extern "C" void fn_80174F08(u8* param_1) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9();
        virtual u32 v30(); virtual u32 v34();
    };
    if (*(Obj**)(param_1 + 4) != 0) {
        *(f32*)(param_1 + 0x50) = (f32)(*(Obj**)(param_1 + 4))->v30();
        *(f32*)(param_1 + 0x54) = (f32)(*(Obj**)(param_1 + 4))->v34();
    }
}

extern "C" void fn_80174FA0(u8* param_1, f32 a, f32 b) {
    *(f32*)(param_1 + 0x24) = a;
    f32 c = lbl_80301AF8;
    *(f32*)(param_1 + 0x28) = b;
    *(f32*)(param_1 + 0x2c) = a;
    *(f32*)(param_1 + 0x30) = b;
    *(f32*)(param_1 + 0x34) = c;
}

extern "C" void fn_801789D0(int* param_1)
{
	int iVar1;

	(*(void (**)(int*, int))(*param_1 + 0x60))(param_1, 0);
	iVar1 = param_1[0x37];
	if (iVar1 != 0) {
		iVar1 = iVar1 - 0xc;
	}
	while (iVar1 != 0) {
		int* obj = *(int**)(iVar1 + 0xc);
		(*(void (**)(int*))(*obj + 0x54))(obj);
		iVar1 = *(int*)(iVar1 + 0x18);
		if (iVar1 != 0) {
			iVar1 = iVar1 - 0xc;
		}
	}
}

extern "C" void fn_80178B74(void* param_1, void* param_2) {
    (*(void (**)(void*))(*(u8**)param_1 + 0x8c))(param_1);
    u8* it = *(u8**)((u8*)param_1 + 0xdc);
    if (it != NULL) {
        it -= 0xc;
    }
    while (it != NULL) {
        void* obj = *(void**)(it + 0xc);
        it = *(u8**)(it + 0x18);
        (*(void (**)(void*, void*))(*(u8**)obj + 0x88))(obj, param_2);
        if (it != NULL) {
            it -= 0xc;
        }
    }
}

extern "C" void fn_80178DA4(void* param_1)
{
}

extern "C" u32 fn_80178E08(void) { return 0x10; }

extern "C" void fn_80178E5C(void* param_1)
{
}

extern "C" void fn_80178E60(void) {
}

