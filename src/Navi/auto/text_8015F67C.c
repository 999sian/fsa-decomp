#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8015f67c-0x8015ffac (18 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_8015D29C(void*, int);
extern char lbl_80297BD4[];
extern "C" void fn_801BDDBC(void*, void*, int);
extern "C" void fn_801BDEE4(void*, void*, int);
extern "C" void fn_8015F814(void);
extern "C" void* fn_8015D13C(void*, int, int, void*);
extern "C" void fn_801C0EEC(void*);
extern "C" void* fn_8015A9A8(int, void*, int);
extern "C" void fn_8015FB6C(int, int, int);
extern "C" BOOL fn_8015F80C();
extern "C" void* fn_8015F6EC(void*, void*);
extern u32 lbl_802FF5E0;
extern void* lbl_802FF540;
extern int lbl_80297B40[];
extern int lbl_80297B30[];
extern "C" void* fn_8015FE40(void*);
extern "C" void fn_80166B70(void*, int);
extern "C" void fn_8015D0B8(void*, int);
extern char lbl_80297C10[];
extern void* lbl_802FF5F0;
extern u32 lbl_802FF5E4;
extern u32 lbl_802FF5E8;
extern u32 lbl_802FF5EC;
extern char lbl_80297C10[];
struct VObj_8015FBCC {
    virtual void vf0(void);
    virtual void vf1(void);
    virtual void vf2(void);
    virtual void vf3(void);
    virtual void vf4(void);
    virtual void vf5(void);
    virtual s32 vf6(void);
    virtual s32 vf7(void);
};

extern "C" void fn_8015D050(void*);
extern "C" void fn_80166B58(void*, void*);
extern "C" void* fn_8015F67C(void* param_1)
{
	if (lbl_802FF5E0 == 0) {
		void* iVar1 = fn_8015A9A8(0x7c, lbl_802FF540, 0);
		if (iVar1 != 0) {
			iVar1 = fn_8015F6EC(iVar1, param_1);
		}
		lbl_802FF5E0 = (u32)iVar1;
		fn_8015FB6C(0, 0, 0);
	}
	return (void*)lbl_802FF5E0;
}

extern "C" void* fn_8015F6EC(void* ptr, void* param_2)
{
	void* r31 = ptr;
	fn_8015D13C(ptr, 0x4000, 0x10, param_2);
	*(void**)r31 = &lbl_80297BD4;
	fn_801C0EEC(((void**)r31)[0xb]);
	return r31;
}

extern "C" void* fn_8015F73C(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80297BD4;
        fn_8015D29C(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8015F79C(void)
{
	fn_801BDDBC(lbl_80297B40, lbl_80297B30, 4);
	while (true) {
		void* local_18;
		fn_801BDEE4(lbl_80297B40, &local_18, 1);
		int iVar1 = *(int*)local_18;
		switch (iVar1) {
		case 2:
			fn_8015F814();
			break;
		case 1:
			fn_8015F80C();
			break;
		default:
			break;
		}
	}
}

extern "C" BOOL fn_8015F80C()
{
	return TRUE;
}

extern "C" void fn_8015FB6C(int param_1, int param_2, int param_3)
{
    lbl_802FF5E4 = 0;
    lbl_802FF5E8 = 0x10000 - 0x8000;
    lbl_802FF5EC = 0;
    if ((u32)param_1 != 0) {
        lbl_802FF5E4 = ((u32)param_1 + 0x1f) & ~0x1f;
    }
    if ((u32)param_2 != 0) {
        lbl_802FF5E8 = (u32)param_2 & ~0x1f;
    }
    if ((u32)param_3 != 0) {
        if ((u32)param_1 == 0) {
            lbl_802FF5EC = param_3;
        }
    }
}

extern "C" void fn_8015FBC0(u8* param_1)
{
    param_1[0x28] = 0;
}

extern "C" s32 fn_8015FBCC(VObj_8015FBCC* param_1)
{
    s32 iVar1;
    s32 iVar2;

    iVar1 = param_1->vf6();
    iVar2 = param_1->vf7();
    return iVar1 - iVar2;
}

extern "C" void* fn_8015FC28(u32* param_1)
{
    fn_8015D050(param_1);
    *param_1 = (u32)lbl_80297C10;
    fn_80166B58(param_1 + 6, param_1);
    param_1[10] = 0;
    param_1[11] = 0;
    param_1[13] = 0;
    return param_1;
}

extern "C" void* fn_8015FC80(u8* p, s16 del) {
    if (p != 0) {
        *(void**)p = lbl_80297C10;
        if (lbl_802FF5F0 == p) {
            lbl_802FF5F0 = 0;
        }
        if (p + 0x18) {
            fn_80166B70(p + 0x18, 0);
        }
        fn_8015D0B8(p, 0);
        if (del > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" void fn_8015FD0C(u8* p) {
    s32 n = *(s32*)(p + 0x34);
    if (n != 0) {
        n--;
        *(s32*)(p + 0x34) = n;
        if (n == 0 && p != 0) {
            ((void (*)(void*, s32))(*(void***)p)[2])(p, 1);
        }
    }
}

extern "C" u32 fn_8015FD5C(u32 param_1) {
    u32 local = param_1;
    void* obj = fn_8015FE40(&local);
    if (obj == 0) {
        return 0;
    }
    return ((u32 (*)(void*, u32))(*(void***)obj)[5])(obj, local);
}

extern "C" s32 fn_8015FDA8(u32 param_1, void* param_2) {
    s32 ret = 0;
    void** node;
    if (param_2 != 0) {
        return ((s32 (*)(void*, s32, u32))(*(void***)param_2)[6])(param_2, 0, param_1);
    }
    for (node = *(void***)lbl_802FF540; node != 0; node = (void**)node[3]) {
    }
    return ret;
}

