#include "types.h"
#include "Game/SinitPoolChain.h"

extern "C" void* lbl_8053AAF8;
extern "C" void fn_802D6A9C(void);
extern "C" u8 fn_802DCD0C(void);
extern "C" u8 fn_80239D38(void);
extern "C" u8 lbl_80529DEC[];
extern "C" u8* lbl_8053AEC8;

extern "C" void* fn_801902C0(void) {
    return *(void**)((u8*)*(void**)((u8*)lbl_8053AAF8 + 4) + 0x20);
}

extern "C" void fn_80190DC8(u8* p) {
    u8* e3;
    s32 i;
    s32 t = *(s32*)(p + 4);
    u8* cur = p;
    for (i = 0; i < 7; i++, cur += 0x60) {
        u8* e = *(u8**)(cur + 0x48);
        if (e != NULL && cur[0x64] != 0) {
            *(f32*)(e + 8) = (f32)(t % *(s16*)(e + 6));
            f32 f = *(f32*)(cur + 0x50);
            if (f >= 0.0f) {
                if (f == 0.0f) {
                    *(f32*)(*(u8**)(cur + 0x4c) + 8) = 201.0f;
                } else if (f < 1.0f) {
                    *(f32*)(*(u8**)(cur + 0x4c) + 8) = 200.0f * f + 201.0f;
                } else {
                    *(s32*)(cur + 0x58) = *(s32*)(cur + 0x58) + 1;
                    *(f32*)(*(u8**)(cur + 0x4c) + 8) = (f32)(*(s32*)(cur + 0x58) % 200 + 401);
                }
            } else {
                s32 x = *(s32*)(cur + 0x54);
                if (x >= 0) {
                    *(f32*)(*(u8**)(cur + 0x4c) + 8) = (f32)x;
                }
            }
        }
    }
    u8* e2 = *(u8**)(p + 0x2bc);
    if (e2 != NULL && p[0x2c0] != 0) {
        *(f32*)(e2 + 8) = (f32)(t % *(s16*)(e2 + 6));
    }
    e2 = *(u8**)(p + 0x2d8);
    if (e2 != NULL && p[0x2dc] != 0) {
        *(f32*)(e2 + 8) = (f32)(t % *(s16*)(e2 + 6));
    }
    e2 = *(u8**)(p + 0x2f0);
    if (e2 != NULL && p[0x2fc] != 0) {
        *(f32*)(e2 + 8) = 121.0f * *(f32*)(p + 0x2f4);
    }
    e2 = *(u8**)(p + 0x310);
    if (e2 != NULL && p[0x31c] != 0) {
        *(f32*)(e2 + 8) = (f32)(s32)(37.0f * *(f32*)(p + 0x314));
    }
    e2 = *(u8**)(p + 0x330);
    if (e2 != NULL && p[0x33c] != 0) {
        if (*(f32*)(p + 0x334) < 1.0f) {
            *(f32*)(e2 + 8) = 121.0f * *(f32*)(p + 0x334);
            *(s32*)(p + 0x338) = 0;
        } else {
            *(f32*)(e2 + 8) = (f32)(*(s32*)(p + 0x338) % 120 + 121);
            *(s32*)(p + 0x338) = *(s32*)(p + 0x338) + 1;
        }
    }
    cur = p;
    for (i = 0; i < *(s32*)(p + 0x4a8); i++, cur += 0x24) {
        e3 = *(u8**)(cur + 0x35c);
        if (e3 != NULL) {
            s32 v = (s32)((f32)t * *(f32*)(cur + 0x354));
            *(f32*)(e3 + 8) = (f32)(v % *(s16*)(e3 + 6));
            *(f32*)(*(u8**)(cur + 0x360) + 8) = (f32)(s32)(60.0f - 59.0f * *(f32*)(cur + 0x350));
        }
    }
    cur = p;
    for (i = 0; i < *(s32*)(p + 0x5ec); i++, cur += 0x28) {
        e3 = *(u8**)(cur + 0x4c4);
        if (e3 != NULL) {
            *(f32*)(e3 + 8) = (f32)(t % *(s16*)(e3 + 6));
            *(f32*)(*(u8**)(cur + 0x4c8) + 8) = *(f32*)(cur + 0x4bc);
            u8* e4 = *(u8**)(cur + 0x4cc);
            *(f32*)(e4 + 8) = (f32)(t % *(s16*)(e4 + 6));
            *(f32*)(*(u8**)(cur + 0x4d0) + 8) = (f32)*(s32*)(cur + 0x4b8);
        }
    }
    cur = p;
    for (i = 0; i < *(s32*)(p + 0x618); i++, cur += 0x14) {
        e3 = *(u8**)(cur + 0x600);
        if (e3 != NULL) {
            *(f32*)(e3 + 8) = (f32)(t % *(s16*)(e3 + 6));
        }
    }
    cur = p;
    for (i = 0; i < *(s32*)(p + 0x79c); i++, cur += 0x18) {
        e3 = *(u8**)(cur + 0x630);
        if (e3 != NULL) {
            *(f32*)(e3 + 8) = (f32)(t % *(s16*)(e3 + 6));
        }
    }
    u8* e5 = *(u8**)(p + 0x7b0);
    if (e5 != NULL && p[0x7a8] != 0) {
        *(f32*)(e5 + 8) = (f32)(t % *(s16*)(e5 + 6));
        if (*(s32*)(p + 0x7a4) > 0) {
            *(s32*)(p + 0x7a4) = *(s32*)(p + 0x7a4) - 1;
        } else if (*(s32*)(p + 0x7a0) < *(s16*)(*(u8**)(p + 0x7b4) + 6)) {
            *(s32*)(p + 0x7a0) = *(s32*)(p + 0x7a0) + 1;
        } else {
            *(s32*)(p + 0x7a0) = 0;
            u8* g = (u8*)lbl_8053AAF8;
            *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
            u32 bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
            *(s32*)(p + 0x7a4) = (s32)(120.0f * (*(f32*)&bits - 1.0f));
        }
        if (*(s32*)(p + 0x7a0) == 0) {
            *(f32*)(*(u8**)(p + 0x7b4) + 8) = (f32)*(s16*)(*(u8**)(p + 0x7b4) + 6);
        } else {
            *(f32*)(*(u8**)(p + 0x7b4) + 8) = (f32)(*(s32*)(p + 0x7a0) - 1);
        }
    }
    u8* e6 = *(u8**)(p + 0x7c8);
    if (e6 != NULL) {
        if (p[0x7c0] != 0 || (*(s32*)(p + 0x7bc) > 0 && *(s32*)(p + 0x7bc) < *(s16*)(e6 + 6))) {
            *(s32*)(p + 0x7bc) = *(s32*)(p + 0x7bc) + 1;
        }
        *(f32*)(e6 + 8) = (f32)*(s32*)(p + 0x7bc);
    }
    u8* e7 = *(u8**)(p + 0x7e4);
    if (e7 != NULL && p[0x7ec] != 0) {
        *(f32*)(e7 + 8) = (f32)*(s32*)(p + 0x7dc);
        *(f32*)(*(u8**)(p + 0x7e8) + 8) = (f32)*(s32*)(p + 0x7dc);
    }
}

extern "C" void fn_801914C4(u8* p) {
    bool f;
    u8* g = (u8*)lbl_8053AAF8;
    if (g[0x7f] != 0) {
        s32 x = (*(s32*)(g + 0x4c) == 7 || *(s32*)(g + 0x4c) == 8 || *(s32*)(g + 0x4c) == 9 || *(s32*)(g + 0x4c) == 0x16 || *(s32*)(g + 0x4c) == 0xa || *(s32*)(g + 0x4c) == 0xb);
        f = x;
    } else {
        s32 x = (*(s32*)(g + 0x4c) == 7 || *(s32*)(g + 0x4c) == 8 || *(s32*)(g + 0x4c) == 9 || *(s32*)(g + 0x4c) == 0x16 || *(s32*)(g + 0x4c) == 0xa || *(s32*)(g + 0x4c) == 0xb || *(s32*)(g + 0x4c) == 0xc);
        f = x;
    }
    if (f) {
        fn_802D6A9C();
        if (fn_802DCD0C()) {
            goto end;
        }
    }
    g = (u8*)lbl_8053AAF8;
    if (g[0x94] != 0 || g[0x96] != 0) {
        goto end;
    }
    if (g[0x7f] != 0) {
        bool b;
        if (fn_80239D38()) {
            goto end;
        }
        g = (u8*)lbl_8053AAF8;
        if (*(s32*)(g + 0x4c) == 0xb) {
            b = true;
        } else {
            b = (g[0x88] == 2);
        }
        if (b) {
            goto end;
        }
    }
    if (lbl_80529DEC[0x240] == 0 && lbl_8053AEC8[0x5d] == 0) {
        p[0x64] = 0;
        p[0xc4] = 0;
        p[0x124] = 0;
        p[0x184] = 0;
        p[0x1e4] = 0;
        p[0x244] = 0;
        p[0x2a4] = 0;
        p[0x2c0] = 0;
        p[0x2dc] = 0;
        p[0x2fc] = 0;
        p[0x31c] = 0;
        p[0x33c] = 0;
        *(s32*)(p + 0x4a8) = 0;
        *(s32*)(p + 0x5ec) = 0;
        *(s32*)(p + 0x618) = 0;
        *(s32*)(p + 0x79c) = 0;
        p[0x7a8] = 0;
        p[0x7c0] = 0;
        p[0x7ec] = 0;
    }
end:
    *(s32*)(p + 4) = *(s32*)(p + 4) + 1;
}

extern "C" f32 lbl_8053E218;
extern "C" void destroy__7JKRHeapFv(void*);
extern "C" void fn_8019169C(u8* param_1) {
    f32 fzero = lbl_8053E218;
    *(u8*)(param_1 + 0x64) = 0;
    *(f32*)(param_1 + 0x50) = fzero;
    *(s32*)(param_1 + 0x58) = 0;
    *(u8*)(param_1 + 0xc4) = 0;
    *(f32*)(param_1 + 0xb0) = fzero;
    *(s32*)(param_1 + 0xb8) = 0;
    *(u8*)(param_1 + 0x124) = 0;
    *(f32*)(param_1 + 0x110) = fzero;
    *(s32*)(param_1 + 0x118) = 0;
    *(u8*)(param_1 + 0x184) = 0;
    *(f32*)(param_1 + 0x170) = fzero;
    *(s32*)(param_1 + 0x178) = 0;
    *(u8*)(param_1 + 0x1e4) = 0;
    *(f32*)(param_1 + 0x1d0) = fzero;
    *(s32*)(param_1 + 0x1d8) = 0;
    *(u8*)(param_1 + 0x244) = 0;
    *(f32*)(param_1 + 0x230) = fzero;
    *(s32*)(param_1 + 0x238) = 0;
    *(u8*)(param_1 + 0x2a4) = 0;
    *(f32*)(param_1 + 0x290) = fzero;
    *(s32*)(param_1 + 0x298) = 0;
    *(u8*)(param_1 + 0x2c0) = 0;
    *(u8*)(param_1 + 0x2dc) = 0;
    *(u8*)(param_1 + 0x2fc) = 0;
    *(u8*)(param_1 + 0x31c) = 0;
    *(u8*)(param_1 + 0x33c) = 0;
    *(s32*)(param_1 + 0x338) = 0;
    *(s32*)(param_1 + 0x4a8) = 0;
    *(s32*)(param_1 + 0x5ec) = 0;
    *(s32*)(param_1 + 0x618) = 0;
    *(s32*)(param_1 + 0x79c) = 0;
    *(u8*)(param_1 + 0x7a8) = 0;
    *(s32*)(param_1 + 0x7a4) = 300;
    *(s32*)(param_1 + 0x7a0) = 0;
    *(u8*)(param_1 + 0x7c0) = 0;
    *(s32*)(param_1 + 0x7bc) = 0;
    *(u8*)(param_1 + 0x7ec) = 0;
    *(s32*)(param_1 + 4) = 0;
}

extern "C" void** fn_80191744(void** param_1, s16 param_2) {
    if (param_1 != NULL) {
        if (param_1[499] != NULL) {
            void* obj = param_1[499];
            if (obj != NULL) {
                ((void (**)(void*, int))(*(void***)((u8*)obj + 8)))[12](obj, 1);
            }
        }
        if (param_1[0x1ee] != NULL) {
            void* obj = param_1[0x1ee];
            if (obj != NULL) {
                ((void (**)(void*, int))(*(void***)((u8*)obj + 8)))[12](obj, 1);
            }
        }
        destroy__7JKRHeapFv(*param_1);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80191E00(void);
extern "C" void fn_80191E04(void);
extern "C" void fn_80191E08(void);
extern "C" void fn_80191E0C(void);
extern "C" void fn_80191E10(void);
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* create__12JKRSolidHeapFUlP7JKRHeapb(u32 size, void* parent, bool errorFlag);
extern "C" void becomeCurrentHeap__7JKRHeapFv(void* heap);
extern "C" void adjustSize__12JKRSolidHeapFv(void* heap);
extern "C" void* __nw__FUl(u32 size);
extern "C" void __ct__14WaveControllerFlll(void* self, s32 a, s32 b, s32 c);
extern "C" int sprintf(char* s, const char* format, ...);
extern "C" void fn_8016A3BC(void* archive, const void* a, const void* b, const void* c, const void* d, const void* e, u32 f, void* heap, void* p0, void* p1, const void* g, void* p2, void* h);
extern "C" void* fn_801917E0(u8* param_1, void* param_2) {
    void* wc;
    s32 i;
    u8* elem;
    char nameA[32];
    char nameB[32];
    char nameC[32];

    __construct_array(param_1 + 0x8, (void*)fn_80191E10, 0, 0x60, 7);
    __construct_array(param_1 + 0x340, (void*)fn_80191E0C, 0, 0x24, 10);
    __construct_array(param_1 + 0x4ac, (void*)fn_80191E08, 0, 0x28, 8);
    __construct_array(param_1 + 0x5f0, (void*)fn_80191E04, 0, 0x14, 2);
    __construct_array(param_1 + 0x61c, (void*)fn_80191E00, 0, 0x18, 0x10);
    *(void**)param_1 = create__12JKRSolidHeapFUlP7JKRHeapb(-1, param_2, false);
    becomeCurrentHeap__7JKRHeapFv(*(void**)param_1);

    elem = param_1;
    for (i = 0; i < 7; i++) {
        sprintf(nameA, "suisyo_%d.bmd", i + 1);
        sprintf(nameB, "suisyo_%d.btk", i + 1);
        sprintf(nameC, "suisyo_%d.brk", i + 1);
        if (((void* (*)(void*, u32, const char*))(*(void***)*(void**)(lbl_80529DEC + 0x10))[6])(*(void**)(lbl_80529DEC + 0x10), 0x4a334420, nameA) == 0) {
            sprintf(nameA, "suisyo_op.bmd", i + 1);
            sprintf(nameB, "suisyo_op.btk", i + 1);
            sprintf(nameC, "suisyo_op.brk", i + 1);
        }
        fn_8016A3BC(*(void**)(lbl_80529DEC + 0x10), nameA, nameB, 0, nameC, 0, 0x20240000, *(void**)param_1, elem + 0x44, elem + 0x48, 0, elem + 0x4c, 0);
        elem += 0x60;
    }

    fn_8016A3BC(*(void**)(lbl_80529DEC + 0x10), "taki_a.bmd", "taki_a.btk", 0, 0, 0, 0x20240000, *(void**)param_1, param_1 + 0x2b4, param_1 + 0x2bc, 0, 0, 0);
    fn_8016A3BC(*(void**)(lbl_80529DEC + 0x10), "niji_a.bmd", 0, 0, 0, 0, 0x20240000, *(void**)param_1, param_1 + 0x2b8, 0, 0, 0, 0);
    fn_8016A3BC(*(void**)(lbl_80529DEC + 0x10), "taki_b.bmd", "taki_b.btk", 0, 0, 0, 0x20240000, *(void**)param_1, param_1 + 0x2d0, param_1 + 0x2d8, 0, 0, 0);
    fn_8016A3BC(*(void**)(lbl_80529DEC + 0x10), "osiro_mon.bmd", "osiro_mon.btk", 0, 0, 0, 0x240000, *(void**)param_1, param_1 + 0x2ec, param_1 + 0x2f0, 0, 0, 0);
    fn_8016A3BC(*(void**)(lbl_80529DEC + 0x10), "osiro_tobira.bmd", "osiro_tobira.btk", 0, 0, 0, 0x240000, *(void**)param_1, param_1 + 0x30c, param_1 + 0x310, 0, 0, 0);
    fn_8016A3BC(*(void**)(lbl_80529DEC + 0x10), "osiro_mado.bmd", "osiro_mado.btk", 0, 0, 0, 0x240000, *(void**)param_1, param_1 + 0x32c, param_1 + 0x330, 0, 0, 0);

    elem = param_1;
    for (i = 0; i < 10; i++) {
        fn_8016A3BC(*(void**)(lbl_80529DEC + 0x10), "suna.bmd", "suna.btk", 0, "suna.brk", 0, 0x240000, *(void**)param_1, elem + 0x358, elem + 0x35c, 0, elem + 0x360, 0);
        elem += 0x24;
    }

    elem = param_1;
    for (i = 0; i < 8; i++) {
        fn_8016A3BC(*(void**)(lbl_80529DEC + 0x14), "ak_magicCircle.bmd", "ak_magicCircle.btk", "ak_magicCircleApp.btk", "ak_magicCircle.brk", "ak_magicCircleColor.brk", 0x20240000, *(void**)param_1, elem + 0x4c0, elem + 0x4c4, elem + 0x4c8, elem + 0x4cc, elem + 0x4d0);
        elem += 0x28;
    }

    elem = param_1;
    for (i = 0; i < 2; i++) {
        fn_8016A3BC(*(void**)(lbl_80529DEC + 0x14), "mekakusi.bmd", "mekakusi.btk", 0, 0, 0, 0x01240000, *(void**)param_1, elem + 0x5fc, elem + 0x600, 0, 0, 0);
        elem += 0x14;
    }

    elem = param_1;
    for (i = 0; i < 16; i++) {
        fn_8016A3BC(*(void**)(lbl_80529DEC + 0x10), "unk_0x1c4.bmd", "unk_0x1d4.bmd", 0, 0, 0, 0x240000, *(void**)param_1, elem + 0x62c, elem + 0x630, 0, 0, 0);
        elem += 0x18;
    }

    fn_8016A3BC(*(void**)(lbl_80529DEC + 0x10), "unknown_0x1e4.bmd", "unknown_0x1f8.bmd", 0, "unknown_0x20c.bmd", 0, 0x240000, *(void**)param_1, param_1 + 0x7ac, param_1 + 0x7b0, 0, param_1 + 0x7b4, 0);
    fn_8016A3BC(*(void**)(lbl_80529DEC + 0x10), "unknown_0x220.bmd", 0, 0, "unknown_0x234.bmd", 0, 0x10220000, *(void**)param_1, param_1 + 0x7c4, 0, 0, param_1 + 0x7c8, 0);
    fn_8016A3BC(*(void**)(lbl_80529DEC + 0x10), "unk_0x248.bmd", "unk_0x258.bmd", 0, "unk_0x268.bmd", 0, 0x10240000, *(void**)param_1, param_1 + 0x7e0, param_1 + 0x7e4, 0, param_1 + 0x7e8, 0);

    adjustSize__12JKRSolidHeapFv(*(void**)param_1);
    becomeCurrentHeap__7JKRHeapFv(param_2);

    wc = __nw__FUl(0x5c);
    if (wc != 0) {
        __ct__14WaveControllerFlll(wc, 0, 0, 8);
    }
    *(void**)(param_1 + 0x7b8) = wc;
    wc = __nw__FUl(0x5c);
    if (wc != 0) {
        __ct__14WaveControllerFlll(wc, 0, 0, 8);
    }
    *(void**)(param_1 + 0x7cc) = wc;
    return param_1;
}

extern "C" void fn_80191E00(void) {}

extern "C" void fn_80191E04(void) {}

extern "C" void fn_80191E08(void) {}

extern "C" void fn_80191E0C(void) {}

extern "C" void fn_80191E10(void) {}

void __sinit_tu_801902C0_cpp(void) {}

