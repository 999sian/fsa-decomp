#include "types.h"

extern f32 lbl_80301680;

extern s32 lbl_802FDDB0;
extern "C" void fn_80123EC0(void* a, ...);
#include "dolphin/os/OSFastCast.h"
extern "C" void fn_8013A57C(void);
extern "C" void* fn_80139950(void*, void*, void*);
extern "C" void fn_801334AC();
extern "C" void fn_8013345C();
extern void* lbl_802925EC[];
extern void* lbl_80292558[];
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8011f23c-0x80135cf8 (427 functions). split_file divides it into the game's real files.

extern void* lbl_80290ACC[];
extern "C" void* lbl_802FF364;
extern "C" void* lbl_802FF368;
extern "C" void* fn_801328F8(void* ptr, s16 param_2);

extern "C" void fn_8013345C();

static inline void fn_80133624_set(u8* self, int i, f32 v) {
    u8* e = *(u8**)(self + 4) + i * 0x14;
    *(void**)(e + 8) = (void*)fn_8013345C;
    *(u32*)(e + 4) = 0;
    *(f32*)(e + 0xC) = v;
}

class Unk80133A44Listener {
public:
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(void* owner);
    virtual void vf5(void* owner);
};
extern const f32 lbl_803016E0;
extern const f32 lbl_803016E4;
extern const f32 lbl_803017B0;
extern "C" void fn_8012C274(void*);
extern "C" void fn_8015AB1C(void* ptr);
extern u8 lbl_802FF334;
extern f32 lbl_802FEAB4;
extern "C" void fn_80166C08(void*, int);
extern "C" void* fn_8011F23C(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8011FA0C(void)
{
}

extern "C" void* lbl_802FDD84;
extern "C" void* fn_8011FD10(void)
{
	return lbl_802FDD84;
}

extern void* lbl_802FDD84;
extern u8 lbl_802FDD88;
extern void* lbl_802FF328;
extern void* lbl_80290AB4;
extern "C" void* fn_8015A90C(s32 size);
extern void fn_8015AB1C(void* ptr);
extern void* fn_80120138(void* ptr, void* param);
extern void fn_801CB248(void* ptr);
extern void fn_801CB28C(void* ptr);
typedef void (*VirtualMethod0)(void*, s16);
extern "C" void fn_80120090(u8 param_1) {
    lbl_802FDD88 = param_1;
}

extern "C" void* fn_80120098(void* param_1)
{
	void* allocated = lbl_802FF328;
	if (allocated == 0) {
		allocated = fn_8015A90C(0x58);
		if (allocated != 0) {
			allocated = fn_80120138(allocated, param_1);
		}
	}
	lbl_802FF328 = allocated;
	return *(void**)&lbl_802FF328;
}

extern "C" void fn_801200F0(void)
{
	void* obj = lbl_802FF328;
	if (obj != 0) {
		VirtualMethod0 vf = (VirtualMethod0)(*((void**)(*((void***)obj)) + 2));
		vf(obj, 1);
		lbl_802FF328 = 0;
	}
}

extern "C" void* fn_8012022C(void* param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)param_1 = lbl_80290AB4;
        fn_801CB248(*(void**)((u8*)param_1 + 0x1c));
        fn_801CB28C(*(void**)((u8*)param_1 + 0x20));
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_801204E4(void) {
    lbl_802FF334 = 0;
}

extern "C" void* fn_80120B20(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80290ACC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80120DDC(void);
extern "C" void fn_801225F8(u8* p);
extern "C" void fn_80120DA8(u8* p) {
    fn_80120DDC();
    fn_801225F8(p);
}

extern "C" void fn_80123EA0(void* p)
{
	lbl_802FF364 = p;
}

extern "C" void* fn_80123EA8(void)
{
	return lbl_802FF364;
}

extern "C" void fn_80123EB0(void* p)
{
	lbl_802FF368 = p;
}

extern "C" void* fn_80123EB8(void)
{
	return lbl_802FF368;
}

extern "C" void fn_80123F9C(void* p) {
    fn_80123EC0((void*)&lbl_802FDDB0, p);
}

extern "C" void fn_80124110(void* p) {
    fn_80123EC0((void*)&lbl_802FDDB0, p);
}

extern "C" void fn_801286CC(u8* param_1, u8* param_2) {
    u8* p = *(u8**)(param_1 + 4);
    u8* iVar2 = **(u8***)(p + 0x1c);
    s32 b = *(u8*)(param_2 + 0x95);
    s32 sum = *(s16*)(param_2 + 0x80) + (b & *(u8*)(iVar2 + 0x2f));
    s32 d = *(s16*)(iVar2 + 0x24);
    s32 q = sum / d;
    s32 rem = sum - q * d;
    *(s16*)(param_1 + 0x214) = rem + (q & 1) * (d - rem * 2);
}

extern "C" void fn_80128718(u8* self) {
    *(s16*)(self + 0x214) = 0;
}

extern "C" void fn_80128724(u8* param_1, u8* param_2) {
    u8* iVar1 = **(u8***)(*(u8**)(param_1 + 4) + 0x1c);
    s32 uVar2 = (s32)*(s16*)(iVar1 + 0x24) + 1;
    s32 iVar3 = (s32)(*(f32*)(param_2 + 0x84) * (f32)uVar2) + (*(u8*)(param_2 + 0x95) & *(u8*)(iVar1 + 0x2f));
    *(s16*)(param_1 + 0x214) = iVar3 % uVar2;
}

extern "C" void fn_80128794(u8* self) {
    *(s16*)(self + 0x214) = 0;
}

extern "C" void fn_801287A0(u8* param_1, u8* param_2) {
    u8* p = *(u8**)(param_1 + 4);
    u8* iVar2 = **(u8***)(p + 0x1c);
    u8 b = *(u8*)(param_2 + 0x95);
    s32 d = *(s16*)(iVar2 + 0x24) + 1;
    s32 m = b & *(u8*)(iVar2 + 0x2f);
    *(s16*)(param_1 + 0x214) = m % d;
}

extern "C" void fn_80128EE8(u8* a, u8* b) {
    u8 flags = b[0x95];
    u8** piVar1 = *(u8***)(*(u8**)(a + 4) + 0x1c);
    s16 off = *(s16*)(b + 0x80);
    u8* iVar2 = piVar1[0];
    u8* tbl = piVar1[2];
    int iVar4 = off + (flags & iVar2[0x30]);
    u32 uVar3 = iVar2[0x1f];
    b[0x94] = tbl[(iVar4 - (iVar4 / (int)uVar3) * uVar3) & 0xff];
}

extern "C" void fn_80128F2C(void** param_1) {
    u8* obj = (u8*)*param_1;
    u8* info = *(u8**)((u8*)param_1[1] + 0x1c);
    s32 v = *(s32*)(obj + 0x100);
    s32 m = (*(u8**)info)[0x1f] - 1;
    s32 q = v / m;
    s32 r = v - q * m;
    u8 idx = r + (q & 1) * (m - 2 * r);
    obj[0x111] = (*(u8**)(info + 8))[idx];
}

extern "C" void fn_80128F7C(u8* a, u8* b) {
    u8 flags = b[0x95];
    u8** info = *(u8***)(*(u8**)(a + 4) + 0x1c);
    s16 off = *(s16*)(b + 0x80);
    u8* iVar2 = info[0];
    u8* tbl = info[2];
    s32 v = off + (flags & iVar2[0x30]);
    s32 m = iVar2[0x1f] - 1;
    s32 q = v / m;
    s32 r = v - q * m;
    u8 idx = r + (q & 1) * (m - 2 * r);
    b[0x94] = tbl[idx];
}

extern "C" void fn_80128FD8(void** param_1) {
    u8* obj = (u8*)*param_1;
    u8* info = *(u8**)((u8*)param_1[1] + 0x1c);
    obj[0x111] = (*(u8**)info)[0x20];
}

extern "C" void fn_801DF2A4(void*, s32);
extern "C" void fn_80128FF4(u8* a, u8* b) {
    u8 flags = b[0x95];
    u8** info = *(u8***)(*(u8**)(a + 4) + 0x1c);
    u8* iVar2 = info[0];
    u8* tbl = info[2];
    s32 m = iVar2[0x1f];
    s32 v = (s32)((f32)m * *(f32*)(b + 0x84)) + (flags & iVar2[0x30]);
    b[0x94] = tbl[(v - (v / m) * m) & 0xff];
}

extern "C" void fn_8012906C(void** param_1) {
    u8* obj = (u8*)*param_1;
    u8* info = *(u8**)((u8*)param_1[1] + 0x1c);
    obj[0x111] = (*(u8**)info)[0x20];
}

extern "C" void fn_80129088(u8* a, u8* b) {
    u8** info = *(u8***)(*(u8**)(a + 4) + 0x1c);
    u8* iVar2 = info[0];
    u8* tbl = info[2];
    u8 flags = b[0x95];
    s32 v = flags & iVar2[0x30];
    s32 m = iVar2[0x1f];
    b[0x94] = tbl[(v - (v / m) * m) & 0xff];
}

extern "C" void fn_801290C4(void* p) {
    fn_801DF2A4((u8*)p + 0x184, 0);
}

extern "C" void fn_801290EC(void) {
}

extern "C" void* fn_8012A804(void* p) {
    return *(void**)((char*)p + 4);
}

extern "C" int fn_8012A80C(int* p) { return *p; }

extern "C" void* fn_8012C240(void* ptr, void* param_2) {
    *(void**)ptr = param_2;
    fn_8012C274(ptr);
    return ptr;
}

extern "C" void fn_8012C4A4(void* param_1, u8* param_2) {
    f32 val = lbl_803016E0 * (lbl_803016E4 - *(f32*)(param_2 + 0x84));
    OSf32tou8(&val, param_2 + 0x96);
}

extern "C" void fn_8012C4D0(void* param_1, u8* param_2) {
    *(f32*)(param_2 + 0x60) = *(f32*)(param_2 + 0x68) * (lbl_803016E4 - *(f32*)(param_2 + 0x84));
    *(f32*)(param_2 + 0x64) = *(f32*)(param_2 + 0x6c) * (lbl_803016E4 - *(f32*)(param_2 + 0x84));
}

extern "C" const float lbl_803016E4;
extern "C" const float lbl_803016E0;
extern "C" void fn_8012C274(void*);
extern "C" void fn_8012C500(void** param_1, void* param_2) {
    *param_1 = param_2;
}

extern "C" void fn_8012C604(void** param_1, void* param_2) {
    *param_1 = param_2;
}

extern "C" void fn_8012D010(void*);
extern "C" void* fn_8012CFDC(void* ptr, void* param_2) {
    *(void**)ptr = param_2;
    fn_8012D010(ptr);
    return ptr;
}

extern void* lbl_80290F9C[];
extern "C" void* fn_8012F204(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80290F9C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80290FCC[];
extern "C" void* fn_8012F24C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80290FCC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80290FFC[];
extern "C" void* fn_8012F2A8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80290FFC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029102C[];
extern "C" void* fn_8012F304(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029102C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80291060[];
extern "C" void* fn_8012F360(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80291060;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80291090[];
extern "C" void* fn_8012F3BC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80291090;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802910C0[];
extern "C" void* fn_8012F418(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802910C0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802910F0[];
extern "C" void* fn_8012F474(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802910F0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029111C[];
extern "C" void* fn_8012F4D0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029111C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029114C[];
extern "C" void* fn_8012F52C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029114C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801300FC(u8* p, u32 v, u8 i) {
    (*(u32**)(p + 0x1c))[i] = v;
}

extern "C" void fn_80166C70(unsigned short* param_1, unsigned short param_2);
extern "C" void* fn_80130234(unsigned short* param_1, unsigned short param_2) {
    fn_80166C70(param_1, param_2);
    return param_1;
}

extern "C" void* fn_80130264(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80166B70(void*, s32);
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_80166B58(void*, void*);
extern "C" void fn_801302A0(u32* p) {
    p[0] = 0;
    p[1] = 0;
}

extern "C" void fn_80166C08(void*, int);
extern "C" void* fn_801302B0(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_80130304(u8* p, s16 del) {
    if (p) {
        if (p + 0x58) {
            fn_80166B70(p + 0x58, 0);
        }
        if (del > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" u8* fn_80130364(u8* p) {
    fn_80166B58(p + 0x58, p);
    *(u32*)(p + 0xc4) = 0;
    *(u32*)(p + 0xc8) = 0;
    *(u32*)(p + 0xcc) = 0;
    *(u32*)(p + 0xd0) = 0;
    *(u32*)(p + 0xd4) = 0;
    *(u32*)(p + 0xd8) = 0;
    *(u32*)(p + 0xdc) = 0;
    return p;
}

extern void* lbl_80247020[];
extern "C" void* fn_801303BC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80247020;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802470EC[];
extern "C" void* fn_80130CB8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802470EC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_801327D8(void) {
    return 3;
}

extern "C" BOOL fn_801327E0(void) {
    return TRUE;
}

extern "C" void fn_801327E8(void) {
}

extern "C" float lbl_803017A0;
extern "C" float fn_801327EC(void) {
    return lbl_803017A0;
}

extern "C" void fn_801327F4(void) {
}

extern f32 lbl_802FEAB4;
extern "C" f32 fn_801327F8(void) {
    f32 temp = lbl_802FEAB4;
    return temp;
}

extern "C" void fn_80132804(void) {
}

extern "C" float lbl_803017A0;
extern "C" float fn_80132808(void) {
    return lbl_803017A0;
}

extern "C" void fn_80132810(void) {
}

extern "C" float fn_80132814(void) {
    return lbl_803017A0;
}

extern "C" void fn_8013281C(void) {
}

extern "C" void fn_80132820(void)
{
    return;
}

extern "C" void fn_80132824(void)
{
    return;
}

extern "C" BOOL fn_80132828(void)
{
    return TRUE;
}

extern "C" void fn_80132830(void)
{
    return;
}

extern "C" float fn_8013284C(void) {
    return lbl_803017A0;
}

extern char lbl_802912A4[];
extern "C" void* fn_80132858(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_802912A4;
        fn_801328F8(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" int fn_801328B8(void) {
    return 5;
}

extern "C" BOOL fn_801328C0(void)
{
	return TRUE;
}

extern "C" void fn_801328C8(void) {
}

extern void* lbl_803017A8;
extern "C" void* fn_801328CC(void)
{
	return lbl_803017A8;
}

extern "C" void fn_801328D4(void) {
}

extern "C" void fn_801328D8(void) {
}

extern "C" void fn_801328DC(void)
{
}

extern "C" void fn_801328E0(void)
{
}

extern void* lbl_80291320[];
extern "C" void* fn_801328F8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80291320;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_80132940()
{
	return 0;
}

extern "C" int fn_8013294C()
{
	return 0;
}

extern "C" void fn_80132954(void) {
}

extern "C" int fn_80132958()
{
	return 0;
}

extern "C" void fn_80132960(void) {
}

extern "C" void fn_80132964(void) {
}

extern "C" void fn_80132968(void)
{
}

extern "C" void fn_8013296C(void)
{
}

extern "C" int fn_80132970(void)
{
	return -1;
}

extern "C" int fn_80132978(void* param_1, void* param_2, f32* param_3) {
    f32 val = lbl_803017B0;
    param_3[0] = val;
    param_3[1] = val;
    param_3[2] = val;
    param_3[3] = val;
    param_3[4] = val;
    param_3[5] = val;
    param_3[6] = val;
    param_3[7] = val;
    param_3[8] = val;
    param_3[9] = val;
    param_3[10] = val;
    param_3[11] = val;
    return 0;
}

extern "C" BOOL fn_80132A14(void)
{
    return TRUE;
}

extern "C" BOOL fn_80132A1C(void)
{
    return TRUE;
}

extern "C" int fn_80132A24(void)
{
    return 0;
}

extern "C" void fn_80132A2C(void)
{
}

extern "C" int fn_80132A30()
{
	return 0;
}

extern void* lbl_8020597C[];
extern "C" void* fn_80132C50(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8020597C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292694[];
extern "C" void* fn_80133414(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292694;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292684[];
extern "C" void* fn_80133510(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292684;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292694;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801338F8(u8* p, void* unused, int i);
extern "C" void fn_80133910(u8* p, void* unused, int i, f32* v);
extern "C" void fn_8013393C(u8* p, void* unused, int i, f32* v);
extern "C" void fn_80133968(u8* p, u8* q, int i, void* a, void* b);
extern "C" void fn_801339D8(u8* p, u8* q, int i, void** a);
typedef void (*DispatchFn)(void*, void*, int, void*, void*);
extern "C" void fn_80133584(void* a, void* b, int c, unsigned int type, void* d, void* e) {
    DispatchFn fn;
    switch (type) {
    case 0: fn = (DispatchFn)fn_801338F8; break;
    case 1: fn = (DispatchFn)fn_80133910; break;
    case 2: fn = (DispatchFn)fn_8013393C; break;
    case 3: fn = (DispatchFn)fn_80133968; break;
    case 4: fn = (DispatchFn)fn_801339D8; break;
    case 18:
    default: return;
    }
    fn(a, b, c, d, e);
}

extern "C" void fn_80133624(u8* self, int* idx, f32* vals) {
    int i0 = idx[0];
    int i1 = idx[1];
    int i2 = idx[2];
    u8* e;
    e = *(u8**)(self + 4) + i0 * 0x14;
    *(void**)(e + 8) = (void*)fn_8013345C;
    *(u32*)(e + 4) = 0;
    *(f32*)(e + 0xC) = vals[0];
    e = *(u8**)(self + 4) + i1 * 0x14;
    *(void**)(e + 8) = (void*)fn_8013345C;
    *(u32*)(e + 4) = 0;
    *(f32*)(e + 0xC) = vals[1];
    e = *(u8**)(self + 4) + i2 * 0x14;
    *(void**)(e + 8) = (void*)fn_8013345C;
    *(u32*)(e + 4) = 0;
    *(f32*)(e + 0xC) = vals[2];
}

extern "C" void fn_80133694(int param_1, f32* param_2, int* param_3) {
    int i1 = param_3[1];
    char* base = *(char**)(param_1 + 4);
    int i2 = param_3[2];
    param_2[0] = *(f32*)(base + param_3[0] * 0x14);
    param_2[1] = *(f32*)(base + i1 * 0x14);
    param_2[2] = *(f32*)(base + i2 * 0x14);
}

extern "C" void fn_801338F8(u8* p, void* unused, int i) {
    *(u32*)(*(u8**)(p + 4) + i * 0x14 + 8) = 0;
}

extern "C" void fn_80133910(u8* p, void* unused, int i, f32* v) {
    f32 f = *v;
    u8* e = *(u8**)(p + 4) + i * 0x14;
    *(void**)(e + 8) = (void*)fn_8013345C;
    *(u32*)(e + 4) = 0;
    *(f32*)(e + 0xc) = f;
}

extern "C" void fn_80133470();
extern "C" void fn_8013393C(u8* p, void* unused, int i, f32* v) {
    f32 f = *v;
    u8* e = *(u8**)(p + 4) + i * 0x14;
    *(void**)(e + 8) = (void*)fn_80133470;
    *(u32*)(e + 4) = 0;
    *(f32*)(e + 0xc) = f;
}

extern "C" void fn_80133968(u8* p, u8* q, int i, void* a, void* b) {
    u8* e = *(u8**)(p + 4) + i * 0x14;
    u8* r = (u8*)fn_80139950(*(u8**)(q + 0x14) + 0x60, a, b);
    u32 v;
    if (r == 0) {
        v = 0;
    } else {
        v = *(u32*)(r + 0x14);
    }
    *(void**)(e + 8) = (void*)fn_801334AC;
    *(u32*)(e + 4) = 0;
    *(u32*)(e + 0xc) = v;
}

extern "C" void* fn_801399E4(void*, void*);
extern "C" void fn_801339D8(u8* p, u8* q, int i, void** a) {
    u8* e = *(u8**)(p + 4) + i * 0x14;
    u8* r = (u8*)fn_801399E4(*(u8**)(q + 0x14) + 0x60, *a);
    u32 v;
    if (r == 0) {
        v = 0;
    } else {
        v = *(u32*)(r + 0x14);
    }
    *(void**)(e + 8) = (void*)fn_801334AC;
    *(u32*)(e + 4) = 0;
    *(u32*)(e + 0xc) = v;
}

extern "C" void fn_80133A44(u8* p) {
    Unk80133A44Listener* obj = *(Unk80133A44Listener**)(p + 0x34);
    if (obj != 0) {
        obj->vf4(p);
    }
}

extern "C" void fn_80133A80(u8* p) {
    Unk80133A44Listener* obj = *(Unk80133A44Listener**)(p + 0x34);
    if (obj != 0) {
        obj->vf5(p);
    }
}

extern "C" void fn_80133BB0(int param_1, void* param_2, void* param_3, void* param_4, void* param_5) {
    int* obj = *(int**)(param_1 + 0x34);
    if (obj != 0) {
        int** vftbl = *(int***)obj;
        void (*method)(int, int, void*, void*, void*, void*) = (void (*)(int, int, void*, void*, void*, void*))vftbl[7];
        method(param_1, (int)obj, param_2, param_3, param_4, param_5);
    }
}

extern void* lbl_8029259C[];
extern void* lbl_8029260C[];
extern "C" void* fn_80133C0C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029259C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029260C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u8* fn_80133C68(u8* p, void* a, void* b) {
    fn_8013A57C();
    *(void***)(p + 8) = lbl_802925EC;
    *(void**)(p + 0x34) = b;
    *(void***)(p + 8) = lbl_80292558;
    return p;
}

extern void* lbl_80292500[];
extern void* lbl_8029260C[];
extern "C" void* fn_8013414C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292500;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029260C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802924B4[];
extern "C" u8* fn_801341A8(u8* p, void* a, void* b) {
    fn_8013A57C();
    *(void**)(p + 8) = &lbl_802925EC;
    *(void**)(p + 0x34) = b;
    *(void**)(p + 8) = &lbl_802924B4;
    return p;
}

extern void* lbl_80292438[];
extern "C" void* fn_801343E4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292438;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029260C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802923F0[];
extern "C" u8* fn_80134440(u8* p, void* a, void* b) {
    fn_8013A57C();
    *(void**)(p + 8) = &lbl_802925EC;
    *(void**)(p + 0x34) = b;
    *(void**)(p + 8) = &lbl_802923F0;
    return p;
}

extern void* lbl_80292398[];
extern "C" void* fn_80134898(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292398;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029260C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292354[];
extern "C" u8* fn_801348F4(u8* p, void* a, void* b) {
    fn_8013A57C();
    *(void**)(p + 8) = &lbl_802925EC;
    *(void**)(p + 0x34) = b;
    *(void**)(p + 8) = &lbl_80292354;
    return p;
}

extern void* lbl_802922F4[];
extern "C" void* fn_80134B3C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802922F4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029260C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802922B0[];
extern "C" u8* fn_80134B98(u8* p, void* a, void* b) {
    fn_8013A57C();
    *(void**)(p + 8) = &lbl_802925EC;
    *(void**)(p + 0x34) = b;
    *(void**)(p + 8) = &lbl_802922B0;
    return p;
}

extern void* lbl_80292070[];
struct fn_80135858_Obj {
    virtual void Release(int);
    virtual void fn_0C(int);
    virtual void fn_10(int);
    virtual void fn_14(int);
};
extern void* lbl_802026C0;
extern void* lbl_80291BB4;
extern "C" void fn_8013A5EC(int ptr, int param);
extern "C" void fn_8013A57C(void);
extern "C" void fn_801E10DC(int ptr, uint param);
extern "C" int fn_80135858(int param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)(param_1 + 0x8) = lbl_80292070;
        if (param_1 != 0) {
            *(void**)(param_1 + 0x8) = lbl_802925EC;
            fn_80135858_Obj* obj = *(fn_80135858_Obj**)(param_1 + 0x34);
            if (obj != 0) {
                obj->Release(1);
            }
            fn_8013A5EC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C((void*)param_1);
        }
    }
    return param_1;
}

extern void* lbl_80292148[];
extern "C" int fn_801358EC(int param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)(param_1 + 0x8) = lbl_80292148;
        if (param_1 != 0) {
            *(void**)(param_1 + 0x8) = lbl_802925EC;
            fn_80135858_Obj* obj = *(fn_80135858_Obj**)(param_1 + 0x34);
            if (obj != 0) {
                obj->Release(1);
            }
            fn_8013A5EC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C((void*)param_1);
        }
    }
    return param_1;
}

extern void* lbl_8029220C[];
extern "C" int fn_80135980(int param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)(param_1 + 0x8) = lbl_8029220C;
        if (param_1 != 0) {
            *(void**)(param_1 + 0x8) = lbl_802925EC;
            fn_80135858_Obj* obj = *(fn_80135858_Obj**)(param_1 + 0x34);
            if (obj != 0) {
                obj->Release(1);
            }
            fn_8013A5EC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C((void*)param_1);
        }
    }
    return param_1;
}

extern "C" int fn_80135A14(int param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)(param_1 + 0x8) = lbl_802922B0;
        if (param_1 != 0) {
            *(void**)(param_1 + 0x8) = lbl_802925EC;
            fn_80135858_Obj* obj = *(fn_80135858_Obj**)(param_1 + 0x34);
            if (obj != 0) {
                obj->Release(1);
            }
            fn_8013A5EC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C((void*)param_1);
        }
    }
    return param_1;
}

extern "C" int fn_80135AA8(int param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)(param_1 + 0x8) = lbl_80292354;
        if (param_1 != 0) {
            *(void**)(param_1 + 0x8) = lbl_802925EC;
            fn_80135858_Obj* obj = *(fn_80135858_Obj**)(param_1 + 0x34);
            if (obj != 0) {
                obj->Release(1);
            }
            fn_8013A5EC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C((void*)param_1);
        }
    }
    return param_1;
}

extern "C" int fn_80135B3C(int param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)(param_1 + 0x8) = lbl_802923F0;
        if (param_1 != 0) {
            *(void**)(param_1 + 0x8) = lbl_802925EC;
            fn_80135858_Obj* obj = *(fn_80135858_Obj**)(param_1 + 0x34);
            if (obj != 0) {
                obj->Release(1);
            }
            fn_8013A5EC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C((void*)param_1);
        }
    }
    return param_1;
}

extern "C" int fn_80135BD0(int param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)(param_1 + 0x8) = lbl_802924B4;
        if (param_1 != 0) {
            *(void**)(param_1 + 0x8) = lbl_802925EC;
            fn_80135858_Obj* obj = *(fn_80135858_Obj**)(param_1 + 0x34);
            if (obj != 0) {
                obj->Release(1);
            }
            fn_8013A5EC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C((void*)param_1);
        }
    }
    return param_1;
}

extern "C" int fn_80135C64(int param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)(param_1 + 0x8) = lbl_80292558;
        if (param_1 != 0) {
            *(void**)(param_1 + 0x8) = lbl_802925EC;
            fn_80135858_Obj* obj = *(fn_80135858_Obj**)(param_1 + 0x34);
            if (obj != 0) {
                obj->Release(1);
            }
            fn_8013A5EC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C((void*)param_1);
        }
    }
    return param_1;
}

