#include "JSystem/JGeometry/Vec.h"
#include "Game/SinitPoolChain.h"


extern "C" void __dt__5ActorFv(void* p, int f);
extern void* lbl_804A5B28[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern void* lbl_804A5C88[];
extern void* fn_801F856C();
extern void* fn_801F666C(void*, s32);
extern void fn_8020B434(void*);
extern void fn_8020B3E4(void*, s32, s32, void*, s32);
extern void* fn_80207AC0(void*);
extern f32 lbl_8053F918;
extern f32 lbl_8053F91C;
extern f32 lbl_8053F920;
extern "C" void fn_80209640(void* this_, f32* out);
void operator delete(void* p);
extern "C" void* fn_80208E5C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5C88;
        if (this_ != 0) {
            *(void**)p = lbl_804A5B28;
            if (this_ != 0) {
                *(void**)p = lbl_804A4808;
                if (p + 0x270 != 0) {
                    if (p + 0x294 != 0) {
                        *(void**)(p + 0x294) = lbl_8049CC34;
                    }
                }
                __dt__5ActorFv(this_, 0);
            }
        }
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_80208EFC(char* this_) {
    switch (*(s32*)(this_ + 0x248)) {
    case 0:
    case 2:
    case 3: {
        f32 zero = lbl_8053F918;
        *(f32*)(this_ + 0x3c) = zero;
        *(f32*)(this_ + 0x40) = zero;
        *(f32*)(this_ + 0x44) = zero;
        break;
    }
    case 1: {
        f32 pos[2];
        f32 zero = lbl_8053F918;
        if (*(s32*)(this_ + 0x344) == 0) {
            fn_80209640(this_ + 0x34c, pos);
            *(f32*)(this_ + 0x3c) = pos[0];
            *(f32*)(this_ + 0x40) = pos[1];
            *(f32*)(this_ + 0x44) = zero;
        } else if (*(s32*)(this_ + 0x340) == 0) {
            *(f32*)(this_ + 0x3c) = lbl_8053F91C;
            *(f32*)(this_ + 0x40) = zero;
            *(f32*)(this_ + 0x44) = zero;
        } else {
            *(f32*)(this_ + 0x3c) = lbl_8053F920;
            *(f32*)(this_ + 0x40) = zero;
            *(f32*)(this_ + 0x44) = zero;
        }
        s32 i = 0;
        char* e = this_;
        do {
            char* actor = (char*)fn_801F666C(fn_801F856C(), *(s32*)(e + 0x2b0));
            if (actor != 0) {
                *(JGeometry::TVec2<f32>*)(actor + 0x3c) = *(JGeometry::TVec2<f32>*)(this_ + 0x3c);
                *(f32*)(actor + 0x44) = *(f32*)(this_ + 0x44);
            }
            i++;
            e += 0x24;
        } while (i < 4);
        break;
    }
    }
}

extern void fn_80207A60(void* this_);
extern void fn_8020B500(void* p);
extern f32 lbl_8053F924;
extern "C" void fn_80207A60(void* this_);
extern "C" void* fn_802D6A9C();
extern "C" void fn_8020B500(void* p);
extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void*, s32);
extern "C" void fn_80209014(char* this_) {
    fn_80207A60(this_);
    switch (*(s32*)(this_ + 0x248)) {
    case 0: {
        if ((*(s32*)(this_ + 0x348) == 0 && *(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250)) ||
            ((u8 (*)(char*))(*(void***)this_)[13])(this_)) {
            char* p = this_;
            s32 i = 0;
            while (i < 4) {
                void* a = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x2b0));
                if (a != 0) {
                    fn_8020B500(a);
                }
                i++;
                p += 0x24;
            }
            *(s32*)(this_ + 0x24c) = 0;
            *(s32*)(this_ + 0x248) = 1;
        }
    } break;
    case 1: {
        s32 i = *(s32*)(this_ + 0x4);
        char* p = (char*)fn_802D6A9C();
        f32* pf;
        if (i < 8) {
            pf = (f32*)(p + 0xcc);
        } else {
            pf = (f32*)(p + 0xdc);
        }
        if (*(f32*)(this_ + 0xc) < *pf - lbl_8053F924 || *(f32*)(this_ + 0xc) > lbl_8053F924 + pf[2]) {
            *(u8*)(this_ + 0x11c) = 0;
            for (s32 j = 0; j < 4; j++) {
                void* a = fn_801F666C(fn_801F856C(), *(s32*)(this_ + 0x2b0));
                if (a != 0) {
                    *(u8*)((char*)a + 0x11c) = 0;
                }
                this_ += 0x24;
            }
        }
    } break;
    }
}

extern "C" void fn_80209164(char* this_) {
    if (*(s32*)(this_ + 0x248) != 3) {
        *(s32*)(this_ + 0x24c) = 0;
        *(s32*)(this_ + 0x248) = 3;
    }
    for (s32 i = 0; i < 4; i++) {
        char* ptr = this_ + i * 0x24;
        void* a = fn_801F666C(fn_801F856C(), *(s32*)(ptr + 0x2b0));
        if (a != 0) {
            fn_8020B3E4(a, *(s32*)(ptr + 0x2b8), *(s32*)(ptr + 0x2bc), ptr + 0x2c0, *(s32*)(ptr + 0x2cc));
        }
    }
}

extern "C" void fn_802091EC(char* this_) {
    if (*(s32*)(this_ + 0x248) != 2) {
        *(s32*)(this_ + 0x24c) = 0;
        *(s32*)(this_ + 0x248) = 2;
    }
    for (s32 i = 0; i < 4; i++) {
        void* a = fn_801F666C(fn_801F856C(), *(s32*)(this_ + 0x2b0 + i * 0x24));
        if (a != 0) {
            fn_8020B434(a);
        }
    }
}

extern "C" void fn_80209264(char* this_) {
    *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x24);
    *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x28);
    *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x2c);
}

extern "C" void fn_801D0ED0(void* this_);
extern "C" s32 fn_801CD664(s32 n);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, void* pos, u32 arg5, s32 arg6, s32 arg7);
extern f32 lbl_8053F928;
extern f32 lbl_8053F92C;
extern f32 lbl_8053F930;
extern f32 lbl_8053F934;
extern f32 lbl_8053F938;
extern f32 lbl_8053F93C;
extern f32 lbl_8053F940;
extern f32 lbl_8053F944;
extern "C" void fn_80209280(char* this_) {
    f32 vec[2];
    f32 dx;
    f32 dy;
    fn_801D0ED0(this_);
    *(s32*)(this_ + 0x2ac) = *(u32*)(this_ + 0x90) & 3;
    if (*(s32*)(this_ + 0x2ac) >= 2 || *(s32*)(this_ + 0x2ac) < 0) {
        *(s32*)(this_ + 0x2ac) = fn_801CD664(2);
    }
    *(s32*)(this_ + 0x340) = (*(u32*)(this_ + 0x90) >> 4) & 3;
    if (*(s32*)(this_ + 0x340) >= 2 || *(s32*)(this_ + 0x340) < 0) {
        *(s32*)(this_ + 0x340) = fn_801CD664(2);
    }
    *(s32*)(this_ + 0x344) = (*(u32*)(this_ + 0x90) >> 8) & 1;
    *(s32*)(this_ + 0x348) = *(u32*)(this_ + 0x90) >> 27;
    f32 lo = lbl_8053F928;
    f32 hi = lbl_8053F92C;
    *(f32*)(this_ + 0x60) = lo;
    *(f32*)(this_ + 0x64) = lo;
    *(f32*)(this_ + 0x68) = hi;
    *(f32*)(this_ + 0x6c) = hi;
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
    *(f32*)(this_ + 0x80) = lo;
    *(f32*)(this_ + 0x84) = lo;
    *(f32*)(this_ + 0x88) = hi;
    *(f32*)(this_ + 0x8c) = hi;
    *(s32*)(this_ + 0xb0) = 0;
    *(s32*)(this_ + 0x98) = 2;
    *(u32*)(this_ + 0x230) |= 0x380;
    *(s32*)(this_ + 0x108) = 1000;
    *(s32*)(this_ + 0x244) = *(s32*)(this_ + 0x108);
    *(u8*)(this_ + 0x194) = 1;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = fn_801CD664(0x4b1) + 0x258;
    *(f32*)(this_ + 0x254) = lbl_8053F918;
    *(f32*)(this_ + 0x258) = lbl_8053F918;

    s32 flag = *(s32*)(this_ + 0x340) != 0;
    char* g = (char*)fn_802D6A9C();
    f32 x4 = lbl_8053F930 * (*(f32*)(g + 0xd0) + *(f32*)(g + 0xd8));
    f32 y2 = lbl_8053F930 * (*(f32*)(g + 0xcc) + *(f32*)(g + 0xd4));
    *(s32*)(this_ + 0x34c) = 0;
    switch (flag) {
    case 1:
        *(f32*)(this_ + 0x350) = lbl_8053F934 + *(f32*)(g + 0xd4);
        break;
    case 0:
        *(f32*)(this_ + 0x350) = *(f32*)(g + 0xcc) - lbl_8053F934;
        break;
    }
    *(f32*)(this_ + 0x354) = x4 - lbl_8053F938;
    *(s32*)(this_ + 0x358) = flag;
    *(s16*)(this_ + 0x35c) = -0x8000;
    *(s16*)(this_ + 0x35e) = 0x64;
    if (!flag) {
        *(s16*)(this_ + 0x35e) = -*(s16*)(this_ + 0x35e);
    }
    *(f32*)(this_ + 0x360) = y2 - lbl_8053F93C;
    *(f32*)(this_ + 0x364) = x4;
    *(f32*)(this_ + 0x368) = y2 + lbl_8053F93C;
    *(f32*)(this_ + 0x36c) = x4;

    vec[0] = *(f32*)(this_ + 0x350);
    vec[1] = *(f32*)(this_ + 0x354);
    *(f32*)(this_ + 0x24) = vec[0];
    if (*(s32*)(this_ + 0x344) == 0) {
        *(f32*)(this_ + 0x28) = vec[1];
    }
    *(f32*)(this_ + 0x2c) = lbl_8053F940;
    Vec pos = *(Vec*)(this_ + 0x24);
    dx = lbl_8053F918;
    dy = dx;
    switch (*(s32*)(this_ + 0x2ac)) {
    case 1:
        pos.x -= lbl_8053F940;
        dx = lbl_8053F944;
        break;
    case 0:
        pos.y -= lbl_8053F940;
        dy = lbl_8053F944;
        break;
    }

    char* e = this_;
    for (s32 i = 0; i < 4; i++) {
        *(s32*)(e + 0x2b0) = Actor_CreateByID(fn_801F856C(), 0x464f4252, *(u32*)(this_ + 4), &pos, *(u32*)(this_ + 0x198), -1, -1);
        void* a = fn_801F666C(fn_801F856C(), *(s32*)(e + 0x2b0));
        if (a != 0) {
            *(s16*)((char*)a + 0x94) = i;
        }
        pos.x += dx;
        pos.y += dy;
        e += 0x24;
    }
}

extern "C" void* fn_802095C4(char* this_) {
    fn_80207AC0(this_);
    f32 f0 = lbl_8053F918;
    *(void**)this_ = lbl_804A5C88;
    *(s32*)(this_ + 0x340) = 0;
    *(s32*)(this_ + 0x344) = 0;
    *(s32*)(this_ + 0x348) = 0;
    *(s32*)(this_ + 0x34c) = 0;
    *(f32*)(this_ + 0x350) = f0;
    *(f32*)(this_ + 0x354) = f0;
    *(s32*)(this_ + 0x358) = 0;
    *(s16*)(this_ + 0x35c) = -0x8000;
    *(s16*)(this_ + 0x35e) = 0;
    *(f32*)(this_ + 0x360) = f0;
    *(f32*)(this_ + 0x364) = f0;
    *(f32*)(this_ + 0x368) = f0;
    *(f32*)(this_ + 0x36c) = f0;
    return this_;
}

extern f32 sincosTable___5JMath[];
extern "C" void fn_80209640(void* this_, f32* out) {
    char* p = (char*)this_;
    s32 state = *(s32*)p;
    f32 oldX = *(f32*)(p + 0x4);
    f32 oldY = *(f32*)(p + 0x8);
    f32 x;
    f32 y;
    switch (state) {
    case 0: {
        bool hit = false;
        bool zero = *(s32*)(p + 0xc) == 0;
        if (zero) {
            *(f32*)(p + 0x4) += lbl_8053F91C;
            if (*(f32*)(p + 0x4) >= *(f32*)(p + 0x1c)) {
                *(f32*)(p + 0x4) = *(f32*)(p + 0x1c);
                hit = true;
            }
        } else {
            *(f32*)(p + 0x4) -= lbl_8053F91C;
            if (*(f32*)(p + 0x4) <= *(f32*)(p + 0x14)) {
                *(f32*)(p + 0x4) = *(f32*)(p + 0x14);
                hit = true;
            }
        }
        if (hit) {
            *(s32*)p = 1;
        }
    } break;
    case 1: {
        bool hit = false;
        bool zero = *(s32*)(p + 0xc) == 0;
        *(s16*)(p + 0x10) += *(s16*)(p + 0x12);
        if (zero) {
            if (*(s16*)(p + 0x10) <= 0) {
                if (*(s16*)(p + 0x12) <= 0) {
                    *(s16*)(p + 0x10) = 0;
                } else {
                    *(s16*)(p + 0x10) = (s16)0x8000;
                }
                hit = true;
            }
        } else if (*(s16*)(p + 0x10) >= 0) {
            if (*(s16*)(p + 0x12) <= 0) {
                *(s16*)(p + 0x10) = 0;
            } else {
                *(s16*)(p + 0x10) = (s16)0x8000;
            }
            hit = true;
        }
        s32 idx = (*(s16*)(p + 0x10) >> 2) & 0x3ff8;
        x = *(f32*)((char*)sincosTable___5JMath + idx) * lbl_8053F938;
        y = *(f32*)((char*)sincosTable___5JMath + idx + 4) * lbl_8053F938;
        if (zero) {
            *(f32*)(p + 0x4) = *(f32*)(p + 0x1c);
            *(f32*)(p + 0x8) = *(f32*)(p + 0x20);
        } else {
            *(f32*)(p + 0x4) = *(f32*)(p + 0x14);
            *(f32*)(p + 0x8) = *(f32*)(p + 0x18);
        }
        *(f32*)(p + 0x4) += x;
        *(f32*)(p + 0x8) += y;
        if (hit) {
            *(s32*)p = 2;
        }
    } break;
    case 2: {
        bool hit = false;
        bool nonZero = *(s32*)(p + 0xc) != 0;
        if (nonZero) {
            *(f32*)(p + 0x4) += lbl_8053F91C;
            if (*(f32*)(p + 0x4) >= *(f32*)(p + 0x1c)) {
                *(f32*)(p + 0x4) = *(f32*)(p + 0x1c);
                hit = true;
            }
        } else {
            *(f32*)(p + 0x4) -= lbl_8053F91C;
            if (*(f32*)(p + 0x4) <= *(f32*)(p + 0x14)) {
                *(f32*)(p + 0x4) = *(f32*)(p + 0x14);
                hit = true;
            }
        }
        if (hit) {
            *(s32*)p = 3;
        }
    } break;
    case 3: {
        bool hit = false;
        bool zero = *(s32*)(p + 0xc) == 0;
        *(s16*)(p + 0x10) += *(s16*)(p + 0x12);
        if (zero) {
            if (*(s16*)(p + 0x10) >= 0) {
                if (*(s16*)(p + 0x12) <= 0) {
                    *(s16*)(p + 0x10) = (s16)0x8000;
                } else {
                    *(s16*)(p + 0x10) = 0;
                }
                hit = true;
            }
        } else if (*(s16*)(p + 0x10) <= 0) {
            if (*(s16*)(p + 0x12) <= 0) {
                *(s16*)(p + 0x10) = 0;
            } else {
                *(s16*)(p + 0x10) = (s16)0x8000;
            }
            hit = true;
        }
        s32 idx = (*(s16*)(p + 0x10) >> 2) & 0x3ff8;
        x = *(f32*)((char*)sincosTable___5JMath + idx) * lbl_8053F938;
        y = *(f32*)((char*)sincosTable___5JMath + idx + 4) * lbl_8053F938;
        if (zero) {
            *(f32*)(p + 0x4) = *(f32*)(p + 0x14);
            *(f32*)(p + 0x8) = *(f32*)(p + 0x18);
        } else {
            *(f32*)(p + 0x4) = *(f32*)(p + 0x1c);
            *(f32*)(p + 0x8) = *(f32*)(p + 0x20);
        }
        *(f32*)(p + 0x4) += x;
        *(f32*)(p + 0x8) += y;
        if (hit) {
            *(s32*)p = 4;
        }
    } break;
    case 4: {
        if (*(s32*)(p + 0xc) == 0) {
            *(f32*)(p + 0x4) += lbl_8053F91C;
        } else {
            *(f32*)(p + 0x4) -= lbl_8053F91C;
        }
    } break;
    }
    if (out != 0) {
        out[0] = *(f32*)(p + 0x4);
        out[1] = *(f32*)(p + 0x8);
        out[0] -= oldX;
        out[1] -= oldY;
    }
}
