#include "types.h"
#include "JSystem/J2D/J2DPane.h"
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/J2D/J2DPicture.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "dolphin/os/OSFastCast.h"

struct FsaNode {
    virtual void v0(void);
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual void v6(void);
    virtual void v7(void);
    virtual void v8(void);
    virtual void v9(s32);
    virtual void v10(void);
    virtual void v11(void);
    virtual void v12(void);
    virtual void v13(void);
    virtual void v14(void);
    virtual FsaNode* v15(u64);
};

struct FsaVt15 {
    void* v[15];
    FsaNode* (*v15)(void* a, u64 b);
};

static inline FsaNode* fsaV15(u8* obj, u64 key) {
    return (*(FsaVt15**)obj)->v15(obj, key);
}

struct FsaSlots {
    virtual void v0(void);
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual void v6(void);
    virtual void v7(s32);
    virtual void v8(void);
    virtual void v9(void);
    virtual void v10(void);
    virtual void v11(void);
    virtual void v12(void);
    virtual void v13(void);
    virtual void v14(void);
    virtual void v15(void);
    virtual void v16(void);
    virtual void v17(void);
    virtual void v18(void);
    virtual void v19(void);
    virtual void v20(void);
    virtual void v21(void);
    virtual void v22(void);
    virtual void v23(void);
    virtual void v24(void);
    virtual void v25(void);
    virtual void v26(void);
    virtual void v27(void);
    virtual void v28(void);
    virtual void v29(void);
    virtual void v30(void);
    virtual void v31(void);
    virtual void v32(void);
    virtual void v33(void);
    virtual void v34(void);
    virtual void v35(void);
    virtual void v36(void);
    virtual void v37(void);
    virtual void v38(void);
    virtual void v39(void);
    virtual void v40(void);
    virtual void v41(void);
    virtual void v42(void);
    virtual void v43(void);
    virtual void v44(void);
    virtual void v45(void);
    virtual void v46(void);
    virtual void v47(void);
    virtual void v48(void);
    virtual void v49(void);
    virtual void v50(void);
    virtual void v51(void);
    virtual void v52(void);
    virtual void v53(void);
    virtual void v54(void);
    virtual void v55(void);
    virtual void v56(void);
    virtual void v57(s32, s32, s32, f32, f32, f32, f32);
    virtual void v58(void);
    virtual void v59(s32, s32, s32, f32, f32, f32, f32);
};

struct FsaNodeB {
    virtual void v0(void);
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual void v6(void);
    virtual void v7(void);
    virtual void v8(void);
    virtual void v9(void);
    virtual void v10(void);
    virtual void v11(void);
    virtual void v12(void);
    virtual FsaSlots* v13(u64);
};

struct FsaDisposable {
    virtual void v0(void);
    virtual void v1(void);
    virtual void del(s32);
};


extern "C" void* lbl_8053AB10;
extern "C" void* lbl_8053AD68;
extern "C" f32 lbl_80543534;
extern "C" f32 lbl_80543568;
extern "C" f32 lbl_8054356C;
extern "C" void fn_8013B490(void*);
extern "C" void fn_803D75B0(void);
extern "C" s32 fn_80138A30(void*);
extern "C" void fn_804310CC(void*);
extern "C" void fn_80402E08(void*, f32, f32);
extern "C" u8* fn_804030C4(u32, void*);
extern "C" void fn_80440D78(void*, void*);
extern "C" void fn_80440BF4(void*, s32);
extern "C" void fn_80458FF0(void*, u32, s32, s32);
extern "C" void* lbl_8053AEC0;
extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053AED8;
extern "C" void* lbl_8053AF80;
extern "C" char lbl_80476F80[];
extern "C" char lbl_80529DEC[];
extern "C" f32 lbl_80543530;
extern "C" f32 lbl_80543538;
extern "C" f32 lbl_8054353C;
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void*, f32, f32, void*);
extern "C" u8 fn_80402940(void*, s32, s32, f32, f32);
extern "C" f32* getBounds__7J2DPaneFv(void*);
extern "C" u64 lbl_80477180[][16];
extern "C" u64 lbl_80477408[];

struct FsaVtJ2D {
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual void v6(void);
    virtual void v7(void);
    virtual void v8(void);
    virtual void v9(void);
    virtual void v10(void);
    virtual void v11(void);
    virtual void v12(void);
    virtual void v13(void);
    virtual void v14(void);
    virtual void* search(u32, u32, u32);
    virtual void v16(void);
    virtual void v17(void);
    virtual void v18(void);
    virtual void v19(void);
    virtual void v20(void);
    virtual void v21(void);
    virtual void v22(void);
    virtual void v23(void);
    virtual void set24(void*);
    virtual void v25(void);
    virtual void v26(void);
    virtual void v27(void);
    virtual void set28(void*);
    virtual void v29(void);
    virtual void v30(void);
    virtual void v31(void);
    virtual void v32(void);
    virtual void v33(void);
    virtual void v34(void);
    virtual void v35(void);
    virtual void v36(void);
    virtual void v37(void);
    virtual void v38(void);
    virtual void set39(void*);
    virtual void v40(void);
    virtual void v41(void);
    virtual void v42(void);
    virtual void v43(void);
    virtual void v44(void);
    virtual void v45(void);
    virtual void v46(void);
    virtual void v47(void);
    virtual void v48(void);
    virtual void v49(void);
    virtual void v50(void);
    virtual void v51(void);
    virtual void v52(void);
    virtual void v53(void);
    virtual void v54(void);
    virtual void v55(void);
    virtual void v56(void);
    virtual void v57(void);
    virtual void v58(void);
    virtual void v59(void);
    virtual void v60(void);
    virtual void v61(void);
    virtual void v62(void);
    virtual void v63(void);
    virtual void v64(void);
    virtual void v65(void);
    virtual void v66(void);
    virtual void v67(void);
    virtual void v68(void);
    virtual void v69(void);
    virtual void v70(void);
    virtual void v71(void);
    virtual void v72(void);
    virtual void v73(void);
    virtual void v74(void);
    virtual void v75(void);
    virtual void set76(void*, void*);
};
extern "C" void fn_803D7098(u8* param_1) {
    f32 f28;
    f32 f29;
    f32 f30;
    f32 f31;
    f32 f0;
    u8* p;
    s32 i;
    u8* q;
    s32 j;
    s32 k;
    s16 b;
    s16 a;
    u8 flag0 = 0;
    u8 flag1 = 0;
    u8 flag2 = 0;
    u8 flag3 = 0;

    *(s32*)(param_1 + 0x60) += 1;
    if (*(s32*)(param_1 + 0x60) > 4) {
        flag0 = fn_80402940(*(void**)(param_1 + 0x30), 0x16, 0, lbl_80543530, lbl_80543534);
    }
    if (*(s32*)(param_1 + 0x60) > 0x10) {
        flag1 = fn_80402940(*(void**)(param_1 + 0x48), 0x18, 0, lbl_80543530, lbl_80543534);
    }
    if (*(s32*)(param_1 + 0x60) > 0) {
        i = 0;
        p = param_1;
        for (; i < 4; i++) {
            flag2 = fn_80402940(*(void**)(p + 0x34), 0x16, 0, lbl_80543538, lbl_80543534);
            p += 4;
        }
    }
    if (((u8*)lbl_8053AAF8)[0x7f] != 0) {
        flag3 = 1;
    } else {
        q = param_1;
        for (k = 0, j = 0; k < 2; k++, j += 5) {
            if (*(s32*)(param_1 + 0x60) > j) {
                flag3 = fn_80402940(*(void**)(q + 0x24), 0x10, 0, lbl_8054353C, lbl_80543534);
            }
            q += 4;
        }
    }

    if (flag0 && flag1 && flag2 && flag3) {
        (*(u8**)(*(u8**)(param_1 + 0x2c) + 4))[0xb0] = 1;
        param_1[0x78] = 0;
        param_1[0x79] = param_1[0x78];
        *(s16*)(param_1 + 0x6e) = 0;
        param_1[0x7a] = 3;
        param_1[0x7f] = 1;
        *(s16*)(param_1 + 0x70) = 1;
        a = *(s16*)(param_1 + 0x68);
        if (a >= 0 && a < 4) {
            b = *(s16*)(param_1 + 0x6a);
            if (b >= 0) {
                f28 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477180[0][0])->getBounds())[0];
                f0 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477408[0])->getBounds())[0];
                f31 = f0 + f28;
                f28 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477180[a][b])->getBounds())[0];
                f0 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477408[a])->getBounds())[0];
                f30 = f0 + f28;
                f29 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x8))->search(0x0050306B616B3030ULL)->getBounds())[0];
                f28 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477408[0])->getBounds())[0];
                f0 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(0x004E646174613033ULL)->getBounds())[0];
                f28 = f0 + f28;
                f0 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477180[0][0])->getBounds())[0];
                f0 = f0 + f28;
                f0 = f0 - f29;
                f0 = f0 + f30;
                f0 = f0 - f31;
                *(f32*)(param_1 + 0x58) = f0;

                f28 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477180[0][0])->getBounds())[1];
                f0 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477408[0])->getBounds())[1];
                f28 = f0 + f28;
                f29 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477180[*(s16*)(param_1 + 0x68)][*(s16*)(param_1 + 0x6a)])->getBounds())[1];
                f0 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477408[*(s16*)(param_1 + 0x68)])->getBounds())[1];
                f29 = f0 + f29;
                f30 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x8))->search(0x0050306B616B3030ULL)->getBounds())[1];
                f31 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477408[0])->getBounds())[1];
                f0 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(0x004E646174613033ULL)->getBounds())[1];
                f31 = f0 + f31;
                f0 = ((f32*)((J2DPane*)*(void**)(param_1 + 0x4))->search(lbl_80477180[0][0])->getBounds())[1];
                f0 = f0 + f31;
                f0 = f0 - f30;
                f0 = f0 + f29;
                f0 = f0 - f28;
                *(f32*)(param_1 + 0x5c) = f0;
            }
        }
    }
    fn_80402E08(*(void**)(param_1 + 0x44), *(f32*)(param_1 + 0x58), *(f32*)(param_1 + 0x5c));
}

extern "C" void fn_803D82EC(u8* param_1) {
    FsaSlots* obj;

    fn_8013B490(lbl_8053AB10);
    obj = *(FsaSlots**)(param_1 + 0x1c);
    obj->v7(param_1[0x77]);
    obj = *(FsaSlots**)(param_1 + 0x1c);
    obj->v57(0, 0, 0, lbl_80543534, lbl_80543534, lbl_80543568, lbl_8054356C);
}

extern "C" f32 lbl_80543548;
extern "C" f32 lbl_80543570;
extern "C" f32 lbl_80543574;
extern "C" f32 lbl_80543578;
extern "C" f32 lbl_8054357C;
extern "C" f32 lbl_80543580;
extern "C" f32 lbl_80543584;
extern "C" f32 lbl_80543588;
extern "C" void fn_804316EC(void*);
extern "C" void fn_80440EE8(void*);
extern "C" void fn_803D8364(u8* param_1) {
    f32 f31;
    f32 f30;
    s32 k;
    s32 t;

    if (param_1[0x7f] == 1 || (u8)(param_1[0x7f] - 2) <= 1 || param_1[0x7f] == 4) {
        f31 = lbl_80543534;
        if (*(s16*)(param_1 + 0x6e) > 0) {
            if (*(s16*)(param_1 + 0x6e) == 1) {
                *(s16*)(param_1 + 0x6c) = 0x1e;
            }
            t = *(s16*)(param_1 + 0x6e);
            k = t < 5 ? t : 10 - t;
            f31 = lbl_80543570 * (f32)(k * k) / lbl_80543574;
            if (t < 10) {
                *(s16*)(param_1 + 0x6e) += 1;
            } else {
                *(s16*)(param_1 + 0x6e) = 0;
            }
        }
        *(s16*)(param_1 + 0x6c) += 1;
        if (*(s16*)(param_1 + 0x6c) >= 0x3c) {
            *(s16*)(param_1 + 0x6c) = 0;
        }

        if (param_1[0x7f] == 2 || param_1[0x7f] == 3 || param_1[0x7f] == 4) {
            (*(FsaSlots**)(param_1 + 0x20))->v7(param_1[0x81]);
            (*(FsaSlots**)(param_1 + 0x20))->v57(0, 0, 0, lbl_80543578, lbl_80543578, lbl_8054357C, lbl_80543580);
            fn_804316EC(lbl_8053AEC0);
            f30 = lbl_80543584;
        } else {
            t = *(s16*)(param_1 + 0x6c);
            if (t < 30) {
                f30 = lbl_80543584 * ((f32)(t * t) / lbl_80543588);
            } else {
                k = t - 30;
                f30 = lbl_80543584 * (lbl_80543548 - (f32)(k * k) / lbl_80543588);
            }
            if (param_1[0x79] == 0) {
                fn_80402E08(*(void**)(param_1 + 0x2c), lbl_80543534, f31);
                fn_80402E08(*(void**)(param_1 + 0x24), lbl_80543534, f31);
                fn_80402E08(*(void**)(param_1 + 0x28), lbl_80543534, lbl_80543534);
            } else {
                fn_80402E08(*(void**)(param_1 + 0x2c), *(f32*)(*(u8**)(param_1 + 0x28) + 8) - *(f32*)(*(u8**)(param_1 + 0x24) + 8), f31);
                fn_80402E08(*(void**)(param_1 + 0x24), lbl_80543534, lbl_80543534);
                fn_80402E08(*(void**)(param_1 + 0x28), lbl_80543534, f31);
            }
            if (lbl_80543534 == f31) {
                if (param_1[0x79] != param_1[0x78]) {
                    param_1[0x79] = param_1[0x78];
                    (*(FsaSlots**)(*(u8**)(param_1 + 0x2c) + 4))->v7((s32)f30);
                }
            }
        }
        ((*(FsaNodeB**)(param_1 + 4))->v13(0x5061636375723031ULL))->v7((s32)f30);
        fn_80440EE8(lbl_8053AED8);
    }
}

extern "C" void fn_803D8670(u8* param_1) {
    FsaSlots* obj;

    fn_8013B490(lbl_8053AB10);
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(param_1 + 4), lbl_80543534, lbl_80543534, *(void**)((u8*)lbl_8053AB10 + 0x10));
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(param_1 + 8), lbl_80543534, lbl_80543534, *(void**)((u8*)lbl_8053AB10 + 0x10));
    obj = *(FsaSlots**)(param_1 + 0x1c);
    obj->v7(param_1[0x77]);
    obj = *(FsaSlots**)(param_1 + 0x1c);
    obj->v57(0, 0, 0, lbl_80543534, lbl_80543534, lbl_80543568, lbl_8054356C);
}

extern "C" void fn_803D8718(u8* param_1) {
    s32 bVar1 = param_1[0x76];

    switch (bVar1) {
    case 6:
        if (param_1[0x77] >= 0xf5) {
            param_1[0x77] = 0xff;
            param_1[0x76] = 5;
        } else {
            param_1[0x77] += 10;
        }
        break;
    case 5:
        if (param_1[0x77] <= 10) {
            param_1[0x77] = 0;
            ((u8*)lbl_8053AD68)[0x1d] = 1;
            param_1[0x76] = 2;
        } else {
            param_1[0x77] -= 10;
        }
        break;
    case 2:
        fn_803D75B0();
        break;
    }
}

extern "C" void fn_803D87C0(u8* param_1) {
    u8 mask;
    u8* lbl;
    u8* base;
    s32 j;
    s32 count;
    u64* k26;
    u64* k25;
    s32* cnt;
    u64* k23;
    u64* k22;
    u64* k21;
    u64* k20;
    u64* k19;
    u64* k26o;
    u64* k25o;
    s32 i;
    FsaNode* p;

    base = (u8*)lbl_80476F80;
    fn_804310CC(lbl_8053AEC0);
    k19 = (u64*)(base + 0x420);
    k20 = (u64*)(base + 0x438);
    k21 = (u64*)(base + 0x450);
    for (i = 0; i < 3; i++) {
        if (i >= fn_80138A30(lbl_8053AAF8) - 1) {
            p = (*(FsaNode**)(param_1 + 4))->v15(*k19);
            ((u8*)p)[0xb0] = 1;
            p = (*(FsaNode**)(param_1 + 4))->v15(*k20);
            ((u8*)p)[0xb0] = 0;
            p = (*(FsaNode**)(param_1 + 4))->v15(*k21);
            ((u8*)p)[0xb0] = 0;
        } else {
            p = (*(FsaNode**)(param_1 + 4))->v15(*k19);
            ((u8*)p)[0xb0] = 0;
            p = (*(FsaNode**)(param_1 + 4))->v15(*k20);
            ((u8*)p)[0xb0] = 1;
            p = (*(FsaNode**)(param_1 + 4))->v15(*k21);
            ((u8*)p)[0xb0] = 1;
        }
        k19++;
        k20++;
        k21++;
    }

    lbl = (u8*)lbl_80529DEC;
    k22 = (u64*)(base + 0x400);
    k23 = (u64*)(base + 0x468);
    cnt = (s32*)lbl;
    k25o = (u64*)(base + 0x200);
    k26o = (u64*)base;
    for (i = 0; i < 4; i++) {
        mask = (u8)(1 << i);
        count = *(s32*)((u8*)cnt + 0x140);
        if (lbl[0x243] & mask) {
            *(s16*)(param_1 + 0x68) = i;
            p = (*(FsaNode**)(param_1 + 4))->v15(*k23);
            ((u8*)p)[0xb0] = 1;
            p = (*(FsaNode**)(param_1 + 4))->v15(*k22);
            ((u8*)p)[0xb0] = 1;
        } else {
            p = (*(FsaNode**)(param_1 + 4))->v15(*k23);
            ((u8*)p)[0xb0] = 0;
            p = (*(FsaNode**)(param_1 + 4))->v15(*k22);
            ((u8*)p)[0xb0] = 0;
        }
        k25 = k25o;
        k26 = k26o;
        for (j = 0; j < 16; j++) {
            if (j < count && (((u8*)lbl_8053AAF8)[0x82] & mask)) {
                if (!(lbl[0x243] & mask) || j != count - 1) {
                    p = (*(FsaNode**)(param_1 + 4))->v15(*k26);
                    ((u8*)p)[0xb0] = 1;
                    p = (*(FsaNode**)(param_1 + 4))->v15(*k25);
                    ((u8*)p)[0xb0] = 1;
                    p = (*(FsaNode**)(param_1 + 4))->v15(*k25);
                    p->v9(0);
                } else {
                    *(s16*)(param_1 + 0x6a) = j;
                    p = (*(FsaNode**)(param_1 + 4))->v15(*k26);
                    ((u8*)p)[0xb0] = 0;
                    p = (*(FsaNode**)(param_1 + 4))->v15(*k25);
                    ((u8*)p)[0xb0] = 0;
                }
            } else {
                p = (*(FsaNode**)(param_1 + 4))->v15(*k26);
                ((u8*)p)[0xb0] = 0;
                p = (*(FsaNode**)(param_1 + 4))->v15(*k25);
                ((u8*)p)[0xb0] = 0;
            }
            k25++;
            k26++;
        }
        k25o += 0x10;
        k26o += 0x10;
        k22++;
        k23++;
        cnt++;
    }

    p = (*(FsaNode**)(param_1 + 8))->v15(0x0050306b616b3030ULL);
    p->v9(0);
    p = (*(FsaNode**)(param_1 + 8))->v15(0x000050306b613030ULL);
    p->v9(0);
    p = (*(FsaNode**)(param_1 + 8))->v15(0x0050737461726c69ULL);
    p->v9(0);
    fn_80402E08(*(u8**)(param_1 + 0x30), lbl_80543534, lbl_80543530);
    *(u16*)(*(u8**)(param_1 + 0x30) + 0x22) = 0;
    fn_80402E08(*(u8**)(param_1 + 0x48), lbl_80543534, lbl_80543530);
    *(u16*)(*(u8**)(param_1 + 0x48) + 0x22) = 0;
    for (i = 0; i < 4; i++) {
        fn_80402E08(*(u8**)(param_1 + 0x34 + i * 4), lbl_80543534, lbl_80543538);
        *(u16*)(*(u8**)(param_1 + 0x34 + i * 4) + 0x22) = 0;
    }
    p = (FsaNode*)fn_804030C4(0x54494d47, base + 0x4a8);
    fn_80440D78(lbl_8053AED8, p);
    fn_804030C4(0x54494d47, base + 0x4bc);
    fn_80440BF4(lbl_8053AED8, 0);
    (*(u8**)(*(u8**)(param_1 + 0x2c) + 4))[0xb0] = 0;
    p = (FsaNode*)*(u8**)(*(u8**)(param_1 + 0x2c) + 4);
    p->v9(0);
    p = (*(FsaNode**)(param_1 + 4))->v15(0x5061636375723031ULL);
    p->v9(0);
    for (i = 0; i < 2; i++) {
        fn_80402E08(*(u8**)(param_1 + 0x24 + i * 4), lbl_80543534, lbl_8054353C);
        *(u16*)(*(u8**)(param_1 + 0x24 + i * 4) + 0x22) = 0;
    }
    lbl[0x243] = 0;
    fn_80458FF0(lbl_8053AF80, 0x1000005, 1, 0);
}

extern "C" char lbl_804B03D8[];
extern "C" char lbl_80529DEC[];
extern "C" void* lbl_8053ADC0;
extern "C" void getTotalFreeSize__7JKRHeapFv(void*);
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*, void*);
extern "C" void __dl__FPv(void*);
extern "C" u8* fn_803D8D74(u8* param_1, s16 param_2) {
    s32 i;
    void** slot;
    u8* obj;

    if (param_1 != 0) {
        *(void**)param_1 = lbl_804B03D8;
        getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 8));
        obj = *(u8**)(param_1 + 0x4c);
        if (obj != 0) {
            *(u32*)(obj + 0xf4) |= 1;
            *(s32*)(obj + 0x24) = 1;
            *(void**)(param_1 + 0x4c) = 0;
        }
        slot = (void**)(param_1 + 4);
        for (i = 1; i < 3; i++, slot++) {
            if (slot[0x13] != 0) {
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), slot[0x13]);
                slot[0x13] = 0;
            }
        }
        obj = *(u8**)(param_1 + 0x4);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(param_1 + 0x4) = 0;
        obj = *(u8**)(param_1 + 0x8);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(param_1 + 0x8) = 0;
        obj = *(u8**)(param_1 + 0x1c);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(param_1 + 0x1c) = 0;
        obj = *(u8**)(param_1 + 0x20);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(param_1 + 0x20) = 0;
        slot = (void**)param_1;
        for (i = 0; i < 2; i++, slot++) {
            obj = *(u8**)(slot + 9);
            if (obj != 0) {
                ((FsaDisposable*)obj)->del(1);
            }
            slot[9] = 0;
        }
        obj = *(u8**)(param_1 + 0x2c);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(param_1 + 0x2c) = 0;
        obj = *(u8**)(param_1 + 0x30);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(param_1 + 0x30) = 0;
        slot = (void**)param_1;
        for (i = 0; i < 4; i++, slot++) {
            obj = *(u8**)(slot + 13);
            if (obj != 0) {
                ((FsaDisposable*)obj)->del(1);
            }
            slot[13] = 0;
        }
        obj = *(u8**)(param_1 + 0x44);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(param_1 + 0x44) = 0;
        obj = *(u8**)(param_1 + 0x10);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(param_1 + 0x10) = 0;
        obj = *(u8**)(param_1 + 0x18);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(param_1 + 0x18) = 0;
        lbl_8053ADC0 = 0;
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}

typedef void* (*FsaFind)(void*, u32, u32, u32);
typedef void (*FsaSet1)(void*, void*);
typedef void (*FsaSet2)(void*, void*, void*);
extern "C" char lbl_804AF86C[];
extern "C" void* lbl_8053AD78;
extern "C" void* __nw__FUl(u32);
extern "C" void fn_80402F04(void*, void*);
extern "C" void* fn_80403144(u32, void*);
extern "C" void* load__20J2DAnmLoaderDataBaseFPCv(void*);
extern "C" void fn_803832BC(void*, u32, s32, s32, s32);
extern "C" void __ct__9J2DScreenFv(void*);
extern "C" void __ct__10J2DPictureFPC7ResTIMG(void*, void*);
extern "C" u8* fn_803D901C(u8* param_1) {
    u8* pic;
    u8* sc;
    u8* base = (u8*)lbl_80476F80;
    u8* n;
    u8* o;
    u32 hi1[2];
    u32 lo1[2];
    u32 hi2[2];
    u32 lo2[2];

    *(void**)param_1 = lbl_804B03D8;
    ((JKRHeap*)*(void**)((u8*)lbl_80529DEC + 8))->getTotalFreeSize();
    lbl_8053ADC0 = param_1;

    sc = (u8*)__nw__FUl(0x118);
    if (sc != 0) {
        __ct__9J2DScreenFv(sc);
    }
    *(void**)(param_1 + 4) = sc;
    ((J2DScreen*)*(void**)(param_1 + 4))->setPriority((char*)base + 0x4d0, 0x1100000, (JKRArchive*)*(void**)((u8*)lbl_8053AD68 + 0x14));
    sc = (u8*)__nw__FUl(0x118);
    if (sc != 0) {
        __ct__9J2DScreenFv(sc);
    }
    *(void**)(param_1 + 8) = sc;
    ((J2DScreen*)*(void**)(param_1 + 8))->setPriority((char*)base + 0x4dc, 0x1100000, (JKRArchive*)*(void**)((u8*)lbl_8053AD68 + 0x14));

    sc = fn_804030C4(0x54494D47, base + 0x4ec);
    pic = (u8*)__nw__FUl(0x168);
    if (pic != 0) {
        __ct__10J2DPictureFPC7ResTIMG(pic, sc);
    }
    *(void**)(param_1 + 0x1c) = pic;
    lo1[1] = 0;
    hi1[1] = 0xff;
    lo1[0] = 0;
    hi1[0] = 0xff;
    (*(FsaSet2*)(*(u8**)(param_1 + 0x1c) + 0x130))(*(void**)(param_1 + 0x1c), &lo1[1], &hi1[1]);
    pic = (u8*)__nw__FUl(0x168);
    if (pic != 0) {
        __ct__10J2DPictureFPC7ResTIMG(pic, sc);
    }
    *(void**)(param_1 + 0x20) = pic;
    lo2[1] = 0;
    hi2[1] = 0xff;
    lo2[0] = 0;
    hi2[0] = 0xff;
    (*(FsaSet2*)(*(u8**)(param_1 + 0x20) + 0x130))(*(void**)(param_1 + 0x20), &lo2[1], &hi2[1]);

    o = *(u8**)(param_1 + 4);
    sc = *(u8**)((u8*)lbl_8053AD78 + 0x154);
    o = (u8*)(*(FsaFind*)(*(u8**)o + 0x3c))(o, 0x6e6f0000, 0x54, 0x6e6f3031);
    (*(FsaSet1*)(*(u8**)o + 0x9c))(o, sc);
    o = *(u8**)(param_1 + 4);
    sc = *(u8**)((u8*)lbl_8053AD78 + 0x154);
    o = (u8*)(*(FsaFind*)(*(u8**)o + 0x3c))(o, 0x65730000, 0x5479, 0x65733031);
    (*(FsaSet1*)(*(u8**)o + 0x9c))(o, sc);
    o = *(u8**)(param_1 + 4);
    o = (u8*)(*(FsaFind*)(*(u8**)o + 0x3c))(o, 0x65730000, 0x5479, 0x65733031);
    fn_803832BC(((J2DTextBox*)o)->getStringPtr(), 0x10c, 0, 0, 0);
    o = *(u8**)(param_1 + 4);
    o = (u8*)(*(FsaFind*)(*(u8**)o + 0x3c))(o, 0x6e6f0000, 0x54, 0x6e6f3031);
    fn_803832BC(((J2DTextBox*)o)->getStringPtr(), 0x10d, 0, 0, 0);

    n = (u8*)__nw__FUl(0x2c);
    if (n != 0) {
        *(void**)n = lbl_804AF86C;
    }
    *(void**)(param_1 + 0x24) = n;
    o = *(u8**)(param_1 + 4);
    sc = (u8*)(*(FsaFind*)(*(u8**)o + 0x3c))(o, 0x500000, 0x507965, 0x73623034);
    fn_80402F04(*(void**)(param_1 + 0x24), sc);

    n = (u8*)__nw__FUl(0x2c);
    if (n != 0) {
        *(void**)n = lbl_804AF86C;
    }
    *(void**)(param_1 + 0x28) = n;
    o = *(u8**)(param_1 + 4);
    sc = (u8*)(*(FsaFind*)(*(u8**)o + 0x3c))(o, 0x6f620000, 0x506e, 0x6f623034);
    fn_80402F04(*(void**)(param_1 + 0x28), sc);

    n = (u8*)__nw__FUl(0x2c);
    if (n != 0) {
        *(void**)n = lbl_804AF86C;
    }
    *(void**)(param_1 + 0x2c) = n;
    o = *(u8**)(param_1 + 4);
    sc = (u8*)(*(FsaFind*)(*(u8**)o + 0x3c))(o, 0x50610000, 0x50616363, 0x75723032);
    fn_80402F04(*(void**)(param_1 + 0x2c), sc);

    n = (u8*)__nw__FUl(0x2c);
    if (n != 0) {
        *(void**)n = lbl_804AF86C;
    }
    *(void**)(param_1 + 0x30) = n;
    o = *(u8**)(param_1 + 4);
    sc = (u8*)(*(FsaFind*)(*(u8**)o + 0x3c))(o, 0x50740000, 0x5074746c, 0x626b3035);
    fn_80402F04(*(void**)(param_1 + 0x30), sc);

    n = (u8*)__nw__FUl(0x2c);
    if (n != 0) {
        *(void**)n = lbl_804AF86C;
    }
    *(void**)(param_1 + 0x34) = n;
    o = *(u8**)(param_1 + 4);
    sc = (u8*)(*(FsaFind*)(*(u8**)o + 0x3c))(o, 0x4e0000, 0x4e6461, 0x74613033);
    fn_80402F04(*(void**)(param_1 + 0x34), sc);

    n = (u8*)__nw__FUl(0x2c);
    if (n != 0) {
        *(void**)n = lbl_804AF86C;
    }
    *(void**)(param_1 + 0x38) = n;
    o = *(u8**)(param_1 + 4);
    sc = (u8*)(*(FsaFind*)(*(u8**)o + 0x3c))(o, 0x6c6b0000, 0x5062, 0x6c6b3033);
    fn_80402F04(*(void**)(param_1 + 0x38), sc);

    n = (u8*)__nw__FUl(0x2c);
    if (n != 0) {
        *(void**)n = lbl_804AF86C;
    }
    *(void**)(param_1 + 0x3c) = n;
    o = *(u8**)(param_1 + 4);
    sc = (u8*)(*(FsaFind*)(*(u8**)o + 0x3c))(o, 0x6c6b0000, 0x5062, 0x6c6b3032);
    fn_80402F04(*(void**)(param_1 + 0x3c), sc);

    n = (u8*)__nw__FUl(0x2c);
    if (n != 0) {
        *(void**)n = lbl_804AF86C;
    }
    *(void**)(param_1 + 0x40) = n;
    o = *(u8**)(param_1 + 4);
    sc = (u8*)(*(FsaFind*)(*(u8**)o + 0x3c))(o, 0x6c6b0000, 0x5062, 0x6c6b3031);
    fn_80402F04(*(void**)(param_1 + 0x40), sc);

    o = *(u8**)(param_1 + 4);
    o = (u8*)(*(FsaFind*)(*(u8**)o + 0x3c))(o, 0x4e0000, 0x4e6461, 0x74613035);
    o[0xb0] = 0;

    n = (u8*)__nw__FUl(0x2c);
    if (n != 0) {
        *(void**)n = lbl_804AF86C;
    }
    *(void**)(param_1 + 0x44) = n;
    o = *(u8**)(param_1 + 8);
    sc = (u8*)(*(FsaFind*)(*(u8**)o + 0x3c))(o, 0x524f0000, 0, 0x524f4f54);
    fn_80402F04(*(void**)(param_1 + 0x44), sc);

    *(void**)(param_1 + 0x48) = *(void**)((u8*)lbl_8053AED8 + 8);

    OSInitFastCast();

    *(void**)(param_1 + 0xc) = fn_80403144(0x5343524e, base + 0x4fc);
    *(void**)(param_1 + 0x10) = load__20J2DAnmLoaderDataBaseFPCv(*(void**)(param_1 + 0xc));
    o = *(u8**)(param_1 + 8);
    sc = (u8*)(*(FsaFind*)(*(u8**)o + 0x3c))(o, 0x500000, 0x50306b, 0x616b3030);
    (*(FsaSet1*)(*(u8**)sc + 0x60))(sc, *(void**)(param_1 + 0x10));
    *(void**)(param_1 + 0x14) = fn_80403144(0x5343524e, base + 0x50c);
    *(void**)(param_1 + 0x18) = load__20J2DAnmLoaderDataBaseFPCv(*(void**)(param_1 + 0x14));
    o = *(u8**)(param_1 + 8);
    (*(FsaSet1*)(*(u8**)o + 0x70))(o, *(void**)(param_1 + 0x18));

    *(u32*)(param_1 + 0x4c) = 0;
    *(u32*)(param_1 + 0x50) = 0;
    *(u32*)(param_1 + 0x54) = 0;
    *(f32*)(param_1 + 0x58) = lbl_80543534;
    *(f32*)(param_1 + 0x5c) = lbl_80543534;
    *(u32*)(param_1 + 0x60) = 0;
    *(u32*)(param_1 + 0x64) = 0;
    *(s16*)(param_1 + 0x74) = 0;
    *(s16*)(param_1 + 0x68) = -1;
    *(s16*)(param_1 + 0x6a) = -1;
    *(s16*)(param_1 + 0x6c) = 0;
    *(s16*)(param_1 + 0x6e) = 0;
    *(s16*)(param_1 + 0x70) = 0;
    *(s16*)(param_1 + 0x72) = 0;
    param_1[0x76] = 2;
    param_1[0x77] = 0;
    param_1[0x78] = 0;
    param_1[0x79] = 0;
    param_1[0x7a] = 0;

    o = *(u8**)(param_1 + 4);
    o = (u8*)(*(FsaFind*)(*(u8**)o + 0x3c))(o, 0xffffffff, lbl_80476F80[0], lbl_80476F80[4]);
    param_1[0x7b] = o[0xb2];
    o = *(u8**)(param_1 + 4);
    o = (u8*)(*(FsaFind*)(*(u8**)o + 0x3c))(o, 0xffffffff, lbl_80476F80[0x200], lbl_80476F80[0x204]);
    param_1[0x7c] = o[0xb2];
    o = *(u8**)(param_1 + 8);
    o = (u8*)(*(FsaFind*)(*(u8**)o + 0x3c))(o, 0x500000, 0x507374, 0x61726c69);
    param_1[0x7d] = o[0xb2];
    param_1[0x7e] = 0;
    param_1[0x7f] = 0;
    param_1[0x80] = 0;
    param_1[0x81] = 0;
    return param_1;
}

extern "C" char lbl_80528168[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
void fn_803D9720(void) {
    char* base = lbl_80528168;

    if (!__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, base + 0x0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (!__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, base + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (!__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, base + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (!__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, base + 0x24);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (!__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, base + 0x30);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (!__init__memPool___30JASPoolAllocObject_9JAIStream) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, base + 0x3c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (!__init__memPool___35JASPoolAllocObject_13JAISoundChild) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, base + 0x48);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (!__init__memPool___27JASPoolAllocObject_6JAISeq) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, base + 0x54);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (!__init__memPool___26JASPoolAllocObject_5JAISe) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, base + 0x60);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

