// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801cafd4-0x801e0c34 (354 functions). split_file divides it into the game's real files.

#include <types.h>
#include <Dolphin/mtx.h>
extern "C" void* __OSSetInterruptHandler(s32 interrupt, void (*handler)(void*, void*));
extern "C" void OSInitThreadQueue(void* queue);
extern "C" void __OSUnmaskInterrupts(u32 mask);
extern "C" u8 lbl_802F7D60[];
extern void* lbl_802FFA4C;
extern "C" s32 fn_801D61F8(void* self);
extern "C" s32 fn_801D4C78(void* self);
extern "C" s32 fn_801D4EFC(void* self, s32 a);
extern "C" s32 fn_801D513C(void* self, s32 a);
extern "C" void fn_801D2F34(s32 a);
extern "C" void fn_801DF650(s32 a);
extern void* lbl_802FF9B4;
extern void* lbl_802FF9B0;
extern void* lbl_802FF9C0;
extern void* lbl_802FF9C8;
extern void* lbl_802FF9C4;
extern void* __peReg;
extern u8 lbl_802FFA70;
extern u8 lbl_802FFA74;
extern u8* __GXData;
extern volatile u16* __cpReg;
extern f32 lbl_80301EC0;
typedef struct {
    Mtx23 v;
} GXProjVals;
extern f32 lbl_80301F68;
extern f32 lbl_80301F6C;
extern "C" void fn_801DD410(void* a, void* b, u32 c);
extern "C" void __GXFlushTextureState(void);
extern u8 lbl_8029E5C0[];


extern "C" int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(int state);
extern "C" void fn_801C5050(int);
extern "C" void OSClearContext(void*);
extern "C" void OSSetCurrentContext(void*);
extern "C" void fn_801C4A28(void*);
extern "C" BOOL EXIDeselect(s32 chan);
extern "C" BOOL EXIUnlock(s32 chan);
extern "C" BOOL EXIProbe(s32 chan);
extern "C" BOOL EXISelect(s32 chan, u32 device, u32 frequency);
extern "C" BOOL EXIImm(s32 chan, void* buf, s32 len, u32 type, void* callback);
extern "C" BOOL EXISync(s32 chan);
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
    u32* reg = (u32*)0xcc006c00;
    reg[1] = (reg[1] & 0xffff00ff) | ((param_1 << 8) & 0xff00);
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

extern "C" void fn_801C13D0(int);
extern "C" void fn_801D1D6C(s32 chan) {
    extern u8 lbl_802F7D60[];
    u8* p = lbl_802F7D60 + chan * 0x110;
    fn_801C13D0((int)(p + 0x8c));
}

extern "C" void fn_801D1F90(s32 chan) {
    extern u8 lbl_802F7D60[];
    u8* p = lbl_802F7D60 + chan * 0x110;
    BOOL failed = !EXIDeselect(chan);
    BOOL ok = FALSE;
    void (*cb)(s32, s32);
    EXIUnlock(chan);
    cb = *(void (**)(s32, s32))(p + 0xc8);
    if (cb != nullptr) {
        *(void**)(p + 0xc8) = nullptr;
        if (!failed && EXIProbe(chan)) {
            ok = TRUE;
        }
        if (ok) {
            cb(chan, 0);
        } else {
            cb(chan, -3);
        }
    }
}

extern "C" void fn_801D2038(s32 chan) {
    extern u8 lbl_802F7D60[];
    u32 padding[2];
    u8* p = lbl_802F7D60 + chan * 0x110;
    void* cb = *(void**)(p + 0xdc);
    if (cb != nullptr) {
        *(void**)(p + 0xdc) = nullptr;
        if (EXIProbe(chan)) {
            ((void (*)(s32, s32))cb)(chan, 1);
        } else {
            ((void (*)(s32, s32))cb)(chan, -3);
        }
    }
}

extern "C" u16 fn_801BD4E0(void);
extern "C" void OSRegisterVersion(const char*);
extern "C" void fn_801D1360(void);
extern "C" void OSInitAlarm(void);
extern "C" void OSInitThreadQueue(void*);
extern "C" void OSCreateAlarm(void*);
extern "C" void fn_801D2C90(u32);
extern "C" void OSRegisterResetFunction(void*);
extern const char* lbl_802FEA28;
extern u8 lbl_8029DCB0[];
extern "C" void fn_801D2BDC(void)
{
    extern u8 lbl_802F7D60[];
    extern u16 lbl_802FFA18;
    u8* p = lbl_802F7D60;
    int i;

    if (*(u32*)(p + 0x10c) != 0 && *(u32*)(p + 0x21c) != 0) {
        return;
    }
    lbl_802FFA18 = fn_801BD4E0();
    OSRegisterVersion(lbl_802FEA28);
    fn_801D1360();
    OSInitAlarm();
    for (i = 0; i < 2; i++) {
        *(s32*)(p + 4) = -3;
        OSInitThreadQueue(p + 0x8c);
        OSCreateAlarm(p + 0xe0);
        p += 0x110;
    }
    fn_801D2C90(0x80000000);
    OSRegisterResetFunction(lbl_8029DCB0);
}

extern u16 lbl_802FFA18;
extern "C" u16 fn_801D2C88(void) {
    return lbl_802FFA18;
}

extern "C" void fn_801D2C90(u32 a)
{
    u8* base = lbl_802F7D60;
    void* p = (void*)a;
    *(void**)(base + 0x10c) = p ? p : (void*)(base + 0x220);
    *(void**)(base + 0x21c) = p ? p : (void*)(base + 0x220);
}

extern "C" s32 fn_801D2CC8(s32 chan, u8** pcard)
{
    extern u8 lbl_802F7D60[];
    u8* card = lbl_802F7D60 + chan * 0x110;
    BOOL enabled;
    s32 result;

    if (chan < 0 || chan >= 2 || *(u32*)(card + 0x10c) == 0) {
        return -128;
    }
    enabled = OSDisableInterrupts();
    if (*(s32*)(card + 0) == 0) {
        result = -3;
    } else if (*(s32*)(card + 4) == -1) {
        result = -1;
    } else {
        *(s32*)(card + 4) = -1;
        *(u32*)(card + 0xd0) = 0;
        *pcard = card;
        result = 0;
    }
    OSRestoreInterrupts(enabled);
    return result;
}

extern "C" s32 fn_801D2D80(u8* card, s32 result)
{
    BOOL enabled = OSDisableInterrupts();
    if (*(s32*)(card + 0) != 0) {
        *(s32*)(card + 4) = result;
    } else if (*(s32*)(card + 4) == -1) {
        *(s32*)(card + 4) = result;
    }
    OSRestoreInterrupts(enabled);
    return result;
}

extern "C" s32 fn_801D28AC(s32 chan, void* cb);
extern "C" s32 fn_801D29E0(s32 chan, void* cb);
extern "C" void fn_801D427C(void);
extern "C" void fn_801D43BC(void);
extern "C" s32 fn_801D4358(s32 chan, u32 a, u32 b, u32 c, u32 d)
{
	u8* card = lbl_802F7D60 + chan * 0x110;
	if (*(s32*)card == 0) {
		return -3;
	}
	*(u32*)(card + 0xd4) = d;
	*(u32*)(card + 0xac) = b >> 9;
	*(u32*)(card + 0xb0) = a;
	*(u32*)(card + 0xb4) = c;
	return fn_801D28AC(chan, (void*)fn_801D427C);
}

extern "C" s32 fn_801D4498(s32 chan, u32 a, u32 b, u32 c, u32 d)
{
	u8* card = lbl_802F7D60 + chan * 0x110;
	if (*(s32*)card == 0) {
		return -3;
	}
	*(u32*)(card + 0xd4) = d;
	*(u32*)(card + 0xac) = b >> 7;
	*(u32*)(card + 0xb0) = a;
	*(u32*)(card + 0xb4) = c;
	return fn_801D29E0(chan, (void*)fn_801D43BC);
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
extern "C" void fn_801D1D6C(s32 chan);
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
extern "C" s32 fn_801D2CC8(s32 chan, u8** pcard);
extern "C" s32 fn_801D2D80(u8* card, s32 result);
extern "C" void fn_801D7970(s32* param_1, s32 param_2, s32 param_3, s32 param_4) {
    s32 fn_801D782C(s32* a, s32 b, s32 c, s32 d, void (*e)(s32));
    if (fn_801D782C(param_1, param_2, param_3, param_4, fn_801D1D6C) >= 0) {
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

extern "C" void fn_801DB478(void) {
    int interrupt_state = OSDisableInterrupts();
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = 0x45000002;
    fn_801DAFF4();
    lbl_802FFA70 = 0;
    OSRestoreInterrupts(interrupt_state);
    interrupt_state = OSDisableInterrupts();
    while (lbl_802FFA70 == 0) {
        fn_801C12E4((int)lbl_802FFA74);
    }
    OSRestoreInterrupts(interrupt_state);
}
extern "C" void fn_801DB4F8(void) {
    *(volatile u8*)0xCC008000 = 0x61;
    u8* gx = __GXData;
    *(volatile u32*)0xCC008000 = *(u32*)(gx + 0x1dc);
    *(u16*)(gx + 2) = 0;
}

extern void* __peReg;
extern "C" void fn_801DB51C(s32 a, s32 b) {
    *(u16*)((u8*)__peReg + 6) = (u16)((a << 8) | (b & 0xff));
}

extern "C" void fn_801DB530(s32 a) {
    u16 val = 0;
    val |= a & 3;
    val |= 4;
    *(u16*)((u8*)__peReg + 8) = val;
}

extern "C" void fn_801DB550(s32 a) {
    u8 b = a;
    u16 val = *(u16*)((u8*)__peReg + 2);
    val = (val & ~0x10) | ((b & 1) << 4);
    *(u16*)((u8*)__peReg + 2) = val;
}

extern "C" void fn_801DB568(s32 a, u16 b, u16 c, s16 d) {
    u16 val = *(u16*)((u8*)__peReg + 2);
    u16 ch = 1;
    if (a != 1 && a != 3) {
        ch = 0;
    }
    val = (val & 0x1c) | ch | ((a == 3) << 11) | ((a == 2) << 1) | ((d & 0xf) << 12) | ((b & 7) << 8) | ((c & 7) << 5);
    *(u16*)((u8*)__peReg + 2) = val;
}

extern "C" void fn_801DB5CC(s32 a) {
    u8 b = a;
    u16 val = *(u16*)((u8*)__peReg + 2);
    val = (val & ~0x8) | ((b & 1) << 3);
    *(u16*)((u8*)__peReg + 2) = val;
}

extern "C" void fn_801DB5E4(u8 a, u8 b) {
    u32 val = 0;
    u32 x;
    val = __rlwimi(val, b, 0, 24, 31);
    x = val;
    x = __rlwimi(x, a, 8, 23, 23);
    *(u16*)((u8*)__peReg + 4) = x;
}

extern "C" void fn_801DB608(u8 a) {
    u16* pe = (u16*)__peReg;
    pe[1] = (u16)((pe[1] & ~0x4) | ((u32)(u8)a << 2 & 0x4));
}

extern "C" void fn_801DB620(u8 a, u32 b, u32 c) {
    u32 reg = 0;
    u32 x = a;
    reg = __rlwimi(reg, x, 0, 31, 31);
    reg = __rlwimi(reg, b, 1, 28, 30);
    reg = __rlwimi(reg, c, 4, 27, 27);
    *(u16*)((u8*)__peReg + 0) = reg;
}

extern void* lbl_802FFA68;
extern "C" void fn_801DB684(void* param_1, void* param_2) {
    char context[720];
    u16 token = *(u16*)((u8*)__peReg + 0xe);

    if (lbl_802FFA68 != NULL) {
        OSClearContext(context);
        OSSetCurrentContext(context);
        ((void(*)(u16))lbl_802FFA68)(token);
        OSClearContext(context);
        OSSetCurrentContext(param_2);
    }
    u16 val = *(u16*)((u8*)__peReg + 0xa);
    val = __rlwimi(val, 1, 2, 29, 29);
    *(u16*)((u8*)__peReg + 0xa) = val;
}

extern void* lbl_802FFA6C;
extern "C" void fn_801DB750(void* param_1, void* param_2) {
    u32 padding[2];
    char context[720];
    u32 val;

    val = *(u16*)((u8*)__peReg + 0xa);
    val = __rlwimi(val, 1, 3, 28, 28);
    *(u16*)((u8*)__peReg + 0xa) = val;
    lbl_802FFA70 = 1;
    if (lbl_802FFA6C != 0) {
        OSClearContext(context);
        OSSetCurrentContext(context);
        ((void (*)(void))lbl_802FFA6C)();
        OSClearContext(context);
        OSSetCurrentContext(param_2);
    }
    fn_801C13D0((int)&lbl_802FFA74);
}

extern "C" void __GXPEInit(void) {
    u16* pe;
    u32 val;

    __OSSetInterruptHandler(0x12, fn_801DB684);
    __OSSetInterruptHandler(0x13, fn_801DB750);
    OSInitThreadQueue(&lbl_802FFA74);
    __OSUnmaskInterrupts(0x2000);
    __OSUnmaskInterrupts(0x1000);
    pe = (u16*)__peReg;
    val = pe[5];
    val = __rlwimi(val, 1, 2, 29, 29);
    val = __rlwimi(val, 1, 3, 28, 28);
    val = __rlwimi(val, 1, 0, 31, 31);
    val = __rlwimi(val, 1, 1, 30, 30);
    pe[5] = val;
}

extern "C" void fn_801DD968(void);
extern "C" void fn_801DE2B8(void);
extern "C" void fn_801DBB5C(void);
extern "C" void fn_801DA184(void);
extern "C" void fn_801DA240(void);
#pragma dont_inline on
extern "C" void fn_801DB844(void) {
    u32 flags = *(u32*)(__GXData + 0x5ac);
    if (flags & 1) {
        fn_801DD968();
    }
    if (flags & 2) {
        fn_801DE2B8();
    }
    if (flags & 4) {
        fn_801DBB5C();
    }
    if (flags & 8) {
        fn_801DA184();
    }
    if (flags & 0x10) {
        fn_801DA878();
    }
    if (flags & 0x18) {
        fn_801DA240();
    }
    *(u32*)(__GXData + 0x5ac) = 0;
}

extern "C" void fn_801DBB80(u16 left, u16 top, u16 width, u16 height)
{
	u8* gx = __GXData;
	u32 wd = width - 1;
	u32 ht = height - 1;
	*(u32*)(gx + 0x1e0) = 0;
	*(u32*)(gx + 0x1e0) = __rlwimi(*(u32*)(gx + 0x1e0), left, 0, 22, 31);
	*(u32*)(gx + 0x1e0) = __rlwimi(*(u32*)(gx + 0x1e0), top, 10, 12, 21);
	*(u32*)(gx + 0x1e0) = __rlwimi(*(u32*)(gx + 0x1e0), 0x49, 24, 0, 7);
	*(u32*)(gx + 0x1e4) = 0;
	*(u32*)(gx + 0x1e4) = __rlwimi(*(u32*)(gx + 0x1e4), wd, 0, 22, 31);
	*(u32*)(gx + 0x1e4) = __rlwimi(*(u32*)(gx + 0x1e4), ht, 10, 12, 21);
	*(u32*)(gx + 0x1e4) = __rlwimi(*(u32*)(gx + 0x1e4), 0x4a, 24, 0, 7);
}

extern "C" void fn_801DBBFC(u16 left, u16 top, u16 width, u16 height)
{
	u8* gx = __GXData;
	*(u32*)(gx + 0x1f0) = 0;
	*(u32*)(gx + 0x1f0) = __rlwimi(*(u32*)(gx + 0x1f0), left, 0, 22, 31);
	*(u32*)(gx + 0x1f0) = __rlwimi(*(u32*)(gx + 0x1f0), top, 10, 12, 21);
	*(u32*)(gx + 0x1f0) = __rlwimi(*(u32*)(gx + 0x1f0), 0x49, 24, 0, 7);
	*(u32*)(gx + 0x1f4) = 0;
	*(u32*)(gx + 0x1f4) = __rlwimi(*(u32*)(gx + 0x1f4), width - 1, 0, 22, 31);
	*(u32*)(gx + 0x1f4) = __rlwimi(*(u32*)(gx + 0x1f4), height - 1, 10, 12, 21);
	*(u32*)(gx + 0x1f4) = __rlwimi(*(u32*)(gx + 0x1f4), 0x4a, 24, 0, 7);
}

extern "C" void fn_801DBC78(u32 param_1)
{
	u8* gx = __GXData;
	*(u32*)(gx + 0x1e8) = 0;
	*(u32*)(gx + 0x1e8) = __rlwimi(*(u32*)(gx + 0x1e8), (s32)((param_1 & 0x7fff) << 1) >> 5, 0, 22, 31);
	*(u32*)(gx + 0x1e8) = __rlwimi(*(u32*)(gx + 0x1e8), 0x4d, 24, 0, 7);
}

extern "C" void fn_801DBDDC(u32 param_1) {
    u8* gx = __GXData;
    u32 z = 0;
    u32 v = *(u32*)(gx + 0x1ec);
    *(u32*)(gx + 0x1ec) = (v & 0xffffcfff) | ((param_1 & 3) << 12);
    v = *(u32*)(gx + 0x1fc);
    *(u32*)(gx + 0x1fc) = (v & 0xffffcfff) | ((z & 3) << 12);
}

extern "C" void fn_801DBE00(u32 param_1) {
    u32 a = (param_1 & 1) == 1;
    u8* gx = __GXData;
    *(u32*)(gx + 0x1ec) = (*(u32*)(gx + 0x1ec) & 0xfffffffe) | a;
    u32 b = (param_1 & 2) == 2;
    *(u32*)(gx + 0x1ec) = (*(u32*)(gx + 0x1ec) & 0xfffffffd) | (b << 1);
    *(u32*)(gx + 0x1fc) = (*(u32*)(gx + 0x1fc) & 0xfffffffe) | a;
    *(u32*)(gx + 0x1fc) = (*(u32*)(gx + 0x1fc) & 0xfffffffd) | (b << 1);
}

extern "C" u16 fn_801DBE58(u16 p, f32 f) {
    u32 n = p;
    u32 v = (u32)(lbl_80301EC0 / f);
    u32 d = v & 0x1ff;
    u32 r = ((n - 1) << 8) / d + 1;
    if (d > 0x80 && d < 0x100) {
        do {
            d >>= 1;
        } while ((d & 1) == 0);
        if (n % d == 0) {
            r += 1;
        }
    }
    if (r > 0x400) {
        r = 0x400;
    }
    return (u16)r;
}

extern "C" void fn_801DC1EC(u8* p, u32 val)
{
	u8* gx;
	u32 r6 = 0;
	u32 r10 = 0;
	u32 r11 = 0;

	r6 = __rlwimi(r6, p[0], 0, 24, 31);
	r6 = __rlwimi(r6, p[3], 8, 16, 23);
	r6 = __rlwimi(r6, 0x4f, 24, 0, 7);
	gx = __GXData;
	*(volatile u8*)0xCC008000 = 0x61;
	*(volatile u32*)0xCC008000 = r6;

	r11 = __rlwimi(r11, p[2], 0, 24, 31);
	r11 = __rlwimi(r11, p[1], 8, 16, 23);
	r11 = __rlwimi(r11, 0x50, 24, 0, 7);
	*(volatile u8*)0xCC008000 = 0x61;
	*(volatile u32*)0xCC008000 = r11;

	r10 = __rlwimi(r10, val, 0, 8, 31);
	r10 = __rlwimi(r10, 0x51, 24, 0, 7);
	*(volatile u8*)0xCC008000 = 0x61;
	*(volatile u32*)0xCC008000 = r10;

	*(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DC46C(u32 param_1)
{
	u8* gx = __GXData;
	*(u32*)(gx + 0x1ec) = __rlwimi(*(u32*)(gx + 0x1ec), param_1, 7, 23, 24);
}

extern "C" void fn_801DC774(void)
{
	u8* gx = __GXData;
	*(volatile u8*)0xCC008000 = 0x61;
	*(volatile u32*)0xCC008000 = 0x550003ff;
	*(volatile u8*)0xCC008000 = 0x61;
	*(volatile u32*)0xCC008000 = 0x560003ff;
	*(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DCA0C(void* self, f32 a, f32 b, f32 c) {
    *(f32*)((u8*)self + 0x28) = a;
    *(f32*)((u8*)self + 0x2c) = b;
    *(f32*)((u8*)self + 0x30) = c;
}

extern "C" void fn_801DCA1C(void* self, f32 a, f32 b, f32 c) {
    *(f32*)((u8*)self + 0x34) = -a;
    *(f32*)((u8*)self + 0x38) = -b;
    *(f32*)((u8*)self + 0x3c) = -c;
}

extern "C" void fn_801DCA38(void* p, u32* v)
{
	*(u32*)((u8*)p + 0xc) = *v;
}

extern "C" void fn_801DCCA0(u8 v)
{
    u8* gx = __GXData;
    *(u32*)&gx[0x204] = (*(u32*)&gx[0x204] & ~0x70) | ((u32)v << 4);
    *(volatile u8*)0xCC008000 = 0x10;
    *(volatile u32*)0xCC008000 = 0x1009;
    *(volatile u32*)0xCC008000 = v;
    *(u32*)&gx[0x5ac] |= 4;
}

extern "C" void fn_801DCCDC(s32 chan, u8 enable, s32 amb_src, s32 mat_src, u32 light_mask, s32 diff_fn, s32 attn_fn)
{
    u32 reg;
    u32 idx;

    reg = 0;
    reg = __rlwimi(reg, enable, 1, 30, 30);
    reg = __rlwimi(reg, mat_src, 0, 31, 31);
    reg = __rlwimi(reg, amb_src, 6, 25, 25);
    if (attn_fn == 0) {
        diff_fn = 0;
    }
    idx = chan & 3;
    reg = __rlwimi(reg, diff_fn, 7, 23, 24);
    reg = __rlwimi(reg, attn_fn != 2 ? 1 : 0, 9, 22, 22);
    reg = __rlwimi(reg, attn_fn != 0 ? 1 : 0, 10, 21, 21);
    reg = (reg & ~0x3C) | ((light_mask & 0xF) << 2);
    reg = (reg & ~0x7800) | (((light_mask >> 4) & 0xF) << 11);
    *(volatile u8*)0xCC008000 = 0x10;
    *(volatile u32*)0xCC008000 = idx + 0x100e;
    *(volatile u32*)0xCC008000 = reg;
    if (chan == 4) {
        *(volatile u8*)0xCC008000 = 0x10;
        *(volatile u32*)0xCC008000 = 0x1010;
        *(volatile u32*)0xCC008000 = reg;
    } else if (chan == 5) {
        *(volatile u8*)0xCC008000 = 0x10;
        *(volatile u32*)0xCC008000 = 0x1011;
        *(volatile u32*)0xCC008000 = reg;
    }
    *(u16*)&__GXData[2] = 1;
}

#pragma dummy
extern "C" void fn_801DCFB8(void* a, void* b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern "C" void fn_801DD204(u8* param_1, void* a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 val) {
    fn_801DCFB8(param_1, a, b, c, d, e, f, g);
    param_1[0x1f] &= ~2;
    *(s32*)(param_1 + 0x18) = val;
}

extern "C" s32 fn_801DD3B0(u32* param_1) {
    return (param_1[2] & 0x3ff) + 1;
}

extern "C" s32 fn_801DD3C0(u32* param_1) {
    return ((param_1[2] >> 10) & 0x3ff) + 1;
}

extern "C" u32 fn_801DD3D0(u8* p)
{
	return *(u32*)(p + 0x14);
}

#pragma dont_inline reset
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

extern "C" void fn_801DD58C(void* a, u32 b)
{
	void* r = (*(void* (**)(void))(__GXData + 0x4c8))();
	fn_801DD410(a, r, b);
}

extern "C" void fn_801DD5E0(u32* p, u32 a, u32 b, u16 c)
{
	p[0] = 0;
	p[0] = __rlwimi(p[0], b, 10, 20, 21);
	p[1] = __rlwimi(p[1], a, 27, 11, 31);
	p[1] = __rlwimi(p[1], 0x64, 24, 0, 7);
	*(u16*)(p + 2) = c;
}

extern "C" void fn_801DD410(void* a, void* b, u32 c);
extern "C" void __GXFlushTextureState(void);
extern "C" void fn_801DD618(u32* p, u32 id)
{
	u32* r = (*(u32* (**)(u32))(__GXData + 0x4cc))(id);
	__GXFlushTextureState();
	*(volatile u8*)0xCC008000 = 0x61;
	*(volatile u32*)0xCC008000 = p[1];
	*(volatile u8*)0xCC008000 = 0x61;
	*(volatile u32*)0xCC008000 = r[0];
	__GXFlushTextureState();
	p[0] = __rlwimi(p[0], r[0], 0, 22, 31);
	r[1] = p[0];
	r[2] = p[1];
	r[3] = p[2];
}

extern "C" void GXInitTlutRegion(u32* p, u32 a, u32 b) {
    *p = 0;
    *p = __rlwimi(*p, a - 0x80000, 23, 22, 31);
    *p = __rlwimi(*p, b, 10, 11, 21);
    *p = __rlwimi(*p, 0x65, 24, 0, 7);
}

extern "C" void fn_801DD7DC(void) {
    u32 hi = 0x66000000;
    __GXFlushTextureState();
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = hi + 0x1000;
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = hi + 0x1100;
    __GXFlushTextureState();
}

extern "C" u32 fn_801DD824(u32 param_1) {
    u8* p = __GXData;
    u32 old = *(u32*)(p += 0x4c8);
    *(u32*)p = param_1;
    return old;
}

extern "C" u32 fn_801DD838(u32 param_1) {
    u32* p = (u32*)__GXData;
    u32 old = *(p += 0x4cc / 4);
    *p = param_1;
    return old;
}

extern "C" void fn_801DD84C(u32 param_1, u32 param_2, s32 param_3, s32 param_4) {
    u8* gx = __GXData;
    *(u32*)(gx + 0x594) = (*(u32*)(gx + 0x594) & ~(1 << param_1)) | ((param_2 & 0xff) << param_1);
    if ((param_2 & 0xff) == 0) {
        return;
    }
    u8* b = gx + param_1 * 4;
    *(u32*)(b + 0xb8) = ((param_3 - 1) & 0xffff) | (*(u32*)(b + 0xb8) & 0xffff0000);
    *(u32*)(b + 0xd8) = ((param_4 - 1) & 0xffff) | (*(u32*)(b + 0xd8) & 0xffff0000);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = *(u32*)(b + 0xb8);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = *(u32*)(b + 0xd8);
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DD8C8(s32 param_1, s32 param_2) {
    u8* gx = __GXData;
    u8* a = gx + param_1 * 4;
    u8* b = gx + param_2 * 4;
    u32 v = *(u32*)(a + 0x514);
    *(u32*)(b + 0xb8) = (v & 0x3ff) | (*(u32*)(b + 0xb8) & 0xffff0000);
    *(u32*)(b + 0xd8) = ((v >> 10) & 0x3ff) | (*(u32*)(b + 0xd8) & 0xffff0000);
    u32 w = *(u32*)(a + 0x534);
    *(u32*)(b + 0xb8) = (((w & 3) == 1) << 16) | (*(u32*)(b + 0xb8) & 0xfffeffff);
    *(u32*)(b + 0xd8) = ((((w >> 2) & 3) == 1) << 16) | (*(u32*)(b + 0xd8) & 0xfffeffff);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = *(u32*)(b + 0xb8);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = *(u32*)(b + 0xd8);
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DDE38(int param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u8 param_9, u32 param_10) {
    u32 r0 = 0;
    r0 = __rlwimi(r0, param_2, 0, 30, 31);
    u32 r11 = r0;
    r11 = __rlwimi(r11, param_3, 2, 28, 29);
    r11 = __rlwimi(r11, param_4, 4, 25, 27);
    r11 = __rlwimi(r11, param_10, 7, 23, 24);
    r11 = __rlwimi(r11, param_5, 9, 19, 22);
    r11 = __rlwimi(r11, param_6, 13, 16, 18);
    r11 = __rlwimi(r11, param_7, 16, 13, 15);
    r11 = __rlwimi(r11, param_9, 19, 12, 12);
    *(volatile u8*)0xCC008000 = 0x61;
    r11 = __rlwimi(r11, param_8, 20, 11, 11);
    r11 = __rlwimi(r11, param_1 + 0x10, 24, 0, 7);
    *(volatile u32*)0xCC008000 = r11;
    *(u16*)(__GXData + 2) = 0;
}

extern "C" void fn_801DE24C(u8 param_1) {
    u32* gx = (u32*)__GXData;
    gx[0x204 / 4] = __rlwimi(gx[0x204 / 4], param_1, 16, 13, 15);
    gx[0x5ac / 4] |= 6;
}

extern "C" void fn_801DE270(int param_1) {
    fn_801DDE38(param_1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

extern "C" void fn_801DE2B8(void) {
}

extern "C" void __GXSetIndirectMask(u32 param_1) {
    u8* gx = __GXData;
    u32 v = __rlwimi(*(u32*)(gx + 0x124), param_1, 0, 24, 31);
    u16 zero = 0;
    *(u32*)(gx + 0x124) = v;
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = *(u32*)(gx + 0x124);
    *(u16*)(gx + 2) = zero;
}

extern "C" void __GXFlushTextureState(void) {
    *(volatile u8*)0xCC008000 = 0x61;
    u8* gx = __GXData;
    *(volatile u32*)0xCC008000 = *(u32*)(gx + 0x124);
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DE310(int param_1, int param_2) {
    u8* base = lbl_8029E5C0;
    u8* p2;
    u8* p4;
    param_2 <<= 2;
    if (param_1 == 0) {
        p2 = base + param_2;
        p4 = base + param_2 + 0x28;
    } else {
        p2 = base + param_2 + 0x14;
        p4 = base + param_2 + 0x3c;
    }
    u8* gx = __GXData;
    u8* b = gx + param_1 * 4;
    u32 lo = *(u32*)p2;
    u32 hi = *(u32*)(b + 0x130);
    u32 v = __rlwimi(hi & 0xff000000, lo, 0, 8, 31);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = v;
    *(u32*)(b + 0x130) = v;
    u32 w = *(u32*)(b + 0x170) & 0xff00000f;
    w = __rlwimi(w, *(u32*)p4, 0, 8, 27);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = w;
    *(u32*)(b + 0x170) = w;
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DE39C(s32 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5) {
    u8* gx = __GXData;
    u8* b = gx + param_1 * 4;
    u32 v = __rlwimi(*(u32*)(b + 0x130), param_2, 12, 16, 19);
    *(volatile u8*)0xCC008000 = 0x61;
    v = __rlwimi(v, param_3, 8, 20, 23);
    v = __rlwimi(v, param_4, 4, 24, 27);
    v = __rlwimi(v, param_5, 0, 28, 31);
    *(volatile u32*)0xCC008000 = v;
    *(u32*)(b + 0x130) = v;
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DE3E0(s32 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5) {
    u8* gx = __GXData;
    u8* b = gx + param_1 * 4;
    param_2 = __rlwimi(*(u32*)(b + 0x170), param_2, 13, 16, 18);
    *(volatile u8*)0xCC008000 = 0x61;
    param_2 = __rlwimi(param_2, param_3, 10, 19, 21);
    param_2 = __rlwimi(param_2, param_4, 7, 22, 24);
    param_2 = __rlwimi(param_2, param_5, 4, 25, 27);
    *(volatile u32*)0xCC008000 = param_2;
    *(u32*)(b + 0x170) = param_2;
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DE424(s32 param_1, s32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
    u8* gx = __GXData;
    u8* b = gx + param_1 * 4;
    u32 v = __rlwimi(*(u32*)(b + 0x130), param_2, 18, 13, 13);
    u32 w;
    w = v;
    if (param_2 <= 1) {
        w = __rlwimi(w, param_4, 20, 10, 11);
        w = __rlwimi(w, param_3, 16, 14, 15);
    } else {
        w = __rlwimi(w, param_2, 19, 10, 11);
        w = __rlwimi(w, 3, 16, 14, 15);
    }
    *(volatile u8*)0xCC008000 = 0x61;
    w = __rlwimi(w, param_5, 19, 12, 12);
    w = __rlwimi(w, param_6, 22, 8, 9);
    *(volatile u32*)0xCC008000 = w;
    *(u32*)(b + 0x130) = w;
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DE48C(s32 param_1, s32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
    u8* gx = __GXData;
    u32 v = *(u32*)(gx + param_1 * 4 + 0x170);
    v = __rlwimi(v, param_2, 18, 13, 13);
    if (param_2 > 1) {
        v = __rlwimi(v, param_2, 19, 10, 11);
        v = __rlwimi(v, 3, 16, 14, 15);
    } else {
        v = __rlwimi(v, param_4, 20, 10, 11);
        v = __rlwimi(v, param_3, 16, 14, 15);
    }
    v = __rlwimi(v, param_5, 19, 12, 12);
    v = __rlwimi(v, param_6, 22, 8, 9);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = v;
    *(u32*)(gx + param_1 * 4 + 0x170) = v;
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DE4F4(s32 param_1, u8* param_2) {
    u8* gx = __GXData;
    u32 a = __rlwimi(0, param_2[0], 0, 21, 31);
    a = __rlwimi(a, param_2[3], 12, 9, 19);
    a = __rlwimi(a, param_1 * 2 + 0xe0, 24, 0, 7);
    u32 b = __rlwimi(0, param_2[2], 0, 21, 31);
    b = __rlwimi(b, param_2[1], 12, 9, 19);
    b = __rlwimi(b, param_1 * 2 + 0xe1, 24, 0, 7);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = a;
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = b;
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = b;
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = b;
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DE570(s32 param_1, s16* param_2) {
    u8* gx = __GXData;
    u32 a = __rlwimi(0, param_2[0], 0, 21, 31);
    a = __rlwimi(a, param_2[3], 12, 9, 19);
    a = __rlwimi(a, param_1 * 2 + 0xe0, 24, 0, 7);
    u32 b = __rlwimi(0, param_2[2], 0, 21, 31);
    b = __rlwimi(b, param_2[1], 12, 9, 19);
    b = __rlwimi(b, param_1 * 2 + 0xe1, 24, 0, 7);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = a;
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = b;
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = b;
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = b;
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DE5EC(s32 param_1, u8* param_2) {
    u8* gx = __GXData;
    u32 a = __rlwimi(0, param_2[0], 0, 24, 31);
    a = __rlwimi(a, param_2[3], 12, 12, 19);
    a = __rlwimi(a, 8, 20, 8, 11);
    a = __rlwimi(a, param_1 * 2 + 0xe0, 24, 0, 7);
    u32 b = __rlwimi(0, param_2[2], 0, 24, 31);
    b = __rlwimi(b, param_2[1], 12, 12, 19);
    b = __rlwimi(b, 8, 20, 8, 11);
    b = __rlwimi(b, param_1 * 2 + 0xe1, 24, 0, 7);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = a;
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = b;
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DE660(s32 param_1, u32 param_2) {
    u8* gx = __GXData;
    u8* b = gx + (param_1 >> 1) * 4;
    if (param_1 & 1) {
        *(u32*)(b + 0x1b0) = __rlwimi(*(u32*)(b + 0x1b0), param_2, 14, 13, 17);
    } else {
        *(u32*)(b + 0x1b0) = __rlwimi(*(u32*)(b + 0x1b0), param_2, 4, 23, 27);
    }
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = *(u32*)(b + 0x1b0);
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DE6BC(s32 param_1, u32 param_2) {
    u8* gx = __GXData;
    u32* b = (u32*)(gx + ((param_1 >> 1) * 4 + 0x1b0));
    if (param_1 & 1) {
        *b = __rlwimi(*b, param_2, 19, 8, 12);
    } else {
        *b = __rlwimi(*b, param_2, 9, 18, 22);
    }
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = *b;
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DE718(s32 param_1, u32 param_2, u32 param_3) {
    u8* gx = __GXData;
    u32 off = param_1 * 4 + 0x170;
    u32* r = (u32*)(gx + off);
    *r = __rlwimi(*r, param_2, 0, 30, 31);
    *r = __rlwimi(*r, param_3, 2, 28, 29);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = *r;
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DE760(s32 table, u32 red, u32 green, u32 blue, u32 alpha) {
    u8* gx = __GXData;
    u32* Kreg;
    Kreg = &((u32*)(gx + 0x1b0))[table * 2];
    *Kreg = (*Kreg & ~3) | (red & 3);
    *Kreg = (*Kreg & ~0xC) | ((green & 3) << 2);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = *Kreg;
    Kreg = &((u32*)(gx + 0x1b0))[table * 2 + 1];
    *Kreg = (*Kreg & ~3) | (blue & 3);
    *Kreg = (*Kreg & ~0xC) | ((alpha & 3) << 2);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = *Kreg;
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DE7E0(u32 id, u8 ref, u32 thresh, u32 mode, u8 a) {
    u8* gx = __GXData;
    u32 reg = 0xF3000000;
    reg = __rlwimi(reg, ref, 0, 24, 31);
    reg = __rlwimi(reg, a, 8, 16, 23);
    reg = __rlwimi(reg, id, 16, 13, 15);
    reg = __rlwimi(reg, mode, 19, 10, 12);
    *(volatile u8*)0xCC008000 = 0x61;
    reg = __rlwimi(reg, thresh, 22, 8, 9);
    *(volatile u32*)0xCC008000 = reg;
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DE824(u32 op, s32 fmt, u32 bias) {
    u32 reg0 = 0;
    u32 reg1 = 0;
    u32 type;
    reg0 = __rlwimi(reg0, bias, 0, 8, 31);
    reg0 = __rlwimi(reg0, 0xF4, 24, 0, 7);
    switch (fmt) {
    case 0x11: type = 0; break;
    case 0x13: type = 1; break;
    case 0x16: type = 2; break;
    default: type = 2; break;
    }
    *(volatile u8*)0xCC008000 = 0x61;
    reg1 = __rlwimi(reg1, type, 0, 30, 31);
    reg1 = __rlwimi(reg1, op, 2, 28, 29);
    *(volatile u32*)0xCC008000 = reg0;
    reg1 = __rlwimi(reg1, 0xF5, 24, 0, 7);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = reg1;
    *(u16*)(__GXData + 2) = 0;
}

extern "C" void fn_801DEA4C(u8 param_1) {
    u32* gx = (u32*)__GXData;
    gx[0x204 / 4] = __rlwimi(gx[0x204 / 4], param_1 - 1, 10, 18, 21);
    gx[0x5ac / 4] |= 4;
}

extern "C" void fn_801DEDBC(u8 param_1, u8 param_2, u8 param_3, u8 param_4) {
    u8* gx = __GXData;
    u32 r7 = *(u32*)(gx + 0x1d0);
    r7 = __rlwimi(r7, !(3 - param_1), 6, 20, 20);
    r7 = __rlwimi(r7, param_1, 0, 31, 31);
    r7 = __rlwimi(r7, !(2 - param_1), 28, 30, 30);
    r7 = __rlwimi(r7, param_4, 12, 16, 19);
    r7 = __rlwimi(r7, param_2, 8, 21, 23);
    r7 = __rlwimi(r7, param_3, 5, 24, 26);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = r7;
    *(u32*)(gx + 0x1d0) = r7;
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DEE10(u8 param_1) {
    u8* gx = __GXData;
    u32 r6 = *(u32*)(gx + 0x1d0);
    r6 = __rlwimi(r6, param_1, 3, 28, 28);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = r6;
    *(u32*)(gx + 0x1d0) = r6;
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DEE3C(u8 enable) {
    u32* gx = (u32*)__GXData;
    u32 reg = __rlwimi(gx[0x1d0 / 4], enable, 4, 27, 27);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = reg;
    gx[0x1d0 / 4] = reg;
    *(u16*)((u8*)gx + 2) = 0;
}

extern "C" void fn_801DEE68(u8 param_1, u8 param_2, u8 param_3) {
    u8* gx = __GXData;
    u32 r7 = *(u32*)(gx + 0x1d8);
    r7 = __rlwimi(r7, param_1, 0, 31, 31);
    r7 = __rlwimi(r7, param_2, 1, 28, 30);
    r7 = __rlwimi(r7, param_3, 4, 27, 27);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = r7;
    *(u32*)(gx + 0x1d8) = r7;
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DEE9C(u8 param_1) {
    u8* gx = __GXData;
    u32 v = __rlwimi(*(u32*)(gx + 0x1dc), param_1, 6, 25, 25);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = *(u32*)(gx + 0x1dc);
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DEFA4(u32 param_1) {
    u8* gx = __GXData;
    u32 v;
    v = __rlwimi(*(u32*)(gx + 0x1d0), param_1, 2, 29, 29);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = v;
    *(u32*)(gx + 0x1d0) = v;
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DEFD0(u32 param_1, u32 param_2) {
    u8* gx = __GXData;
    u32 v = __rlwimi(*(u32*)(gx + 0x1d4), (u8)param_2, 0, 24, 31);
    *(volatile u8*)0xCC008000 = 0x61;
    v = __rlwimi(v, (u8)param_1, 8, 23, 23);
    *(volatile u32*)0xCC008000 = v;
    *(u32*)(gx + 0x1d4) = v;
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DF00C(u32 param_1, u32 param_2)
{
    u32 r5 = 0;
    r5 |= (param_2 & 1);
    r5 |= (param_1 & 1) << 1;
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = r5 | (0x44 << 24);
    *(u16*)(__GXData + 0x2) = 0;
}

extern "C" void fn_801DF044(u8 param_1, u8 param_2)
{
    u8 cmd = param_1;
    u8* gx = (u8*)__GXData;
    u32 val = *(u32*)(gx + 0x7C);
    val = (val & ~0x400000) | ((param_2 & 1) << 22);
    *(u32*)(gx + 0x7C) = val;
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = *(u32*)(gx + 0x7C);
    __GXFlushTextureState();
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = 0x68000000 | cmd;
    __GXFlushTextureState();
}

extern "C" void fn_801DB844();
extern "C" void fn_801DB994();
extern "C" void fn_801DF0BC(u32 param_1, u32 param_2) {
    u32 buf[2];
    buf[0] = param_1;
    buf[1] = param_2;
    if (((u32*)__GXData)[0x5ac / 4] != 0) {
        fn_801DB844();
    }
    if (((u32*)__GXData)[0] == 0) {
        fn_801DB994();
    }
    *(volatile u8*)0xCC008000 = 0x40;
    *(volatile u32*)0xCC008000 = buf[0];
    *(volatile u32*)0xCC008000 = buf[1];
}

extern f32 lbl_80301F68;
extern f32 lbl_80301F6C;
extern f32 __psq_l(void* p, int off, int w, int gqr);
extern void __psq_st(f32 v, void* p, int off, int w, int gqr);
extern "C" f32 __psq_l(void* p, int off, int w, int gqr);
extern "C" void __psq_st(f32 v, void* p, int off, int w, int gqr);
extern "C" void* memcpy(void* dst, const void* src, unsigned long n);
extern "C" void fn_801DF25C(f32* p) {
    u8* gx = __GXData;
    p[0] = *(s32*)(gx + 0x4d8) != 0 ? lbl_80301F6C : lbl_80301F68;
    *(GXProjVals*)(p + 1) = *(GXProjVals*)(gx + 0x4dc);
}

extern "C" void fn_801DF344(u32 a) {
    u32* gx = (u32*)__GXData;
    u32 r = gx[0x80 / 4];
    r = (r & ~0x3f) | (a & 0x3f);
    gx[0x80 / 4] = r;
    fn_801DF650(0);
}

extern f32 lbl_80301F70;
extern f32 lbl_80301F74;
extern "C" void fn_801DF42C(void) {
    u8* gx = (u8*)__GXData;
    f32 a = *(f32*)(gx + 0x500);
    f32 b = *(f32*)(gx + 0x4fc);
    f32 d = *(f32*)(gx + 0x4f4);
    f32 e = *(f32*)(gx + 0x4f8);
    f32 f = *(f32*)(gx + 0x508);
    f32 g = *(f32*)(gx + 0x510);
    f32 h = *(f32*)(gx + 0x504);
    f32 i = *(f32*)(gx + 0x50c);
    f32 k = lbl_80301F70;
    f32 bk = b * k;
    f32 ak = a * k;
    f32 fg = f * g;
    *(volatile u8*)0xCC008000 = 0x10;
    *(volatile u32*)0xCC008000 = 0x5101a;
    *(volatile f32*)0xCC008000 = bk;
    *(volatile f32*)0xCC008000 = -a * k;
    *(volatile f32*)0xCC008000 = fg - h * g;
    *(volatile f32*)0xCC008000 = lbl_80301F74 + (d + bk);
    *(volatile f32*)0xCC008000 = lbl_80301F74 + (e + ak);
    *(volatile f32*)0xCC008000 = fg + i;
}

extern "C" void fn_801DF42C(void);
#pragma dont_inline on
extern "C" void fn_801DF4BC(f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) {
    u8* gx = (u8*)__GXData;
    *(f32*)(gx + 0x4f4) = a;
    *(f32*)(gx + 0x4f8) = b;
    *(f32*)(gx + 0x4fc) = c;
    *(f32*)(gx + 0x500) = d;
    *(f32*)(gx + 0x504) = e;
    *(f32*)(gx + 0x508) = f;
    fn_801DF42C();
    *(u16*)((u8*)__GXData + 0x2) = 1;
}
#pragma dont_inline reset
extern "C" void fn_801DF504(f32* dst) {
    f32* src = (f32*)(__GXData + 0x4f4);
    dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2];
    dst[3] = src[3]; dst[4] = src[4]; dst[5] = src[5];
}

extern "C" void fn_801DF528(u32 left, u32 top, u32 wd, u32 ht) {
    u8* gx = __GXData;
    u32 tp, lf, bm, rt;
    tp = top + 0x156;
    *(u32*)(gx + 0xf8) = (tp & 0x7ff) | (*(u32*)(gx + 0xf8) & ~0x7ff);
    lf = left + 0x156;
    *(u32*)(gx + 0xf8) = ((lf << 12) & 0x7ff000) | (*(u32*)(gx + 0xf8) & ~0x7ff000);
    bm = tp + ht - 1;
    *(u32*)(gx + 0xfc) = (bm & 0x7ff) | (*(u32*)(gx + 0xfc) & ~0x7ff);
    rt = lf + wd - 1;
    *(u32*)(gx + 0xfc) = ((rt << 12) & 0x7ff000) | (*(u32*)(gx + 0xfc) & ~0x7ff000);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = *(u32*)(gx + 0xf8);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = *(u32*)(gx + 0xfc);
    *(u16*)(gx + 2) = 0;
}

extern "C" void fn_801DF5A0(s32* left, s32* top, s32* wd, s32* ht) {
    u32 tl = *(u32*)(__GXData + 0xf8);
    u32 br = *(u32*)(__GXData + 0xfc);
    u32 lf;
    u32 tp;
    lf = (tl >> 12) & 0x7ff;
    *left = lf - 0x156;
    tp = tl & 0x7ff;
    *top = tp - 0x156;
    *wd = ((br >> 12) & 0x7ff) - lf + 1;
    *ht = (br & 0x7ff) - tp + 1;
}

extern "C" void fn_801DF5E8(s32 x, s32 y) {
    u32 hx = x + 0x156;
    u32 hy = y + 0x156;
    u32 r = __rlwimi(0, hx, 31, 22, 31);
    u32 reg = __rlwimi(r, hy, 9, 12, 21);
    *(volatile u8*)0xCC008000 = 0x61;
    reg = __rlwimi(reg, 0x59, 24, 0, 7);
    *(volatile u32*)0xCC008000 = reg;
    *(u16*)(__GXData + 2) = 0;
}

extern "C" void fn_801DF628(u32 v) {
    *(volatile u8*)0xCC008000 = 0x10;
    *(volatile u32*)0xCC008000 = 0x1005;
    *(volatile u32*)0xCC008000 = v;
    *(u16*)(__GXData + 2) = 1;
}

extern "C" void fn_801DF650(s32 n) {
    if (n < 5) {
        u8* gx = __GXData;
        *(volatile u8*)0xCC008000 = 8;
        *(volatile u8*)0xCC008000 = 0x30;
        u32 v = *(u32*)(gx + 0x80);
        *(volatile u32*)0xCC008000 = v;
        *(volatile u8*)0xCC008000 = 0x10;
        *(volatile u32*)0xCC008000 = 0x1018;
        *(volatile u32*)0xCC008000 = v;
    } else {
        u8* gx = __GXData;
        *(volatile u8*)0xCC008000 = 8;
        *(volatile u8*)0xCC008000 = 0x40;
        u32 v = *(u32*)(gx + 0x84);
        *(volatile u32*)0xCC008000 = v;
        *(volatile u8*)0xCC008000 = 0x10;
        *(volatile u32*)0xCC008000 = 0x1019;
        *(volatile u32*)0xCC008000 = v;
    }
    *(u16*)(__GXData + 2) = 1;
}

extern "C" void fn_801DFF1C(void) {
    __cpReg[2] = 4;
}

extern "C" void fn_801DFFF0(s32* p, s32 a, s32 b) {
    p[0] = a;
    p[2] = a;
    p[3] = a + b;
    p[1] = b;
}

typedef struct {
    f32 v[6];
} GXDrawBlock;
