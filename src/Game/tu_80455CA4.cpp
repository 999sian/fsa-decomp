#include "types.h"
#include "JSystem/JAudio/Interface/JAISound.h"
#include "JSystem/JAudio/Interface/JAISoundParams.h"
#include "JSystem/JAudio/JAUSoundObject.h"
#include "JSystem/JKernel/JKRDisposer.h"

class WaveController {
public:
    WaveController(s32 pos, s32 heap, s32 handles);
    JAUSoundObject mSound;
    JKRDisposer mDisposer;
    u8 m30;
    u8 m31;
    JGeometry::TVec3f* mPos;
    JGeometry::TVec3f mPosCopy;
    u8 m44;
    u8 m45;
    f32 m48;
    f32 m4C;
    u8 m50;
    u8 m51;
    u8 m52;
    JAISoundID m54;
    JAISoundID m58;
};


extern u8* lbl_8053AF80;
typedef void (*VFn)(void*);
typedef u32 (*VFnArg)(void*, void*);
extern "C" void writePort__8JASTrackFUlUs(void* a, u32 b, u16 c);
#pragma exceptions off
extern "C" void fn_80455CA4(u8* p, void** snd, const f32* __restrict src, u32* id) {
    if (src[0] < 0.0f) {
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->movePan(0.0f, 0);
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(0.4f, 0);
        return;
    }
    if (src[0] > 1.0f) {
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->movePan(1.0f, 0);
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(0.4f, 0);
        return;
    }
    if (src[1] < 0.0f) {
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->movePan(src[0], 0);
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(0.4f, 0);
        return;
    }
    if (src[1] > 1.0f) {
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->movePan(src[0], 0);
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(0.4f, 0);
        return;
    }
    if (src[0] < 0.1f || src[1] < 0.1f) {
        f32 m = (src[0] <= src[1]) ? src[0] : src[1];
        f32 v = 0.4f + 10.0f * m;
        if (v > 1.0f) {
            v = 1.0f;
        }
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(v, 0);
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->movePan(src[0], 0);
        return;
    }
    if (src[0] > 0.9f || src[1] > 0.9f) {
        f32 m = (src[0] >= src[1]) ? src[0] : src[1];
        f32 v = 0.4f + 10.0f * (1.0f - m);
        if (v > 1.0f) {
            v = 1.0f;
        }
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(v, 0);
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->movePan(src[0], 0);
        return;
    }
    ((JAISoundParamsMove*)((u8*)*snd + 0x48))->movePan(src[0], 0);
    if (((u8*)id)[1] != 0) {
        if (*id != 0x30009 && *id != 0x30051 && *id != 0x3004b && *id != 0x5006d && p[0x44] != 1) {
            if (lbl_8053AF80[6] == 1) {
                ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(0.35f, 0);
            } else {
                ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(1.0f, 0);
            }
        }
    }
}
#pragma exceptions reset
extern "C" void fn_80455F40(u8* param_1, void** param_2) {
    struct SndVT {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void* v6();
    };
    void* track;

    if (param_2 != NULL && *param_2 != NULL) {
        track = ((SndVT*)*param_2)->v6();
        if (param_1[0x44] == 1) {
            writePort__8JASTrackFUlUs(track, 10, 1);
            switch (param_1[0x45]) {
            case 2:
                writePort__8JASTrackFUlUs(track, 9, 0x78);
                writePort__8JASTrackFUlUs(track, 0xb, 0);
                break;
            case 3:
                writePort__8JASTrackFUlUs(track, 0xb, 1);
                writePort__8JASTrackFUlUs(track, 9, 0x3c);
                break;
            case 1:
            default:
                writePort__8JASTrackFUlUs(track, 9, 0);
                writePort__8JASTrackFUlUs(track, 0xb, 0);
                break;
            }
        } else {
            writePort__8JASTrackFUlUs(track, 10, 0);
            switch (param_1[0x45]) {
            case 2:
                writePort__8JASTrackFUlUs(track, 9, 0x78);
                writePort__8JASTrackFUlUs(track, 0xb, 0);
                break;
            case 3:
                writePort__8JASTrackFUlUs(track, 0xb, 1);
                writePort__8JASTrackFUlUs(track, 9, 0x3c);
                break;
            case 1:
            default:
                writePort__8JASTrackFUlUs(track, 9, 0);
                writePort__8JASTrackFUlUs(track, 0xb, 0);
                break;
            }
        }
    }
}

extern "C" int fn_804560D0(void* unused, u8** p) {
    struct VObj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual u32 v18(u32*);
    };
    u32 v;
    VObj* obj = *(VObj**)(lbl_8053AF80 + 0x40);
    v = *(u32*)(*p + 0x18);
    if (obj->v18(&v) & 0x8000) {
        return 0;
    }
    return 1;
}

extern "C" void fn_80456120(u8* p) {
    struct VObj {
        u32 a;
        u32 b;
        virtual void v0();
        virtual void v1();
    };
    p[0x31] = 0;
    ((VObj*)p)->v1();
}

extern "C" void fn_80456154(u8* p) {
    f32* src = *(f32**)(p + 0x34);
    if (src != NULL) {
        *(f32*)(p + 0x38) = src[0];
        *(f32*)(p + 0x3c) = src[1];
        *(f32*)(p + 0x40) = src[2];
        *(f32**)(p + 0x14) = (f32*)(p + 0x38);
    } else {
        *(f32**)(p + 0x14) = NULL;
    }
    f32* v = *(f32**)(p + 0x14);
    if (v != NULL) {
        f32 t = v[1];
        v[1] = v[2];
        (*(f32**)(p + 0x14))[2] = t;
    }
    if (p[0x50] != 0) {
        p[0x50]--;
    }
    if (p[0x51] != 0) {
        p[0x51]--;
    }
}

extern "C" void* fn_80456334(u8* p, JAISoundID id, u32 x);
extern "C" void fn_804561D8(u8* p, JAISoundID id, u8 mode, u32 x, u8 y) {
    f32 pan;
    f32 vol;
    void** snd;

    p[0x44] = y;
    snd = (void**)fn_80456334(p, id, x);
    if (*snd == NULL) {
        return;
    }
    switch (mode) {
    case 0:
    case 1:
        pan = 0.5f;
        vol = 0.4f;
        break;
    case 2:
        pan = 1.0f;
        vol = 0.4f;
        break;
    case 3:
        pan = 0.0f;
        vol = 0.4f;
        break;
    case 4:
    default:
        pan = 0.5f;
        vol = 0.0f;
        break;
    }
    ((JAISoundParamsMove*)((u8*)*snd + 0x48))->movePan(pan, 0);
    if (y != 0) {
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(1.0f, 0);
    } else {
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(vol, 0);
    }
    if (p[0x44] != 1) {
        if (lbl_8053AF80[6] == 1) {
            ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(0.35f, 0);
        } else {
            ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(vol, 0);
        }
    }
}

extern "C" void fn_80457840(u8* p, f32* src) {
    *(f32**)(p + 0x34) = src;
    if (src != NULL) {
        *(f32*)(p + 0x38) = src[0];
        *(f32*)(p + 0x3c) = src[1];
        *(f32*)(p + 0x40) = src[2];
        *(f32**)(p + 0x14) = (f32*)(p + 0x38);
    } else {
        *(f32**)(p + 0x14) = NULL;
    }
}

extern "C" char lbl_804B1E28[];
extern "C" void __dt__11JKRDisposerFv(void*, s16);
extern "C" void __dt__14JAUSoundObjectFv(void*, s16);
extern "C" void* fn_8045787C(char* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(char**)(param_1 + 8) = lbl_804B1E28;
        *(char**)(param_1 + 0x18) = lbl_804B1E28 + 0x24;
        __dt__11JKRDisposerFv(param_1 + 0x18, 0);
        __dt__14JAUSoundObjectFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

#pragma optimization_level 3
WaveController::WaveController(s32 pos, s32 heap, s32 handles)
    : mSound((JGeometry::TVec3f*)pos, handles, (JKRHeap*)heap) {
    *(char**)((u8*)this + 8) = lbl_804B1E28;
    *(char**)((u8*)this + 0x18) = lbl_804B1E28 + 0x24;
    m31 = 1;
    mPos = (JGeometry::TVec3f*)pos;
    if ((JGeometry::TVec3f*)pos != NULL) {
        mPosCopy.x = ((JGeometry::TVec3f*)pos)->x;
        mPosCopy.y = ((JGeometry::TVec3f*)pos)->y;
        mPosCopy.z = ((JGeometry::TVec3f*)pos)->z;
        mSound.mSoundPos = &mPosCopy;
    } else {
        mSound.mSoundPos = NULL;
    }
    m44 = 0;
    m45 = 0;
    m50 = 0;
    m51 = 0;
    m52 = 0;
    m4C = 1.0f;
    m48 = 0.0f;
    m54 = JAISoundID(0x400a5);
    m58 = JAISoundID(0x3006d);
    m30 = 0;
}
#pragma optimization_level reset
#include "JSystem/JAudio/JASFakeMatchFSA.h"

