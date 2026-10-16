#include "types.h"
#include "JSystem/JGeometry/Vec.h"


extern "C" u8* lbl_804ADA98[];
extern "C" void fn_80360914(u8* p);
extern "C" u8 __vt__4EOWL[];
extern "C" void __dt__5ActorFv(void* p, s32 flag);
extern "C" void __dl__FPv(void* p);
class FsaState;
typedef void (FsaState::*FsaStateFn)();
struct FsaStateEntry {
    FsaStateFn fn;
};
extern FsaStateEntry lbl_804ADA50[];
struct JMathSinCos { f32 sin; f32 cos; };
extern "C" s32 lbl_804742A8[];
extern "C" const JMathSinCos sincosTable___5JMath[];
extern "C" u8 fn_8035F3C0(u8* p);
extern "C" void fn_8013CB44(u8* owner, u8* p, s32 a, s32 b, s32 c);
extern "C" void* fn_8035F360(void* param_1, s16 param_2) {
  if (param_1 != 0) {
    *(u8**)param_1 = __vt__4EOWL;
    __dt__5ActorFv(param_1, 0);
    if (param_2 > 0) {
      __dl__FPv(param_1);
    }
  }
  return param_1;
}

extern "C" void fn_8035FB64(u8* param_1) {
    if (*(s32*)(param_1 + 0x234) == 0) {
        if (lbl_804742A8[*(s32*)(param_1 + 0x240) * 2] < 0) {
            *(s32*)(param_1 + 0x240) = 0;
        }
        *(s32*)(param_1 + 0x234) = lbl_804742A8[*(s32*)(param_1 + 0x240) * 2 + 1];
        *(s32*)(param_1 + 0x23c) = lbl_804742A8[*(s32*)(param_1 + 0x240) * 2];
        *(s32*)(param_1 + 0x240) = *(s32*)(param_1 + 0x240) + 1;
    }
    if (*(f32*)(param_1 + 0x26c) < 16.0f) {
        *(f32*)(param_1 + 0x26c) = *(f32*)(param_1 + 0x26c) + 0.2f;
    }
    s32 step = (s32)(65536.0f * (1.75f / (6.28318f * *(f32*)(param_1 + 0x26c))));
    *(s16*)(param_1 + 0x254) = *(s16*)(param_1 + 0x254) - step;
    *(f32*)(param_1 + 0x3c) = 1.75f * sincosTable___5JMath[(*(s16*)(param_1 + 0x254) >> 5) & 0x7ff].cos;
    *(f32*)(param_1 + 0x40) = 1.75f * sincosTable___5JMath[(*(s16*)(param_1 + 0x254) >> 5) & 0x7ff].sin;
    *(f32*)(param_1 + 0x44) = 0.2f;
    *(s32*)(param_1 + 0x264) = *(s32*)(param_1 + 0x264) + (s16)step;
    if (*(f32*)(param_1 + 0x26c) < 16.0f) {
        fn_80360914(param_1);
        *(f32*)(param_1 + 0x44) = 0.0f;
    }
}

extern "C" void fn_8035FCD8(u8* param_1) {
  u8 done;
  s32 tbl = *(s32*)(param_1 + 0x244);
  if (*(s32*)(param_1 + 0x234) == 0) {
    s32 idx = *(s32*)(param_1 + 0x240);
    struct Entry {
      s32 m_0;
      u32 m_4;
    };
    Entry* base = (Entry*)lbl_804ADA98[tbl];
    if (base[idx].m_0 < 0) {
      done = 1;
      goto end;
    }
    *(u32*)(param_1 + 0x234) = base[idx].m_4;
    *(u32*)(param_1 + 0x23c) = base[*(s32*)(param_1 + 0x240)].m_0;
    *(s32*)(param_1 + 0x240) = *(s32*)(param_1 + 0x240) + 1;
  }
  done = 0;
end:
  if (done == 1) {
    fn_80360914(param_1);
  }
}

extern "C" s32 lbl_804742A8[];
extern "C" void fn_8021A570(u8* r, s32 active);
extern "C" void fn_8035FF70(u8* param_1) {
    if (*(u8*)(param_1 + 0x2b0) == 1) {
        if (*(s32*)(param_1 + 0x270) == 0) {
            fn_8021A570(param_1 + 0x2a0, 1);
        } else if (*(s32*)(param_1 + 0x234) == 0) {
            if (lbl_804742A8[*(s32*)(param_1 + 0x240) * 2] < 0) {
                *(s32*)(param_1 + 0x240) = 0;
            }
            *(s32*)(param_1 + 0x234) = lbl_804742A8[*(s32*)(param_1 + 0x240) * 2 + 1];
            *(s32*)(param_1 + 0x23c) = lbl_804742A8[*(s32*)(param_1 + 0x240) * 2];
            *(s32*)(param_1 + 0x240) = *(s32*)(param_1 + 0x240) + 1;
        }
    }
    if (*(s32*)(param_1 + 0x280) == 0) {
        fn_80360914(param_1);
    }
}

extern "C" void fn_803613D0(u8* param_1) {
  u8* e = *(u8**)(param_1 + 0x2b4);
  if (e != 0) {
    *(u32*)(e + 0xf4) |= 1;
    *(s32*)(e + 0x24) = 1;
    *(u8**)(param_1 + 0x2b4) = 0;
  }
  e = *(u8**)(param_1 + 0x2b8);
  if (e != 0) {
    *(u32*)(e + 0xf4) |= 1;
    *(s32*)(e + 0x24) = 1;
    *(u8**)(param_1 + 0x2b8) = 0;
  }
}

extern "C" void fn_80361DAC(u8* param_1) {
    if (*(s32*)(param_1 + 0x280) != 0) {
        *(s32*)(param_1 + 0x280) = *(s32*)(param_1 + 0x280) - 1;
    }
    if (*(s32*)(param_1 + 0x234) != 0) {
        *(s32*)(param_1 + 0x234) = *(s32*)(param_1 + 0x234) - 1;
    }
    do {
    } while (fn_8035F3C0(param_1) != 0);
    (((FsaState*)param_1)->*lbl_804ADA50[*(s32*)(param_1 + 0x278)].fn)();
    if (*(u8*)(param_1 + 0x2b0) == 0) {
        if (*(u8**)(param_1 + 0x2b4) != 0) {
            fn_8013CB44(*(u8**)(param_1 + 0x2b4), param_1 + 0xc, -2, -2, 1);
        }
        if (*(u8**)(param_1 + 0x2b8) != 0) {
            fn_8013CB44(*(u8**)(param_1 + 0x2b8), param_1 + 0xc, -2, -2, 1);
        }
    } else {
        if (*(u8**)(param_1 + 0x2b4) != 0) {
            fn_8013CB44(*(u8**)(param_1 + 0x2b4), param_1 + 0xc, *(s8*)(param_1 + 0x24c), *(s8*)(param_1 + 0x24d), 1);
        }
        if (*(u8**)(param_1 + 0x2b8) != 0) {
            fn_8013CB44(*(u8**)(param_1 + 0x2b8), param_1 + 0xc, *(s8*)(param_1 + 0x24c), *(s8*)(param_1 + 0x24d), 1);
        }
    }
}

