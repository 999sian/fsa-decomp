#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JMath/Inline.h"

extern "C" void fn_8013CC50(s32, void*, f32, s32, s32, s32, s32, s32, s32);
extern "C" f32 lbl_80542438;
extern "C" f32 lbl_8054243C;
extern "C" f32 lbl_80542440;
extern "C" f32 lbl_80542444;
extern "C" u16 fn_80226850(void* pos, s32 room);
extern "C" f32 lbl_80542448;
extern "C" f32 lbl_8054244C;
extern "C" f32 lbl_80542450;
extern "C" f32 lbl_80542454;
extern "C" f32 lbl_80542458;


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
extern "C" void fn_801F06F0(Actor* a, void* p2, s32 idx, u8* ids, s32 p5, f32 f6, f32 f7);
extern "C" void fn_803075AC(void* h, s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" void fn_80346E84(Actor* this_) {
    u8* p = (u8*)this_;
    s32 mode;
    u8 ids[16];
    u8 rec[0x3c];
    f32 m[3][4];
    s32 i;
    f32 sa, sb, sc, ca, cb, cc;
    f32 s;

    if (*(s32*)(p + 0x230) == 4) {
        if (*(s32*)(p + 0x260) == 0) {
            return;
        }
        mode = -1;
        for (i = 0; i < 16; i++) {
            ids[i] = i;
        }
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
    u8* p = (u8*)this_;
    s32 room;
    s32 hit;
    s32 flag;
    s32 i;
    f32 box[4];
    Vec tmp;
    Vec* pos = (Vec*)(p + 0xc);
    Vec* vel = (Vec*)(p + 0x3c);

    switch (*(s32*)(p + 0x230)) {
    case 0:
        room = *(s32*)(p + 4);
        if (*((u8*)fn_802D6A9C() + room + 0x131df) != 0) {
            pos->z = lbl_80542438;
            vel->z = lbl_80542438;
            vel->y += lbl_80542440;
            pos->x += vel->x;
            pos->y += vel->y;
            pos->z += vel->z;
            if (fn_801F2618(p, 0, 0) == 1) {
                vel->x = -vel->x;
                if (vel->y > lbl_8054243C) {
                    vel->z = lbl_80542438;
                    vel->y = lbl_80542438;
                    vel->x = lbl_80542438;
                } else {
                    vel->y = -(lbl_80542444 * vel->y);
                }
            }
        } else {
            if (pos->z != lbl_80542438 || vel->z != lbl_80542438) {
                vel->z -= lbl_80542440;
                if (pos->z <= lbl_80542438) {
                    pos->z = lbl_80542438;
                    vel->z = lbl_80542438;
                    vel->y = lbl_80542438;
                    vel->x = lbl_80542438;
                }
            }
            pos->x += vel->x;
            pos->y += vel->y;
            pos->z += vel->z;
            if (fn_801F2618(p, 0, 0) == 1) {
                vel->x = -vel->x;
                vel->y = -vel->y;
            }
        }
        for (i = 0; i < 4; i++) {
            box[0] = *(f32*)(p + 0x60) + pos->x;
            box[1] = *(f32*)(p + 0x64) + pos->y;
            box[2] = *(f32*)(p + 0x68) + pos->x;
            box[3] = *(f32*)(p + 0x6c) + pos->y;
            if (fn_80233DA4(i) == 1) {
                box[3] += lbl_80542448;
                if (fn_8023B0F4(i, lbl_80542438, box, room, 0) == 1) {
                    if (fn_8023E724(i)->z > lbl_80542438) {
                        *(s32*)(p + 0x250) = i;
                        break;
                    }
                }
            }
        }
        hit = 0;
        flag = 0;
        if (*(s32*)(p + 0x250) >= 0) {
            if (fn_8022CAF8(*(s32*)(p + 0x250)) == 4) {
                if (!fn_8022F478(*(s32*)(p + 0x250))) {
                    hit = 1;
                    flag = 1;
                }
            } else if (lbl_8053AAF8[0x82] & (u8)(1 << *(s32*)(p + 0x250))) {
                hit = 1;
            } else if (fn_8022F514(*(s32*)(p + 0x250))) {
                hit = 1;
            }
            if (hit == 0) {
                *(s32*)(p + 0x250) = -1;
            }
        }
        if (hit == 1) {
            if (fn_80235580(*(s32*)(p + 0x250))) goto check271;
            if (fn_8023EA28(*(s32*)(p + 0x250))) goto check271;
            *(s32*)(p + 0x24c) = 0x2d0;
            if (flag == 0) {
                if (fn_8022F514(*(s32*)(p + 0x250))) {
                    *(s32*)(p + 0x250) = fn_8022F3DC(*(s32*)(p + 0x250));
                }
            }
            if (fn_8023EBB8(*(s32*)(p + 0x250)) == 1) {
                fn_80230C6C(*(s32*)(p + 0x250));
            }
            hit = fn_80233DA4(*(s32*)(p + 0x250)) == 1;
            if (fn_8023C830(*(s32*)(p + 0x250)) != 1) goto check271;
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
                *pos = *pos;
                goto tail;
            }
            if (*(u8*)(p + 0x270) == 0) {
                detach__5ActorFv(this_);
            } else {
                *(u8*)(p + 0x11c) = 0;
            }
            goto tail;
        }
    check271:
        if (*(u8*)(p + 0x271) == 1) {
            *(s32*)(p + 0x24c) -= 1;
        }
        goto tail;
    case 1:
        if (fn_80226850(pos, *(s32*)(p + 4)) != *(u16*)(p + 0x264)) {
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
        if (fn_8023F264(*(s32*)(p + 0x250))) {
            *pos = *fn_8023E724(*(s32*)(p + 0x250));
            pos->y -= lbl_80542458;
        }
        if (*(s32*)(p + 0x25c) != 0) {
            *(s32*)(p + 0x25c) -= 1;
            if (*(s32*)(p + 0x25c) == 0) {
                Actor_CreateByID(fn_801F856C(), 0x4e4e4a4e, room, (f32*)(p + 0x240), *(s32*)(p + 0x90), *(s32*)(p + 0x16c), -1);
            } else if (*(s32*)(p + 0x25c) == 4) {
                if (*(s32*)(p + 4) >= 8) {
                    tmp = *(Vec*)(p + 0x240);
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
tail:
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
extern "C" f32 lbl_80542438;
extern "C" f32 lbl_8054243C;
extern "C" f32 lbl_8054245C;
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

extern "C" char lbl_8050A4F8[];
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" void __register_global_object(void*, void*, void*);
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void fn_80347C6C(void)
{
  char* base = lbl_8050A4F8;
  if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
    __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
    __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, base + 0x0);
    __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
  }
  if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
    __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
    __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, base + 0xc);
    __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
  }
  if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
    __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
    __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, base + 0x18);
    __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
  }
  if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
    __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
    __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, base + 0x24);
    __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
  }
  if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
    __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
    __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, base + 0x30);
    __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
  }
  if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
    __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
    __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, base + 0x3c);
    __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
  }
  if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
    __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
    __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, base + 0x48);
    __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
  }
  if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
    __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
    __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, base + 0x54);
    __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
  }
  if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
    __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
    __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, base + 0x60);
    __init__memPool___26JASPoolAllocObject_5JAISe = 1;
  }
}

