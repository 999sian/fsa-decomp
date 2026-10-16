// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801cafd4-0x801e0c34 (354 functions). split_file divides it into the game's real files.

#include <types.h>
extern void* lbl_802FFA4C;
extern void* lbl_802FF9B4;
extern void* lbl_802FF9B0;
extern void* lbl_802FF9C0;
extern void* lbl_802FF9C8;
extern void* lbl_802FF9C4;
extern u8* __GXData;
extern volatile u16* __cpReg;


extern "C" int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(int state);
extern "C" void fn_801C5050(int);
extern "C" void OSClearContext(void*);
extern "C" void OSSetCurrentContext(void*);
extern "C" void fn_801C4A28(void*);
extern "C" void fn_801C4AF4(void*);
extern "C" int fn_801C42F4(void);
extern "C" void fn_801CDB9C(int);
extern "C" int fn_801CEB00(unsigned int param_1);

extern int lbl_802FF928;
extern int lbl_802FF960;
extern int lbl_802FF948;
extern int lbl_802FE9EC;
extern int lbl_802FF964;
int lbl_802FF8F4;
extern unsigned long lbl_802FF944;
extern unsigned long lbl_802FE9F8;
extern unsigned long lbl_802FE9F4;
extern unsigned long CurrTvMode_802FF92C;
int jumptable_8029D79C[];
extern "C" int fn_801CB248(int param_1) {
    volatile int dummy;
    int r30 = param_1;
    int r31 = lbl_802FF8F4;
    int interrupt_state = OSDisableInterrupts();
    lbl_802FF8F4 = r30;
    OSRestoreInterrupts(interrupt_state);
    return r31;
}

extern int lbl_802FF8E4;
extern int lbl_802FF8EC;
extern int lbl_802F7BC8[];
extern int lbl_802FF938;
extern "C" void fn_801C12E4(int param);
extern "C" void fn_801CBA74(void* a, void* b, void* c, void* d, void* e);
extern "C" void fn_801CBD48(unsigned short a, unsigned short b, unsigned char c, unsigned short d, unsigned short e, unsigned short f, unsigned short g, unsigned short h, int param_1);
extern "C" void fn_801CB2D0(int param_1) {
    if (param_1 > 0x1a) {
        return;
    }
    ((void (*)())jumptable_8029D79C[param_1])();
}

extern "C" void fn_801CBA20(void) {
    int interrupt_state = OSDisableInterrupts();
    int original = lbl_802FF8E4;
    fn_801C12E4(lbl_802FF8EC);
    int new_val = lbl_802FF8E4;
    if (original != new_val) {
        OSRestoreInterrupts(interrupt_state);
    }
}

extern "C" void fn_801CC840(int param_1) {
    char* base = (char*)lbl_802F7BC8;
    int interrupt_state = OSDisableInterrupts();
    *(int*)(base + 0x120) = param_1;
    lbl_802FF938 = 1;
    fn_801CBA74((void*)(base + 0xf0), (void*)(base + 0x124), (void*)(base + 0x128),
               (void*)(base + 0x13c), (void*)(base + 0x140));
    OSRestoreInterrupts(interrupt_state);
}

extern "C" void* lbl_802FF934;
extern "C" void* fn_801CC8AC(void)
{
	return lbl_802FF934;
}

extern "C" void fn_801CC8B4(int param_1) {
    int saved_param = param_1;
    char* base = (char*)lbl_802F7BC8;
    int interrupt_state = OSDisableInterrupts();
    *(int*)(base + 0x130) = saved_param;
    
    void* ptr_144 = *(void**)(base + 0x144);
    unsigned char* data = (unsigned char*)ptr_144;
    
    unsigned short arg1 = *(unsigned short*)(base + 0xfa);
    unsigned short arg2 = *(unsigned short*)(base + 0xf6);
    unsigned char arg3 = data[0x0];
    unsigned short arg4 = *(unsigned short*)(data + 0x2);
    unsigned short arg5 = *(unsigned short*)(data + 0x4);
    unsigned short arg6 = *(unsigned short*)(data + 0x6);
    unsigned short arg7 = *(unsigned short*)(data + 0x8);
    unsigned short arg8 = *(unsigned short*)(data + 0xa);
    
    fn_801CBD48(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, saved_param);
    OSRestoreInterrupts(interrupt_state);
}

extern "C" int fn_801CC930(void)
{
	return lbl_802FF8E4;
}

int fn_801CC938(void) {
    u32 val1, val2, val3;
    int i;
    
    for (i = 0; i < 10; i++) {
        val1 = *(vu16*)0xcc00202c;
        val2 = *(vu16*)0xcc00202e;
        val3 = *(vu16*)0xcc00202c;
        if (val1 == val3) {
            return val1 + (val2 << 16);
        }
    }
    return 0;
}

extern "C" u32 fn_801CC9A0(void) {
    u32 val1_masked, val2_masked, val3_masked;
    u32 result;
    u32 divisor;
    u32 threshold;
    u32 dummy[4];  // force stack frame to 0x20
    
    int interrupt_state = OSDisableInterrupts();
    
    for (int i = 0; i < 10; i++) {
        val1_masked = (*(vu16*)0xcc00202c) & 0x7ff;
        val2_masked = (*(vu16*)0xcc00202e) & 0x7ff;
        val3_masked = (*(vu16*)0xcc00202c) & 0x7ff;
        
        if (val1_masked == val3_masked) {
            divisor = *(u16*)((u32)&lbl_802FF928 + 0x1a);
            result = (val3_masked - 1) * 2 + (val2_masked - 1) / divisor;
            
            OSRestoreInterrupts(interrupt_state);
            
            threshold = *(u16*)((u32)&lbl_802FF928 + 0x18);
            if (result > threshold) {
                result -= threshold;
            }
            
            return result >> 1;
        }
    }
    
    OSRestoreInterrupts(interrupt_state);
    return 0;
}

extern "C" unsigned long SIGetType(long chan);
extern "C" void fn_801C4F24(long, unsigned long);
extern "C" void fn_801C4F38(void);
extern "C" void fn_801CE100(long chan, unsigned long command) {
    int enabled = OSDisableInterrupts();
    unsigned long chanBit = 0x80000000 >> chan;
    if ((lbl_802FF944 & chanBit) && !(SIGetType(chan) & 0x20000000)) {
        if (lbl_802FE9F8 < 2 && command == 2) {
            command = 0;
        }
        if (*(unsigned char*)0x800030E3 & 0x20) {
            command = 0;
        }
        fn_801C4F24(chan, lbl_802FE9F4 | 0x400000 | (command & 3));
        fn_801C4F38();
    }
    OSRestoreInterrupts(enabled);
}

extern unsigned long __PADSpec;
extern void* lbl_802FE9FC;
extern unsigned long lbl_802FE9F8;
extern "C" void fn_801CE218(void);
extern "C" void fn_801CE38C(void);
extern "C" void fn_801CE500(void);
extern "C" void fn_801CE1B8(unsigned long spec) {
    __PADSpec = 0;
    switch (spec) {
    case 0:
        lbl_802FE9FC = (void*)fn_801CE218;
        break;
    case 1:
        lbl_802FE9FC = (void*)fn_801CE38C;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        lbl_802FE9FC = (void*)fn_801CE500;
        break;
    }
    lbl_802FE9F8 = spec;
}

void fn_801CE970(int r31) {
    int interrupt_state = OSDisableInterrupts();
    fn_801C5050(r31);
    OSRestoreInterrupts(interrupt_state);
}

extern "C" int fn_801CE9E4(int param_1) {
    if (*(int*)(&lbl_802FF960) != 0) {
        fn_801CEB00(0);
    }
    
    if (param_1 == 0) {
        return 0;
    }
    
    int interrupt_state = OSDisableInterrupts();
    int result = 0;
    
    if ((*(int*)(&lbl_802FF948) == 0) && (*(int*)(&lbl_802FE9EC) == 0x20)) {
        if (fn_801C42F4() == 0) {
            result = 1;
        }
    }
    
    OSRestoreInterrupts(interrupt_state);
    
    if (*(int*)(&lbl_802FF964) == 0) {
        if (result != 0) {
            fn_801CDB9C(0xf0000000);
            *(int*)(&lbl_802FF964) = 1;
            return 0;
        }
    } else {
        *(int*)(&lbl_802FF964) = 0;
        return 1;
    }
    
    return result;
}

extern "C" void fn_801CEAA0(void* param_1) {
    char context[720];
    
    if (*(void**)(&lbl_802FF960) != NULL) {
        OSClearContext(context);
        OSSetCurrentContext(context);
        ((void(*)(void))*(void**)(&lbl_802FF960))();;
        OSClearContext(context);
        OSSetCurrentContext(param_1);
    }
}

extern "C" int fn_801CEB00(unsigned int param_1) {
    u32 padding[2];
    int old_value = lbl_802FF960;
    lbl_802FF960 = param_1;
    
    if (param_1 != 0) {
        fn_801C4A28((void*)fn_801CEAA0);
    } else {
        fn_801C4AF4((void*)fn_801CEAA0);
    }
    
    return old_value;
}

extern "C" int __PADDisableRecalibration(int param_1) {
    int state = OSDisableInterrupts();
    
    volatile unsigned char* ptr = (volatile unsigned char*)0x800030E3;
    unsigned char val = *ptr;
    
    int result = (val >> 6) & 1;
    
    val = (val & 0xBF);
    *ptr = val;
    
    if (param_1 != 0) {
        val = *ptr;
        val = (val | 0x40);
        *ptr = val;
    }
    
    OSRestoreInterrupts(state);
    return result;
}

extern "C" void fn_801CEC14(u32 start, u32 length) {
    int enabled = OSDisableInterrupts();
    ((volatile u16*)0xCC005000)[24] = (u16)((((volatile u16*)0xCC005000)[24] & ~0x3FF) | (start >> 16));
    ((volatile u16*)0xCC005000)[25] = (u16)((((volatile u16*)0xCC005000)[25] & ~0xFFE0) | (0xFFFF & start));
    ((volatile u16*)0xCC005000)[27] = (u16)((((volatile u16*)0xCC005000)[27] & ~0x7FFF) | (u16)((length >> 5) & 0xFFFF));
    OSRestoreInterrupts(enabled);
}

extern "C" void fn_801CEC9C(void) {
    unsigned long base = 0xCC005000;
    volatile unsigned short* ptr = (volatile unsigned short*)base;
    unsigned short* reg = (unsigned short*)((unsigned long)ptr + 0x36);
    *reg = *reg | 0x8000;
}

extern "C" u32 fn_801CED8C(void) {
    volatile unsigned int* reg = (volatile unsigned int*)0xCC006C00;
    return *reg & 1;
}

extern "C" void* fn_801CF5D0(int param_1) {
    volatile long long dummy;
    int r30 = param_1;
    int state = OSDisableInterrupts();
    void* r31 = lbl_802FF9C0;
    
    lbl_802FF9C0 = (void*)((u32)lbl_802FF9C0 + r30);
    *(int*)lbl_802FF9C8 = r30;
    
    lbl_802FF9C8 = (void*)((u32)lbl_802FF9C8 + 4);
    lbl_802FF9C4 = (void*)((u32)lbl_802FF9C4 - 1);
    
    OSRestoreInterrupts(state);
    
    return r31;
}

extern "C" u32 fn_801CF6FC(void) {
    return 0x4000;
}

extern "C" void* fn_801CF704(void) {
    return lbl_802FF9B4;
}

extern "C" void fn_801D1078(void) {
}

extern const char* lbl_802FEA18;
extern int lbl_802FF9F4;
extern int lbl_802FF9D8;
extern int lbl_802FF9D0;
extern int lbl_802FF9F0;
extern int lbl_802FF9E0;
extern int lbl_802FF9E4;
extern int lbl_802FF9E8;
extern int lbl_802FF9EC;
extern "C" void OSRegisterVersion(const char* id);
extern "C" void fn_801CF49C(void (*fn)(void));
extern "C" void fn_801D107C(void);
extern "C" void fn_801D1148(void) {
    int zero = 0;
    if (lbl_802FF9F4 != 1) {
        OSRegisterVersion(lbl_802FEA18);
        lbl_802FF9D8 = zero;
        lbl_802FF9D0 = zero;
        lbl_802FF9F0 = 0x1000;
        fn_801CF49C(fn_801D107C);
        lbl_802FF9E0 = zero;
        lbl_802FF9E4 = zero;
        lbl_802FF9E8 = zero;
        lbl_802FF9EC = zero;
        lbl_802FF9F4 = 1;
    }
}

extern "C" u16 fn_801D1314(void) {
    return (*(vu16*)0xcc005000 >> 15) & 1;
}

extern "C" u16 fn_801D1324(void) {
    return (*(vu16*)0xcc005004 >> 15) & 1;
}

extern "C" u32 fn_801D1334(void) {
    volatile u16* p = (volatile u16*)(0xCC000000 + 0x5000);
    return (p[2] << 16) | p[3];
}

extern void* lbl_802FFA0C;
extern void* lbl_802FFA14;
extern "C" void fn_801D134C(u32 a) {
    *(vu16*)0xcc005000 = a >> 16;
    *(vu16*)0xcc005002 = a;
}

extern "C" void fn_801D1AA8(void* p);
extern "C" void fn_801D1C34(void* p);
extern void* lbl_802FFA10;
extern "C" void* fn_801D1424(void* param_1) {
    BOOL enabled;
    enabled = OSDisableInterrupts();
    fn_801D1C34(param_1);
    *(u32*)param_1 = 0;
    *(u32*)((u8*)param_1 + 8) = 1;
    OSRestoreInterrupts(enabled);
    if (param_1 == lbl_802FFA10) {
        fn_801D1AA8(param_1);
    }
    return param_1;
}

extern "C" void fn_801D1494(const char* fmt, ...) {
}

extern "C" void fn_801D1C34(void* p) {
    u8* node = (u8*)p;
    if (lbl_802FFA10 == 0) {
        lbl_802FFA14 = p;
        lbl_802FFA0C = p;
        lbl_802FFA10 = p;
        *(void**)(node + 0x3c) = 0;
        *(void**)(node + 0x38) = 0;
        return;
    }
    u8* cur = (u8*)lbl_802FFA10;
    while (cur != 0) {
        if (*(u32*)(node + 4) < *(u32*)(cur + 4)) {
            *(void**)(node + 0x3c) = *(void**)(cur + 0x3c);
            *(void**)(cur + 0x3c) = p;
            *(void**)(node + 0x38) = cur;
            if (*(void**)(node + 0x3c) != 0) {
                *(void**)(*(u8**)(node + 0x3c) + 0x38) = p;
            } else {
                lbl_802FFA10 = p;
            }
            return;
        }
        cur = *(u8**)(cur + 0x38);
    }
    *(void**)((u8*)lbl_802FFA0C + 0x38) = p;
    *(void**)(node + 0x38) = 0;
    *(void**)(node + 0x3c) = lbl_802FFA0C;
    lbl_802FFA0C = p;
}

extern "C" void fn_801D1CD4(void* p) {
    u8* node = (u8*)p;
    *(u32*)(node + 8) = 0;
    *(u32*)node = 3;
    if (lbl_802FFA10 == p) {
        void* next = *(void**)(node + 0x38);
        if (next != 0) {
            lbl_802FFA10 = next;
            *(void**)((u8*)next + 0x3c) = 0;
            return;
        }
        lbl_802FFA14 = 0;
        lbl_802FFA0C = 0;
        lbl_802FFA10 = 0;
        return;
    }
    if (lbl_802FFA0C == p) {
        lbl_802FFA0C = *(void**)(node + 0x3c);
        *(void**)(*(u8**)(node + 0x3c) + 0x38) = 0;
        lbl_802FFA14 = lbl_802FFA10;
        return;
    }
    lbl_802FFA14 = *(void**)(node + 0x38);
    *(void**)(*(u8**)(node + 0x3c) + 0x38) = *(void**)(node + 0x38);
    *(void**)(*(u8**)(node + 0x38) + 0x3c) = *(void**)(node + 0x3c);
}

extern "C" void fn_801D1D68(void) {
}

extern "C" s32 fn_801D782C(void* a);
extern "C" void fn_801D2F34(s32 a);
extern "C" s32 fn_801D72DC(void* a);
extern "C" s32 fn_801D2CC8(s32 a, u32* b);
extern "C" void fn_801D2D80(s32 a, s32 b);
extern "C" void fn_801D7970(s32* param_1) {
    if (fn_801D782C(param_1) >= 0) {
        fn_801D2F34(*param_1);
    }
}

extern "C" void fn_801D9BF8(u8* a, u8* b, u8* c, u8* d, u8* e)
{
	u8* gx = __GXData;
	*(u32*)(gx + 0xc) = *(u16*)__cpReg;
	*a = *(u32*)(gx + 0xc) & 1;
	*b = (*(u32*)(gx + 0xc) >> 1) & 1;
	*c = (*(u32*)(gx + 0xc) >> 2) & 1;
	*d = (*(u32*)(gx + 0xc) >> 3) & 1;
	*e = (*(u32*)(gx + 0xc) >> 4) & 1;
}

extern "C" void __GXFifoInit(void) {
    extern void fn_801D9640(void);
    extern void* fn_801C027C(void);
    extern void __OSSetInterruptHandler(int, void (*)(void));
    extern void __OSUnmaskInterrupts(unsigned int);
    extern void* lbl_802FFA50;
    extern void* lbl_802FFA58;
    extern void* lbl_802FFA48;
    __OSSetInterruptHandler(0x11, fn_801D9640);
    __OSUnmaskInterrupts(0x4000);
    lbl_802FFA50 = fn_801C027C();
    lbl_802FFA58 = 0;
    lbl_802FFA48 = 0;
    lbl_802FFA4C = 0;
}

extern "C" void fn_801D9CD8(void)
{
	u8* gx = __GXData;
	*(u32*)(gx + 0x8) = __rlwimi(*(u32*)(gx + 0x8), 1, 0, 31, 31);
	__cpReg[1] = *(u32*)(gx + 0x8);
}

extern "C" void fn_801D9CFC(void)
{
	u8* gx = __GXData;
	*(u32*)(gx + 0x8) = __rlwimi(*(u32*)(gx + 0x8), 0, 0, 31, 31);
	__cpReg[1] = *(u32*)(gx + 0x8);
}

extern "C" void fn_801D9D20(u8 enable)
{
	u8 v;
	u8* gx;
	if (enable) {
		v = 1;
	} else {
		v = 0;
	}
	gx = __GXData;
	*(u32*)(gx + 0x8) = __rlwimi(*(u32*)(gx + 0x8), v, 4, 27, 27);
	__cpReg[1] = *(u32*)(gx + 0x8);
}

extern "C" void fn_801D9D54(u32 a, u8 b)
{
	u8* gx = __GXData;
	*(u32*)(gx + 0x8) = __rlwimi(*(u32*)(gx + 0x8), a, 2, 29, 29);
	*(u32*)(gx + 0x8) = __rlwimi(*(u32*)(gx + 0x8), b, 3, 28, 28);
	__cpReg[1] = *(u32*)(gx + 0x8);
}

extern void* lbl_802FFA50;
extern void* lbl_802FFA48;
extern "C" void* fn_801C027C(void);
extern u8* __GXData;
extern volatile u16* __cpReg;
extern "C" void fn_801D9D84(u32 a, u8 b)
{
	u8* gx = __GXData;
	*(u32*)(gx + 0x10) = __rlwimi(*(u32*)(gx + 0x10), a, 0, 31, 31);
	*(u32*)(gx + 0x10) = __rlwimi(*(u32*)(gx + 0x10), b, 1, 30, 30);
	__cpReg[2] = *(u32*)(gx + 0x10);
}

extern "C" void* fn_801D9EB4(void)
{
	int enabled = OSDisableInterrupts();
	void* old = lbl_802FFA50;
	lbl_802FFA50 = fn_801C027C();
	OSRestoreInterrupts(enabled);
	return old;
}

extern "C" void* fn_801D9F00(void)
{
	return lbl_802FFA50;
}

extern "C" void* fn_801D9F08(void)
{
	return lbl_802FFA48;
}

extern "C" void* fn_801D9F10(void)
{
	return lbl_802FFA4C;
}

extern "C" void fn_801DA364(void)
{
	register u8* gx = __GXData;
	*(u32*)(gx + 0x14) = __rlwimi(*(u32*)(gx + 0x14), 1, 9, 21, 22);
	*(u32*)(gx + 0x14) = 0;
	*(u32*)(gx + 0x18) = 0;
	*(u8*)(gx + 0x4d4) = 0;
	*(u8*)(gx + 0x4d5) = 0;
	*(u32*)(gx + (unsigned)0x5ac) |= 8;
}

extern "C" uint fn_801DD3D8(uint *param_1)
{
  return *param_1 & 3;
}

extern "C" uint fn_801DD3E4(uint *param_1)
{
  return *param_1 >> 2 & 3;
}

extern "C" uint fn_801DD3F0(int param_1)
{
  u8 val = *(u8*)(param_1 + 0x1f);
  u32 tmp = (val & 1) - 1;
  u32 cnt = __cntlzw(tmp);
  return (cnt >> 5) & 0xFF;
}

extern "C" u32 fn_801DD408(int param_1)
{
    return *(u32*)(param_1 + 0x18);
}

