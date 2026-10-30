// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "types.h"
#include "JSystem/JAudio/System/JASHeapCtrl.h"
#include "JSystem/JAudio/System/JASSoundParams.h"

extern "C" const f32 lbl_8053B2B0;
extern "C" const f32 lbl_8053B2B4;
extern "C" const f32 lbl_8053B2B8;
extern "C" const f32 lbl_8053B2BC;
extern "C" const f32 lbl_8053B2C0;
extern "C" const f32 lbl_8053B2C4;
extern "C" const f32 lbl_8053B2C8;
extern "C" const f32 lbl_8053B2CC;
extern "C" const f32 lbl_8053B2D0;
extern "C" const f32 lbl_8053B2D4;
extern "C" const f32 lbl_8053B2D8;
extern "C" const f32 lbl_8053B2DC;
extern "C" void* __vt__11JAIAudience[];
extern "C" const f64 lbl_8053B2E0;
extern "C" void* lbl_8049552C[];
extern "C" void* lbl_80495518[];
extern "C" void __dt__10JAIAudibleFv(void*, short);

extern "C" void* lbl_804954D8[];
extern "C" void* lbl_804954F8[];
extern "C" void* lbl_80495480[];
extern "C" void* lbl_80495450[];
extern "C" void __dt__11JAIAudienceFv(void*, short);

class JAIAudience {
public:
    ~JAIAudience();
};

extern "C" void fn_8003C8D8(char* p) {
    *(f32*)(p + 0x3c) = (*(f32*)(p + 0x20) - *(f32*)(p + 0x1c)) / *(f32*)(p + 0x10);
    *(f32*)(p + 0x40) = (*(f32*)(p + 0x18) - *(f32*)(p + 0x1c)) / *(f32*)(p + 0x14);
    *(f32*)(p + 0x44) = (*(f32*)(p + 0xc) - lbl_8053B2CC) / (*(f32*)(p + 0x4) - *(f32*)(p + 0x8));
    *(f32*)(p + 0x48) = (f32)*(u32*)(p + 0x38) / (*(f32*)(p + 0x4) - *(f32*)(p + 0x8));
    *(f32*)(p + 0x4c) = (*(f32*)(p + 0x28) - *(f32*)(p + 0x24)) / (*(f32*)(p + 0x4) - *(f32*)(p + 0x8));
}

extern "C" void fn_8003C984(char* p) {
    void* lbl = lbl_80495450;
    void* vt = (void*)__vt__11JAIAudience;
    *(void**)p = vt;
    *(void**)p = lbl;
    *(f32*)(p + 0x4) = lbl_8053B2B0;
    *(f32*)(p + 0x8) = lbl_8053B2B4;
    *(f32*)(p + 0xc) = lbl_8053B2B8;
    *(f32*)(p + 0x14) = lbl_8053B2BC;
    *(f32*)(p + 0x10) = lbl_8053B2C0;
    *(f32*)(p + 0x28) = lbl_8053B2C4;
    *(f32*)(p + 0x24) = lbl_8053B2C8;
    *(f32*)(p + 0x18) = lbl_8053B2CC;
    *(f32*)(p + 0x1c) = lbl_8053B2D0;
    *(f32*)(p + 0x20) = lbl_8053B2C8;
    *(f32*)(p + 0x2c) = lbl_8053B2D4;
    *(u32*)(p + 0x38) = 0xff;
    *(f32*)(p + 0x30) = lbl_8053B2D8;
    *(f32*)(p + 0x34) = lbl_8053B2DC;
    *(f32*)(p + 0x3c) = (*(f32*)(p + 0x20) - *(f32*)(p + 0x1c)) / *(f32*)(p + 0x10);
    *(f32*)(p + 0x40) = (*(f32*)(p + 0x18) - *(f32*)(p + 0x1c)) / *(f32*)(p + 0x14);
    *(f32*)((unsigned short)p + 0x44) = (*(f32*)(p + 0xc) - lbl_8053B2CC) / (*(f32*)(p + 0x4) - *(f32*)(p + 0x8));
    *(f32*)(p + 0x48) = (f32)*(u32*)(p + 0x38) / (*(f32*)(p + 0x4) - *(f32*)(p + 0x8));
    *(f32*)(p + 0x4c) = (*(f32*)(p + 0x28) - *(f32*)(p + 0x24)) / (*(f32*)(p + 0x4) - *(f32*)(p + 0x8));
}

extern "C" void** fn_8003CAB0(void** p, short del) {
    if (p != 0) {
        *p = lbl_804954D8;
        if (p != 0) {
            *p = lbl_804954F8;
            if (p != 0) {
                *p = lbl_80495480;
                if (p != 0) {
                    *p = lbl_80495450;
                    __dt__11JAIAudienceFv(p, 0);
                }
            }
        }
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void** fn_8003CB40(void** p, short del) {
    if (p != 0) {
        *p = lbl_804954F8;
        if (p != 0) {
            *p = lbl_80495480;
            if (p != 0) {
                *p = lbl_80495450;
                __dt__11JAIAudienceFv(p, 0);
            }
        }
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void* fn_8003CBC0(char* p) {
    return *(void**)(p + 0x50);
}

extern "C" const f32 lbl_8053B2C8;
extern "C" const f32 lbl_8053B2D4;
extern "C" const f32 lbl_8053B2E8;
extern "C" int __float_epsilon[];
#pragma opt_common_subs off
extern "C" void fn_8003CBC8(char* p, JASSoundParams* out, char* obj, int index) {
    struct VObj {
        virtual void v00();
        virtual JASSoundParams* v01(int);
    };
    struct Params {
        f32 mVolume;
        f32 mFxMix;
        f32 mPitch;
        f32 mPan;
        f32 mDolby;
    };
    char* item = ((char**)(obj + 0x18))[index];
    if (item != 0) {
        Params params;
        params.mFxMix = lbl_8053B2C8;
        params.mVolume = lbl_8053B2CC;
        params.mPitch = lbl_8053B2CC;
        params.mPan = lbl_8053B2D4;
        params.mDolby = lbl_8053B2C8;
        if (((obj[0x10] >> 2) & 1) != 0) {
            f32 d = *(f32*)(item + 0x20);
            f32 vol;
            if (d > *(f32*)(p + 0x4)) {
                vol = *(f32*)(p + 0xc);
            } else if (!(d < *(f32*)(p + 0x8))) {
                vol = *(f32*)(p + 0x44) * (d - *(f32*)(p + 0x8)) + lbl_8053B2CC;
                if (vol < lbl_8053B2C8) {
                    vol = lbl_8053B2C8;
                } else if (vol > lbl_8053B2CC) {
                    vol = lbl_8053B2CC;
                }
            } else {
                vol = lbl_8053B2CC;
            }
            params.mVolume = vol;
        } else {
            params.mVolume = lbl_8053B2CC;
        }
        if (((obj[0x11] >> 6) & 1) != 0) {
            f32 v = *(f32*)(item + 0x1c);
            f32 dolby;
            if (v > *(f32*)(p + 0x14)) {
                dolby = *(f32*)(p + 0x18);
            } else if (v < *(f32*)(p + 0x10)) {
                dolby = *(f32*)(p + 0x20);
            } else if (v < lbl_8053B2C8) {
                dolby = *(f32*)(p + 0x3c) * v + *(f32*)(p + 0x1c);
            } else {
                dolby = *(f32*)(p + 0x40) * v + *(f32*)(p + 0x1c);
            }
            params.mDolby = dolby;
        } else {
            params.mDolby = *(f32*)(p + 0x1c);
        }
        if (((obj[0x11] >> 7) & 1) != 0) {
            if (*(int*)(p + 0x50) > 2) {
                params.mPan = (index & 1) ? lbl_8053B2CC : lbl_8053B2C8;
            } else {
                f32 d = *(f32*)(item + 0x20);
                f32 r;
                if (d <= lbl_8053B2E8 * *(f32*)__float_epsilon) {
                    r = lbl_8053B2C8;
                } else {
                    r = *(f32*)(item + 0x14) / d;
                }
                params.mPan = r * *(f32*)(p + 0x2c) + lbl_8053B2D4;
            }
        } else {
            params.mPan = lbl_8053B2D4;
        }
        params.mPitch = lbl_8053B2CC;
        if (((obj[0x10] >> 1) & 1) != 0) {
            f32 d = *(f32*)(item + 0x20);
            f32 fx;
            if (d > *(f32*)(p + 0x4)) {
                fx = *(f32*)(p + 0x28);
            } else if (d < *(f32*)(p + 0x8)) {
                fx = *(f32*)(p + 0x24);
            } else {
                fx = *(f32*)(p + 0x4c) * (d - *(f32*)(p + 0x8)) + *(f32*)(p + 0x24);
            }
            params.mFxMix = fx;
        } else {
            params.mFxMix = lbl_8053B2C8;
        }
        ((VObj*)obj)->v01(index)->combine(*out, *(JASSoundParams*)&params);
    }
}
#pragma opt_common_subs reset
extern "C" void* fn_8003CE04(char* p, int i) {
    void* r = ((void**)(p + 0x18))[i];
    if (r != 0) {
        return r;
    }
    return 0;
}

extern "C" void PSMTXMultVec(void*, void*, void*);
extern "C" f32 PSVECMag(void*);
extern "C" u32 __cvt_fp2unsigned(f64);

struct fn_8003CE20_Flags {
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 b3 : 1;
    u8 b2 : 1;
    u8 b1 : 1;
    u8 b0 : 1;
};

static inline u32 fn_8003CE20_level(char* self, f32 dist, bool loud) {
    if (dist > *(f32*)(self + 4)) {
        if (loud) {
            return 0xffffffff;
        }
        return *(u32*)(self + 0x38);
    }
    if (dist < *(f32*)(self + 8)) {
        return 0;
    }
    return __cvt_fp2unsigned(*(f32*)(self + 0x48) * (dist - *(f32*)(self + 8)));
}
extern "C" u32 fn_8003CE20(char* param_1, char* param_2) {
    u32 local[2];

    if (((fn_8003CE20_Flags*)(param_2 + 0x10))->b3 == 0) {
        char* item;
        char* p = param_2;
        char* m = param_1;
        for (int i = 0; i < *(int*)(param_1 + 0x50); i++) {
            item = *(char**)(p + 0x18);
            if (item != 0) {
                PSMTXMultVec(m + 0x54, param_2 + 4, item + 0x14);
                *(f32*)(item + 0x20) = PSVECMag(item + 0x14);
            }
            p += 4;
            m += 0x30;
        }
        return 0;
    }
    u32* out = local;
    char* p = param_2;
    char* m = param_1;
    char* item;
    u32 min = 0xffffffff;
    for (int i = 0; i < *(int*)(param_1 + 0x50); i++) {
        item = *(char**)(p + 0x18);
        if (item != 0) {
            PSMTXMultVec(m + 0x54, param_2 + 4, item + 0x14);
            *(f32*)(item + 0x20) = PSVECMag(item + 0x14);
            *out = fn_8003CE20_level(param_1, *(f32*)(item + 0x20), ((fn_8003CE20_Flags*)(param_2 + 0x10))->b0);
            if (*out < min) {
                min = *out;
            }
        }
        p += 4;
        m += 0x30;
        out++;
    }
    return min;
}

extern "C" void fn_8003CF84(void* param_1, void** param_2) {
    struct VObj {
        virtual void v00(int);
    };
    if (param_2 != 0) {
        ((VObj*)param_2)->v00(1);
    }
}

class JASPoolObj3_FSA;
extern "C" void** fn_8003CFC0(void** p, short del) {
    if (p != 0) {
        *p = lbl_8049552C;
        if (p != 0) {
            *p = lbl_80495518;
            __dt__10JAIAudibleFv(p, 0);
        }
        if (del > 0) {
            JASPoolAllocObject<JASPoolObj3_FSA>::operator delete(p, 0x40);
        }
    }
    return p;
}

extern "C" void* sInstance__33JASGlobalInstance__12JAUSoundInfo;
extern "C" void* __vt__10JAIAudible[];
extern "C" void fn_8003B0B0(float* v);
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, unsigned long size, unsigned long n);
extern "C" void** fn_8003D03C(char* param_1, f32* param_2, u32* param_3, s32 param_4, u32 param_5) {
    struct Pair {
        s16 a;
        s16 b;
    };
    s32 i;
    char* m;
    void** q;
    void** obj;
    char* p;
    u32 flags;
    u32 key;
    u32 w;
    Pair pair;
    flags = param_5 | ~((1 << *(u32*)(param_1 + 0x50)) - 1);
    if (flags == 0xffffffff) {
        return 0;
    }
    obj = (void**)JASPoolAllocObject<JASPoolObj3_FSA>::operator new(0x40);
    if (obj != 0) {
        p = (char*)obj;
        *obj = __vt__10JAIAudible;
        *obj = lbl_80495518;
        __construct_array(p + 0x1c, fn_8003B0B0, 0, 0x24, 1);
        *(s32*)(p + 0x10) = -1;
        *(f32*)(p + 0x4) = param_2[0];
        *(f32*)(p + 0x8) = param_2[1];
        *(f32*)(p + 0xc) = param_2[2];
        if ((flags & 1) == 0) {
            *(f32*)(p + 0x1c) = lbl_8053B2CC;
            *(f32*)(p + 0x24) = lbl_8053B2CC;
            *(f32*)(p + 0x20) = lbl_8053B2C8;
            *(f32*)(p + 0x28) = lbl_8053B2D4;
            *(f32*)(p + 0x2c) = lbl_8053B2C8;
            *(void**)(p + 0x18) = p + 0x1c;
        } else {
            *(void**)(p + 0x18) = 0;
        }
        *obj = lbl_8049552C;
    }
    if (obj == 0) {
        return 0;
    }
    q = obj;
    m = param_1;
    for (i = 0; i < *(s32*)(param_1 + 0x50); i++) {
        char* item = (char*)q[6];
        if (item != 0) {
            PSMTXMultVec(m + 0x54, p + 4, item + 0x14);
            *(f32*)(item + 0x20) = PSVECMag(item + 0x14);
        }
        q++;
        m += 0x30;
    }
    if (sInstance__33JASGlobalInstance__12JAUSoundInfo != 0) {
        key = *(u32*)param_3;
        pair.a = ((s16 (*)(void*, u32*))((void**)*(void**)sInstance__33JASGlobalInstance__12JAUSoundInfo)[2])(sInstance__33JASGlobalInstance__12JAUSoundInfo, &key);
        pair.b = -1;
        w = *(u32*)&pair;
        *(u32*)(p + 0x10) = w;
    }
    return obj;
}

extern "C" void* lbl_80495518[];
extern "C" void __dt__10JAIAudibleFv(void*, short);
extern "C" void** fn_8003D200(void** p, short del) {
    if (p != 0) {
        *p = lbl_80495518;
        __dt__10JAIAudibleFv(p, 0);
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_8003D260(void) {
}
