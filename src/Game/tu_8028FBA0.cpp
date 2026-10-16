// Player-state methods, 0x8028FBA0-0x802957CC.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

#define U8(p, o) (*(u8*)((char*)(p) + (o)))
#define U32(p, o) (*(u32*)((char*)(p) + (o)))
#define S32(p, o) (*(s32*)((char*)(p) + (o)))
#define F32(p, o) (*(f32*)((char*)(p) + (o)))
#define PTR(p, o) (*(char**)((char*)(p) + (o)))
#define VEC(p, o) (*(JGeometry::TVec3<f32>*)((char*)(p) + (o)))

#pragma auto_inline off

class Actor;

extern "C" {
extern char* lbl_8053AAF8;
extern void* lbl_8053AF80;
extern const f32 lbl_805405A8;
extern const f32 lbl_805405B4;
extern const f32 lbl_80540600;
extern const f32 lbl_8054060C;
extern const f32 lbl_80540614;
extern const f32 lbl_80540618;
extern const f32 lbl_8054061C;
extern const f32 lbl_80540620;
extern const f32 lbl_80540644;
extern const f64 lbl_80540630;
extern const f64 lbl_80540638;

void* fn_8013CC50(s32, void*, s32, s32, s32, s32, void*, s32, f32);
void fn_801F349C(Actor*, u32, f32*);
Actor* fn_801F666C(void*, s32);
void* fn_801F856C(void);
void fn_80238244(s32);
BOOL fn_80240670(char*);
void fn_80241454(char*, u8);
int fn_80241E28(char*, s32, JGeometry::TVec3<f32>*);
BOOL fn_80240D64(char*);
void fn_80248604(char*);
s32 fn_8024189C(char*);
void fn_80248004(char*, s32, s32);
s32 fn_802486A0(const char*);
void fn_8024BAEC(char*);
s32 fn_8024EFA0(char*, u8);
void fn_8024F0E8(char*, s32);
bool fn_80251AEC(char*, s32);
int fn_8025F684(char*);
void fn_803037D4(s32, s32);
bool Player_IsLinked(char*);
bool fn_80290070(char*, s32, const JGeometry::TVec3<f32>*, const JGeometry::TVec3<f32>*, s32);
void* fn_802D6A9C(void);
void fn_80301D54(s32);
bool fn_80303750(s32);
bool fn_80301CD0(char*);
void fn_8030BD3C(void*, s32);
void fn_803037D4(s32, s32);
void fn_8045815C(void*, s32);

bool fn_8028FBA0(char* p) {
    JGeometry::TVec3<f32> position;
    position.x = F32(p, 0xcb0);
    position.y = F32(p, 0xcb4);
    position.z = F32(p, 0xcb8);
    if (U8(p, 0xcf2) == 0) {
        position.y -= lbl_805405A8;
    }
    if (fn_80290070(p, 0, &VEC(p, 0x8), &position, 5)) {
        U8(p, 0xbdc) = 0;
        return true;
    }
    return false;
}

void fn_80290D58(char* p) {
    if (!(u8)fn_80241E28(p, S32(p, 0xce0), &VEC(p, 0xcc8))) {
        VEC(p, 0xcbc) = VEC(p, 0x8);
        VEC(p, 0xd1c) = VEC(p, 0xcbc);
    }
    if (S32(p, 0xcf4) == 0x14 && S32(p, 0x3b4) >= 8) {
        S32(p, 0xbd8) = 0x258;
        U8(p, 0xbdc) = 1;
    }
    if ((u8)fn_80240D64(p)) {
        S32(p, 0x11f0) = 5;
    }
    U8(p, 0xce8) = 0;
    S32(p, 0xcf8) = S32(p, 0xcf4);
    S32(p, 0xcf4) = 0x29;
    S32(p, 0x468) = 0x3c;
    U8(p, 0xced) = 0;
    fn_80241454(p, 1);
    U8(p, 0x1216) = 0;
    fn_8024BAEC(p);
    fn_8030BD3C((void*)S32(p, 0xbec), S32(p, 0x4));
    if (fn_802486A0(p) != 4 && fn_802486A0(p) != 5) {
        fn_80248004(p, 5, 1);
    }
    fn_80248604(p);
    U8(p, 0xceb) = 0;
    U8(p, 0x400) = 0;
    U8(p, 0xcec) = 0;
}

void fn_80290E90(char* p) {
    if ((u8)fn_80240670(p) == 0) {
        fn_80301D54(S32(p, 0x4));
    }
    U8(p, 0x400) = 0;
    if (U8(lbl_8053AAF8, 0x7e) == 0 && (u8)fn_80240670(p) == 0) {
        if (S32(p, 0xce4) < 8) {
            fn_8045815C(lbl_8053AF80, 0);
        } else if (S32(p, 0xce4) == 8) {
            fn_8045815C(lbl_8053AF80, 1);
        }
    }
}

void fn_80290F20(char* p) {
    char* emitter = PTR(p, 0x132c);
    if (emitter != NULL) {
        U32(emitter, 0xf4) |= 1;
        U32(emitter, 0x24) = 1;
        PTR(p, 0x132c) = NULL;
    }
    emitter = PTR(p, 0x135c);
    if (emitter != NULL) {
        U32(emitter, 0xf4) |= 1;
        U32(emitter, 0x24) = 1;
        PTR(p, 0x135c) = NULL;
    }
    if (fn_802486A0(p) != 4 && Player_IsLinked(p)) {
        fn_80238244(S32(p, 0x4));
    }
}

void fn_8029185C(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    fn_8024F0E8(p, 0x10003);
    if (S32(p, 0xcf4) == 0xd) {
        fn_8024F0E8(p, 0x20067);
        U8(p, 0x3fc) = 0x28;
    } else if (S32(p, 0xcf4) == 0x26) {
        U8(p, 0x3fc) = 0x3a;
    }
    if (fn_802486A0(p) != 4 && fn_802486A0(p) != 5) {
        fn_80248004(p, 5, 1);
    }
    fn_8024BAEC(p);
}

void fn_80291B64(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    F32(p, 0x344) = lbl_805405B4;
    F32(p, 0x348) = lbl_805405B4;
    F32(p, 0x34c) = lbl_8054061C;
}

void fn_80291B8C(char* p) {
    U8(p, 0x3fc)++;
    if (U8(p, 0x3fc) >= 0x3c) {
        F32(p, 0x10) += lbl_8054061C;
        if (F32(p, 0x10) > lbl_80540620) {
            if (S32(p, 0x3b4) < 8) {
                VEC(p, 0xcb0) = VEC(p, 0x8);
            }
            U8(p, 0x124d) = 0;
            if (fn_80251AEC(p, 0x2b)) {
                fn_80241454(p, 0);
                S32(p, 0x3b4) = S32(p, 0xce4);
                VEC(p, 0x8) = VEC(p, 0xcd4);
                F32(p, 0x10) = lbl_805405B4;
                fn_8030BD3C(PTR(p, 0xbec), S32(p, 0x4));
            }
        }
    }
    s32 state = (U8(p, 0x3fc) >> 2) & 3;
    if (state == 0) {
        S32(p, 0x3dc) = 2;
        S32(p, 0x3e8) = 2;
    } else if (state == 1) {
        S32(p, 0x3dc) = 1;
        S32(p, 0x3e8) = 1;
    } else if (state == 2) {
        S32(p, 0x3dc) = 3;
        S32(p, 0x3e8) = 3;
    } else {
        S32(p, 0x3dc) = 0;
        S32(p, 0x3e8) = 0;
    }
}

void fn_80291CB8(char* p) {
    U8(p, 0x124d) = 1;
    F32(p, 0x10) = lbl_805405B4;
    U8(p, 0x458) = 0;
    fn_8024F0E8(p, 0x2002e);
    if (S32(p, 0x3b4) >= 8 && S32(p, 0xce4) < 8) {
        fn_8024EFA0(p, 0);
    }
}

void fn_80291D28(char* p) {
    if (!fn_80301CD0(PTR(p, 0x4))) {
        if (S32(p, 0xce4) < 8) {
            if (S32(p, 0x430) > 0) {
                S32(p, 0x430) = S32(p, 0x430) - 1;
            }
            U8(p, 0x3fb) = 3;
            if (S32(p, 0x430) <= 0x5a) {
                if (S32(p, 0x430) == 0x5a) {
                    fn_80241454(p, 1);
                } else if (S32(p, 0x430) > 0x54) {
                    U8(p, 0x3f9) = (0x5a - S32(p, 0x430)) / 2;
                } else {
                    U8(p, 0x3f9) = ((0x54 - S32(p, 0x430)) / 6 & 3) + 3;
                }
            }
            if (S32(p, 0x430) == 0) {
                U8(p, 0x124d) = 0;
                S32(p, 0x44c) = 5;
                fn_80251AEC(p, 0x4a);
            }
        } else if (U8(p, 0x3f8) < 0x3c) {
            U8(p, 0x3f8)++;
        } else {
            U8(p, 0x124d) = 0;
            fn_80251AEC(p, 0);
        }
    }
}

void fn_80291E44(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    U8(p, 0x3f9) = 0;
    S32(p, 0x3dc) = 2;
    S32(p, 0x3e8) = 2;
    if (S32(p, 0xce4) < 8) {
        fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x15b, 0, 1, 0, NULL, 1, lbl_80540600);
        fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x15c, -1, 0, 0, NULL, 1, lbl_80540600);
        fn_8024F0E8(p, 0x20041);
        fn_8024F0E8(p, 0x1000f);
        S32(p, 0x430) = 0x5c;
    }
}

void fn_80292124(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    S32(p, 0x3dc) = 3;
    S32(p, 0x3e8) = 3;
    if ((u8)fn_80240670(p) == 0 && S32(p, 0x3b4) >= 8 && S32(p, 0xce4) < 8) {
        fn_8024EFA0(p, 0);
    }
}

void fn_80292198(char* p) {
  U8(p, 0x3f8) = U8(p, 0x3f8) + 1;
  if (U8(p, 0x3f8) >= 0x18) {
    U8(p, 0x3f8) = 0;
  }
  U8(p, 0x3f9) = U8(p, 0x3f8) / 6;
  if (U8(p, 0x3fc) == 2) {
    fn_80241454(p, 1);
  }
  if (U8(p, 0x3fc) < 0x3c) {
    U8(p, 0x3fc) = U8(p, 0x3fc) + 1;
  }
  if (S32(p, 0xce4) != S32(p, 0xce0) && (u8)fn_80240670(p) == 0 && fn_80303750(S32(p, 0x4))) {
    return;
  }
  if (U8(p, 0x3fc) >= 0x3c) {
    if (U8(p, 0x3fb) == 0) {
      if (U8(p, 0x400) != 0) {
        U8(p, 0x400) = U8(p, 0x400) - 1;
      } else {
        U8(p, 0x124d) = 0;
        if (fn_80251AEC(p, 0x4a) && S32(p, 0xce4) >= 8) {
          fn_803037D4(S32(p, 0x4), 0xd);
        }
      }
    } else {
      U8(p, 0x3fb) = 0;
      U8(p, 0x400) = 8;
    }
  }
}

void fn_802922D0(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    U8(p, 0x3fb) = 1;
    U8(p, 0x3f9) = 0;
}

void fn_802922EC(char* p) {
  U8(p, 0x3f8) = U8(p, 0x3f8) + 1;
  if (U8(p, 0x3f8) < 0x7) {
    U8(p, 0x3f9) = 4;
  } else if (U8(p, 0x3f8) < 0xd) {
    U8(p, 0x3f9) = 5;
  } else if (U8(p, 0x3f8) < 0x13) {
    U8(p, 0x3f9) = 6;
  } else if (U8(p, 0x3f8) < 0x22) {
    U8(p, 0x3f9) = 7;
  } else if (U8(p, 0x3f8) < 0x28) {
    U8(p, 0x3f9) = 4;
  } else if (U8(p, 0x3f8) < 0x2e) {
    U8(p, 0x3f9) = 5;
  } else if (U8(p, 0x3f8) < 0x34) {
    U8(p, 0x3f9) = 6;
  } else if (U8(p, 0x3f8) < 0x43) {
    U8(p, 0x3f9) = 7;
  }
  if (U8(p, 0x3f8) < 0x43) {
    F32(p, 0xc) = F32(p, 0xc) - lbl_80540630;
  } else {
    U8(p, 0x124d) = 0;
    if (fn_80251AEC(p, 0x29)) {
      fn_80241454(p, 0);
      if (S32(p, 0x3b4) < 8) {
        VEC(p, 0xcb0) = VEC(p, 0x8);
        F32(p, 0xcb8) = F32(p, 0x10);
        S32(p, 0x3b4) = S32(p, 0xce4);
        VEC(p, 0x8) = VEC(p, 0xcd4);
        F32(p, 0x10) = F32(p, 0xcdc);
      }
      fn_8030BD3C(PTR(p, 0xbec), S32(p, 0x4));
    }
  }
}

void fn_80292454(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    S32(p, 0x3dc) = 3;
    S32(p, 0x3e8) = 3;
    if (S32(p, 0x3b4) >= 8 && S32(p, 0xce4) < 8) {
        fn_8024EFA0(p, 0);
    }
}

void fn_802924AC(char* p) {
    U8(p, 0x3f8)++;
    if (U8(p, 0x3f8) >= 0x18) {
        U8(p, 0x3f8) = 0;
    }
    U8(p, 0x3f9) = U8(p, 0x3f8) / 6;
    if (U8(p, 0x3fc) < 0x3c) {
        U8(p, 0x3fc)++;
    }
    if ((S32(p, 0xce4) == S32(p, 0xce0) || (u8)fn_80240670(p) || !(u8)fn_80303750(S32(p, 0x4))) && U8(p, 0x3fc) >= 0x3c) {
        if (U8(p, 0x3fc) >= 0x5c) {
            U8(p, 0x124d) = 0;
            if ((u8)fn_80251AEC(p, 0x4b)) {
                if (S32(p, 0xce4) >= 8) {
                    fn_803037D4(S32(p, 0x4), 0xd);
                }
                return;
            }
        } else {
            F32(p, 0xc) = F32(p, 0xc) + lbl_80540638;
            U8(p, 0x3fc)++;
        }
    }
}

void fn_802925C4(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    S32(p, 0x3dc) = 2;
    S32(p, 0x3e8) = 2;
}

void fn_802927B0(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    U8(p, 0x3fb) = 0;
    fn_8024F0E8(p, 0x20060);
    fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x547, -1, 0, 0, NULL, 1, lbl_80540600);
}

void fn_80292820(char* p) {
    if (U8(p, 0x3fc) < 0x3c) {
        U8(p, 0x3fc)++;
    }
    if (S32(p, 0xce4) == S32(p, 0xce0) || fn_80240670(p) || !fn_80303750(S32(p, 0x4))) {
        if (U8(p, 0x3fc) >= 0x3c) {
            U8(p, 0x124d) = 0;
            bool r;
            if (fn_8024189C(p) <= 0) {
                r = fn_80251AEC(p, 0x33);
            } else if (U8(p, 0xcf0) == 1) {
                r = fn_80251AEC(p, 0x3e);
            } else if (fn_8025F684(p)) {
                r = fn_80251AEC(p, 0x12);
            } else {
                r = fn_80251AEC(p, 0);
            }
            if (r) {
                fn_803037D4(S32(p, 0x4), 0xd);
            }
        }
    }
    F32(p, 0x2f4) = F32(p, 0x8);
    F32(p, 0x2f8) = F32(p, 0xc);
    F32(p, 0x2fc) = F32(p, 0x10);
    F32(p, 0x2fc) += lbl_805405A8;
}

void fn_80292944(char* p) {
    fn_80241454(p, 1);
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    F32(p, 0x2f4) = F32(p, 0x8);
    F32(p, 0x2f8) = F32(p, 0xc);
    F32(p, 0x2fc) = F32(p, 0x10);
    F32(p, 0x2fc) += lbl_805405A8;
    if ((u8)fn_8025F684(p)) {
        s32 actorId = S32(p, 0xd68);
        if (actorId >= 0) {
            Actor* actor = fn_801F666C(fn_801F856C(), actorId);
            fn_802D6A9C();
            if (actor != NULL) {
                fn_801F349C(actor, U32(p, 0x3b4), (f32*)(p + 0x2f4));
            }
        }
    }
}

void fn_80292E90(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    U8(p, 0x3fd) = 1;
    fn_8024F0E8(p, 0x2000c);
}

void fn_802932BC(char* p) {
    U8(p, 0x124d) = 1;
    F32(p, 0x10) = lbl_805405B4;
    U8(p, 0x458) = 0;
    F32(p, 0x344) = lbl_805405B4;
    F32(p, 0x348) = lbl_80540644;
    F32(p, 0x34c) = lbl_8054061C;
    F32(p, 0x2f4) = F32(p, 0x8);
    F32(p, 0x2f8) = F32(p, 0xc);
    F32(p, 0x2fc) = F32(p, 0x10);
    F32(p, 0x2fc) += lbl_805405A8;
    if ((u8)fn_8025F684(p)) {
        s32 actorId = S32(p, 0xd68);
        if (actorId >= 0) {
            Actor* actor = fn_801F666C(fn_801F856C(), actorId);
            fn_802D6A9C();
            if (actor != NULL) {
                fn_801F349C(actor, U32(p, 0x3b4), (f32*)(p + 0x2f4));
            }
        }
    }
    if (S32(p, 0xcf4) == 0x1f) {
        U8(p, 0x3fc) = 0x32;
    }
}

void fn_80293534(char* p) {
    U8(p, 0x124d) = 1;
    F32(p, 0x10) = lbl_805405B4;
    U8(p, 0x458) = 0;
    fn_8024F0E8(p, 0x2002e);
    if (S32(p, 0x3b4) >= 8 && S32(p, 0xce4) < 8) {
        fn_8024EFA0(p, 0);
    }
}

void fn_80293760(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
}

void fn_80293774(char* p) {
    if (U8(p, 0x3fc) == 0x3c) {
        if (S32(p, 0xcf4) != 0x1d) {
            if (S32(p, 0x3b4) < 8) {
                JGeometry::TVec3<f32> pos;
                pos.x = F32(p, 0x8);
                pos.y = F32(p, 0xc) + lbl_80540614;
                pos.z = F32(p, 0x10) + lbl_805405A8;
                fn_8013CC50(S32(p, 0x3b4), &pos, 0x17d, 1, 0, 0, NULL, 1, lbl_80540600);
            } else if (S32(p, 0xce4) < 8) {
                fn_8024EFA0(p, 0);
            }
        }
        U8(p, 0x3fd) = 0;
    } else if (U8(p, 0x3fc) >= 0x76) {
        if (S32(p, 0x3b4) < 8) {
            VEC(p, 0xcb0) = VEC(p, 0x8);
        }
        U8(p, 0x124d) = 0;
        if (fn_80251AEC(p, 0x21)) {
            fn_80241454(p, 0);
            S32(p, 0x3b4) = S32(p, 0xce4);
            VEC(p, 0x8) = VEC(p, 0xcd4);
            F32(p, 0x10) = lbl_805405B4;
            fn_8030BD3C(PTR(p, 0xbec), S32(p, 0x4));
        }
    }
    U8(p, 0x3fc)++;
}

void fn_802938B8(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    U8(p, 0x3fd) = 1;
    if (S32(p, 0xcf4) != 0x1d) {
        fn_8024F0E8(p, 0x2000c);
    }
}

void fn_80293B1C(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
}

void fn_80293E8C(char* p) {
    U8(p, 0x124d) = 1;
    F32(p, 0x10) = lbl_805405B4;
    U8(p, 0x458) = 0;
    fn_8024F0E8(p, 0x10003);
    fn_8024F0E8(p, 0x2002d);
    s32 cur = S32(p, 0x3b4);
    if (cur > 8 && S32(p, 0xce4) > 8) {
        if (((char*)fn_802D6A9C() + 0x10000)[cur + 0x31df] != 0) {
            s32 other = S32(p, 0xce4);
            if (((char*)fn_802D6A9C() + 0x10000)[other + 0x31df] != 0 && S32(p, 0xce4) != S32(p, 0x3b4)) {
                U8(p, 0x3fc) = 0x3a;
            }
        }
    }
    F32(p, 0x2f4) = F32(p, 0x8);
    F32(p, 0x2f8) = F32(p, 0xc);
    F32(p, 0x2fc) = F32(p, 0x10);
    F32(p, 0x2fc) += lbl_805405A8;
    if (S32(p, 0xcf4) == 0x24 && S32(p, 0x3b4) >= 8 && S32(p, 0xce4) < 8) {
        fn_8024EFA0(p, 0);
    }
    if (fn_802486A0(p) != 4) {
        if (fn_802486A0(p) != 5) {
            fn_80248004(p, 5, 1);
        }
        fn_8024BAEC(p);
    }
}

void fn_8029513C(char* p) {
    if (U8(p, 0x3fc) < 0x3c) {
        U8(p, 0x3fc)++;
        return;
    }
    fn_80241454(p, 1);
    if (S32(p, 0xce4) != S32(p, 0xce0) && (u8)fn_80240670(p) == 0 &&
        fn_80303750(S32(p, 0x4))) {
        return;
    }
    F32(p, 0x34c) -= lbl_8054060C;
    if (F32(p, 0x34c) < lbl_80540618) {
        F32(p, 0x34c) = lbl_80540618;
    }
    VEC(p, 0x8).add(VEC(p, 0x344));
    if (F32(p, 0x10) < lbl_805405B4) {
        F32(p, 0x10) = lbl_805405B4;
        U8(p, 0x124d) = 0;
        if (fn_8024189C(p) <= 0) {
            fn_80251AEC(p, 0x33);
        } else {
            fn_80251AEC(p, 0);
        }
    }
}

void fn_80295240(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    F32(p, 0x344) = lbl_805405B4;
    F32(p, 0x348) = lbl_80540644;
    F32(p, 0x34c) = lbl_805405B4;
}

void fn_80295268(char* p) {
    U8(p, 0x3fc)++;
    if (U8(p, 0x3fc) >= 0xa) {
        F32(p, 0x10) += lbl_8054061C;
        if (F32(p, 0x10) > lbl_80540620) {
            if (S32(p, 0x3b4) < 8) {
                JGeometry::setTVec3f((f32*)(p + 0x8), (f32*)(p + 0xcb0));
            }
            U8(p, 0x124d) = 0;
            if (fn_80251AEC(p, 0x2f)) {
                fn_80241454(p, 0);
                S32(p, 0x3b4) = S32(p, 0xce4);
                JGeometry::setTVec3f((f32*)(p + 0xcd4), (f32*)(p + 0x8));
                fn_8030BD3C(PTR(p, 0xbec), S32(p, 0x4));
            }
        }
    }
}

void fn_80295334(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    if (S32(p, 0x3b4) >= 8 && S32(p, 0xce4) < 8) {
        fn_8024EFA0(p, 0);
    }
    S32(p, 0x3dc) = 2;
    S32(p, 0x3e8) = 2;
    F32(p, 0x10) = lbl_805405B4;
}

void fn_803037D4(s32, s32);
void fn_802953A0(char* p) {
    if (U8(p, 0x3fc) < 0x3c) {
        U8(p, 0x3fc)++;
        return;
    }
    if (S32(p, 0xce4) != S32(p, 0xce0) && (u8)fn_80240670(p) == 0 && fn_80303750(S32(p, 0x4))) {
        return;
    }
    if (U8(p, 0x3fc) < 0x3c) {
        return;
    }
    F32(p, 0x34c) = F32(p, 0x34c) - lbl_8054060C;
    if (F32(p, 0x34c) < lbl_80540618) {
        F32(p, 0x34c) = lbl_80540618;
    }
    VEC(p, 0x8) += VEC(p, 0x344);
    if (F32(p, 0x10) < lbl_805405B4) {
        F32(p, 0x10) = lbl_805405B4;
    }
    U8(p, 0x124d) = 0;
    bool r;
    if (fn_8024189C(p) <= 0) {
        r = fn_80251AEC(p, 0x33);
    } else {
        r = fn_80251AEC(p, 0);
    }
    if (r) {
        fn_803037D4(S32(p, 0x4), 0xd);
    }
}

void fn_802954B8(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    F32(p, 0x344) = lbl_805405B4;
    F32(p, 0x348) = lbl_805405B4;
    F32(p, 0x34c) = lbl_805405B4;
}

void fn_802954DC(char* p) {
    if (U8(p, 0x3fc) >= 0x3c) {
        U8(p, 0x124d) = 0;
        if (fn_80251AEC(p, 0x2d)) {
            if (S32(p, 0x3b4) < 8) {
                JGeometry::setTVec3f((f32*)(p + 0x8), (f32*)(p + 0xcb0));
            }
            S32(p, 0x3b4) = S32(p, 0xce4);
            JGeometry::setTVec3f((f32*)(p + 0xcd4), (f32*)(p + 0x8));
            F32(p, 0x10) = lbl_80540620;
            fn_8030BD3C(PTR(p, 0xbec), S32(p, 0x4));
        }
    } else {
        U8(p, 0x3fc)++;
    }
}

void fn_80295584(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    U8(p, 0x3fd) = 1;
    S32(p, 0x3dc) = 2;
    S32(p, 0x3e8) = 2;
}
}
