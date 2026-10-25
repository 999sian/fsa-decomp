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
struct VSub8045 {
    virtual void v0(void);
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void** call5(void* a, u32* b);
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
extern f32 __float_epsilon;
extern "C" void* fn_8045B154(u8* p, u32* param_2) {
    u8 kind = ((u8*)param_2)[1];
    void** h;
    void* mgr = *(void**)((u8*)lbl_8053AF80 + 0x34);
    s32 i;

    switch (*(s32*)param_2) {
    case 0x20037: {
        u32 d = 0x10002;
        ((void (*)(void*, u32*))(*(void***)(p + 8))[5])(p, &d);
        break;
    }
    case 0x2001f:
    case 0x20035:
    case 0x20054:
    case 0x20055:
    case 0x20056:
    case 0x2005f: {
        u32 a = 0x10003;
        stopSoundID__8JAISeMgrF10JAISoundID(mgr, &a);
        break;
    }
    case 0x20029: {
        u32 b = 0x10009;
        ((void (*)(void*, u32*))(*(void***)(p + 8))[5])(p, &b);
        break;
    }
    case 0x20032: {
        u32 c = 0x20032;
        stopSoundID__8JAISeMgrF10JAISoundID(mgr, &c);
        break;
    }
    case 0x20049: {
        u32 e = *param_2;
        if (getHandleSoundID__15JAISoundHandlesF10JAISoundID(p, &e) != 0) {
            return NULL;
        }
        break;
    }
    }

    if (kind == 1) {
        for (i = 0; i < *(s32*)(p + 4); i++) {
            void* snd = ((void**)*(void**)p)[i];
            if (snd != NULL) {
                u32 sid = *(u32*)((u8*)snd + 0x18);
                if (((u8*)&sid)[1] == 1 && sid != 0x10009 && sid != 0x1000d) {
                    stop__8JAISoundFUl(snd, 0);
                    break;
                }
            }
        }
    }

    {
        u32 f = *param_2;
        h = (void**)fn_80456334(p, &f, 0);
    }
    if (h == NULL) {
        return NULL;
    }
    if (*h != NULL && *param_2 != 0x20033 && *param_2 != 0x20049) {
        if (lbl_8053AF88 == 0) {
            __ct__Q25JMath13TRandom_fast_FUl(&lbl_8053AF8C, 0);
            lbl_8053AF88 = 1;
        }
        if (*(s8*)(p + 0x5c) >= 0 && *(s8*)(p + 0x5c) < 4) {
            if (kind == 1) {
                movePitch__18JAISoundParamsMoveFfUl((u8*)*h + 0x48, lbl_80491680[*(s8*)(p + 0x5c)], 0);
            } else if (kind == 2) {
                f32 v;
                u32 bits;
                lbl_8053AF8C = lbl_8053AF8C * 0x19660d + 0x3c6ef35f;
                bits = (lbl_8053AF8C >> 9) | 0x3f800000;
                v = *(f32*)&bits - 1.0f;
                movePitch__18JAISoundParamsMoveFfUl((u8*)*h + 0x48, 1.0f + (0.03f * v - 0.015f * (1.0f - __float_epsilon)), 0);
            }
        }
    }
    return h;
}

extern "C" char* fn_8045B46C(char* p, unsigned char value, long a, long b, long c) {
    __ct__14WaveControllerFlll(p, a, b, c);
    *(void**)(p + 8) = lbl_804B20F8;
    *(void**)(p + 0x18) = lbl_804B20F8 + 0x24;
    *(unsigned char*)(p + 0x5c) = value;
    return p;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

