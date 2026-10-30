#include "types.h"
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
extern "C" char lbl_80528568[];
extern "C" u32 lbl_804B06A0[];
#include "Game/FsaMenuAction.h"
#include "JSystem/J2D/J2DPane.h"
extern const f32 lbl_805436E8;
extern const f32 lbl_805436EC;

extern const f32 lbl_80543664;
extern const f32 lbl_805436A8;
extern const f32 lbl_805436AC;
extern const f32 lbl_805436F0;
extern const f32 lbl_805436F4;
extern const f32 lbl_80543668;
extern const f32 lbl_8054368C;
extern const f32 lbl_805436F8;
extern const f32 lbl_805436C0;
extern const f32 lbl_805436B0;
extern const f32 lbl_805436C4;
extern const f32 lbl_80543694;
extern const f32 lbl_805436FC;
extern const f32 lbl_80543698;
extern const f32 lbl_805436B4;
extern const f32 lbl_80543668;
extern const f32 lbl_805436BC;
extern const f32 lbl_805436C8;
extern const f64 lbl_80543678;
extern const f64 lbl_80543670;
extern const f32 lbl_8054369C;
extern const f32 lbl_805436A0;
extern const f32 lbl_805436A4;
extern const f32 lbl_80543680;
extern "C" u8 lbl_8050EC80[];
static inline f32 MenuSlideExit803E(s32 elapsed, const f32 magnitude, const f32 multiplier) {
    f32 square=(f32)(elapsed*elapsed);
    return magnitude*(square*multiplier);
}
static inline f32 MenuSquare803E(s32 n) { return n * n; }
static inline int MenuFadeAlpha803E(u8 alpha, const f32 factor) { return (f32)alpha * factor; }
static inline void MenuSetSlide803E(u8* entry, f32 value) { *(f32*)(entry + 0x120) = value; }
static inline f32 MenuGetSlide803E(u8* entry) { return *(f32*)(entry + 0x120); }
static inline f32 MenuAlpha803E(s32 elapsed) {
    return (f32)(elapsed * elapsed) / 900.0f;
}
static inline f32 MenuEnterSlide803E(const f32 magnitude, const f32 denominator, const s32 remaining) {
    f32 square = (f32)(remaining * remaining);
    return magnitude * (square / denominator);
}
static inline f32 MenuSlide803E(s32 remaining, const f32 magnitude, const f32 denominator) {
    f32 square=(f32)(remaining*remaining);
    return magnitude*(square/denominator);
}

class Screen803E4650 {
public:
    virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual class Pane803E4650* v3C(s32 a, s32 b);
};
class Pane803E4650 {
public:
    virtual void v08(); virtual void v0C();
    virtual void v10(f32 x, f32 y);
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void setAlpha(s32 a);
};
class Screen803EDBF0 {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual class Pane803E4650* v3C(s32 a, s32 b, s32 c);
};
extern "C" u8 lbl_80477970[];
static inline void MenuRowAlpha803E(u8* p, s32 id, u8* base, const f32 factor) {
    u8* alpha = p + id * 6;
    u64* names = (u64*)(base + 0x140);
    names += id * 6;
    for (int i = 0; i < 6; i++, alpha++, names++) {
        J2DPane* pane = (*(J2DPane**)(p + 4))->search(*names);
        f32 value = alpha[0x280];
        value *= factor;
        ((Pane803E4650*)pane)->setAlpha((int)value);
    }
}

extern "C" f32* getBounds__7J2DPaneFv(void* this_);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void* this_, f32 x, f32 y, void* ctx);
extern "C" void fn_80440EE8(void* p);
extern "C" void fn_80402E08(void* p, f32 a, f32 b);
extern "C" void* lbl_8053AB10;
extern "C" void* lbl_8053AED8;

extern "C" void* fn_804031C4(u32 type, void* name);
extern "C" void fn_803832BC(char* s, s32 a, s32 b, s32 c, s32 d);
extern "C" char* getStringPtr__10J2DTextBoxCFv(void* this_);

class J2DGrafContext;
#include "JSystem/J2D/J2DPicture.h"
struct Tu803E1668Obj {
    u8 _00[0x120];
    union { f32 slide[4]; f32 slideX; };
    u8 _130[0x8c];
    s32 selection;
    u8 _1c0[0x94];
    s16 timer;
    u8 _256[0x19];
    u8 panelAlpha[17];
    u8 rowAlpha[4][6];
};
typedef void (Tu803E1668Obj::*Tu803E1668Fn)();
struct T803ED83C;
typedef void (T803ED83C::*PMF803ED83C)();
extern PMF803ED83C lbl_804B0754[];
extern "C" void* lbl_8053AD30;
extern "C" u8 lbl_80529DEC[];
extern "C" u8 lbl_804B0B00[];
class T803EDF94Late : public FsaMenuActionBase {
public:
    virtual void v00(); virtual void v04(); virtual void v08();
    virtual void v0c(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1c(); virtual void v20();
    virtual void v24(); virtual void v30(s32);
};
class T803EDF94Obj {
public:
    virtual void v08(s32 a);
};
extern "C" u32 fn_80309C4C(void* a, s32 b, s32 c);
extern "C" u32 fn_80309A9C(void* a, s32 b, s32 c);


extern void* lbl_8053AF80;
extern "C" u8* lbl_8053AAF8;
extern "C" void* lbl_8053AD30;
extern "C" s32 fn_8030AAF4(s32 i);
extern "C" u8 fn_8030A308(void* a, s32 b);
extern "C" int fn_804366B8(void* p);
extern "C" void fn_80436668(void* p);
extern "C" void fn_80458880(void* mgr, s32 id, s32 a);
extern void* lbl_8053AEC0;
extern "C" void fn_8043670C(void* p, s32 a);
extern "C" void fn_80431A9C(void* mgr, s32 id, u8 v, s32 a);
extern "C" u8 fn_80402940(void* p, s32 id, f32 a, f32 b, s32 c);
extern "C" void fn_802F86CC(void* a, s32 b, s32 c, s32 d, s32 e, s32 f);
#pragma dont_inline on
extern "C" void fn_803E1668(u8* p) {
    s32 i;
    s32 j = 0;
    s32 k;
    f32 t;
    f32 a;
    f32 b;
    if (*(s32*)(p + 0x220) >= 100) {
        return;
    }
    for (i = 0; i < 4; i++) {
        j += 8;
    }
    k = *(s32*)(p + 0x1bc);
    a = (f32)k;
    b = a - 1.0f;
    t = b;
    fn_802F86CC(p, t, a, j, 0, 0);
}
#pragma dont_inline reset

#pragma dont_inline reset
extern "C" s32 fn_80403414(s32);
extern "C" s32 fn_804033D4(s32);
extern "C" s32 fn_8040336C(s32);
extern "C" s32 fn_80403070(s32);
extern "C" s32 fn_8040305C(s32);
extern "C" void* fn_804030C4(u32, const char*);
extern const char* lbl_804B0AD8[];
extern const s16 lbl_80543648[4];
extern const f32 lbl_80543690;
static inline ResTIMG* MenuDigit803E(s32 n) { return (ResTIMG*)fn_804030C4('TIMG', lbl_804B0AD8[n]); }
extern "C" void fn_803E29C8(u8* param_1) {
    fn_8043670C(*(void**)(param_1 + 0x5c), 0);
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 0xe;
}

extern "C" void fn_803E2A0C(u8* param_1) {
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 0xd;
}

extern "C" void fn_803E2A20(u8* p) {
    s32 max, j;
    const u64 *aa,*bb,*cc,*dd;
    u8* base = lbl_80477970;
    const u64* group = (const u64*)(base + 0xf08);
    u8* row = p;
    const u64* hundredsB = (const u64*)(base + 0xac0);
    const u64* tensA = (const u64*)(base + 0xa60);
    const u64* tensB = (const u64*)(base + 0xa80);
    const u64* onesA = (const u64*)(base + 0xa20);
    const u64* onesB = (const u64*)(base + 0xa40);
    const u64* status;
    const u64* statusBase = (const u64*)(base + 0x9e0);
    const u64* a = (const u64*)(base + 0xba8);
    const u64* b = (const u64*)(base + 0xc68);
    const u64* c = (const u64*)(base + 0xd28);
    const u64* d = (const u64*)(base + 0xde8);
    s32 i;
    register const u64* hundredsA = (const u64*)(base + 0xaa0);
    status = statusBase;
    for (i=0; i<4; i++, row+=4, group++, hundredsA++, hundredsB++, tensA++, tensB++, onesA++, onesB++, status++, a+=6,b+=6,c+=6,d+=6) {
        if(i>=1) {
            if(i>*(s32*)(p+0x1bc)) (*(J2DPane**)(p+0x10))->search(group[-1])->show();
            else (*(J2DPane**)(p+0x10))->search(group[-1])->hide();
        }
        *(s32*)(row+0x1f0)=fn_80403414(i);
        *(s32*)(row+0x200)=fn_804033D4(i);
        *(s32*)(row+0x210)=fn_8040336C(i);
        s32 value=fn_80403070(*(s32*)(row+0x1f0));
        ResTIMG* texture=MenuDigit803E(value/100);
        ((J2DPicture*)(*(J2DPane**)(p+0x10))->search(*hundredsA))->changeTexture((ResTIMG*)texture,0);
        ((J2DPicture*)(*(J2DPane**)(p+0x10))->search(*hundredsB))->changeTexture((ResTIMG*)texture,0);
        texture=MenuDigit803E(value%100/10);
        ((J2DPicture*)(*(J2DPane**)(p+0x10))->search(*tensA))->changeTexture((ResTIMG*)texture,0);
        ((J2DPicture*)(*(J2DPane**)(p+0x10))->search(*tensB))->changeTexture((ResTIMG*)texture,0);
        texture=MenuDigit803E(value%10);
        ((J2DPicture*)(*(J2DPane**)(p+0x10))->search(*onesA))->changeTexture((ResTIMG*)texture,0);
        ((J2DPicture*)(*(J2DPane**)(p+0x10))->search(*onesB))->changeTexture((ResTIMG*)texture,0);
        max=fn_8040305C(*(s32*)(row+0x200))-1;
        aa=a;bb=b;cc=c;dd=d;
        for(j=0;j<6;j++,aa++,bb++,cc++,dd++){
            if(j<max){
                {
                J2DPane* pane=(*(J2DPane**)(p+0x10))->search(*aa);
                u64 tag=*bb;
                pane->show();
                (*(J2DPane**)(p+0x10))->search(tag)->show();
                }
                {
                J2DPane* pane=(*(J2DPane**)(p+0x10))->search(*cc);
                u64 tag=*dd;
                pane->hide();
                (*(J2DPane**)(p+0x10))->search(tag)->hide();
                }
            }else if(j==max){
                {
                J2DPane* pane=(*(J2DPane**)(p+0x10))->search(*aa);
                u64 tag=*bb;
                pane->hide();
                (*(J2DPane**)(p+0x10))->search(tag)->hide();
                }
                {
                J2DPane* pane=(*(J2DPane**)(p+0x10))->search(*cc);
                u64 tag=*dd;
                pane->show();
                (*(J2DPane**)(p+0x10))->search(tag)->show();
                }
            }else{
                {
                J2DPane* pane=(*(J2DPane**)(p+0x10))->search(*aa);
                u64 tag=*bb;
                pane->hide();
                (*(J2DPane**)(p+0x10))->search(tag)->hide();
                }
                {
                J2DPane* pane=(*(J2DPane**)(p+0x10))->search(*cc);
                u64 tag=*dd;
                pane->hide();
                (*(J2DPane**)(p+0x10))->search(tag)->hide();
                }
            }
        }
        (*(J2DPane**)(p+0x10))->search(*status)->hide();
    }
    fn_80402E08(*(void**)(p+0x64),lbl_80543664,lbl_8054368C);
    *(s16*)(*(u8**)(p+0x64)+0x22)=0;
    row=p;u8* counter=p;
    const u64* normal=(const u64*)(base+0x9a0);
    const u64* selected=(const u64*)(base+0x9c0);
    status=statusBase;
    for(i=0;i<4;i++,row+=4,counter+=2,normal++,selected++,status++){
        if(i<=*(s32*)(p+0x1bc)){
            fn_80402E08(*(void**)(row+0x68),lbl_80543664,lbl_80543690);
            *(s16*)(*(u8**)(row+0x68)+0x22)=0;
        }
        if(i<=*(s32*)(p+0x1bc)) *(s32*)(row+0x1c0)=3;
        else *(s32*)(row+0x1c0)=4;
        *(s32*)(row+0x1e0)=30;
        if(i<=*(s32*)(p+0x1bc)){
            if(*(s32*)(row+0x1c0)<3){
                {
                J2DPane* pane=(*(J2DPane**)(p+0x10))->search(*normal);
                u64 tag=*selected;
                pane->hide();
                (*(J2DPane**)(p+0x10))->search(tag)->show();
                }
                (*(J2DPane**)(p+0x10))->search(*status)->hide();
            }else if(*(s32*)(row+0x1c0)==3){
                {
                J2DPane* pane=(*(J2DPane**)(p+0x10))->search(*normal);
                u64 tag=*selected;
                pane->hide();
                (*(J2DPane**)(p+0x10))->search(tag)->show();
                }
                (*(J2DPane**)(p+0x10))->search(*status)->show();
            }else{
                {
                J2DPane* pane=(*(J2DPane**)(p+0x10))->search(*normal);
                u64 tag=*selected;
                pane->show();
                (*(J2DPane**)(p+0x10))->search(tag)->hide();
                }
                (*(J2DPane**)(p+0x10))->search(*status)->hide();
            }
        }else{
            {
            J2DPane* pane=(*(J2DPane**)(p+0x10))->search(*normal);
            u64 tag=*selected;
            pane->hide();
            (*(J2DPane**)(p+0x10))->search(tag)->hide();
            }
            (*(J2DPane**)(p+0x10))->search(*status)->hide();
        }
        s32 state=*(s32*)(row+0x1c0);
        if(state<=3){
            f32 x=(*(J2DPane**)(p+0x10))->search(*selected)->getBounds()->i.x;
            (*(J2DPane**)(p+0x10))->search(*selected)->move(x,(f32)lbl_80543648[state]);
        }
        *(s16*)(counter+0x254)=0;
        *(s32*)(row+0x1e0)=0;
    }
    fn_80402E08(*(void**)(p+0x78),lbl_80543664,lbl_8054368C);
    *(s16*)(*(u8**)(p+0x78)+0x22)=0;
    *(s16*)(p+0x260)=0;
    *(s32*)(p+0x1d8)=*(s32*)(p+0x1d4);
    *(s32*)(p+0x1d4)=12;
}

#pragma opt_propagation off
extern "C" void fn_803E3320(u8* param_1) {
    s32 j = 0;
    s32 i;
    *(s16*)(param_1 + 0x254) = j;
    *(s32*)(param_1 + 0x1e0) = 5;
    if (*(s32*)(param_1 + 0x1bc) == 0) {
        if (*(s32*)(param_1 + 0x1b8) == 1) {
            lbl_8053AAF8[0x82] |= 0x10;
            lbl_8053AAF8[0x82] &= ~0x20;
            lbl_8053AAF8[0x82] &= ~0x40;
            lbl_8053AAF8[0x82] &= 0x7f;
            lbl_8053AAF8[0x82] |= 0x1;
            lbl_8053AAF8[0x82] &= ~0x2;
            lbl_8053AAF8[0x82] &= ~0x4;
            lbl_8053AAF8[0x82] &= ~0x8;
            if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(0)) != 0) {
                u8* p = lbl_8053AAF8;
                p[0x83] &= ~0x3;
                p[0x83] |= 0x1;
            } else {
                u8* p = lbl_8053AAF8;
                p[0x83] &= ~0x3;
                p[0x83] |= 0x2;
            }
            lbl_8053AAF8[0x83] &= ~0xc;
            lbl_8053AAF8[0x83] &= ~0x30;
            lbl_8053AAF8[0x83] &= 0x3f;
        }
    } else if (*(s32*)(param_1 + 0x1b8) == 0) {
        for (i = 0; i < 4; i++) {
            if (i < *(s32*)(param_1 + 0x1bc) + 1) {
                lbl_8053AAF8[0x82] |= (u8)(1 << i);
                u8* p = lbl_8053AAF8;
                p[0x83] &= ~(u8)(3 << j);
                p[0x83] |= (u8)(1 << j);
            } else {
                lbl_8053AAF8[0x82] &= ~(u8)(1 << i);
                lbl_8053AAF8[0x83] &= ~(u8)(3 << j);
            }
            j += 2;
        }
    }
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 0xb;
}
#pragma opt_propagation reset
extern "C" void fn_803E3548(u8* param_1) {
    *(s16*)(param_1 + 0x254) = 0;
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 10;
}

class Picture803E3CB0 {
public:
    virtual void p00(); virtual void p01(); virtual void p02(); virtual void p03();
    virtual void p04(); virtual void p05(); virtual void p06(); virtual void p07();
    virtual void p08(); virtual void p09(); virtual void p10(); virtual void p11();
    virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15();
    virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19();
    virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23();
    virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27();
    virtual void p28(); virtual void p29(); virtual void p30(); virtual void p31();
    virtual void p32(); virtual void p33(); virtual void p34(); virtual void p35();
    virtual void p36(); virtual void p37(); virtual void p38(); virtual void p39();
    virtual void p40(); virtual void p41(); virtual void p42(); virtual void p43();
    virtual void p44(); virtual void p45(); virtual void p46(); virtual void p47();
    virtual void p48(); virtual void p49(); virtual void p50(); virtual void p51();
    virtual void p52(); virtual void p53(); virtual void p54(); virtual void p55();
    virtual void p56(); virtual void p57(); virtual void p58(); virtual void p59();
    virtual void p60(); virtual void p61(); virtual void p62(); virtual void p63();
    virtual void p64(); virtual void p65();
    virtual void* changeTexture(void* img, u8 id);
};
extern "C" void fn_803E3564(u8* p) {
    u8* base = lbl_80477970;
    char* a;
    char* b;
    char* c;
    Pane803E4650* pane;

    a = getStringPtr__10J2DTextBoxCFv((Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x5468 << 32) | 0x616e3031));
    b = getStringPtr__10J2DTextBoxCFv((Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x5473 << 32) | 0x74613031));
    c = getStringPtr__10J2DTextBoxCFv((Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x547275 << 32) | 0x6c653031));
    if (*(s32*)(p + 0x1bc) == 0) {
        if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(0)) != 0) {
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x5067 << 32) | 0x62613032);
            ((u8*)pane)[0xb0] = 0;
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x5063 << 32) | 0x6f6e3032);
            ((u8*)pane)[0xb0] = 1;
        } else {
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x5067 << 32) | 0x62613032);
            ((u8*)pane)[0xb0] = 1;
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x5063 << 32) | 0x6f6e3032);
            ((u8*)pane)[0xb0] = 0;
        }
        fn_803832BC(b, 0x11b, 0, 0, 0);
        fn_803832BC(a, 0x11b, 0, 0, 0);
        fn_803832BC(c, 0xf7, 0, 0, 0);
        void* g = fn_804031C4(0x54494d47, base + 0xfd8);
        pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506e << 32) | 0x6f703032);
        ((Picture803E3CB0*)pane)->changeTexture(g, 0);
        pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506e << 32) | 0x6f703031);
        ((Picture803E3CB0*)pane)->changeTexture(g, 0);
        pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x507374 << 32) | 0x61623034);
        ((u8*)pane)[0xb0] = 0;
    } else {
        fn_803832BC(b, 0x11b, 0, 0, 0);
        fn_803832BC(a, 0xac, 0, 0, 0);
        fn_803832BC(c, 0xf7, 0, 0, 0);
        pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x5067 << 32) | 0x62613032);
        ((u8*)pane)[0xb0] = 0;
        pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x5063 << 32) | 0x6f6e3032);
        ((u8*)pane)[0xb0] = 1;
        if (*(s32*)(p + 0x1bc) == 1) {
            void* g = fn_804031C4(0x54494d47, base + 0xfec);
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506e << 32) | 0x6f703032);
            ((Picture803E3CB0*)pane)->changeTexture(g, 0);
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506e << 32) | 0x6f703031);
            ((Picture803E3CB0*)pane)->changeTexture(g, 0);
        } else if (*(s32*)(p + 0x1bc) == 2) {
            void* g = fn_804031C4(0x54494d47, base + 0x1000);
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506e << 32) | 0x6f703032);
            ((Picture803E3CB0*)pane)->changeTexture(g, 0);
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506e << 32) | 0x6f703031);
            ((Picture803E3CB0*)pane)->changeTexture(g, 0);
        } else {
            void* g = fn_804031C4(0x54494d47, base + 0x1014);
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506e << 32) | 0x6f703032);
            ((Picture803E3CB0*)pane)->changeTexture(g, 0);
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506e << 32) | 0x6f703031);
            ((Picture803E3CB0*)pane)->changeTexture(g, 0);
        }
        pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x507374 << 32) | 0x61623034);
        ((u8*)pane)[0xb0] = 1;
    }
    *(f32*)(p + 0x164) = -200.0f;
    *(f32*)(p + 0x168) = -200.0f;
    *(f32*)(p + 0x184) = 300.0f;
    *(f32*)(p + 0x188) = 300.0f;
    *(f32*)(p + 0x18c) = 300.0f;
    *(f32*)(p + 0x198) = -450.0f;
    pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506d6164 << 32) | 0x62623037);
    pane->v10(*(f32*)(p + 0x15c), *(f32*)(p + 0x160) + *(f32*)(p + 0x164));
    fn_80402E08(*(void**)(p + 0x78), 0.0f, *(f32*)(p + 0x168));
    pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x507374 << 32) | 0x61623034);
    pane->v10(*(f32*)(p + 0x16c) + *(f32*)(p + 0x184), *(f32*)(p + 0x178));
    pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506861 << 32) | 0x6e623034);
    pane->v10(*(f32*)(p + 0x170) + *(f32*)(p + 0x188), *(f32*)(p + 0x17c));
    pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x5072 << 32) | 0x75623034);
    pane->v10(*(f32*)(p + 0x174) + *(f32*)(p + 0x18c), *(f32*)(p + 0x180));
    pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 0xc))->search(((u64)0x506c6962 << 32) | 0x6b6b3033);
    pane->v10(*(f32*)(p + 0x190) + *(f32*)(p + 0x198), *(f32*)(p + 0x194));
    *(s32*)(p + 0x220) = 0;
    *(s32*)(p + 0x1e0) = 0;
    *(s16*)(p + 0x254) = 0;
    *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
    *(s32*)(p + 0x1d4) = 9;
}

extern "C" void fn_803E3C00(u8* param_1) {
    s32 n = *(s32*)(param_1 + 0x1bc);
    if (n == 0) {
        fn_80431A9C(lbl_8053AEC0, 0xa9, (u8)(n + 1), 0);
    } else {
        fn_80431A9C(lbl_8053AEC0, 0xc4, (u8)(n + 1), 0);
    }
    param_1[0x26c] = 0;
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 8;
}

extern "C" void fn_803E3C80(u8* param_1) {
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 7;
}

extern "C" void fn_803E3C94(u8* param_1) {
    *(s16*)(param_1 + 0x254) = 0;
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 6;
}

extern "C" void* fn_804031C4(u32 type, void* name);
extern "C" void fn_803832BC(char* s, s32 a, s32 b, s32 c, s32 d);
extern "C" char* getStringPtr__10J2DTextBoxCFv(void* this_);

// Picture pane view: changeTexture(img, id) at vtable 0x110.
extern "C" void fn_803E3CB0(u8* p) {
    u8* base = lbl_80477970;
    u8 v;
    u64* b;
    u64* tA;
    u64* tB;
    u64* tC;
    u8* q;
    if (*(s32*)(p + 0x1bc) == 1) {
        void* g = fn_804031C4(0x54494d47, base + 0xfec);
        ((Picture803E3CB0*)(*(J2DPane**)(p + 8))->search(0x50746e3032ULL))->changeTexture(g, 0);
        ((Picture803E3CB0*)(*(J2DPane**)(p + 8))->search(0x50746e3031ULL))->changeTexture(g, 0);
    } else if (*(s32*)(p + 0x1bc) == 2) {
        void* g = fn_804031C4(0x54494d47, base + 0x1000);
        ((Picture803E3CB0*)(*(J2DPane**)(p + 8))->search(0x50746e3032ULL))->changeTexture(g, 0);
        ((Picture803E3CB0*)(*(J2DPane**)(p + 8))->search(0x50746e3031ULL))->changeTexture(g, 0);
    } else {
        void* g = fn_804031C4(0x54494d47, base + 0x1014);
        ((Picture803E3CB0*)(*(J2DPane**)(p + 8))->search(0x50746e3032ULL))->changeTexture(g, 0);
        ((Picture803E3CB0*)(*(J2DPane**)(p + 8))->search(0x50746e3031ULL))->changeTexture(g, 0);
    }
    {
        char* s1 = getStringPtr__10J2DTextBoxCFv((*(J2DPane**)(p + 8))->search(0x54746b673031ULL));
        char* s2 = getStringPtr__10J2DTextBoxCFv((*(J2DPane**)(p + 8))->search(0x54746b673032ULL));
        fn_803832BC(s1, 0x3e, 0, 0, 0);
        fn_803832BC(s2, 0x3e, 0, 0, 0);
    }
    *(f32*)(p + 0xa0) = -300.0f;
    (*(J2DPane**)(p + 8))->search(0x4e646174613033ULL)->move(*(f32*)(p + 0x98), *(f32*)(p + 0x9c) + *(f32*)(p + 0xa0));
    *(f32*)(p + 0xac) = -100.0f;
    (*(J2DPane**)(p + 8))->search(0x4e646174613035ULL)->move(*(f32*)(p + 0xa4), *(f32*)(p + 0xa8) + *(f32*)(p + 0xac));
    *(f32*)(p + 0xb8) = -200.0f;
    (*(J2DPane**)(p + 8))->search(0x4e646174613036ULL)->move(*(f32*)(p + 0xb0), *(f32*)(p + 0xb4) + *(f32*)(p + 0xb8));
    *(f32*)(p + 0xbc) = -200.0f;
    fn_80402E08(*(void**)(p + 0x78), 0.0f, *(f32*)(p + 0xbc));
    *(f32*)(p + 0xe0) = 200.0f;
    (*(J2DPane**)(p + 8))->search(0x50706c6c626b3032ULL)->move(*(f32*)(p + 0xc0), *(f32*)(p + 0xd0) + *(f32*)(p + 0xe0));
    *(f32*)(p + 0xe4) = 200.0f;
    (*(J2DPane**)(p + 8))->search(0x50706c6c626b3132ULL)->move(*(f32*)(p + 0xc4), *(f32*)(p + 0xd4) + *(f32*)(p + 0xe4));
    *(f32*)(p + 0xe8) = 200.0f;
    (*(J2DPane**)(p + 8))->search(0x50706c6c626b3232ULL)->move(*(f32*)(p + 0xc8), *(f32*)(p + 0xd8) + *(f32*)(p + 0xe8));
    *(f32*)(p + 0xec) = 200.0f;
    (*(J2DPane**)(p + 8))->search(0x50706c6c626b3332ULL)->move(*(f32*)(p + 0xcc), *(f32*)(p + 0xdc) + *(f32*)(p + 0xec));
    q = p;
    tA = (u64*)(base + 0x840);
    tB = (u64*)(base + 0x8e0);
    tC = (u64*)(base + 0x8c0);
    for (s32 i = 0; i < 4; i++) {
        if (i <= *(s32*)(p + 0x1bc)) {
            J2DPane* o = (*(J2DPane**)(p + 8))->search(*tA);
            v = 1;
            b = tB + 2;
            ((u8*)o)[0xb0] = v;
            for (s32 j = 2; j < 4; j++) {
                ((u8*)(*(J2DPane**)(p + 8))->search(*b))[0xb0] = v;
                b++;
            }
            (*(J2DPane**)(p + 8))->search(*tC)->setAlpha(0xff);
            *(s32*)(q + 0x230) = *(s16*)(*(u8**)(q + 0x38) + 6);
            *(s32*)(q + 0x240) = *(s16*)(*(u8**)(q + 0x48) + 6);
        } else {
            J2DPane* o = (*(J2DPane**)(p + 8))->search(*tA);
            v = 0;
            b = tB + 2;
            ((u8*)o)[0xb0] = v;
            for (s32 j = 2; j < 4; j++) {
                ((u8*)(*(J2DPane**)(p + 8))->search(*b))[0xb0] = v;
                b++;
            }
            (*(J2DPane**)(p + 8))->search(*tC)->setAlpha(0x80);
            *(s32*)(q + 0x230) = 0;
            *(s32*)(q + 0x240) = 0;
        }
        tA++;
        tB += 4;
        tC++;
        q += 4;
    }
    *(s16*)(p + 0x254) = 0;
    *(s16*)(p + 0x25e) = 0;
    *(s16*)(p + 0x25c) = 0;
    p[0x26b] = 0;
    *(s16*)(p + 0x250) = -1;
    *(s16*)(p + 0x252) = -1;
    *(s16*)(p + 0x262) = 0;
    *(s32*)(p + 0x220) = 0;
    *(s32*)(p + 0x224) = 0;
    *(s32*)(p + 0x228) = 0;
    *(s32*)(p + 0x22c) = 0;
    *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
    *(s32*)(p + 0x1d4) = 5;
}

extern "C" void fn_803E4308(u8* param_1) {
    *(s32*)(param_1 + 0x220) = 0;
    *(s16*)(param_1 + 0x254) = 0;
    *(s32*)(param_1 + 0x1e0) = 5;
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 4;
}

extern "C" void fn_803E4330(u8* param_1) {
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 3;
}

extern "C" void fn_80402E08(void* p, f32 a, f32 b);
extern "C" void fn_803E4344(u8* p) {
    *(f32*)(p + 0xf8) = lbl_805436A8;
    (*(J2DPane**)(p + 4))->search(0x506d616462623037ULL)->move(*(f32*)(p + 0xf0), *(f32*)(p + 0xf4) + *(f32*)(p + 0xf8));
    *(f32*)(p + 0xfc) = lbl_8054368C;
    fn_80402E08(*(void**)(p + 0x78), lbl_80543664, *(f32*)(p + 0xfc));
    *(f32*)(p + 0x120) = lbl_805436AC;
    (*(J2DPane**)(p + 4))->search(0x00506e6f70623034ULL)->move(*(f32*)(p + 0x100) + *(f32*)(p + 0x120), *(f32*)(p + 0x110));
    *(f32*)(p + 0x124) = lbl_805436AC;
    (*(J2DPane**)(p + 4))->search(0x00506e6f70623038ULL)->move(*(f32*)(p + 0x104) + *(f32*)(p + 0x124), *(f32*)(p + 0x114));
    *(f32*)(p + 0x128) = lbl_805436AC;
    (*(J2DPane**)(p + 4))->search(0x00506e6f70623132ULL)->move(*(f32*)(p + 0x108) + *(f32*)(p + 0x128), *(f32*)(p + 0x118));
    *(f32*)(p + 0x12c) = lbl_805436AC;
    (*(J2DPane**)(p + 4))->search(0x00506e6f70623136ULL)->move(*(f32*)(p + 0x10c) + *(f32*)(p + 0x12c), *(f32*)(p + 0x11c));
    *(f32*)(p + 0x138) = lbl_805436B0;
    (*(J2DPane**)(p + 4))->search(0x004e646174613032ULL)->move(*(f32*)(p + 0x130) + *(f32*)(p + 0x138), *(f32*)(p + 0x134));
    *(f32*)(p + 0x14c) = lbl_805436B0;
    (*(J2DPane**)(p + 4))->search(0x004e646174613035ULL)->move(*(f32*)(p + 0x13c) + *(f32*)(p + 0x14c), *(f32*)(p + 0x140));
    (*(J2DPane**)(p + 4))->search(0x004e646174613037ULL)->move(*(f32*)(p + 0x144) + *(f32*)(p + 0x14c), *(f32*)(p + 0x148));
    *(s32*)(p + 0x220) = 0;
    *(s32*)(p + 0x1e0) = 0;
    *(s16*)(p + 0x254) = 0;
    *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
    *(s32*)(p + 0x1d4) = 2;
}

extern "C" void fn_803E45FC(u8* param_1) {
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 1;
}

extern "C" void fn_803E4610(u8* param_1) {
    *(s32*)(param_1 + 0x1e0) = 0;
    *(s16*)(param_1 + 0x254) = 0;
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 0;
}

extern "C" void fn_803E462C(u8* param_1) {
    fn_80436668(*(void**)(param_1 + 0x5c));
}

#pragma opt_common_subs off
extern "C" void fn_803E4650(u8* p) {
    u8* q;
    u64* tA = (u64*)(lbl_80477970 + 0x9c0);
    u64* tB = (u64*)(lbl_80477970 + 0x9e0);
    u64* tC = (u64*)(lbl_80477970 + 0xa00);
    u8* sp;
    s32 i;
    s32 k;
    s32 n;
    f32 t;
    f32 off;
    J2DPane* pane;
    i = 0;
    q = p;
    sp = p;
    for (; i < 4; i++, q += 4, tA++, tB++, tC++, sp += 2) {

    n = *(s32*)(q + 0x1e0);
    if (n < 30) {
        t = MenuAlpha803E(n);
    } else {
        t = MenuAlpha803E(n - 30);
        t = 1.0f - t;
    }
        if (i <= *(s32*)(p + 0x1bc)) {
            if (*(s32*)(q + 0x1c0) < 4) {
                pane = (*(J2DPane**)(p + 0x10))->search(*tA);
                ((Pane803E4650*)pane)->setAlpha((s32)(160.0f * t));
            }
            if (*(s32*)(q + 0x1c0) == 3) {
                pane = (*(J2DPane**)(p + 0x10))->search(*tB);
                ((Pane803E4650*)pane)->setAlpha((s32)(t * (f32)p[0x26a]));
                pane = (*(J2DPane**)(p + 0x10))->search(*tC);
                ((Pane803E4650*)pane)->setAlpha((s32)(t * (f32)p[0x26a]));
            }
        }
            if (*(s32*)(p + 0x1d4) != 0xc) {
                k = *(s16*)(sp + 0x254);
                k = k < 5 ? k : 10 - k;
                off = (5.0f * (f32)(k * k)) / 25.0f;
                pane = (*(J2DPane**)(p + 0x10))->search(*tB);
                t = getBounds__7J2DPaneFv(pane)[0];
                pane = (*(J2DPane**)(p + 0x10))->search(*tB);
                pane->move(t, *(f32*)(p + 0x1b0) + off);
                if (*(s32*)(q + 0x1c0) >= 3) {
                    fn_80402E08(*(void**)(q + 0x68), 0.0f, off);
                }
            }
    }
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p + 0x10), 0.0f, 0.0f, *(void**)((u8*)lbl_8053AB10 + 0x10));
    fn_80440EE8(lbl_8053AED8);
}
#pragma opt_common_subs reset
extern const f32 lbl_80543654;
extern const f32 lbl_8054365C;
extern "C" void fn_8013B414(void*, void*, s32);
#pragma auto_inline off
extern "C" void fn_803E4940(u8* p) {
    s32 state = *(s32*)(p + 0x1d4);
    f32 f2;
    f32 alpha;
    f32 off;
    f32 t;
    s32 n;
    if (state != 11) {
        if (*(s32*)(p + 0x1e0) < 0x1e) {
            f2 = MenuSquare803E(*(s32*)(p + 0x1e0)) / lbl_805436B4;
        } else {
            f2 = lbl_80543668 - MenuSquare803E(*(s32*)(p + 0x1e0) - 0x1e) / lbl_805436B4;
        }
        alpha = f2 * (f32)*(u8*)(p + 0x269);
    } else if (*(s32*)(p + 0x1dc) == 2) {
        alpha = lbl_80543664;
    } else {
        if (*(s32*)(p + 0x1e0) < 0xf) {
            f2 = MenuSquare803E(*(s32*)(p + 0x1e0)) / lbl_805436C4;
        } else {
            f2 = lbl_80543668 - MenuSquare803E(*(s32*)(p + 0x1e0) - 0xf) / lbl_805436C4;
        }
        alpha = lbl_805436C8 * f2;
    }
    if (state == 0 || state == 10 || (state == 11 && *(s32*)(p + 0x1dc) != 2 && *(s16*)(p + 0x254) <= 10)) {
        n = *(s16*)(p + 0x254);
        if (n < 5) {
            n = *(s16*)(p + 0x254);
        } else {
            n = 10 - n;
        }
    } else {
        n = 0;
    }
    off = lbl_805436BC * MenuSquare803E(n) / lbl_805436C0;
    if (*(s32*)(p + 0x1b8) == 0) {
        t = (*(J2DPane**)(p + 0xc))->search(0x0050737461623034ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x0050737461623034ULL)->move(t, *(f32*)(p + 0x150) + off);
        t = (*(J2DPane**)(p + 0xc))->search(0x005068616e623034ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x005068616e623034ULL)->move(t, *(f32*)(p + 0x154));
        t = (*(J2DPane**)(p + 0xc))->search(0x0000507275623034ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x0000507275623034ULL)->move(t, *(f32*)(p + 0x158));
        t = (*(J2DPane**)(p + 0xc))->search(0x50736375726f3032ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x50736375726f3032ULL)->move(t, *(f32*)(p + 0x1a8) + off);
    } else if (*(s32*)(p + 0x1b8) == 1) {
        t = (*(J2DPane**)(p + 0xc))->search(0x0050737461623034ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x0050737461623034ULL)->move(t, *(f32*)(p + 0x150));
        t = (*(J2DPane**)(p + 0xc))->search(0x005068616e623034ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x005068616e623034ULL)->move(t, *(f32*)(p + 0x154) + off);
        t = (*(J2DPane**)(p + 0xc))->search(0x0000507275623034ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x0000507275623034ULL)->move(t, *(f32*)(p + 0x158));
        t = (*(J2DPane**)(p + 0xc))->search(0x0050737461623034ULL)->getBounds()->i.y;
        off = (*(f32*)(p + 0x1a8) + (*(J2DPane**)(p + 0xc))->search(0x005068616e623034ULL)->getBounds()->i.y) - t;
        t = (*(J2DPane**)(p + 0xc))->search(0x50736375726f3032ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x50736375726f3032ULL)->move(t, off);
    } else {
        t = (*(J2DPane**)(p + 0xc))->search(0x0050737461623034ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x0050737461623034ULL)->move(t, *(f32*)(p + 0x150));
        t = (*(J2DPane**)(p + 0xc))->search(0x005068616e623034ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x005068616e623034ULL)->move(t, *(f32*)(p + 0x154));
        t = (*(J2DPane**)(p + 0xc))->search(0x0000507275623034ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x0000507275623034ULL)->move(t, *(f32*)(p + 0x158) + off);
        t = (*(J2DPane**)(p + 0xc))->search(0x0050737461623034ULL)->getBounds()->i.y;
        t = (*(f32*)(p + 0x1a8) + (*(J2DPane**)(p + 0xc))->search(0x0000507275623034ULL)->getBounds()->i.y) - t;
        off = (*(J2DPane**)(p + 0xc))->search(0x50736375726f3032ULL)->getBounds()->i.x;
        (*(J2DPane**)(p + 0xc))->search(0x50736375726f3032ULL)->move(off, t);
    }
    (*(J2DPane**)(p + 0xc))->search(0x50736375726f3031ULL)->setAlpha((u8)alpha);
    (*(J2DPane**)(p + 0xc))->search(0x50736375726f3032ULL)->setAlpha((u8)alpha);
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p + 0xc), lbl_80543664, lbl_80543664, ((void**)lbl_8053AB10)[4]);
    {
        f32 box[4];
        box[0] = lbl_80543664;
        box[1] = lbl_80543664;
        box[2] = lbl_80543654;
        box[3] = lbl_8054365C;
        fn_8013B414(lbl_8053AB10, box, 1);
    }
    fn_803E1668(p);
    fn_80440EE8(lbl_8053AED8);
}
#pragma auto_inline reset
extern const f32 lbl_805436CC;
extern const f32 lbl_80543690;
extern const f32 lbl_805436D4;
extern const f32 lbl_805436D0;
#include "Game/ItemBase.h"
extern "C" u8 fn_8030A388(void*, s32);
extern "C" void fn_8013B490(void*);
extern "C" void fn_804316EC(void*);
extern "C" u8* sManager__8JUTVideo;
extern const f32 lbl_80543650, lbl_80543658, lbl_80543660, lbl_805436D8, lbl_805436DC, lbl_805436E0;
static inline u8 MenuEnabled803E(s32 i) { return (lbl_8053AAF8[0x82] & (u8)(1 << (i + 4))) != 0; }
static inline s16 MenuNext803E(s16 old, s32 count) {
    s16 next = old;
    for (s32 i = 0; i < count; i++) {
        next++;
        if (next >= count) next = 0;
        if (!(lbl_8053AAF8[0x82] & (u8)(1 << (next + 4)))) return next;
        if (next == old) return -1;
    }
    return -1;
}
static inline void MenuRestore803E(u8* p, const u64* a, const u64* b, const u64* c) {
    ((Pane803E4650*)(*(J2DPane**)(p + 8))->search(*a))->setAlpha(p[0x265]);
    ((Pane803E4650*)(*(J2DPane**)(p + 8))->search(*b))->setAlpha(p[0x266]);
    ((Pane803E4650*)(*(J2DPane**)(p + 8))->search(*c))->setAlpha(p[0x267]);
}
class MenuResource803E {
public:
    virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
    virtual void* get(u32, const void*);
};
static inline void MenuSprite803E(JGeometry::TVec3f& pos, s32 id, DrawRec& rec, const u8* base=lbl_80477970) {
    MenuResource803E* mgr = *(MenuResource803E**)(lbl_8053AAF8 + 0xa4);
    void* res = mgr->get('SOB ', base + 0xfa0);
    ((void(*)(void*,const JGeometry::TVec3f*,void*,s32,DrawRec*,f32,f32))fn_802F86CC)(((void**)lbl_8053AB10)[8], &pos, res, id, &rec, lbl_80543668, lbl_80543668);
}

struct MenuFrameValue803E {s32 frame;};
struct MenuFrame803E {u8 _00[0x230];MenuFrameValue803E frame230[4];MenuFrameValue803E frame240[4];};
static inline void MenuRestoreValue803E(u8* p,u64 a,const u64* b,const u64* c) {
    ((Pane803E4650*)(*(J2DPane**)(p+8))->search(a))->setAlpha(p[0x265]);
    ((Pane803E4650*)(*(J2DPane**)(p+8))->search(*b))->setAlpha(p[0x266]);
    ((Pane803E4650*)(*(J2DPane**)(p+8))->search(*c))->setAlpha(p[0x267]);
}
static inline void MenuRestoreClear803E(u8* p,u64 a,const u64* b,const u64* c,s32 mask) {
    p[0x26b]&=~mask;
    ((Pane803E4650*)(*(J2DPane**)(p+8))->search(a))->setAlpha(p[0x265]);
    ((Pane803E4650*)(*(J2DPane**)(p+8))->search(*b))->setAlpha(p[0x266]);
    ((Pane803E4650*)(*(J2DPane**)(p+8))->search(*c))->setAlpha(p[0x267]);
}
static inline f32 MenuPulse803E(s32 n,const f32 magnitude,const f32 denominator,const f32 base) {
    f32 value=(f32)(n*n);
    return magnitude*(value/denominator)+base;
}
static inline f32 MenuCenterAxis803E(J2DPane* root,J2DPane* screen,u64 tag,int axis) {
    f32 size;
    f32 offset;
    J2DPane* pane=screen->search(0x4e554c4c5f303031ULL);
    size=axis ? pane->getHeight() : pane->getWidth();
    pane=root->search(tag);
    offset=getBounds__7J2DPaneFv(root->search(tag))[axis];
    f32 origin=getBounds__7J2DPaneFv(root->search(0x4e554c4c5f303031ULL))[axis];
    f32 span=axis ? pane->getHeight() : pane->getWidth();
    return (span-size)*lbl_80543658+(origin+offset);
}
static inline f32 MenuCenter803E(const f32 half,const f32 size,const f32 span,const f32 origin) {return (span-size)*half+origin;}
static inline void MenuMove803E(J2DPane* screen,u64 tag,f32 x,f32 y) { screen->search(tag)->move(x,y); }

#pragma opt_common_subs off
extern "C" void fn_803E51C4(void* param_1) {
    u8* p=(u8*)param_1;
    f32 x,y,size;
    JGeometry::TVec3f pos;
    JGeometry::TBox2f box;
    const u8* base=lbl_80477970;
    {
    u8* q=p;
    const u64* a=(u64*)(base+0x8a0);
    const u64* b=(u64*)(base+0x840);
    const u64* c=(u64*)(base+0x860);
    const u64* d=(u64*)(base+0x880);
    s32 mask;
    s32 i;
    for(i=0;i<4;i++,a++,b++,c++,d++,q+=4) {
        mask=1<<(i+4);
        if(MenuEnabled803E(i)&1) {
            s32 v=*(s32*)(q+0x220);
            s32 alpha;
            if(v==0) {p[0x26b]&=~(1<<i);alpha=0;}
            else if(v<36) alpha=lbl_80543690*((f32)(v*v)/lbl_805436CC);
            else {
                if(*(s16*)(p+0x25e)==0) p[0x26b]|=1<<i;
                if(p[0x26b]&(1<<i)) {
                    s16 t=*(s16*)(p+0x25e);
                    if(t<50) {s32 n=t;alpha=((f32)(n*n)/lbl_805436D4)*lbl_805436D0+lbl_80543690;}
                    else {s32 n=50-(t-50);alpha=((f32)(n*n)/lbl_805436D4)*lbl_805436D0+lbl_80543690;}
                } else alpha=150;
            }
            ((Pane803E4650*)(*(J2DPane**)(p+8))->search(*a))->setAlpha(alpha);
            if(p[0x26b]&mask) {p[0x26b]&=~mask;MenuRestore803E(p,b,c,d);}
        } else {
            ((Pane803E4650*)(*(J2DPane**)(p+8))->search(*a))->setAlpha(0);
            if(fn_8030A388(lbl_8053AD30,fn_8030AAF4(i))) {
                if(!(p[0x26b]&mask)&&*(s16*)(p+0x25c)==50) p[0x26b]|=mask;
                if(p[0x26b]&mask) {
                    s16 t=*(s16*)(p+0x25c);
                    if(t<50) {s32 n=t;x=(f32)(n*n)/lbl_805436D4;}
                    else {s32 n=50-(t-50);x=(f32)(n*n)/lbl_805436D4;}
                    ((Pane803E4650*)(*(J2DPane**)(p+8))->search(*b))->setAlpha((f32)p[0x265]*x);
                    ((Pane803E4650*)(*(J2DPane**)(p+8))->search(*c))->setAlpha((f32)p[0x266]*x);
                    ((Pane803E4650*)(*(J2DPane**)(p+8))->search(*d))->setAlpha((f32)p[0x267]*x);
                }
            } else if(p[0x26b]&mask) {p[0x26b]&=~mask;MenuRestore803E(p,b,c,d);}
        }
    }
    }
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p+8),lbl_80543664,lbl_80543664,((void**)lbl_8053AB10)[4]);
    if(*(s32*)(p+0x1d4)!=5) {
        if(*(s32*)(p+0x230)==0&&*(s32*)(p+0x234)==0&&*(s32*)(p+0x238)==0&&*(s32*)(p+0x23c)==0) {
            *(s16*)(p+0x250)=MenuNext803E(*(s16*)(p+0x250),*(s32*)(p+0x1bc)+1);
            if(*(s16*)(p+0x250)!=-1) ((MenuFrame803E*)p)->frame230[*(s16*)(p+0x250)].frame++;
        }
        if(*(s32*)(p+0x240)==0&&*(s32*)(p+0x244)==0&&*(s32*)(p+0x248)==0&&*(s32*)(p+0x24c)==0) {
            *(s16*)(p+0x252)=MenuNext803E(*(s16*)(p+0x252),*(s32*)(p+0x1bc)+1);
            if(*(s16*)(p+0x252)!=-1) ((MenuFrame803E*)p)->frame240[*(s16*)(p+0x252)].frame++;
        }
    }
    {
    u8* q=p;
    const u64* a=(u64*)(base+0x960);
    const u64* b=(u64*)(base+0x980);
    const u64* c=(u64*)(base+0x8e0);
    s32 i;
    for(i=0;i<*(s32*)(p+0x1bc)+1;q+=4,a++,b++,c+=4,i++) {

        if(*(s32*)(q+0x230)!=0) {
            ++*(s32*)(q+0x230);
            if(*(s32*)(q+0x230)>=*(s16*)(*(u8**)(q+0x38)+6)) *(s32*)(q+0x230)=0;
            *(f32*)(*(u8**)(q+0x38)+8)=(f32)*(s32*)(q+0x230);
            (*(J2DPane**)(q+0x18))->search(0x4e554c4c5f303031ULL)->animationTransform();
            if(i==*(s16*)(p+0x250) && *(s32*)(q+0x230)==*(s16*)(*(u8**)(q+0x38)+6)-10) {
                s16 old=*(s16*)(p+0x250);
                s16 next=MenuNext803E(old,*(s32*)(p+0x1bc)+1);
                if(next!=-1 && old!=next) {
                    *(s16*)(p+0x250)=next;
                    u8* r=p+next*4;
                    ((MenuFrame803E*)r)->frame230[0].frame++;
                    *(f32*)(*(u8**)(q+0x38)+8)=(f32)*(s32*)(r+0x230);
                    (*(J2DPane**)(r+0x18))->search(0x4e554c4c5f303031ULL)->animationTransform();
                }
            }
        }

        if(*(s32*)(q+0x240)!=0) {
            ++*(s32*)(q+0x240);
            if(*(s32*)(q+0x240)>=*(s16*)(*(u8**)(q+0x48)+6)) *(s32*)(q+0x240)=0;
            *(f32*)(*(u8**)(q+0x48)+8)=(f32)*(s32*)(q+0x240);
            (*(J2DPane**)(q+0x28))->search(0x4e64617461793030ULL)->animationTransform();
            if(i==*(s16*)(p+0x252) && *(s32*)(q+0x240)==*(s16*)(*(u8**)(q+0x48)+6)-10) {
                s16 old=*(s16*)(p+0x252);
                s16 next=MenuNext803E(old,*(s32*)(p+0x1bc)+1);
                if(next!=-1 && old!=next) {
                    *(s16*)(p+0x252)=next;
                    u8* r=p+next*4;
                    ((MenuFrame803E*)r)->frame240[0].frame++;
                    *(f32*)(*(u8**)(q+0x48)+8)=(f32)*(s32*)(r+0x240);
                    (*(J2DPane**)(r+0x28))->search(0x4e64617461793030ULL)->animationTransform();
                }
            }
        }


        size=(*(J2DPane**)(q+0x18))->search(0x4e554c4c5f303031ULL)->getWidth();
        J2DPane* pane=(*(J2DPane**)(p+8))->search(*a);
        y=getBounds__7J2DPaneFv((*(J2DPane**)(p+8))->search(*a))[0];
        f32 root=getBounds__7J2DPaneFv((*(J2DPane**)(p+8))->search(0x4e554c4c5f303031ULL))[0];
        {f32 origin=root+y;f32 delta=pane->getWidth()-size;x=delta*lbl_80543658+origin;}
        size=(*(J2DPane**)(q+0x18))->search(0x4e554c4c5f303031ULL)->getHeight();
        pane=(*(J2DPane**)(p+8))->search(*a);
        y=getBounds__7J2DPaneFv((*(J2DPane**)(p+8))->search(*a))[1];
        root=getBounds__7J2DPaneFv((*(J2DPane**)(p+8))->search(0x4e554c4c5f303031ULL))[1];
        {f32 origin=root+y;f32 delta=pane->getHeight()-size;y=delta*lbl_80543658+origin;}
        MenuMove803E(*(J2DPane**)(q+0x18),0x4e554c4c5f303031ULL,x,y);
        y=getBounds__7J2DPaneFv((*(J2DPane**)(p+8))->search(*b))[0];
        root=getBounds__7J2DPaneFv((*(J2DPane**)(p+8))->search(0x004e646174613033ULL))[0];
        x=root+y;
        size=getBounds__7J2DPaneFv((*(J2DPane**)(q+0x28))->search(0x0050636361613030ULL))[1];
        y=getBounds__7J2DPaneFv((*(J2DPane**)(p+8))->search(*b))[1];
        root=getBounds__7J2DPaneFv((*(J2DPane**)(p+8))->search(0x004e646174613033ULL))[1];
        y=root+y;
        root=getBounds__7J2DPaneFv((*(J2DPane**)(p+8))->search(c[1]))[1];
        y=(root+y)-size;
        MenuMove803E(*(J2DPane**)(q+0x28),0x4e64617461793030ULL,x,y);
        draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(q+0x28),lbl_80543664,lbl_80543664,((void**)lbl_8053AB10)[4]);
        if(*(s32*)(p+0x1d4)!=5 && !(lbl_8053AAF8[0x82]&(u8)(1<<(i+4))))
            draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(q+0x18),lbl_80543664,lbl_80543664,((void**)lbl_8053AB10)[4]);
    }
    }
    box.set(lbl_80543664,lbl_80543664,lbl_805436D8,lbl_805436DC);
    fn_8013B414(lbl_8053AB10,&box,1);
    u8* row=p;
    const u64* a=(u64*)(base+0x820);
    const u64* b=(u64*)(base+0x530);
    u8* q=p;
    s32 i;
    for(i=0;i<4;i++,b+=9,row+=9,q+=4,a++) {
        DrawRec rec;
        rec.b26=0;
        J2DPane* pane=(*(J2DPane**)(p+8))->search(*a);
        f32 size=pane->getWidth();
        pane=(*(J2DPane**)(p+8))->search(*a);
        pos.x=lbl_805436D8*(size*lbl_80543658+*(f32*)((u8*)pane+0x30))/(f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo+4)+4);
        pane=(*(J2DPane**)(p+8))->search(*a);
        size=pane->getHeight();
        pane=(*(J2DPane**)(p+8))->search(*a);
        pos.y=lbl_805436DC*(lbl_80543660+(size*lbl_80543658+*(f32*)((u8*)pane+0x34)))/(f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo+4)+6);
        pos.z=lbl_80543664;
        rec.ids[7]=i+12;
        u8 alpha=((u8*)(*(J2DPane**)(p+8))->search(*b))[0xb2];
        f32 ratio=(f32)alpha/(f32)row[0x2fe];
        if(!(lbl_8053AAF8[0x82]&(u8)(1<<(i+4)))||*(s32*)(q+0x220)==0) {
            if(i>*(s32*)(p+0x1bc)) {
                ((u8*)&rec.w10)[0]=0x80;((u8*)&rec.w10)[1]=0x80;((u8*)&rec.w10)[2]=0x80;
                ((u8*)&rec.w10)[3]=(u8)(lbl_805436E0*ratio);
            } else ((u8*)&rec.w10)[3]=(u8)(lbl_80543650*ratio);
            MenuSprite803E(pos,0x10,rec,base);
        } else {
            s32 v=*(s32*)(q+0x220);
            ((u8*)&rec.w10)[3]=(u8)(lbl_80543650*ratio);
            if(v<=10) MenuSprite803E(pos,0xdb,rec,base);
            else if(v<=36) MenuSprite803E(pos,(v-10)/2+0xdb,rec,base);
            else if(v<100) MenuSprite803E(pos,0xe8,rec,base);
            else MenuSprite803E(pos,((s32*)(base+0x40))[v-100]+0x10,rec,base);
        }
    }
    fn_8013B490(lbl_8053AB10);
    if(*(s32*)(p+0x1d4)==8) fn_804316EC(lbl_8053AEC0);
    fn_80440EE8(lbl_8053AED8);
}
#pragma opt_common_subs reset
extern "C" void fn_803E64A0(u8* p) {
    s32 i;
    s32 k;
    s32 n;
    s32 st;
    f32 u;
    f32 f31;
    f32 f30;
    f32 off;
    f32 h;
    f32 h2;
    u8* q;
    const u8* base = lbl_80477970;
    s32* tA;
    s32* tB;
    s32* tC;
    Pane803E4650* pane;

    st = *(s32*)(p + 0x1d4);
    if (st != 4) {
        n = *(s32*)(p + 0x1e0);
        if (n < 30) {
            u = (f32)(n * n) / 900.0f;
        } else {
            n -= 30;
            u = 1.0f - (f32)(n * n) / 900.0f;
        }
        f30 = u * (f32)p[0x268];
    } else {
        n = *(s32*)(p + 0x1e0);
        if (n < 15) {
            u = (f32)(n * n) / 225.0f;
        } else {
            u = (f32)((n - 15) * (n - 15)) / 225.0f;
        }
        f30 = 230.0f * u;
    }
    if (st == 3 || (st == 4 && *(s16*)(p + 0x254) <= 10)) {
        k = *(s16*)(p + 0x254);
        if (k >= 5) {
            k = 10 - k;
        }
    } else {
        k = 0;
    }
    f31 = 80.0f * u;
    off = (5.0f * (f32)(k * k)) / 25.0f;
    q = p;
    tA = (s32*)(base + 0xea8);
    tB = (s32*)(base + 0xec8);
    tC = (s32*)(base + 0xee8);
    for (i = 0; i < 4; i++, tA += 2, tB += 2, tC += 2, q += 4) {
        if (i == *(s32*)(p + 0x1bc)) {
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 4))->search(*(u64*)tA);
            h = getBounds__7J2DPaneFv(pane)[0];
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 4))->search(*(u64*)tA);
            pane->v10(h, *(f32*)(q + 0x110) + off);
            if (i == 0) {
                pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 4))->search(((u64)0x50736375 << 32) | 0x726f3032);
                h = getBounds__7J2DPaneFv(pane)[0];
                pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 4))->search(((u64)0x50736375 << 32) | 0x726f3032);
                pane->v10(h, *(f32*)(p + 0x1a0) + off);
            } else {
                h = getBounds__7J2DPaneFv((Pane803E4650*)((J2DPane*)*(void**)(p + 4))->search(*(u64*)(base + 0xea8)))[1];
                h2 = getBounds__7J2DPaneFv((Pane803E4650*)((J2DPane*)*(void**)(p + 4))->search(*(u64*)tA))[1];
                h2 = (*(f32*)(p + 0x1a0) + h2) - h;
                pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 4))->search(((u64)0x50736375 << 32) | 0x726f3032);
                h = getBounds__7J2DPaneFv(pane)[0];
                pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 4))->search(((u64)0x50736375 << 32) | 0x726f3032);
                pane->v10(h, h2);
            }
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 4))->search(*(u64*)tB);
            *((u8*)pane + 0xb0) = 0;
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 4))->search(*(u64*)tC);
            *((u8*)pane + 0xb0) = 1;
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 4))->search(*(u64*)tC);
            pane->setAlpha((int)f31);
        } else {
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 4))->search(*(u64*)tA);
            h = getBounds__7J2DPaneFv(pane)[0];
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 4))->search(*(u64*)tA);
            pane->v10(h, *(f32*)(q + 0x110));
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 4))->search(*(u64*)tB);
            *((u8*)pane + 0xb0) = 1;
            pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 4))->search(*(u64*)tC);
            *((u8*)pane + 0xb0) = 0;
        }
    }
    pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 4))->search(((u64)0x50736375 << 32) | 0x726f3031);
    pane->setAlpha((int)f30);
    pane = (Pane803E4650*)((J2DPane*)*(void**)(p + 4))->search(((u64)0x50736375 << 32) | 0x726f3032);
    pane->setAlpha((int)f30);
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p + 4), 0.0f, 0.0f, *(void**)((u8*)lbl_8053AB10 + 0x10));
    fn_80440EE8(lbl_8053AED8);
}

#pragma opt_common_subs reset
#pragma opt_loop_invariants reset
#pragma opt_propagation reset
extern "C" void fn_803E6A28(void) {}

extern "C" void fn_803E6A2C(u8* param_1) {
    if (fn_804366B8(*(void**)(param_1 + 0x5c)) != 0) {
        if (param_1[0x26e] == 0) {
            *(s32*)(param_1 + 0x1dc) = 9;
            param_1[0x26e] = 1;
        }
        if (*(s32*)(param_1 + 0x1bc) == 0) {
            *(s32*)(param_1 + 0x1b8) = 1;
        } else {
            *(s32*)(param_1 + 0x1b8) = 0;
        }
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
}

void fn_803E6AB0(void)
{
}

extern "C" void fn_803E8210(u8* p) {
    s32 t;
    u8* q;
    u8 a;
    u8 b;
    u8 c;
    s32 i;

    a = 0;
    b = 0;
    c = 0;
    *(s16*)(p + 0x260) = *(s16*)(p + 0x260) + 1;
    if (*(s16*)(p + 0x260) > 0) {
        a = fn_80402940(*(void**)(p + 0x64), 0x16, -200.0f, 0.0f, 0);
    }
    if (*(s16*)(p + 0x260) > 0x10) {
        b = fn_80402940(*(void**)(p + 0x78), 0x18, -200.0f, 0.0f, 0);
    }
    q = p;
    i = 0;
    t = 4;
    for (; i < 4; i++, q += 4) {
        if (i <= *(s32*)(p + 0x1bc) && *(s16*)(p + 0x260) > t) {
            c = fn_80402940(*(void**)(q + 0x68), 0x12, 150.0f, 0.0f, 0);
        }
        t += 5;
    }
    if (a != 0 && b != 0 && c != 0) {
        *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
        *(s32*)(p + 0x1d4) = 0xd;
    }
}

#pragma opt_common_subs off
extern "C" void fn_803E831C(u8* p) {
    u8* tbl = (u8*)lbl_80477970;
    s32 i;
    s32 val;
    Pane803E4650* pane;
    f32 v;

    if (*(s32*)(p + 0x1bc) != 3) {
        if (*(s32*)(p + 0x220) < 0x64) {
            *(s32*)(p + 0x220) = 0;
        } else if (*(s32*)(p + 0x220) < 0x70) {
            *(s32*)(p + 0x220) += 1;
        } else if (*(s32*)(p + 0x220) < 0xd4) {
            *(s32*)(p + 0x220) = 0x70;
        } else {
            *(s32*)(p + 0x220) += 1;
            if (*(s32*)(p + 0x220) >= 0xe0) {
                *(s32*)(p + 0x220) = 0;
            }
        }
    }

    *(s16*)(p + 0x254) += 1;
    if (*(s16*)(p + 0x254) > 0x14) {
        if (*(s16*)(p + 0x254) < 0x1c) {
            s32 d=*(s16*)(p+0x254)-20;
 *(f32*)(p+0x164)=MenuSlideExit803E(d,lbl_8054368C,lbl_805436E8);
            v = (f32)(8 - (*(s16*)(p + 0x254) - 0x14)) * lbl_805436EC;
            if (v < lbl_80543664) {
                v = lbl_80543664;
            }
            else if (v > lbl_80543668) {
                v = lbl_80543668;
            }
            u64* names=(u64*)(tbl+0x650);s32 j;
            for (j = 0; j < 0x11; j++,names++) {
                pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*names);
                f32 value=p[0x322+j];value*=v;val=(s32)value;
                pane->setAlpha(val);
            }
        } else {
            *(f32*)(p + 0x164) = lbl_8054368C;
            u64* names=(u64*)(tbl+0x650);s32 j;
            for (j = 0; j < 0x11; j++,names++) {
                pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*names);
                f32 value=p[0x322+j];value*=lbl_80543664;val=(s32)value;
                pane->setAlpha(val);
            }
        }
    }

 if(*(s16*)(p+0x254)>0){
 if(*(s16*)(p+0x254)<10){s32 t=*(s16*)(p+0x254);*(f32*)(p+0x168)=lbl_8054368C*((f32)(t*t)/lbl_805436F0);}
 else *(f32*)(p+0x168)=lbl_8054368C;
 }
 s16 ids[2];s16* id=ids;s16* write=id;
 for(s32 j=0;j<3;j++){if(j!=*(s32*)(p+0x1b8))*write++=j;}
 if(*(s32*)(p+0x1dc)==2){
 long lo;int hi;u8* offsets;s32 lo2;u8* bytes;u64* keys;s32 group;
group=0;
 for(;group<3;group++){
lo=(long)group*10;hi=(int)group*10+10;offsets=p+group*4;lo2=group*30;bytes=p+group*5;keys=(u64*)(tbl+0x6d8)+group*5;
 if(*(s16*)(p+0x254)>lo){
 if(*(s16*)(p+0x254)<hi){
 s32 d=*(s16*)(p+0x254)-lo;
 *(f32*)(offsets+0x184)=MenuSlide803E(d,lbl_80543694,lbl_805436F0);
 v=(f32)(10-(*(s16*)(p+0x254)-lo2))/lbl_805436F4;
 if(v<lbl_80543664)v=lbl_80543664;else if(v>lbl_80543668)v=lbl_80543668;
 u8* alpha=bytes;u64* name=keys;
 for(i=0;i<5;i++,alpha++,name++){pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*name);f32 value=alpha[0x333];value*=v;pane->setAlpha((s32)value);}
 }else{
 *(f32*)(offsets+0x184)=lbl_80543694;
 u8* alpha=bytes;u64* name=keys;
 for(i=0;i<5;i++,alpha++,name++){pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*name);f32 value=alpha[0x333];value*=lbl_80543664;pane->setAlpha((s32)value);}
 }}}
 }else{
 s32 group;long lo;int hi;s32 lo2;
group=0;
 for(;group<2;group++,id++){
lo=(long)group*10;hi=(int)group*10+10;lo2=group*30;
 if(*(s16*)(p+0x254)>lo){
 if(*(s16*)(p+0x254)<hi){
 s32 d=*(s16*)(p+0x254)-lo;
 s32 idx=*id; s32 cell=idx*4+0x184;
 ((f32*)p)[idx+0x61]=MenuSlide803E(d,lbl_80543694,lbl_805436F0);
 v=(f32)(10-(*(s16*)(p+0x254)-lo2))/lbl_805436F4;
 if(v<lbl_80543664)v=lbl_80543664;else if(v>lbl_80543668)v=lbl_80543668;
 s32 alphaOffset=idx*5;
 u8* alpha;u64* name=(u64*)(tbl+0x6d8);
 alpha=p+alphaOffset;
 name+=idx*5;
 for(s32 j=0;j<5;j++,alpha++,name++){pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*name);f32 value=alpha[0x333];value*=v;pane->setAlpha((s32)value);}
 }else{
 s32 idx=*id; s32 cell=idx*4+0x184;
 ((f32*)p)[idx+0x61]=lbl_80543694;
 s32 alphaOffset=idx*5;
 u64* name=(u64*)(tbl+0x6d8);
 u8* alpha=p+alphaOffset;
 name+=idx*5;
 for(s32 j=0;j<5;j++,alpha++,name++){pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*name);f32 value=alpha[0x333];value*=lbl_80543664;pane->setAlpha((s32)value);}
 }}}
 if(*(s16*)(p+0x254)>15){
 if(*(s16*)(p+0x254)<23){
 s32 d=*(s16*)(p+0x254)-15;
 ((f32*)(p+0x184))[*(s32*)(p+0x1b8)]=MenuSlideExit803E(d,lbl_80543694,lbl_805436E8);
 s32 idx=*(s32*)(p+0x1b8);
 v=(f32)(8-(*(s16*)(p+0x254)-15))*lbl_805436EC;
 if(v<lbl_80543664)v=lbl_80543664;else if(v>lbl_80543668)v=lbl_80543668;
 s32 alphaOffset=idx*5;
 u64* name=(u64*)(tbl+0x6d8);
 u8* alpha=p+alphaOffset;
 name+=idx*5;
 for(s32 j=0;j<5;j++,alpha++,name++){pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*name);f32 value=alpha[0x333];value*=v;pane->setAlpha((s32)value);}
 }else{
 s32 idx=*(s32*)(p+0x1b8);
 ((f32*)(p+0x184))[idx]=lbl_80543694;
 idx=*(s32*)(p+0x1b8);
 s32 alphaOffset=idx*5;
 u64* name=(u64*)(tbl+0x6d8);
 u8* alpha=p+alphaOffset;
 name+=idx*5;
 for(s32 j=0;j<5;j++,alpha++,name++){pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*name);f32 value=alpha[0x333];value*=lbl_80543664;pane->setAlpha((s32)value);}
 }}
 }

 if(*(s16*)(p+0x254)>15){
 if(*(s16*)(p+0x254)<23){
 s32 d=*(s16*)(p+0x254)-15;
 *(f32*)(p+0x198)=MenuSlideExit803E(d,lbl_80543698,lbl_805436E8);
 v=(f32)(8-(*(s16*)(p+0x254)-15))*lbl_805436EC;
 if(v<lbl_80543664)v=lbl_80543664;else if(v>lbl_80543668)v=lbl_80543668;
 u64* names=(u64*)(tbl+0x750);for(i=0;i<26;i++,names++){pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*names);f32 value=p[0x342+i];value*=v;pane->setAlpha((s32)value);}
 }else{
 *(f32*)(p+0x198)=lbl_80543698;
 u64* names=(u64*)(tbl+0x750);for(i=0;i<26;i++,names++){pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(*names);f32 value=p[0x342+i];value*=lbl_80543664;pane->setAlpha((s32)value);}
 }}
 if(*(s16*)(p+0x254)>=48){
 if(*(s32*)(p+0x1dc)==2) *(s32*)(p+0x360)=6;
 else if(*(s32*)(p+0x1bc)==0){
 if(*(s32*)(p+0x1b8)==1) *(s32*)(p+0x360)=6;
 else if(*(s32*)(p+0x1b8)==1) {if(p[0x26e]==0){*(s32*)(p+0x1dc)=1;p[0x26e]=1;}}
 else {if(p[0x26e]==0){*(s32*)(p+0x1dc)=14;p[0x26e]=1;}}
 }else{
 if(*(s32*)(p+0x1b8)==0) *(s32*)(p+0x360)=6;
 else if(*(s32*)(p+0x1b8)==1) {if(p[0x26e]==0){*(s32*)(p+0x1dc)=12;p[0x26e]=1;}}
 else {if(p[0x26e]==0){*(s32*)(p+0x1dc)=14;p[0x26e]=1;}}
 }
 *(s16*)(p+0x254)=0;
 }
 *(s32*)(p+0x1e0)+=1;
 if(*(s32*)(p+0x1e0)>=30)*(s32*)(p+0x1e0)=0;
 pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(0x506d616462623037ULL);
 pane->v10(*(f32*)(p+0x15c),*(f32*)(p+0x160)+*(f32*)(p+0x164));
 fn_80402E08(*(void**)(p+0x78),lbl_80543664,*(f32*)(p+0x168));
 pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(0x0050737461623034ULL);
 pane->v10(*(f32*)(p+0x16c)+*(f32*)(p+0x184),*(f32*)(p+0x178));
 pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(0x005068616e623034ULL);
 pane->v10(*(f32*)(p+0x170)+*(f32*)(p+0x188),*(f32*)(p+0x17c));
 pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(0x507275623034ULL);
 pane->v10(*(f32*)(p+0x174)+*(f32*)(p+0x18c),*(f32*)(p+0x180));
 pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(0x506c69626b6b3033ULL);
 pane->v10(*(f32*)(p+0x190)+*(f32*)(p+0x198),*(f32*)(p+0x194));
 pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(0x50736375726f3032ULL);
 f32 h=getBounds__7J2DPaneFv(pane)[1];
 pane=(Pane803E4650*)(*(J2DPane**)(p+0xc))->search(0x50736375726f3032ULL);
 pane->v10(*(f32*)(p+0x1a4)+((f32*)(p+0x184))[*(s32*)(p+0x1b8)],h);
}
#pragma opt_common_subs reset

extern "C" void fn_803E9034(u8* p) {
	s32 n;
	s32 t = *(s16*)(p + 0x254);
	if (t != 0) {
		*(s16*)(p + 0x254) = t + 1;
		if (*(s16*)(p + 0x254) > 10) {
			*(s16*)(p + 0x254) = 0;
		}
	}
	*(s32*)(p + 0x220) = *(s32*)(p + 0x220) + 1;
	if (*(s32*)(p + 0x220) >= 0x1e) {
		*(s32*)(p + 0x220) = 0;
	}
	n = *(s32*)(p + 0x1bc);
	if (*(s32*)(p + 0x1d0) != n + 1 && n > 0) {
		p[0x26c] = 0xff;
		(((T803ED83C*)p)->*lbl_804B0754[5])();
	} else {
		if (fn_80309C4C(lbl_8053AD30, 0x1100, lbl_80529DEC[0x23c] + 1) != 0) {
			if (*(s32*)(p + 0x1b8) < 3) {
				*(s32*)(p + 0x1dc) = 0xf;
				fn_803E3320(p);
			}
			fn_80458880(lbl_8053AF80, 0xb, -1);
		} else if (fn_80309C4C(lbl_8053AD30, 0x200, lbl_80529DEC[0x23c] + 1) != 0) {
			*(s32*)(p + 0x1dc) = 2;
			(((T803ED83C*)p)->*lbl_804B0754[11])();
			fn_80458880(lbl_8053AF80, 0xc, -1);
		} else if (fn_80309A9C(lbl_8053AD30, 4, lbl_80529DEC[0x23c] + 1) != 0) {
			*(s32*)(p + 0x1b8) = *(s32*)(p + 0x1b8) + 1;
			if (*(s32*)(p + 0x1b8) >= 3) {
				*(s32*)(p + 0x1b8) = 0;
			}
			*(s16*)(p + 0x254) = 1;
			*(s32*)(p + 0x1e0) = 0x1e;
			fn_80458880(lbl_8053AF80, 0x26, -1);
		} else if (fn_80309A9C(lbl_8053AD30, 8, lbl_80529DEC[0x23c] + 1) != 0) {
			*(s32*)(p + 0x1b8) = *(s32*)(p + 0x1b8) - 1;
			if (*(s32*)(p + 0x1b8) < 0) {
				*(s32*)(p + 0x1b8) = 2;
			}
			*(s16*)(p + 0x254) = 1;
			*(s32*)(p + 0x1e0) = 0x1e;
			fn_80458880(lbl_8053AF80, 0x26, -1);
		}
	}
	*(s32*)(p + 0x1e0) = *(s32*)(p + 0x1e0) + 1;
	if (*(s32*)(p + 0x1e0) >= 0x3c) {
		*(s32*)(p + 0x1e0) = 0;
	}
}

#pragma optimization_level 3
#pragma opt_common_subs off
extern "C" void fn_803E926C(u8* p) {
    u8* base = lbl_80477970;
    int i;
    J2DPane* pane;
    f32 t;
    s32 frame;
    *(s16*)(p + 0x254) += 1;
    frame = *(s16*)(p + 0x254);
    if (frame > 0) {
        if (frame < 25) {
            s32 d = 25 - frame;
            *(f32*)(p + 0x164) = MenuSlide803E(d, lbl_8054368C, lbl_805436F8);
            t = (f32)*(s16*)(p + 0x254) / lbl_805436C0;
            if (t < lbl_80543664) t = lbl_80543664;
            else if (t > lbl_80543668) t = lbl_80543668;
            u64* names = (u64*)(base + 0x650);
            for (i = 0; i < 17; i++, names++) {
                pane = (*(J2DPane**)(p + 0xc))->search(*names);
                f32 value = p[0x322 + i];
                value *= t;
                pane->setAlpha((u8)value);
            }
        } else {
            *(f32*)(p + 0x164) = lbl_80543664;
            u64* names = (u64*)(base + 0x650);
            for (i = 0; i < 17; i++, names++) {
                pane = (*(J2DPane**)(p + 0xc))->search(*names);
                f32 value = p[0x322 + i];
                value *= lbl_80543668;
                pane->setAlpha((u8)value);
            }
        }
    }
    if (*(s16*)(p + 0x254) > 25) {
        if (*(s16*)(p + 0x254) < 45) {
            s32 d = 20 - (*(s16*)(p + 0x254) - 25);
            *(f32*)(p + 0x168) = MenuSlide803E(d, lbl_8054368C, lbl_805436B0);
        } else *(f32*)(p + 0x168) = lbl_80543664;
    }
    long lo;
    int hi;
    u8* offsets;
    int lo2;
    u8* bytes;
    u64* keys;
    int group;
    group = 0;
    for (; group < 3; group++) {
        lo = (long)group * 10;
        hi = (int)group * 10 + 15;
        offsets = p + group * 4;
        lo2 = group * 10;
        bytes = p + group * 5;
        keys = (u64*)(base + 0x6d8) + group * 5;
        if (*(s16*)(p + 0x254) > lo) {
            if (*(s16*)(p + 0x254) < hi) {
                s32 d = 15 - (*(s16*)(p + 0x254) - lo2);
                *(f32*)(offsets + 0x184) = MenuSlide803E(d, lbl_80543694, lbl_805436C4);
                t = (f32)(*(s16*)(p + 0x254) - lo2) / lbl_805436FC;
                if (t < lbl_80543664) t = lbl_80543664;
                else if (t > lbl_80543668) t = lbl_80543668;
                u8* alpha = bytes;
                u64* names = keys;
                for (i = 0; i < 5; i++, alpha++, names++) {
                    pane = (*(J2DPane**)(p + 0xc))->search(*names);
                    f32 value = alpha[0x333];
                    value *= t;
                    pane->setAlpha((u8)value);
                }
            } else {
                *(f32*)(offsets + 0x184) = lbl_80543664;
                u8* alpha = bytes;
                u64* names = keys;
                for (i = 0; i < 5; i++, alpha++, names++) {
                    pane = (*(J2DPane**)(p + 0xc))->search(*names);
                    f32 value = alpha[0x333];
                    value *= lbl_80543668;
                    pane->setAlpha((u8)value);
                }
            }
        }
    }
    frame = *(s16*)(p + 0x254);
    if (frame > 0) {
        if (frame < 15) {
            s32 d = 15 - frame;
            *(f32*)(p + 0x198) = MenuSlide803E(d, lbl_80543698, lbl_805436C4);
            t = (f32)*(s16*)(p + 0x254) / lbl_805436FC;
            if (t < lbl_80543664) t = lbl_80543664;
            else if (t > lbl_80543668) t = lbl_80543668;
            u64* names = (u64*)(base + 0x750);
            for (i = 0; i < 26; i++, names++) {
                pane = (*(J2DPane**)(p + 0xc))->search(*names);
                f32 value = p[0x342 + i];
                value *= t;
                pane->setAlpha((u8)value);
            }
        } else {
            *(f32*)(p + 0x198) = lbl_80543664;
            u64* names = (u64*)(base + 0x750);
            for (i = 0; i < 26; i++, names++) {
                pane = (*(J2DPane**)(p + 0xc))->search(*names);
                f32 value = p[0x342 + i];
                value *= lbl_80543668;
                pane->setAlpha((u8)value);
            }
        }
    }
    if (*(s16*)(p + 0x254) >= 75) {
        *(s16*)(p + 0x254) = 0;
        if (*(s32*)(p + 0x1bc) == 0) {
            *(s32*)(p + 0x1e0) = 0;
            *(s16*)(p + 0x254) = 0;
            *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
            *(s32*)(p + 0x1d4) = 0;
        } else {
            *(s16*)(p + 0x254) = 0;
            *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
            *(s32*)(p + 0x1d4) = 10;
        }
    }

    pane = (*(J2DPane**)(p + 0xc))->search(0x506d616462623037ULL);
    pane->move(*(f32*)(p + 0x15c), *(f32*)(p + 0x160) + *(f32*)(p + 0x164));
    fn_80402E08(*(void**)(p + 0x78), lbl_80543664, *(f32*)(p + 0x168));

    pane = (*(J2DPane**)(p + 0xc))->search(0x50737461623034ULL);
    pane->move(*(f32*)(p + 0x16c) + *(f32*)(p + 0x184), *(f32*)(p + 0x178));

    pane = (*(J2DPane**)(p + 0xc))->search(0x5068616e623034ULL);
    pane->move(*(f32*)(p + 0x170) + *(f32*)(p + 0x188), *(f32*)(p + 0x17c));

    pane = (*(J2DPane**)(p + 0xc))->search(0x507275623034ULL);
    pane->move(*(f32*)(p + 0x174) + *(f32*)(p + 0x18c), *(f32*)(p + 0x180));

    pane = (*(J2DPane**)(p + 0xc))->search(0x506c69626b6b3033ULL);
    pane->move(*(f32*)(p + 0x190) + *(f32*)(p + 0x198), *(f32*)(p + 0x194));

    pane = (*(J2DPane**)(p + 0xc))->search(0x50736375726f3032ULL);
    t = getBounds__7J2DPaneFv(pane)[1];
    pane = (*(J2DPane**)(p + 0xc))->search(0x50736375726f3032ULL);
    pane->move(*(f32*)(p + 0x1a4), t);
}
#pragma opt_common_subs reset
#pragma optimization_level reset
extern "C" s32 fn_804317AC(void*);
extern "C" s32 fn_80431740(void*);
extern "C" void fn_8013CC50(s32, f32*, s32, s32, s32, s32, s32, s32, f32);
extern "C" u8* sManager__8JUTVideo;
extern "C" const u64 lbl_80478190[];
extern const f32 lbl_80543658;
extern const f32 lbl_80543660;
extern const f32 lbl_80543664;
extern const f32 lbl_80543668;
extern const f32 lbl_805436D8;
extern const f32 lbl_805436DC;
extern const f32 lbl_80543700;
extern const f32 lbl_80543704;
extern "C" void fn_803E9A20(u8* p) {
    s32 i;
    f32 span;
    void* r;
    u32 t1;
    u32 t2;
    JGeometry::TVec3f v1;
    JGeometry::TVec3f v2;

    switch (p[0x26c]) {
    case 0:
        if (fn_804317AC(lbl_8053AEC0)) {
            p[0x26c] = 1;
        }
        break;
    case 2:
        if (fn_80431740(lbl_8053AEC0)) {
            p[0x26c] = 0;
            *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
            *(s32*)(p + 0x1d4) = 7;
        }
        break;
    case 1:
    default:
        if (*(s32*)(p + 0x1d0) == *(s32*)(p + 0x1bc) + 1) {
            p[0x26c] = 2;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else if ((lbl_8053AAF8[0x82] & 0x10) && fn_8030A308(lbl_8053AD30, fn_8030AAF4(0))) {
            if (fn_80309C4C(lbl_8053AD30, 0x1100, lbl_80529DEC[0x23c] + 1)) {
                p[0x26c] = 2;
                fn_80458880(lbl_8053AF80, 0xb, -1);
            } else if (fn_80309C4C(lbl_8053AD30, 0x200, lbl_80529DEC[0x23c] + 1)) {
                p[0x26c] = 2;
                fn_80458880(lbl_8053AF80, 0xc, -1);
            }
        } else if (fn_80309C4C(lbl_8053AD30, 0x1300, lbl_80529DEC[0x23c] + 1)) {
            p[0x26c] = 2;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        }
        break;
    }

    *(s16*)(p + 0x25e) += 1;
    if (*(s16*)(p + 0x25e) >= 100) {
        *(s16*)(p + 0x25e) = 0;
    }
    *(s16*)(p + 0x25c) += 1;
    if (*(s16*)(p + 0x25c) >= 100) {
        *(s16*)(p + 0x25c) = 0;
    }

    for (i = 0; i < 4; i++) {
        if (lbl_8053AAF8[0x82] & (u8)(1 << (i + 4))) {
            *(s32*)(p + i * 4 + 0x220) += 1;
            if (*(s32*)(p + i * 4 + 0x220) >= 0x82) {
                *(s32*)(p + i * 4 + 0x220) = 0x64;
            }
            if (*(s32*)(p + i * 4 + 0x220) == 0xb) {
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x44] = 0;
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x45] = 0;
                t1 = 0x10001;
                (*(FsaMenuAction**)(p + i * 4 + 0x7c))->setAction(&t1);
            } else if (*(s32*)(p + i * 4 + 0x220) == 0x24) {
                r = (*(J2DPane**)(p + 8))->search(lbl_80478190[i]);
                span = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                r = (*(J2DPane**)(p + 8))->search(lbl_80478190[i]);
                *(f32*)(p + 0x8c) = (lbl_805436D8 * (span * lbl_80543658 + *(f32*)((u8*)r + 0x30))) /
                                    (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 4);
                r = (*(J2DPane**)(p + 8))->search(lbl_80478190[i]);
                span = *(f32*)((u8*)r + 0x2c) - *(f32*)((u8*)r + 0x24);
                r = (*(J2DPane**)(p + 8))->search(lbl_80478190[i]);
                *(f32*)(p + 0x90) = (lbl_805436DC * (lbl_80543660 + (span * lbl_80543658 + *(f32*)((u8*)r + 0x34)))) /
                                    (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 6);
                *(f32*)(p + 0x94) = lbl_80543664;
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x44] = 0;
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x45] = 0;
                t2 = 0x2000E;
                (*(FsaMenuAction**)(p + i * 4 + 0x7c))->setAction(&t2);
                v1.set(lbl_80543704 + *(f32*)(p + 0x8c), *(f32*)(p + 0x90) - lbl_80543700, *(f32*)(p + 0x94));
                fn_8013CC50(0, &v1.x, 0xcb, 1, 0, 0, 0, 1, lbl_80543668);
                v2.set(lbl_80543704 + *(f32*)(p + 0x8c), *(f32*)(p + 0x90) - lbl_80543700, *(f32*)(p + 0x94));
                fn_8013CC50(0, &v2.x, 0xcc, 1, 0, 0, 0, 1, lbl_80543668);
            }
        } else {
            *(s32*)(p + i * 4 + 0x220) = 0;
        }
    }
}

extern "C" s32 fn_80403414(s32 a);
extern "C" s32 fn_804033D4(s32 a);
extern "C" s32 fn_8040336C(s32 a);
extern "C" void fn_8013CC50(s32 a, f32* v, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, f32 h);
extern "C" void fn_803E9EE8(u8* p) {
    s32 i;
    f32 span;
    void* r;
    u32 t1;
    u32 t2;
    JGeometry::TVec3f v1;
    JGeometry::TVec3f v2;

    if (p[0x26c] == 0xff) {
        if (*(s32*)(p + 0x1bc) == 0) {
            fn_80431A9C(lbl_8053AEC0, 0xa9, (u8)(*(s32*)(p + 0x1bc) + 1), 0);
        } else {
            fn_80431A9C(lbl_8053AEC0, 0xc4, (u8)(*(s32*)(p + 0x1bc) + 1), 0);
        }
        p[0x26c] = 0;
        *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
        *(s32*)(p + 0x1d4) = 8;
    } else if (fn_80309C4C(lbl_8053AD30, 0x1100, lbl_80529DEC[0x23c] + 1)) {
        if (*(s32*)(p + 0x1d0) == *(s32*)(p + 0x1bc) + 1) {
            *(s32*)(p + 0x1b8) = 0;
            for (i = 0; i < 4; i++) {
                *(s32*)(p + i * 4 + 0x1f0) = fn_80403414(i);
                *(s32*)(p + i * 4 + 0x200) = fn_804033D4(i);
                *(s32*)(p + i * 4 + 0x210) = fn_8040336C(i);
                *(s32*)(p + i * 4 + 0x1c0) = 0;
            }
            *(s16*)(p + 0x254) = 0;
            *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
            *(s32*)(p + 0x1d4) = 6;
        } else {
            if (*(s32*)(p + 0x1bc) == 0) {
                fn_80431A9C(lbl_8053AEC0, 0xa9, (u8)(*(s32*)(p + 0x1bc) + 1), 0);
            } else {
                fn_80431A9C(lbl_8053AEC0, 0xc4, (u8)(*(s32*)(p + 0x1bc) + 1), 0);
            }
            p[0x26c] = 0;
            *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
            *(s32*)(p + 0x1d4) = 8;
        }
        fn_80458880(lbl_8053AF80, 0xb, -1);
    } else if (fn_80309C4C(lbl_8053AD30, 0x200, lbl_80529DEC[0x23c] + 1)) {
        (((T803ED83C*)p)->*lbl_804B0754[2])();
        fn_80458880(lbl_8053AF80, 0xc, -1);
    }

    *(s32*)(p + 0x1e0) += 1;
    if (*(s32*)(p + 0x1e0) >= 0x3c) {
        *(s32*)(p + 0x1e0) = 0;
    }
    *(s16*)(p + 0x25e) += 1;
    if (*(s16*)(p + 0x25e) >= 100) {
        *(s16*)(p + 0x25e) = 0;
    }
    *(s16*)(p + 0x25c) += 1;
    if (*(s16*)(p + 0x25c) >= 100) {
        *(s16*)(p + 0x25c) = 0;
    }

    for (i = 0; i < 4; i++) {
        if (lbl_8053AAF8[0x82] & (u8)(1 << (i + 4))) {
            *(s32*)(p + i * 4 + 0x220) += 1;
            if (*(s32*)(p + i * 4 + 0x220) >= 0x82) {
                *(s32*)(p + i * 4 + 0x220) = 0x64;
            }
            if (*(s32*)(p + i * 4 + 0x220) == 0xb) {
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x44] = 0;
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x45] = 0;
                t1 = 0x10001;
                (*(FsaMenuAction**)(p + i * 4 + 0x7c))->setAction(&t1);
            } else if (*(s32*)(p + i * 4 + 0x220) == 0x24) {
                r = (*(J2DPane**)(p + 8))->search(lbl_80478190[i]);
                span = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                r = (*(J2DPane**)(p + 8))->search(lbl_80478190[i]);
                *(f32*)(p + 0x8c) = (lbl_805436D8 * (span * lbl_80543658 + *(f32*)((u8*)r + 0x30))) /
                                    (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 4);
                r = (*(J2DPane**)(p + 8))->search(lbl_80478190[i]);
                span = *(f32*)((u8*)r + 0x2c) - *(f32*)((u8*)r + 0x24);
                r = (*(J2DPane**)(p + 8))->search(lbl_80478190[i]);
                *(f32*)(p + 0x90) = (lbl_805436DC * (lbl_80543660 + (span * lbl_80543658 + *(f32*)((u8*)r + 0x34)))) /
                                    (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 6);
                *(f32*)(p + 0x94) = lbl_80543664;
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x44] = 0;
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x45] = 0;
                t2 = 0x2000E;
                (*(FsaMenuAction**)(p + i * 4 + 0x7c))->setAction(&t2);
                v1.set(lbl_80543704 + *(f32*)(p + 0x8c), *(f32*)(p + 0x90) - lbl_80543700, *(f32*)(p + 0x94));
                fn_8013CC50(0, &v1.x, 0xcb, 1, 0, 0, 0, 1, lbl_80543668);
                v2.set(lbl_80543704 + *(f32*)(p + 0x8c), *(f32*)(p + 0x90) - lbl_80543700, *(f32*)(p + 0x94));
                fn_8013CC50(0, &v2.x, 0xcc, 1, 0, 0, 0, 1, lbl_80543668);
            }
        } else {
            *(s32*)(p + i * 4 + 0x220) = 0;
        }
    }
}

extern const f32 lbl_8054369C;
extern const f32 lbl_805436E8;
extern "C" void fn_803EA3F8(u8* p) {
    u8* base = lbl_80477970;
    u64* names;
    int j;
    int i;
    J2DPane* pane;
    f32 t;
    s32 frame;
    *(s16*)(p + 0x254) += 1;
    frame = *(s16*)(p + 0x254);
    if (frame > 0) {
        if (frame < 8) {
            *(f32*)(p + 0xa0) = MenuSlide803E(frame, lbl_8054369C, 64.0f);
            *(f32*)(p + 0xac) = MenuSlide803E(*(s16*)(p + 0x254), lbl_805436A0, 64.0f);
            t = (f32)(8 - *(s16*)(p + 0x254)) / 8.0f;
            if (t < 0.0f) t = 0.0f;
            else if (t > 1.0f) t = 1.0f;
            names = (u64*)(base + 0x420);
            for (i = 0; i < 34; i++, names++) {
                pane = (*(J2DPane**)(p + 8))->search(*names);
                f32 value = p[0x2dc + i];
                value *= t;
                pane->setAlpha((u8)value);
            }
            t = (f32)(8 - *(s16*)(p + 0x254)) / 8.0f;
            if (t < 0.0f) t = 0.0f;
            else if (t > 1.0f) t = 1.0f;
            names = (u64*)(base + 0x398);
            for (i = 0; i < 11; i++, names++) {
                pane = (*(J2DPane**)(p + 8))->search(*names);
                f32 value = p[0x2cb + i];
                value *= t;
                pane->setAlpha((u8)value);
            }
        } else {
            *(f32*)(p + 0xa0) = lbl_8054369C;
            *(f32*)(p + 0xac) = lbl_805436A0;
            names = (u64*)(base + 0x420);
            for (i = 0; i < 34; i++, names++) {
                pane = (*(J2DPane**)(p + 8))->search(*names);
                f32 value = p[0x2dc + i];
                value *= lbl_80543664;
                pane->setAlpha((u8)value);
            }
            names = (u64*)(base + 0x398);
            for (i = 0; i < 11; i++, names++) {
                pane = (*(J2DPane**)(p + 8))->search(*names);
                f32 value = p[0x2cb + i];
                value *= lbl_80543664;
                pane->setAlpha((u8)value);
            }
        }
    }
    frame = *(s16*)(p + 0x254);
    if (frame > 0) {
        if (frame < 8) {
            *(f32*)(p + 0xb8) = MenuSlide803E(frame, lbl_8054368C, 64.0f);
            *(f32*)(p + 0xbc) = MenuSlide803E(*(s16*)(p + 0x254), lbl_8054368C, 64.0f);
            t = (f32)(8 - *(s16*)(p + 0x254)) / 8.0f;
            if (t < 0.0f) t = 0.0f;
            else if (t > 1.0f) t = 1.0f;
            names = (u64*)(base + 0x3f0);
            for (i = 0; i < 6; i++, names++) {
                pane = (*(J2DPane**)(p + 8))->search(*names);
                f32 value = p[0x2d6 + i];
                value *= t;
                pane->setAlpha((u8)value);
            }
        } else {
            *(f32*)(p + 0xb8) = lbl_8054368C;
            *(f32*)(p + 0xbc) = lbl_8054368C;
            names = (u64*)(base + 0x3f0);
            for (i = 0; i < 6; i++, names++) {
                pane = (*(J2DPane**)(p + 8))->search(*names);
                f32 value = p[0x2d6 + i];
                value *= lbl_80543664;
                pane->setAlpha((u8)value);
            }
        }
    }
    int lo2;
    int hi;
    int lo;
    i = 0;
    for (lo = 0; i < 4; lo += 5) {
        lo2 = i * 5;
        hi = i * 5 + 8;
        if (*(s16*)(p + 0x254) > lo) {
            if (*(s16*)(p + 0x254) < hi) {
                s32 idx = 3 - i;
                *(f32*)(p + 0xe0 + idx * 4) = MenuSlide803E(*(s16*)(p + 0x254) - lo2, lbl_805436A4, 64.0f);
                t = (f32)(8 - (*(s16*)(p + 0x254) - lo2)) / 8.0f;
                if (t < 0.0f) t = 0.0f;
                else if (t > 1.0f) t = 1.0f;
                u8* alpha = p + idx * 9;
                names = (u64*)(base + 0x530);
                names += idx * 9;
                for (int k = 0; k < 9; k++, alpha++, names++) {
                    pane = (*(J2DPane**)(p + 8))->search(*names);
                    f32 value = alpha[0x2fe];
                    value *= t;
                    pane->setAlpha((u8)value);
                }
            } else {
                s32 idx = 3 - i;
                *(f32*)(p + 0xe0 + idx * 4) = lbl_805436A4;
                u8* alpha = p + idx * 9;
                names = (u64*)(base + 0x530);
                names += idx * 9;
                for (int k = 0; k < 9; k++, alpha++, names++) {
                    pane = (*(J2DPane**)(p + 8))->search(*names);
                    f32 value = alpha[0x2fe];
                    value *= lbl_80543664;
                    pane->setAlpha((u8)value);
                }
            }
        }
        i++;
    }
    if (*(s16*)(p + 0x254) >= 23) {
        for (j = 0, i = 0; i < 4; i++, j += 2) {
            if (i < *(s32*)(p + 0x1bc) + 1) {
                lbl_8053AAF8[0x82] |= (u8)(1 << i);
                u8* q = lbl_8053AAF8;
                q[0x83] &= ~(u8)(3 << j);
                q[0x83] |= (u8)(1 << j);
            } else {
                lbl_8053AAF8[0x82] &= ~(u8)(1 << i);
                lbl_8053AAF8[0x83] &= ~(u8)(3 << j);
            }
        }
        if (*(s32*)(p + 0x1d0) == *(s32*)(p + 0x1bc) + 1) {
            *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
            *(s32*)(p + 0x1d4) = 0xf;
            if (*(s32*)(p + 0x1bc) == 2 && *(s32*)(lbl_80529DEC + 0x64) == -1) {
                u8* g = lbl_8053AAF8;
                *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
                u32 bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
                f32 r = *(f32*)&bits;
                s32 v = (s32)(lbl_80543680 * (r - lbl_80543668));
                if (v >= 3) v = 2;
                *(s32*)(lbl_80529DEC + 0x64) = v;
            }
            u8* rec = lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8;
            if (rec[0x85] & 1) {
                lbl_80529DEC[0x237] = 5;
                *(s32*)(p + 0x360) = 6;
            } else {
                *(s32*)(lbl_80529DEC + 0x118) = 8;
                *(s32*)(lbl_80529DEC + 0x11c) = 3;
                *(s32*)(p + 0x360) = 7;
                lbl_80529DEC[0x242] = 0;
            }
            lbl_80529DEC[0x23e] = 0;
        } else {
            fn_803E3CB0(p);
        }
        *(s16*)(p + 0x254) = 0;
    }
    (*(J2DPane**)(p + 8))->search(0x4e646174613033ULL)->move(*(f32*)(p + 0x98), *(f32*)(p + 0x9c) + *(f32*)(p + 0xa0));
    (*(J2DPane**)(p + 8))->search(0x4e646174613035ULL)->move(*(f32*)(p + 0xa4), *(f32*)(p + 0xa8) + *(f32*)(p + 0xac));
    (*(J2DPane**)(p + 8))->search(0x4e646174613036ULL)->move(*(f32*)(p + 0xb0), *(f32*)(p + 0xb4) + *(f32*)(p + 0xb8));
    fn_80402E08(*(void**)(p + 0x78), lbl_80543664, *(f32*)(p + 0xbc));
    (*(J2DPane**)(p + 8))->search(0x50706c6c626b3032ULL)->move(*(f32*)(p + 0xc0), *(f32*)(p + 0xd0) + *(f32*)(p + 0xe0));
    (*(J2DPane**)(p + 8))->search(0x50706c6c626b3132ULL)->move(*(f32*)(p + 0xc4), *(f32*)(p + 0xd4) + *(f32*)(p + 0xe4));
    (*(J2DPane**)(p + 8))->search(0x50706c6c626b3232ULL)->move(*(f32*)(p + 0xc8), *(f32*)(p + 0xd8) + *(f32*)(p + 0xe8));
    (*(J2DPane**)(p + 8))->search(0x50706c6c626b3332ULL)->move(*(f32*)(p + 0xcc), *(f32*)(p + 0xdc) + *(f32*)(p + 0xec));
}

extern const f32 lbl_805436A0;
extern const f32 lbl_805436A4;
extern const f32 lbl_80543708;
#pragma opt_common_subs off
extern "C" void fn_803EAEC8(u8* p) {
 u8* base=lbl_80477970;
 s32 i,j;
 f32 t,span; f32 fraction;
 void* r;
 u32 t1,t2;
 JGeometry::TVec3f v1,v2;
 ++*(s16*)(p+0x254);
 s32 time=*(s16*)(p+0x254);
if(time>0){if(time<25){
{s32 d=25-time; t=(f32)(d*d)/lbl_805436F8; *(f32*)(p+0xa0)=lbl_8054369C*t;}
{s32 d=25-*(s16*)(p+0x254); t=(f32)(d*d)/lbl_805436F8; *(f32*)(p+0xac)=lbl_805436A0*t;}
t=(f32)*(s16*)(p+0x254)/lbl_805436C0;if(t<lbl_80543664)t=lbl_80543664; else if(t>lbl_80543668)t=lbl_80543668;
{ u64* names=(u64*)(base+0x420); s32 i; for(i=0;i<34;i++,names++){ J2DPane* pane=(*(J2DPane**)(p+8))->search(*names); f32 value=p[0x2dc+i]; value*=t; ((Pane803E4650*)pane)->setAlpha((int)value); }}
t=(f32)*(s16*)(p+0x254)/lbl_805436C0;if(t<lbl_80543664)t=lbl_80543664; else if(t>lbl_80543668)t=lbl_80543668;
{ u64* names=(u64*)(base+0x398); s32 i; for(i=0;i<11;i++,names++){ J2DPane* pane=(*(J2DPane**)(p+8))->search(*names); f32 value=p[0x2cb+i]; value*=t; ((Pane803E4650*)pane)->setAlpha((int)value); }}
}else{
*(f32*)(p+0xac)=lbl_80543664; *(f32*)(p+0xa0)=lbl_80543664;{ u64* names=(u64*)(base+0x420); s32 i; for(i=0;i<34;i++,names++){ J2DPane* pane=(*(J2DPane**)(p+8))->search(*names); f32 value=p[0x2dc+i]; value*=lbl_80543668; ((Pane803E4650*)pane)->setAlpha((int)value); }}
{ u64* names=(u64*)(base+0x398); s32 i; for(i=0;i<11;i++,names++){ J2DPane* pane=(*(J2DPane**)(p+8))->search(*names); f32 value=p[0x2cb+i]; value*=lbl_80543668; ((Pane803E4650*)pane)->setAlpha((int)value); }}
}}
time=*(s16*)(p+0x254);
if(time>25){if(time<45){
{s32 d=20-(time-25); t=(f32)(d*d)/lbl_805436B0; *(f32*)(p+0xb8)=lbl_8054368C*t;}
{s32 d=20-(*(s16*)(p+0x254)-25); t=(f32)(d*d)/lbl_805436B0; *(f32*)(p+0xbc)=lbl_8054368C*t;}
t=(f32)(*(s16*)(p+0x254)-25)/lbl_80543708;if(t<lbl_80543664)t=lbl_80543664; else if(t>lbl_80543668)t=lbl_80543668;
{ u64* names=(u64*)(base+0x3f0); s32 i; for(i=0;i<6;i++,names++){ J2DPane* pane=(*(J2DPane**)(p+8))->search(*names); f32 value=p[0x2d6+i]; value*=t; ((Pane803E4650*)pane)->setAlpha((int)value); }}
}else{
*(f32*)(p+0xbc)=lbl_80543664; *(f32*)(p+0xb8)=lbl_80543664;{ u64* names=(u64*)(base+0x3f0); s32 i; for(i=0;i<6;i++,names++){ J2DPane* pane=(*(J2DPane**)(p+8))->search(*names); f32 value=p[0x2d6+i]; value*=lbl_80543668; ((Pane803E4650*)pane)->setAlpha((int)value); }}
}}
{ s32 lo; s32 hi; s32 lo2; u8* offsets; u8* bytes; u64* group; s32 k;
offsets=p;lo2=0;bytes=p;group=(u64*)(base+0x530);k=0;hi=15;
for(;k<4;k++,hi+=5,lo2+=5,offsets+=4,bytes+=9,group+=9){
lo=k*5; time=*(s16*)(p+0x254); if(time>lo){if(time<hi){
{s32 d=15-(time-lo2); t=(f32)(d*d)/lbl_805436C4; *(f32*)(offsets+0xe0)=lbl_805436A4*t;}
t=(f32)(*(s16*)(p+0x254)-lo2)/lbl_805436FC;if(t<lbl_80543664)t=lbl_80543664; else if(t>lbl_80543668)t=lbl_80543668;
u8* alpha=bytes;u64* names=group;
for(i=0;i<9;i++,alpha++,names++){J2DPane* pane=(*(J2DPane**)(p+8))->search(*names);f32 value=alpha[0x2fe];value*=t;((Pane803E4650*)pane)->setAlpha((int)value);}
}else{*(f32*)(offsets+0xe0)=lbl_80543664;u8* alpha=bytes;u64* names=group;
for(i=0;i<9;i++,alpha++,names++){J2DPane* pane=(*(J2DPane**)(p+8))->search(*names);f32 value=alpha[0x2fe];value*=lbl_80543668;((Pane803E4650*)pane)->setAlpha((int)value);}
}}}
}
++*(s16*)(p+0x25e);if(*(s16*)(p+0x25e)>=100)*(s16*)(p+0x25e)=0;
{u64* names=(u64*)(base+0x820);
 s32 i;
    for (i = 0; i < 4; i++) {
        if ((lbl_8053AAF8[0x82] & (u8)(1 << (i + 4))) && lbl_80543664 == *(f32*)(p+i*4+0xe0)) {
            *(s32*)(p + i * 4 + 0x220) += 1;
            if (*(s32*)(p + i * 4 + 0x220) >= 0x82) {
                *(s32*)(p + i * 4 + 0x220) = 0x64;
            }
            if (*(s32*)(p + i * 4 + 0x220) == 0xb) {
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x44] = 0;
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x45] = 0;
                t1 = 0x10001;
                (*(FsaMenuAction**)(p + i * 4 + 0x7c))->setAction(&t1);
            } else if (*(s32*)(p + i * 4 + 0x220) == 0x24) {
                r = (*(J2DPane**)(p + 8))->search(names[i]);
                span = *(f32*)((u8*)r + 0x28) - *(f32*)((u8*)r + 0x20);
                r = (*(J2DPane**)(p + 8))->search(names[i]);
                *(f32*)(p + 0x8c) = (lbl_805436D8 * (span * lbl_80543658 + *(f32*)((u8*)r + 0x30))) /
                                    (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 4);
                r = (*(J2DPane**)(p + 8))->search(names[i]);
                span = *(f32*)((u8*)r + 0x2c) - *(f32*)((u8*)r + 0x24);
                r = (*(J2DPane**)(p + 8))->search(names[i]);
                *(f32*)(p + 0x90) = (lbl_805436DC * (lbl_80543660 + (span * lbl_80543658 + *(f32*)((u8*)r + 0x34)))) /
                                    (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 6);
                *(f32*)(p + 0x94) = lbl_80543664;
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x44] = 0;
                ((u8*)*(void**)(p + i * 4 + 0x7c))[0x45] = 0;
                t2 = 0x2000E;
                (*(FsaMenuAction**)(p + i * 4 + 0x7c))->setAction(&t2);
                v1.set(lbl_80543704 + *(f32*)(p + 0x8c), *(f32*)(p + 0x90) - lbl_80543700, *(f32*)(p + 0x94));
                fn_8013CC50(0, &v1.x, 0xcb, 1, 0, 0, 0, 1, lbl_80543668);
                v2.set(lbl_80543704 + *(f32*)(p + 0x8c), *(f32*)(p + 0x90) - lbl_80543700, *(f32*)(p + 0x94));
                fn_8013CC50(0, &v2.x, 0xcc, 1, 0, 0, 0, 1, lbl_80543668);
            }
        } else {
            *(s32*)(p + i * 4 + 0x220) = 0;
        }
    }
}
if(*(s16*)(p+0x254)>=75){*(s16*)(p+0x254)=0;*(s32*)(p+0x1d8)=*(s32*)(p+0x1d4);*(s32*)(p+0x1d4)=7;}
(*(J2DPane**)(p+8))->search(0x004e646174613033ULL)->move(*(f32*)(p+152),*(f32*)(p+156)+*(f32*)(p+160));
(*(J2DPane**)(p+8))->search(0x004e646174613035ULL)->move(*(f32*)(p+164),*(f32*)(p+168)+*(f32*)(p+172));
(*(J2DPane**)(p+8))->search(0x004e646174613036ULL)->move(*(f32*)(p+176),*(f32*)(p+180)+*(f32*)(p+184));
fn_80402E08(*(void**)(p+0x78),lbl_80543664,*(f32*)(p+0xbc));
(*(J2DPane**)(p+8))->search(0x50706c6c626b3032ULL)->move(*(f32*)(p+192),*(f32*)(p+208)+*(f32*)(p+224));
(*(J2DPane**)(p+8))->search(0x50706c6c626b3132ULL)->move(*(f32*)(p+196),*(f32*)(p+212)+*(f32*)(p+228));
(*(J2DPane**)(p+8))->search(0x50706c6c626b3232ULL)->move(*(f32*)(p+200),*(f32*)(p+216)+*(f32*)(p+232));
(*(J2DPane**)(p+8))->search(0x50706c6c626b3332ULL)->move(*(f32*)(p+204),*(f32*)(p+220)+*(f32*)(p+236));
}
#pragma optimization_level 4
extern "C" void fn_803EBAA8(u8* p) {
s32 ids[3];
s32 lo;
s32 hi;
s32 lo2;
s32* ip;
s32 group;
u8* base=lbl_80477970;
s32* selected=ids;
ip=selected;
f32 t;
for(int n=0;n<4;n++){if(n!=*(s32*)(p+0x1bc))*ip++=n;}
++*(s16*)(p+0x254);
s32 time=*(s16*)(p+0x254);
if(time>20){if(time<28){
*(f32*)(p+0xf8)=(lbl_805436A8*(MenuSquare803E(time-20)/64.0f));
t=(f32)(8-(*(s16*)(p+0x254)-20))/8.0f;
if(t<0.0f)t=0.0f;else if(t>1.0f)t=1.0f;
{u64* names=(u64*)(base+0xb8);for(group=0;group<17;group++,names++){J2DPane* pane=(*(J2DPane**)(p+4))->search(*names);f32 value=p[0x26f+group];value*=t;((Pane803E4650*)pane)->setAlpha((int)value);}}

}else{
*(f32*)(p+0xf8)=lbl_805436A8;
{u64* names=(u64*)(base+0xb8);for(group=0;group<17;group++,names++){J2DPane* pane=(*(J2DPane**)(p+4))->search(*names);f32 value=p[0x26f+group];value*=lbl_80543664;((Pane803E4650*)pane)->setAlpha((int)value);}}

}}
time=*(s16*)(p+0x254);
if(time>0){if(time<8){*(f32*)(p+0xfc)=(lbl_8054368C*(MenuSquare803E(time)/64.0f));}else{*(f32*)(p+0xfc)=lbl_8054368C;}}
lo=0;group=0;
for(;group<3;group++,lo+=5,selected++){
lo2=group*5;hi=group*5+8;
time=*(s16*)(p+0x254);
if(time>lo){if(time<hi){
s32 id=*selected;
((Tu803E1668Obj*)p)->slide[id]=(lbl_805436AC*(MenuSquare803E(time-lo2)/64.0f));
t=(f32)(8-(*(s16*)(p+0x254)-lo2))/8.0f;
if(t<0.0f)t=0.0f;else if(t>1.0f)t=1.0f;
MenuRowAlpha803E(p,id,base,t);

}else{
((Tu803E1668Obj*)p)->slide[*selected]=lbl_805436AC;
MenuRowAlpha803E(p,*selected,base,lbl_80543664);

}}}
time=*(s16*)(p+0x254);
if(time>15){if(time<23){
((Tu803E1668Obj*)(p+*(s32*)(p+0x1bc)*4))->slide[0]=(lbl_805436AC*(MenuSquare803E(time-15)/64.0f));
s32 id=*(s32*)(p+0x1bc);
t=(f32)(8-(*(s16*)(p+0x254)-15))/8.0f;
if(t<0.0f)t=0.0f;else if(t>1.0f)t=1.0f;
{
u64* names=(u64*)(base+0x140);names+=id*6;u8* alpha=p+id*6;for(int k=0;k<6;k++,alpha++,names++){J2DPane* pane=(*(J2DPane**)(p+4))->search(*names);f32 value=alpha[0x280];value*=t;((Pane803E4650*)pane)->setAlpha((int)value);}}

}else{
((Tu803E1668Obj*)(p+*(s32*)(p+0x1bc)*4))->slide[0]=lbl_805436AC;
MenuRowAlpha803E(p,*(s32*)(p+0x1bc),base,lbl_80543664);

}}
time=*(s16*)(p+0x254);
if(time>15){if(time<23){
*(f32*)(p+0x138)=*(f32*)(p+0x14c)=(lbl_805436B0*(MenuSquare803E(time-15)/64.0f));
t=(f32)(8-(*(s16*)(p+0x254)-15))/8.0f;
if(t<0.0f)t=0.0f;else if(t>1.0f)t=1.0f;
{u64* names=(u64*)(base+0x200);for(int k=0;k<29;k++,names++){J2DPane* pane=(*(J2DPane**)(p+4))->search(*names);f32 value=p[0x298+k];value*=t;((Pane803E4650*)pane)->setAlpha((int)value);}}
{u64* names=(u64*)(base+0x2e8);for(int k=0;k<22;k++,names++){J2DPane* pane=(*(J2DPane**)(p+4))->search(*names);f32 value=p[0x2b5+k];value*=t;((Pane803E4650*)pane)->setAlpha((int)value);}}

}else{
*(f32*)(p+0x138)=*(f32*)(p+0x14c)=lbl_805436B0;
{u64* names=(u64*)(base+0x200);for(int k=0;k<29;k++,names++){J2DPane* pane=(*(J2DPane**)(p+4))->search(*names);f32 value=p[0x298+k];value*=lbl_80543664;((Pane803E4650*)pane)->setAlpha((int)value);}}
{u64* names=(u64*)(base+0x2e8);for(int k=0;k<22;k++,names++){J2DPane* pane=(*(J2DPane**)(p+4))->search(*names);f32 value=p[0x2b5+k];value*=lbl_80543664;((Pane803E4650*)pane)->setAlpha((int)value);}}

}}
if(*(s16*)(p+0x254)>=28){
if(*(s32*)(p+0x1dc)==15){
if(*(s32*)(p+0x1bc)+1==*(s32*)(p+0x1d0)||*(s32*)(p+0x1bc)==0){
*(s32*)(p+0x1d8)=*(s32*)(p+0x1d4);*(s32*)(p+0x1d4)=15;
if(*(s32*)(p+0x1bc)==2&&*(s32*)(lbl_80529DEC+0x64)==-1){
u8* g=lbl_8053AAF8;
*(u32*)(g+0xb4)=*(u32*)(g+0xb4)*0x19660d+0x3c6ef35f;
u32 bits=(*(u32*)(g+0xb4)>>9)|0x3f800000;
f32 r=*(f32*)&bits;
s32 v=(s32)(lbl_80543680*(r-lbl_80543668));if(v>=3)v=2;
*(s32*)(lbl_80529DEC+0x64)=v;
}
u8* rec=lbl_8050EC80+*(s32*)(lbl_8050EC80+0x10)*0xc8;
if(rec[0x85]&1){lbl_80529DEC[0x237]=5;*(s32*)(p+0x360)=6;}
else{*(s32*)(lbl_80529DEC+0x118)=8;*(s32*)(lbl_80529DEC+0x11c)=3;*(s32*)(p+0x360)=7;lbl_80529DEC[0x242]=0;}
lbl_80529DEC[0x23e]=0;
}else{fn_803E3CB0(p);}
}else if(*(s32*)(p+0x1bc)==0){(((T803ED83C*)p)->*lbl_804B0754[9])();}
else{p[0x26c]=0;(((T803ED83C*)p)->*lbl_804B0754[5])();}
}
if(*(s16*)(p+0x254)>=53)*(s16*)(p+0x254)=0;
++*(s32*)(p+0x1e0);if(*(s32*)(p+0x1e0)>=30)*(s32*)(p+0x1e0)=0;
(*(J2DPane**)(p+4))->search(0x506d616462623037ULL)->move(*(f32*)(p+0xf0),*(f32*)(p+0xf4)+*(f32*)(p+0xf8));
fn_80402E08(*(void**)(p+0x78),lbl_80543664,*(f32*)(p+0xfc));
(*(J2DPane**)(p+4))->search(0x00506e6f70623034ULL)->move(*(f32*)(p+256)+*(f32*)(p+288),*(f32*)(p+272));
(*(J2DPane**)(p+4))->search(0x00506e6f70623038ULL)->move(*(f32*)(p+260)+*(f32*)(p+292),*(f32*)(p+276));
(*(J2DPane**)(p+4))->search(0x00506e6f70623132ULL)->move(*(f32*)(p+264)+*(f32*)(p+296),*(f32*)(p+280));
(*(J2DPane**)(p+4))->search(0x00506e6f70623136ULL)->move(*(f32*)(p+268)+*(f32*)(p+300),*(f32*)(p+284));
(*(J2DPane**)(p+4))->search(0x004e646174613032ULL)->move(*(f32*)(p+304)+*(f32*)(p+312),*(f32*)(p+308));
(*(J2DPane**)(p+4))->search(0x004e646174613035ULL)->move(*(f32*)(p+316)+*(f32*)(p+332),*(f32*)(p+320));
(*(J2DPane**)(p+4))->search(0x004e646174613037ULL)->move(*(f32*)(p+324)+*(f32*)(p+332),*(f32*)(p+328));
f32 y=getBounds__7J2DPaneFv((*(J2DPane**)(p+4))->search(0x50736375726f3032ULL))[1];
(*(J2DPane**)(p+4))->search(0x50736375726f3032ULL)->move(*(f32*)(p+0x19c)+((Tu803E1668Obj*)(p+*(s32*)(p+0x1bc)*4))->slide[0],y);
}
#pragma optimization_level 3
extern "C" void fn_80403680(void* p);
extern "C" void fn_803EC804(u8* p) {
    s32 j;
    s32 i;
    if (*(s16*)(p + 0x254) != 0) {
        *(s16*)(p + 0x254) += 1;
        if (*(s16*)(p + 0x254) > 10) {
            *(s16*)(p + 0x254) = 0;
        }
    }
    *(s32*)(p + 0x220) += 1;
    if (*(s32*)(p + 0x220) >= 0x1e) {
        *(s32*)(p + 0x220) = 0;
    }
    if (fn_80309C4C(lbl_8053AD30, 0x1100, 1) != 0) {
        if (*(s32*)(p + 0x1bc) == 0) {
            *(s32*)(p + 0x1b8) = 1;
            lbl_8053AAF8[0x7e] = 0;
            lbl_8053AAF8[0x82] |= 0x10;
            lbl_8053AAF8[0x82] &= ~0x20;
            lbl_8053AAF8[0x82] &= ~0x40;
            lbl_8053AAF8[0x82] &= 0x7f;
            lbl_8053AAF8[0x82] |= 0x1;
            lbl_8053AAF8[0x82] &= ~0x2;
            lbl_8053AAF8[0x82] &= ~0x4;
            lbl_8053AAF8[0x82] &= ~0x8;
            if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(0)) != 0) {
                u8* q = lbl_8053AAF8;
                q[0x83] &= ~0x3;
                q[0x83] |= 0x1;
            } else {
                u8* q = lbl_8053AAF8;
                q[0x83] &= ~0x3;
                q[0x83] |= 0x2;
            }
            lbl_8053AAF8[0x83] &= ~0xc;
            lbl_8053AAF8[0x83] &= ~0x30;
            lbl_8053AAF8[0x83] &= 0x3f;
            *(s32*)(p + 0x1dc) = 0xf;
            *(s32*)(p + 0x220) = 0;
            *(s16*)(p + 0x254) = 0;
            *(s32*)(p + 0x1e0) = 5;
            *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
            *(s32*)(p + 0x1d4) = 4;
        } else {
            *(s32*)(p + 0x1b8) = j = 0;
            lbl_8053AAF8[0x7e] = 1;
            if (*(s32*)(p + 0x1d0) == *(s32*)(p + 0x1bc) + 1) {
                for (i = 0; i < 4; i++) {
                    if (i < *(s32*)(p + 0x1bc) + 1) {
                        lbl_8053AAF8[0x82] |= (u8)(1 << i);
                        u8* q = lbl_8053AAF8;
                        q[0x83] &= ~(u8)(3 << j);
                        q[0x83] |= (u8)(1 << j);
                    } else {
                        lbl_8053AAF8[0x82] &= ~(u8)(1 << i);
                        lbl_8053AAF8[0x83] &= ~(u8)(3 << j);
                    }
                    j += 2;
                }
                *(s32*)(p + 0x1dc) = 0xf;
            }
            *(s32*)(p + 0x220) = 0;
            *(s16*)(p + 0x254) = 0;
            *(s32*)(p + 0x1e0) = 5;
            *(s32*)(p + 0x1d8) = *(s32*)(p + 0x1d4);
            *(s32*)(p + 0x1d4) = 4;
            if (*(s32*)(p + 0x1bc) != lbl_80529DEC[0x23c]) {
                *(s32*)(lbl_80529DEC + 0x130) = 0;
                *(s32*)(lbl_80529DEC + 0x134) = 0;
                *(s32*)(lbl_80529DEC + 0x138) = 0;
                *(s32*)(lbl_80529DEC + 0x13c) = 0;
                *(s32*)(lbl_80529DEC + 0x64) = -1;
            }
        }
        if (*(s32*)(p + 0x1bc) != lbl_80529DEC[0x23c]) {
            fn_80403680(lbl_80529DEC);
        }
        lbl_80529DEC[0x23c] = *(s32*)(p + 0x1bc);
        fn_80458880(lbl_8053AF80, 0xb, -1);
    } else if (fn_80309C4C(lbl_8053AD30, 0x200, 1) != 0) {
        *(s32*)(p + 0x360) = 2;
        fn_80458880(lbl_8053AF80, 0xc, -1);
    } else if (fn_80309A9C(lbl_8053AD30, 4, 1) != 0) {
        *(s32*)(p + 0x1bc) += 1;
        if (*(s32*)(p + 0x1bc) >= 4) {
            *(s32*)(p + 0x1bc) = 0;
        }
        *(s16*)(p + 0x254) = 1;
        *(s32*)(p + 0x1e0) = 0x1e;
        fn_80458880(lbl_8053AF80, 0x26, -1);
    } else if (fn_80309A9C(lbl_8053AD30, 8, 1) != 0) {
        *(s32*)(p + 0x1bc) -= 1;
        if (*(s32*)(p + 0x1bc) < 0) {
            *(s32*)(p + 0x1bc) = 3;
        }
        *(s16*)(p + 0x254) = 1;
        *(s32*)(p + 0x1e0) = 0x1e;
        fn_80458880(lbl_8053AF80, 0x26, -1);
    }
    *(s32*)(p + 0x1e0) += 1;
    if (*(s32*)(p + 0x1e0) >= 0x3c) {
        *(s32*)(p + 0x1e0) = 0;
    }
}

#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" void fn_803ECC64(u8* self) {
    u8* base=lbl_80477970;
    s32 j;
    s32 i;
    f32 t;
    ++*(s16*)(self+0x254);
    s32 time=*(s16*)(self+0x254);
    if(time>0) {
        if(time<25) {
            s32 d=25-time;
            f32 fraction=(f32)(d*d)/lbl_805436F8;
            *(f32*)(self+0xf8)=lbl_805436A8*fraction;
            t=(f32)*(s16*)(self+0x254)/lbl_805436C0;
            if(t<lbl_80543664) t=lbl_80543664;
            else if(t>lbl_80543668) t=lbl_80543668;
            {
                u64* names=(u64*)(base+0xb8);
                s32 i;
                for(i=0;i<17;i++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=self[0x26f+i];
                    value*=t;
                    ((Pane803E4650*)pane)->setAlpha((s32)value);
                }
            }
        } else {
            *(f32*)(self+0xf8)=lbl_80543664;
            {
                u64* names=(u64*)(base+0xb8);
                s32 i;
                for(i=0;i<17;i++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=self[0x26f+i];
                    value*=lbl_80543668;
                    ((Pane803E4650*)pane)->setAlpha((s32)value);
                }
            }
        }
    }
    time=*(s16*)(self+0x254);
    if(time>25) {
        if(time<45) {
            s32 d=20-(time-25);
            f32 fraction=(f32)(d*d)/lbl_805436B0;
            *(f32*)(self+0xfc)=lbl_8054368C*fraction;
        } else *(f32*)(self+0xfc)=lbl_80543664;
    }
    s32 lo;
    s32 hi;
    s32 lo2;
    u8* offsets;
    u8* bytes;
    u64* group;
    s32 k;
    offsets=self;
    lo2=0;
    bytes=self;
    group=(u64*)(base+0x140);
    k=0;
    hi=10;
    for(;k<4;k++,hi+=5,lo2+=5,offsets+=4,bytes+=6,group+=6) {
        lo=k*5;
        time=*(s16*)(self+0x254);
        if(time>lo) {
            if(time<hi) {
                s32 d=10-(time-lo2);
                f32 fraction=(f32)(d*d)/lbl_805436F0;
                *(f32*)(offsets+0x120)=lbl_805436AC*fraction;
                t=(f32)(*(s16*)(self+0x254)-lo2)/lbl_805436F4;
            if(t<lbl_80543664) t=lbl_80543664;
            else if(t>lbl_80543668) t=lbl_80543668;
                u8* alpha=bytes;
                u64* names=group;
                for(i=0;i<6;i++,alpha++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=alpha[0x280];
                    value*=t;
                    ((Pane803E4650*)pane)->setAlpha((s32)value);
                }
            } else {
                *(f32*)(offsets+0x120)=lbl_80543664;
                u8* alpha=bytes;
                u64* names=group;
                for(i=0;i<6;i++,alpha++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=alpha[0x280];
                    value*=lbl_80543668;
                    ((Pane803E4650*)pane)->setAlpha((s32)value);
                }
            }
        }
    }
    time=*(s16*)(self+0x254);
    if(time>0) {
        if(time<15) {
            s32 d=15-time;
            f32 fraction=(f32)(d*d)/lbl_805436C4;
            f32 value=lbl_805436B0*fraction;
            *(f32*)(self+0x14c)=value;
            *(f32*)(self+0x138)=value;
            t=(f32)*(s16*)(self+0x254)/lbl_805436FC;
            if(t<lbl_80543664) t=lbl_80543664;
            else if(t>lbl_80543668) t=lbl_80543668;
            {
                u64* names=(u64*)(base+0x200);
                for(j=0;j<29;j++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=self[0x298+j];
                    value*=t;
                    ((Pane803E4650*)pane)->setAlpha((s32)value);
                }
            }
            {
                u64* names=(u64*)(base+0x2e8);
                for(j=0;j<22;j++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=self[0x2b5+j];
                    value*=t;
                    ((Pane803E4650*)pane)->setAlpha((s32)value);
                }
            }
        } else {
            *(f32*)(self+0x14c)=lbl_80543664;
            *(f32*)(self+0x138)=lbl_80543664;
            {
                u64* names=(u64*)(base+0x200);
                for(j=0;j<29;j++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=self[0x298+j];
                    value*=lbl_80543668;
                    ((Pane803E4650*)pane)->setAlpha((s32)value);
                }
            }
            {
                u64* names=(u64*)(base+0x2e8);
                for(j=0;j<22;j++,names++) {
                    J2DPane* pane=(*(J2DPane**)(self+4))->search(*names);
                    f32 value=self[0x2b5+j];
                    value*=lbl_80543668;
                    ((Pane803E4650*)pane)->setAlpha((s32)value);
                }
            }
        }
    }
    if(*(s16*)(self+0x254)>=75) {
        *(s16*)(self+0x254)=0;
        *(s32*)(self+0x1d8)=*(s32*)(self+0x1d4);
        *(s32*)(self+0x1d4)=3;
    }
    (*(J2DPane**)(self+4))->search(0x506d616462623037ULL)->move(*(f32*)(self+0xf0),*(f32*)(self+0xf4)+*(f32*)(self+0xf8));
    fn_80402E08(*(void**)(self+0x78),lbl_80543664,*(f32*)(self+0xfc));
    (*(J2DPane**)(self+4))->search(0x00506e6f70623034ULL)->move(*(f32*)(self+0x100)+*(f32*)(self+0x120),*(f32*)(self+0x110));
    (*(J2DPane**)(self+4))->search(0x00506e6f70623038ULL)->move(*(f32*)(self+0x104)+*(f32*)(self+0x124),*(f32*)(self+0x114));
    (*(J2DPane**)(self+4))->search(0x00506e6f70623132ULL)->move(*(f32*)(self+0x108)+*(f32*)(self+0x128),*(f32*)(self+0x118));
    (*(J2DPane**)(self+4))->search(0x00506e6f70623136ULL)->move(*(f32*)(self+0x10c)+*(f32*)(self+0x12c),*(f32*)(self+0x11c));
    (*(J2DPane**)(self+4))->search(0x004e646174613032ULL)->move(*(f32*)(self+0x130)+*(f32*)(self+0x138),*(f32*)(self+0x134));
    (*(J2DPane**)(self+4))->search(0x004e646174613035ULL)->move(*(f32*)(self+0x13c)+*(f32*)(self+0x14c),*(f32*)(self+0x140));
    (*(J2DPane**)(self+4))->search(0x004e646174613037ULL)->move(*(f32*)(self+0x144)+*(f32*)(self+0x14c),*(f32*)(self+0x148));
    t = (*(J2DPane**)(self+4))->search(0x50736375726f3032ULL)->getBounds()->i.y;
    (*(J2DPane**)(self+4))->search(0x50736375726f3032ULL)->move(*(f32*)(self+0x19c), t);
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
extern "C" void fn_803ED5B4(u8* param_1) {
    if (param_1[0x26e] == 0) {
        *(s32*)(param_1 + 0x1dc) = 9;
        param_1[0x26e] = 1;
    }
    *(s32*)(param_1 + 0x1b8) = 1;
    fn_80458880(lbl_8053AF80, 0xb, -1);
}

extern "C" void fn_803ED604(u8* p) {
    s32 n;
    if (*(s16*)(p + 0x254) != 0) {
        *(s16*)(p + 0x254) += 1;
        if (*(s16*)(p + 0x254) > 10) {
            *(s16*)(p + 0x254) = 0;
        }
    }
    *(s32*)(p + 0x220) += 1;
    if (*(s32*)(p + 0x220) >= 0x1e) {
        *(s32*)(p + 0x220) = 0;
    }
    n = *(s32*)(p + 0x1bc);
    if (*(s32*)(p + 0x1d0) != n + 1 && n > 0) {
        p[0x26c] = 0xff;
        (((T803ED83C*)p)->*lbl_804B0754[5])();
    } else {
        u8* q = lbl_80529DEC;
        if (fn_80309C4C(lbl_8053AD30, 0x1100, q[0x23c] + 1) != 0) {
            if (*(s32*)(p + 0x1b8) < 3) {
                *(s32*)(p + 0x1dc) = 0xf;
                fn_803E3320(p);
            }
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else if (fn_80309C4C(lbl_8053AD30, 0x200, q[0x23c] + 1) != 0) {
            *(s32*)(p + 0x1dc) = 2;
            (((T803ED83C*)p)->*lbl_804B0754[11])();
            fn_80458880(lbl_8053AF80, 0xc, -1);
        } else if (fn_80309A9C(lbl_8053AD30, 4, q[0x23c] + 1) != 0) {
            if (*(s32*)(p + 0x1b8) == 1) {
                *(s32*)(p + 0x1b8) = 2;
            } else {
                *(s32*)(p + 0x1b8) = 1;
            }
            *(s16*)(p + 0x254) = 1;
            *(s32*)(p + 0x1e0) = 0x1e;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        } else if (fn_80309A9C(lbl_8053AD30, 8, q[0x23c] + 1) != 0) {
            if (*(s32*)(p + 0x1b8) == 1) {
                *(s32*)(p + 0x1b8) = 2;
            } else {
                *(s32*)(p + 0x1b8) = 1;
            }
            *(s16*)(p + 0x254) = 1;
            *(s32*)(p + 0x1e0) = 0x1e;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    }
    *(s32*)(p + 0x1e0) += 1;
    if (*(s32*)(p + 0x1e0) >= 0x3c) {
        *(s32*)(p + 0x1e0) = 0;
    }
}

extern "C" void fn_80456154(void* p);
extern "C" s32 fn_8030AAF4(s32 i);
extern "C" u8 fn_8030A308(void* a, s32 b);
extern "C" u8 fn_8030A3B0(void* a, s32 b);
extern "C" void* lbl_8053AD30;
extern "C" u8* lbl_8053AAF8;
struct T803ED83C;
typedef void (T803ED83C::*PMF803ED83C)();
extern PMF803ED83C lbl_804B08BC[];
extern "C" void fn_8013B490(void* p);
extern "C" void* lbl_8053AB10;
extern "C" void* lbl_8053AED8;
extern "C" void* fn_804030C4(u32 tag, const char* name);
extern "C" void fn_80440D78(void* p, void* r);
extern "C" void fn_80440CE4(void* p, void* r);
class Pane803EDA2C {
public:
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void setAlpha(u8 a);
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4C(); virtual void v50(); virtual void v54();
    virtual void v58(); virtual void v5C(); virtual void v60(); virtual void v64();
    virtual void v68(); virtual void v6C(); virtual void v70(); virtual void v74();
    virtual void v78(); virtual void v7C(); virtual void v80(); virtual void v84();
    virtual void v88(); virtual void v8C(); virtual void v90(); virtual void v94();
    virtual void v98(); virtual void v9C(); virtual void vA0(); virtual void vA4();
    virtual void vA8(); virtual void vAC(); virtual void vB0(); virtual void vB4();
    virtual void vB8(); virtual void vBC(); virtual void vC0(); virtual void vC4();
    virtual void vC8(); virtual void vCC(); virtual void vD0(); virtual void vD4();
    virtual void vD8(); virtual void vDC(); virtual void vE0(); virtual void vE4();
    virtual void vE8();
    virtual void vEC(s32 a, f32 x, f32 y, s32 b, s32 c, f32 w, f32 h);
};
extern PMF803ED83C lbl_804B0A24[];
extern PMF803ED83C lbl_804B0754[];
extern "C" const char lbl_80478920[];
extern "C" const char lbl_80478934[];
extern "C" void fn_803ED83C(u8* p) {
    s32 i;

    *(s32*)(p + 0x1d0) = 0;
    if (*(s32*)(p + 0x1bc) == 0) {
        if (fn_8030A3B0(lbl_8053AD30, fn_8030AAF4(0))) {
            lbl_8053AAF8[0x82] |= 0x10;
            *(s32*)(p + 0x1d0) += 1;
        } else {
            lbl_8053AAF8[0x82] &= ~0x10;
        }
        lbl_8053AAF8[0x82] &= ~0x20;
        lbl_8053AAF8[0x82] &= ~0x40;
        lbl_8053AAF8[0x82] &= ~0x80;
    } else {
        for (i = 0; i < 4; i++) {
            if (i <= *(s32*)(p + 0x1bc)) {
                if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
                    lbl_8053AAF8[0x82] |= (u8)(1 << (i + 4));
                    *(s32*)(p + 0x1d0) += 1;
                } else {
                    lbl_8053AAF8[0x82] &= ~(u8)(1 << (i + 4));
                }
            } else {
                lbl_8053AAF8[0x82] &= ~(u8)(1 << (i + 4));
            }
        }
    }
    if (p[0x26e] == 0 || *(s32*)(p + 0x1d4) == 6) {
        if (*(s32*)(p + 0x1d4) != 0xf) {
            (((T803ED83C*)p)->*lbl_804B08BC[*(s32*)(p + 0x1d4)])();
        } else {
            (((T803ED83C*)p)->*lbl_804B08BC[*(s32*)(p + 0x1d8)])();
        }
        for (i = 0; i < 4; i++, p += 4) {
            fn_80456154(*(void**)(p + 0x7c));
        }
    }
}

extern "C" void fn_803EDA2C(u8* p) {
    fn_8013B490(lbl_8053AB10);
    (*(J2DScreen**)(p + 0x14))->draw(0.0f, 0.0f, *(const J2DGrafContext**)((u8*)lbl_8053AB10 + 0x10));
    if (*(s32*)(p + 0x1d4) != 0xf) {
        (((T803ED83C*)p)->*lbl_804B0A24[*(s32*)(p + 0x1d4)])();
    } else {
        (((T803ED83C*)p)->*lbl_804B0A24[*(s32*)(p + 0x1d8)])();
    }
    if (p[0x26e] != 0) {
        switch (p[0x26e]) {
        case 1:
            if (p[0x26d] >= 0xf5) {
                if (*(s32*)(p + 0x1dc) == 9) {
                    fn_80440D78(lbl_8053AED8, fn_804030C4(0x54494d47, lbl_80478920));
                    fn_80440CE4(lbl_8053AED8, fn_804030C4(0x54494d47, lbl_80478934));
                }
                p[0x26d] = 0xff;
                p[0x26e] = 2;
                (((T803ED83C*)p)->*lbl_804B0754[*(s32*)(p + 0x1dc)])();
            } else {
                p[0x26d] += 10;
            }
            break;
        case 2:
            if (p[0x26d] <= 10) {
                p[0x26d] = 0;
                p[0x26e] = 0;
            } else {
                p[0x26d] -= 10;
            }
            break;
        }
        fn_8013B490(lbl_8053AB10);
        (*(Pane803EDA2C**)(p + 0x60))->setAlpha(p[0x26d]);
        (*(Pane803EDA2C**)(p + 0x60))->vEC(0, 0.0f, 0.0f, 0, 0, 800.0f, 600.0f);
    }
}

extern "C" void fn_804310CC(void* p);
extern "C" u8 fn_8030A388(void* a, s32 b);
extern "C" void fn_803E3564(u8* p);
extern "C" void fn_803EDBF0(u8* param_1, u8 param_2) {
    s32 i;

    fn_804310CC(lbl_8053AEC0);
    switch (param_2) {
    case 1:
        *(s32*)(param_1 + 0x1d4) = 10;
        fn_803E3564(param_1);
        break;
    case 2:
        *(s32*)(param_1 + 0x1d4) = 9;
        fn_803E3564(param_1);
        break;
    default:
        if (fn_8030A388(lbl_8053AD30, fn_8030AAF4(0)) != 0) {
            *(s32*)(param_1 + 0x1bc) = 0;
        } else {
            if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(0)) != 0) {
                *(s32*)(param_1 + 0x1bc) = 0;
                i = 1;
                do {
                    if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(i)) == 0) {
                        break;
                    }
                    i++;
                    *(s32*)(param_1 + 0x1bc) += 1;
                } while (i < 4);
            }
        }
        *(s32*)(param_1 + 0x1d4) = 2;
    *(f32*)(param_1 + 0xf8) = lbl_805436A8;
    (*(J2DPane**)(param_1 + 4))->search(0x506d616462623037ULL)->move(*(f32*)(param_1 + 0xf0), *(f32*)(param_1 + 0xf4) + *(f32*)(param_1 + 0xf8));
    *(f32*)(param_1 + 0xfc) = lbl_8054368C;
    fn_80402E08(*(void**)(param_1 + 0x78), lbl_80543664, *(f32*)(param_1 + 0xfc));
    *(f32*)(param_1 + 0x120) = lbl_805436AC;
    (*(J2DPane**)(param_1 + 4))->search(0x00506e6f70623034ULL)->move(*(f32*)(param_1 + 0x100) + *(f32*)(param_1 + 0x120), *(f32*)(param_1 + 0x110));
    *(f32*)(param_1 + 0x124) = lbl_805436AC;
    (*(J2DPane**)(param_1 + 4))->search(0x00506e6f70623038ULL)->move(*(f32*)(param_1 + 0x104) + *(f32*)(param_1 + 0x124), *(f32*)(param_1 + 0x114));
    *(f32*)(param_1 + 0x128) = lbl_805436AC;
    (*(J2DPane**)(param_1 + 4))->search(0x00506e6f70623132ULL)->move(*(f32*)(param_1 + 0x108) + *(f32*)(param_1 + 0x128), *(f32*)(param_1 + 0x118));
    *(f32*)(param_1 + 0x12c) = lbl_805436AC;
    (*(J2DPane**)(param_1 + 4))->search(0x00506e6f70623136ULL)->move(*(f32*)(param_1 + 0x10c) + *(f32*)(param_1 + 0x12c), *(f32*)(param_1 + 0x11c));
    *(f32*)(param_1 + 0x138) = lbl_805436B0;
    (*(J2DPane**)(param_1 + 4))->search(0x004e646174613032ULL)->move(*(f32*)(param_1 + 0x130) + *(f32*)(param_1 + 0x138), *(f32*)(param_1 + 0x134));
    *(f32*)(param_1 + 0x14c) = lbl_805436B0;
    (*(J2DPane**)(param_1 + 4))->search(0x004e646174613035ULL)->move(*(f32*)(param_1 + 0x13c) + *(f32*)(param_1 + 0x14c), *(f32*)(param_1 + 0x140));
    (*(J2DPane**)(param_1 + 4))->search(0x004e646174613037ULL)->move(*(f32*)(param_1 + 0x144) + *(f32*)(param_1 + 0x14c), *(f32*)(param_1 + 0x148));
    *(s32*)(param_1 + 0x220) = 0;
    *(s32*)(param_1 + 0x1e0) = 0;
    *(s16*)(param_1 + 0x254) = 0;
    *(s32*)(param_1 + 0x1d8) = *(s32*)(param_1 + 0x1d4);
    *(s32*)(param_1 + 0x1d4) = 2;
        break;
    }
    *(s32*)(param_1 + 0x360) = 4;
}

extern "C" void* fn_803EDF94(u8* param_1, s16 param_2) {
    int firstIndex;
    u8* p;

    if (param_1 != 0) {
        *(void**)param_1 = lbl_804B0B00;
        if (*(void**)(param_1 + 0x4) != 0) {
            ((T803EDF94Obj*)*(void**)(param_1 + 0x4))->v08(1);
        }
        *(void**)(param_1 + 0x4) = 0;
        if (*(void**)(param_1 + 0x8) != 0) {
            ((T803EDF94Obj*)*(void**)(param_1 + 0x8))->v08(1);
        }
        *(void**)(param_1 + 0x8) = 0;
        if (*(void**)(param_1 + 0xc) != 0) {
            ((T803EDF94Obj*)*(void**)(param_1 + 0xc))->v08(1);
        }
        *(void**)(param_1 + 0xc) = 0;
        if (*(void**)(param_1 + 0x10) != 0) {
            ((T803EDF94Obj*)*(void**)(param_1 + 0x10))->v08(1);
        }
        *(void**)(param_1 + 0x10) = 0;
        if (*(void**)(param_1 + 0x14) != 0) {
            ((T803EDF94Obj*)*(void**)(param_1 + 0x14))->v08(1);
        }
        *(void**)(param_1 + 0x14) = 0;

        p = param_1;
        for (firstIndex = 0; firstIndex < 4; firstIndex++, p += 4) {
            if (*(void**)(p + 0x18) != 0) {
                ((T803EDF94Obj*)*(void**)(p + 0x18))->v08(1);
            }
            *(void**)(p + 0x18) = 0;
            if (*(void**)(p + 0x38) != 0) {
                ((T803EDF94Obj*)*(void**)(p + 0x38))->v08(1);
            }
            *(void**)(p + 0x38) = 0;
            if (*(void**)(p + 0x28) != 0) {
                ((T803EDF94Obj*)*(void**)(p + 0x28))->v08(1);
            }
            *(void**)(p + 0x28) = 0;
            if (*(void**)(p + 0x48) != 0) {
                ((T803EDF94Obj*)*(void**)(p + 0x48))->v08(1);
            }
            *(void**)(p + 0x48) = 0;
        }

        if (*(void**)(param_1 + 0x64) != 0) {
            ((T803EDF94Obj*)*(void**)(param_1 + 0x64))->v08(1);
        }
        *(void**)(param_1 + 0x64) = 0;

        p = param_1;
        for (int i = 0; i < 4; i++, p += 4) {
            if (*(void**)(p + 0x68) != 0) {
                ((T803EDF94Obj*)*(void**)(p + 0x68))->v08(1);
            }
            *(void**)(p + 0x68) = 0;
        }

        if (*(void**)(param_1 + 0x5c) != 0) {
            ((T803EDF94Obj*)*(void**)(param_1 + 0x5c))->v08(1);
        }
        *(void**)(param_1 + 0x5c) = 0;
        if (*(void**)(param_1 + 0x60) != 0) {
            ((T803EDF94Obj*)*(void**)(param_1 + 0x60))->v08(1);
        }
        *(void**)(param_1 + 0x60) = 0;

        p = param_1;
        for (int i = 0; i < 4; i++, p += 4) {
            if (*(void**)(p + 0x7c) != 0) {
                ((T803EDF94Late*)*(void**)(p + 0x7c))->v30(1);
            }
            *(void**)(p + 0x7c) = 0;
        }

        if (param_2 > 0) {
            delete param_1;
        }
    }
    return param_1;
}

extern "C" void fn_803EE254(u8* self) {
    s32 i;
    u8* base = lbl_80529DEC;
    *(void**)self = lbl_804B0B00;
    *(s32*)(self + 0x1b4) = 0;
    *(s32*)(self + 0x1bc) = *(u8*)(base + 0x23c);
    if (*(s32*)(self + 0x1bc) == 0) {
        *(s32*)(self + 0x1b8) = 1;
    } else {
        *(s32*)(self + 0x1b8) = 0;
    }
    *(s32*)(self + 0x1d0) = 0;
    *(u8*)(self + 0x264) = 0;
    *(u8*)(self + 0x26b) = 0;
    *(u8*)(self + 0x26c) = 0;
    *(s32*)(self + 0x1d8) = 2;
    *(s32*)(self + 0x1d4) = 2;
    *(s32*)(self + 0x1dc) = 0;
    for (i = 0; i < 4; i++) {
        *(s32*)(self + 0x1e0 + i * 4) = 0;
        *(s32*)(self + 0x1f0 + i * 4) = fn_80403414(i);
        *(s32*)(self + 0x200 + i * 4) = fn_804033D4(i);
        *(s32*)(self + 0x210 + i * 4) = fn_8040336C(i);
        *(s32*)(self + 0x220 + i * 4) = 0;
        *(s32*)(self + 0x1c0 + i * 4) = 0;
        *(s16*)(self + 0x254 + i * 2) = 0;
    }
}

extern "C" u32 lbl_804B06A0[];
#pragma opt_propagation off
extern "C" void fn_803F01F4(void) {
    char* registrations = lbl_80528568;
    const u32* b = lbl_804B06A0;
    u32* part0 = lbl_804B06A0 + 45;
    part0[0] = b[0];
    part0[1] = b[1];
    part0[2] = b[2];
    part0[3] = b[3];
    part0[4] = b[4];
    part0[5] = b[5];
    part0[6] = b[6];
    part0[7] = b[7];
    part0[8] = b[8];
    part0[9] = b[9];
    part0[10] = b[10];
    part0[11] = b[11];
    part0[12] = b[12];
    part0[13] = b[13];
    part0[14] = b[14];
    part0[15] = b[15];
    part0[16] = b[16];
    part0[17] = b[17];
    part0[18] = b[18];
    part0[19] = b[19];
    part0[20] = b[20];
    part0[21] = b[21];
    part0[22] = b[22];
    part0[23] = b[23];
    part0[24] = b[24];
    part0[25] = b[25];
    part0[26] = b[26];
    part0[27] = b[27];
    part0[28] = b[28];
    part0[29] = b[29];
    part0[30] = b[30];
    part0[31] = b[31];
    part0[32] = b[32];
    part0[33] = b[33];
    part0[34] = b[34];
    part0[35] = b[35];
    part0[36] = b[36];
    part0[37] = b[37];
    part0[38] = b[38];
    part0[39] = b[39];
    part0[40] = b[40];
    part0[41] = b[41];
    part0[42] = b[42];
    part0[43] = b[43];
    part0[44] = b[44];
    u32* part1 = lbl_804B06A0 + 135;
    part1[0] = b[90];
    part1[1] = b[91];
    part1[2] = b[92];
    part1[3] = b[93];
    part1[4] = b[94];
    part1[5] = b[95];
    part1[6] = b[96];
    part1[7] = b[97];
    part1[8] = b[98];
    part1[9] = b[99];
    part1[10] = b[100];
    part1[11] = b[101];
    part1[12] = b[102];
    part1[13] = b[103];
    part1[14] = b[104];
    part1[15] = b[105];
    part1[16] = b[106];
    part1[17] = b[107];
    part1[18] = b[108];
    part1[19] = b[109];
    part1[20] = b[110];
    part1[21] = b[111];
    part1[22] = b[112];
    part1[23] = b[113];
    part1[24] = b[114];
    part1[25] = b[115];
    part1[26] = b[116];
    part1[27] = b[117];
    part1[28] = b[118];
    part1[29] = b[119];
    part1[30] = b[120];
    part1[31] = b[121];
    part1[32] = b[122];
    part1[33] = b[123];
    part1[34] = b[124];
    part1[35] = b[125];
    part1[36] = b[126];
    part1[37] = b[127];
    part1[38] = b[128];
    part1[39] = b[129];
    part1[40] = b[130];
    part1[41] = b[131];
    part1[42] = b[132];
    part1[43] = b[133];
    part1[44] = b[134];
    u32* part2 = lbl_804B06A0 + 225;
    part2[0] = b[180];
    part2[1] = b[181];
    part2[2] = b[182];
    part2[3] = b[183];
    part2[4] = b[184];
    part2[5] = b[185];
    part2[6] = b[186];
    part2[7] = b[187];
    part2[8] = b[188];
    part2[9] = b[189];
    part2[10] = b[190];
    part2[11] = b[191];
    part2[12] = b[192];
    part2[13] = b[193];
    part2[14] = b[194];
    part2[15] = b[195];
    part2[16] = b[196];
    part2[17] = b[197];
    part2[18] = b[198];
    part2[19] = b[199];
    part2[20] = b[200];
    part2[21] = b[201];
    part2[22] = b[202];
    part2[23] = b[203];
    part2[24] = b[204];
    part2[25] = b[205];
    part2[26] = b[206];
    part2[27] = b[207];
    part2[28] = b[208];
    part2[29] = b[209];
    part2[30] = b[210];
    part2[31] = b[211];
    part2[32] = b[212];
    part2[33] = b[213];
    part2[34] = b[214];
    part2[35] = b[215];
    part2[36] = b[216];
    part2[37] = b[217];
    part2[38] = b[218];
    part2[39] = b[219];
    part2[40] = b[220];
    part2[41] = b[221];
    part2[42] = b[222];
    part2[43] = b[223];
    part2[44] = b[224];
    if (!__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr,
                                 __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, registrations);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (!__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack,
                                 __dt__35JASMemPool_MultiThreaded_8JASTrackFv, registrations + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (!__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel,
                                 __dt__38JASMemPool_MultiThreaded_10JASChannelFv, registrations + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (!__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA,
                                 __dt__29JASMemPool_15JASPoolObj3_FSAFv, registrations + 0x24);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (!__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA,
                                 __dt__29JASMemPool_15JASPoolObj4_FSAFv, registrations + 0x30);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (!__init__memPool___30JASPoolAllocObject_9JAIStream) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream,
                                 __dt__22JASMemPool_9JAIStreamFv, registrations + 0x3c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (!__init__memPool___35JASPoolAllocObject_13JAISoundChild) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild,
                                 __dt__27JASMemPool_13JAISoundChildFv, registrations + 0x48);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (!__init__memPool___27JASPoolAllocObject_6JAISeq) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq,
                                 __dt__19JASMemPool_6JAISeqFv, registrations + 0x54);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (!__init__memPool___26JASPoolAllocObject_5JAISe) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe,
                                 __dt__18JASMemPool_5JAISeFv, registrations + 0x60);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}
#pragma opt_propagation reset
