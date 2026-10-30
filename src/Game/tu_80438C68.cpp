#include "types.h"
#include "JSystem/J2D/J2DPane.h"
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/J2D/J2DPicture.h"
#include "JSystem/JParticle/JPAEmitter.h"
#include "dolphin/os/OSFastCast.h"


struct FsaVObj {
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual void v6(void);
    virtual void v7(void);
    virtual void v8(void);
    virtual void v9(s32 a);
    virtual void v10(void);
          virtual void v11(s32 a);

    virtual void v12(void);
    virtual void v13(void);
    virtual void v14(void);
          virtual J2DPane* v15(s32 a, s32 b, s32 c);

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
    virtual void v57(void);
    virtual void v58(void);
    virtual void v59(s32 a, s32 b, s32 c, f32 d, f32 e, f32 f, f32 g);
};

struct Slot0 {
    virtual void slot0(s32 arg);
};

extern "C" void* fn_8013C824(void);
extern "C" void* lbl_804B17A0[];
extern "C" void* lbl_8053AEC8;
extern "C" void __dl__FPv(void* p);
extern "C" f32 lbl_80543C40;
extern "C" f32 lbl_80543C44;
extern "C" void* fn_801F856C(void);
extern "C" u32 fn_8022EA0C(u32 a);
extern "C" void* fn_8023E724(u32 i);
extern "C" s32 fn_8023DE58(u32 i);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, s32 id, void* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" u8 fn_8022ADB0(void);
extern "C" void fn_8022ADE4(void);
extern "C" void fn_8043D67C(void* a, s32 b, s32 c, u8 d);
extern "C" void fn_80458F9C(void* a, u32 b);
extern "C" void fn_802B7CD8(void* p);
extern "C" void* lbl_8053AED0;
extern "C" void* lbl_8053AF80;
extern "C" u8 lbl_80529DEC[];
extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053AB10;
extern "C" u8 lbl_8050DB0C[];
extern "C" void fn_8022ADCC(void);
extern "C" s32 fn_801F666C(void* mgr, s32 idx);
extern "C" void* fn_8013CC50(u32 a, void* pos, s32 id, s32 b, s32 c, s32 d, s32 e, s32 f, f32 scale);
extern "C" void fn_80458880(void* mgr, u32 p, s32 v);
extern "C" void* fn_80309C4C(void* a, u32 b, s32 c);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* a, void* p);
extern "C" void* lbl_8053AD30;
extern "C" f32 lbl_80543C48;
extern "C" f32 lbl_80543C4C;
extern "C" f32 lbl_80543C50;
extern "C" f32 lbl_80543C54;
extern "C" f32 lbl_80543C58;
extern "C" f32 lbl_80543C5C;
extern "C" f32 lbl_80543C60;
extern "C" f32 lbl_80543C64;
extern "C" f32 lbl_80543C68;
extern "C" void fn_80438C68(u8* p) {
    switch (p[0x58]) {
    case 0:
        if (*(s32*)(p + 0x44) == -1) {
            s32 id;
            u32 pos;
            u32 a5 = *(u32*)(p + 0x48);
            pos = (u32)fn_8023E724(fn_8022EA0C(0));
            id = fn_8023DE58(0);
            *(s32*)(p + 0x44) = Actor_CreateByID(fn_801F856C(), 0x544e474c, id, (void*)pos, a5, -1, -1);
            p[0x5f] = fn_8022ADB0();
            if (p[0x5f] == 0) {
                fn_8022ADE4();
            }
        }
        if (*(s32*)(p + 0x44) > 0) {
            p[0x58] = 1;
            p[0x59] = 0xff;
        }
        break;
    case 1:
        switch (p[0x59]) {
        case 0:
            p[0x58] = 2;
            break;
        case 1:
        case 2: {
            s32 n;
            s32 off;
            s32 i;
            fn_8043D67C(lbl_8053AED0, 0x33a, 0, lbl_80529DEC[0x24f]);
            *(s32*)(p + 0x38) += 1;
            p[0x58] = 3;
            p[0x40] = 5;
            fn_80458F9C(lbl_8053AF80, 0x14);
            n = *(s32*)((u8*)fn_801F856C() + 0x1008);
            i = 0;
            for (off = 0; i < n; off += 4, i++) {
                void* a = *(void**)((u8*)fn_801F856C() + off + 8);
                if (a != 0 && *(u32*)((u8*)a + 0x1a0) == 0x44455448 && a != 0) {
                    fn_802B7CD8(a);
                }
            }
            break;
        }
        }
        break;
    }
}

extern "C" void fn_80438E10(u8* p, u8 flag)
{
    *(u8*)(p + 0x40) = flag;
    if (flag) {
        return;
    }
    *(u8*)(p + 0x40) = 0;
    *(u8*)(p + 0x42) = 0;
    *(u8*)(p + 0x5d) = 0;
    *(s32*)(p + 0x44) = -1;
    *(s32*)(p + 0x48) = 0;
    *(u8*)(p + 0x58) = 0;
    *(u8*)(p + 0x59) = 0xff;
    *(u8*)(p + 0x5a) = 0xff;
    *(f32*)(p + 0x4c) = 255.0f;
    *(f32*)(p + 0x50) = 0.0f;
    *(s16*)(p + 0x54) = 0;
    *(s16*)(p + 0x56) = 0;
    *(s32*)(p + 0x3c) = 0;
    *(s32*)(p + 0xc) = 0;
    *(s32*)(p + 0x10) = 0;
    *(s32*)(p + 0x14) = 0;
    *(s32*)(p + 0x18) = 0;
    *(s32*)(p + 0x1c) = 0;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2c) = 0;
    *(s32*)(p + 0x30) = 0;
    *(u8*)(p + 0x5f) = 0;
}

#pragma opt_strength_reduction off
extern "C" u32 fn_80438E94(u8* p) {
    s32 id;
    u16 c;
    u8* q;
    int i;
    f32 pos[3];
    id = *(s32*)(p + 0x44);
    if (id > 0) {
        if ((u32)fn_801F666C(fn_801F856C(), id) == 0) {
            *(s32*)(p + 0x44) = -2;
        }
    }
    switch (p[0x40]) {
    case 0:
        if (p[0x5a] == 0xff) {
            if (((u8*)lbl_8053AAF8)[0x7f] == 1) {
                if (lbl_80529DEC[0x24f] != 0) {
                    *(s32*)(p + 0x48) = 0;
                    p[0x5a] = 1;
                } else p[0x5a] = 0;
            } else {
                p[0x5a] = 0;
            }
            p[0x5b] = ((u8*)(*(void**)((u8*)lbl_8053AB10 + 0x2c)))[0xc];
        }
        if (p[0x5a] != 0) {
            fn_80438C68(p);
        } else {
            *(s32*)(p + 0x44) = -2;
            p[0x58] = 2;
        }
        if (p[0x58] == 2) {
            c = p[0x41];
            if ((s32)p[0x42] < (s32)c - 2) {
                p[0x42] += 2;
                ((J2DPane*)*(void**)(p + 4))->search('Pblk')->setAlpha(p[0x42]);
            } else {
                ((J2DPane*)*(void**)(p + 4))->search('Pblk')->setAlpha(c);
                p[0x40] = 1;
                *(s16*)(p + 0x56) = 1;
                fn_80458F9C(lbl_8053AF80, 0x14);
            }
        }
        break;
    case 1:
        *(s32*)(p + 0x3c) += 1;
        if (*(s32*)(p + 0x3c) >= 0x3c) {
            p[0x40] = 3;
        }
        switch (*(s32*)(p + 0x3c) - 0x11) {
        case 13:
            pos[0] = lbl_80543C48; pos[1] = 255.0f; pos[2] = 0.0f;
            if (*(void**)(p + 0xc) == 0) {
                *(void**)(p + 0xc) = fn_8013CC50(0, pos, 0x567, 0, 0, 0, 0, 1, lbl_80543C4C);
            }
            if (*(void**)(p + 0xc) != 0) {
                *(u32*)((u8*)*(void**)(p + 0xc) + 0xf4) |= 0x40;
            }
            fn_80458880(lbl_8053AF80, 0xd, -1);
            break;
        case 0:
            pos[0] = lbl_80543C50; pos[1] = 255.0f; pos[2] = 0.0f;
            if (*(void**)(p + 0x10) == 0) {
                *(void**)(p + 0x10) = fn_8013CC50(0, pos, 0x567, 0, 0, 0, 0, 1, lbl_80543C4C);
            }
            if (*(void**)(p + 0x10) != 0) {
                *(u32*)((u8*)*(void**)(p + 0x10) + 0xf4) |= 0x40;
            }
            fn_80458880(lbl_8053AF80, 0xd, -1);
            break;
        case 4:
            pos[0] = lbl_80543C54; pos[1] = 255.0f; pos[2] = 0.0f;
            if (*(void**)(p + 0x14) == 0) {
                *(void**)(p + 0x14) = fn_8013CC50(0, pos, 0x567, 0, 0, 0, 0, 1, lbl_80543C4C);
            }
            if (*(void**)(p + 0x14) != 0) {
                *(u32*)((u8*)*(void**)(p + 0x14) + 0xf4) |= 0x40;
            }
            fn_80458880(lbl_8053AF80, 0xd, -1);
            break;
        case 10:
            pos[0] = lbl_80543C58; pos[1] = 255.0f; pos[2] = 0.0f;
            if (*(void**)(p + 0x18) == 0) {
                *(void**)(p + 0x18) = fn_8013CC50(0, pos, 0x567, 0, 0, 0, 0, 1, lbl_80543C4C);
            }
            if (*(void**)(p + 0x18) != 0) {
                *(u32*)((u8*)*(void**)(p + 0x18) + 0xf4) |= 0x40;
            }
            fn_80458880(lbl_8053AF80, 0xd, -1);
            break;
        case 2:
            pos[0] = lbl_80543C5C; pos[1] = 255.0f; pos[2] = 0.0f;
            if (*(void**)(p + 0x1c) == 0) {
                *(void**)(p + 0x1c) = fn_8013CC50(0, pos, 0x567, 0, 0, 0, 0, 1, lbl_80543C4C);
            }
            if (*(void**)(p + 0x1c) != 0) {
                *(u32*)((u8*)*(void**)(p + 0x1c) + 0xf4) |= 0x40;
            }
            fn_80458880(lbl_8053AF80, 0xd, -1);
            break;
        case 8:
            pos[0] = lbl_80543C60; pos[1] = 255.0f; pos[2] = 0.0f;
            if (*(void**)(p + 0x20) == 0) {
                *(void**)(p + 0x20) = fn_8013CC50(0, pos, 0x567, 0, 0, 0, 0, 1, lbl_80543C4C);
            }
            if (*(void**)(p + 0x20) != 0) {
                *(u32*)((u8*)*(void**)(p + 0x20) + 0xf4) |= 0x40;
            }
            fn_80458880(lbl_8053AF80, 0xd, -1);
            break;
        case 16:
            pos[0] = lbl_80543C64; pos[1] = 255.0f; pos[2] = 0.0f;
            if (*(void**)(p + 0x24) == 0) {
                *(void**)(p + 0x24) = fn_8013CC50(0, pos, 0x567, 0, 0, 0, 0, 1, lbl_80543C4C);
            }
            if (*(void**)(p + 0x24) != 0) {
                *(u32*)((u8*)*(void**)(p + 0x24) + 0xf4) |= 0x40;
            }
            fn_80458880(lbl_8053AF80, 0xd, -1);
            break;
        case 6:
            pos[0] = lbl_80543C68; pos[1] = 255.0f; pos[2] = 0.0f;
            if (*(void**)(p + 0x28) == 0) {
                *(void**)(p + 0x28) = fn_8013CC50(0, pos, 0x567, 0, 0, 0, 0, 1, lbl_80543C4C);
            }
            if (*(void**)(p + 0x28) != 0) {
                *(u32*)((u8*)*(void**)(p + 0x28) + 0xf4) |= 0x40;
            }
            fn_80458880(lbl_8053AF80, 0xd, -1);
            break;
        }
        break;
    case 3:
        if (*(s32*)(p + 0x44) == -2) {
            if (fn_80309C4C(lbl_8053AD30, 0x1100, -1) != 0) {
                f32 vec[3];
                vec[0] = 0.0f; vec[1] = 0.0f; vec[2] = 0.0f;
                if (*(void**)(p + 0x2c) == 0) {
                    *(void**)(p + 0x2c) = fn_8013CC50(0, vec, 0x568, 0, 0, 0, 0, 1, lbl_80543C4C);
                }
                if (*(void**)(p + 0x2c) != 0) {
                    *(u32*)((u8*)*(void**)(p + 0x2c) + 0xf4) |= 0x40;
                }
                if (*(void**)(p + 0x30) == 0) {
                    *(void**)(p + 0x30) = fn_8013CC50(0, vec, 0x566, 0, 0, 0, 0, 1, lbl_80543C4C);
                }
                if (*(void**)(p + 0x30) != 0) {
                    *(u32*)((u8*)*(void**)(p + 0x30) + 0xf4) |= 0x40;
                }
                p[0x40] = 4;
                p[0x42] = 0;
                fn_80458880(lbl_8053AF80, 0x48, -1);
                fn_80458880(lbl_8053AF80, 0xc, -1);
            }
        }
        break;
    case 4:
        if ((s32)p[0x42] < *(s16*)(lbl_8050DB0C + 0x5c)) {
            p[0x42] += 1;
        } else {
        *(s32*)(p + 0x3c) += 1;
        if (*(s32*)(p + 0x3c) >= *(s16*)(*(u8**)(p + 8) + 6) - 1) {
            for (i = 0, q = p; i < 8; i++, q += 4) {
                if (*(void**)(q + 0xc) != 0) {
                    void* manager=*(void**)((u8*)fn_8013C824() + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(q + 0xc));
                    *(void**)(q + 0xc) = 0;
                }
            }
            if (*(void**)(p + 0x2c) != 0) {
                void* manager=*(void**)((u8*)fn_8013C824() + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(p + 0x2c));
                *(void**)(p + 0x2c) = 0;
            }
            if (*(void**)(p + 0x30) != 0) {
                void* manager=*(void**)((u8*)fn_8013C824() + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(p + 0x30));
                *(void**)(p + 0x30) = 0;
            }
            *(s32*)(p + 0x3c) = 0;
            p[0x42] = 0;
            p[0x40] = 6;
        }
        break;        }
        break;
    case 6:
        if ((s32)p[0x42] < *(s16*)(lbl_8050DB0C + 0x5e)) {
            p[0x42] += 1;
        } else {
            lbl_80529DEC[0x237] = 7;
            p[0x40] = 7;
        }
        break;
    case 2:
    case 5:
        break;
    }
        *(f32*)(*(u8**)(p + 8) + 8) = (f32)*(s32*)(p + 0x3c);
        ((J2DPane*)*(void**)(p + 4))->search(0x004e646174613031ULL)->animationTransform();
        for (i = 0, q = p; i < 8; i++, q += 4) {
            if (*(void**)(q + 0xc) != 0 && (*(JPABaseEmitter**)(q + 0xc))->isEnableDeleteEmitter()) {
                void* manager=*(void**)((u8*)fn_8013C824() + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(q + 0xc));
                *(void**)(q + 0xc) = 0;
            }
        }
    if (*(JPABaseEmitter**)(p + 0x2c) && (*(JPABaseEmitter**)(p + 0x2c))->isEnableDeleteEmitter()) {
        void* manager=*(void**)((u8*)fn_8013C824() + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(p + 0x2c));
        *(void**)(p + 0x2c)=0;
    }
    if (*(JPABaseEmitter**)(p + 0x30) && (*(JPABaseEmitter**)(p + 0x30))->isEnableDeleteEmitter()) {
        void* manager=*(void**)((u8*)fn_8013C824() + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(p + 0x30));
        *(void**)(p + 0x30)=0;
    }

    if (*(s16*)(p + 0x54) < *(s16*)(lbl_8050DB0C + 0x9c)) {
        *(s16*)(p + 0x54) += 1;
    } else if (*(f32*)(p + 0x4c) > 0.0f) {
        *(f32*)(p + 0x4c) = *(f32*)(p + 0x4c) - 255.0f / (f32)*(s16*)(lbl_8050DB0C + 0x9e);
        if (*(f32*)(p + 0x4c) <= 0.0f) {
            p[0x5d] = 0;
            *(f32*)(p + 0x4c) = 0.0f;
        }
    }
    if (p[0x40] == 5) {
        ((u8*)*(void**)((u8*)lbl_8053AB10 + 0x2c))[0xc] = p[0x5b];
        if (p[0x5f] == 0) {
            fn_8022ADCC();
        }
        if (p[0x5e] == 0) {
            p[0x5e] = 1;
        } else {
            p[0x5e] = 0;
        }
        p[0x5c] = 0;
    } else {
        if ((u32)(u8)(s32)*(f32*)(p + 0x4c) < p[0x5b]) {
            ((u8*)*(void**)((u8*)lbl_8053AB10 + 0x2c))[0xc] = (u8)(s32)*(f32*)(p + 0x4c);
        }
        p[0x5c] = (u8)(s32)(255.0f - *(f32*)(p + 0x4c));
    }
    if (*(s16*)(p + 0x56) > 0) {
        if (*(s16*)(p + 0x56) < *(s16*)(lbl_8050DB0C + 0x98)) {
            *(s16*)(p + 0x56) += 1;
        } else if (*(f32*)(p + 0x50) < 255.0f) {
            *(f32*)(p + 0x50) = *(f32*)(p + 0x50) + 255.0f / (f32)*(s16*)(lbl_8050DB0C + 0x9a);
            if (*(f32*)(p + 0x50) > 255.0f) {
                *(f32*)(p + 0x50) = 255.0f;
            }
        }
    }
    return p[0x40];
}
#pragma opt_strength_reduction reset
extern "C" f32 lbl_80543C78;
extern "C" f32 lbl_80543C7C;
extern "C" f32 lbl_80543C80;
extern "C" void* lbl_8053AB10;
extern "C" u8* lbl_8053ADC8;
extern "C" void fn_8013B490(void* p);
extern "C" f64 lbl_80543C70;
extern "C" void fn_804399A0(u8* param_1)
{
    fn_8013B490(lbl_8053AB10);
    FsaVObj* obj = *(FsaVObj**)(param_1 + 0x34);
    obj->v9((s32)*(f32*)(param_1 + 0x50));
    obj = *(FsaVObj**)(param_1 + 0x34);
    obj->v59(0, 0, 0, lbl_80543C78, lbl_80543C78, lbl_80543C7C, lbl_80543C80);
    *(f32*)(*(u8**)(param_1 + 8) + 8) = (f32)*(s32*)(param_1 + 0x3c);
    (*(J2DPane**)(param_1 + 4))->search(0x004e646174613031ULL)->animationTransform();
    (*(J2DScreen**)(param_1 + 4))->draw(lbl_80543C44, lbl_80543C44, *(J2DGrafContext**)((u8*)lbl_8053AB10 + 0x10));
    if (*(u8*)(param_1 + 0x40) == 3) {
        *(u8*)((u8*)lbl_8053ADC8 + 0x20) = 1;
        *(u8*)((u8*)lbl_8053ADC8 + 0x21) = 0;
    }
}

extern "C" void fn_80439AB0(u8* p)
{
    *(u8*)(p + 0x40) = 0;
    *(u8*)(p + 0x42) = 0;
    *(u8*)(p + 0x5d) = 0;
    *(s32*)(p + 0x44) = -1;
    *(s32*)(p + 0x48) = 0;
    *(u8*)(p + 0x58) = 0;
    *(u8*)(p + 0x59) = 0xff;
    *(u8*)(p + 0x5a) = 0xff;
    *(f32*)(p + 0x4c) = 255.0f;
    *(f32*)(p + 0x50) = 0.0f;
    *(s16*)(p + 0x54) = 0;
    *(s16*)(p + 0x56) = 0;
    *(s32*)(p + 0x3c) = 0;
    *(s32*)(p + 0xc) = 0;
    *(s32*)(p + 0x10) = 0;
    *(s32*)(p + 0x14) = 0;
    *(s32*)(p + 0x18) = 0;
    *(s32*)(p + 0x1c) = 0;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2c) = 0;
    *(s32*)(p + 0x30) = 0;
    *(u8*)(p + 0x5f) = 0;
}

extern "C" void** fn_80439B28(void** this_, s16 flag) {
    int i;
    if (this_ != 0) {
        *this_ = lbl_804B17A0;
        void* p1 = this_[1];
        if (p1 != 0) {
            ((Slot0*)p1)->slot0(1);
        }
        this_[1] = 0;
        void* p2 = this_[2];
        if (p2 != 0) {
            ((Slot0*)p2)->slot0(1);
        }
        this_[2] = 0;
        void* p3 = this_[13];
        if (p3 != 0) {
            ((Slot0*)p3)->slot0(1);
        }
        this_[13] = 0;
        void** pp = this_;
        i = 0;
        do {
            if (pp[3] != 0) {
                JPAEmitterManager* mgr = *(JPAEmitterManager**)((char*)fn_8013C824() + 0xc);
                mgr->forceDeleteEmitter((JPABaseEmitter*)pp[3]);
                pp[3] = 0;
            }
            pp++;
            i++;
        } while (i < 8);
        if (this_[11] != 0) {
            JPAEmitterManager* mgr = *(JPAEmitterManager**)((char*)fn_8013C824() + 0xc);
            mgr->forceDeleteEmitter((JPABaseEmitter*)this_[11]);
            this_[11] = 0;
        }
        if (this_[12] != 0) {
            JPAEmitterManager* mgr = *(JPAEmitterManager**)((char*)fn_8013C824() + 0xc);
            mgr->forceDeleteEmitter((JPABaseEmitter*)this_[12]);
            this_[12] = 0;
        }
        lbl_8053AEC8 = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void setPriority__9J2DScreenFPCcUlP10JKRArchive(void* self, const char* name, u32 flags, void* archive);
extern "C" void* fn_80403084(u32 id, const char* name);
extern "C" void* fn_804030C4(u32 id, const char* name);
extern "C" void* load__20J2DAnmLoaderDataBaseFPCv(const void* data);
extern "C" char lbl_8048F6D0[];
extern "C" void* fn_80439C78(void** this_) {
    const char* base;
    s32 local_28 = 0;
    s32 local_24 = 0;
    s32 local_20 = 0xff;
    s32 local_1c = 0xff;
    void** vt;
    void* res;
    J2DPicture* pic;
    u8* p;

    base = (const char*)lbl_8048F6D0;
    this_[0] = lbl_804B17A0;
    lbl_8053AEC8 = this_;
    this_[1] = new J2DScreen();
    setPriority__9J2DScreenFPCcUlP10JKRArchive(this_[1], base + 0xc, 0x1100000, *(void**)((u8*)lbl_80529DEC + 0x4c));
    OSInitFastCast();
    fn_80403084(0x5343524e, base + 0x1c);
    this_[2] = load__20J2DAnmLoaderDataBaseFPCv(0);
    vt = *(void***)this_[1];
    res = ((void* (*)(void*, u32, u32, u32))vt[15])(this_[1], 0x4e0000, 0x4e6461, 0x74613031);
    vt = *(void***)res;
    ((void (*)(void*, void*))vt[24])(res, this_[2]);
    this_[15] = 0;
    this_[3] = 0;
    this_[4] = 0;
    this_[5] = 0;
    this_[6] = 0;
    this_[7] = 0;
    this_[8] = 0;
    this_[9] = 0;
    this_[10] = 0;
    this_[11] = 0;
    this_[12] = 0;
    res = fn_804030C4(0x54494d47, base + 0x2c);
    pic = new J2DPicture((ResTIMG*)res);
    this_[13] = pic;
    vt = *(void***)pic;
    ((void (*)(void*, void*, void*))vt[76])(pic, &local_1c, &local_24);
    p = (u8*)this_;
    *(f32*)(p + 0x4c) = lbl_80543C40;
    *(f32*)(p + 0x50) = lbl_80543C44;
    *(s16*)(p + 0x54) = 0;
    *(s16*)(p + 0x56) = 0;
    *(u8*)(p + 0x40) = 0;
    *(u8*)(p + 0x42) = 0;
    vt = *(void***)this_[1];
    res = ((void* (*)(void*, u32, u32, u32))vt[15])(this_[1], 0x50620000, 0, 0x50626c6b);
    *(u8*)((u8*)res + 0xb0) = 0;
    vt = *(void***)this_[1];
    res = ((void* (*)(void*, u32, u32, u32))vt[15])(this_[1], 0x50620000, 0, 0x50626c6b);
    p[0x41] = ((u8*)res)[0xb2];
    *(u8*)(p + 0x5b) = 0;
    *(s32*)(p + 0x44) = -1;
    *(s32*)(p + 0x48) = 0;
    *(u8*)(p + 0x58) = 0;
    *(u8*)(p + 0x59) = 0xff;
    *(u8*)(p + 0x5a) = 0xff;
    *(s32*)(p + 0x38) = 0;
    *(u8*)(p + 0x5c) = 0;
    *(u8*)(p + 0x5d) = 0;
    *(u8*)(p + 0x5e) = 0;
    *(u8*)(p + 0x5f) = 0;
    return this_;
}

extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void*, void*);
extern "C" void fn_80439EC4(void) {
    static u32 c0[3], c1[3], c2[3], c3[3], c4[3], c5[3], c6[3], c7[3], c8[3];
    if (!__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, (void*)__dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, c0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (!__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, (void*)__dt__35JASMemPool_MultiThreaded_8JASTrackFv, c1);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (!__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, (void*)__dt__38JASMemPool_MultiThreaded_10JASChannelFv, c2);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (!__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, (void*)__dt__29JASMemPool_15JASPoolObj3_FSAFv, c3);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (!__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, (void*)__dt__29JASMemPool_15JASPoolObj4_FSAFv, c4);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (!__init__memPool___30JASPoolAllocObject_9JAIStream) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, (void*)__dt__22JASMemPool_9JAIStreamFv, c5);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (!__init__memPool___35JASPoolAllocObject_13JAISoundChild) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, (void*)__dt__27JASMemPool_13JAISoundChildFv, c6);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (!__init__memPool___27JASPoolAllocObject_6JAISeq) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, (void*)__dt__19JASMemPool_6JAISeqFv, c7);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (!__init__memPool___26JASPoolAllocObject_5JAISe) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, (void*)__dt__18JASMemPool_5JAISeFv, c8);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

