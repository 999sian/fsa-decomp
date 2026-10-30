#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JParticle/JPAEmitter.h"


extern "C" char lbl_804ABA90[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void* handle);
extern "C" int fn_80230CFC(int index);
extern "C" int fn_80230498(int index, const void* pos, s32 a1, u8 a2, s8 a3, s8 a4, u8 a5);
extern "C" const JGeometry::TVec3<f32> lbl_80471AE0[4][4];
extern "C" u8 fn_8022E438(s32 i, s32 b);
extern "C" s32 fn_8022CAF8(s32 i);
extern "C" u8 fn_8022F478(s32 i);
extern "C" u8 fn_802300EC(s32 i);
extern "C" void fn_80230AD4(s32 i);
extern "C" void* fn_8023E724(s32 i);
extern "C" u8 fn_80388EEC(s32 i);
extern "C" void fn_80230FD0(s32 i, void* p);
extern "C" void fn_80230F44(s32 i, s32 v);
extern "C" s32 fn_80336040(Actor* self) {
    u8* p = (u8*)self;
    s32 slot;
    s32 idx;
    s32 ret = 0;

    *(s32*)(p + 0x26c) = *(s32*)(p + 0x26c) + 1;
    if (*(s32*)(p + 0x26c) < 8) {
        *(s32*)(p + 0x260) = 0;
        slot = 0;
    } else if (*(s32*)(p + 0x26c) < 0x10) {
        *(s32*)(p + 0x260) = 1;
        slot = 0;
    } else if (*(s32*)(p + 0x26c) < 0x18) {
        *(s32*)(p + 0x260) = 2;
        slot = 1;
    } else {
        *(s32*)(p + 0x260) = 3;
        slot = 2;
    }

    idx = fn_80230CFC(*(s32*)(p + 0x24c));
    if (idx == 0) {
        *(s32*)(p + 0x270) = 0x2b0;
    } else if (idx == 1) {
        *(s32*)(p + 0x270) = 0x2b4;
    } else if (idx == 2) {
        *(s32*)(p + 0x270) = 0x2b8;
    } else {
        *(s32*)(p + 0x270) = 0x2bc;
    }
    *(s32*)(p + 0x270) = *(s32*)(p + 0x270) + *(s32*)(p + 0x260);

    if (*(s32*)(p + 0x26c) % 0x24 < 6) {
        *(s32*)(p + 0x264) = 0;
    } else if (*(s32*)(p + 0x26c) % 0x24 < 0xc) {
        *(s32*)(p + 0x264) = 1;
    } else if (*(s32*)(p + 0x26c) % 0x24 < 0x12) {
        *(s32*)(p + 0x264) = 0;
    } else if (*(s32*)(p + 0x26c) % 0x24 < 0x18) {
        *(s32*)(p + 0x264) = 2;
    } else if (*(s32*)(p + 0x26c) % 0x24 < 0x1e) {
        *(s32*)(p + 0x264) = 3;
    } else {
        *(s32*)(p + 0x264) = 2;
    }
    *(s32*)(p + 0x274) = (u16)(*(s32*)(p + 0x264) + 0x296);

    if (*(s32*)(p + 0x26c) > 0x28) {
        ret = 1;
    }

    JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)(p + 0xc);
    JGeometry::TVec3<f32> sum;
    JGeometry::TVec3<f32> off;
    off.x = (&lbl_80471AE0[0][0])[idx * 4 + slot].x;
    off.y = (&lbl_80471AE0[0][0])[idx * 4 + slot].y;
    off.z = (&lbl_80471AE0[0][0])[idx * 4 + slot].z;
    sum = pos;
    sum += off;
    fn_80230498(*(s32*)(p + 0x24c), &pos, *(s32*)(p + 0x270), 0xff, -0x80, -0x80, 1);
    fn_80230498(*(s32*)(p + 0x250), &sum, *(s32*)(p + 0x274), 0xff, -0x80, -0x80, 1);
    return ret;
}

extern "C" void fn_80336294(void) {
}

extern "C" JPABaseEmitter* fn_8013CC50(s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_8013CB44(JPABaseEmitter* e, void* pos, s32 a, s32 b, s32 c);
extern "C" void fn_8038BD08(s32 a, s32 b, s32 c, void* d, s32 e);
extern "C" u8 fn_80230224(s32 i, s32 b);
extern "C" void fn_80336298(Actor* self) {
    s32 i;
    s32 j;
    s32 k;
    u8* p = (u8*)self;
    JGeometry::TVec3<f32> pos;

    switch (*(s32*)(p + 0x230)) {
    case 0:
        if (p[0x285] == 1) {
            *(s32*)(p + 0x230) = 1;
            for (i = 0; i < 4; i++) {
                if (i == *(s32*)(p + 0x24c) || i == *(s32*)(p + 0x250) ||
                    (fn_8022E438(i, *(s32*)(p + 0x24c)) == 1 && (fn_8022CAF8(i) != 4 || !fn_8022F478(i)))) {
                    *(s32*)(p + 0x278) = *(s32*)(p + 0x278) + 1;
                }
            }
        } else {
            p[0x285] = 1;
            for (i = 0; i < 4; i++) {
                if (i == *(s32*)(p + 0x24c) || i == *(s32*)(p + 0x250) ||
                    (fn_8022E438(i, *(s32*)(p + 0x24c)) == 1 && (fn_8022CAF8(i) != 4 || !fn_8022F478(i)))) {
                    if (!fn_802300EC(i)) {
                        p[0x285] = 0;
                        break;
                    }
                }
            }
            if (p[0x285] == 1) {
                for (i = 0; i < 4; i++) {
                    if (i == *(s32*)(p + 0x24c) || i == *(s32*)(p + 0x250) ||
                        (fn_8022E438(i, *(s32*)(p + 0x24c)) == 1 && (fn_8022CAF8(i) != 4 || !fn_8022F478(i)))) {
                        fn_80230AD4(i);
                    }
                }
            }
        }
        break;
    case 1:
        if ((u8)fn_80336040(self) == 1) {
            for (i = 0; i < 4; i++) {
                if (i == *(s32*)(p + 0x24c) || i == *(s32*)(p + 0x250) ||
                    (fn_8022E438(i, *(s32*)(p + 0x24c)) == 1 && (fn_8022CAF8(i) != 4 || !fn_8022F478(i)))) {
                    if (*(JPABaseEmitter**)(p + 0x2a0 + i * 4) == 0) {
                        switch (i) {
                        case 0:
                            *(JPABaseEmitter**)(p + 0x2a0 + i * 4) = fn_8013CC50(*(s32*)(p + 4), p + 0xc, 0x477, 0, -1, 0, 0, 1, 1.0f);
                            break;
                        case 1:
                            *(JPABaseEmitter**)(p + 0x2a0 + i * 4) = fn_8013CC50(*(s32*)(p + 4), p + 0xc, 0x479, 0, -1, 0, 0, 1, 1.0f);
                            break;
                        case 2:
                            *(JPABaseEmitter**)(p + 0x2a0 + i * 4) = fn_8013CC50(*(s32*)(p + 4), p + 0xc, 0x476, 0, -1, 0, 0, 1, 1.0f);
                            break;
                        case 3:
                            *(JPABaseEmitter**)(p + 0x2a0 + i * 4) = fn_8013CC50(*(s32*)(p + 4), p + 0xc, 0x478, 0, -1, 0, 0, 1, 1.0f);
                            break;
                        }
                    }
                    if (*(JPABaseEmitter**)(p + 0x2b0 + i * 4) == 0) {
                        *(JPABaseEmitter**)(p + 0x2b0 + i * 4) = fn_8013CC50(*(s32*)(p + 4), p + 0xc, 0x475, 0, -1, 0, 0, 1, 1.0f);
                    }
                    p[0x281 + i] = 0;
                }
            }
            *(s32*)(p + 0x230) = 2;
            *(s32*)(p + 0x234) = 0x5a;
            *(s32*)(p + 0x25c) = 10;
            *(JGeometry::TVec3<f32>*)(p + 0x294) = *(JGeometry::TVec3<f32>*)fn_8023E724(*(s32*)(p + 0x24c));
        }
        break;
    case 2: {
        if (*(s32*)(p + 0x234) <= 0) {
            if (*(s32*)(p + 0x254) == 0) {
                s32 room = *(s32*)(p + 4);
                JGeometry::TVec3<f32> here = *(JGeometry::TVec3<f32>*)(p + 0xc);
                fn_8038BD08(*(s32*)(p + 0x24c), 0xd4, room, &here, 1);
            }
            *(s32*)(p + 0x230) = 3;
        } else {
            *(s32*)(p + 0x25c) = *(s32*)(p + 0x25c) - 1;
            if (*(s32*)(p + 0x25c) == 0) {
                *(s32*)(p + 0x258) = *(s32*)(p + 0x258) + 1;
                if (*(s32*)(p + 0x258) == 0) {
                    *(s32*)(p + 0x25c) = 8;
                } else if (*(s32*)(p + 0x258) == 1) {
                    *(s32*)(p + 0x25c) = 3;
                    fn_80230FD0(*(s32*)(p + 0x24c), (void*)0x10008);
                    fn_80230F44(*(s32*)(p + 0x24c), 0x1000002);
                } else if (*(s32*)(p + 0x258) == 2) {
                    *(s32*)(p + 0x258) = 2;
                    *(s32*)(p + 0x25c) = 0x1e;
                } else if (*(s32*)(p + 0x258) >= 3) {
                    *(s32*)(p + 0x258) = 2;
                    *(s32*)(p + 0x25c) = 0x5a;
                }
            }
        }
        j = 0;
        for (k = 0; k < 4; k++) {
            if (k == *(s32*)(p + 0x24c) || k == *(s32*)(p + 0x250) ||
                (fn_8022E438(k, *(s32*)(p + 0x24c)) == 1 && (fn_8022CAF8(k) != 4 || !fn_8022F478(k)))) {
                JGeometry::TVec3<f32> tmp(
                    *(f32*)(p + 0x294) + *(f32*)(p + 0x27c) * ((f32)j - ((f32)*(s32*)(p + 0x278) - 1.0f) / 2.0f),
                    *(f32*)(p + 0x298), *(f32*)(p + 0x29c));
                pos = tmp;
                fn_80230498(k, &pos, *(s32*)(p + 0x258) + 0x31a, 0xff, -0x80, -0x80, 1);
                if (*(JPABaseEmitter**)(p + 0x2a0 + k * 4) != 0) {
                    fn_8013CB44(*(JPABaseEmitter**)(p + 0x2a0 + k * 4), &pos, 0, -1, 1);
                }
                if (*(JPABaseEmitter**)(p + 0x2b0 + k * 4) != 0) {
                    JGeometry::TVec3<f32> pos2(
                        *(f32*)(p + 0x294) + *(f32*)(p + 0x27c) * ((f32)j - ((f32)*(s32*)(p + 0x278) - 1.0f) / 2.0f),
                        *(f32*)(p + 0x298), *(f32*)(p + 0x29c));
                    fn_8013CB44(*(JPABaseEmitter**)(p + 0x2b0 + k * 4), &pos2, 0, -1, 1);
                }
                if (p[0x280] == 0) {
                    JGeometry::TVec3<f32> pos3(
                        *(f32*)(p + 0x294) + (0.5f + *(f32*)(p + 0x27c)) * ((f32)j - ((f32)*(s32*)(p + 0x278) - 1.0f) / 2.0f),
                        *(f32*)(p + 0x298), *(f32*)(p + 0x29c));
                    if ((u8)self->v17(*(s32*)(p + 4), (f32*)&pos3)) {
                        p[0x280] = 1;
                    }
                }
                if (*(f32*)(p + 0x27c) < 16.0f && *(s32*)(p + 0x258) >= 2 && p[0x280] == 0) {
                    *(f32*)(p + 0x27c) += 0.5f;
                } else if ((*(s32*)(p + 0x258) >= 2 || p[0x280] == 1) && p[0x281 + k] == 0) {
                    JGeometry::TVec3<f32> a(6.0f + pos.x, pos.y - 29.0f, pos.z);
                    fn_8013CC50(*(s32*)(p + 4), &a, 0xcb, 0, 1, 0, 0, 1, 1.0f);
                    JGeometry::TVec3<f32> b(6.0f + pos.x, pos.y - 29.0f, pos.z);
                    fn_8013CC50(*(s32*)(p + 4), &b, 0xcc, 0, 1, 0, 0, 1, 1.0f);
                    p[0x281 + k] = 1;
                }
                j++;
            }
        }
        break;
    }
    case 3:
        if (*(s32*)(p + 0x234) <= 0 && fn_80388EEC(*(s32*)(p + 0x24c))) {
            i = 1;
            for (k = 0; k < 4; k++) {
                if (k == *(s32*)(p + 0x24c) || k == *(s32*)(p + 0x250) ||
                    (fn_8022E438(k, *(s32*)(p + 0x24c)) == 1 && (fn_8022CAF8(k) != 4 || !fn_8022F478(k)))) {
                    if (!fn_80230224(k, 0)) {
                        i = 0;
                        break;
                    }
                }
            }
            if (i == 1) {
                for (k = 0; k < 4; k++) {
                    if (*(JPABaseEmitter**)(p + 0x2a0 + k * 4) != 0) {
                        (*(JPABaseEmitter**)(p + 0x2a0 + k * 4))->becomeInvalidEmitter();
                    }
                    if (*(JPABaseEmitter**)(p + 0x2b0 + k * 4) != 0) {
                        (*(JPABaseEmitter**)(p + 0x2b0 + k * 4))->becomeInvalidEmitter();
                    }
                }
                p[0x11c] = 0;
            }
        }
        break;
    }

    if (*(s32*)(p + 0x234) > 0) {
        *(s32*)(p + 0x234) = *(s32*)(p + 0x234) - 1;
    }
    if (*(s32*)(p + 0x238) > 0) {
        *(s32*)(p + 0x238) = *(s32*)(p + 0x238) - 1;
    }
    if (*(s32*)(p + 0x23c) > 0) {
        *(s32*)(p + 0x23c) = *(s32*)(p + 0x23c) - 1;
    }
}

extern "C" void* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(void* entry, int a, f32* b, s32 d, int e);
extern "C" u16 fn_8022461C(void* a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802265DC(f32* b, int a, int c);
#pragma opt_propagation off
extern "C" u8 fn_80336C44(Actor* a, s32 b, f32* c) {
    u32 unk = *(u32*)((u8*)a + 0x198);
    s32 idx = b;
    u8* base = (u8*)fn_8020D58C();
    s32 code;
    if (fn_8020D6AC(base + base[1] * 0x784 + 4, idx, c, unk, 0) == 1) {
        return 1;
    }
    code = fn_8022461C(c, idx);
    if (code == 0 || code == 2 || code == 0x50 || code == 0x39 || code == 0xd || code == 0x61) {
        return 0;
    }
    if (code == 0x22 && ((u8*)fn_802D6A9C())[0x170] == 0) {
        return 0;
    }
    if (code == 0x25 && ((u8*)fn_802D6A9C())[0x171] == 0) {
        return 0;
    }
    if (code == 4) {
        if (((int)c[1] & 0xf) >= 8) {
            return 0;
        }
    } else if (code == 5) {
        if (((int)c[1] & 0xf) < 8) {
            return 0;
        }
    } else if (code == 6) {
        if (((int)c[0] & 0xf) >= 8) {
            return 0;
        }
    } else if (code == 7) {
        if (((int)c[0] & 0xf) < 8) {
            return 0;
        }
    }
    return fn_802265DC(c, idx, 1);
}
#pragma opt_propagation reset
extern "C" void* fn_8023E724(s32 i);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" u8 fn_8022E438(s32 i, s32 b);
extern "C" s32 fn_8022CAF8(s32 i);
extern "C" u8 fn_8022F478(s32 i);
extern "C" u8 fn_802300EC(s32 i);
extern "C" void fn_80230AD4(s32 i);
extern "C" f32 lbl_80542048;
extern "C" void fn_80336E08(Actor* self) {
    u8* p = (u8*)self;
    s32 i;
    f32 zero;
    *(s32*)(p + 0x24c) = *(s32*)(p + 0x90) & 3;
    *(s32*)(p + 0x250) = (*(s32*)(p + 0x90) >> 2) & 3;
    *(s32*)(p + 0x254) = 1;
    *(JGeometry::TVec3<f32>*)(p + 0xc) = *(JGeometry::TVec3<f32>*)fn_8023E724(*(s32*)(p + 0x24c));
    *(JGeometry::TVec3<f32>*)(p + 0x24) = *(JGeometry::TVec3<f32>*)(p + 0xc);
    *(s32*)(p + 4) = fn_8023DE58(*(s32*)(p + 0x24c));
    for (i = 0; i < 4; i++) {
        *(s32*)(p + 0x2a0 + i * 4) = 0;
        *(s32*)(p + 0x2b0 + i * 4) = 0;
        p[0x281 + i] = 1;
    }
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    p[0x285] = 1;
    for (i = 0; i < 4; i++) {
        if (i == *(s32*)(p + 0x24c) || i == *(s32*)(p + 0x250)) {
            continue;
        }
        if (fn_8022E438(i, *(s32*)(p + 0x24c)) != 1 ||
            (fn_8022CAF8(i) == 4 && (fn_8022F478(i) || fn_802300EC(i)))) {
            p[0x285] = 0;
        }
    }
    if (p[0x285] == 1) {
        for (i = 0; i < 4; i++) {
            if (i == *(s32*)(p + 0x24c) || i == *(s32*)(p + 0x250)) {
                continue;
            }
            if (fn_8022E438(i, *(s32*)(p + 0x24c)) != 1) {
                continue;
            }
            if (fn_8022CAF8(i) != 4) {
                continue;
            }
            if (fn_8022F478(i)) {
                continue;
            }
            fn_80230AD4(i);
        }
    }
    *(s32*)(p + 0x258) = 0;
    zero = lbl_80542048;
    *(f32*)(p + 0x27c) = zero;
    p[0x280] = 0;
    *(s32*)(p + 0x260) = 0;
    *(s32*)(p + 0x268) = 0;
    *(s32*)(p + 0x26c) = 0;
    *(s32*)(p + 0x270) = 0;
    *(s32*)(p + 0x274) = 0;
    *(s32*)(p + 0x264) = 0;
    *(s32*)(p + 0x278) = 0;
    *(f32*)(p + 0x29c) = zero;
    *(f32*)(p + 0x298) = zero;
    *(f32*)(p + 0x294) = zero;
    p[0x11f] = 1;
    *(s32*)(p + 0x230) = 0;
}

extern "C" Actor* fn_80337010(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804ABA90;
        for (int i = 0; i < 4; i++) {
            fn_801EE434(*(void**)((u8*)p + 0x2a0 + i * 4));
            fn_801EE434(*(void**)((u8*)p + 0x2b0 + i * 4));
        }
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" char lbl_805095F8[];
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
void __sinit_tu_80336040_cpp(void) {}

