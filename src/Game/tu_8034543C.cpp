#include "types.h"
#include "Game/Actor.h"
#include <math.h>

/* JSystem/JMath/JMath.h cannot be included here (its Vec clashes with Actor.h). */
namespace JMath {
template <int length, typename T>
struct TAtanTable {
    T atan2_(T, T) const;
};
extern TAtanTable<1024, f32> atanTable_;
}


extern "C" s16 fn_8022461C(s32);
extern "C" char lbl_804AC658[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" char lbl_8050A3F8[];
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" Actor* fn_8034543C(Actor* this_, s16 n) {
    if (this_ != nullptr) {
        *(void**)this_ = lbl_804AC658;
        __dt__5ActorFv(this_, 0);
        if (n > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_801EEC98(void*, s32, u16*, s32*, f32*, s32*, s32, s32);
extern "C" u8 fn_80233E40(s32);
extern "C" u8 fn_8022B7C4(s32);
extern "C" s32 fn_8022CAF8(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" Vec* fn_8023E724(s32);
extern "C" s32 ClassifyBamAngleToQuadrant(u16);
extern const f32 lbl_805423A0;
extern const f32 lbl_805423FC;
extern const f32 lbl_80542418;
extern "C" s32 fn_80346330(u8* this_) {
    s32 i;
    u8* self = this_;

    *(f32*)(self + 0x264) = lbl_805423A0;
    *(u16*)(self + 0x268) = 0;
    *(s32*)(self + 0x26c) = -1;
    *(s32*)(self + 0x270) = -1;
    fn_801EEC98(self, *(s32*)(self + 0x198), (u16*)(self + 0x268), (s32*)(self + 0x26c), (f32*)(self + 0x264), (s32*)(self + 0x270), 0, 0);

    if (*(s32*)(self + 0x26c) >= 0 && *(f32*)(self + 0x264) < lbl_805423FC) {
        if (*(s32*)(self + 0x270) >= 0) {
            if (fn_80233E40(*(s32*)(self + 0x270)) == 1 || fn_8022B7C4(*(s32*)(self + 0x270)) == 1) {
                return 1;
            }
        }
    }

    for (i = 0; i < 4; i++) {
        s32 room;
        if (fn_8022CAF8(i) == 4 || fn_8022CAF8(i) == 5) {
            continue;
        }
        if (*(s32*)(self + 0x270) == i) {
            continue;
        }
        room = *(s32*)(self + 0x4);
        if (room != fn_8023DE58(i)) {
            continue;
        }
        if (fn_80233E40(i) != 1 && fn_8022B7C4(i) != 1) {
            continue;
        }
        {
            f32 dx = *(f32*)(self + 0xc) - fn_8023E724(i)->x;
            f32 dy = *(f32*)(self + 0x10) - fn_8023E724(i)->y;
            f32 dist = sqrt(dx * dx + dy * dy);

            if (dist < lbl_805423FC) {
                *(f32*)(self + 0x264) = dist;
                *(s16*)(self + 0x268) = (s16)(JMath::atanTable_.atan2_(-dx, -dy) * lbl_80542418);
                *(s32*)(self + 0x270) = i;
                *(s32*)(self + 0x26c) = ClassifyBamAngleToQuadrant(*(u16*)(self + 0x268));
                return 1;
            }
        }
    }
    return 0;
}

extern void* lbl_8053AAF8;
extern const f32 lbl_805423A8;
extern const f32 lbl_805423D0;
extern const f32 lbl_805423D4;
extern const f32 lbl_8054241C;
extern const f32 lbl_80542420;
extern const f32 lbl_80542424;
extern const f32 lbl_80542428;
extern "C" void fn_801F6758(void* pos, s32 room);
extern "C" u8* fn_802D6A9C(void);
extern "C" s32 fn_802265FC(f32* pos, s32 room);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 id, u32 room, void* pos, u32 arg, s32 a, s32 b);

static inline f32 tuRandF() {
    u8* g = (u8*)lbl_8053AAF8;
    *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
    u32 bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
    return *(f32*)&bits - 1.0f;
}

static inline s32 tuCollectTiles(u8* self, u16* tiles, f32 x0, f32 y0, s32 w, s32 h) {
    s32 n = 0;
    s32 col = 1;
    for (s32 x = 16; x < w; x += 16, col++) {
        f32 fx = (f32)x + x0;
        s32 v = col + 0x20;
        for (s32 y = 16; y < h; y += 16, v += 0x20) {
            f32 pos[2];
            pos[0] = fx;
            pos[1] = (f32)y + y0;
            s32 t = (u16)fn_802265FC(pos, *(s32*)(self + 0x4));
            if (t == 0xd || t == 0x3a) {
                if (n >= 713) {
                    return 0;
                }
                tiles[n] = v;
                n++;
            }
        }
    }
    return n;
}

static inline void tuSetVec(Vec* v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void tuSpawnFish(u8* self, f32 fx, f32 fy) {
    Vec pos;
    tuSetVec(&pos, fx + lbl_805423D0 * tuRandF(), fy + lbl_805423D0 * tuRandF(), lbl_805423A0);
    Actor_CreateByID(fn_801F856C(), 0x46495348, *(s32*)(self + 0x4), &pos, 0, -1, -1);
}

extern "C" s32 fn_803466C0(s32 param_1, s32 param_2, s32 param_3) {
    s32 r = (u16)fn_8022461C(param_3);
    if (r == 0xd || r == 0x3a) {
        return 0;
    }
    return 1;
}

extern "C" void fn_80346704(Actor* this_) {
    u16 tiles[713];
    u32 spawn = *(u32*)((u8*)this_ + 0x90);
    u8* self = (u8*)this_;
    s32 extra;
    s32 range;
    u32 count;
    s32 n;

    *(u32*)(self + 0x90) = spawn & 0xfff;
    extra = (spawn >> 12) & 0xff;
    range = (spawn >> 20) & 0xff;
    *(s32*)(self + 0x108) = 10000;
    *(f32*)(self + 0x60) = lbl_8054241C;
    *(f32*)(self + 0x64) = lbl_8054241C;
    *(f32*)(self + 0x68) = lbl_80542420;
    *(f32*)(self + 0x6c) = lbl_80542420;
    *(f32*)(self + 0x80) = lbl_8054241C;
    *(f32*)(self + 0x84) = lbl_8054241C;
    *(f32*)(self + 0x88) = lbl_80542420;
    *(f32*)(self + 0x8c) = lbl_80542420;
    *(s32*)(self + 0x240) = 0;
    *(s32*)(self + 0x244) = 0;
    *(s32*)(self + 0x248) = 0;
    *(s32*)(self + 0x234) = 0;
    *(s32*)(self + 0x238) = 0;
    *(s32*)(self + 0x23c) = 0;
    *(f32*)(self + 0x264) = lbl_805423A0;
    *(u16*)(self + 0x268) = 0;
    *(s32*)(self + 0x26c) = -1;
    *(s32*)(self + 0x270) = -1;
    fn_801F6758(self + 0xc, *(s32*)(self + 0x4));

    count = *(u32*)(self + 0x90);
    if (count != 0) {
        s32 room = *(s32*)(self + 0x4);
        u8* mgr = fn_802D6A9C();
        f32* box;
        if (room < 8) {
            box = (f32*)(mgr + 0xcc);
        } else {
            box = (f32*)(mgr + 0xdc);
        }
        f32 x0 = box[0];
        f32 y0 = box[1];
        s32 w = (s32)(box[2] - x0);
        s32 h = (s32)(box[3] - y0);
        n = 0;
        s32 col = 1;
        for (s32 x = 16; x < w; x += 16, col++) {
            f32 fx = (f32)x + x0;
            s32 v = col + 0x20;
            for (s32 y = 16; y < h; y += 16, v += 0x20) {
                f32 pos[2];
                pos[0] = fx;
                pos[1] = (f32)y + y0;
                s32 t = (u16)fn_802265FC(pos, *(s32*)(self + 0x4));
                if (t == 0xd || t == 0x3a) {
                    if (n >= 713) {
                        return;
                    }
                    tiles[n] = v;
                    n++;
                }
            }
        }
        if (n == 0) {
            return;
        }
        for (s32 k = 0; k < (s32)count;) {
            s32 idx = (s32)((f32)n * tuRandF());
            u16 t = tiles[idx];
            s32 num = extra + (s32)((f32)(range + 1) * tuRandF());
            if (!(tuRandF() > lbl_80542424 && (s32)count - k > num)) {
                num = 1;
            }
            f32 fx = (f32)((t & 0x1f) << 4) + x0;
            f32 fy = (f32)(((t >> 5) & 0x7ff) << 4) + y0;
            for (s32 j = 0; j < num; j++) {
                tuSpawnFish(self, fx, fy);
                k++;
            }
        }
    }

    *(s16*)(self + 0x250) = (s32)(lbl_80542428 * tuRandF());
    *(u16*)(self + 0x252) = *(u16*)(self + 0x250) + 0x4000;
    *(s32*)(self + 0x24c) = 0;
    *(s16*)(self + 0x250) = 0;
    *(f32*)(self + 0x25c) = lbl_805423A0;
    *(f32*)(self + 0x258) = lbl_805423A0;
    *(f32*)(self + 0x254) = lbl_805423A0;
    *(f32*)(self + 0x260) = lbl_805423D4;
    *(s32*)(self + 0x230) = 0;
}

extern "C" void fn_80346C00(void) {
    char* base = &lbl_8050A3F8[0];
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

