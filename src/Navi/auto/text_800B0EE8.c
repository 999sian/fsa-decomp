#include "types.h"
struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
struct VObj_800B98AC {
virtual void v0(int a);
};
struct VObj2_800B98AC {
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
};
struct VObj_800B95E4 {
    virtual void v0();
    virtual void v1();
    virtual void v2(f32 x, f32 y);
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800b0ee8-0x800bace4 (71 functions). split_file divides it into the game's real files.

extern void* lbl_8028794C[];
extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_80287910[];
extern void* lbl_80286A30[];
extern unsigned char lbl_802313EC[];
extern u32 lbl_80287510[];
extern "C" void fn_8002F544(u32 a);
extern "C" void fn_8002F458(s32 a, s32 b);
extern "C" s32 fn_800BA298(u8* p, s32 a, s32 b, s32 c, s32 d);
extern unsigned char lbl_802C55A4[];
extern "C" int fn_8002F6BC(void);
extern "C" void fn_800B95E4(u8* p);
extern "C" void fn_800B6F64(u8* p);
extern "C" void fn_800B72AC(u8* p);
extern "C" void fn_800B7528(u8* p);
extern "C" void fn_800B78BC(u8* p, int a, int b);
extern "C" void fn_800B73D8(u8* p);
extern "C" void fn_800B6F18(u8* p);
extern char lbl_802B7CA0[];
extern u32 lbl_802BB0FC[];
extern u32 lbl_80287550[];
extern void* lbl_802FEC84;
extern "C" void fn_800B15E0(u8* p);
extern "C" void fn_8002F7C0(u32 a, s32 b);
struct NaviState_800B51F8;
typedef void (NaviState_800B51F8::*NaviStateFn_800B51F8)();
extern NaviStateFn_800B51F8 lbl_802876DC[];
extern "C" void fn_800B7234(u8* p);
extern "C" void fn_800B7448(u8* p);
extern "C" s32 fn_800B9D60(u8* p, s32 idx, u8 max, s32 unused, s32 mode, f32 a, f32 b);
extern f32 lbl_80300C88;
extern "C" void fn_800B9754(char* self);
extern "C" void fn_800B9588(u8* p);
extern "C" void fn_800B96D8(char* p);
extern "C" void fn_8017A4F8(void* p);
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" void fn_800B10D4(u8* p);
extern "C" void fn_800B4D64(u8* p);
extern "C" void fn_800B48F8(u8* p);
extern "C" void fn_800B4E7C(u8* p);
extern "C" void fn_800B0EE8(u8* p) {
    *(void**)p = lbl_802FEC84;
    u8 v = (u8)lbl_802B7CA0[0x3fc] & 0xf;
    if (v >= 12) {
        v = 0;
    }
    p[0x387] = v % 4;
    p[0x388] = v / 4;
    p[0x386] = 0;
    p[0x60] = 0;
    p[0x3a0] = 0;
    p[0x3a1] = 0;
    p[0x385] = 1;
    p[0x384] = 0;
    p[0x39a] = 0;
    fn_800B15E0(p);
    fn_800B10D4(p);
    fn_800B4D64(p);
    fn_800B48F8(p);
    fn_800B4E7C(p);
    fn_800B95E4(p);
    p[0x39d] = 0;
    if (p[0x39b] != 0 && p[0x39c] != 0) {
        p[0x39d] = 1;
    }
    p[0x3a3] = 0;
    *(u32*)(p + 0x378) = 0;
    p[0x3a2] = 0;
}

extern "C" void fn_800B0FE8(u8* p) {
    p[0x3a0] = 0;
    p[0x3a1] = 0;
    if (p[0x39a] != 0) {
        u8 v = (u8)lbl_802B7CA0[0x3fc] & 0xf;
        if (v >= 12) {
            v = 0;
        }
        p[0x387] = v % 4;
        p[0x388] = v / 4;
        p[0x39a] = 0;
    }
    fn_800B10D4(p);
    fn_800B4D64(p);
    fn_800B95E4(p);
    fn_800B48F8(p);
    fn_800B4E7C(p);
    p[0x39d] = 0;
    if (p[0x39b] != 0 && p[0x39c] != 0) {
        p[0x39d] = 1;
    }
    p[0x3a3] = 0;
    *(u32*)(p + 0x378) = 0;
    p[0x3a2] = 0;
}

extern "C" void fn_800B4454(void) {}

extern "C" unsigned char fn_800B51E8(void* self, int i) {
    return lbl_802313EC[i];
}

extern "C" void fn_800B51F8(NaviState_800B51F8* p) {
    ((u8*)p)[0x3a2] = 0;
    (p->*lbl_802876DC[*(u32*)((u8*)p + 0x378)])();
    fn_800B7234((u8*)p);
    fn_800B7448((u8*)p);
    fn_800B9754((char*)p);
    fn_800B9588((u8*)p);
    fn_800B96D8((char*)p);
    fn_8017A4F8(*(void**)((u8*)p + 8));
}

extern "C" void fn_800B562C(u8* p) {
    if (fn_8002F6BC() == 0) {
        if (p[0x39e] != 0) {
            p[0x39e]--;
        } else {
            fn_8002F544(lbl_80287510[0]);
            *(u32*)(p + 0x378) = 0xb;
        }
    }
}

extern "C" void fn_800B5A38(u8* p) {
    if (p[0x39e] != 0) {
        p[0x39e]--;
    } else {
        if (p[0x37c] == 0) {
            fn_8002F544(0x3e);
            fn_8002F458(0xb6, 0);
        }
        s32 r = fn_800BA298(p, p[0x37c], lbl_802C55A4[0x34], 0, 0);
        p[0x37c]++;
        if (r == 1 && fn_8002F6BC() == 0) {
            p[0x37c] = 0;
            p[0x39e] = lbl_802C55A4[0x45];
            *(s32*)(p + 0x378) = 2;
        }
    }
}

extern "C" void fn_800B5CF0(u8* p) {
    if (*(u32*)(lbl_802B7CA0 + 0x3440) != 0) {
        if (p[0x60] == 1) {
            (*(u8**)(p + 0x30))[0xb0] = 0;
            (*(u8**)(p + 0x3c))[0xb0] = 1;
            if (p[0x386] != 3) {
                fn_8002F7C0(lbl_80287550[p[0x386]], 0);
            } else {
                fn_8002F544(lbl_80287550[p[0x386]]);
            }
        } else {
            (*(u8**)(p + 0x30))[0xb0] = 1;
            (*(u8**)(p + 0x3c))[0xb0] = 0;
            if (p[0x51] != 1 && p[0x3a3] == 0) {
                fn_8002F544(0x2e);
                p[0x38a] = 0;
            }
        }
        p[0x3a2] = 2;
        *(s32*)(p + 0x378) = 4;
    }
}

extern "C" void fn_8002F458(s32 a, s32 b);
extern "C" s32 fn_800BA298(u8* p, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_800B68EC(u8* p) {
    if (fn_8002F6BC() == 0) {
        if (p[0x39e] != 0) {
            p[0x39e]--;
        } else {
            fn_8002F544(lbl_80287510[0]);
            *(s32*)(p + 0x378) = 0x14;
        }
    }
}

extern "C" void fn_800B6950(u8* p) {
    if (fn_8002F6BC() == 0) {
        p[0x3a2] = 2;
        p[0x39e] = 8;
        *(s32*)(p + 0x378) = 0x15;
    }
}

extern "C" void fn_800B699C(u8* p) {
    if (p[0x39e] != 0) {
        p[0x39e]--;
        return;
    }
    p[0x39d] = 0;
    *(u8*)(*(u8**)(p + 0x30) + 0xb0) = 1;
    *(s32*)(p + 0x378) = 4;
}

extern "C" void fn_800B6D90(u8* p) {
    if ((u16)(*(u16*)(lbl_802B7CA0 + 0xc) & (1 << lbl_802313EC[p[0x387] + p[0x388] * 4])) != 0) {
        p[0x384] = 0;
        fn_8002F544(lbl_80287510[p[0x387] + p[0x388] * 4]);
        *(u32*)(p + 0x394) = 0;
    } else {
        p[0x384] = 1;
    }
    fn_800B73D8(p);
    fn_800B95E4(p);
    fn_800B6F18(p);
    if (p[0x38a] == 0) {
        p[0x38a] = 1;
    }
}

extern "C" void fn_800B6E5C(u8* p) {
    p[0x384] = 0;
    fn_8002F544(lbl_80287510[p[0x387] + p[0x388] * 4]);
    *(u32*)(p + 0x394) = 0;
    fn_800B95E4(p);
    fn_800B78BC(p, fn_800B51E8(p, p[0x387] + p[0x388] * 4), p[0x381] ^ 1);
    fn_800B7528(p);
    fn_800B6F64(p);
    fn_800B72AC(p);
    if (p[0x38a] == 0) {
        p[0x38a] = 1;
    }
}

extern "C" void fn_800B6F18(u8* p) {
    if (p[0x37e] == 1) {
        fn_800B72AC(p);
    } else {
        p[0x37e] = 1;
    }
    fn_800B6F64(p);
}

extern unsigned char lbl_802C55A4[];
extern "C" int fn_800BA614(u8* p, u8 a, u8 b, int c);
extern "C" void fn_800B7234(u8* p) {
    if (p[0x37e] != 0) {
        s32 r = fn_800BA614(p, p[0x37f], lbl_802C55A4[0xc], 0);
        p[0x37f]++;
        if (r == 1) {
            p[0x37f] = 0;
            p[0x37e] = 0;
            p[0x37d] ^= 1;
        }
    }
}

extern "C" void fn_800B7528(u8* p);
extern "C" void fn_800B78BC(u8* p, int a, int b);
extern "C" void fn_800B73D8(u8* p) {
    if (p[0x382] == 1) {
        fn_800B7528(p);
    } else {
        p[0x382] = 1;
    }
    fn_800B78BC(p, fn_800B51E8(p, p[0x387] + p[0x388] * 4), p[0x381] ^ 1);
}

extern "C" void fn_800B7448(u8* p) {
    s32 r;

    if (p[0x382] != 0) {
        if (p[0x380] != 0) {
            r = fn_800B9D60(p, p[0x383], (u32)((u8*)lbl_802C55A4)[0xc] >> 1, 1, 0, *(f32*)((u8*)lbl_802C55A4 + 0x2c), lbl_80300C88);
        } else {
            r = fn_800B9D60(p, p[0x383], (u32)((u8*)lbl_802C55A4)[0xc] >> 1, 1, 1, lbl_80300C88, *(f32*)((u8*)lbl_802C55A4 + 0x2c));
        }
        p[0x383]++;
        if (r == 1) {
            p[0x383] = 0;
            if (p[0x380] == 0) {
                p[0x380] = 1;
                p[0x381] ^= 1;
            } else {
                p[0x382] = 0;
                p[0x385] = p[0x384];
            }
        }
    }
}

extern "C" int fn_8002F87C(void);
extern "C" int fn_8002F6BC(void);
extern "C" void fn_8002F9B4(void);
extern "C" void fn_80130974(void* obj);
extern "C" void fn_8015FDA8(void* a, void* b);
extern "C" void fn_800B9570(u8* p);
extern "C" void fn_800B83C0(u8* p) {
    if (fn_8002F87C() == 0 && fn_8002F6BC() == 0) {
        if (p[0x39e] != 0) {
            p[0x39e]--;
        } else {
            *(u32*)(p + 0x378) = 6;
        }
    }
}

extern "C" void fn_800B8420(u8* p) {
    if (fn_8002F6BC() == 0) {
        if ((*(u32*)(lbl_802B7CA0 + 0x3f4) & 1) == 0 && p[0x39f] == 2) {
            fn_8002F9B4();
        }
        if (*(u8**)(p + 0x3a4) != nullptr) {
            fn_80130974(*(void**)(p + 0x3a4));
            u8* obj = *(u8**)(p + 0x3a4);
            *(u32*)(obj + 0xf4) |= 1;
            *(u32*)(obj + 0x24) = 1;
        }
        p[0x3a0] = p[0x39f];
        *(u32*)(p + 0x378) = 7;
    }
}

extern "C" void fn_800B8634(void) {}

extern "C" void fn_800B8638(u8* p) {
    *(s32*)(p + 0x394) = *(s16*)(lbl_802C55A4 + 0x36);
    p[0x38a] = 0;
    fn_800B9570(p);
    p[0x3a2] = 2;
    if (p[0x60] == 1) {
        (*(u8**)(p + 0x30))[0xb0] = 0;
        (*(u8**)(p + 0x3c))[0xb0] = 1;
    } else {
        (*(u8**)(p + 0x30))[0xb0] = 1;
        (*(u8**)(p + 0x3c))[0xb0] = 0;
    }
    *(u32*)(p + 0x378) = 4;
}

extern "C" void fn_800B9570(u8* param_1) {
    *(u8*)(*(u8**)(param_1 + 0x30) + 0xb0) = 1;
    *(u32*)(param_1 + 0x5c) = 0;
}

extern "C" void fn_800B9588(u8* param_1) {
    (*(s32*)(param_1 + 0x5c))++;
    if (*(s16*)(*(u8**)(param_1 + 0x58) + 6) <= *(s32*)(param_1 + 0x5c)) {
        *(s32*)(param_1 + 0x5c) -= *(s16*)(*(u8**)(param_1 + 0x58) + 6);
    }
    *(f32*)(*(u8**)(param_1 + 0x58) + 8) = *(s32*)(param_1 + 0x5c);
}

extern "C" void fn_800B95E4(u8* p) {
    f32 offX = *(f32*)(p + 0x38c) * p[0x387];
    f32 offY = *(f32*)(p + 0x390) * p[0x388];
    (*(VObj_800B95E4**)(p + 0x30))->v2(*(f32*)(p + 0x34) + offX, *(f32*)(p + 0x38) + offY);
}

extern "C" void fn_800B9668(u8* p) {
    f32 off = *(f32*)(p + 0x38c) * p[0x386];
    (*(VObj_800B95E4**)(p + 0x3c))->v2(*(f32*)(p + 0x40) + off, *(f32*)(p + 0x44));
}

extern "C" void fn_800B96CC(u8* p) {
    *(u32*)(p + 0x1bc) = 0;
}

extern "C" void fn_800B96D8(char* p) {
    if (*(u8*)(*(char**)(p + 0x1b0) + 0xb0) != 0 || *(u8*)(*(char**)(p + 0x1b4) + 0xb0) != 0) {
        *(s32*)(p + 0x1bc) += 1;
        char* q = *(char**)(p + 0x1b8);
        s32 c = *(s32*)(p + 0x1bc);
        if (c >= *(s16*)(q + 6)) {
            *(s32*)(p + 0x1bc) = c - *(s16*)(q + 6);
        }
        *(f32*)(*(char**)(p + 0x1b8) + 8) = *(s32*)(p + 0x1bc);
    }
}

extern "C" void fn_800B9754(char* self) {
    if (*(unsigned char*)(*(char**)(self + 0x19c) + 0xb0) != 0) {
        *(int*)(self + 0x1ac) += 1;
        char* p = *(char**)(self + 0x1a8);
        int v = *(int*)(self + 0x1ac);
        if (v >= *(short*)(p + 6)) {
            *(int*)(self + 0x1ac) = v - *(short*)(p + 6);
        }
        *(float*)(*(char**)(self + 0x1a8) + 8) = (float)*(int*)(self + 0x1ac);
    }
}

extern u32 lbl_802BB0FC[];
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" void fn_800B97C0(u8* p) {
    (*(u8**)(p + 0x1c0))[0xb0] = 0;
    (*(u8**)(p + 0x64))[0xb0] = 0;
    (*(u8**)(p + 0x78))[0xb0] = 0;
    (*(u8**)(p + 0x188))[0xb0] = 0;
    (*(u8**)(p + 0x68))[0xb0] = 0;
    (*(u8**)(p + 0x7c))[0xb0] = 0;
    (*(u8**)(p + 0x18c))[0xb0] = 0;
}

extern "C" void fn_800B9800(u8* p) {
    u8 one = 1;
    (*(u8**)(p + 0x1c0))[0xb0] = one;
    (*(u8**)(p + 0x64))[0xb0] = one;
    (*(u8**)(p + 0x78))[0xb0] = one;
    (*(u8**)(p + 0x68))[0xb0] = one;
    (*(u8**)(p + 0x7c))[0xb0] = one;
    if ((u8)lbl_802B7CA0[((lbl_802BB0FC[0x10] >> 1) & 1) * 0xc + ((u8(*)[4])lbl_802313EC)[p[0x388]][p[0x387]] + 0x93c] == 0) {
        ((u8**)(p + 0x188))[p[0x37d]][0xb0] = 0;
    } else {
        ((u8**)(p + 0x188))[p[0x37d]][0xb0] = one;
    }
}

extern "C" void fn_80130974(void* p);
extern "C" void fn_800B98AC(u8* p) {
    VObj_800B98AC* obj;
    u8* q;

    obj = *(VObj_800B98AC**)(p + 0x8);
    if (obj != 0) {
        obj->v0(1);
    }
    obj = *(VObj_800B98AC**)(p + 0x1a8);
    if (obj != 0) {
        obj->v0(1);
    }
    obj = *(VObj_800B98AC**)(p + 0x58);
    if (obj != 0) {
        obj->v0(1);
    }
    (*(VObj2_800B98AC**)p)->v7();
    if (*(void**)(p + 0x3a4) != 0) {
        fn_80130974(*(void**)(p + 0x3a4));
        q = *(u8**)(p + 0x3a4);
        *(u32*)(q + 0xf4) |= 1;
        *(u32*)(q + 0x24) = 1;
    }
}

extern "C" void* fn_800B9970(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80287910;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80286A30;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800B99CC(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0x204, base + 0x208, p + 4);
}

extern "C" void fn_800BA9E4(void** p, void* x) {
    fn_8015FDA8(x, *p);
}

extern char lbl_802B7CA0[];
extern f32 lbl_80300C88;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_800BAC38(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300C88;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800BAC9C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028794C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
