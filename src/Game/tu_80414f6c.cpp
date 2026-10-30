// TU 0x80414f6c-0x80418b64.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/JFramework/JFWDisplay.h"
extern u8* lbl_8053AAF8;
extern void* lbl_8053AF80;
extern u8 lbl_80529DEC[];
extern u8 lbl_8050EC80[];
extern const u64 lbl_8048D198[];
extern const s32 lbl_8048D2B0[];
extern "C" void fn_803832BC(void*,s32,s32,s32,s32);
extern "C" char* getStringPtr__10J2DTextBoxCFv(void*);
extern "C" JGeometry::TBox2f* getBounds__7J2DPaneFv(void*);
extern "C" char* strcpy(char*,const char*);
extern "C" void fn_80458880(void*,s32,s32);
extern "C" void fn_80458F9C(void*,s32);
extern "C" void* fn_80309A9C(void*,s32,s32);
extern "C" void fn_8042EDAC(void*,s32,s32);


// ---- from src/Game/fn_8041769C_dtor.cpp ----
// vtable slot 2 (byte offset 8) - see [[reference_fsa_virtual_dispatch_codegen_trick]]
// for why this is a real `virtual` member rather than a manual cast dispatch.
struct DtorSlot2 {
    virtual void destroy(s32 freeFlag);
};

extern "C" void fn_8042EB14(void* a);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B1378[];
extern void* lbl_8053AEC4;
extern void* lbl_8053AED8;
extern void* sManager__10JFWDisplay;
extern f32 lbl_805439B8;
extern f32 lbl_805439D8;
extern f32 lbl_805439E8;
extern f32 lbl_805439EC;
extern "C" void fn_8013B490(void* this_);
extern "C" void fn_8042EB98(void* this_);
extern "C" void fn_80440EE8(void* this_);

struct T804170EC_Grc {
    u8 pad0[0x10];
    const J2DGrafContext* ctx;
};
extern T804170EC_Grc* lbl_8053AB10;

struct T804170EC_Color {
    u8 r, g, b, a;
};
extern s32 lbl_8053AE00;
struct T80416BD0_Tags;
extern const T80416BD0_Tags lbl_8048CD50;
struct T80416BD0_Tags {
    u64 first[11];
    u64 second[11];
    u64 third[9];
    u64 fourth[6];
    u64 grid[10][10];
    u64 selected[10];
    u64 locked[10];
    u64 wrappers[15];
    s32 message[12];
    char layout[24];
    char confirm[20];
    char back[20];
};
extern const f32 lbl_805439C8;
extern const f32 lbl_805439CC;
extern const f32 lbl_805439D4;
extern const f32 lbl_805439DC;

// Child object at this+0x24. slot 9 takes an s32; slot 15 takes a u64 (EABI puts it in r5:r6)
// and returns the child it creates.
struct T80416BD0_Child {
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9(s32 v);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual T80416BD0_Child* slot15(u64 name);
};

extern "C" void fn_8042EB24(void* a);
extern "C" void fn_80402E08(void* p, f32 x, f32 y);

struct T80414F6C_Obj {
    u8 pad0[0xe0];
    void* fe0;
};

class TU80414F6C {
public:
    void fn_80414F78();
    void fn_80415028();
    void fn_80416038();
    void fn_804170B0();

    u8 pad0[0x109];
    u8 f109;
    u8 f10a;
    u8 choices[12];
    u8 shuffled[12];
    u8 alphaFirst[11];
    u8 alphaSecond[11];
    u8 alphaThird[9];
    u8 alphaFourth[6];
    u8 alphaGrid[10];
};

typedef void (TU80414F6C::*TU80414F6C_StateFn)();
static TU80414F6C_StateFn lbl_804B1354[3] = {
    &TU80414F6C::fn_80416038,
    &TU80414F6C::fn_80415028,
    &TU80414F6C::fn_80414F78,
};

extern "C" {
BOOL fn_8042EC7C(void*);
BOOL fn_8042EBEC(void*);
void* fn_80309C4C(void*, s32, s32);
extern void* lbl_8053AD30;

void* fn_80414F6C() {
    return ((T80414F6C_Obj*)lbl_8053AE00)->fe0;
}
}

void TU80414F6C::fn_80414F78() {
    switch (f10a) {
    case 0:
        if (fn_8042EC7C(lbl_8053AEC4)) {
            f10a = 1;
        }
        break;
    case 1:
        if (fn_80309C4C(lbl_8053AD30, 0x1300, -1)) {
            f10a = 2;
        }
        break;
    case 2:
        if (fn_8042EBEC(lbl_8053AEC4)) {
            f10a = 0;
            f109 = 1;
        }
        break;
    }
}

#pragma opt_common_subs off
void TU80414F6C::fn_80415028() {
    f32 x; f32 y;
    u8* p=(u8*)this;
    s32 oldRow=*(s32*)(p+0xc);
    s32 oldCol=*(s32*)(p+0x10);
    if(*(s32*)(p+0x1c)>=0){
        --*(s32*)(p+0x20);
        if(*(s32*)(p+0x1c)>0 && *(s32*)(p+0x20)<=0){
            u32* seed=(u32*)(lbl_8053AAF8+0xb4);
            *seed=*seed*0x19660d+0x3c6ef35f;
            u32 bits=(*seed>>9)|0x3f800000;
            s32 n;
            s32 total=*(s16*)(p+0x104);
            n=total-1;
            s32 r=(s32)((f32)n*(*(f32*)&bits-1.0f));
            if(r>=n)r=total-2;
            s32 choice=p[0x117+r];
            s32 count=0;
            for(s32 j=0;j<10;j++){if((*(u16*)(p+0x106)&(u16)(1<<j)) && j!=choice){p[0x117+count]=j;++count;}}
            *(s32*)(p+0x10)=choice%5;*(s32*)(p+0xc)=choice/5;
            s32 selected=*(s32*)(p+0x10)+*(s32*)(p+0xc)*5;
if(selected>=10){
*(s32*)(p+0x14)=30;*(s32*)(p+0x18)=1;fn_803832BC(p+0xe4,0x109,0,0,0);
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3031ULL)),(char*)p+0xe4);
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3032ULL)),(char*)p+0xe4);

}else{
if(*(s32*)(p+0x14)>30)*(s32*)(p+0x14)=0;
if(*(u16*)(p+0x106)&(u16)(1<<selected))fn_803832BC(p+0xe4,lbl_8048D2B0[selected],0,0,0);else p[0xe4]=0;
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3031ULL)),(char*)p+0xe4);
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3032ULL)),(char*)p+0xe4);


const u64* tag = &lbl_8048D198[selected];
x=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x24))->search(*tag))->i.x;
y=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x24))->search(*tag))->i.y;
(*(J2DScreen**)(p+0x24))->search(0x4e646174613034ULL)->move(x,y);
}

            --*(s32*)(p+0x1c);
            if(*(s32*)(p+0x1c)==0)*(s32*)(p+0x20)=20;else *(s32*)(p+0x20)=5;
            fn_80458880(lbl_8053AF80,38,-1);
        }
        if(*(s32*)(p+0x1c)!=0 || *(s32*)(p+0x20)!=0)return;
    }
    if(*(s32*)(p+0x1c)==0){
        s32 selected=*(s32*)(p+0x10)+*(s32*)(p+0xc)*5;
        if(selected>=5)lbl_8050EC80[0x81+0xc8**(s32*)(lbl_8050EC80+0x10)]=1;else lbl_8050EC80[0x81+0xc8**(s32*)(lbl_8050EC80+0x10)]=0;
*(s32*)(lbl_80529DEC+0x128)=selected/4;*(s32*)(lbl_80529DEC+0x12c)=selected%4;
fn_80458F9C(lbl_8053AF80,10);fn_80458880(lbl_8053AF80,11,-1);*(s32*)(p+0xe0)=7;
lbl_80529DEC[0x242]=0;lbl_80529DEC[0x252]=1;

        return;
    }
    if(fn_80309C4C(lbl_8053AD30,0x1000,-1)){
        *(s32*)(p+0xe0)=4;lbl_80529DEC[0x237]=3;fn_80458880(lbl_8053AF80,11,-1);return;
    }
    if(fn_80309C4C(lbl_8053AD30,0x100,-1)){
        s32 selected=*(s32*)(p+0x10)+*(s32*)(p+0xc)*5;
        if(selected>=5)lbl_8050EC80[0x81+0xc8**(s32*)(lbl_8050EC80+0x10)]=1;else lbl_8050EC80[0x81+0xc8**(s32*)(lbl_8050EC80+0x10)]=0;

        if(selected<10){
            if(*(u16*)(p+0x106)&(u16)(1<<selected)){*(s32*)(lbl_80529DEC+0x128)=selected/4;*(s32*)(lbl_80529DEC+0x12c)=selected%4;
fn_80458F9C(lbl_8053AF80,10);fn_80458880(lbl_8053AF80,11,-1);*(s32*)(p+0xe0)=7;
lbl_80529DEC[0x242]=0;lbl_80529DEC[0x252]=0;
}
            else {fn_8042EDAC(lbl_8053AEC4,0x102,0);p[0x10a]=0;p[0x109]=2;}
        }else if(*(s32*)(p+0x1c)==-1){*(s32*)(p+0x1c)=25;*(s32*)(p+0x20)=1;*(s32*)(p+0x18)=1;}
        return;
    }
    if(fn_80309C4C(lbl_8053AD30,0x200,-1)){*(s32*)(p+0xe0)=4;fn_80458880(lbl_8053AF80,11,-1);return;}
    if(fn_80309A9C(lbl_8053AD30,1,-1)){
        --*(s32*)(p+0x10);if(*(s32*)(p+0x10)<0)*(s32*)(p+0x10)=4;
        if(*(s32*)(p+0x10)==oldCol)return;
        s32 selected=*(s32*)(p+0x10)+*(s32*)(p+0xc)*5;
        if(selected>=10 && oldCol+*(s32*)(p+0xc)*5>=10)return;
        if(selected>=10){
*(s32*)(p+0x14)=30;*(s32*)(p+0x18)=1;fn_803832BC(p+0xe4,0x109,0,0,0);
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3031ULL)),(char*)p+0xe4);
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3032ULL)),(char*)p+0xe4);

}else{
if(*(s32*)(p+0x14)>30)*(s32*)(p+0x14)=0;
if(*(u16*)(p+0x106)&(u16)(1<<selected))fn_803832BC(p+0xe4,lbl_8048D2B0[selected],0,0,0);else p[0xe4]=0;
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3031ULL)),(char*)p+0xe4);
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3032ULL)),(char*)p+0xe4);


const u64* tag = &lbl_8048D198[selected];
x=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x24))->search(*tag))->i.x;
y=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x24))->search(*tag))->i.y;
(*(J2DScreen**)(p+0x24))->search(0x4e646174613034ULL)->move(x,y);
}
fn_80458880(lbl_8053AF80,38,-1);return;
    }else if(fn_80309A9C(lbl_8053AD30,2,-1)){
        ++*(s32*)(p+0x10);if(*(s32*)(p+0xc)<2 && *(s32*)(p+0x10)>4)*(s32*)(p+0x10)=0;
        if(*(s32*)(p+0x10)==oldCol)return;
        s32 selected=*(s32*)(p+0x10)+*(s32*)(p+0xc)*5;
        if(selected>=10 && oldCol+*(s32*)(p+0xc)*5>=10)return;
        if(selected>=10){
*(s32*)(p+0x14)=30;*(s32*)(p+0x18)=1;fn_803832BC(p+0xe4,0x109,0,0,0);
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3031ULL)),(char*)p+0xe4);
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3032ULL)),(char*)p+0xe4);

}else{
if(*(s32*)(p+0x14)>30)*(s32*)(p+0x14)=0;
if(*(u16*)(p+0x106)&(u16)(1<<selected))fn_803832BC(p+0xe4,lbl_8048D2B0[selected],0,0,0);else p[0xe4]=0;
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3031ULL)),(char*)p+0xe4);
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3032ULL)),(char*)p+0xe4);


const u64* tag = &lbl_8048D198[selected];
x=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x24))->search(*tag))->i.x;
y=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x24))->search(*tag))->i.y;
(*(J2DScreen**)(p+0x24))->search(0x4e646174613034ULL)->move(x,y);
}
fn_80458880(lbl_8053AF80,38,-1);return;
    }else if(fn_80309A9C(lbl_8053AD30,8,-1)){
        --*(s32*)(p+0xc);if(*(s32*)(p+0xc)<0)*(s32*)(p+0xc)=2;
        if(*(s32*)(p+0xc)==oldRow)return;
        s32 selected=*(s32*)(p+0x10)+*(s32*)(p+0xc)*5;
        if(selected>=10){
*(s32*)(p+0x14)=30;*(s32*)(p+0x18)=1;fn_803832BC(p+0xe4,0x109,0,0,0);
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3031ULL)),(char*)p+0xe4);
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3032ULL)),(char*)p+0xe4);

}else{
if(*(s32*)(p+0x14)>30)*(s32*)(p+0x14)=0;
if(*(u16*)(p+0x106)&(u16)(1<<selected))fn_803832BC(p+0xe4,lbl_8048D2B0[selected],0,0,0);else p[0xe4]=0;
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3031ULL)),(char*)p+0xe4);
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3032ULL)),(char*)p+0xe4);


const u64* tag = &lbl_8048D198[selected];
x=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x24))->search(*tag))->i.x;
y=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x24))->search(*tag))->i.y;
(*(J2DScreen**)(p+0x24))->search(0x4e646174613034ULL)->move(x,y);
}
fn_80458880(lbl_8053AF80,38,-1);return;
    }else if(fn_80309A9C(lbl_8053AD30,4,-1)){
        ++*(s32*)(p+0xc);if(*(s32*)(p+0xc)>2)*(s32*)(p+0xc)=0;
        if(*(s32*)(p+0xc)==oldRow)return;
        s32 selected=*(s32*)(p+0x10)+*(s32*)(p+0xc)*5;
        if(selected>=10){
*(s32*)(p+0x14)=30;*(s32*)(p+0x18)=1;fn_803832BC(p+0xe4,0x109,0,0,0);
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3031ULL)),(char*)p+0xe4);
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3032ULL)),(char*)p+0xe4);

}else{
if(*(s32*)(p+0x14)>30)*(s32*)(p+0x14)=0;
if(*(u16*)(p+0x106)&(u16)(1<<selected))fn_803832BC(p+0xe4,lbl_8048D2B0[selected],0,0,0);else p[0xe4]=0;
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3031ULL)),(char*)p+0xe4);
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3032ULL)),(char*)p+0xe4);


const u64* tag = &lbl_8048D198[selected];
x=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x24))->search(*tag))->i.x;
y=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x24))->search(*tag))->i.y;
(*(J2DScreen**)(p+0x24))->search(0x4e646174613034ULL)->move(x,y);
}
fn_80458880(lbl_8053AF80,38,-1);
    }
}
#pragma opt_common_subs reset
extern "C" u8 fn_80402940(void* obj, s32 idx, f32 a, f32 b, s32 c);
extern const f32 lbl_805439D0;

// Sets the alpha of n panes keyed by keys[] to their base alpha (p[flag + i]) scaled by rate.
static inline void fadeKeys(u8* p, const u64* keys, s32 n, s32 flag, f32 rate) {
    for (s32 i = 0; i < n; i++, keys++) {
        T80416BD0_Child* pane = (*(T80416BD0_Child**)(p + 0x24))->slot15(*keys);
        pane->slot9((s32)((f32)p[flag + i] * rate));
    }
}
#pragma opt_common_subs off
void TU80414F6C::fn_80416038() {
    f32 rate;
    f32 full;
    f32 raw;
    u8* p = (u8*)this;
    const T80416BD0_Tags* t = &lbl_8048CD50;
    u8 done0 = 0;
    u8 done1 = 0;
    u8 done2 = 0;
    u8 done3 = 0;
    u8 done4 = 0;
    u8 done5 = 0;
    u8 done6 = 0;
    s32 i;
    s32 j;
    const u64* k;

    *(s16*)(p + 0x102) = *(s16*)(p + 0x102) + 1;

    if (*(s16*)(p + 0x102) > 0) {
        for (i = 0; i < 2; i++) {
            fn_80402940(*(void**)(p + 0x28 + i * 4), 0xf, lbl_805439C8, lbl_805439CC, 0);
        }
        done0 = fn_80402940(*(void**)(p + 0x30), 0xf, lbl_805439C8, lbl_805439CC, 0);
        if (*(s16*)(p + 0x102) < 0xf) {
            rate = (f32)*(s16*)(p + 0x102) / lbl_805439D0;
            if (rate < lbl_805439CC) {
                rate = lbl_805439CC;
            } else if (rate > lbl_805439B8) {
                rate = lbl_805439B8;
            }
            for (k = t->first, i = 0; i < 0xb; i++, k++) {
                T80416BD0_Child* pane = (*(T80416BD0_Child**)(p + 0x24))->slot15(*k);
                pane->slot9((s32)((f32)*(u8*)(p + 0x123 + i) * rate));
            }
        } else {
            full = lbl_805439B8;
            for (k = t->first, i = 0; i < 0xb; i++, k++) {
                T80416BD0_Child* pane = (*(T80416BD0_Child**)(p + 0x24))->slot15(*k);
                pane->slot9((s32)((f32)*(u8*)(p + 0x123 + i) * full));
            }
        }
    }

    if (*(s16*)(p + 0x102) > 0) {
        done1 = fn_80402940(*(void**)(p + 0x34), 0x19, lbl_805439D4, lbl_805439CC, 0);
        if (*(s16*)(p + 0x102) < 0x19) {
            rate = (f32)*(s16*)(p + 0x102) / lbl_805439D8;
            if (rate < lbl_805439CC) {
                rate = lbl_805439CC;
            } else if (rate > lbl_805439B8) {
                rate = lbl_805439B8;
            }
            for (k = t->third, i = 0; i < 9; i++, k++) {
                T80416BD0_Child* pane = (*(T80416BD0_Child**)(p + 0x24))->slot15(*k);
                pane->slot9((s32)((f32)*(u8*)(p + 0x139 + i) * rate));
            }
        } else {
            full = lbl_805439B8;
            for (k = t->third, i = 0; i < 9; i++, k++) {
                T80416BD0_Child* pane = (*(T80416BD0_Child**)(p + 0x24))->slot15(*k);
                pane->slot9((s32)((f32)*(u8*)(p + 0x139 + i) * full));
            }
        }
    }

    if (*(s16*)(p + 0x102) > 0) {
        done2 = fn_80402940(*(void**)(p + 0x38), 0xf, lbl_805439DC, lbl_805439CC, 0);
        for (i = 0; i < 0xf; i++) {
            fn_80402940(*(void**)(p + 0xa4 + i * 4), 0xf, lbl_805439DC, lbl_805439CC, 0);
        }
        if (*(s16*)(p + 0x102) < 0xf) {
            raw = (f32)*(s16*)(p + 0x102) / lbl_805439D0;
            rate = raw;
            if (raw < lbl_805439CC) {
                rate = lbl_805439CC;
            } else if (raw > lbl_805439B8) {
                rate = lbl_805439B8;
            }
            for (k = t->second, i = 0; i < 0xb; i++, k++) {
                T80416BD0_Child* pane = (*(T80416BD0_Child**)(p + 0x24))->slot15(*k);
                pane->slot9((s32)((f32)*(u8*)(p + 0x12e + i) * rate));
            }
            for (i = 0; i < 0xf; i++) {
                u8* o = *(u8**)(p + 0xa4 + i * 4);
                (*(T80416BD0_Child**)(o + 4))->slot9((s32)(raw * (f32)o[0x28]));
            }
        } else {
            for (i = 0; i < 0xf; i++) {
                u8* o = *(u8**)(p + 0xa4 + i * 4);
                (*(T80416BD0_Child**)(o + 4))->slot9(o[0x28]);
            }
            full = lbl_805439B8;
            for (k = t->second, i = 0; i < 0xb; i++, k++) {
                T80416BD0_Child* pane = (*(T80416BD0_Child**)(p + 0x24))->slot15(*k);
                pane->slot9((s32)((f32)*(u8*)(p + 0x12e + i) * full));
            }
        }
    }

    for (i = 0; i < 5; i++) {
        if (*(s16*)(p + 0x102) > i * 2) {
            fn_80402940(*(void**)(p + 0x3c + i * 4), 0xf, lbl_805439C8, lbl_805439CC, 0);
            if (i == 4) {
                done5 = fn_80402940(*(void**)(p + 0x6c + i * 4), 0xf, lbl_805439C8, lbl_805439CC, 0);
            } else {
                fn_80402940(*(void**)(p + 0x6c + i * 4), 0xf, lbl_805439C8, lbl_805439CC, 0);
            }
            s32 d = *(s16*)(p + 0x102) - i * 2;
            if (d < 0xf) {
                rate = (f32)d / lbl_805439D0;
                if (rate < lbl_805439CC) {
                    rate = lbl_805439CC;
                } else if (rate > lbl_805439B8) {
                    rate = lbl_805439B8;
                }
                for (j = 0; j < 0xa; j++) {
                    if (t->grid[i][j] != 0) {
                        T80416BD0_Child* pane = (*(T80416BD0_Child**)(p + 0x24))->slot15(t->grid[i][j]);
                        pane->slot9((s32)((f32)*(u8*)(p + 0x148 + j) * rate));
                    }
                }
            } else {
                for (j = 0; j < 0xa; j++) {
                    if (t->grid[i][j] != 0) {
                        T80416BD0_Child* pane = (*(T80416BD0_Child**)(p + 0x24))->slot15(t->grid[i][j]);
                        pane->slot9((s32)((f32)*(u8*)(p + 0x148 + j) * lbl_805439B8));
                    }
                }
            }
        }
    }
    for (i = 5; i < 0xa; i++) {
        s32 thr = (i - 5) * 2 + 2;
        if (*(s16*)(p + 0x102) > thr) {
            fn_80402940(*(void**)(p + 0x3c + i * 4), 0xf, lbl_805439C8, lbl_805439CC, 0);
            if (i == 9) {
                done6 = fn_80402940(*(void**)(p + 0x6c + i * 4), 0xf, lbl_805439C8, lbl_805439CC, 0);
            } else {
                fn_80402940(*(void**)(p + 0x6c + i * 4), 0xf, lbl_805439C8, lbl_805439CC, 0);
            }
            s32 d = *(s16*)(p + 0x102) - thr;
            if (d < 0xf) {
                rate = (f32)d / lbl_805439D0;
                if (rate < lbl_805439CC) {
                    rate = lbl_805439CC;
                } else if (rate > lbl_805439B8) {
                    rate = lbl_805439B8;
                }
                for (j = 0; j < 0xa; j++) {
                    if (t->grid[i][j] != 0) {
                        T80416BD0_Child* pane = (*(T80416BD0_Child**)(p + 0x24))->slot15(t->grid[i][j]);
                        pane->slot9((s32)((f32)*(u8*)(p + 0x148 + j) * rate));
                    }
                }
            } else {
                for (j = 0; j < 0xa; j++) {
                    if (t->grid[i][j] != 0) {
                        T80416BD0_Child* pane = (*(T80416BD0_Child**)(p + 0x24))->slot15(t->grid[i][j]);
                        pane->slot9((s32)((f32)*(u8*)(p + 0x148 + j) * lbl_805439B8));
                    }
                }
            }
        }
    }

    if (*(s16*)(p + 0x102) > 8) {
        done3 = fn_80402940(*(void**)(p + 0x9c), 0xf, lbl_805439C8, lbl_805439CC, 0);
        s32 d = *(s16*)(p + 0x102) - 8;
        if (d < 0xf) {
            rate = (f32)d / lbl_805439D0;
            if (rate < lbl_805439CC) {
                rate = lbl_805439CC;
            } else if (rate > lbl_805439B8) {
                rate = lbl_805439B8;
            }
            for (k = t->fourth, i = 0; i < 6; i++, k++) {
                T80416BD0_Child* pane = (*(T80416BD0_Child**)(p + 0x24))->slot15(*k);
                pane->slot9((s32)((f32)*(u8*)(p + 0x142 + i) * rate));
            }
        } else {
            full = lbl_805439B8;
            for (k = t->fourth, i = 0; i < 6; i++, k++) {
                T80416BD0_Child* pane = (*(T80416BD0_Child**)(p + 0x24))->slot15(*k);
                pane->slot9((s32)((f32)*(u8*)(p + 0x142 + i) * full));
            }
        }
    }

    if (*(s16*)(p + 0x102) > 0x14) {
        done4 = fn_80402940(*(void**)(p + 0xa0), 0x19, lbl_805439DC, lbl_805439CC, 0);
    }

    if (done0 && done1 && done2 && done3 && done4 && done5 && done6) {
        p[0x109] = 1;
    }
}
#pragma opt_common_subs on
extern "C" void fn_80416BD0(u8* p) {
    u8* slot;
    u8* slotA;
    u8* slotB;
    int k;
    int i;
    const u64* first;
    const u64* t = (const u64*)&lbl_8048CD50;
    first = t;

    fn_8042EB24(lbl_8053AEC4);
    *(s32*)(p + 0x1c) = -1;
    *(s32*)(p + 0x20) = 5;
    *(u8*)(p + 0x109) = 0;
    *(u8*)(p + 0x10a) = 0;
    *(u16*)(p + 0x102) = 0;

    for (i = 0; i < 0xb; i++) {
        T80416BD0_Child* pane = (*(T80416BD0_Child**)(p + 0x24))->slot15(*first);
        pane->slot9((s32)((f32)*(u8*)(p + 0x123 + i) * lbl_805439CC));
        first++;
    }
    {
    const u64* q = t + 11;
    for (i = 0; i < 0xb; i++) {
        T80416BD0_Child* pane = (*(T80416BD0_Child**)(p + 0x24))->slot15(*q);
        pane->slot9((s32)((f32)*(u8*)(p + 0x12e + i) * lbl_805439CC));
        q++;
    }
    }
    {
    const u64* q = t + 22;
    for (i = 0; i < 9; i++) {
        T80416BD0_Child* pane = (*(T80416BD0_Child**)(p + 0x24))->slot15(*q);
        pane->slot9((s32)((f32)*(u8*)(p + 0x139 + i) * lbl_805439CC));
        q++;
    }
    }
    {
    const u64* q = t + 31;
    for (i = 0; i < 6; i++) {
        T80416BD0_Child* pane = (*(T80416BD0_Child**)(p + 0x24))->slot15(*q);
        pane->slot9((s32)((f32)*(u8*)(p + 0x142 + i) * lbl_805439CC));
        q++;
    }

    }
    const u64* row;
    int j;
    s32 outer;
    t += 37;
    for (outer = 0; outer < 0xa; outer++, t += 10) {
        row = t;
        for (j = 0; j < 0xa; j++) {
            if (row[j] != 0) {
                T80416BD0_Child* pane = (*(T80416BD0_Child**)(p + 0x24))->slot15(row[j]);
                pane->slot9((s32)((f32)*(u8*)(p + 0x148 + j) * lbl_805439CC));
            }
        }
    }

    for (k = 0; k < 3; k++) {
        slot = p + 0x28 + k * 4;
        fn_80402E08(*(void**)slot, lbl_805439CC, lbl_805439C8);
        *(u16*)((u8*)*(void**)slot + 0x22) = 0;
    }

    fn_80402E08(*(void**)(p + 0x34), lbl_805439CC, lbl_805439D4);
    *(u16*)((u8*)*(void**)(p + 0x34) + 0x22) = 0;
    fn_80402E08(*(void**)(p + 0x38), lbl_805439CC, lbl_805439DC);
    *(u16*)((u8*)*(void**)(p + 0x38) + 0x22) = 0;

    for (k = 0; k < 0xa; k++) {
        slotA = p + 0x3c + k * 4;
        fn_80402E08(*(void**)slotA, lbl_805439CC, lbl_805439C8);
        *(u16*)((u8*)*(void**)slotA + 0x22) = 0;
        slotB = p + 0x6c + k * 4;
        fn_80402E08(*(void**)slotB, lbl_805439CC, lbl_805439C8);
        *(u16*)((u8*)*(void**)slotB + 0x22) = 0;
    }

    fn_80402E08(*(void**)(p + 0x9c), lbl_805439CC, lbl_805439C8);
    *(u16*)((u8*)*(void**)(p + 0x9c) + 0x22) = 0;
    fn_80402E08(*(void**)(p + 0xa0), lbl_805439CC, lbl_805439DC);
    *(u16*)((u8*)*(void**)(p + 0xa0) + 0x22) = 0;

    T80416BD0_Child* c;
    c = (*(T80416BD0_Child**)(p + 0x24))->slot15(0x0050736375723031ULL);
    *((u8*)c + 0xb0) = 0;
    c = (*(T80416BD0_Child**)(p + 0x24))->slot15(0x0050736375723032ULL);
    *((u8*)c + 0xb0) = 0;
    c = (*(T80416BD0_Child**)(p + 0x24))->slot15(0x0050736375723033ULL);
    *((u8*)c + 0xb0) = 0;
    (*(T80416BD0_Child**)(p + 0x24))->slot15(0x00506f6375723031ULL)->slot9(0);
    (*(T80416BD0_Child**)(p + 0x24))->slot15(0x00506f6375723032ULL)->slot9(0);

    *(s32*)(p + 0xe0) = 6;
}
#pragma opt_common_subs on
void TU80414F6C::fn_804170B0() {
    (((TU80414F6C*)lbl_8053AE00)->*lbl_804B1354[f109])();
}

extern "C" void fn_804170EC(u8* this_) {
    u8* p = this_;
    f32 f31;
    f32 f30;
    s32 idx;
    s32 row;
    s32 col;
    u8* pane;

    row = *(s32*)(p + 0xc);
    col = *(s32*)(p + 0x10);
    idx = col + row * 5;
    JFWDisplay::getManager()->setClearColor(JUtility::TColor(0, 0, 0, 0));
    fn_8013B490(lbl_8053AB10);

    if (*(u8*)(p + 0x109) != 0) {
        if (idx < 0xa) {
            *(s32*)(p + 0x14) += 1;
            if (*(s32*)(p + 0x14) >= 0x1e) {
                *(s32*)(p + 0x14) = 0;
            }
            if (*(s32*)(p + 0x14) < 0xa) {
                pane = (u8*)(*(J2DScreen**)(p + 0x24))->search(0x0050736375723031ULL);
                pane[0xb0] = 1;
                pane = (u8*)(*(J2DScreen**)(p + 0x24))->search(0x0050736375723032ULL);
                pane[0xb0] = 0;
                pane = (u8*)(*(J2DScreen**)(p + 0x24))->search(0x0050736375723033ULL);
                pane[0xb0] = 0;
            } else if (*(s32*)(p + 0x14) < 0x14) {
                pane = (u8*)(*(J2DScreen**)(p + 0x24))->search(0x0050736375723031ULL);
                pane[0xb0] = 0;
                pane = (u8*)(*(J2DScreen**)(p + 0x24))->search(0x0050736375723032ULL);
                pane[0xb0] = 1;
                pane = (u8*)(*(J2DScreen**)(p + 0x24))->search(0x0050736375723033ULL);
                pane[0xb0] = 0;
            } else {
                pane = (u8*)(*(J2DScreen**)(p + 0x24))->search(0x0050736375723031ULL);
                pane[0xb0] = 0;
                pane = (u8*)(*(J2DScreen**)(p + 0x24))->search(0x0050736375723032ULL);
                pane[0xb0] = 0;
                pane = (u8*)(*(J2DScreen**)(p + 0x24))->search(0x0050736375723033ULL);
                pane[0xb0] = 1;
            }
            idx = 0;
        } else {
            s32 sq;
            *(s32*)(p + 0x14) += 1;
            if (*(s32*)(p + 0x14) >= 0x3c) {
                *(s32*)(p + 0x14) = 0;
            }
            if (*(s32*)(p + 0x14) < 0x1e) {
                sq = *(s32*)(p + 0x14) * *(s32*)(p + 0x14);
                f31 = (f32)sq / lbl_805439E8;
            } else {
                sq = (*(s32*)(p + 0x14) - 0x1e) * (*(s32*)(p + 0x14) - 0x1e);
                f31 = lbl_805439B8 - (f32)sq / lbl_805439E8;
            }
            pane = (u8*)(*(J2DScreen**)(p + 0x24))->search(0x0050736375723031ULL);
            pane[0xb0] = 0;
            pane = (u8*)(*(J2DScreen**)(p + 0x24))->search(0x0050736375723032ULL);
            pane[0xb0] = 0;
            pane = (u8*)(*(J2DScreen**)(p + 0x24))->search(0x0050736375723033ULL);
            pane[0xb0] = 0;
            idx = (s32)(f31 * (f32)*(u8*)(p + 0x108));
        }

        if (*(s32*)(p + 0x18) > 0) {
            s32 t = 10 - *(s32*)(p + 0x18);
            if (*(s32*)(p + 0x18) < 5) {
                t = *(s32*)(p + 0x18);
            }
            if (*(s32*)(p + 0x18) >= 10) {
                *(s32*)(p + 0x18) = 0;
            } else {
                *(s32*)(p + 0x18) += 1;
            }
            f30 = lbl_805439EC * (f32)(t * t) / lbl_805439D8;
            f31 = (*(J2DScreen**)(p + 0x24))->search(0x004E646174613035ULL)->getBounds()->i.x;
            (*(J2DScreen**)(p + 0x24))->search(0x004E646174613035ULL)->move(f31, *(f32*)(p + 0x4) + f30);
            f31 = (*(J2DScreen**)(p + 0x24))->search(0x00506F6375723032ULL)->getBounds()->i.x;
            (*(J2DScreen**)(p + 0x24))->search(0x00506F6375723032ULL)->move(f31, *(f32*)(p + 0x8) + f30);
        }
            ((T80416BD0_Child*)(*(J2DScreen**)(p + 0x24))->search(0x00506F6375723031ULL))->slot9(idx);
            ((T80416BD0_Child*)(*(J2DScreen**)(p + 0x24))->search(0x00506F6375723032ULL))->slot9(idx);

    }
        (*(J2DScreen**)(p + 0x24))->draw(lbl_805439CC, lbl_805439CC, lbl_8053AB10->ctx);

    if (*(u8*)(p + 0x109) == 2) {
        fn_8042EB98(lbl_8053AEC4);
    }
        fn_80440EE8(lbl_8053AED8);
}

// actor@lbl_804B1378: destructor (0x1E0). Resets the vtable pointer, then
// tears down a large family of owned sub-object slots via real virtual
// dispatch (vtable slot 2, freeFlag=1): 1 single slot (0x24), a 3-element
// array (0x28-0x30), 2 more single slots (0x34/0x38), TWO parallel
// 10-element arrays walked together (0x3c-0x64 and 0x6c-0x94), 1 more
// single slot (0x9c), and a 15-element array (0xa4-0xe0). Always clears
// the global lbl_8053AE00, then conditionally chains to the shared base
// dtor `__dl__FPv` when `how > 0`.
extern "C" void* fn_8041769C(void* this_, s16 how) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B1378;
        fn_8042EB14(lbl_8053AEC4);

        char* p = (char*)this_;
        DtorSlot2* single1 = *(DtorSlot2**)(p + 0x24);
        if (single1 != 0) {
            single1->destroy(1);
        }
        *(void**)(p + 0x24) = 0;

        for (s32 i = 0; i < 3; i++) {
            char* slot = p + 0x28 + i * 4;
            DtorSlot2* obj = *(DtorSlot2**)slot;
            if (obj != 0) {
                obj->destroy(1);
            }
            *(void**)slot = 0;
        }

        DtorSlot2* single2 = *(DtorSlot2**)(p + 0x34);
        if (single2 != 0) {
            single2->destroy(1);
        }
        *(void**)(p + 0x34) = 0;

        DtorSlot2* single3 = *(DtorSlot2**)(p + 0x38);
        if (single3 != 0) {
            single3->destroy(1);
        }
        *(void**)(p + 0x38) = 0;

        for (s32 i = 0; i < 0xa; i++) {
            char* slotA = p + 0x3c + i * 4;
            DtorSlot2* objA = *(DtorSlot2**)slotA;
            if (objA != 0) {
                objA->destroy(1);
            }
            *(void**)slotA = 0;

            char* slotB = p + 0x6c + i * 4;
            DtorSlot2* objB = *(DtorSlot2**)slotB;
            if (objB != 0) {
                objB->destroy(1);
            }
            *(void**)slotB = 0;
        }

        DtorSlot2* single4 = *(DtorSlot2**)(p + 0x9c);
        if (single4 != 0) {
            single4->destroy(1);
        }
        *(void**)(p + 0x9c) = 0;

        for (s32 i = 0; i < 0xf; i++) {
            char* slot = p + 0xa4 + i * 4;
            DtorSlot2* obj = *(DtorSlot2**)slot;
            if (obj != 0) {
                obj->destroy(1);
            }
            *(void**)slot = 0;
        }

        lbl_8053AE00 = 0;
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern void* lbl_804AF86C[];
extern u8* lbl_8053AD78;
extern "C" void* __nw__FUl(u32);
extern "C" void fn_80402F04(void*, void*);
extern "C" void* fn_804030C4(u32, const char*);
extern "C" void fn_80440D78(void*, void*);
extern "C" void fn_80440CE4(void*, void*);
extern "C" u8 fn_803B9120(s32);
static inline void dataSelectChild(u8* p, s32 offset, u64 key) {
    void* child = __nw__FUl(0x2c);
    if (child) *(void**)child = lbl_804AF86C;
    *(void**)(p + offset) = child;
    fn_80402F04(*(void**)(p + offset), (*(J2DScreen**)(p + 0x24))->search(key));
}
static inline void dataSelectFont(J2DScreen* screen, u64 key, JUTFont* font) {
    ((J2DTextBox*)screen->search(key))->setFont(font);
}
#pragma opt_common_subs off
extern "C" void* fn_8041787C(void* this_) {
    f32 y; f32 x;
    u8* p = (u8*)this_;
    const T80416BD0_Tags& t=lbl_8048CD50;
    const u64* a;
    const u64* b;
    u8* slot;
    int i;
    *(void**)p = lbl_804B1378;
    lbl_8053AE00 = (s32)p;
    p[0xe4] = 0;
    *(J2DScreen**)(p + 0x24) = new J2DScreen();
    (*(J2DScreen**)(p + 0x24))->setPriority(t.layout,0x1100000,*(JKRArchive**)(lbl_80529DEC+0x34));
    dataSelectFont(*(J2DScreen**)(p+0x24),0x546f6d3031ULL,*(JUTFont**)(lbl_8053AD78+0x154));
    dataSelectFont(*(J2DScreen**)(p+0x24),0x546f6d3032ULL,*(JUTFont**)(lbl_8053AD78+0x154));
    dataSelectFont(*(J2DScreen**)(p+0x24),0x54736e3031ULL,*(JUTFont**)(lbl_8053AD78+0x154));
    dataSelectFont(*(J2DScreen**)(p+0x24),0x54736e3032ULL,*(JUTFont**)(lbl_8053AD78+0x154));
    fn_803832BC(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x546f6d3031ULL)),0x100,0,0,0);
    fn_803832BC(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x546f6d3032ULL)),0x100,0,0,0);
    for(a=t.first,b=t.second,i=0;i<11;i++,a++,b++){
        u8 alpha=((u8*)(*(J2DScreen**)(p+0x24))->search(*a))[0xb2];
        slot=p+i;
        slot[0x123]=alpha;
        slot[0x12e]=((u8*)(*(J2DScreen**)(p+0x24))->search(*b))[0xb2];
    }
    for(i=0,b=t.third;i<9;i++,b++) p[313+i]=((u8*)(*(J2DScreen**)(p+0x24))->search(*b))[0xb2];
    for(i=0,b=t.fourth;i<6;i++,b++) p[322+i]=((u8*)(*(J2DScreen**)(p+0x24))->search(*b))[0xb2];
    for(i=0,b=t.grid[0];i<10;i++,b++) p[328+i]=((u8*)(*(J2DScreen**)(p+0x24))->search(*b))[0xb2];
    dataSelectChild(p,40,0x506273626b3032ULL);
    dataSelectChild(p,44,0x506273626b3031ULL);
    dataSelectChild(p,48,0x506273623039ULL);
    dataSelectChild(p,52,0x4e646174613033ULL);
    dataSelectChild(p,56,0x4e646174613032ULL);
    dataSelectChild(p,60,0x4e646174613036ULL);
    dataSelectChild(p,108,0x50627371623031ULL);
    dataSelectChild(p,64,0x4e646174613037ULL);
    dataSelectChild(p,112,0x50627371623032ULL);
    dataSelectChild(p,68,0x4e646174613038ULL);
    dataSelectChild(p,116,0x50627371623033ULL);
    dataSelectChild(p,72,0x4e646174613039ULL);
    dataSelectChild(p,120,0x50627371623034ULL);
    dataSelectChild(p,76,0x4e646174613130ULL);
    dataSelectChild(p,124,0x50627371623035ULL);
    dataSelectChild(p,80,0x4e646174613131ULL);
    dataSelectChild(p,128,0x50627371623036ULL);
    dataSelectChild(p,84,0x4e646174613132ULL);
    dataSelectChild(p,132,0x50627371623037ULL);
    dataSelectChild(p,88,0x4e646174613133ULL);
    dataSelectChild(p,136,0x50627371623038ULL);
    dataSelectChild(p,92,0x4e646174613134ULL);
    dataSelectChild(p,140,0x50627371623039ULL);
    dataSelectChild(p,96,0x4e646174613135ULL);
    dataSelectChild(p,144,0x50627371623130ULL);
    dataSelectChild(p,0x9c,0x4e646174613035ULL);
    for(i=0,a=t.wrappers;i<15;i++,a++){
        slot=p+i*4;
        void* child = __nw__FUl(0x2c);
        if(child) *(void**)child = lbl_804AF86C;
        *(void**)(slot+0xa4)=child;
        fn_80402F04(*(void**)(slot+0xa4),(*(J2DScreen**)(p+0x24))->search(*a));
        ((T80416BD0_Child*)*(void**)((u8*)*(void**)(slot+0xa4)+4))->slot9(0);
    }
    *(void**)(p+0xa0)=*(void**)((u8*)lbl_8053AED8+8);
    fn_80440D78(lbl_8053AED8,fn_804030C4(0x54494d47,t.confirm));
    fn_80440CE4(lbl_8053AED8,fn_804030C4(0x54494d47,t.back));
    *(u16*)(p+0x106)=3;
    { u8* pane=(u8*)(*(J2DScreen**)(p+0x24))->search(*t.locked); pane[0xb0]=0; }
    { u8* pane=(u8*)(*(J2DScreen**)(p+0x24))->search(t.locked[1]); pane[0xb0]=0; }
    for(i=0,b=t.locked;i<8;i++,b++){
        if(fn_803B9120(i)){
            { u8* pane=(u8*)(*(J2DScreen**)(p+0x24))->search(b[2]); pane[0xb0]=0; }
            *(u16*)(p+0x106)|=(u16)(1<<(i+2));
        }else { u8* pane=(u8*)(*(J2DScreen**)(p+0x24))->search(b[2]); pane[0xb0]=1; }
    }
    *(s16*)(p+0x104)=0;
    for(s32 j=0;j<10;j++){
        u8* item=p+j;item[0x10b]=0;item[0x117]=0;
        if(*(u16*)(p+0x106)&(u16)(1<<j)){
            p[0x117+*(s16*)(p+0x104)]=j;
            p[0x10b+*(s16*)(p+0x104)]=j;
            ++*(s16*)(p+0x104);
        }
    }
    p[0x108]=156;
    *(f32*)(p+4)=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x24))->search(0x4e646174613035ULL))->i.y;
    *(f32*)(p+8)=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x24))->search(0x506f6375723032ULL))->i.y;
    if(!lbl_80529DEC[0x252]){
        s32 choice=*(s32*)(lbl_80529DEC+0x12c)+*(s32*)(lbl_80529DEC+0x128)*4;
        *(s32*)(p+0x10)=choice%5;*(s32*)(p+0xc)=choice/5;
    }else{*(s32*)(p+0x10)=0;*(s32*)(p+0xc)=2;}
    *(s32*)(p+0x14)=0;*(s32*)(p+0x18)=0;*(s32*)(p+0x1c)=-1;*(s32*)(p+0x20)=0;
    s32 selected=*(s32*)(p+0x10)+*(s32*)(p+0xc)*5;
if(selected>=10){
*(s32*)(p+0x14)=30;*(s32*)(p+0x18)=1;fn_803832BC(p+0xe4,0x109,0,0,0);
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3031ULL)),(char*)p+0xe4);
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3032ULL)),(char*)p+0xe4);

}else{
if(*(s32*)(p+0x14)>30)*(s32*)(p+0x14)=0;
const s32* messages=t.message;
if(*(u16*)(p+0x106)&(u16)(1<<selected))fn_803832BC(p+0xe4,messages[selected],0,0,0);else p[0xe4]=0;
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3031ULL)),(char*)p+0xe4);
strcpy(getStringPtr__10J2DTextBoxCFv((*(J2DScreen**)(p+0x24))->search(0x54736e3032ULL)),(char*)p+0xe4);


const u64* tag = t.selected;
tag+=selected;
x=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x24))->search(*tag))->i.x;
y=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x24))->search(*tag))->i.y;
(*(J2DScreen**)(p+0x24))->search(0x4e646174613034ULL)->move(x,y);
}

    *(s32*)(p+0xe0)=6;
    return p;
}
#pragma opt_common_subs reset
#include "JSystem/JAudio/JASFakeMatchFSA.h"
