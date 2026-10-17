

#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, s32 a, s32 b, f32 s0, f32 s1);
extern "C" const char lbl_80474BFC[];
extern "C" f32 lbl_80542B10;

extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" void* fn_804032E8(u32 type, const char* name);
extern "C" void fn_802F745C(void* mgr, void* pos, void* tex, void* prm);
extern "C" void* lbl_8053AB10;
extern "C" const char lbl_80474C10[];
extern "C" const s32 lbl_80474B88[];
extern "C" const s32 lbl_80474BA0[];
extern "C" const s32 lbl_80474320[];
extern "C" f32 lbl_80542B5C;

struct Unk80365AB8;
typedef void (Unk80365AB8::*Unk80365AB8Func)();
extern Unk80365AB8Func lbl_804ADDE8[];
extern Unk80365AB8Func lbl_804ADC38[];
extern "C" f32 lbl_80542BD4;
extern "C" f32 lbl_80542B0C;
extern "C" f32 lbl_80542BC4;
extern "C" f32 lbl_80542B8C;
extern "C" f32 lbl_80542BC8;
extern "C" f32 lbl_80542B54;
extern "C" f32 lbl_80542B20;
extern "C" f32 lbl_80542B24;
extern "C" f32 lbl_80542B28;
extern "C" f32 lbl_80542B2C;
extern "C" f32 lbl_80542B30;
extern "C" f32 lbl_80542B34;
extern "C" f32 lbl_80542B38;
extern "C" f32 lbl_80542B3C;
extern "C" f32 lbl_80542B40;
extern "C" f32 lbl_80542B44;
extern "C" f32 lbl_80542B48;
extern "C" f32 lbl_80542B4C;
extern "C" f32 lbl_80542BB4;
extern "C" f32 lbl_80542BB8;
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801CD664(s32 n);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);

static bool fn_80364340_isBadPos(Vec* p) {
    if (p->x < lbl_80542B20) {
    } else if (p->x > lbl_80542B24) {
        return true;
    }
    if (p->y < lbl_80542B28) {
    } else if (p->y > lbl_80542B2C) {
        return true;
    }
    if (p->x + p->y < lbl_80542B30) {
        return true;
    }
    if (p->x > lbl_80542B34 && p->y < lbl_80542B38) {
        return true;
    }
    Vec v1 = {lbl_80542B3C, lbl_80542B38, lbl_80542B0C};
    if (PSVECDistance(p, &v1) < lbl_80542B40) {
        return true;
    }
    Vec v2 = {lbl_80542B44, lbl_80542B48, lbl_80542B0C};
    return PSVECDistance(p, &v2) < lbl_80542B40;
}


extern "C" const s32 lbl_80474A98[];
extern "C" const s32 lbl_80474AD8[];

extern "C" void fn_80362634(char* self) {
    if (*(void**)(self + 0x300) != NULL) {
        void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(self + 0x300));
        *(void**)(self + 0x300) = NULL;
    }
}

extern "C" void fn_80362680(char* self) {
    const char* names = (const char*)lbl_80474320;
    struct {
        u8 unk_0x0[16];
        s32 unk_0x10;
        s32 unk_0x14;
        void* unk_0x18;
        u8 unk_0x1c;
        u8 unk_0x1d;
        u8 unk_0x1e;
        u8 unk_0x1f;
        u8 unk_0x20;
        u8 unk_0x21[5];
        u8 unk_0x26;
        s32 unk_0x28;
        u8 unk_0x2c;
        u8 unk_0x2d[2];
        s32 unk_0x30;
        s32 unk_0x34;
        s32 unk_0x38;
    } p;
    f32 mtx[3][4];
    s32 i;

    p.unk_0x10 = -1;
    p.unk_0x14 = -1;
    for (i = 0; (u8)i < 0x10; i += 8) {
        p.unk_0x0[(u8)i] = i;
        p.unk_0x0[(u8)(i + 1)] = i + 1;
        p.unk_0x0[(u8)(i + 2)] = i + 2;
        p.unk_0x0[(u8)(i + 3)] = i + 3;
        p.unk_0x0[(u8)(i + 4)] = i + 4;
        p.unk_0x0[(u8)(i + 5)] = i + 5;
        p.unk_0x0[(u8)(i + 6)] = i + 6;
        p.unk_0x0[(u8)(i + 7)] = i + 7;
    }
    p.unk_0x1f = 1;
    p.unk_0x10 = -1;
    p.unk_0x14 = 0;
    p.unk_0x18 = NULL;
    p.unk_0x1c = 0;
    p.unk_0x1d = 0;
    p.unk_0x1e = 0;
    p.unk_0x20 = 1;
    p.unk_0x21[0] = 0;
    p.unk_0x21[1] = 0;
    p.unk_0x21[2] = 0;
    p.unk_0x21[3] = 0;
    p.unk_0x21[4] = 0;
    p.unk_0x26 = 1;
    p.unk_0x28 = 3;
    p.unk_0x2c = 1;
    p.unk_0x2d[0] = 0;
    p.unk_0x2d[1] = 0;
    p.unk_0x30 = -1;
    p.unk_0x34 = 0;
    p.unk_0x38 = 2;
    p.unk_0x1f = 0;

    if (*(s32*)(self + 0x234) == 0x10 || *(s32*)(self + 0x234) == 8) {
        p.unk_0x1d = 1;
    }
    if (*(s32*)(self + 0x234) == 4) {
        if (*(s32*)(self + 0x238) == 0x1d || *(s32*)(self + 0x238) == 0x1e) {
            p.unk_0x26 = 0;
        }
        if (*(s32*)(self + 0x238) >= 0x26 && *(s32*)(self + 0x238) <= 0x29) {
            *((u8*)&p.unk_0x10 + 3) = 0x66;
        }
    }
    if (*(u8*)(self + 0x278) == 1) {
        p.unk_0x18 = mtx;
        mtx[0][3] = lbl_80542B0C;
        mtx[1][3] = lbl_80542B0C;
        mtx[2][3] = lbl_80542B0C;
        mtx[0][0] = lbl_80542B5C;
        mtx[0][1] = lbl_80542B0C;
        mtx[0][2] = lbl_80542B0C;
        mtx[1][0] = lbl_80542B0C;
        mtx[1][1] = lbl_80542B10;
        mtx[1][2] = lbl_80542B0C;
        mtx[2][0] = lbl_80542B0C;
        mtx[2][1] = lbl_80542B0C;
        mtx[2][2] = lbl_80542B10;
    }
    if (*(s32*)(self + 0x258) == 0) {
        fn_801F06F0(self, names + 0x8b4, *(s32*)(self + 0x26c) + *(s32*)(self + 0x264), (s32)&p, 7, lbl_80542B10, lbl_80542B10);
    } else if (*(s32*)(self + 0x258) == 1) {
        fn_801F06F0(self, names + 0x8c8, *(s32*)(self + 0x26c) + *(s32*)(self + 0x264), (s32)&p, 7, lbl_80542B10, lbl_80542B10);
    } else if (*(s32*)(self + 0x258) == 2) {
        fn_801F06F0(self, names + 0x8dc, *(s32*)(self + 0x26c) + *(s32*)(self + 0x264), (s32)&p, 7, lbl_80542B10, lbl_80542B10);
    }
}

extern "C" f32 lbl_80474BB8[];
extern "C" const char lbl_80474BD4[];
extern "C" void fn_801EF830(s32 idx, f32* pos, u8* p3, u32 mask, u8* p5, u32 p6, u8* p7);
extern "C" void fn_803628D4(char* self) {
  JGeometry::TVec3<f32> saved = *(JGeometry::TVec3<f32>*)(self + 0xc);
  u8 arr[16];
  u8 i;
  for (i = 0; i < 16; i += 8) {
    arr[i] = i;
    arr[i + 1] = i + 1;
    arr[i + 2] = i + 2;
    arr[i + 3] = i + 3;
    arr[i + 4] = i + 4;
    arr[i + 5] = i + 5;
    arr[i + 6] = i + 6;
    arr[i + 7] = i + 7;
  }
  if ((*(s32*)(self + 0x268) & 7) >= 5) {
    *(f32*)(self + 0x10) -= lbl_80474BB8[(*(s32*)(self + 0x268) & 7) - 5];
  }
  fn_801F06F0(self, lbl_80474BD4, *(s32*)(self + 0x26c) + *(s32*)(self + 0x264), (s32)arr, -1, lbl_80542B10, lbl_80542B10);
  *(JGeometry::TVec3<f32>*)(self + 0xc) = saved;
  if (*(s32*)(self + 0x138) == 0) {
    fn_801EF830(*(s32*)(self + 4), (f32*)(self + 0xc), arr, 7, (u8*)lbl_80474BD4, *(s32*)(self + 0x26c) + *(s32*)(self + 0x264), 0);
  }
}

extern "C" void fn_80362B14(char* self) {
    void* tex = fn_804032E8(0x54494d47, lbl_80474C10);
    if (*(s32*)(self + 4) < 8) {
        fn_802F745C(*(void**)((char*)lbl_8053AB10 + 0x20), self + 0xc, tex, NULL);
    }
}

extern "C" void fn_80362B74(char* self) {
    Vec saved;
    s32 i;

    fn_801F06F0(self, lbl_80474BFC, *(s32*)(self + 0x26c) + *(s32*)(self + 0x264), 0, 7, lbl_80542B10, lbl_80542B10);
    JGeometry::setTVec3f((f32*)(self + 0xc), (f32*)&saved);
    for (i = 0; i < 3; i++) {
        JGeometry::setTVec3f((f32*)(self + 0x27c + i * 0xc), (f32*)(self + 0xc));
        fn_801F06F0(self, lbl_80474BFC, *(s32*)(self + 0x2e8 + i * 4) + *(s32*)(self + 0x264), 0, 7, lbl_80542B10, lbl_80542B10);
    }
    JGeometry::setTVec3f((f32*)&saved, (f32*)(self + 0xc));
}

extern "C" void fn_8036335C(void) {
}

extern "C" void fn_80363F7C(char* self) {
    if (*(s32*)(self + 0x25c) == 0) {
        *(s32*)(self + 0x268) = *(s32*)(self + 0x268) + 1;
        if (*(s32*)(self + 0x268) >= 6) {
            *(s32*)(self + 0x268) = 0;
        }
        *(s32*)(self + 0x25c) = lbl_80474B88[*(s32*)(self + 0x268)];
        *(s32*)(self + 0x264) = lbl_80474BA0[*(s32*)(self + 0x268)];
    }
    ((JGeometry::TVec3<f32>*)(self + 0xc))->add(*(JGeometry::TVec3<f32>*)(self + 0x3c));
}

extern "C" void fn_80364340(char* self) {
    if (*(s32*)(self + 0x248) == 0) {
        JGeometry::TVec3<f32> saved = *(JGeometry::TVec3<f32>*)(self + 0xc);
        JGeometry::TVec3<f32> offs;
        offs.x = (f32)fn_801CD664(0x17c) - lbl_80542BB4;
        offs.y = (f32)fn_801CD664(0x17c) - lbl_80542BB8;
        offs.z = lbl_80542B0C;
        ((JGeometry::TVec3<f32>*)(self + 0xc))->add(offs);
        f32 x = *(f32*)(self + 0xc);
        f32 y = *(f32*)(self + 0x10);
        u8 hit = 0;
        if (!(x < lbl_80542B20) && x > lbl_80542B24) {
            hit = 1;
        } else if (!(y < lbl_80542B28) && y > lbl_80542B2C) {
            hit = 1;
        } else if (x + y < lbl_80542B30) {
            hit = 1;
        } else if (x > lbl_80542B34 && y < lbl_80542B38) {
            hit = 1;
        } else {
            Vec v1 = {lbl_80542B3C, lbl_80542B38, lbl_80542B0C};
            Vec v2 = {lbl_80542B44, lbl_80542B48, lbl_80542B0C};
            if (PSVECDistance((Vec*)(self + 0xc), &v1) < lbl_80542B40) {
                hit = 1;
            } else if (PSVECDistance((Vec*)(self + 0xc), &v2) < lbl_80542B40) {
                hit = 1;
            }
        }
        if (hit) {
            *(JGeometry::TVec3<f32>*)(self + 0xc) = saved;
            return;
        }
        *(s32*)(self + 0x248) = fn_801CD664(0x32) + 0x3c;
        *(JGeometry::TVec3<f32>*)(self + 0xc) = saved;
        offs.z = lbl_80542B4C;
        JGeometry::TVec3<f32> spawn(saved);
        spawn.add(offs);
        u32 type = fn_801CD664(8) | 0x250000;
        Actor_CreateByID(fn_801F856C(), 0x52555059, *(u32*)(self + 4), (f32*)&spawn, type, -1, -1);
    }
}

extern "C" void fn_80364900(char* self) {
    if (*(s32*)(self + 0x238) == 0) {
        ((JGeometry::TVec3<f32>*)(self + 0xc))->add(*(JGeometry::TVec3<f32>*)(self + 0x3c));
        if (*(s32*)(self + 0x25c) != 0) {
            return;
        }
        *(s32*)(self + 0x268) += 1;
        if (*(s32*)(self + 0x268) >= 0x10) {
            f32 zero = lbl_80542B0C;
            *(s32*)(self + 0x238) = 1;
            *(s32*)(self + 0x264) = 0;
            *(s32*)(self + 0x268) = 0;
            *(s32*)(self + 0x26c) = 0x2b1;
            *(f32*)(self + 0x44) = lbl_80542BC4;
            *(f32*)(self + 0x3c) = zero;
            return;
        }
        {
            f32 zero = lbl_80542B0C;
            *(s32*)(self + 0x25c) = lbl_80474A98[*(s32*)(self + 0x268)];
            if (*(f32*)(self + 0x3c) < zero) {
                *(s32*)(self + 0x264) = lbl_80474AD8[*(s32*)(self + 0x268) + 16];
            } else {
                *(s32*)(self + 0x264) = lbl_80474AD8[*(s32*)(self + 0x268)];
            }
        }
        return;
    }
    {
        f32 zero = lbl_80542B0C;
        *(f32*)(self + 0x44) -= lbl_80542B8C;
        ((JGeometry::TVec3<f32>*)(self + 0xc))->add(*(JGeometry::TVec3<f32>*)(self + 0x3c));
        if (*(f32*)(self + 0x14) >= zero) {
            return;
        }
        *(s32*)(self + 0x238) = 0;
        *(f32*)(self + 0x14) = zero;
        *(f32*)(self + 0x44) = zero;
        *(s32*)(self + 0x26c) = 0x38e;
        *(s32*)(self + 0x25c) = 4;
        if (*(s32*)(self + 0x23c) == 3) {
            *(s32*)(self + 0x23c) = 2;
            *(f32*)(self + 0x3c) = lbl_80542BC8;
            *(s32*)(self + 0x264) = 5;
            *(s32*)(self + 0x25c) = 4;
        } else {
            *(s32*)(self + 0x23c) = 3;
            *(f32*)(self + 0x3c) = lbl_80542B54;
            *(s32*)(self + 0x26c) = 0x38e;
            *(s32*)(self + 0x264) = 0;
        }
    }
}

extern "C" void* fn_801F856C(void);
extern "C" f32 lbl_80542B50;
extern "C" f32 lbl_80542B58;
extern "C" const s32 lbl_80474320[];
extern "C" const s32 lbl_80474450[];
extern "C" void fn_80364D0C(char* self) {
    s32 idx = *(s32*)(self + 0x24c);
    if (idx < 0) {
        s32 count = *(s32*)((char*)fn_801F856C() + 0x1008);
        s32 off = 0;
        s32 i = 0;
        for (; i < count; off += 4, i++) {
            char* p = *(char**)((char*)fn_801F856C() + off + 8);
            if (p != NULL && *(u32*)(p + 0x1a0) == 0x454f574c) {
                *(s32*)(self + 0x24c) = i;
                break;
            }
        }
    } else {
        s32 old = *(s32*)(self + 0x23c);
        char* p = ((char**)((char*)fn_801F856C() + 8))[idx];
        if (p == NULL) {
            *(s32*)(self + 0x24c) = -1;
        } else {
            if (PSVECDistance((Vec*)(self + 0xc), (Vec*)(p + 0xc)) < lbl_80542B58) {
                *(s32*)(self + 0x23c) = 0;
            } else {
                f32 angle = JMath::atanTable_.atan2_(*(f32*)(p + 0x10) - *(f32*)(self + 0x10),
                                                     *(f32*)(p + 0xc) - *(f32*)(self + 0xc));
                *(s16*)(self + 0x240) = (s16)(angle * lbl_80542B50);
                u16 u = *(s16*)(self + 0x240);
                if (u >= 0x2000 && u < 0x6000) {
                    *(s32*)(self + 0x23c) = 0;
                } else if (u >= 0x6000 && u < 0xa000) {
                    *(s32*)(self + 0x23c) = 2;
                } else if (u >= 0xa000 && u < 0xe000) {
                    *(s32*)(self + 0x23c) = 1;
                } else {
                    *(s32*)(self + 0x23c) = 3;
                }
            }
        }
        if (*(s32*)(self + 0x23c) != old) {
            *(s32*)(self + 0x26c) = lbl_80474320[*(s32*)(self + 0x23c) + *(s32*)(self + 0x238) * 4];
            *(s32*)(self + 0x25c) = *(s32*)((char*)lbl_80474450 + *(s32*)(self + 0x238) * 8);
        }
    }
    if (*(s32*)(self + 0x25c) == 0) {
        *(s32*)(self + 0x25c) = *(s32*)(self + 0x260);
        *(u32*)(self + 0x264) ^= 1;
    }
}

extern "C" void fn_80364F00(char* this_) {
    if (*(s32*)(this_ + 0x25c) != 0) {
        return;
    }
    *(s32*)(this_ + 0x268) += 1;
    if (*(char*)(*(char**)(this_ + 0x270) + *(s32*)(this_ + 0x268)) < 0) {
        *(s32*)(this_ + 0x268) = 0;
    }
    *(s32*)(this_ + 0x25c) = *(char*)(*(char**)(this_ + 0x270) + *(s32*)(this_ + 0x268));
    *(s32*)(this_ + 0x264) = *(char*)(*(char**)(this_ + 0x274) + *(s32*)(this_ + 0x268));
}

extern "C" f32 lbl_80542BCC;
extern "C" f32 lbl_80542BD0;
extern "C" f32 lbl_80542B0C;
extern "C" s32 fn_801CD664(s32 n);
extern "C" void fn_80364F60(char* this_) {
  if (*(s32*)(this_ + 0x238) != 5) {
    s32 prev = *(s32*)(this_ + 0x264);
    if (*(s32*)(this_ + 0x25c) == 0) {
      *(s32*)(this_ + 0x268) += 1;
      if (*(char*)(*(char**)(this_ + 0x270) + *(s32*)(this_ + 0x268)) < 0) {
        *(s32*)(this_ + 0x268) = 0;
      }
      *(s32*)(this_ + 0x25c) = *(char*)(*(char**)(this_ + 0x270) + *(s32*)(this_ + 0x268));
      *(s32*)(this_ + 0x264) = *(char*)(*(char**)(this_ + 0x274) + *(s32*)(this_ + 0x268));
    }
    s32 cur = *(s32*)(this_ + 0x264);
    if (prev != cur && *(s32*)(this_ + 0x238) >= 4 && *(s32*)(this_ + 0x238) <= 7 && cur == 0) {
      *(s32*)(this_ + 0x25c) += fn_801CD664(5) * 6;
    }
    if (*(s32*)(this_ + 0x238) == 0x1d || *(s32*)(this_ + 0x238) == 0x1e) {
      if (*(s32*)(this_ + 0x268) == 2) {
        if (*(s32*)(this_ + 0x25c) == 0xc) {
          *(f32*)(this_ + 0x44) = lbl_80542BCC;
        } else {
          *(f32*)(this_ + 0x44) = *(f32*)(this_ + 0x44) - lbl_80542BD0;
        }
        *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x14) + *(f32*)(this_ + 0x44);
      } else {
        f32 zero = lbl_80542B0C;
        *(f32*)(this_ + 0x14) = zero;
        *(f32*)(this_ + 0x44) = zero;
      }
    }
  }
}

extern "C" void* fn_8013CC50(u32 id, void* pos, f32 scale, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern f32 lbl_80542B10;
extern "C" void fn_8036509C(char* self) {
    if (*(s32*)(self + 0x248) != 0) {
        if (*(s32*)(self + 0x248) <= 0xe) {
            if (*(s32*)(self + 0x248) == 0xe) {
                char* p = *(char**)(self + 0x300);
                if (p != NULL) {
                    *(u32*)(p + 0xf4) |= 1;
                    *(s32*)(p + 0x24) = 1;
                    *(void**)(self + 0x300) = NULL;
                }
                *(s32*)(self + 0x258) = 0;
                *(s32*)(self + 0x264) = 0xb;
                fn_8013CC50(*(u32*)(self + 4), self + 0xc, 1.0f, 0x15b, 0, 1, 0, 0, 1);
                fn_8013CC50(*(u32*)(self + 4), self + 0xc, 1.0f, 0x15c, -1, 0, 0, 0, 1);
            } else if (*(s32*)(self + 0x248) == 0xa) {
                *(s32*)(self + 0x264) = 0xa;
            } else if (*(s32*)(self + 0x248) == 8) {
                *(s32*)(self + 0x264) = 9;
            } else if (*(s32*)(self + 0x248) == 6) {
                *(s32*)(self + 0x264) = 8;
            } else if (*(s32*)(self + 0x248) == 4) {
                *(s32*)(self + 0x264) = 2;
            } else if (*(s32*)(self + 0x248) == 2) {
                *(s32*)(self + 0x264) = 1;
            }
        }
        if (*(s32*)(self + 0x248) == 1) {
            *(s32*)(self + 0x25c) = fn_801CD664(9);
            *(s32*)(self + 0x264) = 0;
        }
    } else {
        if (*(s32*)(self + 0x25c) == 0) {
            *(s32*)(self + 0x25c) = 8;
            *(s32*)(self + 0x264) = *(s32*)(self + 0x264) + 1;
            if (*(s32*)(self + 0x264) >= 4) {
                *(s32*)(self + 0x264) = 0;
            }
        }
    }
}

extern "C" void fn_80365220(char* this_) {
    if (*(s32*)(this_ + 0x248) == 0) {
        *(s32*)(this_ + 0x248) = 0x40;
        *(s32*)(this_ + 0x238) += 1;
    }
    if (!(*(u32*)(this_ + 0x238) & 1)) {
        *(f32*)(this_ + 0x10) += lbl_80542BD4;
    } else {
        *(f32*)(this_ + 0x10) -= lbl_80542BD4;
    }
}

extern "C" const s32 lbl_80474BC4[];
extern "C" f32 lbl_80542BD8;
extern "C" void fn_80365274(char* this_) {
    ((JGeometry::TVec3<f32>*)(this_ + 0xc))->add(*(JGeometry::TVec3<f32>*)(this_ + 0x3c));
    s32 state = *(s32*)(this_ + 0x238);
    switch (state) {
    case 0:
    case 2:
        if (*(s32*)(this_ + 0x25c) == 0) {
            *(s32*)(this_ + 0x25c) = *(s32*)(this_ + 0x260);
            *(s32*)(this_ + 0x268) += 1;
            if (*(s32*)(this_ + 0x268) >= 4) {
                *(s32*)(this_ + 0x268) = 0;
            }
            *(s32*)(this_ + 0x264) = lbl_80474BC4[*(s32*)(this_ + 0x268)];
        }
        if (*(s32*)(this_ + 0x248) == 0) {
            *(s32*)(this_ + 0x248) = 0xc6;
            f32 zero = lbl_80542B0C;
            *(f32*)(this_ + 0x44) = zero;
            *(f32*)(this_ + 0x40) = zero;
            *(f32*)(this_ + 0x3c) = zero;
            *(s32*)(this_ + 0x26c) = 0x3ac;
            *(s32*)(this_ + 0x264) = 0;
            if (*(s32*)(this_ + 0x238) == 2) {
                *(u8*)(this_ + 0x11c) = 0;
            } else {
                *(s32*)(this_ + 0x238) = *(s32*)(this_ + 0x238) + 1;
            }
        }
        break;
    case 1: {
        s32 timer = *(s32*)(this_ + 0x248);
        if (timer == 0x8a) {
            *(s32*)(this_ + 0x26c) = 0x3a4;
        } else if (timer == 0x72) {
            *(s32*)(this_ + 0x26c) = 0x3a8;
        } else if (timer == 0x5a) {
            *(s32*)(this_ + 0x26c) = 0x3a4;
        } else if (timer == 0) {
            f32 x = lbl_80542B0C;
            f32 y = lbl_80542BD8;
            *(s32*)(this_ + 0x238) = state + 1;
            *(s32*)(this_ + 0x26c) = 0x3b1;
            *(s32*)(this_ + 0x264) = 0;
            JGeometry::TVec3<f32> v(x, y, x);
            *(JGeometry::TVec3<f32>*)(this_ + 0x3c) = v;
            *(s32*)(this_ + 0x248) = 0x64;
        }
        break;
    }
    }
}

extern "C" void fn_80365AB8(Unk80365AB8* self) {
    (self->*lbl_804ADDE8[*(s32*)((u8*)self + 0x234)])();
}

extern "C" void fn_80365AF0(Unk80365AB8* self) {
    if (*(s8*)((u8*)self + 0x230) == 0) {
        if (*(s32*)((u8*)self + 0x248) != 0) {
            *(s32*)((u8*)self + 0x248) -= 1;
        }
        if (*(s32*)((u8*)self + 0x25c) != 0) {
            *(s32*)((u8*)self + 0x25c) -= 1;
        }
        (self->*lbl_804ADC38[*(s32*)((u8*)self + 0x234)])();
    }
}

extern "C" char lbl_804ADF28[];
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void*);
extern "C" char __vt__4EETC[];
extern "C" void* fn_80366D44(void* this_, short how) {
    if (this_) {
        *(void**)this_ = __vt__4EETC;
        if (*(s32*)((char*)this_ + 0x234) == 3) {
            if (*(void**)((char*)this_ + 0x300)) {
                void* base = fn_8013C824();
                void* mgr = *(void**)((char*)base + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)((char*)this_ + 0x300));
                *(void**)((char*)this_ + 0x300) = 0;
            }
        }
        if (*(s32*)((char*)this_ + 0x234) == 0x10) {
            if (*(void**)((char*)this_ + 0x304)) {
                void* base = fn_8013C824();
                void* mgr = *(void**)((char*)base + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)((char*)this_ + 0x304));
                *(void**)((char*)this_ + 0x304) = 0;
            }
            if (*(void**)((char*)this_ + 0x308)) {
                void* base = fn_8013C824();
                void* mgr = *(void**)((char*)base + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)((char*)this_ + 0x308));
                *(void**)((char*)this_ + 0x308) = 0;
            }
            char* p = (char*)this_;
            int i = 0;
            do {
                if (*(void**)(p + 0x30c)) {
                    void* base = fn_8013C824();
                    void* mgr = *(void**)((char*)base + 0xc);
                    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(p + 0x30c));
                    *(void**)(p + 0x30c) = 0;
                }
                i++;
                p += 4;
            } while (i < 4);
        }
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

