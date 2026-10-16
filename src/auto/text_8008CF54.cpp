// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"

extern "C" void fn_8008E364(u32);
extern "C" void fn_8008E4A4(u32);
extern "C" void fn_8008DF30(int, int);
extern "C" void PADControlMotor(int, int);
extern "C" int OSGetResetSwitchState(void);
extern "C" u8 lbl_8053A950;
extern "C" u8 lbl_8053A951;
extern "C" u32 lbl_8053A93C;
extern "C" u32 lbl_8053A940;
extern "C" u32 lbl_8053A954;
extern "C" u32 lbl_8053A938;
extern "C" float lbl_8053B8A0;
extern "C" float lbl_80539DA4;
extern "C" float lbl_80539DA0;
extern "C" u8 lbl_8053A934[];
extern "C" u32 lbl_80499470[];
extern "C" u8 lbl_8053A920;
extern "C" u8 lbl_8053A924[4];
extern "C" u32 lbl_8053A948;
extern "C" u32 lbl_8053A94C;
extern "C" u8 lbl_8052E8A0[];
extern "C" u32 lbl_8052EA28[];
extern "C" u32 lbl_8052EA58[];
extern "C" void initiate__10JSUPtrListFv(void *);
extern "C" void fn_8008E488(void *, u32, u32, u32);
extern "C" void PADSetSpec(u32);
extern "C" void PADSetAnalogMode(u32);
extern "C" int PADInit(void);
extern "C" u32 lbl_8053A92C;
extern "C" u32 lbl_80499490[];
extern "C" void remove__10JSUPtrListFP10JSUPtrLink(void *, void *);
extern "C" void __dt__10JSUPtrLinkFv(void *, s16);
extern "C" void __dt__11JKRDisposerFv(void *, s16);
extern "C" void __ct__11JKRDisposerFv(void *);
extern "C" void __ct__10JSUPtrLinkFPv(void *, void *);
extern "C" void append__10JSUPtrListFP10JSUPtrLink(void *, void *);
extern "C" void fn_8008D910(void *);
extern "C" void fn_8008D538(void *);
void operator delete(void *p);

struct JUTGamePad {
    static void init();
};

extern "C" void* dtor_8008D028(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_80499490;
        s16 idx = *(s16*)(p + 0x7c);
        if (idx >= 0) {
            lbl_8053A924[idx]--;
            *(s16*)(p + 0x7c) = -1;
        }
        remove__10JSUPtrListFP10JSUPtrLink(lbl_8052E8A0, p + 0x80);
        if (p + 0x80 != 0) {
            __dt__10JSUPtrLinkFv(p + 0x80, 0);
        }
        __dt__11JKRDisposerFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_8008D0D4(void)
{
    if (lbl_8053A920 == 0) {
        initiate__10JSUPtrListFv((void *)lbl_8052E8A0);
        lbl_8053A920 = 1;
    }
}

void JUTGamePad::init() {
    PADSetSpec(5);
    lbl_8053A92C = 3;
    PADSetAnalogMode(3);
    PADInit();
}

extern "C" void fn_8008D148(int param_1)
{
  *(u8 *)(param_1 + 0x98) = 0;
  *(u8 *)(param_1 + 0xa8) = 1;
}

extern "C" void fn_8008D424(int param_1)
{
    extern void fn_8008DE64(int, int);
    
    for (int i = 0; i < 4; i++) {
        if (((s8*)lbl_8052EA28)[i * 12 + 10] != 0) continue;
        if (lbl_8053A924[i] != 0) continue;
        
        *(s16*)(param_1 + 0x7c) = (s16)i;
        lbl_8053A924[i] = 1;
        fn_8008E488((u8*)lbl_8052EA58 + i * 0x30,
                    *(u32*)(param_1 + 0x3c),
                    *(u32*)(param_1 + 0x40),
                    *(u32*)(param_1 + 0x44));
        fn_8008DE64(param_1 + 0x68, param_1);
        return;
    }
}

extern "C" void fn_8008D4CC(int param_1, int param_2, int param_3, int param_4)
{
    int val1 = (int)lbl_8053A948;
    int val2 = (int)lbl_8053A94C;
    
    // Check if param_3 >= val1 AND param_4 >= val2
    if ((param_3 - val1) >= 0 && (param_4 - val2) >= 0) {
        lbl_8053A951 = 1;
        u32 func_ptr = lbl_8053A93C;
        s16 val = *(s16*)(param_1 + 0x7c);
        lbl_8053A954 = (u32)val;
        
        if (func_ptr != 0) {
            u32 arg = lbl_8053A940;
            ((void (*)(int, u32))(func_ptr))(val, arg);
        }
    }
}

extern "C" void fn_8008D864(void)
{
    u8 val = lbl_8053A951;
    
    if (val != 0) {
        if (lbl_8053A950 == 1) {
            lbl_8053A951 = 1;
            lbl_8053A954 = 0xffffffff;
            
            u32 fn_ptr = lbl_8053A93C;
            if (fn_ptr != 0) {
                void (*fn)(u32) = (void (*)(u32))fn_ptr;
                u32 param = lbl_8053A940;
                fn(param);
            }
            lbl_8053A950 = 0;
        }
    } else {
        int result = OSGetResetSwitchState();
        if (result != 0) {
            lbl_8053A950 = 1;
        }
    }
}

extern "C" void fn_8008D8E4(void)
{
    fn_8008E364(0);
    fn_8008E4A4(0xf0000000);
}

extern "C" void fn_8008D910(void *param_1)
{
    *(u32 *)((u32)param_1 + 0x0) = 0;
    *(u32 *)((u32)param_1 + 0x4) = 0;
    *(u32 *)((u32)param_1 + 0x8) = 0;
    *(u32 *)((u32)param_1 + 0x18) = 0;
    *(u8 *)((u32)param_1 + 0xc) = 0;
    *(u8 *)((u32)param_1 + 0xd) = 0;
    *(u8 *)((u32)param_1 + 0xe) = 0;
    *(u8 *)((u32)param_1 + 0xf) = 0;
    *(u32 *)((u32)param_1 + 0x1c) = 0;
    *(u32 *)((u32)param_1 + 0x20) = 0;
    *(u32 *)((u32)param_1 + 0x24) = 0;
    *(u32 *)((u32)param_1 + 0x28) = 0;
    *(u32 *)((u32)param_1 + 0x2c) = 0;
}

extern "C" void fn_8008DADC(u32 *param_1) {
    float f = lbl_8053B8A0;
    *(float *)param_1 = f;
    *(float *)((char *)param_1 + 4) = f;
    *(float *)((char *)param_1 + 8) = f;
    *(u16 *)((char *)param_1 + 0xc) = 0;
}

extern "C" u32 fn_8008DDB0(float *param_1, u32 param_2) {
    u32 result = param_2 & 0xf;
    float f2 = *param_1;
    float f1 = lbl_80539DA4;
    
    if (f2 <= -f1 || f2 >= f1) {
        if (f2 <= -f1) {
            result = (param_2 & 0xd) | 1;
        } else {
            result = (param_2 & 0xe) | 2;
        }
    } else {
        result = param_2 & 0xc;
    }
    
    f2 = param_1[1];
    f1 = lbl_80539DA0;
    
    if (f2 <= -f1 || f2 >= f1) {
        if (f2 <= -f1) {
            result = (result & 0xfffffff7) | 4;
        } else {
            result = (result & 0xfffffffb) | 8;
        }
    } else {
        result = result & 0xfffffff3;
    }
    
    return result;
}

extern "C" void fn_8008DE64(u32 *param_1, int param_2) {
    short idx = *(short *)(param_2 + 0x7c);
    if (idx >= 0 && idx < 4) {
        lbl_8053A934[idx] = 0;
        fn_8008DF30(*(short *)(param_2 + 0x7c), 1);
    }
    param_1[0] = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    lbl_8053A938 = 0xf0000000;
}

extern "C" void fn_8008DED8(u32 param_1) {
    u32 mask = lbl_80499470[param_1];
    if ((lbl_8053A938 & mask) != 0) {
        PADControlMotor(param_1, 1);
        lbl_8053A934[param_1] = 1;
    }
}

extern "C" void fn_8008DF30(int param_1, int param_2)
{
    u32 mask = lbl_80499470[param_1];
    if ((lbl_8053A938 & mask) != 0) {
        u8 b = (u8)param_2;
        s32 neg = -(s32)b;
        s32 ored = neg | b;
        s32 sign = ored >> 31;
        u32 motor = 2 & sign;
        u8 mode = (u8)motor;
        PADControlMotor(param_1, mode);
        lbl_8053A934[param_1] = 0;
    }
}

extern "C" void fn_8008E1FC(u32 *param_1, u8 *param_2, s32 param_3, u32 param_4) {
    u8 b0 = param_2[0];
    u8 b1 = param_2[1];
    u32 ptr_val = (u32)(param_2 + 2);
    u32 byte_val = (b0 << 8) + b1;
    
    param_1[3] = byte_val;
    param_1[2] = ptr_val;
    
    if (param_3 == 1) {
        if (param_1[2] == 0) return;
        if (param_1[3] == 0) return;
        param_1[1] = 0xffffffff;
        param_1[0] = 0;
    } else if (param_3 < 1) {
        if (param_3 < 0) return;
        if (param_1[2] == 0) return;
        if (param_1[3] == 0) return;
        param_1[1] = param_1[3];
        param_1[0] = 0;
    } else {
        if (param_3 >= 3) return;
        if (param_1[2] == 0) return;
        if (param_1[3] == 0) return;
        param_1[1] = param_4;
        param_1[0] = 0;
    }
}

extern "C" void fn_8008E2B8(u32 param_1, s16 param_2) {
    *(u32*)(param_1 + 4) = 0;
    
    u32 mask = lbl_80499470[param_2];
    u32 val = lbl_8053A938;
    u32 result = val & mask;
    u32 test = (-(s32)result) | result;
    
    if ((test >> 31) == 0) {
        return;
    }
    
    PADControlMotor(param_2, 2);
    lbl_8053A934[param_2] = 0;
}

extern "C" int fn_8008E328(int param_1)
{
    int *p = *(int **)((void *)lbl_8052E8A0);
    
    do {
        s16 val = *(s16*)((u8*)(*(int *)p) + 0x7c);
        if (param_1 == val) return (int)p;
        p = (int *)p[3];
    } while (p != NULL);
    
    return 0;
}

extern "C" void fn_8008E530(int param_1, int param_2, u32 param_3)
{
    if (!(param_2 < 0)) {
        u32 val1c = *(u32 *)((u32)param_1 + 0x1c);
        if (!(param_3 < val1c)) {
            *(u8 *)((u32)param_1 + 0x11) = 1;
            *(u8 *)((u32)(param_1 + param_2) + 0x48) = 1;
            u32 func_ptr = *(u32 *)((u32)param_1 + 0x4c);
            if (func_ptr != 0) {
                u32 arg = *(u32 *)((u32)param_1 + 0x50);
                ((void (*)(int, int, u32))(func_ptr))(param_2, param_1, arg);
            }
        }
    }
}

