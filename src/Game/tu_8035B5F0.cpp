#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "Game/ItemBase.h"

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
struct StateTableCopy { u32 words[24]; };
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

extern const f32 lbl_805428F4;
extern const f32 lbl_805428F8;
extern const f32 lbl_805428FC;
extern const f32 lbl_80542900;
extern "C" void* lbl_8053AAF8;
extern "C" void fn_801365C8(void* a, s32 b);
extern "C" void fn_8035BE24(u8* p) {
    f32 a;
    f32 b;
    f32 c;
    f32 sum;
    f32 diff;
    u8* s;
    s32 i;
    s32 id;
    u8* q;
    Vec off1;
    Vec pos1;
    Vec off2;
    Vec pos2;
    Vec off3;
    Vec pos3;

    fn_801365C8(lbl_8053AAF8, 0);
    *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x24) + 0x179) = 1;
    a = *(f32*)(p + 0x240);
    b = *(f32*)(p + 0x254);
    sum = a + b;
    diff = a - b;
    c = *(f32*)(p + 0x23c);
    s = *(u8**)((u8*)lbl_8053AB10 + 0x24);
    if (s[0x840] == 0) {
        s[0x840] = 1;
        *(f32*)(s + 0x844) = c;
        *(f32*)(s + 0x848) = diff;
        *(f32*)(s + 0x84c) = c;
        *(f32*)(s + 0x850) = sum;
        *(f32*)(s + 0x854) = lbl_805428EC;
        *(f32*)(s + 0x1d4) = lbl_805428F4;
        *(f32*)(s + 0x1d8) = lbl_805428F4;
    }

    off1.x = lbl_805428D4;
    off1.y = lbl_805428F8;
    off1.z = lbl_805428D4;
    JMathInlineVEC::PSVECAdd((Vec*)(p + 0xc), &off1, &pos1);
    *(s32*)(p + 0x278) = Actor_CreateByID(fn_801F856C(), 0x455a4c44, *(u32*)(p + 0x4), &pos1, 0, -1, -1);
    id = *(s32*)(p + 0x278);
    if (id >= 0) {
        void* found = fn_801F666C(fn_801F856C(), id);
        *(s32*)((u8*)found + 0x23c) = *(s32*)(p + 0x198);
    }

    q = p;
    for (i = 0; i < 6; i++) {
        id = Actor_CreateByID(fn_801F856C(), 0x454d494b, *(u32*)(p + 0x4), p + 0xc, i, -1, -1);
        *(s32*)(q + 0x27c) = id;
        if (id >= 0) {
            void* found = fn_801F666C(fn_801F856C(), id);
            *(s32*)((u8*)found + 0x23c) = *(s32*)(p + 0x198);
        }
        q += 4;
    }

    off2.x = lbl_805428FC;
    off2.y = lbl_80542900;
    off2.z = lbl_805428D4;
    JMathInlineVEC::PSVECAdd((Vec*)(p + 0xc), &off2, &pos2);
    *(s32*)(p + 0x294) = Actor_CreateByID(fn_801F856C(), 0x454c4e4b, *(u32*)(p + 0x4), &pos2, *(s32*)(p + 0x278), -1, -1);
    id = *(s32*)(p + 0x294);
    if (id >= 0) {
        void* found = fn_801F666C(fn_801F856C(), id);
        *(s32*)((u8*)found + 0x23c) = *(s32*)(p + 0x198);
    }

    off3.x = lbl_805428D4;
    off3.y = lbl_80542900;
    off3.z = lbl_805428D4;
    JMathInlineVEC::PSVECAdd((Vec*)(p + 0xc), &off3, &pos3);
    fn_80230498(0, &pos3, 0, 0xff, -0x80, -0x80, 1);
    for (i = 1; i < 4; i++) {
        Vec off;
        Vec pos;
        off.x = lbl_805428D4;
        off.y = lbl_80542900;
        off.z = lbl_805428D4;
        JMathInlineVEC::PSVECAdd((Vec*)(p + 0xc), &off, &pos);
        fn_80230498(i, &pos, 0, 0xff, -0x80, -0x80, 1);
    }
    *(s32*)(p + 0x230) = 1;
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
    int m_0;
    long m_4;
  };
  *(u32 *)(param_1 + 0x250) = param_3;
  *(u32 *)(param_1 + 0x244) = 0;
  *(u32 *)(param_1 + 0x24c) = 0;
  if (*(s32 *)(param_1 + 0x244) != 0) {
    return;
  }
  register Entry *base = (Entry *)lbl_804AD460[param_2];
  if (base[*(s32 *)(param_1 + 0x24c)].m_0 < 0) {
    return;
  }
  *(u32 *)(param_1 + 0x244) = base[*(s32 *)(param_1 + (unsigned)0x24c)].m_4;
  *(u32 *)(param_1 + 0x248) = base[*(s32 *)(param_1 + 0x24c)].m_0;
  *(s32 *)(param_1 + 0x24c) = *(s32 *)(param_1 + 0x24c) + 1;
}

extern "C" void fn_801F06F0(void* mgr, u32* tbl, s32 id, void* buf, s32 a, s32 b, s32 c, f32 x, f32 y);
extern u32 lbl_80472700[];
extern "C" void fn_8035C230(u8* p) {
    if (*(s32*)(p + 0x238) != 0) {
        JGeometry::TVec3<f32> saved(*(JGeometry::TVec3<f32>*)(p + 0xc));
        *(f32*)(p + 0x10) = *(f32*)(p + 0x10) + lbl_805428EC;
        DrawRec rec;
        s8 neg = -1;
        rec.b1d = neg;
        fn_801F06F0(p, lbl_80472700, 0x179, &rec, -1, 3, 1, lbl_805428EC, lbl_805428EC);
        *(JGeometry::TVec3<f32>*)(p + 0xc) = saved;
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

extern const f32 lbl_80542904;
extern const f32 lbl_80542908;
extern const f32 lbl_8054290C;
extern "C" void fn_8035C4BC(u8* p) {
    *(f32*)(p + 0xc) = lbl_80542904;
    *(f32*)(p + 0x10) = lbl_80542908;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x260) = 0;
    *(s32*)(p + 0x264) = 0;
    *(s32*)(p + 0x268) = 0;
    *(s32*)(p + 0x26c) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x278) = -1;
    *(s32*)(p + 0x298) = 0;
    *(s32*)(p + 0x29c) = 0;
    *(s32*)(p + 0x2a0) = 0;
    *(f32*)(p + 0x250) = lbl_8054290C;
    *(f32*)(p + 0x254) = lbl_805428E8;
    fn_80119998(fn_80119DD0(), 0x96, 0, 0, 0, 0, 0x14, 0);
    *(s32*)(p + 0x270) = -1;
    *(s32*)(p + 0x274) = 0;
}

void fn_8035C650(void) {
  u32 *src = lbl_804AD3A0;
  u32 *dst = lbl_804AD3A0 + 24;
  for (s32 i = 0; i < 24; i++) {
    dst[i] = src[i];
  }
}
