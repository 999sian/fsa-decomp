#include "types.h"
#include <math.h>
static inline f32 maxMenuExtent(const f64 x, const f64 y) { f32 a = x; f32 b = y; return a >= b ? a : b; }
static inline void fn_8043E80C_pair(u8* self, u32 off, u32 c1, u32 c2) {
    void* obj = *(void**)(self + off);
    ((void (*)(void*, u32*, u32*))(*(void***)obj)[76])(obj, &c1, &c2);
}
extern const f32 lbl_80543D00;
extern const f32 lbl_80543D04;
extern const f32 lbl_80543D08;
extern const f32 lbl_80543D0C;
extern const f32 lbl_80543D10;
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/J2D/J2DPane.h"
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/J2D/J2DPicture.h"
static inline void menuCorner(J2DPicture* picture, u32 corner, JUtility::TColor color) {
    picture->mCornerColors[corner].setRGBA(color);
}

struct FsaMenuNumber {
    u8 unk_0x0[0x118];
    f32 x[10];
    f32 y[10];
    f32 scale[10];
    u8 unk_0x190[0x64];
    u8 digits[5][10];
    u8 count[10];
    u8 unk_0x230[10];
    u8 level[10];
    u8 type[10];
    u8 unk_0x24e[4];
    u8 used;
};

struct FsaBlock48 {
    u32 w[12];
};
extern "C" u8 lbl_804B1810[];
extern "C" u8 lbl_8052C5D8[];
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
extern "C" const char* lbl_804B1900[];
extern "C" const char* lbl_804B1820[];
extern "C" void* fn_804030C4(u32 type, const char* name);
extern "C" void* fn_804032E8(u32 type, const char* name);
extern "C" void fn_803837A4(void* dst, u32 a, f32 b, f32 c, u32 d, u32 e);
extern "C" void fn_8030C5F0(void* a, void* b, u32 c, u32 d, void* out);
extern "C" void fn_80402E08(void* p, f32 a, f32 b);
extern void* lbl_8053AB10;
extern void* sManager__8JUTVideo;
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 i);
extern "C" char* getStringPtr__10J2DTextBoxCFv(void* self);
extern "C" char* strcpy(char* dst, const char* src);
extern const f32 lbl_80543C88;
extern const f32 lbl_80543CC0;
extern const f32 lbl_80543CC4;
extern const f32 lbl_80543CC8;
extern const f32 lbl_80543CCC;
extern const f32 lbl_80543CC0;
extern const f32 lbl_80543CCC;
extern const f64 lbl_80543C98;
extern const f32 lbl_80543C8C;
extern const f32 lbl_80543C90;
extern const f32 lbl_80543CB8;
extern const f32 lbl_80543CBC;
extern u8 lbl_8050DB0C[];
extern u8 lbl_80529DEC[];
extern void* lbl_8053AED0;
extern "C" void fn_8013B490(void* p);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void* screen, f32 x, f32 y, void* ctx);

struct Fn8043EED8_Obj {
    virtual void v02(s32 how);
};

extern "C" u8 lbl_804B1920[];

struct Fn8043ABCC_Obj {
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void* v15(u32 a, s32 b, u32 c);
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68(void* a, s32 b);
};

extern const f32 lbl_80543C88;
extern const f32 lbl_80543CC4;
extern const f32 lbl_80543CC8;
extern const f32 lbl_80543CE8;
extern const f32 lbl_80543CEC;


extern void* lbl_8053AED0;
extern "C" void fn_8043DF8C(void* p, f32 x, f32 y);
extern char* lbl_8053AAF8;
extern s32 lbl_8053AEF0;
extern u8 lbl_80529DEC[];
extern u8 lbl_8050EC80[];
extern "C" void fn_8043A450(void* param_1, s32 param_2, s32 param_3);
extern const f32 lbl_80543CFC;
extern const f32 lbl_80543CF8;
extern const f32 lbl_80543CF0;
extern const f32 lbl_80543CF4;
extern "C" void fn_8041E708(void* p, s32 i, s32 val, u8 flag);
extern "C" void fn_80425234(void* p, s32 i, s32 val, u8 flag);
#pragma dont_inline on
extern "C" void fn_8043E7CC(void* game, void* v);
#pragma dont_inline reset
extern "C" void fn_8041E58C(void* p);
extern "C" void fn_80425128(void* p);
extern "C" void fn_8041FC2C(void* p);
extern "C" void fn_8041F5FC(void* p);
extern "C" void fn_80425F24(void* p);
extern "C" void fn_8043E80C(u8* self, s32 digit, u8 alpha, u32 c1, u32 c2, f32 a, f32 b, f32 c);
extern const f32 lbl_80543CA0;
extern const f32 lbl_80543CD0;
extern const f32 lbl_80543CD4;
extern const f32 lbl_80543CD8;
extern const f32 lbl_80543CDC;
extern const f32 lbl_80543CE0;
extern const f32 lbl_80543CE4;
extern void* lbl_8053AB10;
extern "C" void fn_8013B490(void* p);
extern "C" void fn_8044A06C(void* p);
extern "C" void fn_80445D24(void* p);
extern "C" void fn_80448334(void* p);
extern "C" void fn_8044AFD8(void* p);
extern "C" void fn_804490B8(void* p);
extern "C" void fn_804479A0(void* p);
extern "C" u8 fn_80402940(void* p, s32 a, f32 x, f32 y, s32 b);
extern "C" void fn_80446DB0(void* p);
extern "C" void fn_804263A8(void* p);
extern "C" void fn_80443688(s32 p);
extern "C" void fn_8043A0E8(u8 param_1) {
    if (((u8*)lbl_8053AAF8)[0x7f] != 0 && (*(u32*)(lbl_8050EC80 + 0x28 + 0xc8 * *(s32*)(lbl_8050EC80 + 0x10)) & 1) == 0 &&
        *(s32*)(lbl_80529DEC + 0x118) == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 0) {
        if (param_1 == 0) {
            return;
        }
    }
    if (*(s32*)(lbl_80529DEC + 0x118) == 10 && *(s32*)(lbl_80529DEC + 0x11c) == 2) {
        return;
    }
    *((u8*)lbl_8053AED0 + 0xdd) = 0xf;
}

extern "C" void fn_8043A170(u32 param_1, u8 param_2) {
    if (((u8*)lbl_8053AAF8)[0x7f] != 0 && (*(u32*)(lbl_8050EC80 + 0x28 + 0xc8 * *(s32*)(lbl_8050EC80 + 0x10)) & 1) == 0 &&
        *(s32*)(lbl_80529DEC + 0x118) == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 0) {
        if (param_2 == 0) {
            return;
        }
    }
    if (*(s32*)(lbl_80529DEC + 0x118) == 10 && *(s32*)(lbl_80529DEC + 0x11c) == 2) {
        return;
    }
    *((u8*)lbl_8053AED0 + 0xdd) = *((u8*)lbl_8053AED0 + 0xdd) | (u8)(1 << param_1);
}

extern "C" void fn_8043A208(u8* param_1, f32 param_2, f32 param_3, f32 param_4, f32 param_5) {
    struct VObj {
        virtual void v00();
        virtual void v01();
        virtual void v02();
        virtual void v03();
        virtual void v04();
        virtual void v05();
        virtual void v06();
        virtual void v07();
        virtual void v08();
        virtual void v09();
    };
    if (*(void**)(param_1 + 0x10) != NULL) {
        *(f32*)(param_1 + 0x1c0) = param_2;
        *(f32*)(param_1 + 0x1c4) = param_3;
        *(f32*)(param_1 + 0x1c8) = param_4;
        *(f32*)(param_1 + 0x1cc) = param_5;
        ((VObj*)*(void**)(param_1 + 0x10))->v07();
        *(u8*)(param_1 + 0x254) = 1;
    }
}

extern "C" void fn_8043A268(u8* param_1, s32 param_2, s32 param_3, s16 param_4, f32 param_5, f32 param_6) {
    struct VScreen {
        virtual void v02();
        virtual void v03();
        virtual void v04();
        virtual void v05();
        virtual void v06();
        virtual void v07();
        virtual void v08();
        virtual void v09();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual Fn8043ABCC_Obj* search(u64 tag);
    };
    u8* self = (u8*)param_1;
    void* uVar1;
    if ((param_2 == 0 && param_3 == 2) || (param_2 == 1 && param_3 == 2) || (param_2 == 2 && param_3 == 2) ||
        (param_2 == 3 && param_3 == 2) || (param_2 == 4 && param_3 == 2) || (param_2 == 5 && param_3 == 2) ||
        (param_2 == 6 && param_3 == 2) || (param_2 == 7 && param_3 == 1)) {
        return;
    }
    if (((u8*)lbl_8053AAF8)[0x7f] != 0 && param_2 < 8 && param_3 < 4) {
        s32 idx = param_3 + param_2 * 4;
        if (idx != 0) {
            uVar1 = fn_804032E8(0x54494D47, lbl_804B1820[idx]);
        } else {
            uVar1 = fn_804030C4(0x54494D47, lbl_804B1820[idx]);
        }
        (*(VScreen**)(self + 8))->search(0x507730313031ULL)->v68(uVar1, 0);
        u8* p = (u8*)(*(VScreen**)(self + 8))->search(0x507730313031ULL);
        p[0xb0] = 1;
        u8* q = (u8*)(*(VScreen**)(self + 8))->search(0x5064663031ULL);
        q[0xb0] = 0;
        *(s16*)(self + 0x106) = 1;
        self[0x10d] = 1;
        *(f32*)(self + 0xf4) = param_5;
        *(f32*)(self + 0xf8) = param_6;
        *(s16*)(self + 0x108) = param_4;
    }
}

extern "C" const char* lbl_804B1820[];
extern "C" void fn_8043A450(void* param_1, s32 param_2, s32 param_3) {
    struct VScreen {
        virtual void v02();
        virtual void v03();
        virtual void v04();
        virtual void v05();
        virtual void v06();
        virtual void v07();
        virtual void v08();
        virtual void v09();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual Fn8043ABCC_Obj* search(u64 tag);
    };
    u8* self = (u8*)param_1;
    void* uVar1;
    if ((param_2 == 0 && param_3 == 2) || (param_2 == 1 && param_3 == 2) || (param_2 == 2 && param_3 == 2) ||
        (param_2 == 3 && param_3 == 2) || (param_2 == 4 && param_3 == 2) || (param_2 == 5 && param_3 == 2) ||
        (param_2 == 6 && param_3 == 2) || (param_2 == 7 && param_3 == 1)) {
        return;
    }
    if (((u8*)lbl_8053AAF8)[0x7f] == 0) return;
    if (param_2 >= 8) return;
    if (param_3 >= 4) return;
    s32 idx = param_3 + param_2 * 4;
    if (idx != 0) {
        uVar1 = fn_804032E8(0x54494D47, lbl_804B1820[idx]);
    } else {
        uVar1 = fn_804030C4(0x54494D47, lbl_804B1820[idx]);
    }
    (*(VScreen**)(self + 8))->search(0x507730313031ULL)->v68(uVar1, 0);
    u8* p = (u8*)(*(VScreen**)(self + 8))->search(0x507730313031ULL);
    p[0xb0] = 1;
    u8* q = (u8*)(*(VScreen**)(self + 8))->search(0x5064663031ULL);
    q[0xb0] = 0;
    *(s16*)(self + 0x106) = 1;
    self[0x10d] = 0;
}

extern "C" void fn_8043A608(void* param_1) {
    fn_8043A450(param_1, *(s32*)(lbl_80529DEC + 0x118), *(s32*)(lbl_80529DEC + 0x11c));
}

extern "C" void fn_8043A638(u8* param_1) {
    struct PaneAlpha {
        virtual void v02();
        virtual void v03();
        virtual void v04();
        virtual void v05();
        virtual void v06();
        virtual void v07();
        virtual void v08();
        virtual void setAlpha(s32 alpha);
    };
    f32 f31 = lbl_80543C88;
    f32 f30 = f31;
    s16 r31;
    s16 r30 = *(s16*)(lbl_8050DB0C + 0x22a);
    s16 r29 = *(s16*)(lbl_8050DB0C + 0x22c);
    s16 r28 = *(s16*)(lbl_8050DB0C + 0x22e);
    if (*(s16*)(param_1 + 0x106) != 0) {
        ((u8*)lbl_8053AED0)[0xdc] |= 0x1;
        ((u8*)lbl_8053AED0)[0xdc] |= 0x2;
        ((u8*)lbl_8053AED0)[0xdc] |= 0x4;
        ((u8*)lbl_8053AED0)[0xdc] |= 0x8;
        if (param_1[0x10d] == 0) {
            r31 = *(s16*)(lbl_8050DB0C + 0x2e6) + 0x50;
            s16 cur = *(s16*)(param_1 + 0x106);
            if (cur < r31) {
                ((PaneAlpha*)(*(J2DScreen**)(param_1 + 8))->search(0x5064663031ULL))->setAlpha(0);
            } else if (cur <= r31 + r30) {
                ((PaneAlpha*)(*(J2DScreen**)(param_1 + 8))->search(0x5064663031ULL))->setAlpha((s32)(lbl_80543C8C * ((f32)(cur - r31) / (f32)r30)));
            } else {
                s32 r25 = r29 + r31 + r30;
                if (cur > r25) {
                    ((PaneAlpha*)(*(J2DScreen**)(param_1 + 8))->search(0x5064663031ULL))->setAlpha((s32)(lbl_80543C8C * ((f32)(r28 + r25 - cur) / (f32)r28)));
                }
            }
            J2DPane* pdf = (*(J2DScreen**)(param_1 + 8))->search(0x5064663031ULL);
            (*(J2DScreen**)(param_1 + 8))->search(0x507730313031ULL)->setAlpha(pdf->getAlpha());
            s16 cur2 = *(s16*)(param_1 + 0x106);
            if (cur2 < r31 + r30 + r29 + r28) {
                *(s16*)(param_1 + 0x106) = cur2 + 1;
            } else {
                *(s16*)(param_1 + 0x106) = 0;
            }
            if (*(s32*)(lbl_80529DEC + 0x118) == 8 && *(s32*)(lbl_80529DEC + 0x11c) == 3) {
                f30 = lbl_80543C90;
            }
            f31 += (f32)*(s16*)(lbl_8050DB0C + 0x2e2);
            f30 += (f32)*(s16*)(lbl_8050DB0C + 0x2e4);
            (*(J2DScreen**)(param_1 + 8))->search(0x507730313031ULL)->move(*(f32*)(param_1 + 0xec) + f31, *(f32*)(param_1 + 0xf0) + f30);
        } else {
            s16 r25 = *(s16*)(param_1 + 0x106);
            r31 = *(s16*)(param_1 + 0x108);
            if (r25 < 0x14) {
                ((PaneAlpha*)(*(J2DScreen**)(param_1 + 8))->search(0x5064663031ULL))->setAlpha(0);
            } else if (r25 <= r30 + 0x14) {
                ((PaneAlpha*)(*(J2DScreen**)(param_1 + 8))->search(0x5064663031ULL))->setAlpha((s32)(lbl_80543C8C * ((f32)(r25 - 0x14) / (f32)r30)));
            } else {
                s32 r26 = r31 + (r30 + 0x14);
                if (r25 > r26) {
                    ((PaneAlpha*)(*(J2DScreen**)(param_1 + 8))->search(0x5064663031ULL))->setAlpha((s32)(lbl_80543C8C * ((f32)(r28 + r26 - r25) / (f32)r28)));
                }
            }
            J2DPane* pdf = (*(J2DScreen**)(param_1 + 8))->search(0x5064663031ULL);
            (*(J2DScreen**)(param_1 + 8))->search(0x507730313031ULL)->setAlpha(pdf->getAlpha());
            register s16 cur2 = *(s16*)(param_1 + 0x106);
            register s32 lim = r30 + r31;
            lim += r28;
            if (cur2 < lim + 0x14) {
                *(s16*)(param_1 + 0x106) = cur2 + 1;
            } else {
                *(s16*)(param_1 + 0x106) = 0;
            }
            (*(J2DScreen**)(param_1 + 8))->search(0x507730313031ULL)->move(*(f32*)(param_1 + 0xf4), *(f32*)(param_1 + 0xf8));
        }
        fn_8013B490(lbl_8053AB10);
        draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(param_1 + 8), lbl_80543C88, lbl_80543C88, *(void**)((u8*)lbl_8053AB10 + 0x10));
    }
}

extern "C" void fn_8043ABCC(u8* param_1, s32 param_2) {
    void* uVar1;
    Fn8043ABCC_Obj* piVar2;
    s32 idx = param_2 & ~(param_2 >> 31);
    if (idx != 1) {
        uVar1 = fn_804032E8(0x54494D47, lbl_804B1900[idx]);
    } else {
        uVar1 = fn_804030C4(0x54494D47, lbl_804B1900[idx]);
    }
    piVar2 = (Fn8043ABCC_Obj*)(*(Fn8043ABCC_Obj**)(param_1 + 8))->v15(0x64660000, 0x50, 0x64663031);
    piVar2->v68(uVar1, 0);
    s32 sz = 0x50;
    u8* p = (u8*)(*(Fn8043ABCC_Obj**)(param_1 + 8))->v15(0x64660000, sz, 0x64663031);
    p[0xb0] = 1;
    u8* q = (u8*)(*(Fn8043ABCC_Obj**)(param_1 + 8))->v15(0x30310000, 0x5077, 0x30313031);
    q[0xb0] = 0;
    *(s16*)(param_1 + 0x106) = 1;
    param_1[0x10d] = 0;
}

extern "C" void fn_8043ACE4(u8* self){
static JUtility::TColor colors[4] = {JUtility::TColor(242,73,18,255),JUtility::TColor(242,73,18,255),JUtility::TColor(242,73,18,255),JUtility::TColor(216,255,161,255)};
s32 i;
J2DPicture* picture;
f32 alpha;
if(self[0x253]){
for(i=0;i<self[0x253];i++){
alpha=(f32)self[0x24e+i]/255.0f;
fn_8013B490(lbl_8053AB10);
switch(*(s32*)(self+i*4+0x1d0)){
case 1:
(*(J2DPicture**)(self+0x280))->setBlackWhite(JUtility::TColor(0,0,0,0),JUtility::TColor(0,0,0,255));
picture=(*(J2DPicture**)(self+0x280));picture->setCornerColor(JUtility::TColor(255,255,255,255),JUtility::TColor(255,255,255,255),JUtility::TColor(255,255,255,255),JUtility::TColor(255,255,255,255));
(*(J2DPicture**)(self+0x280))->setAlpha((u8)(200.0f*alpha));
(*(J2DPicture**)(self+0x280))->draw(3.0f+*(f32*)(self+i*4+0x190),3.0f+*(f32*)(self+i*4+0x1a0),48.0f**(f32*)(self+i*4+0x1b0),48.0f**(f32*)(self+i*4+0x1b0),false,false,false);
(*(J2DPicture**)(self+0x280))->setBlackWhite(JUtility::TColor(0,0,0,0),JUtility::TColor(255,255,255,255));
picture=(*(J2DPicture**)(self+0x280));picture->setCornerColor(JUtility::TColor(185,18,18,255),JUtility::TColor(216,58,22,255),JUtility::TColor(185,84,18,255),JUtility::TColor(255,157,16,255));
(*(J2DPicture**)(self+0x280))->setAlpha(self[0x24e+i]);
(*(J2DPicture**)(self+0x280))->draw(*(f32*)(self+i*4+0x190),*(f32*)(self+i*4+0x1a0),48.0f**(f32*)(self+i*4+0x1b0),48.0f**(f32*)(self+i*4+0x1b0),false,false,false);break;
case 2:
(*(J2DPicture**)(self+0x284))->setBlackWhite(JUtility::TColor(0,0,0,0),JUtility::TColor(0,0,0,255));
picture=(*(J2DPicture**)(self+0x284));picture->setCornerColor(JUtility::TColor(255,255,255,255),JUtility::TColor(255,255,255,255),JUtility::TColor(255,255,255,255),JUtility::TColor(255,255,255,255));
(*(J2DPicture**)(self+0x284))->setAlpha((u8)(200.0f*alpha));
(*(J2DPicture**)(self+0x284))->draw(3.0f+*(f32*)(self+i*4+0x190),3.0f+*(f32*)(self+i*4+0x1a0),48.0f**(f32*)(self+i*4+0x1b0),48.0f**(f32*)(self+i*4+0x1b0),false,false,false);
(*(J2DPicture**)(self+0x284))->setBlackWhite(JUtility::TColor(0,0,0,0),JUtility::TColor(255,255,255,255));
picture=(*(J2DPicture**)(self+0x284));picture->setCornerColor(JUtility::TColor(242,72,9,255),JUtility::TColor(242,72,9,255),JUtility::TColor(242,171,36,255),JUtility::TColor(252,255,33,255));
(*(J2DPicture**)(self+0x284))->setAlpha(self[0x24e+i]);
(*(J2DPicture**)(self+0x284))->draw(*(f32*)(self+i*4+0x190),*(f32*)(self+i*4+0x1a0),48.0f**(f32*)(self+i*4+0x1b0),48.0f**(f32*)(self+i*4+0x1b0),false,false,false);break;
case 3:
(*(J2DPicture**)(self+0x288))->setBlackWhite(JUtility::TColor(0,0,0,0),JUtility::TColor(0,0,0,255));
picture=(*(J2DPicture**)(self+0x288));picture->setCornerColor(JUtility::TColor(255,255,255,255),JUtility::TColor(255,255,255,255),JUtility::TColor(255,255,255,255),JUtility::TColor(255,255,255,255));
(*(J2DPicture**)(self+0x288))->setAlpha((u8)(200.0f*alpha));
(*(J2DPicture**)(self+0x288))->draw(3.0f+*(f32*)(self+i*4+0x190),3.0f+*(f32*)(self+i*4+0x1a0),48.0f**(f32*)(self+i*4+0x1b0),48.0f**(f32*)(self+i*4+0x1b0),false,false,false);
(*(J2DPicture**)(self+0x288))->setBlackWhite(JUtility::TColor(0,0,0,0),JUtility::TColor(255,255,119,255));
picture=(*(J2DPicture**)(self+0x288));picture->setCornerColor(JUtility::TColor(255,255,255,255),JUtility::TColor(255,255,255,255),JUtility::TColor(255,255,255,255),JUtility::TColor(255,255,255,255));
(*(J2DPicture**)(self+0x288))->setAlpha(self[0x24e+i]);
(*(J2DPicture**)(self+0x288))->draw(*(f32*)(self+i*4+0x190),*(f32*)(self+i*4+0x1a0),48.0f**(f32*)(self+i*4+0x1b0),48.0f**(f32*)(self+i*4+0x1b0),false,false,false);break;
case 4:
(*(J2DPicture**)(self+0x28c))->setBlackWhite(JUtility::TColor(0,0,0,0),JUtility::TColor(0,0,0,255));
picture=(*(J2DPicture**)(self+0x28c));picture->setCornerColor(JUtility::TColor(255,255,255,255),JUtility::TColor(255,255,255,255),JUtility::TColor(255,255,255,255),JUtility::TColor(255,255,255,255));
(*(J2DPicture**)(self+0x28c))->setAlpha((u8)(200.0f*alpha));
(*(J2DPicture**)(self+0x28c))->draw(3.0f+*(f32*)(self+i*4+0x190),3.0f+*(f32*)(self+i*4+0x1a0),48.0f**(f32*)(self+i*4+0x1b0),48.0f**(f32*)(self+i*4+0x1b0),false,false,false);
(*(J2DPicture**)(self+0x28c))->setBlackWhite(JUtility::TColor(0,0,0,0),JUtility::TColor(216,255,161,255));
picture=(*(J2DPicture**)(self+0x28c));picture->setCornerColor(JUtility::TColor(255,255,255,255),JUtility::TColor(255,255,255,255),JUtility::TColor(255,255,255,255),JUtility::TColor(255,255,255,255));
(*(J2DPicture**)(self+0x28c))->setAlpha(self[0x24e+i]);
(*(J2DPicture**)(self+0x28c))->draw(*(f32*)(self+i*4+0x190),*(f32*)(self+i*4+0x1a0),48.0f**(f32*)(self+i*4+0x1b0),48.0f**(f32*)(self+i*4+0x1b0),false,false,false);break;

}
}
self[0x253]=0;
}
}

extern "C" void fn_8043BB84(u8* self)
{
    static JUtility::TColor colors[6] = {
        JUtility::TColor(255,210,0,255), JUtility::TColor(180,255,0,255),
        JUtility::TColor(250,100,50,255), JUtility::TColor(110,225,240,255),
        JUtility::TColor(225,130,255,255), JUtility::TColor(255,255,255,255)
    };
    s32 i;
    s32 j;
    f32 alpha;
    if(self[0x252]) {
        for(i=0;i<self[0x252];i++) {
            alpha=(f32)self[0x244+i]/255.0f;
            fn_8013B490(lbl_8053AB10);
            alpha=200.0f*alpha;
            for(j=0;j<5;j++) {
                switch(self[0x1f4+i+j*10]) {
                case 0:
                    (*(J2DPicture**)(self+0x258))->setBlackWhite(JUtility::TColor(0,0,0,0),JUtility::TColor(0,0,0,255));
                    (*(J2DPicture**)(self+0x258))->setAlpha((u8)alpha);
                    (*(J2DPicture**)(self+0x258))->draw(3.0f+*(f32*)(self+i*4+0x118),3.0f+*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    (*(J2DPicture**)(self+0x258))->setBlackWhite(JUtility::TColor(0,0,0,0),colors[self[0x23a+i]]);
                    (*(J2DPicture**)(self+0x258))->setAlpha(self[0x244+i]);
                    (*(J2DPicture**)(self+0x258))->draw(*(f32*)(self+i*4+0x118),*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    break;
                case 1:
                    (*(J2DPicture**)(self+0x25c))->setBlackWhite(JUtility::TColor(0,0,0,0),JUtility::TColor(0,0,0,255));
                    (*(J2DPicture**)(self+0x25c))->setAlpha((u8)alpha);
                    (*(J2DPicture**)(self+0x25c))->draw(3.0f+*(f32*)(self+i*4+0x118),3.0f+*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    (*(J2DPicture**)(self+0x25c))->setBlackWhite(JUtility::TColor(0,0,0,0),colors[self[0x23a+i]]);
                    (*(J2DPicture**)(self+0x25c))->setAlpha(self[0x244+i]);
                    (*(J2DPicture**)(self+0x25c))->draw(*(f32*)(self+i*4+0x118),*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    break;
                case 2:
                    (*(J2DPicture**)(self+0x260))->setBlackWhite(JUtility::TColor(0,0,0,0),JUtility::TColor(0,0,0,255));
                    (*(J2DPicture**)(self+0x260))->setAlpha((u8)alpha);
                    (*(J2DPicture**)(self+0x260))->draw(3.0f+*(f32*)(self+i*4+0x118),3.0f+*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    (*(J2DPicture**)(self+0x260))->setBlackWhite(JUtility::TColor(0,0,0,0),colors[self[0x23a+i]]);
                    (*(J2DPicture**)(self+0x260))->setAlpha(self[0x244+i]);
                    (*(J2DPicture**)(self+0x260))->draw(*(f32*)(self+i*4+0x118),*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    break;
                case 3:
                    (*(J2DPicture**)(self+0x264))->setBlackWhite(JUtility::TColor(0,0,0,0),JUtility::TColor(0,0,0,255));
                    (*(J2DPicture**)(self+0x264))->setAlpha((u8)alpha);
                    (*(J2DPicture**)(self+0x264))->draw(3.0f+*(f32*)(self+i*4+0x118),3.0f+*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    (*(J2DPicture**)(self+0x264))->setBlackWhite(JUtility::TColor(0,0,0,0),colors[self[0x23a+i]]);
                    (*(J2DPicture**)(self+0x264))->setAlpha(self[0x244+i]);
                    (*(J2DPicture**)(self+0x264))->draw(*(f32*)(self+i*4+0x118),*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    break;
                case 4:
                    (*(J2DPicture**)(self+0x268))->setBlackWhite(JUtility::TColor(0,0,0,0),JUtility::TColor(0,0,0,255));
                    (*(J2DPicture**)(self+0x268))->setAlpha((u8)alpha);
                    (*(J2DPicture**)(self+0x268))->draw(3.0f+*(f32*)(self+i*4+0x118),3.0f+*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    (*(J2DPicture**)(self+0x268))->setBlackWhite(JUtility::TColor(0,0,0,0),colors[self[0x23a+i]]);
                    (*(J2DPicture**)(self+0x268))->setAlpha(self[0x244+i]);
                    (*(J2DPicture**)(self+0x268))->draw(*(f32*)(self+i*4+0x118),*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    break;
                case 5:
                    (*(J2DPicture**)(self+0x26c))->setBlackWhite(JUtility::TColor(0,0,0,0),JUtility::TColor(0,0,0,255));
                    (*(J2DPicture**)(self+0x26c))->setAlpha((u8)alpha);
                    (*(J2DPicture**)(self+0x26c))->draw(3.0f+*(f32*)(self+i*4+0x118),3.0f+*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    (*(J2DPicture**)(self+0x26c))->setBlackWhite(JUtility::TColor(0,0,0,0),colors[self[0x23a+i]]);
                    (*(J2DPicture**)(self+0x26c))->setAlpha(self[0x244+i]);
                    (*(J2DPicture**)(self+0x26c))->draw(*(f32*)(self+i*4+0x118),*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    break;
                case 6:
                    (*(J2DPicture**)(self+0x270))->setBlackWhite(JUtility::TColor(0,0,0,0),JUtility::TColor(0,0,0,255));
                    (*(J2DPicture**)(self+0x270))->setAlpha((u8)alpha);
                    (*(J2DPicture**)(self+0x270))->draw(3.0f+*(f32*)(self+i*4+0x118),3.0f+*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    (*(J2DPicture**)(self+0x270))->setBlackWhite(JUtility::TColor(0,0,0,0),colors[self[0x23a+i]]);
                    (*(J2DPicture**)(self+0x270))->setAlpha(self[0x244+i]);
                    (*(J2DPicture**)(self+0x270))->draw(*(f32*)(self+i*4+0x118),*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    break;
                case 7:
                    (*(J2DPicture**)(self+0x274))->setBlackWhite(JUtility::TColor(0,0,0,0),JUtility::TColor(0,0,0,255));
                    (*(J2DPicture**)(self+0x274))->setAlpha((u8)alpha);
                    (*(J2DPicture**)(self+0x274))->draw(3.0f+*(f32*)(self+i*4+0x118),3.0f+*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    (*(J2DPicture**)(self+0x274))->setBlackWhite(JUtility::TColor(0,0,0,0),colors[self[0x23a+i]]);
                    (*(J2DPicture**)(self+0x274))->setAlpha(self[0x244+i]);
                    (*(J2DPicture**)(self+0x274))->draw(*(f32*)(self+i*4+0x118),*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    break;
                case 8:
                    (*(J2DPicture**)(self+0x278))->setBlackWhite(JUtility::TColor(0,0,0,0),JUtility::TColor(0,0,0,255));
                    (*(J2DPicture**)(self+0x278))->setAlpha((u8)alpha);
                    (*(J2DPicture**)(self+0x278))->draw(3.0f+*(f32*)(self+i*4+0x118),3.0f+*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    (*(J2DPicture**)(self+0x278))->setBlackWhite(JUtility::TColor(0,0,0,0),colors[self[0x23a+i]]);
                    (*(J2DPicture**)(self+0x278))->setAlpha(self[0x244+i]);
                    (*(J2DPicture**)(self+0x278))->draw(*(f32*)(self+i*4+0x118),*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    break;
                case 9:
                    (*(J2DPicture**)(self+0x27c))->setBlackWhite(JUtility::TColor(0,0,0,0),JUtility::TColor(0,0,0,255));
                    (*(J2DPicture**)(self+0x27c))->setAlpha((u8)alpha);
                    (*(J2DPicture**)(self+0x27c))->draw(3.0f+*(f32*)(self+i*4+0x118),3.0f+*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    (*(J2DPicture**)(self+0x27c))->setBlackWhite(JUtility::TColor(0,0,0,0),colors[self[0x23a+i]]);
                    (*(J2DPicture**)(self+0x27c))->setAlpha(self[0x244+i]);
                    (*(J2DPicture**)(self+0x27c))->draw(*(f32*)(self+i*4+0x118),*(f32*)(self+i*4+0x140),16.0f**(f32*)(self+i*4+0x168),16.0f**(f32*)(self+i*4+0x168),false,false,false);
                    break;
                }
                *(f32*)(self+i*4+0x118)+=*(f32*)(self+i*4+0x168)*lbl_80543CC0;
            }
        }
        self[0x252]=0;
    }
}

#pragma opt_strength_reduction off
extern "C" s32 fn_8043CB24(FsaMenuNumber* self, s32 value, u8 p3, u8 p4, u8 p5, u8 p6, f32 f1, f32 f2, f32 f3) {
    u8 n = self->used;
    if (n < 10) {
        int count = p5;
        f32 b = (f32)(count % 2);
        f32 a = (f32)(p5 / 2);
        self->x[n] = f1 - lbl_80543CB8 * (lbl_80543CBC * b * f3) - (lbl_80543CC0 * a) * f3;
        self->y[self->used] = f2 - lbl_80543CB8 * (lbl_80543CBC * f3);
        self->scale[self->used] = f3;
        self->type[self->used] = p3;
        self->count[self->used] = p5;
        self->digits[0][self->used] = 0xff;
        self->digits[1][self->used] = 0xff;
        self->digits[2][self->used] = 0xff;
        self->digits[3][self->used] = 0xff;
        self->digits[4][self->used] = 0xff;
        int pow = 1;
        u8 flag = 0;
        if (p6) flag = 1;
        for (int i=0; i<count; i++) pow *= 10;
        if (value > pow-1) value=pow-1;
        if (value<0) value=0;
        pow /= 10;
        u8* d=(u8*)self;
        for (int i=count-1; i>0; i--) {
            int digit=value/pow;
            value-=digit*pow;
            if (!flag && digit==0) d[self->used+0x1f4]=0xff;
            else {
                if (!flag) flag=1;
                d[self->used+0x1f4]=digit;
            }
            d+=10;
            pow/=10;
        }
        self->digits[count-1][self->used]=value;
        if (p4>5) p4=5;
        self->level[self->used]=p4;
        self->used++;
        return 1;
    }
    return 0;
}
#pragma opt_strength_reduction reset
extern "C" void fn_8043CDA0(u8* self) {
	f32 x;
	f32 y;
	u8 done;
	if (self[0x10c] == 0) {
		x = lbl_80543C88;
		y = lbl_80543CC4;
	} else {
		f32 pane_y = *(f32*)(*(u8**)(self + 0x64) + 0xc);
		x = lbl_80543CC8 - pane_y;
		y = x - lbl_80543CC4;
	}
	done = fn_80402940(*(void**)(self + 0x40), 0xb, x, y, 0);
	for (int i = 1; i < 12; i++) {
		fn_80402940(*(void**)(self + 0x40 + i * 4), 0xb, x, y, 0);
	}
	if (done) {
		u8* game = (u8*)lbl_8053AED0;
		game[0x10a] = 0;
		*(u32*)(game + 0xfc) = 0;
		*(u32*)(game + 0xe8) = 0;
		*(u32*)(game + 0x100) = 0;
		self[0x10b] = 0;
	}
}

extern "C" void fn_8043CEA0(u8* self) {
    *(s16*)(self + 0x104) = *(s16*)(self + 0x104) - 1;
    if (*(s32*)(lbl_8053AAF8 + 0x4c) != 7) {
        *(s16*)(self + 0x104) = 0;
    }
    if (*(s16*)(self + 0x104) > 0) {
        return;
    }
    *(s16*)(*(u8**)(self + 0x40) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x44) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x48) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x4c) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x50) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x54) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x58) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x5c) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x60) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x64) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x68) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x6c) + 0x22) = 0;
    self[0x10b] = 3;
}

extern "C" void fn_8043CF40(u8* self) {
    f32 f31;
    f32 f30;
    u8 r;
    s32 i;
    if (self[0x10c] == 0) {
        f31 = lbl_80543CC4;
        f30 = lbl_80543C88;
    } else {
        f30 = lbl_80543CC8 - *(f32*)(*(u8**)(self + 0x64) + 0xc);
        f31 = f30 - lbl_80543CC4;
    }
    r = fn_80402940(*(void**)(self + 0x40), 0x13, f31, f30, 0);
    for (i = 1; i < 12; i++) {
        fn_80402940(*(void**)(self + 0x40 + i * 4), 0x13, f31, f30, 0);
    }
    if (r) {
        *(s16*)(self + 0x104) = 0xa0;
        self[0x10b] = 2;
    }
}

#pragma opt_lifetimes off
extern "C" void fn_8043D034(u8* self) {
	u8 flags[4];
	JGeometry::TVec3<f32> outA;
	JGeometry::TVec3<f32> outB;
	JGeometry::TVec3<f32> outLoop;
	JGeometry::TVec3<f32> vecA;
	JGeometry::TVec3<f32> vecB;
	f32 f30;
	s32 j;
	int i;

	if (((u8*)lbl_8053AED0)[0x10a] != 0) {
		*(s16*)(*(u8**)(self + 0x40) + 0x22) = 0;
		*(s16*)(*(u8**)(self + 0x44) + 0x22) = 0;
		*(s16*)(*(u8**)(self + 0x48) + 0x22) = 0;
		*(s16*)(*(u8**)(self + 0x4c) + 0x22) = 0;
		*(s16*)(*(u8**)(self + 0x50) + 0x22) = 0;
		*(s16*)(*(u8**)(self + 0x54) + 0x22) = 0;
		*(s16*)(*(u8**)(self + 0x58) + 0x22) = 0;
		*(s16*)(*(u8**)(self + 0x5c) + 0x22) = 0;
		*(s16*)(*(u8**)(self + 0x60) + 0x22) = 0;
		*(s16*)(*(u8**)(self + 0x64) + 0x22) = 0;
		*(s16*)(*(u8**)(self + 0x68) + 0x22) = 0;
		*(s16*)(*(u8**)(self + 0x6c) + 0x22) = 0;
		fn_803837A4(self + 0x78, *(u32*)(((u8*)lbl_8053AED0) + 0xe8), *(f32*)(*(u8**)(self + 0x70) + 0x18), lbl_80543CCC, *(u32*)(((u8*)lbl_8053AED0) + 0xfc), *(u32*)(((u8*)lbl_8053AED0) + 0x100));
		for (i = 0; i < 2; i++) {
			strcpy(getStringPtr__10J2DTextBoxCFv(*(void**)((u8*)*(void**)(self + 0x70 + i * 4) + 4)), (char*)(self + 0x78));
		}
		vecA.x = lbl_80543C88;
		vecA.y = lbl_80543C88;
		vecA.z = lbl_80543C88;
		fn_8030C5F0(*(void**)((u8*)lbl_8053AB10 + 0x24), &vecA, 0, 0, &outA);
		vecB.x = lbl_80543C88;
		vecB.y = lbl_80543CC0;
		vecB.z = lbl_80543C88;
		fn_8030C5F0(*(void**)((u8*)lbl_8053AB10 + 0x24), &vecB, 0, 0, &outB);
		f30 = (outB.y - outA.y) + ((f32)(s32)*(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 6) - *(f32*)(*(u8**)(self + 0x64) + 0xc));
		self[0x10c] = 0;
		for (j = 0; j < 4; j++) {
			fn_8030C5F0(*(void**)((u8*)lbl_8053AB10 + 0x24), fn_8023E724(j), 0, 0, &outLoop);
			flags[j] = 0;
			if (outLoop.x > lbl_80543C88 && outLoop.x < (f32)(s32)*(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 4)) {
				if (outLoop.y > lbl_80543C88 && outLoop.y < (f32)(s32)*(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 6)) {
					if (outLoop.y > (f32)(s32)*(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 6) - f30) {
						flags[j] = 1;
						self[0x10c] = 1;
					} else if (outLoop.y < f30) {
						flags[j] = 2;
					}
				}
			}
		}
		if (self[0x10c] == 1) {
			for (j=0; j<4; j++) { if(flags[j]==2) self[0x10c]=0; }
		}
		if (self[0x10c] == 0) {
			f30 = lbl_80543CC4;
		} else {
			f30 = lbl_80543CC8 - *(f32*)(*(u8**)(self + 0x64) + 0xc) - lbl_80543CC4;
		}
		for (i = 0; i < 12; i++) {
			fn_80402E08(*(void**)(self + 0x40 + i * 4), lbl_80543C88, f30);
		}
		self[0x10b] = 1;
	}
}
#pragma opt_lifetimes reset
extern "C" void fn_8043D39C(u8* self) {
    if (((u8*)lbl_8053AAF8)[0x7f] != 0) {
        fn_8041F5FC(*(void**)(self + 0x290));
    } else {
        fn_80425F24(*(void**)(self + 0x294));
    }
    if (((u8*)lbl_8053AAF8)[0xfe] == 1) {
        if (*(s32*)(self + 0xe4) != 0) {
            fn_8013B490(lbl_8053AB10);
            *(s32*)(self + 0xe4) -= 1;
            s32 n = *(s32*)(self + 0xe0);
            u8 tens = n / 10;
            u8 ones = n % 10;
            if (tens != 0) {
                fn_8043E80C(self, tens, 0xff, 0xa280a00, 0x28ff28ff, lbl_80543CD0, lbl_80543CA0, lbl_80543CD4);
                fn_8043E80C(self, ones, 0xff, 0xa280a00, 0x28ff28ff, lbl_80543CD8, lbl_80543CA0, lbl_80543CD4);
            } else if (ones != 0) {
                fn_8043E80C(self, ones, 0xff, 0x50500000, 0xffff00ff, lbl_80543CDC, lbl_80543CA0, lbl_80543CE0);
            } else {
                fn_8043E80C(self, ones, 0xff, 0x50282800, 0xff5050ff, lbl_80543CDC, lbl_80543CA0, lbl_80543CE4);
            }
        }
    }
}

extern "C" f32 fn_8043D514(u8* param_1) {
    f32 ret = lbl_80543C88;
    if (param_1[0x10b] != 0 && param_1[0x10c] == 1) {
        J2DPane* pane = *(J2DPane**)(*(u8**)(param_1 + 0x64) + 4);
        f32 y = pane->getBounds()->i.y;
        ret = (lbl_80543CE8 * (lbl_80543CEC - (y - lbl_80543CC8))) / lbl_80543CC4;
    }
    return ret;
}

extern "C" f32 fn_8043D57C(u8* param_1) {
    f32 ret = lbl_80543C88;
    if (param_1[0x10b] != 0 && param_1[0x10c] == 0) {
        J2DPane* pane = *(J2DPane**)(*(u8**)(param_1 + 0x40) + 4);
        f32 dy = pane->getBounds()->i.y - *(f32*)(*(u8**)(param_1 + 0x40) + 0xc);
        ret = (-66.0f * (100.0f - dy)) / 100.0f;
    }
    return ret;
}

extern void* lbl_8053AB10;
extern "C" void fn_8013B490(void* p);
extern "C" void fn_8043D5F0(u8* param_1) {
    fn_8013B490(lbl_8053AB10);
    *(u8*)(*(u8**)(param_1 + 4) + 0x100) = 1;
    (*(J2DScreen**)(param_1 + 4))->draw(lbl_80543C88, lbl_80543C88, *(J2DGrafContext**)((u8*)lbl_8053AB10 + 0x10));
}

struct Fn8043D644_Obj;
typedef void (Fn8043D644_Obj::*Fn8043D644_Fn)();
extern "C" Fn8043D644_Fn lbl_804B18D0[];
extern "C" void fn_8043D644(Fn8043D644_Obj* self) {
    u8 idx = *(u8*)((u8*)self + 0x10b);
    (self->*lbl_804B18D0[idx])();
}

extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D46D8(void* mgr, u32 a, u32 id, u32 b);
extern "C" void fn_80383E2C(u32 id, char* buf);
extern "C" void fn_80458880(void* p, u32 a, s32 b);
extern void* lbl_8053AF80;
static inline bool tu8043_isFlagSet(u8 flags, u8 bit) {
    return flags & bit;
}
extern "C" s32 fn_8043D67C(u8* param_1, u32 param_2, u32 param_3, u32 param_4) {
    char name[8];
    if (param_1[0x10a] != 0) {
        return 0;
    }
    if (param_2 == 0x199) {
        if (fn_802D46D8(fn_802D6A9C(), 0, param_2, 0) == 1) {
            return 0;
        }
        fn_802D46D8(fn_802D6A9C(), 0, param_2, 1);
    } else if (param_2 == 0x1b5) {
        u8 flags = param_1[0xde];
        u8 bit = 1 << param_3;
        if (tu8043_isFlagSet(flags, bit) & 1) {
            return 0;
        }
        param_1[0xde] = flags | bit;
    }
    fn_80383E2C(param_2, name);
    if (name[0] == '*') {
        if (fn_802D46D8(fn_802D6A9C(), 0, param_2, 0) == 1) {
            return 0;
        }
        fn_802D46D8(fn_802D6A9C(), 0, param_2, 1);
    }
    param_1[0x10a] = 1;
    *(u32*)(param_1 + 0xfc) = param_3 + 1;
    *(u32*)(param_1 + 0xe8) = param_2;
    *(u32*)(param_1 + 0x100) = param_4;
    switch (param_2) {
    case 0x18f:
    case 0x190:
    case 0x195:
    case 0x196:
    case 0x197:
    case 0x198:
    case 0x1a8:
        fn_80458880(lbl_8053AF80, 0x40, -1);
        break;
    case 0x23f:
        break;
    default:
        fn_80458880(lbl_8053AF80, 0x39, -1);
        break;
    }
    return 1;
}

extern "C" void fn_8043D834(u8* self) {
    if (((u8*)lbl_8053AAF8)[0x7f] != 0) {
        fn_8041E58C(*(void**)(self + 0x290));
    } else {
        fn_80425128(*(void**)(self + 0x294));
    }
}

extern "C" void fn_8043D874(u8* param_1, s32 i, s32 val, u8 flag) {
    u8* game = (u8*)lbl_8053AAF8;
    if (game[0x7f] != 0) {
        fn_8041E708(*(void**)(param_1 + 0x290), i, val, flag);
    } else {
        fn_80425234(*(void**)(param_1 + 0x294), i, val, flag);
    }
}

extern "C" s32 fn_8022EA0C(s32 i);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 i);
extern "C" s32 fn_80237810(s32 i);
extern "C" s32 fn_802373EC(s32 i);
extern "C" u8 fn_8023F264(s32 i);
extern "C" void fn_804408F0(JGeometry::TVec3<f32>* v);
extern "C" u8 fn_8037E4BC(void);
extern "C" void fn_804257E4(void* p);
extern "C" void fn_8041EDB0(void* p);
extern "C" void fn_8044998C(void* p);
extern "C" void fn_804455E0(void* p);
extern "C" void fn_80447FAC(void* p);
extern "C" void fn_8044A828(void* p);
extern "C" void fn_80448940(void* p);
extern "C" void fn_80447618(void* p);
extern "C" void fn_804465B8(void* p);
extern "C" void fn_8044C038(void* p);
extern "C" void fn_80443638(void* p);
extern "C" void reset__7RupyNumFv(void* p);
#pragma opt_common_subs off
extern "C" void fn_8043D8B4(u8* self) {
    s32 i;
    s32* p;
    s32 k;
    if (((u8*)lbl_8053AAF8)[0x7e] == 0) {
        i = 0;
        p = (s32*)lbl_80529DEC;
        do {
            if (((u8*)lbl_8053AAF8)[0x82] & (u8)(1 << i)) {
                k = fn_8022EA0C(i);
                if (fn_8023DE58(k) < 8) {
                    JGeometry::TVec3<f32> tmp = *fn_8023E724(k);
                    fn_804408F0(&tmp);
                }
                p[50] = fn_80237810(i);
                p[62] = fn_802373EC(i);
            }
            i++;
            p++;
        } while (i < 4);
    } else {
        k = 0;
        p = (s32*)lbl_80529DEC;
        do {
            if (fn_8023F264(k) && fn_8023DE58(k) < 8) {
                JGeometry::TVec3<f32> tmp = *fn_8023E724(k);
                fn_804408F0(&tmp);
            }
            if (((u8*)lbl_8053AAF8)[0x82] & (u8)(1 << k)) {
                p[50] = fn_80237810(k);
                p[62] = fn_802373EC(k);
            }
            k++;
            p++;
        } while (k < 4);
    }
    if (((u8*)lbl_8053AAF8)[0x7e] != 0 && fn_8037E4BC()) {
        ((u8*)lbl_8053AED0)[0xdc] |= 4;
        ((u8*)lbl_8053AED0)[0xdc] |= 8;
    }
    if (((u8*)lbl_8053AAF8)[0x7f] != 0) {
        fn_8041EDB0(*(void**)(self + 0x290));
        if (*(void**)(self + 0x2b0) != 0) fn_8044998C(*(void**)(self + 0x2b0));
        if (*(void**)(self + 0x29c) != 0) fn_804455E0(*(void**)(self + 0x29c));
        if (*(void**)(self + 0x2a8) != 0) fn_80447FAC(*(void**)(self + 0x2a8));
        if (*(void**)(self + 0x2b4) != 0) fn_8044A828(*(void**)(self + 0x2b4));
        if (*(void**)(self + 0x2ac) != 0) fn_80448940(*(void**)(self + 0x2ac));
        if (*(void**)(self + 0x2a4) != 0) fn_80447618(*(void**)(self + 0x2a4));
        if (*(void**)(self + 0x2a0) != 0) fn_804465B8(*(void**)(self + 0x2a0));
        if (*(void**)(self + 0x2b8) != 0) fn_8044C038(*(void**)(self + 0x2b8));
    } else {
        fn_804257E4(*(void**)(self + 0x294));
    }
    if (*(void**)(self + 0x2bc) != 0) reset__7RupyNumFv(*(void**)(self + 0x2bc));
    self[0x255] = 0;
    if (*(void**)(self + 0x298) != 0) fn_80443638((void*)lbl_8053AEF0);
    if (((u8*)lbl_8053AAF8)[0x85] != 0) {
        self[0x257] = 1;
    } else {
        self[0x257] = 0;
    }
}
#pragma opt_common_subs reset
extern "C" void fn_8043DB58(u8* param_1) {
	struct VObj {
		virtual void v00();
		virtual void v01();
		virtual void v02();
		virtual void v03();
		virtual void v04();
		virtual void v05();
		virtual void v06();
		virtual void v07();
		virtual void v08();
		virtual void v09();
		virtual void v10();
		virtual void v11();
		virtual void v12();
		virtual void v13();
		virtual void v14();
		virtual void v15();
		virtual void v16();
		virtual void v17();
		virtual void v18();
		virtual void v19();
		virtual void v20();
		virtual void v21();
		virtual void v22();
		virtual void v23();
		virtual void v24();
		virtual void v25();
		virtual void v26();
		virtual void v27();
		virtual void v28();
		virtual void v29();
		virtual void v30();
		virtual void v31();
		virtual void v32();
		virtual void v33();
		virtual void v34();
		virtual void v35();
		virtual void v36();
		virtual void v37();
		virtual void v38();
		virtual void v39();
		virtual void v40();
		virtual void v41();
		virtual void v42();
		virtual void v43();
		virtual void v44();
		virtual void v45();
		virtual void v46();
		virtual void v47();
		virtual void v48();
		virtual void v49();
		virtual void v50();
		virtual void v51();
		virtual void v52();
		virtual void v53();
		virtual void v54();
		virtual void v55(s32 a, f32 b, s32 c, f32 d, s32 e);
	};
	fn_8013B490(lbl_8053AB10);
	if (param_1[0x256] != 0xff) {
		switch (param_1[0x256]) {
		case 0:
			((VObj*)*(void**)(param_1 + 0x14))->v55(0, lbl_80543CF0, 0, lbl_80543CF4, 0);
			break;
		case 1:
			((VObj*)*(void**)(param_1 + 0x18))->v55(0, lbl_80543CF0, 0, lbl_80543CF4, 0);
			break;
		case 2:
			((VObj*)*(void**)(param_1 + 0x1c))->v55(0, lbl_80543CF0, 0, lbl_80543CF4, 0);
			break;
		case 3:
			((VObj*)*(void**)(param_1 + 0x20))->v55(0, lbl_80543CF0, 0, lbl_80543CF4, 0);
			break;
		case 4:
			((VObj*)*(void**)(param_1 + 0x24))->v55(0, lbl_80543CF0, 0, lbl_80543CF4, 0);
			break;
		}
	}
}

extern u8 lbl_8050DB0C[];
extern "C" void fn_8041F720(void* p);
extern "C" void fn_8044A024(void* p);
extern "C" void fn_80445CDC(void* p);
extern "C" void fn_804482EC(void* p);
extern "C" void fn_8044AF90(void* p);
extern "C" void fn_80449070(void* p);
extern "C" void fn_80447958(void* p);
extern "C" void fn_80446D68(void* p);
extern "C" void fn_8044C14C(void* p);
extern "C" void fn_80425F6C(void* p);
extern "C" void fn_8043BB84(u8* p);
extern "C" void fn_8043ACE4(u8* p);
extern "C" void fn_8043A638(u8* p);
extern "C" void fn_804435E4(void* p);
extern "C" void draw__7RupyNumFv(void* p);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void* screen, f32 x, f32 y, void* ctx);
extern const f64 lbl_80543C98;
#pragma inline_depth(0)
extern "C" void fn_8043DC98(u8* param_1) {
    struct VObj {
        virtual void v00();
        virtual void v01();
        virtual void v02();
        virtual void v03();
        virtual void v04();
        virtual void v05();
        virtual void v06();
        virtual void v07();
        virtual void v08();
        virtual void v09();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual void v21();
        virtual void v22();
        virtual void v23();
        virtual void v24();
        virtual void v25();
        virtual void v26();
        virtual void v27();
        virtual void v28();
        virtual void v29();
        virtual void v30();
        virtual void v31();
        virtual void v32();
        virtual void v33();
        virtual void v34();
        virtual void v35();
        virtual void v36();
        virtual void v37();
        virtual void v38();
        virtual void v39();
        virtual void v40();
        virtual void v41();
        virtual void v42();
        virtual void v43();
        virtual void v44();
        virtual void v45();
        virtual void v46();
        virtual void v47();
        virtual void v48();
        virtual void v49();
        virtual void v50();
        virtual void v51();
        virtual void v52();
        virtual void v53();
        virtual void v54();
        virtual void v55();
        virtual void v56();
        virtual void v57(s32, f32, s32, f32, s32, f32, f32);
    };
    typedef void* (*VFn15)(void*, u32, u32, u32);
    typedef void (*VFn4)(void*, f32, f32);
    u8* game = (u8*)lbl_8053AAF8;
    if (game[0x7f] != 0) {
        fn_8041F720(*(void**)(param_1 + 0x290));
        if (*(void**)(param_1 + 0x2b0) != NULL) {
            fn_8044A024(*(void**)(param_1 + 0x2b0));
        }
        if (*(void**)(param_1 + 0x29c) != NULL) {
            fn_80445CDC(*(void**)(param_1 + 0x29c));
        }
        if (*(void**)(param_1 + 0x2a8) != NULL) {
            fn_804482EC(*(void**)(param_1 + 0x2a8));
        }
        if (*(void**)(param_1 + 0x2b4) != NULL) {
            fn_8044AF90(*(void**)(param_1 + 0x2b4));
        }
        if (*(void**)(param_1 + 0x2ac) != NULL) {
            fn_80449070(*(void**)(param_1 + 0x2ac));
        }
        if (*(void**)(param_1 + 0x2a4) != NULL) {
            fn_80447958(*(void**)(param_1 + 0x2a4));
        }
        if (*(void**)(param_1 + 0x2a0) != NULL) {
            fn_80446D68(*(void**)(param_1 + 0x2a0));
        }
        if (*(void**)(param_1 + 0x2b8) != NULL) {
            fn_8044C14C(*(void**)(param_1 + 0x2b8));
        }
    } else {
        fn_80425F6C(*(void**)(param_1 + 0x294));
    }
    if (*(void**)(param_1 + 0x2bc) != NULL) {
        draw__7RupyNumFv(*(void**)(param_1 + 0x2bc));
    }
    ((u8*)lbl_8053AED0)[0xdc] &= ~0x01;
    ((u8*)lbl_8053AED0)[0xdc] &= ~0x02;
    ((u8*)lbl_8053AED0)[0xdc] &= ~0x04;
    ((u8*)lbl_8053AED0)[0xdc] &= ~0x08;
    ((u8*)lbl_8053AED0)[0xdc] &= ~0x01;
    ((u8*)lbl_8053AED0)[0xdc] &= ~0x02;
    ((u8*)lbl_8053AED0)[0xdc] &= ~0x04;
    ((u8*)lbl_8053AED0)[0xdc] &= ~0x08;
    fn_8013B490(lbl_8053AB10);
    fn_8043BB84(param_1);
    fn_8043ACE4(param_1);
    fn_8043A638(param_1);
    if (*(void**)(param_1 + 0x10) != NULL && *(u8*)(param_1 + 0x254) != 0) {
        ((VObj*)*(void**)(param_1 + 0x10))->v57(0, *(f32*)(param_1 + 0x1c0), 0, *(f32*)(param_1 + 0x1c4), 0, *(f32*)(param_1 + 0x1c8), *(f32*)(param_1 + 0x1cc));
        *(u8*)(param_1 + 0x254) = 0;
    }
    if (*(u32*)(param_1 + 0x298) != 0) {
        fn_804435E4((void*)lbl_8053AEF0);
    }
    if (*(u8*)(param_1 + 0x257) != 0) {
        fn_8013B490(lbl_8053AB10);
        J2DPane* pane = (*(J2DScreen**)(param_1 + 0xc))->search(0x004E646174613035ULL);
        pane->move(*(f32*)(param_1 + 0x110) + (f32)*(s16*)(lbl_8050DB0C + 0x2a2), *(f32*)(param_1 + 0x114) + (f32)*(s16*)(lbl_8050DB0C + 0x2a4));
        draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(param_1 + 0xc), lbl_80543C88, lbl_80543C88, *(void**)((u8*)lbl_8053AB10 + 0x10));
    }
}
#pragma inline_depth(8)
extern "C" u8 fn_8043DF24(f32 x, f32 y, f32 px, f32 py, f32 r) {
    f32 a = 94.0f;
    f32 b = 61.5f;
    f32 dx = x - a;
    f32 dy = y - b;
    f32 sx = a + x;
    f32 left = dx - r;
    f32 sy = b + y;
    f32 bottom = dy - r;
    f32 right = r + sx;
    f32 top = r + sy;
    if (px >= left && px <= right && py >= bottom && py <= top) {
        return 0;
    }
    return 1;
}

static inline bool fn_8043DF8C_hit(f32 x, f32 y, f32 px, f32 py, f32 r) {
    f32 a = 94.0f;
    f32 b = 61.5f;
    f32 left = x - a - r;
    f32 bottom = y - b - r;
    f32 right = a + x + r;
    f32 top = b + y + r;
    if (px >= left && px <= right && py >= bottom && py <= top) {
        return false;
    }
    return true;
}

extern "C" void fn_8043DF8C(void* p, f32 x, f32 y) {
    JGeometry::TVec3<f32> out1;
    JGeometry::TVec3<f32> out2;
    JGeometry::TVec3<f32> in1(0.0f, 0.0f, 0.0f);
    fn_8030C5F0(*(void**)((u8*)lbl_8053AB10 + 0x24), &in1, 0, 0, &out1);
    JGeometry::TVec3<f32> in2(lbl_80543CC0, 0.0f, 0.0f);
    fn_8030C5F0(*(void**)((u8*)lbl_8053AB10 + 0x24), &in2, 0, 0, &out2);
    f32 r = out2.x - out1.x;
    if (!fn_8043DF8C_hit(93.0f, 61.5f + fn_8043D514((u8*)lbl_8053AED0), x, y, r)) {
        *((u8*)lbl_8053AED0 + 0xdc) |= 1;
    }
    if (!fn_8043DF8C_hit(514.0f, 61.5f + fn_8043D514((u8*)lbl_8053AED0), x, y, r)) {
        *((u8*)lbl_8053AED0 + 0xdc) |= 2;
    }
    if (!fn_8043DF8C_hit(93.0f, 407.5f + fn_8043D57C((u8*)lbl_8053AED0), x, y, r)) {
        *((u8*)lbl_8053AED0 + 0xdc) |= 4;
    }
    if (!fn_8043DF8C_hit(514.0f, 407.5f + fn_8043D57C((u8*)lbl_8053AED0), x, y, r)) {
        *((u8*)lbl_8053AED0 + 0xdc) |= 8;
    }
}

extern "C" void fn_8043E398(void* self, void* a, void* b)
{
    Vec pa, pb;
    fn_8030C5F0(*(void**)((u8*)lbl_8053AB10 + 0x24), a, 0, 0, &pa);
    fn_8030C5F0(*(void**)((u8*)lbl_8053AB10 + 0x24), b, 0, 0, &pb);
    f32 r = maxMenuExtent(__fabs(pb.x - pa.x), __fabs(pb.y - pa.y));
    f32 move1, move2;
    f32 left1;
    f32 left2;
    f32 x = lbl_80543CB8 * (pa.x + pb.x);
    f32 y = lbl_80543CB8 * (pa.y + pb.y);
    f32 right1;
    f32 y1;
    move1 = lbl_80543C88;
    {
        u8* game = (u8*)lbl_8053AED0;
        if (game[0x10b] != 0 && game[0x10c] == 1) {
            J2DPane* pane = *(J2DPane**)(*(u8**)(game + 0x64) + 4);
            f32 paneY = pane->getBounds()->i.y;
            move1 = (lbl_80543CE8 * (lbl_80543CEC - (paneY - lbl_80543CC8))) / lbl_80543CC4;
        }
    }
    y1 = lbl_80543CF8 + move1;
    left1 = lbl_80543D04 - r;
    right1 = r + lbl_80543D00;
    f32 low = (y1 - lbl_80543CF8) - r;
    f32 high = r + (lbl_80543CF8 + y1);
    s32 outside;
    if (x >= left1 && x <= right1 && y >= low && y <= high) outside = 0; else outside = 1;
    if ((u8)outside == 0) ((u8*)lbl_8053AED0)[0xdc] |= 1;
    {
    f32 right2;
    f32 y2;
    move2 = lbl_80543C88;
    {
        u8* game = (u8*)lbl_8053AED0;
        if (game[0x10b] != 0 && game[0x10c] == 1) {
            J2DPane* pane = *(J2DPane**)(*(u8**)(game + 0x64) + 4);
            f32 paneY = pane->getBounds()->i.y;
            move2 = (lbl_80543CE8 * (lbl_80543CEC - (paneY - lbl_80543CC8))) / lbl_80543CC4;
        }
    }
    y2 = lbl_80543CF8 + move2;
    left2 = lbl_80543D0C - r;
    right2 = r + lbl_80543D08;
    low = (y2 - lbl_80543CF8) - r;
    high = r + (lbl_80543CF8 + y2);
    if (x >= left2 && x <= right2 && y >= low && y <= high) outside = 0; else outside = 1;
    if ((u8)outside == 0) ((u8*)lbl_8053AED0)[0xdc] |= 2;
    }
    {
    f32 right3;
    f32 y3;
    f32 move3 = fn_8043D57C((u8*)lbl_8053AED0);
    y3 = lbl_80543D10 + move3;
    right3 = r + lbl_80543D00;
    low = (y3 - lbl_80543CF8) - r;
    high = r + (lbl_80543CF8 + y3);
    if (x >= left1 && x <= right3 && y >= low && y <= high) outside = 0; else outside = 1;
    if ((u8)outside == 0) ((u8*)lbl_8053AED0)[0xdc] |= 4;
    }
    {
    f32 right4;
    f32 y4;
    f32 move4 = fn_8043D57C((u8*)lbl_8053AED0);
    y4 = lbl_80543D10 + move4;
    right4 = r + lbl_80543D08;
    low = (y4 - lbl_80543CF8) - r;
    high = r + (lbl_80543CF8 + y4);
    if (x >= left2 && x <= right4 && y >= low && y <= high) outside = 0; else outside = 1;
    if ((u8)outside == 0) ((u8*)lbl_8053AED0)[0xdc] |= 8;
    }
}

extern "C" void* fn_80440928(f32 a, f32 b);
#pragma dont_inline on
extern "C" void fn_8043E7CC(void* a, void* b) {
    f32 pos[6];
    fn_8030C5F0(*(void**)((u8*)lbl_8053AB10 + 0x24), b, 0, 0, pos);
    fn_80440928(pos[0], pos[1]);
}
#pragma dont_inline reset

extern const f32 lbl_80543CB8;
extern const f32 lbl_80543D14;
extern const f32 lbl_80543D18;
extern const f32 lbl_80543D1C;
extern const f32 lbl_80543D20;
extern const f32 lbl_80543D24;
extern "C" void fn_8043E80C(u8* param_1, s32 param_2, u8 param_3, u32 param_4, u32 param_5, f32 param_6, f32 param_7, f32 param_8) {
    f32 x;
    f32 y;
    f32 sx;
    f32 sy;
    if ((lbl_80543CD4 == param_8) | (lbl_80543CE0 == param_8) | (lbl_80543CE4 == param_8)) {
        sx = lbl_80543D14;
        sy = sx;
    } else if (param_8 > lbl_80543CCC) {
        f32 t = lbl_80543D18 * param_8;
        sx = t;
        sy = t;
    } else if (lbl_80543CCC == param_8) {
        sx = lbl_80543D1C;
        sy = sx;
    } else {
        sx = lbl_80543D20;
        sy = sx;
    }
    x = (lbl_80543D24 + param_6) - sx * lbl_80543CB8;
    y = (lbl_80543D24 + param_7) - sy * lbl_80543CB8;
    switch ((u32)param_2) {
    case 0:
        (*(J2DPicture**)(param_1 + 0x258))->setBlackWhite(JUtility::TColor(param_4), JUtility::TColor(param_5));
        (*(J2DPicture**)(param_1 + 0x258))->setAlpha(param_3);
        (*(J2DPicture**)(param_1 + 0x258))->draw(x, y, sx, sy, false, false, false);
        break;
    case 1:
        (*(J2DPicture**)(param_1 + 0x25c))->setBlackWhite(JUtility::TColor(param_4), JUtility::TColor(param_5));
        (*(J2DPicture**)(param_1 + 0x25c))->setAlpha(param_3);
        (*(J2DPicture**)(param_1 + 0x25c))->draw(x, y, sx, sy, false, false, false);
        break;
    case 2:
        (*(J2DPicture**)(param_1 + 0x260))->setBlackWhite(JUtility::TColor(param_4), JUtility::TColor(param_5));
        (*(J2DPicture**)(param_1 + 0x260))->setAlpha(param_3);
        (*(J2DPicture**)(param_1 + 0x260))->draw(x, y, sx, sy, false, false, false);
        break;
    case 3:
        (*(J2DPicture**)(param_1 + 0x264))->setBlackWhite(JUtility::TColor(param_4), JUtility::TColor(param_5));
        (*(J2DPicture**)(param_1 + 0x264))->setAlpha(param_3);
        (*(J2DPicture**)(param_1 + 0x264))->draw(x, y, sx, sy, false, false, false);
        break;
    case 4:
        (*(J2DPicture**)(param_1 + 0x268))->setBlackWhite(JUtility::TColor(param_4), JUtility::TColor(param_5));
        (*(J2DPicture**)(param_1 + 0x268))->setAlpha(param_3);
        (*(J2DPicture**)(param_1 + 0x268))->draw(x, y, sx, sy, false, false, false);
        break;
    case 5:
        (*(J2DPicture**)(param_1 + 0x26c))->setBlackWhite(JUtility::TColor(param_4), JUtility::TColor(param_5));
        (*(J2DPicture**)(param_1 + 0x26c))->setAlpha(param_3);
        (*(J2DPicture**)(param_1 + 0x26c))->draw(x, y, sx, sy, false, false, false);
        break;
    case 6:
        (*(J2DPicture**)(param_1 + 0x270))->setBlackWhite(JUtility::TColor(param_4), JUtility::TColor(param_5));
        (*(J2DPicture**)(param_1 + 0x270))->setAlpha(param_3);
        (*(J2DPicture**)(param_1 + 0x270))->draw(x, y, sx, sy, false, false, false);
        break;
    case 7:
        (*(J2DPicture**)(param_1 + 0x274))->setBlackWhite(JUtility::TColor(param_4), JUtility::TColor(param_5));
        (*(J2DPicture**)(param_1 + 0x274))->setAlpha(param_3);
        (*(J2DPicture**)(param_1 + 0x274))->draw(x, y, sx, sy, false, false, false);
        break;
    case 8:
        (*(J2DPicture**)(param_1 + 0x278))->setBlackWhite(JUtility::TColor(param_4), JUtility::TColor(param_5));
        (*(J2DPicture**)(param_1 + 0x278))->setAlpha(param_3);
        (*(J2DPicture**)(param_1 + 0x278))->draw(x, y, sx, sy, false, false, false);
        break;
    case 9:
        (*(J2DPicture**)(param_1 + 0x27c))->setBlackWhite(JUtility::TColor(param_4), JUtility::TColor(param_5));
        (*(J2DPicture**)(param_1 + 0x27c))->setAlpha(param_3);
        (*(J2DPicture**)(param_1 + 0x27c))->draw(x, y, sx, sy, false, false, false);
        break;
    }
}

extern "C" void fn_8043EDE8(char* param_1, s32 param_2) {
    *(s32*)(param_1 + 0xe0) = param_2;
    *(s32*)(param_1 + 0xe4) = 0x1e;
}

extern "C" void fn_8043EDF8(u8* param_1) {
    param_1[0xdd] = 0;
    param_1[0xdc] = 0;
    param_1[0x255] = 0;
    if (((u8*)lbl_8053AAF8)[0x7f] != 0) {
        fn_8041FC2C(*(void**)(param_1 + 0x290));
        if (*(u32*)(param_1 + 0x2b0) != 0) {
            fn_8044A06C(*(void**)(param_1 + 0x2b0));
        }
        if (*(u32*)(param_1 + 0x29c) != 0) {
            fn_80445D24(*(void**)(param_1 + 0x29c));
        }
        if (*(u32*)(param_1 + 0x2a8) != 0) {
            fn_80448334(*(void**)(param_1 + 0x2a8));
        }
        if (*(u32*)(param_1 + 0x2b4) != 0) {
            fn_8044AFD8(*(void**)(param_1 + 0x2b4));
        }
        if (*(u32*)(param_1 + 0x2ac) != 0) {
            fn_804490B8(*(void**)(param_1 + 0x2ac));
        }
        if (*(u32*)(param_1 + 0x2a4) != 0) {
            fn_804479A0(*(void**)(param_1 + 0x2a4));
        }
        if (*(u32*)(param_1 + 0x2a0) != 0) {
            fn_80446DB0(*(void**)(param_1 + 0x2a0));
        }
    } else {
        fn_804263A8(*(void**)(param_1 + 0x294));
    }
    if (*(u32*)(param_1 + 0x298) != 0) {
        fn_80443688(lbl_8053AEF0);
    }
}

extern "C" void* fn_8043EED8(u8* this_, s16 how) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B1920;
        Fn8043EED8_Obj* o;
        o = *(Fn8043EED8_Obj**)(this_ + 0x290);
        if (o) { if (o) o->v02(1);
            *(void**)(this_ + 0x290) = 0;
        }
        o = *(Fn8043EED8_Obj**)(this_ + 0x294);
        if (o) { if (o) o->v02(1);
            *(void**)(this_ + 0x294) = 0;
        }
        o = *(Fn8043EED8_Obj**)(this_ + 0x298);
        if (o) { if (o) o->v02(1);
            *(void**)(this_ + 0x298) = 0;
        }
        o = *(Fn8043EED8_Obj**)(this_ + 0x2b8);
        if (o) { if (o) o->v02(1);
            *(void**)(this_ + 0x2b8) = 0;
        }
        o = *(Fn8043EED8_Obj**)(this_ + 0x2b0);
        if (o) { if (o) o->v02(1);
            *(void**)(this_ + 0x2b0) = 0;
        }
        o = *(Fn8043EED8_Obj**)(this_ + 0x29c);
        if (o) { if (o) o->v02(1);
            *(void**)(this_ + 0x29c) = 0;
        }
        o = *(Fn8043EED8_Obj**)(this_ + 0x2a8);
        if (o) { if (o) o->v02(1);
            *(void**)(this_ + 0x2a8) = 0;
        }
        o = *(Fn8043EED8_Obj**)(this_ + 0x2b4);
        if (o) { if (o) o->v02(1);
            *(void**)(this_ + 0x2b4) = 0;
        }
        o = *(Fn8043EED8_Obj**)(this_ + 0x2ac);
        if (o) { if (o) o->v02(1);
            *(void**)(this_ + 0x2ac) = 0;
        }
        o = *(Fn8043EED8_Obj**)(this_ + 0x2a4);
        if (o) { if (o) o->v02(1);
            *(void**)(this_ + 0x2a4) = 0;
        }
        o = *(Fn8043EED8_Obj**)(this_ + 0x2a0);
        if (o) { if (o) o->v02(1);
            *(void**)(this_ + 0x2a0) = 0;
        }
        o = *(Fn8043EED8_Obj**)(this_ + 0x2bc);
        if (o) { if (o) o->v02(1);
            *(void**)(this_ + 0x2bc) = 0;
        }
        o = *(Fn8043EED8_Obj**)(this_ + 0x4);
        if (o) o->v02(1);
        *(void**)(this_ + 0x4) = 0;
        o = *(Fn8043EED8_Obj**)(this_ + 0x8);
        if (o) o->v02(1);
        *(void**)(this_ + 0x8) = 0;
        o = *(Fn8043EED8_Obj**)(this_ + 0xc);
        if (o) o->v02(1);
        *(void**)(this_ + 0xc) = 0;
        for (s32 i = 0; i < 12; i++) {
            o = *(Fn8043EED8_Obj**)(this_ + 0x40 + i * 4);
            if (o) o->v02(1);
            *(void**)(this_ + 0x40 + i * 4) = 0;
        }
        o = *(Fn8043EED8_Obj**)(this_ + 0x70);
        if (o) o->v02(1);
        *(void**)(this_ + 0x70) = 0;
        o = *(Fn8043EED8_Obj**)(this_ + 0x74);
        if (o) o->v02(1);
        *(void**)(this_ + 0x74) = 0;
        o = *(Fn8043EED8_Obj**)(this_ + 0x258);
        if (o) o->v02(1);
        *(void**)(this_ + 0x258) = 0;
        o = *(Fn8043EED8_Obj**)(this_ + 0x25c);
        if (o) o->v02(1);
        *(void**)(this_ + 0x25c) = 0;
        o = *(Fn8043EED8_Obj**)(this_ + 0x260);
        if (o) o->v02(1);
        *(void**)(this_ + 0x260) = 0;
        o = *(Fn8043EED8_Obj**)(this_ + 0x264);
        if (o) o->v02(1);
        *(void**)(this_ + 0x264) = 0;
        o = *(Fn8043EED8_Obj**)(this_ + 0x268);
        if (o) o->v02(1);
        *(void**)(this_ + 0x268) = 0;
        o = *(Fn8043EED8_Obj**)(this_ + 0x26c);
        if (o) o->v02(1);
        *(void**)(this_ + 0x26c) = 0;
        o = *(Fn8043EED8_Obj**)(this_ + 0x270);
        if (o) o->v02(1);
        *(void**)(this_ + 0x270) = 0;
        o = *(Fn8043EED8_Obj**)(this_ + 0x274);
        if (o) o->v02(1);
        *(void**)(this_ + 0x274) = 0;
        o = *(Fn8043EED8_Obj**)(this_ + 0x278);
        if (o) o->v02(1);
        *(void**)(this_ + 0x278) = 0;
        o = *(Fn8043EED8_Obj**)(this_ + 0x27c);
        if (o) o->v02(1);
        *(void**)(this_ + 0x27c) = 0;
        o = *(Fn8043EED8_Obj**)(this_ + 0x280);
        if (o) o->v02(1);
        *(void**)(this_ + 0x280) = 0;
        o = *(Fn8043EED8_Obj**)(this_ + 0x284);
        if (o) o->v02(1);
        *(void**)(this_ + 0x284) = 0;
        o = *(Fn8043EED8_Obj**)(this_ + 0x288);
        if (o) o->v02(1);
        *(void**)(this_ + 0x288) = 0;
        o = *(Fn8043EED8_Obj**)(this_ + 0x28c);
        if (o) o->v02(1);
        *(void**)(this_ + 0x28c) = 0;
        for (s32 i = 0; i < 4; i++) {
            o = *(Fn8043EED8_Obj**)(this_ + 0x14 + i * 4);
            if (o) o->v02(1);
            *(void**)(this_ + 0x14 + i * 4) = 0;
        }
        o = *(Fn8043EED8_Obj**)(this_ + 0x24);
        if (o) o->v02(1);
        *(void**)(this_ + 0x24) = 0;
        o = *(Fn8043EED8_Obj**)(this_ + 0x10);
        if (o) { if (o) o->v02(1);
            *(void**)(this_ + 0x10) = 0;
        }
        lbl_8053AED0 = 0;
        if (how > 0) {
            delete this_;
        }
    }
    return this_;
}

extern "C" void* __nw__FUl(u32 size);
extern "C" void fn_80420574(void* p);
extern "C" void fn_80426DEC(void* p);
extern "C" void fn_80443760(void* p);
extern "C" void fn_8044C260(void* p);
extern "C" void fn_8044A4D4(void* p);
extern "C" void fn_804461D0(void* p);
extern "C" void fn_804485C4(void* p);
extern "C" void fn_80447C30(void* p);
extern "C" void fn_8044728C(void* p);
extern "C" void fn_8044B4B8(void* p);
extern "C" void fn_804495B8(void* p);
extern "C" void __ct__7RupyNumFv(void* p);
extern "C" void __ct__9J2DScreenFv(void* p);
extern "C" void setPriority__9J2DScreenFPCcUlP10JKRArchive(void* self, const char* name, u32 flags, void* archive);
extern "C" void fn_80402F04(void* a, void* b);
extern "C" u8 lbl_80529DEC[];
extern "C" u8 lbl_8048F710[];
extern "C" void* lbl_8053AED0;
extern "C" char* lbl_8053AAF8;
extern u8* lbl_8053AD78;
extern u8 lbl_804AF86C[];
extern const f32 lbl_80543D28;
#pragma opt_propagation reset
static inline void menuInitCorner(J2DPicture* picture, const u32 corner, const JUtility::TColor color) {
    picture->mCornerColors[corner].setRGBA(color);
}
#pragma opt_strength_reduction off
extern "C" void* fn_8043F504(u8* self) {
    const char* names = (const char*)lbl_8048F710;
    const ResTIMG* image;
    s32 i;
    u8* p;
    J2DPicture* picture;
    *(u8**)self = lbl_804B1920;
    lbl_8053AED0 = self;
    lbl_80529DEC[0x24a] = 0;
    self[0xdd] = 0;
    self[0xdc] = 0;
    self[0x10e] = 0;
    self[0xde] = 0;
    self[0x255] = 0;
    self[0x257] = 0;
    *(u32*)(self + 0x290) = 0;
    *(u32*)(self + 0x294) = 0;
    *(u32*)(self + 0x298) = 0;
    *(u32*)(self + 0x29c) = 0;
    *(u32*)(self + 0x2a0) = 0;
    *(u32*)(self + 0x2a4) = 0;
    *(u32*)(self + 0x2a8) = 0;
    *(u32*)(self + 0x2ac) = 0;
    *(u32*)(self + 0x2b0) = 0;
    *(u32*)(self + 0x2b4) = 0;
    *(u32*)(self + 0x2b8) = 0;
    *(u32*)(self + 0x2bc) = 0;
    if (((u8*)lbl_8053AAF8)[0x7f] != 0) {
        p = (u8*)__nw__FUl(0x29c);
        if (p != NULL) {
            fn_80420574(p);
        }
        *(u8**)(self + 0x290) = p;
        if (*(s32*)(lbl_80529DEC + 0x118) == 9 && *(s32*)(lbl_80529DEC + 0x11c) == 3) {
            p = (u8*)__nw__FUl(0x18);
            if (p != NULL) {
                fn_80443760(p);
            }
            *(u8**)(self + 0x298) = p;
        }
        if (*(s32*)(lbl_80529DEC + 0x118) == 8 && *(s32*)(lbl_80529DEC + 0x11c) == 3) {
            p = (u8*)__nw__FUl(0x1c);
            if (p != NULL) {
                fn_8044C260(p);
            }
            *(u8**)(self + 0x2b8) = p;
        }
        if (*(s32*)(lbl_80529DEC + 0x118) == 4 && *(s32*)(lbl_80529DEC + 0x11c) == 1) {
            p = (u8*)__nw__FUl(0x14);
            if (p != NULL) {
                fn_8044A4D4(p);
            }
            *(u8**)(self + 0x2b0) = p;
        } else if (*(s32*)(lbl_80529DEC + 0x118) == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 2) {
            p = (u8*)__nw__FUl(0x48);
            if (p != NULL) {
                fn_804461D0(p);
            }
            *(u8**)(self + 0x29c) = p;
        } else if (*(s32*)(lbl_80529DEC + 0x118) == 1 && *(s32*)(lbl_80529DEC + 0x11c) == 1) {
            p = (u8*)__nw__FUl(0x30);
            if (p != NULL) {
                fn_804485C4(p);
            }
            *(u8**)(self + 0x2a8) = p;
        } else if (*(s32*)(lbl_80529DEC + 0x118) == 1 && *(s32*)(lbl_80529DEC + 0x11c) == 2) {
            p = (u8*)__nw__FUl(0x30);
            if (p != NULL) {
                fn_80447C30(p);
            }
            *(u8**)(self + 0x2a4) = p;
        } else if (*(s32*)(lbl_80529DEC + 0x118) == 2 && *(s32*)(lbl_80529DEC + 0x11c) == 2) {
            p = (u8*)__nw__FUl(0x34);
            if (p != NULL) {
                fn_8044728C(p);
            }
            *(u8**)(self + 0x2a0) = p;
        } else if (*(s32*)(lbl_80529DEC + 0x118) == 4 && *(s32*)(lbl_80529DEC + 0x11c) == 2) {
            p = (u8*)__nw__FUl(0x18);
            if (p != NULL) {
                fn_8044B4B8(p);
            }
            *(u8**)(self + 0x2b4) = p;
        } else if (*(s32*)(lbl_80529DEC + 0x118) == 5 && *(s32*)(lbl_80529DEC + 0x11c) == 2) {
            p = (u8*)__nw__FUl(0x34);
            if (p != NULL) {
                fn_804495B8(p);
            }
            *(u8**)(self + 0x2ac) = p;
        }
    } else {
        p = (u8*)__nw__FUl(0x264);
        if (p != NULL) {
            fn_80426DEC(p);
        }
        *(u8**)(self + 0x294) = p;
    }
    p = (u8*)__nw__FUl(0xa30);
    if (p != NULL) {
        __ct__7RupyNumFv(p);
    }
    *(u8**)(self + 0x2bc) = p;
    self[0x10a] = 0;
    *(u32*)(self + 0xfc) = 0;
    *(u32*)(self + 0xe8) = 0;
    *(u32*)(self + 0x100) = 0;
    p = (u8*)__nw__FUl(0x118);
    if (p != NULL) {
        __ct__9J2DScreenFv(p);
    }
    *(u8**)(self + 0x4) = p;
    setPriority__9J2DScreenFPCcUlP10JKRArchive(*(void**)(self + 0x4), (names + 0x230), 0x1100000, *(void**)(lbl_80529DEC + 0x20));
    p = (u8*)__nw__FUl(0x118);
    if (p != NULL) {
        __ct__9J2DScreenFv(p);
    }
    *(u8**)(self + 0x8) = p;
    setPriority__9J2DScreenFPCcUlP10JKRArchive(*(void**)(self + 0x8), (names + 0x248), 0x1100000, *(void**)(lbl_80529DEC + 0x20));
    p = (u8*)__nw__FUl(0x118);
    if (p != NULL) {
        __ct__9J2DScreenFv(p);
    }
    *(u8**)(self + 0xc) = p;
    setPriority__9J2DScreenFPCcUlP10JKRArchive(*(void**)(self + 0xc), (names + 0x25c), 0x1100000, *(void**)(lbl_80529DEC + 0x20));
    (*(J2DScreen**)(self + 0xc))->search(0x546d3032ULL)->hide();
    (*(J2DScreen**)(self + 0xc))->search(0x546d3031ULL)->hide();
    (*(J2DScreen**)(self + 0xc))->search(0x5031623032ULL)->hide();
    (*(J2DScreen**)(self + 0xc))->search(0x50316172ULL)->hide();
    (*(J2DScreen**)(self + 0xc))->search(0x5035623032ULL)->hide();
    (*(J2DScreen**)(self + 0xc))->search(0x50356172ULL)->hide();
    *(f32*)(self + 0x110) = lbl_80543D28 + (*(J2DScreen**)(self + 0xc))->search(0x4e646174613035ULL)->getBounds()->i.x;
    *(f32*)(self + 0x114) = (*(J2DScreen**)(self + 0xc))->search(0x4e646174613035ULL)->getBounds()->i.y;
    *(u16*)(self + 0x106) = 0; *(u16*)(self + 0x108) = 0;
    *(f32*)(self + 0xec) = (*(J2DScreen**)(self + 0x8))->search(0x507730313031ULL)->getBounds()->i.x;
    *(f32*)(self + 0xf0) = (*(J2DScreen**)(self + 0x8))->search(0x507730313031ULL)->getBounds()->i.y;
    *(f32*)(self + 0xf4) = lbl_80543C88; *(f32*)(self + 0xf8) = lbl_80543C88; self[0x10d] = 0;
    JUTFont* font;
    font = *(JUTFont**)(lbl_8053AD78 + 0x154);
    ((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546d6d743032ULL))->setFont(font);
    font = *(JUTFont**)(lbl_8053AD78 + 0x154);
    ((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546d6d743031ULL))->setFont(font);
    u8* slot = self;
    for (i = 0; i < 12; i++, slot += 4) {
        p = (u8*)__nw__FUl(0x2c);
        if (p) *(void**)p = lbl_804AF86C;
        *(u8**)(slot + 0x40) = p;
    }
    fn_80402F04(*(void**)(self + 0x40), (*(J2DScreen**)(self + 0x4))->search(0x506d6d776b3032ULL));
    fn_80402F04(*(void**)(self + 0x44), (*(J2DScreen**)(self + 0x4))->search(0x506d6d776b3031ULL));
    fn_80402F04(*(void**)(self + 0x48), (*(J2DScreen**)(self + 0x4))->search(0x506d6d773039ULL));
    fn_80402F04(*(void**)(self + 0x4c), (*(J2DScreen**)(self + 0x4))->search(0x506d6d773038ULL));
    fn_80402F04(*(void**)(self + 0x50), (*(J2DScreen**)(self + 0x4))->search(0x506d6d773037ULL));
    fn_80402F04(*(void**)(self + 0x54), (*(J2DScreen**)(self + 0x4))->search(0x506d6d773036ULL));
    fn_80402F04(*(void**)(self + 0x58), (*(J2DScreen**)(self + 0x4))->search(0x506d6d773035ULL));
    fn_80402F04(*(void**)(self + 0x5c), (*(J2DScreen**)(self + 0x4))->search(0x506d6d773034ULL));
    fn_80402F04(*(void**)(self + 0x60), (*(J2DScreen**)(self + 0x4))->search(0x506d6d773033ULL));
    fn_80402F04(*(void**)(self + 0x64), (*(J2DScreen**)(self + 0x4))->search(0x506d6d773032ULL));
    fn_80402F04(*(void**)(self + 0x68), (*(J2DScreen**)(self + 0x4))->search(0x506d6d773031ULL));
    fn_80402F04(*(void**)(self + 0x6c), (*(J2DScreen**)(self + 0x4))->search(0x506d6d7470ULL));
    {
        JUtility::TColor black(0u), white(0u);
        J2DPicture* pane = *(J2DPicture**)(*(u8**)(self + 0x6c) + 4);
        pane->setBlackWhite(black, white);
    }
    p = (u8*)__nw__FUl(0x2c); if (p) *(void**)p = lbl_804AF86C; *(u8**)(self + 0x70) = p;
    fn_80402F04(*(void**)(self + 0x70), (*(J2DScreen**)(self + 0x4))->search(0x546d6d743031ULL));
    p = (u8*)__nw__FUl(0x2c); if (p) *(void**)p = lbl_804AF86C; *(u8**)(self + 0x74) = p;
    fn_80402F04(*(void**)(self + 0x74), (*(J2DScreen**)(self + 0x4))->search(0x546d6d743032ULL));
    *(u16*)(self + 0x104) = 0; self[0x10b] = 0; self[0x10c] = 0; self[0x78] = 0;
    slot = self;
    for (i = 0; i < 12; i++, slot += 4) fn_80402E08(*(void**)(slot + 0x40), lbl_80543C88, lbl_80543CC4);
    image = (const ResTIMG*)fn_804030C4('TIMG', (names + 0x26c));
    *(J2DPicture**)(self + 0x258) = new J2DPicture(image);
    image = (const ResTIMG*)fn_804030C4('TIMG', (names + 0x280));
    *(J2DPicture**)(self + 0x25c) = new J2DPicture(image);
    image = (const ResTIMG*)fn_804030C4('TIMG', (names + 0x294));
    *(J2DPicture**)(self + 0x260) = new J2DPicture(image);
    image = (const ResTIMG*)fn_804030C4('TIMG', (names + 0x2a8));
    *(J2DPicture**)(self + 0x264) = new J2DPicture(image);
    image = (const ResTIMG*)fn_804030C4('TIMG', (names + 0x2bc));
    *(J2DPicture**)(self + 0x268) = new J2DPicture(image);
    image = (const ResTIMG*)fn_804030C4('TIMG', (names + 0x2d0));
    *(J2DPicture**)(self + 0x26c) = new J2DPicture(image);
    image = (const ResTIMG*)fn_804030C4('TIMG', (names + 0x2e4));
    *(J2DPicture**)(self + 0x270) = new J2DPicture(image);
    image = (const ResTIMG*)fn_804030C4('TIMG', (names + 0x2f8));
    *(J2DPicture**)(self + 0x274) = new J2DPicture(image);
    image = (const ResTIMG*)fn_804030C4('TIMG', (names + 0x30c));
    *(J2DPicture**)(self + 0x278) = new J2DPicture(image);
    image = (const ResTIMG*)fn_804030C4('TIMG', (names + 0x320));
    *(J2DPicture**)(self + 0x27c) = new J2DPicture(image);
    image = (const ResTIMG*)fn_804030C4('TIMG', ((const char**)lbl_804B1810)[0]);
    *(J2DPicture**)(self + 0x280) = new J2DPicture(image);
    image = (const ResTIMG*)fn_804030C4('TIMG', ((const char**)lbl_804B1810)[1]);
    *(J2DPicture**)(self + 0x284) = new J2DPicture(image);
    image = (const ResTIMG*)fn_804030C4('TIMG', ((const char**)lbl_804B1810)[2]);
    *(J2DPicture**)(self + 0x288) = new J2DPicture(image);
    image = (const ResTIMG*)fn_804030C4('TIMG', ((const char**)lbl_804B1810)[3]);
    *(J2DPicture**)(self + 0x28c) = new J2DPicture(image);
    image = (const ResTIMG*)fn_804030C4('TIMG', (names + 0x334));
    *(J2DPicture**)(self + 0x14) = new J2DPicture(image);
    picture = *(J2DPicture**)(self + 0x14);
    menuCorner(picture, 0, JUtility::TColor(255,210,0,255));
    menuCorner(picture, 1, JUtility::TColor(255,210,0,255));
    menuCorner(picture, 2, JUtility::TColor(212,34,0,255));
    menuCorner(picture, 3, JUtility::TColor(212,34,0,255));
    image = (const ResTIMG*)fn_804030C4('TIMG', (names + 0x344));
    *(J2DPicture**)(self + 0x18) = new J2DPicture(image);
    picture = *(J2DPicture**)(self + 0x18);
    menuCorner(picture, 0, JUtility::TColor(255,210,0,255));
    menuCorner(picture, 1, JUtility::TColor(255,210,0,255));
    menuCorner(picture, 2, JUtility::TColor(212,34,0,255));
    menuCorner(picture, 3, JUtility::TColor(212,34,0,255));
    image = (const ResTIMG*)fn_804030C4('TIMG', (names + 0x354));
    *(J2DPicture**)(self + 0x1c) = new J2DPicture(image);
    picture = *(J2DPicture**)(self + 0x1c);
    menuCorner(picture, 0, JUtility::TColor(255,210,0,255));
    menuCorner(picture, 1, JUtility::TColor(255,210,0,255));
    menuCorner(picture, 2, JUtility::TColor(212,34,0,255));
    menuCorner(picture, 3, JUtility::TColor(212,34,0,255));
    image = (const ResTIMG*)fn_804030C4('TIMG', (names + 0x364));
    *(J2DPicture**)(self + 0x20) = new J2DPicture(image);
    picture = *(J2DPicture**)(self + 0x20);
    menuCorner(picture, 0, JUtility::TColor(255,210,0,255));
    menuCorner(picture, 1, JUtility::TColor(255,210,0,255));
    menuCorner(picture, 2, JUtility::TColor(212,34,0,255));
    menuCorner(picture, 3, JUtility::TColor(212,34,0,255));
    image = (const ResTIMG*)fn_804030C4('TIMG', (names + 0x374));
    *(J2DPicture**)(self + 0x24) = new J2DPicture(image);
    picture = *(J2DPicture**)(self + 0x24);
    menuCorner(picture, 0, JUtility::TColor(255,170,210,255));
    menuCorner(picture, 1, JUtility::TColor(255,170,210,255));
    menuCorner(picture, 2, JUtility::TColor(4,36,130,255));
    menuCorner(picture, 3, JUtility::TColor(4,36,130,255));
    fn_804030C4('TIMG', (names + 0x280));
    u8 zero = 0;
    u8* cursor = self;
    for (s32 k = 0; k < 10; k++, cursor += 4) {
        *(f32*)(cursor + 0x118) = lbl_80543C88;
        *(f32*)(cursor + 0x140) = lbl_80543C88;
        *(f32*)(cursor + 0x168) = lbl_80543CCC;
        self[0x244+k] = 255; self[0x1f4+k] = zero; self[0x1fe+k] = zero; self[0x208+k] = zero; self[0x23a+k] = zero; self[0x226+k] = zero;
    }
    self[0x252] = 0;
    *(f32*)(self + 0x190) = lbl_80543C88;
    *(f32*)(self + 0x1a0) = lbl_80543C88;
    *(f32*)(self + 0x1b0) = lbl_80543CCC;
    self[0x24e] = 255; *(u32*)(self + 0x1d0) = 0;
    *(f32*)(self + 0x194) = lbl_80543C88;
    *(f32*)(self + 0x1a4) = lbl_80543C88;
    *(f32*)(self + 0x1b4) = lbl_80543CCC;
    self[0x24f] = 255; *(u32*)(self + 0x1d4) = 0;
    *(f32*)(self + 0x198) = lbl_80543C88;
    *(f32*)(self + 0x1a8) = lbl_80543C88;
    *(f32*)(self + 0x1b8) = lbl_80543CCC;
    self[0x250] = 255; *(u32*)(self + 0x1d8) = 0;
    *(f32*)(self + 0x19c) = lbl_80543C88;
    *(f32*)(self + 0x1ac) = lbl_80543C88;
    *(f32*)(self + 0x1bc) = lbl_80543CCC;
    self[0x251] = 255; *(u32*)(self + 0x1dc) = 0;
    self[0x253] = 0;
    if (((u8*)lbl_8053AAF8)[0x7f] && *(s32*)(lbl_80529DEC+0x118) == 8 && *(s32*)(lbl_80529DEC+0x11c) == 3) {
        image = (const ResTIMG*)fn_804032E8('TIMG', (names + 0x384));
        *(J2DPicture**)(self + 0x10) = new J2DPicture(image);
    } else *(void**)(self + 0x10) = 0;
    *(f32*)(self + 0x1c0) = lbl_80543C88;
    *(f32*)(self + 0x1c4) = lbl_80543C88;
    *(f32*)(self + 0x1c8) = lbl_80543C88;
    *(f32*)(self + 0x1cc) = lbl_80543C88;
    self[0x256] = 255; *(u32*)(self + 0xe4) = 0;
    *(u32*)(self + 0x1e0) = 1; self[0x1f0] = 0;
    *(u32*)(self + 0x1e4) = 1; self[0x1f1] = 0;
    *(u32*)(self + 0x1e8) = 1; self[0x1f2] = 0;
    *(u32*)(self + 0x1ec) = 1; self[0x1f3] = 0;
    return self;
}
#pragma opt_strength_reduction reset
extern "C" void fn_804408F0(JGeometry::TVec3<f32>* self) {
    JGeometry::TVec3<f32> v = *self;
    fn_8043E7CC(lbl_8053AED0, &v);
}
#pragma inline_depth(8)
extern "C" void* fn_80440928(f32 a, f32 b) { return ((void* (*)(void*, f32, f32))fn_8043DF8C)(lbl_8053AED0, a, b); }

#pragma opt_strength_reduction off
extern "C" void fn_8044094C(void) {
    u8* p = lbl_804B1810;
    u8* base = lbl_8052C5D8;
    *(FsaBlock48*)(p + 0xc0) = *(FsaBlock48*)(p + 0x90);
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, base + 0x28);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, base + 0x34);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, base + 0x40);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, base + 0x4c);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, base + 0x58);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, base + 0x64);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, base + 0x70);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, base + 0x7c);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, base + 0x88);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}
#pragma opt_strength_reduction reset
