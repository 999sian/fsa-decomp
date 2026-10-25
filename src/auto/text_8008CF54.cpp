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
extern "C" u32 fn_8008E4A4(u32);
extern "C" void fn_8008DF30(int, int);
extern "C" void PADControlMotor(int, int);
extern "C" BOOL PADRecalibrate(u32);
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
extern "C" void fn_8008DFA0(u32 *param_1, s16 param_2);
extern "C" void fn_8008E530(int param_1, int param_2, u32 param_3);
extern "C" s64 OSGetTime(void);
extern "C" u32 lbl_8052EB98[];
extern "C" u32 lbl_80539DA8;
extern "C" u32 lbl_80539DAC;
void operator delete(void *p);

struct JUTGamePad {
    static void init();
};

extern "C" void* fn_8008CF54(u8* this_, s32 param_2) {
    u8* self = this_;
    s32 id = param_2;
    __ct__11JKRDisposerFv(self);
    *(u32*)self = (u32)lbl_80499490;
    fn_8008D910(self + 0x18);
    fn_8008DADC((u32*)(self + 0x48));
    fn_8008DADC((u32*)(self + 0x58));
    fn_8008DE64((u32*)(self + 0x68), (int)self);
    __ct__10JSUPtrLinkFPv(self + 0x80, self);
    *(u8*)(self + 0x98) = 0;
    *(s16*)(self + 0x7c) = (s16)id;
    if (*(s16*)(self + 0x7c) >= 0) {
        lbl_8053A924[id]++;
        fn_8008D0D4();
    }
    append__10JSUPtrListFP10JSUPtrLink((void*)lbl_8052E8A0, self + 0x80);
    fn_8008D538(self);
    *(u32*)(self + 0x90) = 0;
    *(u32*)(self + 0x94) = 0;
    fn_8008D148((int)self);
    return self;
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
    u32 reset;
    s8* pad;
    u32* entry;
    f32* stickX;
    f32* stickY;
    u32 mask;
    s32 i;
    u8* link;
    s8 buf[0x18];

    lbl_8053A930 = PADRead(lbl_8052EA28);
    switch (lbl_80539D9C) {
    case 1:
        PADClamp(lbl_8052EA28);
        break;
    case 2:
        PADClampCircle(lbl_8052EA28);
        break;
    }

    pad = (s8*)lbl_8052EA28;
    entry = lbl_8052EA58;
    stickX = (f32*)lbl_8052EB18;
    stickY = (f32*)lbl_8052EB58;
    reset = 0;
    for (i = 0; i < 4; i++) {
        mask = 0x80000000 >> i;
        if (pad[10] == 0) {
            u32 packed = fn_8008DAF8(stickX, pad[2], pad[3], lbl_80539D98, 0, entry[0]) << 24;
            packed |= fn_8008DAF8(stickY, pad[4], pad[5], lbl_80539D98, 1, entry[0]) << 16;
            fn_8008D94C(entry, (u16*)pad, packed);
        } else if (pad[10] == -1) {
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
            ((void (*)(u8*, s8*))(*(u32**)sub)[3])(sub, buf);
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

extern "C" void fn_8008D4CC(int param_1, int param_2, s64 param_3)
{
    if (param_3 >= *(s64*)&lbl_8053A948) {
        lbl_8053A951 = 1;
        u32 func_ptr = lbl_8053A93C;
        lbl_8053A954 = *(s16*)(param_1 + 0x7c);
        if (func_ptr != 0) {
            ((void (*)(int, u32))(func_ptr))(*(s16*)(param_1 + 0x7c), lbl_8053A940);
        }
    }
}

extern "C" void fn_8008D538(void* this_) {
    u8* p = (u8*)this_;
    if (*(s16*)(p + 0x7c) != -1) {
        if (*(s16*)(p + 0x7c) >= 0 && *(s16*)(p + 0x7c) < 4) {
            u8* a = (u8*)lbl_8052EA58 + *(s16*)(p + 0x7c) * 0x30;
            u8* b = (u8*)lbl_8052EB18;
            u8* c = (u8*)lbl_8052EB58;
            u8* d = (u8*)lbl_8052EA28;
            *(u32*)(p + 0x18) = *(u32*)(a + 0x0);
            *(u32*)(p + 0x1c) = *(u32*)(a + 0x4);
            *(u32*)(p + 0x20) = *(u32*)(a + 0x8);
            p[0x24] = a[0xc];
            p[0x25] = a[0xd];
            p[0x26] = a[0xe];
            p[0x27] = a[0xf];
            *(f32*)(p + 0x28) = *(f32*)(a + 0x10);
            *(f32*)(p + 0x2c) = *(f32*)(a + 0x14);
            *(u32*)(p + 0x30) = *(u32*)(a + 0x18);
            *(u32*)(p + 0x34) = *(u32*)(a + 0x1c);
            *(u32*)(p + 0x38) = *(u32*)(a + 0x20);
            *(u32*)(p + 0x3c) = *(u32*)(a + 0x24);
            *(u32*)(p + 0x40) = *(u32*)(a + 0x28);
            *(u32*)(p + 0x44) = *(u32*)(a + 0x2c);
            b += *(s16*)(p + 0x7c) * 0x10;
            *(f32*)(p + 0x48) = *(f32*)(b + 0x0);
            *(f32*)(p + 0x4c) = *(f32*)(b + 0x4);
            *(f32*)(p + 0x50) = *(f32*)(b + 0x8);
            *(s16*)(p + 0x54) = *(s16*)(b + 0xc);
            p[0x56] = b[0xe];
            p[0x57] = b[0xf];
            c += *(s16*)(p + 0x7c) * 0x10;
            *(f32*)(p + 0x58) = *(f32*)(c + 0x0);
            *(f32*)(p + 0x5c) = *(f32*)(c + 0x4);
            *(f32*)(p + 0x60) = *(f32*)(c + 0x8);
            *(s16*)(p + 0x64) = *(s16*)(c + 0xc);
            p[0x66] = c[0xe];
            p[0x67] = c[0xf];
            d += *(s16*)(p + 0x7c) * 0xc;
            p[0x7e] = d[0xa];
        }
        if (p[0xa8] == 0 || lbl_80539DA8 != (*(u32*)(p + 0x18) & lbl_80539DAC)) {
            p[0x98] = 0;
        } else if (lbl_8053A951 == 0) {
            if (p[0x98] == 1) {
                s64 elapsed = OSGetTime() - *(s64*)(p + 0xa0);
                if (elapsed >= *(s64*)&lbl_8053A948) {
                    void (*fn)(s32, u32) = (void (*)(s32, u32))lbl_8053A93C;
                    lbl_8053A951 = 1;
                    lbl_8053A954 = *(s16*)(p + 0x7c);
                    if (fn != 0) {
                        fn(*(s16*)(p + 0x7c), lbl_8053A940);
                    }
                }
            } else {
                p[0x98] = 1;
                *(s64*)(p + 0xa0) = OSGetTime();
            }
        }
        for (u32* node = (u32*)lbl_8052EB98[0]; node != 0; node = (u32*)node[3]) {
            u8* obj = (u8*)node[0];
            if (obj[0x10] != 0) {
                s16 sVar2 = *(s16*)(p + 0x7c);
                if (sVar2 >= 0 && sVar2 < 4) {
                    u32 uVar9 = *(u32*)(p + 0x18);
                    if ((uVar9 & *(u32*)(obj + 0x18)) == *(u32*)(obj + 0x14)) {
                        if (obj[sVar2 + 0x20] == 1) {
                            s64 t = OSGetTime();
                            fn_8008E530(node[0], *(s16*)(p + 0x7c), (u32)t - *(u32*)(obj + sVar2 * 8 + 0x2c));
                        } else {
                            obj[sVar2 + 0x20] = 1;
                            obj = (u8*)node[0];
                            *(s64*)(obj + sVar2 * 8 + 0x28) = OSGetTime();
                        }
                    } else {
                        obj[sVar2 + 0x20] = 0;
                    }
                }
            }
        }
        if (*(s16*)(p + 0x7c) >= 0 && *(s16*)(p + 0x7c) < 4) {
            fn_8008DFA0((u32*)(p + 0x68), *(s16*)(p + 0x7c));
        }
    }
}

extern "C" void fn_8008D864(void)
{
    if (lbl_8053A951 != 0) {
        return;
    }
    if (OSGetResetSwitchState() != 0) {
        lbl_8053A950 = 1;
        return;
    }
    if (lbl_8053A950 == 1) {
        lbl_8053A951 = 1;
        lbl_8053A954 = 0xffffffff;
        if (lbl_8053A93C != 0) {
            void (*fn)(s32, u32) = (void (*)(s32, u32))lbl_8053A93C;
            fn(-1, lbl_8053A940);
        }
    }
    lbl_8053A950 = 0;
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

    if (-lbl_80539DA4 < param_1[0] && param_1[0] < lbl_80539DA4) {
        result &= ~3;
    } else if (param_1[0] <= -lbl_80539DA0) {
        result = (result & ~2) | 1;
    } else if (param_1[0] >= lbl_80539DA0) {
        result = (result & ~1) | 2;
    }

    if (-lbl_80539DA4 < param_1[1] && param_1[1] < lbl_80539DA4) {
        result &= ~0xc;
    } else if (param_1[1] <= -lbl_80539DA0) {
        result = (result & ~8) | 4;
    } else if (param_1[1] >= lbl_80539DA0) {
        result = (result & ~4) | 8;
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
        u8 mode = (u8)param_2 ? 2 : 0;
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
    
    switch (param_3) {
    case 0: {
        u32 v = param_1[3];
        if (param_1[2] == 0) return;
        if (v == 0) return;
        param_1[1] = v;
        param_1[0] = 0;
        break;
    }
    case 1:
        if (param_1[2] == 0) return;
        if (param_1[3] == 0) return;
        param_1[1] = 0xffffffff;
        param_1[0] = 0;
        break;
    case 2:
        if (param_1[2] == 0) return;
        if (param_1[3] == 0) return;
        param_1[1] = param_4;
        param_1[0] = 0;
        break;
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

    while (p != NULL) {
        int *obj = (int *)*p;
        s16 val = *(s16 *)((u8 *)obj + 0x7c);
        if (param_1 == val) return (int)obj;
        p = (int *)p[3];
    }

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
                if ((lbl_8053A938 & lbl_80499470[idx]) != 0) {
                    PADControlMotor(idx, 2);
                    lbl_8053A934[idx] = 0;
                }
            }
        }
    }
    lbl_8053A938 = param_1 & 0xf0000000;
}

extern "C" void fn_8008E488(void *param_1, u32 param_2, u32 param_3, u32 param_4) {
    ((u32 *)param_1)[8] = 0;
    ((u32 *)param_1)[7] = 0;
    ((u32 *)param_1)[9] = param_2;
    ((u32 *)param_1)[10] = param_3;
    ((u32 *)param_1)[11] = param_4;
}

extern "C" u32 fn_8008E4A4(u32 mask) {
    u32* p = lbl_80499480;
    if (lbl_8053A928 & *p) {
        mask &= *p ^ 0xffffffff;
    }
    p++;
    if (lbl_8053A928 & *p) {
        mask &= *p ^ 0xffffffff;
    }
    p++;
    if (lbl_8053A928 & *p) {
        mask &= *p ^ 0xffffffff;
    }
    p++;
    if (lbl_8053A928 & *p) {
        mask &= *p ^ 0xffffffff;
    }
    return PADRecalibrate(mask) != 0;
}

extern "C" void fn_8008E530(int param_1, int param_2, u32 param_3)
{
    if (param_2 >= 0) {
        u32 val1c = *(u32 *)((u32)param_1 + 0x1c);
        if (param_3 >= val1c) {
            u8* addr = (u8*)param_1;
            addr[0x11] = 1;
            addr += param_2;
            addr[0x48] = 1;
            u32 func_ptr = *(u32 *)((u32)param_1 + 0x4c);
            if (func_ptr != 0) {
                u32 arg = *(u32 *)((u32)param_1 + 0x50);
                ((void (*)(int, int, u32))(func_ptr))(param_2, param_1, arg);
            }
        }
    }
}

