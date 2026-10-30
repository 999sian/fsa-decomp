#include "Game/Actor.h"

extern "C" {
void* fn_802D6A9C();
void fn_802F9974(void* mgr, s32 room, u32 key, s32 n);
}

static inline s32 clampTileCoordinate(s32 v) {
    s32 r = v;
    if (v < 0) r = 0;
    else if (v >= 0x200) r = 0x1ff;
    return r;
}

struct Box4 {
    f32 a, b, c, d;
};

extern "C" f32 lbl_805408C8;
extern "C" f32 lbl_805408DC;
extern "C" f32 lbl_805408F4;
extern "C" f32 lbl_805408FC;
extern "C" f32 lbl_80540900;
extern "C" f32 lbl_80540904;
extern "C" f32 lbl_80540908;
extern "C" f32 lbl_8054090C;
extern "C" f32 lbl_80540948;
extern "C" f32 lbl_8054094C;
extern "C" f32 lbl_80540950;
extern "C" f32 lbl_80540954;
extern "C" f32 lbl_80540958;
extern "C" f32 lbl_8054095C;
extern "C" s32 lbl_8046C8CC[];
extern "C" s32 lbl_8046C8B0[];
extern void* lbl_8053AAF8;
extern void* lbl_8053AB10;


extern "C" char lbl_804A83A0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802ACEA4(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804A83A0;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

#include "Game/ItemBase.h"
#include "JSystem/JKernel/JKRFileLoader.h"
extern "C" void fn_802F745C(void* mgr, Vec* pos, void* resource, DrawRec* rec);
extern "C" void fn_802F6CF4(void* mgr, Vec* pos, void* resource, DrawRec* rec);
extern "C" void* fn_802D6A9C();
extern "C" f64 lbl_805408D0;
extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_805408CC;
extern "C" f32 lbl_805408D8;

#pragma pool_data on
extern "C" const s32 platformTileX[7]={4,4,6,4,6,6,4};
extern "C" const s32 platformTileY[7]={4,4,5,5,6,6,4};
extern "C" const u16 platformTiles[16]={0x1b0,0x1b0,0x1b0,0x1b0,0x1b0,0x1d8,0x1da,0x1b0,0x1b0,0x1d9,0x1db,0x1b0,0x1b0,0x1b0,0x1b0,0x1b0};
extern "C" const f32 platformCenterX[7]={32,32,48,32,64,64,32};
extern "C" const f32 platformCenterY[7]={32,32,40,40,64,64,32};
extern "C" const f32 platformScaleX[7]={1,1,1.5f,1,1,1,1};
extern "C" const f32 platformScaleY[7]={1,1,1.3f,1.3f,1,1,1};
extern "C" const char platformTexture[20]="otosiana_bg_s.bti";
extern "C" const char platformFloor[16]="floor_smp.bin";
extern "C" const char platformSwordLeft[28]="mastersword_left_smp.bin";
extern "C" const char platformHouseLeft[20]="house_left_smp.bin";
extern "C" const char platformTree0[16]="tree0_smp.bin";
extern "C" const char platformTree1[16]="tree1_smp.bin";
extern "C" const char platformField[16]="field_smp.bin";
extern "C" const char platformSwordRight[28]="mastersword_right_smp.bin";
extern "C" const char platformHouseRight[20]="house_right_smp.bin";
extern "C" const char platformGround[16]="jimen_smp.bin";
extern "C" const char platformHouse[16]="house_smp.bin";
#pragma pool_data reset

static inline void platformScale33(f32 m[3][4], const f32 x, const f32 y, const f32 z) {
    m[0][1]=0.0f; m[0][2]=0.0f; m[0][0]=x;
    m[1][0]=0.0f; m[1][1]=y; m[1][2]=0.0f;
    m[2][0]=0.0f; m[2][1]=0.0f; m[2][2]=z;
}

static inline void platformSetVec(Vec* v, f32 x, f32 y, f32 z) {
    v->x=x; v->y=y; v->z=z;
}
extern "C" double cos(double);
extern "C" double sin(double);
extern "C" const f32 sincosTable___5JMath[];
static inline void platformRotation(f32 m[3][4], const f32 ry) {
    f32 sz, sy, sx, cz, cy, cx;
    cx=cos(0.0);
    cy=cos(ry);
    cz=cos(0.0);
    sx=sin(0.0);
    sy=sin(ry);
    sz=sin(0.0);
    m[0][0]=cy*cx;
    m[1][0]=cy*sx;
    m[2][0]=-sy;
    f32 czcx=cz*cx;
    f32 szsy=sz*sy;
    f32 czsx=cz*sx;
    f32 szsx=sz*sx;
    f32 szcx=sz*cx;
    m[0][1]=szsy*cx-czsx;
    m[1][1]=szsy*sx+czcx;
    m[2][1]=sz*cy;
    m[0][2]=czcx*sy+szsx;
    m[1][2]=czsx*sy-szcx;
    m[2][2]=cz*cy;
}
static inline f32 platformSin(f32 angle) {
    if(angle<0.0f) return -sincosTable___5JMath[((u16)(s32)(angle * -325.9493f)&0x7ff)*2];
    return sincosTable___5JMath[((u16)(s32)(325.9493f*angle)&0x7ff)*2];
}
static inline f32 platformCos(f32 angle) {
    if(angle<0.0f)angle=-angle;
    return sincosTable___5JMath[((u16)(s32)(angle * 325.9493f)&0x7ff)*2+1];
}

#pragma opt_propagation on
extern "C" void fn_802ACF04(Actor* a) {
Actor* self=a;
DrawRec rec;
f32 m[3][4];
Vec pos;
rec.b1c=-1;rec.b1d=-2;
m[0][3]=0.0f;m[1][3]=0.0f;m[2][3]=0.0f;
platformScale33(m,platformScaleX[*(s32*)((u8*)self+0x234)],1.0f,platformScaleY[*(s32*)((u8*)self+0x234)]);
rec.w18=m;
void* texture=(*(JKRFileLoader**)((u8*)lbl_8053AAF8+0xa4))->getResource('TIMG',platformTexture);
platformSetVec(&pos,self->field_0C.x+platformCenterX[*(s32*)((u8*)self+0x234)],self->field_0C.y+platformCenterY[*(s32*)((u8*)self+0x234)],self->field_0C.z);
if((s32)self->field_04<8)fn_802F745C(*(void**)((u8*)lbl_8053AB10+0x20),&pos,texture,&rec);
m[0][3]=0.0f;m[1][3]=0.0f;m[2][3]=0.0f;
f32 rotation=*(f32*)((u8*)self+0x248);
{
    f32 sz, sx, cz, cy, cx, sy;
    cx=cos(0.0);cy=cos(rotation);cz=cos(0.0);
    sx=sin(0.0);sy=sin(rotation);sz=sin(0.0);
    m[0][0]=cy*cx;m[1][0]=cy*sx;m[2][0]=-sy;
    f32 czcx=cz*cx, szsy=sz*sy, czsx=cz*sx, szsx=sz*sx, szcx=sz*cx;
    m[0][1]=szsy*cx-czsx;m[1][1]=szsy*sx+czcx;m[2][1]=sz*cy;
    m[0][2]=czcx*sy+szsx;m[1][2]=czsx*sy-szcx;m[2][2]=cz*cy;
}
rec.b1c=-1;rec.b1d=-1;rec.b21=1;rec.w18=m;
switch(*(s32*)((u8*)self+0x234)) {
default:if((s32)self->field_04<8) fn_802F6CF4(*(void**)((u8*)lbl_8053AB10+0x20),&self->field_0C,(*(JKRFileLoader**)((u8*)lbl_8053AAF8+0xa4))->getResource('SMP ',platformFloor),&rec);break;
case 1:if((s32)self->field_04<8) fn_802F6CF4(*(void**)((u8*)lbl_8053AB10+0x20),&self->field_0C,(*(JKRFileLoader**)((u8*)lbl_8053AAF8+0xa4))->getResource('SMP ',platformSwordLeft),&rec);break;
case 2:if((s32)self->field_04<8) fn_802F6CF4(*(void**)((u8*)lbl_8053AB10+0x20),&self->field_0C,(*(JKRFileLoader**)((u8*)lbl_8053AAF8+0xa4))->getResource('SMP ',platformHouseLeft),&rec);break;
case 3:if((s32)self->field_04<8) fn_802F6CF4(*(void**)((u8*)lbl_8053AB10+0x20),&self->field_0C,(*(JKRFileLoader**)((u8*)lbl_8053AAF8+0xa4))->getResource('SMP ',platformTree0),&rec);if((s32)self->field_04<8) fn_802F6CF4(*(void**)((u8*)lbl_8053AB10+0x20),&self->field_0C,(*(JKRFileLoader**)((u8*)lbl_8053AAF8+0xa4))->getResource('SMP ',platformTree1),&rec);break;
case 4:case 5:break;
case 6:if((s32)self->field_04<8) fn_802F6CF4(*(void**)((u8*)lbl_8053AB10+0x20),&self->field_0C,(*(JKRFileLoader**)((u8*)lbl_8053AAF8+0xa4))->getResource('SMP ',platformField),&rec);break;
}
m[0][3]=0.0f;m[1][3]=0.0f;m[2][3]=0.0f;
if(*(s32*)((u8*)self+0x234)==3 || *(s32*)((u8*)self+0x234)==4 || *(s32*)((u8*)self+0x234)==5)
platformRotation(m,3.1415927f-*(f32*)((u8*)self+0x248));
else platformRotation(m,-*(f32*)((u8*)self+0x248));
rec.w18=m;
switch(*(s32*)((u8*)self+0x234)) {
default:{
Vec v0;
f32 angle=*(f32*)((u8*)self+0x248);
f32 z=self->field_0C.z;
f32 x;
f32 y=32.0f*platformSin(angle)+self->field_0C.y;
x=(64.0f+self->field_0C.x)-32.0f*platformCos(-angle);
v0.y=y; v0.z=z; v0.x=x;
if((s32)self->field_04<8) fn_802F6CF4(*(void**)((u8*)lbl_8053AB10+0x20),&v0,(*(JKRFileLoader**)((u8*)lbl_8053AAF8+0xa4))->getResource('SMP ',platformFloor),&rec);
}break;
case 1:{
Vec v1;
f32 angle=*(f32*)((u8*)self+0x248);
f32 z=self->field_0C.z;
f32 x;
f32 y=32.0f*platformSin(angle)+self->field_0C.y;
x=(64.0f+self->field_0C.x)-32.0f*platformCos(-angle);
v1.y=y; v1.z=z; v1.x=x;
if((s32)self->field_04<8) fn_802F6CF4(*(void**)((u8*)lbl_8053AB10+0x20),&v1,(*(JKRFileLoader**)((u8*)lbl_8053AAF8+0xa4))->getResource('SMP ',platformSwordRight),&rec);
}break;
case 2:{
Vec v2;
f32 angle=*(f32*)((u8*)self+0x248);
f32 z=self->field_0C.z;
f32 x;
f32 y=48.0f*platformSin(angle)+self->field_0C.y;
x=(96.0f+self->field_0C.x)-48.0f*platformCos(-angle);
v2.y=y; v2.z=z; v2.x=x;
if((s32)self->field_04<8) fn_802F6CF4(*(void**)((u8*)lbl_8053AB10+0x20),&v2,(*(JKRFileLoader**)((u8*)lbl_8053AAF8+0xa4))->getResource('SMP ',platformHouseRight),&rec);
}break;
case 3: {
Vec v3;
platformSetVec(&v3,64.0f+self->field_0C.x,self->field_0C.y,self->field_0C.z);
if((s32)self->field_04<8) fn_802F6CF4(*(void**)((u8*)lbl_8053AB10+0x20),&v3,(*(JKRFileLoader**)((u8*)lbl_8053AAF8+0xa4))->getResource('SMP ',platformTree0),&rec);
Vec v4;
platformSetVec(&v4,64.0f+self->field_0C.x,self->field_0C.y,self->field_0C.z);
if((s32)self->field_04<8) fn_802F6CF4(*(void**)((u8*)lbl_8053AB10+0x20),&v4,(*(JKRFileLoader**)((u8*)lbl_8053AAF8+0xa4))->getResource('SMP ',platformTree1),&rec);
break;
}
case 4:case 5:
rec.b1c=1;rec.b1d=-1;
if(*(s32*)((u8*)self+0x230)==7) {Vec v5;platformSetVec(&v5,96.0f+self->field_0C.x,self->field_0C.y,self->field_0C.z);if((s32)self->field_04<8) fn_802F6CF4(*(void**)((u8*)lbl_8053AB10+0x20),&v5,(*(JKRFileLoader**)((u8*)lbl_8053AAF8+0xa4))->getResource('SMP ',platformGround),&rec);}
else if(*(s32*)((u8*)self+0x230)!=8){Vec v6;platformSetVec(&v6,96.0f+self->field_0C.x,self->field_0C.y,self->field_0C.z);if((s32)self->field_04<8) fn_802F6CF4(*(void**)((u8*)lbl_8053AB10+0x20),&v6,(*(JKRFileLoader**)((u8*)lbl_8053AAF8+0xa4))->getResource('SMP ',platformHouse),&rec);}
break;
case 6:{
Vec v7;
f32 angle=*(f32*)((u8*)self+0x248);
f32 z=self->field_0C.z;
f32 x;
f32 y=32.0f*platformSin(angle)+self->field_0C.y;
x=(64.0f+self->field_0C.x)-32.0f*platformCos(-angle);
v7.y=y; v7.z=z; v7.x=x;
if((s32)self->field_04<8) fn_802F6CF4(*(void**)((u8*)lbl_8053AB10+0x20),&v7,(*(JKRFileLoader**)((u8*)lbl_8053AAF8+0xa4))->getResource('SMP ',platformField),&rec);
}break;
}
}
#pragma opt_propagation reset
extern "C" {
void fn_80239914(void* box, s32 room, void* obj);
Vec* fn_8023E724(s32 idx);
u8 fn_8022F478(s32 idx);
u8 fn_80234F68(s32 idx);
s32 fn_801F2718(Actor* a, u32 fourcc);
void fn_8023A89C(void* box, s32 room, void* out);
u8 fn_8023A97C(s32 idx, void* box, s32 room, void* out);
u8 fn_802D800C(void* mgr, s32 idx);
u16 fn_802F9908(void* mgr, s32 room, u32 key);
void fn_8013CC50(s32 room, Vec* vec, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 f);
void fn_801F0E34(Actor* a, u32 id, s32 n);
void fn_802D79E8(void* mgr, s32 room, s32 n, f32 a, f32 b);
char* fn_802D9C4C(void* mgr);
}
extern "C" f32 lbl_805408EC;
extern "C" f32 lbl_805408F0;
extern "C" f32 lbl_805408F8;
extern "C" f32 lbl_80540910;
extern "C" f32 lbl_80540914;
extern "C" f32 lbl_80540918;
extern "C" f32 lbl_8054091C;
extern "C" f32 lbl_80540920;
extern "C" f64 lbl_80540928;
extern "C" f32 lbl_80540930;
extern "C" f64 lbl_80540938;
extern "C" f32 lbl_80540940;
extern "C" f32 lbl_80540944;
extern "C" void fn_802ADC18(Actor* a) {
    u8* p = (u8*)a;
    Vec pos = a->field_0C;

    switch (*(s32*)(p + 0x234)) {
    case 2:
        a->field_0C.x += lbl_805408EC;
        a->field_0C.y += lbl_805408F4;
        break;
    case 3:
        a->field_0C.x += lbl_805408DC;
        a->field_0C.y += lbl_805408F4;
        break;
    case 4:
    case 5:
        *(f32*)(p + 0x80) = lbl_805408F8;
        *(f32*)(p + 0x84) = lbl_805408F8;
        *(f32*)(p + 0x88) = lbl_805408EC;
        *(f32*)(p + 0x8c) = lbl_805408EC;
        a->field_0C.x += lbl_805408EC;
        a->field_0C.y += lbl_805408EC;
        break;
    default:
        a->field_0C.x += lbl_805408DC;
        a->field_0C.y += lbl_805408DC;
        break;
    }
}

#pragma opt_propagation off
extern "C" void fn_802AEE10(Actor* a) {
    f32 one;
    f32 bx;
    f32 px;
    f32 py;
    f32 ry0;
    s32 i;
    u8* p = (u8*)a;
    f32 zero = 0.0f;
    *(s32*)(p + 0x234) = a->field_90 & 0x7f;
    *(s32*)(p + 0x238) = (a->field_90 >> 7) & 0x1f;
    *(s32*)(p + 0x240) = (a->field_90 >> 12) & 0xfff;
    *(s32*)(p + 0x23c) = (a->field_90 >> 24) & 3;
    *(f32*)(p + 0x248) = zero;

    switch (*(s32*)(p + 0x234)) {
    case 6:
    default:
        if (*(s32*)(p + 0x23c) == 1) {
            a->field_60 = -20.0f;
            a->field_64 = -20.0f;
            a->field_68 = 20.0f;
            a->field_6C = 20.0f;
        } else {
            a->field_60 = -32.0f;
            a->field_64 = -32.0f;
            a->field_68 = 32.0f;
            a->field_6C = 32.0f;
        }
        break;
    case 2:
        a->field_60 = -40.0f;
        a->field_64 = -32.0f;
        a->field_68 = 40.0f;
        a->field_6C = 32.0f;
        break;
    case 3:
        a->field_60 = -24.0f;
        a->field_64 = -32.0f;
        a->field_68 = 24.0f;
        a->field_6C = 32.0f;
        break;
    case 4:
    case 5:
        a->field_60 = -16.0f;
        a->field_64 = -50.0f;
        a->field_68 = 24.0f;
        a->field_6C = 50.0f;
        *(f32*)(p + 0x248) = -0.06f;
        break;
    }

    *(s32*)(p + 0x244) = 0x14;
    if (((u8*)lbl_8053AAF8)[0x7f] == 1) {
        *(s16*)(p + 0x252) = 12;
    } else {
        *(s16*)(p + 0x252) = 13;
    }

    if (*(s32*)(p + 0x234) >= 2) {
        px = a->field_0C.x;
        s32 room = a->field_04;
        u8* mgr = (u8*)fn_802D6A9C();
        Box4 box = *(Box4*)(room < 8 ? mgr + 0xcc : mgr + 0xdc);
        s32* ta = lbl_8046C8CC;
        s32* tb = lbl_8046C8B0;
        ry0 = box.b;
        one = 16.0f;
        bx = box.a;
        for (i = 0; i < tb[*(s32*)(p + 0x234)]; i++) {
            s32 xi = (s32)(px - bx);
            py = a->field_0C.y;
            for (s32 j = 0; j < ta[*(s32*)(p + 0x234)]; j++) {
                s32 yi = (s32)(py - ry0);
                s32 x = clampTileCoordinate(xi);
                if(yi < 0) yi = 0;
                else if(yi >= 0x200) yi = 0x1ff;
                s32 y = yi;
                fn_802F9974(*(void**)((u8*)lbl_8053AB10 + 0x20), a->field_04,
                  ((y << 1) & 0x200) | (x & 0x100) | (y & 0xf0) | ((x >> 4) & 0xf), 6);
                py += one;
            }
            px += one;
        }
    }
    *(s32*)(p + 0x230) = 0;
}
#pragma opt_propagation reset
