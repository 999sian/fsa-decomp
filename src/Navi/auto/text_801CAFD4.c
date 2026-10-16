// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801cafd4-0x801e0c34 (354 functions). split_file divides it into the game's real files.

#include <types.h>
extern void* lbl_802FFA4C;
extern "C" s32 fn_801D61F8(void* self);
extern "C" s32 fn_801D4C78(void* self);
extern "C" s32 fn_801D4EFC(void* self, s32 a);
extern "C" s32 fn_801D513C(void* self, s32 a);
extern "C" void fn_801D2F34(s32 a);
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
extern "C" BOOL EXIDeselect(s32 chan);
extern "C" BOOL EXIUnlock(s32 chan);
extern "C" BOOL EXIProbe(s32 chan);
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
    int r30 = param_1;
    int r31 = lbl_802FF8F4;
    BOOL enabled = OSDisableInterrupts();
    lbl_802FF8F4 = r30;
    OSRestoreInterrupts(enabled);
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

extern "C" BOOL fn_801CEE7C(void) {
    return ((*(vu32*)0xcc006c00 >> 6) & 1) ^ 1;
}

extern "C" BOOL fn_801CEF64(void) {
    return (*(vu32*)0xcc006c00 >> 1) & 1;
}

extern "C" void fn_801CEF74(u8 param_1) {
    vu32* reg = (vu32*)0xcc006c04;
    *reg = (*reg & 0xffffff00) | param_1;
}

extern "C" u32 fn_801CEF90(void) {
    volatile unsigned int* reg = (volatile unsigned int*)0xCC006C04;
    return *reg & 0xFF;
}

extern "C" void fn_801CEFA0(u32 param_1) {
    *(vu32*)0xcc006c04 = (*(vu32*)0xcc006c04 & 0xffff00ff) | ((param_1 & 0xff) << 8);
}

extern "C" u32 fn_801CEFBC(void) {
    return (*(vu32*)0xcc006c04 >> 8) & 0xff;
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
    vu16* reg = (vu16*)0xcc005000;
    reg[0] = (u16)(a >> 16);
    reg[1] = (u16)a;
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
            if (*(void**)(node + 0x3c) == 0) {
                lbl_802FFA10 = p;
            } else {
                *(void**)(*(u8**)(node + 0x3c) + 0x38) = p;
            }
            break;
        }
        cur = *(u8**)(cur + 0x38);
    }
    if (cur != 0) {
        return;
    }
    *(void**)((u8*)lbl_802FFA0C + 0x38) = p;
    *(void**)(node + 0x38) = 0;
    *(void**)(node + 0x3c) = lbl_802FFA0C;
    lbl_802FFA0C = p;
}

extern "C" void fn_801D1CD4(void* p) {
    u8* node = (u8*)p;
    *(void**)(node + 8) = 0;
    *(s32*)node = 3;
    if (lbl_802FFA10 == p) {
        if (*(void**)(node + 0x38) != 0) {
            lbl_802FFA10 = *(void**)(node + 0x38);
            *(void**)(*(u8**)(node + 0x38) + 0x3c) = 0;
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

extern "C" u32 fn_801D44FC(u8* param_1) {
    return *(u32*)(param_1 + 0x88);
}

extern u8 lbl_802F7D60[];
extern "C" void fn_801D4AC8(void*, s32, void*, void*);
extern "C" void fn_801BC250(void*, s32);
extern "C" void fn_801D2AFC(s32, s32, void*);
extern "C" void fn_801D45D8(void);
extern "C" void fn_801D47B8(s32 chan, u8* buf, u32 val) {
    u8* p;
    p = lbl_802F7D60 + chan * 0x110;
    (*(u16*)(buf + 4))++;
    fn_801D4AC8(buf + 4, 0x1ffc, buf, buf + 2);
    fn_801BC250(buf, 0x2000);
    *(u32*)(p + 0xd8) = val;
    fn_801D2AFC(chan, *(s32*)(p + 0xc) * ((u32)(buf - *(u8**)(p + 0x80)) >> 13), (void*)fn_801D45D8);
}

extern "C" s32 fn_801D4864(int param_1) {
    return *(s32 *)(param_1 + 0x84);
}

extern "C" s32 fn_801D61F8(void* self);
extern "C" s32 fn_801E3C54(const void*, const void*, u32);
extern "C" u8 lbl_802F7F80[];
extern "C" s32 fn_801D4C78(void* self);
extern "C" s32 fn_801D4EFC(void* self, s32 a);
extern "C" s32 fn_801D513C(void* self, s32 a);
extern "C" s32 fn_801D53C0(void* param_1) {
    s32 iVar1 = fn_801D4C78(param_1);
    if (iVar1 >= 0) {
        s32 iVar2 = fn_801D4EFC(param_1, 0);
        s32 iVar3 = fn_801D513C(param_1, 0);
        iVar1 = iVar2 + iVar3;
        if (iVar1 == 1) {
            iVar1 = -6;
        } else if (iVar1 < 1 && iVar1 >= 0) {
            iVar1 = 0;
        } else {
            iVar1 = -6;
        }
    }
    return iVar1;
}

extern "C" s32 fn_801D544C(void* self, void* out, void* cb);
extern "C" void fn_801D1D6C(void);
extern "C" void fn_801D59DC(void* param_1) {
    s32 pad;
    void* local;
    if (fn_801D544C(param_1, &local, fn_801D1D6C) >= 0) {
        if (&local != nullptr) {
            fn_801D2F34((s32)param_1);
        }
    }
}

extern "C" void fn_801D6398(void* param_1) {
    if (fn_801D61F8(param_1) >= 0) {
        fn_801D2F34((s32)param_1);
    }
}

extern "C" u32 fn_801D6D18(char* self, char* param_2) {
    char* pcVar3 = self + 8;
    s32 lVar4 = 0x20;
    char cVar1;
    char cVar2;
    do {
        lVar4 = lVar4 - 1;
        if (lVar4 < 0) {
            if (*param_2 == '\0') {
                return 1;
            }
            return 0;
        }
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        cVar2 = *param_2;
        param_2 = param_2 + 1;
        if (cVar1 != cVar2) {
            return 0;
        }
    } while (cVar2 != '\0');
    return 1;
}

extern "C" u32 fn_801D6D80(u8* param_1, u8* param_2) {
    u32 uVar2;
    u8* puVar1 = *(u8**)(param_1 + 0x10c);
    s32 iVar3;
    if (*param_2 == 0xff) {
        uVar2 = -4;
    } else if (puVar1 == lbl_802F7F80 ||
               ((iVar3 = fn_801E3C54(param_2, puVar1, 4)) == 0 &&
                (iVar3 = fn_801E3C54(param_2 + 4, puVar1 + 4, 2)) == 0)) {
        uVar2 = 0;
    } else {
        uVar2 = -10;
    }
    return uVar2;
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

extern "C" void fn_801D9850(void* base, u32 hi, u32 lo);
extern "C" void fn_801D97E0(s32* fifo, s32 readPtr, s32 writePtr);
extern "C" void GXInitFifoBase(s32* fifo, s32 base, s32 size) {
    fifo[0] = base;
    fifo[1] = base + size - 4;
    fifo[2] = size;
    fifo[7] = 0;
    fn_801D9850(fifo, size - 0x4000, (size >> 1) & ~0x1F);
    fn_801D97E0(fifo, base, base);
}

extern "C" void fn_801D97E0(s32* fifo, s32 readPtr, s32 writePtr) {
    BOOL enabled = OSDisableInterrupts();
    fifo[5] = readPtr;
    fifo[6] = writePtr;
    fifo[7] = writePtr - readPtr;
    if (fifo[7] < 0) {
        fifo[7] += fifo[2];
    }
    OSRestoreInterrupts(enabled);
}

extern "C" void fn_801D9850(void* base, u32 hi, u32 lo) {
    *(u32*)((u8*)base + 0xc) = hi;
    *(u32*)((u8*)base + 0x10) = lo;
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

extern "C" void fn_801DA878(void)
{
	u8* gx = __GXData;
	u8 i;
	s32 off = 0;
	for (i = 0; i < 8; i++) {
		if (gx[0x5ab] & (1 << i)) {
			*(volatile u8*)0xCC008000 = 8;
			*(volatile u8*)0xCC008000 = i | 0x70;
			*(volatile u32*)0xCC008000 = *(u32*)&gx[off + 0x1c];
			*(volatile u8*)0xCC008000 = 8;
			*(volatile u8*)0xCC008000 = i | 0x80;
			*(volatile u32*)0xCC008000 = *(u32*)&gx[off + 0x3c];
			*(volatile u8*)0xCC008000 = 8;
			*(volatile u8*)0xCC008000 = i | 0x90;
			*(volatile u32*)0xCC008000 = *(u32*)&gx[off + 0x5c];
		}
		off += 4;
	}
	__GXData[0x5ab] = 0;
}

void fn_801DA914(u32 fmt, s32 attr, s32* cnt, s32* type, u8* frac);
void fn_801DAB94(u32 fmt, s32* list)
{
    s32 attr;
    for (attr = 9; attr <= 0x14; attr++) {
        list[0] = attr;
        fn_801DA914(fmt, attr, &list[1], &list[2], (u8*)&list[3]);
        list += 4;
    }
    list[0] = 0xff;
}

extern "C" void fn_801DAC08(s32 attr, void* base, u8 stride)
{
    s32 cpAttr;
    s32 idx;
    u32 phy;

    if (attr == 0x19) {
        attr = 10;
    }
    cpAttr = attr - 9;
    phy = (u32)base & 0x3FFFFFFF;
    *(volatile u8*)0xCC008000 = 8;
    *(volatile u8*)0xCC008000 = cpAttr | 0xA0;
    *(volatile u32*)0xCC008000 = phy;
    idx = cpAttr - 12;
    if (idx >= 0 && idx < 4) {
        *(u32*)&__GXData[idx * 4 + 0x88] = phy;
    }
    *(volatile u8*)0xCC008000 = 8;
    *(volatile u8*)0xCC008000 = cpAttr | 0xB0;
    *(volatile u32*)0xCC008000 = stride;
    idx = cpAttr - 12;
    if (idx >= 0 && idx < 4) {
        *(u32*)&__GXData[idx * 4 + 0x98] = stride;
    }
}

extern "C" void fn_801DAC94(void)
{
    *(volatile u8*)0xCC008000 = 0x48;
}

extern "C" void fn_801DAF24(u32 v)
{
    u8* gx = __GXData;
    *(u32*)&gx[0x204] = (*(u32*)&gx[0x204] & ~0xF) | (v & 0xF);
    *(volatile u8*)0xCC008000 = 0x10;
    *(volatile u32*)0xCC008000 = 0x103f;
    *(volatile u32*)0xCC008000 = (u8)v;
    *(u32*)&gx[0x5ac] |= 4;
}

extern "C" void GXSetMisc(s32 token, u32 val)
{
	u8* gx;
	switch (token) {
	case 0:
		break;
	case 1:
		gx = __GXData;
		*(u16*)(gx + 4) = val;
		*(u16*)(gx + 0) = (u16)(*(u16*)(gx + 4) == 0 ? 1 : 0);
		*(u16*)(gx + 2) = 1;
		if (*(u16*)(gx + 4) != 0) {
			*(u32*)(gx + 0x5ac) |= 8;
		}
		break;
	case 2:
		__GXData[0x5a9] = (u8)(val > 0);
		break;
	case 3:
		__GXData[0x5aa] = (u8)(val > 0);
		break;
	}
}

extern "C" void fn_801DB844(void);
extern "C" void PPCSync(void);
extern "C" void fn_801DAFF4(void)
{
	if (*(u32*)(__GXData + 0x5ac) != 0) {
		fn_801DB844();
	}
	*(volatile u32*)0xCC008000 = 0;
	*(volatile u32*)0xCC008000 = 0;
	*(volatile u32*)0xCC008000 = 0;
	*(volatile u32*)0xCC008000 = 0;
	*(volatile u32*)0xCC008000 = 0;
	*(volatile u32*)0xCC008000 = 0;
	*(volatile u32*)0xCC008000 = 0;
	*(volatile u32*)0xCC008000 = 0;
	PPCSync();
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

