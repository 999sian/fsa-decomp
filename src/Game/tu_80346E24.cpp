#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JMath/Inline.h"
#include "JSystem/JGeometry/Vec.h"
#include "Game/ItemBase.h"
extern "C" char lbl_804720A0[];

extern "C" void fn_8013CC50(s32, void*, f32, s32, s32, s32, s32, s32, s32);
extern "C" const f32 lbl_80542438;
extern "C" const f32 lbl_8054243C;
extern "C" const f32 lbl_80542440;
extern "C" const f32 lbl_80542444;
extern "C" u16 fn_80226850(void* pos, s32 room);
extern "C" const f32 lbl_80542448;
extern "C" const f32 lbl_8054244C;
extern "C" const f32 lbl_80542450;
extern "C" const f32 lbl_80542454;
extern "C" const f32 lbl_80542458;


extern "C" char lbl_804AC6B0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80346E24(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AC6B0;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" double sin(double);
extern "C" double cos(double);
static inline void setDrawRotation(Mtx m, f32 angle, const f32 scale) {
    f32 sx,sy,sz,cx,cy,cz;
    sx=sin(lbl_80542438);
    sy=sin(angle);
    sz=sin(lbl_80542438);
    cx=cos(lbl_80542438);
    cy=cos(angle);
    cz=cos(lbl_80542438);
    f32 cxcz=cx*cz;
    f32 sxsy=sx*sy;
    f32 cxsz=cx*sz;
    m[0][0]=scale*(cy*cz);
    m[1][0]=scale*(cy*sz);
    m[2][0]=scale*(-sy);
    m[0][1]=scale*(sxsy*cz-cxsz);
    m[1][1]=scale*(sxsy*sz+cxcz);
    m[2][1]=scale*(sx*cy);
    m[0][2]=scale*(cxcz*sy+sx*sz);
    m[1][2]=scale*(cxsz*sy-sx*cz);
    m[2][2]=scale*(cx*cy);
}

extern "C" void fn_801F06F0(Actor* a, void* p2, s32 idx, u8* ids, s32 p5, f32 f6, f32 f7);
extern "C" void fn_803075AC(void* h, s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" void fn_80346E84(Actor* this_) {
    Vec transform;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 cy;
    f32 cz;
    u8* p=(u8*)this_;
    if(*(s32*)(p+0x230)==4 && *(s32*)(p+0x260)==0) return;
    DrawRec rec;
    Mtx m;
    s32 mode=7;
    rec.b2d=1;
    PSMTXIdentity(m);
    transform.y=*(f32*)(p+0x268);
    transform.x=*(f32*)(p+0x26c);
    sx=sin(lbl_80542438);
    sy=sin(transform.y);
    sz=sin(lbl_80542438);
    transform.z=cos(lbl_80542438);
    cy=cos(transform.y);
    cz=cos(lbl_80542438);
    f32 cxcz=transform.z*cz;
    f32 sxsy=sx*sy;
    f32 cxsz=transform.z*sz;
    m[0][0]=transform.x*(cy*cz);
    m[1][0]=transform.x*(cy*sz);
    m[2][0]=transform.x*(-sy);
    m[0][1]=transform.x*(sxsy*cz-cxsz);
    m[1][1]=transform.x*(sxsy*sz+cxcz);
    m[2][1]=transform.x*(sx*cy);
    m[0][2]=transform.x*(cxcz*sy+sx*sz);
    m[1][2]=transform.x*(cxsz*sy-sx*cz);
    m[2][2]=transform.x*(transform.z*cy);
    rec.w18=m;
    s32 state=*(s32*)(p+0x230);
    if(state==3) mode=-1;
    if(state==0 || state==3 || state==4) {
        if(*(s32*)(p+0x24c)<0x100 && (*(s32*)(p+0x24c)&2)) return;
        if(state==4) rec.b1d=3;
        fn_801F06F0(this_,lbl_804720A0,0x2aa,rec.ids,mode,lbl_8054243C,lbl_8054243C);
        fn_803075AC(*(void**)(p+0x198),*(s32*)(p+4),p+0xc,0x2aa,0,2,-1,0,0,0);
    }
}

extern "C" u8* lbl_8053AAF8;
extern "C" s32 fn_802D6A9C(void);
extern "C" BOOL fn_801F2618(void* p, s32 a, s32 b);
extern "C" BOOL fn_80233DA4(s32 id);
extern "C" BOOL fn_8023B0F4(s32 id, f32 t, f32* box, s32 room, s32 c);
extern "C" Vec* fn_8023E724(s32 id);
extern "C" s32 fn_8022CAF8(s32 id);
extern "C" BOOL fn_8022F478(s32 id);
extern "C" BOOL fn_8022F514(s32 id);

static inline BOOL IsPlayerBitSet(s32 id) {
    return (lbl_8053AAF8[0x82] & (u8)(1 << id)) != 0;
}

static inline void OffsetBox(f32* box, f32 x, f32 y) {
    box[0] += x;
    box[1] += y;
    box[2] += x;
    box[3] += y;
}
extern "C" BOOL fn_80235580(s32 id);
extern "C" BOOL fn_8023EA28(s32 id);
extern "C" s32 fn_8022F3DC(s32 id);
extern "C" BOOL fn_8023EBB8(s32 id);
extern "C" void fn_80230C6C(s32 id);
extern "C" BOOL fn_8023C830(s32 id);
extern "C" void fn_80230FD0(s32 id, s32 v);
extern "C" BOOL fn_8023F264(s32 id);
extern "C" s32 fn_801F856C(void);
extern "C" void fn_801F71A4(f32* v, f32 cur, f32 target, f32 step);
extern "C" void Actor_CreateByID(s32 mgr, s32 name, s32 room, f32* pos, s32 a, s32 b, s32 c);
extern "C" void detach__5ActorFv(Actor* p);
extern "C" void fn_803471A0(Actor* this_) {
    s32 i;
    u8 flag;
    f32 box[4];
    Vec tmp;
    u8 hit;
    u8* p = (u8*)this_;

    switch (*(s32*)(p + 0x230)) {
    case 0:
        i = *(s32*)(p + 4);
        if (*(u8*)(fn_802D6A9C() + 0x131df + i) != 0) {
            *(f32*)(p + 0x14) = lbl_80542438;
            *(f32*)(p + 0x44) = lbl_80542438;
            *(f32*)(p + 0x40) += lbl_80542440;
            JMathInlineVEC::PSVECAdd((Vec*)(p + 0xc), (Vec*)(p + 0x3c), (Vec*)(p + 0xc));
            if ((u8)fn_801F2618(p, 0, 0) == 1) {
                *(f32*)(p + 0x3c) = -*(f32*)(p + 0x3c);
                if (*(f32*)(p + 0x40) <= lbl_8054243C) {
                    *(f32*)(p + 0x44) = lbl_80542438;
                    *(f32*)(p + 0x40) = lbl_80542438;
                    *(f32*)(p + 0x3c) = lbl_80542438;
                } else {
                    *(f32*)(p + 0x40) = -(*(f32*)(p + 0x40) * lbl_80542444);
                }
            }
        } else {
            if (lbl_80542438 != *(f32*)(p + 0x14) || lbl_80542438 != *(f32*)(p + 0x44)) {
                *(f32*)(p + 0x44) -= lbl_80542440;
                if (*(f32*)(p + 0x14) <= lbl_80542438) {
                    *(f32*)(p + 0x14) = lbl_80542438;
                    *(f32*)(p + 0x44) = lbl_80542438;
                    *(f32*)(p + 0x40) = lbl_80542438;
                    *(f32*)(p + 0x3c) = lbl_80542438;
                }
            }
            JMathInlineVEC::PSVECAdd((Vec*)(p + 0xc), (Vec*)(p + 0x3c), (Vec*)(p + 0xc));
            if ((u8)fn_801F2618(p, 0, 0) == 1) {
                *(f32*)(p + 0x3c) = -*(f32*)(p + 0x3c);
                *(f32*)(p + 0x40) = -*(f32*)(p + 0x40);
            }
        }
        for (i = 0; i < 4; i++) {
            box[0] = *(f32*)(p + 0x60);
            box[1] = *(f32*)(p + 0x64);
            box[2] = *(f32*)(p + 0x68);
            box[3] = *(f32*)(p + 0x6c);
            OffsetBox(box, *(f32*)(p + 0xc), *(f32*)(p + 0x10));
            if ((u8)fn_80233DA4(i) == 1) {
                box[3] += lbl_80542448;
            }
            if ((u8)fn_8023B0F4(i, lbl_80542438, box, *(s32*)(p + 4), 0) == 1) {
                if (fn_8023E724(i)->z <= lbl_80542438) {
                    *(s32*)(p + 0x250) = i;
                    break;
                }
            }
        }
        hit = 0;
        flag = 0;
        if (*(s32*)(p + 0x250) >= 0) {
            if (fn_8022CAF8(*(s32*)(p + 0x250)) == 4) {
                if (!(u8)fn_8022F478(*(s32*)(p + 0x250))) {
                    hit = 1;
                    flag = 1;
                }
            } else if (IsPlayerBitSet(*(s32*)(p + 0x250)) || (u8)fn_8022F514(*(s32*)(p + 0x250))) {
                hit = 1;
            }
            if (!hit) {
                *(s32*)(p + 0x250) = -1;
            }
        }
        if (hit == 1 && !(u8)fn_80235580(*(s32*)(p + 0x250)) && !(u8)fn_8023EA28(*(s32*)(p + 0x250))) {
            *(s32*)(p + 0x24c) = 0x2d0;
            if (!flag && (u8)fn_8022F514(*(s32*)(p + 0x250))) {
                *(s32*)(p + 0x250) = fn_8022F3DC(*(s32*)(p + 0x250));
            }
            if ((u8)fn_8023EBB8(*(s32*)(p + 0x250)) == 1) {
                fn_80230C6C(*(s32*)(p + 0x250));
            }
            hit = 0;
            if ((u8)fn_80233DA4(*(s32*)(p + 0x250)) == 1) {
                hit = 1;
            }
            if ((u8)fn_8023C830(*(s32*)(p + 0x250)) == 1) {
                *(s32*)(p + 0xb0) = 0;
                if (hit == 1) {
                    fn_80230FD0(*(s32*)(p + 0x250), 0x20049);
                }
                if (*(s32*)(p + 0x254) != 0) {
                    *(s32*)(p + 0x230) = 4;
                    *(s32*)(p + 0x25c) = 0x19;
                    *(s32*)(p + 0x260) = 0x3c;
                    *(f32*)(p + 0x60) = lbl_80542438;
                    *(f32*)(p + 0x64) = lbl_80542438;
                    *(f32*)(p + 0x68) = lbl_80542438;
                    *(f32*)(p + 0x6c) = lbl_80542438;
                    *(f32*)(p + 0x80) = lbl_80542438;
                    *(f32*)(p + 0x84) = lbl_80542438;
                    *(f32*)(p + 0x88) = lbl_80542438;
                    *(f32*)(p + 0x8c) = lbl_80542438;
                    JGeometry::setTVec3f((f32*)(p + 0xc), (f32*)(p + 0x240));
                } else if (*(u8*)(p + 0x270) == 0) {
                    detach__5ActorFv(this_);
                } else {
                    *(u8*)(p + 0x11c) = 0;
                }
                break;
            }
        }
        if (*(u8*)(p + 0x271) == 1) {
            *(s32*)(p + 0x24c) -= 1;
        }
        break;
    case 1:
        if (*(u16*)(p + 0x264) != fn_80226850(p + 0xc, *(s32*)(p + 4))) {
            *(s32*)(p + 0x230) = 0;
            *(f32*)(p + 0x44) = lbl_8054244C;
        }
        break;
    case 3:
        fn_801F71A4((f32*)(p + 0xc), *(f32*)(p + 0x234), lbl_80542450, lbl_8054243C);
        fn_801F71A4((f32*)(p + 0x10), *(f32*)(p + 0x238), lbl_80542450, lbl_8054243C);
        *(f32*)(p + 0x268) += lbl_80542450;
        *(f32*)(p + 0x26c) -= lbl_80542454;
        if (*(f32*)(p + 0x26c) < lbl_80542450) {
            detach__5ActorFv(this_);
        }
        break;
    case 4:
        if ((u8)fn_8023F264(*(s32*)(p + 0x250))) {
            JGeometry::setTVec3f((f32*)fn_8023E724(*(s32*)(p + 0x250)), (f32*)(p + 0xc));
            *(f32*)(p + 0x10) -= lbl_80542458;
        }
        if (*(s32*)(p + 0x25c) != 0) {
            *(s32*)(p + 0x25c) -= 1;
            if (*(s32*)(p + 0x25c) == 0) {
                Actor_CreateByID(fn_801F856C(), 0x4e4e4a4e, *(s32*)(p + 4), (f32*)(p + 0x240), *(s32*)(p + 0x90), *(s32*)(p + 0x16c), -1);
            } else if (*(s32*)(p + 0x25c) == 4) {
                if (*(s32*)(p + 4) >= 8) {
                    JGeometry::setTVec3f((f32*)(p + 0x240), (f32*)&tmp);
                    tmp.z = lbl_80542438;
                    Actor_CreateByID(fn_801F856C(), 0x4b4d5249, *(s32*)(p + 4), (f32*)&tmp, 3, -1, -1);
                } else {
                    fn_8013CC50(*(s32*)(p + 4), p + 0x240, lbl_8054243C, 0x503, 1, 0, 0, 0, 1);
                }
            }
        }
        if (*(s32*)(p + 0x260) != 0) {
            *(s32*)(p + 0x260) -= 1;
            if (*(s32*)(p + 0x260) == 0) {
                *(u8*)(p + 0x11c) = 0;
            }
        }
        break;
    }
    if (*(s32*)(p + 0x24c) <= 0) {
        *(u8*)(p + 0x11c) = 0;
    }
}

extern "C" s32 fn_8022461C(s32);
extern "C" void fn_8013CC50(s32, void*, f32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_801F0E34(Actor*, s32, s32);
extern "C" u8 fn_802DE9A0(void);
extern "C" u8 fn_802DEB58(void);
extern "C" s32 v17__5ActorFiPf(Actor*, s32, f32*);
extern "C" const f32 lbl_8054245C;
extern "C" s32 fn_803477DC(Actor* this_, s32 a, s32 b) {
    u8* p = (u8*)this_;
    s32 type = (u16)fn_8022461C(b);
    if ((u32)(type - 0x4c) <= 2 || type == 0x4f) {
        return 0;
    } else if (type == 3) {
        if (*(f32*)(p + 0x14) <= lbl_80542438) {
            *(f32*)(p + 0x234) = (f32)(((s32)*(f32*)(p + 0xc)) & 0xfff0) + lbl_8054245C;
            *(f32*)(p + 0x238) = (f32)(((s32)*(f32*)(p + 0x10)) & 0xfff0) + lbl_8054245C;
            *(u32*)(p + 0x24c) = 0x400;
            *(s32*)(p + 0x230) = 3;
            *(f32*)(p + 0x3c) = lbl_80542438;
            *(f32*)(p + 0x40) = lbl_80542438;
            *(f32*)(p + 0x44) = lbl_80542438;
        }
        return 0;
    } else if (type == 0xd || type == 0x3a) {
        if (*(f32*)(p + 0x14) <= lbl_80542438) {
            fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, lbl_8054243C, 0x3d0, 0, 1, 0, 0, 1);
            fn_801F0E34(this_, 0x30022, 0);
            *(u8*)(p + 0x11c) = 0;
        }
        return 0;
    } else if (type == 0xe) {
        if (*(f32*)(p + 0x14) <= lbl_80542438) {
            if (fn_802DE9A0()) {
                fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, lbl_8054243C, 0x2a9, -1, 1, 0, 0, 1);
                fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, lbl_8054243C, 0x2aa, -1, 0, 0, 0, 1);
                fn_801F0E34(this_, 0x5005f, 0);
                *(u8*)(p + 0x11c) = 0;
            } else if (fn_802DEB58()) {
                fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, lbl_8054243C, 0x45e, -1, 1, 0, 0, 1);
                fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, lbl_8054243C, 0x45f, 0, 0, 0, 0, 1);
                fn_801F0E34(this_, 0x5003f, 0);
            } else {
                *(f32*)(p + 0x234) = (f32)(((s32)*(f32*)(p + 0xc)) & 0xfff0) + lbl_8054245C;
                *(f32*)(p + 0x238) = (f32)(((s32)*(f32*)(p + 0x10)) & 0xfff0) + lbl_8054245C;
                *(u32*)(p + 0x24c) = 0x400;
                *(s32*)(p + 0x230) = 3;
                *(f32*)(p + 0x3c) = lbl_80542438;
                *(f32*)(p + 0x40) = lbl_80542438;
                *(f32*)(p + 0x44) = lbl_80542438;
            }
        }
        return 0;
    } else if (type == 0x39) {
        return 0;
    }
    return v17__5ActorFiPf(this_, a, (f32*)b);
}

extern "C" u16 fn_80226850(void* pos, s32 room);
extern "C" Vec lbl_80472010[];
extern "C" void fn_80347B20(Actor* this_) {
    u8* p = (u8*)this_;
    *(f32*)(p + 0x60) = -4.0f;
    *(f32*)(p + 0x64) = -4.0f;
    *(f32*)(p + 0x68) = 4.0f;
    *(f32*)(p + 0x6c) = 4.0f;
    *(f32*)(p + 0x80) = -4.0f;
    *(f32*)(p + 0x84) = -4.0f;
    *(f32*)(p + 0x88) = 4.0f;
    *(f32*)(p + 0x8c) = 4.0f;
    *(u32*)(p + 0x108) = 8;
    *(u16*)(p + 0x264) = 0;
    *(f32*)(p + 0x26c) = 1.0f;
    *(f32*)(p + 0x268) = 0.0f;
    *(f32*)(p + 0x23c) = 0.0f;
    *(f32*)(p + 0x238) = 0.0f;
    *(f32*)(p + 0x234) = 0.0f;
    *(u8*)(p + 0x270) = (this_->field_90 >> 8) & 1;
    *(u32*)(p + 0x24c) = 0x400;
    if (((this_->field_90 >> 4) & 1) == 1) {
        *(u32*)(p + 0x230) = 1;
        *(u16*)(p + 0x264) = fn_80226850(p + 0xc, *(u32*)(p + 0x4));
        *(u32*)(p + 0xb0) = 0;
    } else {
        *(u32*)(p + 0x230) = 0;
        *(u32*)(p + 0xb0) = 0x20000;
    }
    *(s32*)(p + 0x254) = (this_->field_90 >> 27) & 3;
    if (*(s32*)(p + 0x254) != 0) {
        Vec* v;
        *(s32*)(p + 0x258) = (this_->field_90 >> 22) & 3;
        v = &lbl_80472010[*(s32*)(p + 0x258) | ((*(s32*)(p + 0x254) - 1) << 2)];
        f32 y = v->y;
        f32 x = v->x;
        *(f32*)(p + 0x3c) = x;
        f32 z = v->z;
        *(f32*)(p + 0x40) = y;
        *(f32*)(p + 0x44) = z;
    }
    *(s32*)(p + 0x250) = -1;
    *(u8*)(p + 0x271) = this_->field_90 & 1;
    *(u32*)(p + 0x25c) = 0;
}

#include "Game/SinitPoolChain.h"

