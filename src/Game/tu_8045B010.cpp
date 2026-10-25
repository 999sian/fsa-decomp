#include "types.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"


extern "C" void* fn_8045A640(void*);
extern "C" u16 fn_8045ABC8(void* param_1, u8* param_2);
extern "C" void fn_8045AD64(void*);
extern "C" void __ct__14WaveControllerFlll(void*, long, long, long);
extern "C" unsigned char lbl_804B20F8[];
#pragma mark fn_8045B010
extern "C" void fn_8045AD64(void* p);
#pragma exceptions off
extern "C" void fn_8045B010(void* p) {
    void (*call)(void*) = fn_8045AD64;
    p = (u8*)p - 4;
    call(p);
}
#pragma exceptions reset
extern "C" u16 fn_8045B018(void* p, u8* q) {
    u16 (*call)(void*, u8*) = fn_8045ABC8;
    p = (char*)p - 4;
    return call(p, q);
}
#pragma exceptions reset
extern "C" void* fn_8045A640(void* p);
void* fn_8045A640(void* p);
#pragma optimization_level 4
extern "C" void* fn_8045B020(void* p) {
    return fn_8045A640((void*)((u32)p - 8));
}
#pragma optimization_level reset
extern "C" s32 fn_8045A6F4(void* p);
extern "C" s32 fn_8045B028(void* p) {
    return fn_8045A6F4((char*)p - 8);
}

extern "C" void fn_80458880(void* a, u32 b, s32 c);
extern "C" void fn_80458F04(void* a, u32 b);
extern "C" void fn_80458FF0(void* a, u32 b, s32 c, s32 d);
extern "C" void* fn_80456334(void* a, u32* b, s32 c);
extern "C" void writePort__8JASTrackFUlUs(void* a, u32 b, u16 c);
extern void* lbl_8053AF80;
extern u32 lbl_8052DEE0[];
struct Holder8045 {
    u32 pad[2];
    void** vt;
};
struct VObj8045 {
    virtual void v0(void);
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual u32 v8(void);
};
extern "C" void fn_8045B030(void* param_1, u8 param_2, s8 param_3) {
    u32 w;
    u8 sec;
    u32 local;
    void** piVar2 = 0;

    w = lbl_8052DEE0[param_2];
    sec = ((u8*)&w)[1];
    if (((u8*)&w)[0] == 1) {
        if (w == 0x1000002 || w == 0x1000023) {
            fn_80458F04(lbl_8053AF80, w);
        } else {
            fn_80458FF0(lbl_8053AF80, w, 1, 0);
        }
        return;
    }
    if (sec == 2 || sec == 1) {
        local = w;
        piVar2 = ((void** (*)(void*, u32*))((Holder8045*)param_1)->vt[5])(param_1, &local);
    } else if (sec == 0) {
        fn_80458880(lbl_8053AF80, w, -1);
    } else {
        u32 tmp = w;
        piVar2 = (void**)fn_80456334(param_1, &tmp, 0);
    }
    if (param_3 != 0 && piVar2 != 0) {
        VObj8045* obj = (VObj8045*)*piVar2;
        if (obj != 0) {
            u32 r = obj->v8();
            writePort__8JASTrackFUlUs((void*)r, 9, param_3);
        }
    }
}

extern "C" void stopSoundID__8JAISeMgrF10JAISoundID(void* self, u32* id);
extern "C" s32 getHandleSoundID__15JAISoundHandlesF10JAISoundID(void* self, u32* id);
extern "C" void stop__8JAISoundFUl(void* self, u32 x);
extern "C" void movePitch__18JAISoundParamsMoveFfUl(void* self, f32 x, u32 y);
extern "C" void __ct__Q25JMath13TRandom_fast_FUl(void* self, u32 x);
extern u32 lbl_8053AF8C;
extern s8 lbl_8053AF88;
extern f32 lbl_80491680[];
#include "JSystem/JAudio/JAUSoundObject.h"
#include "JSystem/JAudio/Interface/JAISeMgr.h"
static inline f32 randomWavePitch8045(JMath::TRandom_fast_* random, f32 width, f32 half) {
    f32 value;
    f32 epsilon;
    epsilon = 1.0f - ((f32*)&__float_epsilon)[0];
    value = random->get_ufloat_1();
    value = width * value;
    value -= half * epsilon;
    return 1.0f + value;
}
#pragma opt_common_subs off
#pragma opt_propagation reset
extern "C" void* fn_8045B154(u8* p, JAISoundID soundID) {
    u32* param_2 = (u32*)&soundID;
    void* mgr;
    s32 id;
    u32 kind;
    void** h;
    id = *(s32*)param_2;
    kind = *param_2 >> 16;
    mgr = *(void**)((u8*)lbl_8053AF80 + 0x34);
    s32 i;
    JAISoundID sid;

    switch (id) {
    case 0x20037: {
        ((JAUSoundObject*)p)->startSound(JAISoundID(0x10002));
        break;
    }
    case 0x20036:
        break;
    case 0x2001f:
    case 0x20035:
    case 0x20054:
    case 0x20055:
    case 0x20056:
    case 0x2005f: {
        ((JAISeMgr*)mgr)->stopSoundID(JAISoundID(0x10003));
        break;
    }
    case 0x20029: {
        ((JAUSoundObject*)p)->startSound(JAISoundID(0x10009));
        break;
    }
    case 0x20032: {
        ((JAISeMgr*)mgr)->stopSoundID(JAISoundID(0x20032));
        break;
    }
    case 0x20049: {
        if (((JAISoundHandles*)p)->getHandleSoundID(*(JAISoundID*)param_2) != 0) {
            return NULL;
        }
        break;
    }
    }

    if ((u8)kind == 1) {
        s32 count = *(s32*)(p + 4);
        for (i = 0; count > 0; count--, i += 4) {
            void* snd = *(void**)((u8*)*(void**)p + i);
            if (snd != NULL) {
                sid = ((JAISound*)snd)->getID();
                if (sid.mId.mBytes.mGroupId == 1 && sid != 0x10009 && sid != 0x1000d) {
                    stop__8JAISoundFUl(snd, 0);
                    break;
                }
            }
        }
    }

    const JAISoundID& request = JAISoundID(*param_2);
    h = (void**)fn_80456334(p, (u32*)&request, 0);
    if (h == NULL) {
        return NULL;
    }
    if (*h == NULL) return h;
    if (*param_2 != 0x20033 && *param_2 != 0x20049) {
        if (lbl_8053AF88 == 0) {
            __ct__Q25JMath13TRandom_fast_FUl(&lbl_8053AF8C, 0);
            lbl_8053AF88 = 1;
        }
        int pitchIndex = *(s8*)(p + 0x5c);
        if (pitchIndex >= 0 && pitchIndex < 4) {
            if ((u8)kind == 1) {
                movePitch__18JAISoundParamsMoveFfUl((u8*)*h + 0x48, lbl_80491680[pitchIndex], 0);
            } else if ((u8)kind == 2) {
                movePitch__18JAISoundParamsMoveFfUl((u8*)*h + 0x48,
                    randomWavePitch8045((JMath::TRandom_fast_*)&lbl_8053AF8C, 0.03f, 0.015f), 0);
            }
        }
    }
    return h;
}
#pragma opt_common_subs reset
extern "C" char* fn_8045B46C(char* p, unsigned char value, long a, long b, long c) {
    __ct__14WaveControllerFlll(p, a, b, c);
    *(void**)(p + 8) = lbl_804B20F8;
    *(void**)(p + 0x18) = lbl_804B20F8 + 0x24;
    *(unsigned char*)(p + 0x5c) = value;
    return p;
}

void fn_8045B4CC(void) {
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

