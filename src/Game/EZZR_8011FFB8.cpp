#include "types.h"
#include "Game/Actor.h"

class GateRegistry;
extern "C" GateRegistry* fn_80131F0C(void);
extern "C" u8* fn_80131E30(GateRegistry*, s32);

class EZZR : public Actor {
public:
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25(s32);
    u8 field_230[0x38];
};

extern "C" void fn_80123394(void*);
extern "C" void fn_8011FFCC(void* p) {
}

extern "C" bool fn_8011FFD0(Actor* p) {
    if (*(s32*)fn_80131F0C() < 2) {
        return false;
    }
    Actor* other = (Actor*)fn_80131E30(fn_80131F0C(), 1);
    if (other == 0) {
        return false;
    }
    return p->field_198 == other->field_198;
}

extern "C" s32 fn_80120040(void* p) {
    return 1;
}

extern "C" void fn_80120048(void* p) {
    fn_80123394(p);
}

extern "C" void fn_80120068(void* p) {
    ((EZZR*)p)->v25(12);
}

extern "C" void fn_80120098(void* p) {
    ((EZZR*)p)->v25(9);
}

extern "C" void fn_801200C8(void* p) {
    ((EZZR*)p)->v25(11);
}

extern "C" void fn_80121DB0(void);
extern "C" void fn_801200F8(void)
{
	fn_80121DB0();
}

class GateRegistry;
extern "C" GateRegistry* fn_80131F0C(void);
extern "C" u8* fn_80131E30(GateRegistry*, s32);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern u8 lbl_8049DF40[];
extern f32 lbl_8053C964;
extern "C" void fn_80120118(EZZR* p) {
    fn_801D2608(p->field_230, lbl_8049DF40, 14);
    fn_801D22DC(p->field_230, 7, 2, 0);
    fn_801D1F14(p->field_230, lbl_8053C964);
}

extern "C" void fn_80120F38(int param_1)
{
    if ((*(unsigned int *)(param_1 + 0x90) & 1) != 0) {
        *(u8 *)(param_1 + 0x3c4) = 1;
    }
    *(unsigned int *)(param_1 + 0x35c) = (*(unsigned int *)(param_1 + 0x90) >> 16) & 0xff;
    *(unsigned int *)(param_1 + 0x3d0) = (*(unsigned int *)(param_1 + 0x90) >> 8) & 0xff;
}

extern "C" s32 fn_80121040(void* p)
{
	s32 val = *(s32*)((u8*)p + 0x33c);
	if (val == 7) {
		return 0;
	}
	if (val < 7) {
		if (val > 6) {
			return 1;
		}
	} else if (val < 0xd) {
		return 1;
	}
	return 0;
}

extern u8 lbl_8049DF78[];
extern "C" void fn_80124740(void*, s32);
extern "C" void* fn_80121104(void* p, s16 flag) {
    if (p != 0) {
        *(u8**)p = lbl_8049DF78;
        fn_80124740(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" s32 fn_8011FFB8(void)
{
	return 0;
}

extern "C" s32 fn_8011FFC0(void)
{
	return 0;
}

extern "C" void fn_8011FFC8(void) {}
