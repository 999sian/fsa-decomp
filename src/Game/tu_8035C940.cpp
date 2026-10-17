#include "JSystem/JMath/JMath.h"
#include "dolphin/mtx.h"
#include "JSystem/JGeometry.h"
#include "Game/ItemBase.h"

struct JMathSinCos { f32 sin; f32 cos; };
extern "C" const JMathSinCos sincosTable___5JMath[];
extern const u32 lbl_80472718[];
extern const s16 lbl_80472748[];
extern const f32 lbl_80542930;
extern const f32 lbl_80542940;
extern const f32 lbl_80542944;
extern const f32 lbl_80542950;
extern const f32 lbl_80542954;
extern const f32 lbl_80542980;
extern const f32 lbl_80542984;
extern const f32 lbl_80542970;
extern const f32 lbl_80542974;
extern const f32 lbl_80542978;
extern const f32 lbl_8054297C;
extern "C" void fn_801F06F0(void* this_, const void* anim, f32 a, f32 b, s32 frame, DrawRec* rec, s32 flag);
extern "C" void fn_801EF830(s32 room, void* pos, DrawRec* rec, s32 mask, const void* anim, s32 frame, s32 e);

struct Unk8035CD00 {
    u8 pad0[0x14];
    f32 m14;
    u8 pad18[0x258 - 0x18];
f32 m258;
f32 m25C;
    s16 m260;
    u8 pad262[2];
    f32 m264;
    f32 m268;
    u8 pad26c[4];
    s16 m270;
};

extern "C" void fn_8013CB44(void* a, void* b, s32 c, s32 d, s32 e);
extern "C" u8 fn_8035C15C(char* p, s32 x);
extern "C" void fn_8035C1C4(char* p, s32 x, u32 y);
extern "C" void* fn_801F856C(void);
extern "C" char* fn_801F666C(void* a, u32 b);
extern const u32 lbl_80472730[];
extern const f32 lbl_80542910;
extern const f32 lbl_80542914;
extern const f32 lbl_80542918;
extern const f32 lbl_8054291C;
extern const f32 lbl_80542920;
extern const f32 lbl_80542924;
extern const f32 lbl_80542928;
extern const f32 lbl_8054292C;
extern "C" void fn_8035C940(char* p) {
    if (*(u32*)(p + 0x274) != 0) {
        fn_8013CB44(*(void**)(p + 0x274), p + 0xc, -1, -1, 1);
    }
    if (*(u32*)(p + 0x278) != 0) {
        fn_8013CB44(*(void**)(p + 0x278), p + 0xc, -1, -1, 1);
    }
    if (fn_8035C15C(p, 10) == 1) {
        fn_8035C1C4(p, 10, lbl_80472730[*(u32*)(p + 0x90) & 7]);
    }
    if (*(s32*)(p + 0x234) == 0) {
        *(f32*)(p + 0x14) = *(f32*)(p + 0x14) + lbl_80542910;
        if (*(f32*)(p + 0x14) >= lbl_80542914) {
            if ((*(u32*)(p + 0x90) & 7) == 0) {
                char* b = fn_801F666C(fn_801F856C(), *(u32*)(p + 0x23c));
                if (b != 0) {
                    *(s32*)(b + 0x230) = 5;
                    if (*(s32*)(b + 0x230) == 5) {
                        *(f32*)(b + 0x258) = (lbl_80542918 - *(f32*)(b + 0x240)) / lbl_8054291C;
                        *(f32*)(b + 0x25c) = (*(f32*)(b + 0x254) - lbl_80542920) / lbl_8054291C;
                    } else {
                        *(f32*)(b + 0x258) = (lbl_80542924 - *(f32*)(b + 0x240)) / lbl_80542928;
                        *(f32*)(b + 0x25c) = (*(f32*)(b + 0x254) - lbl_8054292C) / lbl_80542928;
                    }
                }
            }
            if (*(u32*)(p + 0x274) != 0) {
                char* q = *(char**)(p + 0x274);
                *(u32*)(q + 0xf4) |= 1;
                *(s32*)(q + 0x24) = 1;
                *(s32*)(p + 0x274) = 0;
            }
            if (*(u32*)(p + 0x278) != 0) {
                char* q = *(char**)(p + 0x278);
                *(u32*)(q + 0xf4) |= 1;
                *(s32*)(q + 0x24) = 1;
                *(s32*)(p + 0x278) = 0;
            }
            *(u8*)(p + 0x11c) = 0;
        }
    }
}

extern const f32 lbl_80542934;
extern const u32 lbl_804727A4[];
f32 JMAFastVECMag(const Vec* v);
extern "C" void fn_8035CAF8(char* p)
{
    if (*(u32*)(p + 0x274) != 0) {
        fn_8013CB44(*(void**)(p + 0x274), p + 0xc, -1, -1, 1);
    }
    if (*(u32*)(p + 0x278) != 0) {
        fn_8013CB44(*(void**)(p + 0x278), p + 0xc, -1, -1, 1);
    }
    if (fn_8035C15C(p, 10) == 1) {
        Unk8035CD00* q = (Unk8035CD00*)p;
        fn_8035C1C4(p, 10, lbl_80472730[*(u32*)(p + 0x90) & 7]);
        s16 ang = q->m260;
        f32 z = q->m14;
        f32 y = q->m25C * sincosTable___5JMath[(u16)ang >> 5].sin + q->m268;
        f32 x = q->m258 * sincosTable___5JMath[(u16)ang >> 5].cos + q->m264;
        JGeometry::TVec3<f32> pos(x, y, z);
        JGeometry::TVec3<f32> cur = pos;
        Vec v;
        v.x = cur.x - *(f32*)(p + 0xc);
        v.y = cur.y - *(f32*)(p + 0x10);
        v.z = lbl_80542930;
        f32 mag = JMAFastVECMag(&v);
        *(f32*)(p + 0xc) = *(f32*)(p + 0xc) + v.x * *(f32*)(p + 0x254) / mag;
        *(f32*)(p + 0x10) = *(f32*)(p + 0x10) + v.y * *(f32*)(p + 0x254) / mag;
        if (fabs(*(f32*)(p + 0xc) - pos.x) + fabs(*(f32*)(p + 0x10) - pos.y) < lbl_80542934) {
            *(f32*)(p + 0x254) = lbl_80542930;
            *(f32*)(p + 0xc) = pos.x;
            *(f32*)(p + 0x10) = pos.y;
            *(s32*)(p + 0x234) = lbl_804727A4[*(u32*)(p + 0x90) & 7] + 0x50;
            *(s32*)(p + 0x230) = 5;
        }
    }
}

extern "C" Vec fn_8035CD00(Unk8035CD00* p) {
    s16 old = p->m260;
    p->m260 += 0x400;
    Vec pos;
    pos.x = 25.0f * JMACosShort(p->m260) + (0.0f + p->m264);
    pos.y = 25.0f * JMASinShort(p->m260) + (25.0f + (p->m268 - p->m25C));
    pos.z = p->m14;
    Vec ret = pos;
    if ((u16)p->m260 >= 0xC000 && (u16)old < 0xC000) {
        if (p->m270 < 0) {
            p->m270 = -0x4000;
        } else {
            p->m270 = -0x8000;
        }
    }
    return ret;
}

extern const f32 lbl_80542938;
extern const f32 lbl_8054293C;
extern "C" JGeometry::TVec3<f32> fn_8035CDC0(char* p) {
    s16 old = *(s16*)(p + 0x260);
    *(s16*)(p + 0x260) = old + 0x400;
    s16 ang = *(s16*)(p + 0x260);
    f32 z = *(f32*)(p + 0x14);
    JGeometry::TVec3<f32> v(lbl_80542938 * JMath::sincosTable_.mTable[(u16)ang >> 5].second + (*(f32*)(p + 0x264) - lbl_8054293C),
        lbl_80542938 * JMath::sincosTable_.mTable[(u16)ang >> 5].first + (*(f32*)(p + 0x268) + *(f32*)(p + 0x25c) - lbl_80542938),
        z);
    if (ang >= 0x4000 && old < 0x4000) {
        if (*(s16*)(p + 0x270) < 0) {
            *(s16*)(p + 0x270) = -0x4000;
        } else {
            *(s16*)(p + 0x270) = -0x8000;
        }
    }
    return v;
}

extern "C" JGeometry::TVec3<f32> fn_8035CE78(Unk8035CD00* p) {
    if (p->m25C > lbl_80542940) {
        p->m25C -= lbl_80542944;
    }
    s16 old = p->m260;
    p->m260 += 0x140;
    JGeometry::TVec3<f32> pos;
    pos.z = p->m14;
    pos.y = p->m25C * JMath::sincosTable_.mTable[(u16)p->m260 >> 5].first + p->m268;
    pos.x = p->m258 * JMath::sincosTable_.mTable[(u16)p->m260 >> 5].second + p->m264;
    JGeometry::TVec3<f32> ret = pos;
    if (p->m260 >= 0x4000 && old < 0x4000) {
        p->m270 |= 1;
    } else if ((u16)p->m260 >= 0xC000 && (u16)old < 0xC000) {
        p->m270 |= 2;
    }
    return ret;
}

typedef Vec (Unk8035CD00::*Unk8035CD00Func)();
extern Unk8035CD00Func lbl_804AD594[];
extern const f32 lbl_80542948;
extern const f32 lbl_8054294C;
extern const f32 lbl_80542958;
extern const f32 lbl_8054295C;
extern const f32 lbl_80542960;
extern const f32 lbl_80542964;
extern const s16 lbl_80472798[];
extern "C" void fn_8035CF50(Unk8035CD00* self) {
    char* p = (char*)self;
    Vec d;
    Vec v;
    Vec w;
    f32 mag;
    s16 prev;

    if (*(f32*)(p + 0x10) < lbl_80542948) {
        f32 diff = *(f32*)(p + 0x10) - *(f32*)(p + 0x14);
        if (diff < lbl_8054294C) {
            *(s8*)(p + 0x272) = -2;
        } else if (diff < lbl_80542924) {
            *(s8*)(p + 0x272) = -1;
        } else {
            *(s8*)(p + 0x272) = 0;
        }
    } else {
        *(s8*)(p + 0x272) = 0;
    }
    if (*(u32*)(p + 0x274) != 0) {
        fn_8013CB44(*(void**)(p + 0x274), p + 0xc, -1, -1, 1);
    }
    if (*(u32*)(p + 0x278) != 0) {
        fn_8013CB44(*(void**)(p + 0x278), p + 0xc, -1, -1, 1);
    }
    if (fn_8035C15C(p, 10) == 1) {
        fn_8035C1C4(p, 10, lbl_80472730[*(u32*)(p + 0x90) & 7]);
    }
    if ((*(s16*)(p + 0x270) & 0xc000) == 0xc000) {
        if (*(f32*)(p + 0x268) < lbl_80542950) {
            *(f32*)(p + 0x268) = *(f32*)(p + 0x268) + lbl_80542954;
        }
    } else {
        if (*(f32*)(p + 0x254) < lbl_80542958) {
            *(f32*)(p + 0x254) = *(f32*)(p + 0x254) + lbl_8054295C;
        }
        if (*(f32*)(p + 0x268) > lbl_80542960) {
            *(f32*)(p + 0x268) = *(f32*)(p + 0x268) - lbl_80542964;
        }
    }
    prev = *(s16*)(p + 0x260);
    w = (self->*lbl_804AD594[*(s16*)(p + 0x270) & 3])();
    v = w;
    d.x = v.x - *(f32*)(p + 0xc);
    d.y = v.y - *(f32*)(p + 0x10);
    d.z = lbl_80542930;
    mag = JMAFastVECMag(&d);
    *(f32*)(p + 0xc) = *(f32*)(p + 0xc) + d.x * *(f32*)(p + 0x254) / mag;
    *(f32*)(p + 0x10) = *(f32*)(p + 0x10) + d.y * *(f32*)(p + 0x254) / mag;
    if ((*(s16*)(p + 0x270) & 0xc000) == 0xc000) {
        s16 tbl = lbl_80472798[*(u32*)(p + 0x90) & 7];
        if ((u16)*(s16*)(p + 0x260) >= (u16)tbl && (u16)prev < (u16)tbl) {
            *(s32*)(p + 0x230) = 4;
            *(s16*)(p + 0x260) = lbl_80472798[*(u32*)(p + 0x90) & 7];
            *(s8*)(p + 0x272) = 0;
        }
    }
}

extern "C" u8 fn_8035C15C(char* p, s32 id);
extern "C" void fn_8035C1C4(char* p, s32 id, u32 arg);
extern "C" u32 fn_801CD664(s32 id);
extern const u32 lbl_80472780[];
extern "C" void fn_8035D4B8(char* p) {
    s32 state = *(s32*)(p + 0x238);
    if (state == 0) {
        if (fn_8035C15C(p, 7) == 1) {
            fn_8035C1C4(p, 7, lbl_80472718[*(u32*)(p + 0x90) & 7]);
        }
    } else if (state == 1) {
        if (fn_8035C15C(p, 9) == 1) {
            *(s32*)(p + 0x24c) = 0;
            *(s32*)(p + 0x238) = 2;
        }
    } else if (state == 2) {
        if (fn_8035C15C(p, 8) == 1) {
            fn_8035C1C4(p, 8, lbl_80472718[*(u32*)(p + 0x90) & 7]);
        }
    } else if (state == 3) {
        s32 t = *(s32*)(p + 0x248);
        if (t < 0x14) {
            *(s32*)(p + 0x248) = 0x14;
            *(s32*)(p + 0x244) = 9;
        } else if (*(s32*)(p + 0x244) == 0) {
            if (t == 0x14) {
                *(s32*)(p + 0x248) = 0x18;
                *(s32*)(p + 0x244) = 0x3c;
            } else if (t == 0x18) {
                *(s32*)(p + 0x248) = 0x19;
                *(s32*)(p + 0x244) = 3;
            } else {
                *(s32*)(p + 0x248) = 8;
                *(s32*)(p + 0x24c) = 0;
                *(s32*)(p + 0x230) = 2;
                *(u32*)(p + 0x234) = lbl_80472780[*(u32*)(p + 0x90) & 7] + 0x128;
                *(s32*)(p + 0x238) = 0;
            }
        }
    } else if (state == 4) {
        s32 timer = *(s32*)(p + 0x244);
        if (timer == 0) {
            *(u32*)(p + 0x24c) = fn_801CD664(6);
            fn_8035C1C4(p, 7, lbl_80472718[*(u32*)(p + 0x90) & 7]);
            *(u32*)(p + 0x244) = fn_801CD664(4);
            *(s32*)(p + 0x238) = 0;
        } else if (timer == 0x28) {
            *(s32*)(p + 0x248) = 0xa;
        } else if (timer == 0xa) {
            *(s32*)(p + 0x248) = 0xb;
        }
    }
}

extern "C" void fn_8035D6C4(char* p) {
    if (*(int*)(p + 0x238) == 0) return;
    *(int*)(p + 0x234) = 0x400;
    *(int*)(p + 0x230) = 1;
    *(int*)(p + 0x244) = 0x38;
    *(int*)(p + 0x238) = 4;
}

extern void* lbl_804AD5B8[];
extern void* lbl_804A5958[];
extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
void operator delete(void* p);
extern "C" void* fn_8035D6F4(u8* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AD5B8;
        if (*(u8**)(this_ + 0x274) != 0) {
            u8* p = *(u8**)(this_ + 0x274);
            *(u32*)(p + 0xf4) |= 1;
            *(s32*)(p + 0x24) = 1;
            *(void**)(this_ + 0x274) = 0;
        }
        if (*(u8**)(this_ + 0x278) != 0) {
            u8* p = *(u8**)(this_ + 0x278);
            *(u32*)(p + 0xf4) |= 1;
            *(s32*)(p + 0x24) = 1;
            *(void**)(this_ + 0x278) = 0;
        }
        if (this_ != 0) {
            *(void**)this_ = lbl_804A5958;
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

struct Unk8035DA78;
typedef void (Unk8035DA78::*Unk8035DA78Func)();
extern Unk8035DA78Func lbl_804AD528[];
extern "C" void fn_8035DA78(Unk8035DA78* self) {
    char* p = (char*)self;
    if (*(int*)(p + 0x234) != 0) *(int*)(p + 0x234) -= 1;
    if (*(int*)(p + 0x244) != 0) *(int*)(p + 0x244) -= 1;
    (self->*lbl_804AD528[*(int*)(p + 0x230)])();
}

extern "C" void fn_8035DAD8(char* p) {
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 8;
    *(s32*)(p + 0x24c) = 0;
    *(u32*)(p + 0x250) = lbl_80472718[*(u32*)(p + 0x90) & 7];
    *(f32*)(p + 0x254) = lbl_80542954;
    *(f32*)(p + 0x258) = lbl_80542980;
    *(f32*)(p + 0x25c) = lbl_80542940;
    *(s16*)(p + 0x260) = lbl_80472748[*(u32*)(p + 0x90) & 7];
    *(f32*)(p + 0x264) = lbl_80542984;
    *(f32*)(p + 0x268) = lbl_80542950;
    *(f32*)(p + 0x26c) = lbl_80542930;
    *(s16*)(p + 0x270) = 0;
    *(u8*)(p + 0x272) = 0;
    *(f32*)(p + 0xc) = *(f32*)(p + 0x258) * JMACosShort(*(s16*)(p + 0x260)) + *(f32*)(p + 0x264);
    *(f32*)(p + 0x10) = *(f32*)(p + 0x25c) * JMASinShort(*(s16*)(p + 0x260)) + *(f32*)(p + 0x268);
    *(s32*)(p + 0x274) = 0;
    *(s32*)(p + 0x278) = 0;
}

