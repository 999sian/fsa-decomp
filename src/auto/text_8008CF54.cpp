// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"
#include <math.h>

static inline f64 sqrtStep(f64 tmpd, f32 mag) {
    return tmpd * 0.5 * (3.0 - mag * (tmpd * tmpd));
}
static inline f32 dolsqrtfull(f32 mag) {
    if (mag > 0.0f) {
        f64 tmpd = __frsqrte(mag);
        tmpd = sqrtStep(tmpd, mag);
        tmpd = sqrtStep(tmpd, mag);
        tmpd = sqrtStep(tmpd, mag);
        return mag * tmpd;
    } else if (mag < 0.0) {
        return NAN;
    } else if (fpclassify(mag) == 1) {
        return NAN;
    } else {
        return mag;
    }
}

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
extern "C" u8 lbl_8053A934[4];
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
extern "C" u32 lbl_80499480[];
extern "C" void remove__10JSUPtrListFP10JSUPtrLink(void *, void *);
extern "C" void __dt__10JSUPtrLinkFv(void *, s16);
extern "C" void __dt__11JKRDisposerFv(void *, s16);
extern "C" void __ct__11JKRDisposerFv(void *);
extern "C" void __ct__10JSUPtrLinkFPv(void *, void *);
extern "C" void append__10JSUPtrListFP10JSUPtrLink(void *, void *);
extern "C" void fn_8008D910(void *);
extern "C" void fn_8008D538(void *);
extern "C" void fn_8008DADC(u32 *);
extern "C" void fn_8008DE64(u32 *, int);
extern "C" void fn_8008D0D4(void);
extern "C" void fn_8008D148(int);
void operator delete(void *p);

struct JUTGamePad {
    static void init();
};

extern "C" void* fn_8008CF54(u8* this_, s32 param_2) {
    __ct__11JKRDisposerFv(this_);
    *(u32*)this_ = (u32)lbl_80499490;
    fn_8008D910(this_ + 0x18);
    fn_8008DADC((u32*)(this_ + 0x48));
    fn_8008DADC((u32*)(this_ + 0x58));
    fn_8008DE64((u32*)(this_ + 0x68), (int)this_);
    __ct__10JSUPtrLinkFPv(this_ + 0x80, this_);
    this_[0x98] = 0;
    *(s16*)(this_ + 0x7c) = (s16)param_2;
    if (*(s16*)(this_ + 0x7c) >= 0) {
        lbl_8053A924[param_2]++;
        fn_8008D0D4();
    }
    append__10JSUPtrListFP10JSUPtrLink((void*)lbl_8052E8A0, this_ + 0x80);
    fn_8008D538(this_);
    *(u32*)(this_ + 0x90) = 0;
    *(u32*)(this_ + 0x94) = 0;
    fn_8008D148((int)this_);
    return this_;
}

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

extern "C" s32 PADRead(void*);
extern "C" void PADClamp(void*);
extern "C" void PADClampCircle(void*);
extern "C" void PADReset(u32);
extern "C" s32 fn_8008DAF8(f32* self, s8 x, s8 y, s32 r6, s32 isY, u32 mask);
extern "C" void fn_8008D94C(u32* self, u16* padStatus, u32 stickStatus);
extern "C" void fn_8008D424(int);
extern "C" void fn_8008D538(void*);
extern "C" void fn_8008D864(void);
extern "C" u32 lbl_8052EB18[];
extern "C" u32 lbl_8052EB58[];
extern "C" u32 lbl_8053A930;
extern "C" s32 lbl_80539D9C;
extern "C" s32 lbl_80539D98;
extern "C" u32 lbl_8053A928;
extern "C" u32 fn_8008D15C(void)
{
    u8 buf[0x18];
    u32 mask;
    u8* link;
    u32* entry;
    f32* stickY;
    f32* stickX;
    u8* pad;
    u32 reset;
    s32 i;

    lbl_8053A930 = PADRead(lbl_8052EA28);
    switch (lbl_80539D9C) {
    case 1:
        PADClamp(lbl_8052EA28);
        break;
    case 2:
        PADClampCircle(lbl_8052EA28);
        break;
    }

    reset = 0;
    pad = (u8*)lbl_8052EA28;
    entry = lbl_8052EA58;
    stickX = (f32*)lbl_8052EB18;
    stickY = (f32*)lbl_8052EB58;
    for (i = 0; i < 4; i++) {
        mask = 0x80000000 >> i;
        if (pad[10] == 0) {
            u32 packed = fn_8008DAF8(stickX, pad[2], pad[3], lbl_80539D98, 0, entry[0]) << 24;
            packed |= fn_8008DAF8(stickY, pad[4], pad[5], lbl_80539D98, 1, entry[0]) << 16;
            fn_8008D94C(entry, (u16*)pad, packed);
        } else if ((s8)pad[10] == -1) {
            fn_8008DAF8(stickX, 0, 0, lbl_80539D98, 0, 0);
            fn_8008DAF8(stickY, 0, 0, lbl_80539D98, 1, 0);
            fn_8008D94C(entry, 0, 0);
            if ((lbl_8053A928 & mask) == 0) {
                reset |= mask;
            }
        } else {
            entry[1] = 0;
            entry[2] = 0;
            entry[6] = 0;
        }
        entry += 12;
        stickX += 4;
        stickY += 4;
        pad += 0xc;
    }

    for (link = *(u8**)lbl_8052E8A0; link != 0; link = *(u8**)(link + 0xc)) {
        u8* sub = *(u8**)(*(u8**)link + 0x94);
        if (sub != 0 && sub[4] != 0) {
            u32 packed;
            ((void (*)(u8*, u8*))(*(u32**)sub)[3])(sub, buf);
            packed = fn_8008DAF8((f32*)(*(u8**)link + 0x48), buf[2], buf[3], lbl_80539D98, 0, *(u32*)(*(u8**)link + 0x18)) << 24;
            packed |= fn_8008DAF8((f32*)(*(u8**)link + 0x58), buf[4], buf[5], lbl_80539D98, 1, *(u32*)(*(u8**)link + 0x18)) << 16;
            fn_8008D94C((u32*)(*(u8**)link + 0x18), (u16*)buf, packed);
        } else {
            if (*(s16*)(*(u8**)link + 0x7c) == -1) {
                fn_8008D424((int)*(u8**)link);
            }
            fn_8008D538(*(u8**)link);
        }
        sub = *(u8**)(*(u8**)link + 0x90);
        if (sub != 0 && sub[4] != 0) {
            s16 idx = *(s16*)(*(u8**)link + 0x7c);
            if (idx >= 0 && ((s8*)lbl_8052EA28)[idx * 12 + 10] == 0) {
                ((void (*)(u8*))(*(u32**)sub)[4])(sub);
            }
        }
    }

    if (reset != 0) {
        PADReset(reset);
    }
    fn_8008D864();
    return lbl_8053A930;
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

extern "C" void fn_8008D94C(u32* self, u16* padStatus, u32 stickStatus)
{
  u32 buttons = (padStatus ? *padStatus : 0) | stickStatus;
  self[6] = 0;
  if (self[10] != 0) {
    u32 mask = self[9];
    if (mask != 0) {
      u32 rep = buttons & mask;
      self[6] = 0;
      if (rep == 0) {
        self[8] = 0;
        self[7] = 0;
      } else if (self[8] == rep) {
        self[7]++;
        if (self[7] == self[10] || (self[7] > self[10] && (self[7] - self[10]) % self[11] == 0)) {
          self[6] = rep;
        }
      } else {
        self[6] = rep & (self[8] ^ 0xffffffff);
        self[8] = rep;
        self[7] = 0;
      }
    }
  }
  self[1] = buttons & (buttons ^ self[0]);
  self[2] = self[0] & (buttons ^ self[0]);
  self[0] = buttons;
  self[6] |= (self[9] ^ 0xffffffff) & self[1];
  u8* b = (u8*)self;
  if (padStatus) {
    b[0xc] = ((u8*)padStatus)[8];
    b[0xd] = ((u8*)padStatus)[9];
    b[0xe] = ((u8*)padStatus)[6];
    b[0xf] = ((u8*)padStatus)[7];
  } else {
    b[0xc] = 0;
    b[0xd] = 0;
    b[0xe] = 0;
    b[0xf] = 0;
  }
  ((f32*)self)[4] = (s32)b[0xe] / 150.0f;
  ((f32*)self)[5] = (s32)b[0xf] / 150.0f;
}

extern "C" void fn_8008DADC(u32 *param_1) {
    float f = lbl_8053B8A0;
    *(float *)param_1 = f;
    *(float *)((char *)param_1 + 4) = f;
    *(float *)((char *)param_1 + 8) = f;
    *(u16 *)((char *)param_1 + 0xc) = 0;
}

extern "C" u32 fn_8008DDB0(float *param_1, u32 param_2);
extern "C" s32 fn_8008DAF8(f32 *param_1, s8 param_2, s8 param_3, s32 param_4, s32 param_5, u32 param_6) {
    s32 uVar3;

    switch (lbl_80539D9C) {
    case 1:
        uVar3 = param_5 == 0 ? 0x36 : 0x2a;
        break;
    case 2:
        uVar3 = param_5 == 0 ? 0x26 : 0x1d;
        break;
    default:
        uVar3 = param_5 == 0 ? 0x45 : 0x39;
        break;
    }
    *(s8 *)((char *)param_1 + 0xe) = param_2;
    *(s8 *)((char *)param_1 + 0xf) = param_3;
    param_1[0] = (f32)param_2 / (f32)uVar3;
    param_1[1] = (f32)param_3 / (f32)uVar3;
    param_1[2] = dolsqrtfull(param_1[0] * param_1[0] + param_1[1] * param_1[1]);
    if (param_1[2] > 1.0f) {
        if (param_4 == 1) {
            param_1[0] = param_1[0] / param_1[2];
            param_1[1] = param_1[1] / param_1[2];
        }
        param_1[2] = 1.0f;
    }
    if (param_1[2] > 0.0f) {
        if (0.0f == param_1[1]) {
            if (param_1[0] > 0.0f) {
                *(s16 *)(param_1 + 3) = 0x4000;
            } else {
                *(s16 *)(param_1 + 3) = -0x4000;
            }
        } else {
            *(s16 *)(param_1 + 3) = (s16)(10430.378f * (f32)atan2(param_1[0], -param_1[1]));
        }
    }
    return fn_8008DDB0(param_1, param_6 >> (param_5 == 0 ? 0x18 : 0x10));
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

extern "C" void fn_8008DFA0(u32 *param_1, s16 param_2) {
    if ((lbl_8053A938 & lbl_80499470[param_2]) == 0) {
        param_1[0] = 0;
        param_1[1] = 0;
        param_1[2] = 0;
        param_1[3] = 0;
        param_1[4] = 0;
    }
    if (param_1[1] != 0) {
        if (param_1[0] < param_1[1]) {
            u32 period = param_1[3];
            if (period == 0) {
                if (lbl_8053A934[param_2] == 0) {
                    if ((lbl_8053A938 & lbl_80499470[param_2]) != 0) {
                        PADControlMotor(param_2, 1);
                        lbl_8053A934[param_2] = 1;
                    }
                }
            } else {
                u32 rem = param_1[0] % period;
                u32 flagF = lbl_8053A934[param_2] != 0;
                u32 flagB = (u8)(((u8 *)param_1[2])[rem >> 3] & (0x80 >> (rem & 7))) != 0;
                if (flagB == 0) {
                    u32 flagB2 = 0;
                    if (param_1[4] != 0) {
                        flagB2 = (u8)(((u8 *)param_1[4])[rem >> 3] & (0x80 >> (rem & 7))) != 0;
                    }
                    if (flagF == 0) {
                        if (flagB2 != 0 && (lbl_8053A938 & lbl_80499470[param_2]) != 0) {
                            PADControlMotor(param_2, 2);
                            lbl_8053A934[param_2] = 0;
                        }
                    } else if ((lbl_8053A938 & lbl_80499470[param_2]) != 0) {
                        PADControlMotor(param_2, flagB2 ? 2 : 0);
                        lbl_8053A934[param_2] = 0;
                    }
                } else if (flagF == 0 && (lbl_8053A938 & lbl_80499470[param_2]) != 0) {
                    PADControlMotor(param_2, 1);
                    lbl_8053A934[param_2] = 1;
                }
            }
        } else {
            if ((lbl_8053A938 & lbl_80499470[param_2]) != 0) {
                PADControlMotor(param_2, 2);
                lbl_8053A934[param_2] = 0;
            }
            param_1[1] = 0;
        }
    }
    param_1[0]++;
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

extern "C" void fn_8008E364(u32 param_1)
{
    s32 i;
    for (i = 0; i < 4; i++) {
        if ((lbl_8053A938 & lbl_80499480[i]) == 0) {
            if (lbl_8053A934[i] != 0 && (lbl_8053A938 & lbl_80499470[i]) != 0) {
                PADControlMotor(i, 0);
                lbl_8053A934[i] = 0;
            }
            u8* obj = 0;
            u8* link = *(u8**)lbl_8052E8A0;
            for (; link != 0; link = *(u8**)(link + 0xc)) {
                if (i == *(s16*)(*(u8**)link + 0x7c)) {
                    obj = *(u8**)link;
                    break;
                }
            }
            if (obj != 0) {
                s16 idx = *(s16*)(obj + 0x7c);
                *(u32*)(obj + 0x6c) = 0;
                if (lbl_8053A938 & lbl_80499470[idx]) {
                    PADControlMotor(idx, 2);
                    lbl_8053A934[idx] = 0;
                }
            }
        }
    }
    lbl_8053A938 = param_1 & 0xf0000000;
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

