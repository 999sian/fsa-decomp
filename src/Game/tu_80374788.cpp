#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
#define Vec ActorVec
#include "Game/Actor.h"
#include "Game/ItemBase.h"


extern "C" char lbl_804AE620[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80374788(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AE620;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" char lbl_80475120[];
extern "C" const f32 lbl_80542ED8;
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, void* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_80307AC8(void* obj, u32 id, void* pos, u32 kind, u32 a, u32 b, s32 c);
#pragma opt_common_subs on
#pragma opt_propagation on
extern "C" void fn_803747E8(Actor* this_) {
    DrawRec rec;
    s32 idx = 0;
    s32 type = *(s32*)((char*)this_ + 0x240);
    if (type != 0) {
        rec.b1d = -1;
        idx = type + 3;
        fn_801F06F0(this_, lbl_80475120, idx + 0x45, &rec, 0, lbl_80542ED8, lbl_80542ED8);
    }
    fn_80307AC8(*(void**)((char*)this_ + 0x198), this_->field_04, (char*)this_ + 0xc, idx + 0x45, 0, 0, -1);
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
extern "C" f32 lbl_80542EE0;
extern "C" f32 lbl_80542EE4;
extern "C" f32 lbl_80542EE8;
extern "C" void fn_80239914(f32* box, s32 room, s32 handle);
extern "C" u8* fn_8020D58C(s32 a);
extern "C" void fn_8020D7D0(u8* rec, s32 handle);
extern "C" const f32 lbl_80542EDC;
extern "C" const f32 lbl_80542EEC;
extern "C" const f32 lbl_80542EFC;
extern "C" const f32 lbl_80542F00;
extern "C" u8 fn_801F2618(Actor*,s32,s32);
extern "C" u8 fn_80374964(Actor*,u8);
extern "C" u16 fn_8022461C(void*,s32);
extern "C" s32 fn_80239108(s32);
extern "C" s32 fn_80238BC4(s32);
extern "C" s32 fn_80239558(void*,s32,s32);
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D7584(void*,s32,u8);
extern "C" void fn_80238E08(s32);
extern "C" void fn_801F0E34(Actor*,s32,s32);
extern "C" JGeometry::TVec3f lbl_804A79E0[];
extern "C" const JGeometry::TVec3f lbl_804750C0[];
static inline f32 blockVelocityY(const JGeometry::TVec3f* velocity) { return velocity->y; }
static inline void blockSetVelocity(Actor* actor, const JGeometry::TVec3f& velocity) {
    f32 x = velocity.x;
    f32 y = velocity.y;
    actor->field_3C.x = x;
    f32 z = velocity.z;
    actor->field_3C.y = y;
    actor->field_3C.z = z;
}
extern "C" void fn_80374BAC(Actor* this_) {
    u8* p = (u8*)this_;
    JGeometry::TBox2f bounds;
    bounds.set(*(JGeometry::TBox2f*)(p + 0x60));
    bounds.addPos(*(JGeometry::TVec2f*)(p + 0xc));
    if (*(s32*)(p + 0x244) != 0) {
        ((f32*)&bounds)[0] -= lbl_80542EE0;
        ((f32*)&bounds)[1] -= lbl_80542EE0;
        ((f32*)&bounds)[2] += lbl_80542EE0;
        ((f32*)&bounds)[3] += lbl_80542EE0;
    } else {
        ((f32*)&bounds)[0] -= lbl_80542ED8;
        ((f32*)&bounds)[1] -= lbl_80542ED8;
        ((f32*)&bounds)[2] += lbl_80542ED8;
        ((f32*)&bounds)[3] += lbl_80542ED8;
    }
    fn_80239914((f32*)&bounds, *(s32*)(p + 4), *(s32*)(p + 0x198));
    if (*(s32*)(p + 0x244) != 0) {
        ((f32*)&bounds)[0] -= lbl_80542EE4;
        ((f32*)&bounds)[1] -= lbl_80542EE4;
        ((f32*)&bounds)[2] += lbl_80542EE4;
        ((f32*)&bounds)[3] += lbl_80542EE4;
    } else {
        ((f32*)&bounds)[0] -= lbl_80542EE8;
        ((f32*)&bounds)[1] -= lbl_80542EE8;
        ((f32*)&bounds)[2] += lbl_80542EE8;
        ((f32*)&bounds)[3] += lbl_80542EE8;
    }

    s32 handle = *(s32*)(p + 0x198);
    u8* mgr = ((u8* (*)())fn_8020D58C)();
    fn_8020D7D0(mgr + mgr[0] * 0x784 + 4, handle);
    JGeometry::TVec3f probe;
    if (*(s32*)(p + 0x244) != 0) {
        (*(JGeometry::TVec3f*)(p + 0xc)).x = (s32)((s32)(*(JGeometry::TVec3f*)(p + 0xc)).x + 4) / 8 * 8;
        (*(JGeometry::TVec3f*)(p + 0xc)).y = (s32)((s32)(*(JGeometry::TVec3f*)(p + 0xc)).y + 4) / 8 * 8;
        return;
    }
    if (PSVECDistance(&(*(JGeometry::TVec3f*)(p + 0xc)), &(*(JGeometry::TVec3f*)(p + 0x230))) >= lbl_80542EEC) {
        if (!fn_801F2618(this_, 0, 0)) {
            probe = (*(JGeometry::TVec3f*)(p + 0x3c));
            probe.normalize();
            probe.scale(lbl_80542EFC);
            probe.add((*(JGeometry::TVec3f*)(p + 0xc)));
            u16 tile = fn_8022461C(&probe, *(s32*)(p + 4));
            u16 current = fn_8022461C(&(*(JGeometry::TVec3f*)(p + 0xc)), *(s32*)(p + 4));
            if (current == 0x50 && (tile == 0 || tile == 0x50)) {
                JGeometry::TVec3f saved((*(JGeometry::TVec3f*)(p + 0x3c)));
                if (fn_80374964(this_, *(u32*)(p + 0x90) & 3) == 1) {
                    (*(JGeometry::TVec3f*)(p + 0x3c)) = saved;
                    (*(JGeometry::TVec3f*)(p + 0x230)).x = (*(JGeometry::TVec3f*)(p + 0xc)).x;
                    (*(JGeometry::TVec3f*)(p + 0x230)).y = (*(JGeometry::TVec3f*)(p + 0xc)).y;
                    (*(JGeometry::TVec3f*)(p + 0x230)).z = (*(JGeometry::TVec3f*)(p + 0xc)).z;
                    (*(JGeometry::TVec3f*)(p + 0x230)).x = (s32)((s32)(*(JGeometry::TVec3f*)(p + 0x230)).x + 4) / 8 * 8;
                    (*(JGeometry::TVec3f*)(p + 0x230)).y = (s32)((s32)(*(JGeometry::TVec3f*)(p + 0x230)).y + 4) / 8 * 8;
                    return;
                }
            }
        }
        if ((*(JGeometry::TVec3f*)(p + 0xc)).x <= lbl_80542F00 + *(f32*)(p + 0x24) && (*(JGeometry::TVec3f*)(p + 0xc)).x >= *(f32*)(p + 0x24) - lbl_80542F00) {
            (*(JGeometry::TVec3f*)(p + 0xc)).x = *(f32*)(p + 0x24);
        } else {
            (*(JGeometry::TVec3f*)(p + 0xc)).x = (s32)((s32)(*(JGeometry::TVec3f*)(p + 0xc)).x + 4) / 8 * 8;
        }
        if ((*(JGeometry::TVec3f*)(p + 0xc)).y <= lbl_80542F00 + *(f32*)(p + 0x28) && (*(JGeometry::TVec3f*)(p + 0xc)).y >= *(f32*)(p + 0x28) - lbl_80542F00) {
            (*(JGeometry::TVec3f*)(p + 0xc)).y = *(f32*)(p + 0x28);
        } else {
            (*(JGeometry::TVec3f*)(p + 0xc)).y = (s32)((s32)(*(JGeometry::TVec3f*)(p + 0xc)).y + 4) / 8 * 8;
        }
        (*(JGeometry::TVec3f*)(p + 0x230)) = (*(JGeometry::TVec3f*)(p + 0xc));
        (*(JGeometry::TVec3f*)(p + 0x3c)).x = lbl_80542EDC;
        (*(JGeometry::TVec3f*)(p + 0x3c)).y = lbl_80542EDC;
        (*(JGeometry::TVec3f*)(p + 0x3c)).z = lbl_80542EDC;
        *(JGeometry::TVec3f*)(p + 0x18) = (*(JGeometry::TVec3f*)(p + 0xc));
        this_->v10(0xff, 1);
        *(s32*)(p + 0x240) = 0;
        *(s32*)(p + 0x244) = 1;
        return;
    }
    JGeometry::TVec3f previous((*(JGeometry::TVec3f*)(p + 0xc)));
    (*(JGeometry::TVec3f*)(p + 0xc)).add((*(JGeometry::TVec3f*)(p + 0x3c)));
    if ((u8)(*(JGeometry::TVec3f*)(p + 0x3c)).isZero() == 0) {
        if (*(s32*)(p + 0x9c) >= 0) (*(JGeometry::TVec3f*)(p + 0xc)) = previous;
        return;
    }
    if (fn_80239108(*(s32*)(p + 0x198)) < 1) return;
    if (!(PSVECDistance(&(*(JGeometry::TVec3f*)(p + 0xc)), (JGeometry::TVec3f*)(p + 0x24)) < lbl_80542EEC)) return;
    s32 direction = fn_80238BC4(*(s32*)(p + 0x198));
    JGeometry::TVec3f step;
    JGeometry::TVec3f savedPos((*(JGeometry::TVec3f*)(p + 0xc)));
    step.x = lbl_804A79E0[direction].x;
    step.y = lbl_804A79E0[direction].y;
    step.z = lbl_804A79E0[direction].z;
    if (*(s32*)(p + 0x240) != 0) {
        s32 hit = fn_80239558((f32*)&bounds, *(s32*)(p + 4), *(s32*)(p + 0x198));
        if (*(s32*)(p + 0x240) - 1 != hit) return;
    }
    if (direction != (s32)(*(u32*)(p + 0x90) & 3)) return;
    if (!fn_80374964(this_, direction)) return;
    if (*(u8*)(p + 0x248) == 0) {
        fn_802D7584(fn_802D6A9C(), *(s32*)(p + 0x16c), direction + 1);
    }
    (*(JGeometry::TVec3f*)(p + 0xc)).add(step);
    if (fn_801F2618(this_, 0, 0)) {
        (*(JGeometry::TVec3f*)(p + 0xc)) = savedPos;
        return;
    }
    (*(JGeometry::TVec3f*)(p + 0xc)) = savedPos;
    if (direction >= 0 && direction < 4) {
    fn_80238E08(*(s32*)(p + 0x198));
    (*(JGeometry::TVec3f*)(p + 0x3c)).set(lbl_804750C0[direction]);
    probe = (*(JGeometry::TVec3f*)(p + 0x3c));
    probe.normalize();
    probe.scale(lbl_80542EFC);
    probe.add((*(JGeometry::TVec3f*)(p + 0xc)));
    if (fn_8022461C(&probe, *(s32*)(p + 4)) == 0x50) {
        (*(JGeometry::TVec3f*)(p + 0x3c)).normalize();
        (*(JGeometry::TVec3f*)(p + 0x3c)).scale(lbl_80542ED8);
    }
    (*(JGeometry::TVec3f*)(p + 0x230)).x = (*(JGeometry::TVec3f*)(p + 0xc)).x;
    (*(JGeometry::TVec3f*)(p + 0x230)).y = (*(JGeometry::TVec3f*)(p + 0xc)).y;
    (*(JGeometry::TVec3f*)(p + 0x230)).z = (*(JGeometry::TVec3f*)(p + 0xc)).z;
    fn_801F0E34(this_, 0x30004, 0);
    }
}

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F78F4(void* a, u32 b, s32 c);
extern "C" void* fn_801F666C(void* a, s32 b);
extern "C" u8 fn_8028D4DC(void* a, s32 b, s32 c);
extern "C" u8* lbl_8053AAF8;
extern "C" const f32 lbl_80542EDC;
extern "C" const f32 lbl_80542F10;
extern "C" const f32 lbl_80542F14;
extern "C" const f32 lbl_80542F18;
extern "C" void fn_803754E8(Actor* this_) {
    s32 mask;
    u8* p = (u8*)this_;
    s32 idx;
    s32 mode;
    union {
        u32 i;
        f32 f;
    } bits;
    f32 fx;
    f32 fy;

    *(f32*)(p + 0x3c) = lbl_80542EDC;
    *(f32*)(p + 0x40) = lbl_80542EDC;
    *(f32*)(p + 0x44) = lbl_80542EDC;
    mode = (*(u32*)(p + 0x90) >> 2) & 7;
    if (mode == 5) {
        mask = 0;
        idx = -1;
        while (true) {
            idx = fn_801F78F4(fn_801F856C(), 0x42434B32, idx);
            if (idx < 0) {
                break;
            }
            if (idx == *(s32*)(p + 0x198)) {
                continue;
            }
            void* o = fn_801F666C(fn_801F856C(), idx);
            if (o != 0 && *(s32*)((u8*)o + 0x240) != 0) {
                mask |= 1 << *(s32*)((u8*)o + 0x240);
            }
        }
        f32 one;
        f32 range;
        range = lbl_80542F10;
        one = lbl_80542ED8;
        for (;;) {
            u8* rng = lbl_8053AAF8;
            *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
            bits.i = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
            *(s32*)(p + 0x240) = (s32)(range * (bits.f - one) + one);
            if ((mask & 0x1e) == 0x1e) {
                break;
            }
            if (((1 << *(s32*)(p + 0x240)) & mask) == 0) {
                break;
            }
        }
    } else {
        *(s32*)(p + 0x240) = mode;
    }
    fx = (f32)((s32)*(f32*)(p + 0xc) / 16 * 16 + 8);
    *(f32*)(p + 0x24) = fx;
    *(f32*)(p + 0xc) = fx;
    fy = (f32)((s32)*(f32*)(p + 0x10) / 16 * 16 + 8);
    *(f32*)(p + 0x28) = fy;
    *(f32*)(p + 0x10) = fy;
    JGeometry::setTVec3f((f32*)(p + 0xc), (f32*)(p + 0x230));
    *(f32*)(p + 0x60) = lbl_80542F14;
    *(f32*)(p + 0x64) = lbl_80542F14;
    *(f32*)(p + 0x68) = lbl_80542F18;
    *(f32*)(p + 0x6c) = lbl_80542F18;
    *(f32*)(p + 0x80) = lbl_80542F14;
    *(f32*)(p + 0x84) = lbl_80542F14;
    *(f32*)(p + 0x88) = lbl_80542F18;
    *(f32*)(p + 0x8c) = lbl_80542F18;
    *(s32*)(p + 0x1a4) = 1;
    *(s32*)(p + 0xb8) = 2;
    *(s32*)(p + 0x244) = 0;
    *(u8*)(p + 0x248) = (*(u32*)(p + 0x90) >> 5) & 1;
    if (*(u8*)(p + 0x248) == 0 && fn_8028D4DC(p + 0xc, 0, *(s32*)(p + 0x16c)) != 0) {
        *(s32*)(p + 0x244) = 1;
        this_->v10(0xff, 1);
        *(s32*)(p + 0x240) = 0;
    }
    if (((*(u32*)(p + 0x90) >> 8) & 0xf) != 0) {
        *(s32*)(p + 0x244) = 1;
    }
}

extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void fn_8037574C(void) {
    static u32 c0[3], c1[3], c2[3], c3[3], c4[3], c5[3], c6[3], c7[3], c8[3];
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, c0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, c1);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, c2);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, c3);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, c4);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, c5);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, c6);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, c7);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, c8);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

