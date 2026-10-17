#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

struct FsaStateEntry;
typedef void (FsaStateEntry::*FsaStateFn)();
struct FsaStateEntry {
    FsaStateFn fn;
};
extern FsaStateEntry lbl_804AD400[];
extern "C" void fn_801F0E34(void* p, s32 a, s32 b);
extern "C" void* lbl_8053AB10;

extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern const f32 lbl_805428D8;
extern const f32 lbl_805428DC;


extern u32 lbl_804AD3A0[48];
extern const f32 lbl_805428E8;
extern const f32 lbl_805428EC;
extern u32 *lbl_804AD460[];
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern const f32 lbl_805428D8;
extern const f32 lbl_805428DC;
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* p);
extern u32 lbl_804AD48C[];
extern "C" s32 fn_8013CC50(u32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern const f32 lbl_805428E0;
extern const f32 lbl_805428E4;
extern const f32 lbl_805428F0;
extern "C" void* fn_8035B5F0(void* this_, s16 flag) {
    if (this_ != 0) {
        *(u32*)this_ = (u32)lbl_804AD48C;
        __dt__5ActorFv(this_, 0);
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_80119DD0(void);
extern "C" void fn_80119998(void* a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, void* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" void fn_80230498(s32 i, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e);
extern const f32 lbl_805428D0;
extern const f32 lbl_805428D4;
extern "C" void fn_8035B650(u8* p) {
    if (*(s32*)(p + 0x234) == 0) {
        fn_80119998(fn_80119DD0(), 0x96, 0, 1, 0, 0, 0xfa, 0);
        *(s32*)(p + 0x234) += 1;
        *(s32*)(p + 0x260) = 0x11c;
    } else if (*(s32*)(p + 0x260) == 0) {
        u8* obj = *(u8**)(p + 0x298);
        if (obj != 0) {
            *(u32*)(obj + 0xf4) |= 0x100;
            *(u32*)(p + 0x298) = 0;
        }
        obj = *(u8**)(p + 0x29c);
        if (obj != 0) {
            *(u32*)(obj + 0xf4) |= 0x100;
            *(u32*)(p + 0x29c) = 0;
        }
        obj = *(u8**)(p + 0x2a0);
        if (obj != 0) {
            *(u32*)(obj + 0xf4) |= 0x100;
            *(u32*)(p + 0x2a0) = 0;
        }
        *(u8*)(p + 0x11c) = 0;
    } else if (*(s32*)(p + 0x260) == 1) {
        f32 pos[3];
        s32 i;
        Actor_CreateByID(fn_801F856C(), 0x454e444d, *(u32*)(p + 0x4), p + 0xc, 0, -1, -1);
        pos[0] = lbl_805428D0;
        pos[1] = lbl_805428D0;
        pos[2] = lbl_805428D4;
        for (i = 0; i < 4; i++) {
            fn_80230498(i, pos, 0, 0xff, -0x80, -0x80, 1);
        }
    }
}

extern "C" void fn_8035B7A8(u8* p) {
    if (*(s32*)(p + 0x234) != 0) {
        void* base = fn_801F856C();
        void* found = fn_801F666C(base, *(s32*)(p + 0x278));
        if (found != 0) {
            *(s32*)((u8*)found + 0x238) = 1;
        }
        base = fn_801F856C();
        found = fn_801F666C(base, *(s32*)(p + 0x294));
        if (found != 0) {
            *(s32*)((u8*)found + 0x238) = 1;
        }
        *(s32*)(p + 0x234) = 0;
    }
}

extern "C" void fn_8035B81C(u8* p) {
    s32 cnt = 0;
    f32 v = *(f32*)(p + 0x240);
    if (v < lbl_805428D8) {
        *(f32*)(p + 0x240) = v + *(f32*)(p + 0x258);
    } else {
        *(f32*)(p + 0x240) = lbl_805428D8;
        cnt = 1;
    }
    v = *(f32*)(p + 0x254);
    if (v > lbl_805428DC) {
        *(f32*)(p + 0x254) = v - *(f32*)(p + 0x25c);
    } else {
        *(f32*)(p + 0x254) = lbl_805428DC;
        cnt++;
    }
    if (cnt >= 2) {
        void* base = fn_801F856C();
        void* found = fn_801F666C(base, *(s32*)(p + 0x278));
        if (found != 0) {
            *(s32*)((u8*)found + 0x238) = 1;
        }
        *(s32*)(p + 0x230) = *(s32*)(p + 0x230) + 1;
    }
}

extern const f32 lbl_805428E0;
extern const f32 lbl_805428E4;
extern "C" void fn_8035B8C8(u8* p) {
    f32 v = *(f32*)(p + 0x240);
    if (v > lbl_805428E0) {
        *(f32*)(p + 0x240) = v - *(f32*)(p + 0x258);
    } else {
        *(f32*)(p + 0x240) = lbl_805428E0;
    }
    v = *(f32*)(p + 0x254);
    if (v < lbl_805428E4) {
        *(f32*)(p + 0x254) = v + *(f32*)(p + 0x25c);
    } else {
        *(f32*)(p + 0x254) = lbl_805428E4;
    }
    s32 mode = *(s32*)(p + 0x260);
    if (mode == 0xf0) {
        void* found = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x278));
        if (found != 0) {
            *(s32*)((u8*)found + 0x238) = 1;
        }
        found = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x278));
        if (found != 0) {
            *(s32*)((u8*)found + 0x244) = 0;
            *(s32*)((u8*)found + 0x248) = 0;
            *(s32*)((u8*)found + 0x24c) = 0;
        }
        u8* q;
        s32 i = 1;
        q = p + 4;
        for (; i <= 6; i++) {
            if (i == 0) {
                found = fn_801F666C(fn_801F856C(), *(s32*)(q + 0x278));
                if (found != 0) {
                    *(s32*)((u8*)found + 0x238) = 1;
                }
            } else {
                found = fn_801F666C(fn_801F856C(), *(s32*)(q + 0x278));
                if (found != 0) {
                    *(s32*)((u8*)found + 0x238) = 1;
                }
            }
            found = fn_801F666C(fn_801F856C(), *(s32*)(q + 0x278));
            if (found != 0) {
                *(s32*)((u8*)found + 0x244) = 0;
                *(s32*)((u8*)found + 0x248) = 8;
                *(s32*)((u8*)found + 0x24c) = 0;
            }
            q += 4;
        }
    } else if (mode == 1) {
        void* found = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x278));
        if (found != 0) {
            *(s32*)((u8*)found + 0x238) = 3;
        }
        u8* q = p + 4;
        for (s32 i = 1; i <= 6; i++) {
            if (i == 0) {
                found = fn_801F666C(fn_801F856C(), *(s32*)(q + 0x278));
                if (found != 0) {
                    *(s32*)((u8*)found + 0x238) = 3;
                }
            } else {
                found = fn_801F666C(fn_801F856C(), *(s32*)(q + 0x278));
                if (found != 0) {
                    *(s32*)((u8*)found + 0x238) = 3;
                }
            }
            q += 4;
        }
    } else {
        void* found = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x28c));
        if (found != 0 && *(s32*)((u8*)found + 0x230) == 2 && *(s32*)((u8*)found + 0x234) == 0) {
            s32 i;
            u8* q = p + 4;
            i = 1;
            for (; i <= 6; i++) {
                if (i == 0) {
                    found = fn_801F666C(fn_801F856C(), *(s32*)(q + 0x278));
                    if (found != 0) {
                        *(s32*)((u8*)found + 0x238) = 1;
                    }
                } else {
                    found = fn_801F666C(fn_801F856C(), *(s32*)(q + 0x278));
                    if (found != 0) {
                        *(s32*)((u8*)found + 0x238) = 1;
                    }
                }
                q += 4;
            }
        }
    }
}

extern "C" void fn_8035BB20(u8* p) {
    if (*(f32*)(p + 0x254) < lbl_805428E8) {
        *(f32*)(p + 0x254) = *(f32*)(p + 0x254) + lbl_805428EC;
    } else {
        fn_8013CC50(*(u32*)(p + 4), p + 0x248, lbl_805428EC, 0x405, 0, -1, 0, 0, 1);
        fn_8013CC50(*(u32*)(p + 4), p + 0x248, lbl_805428EC, 0x406, 0, -1, 0, 0, 1);
        fn_8013CC50(*(u32*)(p + 4), p + 0x248, lbl_805428EC, 0x407, 0, -1, 0, 0, 1);
        fn_8013CC50(*(u32*)(p + 4), p + 0x248, lbl_805428EC, 0x408, 0, -1, 0, 0, 1);
        fn_8013CC50(*(u32*)(p + 4), p + 0x248, lbl_805428EC, 0x409, 0, 0, 0, 0, 1);
        fn_8013CC50(*(u32*)(p + 4), p + 0x248, lbl_805428EC, 0x40a, 0, 0, 0, 0, 1);
        fn_8013CC50(*(u32*)(p + 4), p + 0x248, lbl_805428EC, 0x40b, 0, 0, 0, 0, 1);
        fn_8013CC50(*(u32*)(p + 4), p + 0x248, lbl_805428EC, 0x40c, 0, 0, 0, 0, 1);
        *(s32*)(p + 0x298) = fn_8013CC50(*(u32*)(p + 4), p + 0x248, lbl_805428EC, 0x4a2, 0, 0, 0, 0, 1);
        *(s32*)(p + 0x29c) = fn_8013CC50(*(u32*)(p + 4), p + 0x248, lbl_805428EC, 0x4a3, 0, 0, 0, 0, 1);
        *(s32*)(p + 0x2a0) = fn_8013CC50(*(u32*)(p + 4), p + 0x248, lbl_805428EC, 0x46d, 0, 0, 0, 0, 1);
        *(s32*)(p + 0x270) = 0x258;
        void* obj = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x278));
        if (obj != 0) {
            *(s32*)((u8*)obj + 0x238) = 1;
        }
        u8* q = p + 4;
        for (s32 i = 1; i <= 6; i++) {
            if (i == 0) {
                void* o = fn_801F666C(fn_801F856C(), *(s32*)(q + 0x278));
                if (o != 0) {
                    *(s32*)((u8*)o + 0x238) = 1;
                }
            } else {
                void* o = fn_801F666C(fn_801F856C(), *(s32*)(q + 0x278));
                if (o != 0) {
                    *(s32*)((u8*)o + 0x238) = 1;
                }
            }
            q += 4;
        }
        *(s32*)(p + 0x260) = 0x348;
        *(f32*)(p + 0x258) = (*(f32*)(p + 0x240) - lbl_805428E0) / lbl_805428F0;
        *(f32*)(p + 0x25c) = (lbl_805428E4 - *(f32*)(p + 0x254)) / lbl_805428F0;
        *(s32*)(p + 0x230) = *(s32*)(p + 0x230) + 1;
    }
}

extern "C" void fn_8035BE00(u8 *param_1) {
  f32 v = *(f32 *)(param_1 + 0x254);
  if (v > lbl_805428E8) {
    *(f32 *)(param_1 + 0x254) = v - lbl_805428EC;
  }
}

extern "C" void fn_8035BE20(void) {
}

extern "C" u32 fn_8035C15C(u8 *param_1, s32 param_2) {
  if (*(s32 *)(param_1 + 0x244) == 0) {
    s32 idx = *(s32 *)(param_1 + 0x24c);
    struct Entry {
      s32 m_0;
      u32 m_4;
    };
    Entry *base = (Entry *)lbl_804AD460[param_2];
    if (base[idx].m_0 < 0) {
      return 1;
    }
    *(u32 *)(param_1 + 0x244) = base[idx].m_4;
    *(u32 *)(param_1 + 0x248) = base[*(s32 *)(param_1 + 0x24c)].m_0;
    *(s32 *)(param_1 + 0x24c) = *(s32 *)(param_1 + 0x24c) + 1;
  }
  return 0;
}

extern "C" void fn_8035C1C4(u8 *param_1, s32 param_2, u32 param_3) {
  struct Entry {
    s32 m_0;
    u32 m_4;
  };
  *(u32 *)(param_1 + 0x250) = param_3;
  *(u32 *)(param_1 + 0x244) = 0;
  *(u32 *)(param_1 + 0x24c) = 0;
  if (*(s32 *)(param_1 + 0x244) != 0) {
    return;
  }
  Entry *base = (Entry *)lbl_804AD460[param_2];
  s32 idx = *(s32 *)(param_1 + 0x24c);
  if (base[idx].m_0 < 0) {
    return;
  }
  *(u32 *)(param_1 + 0x244) = base[idx].m_4;
  *(u32 *)(param_1 + 0x248) = base[*(s32 *)(param_1 + 0x24c)].m_0;
  *(s32 *)(param_1 + 0x24c) = *(s32 *)(param_1 + 0x24c) + 1;
}

extern "C" void fn_801F06F0(void* mgr, u32* tbl, s32 id, void* buf, s32 a, s32 b, s32 c, f32 x, f32 y);
extern "C" void fn_8035C230(u8* p) {
    if (*(s32*)(p + 0x238) != 0) {
        u8 idx[16];
        s32 i;
        for (i = 0; i < 16; i++) {
            idx[i] = i;
        }
        *(f32*)(p + 0x10) = *(f32*)(p + 0x10) + lbl_805428EC;
        f32 pair[2];
        pair[0] = *(f32*)(p + 0xc);
        pair[1] = *(f32*)(p + 0x10);
    }
}

extern "C" void fn_8035C3A8(u8* p) {
    f32 b = *(f32*)(p + 0x254);
    f32 a = *(f32*)(p + 0x240);
    f32 sum = a + b;
    f32 diff = a - b;
    f32 c = *(f32*)(p + 0x23c);
    *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x24) + 0x179) = 1;
    u8* s = *(u8**)((u8*)lbl_8053AB10 + 0x24);
    if (s[0x7f5] == 0) {
        s[0x7f4] = 1;
        *(s32*)(s + 0x7f8) = 5;
        *(f32*)(s + 0x808) = c;
        *(f32*)(s + 0x80c) = diff;
        *(f32*)(s + 0x810) = c;
        *(f32*)(s + 0x814) = sum;
        s[0x7f6] = 0;
    }
    *(s32*)(p + 0x274) += 1;
    if (*(s32*)(p + 0x260) != 0) {
        *(s32*)(p + 0x260) -= 1;
    }
    if (*(s32*)(p + 0x268) != 0) {
        *(s32*)(p + 0x268) -= 1;
    }
    s32 t = *(s32*)(p + 0x270);
    if (t > 0) {
        *(s32*)(p + 0x270) = t - 1;
    } else if (t == 0) {
        *(s32*)(p + 0x270) = -1;
        fn_801F0E34(p, 0x30086, 0);
    }
    FsaStateEntry* e = &lbl_804AD400[*(s32*)(p + 0x230)];
    (((FsaStateEntry*)p)->*e->fn)();
}

extern "C" void fn_8035C4B8(void) {}

void fn_8035C650(void) {
  u32 *src = lbl_804AD3A0;
  u32 *dst = lbl_804AD3A0 + 24;
  for (s32 i = 0; i < 24; i++) {
    dst[i] = src[i];
  }
}
