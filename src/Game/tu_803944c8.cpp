// TU 0x803944c8-0x803a3484.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"
struct MsgRodata;
extern "C" const MsgRodata lbl_80475768;
#include "JSystem/J2D/J2DPicture.h"
extern void* lbl_8053AAF8;
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/JMessage/resource.h"
#include "JSystem/JMessage/processor.h"
#include "JSystem/JUtility/JUTFont.h"
#include <string.h>
#include <stdio.h>
#include "JSystem/JMessage/control.h"
extern "C" void* __nw__FUl(u32);
extern "C" void fn_8045B46C(void*,s8,void*,s32,s32);
extern "C" const ResTIMG* fn_804030C4(u32,const char*);
extern "C" void __ct__Q28JMessage18TSequenceProcessorFPCQ28JMessage10TReferencePQ28JMessage8TControl(void*,void*,void*);
extern "C" void __ct__Q28JMessage19TRenderingProcessorFPCQ28JMessage10TReference(void*,void*);
extern void* lbl_804AF6D4[];
extern void* lbl_804AF774[];
extern void* lbl_804AF72C[];
extern void* lbl_804AF6E4[];
extern void* __vt__Q28JMessage10TReference[];
extern f32 lbl_8054321C,lbl_80543224,lbl_80543228,lbl_80543240,lbl_8054322C;
struct MsgResourceAccess {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void* get(u32,const char*);
};
extern void* lbl_804AF5A0[];
extern u8 lbl_80529DEC[];


static inline f32 msgRandomUnit() {
    char* rng=(char*)lbl_8053AAF8;
    *(u32*)(rng+0xb4)=*(u32*)(rng+0xb4)*0x19660d+0x3c6ef35f;
    u32 bits=(*(u32*)(rng+0xb4)>>9)|0x3f800000;
    return *(f32*)&bits-1.0f;
}
static inline f32 msgRandom() { return msgRandomUnit(); }
static inline f32 msgRandomScaled(f32 range) { return range*msgRandomUnit(); }
struct MsgCursorInit {
    u8 data[0x60];
    MsgCursorInit(s8 player,void* pos) { fn_8045B46C(this,player,pos,0,8); }
};
struct MsgSequenceInit {
    u8 data[0x64];
    MsgSequenceInit(void* ref,void* control) {
        __ct__Q28JMessage18TSequenceProcessorFPCQ28JMessage10TReferencePQ28JMessage8TControl(this,ref,control);
        *(void**)this=lbl_804AF774;data[0x5c]=1;
    }
};
static inline void msgRenderingSub(u8* sub,void* reference) {
    __ct__Q28JMessage19TRenderingProcessorFPCQ28JMessage10TReference(sub,reference);
    *(void**)sub=lbl_804AF6E4;
    *(s32*)(sub+0x1d8)=0;*(s32*)(sub+0x1dc)=0;sub[0x1e8]=0;
}
struct MsgRenderingInit {
    u8 data[0x2dc];
    MsgRenderingInit(u8* owner) {
        u8* sub;
        void* reference=*(void**)(owner+0xc);
        __ct__Q28JMessage19TRenderingProcessorFPCQ28JMessage10TReference(this,reference);
        *(void**)this=lbl_804AF72C;
        sub=data+0x38;
        __ct__Q28JMessage19TRenderingProcessorFPCQ28JMessage10TReference(sub,reference);
        *(void**)sub=lbl_804AF6E4;
        *(s32*)(sub+0x1d8)=0;*(s32*)(sub+0x1dc)=0;sub[0x1e8]=0;
    }

    MsgRenderingInit(void* ref) {
        u8* sub;
        void* reference=ref;
        __ct__Q28JMessage19TRenderingProcessorFPCQ28JMessage10TReference(this,reference);
        *(void**)this=lbl_804AF72C;
        sub=data+0x38;
        __ct__Q28JMessage19TRenderingProcessorFPCQ28JMessage10TReference(sub,reference);
        *(void**)sub=lbl_804AF6E4;
        *(s32*)(sub+0x1d8)=0;*(s32*)(sub+0x1dc)=0;sub[0x1e8]=0;
    }
};

static inline void* msgNewCursor(s8 player,void* pos) {
    void* cursor=__nw__FUl(0x60);
    if(cursor) fn_8045B46C(cursor,player,pos,0,8);
    return cursor;
}
static inline u8* msgNewSequence(void* ref,void* control) {
    u8* p=(u8*)__nw__FUl(0x64);
    if(p) {
        __ct__Q28JMessage18TSequenceProcessorFPCQ28JMessage10TReferencePQ28JMessage8TControl(p,ref,control);
        *(void**)p=lbl_804AF774;p[0x5c]=1;
    }
    return p;
}
static inline u8* msgNewRendering(void* ref) {
    u8* p=(u8*)__nw__FUl(0x2dc);
    if(p) {
        __ct__Q28JMessage19TRenderingProcessorFPCQ28JMessage10TReference(p,ref);
        *(void**)p=lbl_804AF72C;
        u8* sub=p+0x38;
        __ct__Q28JMessage19TRenderingProcessorFPCQ28JMessage10TReference(sub,ref);
        *(void**)sub=lbl_804AF6E4;
        *(s32*)(sub+0x1d8)=0;*(s32*)(sub+0x1dc)=0;sub[0x1e8]=0;
    }
    return p;
}


// String scratch buffers (snprintf/strcat targets).
static char lbl_8050E518[0x10];
static char lbl_8050E528[0x10];
static char lbl_8050E538[0x10];
static char lbl_8050E548[0x10];

extern void* lbl_8053AD78;
extern u8 lbl_8050EC80[];
extern f32 lbl_805431E4;
extern f32 lbl_805431DC;
extern "C" const char lbl_80543298[8];
extern "C" const char lbl_805432A0[];
extern "C" const char lbl_805432A4[];
extern void* lbl_8053AD30;
extern void* lbl_8053AF80;
extern "C" u32 fn_80309A9C(void* p, s32 a, s32 b);
extern "C" u32 fn_80309D48(void* p, s32 a, s32 b);
extern "C" s32 fn_8030AAF4(s32 a);
extern "C" void fn_803037D4(s32 i, s32 v);
extern "C" void fn_80458880(void* m, s32 p, s32 v);
#pragma dont_inline on
extern "C" void fn_803944C8(void* this_, s32 a, u8 b, u8 c) {
    *(u8*)((char*)this_ + 0x3b1) = 1;
    *(s32*)((char*)lbl_8053AD78 + 0x48) = a;
    *(u8*)((char*)lbl_8053AD78 + 0xea) = b;
    *(u8*)((char*)lbl_8053AD78 + 0xeb) = c;
}
#pragma dont_inline reset

static inline void setTBFontSize(J2DTextBox* tb, J2DTextBox::TFontSize size) {
    f32 x = size.x;
    f32 y = size.y;
    tb->mFontSize.x = x > 0.0f ? x : 0.0f;
    tb->mFontSize.y = y > 0.0f ? y : 0.0f;
}

struct MsgPrint {
    u8 pad0[0x7c];
    f32 m7c;
    f32 m80;
    u8 pad84[0x2c8 - 0x84];
    f32 m2c8;
    void setScale(f32 s, f32 w) {
        m2c8 = s;
        m7c = s;
        m80 = w;
    }
};

struct MsgWindow {
    u8 pad0[0x14];
    MsgPrint* m14;
    u8 pad18[0x20 - 0x18];
    J2DScreen* screen;          // 0x20
    u8 pad24[0x60 - 0x24];
    f32 fontW;                  // 0x60
    f32 fontH;                  // 0x64
    u8 pad68[0xb0 - 0x68];
    f32 lineSpace;              // 0xb0
    f32 scale;                  // 0xb4
};

extern "C" void fn_803944EC(MsgWindow* w, f32 s) {
    w->scale = s;
    J2DTextBox::TFontSize fs;
    fs.x = w->fontW * s;
    fs.y = w->fontH * s;
    setTBFontSize((J2DTextBox*)w->screen->search('Tm01'), fs);
    ((J2DTextBox*)w->screen->search('Tm01'))->setLineSpace(w->lineSpace * s);
    setTBFontSize((J2DTextBox*)w->screen->search('Tm02'), fs);
    ((J2DTextBox*)w->screen->search('Tm02'))->setLineSpace(w->lineSpace * s);
    w->m14->setScale(s, w->fontW);
}

struct MsgColor {
    u8 r, g, b, a;
};

struct MsgDraw {
    u8 pad0[8];
    void* control;              // 0x08
    u8 padC[0x10 - 0xc];
    u8* m10;                    // 0x10
    u8 pad14[0x20 - 0x14];
    J2DScreen* screens[3];
    J2DScreen* screen;          // 0x2c
    J2DPicture* pictures[11];
    J2DPicture* cursor;
    u8 pad60[8];
    u8* icons[12];
    f32 x98;
    f32 y9c;                    // 0x9c
    u8 padA0[0xd8 - 0xa0];
    f32 xd8;                    // 0xd8
    u8 paddc[0xe0 - 0xdc];
    f32 xe0;                    // 0xe0
    f32 ye4;                    // 0xe4
    u8 pade8[0x124 - 0xe8];
    f32 choicesX[3];
    f32 choicesY[3];
    u8 pad13c[0x154-0x13c];
    u32 col1;                   // 0x154
    u32 col2;                   // 0x158
    u8 pad15c[0x164 - 0x15c];
    s32 m164;                   // 0x164
    u8 pad168[0x170 - 0x168];
    s32 len;                    // 0x170
    u8 pad174[0x1aa - 0x174];
    u8 hidden;                  // 0x1aa
    char text1[0x100];          // 0x1ab
    char text2[0x100];          // 0x2ab
    char suffix[5];             // 0x3ab
    u8 dirty;                   // 0x3b0
};

extern "C" void render__Q28JMessage8TControlFv(void* p);
extern "C" void fn_8013B490(void* p);
extern void* lbl_8053AB10;
extern u8 lbl_8050DB0C[];

// NONMATCHING: integer temporary registers.
#pragma opt_propagation on
extern "C" void fn_80394690(MsgDraw* w) {
    if (w->dirty) {
        render__Q28JMessage8TControlFv(w->control);
        w->dirty = 0;
    }
    J2DTextBox* tb = (J2DTextBox*)w->screen->search('Tm01');
    f32 n = 3.0f - (f32)w->m164;
    f32 spacing = tb->mLineSpacing;
    f32 off = n * spacing;
    off = 0.5f * off + 60.0f;
    if (w->hidden == 0) {
        char buf1[0x100];
        char buf2[0x100];
        char tmp[0x20];
        strcpy(buf1, w->text1);
        strcpy(buf2, w->text2);
        if (strlen(w->suffix) != 0) {
            int c2;
            s16 max;
            int cur;
            cur = *(s32*)(w->m10 + 0x4c);
            max = *(s16*)(lbl_8050DB0C + 0x4c);
            buf1[w->len] = 0;
            buf2[w->len] = 0;
            c2 = cur;
            if (cur > max) {
                c2 = 0;
            }
            u8 alpha = (u8)(255.0f * (f32)(max - c2) / (f32)max);
            snprintf(tmp, 0x1e, "\x1b" "CC[%08x]\x1b" "GM[0]", (w->col1 & 0xffffff00) | alpha);
            strcat(buf1, tmp);
            strcat(buf1, w->suffix);
            snprintf(tmp, 0x1e, "\x1b" "CC[%08x]\x1b" "GM[0]", (w->col2 & 0xffffff00) | alpha);
            strcat(buf2, tmp);
            strcat(buf2, w->suffix);
        }
        strcpy(((J2DTextBox*)w->screen->search('Tm01'))->getStringPtr(), buf1);
        strcpy(((J2DTextBox*)w->screen->search('Tm02'))->getStringPtr(), buf2);
        ((J2DTextBox*)w->screen->search('Tm01'))->move(w->xd8, *(f32*)(lbl_8050DB0C + 0x3c) + (w->y9c + off));
        ((J2DTextBox*)w->screen->search('Tm02'))->move(w->xd8 + w->xe0, w->ye4 + (*(f32*)(lbl_8050DB0C + 0x3c) + (w->y9c + off)));
        fn_8013B490(lbl_8053AB10);
        w->screen->draw(0.0f, 0.0f, *(const J2DGrafContext**)((u8*)lbl_8053AB10 + 0x10));
    }
}

extern "C" void fn_8039499C(MsgDraw* w, u8 shake) {
 u8* p=(u8*)w;
 if(!p[0x1aa]) {
 f32 baseX=*(f32*)(p+0xc0),baseY=*(f32*)(p+0xc4);
 f32 line,off,motion;
 u8* icon;
 s32 n;
 J2DScreen* screen=w->screens[p[0x1a2]];
 J2DTextBox* tb=(J2DTextBox*)screen->search('Tm01');
 J2DTextBox* shadow=(J2DTextBox*)screen->search('Tm02');
 J2DPane* name=screen->search(0x4e6d646174613031ULL);
 if(p[0x3b0]) { render__Q28JMessage8TControlFv(*(void**)(p+8));p[0x3b0]=0; }
 if(shake) {screen->search('ROOT')->move(*(f32*)(p+0x11c)+*(f32*)(p+0x98),*(f32*)(lbl_8050DB0C+0x3c)+(*(f32*)(p+0x120)+*(f32*)(p+0x9c)));}
 else {*(f32*)(p+0x98)=0.0f;*(f32*)(p+0x9c)=0.0f;*(f32*)(p+0xa0)=0.0f;screen->search('ROOT')->move(*(f32*)(p+0x11c),*(f32*)(p+0x120));}
 off=0.5f*((3.0f-(f32)*(s32*)(p+0x164))*tb->mLineSpacing);
 if(screen==w->screens[0] && !w->screens[0]->search('Pm00')->isVisible()) {
 w->screens[0]->search('Pm00')->show();
w->screens[0]->search(0x5035623032ULL)->show();
w->screens[0]->search('P5ar')->show();
w->screens[0]->search(0x5034623032ULL)->show();
w->screens[0]->search('P4ar')->show();
w->screens[0]->search(0x5033623032ULL)->show();
w->screens[0]->search('P3ar')->show();
w->screens[0]->search(0x5032623032ULL)->show();
w->screens[0]->search('P2ar')->show();
w->screens[0]->search(0x5031623032ULL)->show();
w->screens[0]->search('P1ar')->show();
 }
 strcpy(tb->getStringPtr(),(char*)p+0x1ab);
 strcpy(shadow->getStringPtr(),(char*)p+0x2ab);
 name->move(baseX,baseY);
 tb->move(*(f32*)(p+0xc8),*(f32*)(p+0xcc)+off);
 tb->resize(100.0f+*(f32*)(p+0xe8),*(f32*)(p+0xec));
 shadow->move(*(f32*)(p+0xc8)+*(f32*)(p+0xd0),*(f32*)(p+0xd4)+(*(f32*)(p+0xcc)+off));
 shadow->resize(100.0f+*(f32*)(p+0xe8),*(f32*)(p+0xec));
 fn_8013B490(lbl_8053AB10);
 screen->draw(0.0f,0.0f,*(J2DGrafContext**)((u8*)lbl_8053AB10+0x10));
 for(n=0;n<12;n++) {
 if(w->icons[n][8]!=0xff) {
 f32 x=(*(f32*)(p+0x98)+baseX)+tb->getBounds()->i.x;
 icon=w->icons[n];
 x=*(f32*)icon+x;
 f32 y=*(f32*)(icon+4)*tb->mLineSpacing+(off+((*(f32*)(p+0x9c)+baseY)+tb->getBounds()->i.y));
 if(*(s32*)(p+0x164)==1) y-=26.0f;
 else if(*(s32*)(p+0x164)==2)y-=13.0f;
 w->pictures[w->icons[n][8]]->draw(x,y,29.0f,29.0f,false,false,false);
 }}
 if(p[0x1a0]) {
 motion=0.0f;
 s16 t=*(s16*)(p+0x19c);
 if(t<0) {
 s32 v;
 if(t>-5)v=-t;else {v=t+10;if(t==-10)*(s16*)(p+0x19c)=0;}
 motion=(-5.0f*(f32)(v*v))/25.0f;
 if(*(s16*)(p+0x19c)!=0)--*(s16*)(p+0x19c);
 } else if(t>0) {
 s32 v;
 if(t<5)v=t;else {v=10-t;if(t==10)*(s16*)(p+0x19c)=0;}
 motion=(5.0f*(f32)(v*v))/25.0f;
 if(*(s16*)(p+0x19c)!=0)++*(s16*)(p+0x19c);
 }
 if(!p[0x1a1]) {
 if(*(s32*)(p+0x164)==2) {
 f32 y=((w->choicesY[*(s32*)(p+0x168)])*tb->mLineSpacing+(off+((*(f32*)(p+0x9c)+baseY)+tb->getBounds()->i.y)))-13.0f;
 f32 x=lbl_805431DC+(w->choicesX[*(s32*)(p+0x168)]+((*(f32*)(p+0x98)+baseX)+tb->getBounds()->i.x));
 (*(J2DPicture**)(p+0x5c))->draw(x,y,19.2f,28.8f,false,false,false);
 } else if(*(s32*)(p+0x164)==3) {
 f32 y=(w->choicesY[*(s32*)(p+0x168)])*tb->mLineSpacing+(off+((*(f32*)(p+0x9c)+baseY)+tb->getBounds()->i.y));
 f32 x=lbl_805431DC+(w->choicesX[*(s32*)(p+0x168)]+((*(f32*)(p+0x98)+baseX)+tb->getBounds()->i.x));
 (*(J2DPicture**)(p+0x5c))->draw(x,y,19.2f,28.8f,false,false,false);
 }
 } else {
 line=w->choicesY[*(s32*)(p+0x168)];
 if(0.0f==line) {
 f32 y=line*tb->mLineSpacing+(off+((*(f32*)(p+0x9c)+baseY)+tb->getBounds()->i.y))-30.0f;
 f32 x=lbl_805431DC+(motion+(w->choicesX[*(s32*)(p+0x168)]+((*(f32*)(p+0x98)+baseX)+tb->getBounds()->i.x)));
 (*(J2DPicture**)(p+0x5c))->draw(x,y,19.2f,28.8f,false,false,false);
 } else if(1.0f==line) {
 f32 y=line*tb->mLineSpacing+(off+((*(f32*)(p+0x9c)+baseY)+tb->getBounds()->i.y))-13.0f;
 f32 x=lbl_805431DC+(motion+(w->choicesX[*(s32*)(p+0x168)]+((*(f32*)(p+0x98)+baseX)+tb->getBounds()->i.x)));
 (*(J2DPicture**)(p+0x5c))->draw(x,y,19.2f,28.8f,false,false,false);
 } else if(2.0f==line) {
 f32 y=line*tb->mLineSpacing+(off+((*(f32*)(p+0x9c)+baseY)+tb->getBounds()->i.y));
 f32 x=lbl_805431DC+(motion+(w->choicesX[*(s32*)(p+0x168)]+((*(f32*)(p+0x98)+baseX)+tb->getBounds()->i.x)));
 (*(J2DPicture**)(p+0x5c))->draw(x,y,19.2f,28.8f,false,false,false);
 }
 }
 --*(s16*)(p+0x198);
 if(*(s16*)(p+0x198)<=0) {
 if(*(s16*)(p+0x19a)==-96)*(s16*)(p+0x19a)=-84;else *(s16*)(p+0x19a)=-96;
 (*(J2DPicture**)(p+0x5c))->rotate(9.6f,14.4f,(J2DRotateAxis)0x7a,(f32)*(s16*)(p+0x19a));
 u32* state=(u32*)((u8*)lbl_8053AAF8+0xb4);
 *state=*state*0x19660d+0x3c6ef35f;
 u32 bits=(*state>>9)|0x3f800000;
 *(s16*)(p+0x198)=(s32)(11.0f*(*(f32*)&bits-1.0f))+10;
 }
 }
 } else if(p[0x3b0]) {render__Q28JMessage8TControlFv(*(void**)(p+8));p[0x3b0]=0;}
}

#pragma opt_propagation reset
// ---- fn_80395480: cursor/icon "pop" animation ----
extern "C" const f32 lbl_80475DA0[5];
extern "C" const f32 lbl_80475DB4[5];
struct MsgPop {
    u8 pad0[0x108];
    f32 x;                    // 0x108
    f32 y;                    // 0x10c
    f32 w;                    // 0x110
    f32 h;                    // 0x114
    u8 pad118[0x194 - 0x118];
    s16 timer;                // 0x194
    s16 fadeTimer;              // 0x196
    u8 pad198[0x1a4 - 0x198];
    u8 alpha;                 // 0x1a4
    u8 childAlpha[4];         // 0x1a5
};

// NONMATCHING (99.9%): add operand order for the cumulative durations.
extern "C" void fn_80395480(MsgPop* self, J2DPane* pane) {
    s32 t0, t1, t2, t3, t4;
    u32 alpha;
    s16* dur = (s16*)(lbl_8050DB0C + 0x286);
    t0 = dur[0];
    t1 = dur[0] + dur[1];
    t2 = t1 + dur[2];
    t3 = t2 + dur[3];
    t4 = t3 + dur[4];
    self->timer++;
    if (pane->getAlpha() < (alpha = self->alpha)) {
        if (self->timer == 10) {
            self->timer = 0;
            pane->setAlpha(self->alpha);
        } else {
            pane->setAlpha(alpha * (self->timer / 10.0f));
        }
    } else {
        f32 sy;
        f32 sx;
        if (self->timer <= t0) {
            sy = sx = 1.0f;
        } else if (self->timer <= t1) {
            f32 d = self->timer - t0;
            f32 e = t1 - t0;
            f32 r = (d * d) / (e * e);
            sx = r * (lbl_80475DA0[1] - lbl_80475DA0[0]) + lbl_80475DA0[0];
            sy = r * (lbl_80475DB4[1] - lbl_80475DB4[0]) + lbl_80475DB4[0];
        } else if (self->timer <= t2) {
            f32 d = self->timer - t1;
            f32 e = t2 - t1;
            f32 r = (d * d) / (e * e);
            sx = r * (lbl_80475DA0[2] - lbl_80475DA0[1]) + lbl_80475DA0[1];
            sy = r * (lbl_80475DB4[2] - lbl_80475DB4[1]) + lbl_80475DB4[1];
        } else if (self->timer <= t3) {
            f32 d = self->timer - t2;
            f32 e = t3 - t2;
            f32 r = (d * d) / (e * e);
            sx = r * (lbl_80475DA0[3] - lbl_80475DA0[2]) + lbl_80475DA0[2];
            sy = r * (lbl_80475DB4[3] - lbl_80475DB4[2]) + lbl_80475DB4[2];
        } else if (self->timer <= t4) {
            f32 d = self->timer - t3;
            f32 e = t4 - t3;
            f32 r = (d * d) / (e * e);
            sx = r * (lbl_80475DA0[4] - lbl_80475DA0[3]) + lbl_80475DA0[3];
            sy = r * (lbl_80475DB4[4] - lbl_80475DB4[3]) + lbl_80475DB4[3];
        } else {
            sy = sx = 1.0f;
            self->timer = 0;
        }
        f32 w = sx * self->w;
        f32 h = sy * self->h;
        pane->resize(w, h);
        pane->move((self->x + self->w / 2) - w / 2, (self->y + self->h) - h);
    }
}

extern "C" const f32 lbl_80475D78[5];
extern "C" const f32 lbl_80475D8C[5];
struct MsgPop2 {
    u8 pad0[0xf8];
    f32 x;                    // 0xf8
    f32 y;                    // 0xfc
    f32 w;                    // 0x100
    f32 h;                    // 0x104
    u8 pad108[0x194 - 0x108];
    s16 timer;                // 0x194
    u8 pad196[0x1a3 - 0x196];
    u8 alpha;                 // 0x1a3
};

// NONMATCHING (99.9%): add operand order for the cumulative durations.
extern "C" void fn_80395834(MsgPop2* self, J2DPane* pane) {
    s32 t0, t1, t2, t3, t4;
    u32 alpha;
    s16* dur = (s16*)(lbl_8050DB0C + 0x286);
    t0 = dur[0];
    t1 = dur[0] + dur[1];
    t2 = t1 + dur[2];
    t3 = t2 + dur[3];
    t4 = t3 + dur[4];
    self->timer++;
    if (pane->getAlpha() < (alpha = self->alpha)) {
        if (self->timer == 10) {
            self->timer = 0;
            pane->setAlpha(self->alpha);
        } else {
            pane->setAlpha(alpha * (self->timer / 10.0f));
        }
    } else {
        f32 sy;
        f32 sx;
        if (self->timer <= t0) {
            sy = sx = 1.0f;
        } else if (self->timer <= t1) {
            f32 d = self->timer - t0;
            f32 e = t1 - t0;
            f32 r = (d * d) / (e * e);
            sx = r * (lbl_80475D78[1] - lbl_80475D78[0]) + lbl_80475D78[0];
            sy = r * (lbl_80475D8C[1] - lbl_80475D8C[0]) + lbl_80475D8C[0];
        } else if (self->timer <= t2) {
            f32 d = self->timer - t1;
            f32 e = t2 - t1;
            f32 r = (d * d) / (e * e);
            sx = r * (lbl_80475D78[2] - lbl_80475D78[1]) + lbl_80475D78[1];
            sy = r * (lbl_80475D8C[2] - lbl_80475D8C[1]) + lbl_80475D8C[1];
        } else if (self->timer <= t3) {
            f32 d = self->timer - t2;
            f32 e = t3 - t2;
            f32 r = (d * d) / (e * e);
            sx = r * (lbl_80475D78[3] - lbl_80475D78[2]) + lbl_80475D78[2];
            sy = r * (lbl_80475D8C[3] - lbl_80475D8C[2]) + lbl_80475D8C[2];
        } else if (self->timer <= t4) {
            f32 d = self->timer - t3;
            f32 e = t4 - t3;
            f32 r = (d * d) / (e * e);
            sx = r * (lbl_80475D78[4] - lbl_80475D78[3]) + lbl_80475D78[3];
            sy = r * (lbl_80475D8C[4] - lbl_80475D8C[3]) + lbl_80475D8C[3];
        } else {
            sy = sx = 1.0f;
            self->timer = 0;
        }
        f32 w = sx * self->w;
        f32 h = sy * self->h;
        pane->resize(w, h);
        pane->move((self->x + self->w / 2) - w / 2, (self->y + self->h) - h);
    }
}

static inline void msgFadeChoice(u8* p, J2DScreen* screen, const u64* tags) {
    MsgPop* self = (MsgPop*)p;
    s32 period;
    s32 half;
    period = *(s16*)(lbl_8050DB0C + 0x284);
    half = period / 2;
    self->fadeTimer++;
    if (self->fadeTimer >= period) self->fadeTimer = 0;
    s32 t = self->fadeTimer;
    s32 v;
    if (t < half) v = t; else v = period - t;
    f32 alpha = (f32)v / (f32)half;
    for (s32 j = 0; j < 4; j++) {
        if (tags[j] != 0) {
            J2DPane* pane = screen->search(tags[j]);
            f32 value = p[j + 0x1a5];
            pane->setAlpha(value * alpha);
        }
    }
}
#pragma opt_common_subs off
static inline void msgRestoreChoice(u8* p, const u64* tags, bool fixed) {
    s32 j = 0;
    const u64* child = tags;
    for (; j < 4; j++, child++) {
        if (*child != 0) {
            J2DScreen* screen = fixed ? ((MsgDraw*)p)->screen : ((MsgDraw*)p)->screens[p[0x1a2]];
            screen->search(*child)->setAlpha(p[j + 0x1a5]);
        }
    }
}

#pragma opt_strength_reduction off
static inline void msgRestoreChoiceTV(u8* p, const u64* tags) {
    int j = 0;
    const u64* child = tags;
    do {
        if (*child != 0) {
            J2DPane* pane = ((MsgDraw*)p)->screen->search(*child);
            u8 alpha = p[j + 0x1a5];
            pane->setAlpha(alpha);
        }
        j++;
        child++;
    } while (j < 4);
}
#pragma opt_strength_reduction reset

#pragma opt_common_subs reset
extern "C" const u64 lbl_80475790[5][4];
#pragma opt_propagation on
extern "C" void fn_80395BE8(void* this_) {
u8* p=(u8*)this_;
s32 n=*(s32*)(p+0x160);
if((*(u16*)(*(u8**)(*(u8**)(p+0x3c0)+0x3b8)+0x28)&0x100) && ((u8*)lbl_8053AAF8)[0x7e]) n=4;
if(p[0x3af]==0 && p[0x1a9]==0) {
*(s16*)(p+0x194)=0;
if(!(*(u16*)(*(u8**)(*(u8**)(p+0x3c0)+0x3b8)+0x28)&0x40)) {
for(s32 i=0;i<5;i++) {
const u64* tag=(const u64*)&lbl_80475768+i;
const u64* tags=lbl_80475790[i];

if(i==n) {if (*(u8*)((u8*)((MsgDraw*)p)->screens[p[0x1a2]]->search(*tag)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screens[p[0x1a2]]->search(*tag); pane->mIsVisible=false; }
msgFadeChoice(p,((MsgDraw*)p)->screens[p[0x1a2]],tags);
if (!*(u8*)((u8*)((MsgDraw*)p)->screens[p[0x1a2]]->search(*tags)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screens[p[0x1a2]]->search(*tags); pane->mIsVisible=true; }} else {if (*(u8*)((u8*)((MsgDraw*)p)->screens[p[0x1a2]]->search(*tag)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screens[p[0x1a2]]->search(*tag); pane->mIsVisible=false; }if (*(u8*)((u8*)((MsgDraw*)p)->screens[p[0x1a2]]->search(*tags)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screens[p[0x1a2]]->search(*tags); pane->mIsVisible=false; }}
}
}
else {if(n!=4)n=0;{
for(s32 i=0;i<5;i++) {
const u64* tag=(const u64*)&lbl_80475768+i;
const u64* tags=lbl_80475790[i];
if(i>=1 && i<=3) continue;
if(i==n) {if (*(u8*)((u8*)((MsgDraw*)p)->screen->search(*tag)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screen->search(*tag); pane->mIsVisible=false; }
msgFadeChoice(p,((MsgDraw*)p)->screen,tags);
if (!*(u8*)((u8*)((MsgDraw*)p)->screen->search(*tags)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screen->search(*tags); pane->mIsVisible=true; }} else {if (*(u8*)((u8*)((MsgDraw*)p)->screen->search(*tag)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screen->search(*tag); pane->mIsVisible=false; }if (*(u8*)((u8*)((MsgDraw*)p)->screen->search(*tags)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screen->search(*tags); pane->mIsVisible=false; }}
}
}}
} else if(*(u32*)(*(u8**)(p+0x10)+0x4c)==99999 && !p[0x1a9]) {
*(s16*)(p+0x196)=0;
if(!(*(u16*)(*(u8**)(*(u8**)(p+0x3c0)+0x3b8)+0x28)&0x40)) {
for(s32 i=0;i<5;i++) {
const u64* tag=(const u64*)&lbl_80475768+i;
const u64* tags=lbl_80475790[i];

if(i==n) {if (!*(u8*)((u8*)((MsgDraw*)p)->screens[p[0x1a2]]->search(*tag)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screens[p[0x1a2]]->search(*tag); pane->mIsVisible=true; }
fn_80395834((MsgPop2*)p,((MsgDraw*)p)->screens[p[0x1a2]]->search(*tag));
if (!*(u8*)((u8*)((MsgDraw*)p)->screens[p[0x1a2]]->search(*tags)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screens[p[0x1a2]]->search(*tags); pane->mIsVisible=true; }
msgRestoreChoice(p,tags,false);} else {if (*(u8*)((u8*)((MsgDraw*)p)->screens[p[0x1a2]]->search(*tag)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screens[p[0x1a2]]->search(*tag); pane->mIsVisible=false; }if (*(u8*)((u8*)((MsgDraw*)p)->screens[p[0x1a2]]->search(*tags)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screens[p[0x1a2]]->search(*tags); pane->mIsVisible=false; }}
}
}
else {if(n!=4)n=0;{
for(s32 i=0;i<5;i++) {
const u64* tag=(const u64*)&lbl_80475768+i;
const u64* tags=lbl_80475790[i];
if(i>=1 && i<=3) continue;
if(i==n) {if (!*(u8*)((u8*)((MsgDraw*)p)->screen->search(*tag)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screen->search(*tag); pane->mIsVisible=true; }
fn_80395480((MsgPop*)p,((MsgDraw*)p)->screen->search(*tag));
if (!*(u8*)((u8*)((MsgDraw*)p)->screen->search(*tags)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screen->search(*tags); pane->mIsVisible=true; }
msgRestoreChoiceTV(p,tags);} else {if (*(u8*)((u8*)((MsgDraw*)p)->screen->search(*tag)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screen->search(*tag); pane->mIsVisible=false; }if (*(u8*)((u8*)((MsgDraw*)p)->screen->search(*tags)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screen->search(*tags); pane->mIsVisible=false; }}
}
}}
} else {
*(s16*)(p+0x194)=0;
*(s16*)(p+0x196)=0;
if(!(*(u16*)(*(u8**)(*(u8**)(p+0x3c0)+0x3b8)+0x28)&0x40)) {
for(s32 i=0;i<5;i++) {
const u64* tag=(const u64*)&lbl_80475768+i;
const u64* tags=lbl_80475790[i];

if (*(u8*)((u8*)((MsgDraw*)p)->screens[p[0x1a2]]->search(*tag)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screens[p[0x1a2]]->search(*tag); pane->mIsVisible=false; }if (*(u8*)((u8*)((MsgDraw*)p)->screens[p[0x1a2]]->search(*tags)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screens[p[0x1a2]]->search(*tags); pane->mIsVisible=false; }
}
}
else {
for(s32 i=0;i<5;i++) {
const u64* tag=(const u64*)&lbl_80475768+i;
const u64* tags=lbl_80475790[i];
if(i>=1 && i<=3) continue;
if (*(u8*)((u8*)((MsgDraw*)p)->screen->search(*tag)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screen->search(*tag); pane->mIsVisible=false; }if (*(u8*)((u8*)((MsgDraw*)p)->screen->search(*tags)+0xb0)) { J2DPane* pane=((MsgDraw*)p)->screen->search(*tags); pane->mIsVisible=false; }
}
}
}
}
#pragma opt_propagation reset

extern "C" void fn_80396884(void* this_) {
    u8* self = (u8*)this_;
    if (self[0x1a0] == 0) {
        return;
    }
    if ((*(u16*)(*(u8**)(self + 0x3b8) + 0x28) & 0x100) != 0) {
        if (self[0x1a1] == 0) {
            if (fn_80309A9C(lbl_8053AD30, 4, -1) != 0) {
                if (self[0x1a0] == 2) {
                    if (*(s32*)(self + 0x168) < 1) {
                        *(s32*)(self + 0x168) = *(s32*)(self + 0x168) + 1;
                        *(s16*)(self + 0x19c) = 1;
                        if ((u32)(*(s32*)(self + 0x148) + 0x10000) != 0xffff) {
                            s32* slots = (s32*)(self + 0x13c);
                            *(s32*)(self + 0x148) = slots[*(s32*)(self + 0x168)];
                        }
                        if (self[0x1aa] != 0) {
                            fn_803037D4(*(s32*)(self + 0x160), 9);
                        } else {
                            fn_80458880(lbl_8053AF80, 0x26, -1);
                        }
                    }
                } else if (self[0x1a0] == 3 && *(s32*)(self + 0x168) < 2) {
                    *(s32*)(self + 0x168) = *(s32*)(self + 0x168) + 1;
                    *(s16*)(self + 0x19c) = 1;
                    if ((u32)(*(s32*)(self + 0x148) + 0x10000) != 0xffff) {
                        s32* slots = (s32*)(self + 0x13c);
                        *(s32*)(self + 0x148) = slots[*(s32*)(self + 0x168)];
                    }
                    if (self[0x1aa] != 0) {
                        fn_803037D4(*(s32*)(self + 0x160), 9);
                    } else {
                        fn_80458880(lbl_8053AF80, 0x26, -1);
                    }
                }
            } else if (fn_80309A9C(lbl_8053AD30, 8, -1) != 0 && *(s32*)(self + 0x168) > 0) {
                *(s32*)(self + 0x168) = *(s32*)(self + 0x168) - 1;
                *(s16*)(self + 0x19c) = 1;
                if ((u32)(*(s32*)(self + 0x148) + 0x10000) != 0xffff) {
                    s32* slots = (s32*)(self + 0x13c);
                    *(s32*)(self + 0x148) = slots[*(s32*)(self + 0x168)];
                }
                if (self[0x1aa] != 0) {
                    fn_803037D4(*(s32*)(self + 0x160), 9);
                } else {
                    fn_80458880(lbl_8053AF80, 0x26, -1);
                }
            }
        } else {
            if (fn_80309A9C(lbl_8053AD30, 2, -1) != 0) {
                if (self[0x1a0] == 2) {
                    if (*(s32*)(self + 0x168) < 1) {
                        *(s32*)(self + 0x168) = *(s32*)(self + 0x168) + 1;
                        *(s16*)(self + 0x19c) = 1;
                        if ((u32)(*(s32*)(self + 0x148) + 0x10000) != 0xffff) {
                            s32* slots = (s32*)(self + 0x13c);
                            *(s32*)(self + 0x148) = slots[*(s32*)(self + 0x168)];
                        }
                        if (self[0x1aa] != 0) {
                            fn_803037D4(*(s32*)(self + 0x160), 9);
                        } else {
                            fn_80458880(lbl_8053AF80, 0x26, -1);
                        }
                    }
                } else if (self[0x1a0] == 3 && *(s32*)(self + 0x168) < 2) {
                    *(s32*)(self + 0x168) = *(s32*)(self + 0x168) + 1;
                    *(s16*)(self + 0x19c) = 1;
                    if ((u32)(*(s32*)(self + 0x148) + 0x10000) != 0xffff) {
                        s32* slots = (s32*)(self + 0x13c);
                        *(s32*)(self + 0x148) = slots[*(s32*)(self + 0x168)];
                    }
                    if (self[0x1aa] != 0) {
                        fn_803037D4(*(s32*)(self + 0x160), 9);
                    } else {
                        fn_80458880(lbl_8053AF80, 0x26, -1);
                    }
                }
            } else if (fn_80309A9C(lbl_8053AD30, 1, -1) != 0 && *(s32*)(self + 0x168) > 0) {
                *(s32*)(self + 0x168) = *(s32*)(self + 0x168) - 1;
                *(s16*)(self + 0x19c) = -1;
                if ((u32)(*(s32*)(self + 0x148) + 0x10000) != 0xffff) {
                    s32* slots = (s32*)(self + 0x13c);
                    *(s32*)(self + 0x148) = slots[*(s32*)(self + 0x168)];
                }
                if ((u32)(*(s32*)(self + 0x148) + 0x10000) != 0xffff) {
                    s32* slots = (s32*)(self + 0x13c);
                    *(s32*)(self + 0x148) = slots[*(s32*)(self + 0x168)];
                }
                if (self[0x1aa] != 0) {
                    fn_803037D4(*(s32*)(self + 0x160), 9);
                } else {
                    fn_80458880(lbl_8053AF80, 0x26, -1);
                }
            }
        }
    } else if (self[0x1a1] == 0) {
        if (fn_80309D48(lbl_8053AD30, fn_8030AAF4(*(s32*)(self + 0x160)), 4) != 0) {
            if (self[0x1a0] == 2) {
                if (*(s32*)(self + 0x168) < 1) {
                    *(s32*)(self + 0x168) = *(s32*)(self + 0x168) + 1;
                    *(s16*)(self + 0x19c) = 1;
                    if ((u32)(*(s32*)(self + 0x148) + 0x10000) != 0xffff) {
                        s32* slots = (s32*)(self + 0x13c);
                        *(s32*)(self + 0x148) = slots[*(s32*)(self + 0x168)];
                    }
                    if (self[0x1aa] != 0) {
                        fn_803037D4(*(s32*)(self + 0x160), 9);
                    } else {
                        fn_80458880(lbl_8053AF80, 0x26, -1);
                    }
                }
            } else if (self[0x1a0] == 3 && *(s32*)(self + 0x168) < 2) {
                *(s32*)(self + 0x168) = *(s32*)(self + 0x168) + 1;
                *(s16*)(self + 0x19c) = 1;
                if ((u32)(*(s32*)(self + 0x148) + 0x10000) != 0xffff) {
                    s32* slots = (s32*)(self + 0x13c);
                    *(s32*)(self + 0x148) = slots[*(s32*)(self + 0x168)];
                }
                if (self[0x1aa] != 0) {
                    fn_803037D4(*(s32*)(self + 0x160), 9);
                } else {
                    fn_80458880(lbl_8053AF80, 0x26, -1);
                }
            }
        } else if (fn_80309D48(lbl_8053AD30, fn_8030AAF4(*(s32*)(self + 0x160)), 8) != 0 && *(s32*)(self + 0x168) > 0) {
            *(s32*)(self + 0x168) = *(s32*)(self + 0x168) - 1;
            *(s16*)(self + 0x19c) = 1;
            if ((u32)(*(s32*)(self + 0x148) + 0x10000) != 0xffff) {
                s32* slots = (s32*)(self + 0x13c);
                *(s32*)(self + 0x148) = slots[*(s32*)(self + 0x168)];
            }
            if (self[0x1aa] != 0) {
                fn_803037D4(*(s32*)(self + 0x160), 9);
            } else {
                fn_80458880(lbl_8053AF80, 0x26, -1);
            }
        }
    } else {
        if (fn_80309D48(lbl_8053AD30, fn_8030AAF4(*(s32*)(self + 0x160)), 2) != 0) {
            if (self[0x1a0] == 2) {
                if (*(s32*)(self + 0x168) < 1) {
                    *(s32*)(self + 0x168) = *(s32*)(self + 0x168) + 1;
                    *(s16*)(self + 0x19c) = 1;
                    if ((u32)(*(s32*)(self + 0x148) + 0x10000) != 0xffff) {
                        s32* slots = (s32*)(self + 0x13c);
                        *(s32*)(self + 0x148) = slots[*(s32*)(self + 0x168)];
                    }
                    if (self[0x1aa] != 0) {
                        fn_803037D4(*(s32*)(self + 0x160), 9);
                    } else {
                        fn_80458880(lbl_8053AF80, 0x26, -1);
                    }
                }
            } else if (self[0x1a0] == 3 && *(s32*)(self + 0x168) < 2) {
                *(s32*)(self + 0x168) = *(s32*)(self + 0x168) + 1;
                *(s16*)(self + 0x19c) = 1;
                if ((u32)(*(s32*)(self + 0x148) + 0x10000) != 0xffff) {
                    s32* slots = (s32*)(self + 0x13c);
                    *(s32*)(self + 0x148) = slots[*(s32*)(self + 0x168)];
                }
                if (self[0x1aa] != 0) {
                    fn_803037D4(*(s32*)(self + 0x160), 9);
                } else {
                    fn_80458880(lbl_8053AF80, 0x26, -1);
                }
            }
        } else if (fn_80309D48(lbl_8053AD30, fn_8030AAF4(*(s32*)(self + 0x160)), 1) != 0 && *(s32*)(self + 0x168) > 0) {
            *(s32*)(self + 0x168) = *(s32*)(self + 0x168) - 1;
            *(s16*)(self + 0x19c) = -1;
            if ((u32)(*(s32*)(self + 0x148) + 0x10000) != 0xffff) {
                s32* slots = (s32*)(self + 0x13c);
                *(s32*)(self + 0x148) = slots[*(s32*)(self + 0x168)];
            }
            if ((u32)(*(s32*)(self + 0x148) + 0x10000) != 0xffff) {
                s32* slots = (s32*)(self + 0x13c);
                *(s32*)(self + 0x148) = slots[*(s32*)(self + 0x168)];
            }
            if (self[0x1aa] != 0) {
                fn_803037D4(*(s32*)(self + 0x160), 9);
            } else {
                fn_80458880(lbl_8053AF80, 0x26, -1);
            }
        }
    }
}

// ---- from src/Game/fn_80396F94.cpp ----
extern "C" void update__Q28JMessage8TControlFv(void* subObj);
extern "C" void fn_80396884(void* this_);
extern "C" void fn_80395BE8(void* this_);

// fn_80396F94 - leading helper: calls update__Q28JMessage8TControlFv(this->0x8), then
// fn_80396884(this), then fn_80395BE8(this), then sets this->0x3b0=1
// (a "done" latch).
extern "C" void fn_80396F94(void* this_) {
    update__Q28JMessage8TControlFv(*(void**)((char*)this_ + 0x8));
    fn_80396884(this_);
    fn_80395BE8(this_);
    *(u8*)((char*)this_ + 0x3b0) = 1;
}

extern "C" void __dt__Q28JMessage19TRenderingProcessorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF72C[];
extern void* lbl_804AF6E4[];

struct MsgRP38 {
    void* vt;
    u8 pad[0x34];
    inline ~MsgRP38() {
        vt = lbl_804AF6E4;
        __dt__Q28JMessage19TRenderingProcessorFv(this, 0);
    }
};
struct MsgRP {
    void* vt;
    u8 pad[0x34];
    MsgRP38 m38;
};

extern "C" void* fn_803972A4(MsgRP* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->vt = lbl_804AF72C;
        this_->m38.~MsgRP38();
        __dt__Q28JMessage19TRenderingProcessorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/fn_80397328_dtor.cpp ----
extern "C" void __dt__Q28JMessage18TSequenceProcessorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF774[];

extern "C" void* fn_80397328(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF774;
        __dt__Q28JMessage18TSequenceProcessorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/fn_80397388_dtor.cpp ----
extern "C" void __dt__Q28JMessage10TReferenceFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF6D4[];

extern "C" void* fn_80397388(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF6D4;
        __dt__Q28JMessage10TReferenceFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}


static inline void msgInitFontSize(MsgWindow* w) {
    f32 scale=lbl_8054321C;
    w->scale=scale;
    J2DTextBox::TFontSize fs;
    fs.x=w->fontW*scale;fs.y=w->fontH*scale;
    setTBFontSize((J2DTextBox*)w->screen->search('Tm01'),fs);
    f32 spacing=w->lineSpace*lbl_8054321C;
    ((J2DTextBox*)w->screen->search('Tm01'))->setLineSpace(spacing);
    setTBFontSize((J2DTextBox*)w->screen->search('Tm02'),fs);
    spacing=w->lineSpace*lbl_8054321C;
    ((J2DTextBox*)w->screen->search('Tm02'))->setLineSpace(spacing);
    f32 s=lbl_8054321C;
    f32 width=w->fontW;
    w->m14->setScale(s,width);
}

static inline void msgSizes(MsgWindow* w,const f32 scale) {
    J2DTextBox::TFontSize fs;
    fs.x=w->fontW*scale;fs.y=w->fontH*scale;
    setTBFontSize((J2DTextBox*)w->screen->search('Tm01'),fs);
    { f32 factor=lbl_8054321C; f32 spacing=w->lineSpace*factor; ((J2DTextBox*)w->screen->search('Tm01'))->setLineSpace(spacing); }
    setTBFontSize((J2DTextBox*)w->screen->search('Tm02'),fs);
    { f32 factor=lbl_8054321C; f32 spacing=w->lineSpace*factor; ((J2DTextBox*)w->screen->search('Tm02'))->setLineSpace(spacing); }
}

static inline void msgLineSpace(J2DScreen* screen,u64 tag,f32 spacing) {
    ((J2DTextBox*)screen->search(tag))->setLineSpace(spacing);
}
static inline void msgFont(J2DScreen* screen,u64 tag,JUTFont* font) {
    ((J2DTextBox*)screen->search(tag))->setFont(font);
}

extern "C" void* fn_803973E8(u8* p, void* font, s32 player, const char* name) {
    const char* r=(const char*)&lbl_80475768;
    const ResTIMG* image;
    *(void**)p=lbl_804AF5A0;
    *(void**)(p+0x3c0)=p;
    *(void**)(p+0x3b8)=font;
    *(void**)(p+0x18)=(*(MsgResourceAccess**)((u8*)lbl_8053AAF8+0xa8))->get(0x3f3f3f3f,name);
    (*(s32*)(p+0x1c))=0;(*(s32*)(p+0x15c))=0;(*(s32*)(p+0x164))=0;(*(s32*)(p+0x16c))=0;(*(u8*)(p+0x1a0))=0;(*(u8*)(p+0x1a1))=0;(*(s32*)(p+0x168))=-1;(*(s32*)(p+0x160))=player;(*(s32*)(p+0x14c))=0;
    (*(u8*)(p+0x3ae))=7;(*(u8*)(p+0x3b0))=0;(*(u8*)(p+0x3af))=1;(*(u8*)(p+0x1aa))=0;
    (*(s32*)(p+0x180))=-1;(*(s32*)(p+0x184))=-1;(*(s32*)(p+0x188))=-1;(*(s32*)(p+0x18c))=-1;
    (*(s16*)(p+0x190))=0;(*(s16*)(p+0x192))=0;(*(s32*)(p+0x178))=0;(*(s32*)(p+0x17c))=0;(*(s16*)(p+0x194))=0;(*(s16*)(p+0x196))=0;(*(u8*)(p+0x1a2))=0;
    (*(f32*)(p+0x98))=0.0f;(*(f32*)(p+0x9c))=0.0f;(*(f32*)(p+0xa0))=0.0f;
    (*(u8*)(p+0x1ab))=0;(*(u8*)(p+0x2ab))=0;(*(u8*)(p+0x3ab))=0;(*(s32*)(p+0x170))=0;(*(s32*)(p+0x154))=-1;(*(s32*)(p+0x158))=255;(*(u8*)(p+0x19f))=0;(*(u8*)(p+0x1a9))=0;(*(u8*)(p+0x3b1))=0;(*(s32*)(p+0x174))=-1;
    for(s32 i=0;i<12;i++) {
        ((MsgDraw*)p)->icons[i]=(u8*)__nw__FUl(12);
        *(f32*)(((MsgDraw*)p)->icons[i])=0.0f;
        *(f32*)(((MsgDraw*)p)->icons[i]+4)=0.0f;
        ((MsgDraw*)p)->icons[i][8]=255;
    }
    (*(u8*)(p+0x3b2))=0;(*(u8*)(p+0x3b3))=0;(*(u8*)(p+0x3b4))=0;(*(f32*)(p+0xa4))=0.0f;(*(f32*)(p+0xa8))=0.0f;(*(f32*)(p+0xac))=0.0f;
    *(void**)(p+0x3bc)=new MsgCursorInit((s8)player,p+0xa4);
    (*(J2DScreen**)(p+0x20))=new J2DScreen;
    (*(J2DScreen**)(p+0x20))->setPriority(r+0x670,0x1100000,*(JKRArchive**)(lbl_80529DEC+0x20));
    (*(J2DScreen**)(p+0x24))=new J2DScreen;
    (*(J2DScreen**)(p+0x24))->setPriority(r+0x680,0x1100000,*(JKRArchive**)(lbl_80529DEC+0x20));
    (*(J2DScreen**)(p+0x28))=new J2DScreen;
    (*(J2DScreen**)(p+0x28))->setPriority(r+0x694,0x1100000,*(JKRArchive**)(lbl_80529DEC+0x20));
    (*(J2DScreen**)(p+0x2c))=new J2DScreen;
    (*(J2DScreen**)(p+0x2c))->setPriority(r+0x6a8,0x1100000,*(JKRArchive**)(lbl_80529DEC+0x20));
    image=fn_804030C4('TIMG',r+0x6b8);
    *(J2DPicture**)(p+0x30)=new J2DPicture(image);
    image=fn_804030C4('TIMG',r+0x6cc);
    *(J2DPicture**)(p+0x34)=new J2DPicture(image);
    image=fn_804030C4('TIMG',r+0x6e0);
    *(J2DPicture**)(p+0x38)=new J2DPicture(image);
    image=fn_804030C4('TIMG',r+0x6f4);
    *(J2DPicture**)(p+0x3c)=new J2DPicture(image);
    image=fn_804030C4('TIMG',r+0x708);
    *(J2DPicture**)(p+0x40)=new J2DPicture(image);
    image=fn_804030C4('TIMG',r+0x718);
    *(J2DPicture**)(p+0x44)=new J2DPicture(image);
    image=fn_804030C4('TIMG',r+0x728);
    *(J2DPicture**)(p+0x48)=new J2DPicture(image);
    image=fn_804030C4('TIMG',r+0x738);
    *(J2DPicture**)(p+0x4c)=new J2DPicture(image);
    image=fn_804030C4('TIMG',r+0x744);
    *(J2DPicture**)(p+0x50)=new J2DPicture(image);
    image=fn_804030C4('TIMG',r+0x754);
    *(J2DPicture**)(p+0x54)=new J2DPicture(image);
    image=fn_804030C4('TIMG',r+0x764);
    *(J2DPicture**)(p+0x58)=new J2DPicture(image);
    (*(f32*)(p+0xb8))=(*(J2DScreen**)(p+0x20))->search('Pm00')->getWidth();
    (*(f32*)(p+0xbc))=(*(J2DScreen**)(p+0x20))->search('Pm00')->getHeight();
    (*(f32*)(p+0xc0))=(*(J2DScreen**)(p+0x20))->search(0x4e6d646174613031ULL)->getBounds()->i.x;
    (*(f32*)(p+0xc4))=(*(J2DScreen**)(p+0x20))->search(0x4e6d646174613031ULL)->getBounds()->i.y;
    (*(f32*)(p+0xc8))=(*(J2DScreen**)(p+0x20))->search('Tm01')->getBounds()->i.x;
    (*(f32*)(p+0xcc))=(*(J2DScreen**)(p+0x20))->search('Tm01')->getBounds()->i.y;
    { f32 first=(*(J2DScreen**)(p+0x20))->search('Tm01')->getBounds()->i.x; (*(f32*)(p+0xd0))=(*(J2DScreen**)(p+0x20))->search('Tm02')->getBounds()->i.x-first; }
    { f32 first=(*(J2DScreen**)(p+0x20))->search('Tm01')->getBounds()->i.y; (*(f32*)(p+0xd4))=(*(J2DScreen**)(p+0x20))->search('Tm02')->getBounds()->i.y-first; }
    (*(f32*)(p+0xe8))=(*(J2DScreen**)(p+0x20))->search('Tm01')->getWidth();
    (*(f32*)(p+0xec))=(*(J2DScreen**)(p+0x20))->search('Tm01')->getHeight();
    (*(f32*)(p+0x11c))=(*(J2DScreen**)(p+0x20))->search('ROOT')->getBounds()->i.x;
    (*(f32*)(p+0x120))=(*(J2DScreen**)(p+0x20))->search('ROOT')->getBounds()->i.y;
    (*(f32*)(p+0xf8))=(*(J2DScreen**)(p+0x20))->search('P1ar')->getBounds()->i.x;
    (*(f32*)(p+0xfc))=(*(J2DScreen**)(p+0x20))->search('P1ar')->getBounds()->i.y;
    (*(f32*)(p+0x100))=(*(J2DScreen**)(p+0x20))->search('P1ar')->getWidth();
    (*(f32*)(p+0x104))=(*(J2DScreen**)(p+0x20))->search('P1ar')->getHeight();
    (*(u8*)(p+0x1a3))=(*(J2DScreen**)(p+0x20))->search('P1ar')->getAlpha();
    (*(u8*)(p+0x1a5))=(*(J2DScreen**)(p+0x20))->search(0x5031623031ULL)->getAlpha();
    (*(u8*)(p+0x1a6))=(*(J2DScreen**)(p+0x20))->search(0x5031623031ULL)->getAlpha();
    (*(u8*)(p+0x1a7))=(*(J2DScreen**)(p+0x20))->search(0x50316e3032ULL)->getAlpha();
    (*(u8*)(p+0x1a8))=(*(J2DScreen**)(p+0x20))->search(0x50316e3031ULL)->getAlpha();
    (*(f32*)(p+0xd8))=(*(J2DScreen**)(p+0x2c))->search('Tm01')->getBounds()->i.x;
    (*(f32*)(p+0xdc))=(*(J2DScreen**)(p+0x2c))->search('Tm01')->getBounds()->i.y;
    (*(f32*)(p+0xf0))=(*(J2DScreen**)(p+0x2c))->search('Tm01')->getWidth();
    (*(f32*)(p+0xf4))=(*(J2DScreen**)(p+0x2c))->search('Tm01')->getHeight();
    { f32 first=(*(J2DScreen**)(p+0x2c))->search('Tm01')->getBounds()->i.x;(*(f32*)(p+0xe0))=(*(J2DScreen**)(p+0x2c))->search('Tm02')->getBounds()->i.x-first; }
    { f32 first=(*(J2DScreen**)(p+0x2c))->search('Tm01')->getBounds()->i.y;(*(f32*)(p+0xe4))=(*(J2DScreen**)(p+0x2c))->search('Tm02')->getBounds()->i.y-first; }
    (*(f32*)(p+0x108))=(*(J2DScreen**)(p+0x2c))->search('P1ar')->getBounds()->i.x;
    (*(f32*)(p+0x10c))=(*(J2DScreen**)(p+0x2c))->search('P1ar')->getBounds()->i.y;
    (*(f32*)(p+0x110))=(*(J2DScreen**)(p+0x2c))->search('P1ar')->getWidth();
    (*(f32*)(p+0x114))=(*(J2DScreen**)(p+0x2c))->search('P1ar')->getHeight();
    (*(u8*)(p+0x1a3))=(*(J2DScreen**)(p+0x2c))->search('P1ar')->getAlpha();
    msgFont((*(J2DScreen**)(p+0x20)),'Tm01',*(JUTFont**)((u8*)lbl_8053AD78+0x154));
    msgFont((*(J2DScreen**)(p+0x24)),'Tm01',*(JUTFont**)((u8*)lbl_8053AD78+0x154));
    msgFont((*(J2DScreen**)(p+0x28)),'Tm01',*(JUTFont**)((u8*)lbl_8053AD78+0x154));
    msgFont((*(J2DScreen**)(p+0x2c)),'Tm01',*(JUTFont**)((u8*)lbl_8053AD78+0x154));
    msgFont((*(J2DScreen**)(p+0x2c)),'Tm02',*(JUTFont**)((u8*)lbl_8053AD78+0x154));
    msgFont((*(J2DScreen**)(p+0x20)),'Tm02',*(JUTFont**)((u8*)lbl_8053AD78+0x154));
    msgFont((*(J2DScreen**)(p+0x24)),'Tm02',*(JUTFont**)((u8*)lbl_8053AD78+0x154));
    msgFont((*(J2DScreen**)(p+0x28)),'Tm02',*(JUTFont**)((u8*)lbl_8053AD78+0x154));
    ((J2DTextBox*)(*(J2DScreen**)(p+0x20))->search('Tm02'))->setBlackWhite(
        JUtility::TColor(lbl_8050DB0C[0x307],lbl_8050DB0C[0x308],lbl_8050DB0C[0x309],0),
        JUtility::TColor(lbl_8050DB0C[0x304],lbl_8050DB0C[0x305],lbl_8050DB0C[0x306],255));
    (*(J2DScreen**)(p+0x2c))->search(0x4e646174613035ULL)->hide();
    (*(J2DScreen**)(p+0x2c))->search(0x4e646174613031ULL)->hide();
    image=(const ResTIMG*)(*(MsgResourceAccess**)((u8*)lbl_8053AAF8+0xa4))->get('TIMG',r+0x774);
    *(J2DPicture**)(p+0x5c)=new J2DPicture(image);
    (*(J2DPicture**)(p+0x5c))->setBlackWhite(JUtility::TColor(255,255,140,0),JUtility::TColor(255,255,140,255));
    (*(J2DPicture**)(p+0x5c))->rotate(lbl_80543224,lbl_80543228,(J2DRotateAxis)'z',lbl_80543240);
    (*(f32*)(p+0x118))=0.0f;
    (*(s16*)(p+0x198))=(s32)(msgRandomScaled(lbl_8054322C))+10;
    (*(s16*)(p+0x19a))=-96;(*(s16*)(p+0x19c))=0;
    *(void**)(p+4)=0;
    *(JMessage::TResourceContainer**)(p+4)=new JMessage::TResourceContainer;
    *(void**)(p+8)=0;
    *(JMessage::TControl**)(p+8)=new JMessage::TControl;
    *(void**)(p+0xc)=0;
    u8* ref=(u8*)__nw__FUl(8);
    if(ref) { *(void**)ref=__vt__Q28JMessage10TReference; *(void**)(ref+4)=0; *(void**)ref=lbl_804AF6D4; }
    *(void**)(p+0xc)=ref;
    *(void**)(p+0x10)=0;
    *(void**)(p+0x10)=new MsgSequenceInit(*(void**)(p+0xc),*(void**)(p+8));
    *(void**)(*(u8**)(p+0x10)+0x60)=*(void**)(p+0x3c0);
    *(void**)(p+0x14)=0;
    *(void**)(p+0x14)=new MsgRenderingInit(p);
    *(void**)(*(u8**)(p+0x14)+0x2bc)=((J2DTextBox*)(*(J2DScreen**)(p+0x20))->search('Tm01'))->getFont();
    { u8* processor=*(u8**)(p+0x14); *(void**)(processor+0x2c0)=p+0x1ab; *(void**)(processor+0x2c4)=p+0x2ab; }
    *(void**)(*(u8**)(p+0x14)+0x2d8)=*(void**)(p+0x3c0);
    { J2DTextBox* tb=(J2DTextBox*)(*(J2DScreen**)(p+0x20))->search('Tm01'); (*(f32*)(p+0x60))=tb->mFontSize.x; (*(f32*)(p+0x64))=tb->mFontSize.y; }
    f32 lineSpace=((J2DTextBox*)(*(J2DScreen**)(p+0x20))->search('Tm01'))->mLineSpacing;
    f32 scale=lbl_8054321C;
    (*(f32*)(p+0xb0))=lineSpace;
    (*(f32*)(p+0xb4))=scale;
    J2DTextBox::TFontSize fs;
    fs.x=(*(f32*)(p+0x60))*scale;fs.y=(*(f32*)(p+0x64))*scale;
    setTBFontSize((J2DTextBox*)(*(J2DScreen**)(p+0x20))->search('Tm01'),fs);
    ((J2DTextBox*)(*(J2DScreen**)(p+0x20))->search('Tm01'))->setLineSpace((*(f32*)(p+0xb0))*1.0f);
    setTBFontSize((J2DTextBox*)(*(J2DScreen**)(p+0x20))->search('Tm02'),fs);
    ((J2DTextBox*)(*(J2DScreen**)(p+0x20))->search('Tm02'))->setLineSpace((*(f32*)(p+0xb0))*1.0f);
    ((MsgPrint*)*(void**)(p+0x14))->setScale(1.0f,(*(f32*)(p+0x60)));
    *(void**)(*(u8**)(p+0xc)+4)=*(void**)(p+4);
    *(void**)(*(u8**)(p+8)+4)=*(void**)(p+0x10);
    *(void**)(*(u8**)(p+8)+8)=*(void**)(p+0x14);
    JMessage::TParse parser(*(JMessage::TResourceContainer**)(p+4));
    parser.parse(*(void**)(p+0x18),0);
    if(*(void**)(p+0x1c)) {
        JMessage::TParse_color colors(*(JMessage::TResourceContainer**)(p+4));
        colors.parse(*(void**)(p+0x1c),0);
    }
    (*(JMessage::TControl**)(p+8))->reset();
    u8* ctl=*(u8**)(p+8);
    if(*(void**)(ctl+4)) *(void**)(*(u8**)(ctl+4)+8)=0;
    if(*(void**)(ctl+8)) *(void**)(*(u8**)(ctl+8)+8)=0;
    *(void**)(ctl+0x10)=0;
    return p;
}

// ---- from src/Game/fn_803986A0_dtor.cpp ----
extern "C" void __dt__Q28JMessage19TRenderingProcessorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF6E4[];

extern "C" void* fn_803986A0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF6E4;
        __dt__Q28JMessage19TRenderingProcessorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- fn_8039D0DC: glyph-slot position setup ----
struct MsgFontInfo { u8 pad0[0x28]; u16 flags; };
struct MsgRubySlot { f32 x; f32 y; u8 tag; };
struct MsgLayout {
    u8 pad0[0x68];
    MsgRubySlot* ruby[12];    // 0x68
    u8 pad98[0xe8 - 0x98];
    f32 baseE8;               // 0xe8
    u8 padEC[0xf0 - 0xec];
    f32 baseF0;               // 0xf0
    u8 padF4[0x124 - 0xf4];
    f32 slotX[3];             // 0x124
    f32 slotY[3];             // 0x130
    u8 pad13c[0x154 - 0x13c];
    s32 m154;                 // 0x154
    u8 pad158[0x15c - 0x158];
    s32 m15c;                 // 0x15c
    u8 pad160[0x164 - 0x160];
    s32 lineCount;            // 0x164
    u8 pad168[0x16c - 0x168];
    s32 m16c;                 // 0x16c
    s32 m170;                 // 0x170
    u8 pad174[0x178 - 0x174];
    s32 m178;                 // 0x178
    s32 m17c;                 // 0x17c
    u8 pad180[0x190 - 0x180];
    s16 m190;                 // 0x190
    s16 m192;                 // 0x192
    u8 pad194[0x19e - 0x194];
    u8 m19e;                  // 0x19e
    u8 pad19f[0x1a1 - 0x19f];
    u8 m1a1;                  // 0x1a1
    u8 pad1a2[0x1aa - 0x1a2];
    u8 m1aa;                  // 0x1aa
    u8 pad1ab[0x3ab - 0x1ab];
    u8 m3ab;                  // 0x3ab
    u8 m3ac;                  // 0x3ac
    u8 m3ad;                  // 0x3ad
    u8 pad3ae[0x3b2 - 0x3ae];
    u8 slotTag[6];            // 0x3b2
    MsgFontInfo* font;        // 0x3b8
};
struct MsgProc {
    u8 pad0[0x8];
    const JMessage::TResource* res; // 0x08
    u8 padC[0x38 - 0xc];
    JMessage::TRenderingProcessor proc; // 0x38
    s32 m70;                  // 0x70
    u32 bits[2];              // 0x74
    u8 pad7c[0x84 - 0x7c];
    f32 posA[(0x12c - 0x84) / 4];  // 0x84
    f32 posB[(0x1d4 - 0x12c) / 4]; // 0x12c
    f32 slotOfs[(0x210 - 0x1d4) / 4]; // 0x1d4
    s32 hours;                // 0x210
    s32 secs;                 // 0x214
    s32 m218;                 // 0x218
    s32 m21c;                 // 0x21c
    u8 pad220[0x222 - 0x220];
    s16 m222;                 // 0x222
    s16 m224;                 // 0x224
    u8 slotLine[(0x23a - 0x226)];  // 0x226
    s8 lineTab[(0x2bc - 0x23a)];   // 0x23a
    s32 m2bc;                 // 0x2bc
    char* str2c0;             // 0x2c0
    char* str2c4;             // 0x2c4
    u8 pad2c8[0x2cc - 0x2c8];
    s32 cur;                  // 0x2cc
    s32 m2d0;                 // 0x2d0
    u8 slot;                  // 0x2d4
    u8 rubySlot;              // 0x2d5
    u8 m2d6;                  // 0x2d6
    u8 pad2d7[0x2d8 - 0x2d7];
    MsgLayout* layout;        // 0x2d8

    void setTime(s32 t) {
        s32 sec = (t / 60) % 60;
        if (sec == 0) {
            sec = 1;
        }
        hours = t / 3600;
        secs = sec;
    }
    void setInfo(s16 c, s16 d, s32 a, s32 b) {
        m222 = c;
        m224 = d;
        m218 = a;
        m21c = b;
    }
    void setSlotPos(u8 i, s32 x) {
        MsgLayout* l = layout;
        s32 y = slotLine[i] - lineTab[l->m15c] - 1;
        l->slotX[i] = (f32)x + slotOfs[i];
        l->slotY[i] = (f32)y;
    }
    void putSlotPos(const s32 x, const s32 base) {
        str2c0[m2d0++] = -2;
        s32 col = x;
        col += (s8)slotLine[slot + 0x10];
        str2c0[m2d0++] = col + base;
        str2c0[m2d0++] = -2;
        if (layout->m1a1 != 0) {
            const s8 top = lineTab[layout->m15c];
            const u8 line = slotLine[slot];
            if (lineRow(top, line) == 0) {
                str2c0[m2d0++] = slotLine[slot] + (base + 0x20) - lineTab[layout->m15c];
                return;
            }
        }
        str2c0[m2d0++] = slotLine[slot] + (base + 0x1f) - lineTab[layout->m15c];
    }
    s32 slotCol(s32 x) {
        return x + (s8)slotLine[slot + 0x10];
    }
    static s32 lineRow(const s8 top, const int line) {
        return (u8)line - top - 1;
    }
    BOOL testBit(s32 n) {
        if (n < 32) {
            return (bits[0] & (s64)(1 << n)) ? TRUE : FALSE;
        } else if (n < 64) {
            return (bits[1] & (s64)(1 << (n - 32))) ? TRUE : FALSE;
        }
        return FALSE;
    }
};

// ---- counter-noun strings ----
// The TU's .rodata (0x80475768..) is not split yet; this describes the part
// of it holding the long counter nouns so the base+offset addressing matches.
struct MsgRodata {
    u8 pad0[0x788];
    char forceGem[0xc];       // 0x788 " Force Gem"
    char forceGems[0xc];      // 0x794 " Force Gems"
    char baddies[0xc];        // 0x7a0
    char systems[0xc];        // 0x7ac
    char thieves[0xc];        // 0x7b8
    char returns[0xc];        // 0x7c4
    char forceFairy[0x10];    // 0x7d0
    char forceFairies[0x10];  // 0x7e0
};
extern "C" const MsgRodata lbl_80475768;
extern "C" const char lbl_80543244[7];  // " cocco"
extern "C" const char lbl_8054324C[8];  // " coccos"
extern "C" const char lbl_805432A8[7];  // " Cucco"
extern "C" const char lbl_805432B0[8];  // " Cuccos"
extern "C" const char lbl_80543254[7];  // " baddy"
extern "C" const char lbl_8054325C[6];  // " time"
extern "C" const char lbl_80543264[7];  // " times"
extern "C" const char lbl_8054326C[8];  // " system"
extern "C" const char lbl_80543274[7];  // " thief"
extern "C" const char lbl_8054327C[6];  // " mole"
extern "C" const char lbl_80543284[7];  // " moles"
extern "C" const char lbl_8054328C[8];  // " return"

static inline void msgAppendWord(MsgProc* p, const char* w, s32 n) {
    strcat(p->str2c0, w);
    strcat(p->str2c4, w);
    p->m2d0 += n;
}

extern "C" void fn_8039C630(MsgProc* p, u8 kind, s32 count) {
    const MsgRodata* r = &lbl_80475768;
    switch (kind) {
    case 1:
        if (count == 1) {
            msgAppendWord(p, r->forceGem, 10);
        } else {
            msgAppendWord(p, r->forceGems, 11);
        }
        break;
    case 2:
        if (count == 1) {
            msgAppendWord(p, lbl_805432A8, 6);
        } else {
            msgAppendWord(p, lbl_805432B0, 6);
        }
        break;
    case 3:
        if (count == 1) {
            msgAppendWord(p, lbl_80543254, 6);
        } else {
            msgAppendWord(p, r->baddies, 8);
        }
        break;
    case 4:
        if (count == 1) {
            msgAppendWord(p, lbl_8054325C, 5);
        } else {
            msgAppendWord(p, lbl_80543264, 6);
        }
        break;
    case 5:
        if (count == 1) {
            msgAppendWord(p, lbl_8054326C, 7);
        } else {
            msgAppendWord(p, r->systems, 8);
        }
        break;
    case 6:
        if (count == 1) {
            msgAppendWord(p, lbl_80543274, 6);
        } else {
            msgAppendWord(p, r->thieves, 8);
        }
        break;
    case 7:
        if (count == 1) {
            msgAppendWord(p, lbl_8054327C, 5);
        } else {
            msgAppendWord(p, lbl_80543284, 6);
        }
        break;
    case 8:
        if (count == 1) {
            msgAppendWord(p, lbl_8054328C, 7);
        } else {
            msgAppendWord(p, r->returns, 8);
        }
        break;
    case 9:
        if (count == 1) {
            msgAppendWord(p, r->forceFairy, 7);
        } else {
            msgAppendWord(p, r->forceFairies, 8);
        }
        break;
    }
}


struct MsgMeasure {
    u8 pad0[0x38];
    JUTFont* font;            // 0x38
    u32 bits[2];              // 0x3c
    f32 scale;                // 0x44
    f32 fontW;                // 0x48
    f32 lineW[(0xf4 - 0x4c) / 4];  // 0x4c
    f32 lineX[(0x19c - 0xf4) / 4]; // 0xf4
    f32 tabW[3];              // 0x19c
    f32 spaceW[0x14];         // 0x1a8
    u8 pad1f8[0x201 - 0x1f8];
    u8 line;                  // 0x201
    s8 colorHist[0x2a];       // 0x202
    s8 color;                 // 0x22c
    u8 lineChars[0x10];       // 0x22d
};

extern "C" void fn_80398700(MsgMeasure* m, u8 kind, s32 count) {
    const MsgRodata* r = &lbl_80475768;
    f32 ratio = m->fontW / (f32)m->font->getCellWidth();
    char buf[15];
    char* s = buf;
    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 0;
    buf[4] = 0;
    buf[5] = 0;
    buf[6] = 0;
    buf[7] = 0;
    buf[8] = 0;
    buf[9] = 0;
    buf[10] = 0;
    buf[11] = 0;
    buf[12] = 0;
    buf[13] = 0;
    buf[14] = 0;
    switch (kind) {
    case 1:
        if (count == 1) {
            strcat(s, r->forceGem);
        } else {
            strcat(s, r->forceGems);
        }
        break;
    case 2:
        if (count == 1) {
            strcat(s, lbl_80543244);
        } else {
            strcat(s, lbl_8054324C);
        }
        break;
    case 3:
        if (count == 1) {
            strcat(s, lbl_80543254);
        } else {
            strcat(s, r->baddies);
        }
        break;
    case 4:
        if (count == 1) {
            strcat(s, lbl_8054325C);
        } else {
            strcat(s, lbl_80543264);
        }
        break;
    case 5:
        if (count == 1) {
            strcat(s, lbl_8054326C);
        } else {
            strcat(s, r->systems);
        }
        break;
    case 6:
        if (count == 1) {
            strcat(s, lbl_80543274);
        } else {
            strcat(s, r->thieves);
        }
        break;
    case 7:
        if (count == 1) {
            strcat(s, lbl_8054327C);
        } else {
            strcat(s, lbl_80543284);
        }
        break;
    case 8:
        if (count == 1) {
            strcat(s, lbl_8054328C);
        } else {
            strcat(s, r->returns);
        }
        break;
    case 9:
        if (count == 1) {
            strcat(s, r->forceFairy);
        } else {
            strcat(s, r->forceFairies);
        }
        break;
    }
    int i = 0;
    while (*s != 0) {
        JUTFont::TWidth w;
        m->font->getWidthEntry(*s, &w);
        s++;
        m->lineW[m->line] += ratio * (m->scale * (f32)(s32)w.w1);
        m->lineX[m->line] += 3.0f;
        m->lineChars[m->line]++;
        if (++i >= 15) break;
    }
}

typedef s32 (*TuCall0)(void*);
typedef void (*TuCall3)(void*, s32, void*);
extern f32 lbl_805431E8;
extern "C" void fn_80398A34(MsgMeasure* m, s32 n) {
    bool printed = false;
    f32 scale = m->fontW / (f32)m->font->getCellWidth();
    s32 q;
    JUTFont::TWidth wm;
    JUTFont::TWidth w10000;
    JUTFont::TWidth w1000;
    JUTFont::TWidth w100;
    JUTFont::TWidth w10;
    JUTFont::TWidth w1;

    if (n < 0) {
        n *= -1;
        m->font->getWidthEntry(0x2d, &wm);
        m->lineW[m->line] += scale * (m->scale * (f32)(s32)wm.w1);
        m->lineX[m->line] += 3.0f;
        m->lineChars[m->line]++;
    }

    q = n / 10000;
    n = n % 10000;
    if (q != 0) {
        printed = 1;
        m->font->getWidthEntry(q + 0x30, &w10000);
        m->lineW[m->line] += scale * (m->scale * (f32)(s32)w10000.w1);
        m->lineX[m->line] += 3.0f;
        m->lineChars[m->line]++;
    }

    q = n / 1000;
    n = n % 1000;
    if (q != 0 || printed != 0) {
        printed = 1;
        m->font->getWidthEntry(q + 0x30, &w1000);
        m->lineW[m->line] += scale * (m->scale * (f32)(s32)w1000.w1);
        m->lineX[m->line] += 3.0f;
        m->lineChars[m->line]++;
    }

    q = n / 100;
    n = n % 100;
    if (q != 0 || printed != 0) {
        printed = 1;
        m->font->getWidthEntry(q + 0x30, &w100);
        m->lineW[m->line] += scale * (m->scale * (f32)(s32)w100.w1);
        m->lineX[m->line] += 3.0f;
        m->lineChars[m->line]++;
    }

    q = n / 10;
    n = n % 10;
    if (q != 0 || printed != 0) {
        printed = 1;
        m->font->getWidthEntry(q + 0x30, &w10);
        m->lineW[m->line] += scale * (m->scale * (f32)(s32)w10.w1);
        m->lineX[m->line] += 3.0f;
        m->lineChars[m->line]++;
    }

    m->font->getWidthEntry(n + 0x30, &w1);
    m->lineW[m->line] += scale * (m->scale * (f32)(s32)w1.w1);
        m->lineX[m->line] += 3.0f;
        m->lineChars[m->line]++;
}

// ---- ASCII -> font code table helpers ----
struct MsgCharMap {
    u16 ascii;
    u16 code;
};
extern "C" const MsgCharMap lbl_80475830[];

static inline u16 msgToWide(u16 c) {
    for (int i = 0; lbl_80475830[i].ascii != 0xffff; i++) {
        if (lbl_80475830[i].ascii == c) {
            return lbl_80475830[i].code;
        }
    }
    return 0x1420;
}

static inline void msgPutWide(MsgProc* p, int c) {
    u16 w = msgToWide((u16)c);
    p->str2c0[p->m2d0++] = w >> 8;
    p->str2c0[p->m2d0++] = w;
}

extern "C" void fn_8039C258(MsgProc* p, s32 n) {
    bool lead = false;
    if (n < 0) {
        n *= -1;
        msgPutWide(p, '-');
    }
    s32 d = n / 10000;
    n %= 10000;
    if (d != 0) {
        lead = true;
        msgPutWide(p, d + '0');
    }
    d = n / 1000;
    n %= 1000;
    if (d != 0 || lead) {
        lead = true;
        msgPutWide(p, d + '0');
    }
    d = n / 100;
    n %= 100;
    if (d != 0 || lead) {
        lead = true;
        msgPutWide(p, d + '0');
    }
    d = n / 10;
    n %= 10;
    if (d != 0 || lead) {
        msgPutWide(p, d + '0');
    }
    msgPutWide(p, n + '0');
}

static inline s32 msgTestBit(const s32 n, const u32* bits) {
    if (n < 32) return (bits[0] & (s64)(1 << n)) ? TRUE : FALSE;
    if (n < 64) return (bits[1] & (s64)(1 << (n - 32))) ? TRUE : FALSE;
    return FALSE;
}

static inline void msgAppendChar(MsgProc* p, char* buf) {
    strcat(p->str2c0, buf);
    strcat(p->str2c4, buf);
    p->m2d0++;
}

// NONMATCHING (99%): cur/layout register swap in the bit test (same as fn_8039D0DC).
#pragma opt_common_subs on
extern "C" void fn_8039C9A0(MsgProc& object, s32 n) {
    MsgProc* p = &object;
    bool lead = false;
    bool neg = false;
    if (n < 0) {
        n *= -1;
        neg = true;
    }
    if (p->m2d6) {
        if (!p->testBit(p->cur)) {
            MsgLayout* l = p->layout;
            if (l->m16c == 0 || !p->testBit(p->cur)) {
                f32 base;
                f32 pos;
                if (!(l->font->flags & 0x40)) {
                    base = l->baseE8;
                    pos = p->posA[p->cur];
                } else {
                    base = l->baseF0;
                    f32 left = p->posA[p->cur];
                    f32 extra = p->posB[p->cur];
                    extra -= lbl_805431E8;
                    pos = left + extra;
                }
                f32 delta = base;
                delta -= pos;
                s32 x = delta * lbl_805431E4 + lbl_805431E4;
                if (x > 0) {
                    snprintf(lbl_8050E528, 0xf, "\x1b" "CR[%d]", x);
                    strcat(p->str2c0, lbl_8050E528);
                    strcat(p->str2c4, lbl_8050E528);
                    p->m2d0 += strlen(lbl_8050E528);
                }
            }
            p->m2d6 = 0;
        }
    }
    char buf[3];
    buf[2] = 0;
    buf[1] = 0;
    buf[0] = 0;
    if (neg) {
        buf[0] = '-';
        msgAppendChar(p, buf);
    }
    s32 d = n / 10000;
    s32 remainder = n % 10000;
    if (d != 0) {
        buf[0] = d + '0';
        lead = true;
        msgAppendChar(p, buf);
    }
    d = remainder / 1000;
    remainder %= 1000;
    if (d != 0 || lead) {
        buf[0] = d + '0';
        lead = true;
        msgAppendChar(p, buf);
    }
    d = remainder / 100;
    remainder %= 100;
    if (d != 0 || lead) {
        buf[0] = d + '0';
        lead = true;
        msgAppendChar(p, buf);
    }
    d = remainder / 10;
    remainder %= 10;
    if (d != 0 || lead) {
        buf[0] = d + '0';
        msgAppendChar(p, buf);
    }
    buf[0] = remainder + '0';
    msgAppendChar(p, buf);
}
#pragma opt_common_subs reset
static inline void msgMeasureChar(MsgMeasure* m, int c, f32 ratio, f32 add) {
    JUTFont::TWidth w;
    m->font->getWidthEntry(c, &w);
    m->lineW[m->line] += ratio * (m->scale * (f32)(s32)w.w1);
    m->lineX[m->line] += add;
    m->lineChars[m->line]++;
}

static inline void msgMeasureChar2(MsgMeasure* m, int c, f32 ratio, f32 add) {
    JUTFont::TWidth w;
    m->font->getWidthEntry(c, &w);
    m->lineW[m->line] += 2.0f * (ratio * (m->scale * (f32)(s32)w.w1));
    m->lineX[m->line] += add;
    m->lineChars[m->line]++;
}

// Saved line widths in the measure state: tab stops (indexed by +0x282) and spaces (by +0x1fd).
struct MsgMeasureSave {
    u8 pad0[0x19c];
    f32 tabW[3];   // 0x19c
    f32 spaceW[12]; // 0x1a8
};

static inline void msgSetLineBit(MsgMeasure* m, int n) {
    if (n < 32) {
        m->bits[0] |= (s64)(1 << n);
    } else if (n < 64) {
        m->bits[1] |= (s64)(1 << (n - 32));
    }
}

static inline void msgClearLineBit(MsgMeasure* m, int n) {
    if (n < 32) {
        m->bits[0] &= ~(s64)(1 << n);
    } else if (n < 64) {
        m->bits[1] &= ~(s64)(1 << n);
    }
}

static inline void msgMeasureCharK(MsgMeasure* m, int c, f32 ratio, f32 k, f32 add) {
    JUTFont::TWidth w;
    m->font->getWidthEntry(c, &w);
    m->lineW[m->line] += k * (ratio * (m->scale * (f32)(s32)w.w1));
    m->lineX[m->line] += add;
    m->lineChars[m->line]++;
}

static inline void msgMeasureCharTab(MsgMeasure* m, int c, f32 ratio, f32 add) {
    JUTFont::TWidth w;
    m->font->getWidthEntry(c, &w);
    m->lineW[m->line] += (f32)*(s16*)(lbl_8050DB0C + 0x2ee) * (ratio * (m->scale * (f32)(s32)w.w1));
    m->lineX[m->line] += add;
    m->lineChars[m->line]++;
}

extern "C" void fn_80398EF4(MsgMeasure* m, s32 a, s32 b) {
    f32 ratio = m->fontW / (f32)m->font->getCellWidth();
    if (a > 99) {
        a = 99;
    }
    s32 d = a / 10;
    s32 e = a % 10;
    if (d > 0) {
        msgMeasureChar(m, d + '0', ratio, 3.0f);
    }
    msgMeasureChar(m, e + '0', ratio, 3.0f);
    msgMeasureChar(m, '\'', ratio, 3.0f);
    if (b > 99) {
        b = 99;
    }
    msgMeasureChar(m, b / 10 + '0', ratio, 3.0f);
    msgMeasureChar(m, b % 10 + '0', ratio, 3.0f);
    msgMeasureChar2(m, '\'', ratio, 6.0f);
}

// NONMATCHING (96%): furigana row compare codegen (subic. vs cmplwi) and regalloc.
#pragma opt_common_subs on
extern "C" void fn_8039D30C(MsgProc* p, u8 tag) {
    s32 x = 0;
    if (!p->testBit(p->cur)) {
        if (p->layout->m16c == 0 || !p->testBit(p->cur)) {
            x = (0x1c - p->lineTab[p->cur + 0x2b]) / 2;
        }
    }
    switch (p->slot) {
    case 0:
        p->putSlotPos(x, 0);
        break;
    case 1:
        p->putSlotPos(x, 0x40);
        break;
    case 2:
        p->putSlotPos(x, 0x80);
        break;
    }
    p->layout->slotTag[p->slot] = tag;
    p->slot++;
}
#pragma opt_common_subs reset
extern "C" void fn_8039CDF8(MsgProc*, u8);
extern "C" void fn_8039D0DC(MsgProc*, u8);
extern "C" void fn_8039D30C(MsgProc*, u8);
extern "C" void fn_8039C9A0(MsgProc&, s32);
extern "C" void fn_8039A638(MsgProc*, s16);
extern "C" void fn_8039ACD0(u8*, s16);
extern "C" void fn_8039B3EC(u8*, u8, s32);
extern "C" const char lbl_805432BC[4];
extern "C" const char lbl_805432C0[4];
extern "C" const char lbl_805432C4[4];
extern "C" const char lbl_805432C8[4];
extern "C" const char lbl_805432CC[4];
extern "C" const char lbl_805432D4[4];
extern "C" const u32 lbl_80475D64[];
extern "C" const char lbl_80475DC8[];


extern "C" const char lbl_805432BC[4];
extern "C" const char lbl_805432C0[4];
extern "C" const char lbl_805432C4[4];
extern "C" const char lbl_805432C8[4];
extern "C" const char lbl_805432CC[4];
extern "C" const char lbl_805432D4[4];
extern "C" s32 fn_8039D770(MsgProc* p, u32 event, u8* data) {
    char buf[30];
    if (p->layout->m1aa == 0) {
        switch (event) {
    case 0x0:
        return 1;
    case 0x10000:
        fn_8039CDF8(p, 0);
        return 1;
    case 0x10001:
        fn_8039CDF8(p, 1);
        return 1;
    case 0x10002:
        fn_8039CDF8(p, 2);
        return 1;
    case 0x10003:
        fn_8039CDF8(p, 3);
        return 1;
    case 0x10007:
        fn_8039CDF8(p, 7);
        return 1;
    case 0x10008:
        fn_8039CDF8(p, 8);
        return 1;
    case 0x10009:
        fn_8039CDF8(p, 9);
        return 1;
    case 0x1000a:
        fn_8039CDF8(p, 10);
        return 1;
    case 0x10004:
        fn_8039CDF8(p, 4);
        return 1;
    case 0x10005:
        fn_8039CDF8(p, 5);
        return 1;
    case 0x10006:
        fn_8039CDF8(p, 6);
        return 1;
    case 0x1000b:
    case 0x1000c:
        return 1;
    case 0x10010:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            strcat(p->str2c0, lbl_805432BC);
            strcat(p->str2c4, lbl_805432BC);
            u8 tag = data[0];
            p->m2d0 += 1;
            fn_8039D0DC(p, tag);
        }
        return 1;
    case 0x10011:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            strcat(p->str2c0, lbl_805432C0);
            strcat(p->str2c4, lbl_805432C0);
            u8 tag = data[0];
            p->m2d0 += 1;
            fn_8039D0DC(p, tag);
        }
        return 1;
    case 0x10012:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            strcat(p->str2c0, lbl_805432C4);
            strcat(p->str2c4, lbl_805432C4);
            u8 tag = data[0];
            p->m2d0 += 1;
            fn_8039D0DC(p, tag);
        }
        return 1;
    case 0x10013:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            strcat(p->str2c0, lbl_805432C8);
            strcat(p->str2c4, lbl_805432C8);
            u8 tag = data[0];
            p->m2d0 += 1;
            fn_8039D0DC(p, tag);
        }
        return 1;
    case 0x20000:
    case 0x20001:
    case 0x20002:
    case 0x20003:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            strcat(p->str2c0, lbl_805432CC);
            strcat(p->str2c4, lbl_805432CC);
            u8 tag = data[0];
            p->m2d0 += 4;
            fn_8039D0DC(p, tag);
        }
        return 1;
    case 0x20011:
    case 0x20012:
    case 0x20013:
    case 0x20014:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            strcat(p->str2c0, lbl_805432CC);
            strcat(p->str2c4, lbl_805432CC);
            u8 tag = data[4];
            p->m2d0 += 4;
            fn_8039D0DC(p, tag);
        }
        return 1;
    case 0x20009:
    case 0x2000a:
    case 0x2000b:
    case 0x2000c:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            s32 i;
            for (i = 0; i < *(s16*)(lbl_8050DB0C + 0x2ee); i++) {
                strcat(p->str2c0, lbl_805432D4);
                strcat(p->str2c4, lbl_805432D4);
            }
            u8 tag = data[4];
            p->m2d0 += *(s16*)(lbl_8050DB0C + 0x2ee);
            fn_8039D0DC(p, tag);
        }
        return 1;
    case 0x20019:
    case 0x2001a:
    case 0x2001b:
    case 0x2001c:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            s32 i;
            for (i = 0; i < *(s16*)(lbl_8050DB0C + 0x2ee); i++) {
                strcat(p->str2c0, lbl_805432D4);
                strcat(p->str2c4, lbl_805432D4);
            }
            u8 tag = data[0];
            p->m2d0 += *(s16*)(lbl_8050DB0C + 0x2ee);
            fn_8039D0DC(p, tag);
        }
        return 1;
    case 0x20004:
    case 0x20005:
    case 0x20006:
    case 0x20007:
    case 0x20008:
        return 1;
    case 0x2000d:
    case 0x2000e:
    case 0x2000f:
    case 0x20010:
    case 0x20015:
    case 0x20016:
    case 0x20017:
    case 0x20018:
    case 0x2001d:
        return 1;
    case 0x2001e:
        if (p->cur > p->lineTab[p->layout->m15c] && data[0] < 5) {
            snprintf(buf, 30, lbl_80475DC8, static_cast<int>(p->layout->m154 = lbl_80475D64[data[0]]));
            strcat(p->str2c0, buf);
            if ((p->layout->font->flags & 0x40) != 0 || *((u8*)p->layout + 0x1a2) == 0) {
                snprintf(buf, 30, lbl_80475DC8, 0xff);
                strcat(p->str2c4, buf);
            } else {
                snprintf(buf, 30, lbl_80475DC8, -1);
                strcat(p->str2c4, buf);
            }
            p->m2d0 += strlen(buf);
        }
        return 1;
    case 0x2001f:
    case 0x20020:
    case 0x20021:
    case 0x20022:
    case 0x20023:
    case 0x20024:
        return 1;
    case 0x20025:
    case 0x20026:
    case 0x20027:
    case 0x20028:
        return 1;
    case 0x20029:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039ACD0((u8*)p, 0);
        }
        return 1;
    case 0x2002a:
    case 0x2002b:
        return 1;
    case 0x2002c:
        return 1;
    case 0x2002d:
        return 1;
    case 0x2002e:
        return 1;
    case 0x2002f:
        return 1;
    case 0x20030:
        return 1;
    case 0x20031:
        return 1;
    case 0x20032:
        return 1;
    case 0x20033:
        return 1;
    case 0x30000:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039C9A0(*p, p->layout->m190);
            fn_8039C630(p, data[0], p->layout->m190);
        }
        return 1;
    case 0x30001:
        return 1;
    case 0x30002:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039C9A0(*p, p->layout->m192);
            fn_8039C630(p, data[0], p->layout->m192);
        }
        return 1;
    case 0x30003:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039C9A0(*p, p->layout->m178);
            fn_8039C630(p, data[0], p->layout->m178);
        }
        return 1;
    case 0x30004:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039C9A0(*p, p->layout->m17c);
            fn_8039C630(p, data[0], p->layout->m17c);
        }
        return 1;
    case 0x30005:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039A638(p, 0);
        }
        return 1;
    case 0x30006:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039C9A0(*p, *(u16*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 200 + 0x34));
            fn_8039C630(p, 4, *(u16*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 200 + 0x34));
        }
        return 1;
    case 0x30007:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039C9A0(*p, *(u16*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 200 + 0x36));
            fn_8039C630(p, 4, *(u16*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 200 + 0x36));
        }
        return 1;
    case 0x30008:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039C9A0(*p, *(s32*)((u8*)lbl_8053AD78 + 0x10c));
            fn_8039C630(p, 6, *(s32*)((u8*)lbl_8053AD78 + 0x10c));
        }
        return 1;
        }
    } else {
    if (event != 0 && p->cur > p->lineTab[p->layout->m15c] && p->m2d6 != 0) {
        if (!p->testBit(p->cur)) {
            if (p->layout->m16c == 0 || !p->testBit(p->cur)) {
                s32 n = 28 - p->lineTab[p->cur + 43];
                if (n > 0 && n < 28) {
            p->str2c0[p->m2d0++] = 0xff;
            p->str2c0[p->m2d0++] = n + 208;
                }
            }
        }
        p->m2d6 = 0;
    }
    switch (event) {
    case 0x0:
        return 1;
    case 0x10000:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            p->str2c0[p->m2d0++] = 0xff;
            p->str2c0[p->m2d0++] = 0xf1;
            p->str2c0[p->m2d0++] = 0x3c;
            p->str2c0[p->m2d0++] = 0xc0;
            p->str2c0[p->m2d0++] = 0x3c;
            p->str2c0[p->m2d0++] = 0xe0;
        }
        return 1;
    case 0x10001:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            p->str2c0[p->m2d0++] = 0xff;
            p->str2c0[p->m2d0++] = 0xf2;
            p->str2c0[p->m2d0++] = 0x3c;
            p->str2c0[p->m2d0++] = 0xc0;
            p->str2c0[p->m2d0++] = 0x3c;
            p->str2c0[p->m2d0++] = 0xe0;
        }
        return 1;
    case 0x10002:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            p->str2c0[p->m2d0++] = 0xff;
            p->str2c0[p->m2d0++] = 0xf3;
            p->str2c0[p->m2d0++] = 0x3c;
            p->str2c0[p->m2d0++] = 0xc0;
            p->str2c0[p->m2d0++] = 0x3c;
            p->str2c0[p->m2d0++] = 0xe0;
        }
        return 1;
    case 0x10003:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            p->str2c0[p->m2d0++] = 0xff;
            p->str2c0[p->m2d0++] = 0xf4;
            p->str2c0[p->m2d0++] = 0x3c;
            p->str2c0[p->m2d0++] = 0xc0;
            p->str2c0[p->m2d0++] = 0x3c;
            p->str2c0[p->m2d0++] = 0xe0;
        }
        return 1;
    case 0x10007:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            p->str2c0[p->m2d0++] = 0xff;
            p->str2c0[p->m2d0++] = 0xf5;
            p->str2c0[p->m2d0++] = 0x3d;
            p->str2c0[p->m2d0++] = 0x0;
            p->str2c0[p->m2d0++] = 0x3d;
            p->str2c0[p->m2d0++] = 0x20;
        }
        return 1;
    case 0x10008:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            p->str2c0[p->m2d0++] = 0xff;
            p->str2c0[p->m2d0++] = 0xf6;
            p->str2c0[p->m2d0++] = 0x3d;
            p->str2c0[p->m2d0++] = 0x40;
            p->str2c0[p->m2d0++] = 0x3d;
            p->str2c0[p->m2d0++] = 0x60;
        }
        return 1;
    case 0x10009:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            p->str2c0[p->m2d0++] = 0xff;
            p->str2c0[p->m2d0++] = 0xf7;
            p->str2c0[p->m2d0++] = 0x3d;
            p->str2c0[p->m2d0++] = 0x80;
            p->str2c0[p->m2d0++] = 0x3d;
            p->str2c0[p->m2d0++] = 0xa0;
        }
        return 1;
    case 0x1000a:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            p->str2c0[p->m2d0++] = 0xff;
            p->str2c0[p->m2d0++] = 0xf8;
            p->str2c0[p->m2d0++] = 0x3d;
            p->str2c0[p->m2d0++] = 0xc0;
            p->str2c0[p->m2d0++] = 0x3d;
            p->str2c0[p->m2d0++] = 0xe0;
        }
        return 1;
    case 0x10004:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            p->str2c0[p->m2d0++] = 0x3c;
            p->str2c0[p->m2d0++] = 0x0;
        }
        return 1;
    case 0x10005:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            p->str2c0[p->m2d0++] = 0x3c;
            p->str2c0[p->m2d0++] = 0x20;
        }
        return 1;
    case 0x10006:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            p->str2c0[p->m2d0++] = 0x3c;
            p->str2c0[p->m2d0++] = 0x40;
        }
        return 1;
    case 0x1000b:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            p->str2c0[p->m2d0++] = 0x3c;
            p->str2c0[p->m2d0++] = 0x60;
        }
        return 1;
    case 0x1000c:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            p->str2c0[p->m2d0++] = 0x3c;
            p->str2c0[p->m2d0++] = 0x80;
        }
        return 1;
    case 0x10010:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            p->str2c0[p->m2d0++] = 0x14;
            p->str2c0[p->m2d0++] = 0xe0;
        }
        return 1;
    case 0x10011:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            p->str2c0[p->m2d0++] = 0x15;
            p->str2c0[p->m2d0++] = 0x0;
        }
        return 1;
    case 0x10012:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            p->str2c0[p->m2d0++] = 0x15;
            p->str2c0[p->m2d0++] = 0x40;
        }
        return 1;
    case 0x10013:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            p->str2c0[p->m2d0++] = 0x15;
            p->str2c0[p->m2d0++] = 0x20;
        }
        return 1;
    case 0x2000a:
    case 0x2000c:
    case 0x20012:
    case 0x20014:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039D30C(p, data[4]);
            p->str2c0[p->m2d0++] = 0x14;
            p->str2c0[p->m2d0++] = 0x20;
        }
        return 1;
    case 0x20000:
    case 0x20002:
    case 0x20019:
    case 0x2001b:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039D30C(p, data[0]);
            p->str2c0[p->m2d0++] = 0x14;
            p->str2c0[p->m2d0++] = 0x20;
        }
        return 1;
    case 0x20009:
    case 0x20011:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039D30C(p, data[4]);
            p->str2c0[p->m2d0++] = 0xff;
            p->str2c0[p->m2d0++] = 0xb0;
            p->str2c0[p->m2d0++] = 0x14;
            p->str2c0[p->m2d0++] = 0x20;
        }
        return 1;
    case 0x20001:
    case 0x2001a:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039D30C(p, data[0]);
            p->str2c0[p->m2d0++] = 0xff;
            p->str2c0[p->m2d0++] = 0xb0;
            p->str2c0[p->m2d0++] = 0x14;
            p->str2c0[p->m2d0++] = 0x20;
        }
        return 1;
    case 0x2000b:
    case 0x20013:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039D30C(p, data[4]);
            p->str2c0[p->m2d0++] = 0xff;
            p->str2c0[p->m2d0++] = 0xb1;
            p->str2c0[p->m2d0++] = 0x14;
            p->str2c0[p->m2d0++] = 0x20;
        }
        return 1;
    case 0x20003:
    case 0x2001c:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039D30C(p, data[0]);
            p->str2c0[p->m2d0++] = 0xff;
            p->str2c0[p->m2d0++] = 0xb1;
            p->str2c0[p->m2d0++] = 0x14;
            p->str2c0[p->m2d0++] = 0x20;
        }
        return 1;
    case 0x20004:
    case 0x20005:
    case 0x20006:
    case 0x20007:
    case 0x20008:
    case 0x2000d:
    case 0x2000e:
    case 0x2000f:
    case 0x20010:
    case 0x20015:
        return 1;
    case 0x20016:
    {
        u8 tag;
        if (p->cur > p->lineTab[p->layout->m15c] && ((tag = data[0]) <= 5 || (u8)(s8)tag == 11)) {
            p->str2c0[p->m2d0++] = 0xfd;
            p->str2c0[p->m2d0++] = tag;
        }
        return 1;
    }
    case 0x20017:
    case 0x20018:
    case 0x2001d:
        return 1;
    case 0x2001e:
    {
        u8 tag;
        if (p->cur > p->lineTab[p->layout->m15c] && (tag = data[0]) < 5) {
            p->str2c0[p->m2d0++] = 0xfb;
            p->str2c0[p->m2d0++] = tag;
        }
        return 1;
    }
    case 0x2001f:
    case 0x20020:
    case 0x20021:
    case 0x20022:
    case 0x20023:
    case 0x20024:
        return 1;
    case 0x20025:
    case 0x20026:
    case 0x20027:
    case 0x20028:
        return 1;
    case 0x20029:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039ACD0((u8*)p, 1);
        }
        return 1;
    case 0x2002a:
    case 0x2002b:
        return 1;
    case 0x2002c:
        return 1;
    case 0x2002d:
        return 1;
    case 0x2002e:
        return 1;
    case 0x2002f:
        return 1;
    case 0x20030:
        return 1;
    case 0x20031:
        return 1;
    case 0x20032:
        return 1;
    case 0x20033:
        return 1;
    case 0x30000:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039C258(p, p->layout->m190);
            fn_8039B3EC((u8*)p, data[0], p->layout->m190);
        }
        return 1;
    case 0x30001:
        return 1;
    case 0x30002:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039C258(p, p->layout->m192);
            fn_8039B3EC((u8*)p, data[0], p->layout->m192);
        }
        return 1;
    case 0x30003:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039C258(p, p->layout->m178);
            fn_8039B3EC((u8*)p, data[0], p->layout->m178);
        }
        return 1;
    case 0x30004:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039C258(p, p->layout->m17c);
            fn_8039B3EC((u8*)p, data[0], p->layout->m17c);
        }
        return 1;
    case 0x30005:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039A638(p, 1);
        }
        return 1;
    case 0x30006:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039C258(p, *(u16*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 200 + 0x34));
            fn_8039B3EC((u8*)p, 4, *(u16*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 200 + 0x34));
        }
        return 1;
    case 0x30007:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039C258(p, *(u16*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 200 + 0x36));
            fn_8039B3EC((u8*)p, 4, *(u16*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 200 + 0x36));
        }
        return 1;
    case 0x30008:
        if (p->cur > p->lineTab[p->layout->m15c]) {
            fn_8039C258(p, *(s32*)((u8*)lbl_8053AD78 + 0x10c));
            fn_8039B3EC((u8*)p, 6, *(s32*)((u8*)lbl_8053AD78 + 0x10c));
        }
        return 1;
    }
    }
    return 0;
}

static inline u16 msgToWideScan(u16 c) {
    const MsgCharMap* entry = lbl_80475830;
    for (int i = 0; entry->ascii != 0xffff; ++entry, ++i) {
        if (c == entry->ascii) return lbl_80475830[i].code;
    }
    return 0x1420;
}
static inline u16 msgToWideScanFrom(const MsgCharMap* table, u16 c) {
    const MsgCharMap* entry = table;
    for (int i = 0; entry->ascii != 0xffff; ++entry, ++i) {
        if (c == entry->ascii) return lbl_80475830[i].code;
    }
    return 0x1420;
}
#pragma opt_propagation off
extern "C" void fn_8039F540(MsgProc* p, s32 ch) {
    MsgLayout* l;
    char* src;
    l = p->layout;
    l->m3ab = 0;
    src = (char*)&l->m3ab;
    if (p->layout->m1aa == 0) {
        char nl[2];
        nl[1] = 0;
        if (ch == 10) {
            p->cur++;
            if (p->cur <= p->lineTab[p->layout->m15c] + 1) {
                return;
            }
            p->m2d6 = 1;
            nl[0] = (char)ch;
            strcat(p->str2c0, nl);
            strcat(p->str2c4, nl);
            p->m2d0++;
        }
        if (p->cur <= p->lineTab[p->layout->m15c]) {
            return;
        }
        if (p->m2d6 != 0) {
            if (!p->testBit(p->cur)) {
                if (!(p->layout->m16c != 0 && p->testBit(p->cur))) {
                    f32 half;
                    f32 difference;
                    f32 spacing;
                    f32 fa;
                    f32 fb;
                    if ((p->layout->font->flags & 0x40) == 0) {
                        fa = p->layout->baseE8;
                        fb = p->posA[p->cur];
                    } else {
                        fa = p->layout->baseF0;
                        spacing = p->posB[p->cur] - lbl_805431E8;
                        fb = p->posA[p->cur] + spacing;
                    }
                    difference = fa - fb;
                    half = lbl_805431E4;
                    s32 w = (s32)(difference * half + half);
                    if (w > 0) {
                        snprintf(lbl_8050E518, 0xf, lbl_80543298, w);
                        strcat(p->str2c0, lbl_8050E518);
                        strcat(p->str2c4, lbl_8050E518);
                        p->m2d0 += strlen(lbl_8050E518);
                    }
                }
                p->m2d6 = 0;
            }
            if (ch == 10) {
                return;
            }
        }
        char c1 = (char)(((u32)ch >> 8) & 0xff);
        s32 has2 = 0;
        if (c1 != 0) {
            has2 = 1;
            ch &= 0xff;
            p->m2d0++;
            src[0] = c1;
        }
        s32 newLength = p->m2d0;
        s32 count = has2 + 1;
        p->m2d0 = newLength + 1;
        src[has2] = (char)ch;
        l = p->layout;
        s32 n = p->m2d0 - count;
        s32 oldLength = l->m170;
        if (n != oldLength) {
            l->m170 = n;
        }
        strcat(p->str2c0, src);
        strcat(p->str2c4, src);
        return;
    }
    if (ch == 10) {
        p->cur++;
        if (p->cur <= p->lineTab[p->layout->m15c] + 1) {
            return;
        }
        p->str2c0[p->m2d0++] = -1;
        p->str2c0[p->m2d0++] = -16;
        p->m2d6 = 1;
        return;
    }
    if (p->cur <= p->lineTab[p->layout->m15c]) {
        return;
    }
    if (p->m2d6 != 0) {
        if (!p->testBit(p->cur)) {
            if (!(p->layout->m16c != 0 && p->testBit(p->cur))) {
                s32 i = 0x1c - p->lineTab[p->cur + 0x2b];
                if (i > 0 && i < 0x1c) {
                    p->str2c0[p->m2d0++] = -1;
                    p->str2c0[p->m2d0++] = (char)(i + 0xd0);
                }
            }
        }
        p->m2d6 = 0;
    }
    u16 wide = msgToWideScan((u16)ch);
    p->str2c0[p->m2d0++] = wide >> 8;
    p->str2c0[p->m2d0++] = wide;
}

#pragma opt_propagation reset
extern "C" void fn_8039934C(MsgMeasure* m, s32 a, s32 b) {
    f32 ratio = m->fontW / (f32)m->font->getCellWidth();
    if (a > 0) {
        if (a > 99) {
            a = 99;
            b = 59;
        }
        s32 d = a / 10;
        s32 e = a % 10;
        if (d > 0) {
            msgMeasureChar(m, d + '0', ratio, 3.0f);
        }
        msgMeasureChar(m, e + '0', ratio, 3.0f);
        msgMeasureChar(m, '\'', ratio, 3.0f);
    }
    if (b > 59) {
        b = 59;
    }
    s32 d = b / 10;
    s32 e = b % 10;
    if (d > 0 || a > 0) {
        msgMeasureChar(m, d + '0', ratio, 3.0f);
    }
    msgMeasureChar(m, e + '0', ratio, 3.0f);
    msgMeasureChar2(m, '\'', ratio, 6.0f);
}

extern "C" s32 fn_803997B8(MsgMeasure* m, s32 id, u8* data) {
    u8* p = (u8*)m;
    f32 ratio = m->fontW / (f32)m->font->getCellWidth();
    switch (id) {
    case 0:
        if (m->colorHist[p[0x281]] != m->color) {
            p[0x281]++;
            (p + p[0x281])[0x202] = p[0x22c];
            (p + p[0x281])[0x257] = 0;
        }
        return 1;
    case 0x10000:
    case 0x10001:
    case 0x10002:
    case 0x10003:
    case 0x10007:
    case 0x10008:
    case 0x10009:
    case 0x1000a:
    {
        m->spaceW[p[0x1fd]] = m->lineW[m->line];
        (p + p[0x1fd])[0x1f1] = m->line;
        p[0x1fd]++;
        JUTFont::TWidth w;
        m->font->getWidthEntry(0x20, &w);
        m->lineW[m->line] += 2.0f * (ratio * (m->scale * (f32)(s32)w.w1));
        m->lineX[m->line] += 3.0f;
        m->lineChars[m->line] += 2;
        return 1;
    }
    case 0x10004:
    case 0x10005:
    case 0x10006:
        m->spaceW[p[0x1fd]] = m->lineW[m->line];
        (p + p[0x1fd])[0x1f1] = m->line;
        p[0x1fd]++;
        msgMeasureChar2(m, 0x20, ratio, 3.0f);
        return 1;
    case 0x1000b:
    case 0x1000c:
        m->lineChars[m->line]++;
        return 1;
    case 0x10010:
        msgMeasureChar(m, 0xa7, ratio, 3.0f);
        return 1;
    case 0x10011:
        msgMeasureChar(m, 0xa8, ratio, 3.0f);
        return 1;
    case 0x10012:
        msgMeasureChar(m, 0xa6, ratio, 3.0f);
        return 1;
    case 0x10013:
        msgMeasureChar(m, 0xa5, ratio, 3.0f);
        return 1;
    case 0x20000:
    case 0x20001:
    case 0x20002:
    case 0x20003:
    case 0x20011:
    case 0x20012:
    case 0x20013:
    case 0x20014:
        msgSetLineBit(m, m->line);
        m->tabW[p[0x282]] = m->lineW[m->line];
        (p + p[0x282])[0x1ee] = m->line;
        (p + p[0x282])[0x1fe] = m->lineChars[m->line];
        msgMeasureCharK(m, 0x20, ratio, 5.0f, 3.0f);
        p[0x282]++;
        return 1;
    case 0x20009:
    case 0x2000a:
    case 0x2000b:
    case 0x2000c:
    case 0x20019:
    case 0x2001a:
    case 0x2001b:
    case 0x2001c:
        msgClearLineBit(m, m->line);
        m->tabW[p[0x282]] = m->lineW[m->line];
        (p + p[0x282])[0x1ee] = m->line;
        (p + p[0x282])[0x1fe] = m->lineChars[m->line];
        msgMeasureCharTab(m, 0x20, ratio, 3.0f);
        p[0x282]++;
        return 1;
    case 0x20004:
    case 0x20005:
    case 0x20006:
    case 0x20007:
    case 0x20008:
    case 0x2000d:
    case 0x2000e:
    case 0x2000f:
    case 0x20010:
    case 0x20016:
    case 0x20017:
    case 0x20018:
    case 0x2001d:
    case 0x2001e:
    case 0x2001f:
    case 0x20020:
    case 0x20021:
    case 0x20022:
    case 0x20023:
    case 0x20024:
        return 1;
    case 0x20015:
        if (data + 4 != 0) {
            return 1;
        }
    case 0x20025:
        if (p[0x1e8] != 0) {
            (p + p[0x281])[0x256] = 1;
        } else {
            (p + p[0x281])[0x257] = 1;
        }
        return 1;
    case 0x20026:
    case 0x20027:
    case 0x20028:
        return 1;
    case 0x20029:
        fn_8039934C(m, *(s32*)(p + 0x1d8), *(s32*)(p + 0x1dc));
        return 1;
    case 0x2002a:
    case 0x2002b:
        return 1;
    case 0x2002c:
        return 1;
    case 0x2002d:
        return 1;
    case 0x2002e:
        return 1;
    case 0x2002f:
        return 1;
    case 0x20030:
        return 1;
    case 0x20031:
        return 1;
    case 0x20032:
        return 1;
    case 0x20033:
        return 1;
    case 0x30000:
        fn_80398A34(m, *(s16*)(p + 0x1ea));
        fn_80398700(m, data[0], *(s16*)(p + 0x1ea));
        return 1;
    case 0x30001:
        return 1;
    case 0x30002:
        fn_80398A34(m, *(s16*)(p + 0x1ec));
        fn_80398700(m, data[0], *(s16*)(p + 0x1ec));
        return 1;
    case 0x30003:
        fn_80398A34(m, *(s32*)(p + 0x1e0));
        fn_80398700(m, data[0], *(s32*)(p + 0x1e0));
        return 1;
    case 0x30004:
        fn_80398A34(m, *(s32*)(p + 0x1e4));
        fn_80398700(m, data[0], *(s32*)(p + 0x1e4));
        return 1;
    case 0x30005:
    {
        u8* e = lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 200;
        fn_80398EF4(m, e[0x79], e[0x78]);
        return 1;
    }
    case 0x30006:
        fn_80398A34(m, *(u16*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 200 + 0x34));
        fn_80398700(m, 4, *(u16*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 200 + 0x34));
        return 1;
    case 0x30007:
        fn_80398A34(m, *(u16*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 200 + 0x36));
        fn_80398700(m, 4, *(u16*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 200 + 0x36));
        return 1;
    case 0x30008:
        fn_80398A34(m, *(s32*)((u8*)lbl_8053AD78 + 0x10c));
        fn_80398700(m, 6, *(s32*)((u8*)lbl_8053AD78 + 0x10c));
        return 1;
    }
    return 0;
}

extern "C" const char lbl_805432B8[3];

// NONMATCHING (98%): FP register allocation in indent calc, r6/r7 swap.
extern "C" void fn_8039CDF8(MsgProc* p, u8 tag) {
    if (p->cur > p->lineTab[p->layout->m15c]) {
        strcat(p->str2c0, lbl_805432B8);
        strcat(p->str2c4, lbl_805432B8);
        p->m2d0 += 4;
    } else {
        p->rubySlot++;
        return;
    }
    s32 x = 0;
    if (!p->testBit(p->cur)) {
        MsgLayout* l = p->layout;
        if (l->m16c == 0 || !p->testBit(p->cur)) {
            f32 base;
            f32 pos;
            if (!(l->font->flags & 0x40)) {
                base = l->baseE8;
                pos = p->posA[p->cur];
            } else {
                base = l->baseF0;
                pos = p->posA[p->cur] + (p->posB[p->cur] - 3.0f);
            }
            x = (base - pos) * 0.5f + 0.5f;
        }
    }
    MsgLayout* l = p->layout;
    f32 fy = (f32)(p->slotLine[p->rubySlot + 3] - p->lineTab[l->m15c] - 1);
    f32 fx = (f32)x + p->slotOfs[p->rubySlot + 3];
    for (int i = 0; i < 12; i++) {
        if (l->ruby[i]->tag == 0xff) {
            l->ruby[i]->y = fy;
            l->ruby[i]->x = fx;
            l->ruby[i]->tag = tag;
            break;
        }
    }
    p->rubySlot++;
}

// NONMATCHING (97%): register coloring of cur/layout and slot index.
#pragma opt_propagation off
extern "C" void fn_8039D0DC(MsgProc* p, u8 tag) {
    MsgLayout* l;
    int cur;
    s32 x = 0;
    cur = p->cur;
    if (!p->testBit(cur)) {
        l = p->layout;
        if (l->m16c == 0 || !p->testBit(cur)) {
            f32 half;
            f32 delta;
            f32 offset;
            f32 base;
            f32 pos;
            if (!(l->font->flags & 0x40)) {
                base = l->baseE8;
                pos = p->posA[cur];
            } else {
                base = l->baseF0;
                offset = p->posB[cur] - 3.0f;
                pos = p->posA[cur] + offset;
            }
            delta = base - pos;
            half = 0.5f;
            x = delta * half + half;
        }
    }
    p->setSlotPos(p->slot, x);
    p->layout->slotTag[p->slot] = tag;
    p->slot++;
}
#pragma opt_propagation reset
// ---- fn_80396FDC: message-system owner destructor ----
struct MsgVObj {
    virtual ~MsgVObj();
};
struct MsgPad8 { u8 pad[8]; };
struct MsgVObj8 : MsgPad8 {
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual ~MsgVObj8();
};
extern void* lbl_804AF5A0[];
struct MsgSystem {
    void* vt;                          // 0x00
    JMessage::TResourceContainer* res; // 0x04
    MsgVObj* m08[4];                   // 0x08
    u8 pad18[0x20 - 0x18];
    MsgVObj* m20[4];                   // 0x20
    MsgVObj* m30[11];                  // 0x30
    MsgVObj* m5c;                      // 0x5c
    u8 pad60[0x68 - 0x60];
    void* buf[12];                     // 0x68
    u8 pad98[0x3bc - 0x98];
    MsgVObj8* m3bc;                    // 0x3bc
};

static inline void fn_clearRes(JMessage::TResourceContainer* r) {
    while (!r->mContainer.empty()) {
        JGadget::TLinkList<JMessage::TResource, 0>::iterator it = r->mContainer.begin();
        r->mContainer.erase(JGadget::TNodeLinkList::iterator(it.mIt));
        r->mContainer.Do_destroy(&*it);
    }
    r->mColor.reset();
}
extern "C" MsgSystem* fn_80396FDC(MsgSystem* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->vt = lbl_804AF5A0;
        for (int i = 0; i < 12; i++) {
            delete this_->buf[i];
            this_->buf[i] = 0;
        }
        delete this_->m3bc;
        this_->m3bc = 0;
        delete this_->m20[0];
        this_->m20[0] = 0;
        delete this_->m20[1];
        this_->m20[1] = 0;
        delete this_->m20[2];
        this_->m20[2] = 0;
        delete this_->m20[3];
        this_->m20[3] = 0;
        for (int i = 0; i < 11; i++) {
            delete this_->m30[i];
            this_->m30[i] = 0;
        }
        delete this_->m5c;
        this_->m5c = 0;
        fn_clearRes(this_->res);
        delete this_->res;
        this_->res = 0;
        delete this_->m08[0];
        this_->m08[0] = 0;
        delete this_->m08[1];
        this_->m08[1] = 0;
        delete this_->m08[2];
        this_->m08[2] = 0;
        delete this_->m08[3];
        this_->m08[3] = 0;
        if (freeFlag > 0) {
            delete this_;
        }
    }
    return this_;
}

// NONMATCHING (99.9%): r3/r5 swap in the setInfo copy.
extern "C" void fn_8039FB6C(MsgProc* p, const void* entry, const char* text) {
    MsgLayout* l = p->layout;
    l->m3ad = 0;
    l->m3ac = 0;
    l->m3ab = 0;
    *p->str2c0 = 0;
    *p->str2c4 = 0;
    p->cur = 0;
    p->m2d0 = 0;
    p->slot = 0;
    p->rubySlot = 0;
    p->layout->slotTag[0] = 0;
    p->layout->slotTag[1] = 0;
    p->layout->slotTag[2] = 0;
    p->layout->m154 = -1;
    p->m2d6 = 1;
    p->m70 = p->m2bc;
    s32 b;
    s32 a;
    s16 d;
    MsgLayout* q=p->layout;
    b=q->m17c;
    a=q->m178;
    d=q->m192;
    s16 c=q->m190;
    p->m222=c;
    p->m224=d;
    p->m218=a;
    p->m21c=b;
    s32 t = *(s32*)((char*)lbl_8053AD78 + 0x44);
    p->setTime(t);
    p->proc.setBegin_messageEntryText(p->res, entry, text);
    p->proc.process(0);
    p->layout->lineCount = p->lineTab[p->layout->m15c + 1] - p->lineTab[p->layout->m15c];
    p->layout->m170 = 0;
    if (p->lineTab[p->layout->m15c + 0x55] != 0) {
        p->layout->m19e = 0;
    }
    l = p->layout;
    if (l->m1aa == 0) {
        l->ruby[0]->tag = 0xff;
        l->ruby[1]->tag = 0xff;
        l->ruby[2]->tag = 0xff;
        l->ruby[3]->tag = 0xff;
        l->ruby[4]->tag = 0xff;
        l->ruby[5]->tag = 0xff;
        l->ruby[6]->tag = 0xff;
        l->ruby[7]->tag = 0xff;
        l->ruby[8]->tag = 0xff;
        l->ruby[9]->tag = 0xff;
        l->ruby[10]->tag = 0xff;
        l->ruby[11]->tag = 0xff;
    } else {
        p->str2c0[p->m2d0++] = -1;
        p->str2c0[p->m2d0++] = -1;
        if (p->layout->lineCount < 3) {
            p->str2c0[p->m2d0++] = -1;
            p->str2c0[p->m2d0++] = p->layout->lineCount + 0xc0;
        }
    }
}

extern "C" void fn_8039FB28(void* thisPtr) {
    u8* p = (u8*)thisPtr;
    if ((*(u8**)(p + 0x2d8))[0x1aa] != 0) {
        (*(s8**)(p + 0x2c0))[(*(s32*)(p + 0x2d0))++] = -1;
        (*(s8**)(p + 0x2c0))[(*(s32*)(p + 0x2d0))++] = -2;
    }
}

// ---- from src/Game/ClearIndirectFlags_0x2c0_0x2c4.cpp ----
// component C: 3 tiny vtable-slot/helper functions bundled.
extern "C" {
void fn_8039FE54(void* thisPtr) {
	void* p1 = *(void**)((char*)thisPtr + 0x2c0);
	*(u8*)p1 = 0;
	void* p2 = *(void**)((char*)thisPtr + 0x2c4);
	*(u8*)p2 = 0;
}

void fn_8039FE6C(void) {}

int fn_8039FE70(void) { return 1; }

static inline u8 readMessagePair(s32* out,const u8* data) {
    s32 a=*(const s32*)(data+1);
    s32 b=*(const s32*)(data+5);
    u8 id=data[0];
    out[0]=a;
    out[1]=b;
    return id;
}

struct MsgCounter {
    u8 pad0[0x4c];
    s32 m4c;
    s32 m50;
    s32 m54;
    s32 m58;
    u8 m5c;
    u8 m5d;
    u8 pad5e[2];
    u8* m60;
};

extern "C" u8 fn_803A313C(void*);
extern "C" void fn_803A3114(void*);
extern "C" void fn_803A30F0(void*);
extern "C" void fn_803A30E4(void*);
extern "C" s32 fn_803A310C(void*);
extern "C" void fn_803A30FC(void*,s32,s32);
extern "C" void fn_803A30DC(void*,s32);
extern "C" void fn_803A30D0(void*);
extern "C" void fn_803A30C4(void*);
extern "C" s32 fn_803A30BC(void*);
extern "C" void fn_803A30B0(void*);
extern "C" void fn_803A30A4(void*,u8,s32);
extern "C" s32 fn_803A309C(void*);
extern "C" s32 fn_803A3094(void*);
extern "C" void fn_803A3084(void*,s32,s32);
extern "C" void fn_803A3078(void*);
extern "C" void fn_803A3070(void*,s32);
extern "C" s16 fn_803A3068(void*);
extern "C" s16 fn_803A3060(void*);
extern "C" s32 fn_803A3058(void*);
extern "C" s32 fn_803A3050(void*);
extern "C" u16 fn_803A3034(void);
extern "C" u16 fn_803A3018(void);
extern "C" u8 fn_803A300C(void);
extern "C" void fn_803A2FFC(void);
extern "C" void fn_803A2FEC(void);
extern "C" s32 fn_803A2FE0(void);
extern "C" void fn_803A2E48(void*,s32);
extern "C" void fn_803A2CB0(void*,u8,s32);
extern "C" u8 fn_803A3168(s32,s32);
extern "C" void fn_803A31AC(s32,s32,s32);
extern "C" s32 fn_803A3200(void);
extern "C" s32 fn_803A3210(void);
extern "C" s32 fn_803A3220(void*);
extern "C" void fn_803A3228(s32,s32,s32);
extern "C" void fn_803A3144(void);
extern "C" void fn_8018E8DC(u8,s32,u8);
extern "C" u8 fn_8018E930(u8);
extern "C" u8 fn_8018A614(s32);
extern "C" u8 fn_8013997C(s32);
extern "C" s32 fn_8018E89C(void);
extern "C" s32 fn_8019CE40(s32,s32);
extern "C" f32 fn_80154744(void);
extern "C" void* fn_8015445C(s32);
extern "C" u32 fn_801544C8(void*);
extern "C" s32 fn_80154310(u32,u32,const Vec*,u32,s32,s32);
extern "C" s32 fn_8022EA0C(s32);
extern "C" s32 fn_8022CAF8(s32);
extern "C" void fn_80230E1C(s32,s32);
extern "C" s32 fn_80236100(s32);
extern "C" void fn_802362C4(s32,s32);
extern "C" void fn_8023619C(s32,s32);
extern "C" void fn_80236554(s32,s32,s32);
extern "C" s32 fn_8023725C(s32);
extern "C" void fn_802372F8(s32,s32,s32);
extern "C" s32 fn_802373EC(s32);
extern "C" void fn_80237524(s32,s32);
extern "C" s32 fn_80237810(s32);
extern "C" Vec* fn_8023E724(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u32 fn_8023EEB4(s32);
extern "C" s32 fn_8023ECF0(s32);
extern "C" void fn_8023EE28(s32);
extern "C" s32 fn_8023EF50(s32);
extern "C" u8 fn_8023EFEC(s32);
extern "C" s32 fn_803846A4(s32);
extern "C" s32 fn_803846BC(s32);
extern "C" void fn_8045B030(s32,u8,s32);
extern "C" void fn_80458FF0(void*,u32,s32,s32);
extern "C" const u8 lbl_80475D24[];
extern "C" const u8 lbl_80475D44[];
extern "C" const u32 lbl_805431D0[2];
#pragma optimization_level 4
extern "C" s32 fn_8039FE78(MsgCounter& object,s32 event,u8* payload){
u8* data=payload;
MsgCounter* p = &object;
u32 byte0;
u32 byte2;
u32 byte1;
u32 byte3;
u32 byte4;
u32 byte5;
u32 byte6;
u32 byte9;
s32 args[5];
if(!fn_803A313C(p->m60)){
switch((int)event){
case 0x0:
{

p->m58 = 1;
return 1;
}
case 0x10000:
case 0x10001:
case 0x10002:
case 0x10003:
case 0x10004:
case 0x10005:
case 0x10006:
case 0x10007:
case 0x10008:
case 0x10009:
case 0x1000a:
{

return 1;
}
case 0x1000b:
case 0x1000c:
{

return 1;
}
case 0x10010:
case 0x10011:
case 0x10012:
case 0x10013:
{

return 1;
}
case 0x20000:
case 0x20019:
{

fn_803A3114(p->m60);
return 1;
}
case 0x2000a:
case 0x20012:
{

fn_803A30FC(p->m60, fn_803A310C(p->m60), *(s32*)data);
fn_803A3114(p->m60);
return 1;
}
case 0x20001:
{

fn_803A3114(p->m60);
fn_803A30F0(p->m60);
fn_803A30E4(p->m60);
return 1;
}
case 0x20011:
{

fn_803A30FC(p->m60, fn_803A310C(p->m60), *(s32*)data);
fn_803A30DC(p->m60, *(s32*)data);
fn_803A3114(p->m60);
fn_803A30F0(p->m60);
fn_803A30E4(p->m60);
return 1;
}
case 0x20009:
{

fn_803A30FC(p->m60, fn_803A310C(p->m60), *(s32*)data);
fn_803A30DC(p->m60, *(s32*)data);
fn_803A3114(p->m60);
fn_803A30F0(p->m60);
fn_803A30D0(p->m60);
return 1;
}
case 0x2001a:
{

fn_803A3114(p->m60);
fn_803A30F0(p->m60);
fn_803A30D0(p->m60);
return 1;
}
case 0x20002:
case 0x2001b:
{

fn_803A3114(p->m60);
return 1;
}
case 0x2000c:
case 0x20014:
{

fn_803A30FC(p->m60, fn_803A310C(p->m60), *(s32*)data);
fn_803A3114(p->m60);
return 1;
}
case 0x20003:
{

fn_803A3114(p->m60);
fn_803A30C4(p->m60);
fn_803A30E4(p->m60);
return 1;
}
case 0x20013:
{

fn_803A30FC(p->m60, fn_803A310C(p->m60), *(s32*)data);
fn_803A30DC(p->m60, *(s32*)data);
fn_803A3114(p->m60);
fn_803A30C4(p->m60);
fn_803A30E4(p->m60);
return 1;
}
case 0x2000b:
{

fn_803A30FC(p->m60, fn_803A310C(p->m60), *(s32*)data);
fn_803A30DC(p->m60, *(s32*)data);
fn_803A3114(p->m60);
fn_803A30C4(p->m60);
fn_803A30D0(p->m60);
return 1;
}
case 0x2001c:
{

fn_803A3114(p->m60);
fn_803A30C4(p->m60);
fn_803A30D0(p->m60);
return 1;
}
case 0x20004:
{

p->m4c = *(u16*)data;
return 1;
}
case 0x20005:
{

return 1;
}
case 0x20006:
{
byte1 = data[1];
byte0 = data[0];
if (byte1 != 0) fn_8018E8DC(byte0,1,255);
else fn_8018E8DC(byte0,0,255);
return 1;
}
case 0x20007:
{

u8 id=readMessagePair(args,data);
if (fn_8018E930(id)) fn_803A30DC(p->m60,args[0]);
else fn_803A30DC(p->m60,args[1]);
return 1;
}
case 0x20008:
{
int a;
a = data[0];
byte1 = data[1];
byte2 = data[2];
byte3 = data[3];
if (fn_8018E930(a != 0 && byte1 == 1) || !fn_8018E930(a != 0 && byte1 == 0)) {
    if (byte3 != 0) fn_8018E8DC(byte2,1,255);
    else fn_8018E8DC(byte2,0,255);
}
return 1;
}
case 0x2000d:
{
s32 i;
byte5 = data[5];
args[0] = *(s32*)data;
byte4 = data[4];
byte6 = data[6];
if (byte5 == 5) {
    for (i =0;i<4;i++) {
        if (fn_8018A614(i)) {
if (byte4 == 0) {
    if (args[0] >= 100) fn_803A3228(i,args[0],0);
    else fn_802362C4(i,args[0]);
} else if (byte6 == 0) {
    if (args[0] >= 100) fn_803A3228(i,-args[0],0);
    else fn_802362C4(i,-args[0]);
} else {
    if (args[0] >= 100) fn_803A3228(i,-args[0],0);
    else fn_8023619C(i,-args[0]);
}
        }
    }
} else {
    switch ((int)byte5) {
    case 1: args[1]=0; break;
    case 2: args[1]=1; break;
    case 3: args[1]=2; break;
    case 4: args[1]=3; break;
    default: args[1]=fn_803A30BC(p->m60); break;
    }
if (byte4 == 0) {
    if (args[0] >= 100) fn_803A3228(args[1],args[0],0);
    else fn_802362C4(args[1],args[0]);
} else if (byte6 == 0) {
    if (args[0] >= 100) fn_803A3228(args[1],-args[0],0);
    else fn_802362C4(args[1],-args[0]);
} else {
    if (args[0] >= 100) fn_803A3228(args[1],-args[0],0);
    else fn_8023619C(args[1],-args[0]);
}
}
return 1;
}
case 0x2000e:
{
u32 n;
n = data[0];
if (n == 0) {
    n = fn_80237810(fn_803A30BC(p->m60));
    fn_80236554(fn_803A30BC(p->m60), (s32)n,0);
} else fn_80236554(fn_803A30BC(p->m60), (u8)n << 2,0);
return 1;
}
case 0x2000f:
{
u8 n;
n = data[0];
if (n == 0) fn_80237524(fn_803A30BC(p->m60),0x180);
else fn_80237524(fn_803A30BC(p->m60),(u8)(s8)n);
return 1;
}
case 0x20010:
{
void* obj;
byte0 = data[0];
s32 second = *(s32*)(data+5);
s32 first = *(s32*)(data+1);
byte9 = data[9];
args[1] = second;
args[0] = first;
args[2] = second;
switch (byte0) {
case 0: case 1: case 2: case 16:
    if (fn_8023EEB4(fn_8022EA0C(fn_803A30BC(p->m60))) == 'KEY0') {
        obj = fn_8015445C(fn_8023EF50(fn_8022EA0C(fn_803A30BC(p->m60))));
        if ((fn_803A3220(obj)==0 && byte0==0) || (fn_803A3220(obj)==1 && byte0==1) || (fn_803A3220(obj)==2 && byte0==2) || (fn_803A3220(obj)==9 && byte0==16)) {
            args[2] = args[0];
            if (byte9 != 0) fn_8023EE28(fn_8022EA0C(fn_803A30BC(p->m60)));
        }
    }
    break;
case 3:
    if (fn_8023EEB4(fn_8022EA0C(fn_803A30BC(p->m60))) == 'BORD') {
        args[2] = args[0];
        if (byte9 != 0) fn_8023EE28(fn_8022EA0C(fn_803A30BC(p->m60)));
    }
    break;
case 4:
    if (fn_8023EEB4(fn_8022EA0C(fn_803A30BC(p->m60))) == 'STON') {
        args[2] = args[0];
        if (byte9 != 0) fn_8023EE28(fn_8022EA0C(fn_803A30BC(p->m60)));
    }
    break;
case 5:
    if (fn_8023EEB4(fn_8022EA0C(fn_803A30BC(p->m60))) == 'HBMB') {
        args[2] = args[0];
        if (byte9 != 0) fn_8023EE28(fn_8022EA0C(fn_803A30BC(p->m60)));
    }
    break;
case 6:
    if (fn_8023EEB4(fn_8022EA0C(fn_803A30BC(p->m60))) == 'NIWA') {
        args[2] = args[0];
        if (byte9 != 0) fn_8023EE28(fn_8022EA0C(fn_803A30BC(p->m60)));
    }
    break;
case 7:
    if (fn_8023EEB4(fn_8022EA0C(fn_803A30BC(p->m60))) == 'GRAS') {
        args[2] = args[0];
        if (byte9 != 0) fn_8023EE28(fn_8022EA0C(fn_803A30BC(p->m60)));
    }
    break;
case 8: case 9: case 10:
    if (fn_8023EEB4(fn_8022EA0C(fn_803A30BC(p->m60))) == 'TUBO') {
        obj = fn_8015445C(fn_8022EA0C(fn_8023EF50(fn_803A30BC(p->m60))));
        if ((((fn_801544C8(obj)>>7)&31)==0 && byte0==10) || (((fn_801544C8(obj)>>7)&31)==1 && byte0==8) || (((fn_801544C8(obj)>>7)&31)==2 && byte0==9)) {
            args[2] = args[0];
            if (byte9 != 0) fn_8023EE28(fn_8022EA0C(fn_803A30BC(p->m60)));
        }
    }
    break;
case 11: case 12: case 13: case 14:
    if (fn_8023EEB4(fn_8022EA0C(fn_803A30BC(p->m60))) == 'PLAY') {
        if ((fn_8023ECF0(fn_8022EA0C(fn_803A30BC(p->m60)))==0 && byte0==11) || (fn_8023ECF0(fn_8022EA0C(fn_803A30BC(p->m60)))==1 && byte0==12) || (fn_8023ECF0(fn_8022EA0C(fn_803A30BC(p->m60)))==2 && byte0==13) || (fn_8023ECF0(fn_8022EA0C(fn_803A30BC(p->m60)))==3 && byte0==14)) args[2]=args[0];
    }
    break;
case 15:
    if (!fn_8023EFEC(fn_8022EA0C(fn_803A30BC(p->m60)))) args[2]=args[0];
    break;
}
fn_803A30DC(p->m60,args[2]);
return 1;
}
case 0x20015:
{
byte4 = data[4];
args[0] = *(s32*)data;
if (byte4==0) fn_803A30B0(p->m60);
fn_803A30A4(p->m60,byte4,args[0]);
return 1;
}
case 0x20016:
{

fn_8045B030(fn_803A309C(p->m60),data[0],0);
return 1;
}
case 0x20017:
{
u8 count;
f32 random;
s32 total;
s32 n;
count = data[0];
random = fn_80154744();
total = (u8)(s8)count;
n = (s32)((f32)(u32)total*random)+1;
if (n > total) n=total;
args[0] = fn_803846A4(fn_803A3094(p->m60));
args[0] += n;
args[1] = fn_803846BC(args[0]);
fn_803A30DC(p->m60,args[1]);
return 1;
}
case 0x20018:
{

args[0]=*(s32*)(data+0);
args[1]=*(s32*)(data+4);
args[2]=*(s32*)(data+8);
args[3]=*(s32*)(data+12);
fn_803A30DC(p->m60,args[fn_8018E89C()-1]);
return 1;
}
case 0x2001d:
{

args[0]=*(s32*)(data+0);
args[1]=*(s32*)(data+4);
args[2]=*(s32*)(data+8);
if (fn_80236100(fn_803A30BC(p->m60)) >= args[0]) fn_803A30DC(p->m60,args[1]);
else fn_803A30DC(p->m60,args[2]);
return 1;
}
case 0x2001e:
{

return 1;
}
case 0x2001f:
{

return 1;
}
case 0x20020:
{

args[0]=((s32*)data)[fn_803A30BC(p->m60)];
fn_803A30DC(p->m60,args[0]);
return 1;
}
case 0x20021:
{
s32 b;
s32 a;
args[0]=*(s32*)data;
args[1]=args[0];
b =fn_803A3200();
a =fn_803A3210();
if (fn_8019CE40(a,b)) fn_803A30DC(p->m60,args[0]);
else fn_803A30DC(p->m60,args[1]);
return 1;
}
case 0x20022:
{
s32 flag;
byte0 =data[0];
flag =*(u16*)(data+1);
byte3 =data[3];
if(byte0==5){
    if(byte3!=0){
        fn_803A31AC(0,flag,1);
        fn_803A31AC(1,flag,1);
        fn_803A31AC(2,flag,1);
        fn_803A31AC(3,flag,1);
    } else {
        fn_803A31AC(0,flag,0);
        fn_803A31AC(1,flag,0);
        fn_803A31AC(2,flag,0);
        fn_803A31AC(3,flag,0);
    }
} else if(byte0>=1 && byte0<=4){
    if(byte3!=0) fn_803A31AC((u8)(byte0-1),flag,1);
    else fn_803A31AC((u8)(byte0-1),flag,0);
} else {
    if(byte3!=0) fn_803A31AC((u8)fn_803A30BC(p->m60),flag,1);
    else fn_803A31AC((u8)fn_803A30BC(p->m60),flag,0);
}
return 1;
}
case 0x20023:
{
s32 flag;
u32 who;
byte0 =data[0];
args[0]=*(s32*)(data+3);
args[1]=*(s32*)(data+7);
flag =*(u16*)(data+1);

if (byte0>=1 && byte0<=4) who=byte0-1;
else who=(u8)fn_803A30BC(p->m60);
if (fn_803A3168(who,flag)) fn_803A30DC(p->m60,args[0]);
else fn_803A30DC(p->m60,args[1]);
return 1;
}
case 0x20024:
{
u8 kind;
s32 i;
u32 param;
s32 room;
s32 obj;
byte0 =data[0];
byte1 =data[1];
byte2 =data[2];
switch ((int)byte0) {
case 1: case 2: case 3: case 4: args[0]=byte0-1; break;
case 5: args[0]=5; break;
default: args[0]=fn_803A30BC(p->m60); break;
}

if(byte2==1) kind=lbl_80475D24[byte1]; else kind=lbl_80475D44[byte1];
for(i =0;i<4;i++){
    if(fn_8018A614(i)){
        if((u32)i==(u32)args[0] || byte0==5){
            param =(fn_8022EA0C(i)<<12)|0x100|kind;
            Vec& pos = *fn_8023E724(fn_8022EA0C(i));
            room =fn_8023DE58(fn_8022EA0C(i));
            obj =fn_80154310('TKRA',room,&pos,param,-1,-1);
            fn_803A3084(p->m60,i,obj);
        }
    }
}
return 1;
}
case 0x20025:
{

args[0]=*(s32*)data;
fn_803A30A4(p->m60,0,args[0]);
fn_803A30B0(p->m60);
return 1;
}
case 0x20026:
{
args[0]=*(s32*)data;
byte4 =data[4];
byte5 =data[5];
if(!fn_803A300C()) fn_803944C8(p->m60,args[0],byte4,byte5);
return 1;
}
case 0x20027:
{

fn_803A3078(p->m60);
fn_803A2FFC();
return 1;
}
case 0x20028:
{

fn_803A2FEC();
return 1;
}
case 0x20029:
case 0x2002a:
{

return 1;
}
case 0x2002b:
{

fn_803A3070(p->m60,data[0]);
return 1;
}
case 0x2002c:
{

args[0]=*(s32*)data;
args[1]=*(s32*)(data+4);
if(fn_8013997C(fn_803A30BC(p->m60))==2) fn_803A30DC(p->m60,args[0]);
else fn_803A30DC(p->m60,args[1]);
return 1;
}
case 0x2002d:
{

fn_8023EE28(fn_8022EA0C(fn_803A30BC(p->m60)));
return 1;
}
case 0x2002e:
{

if(fn_803A30BC(p->m60)>=0 && fn_803A30BC(p->m60)<4 && fn_8018A614(fn_803A30BC(p->m60)) && fn_8013997C(fn_803A30BC(p->m60))==1 && fn_8023DE58(fn_803A30BC(p->m60))>=8) fn_80230E1C(fn_803A30BC(p->m60),0);
return 1;
}
case 0x2002f:
{

return 1;
}
case 0x20030:
{

args[0]=*(s32*)data;
args[1]=*(s32*)(data+4);
if(fn_8022CAF8(fn_803A30BC(p->m60))!=4) fn_803A30DC(p->m60,args[0]);
else fn_803A30DC(p->m60,args[1]);
return 1;
}
case 0x20031:
{

if(data[0]==0) fn_803A3144();
else fn_80458FF0(lbl_8053AF80,lbl_805431D0[data[0]],1,0);
return 1;
}
case 0x20032:
{
s32 a;
u32 param;
s32 room;
if(fn_802373EC(fn_8022EA0C(fn_803A30BC(p->m60)))!=0){
    a =fn_802373EC(fn_8022EA0C(fn_803A30BC(p->m60)));
    param =(fn_8023725C(fn_8022EA0C(fn_803A30BC(p->m60)))<<22)|a;
    Vec& pos = *fn_8023E724(fn_8022EA0C(fn_803A30BC(p->m60)));
    room =fn_8023DE58(fn_8022EA0C(fn_803A30BC(p->m60)));
    fn_80154310('LSTI',room,&pos,param,-1,-1);
    fn_802372F8(fn_8022EA0C(fn_803A30BC(p->m60)),0,1);
}
return 1;
}
case 0x20033:
{

args[0]=*(s32*)data;
args[1]=*(s32*)(data+4);
if(fn_802373EC(fn_8022EA0C(fn_803A30BC(p->m60)))==1) fn_803A30DC(p->m60,args[0]);
else fn_803A30DC(p->m60,args[1]);
return 1;
}
case 0x30000:
{

fn_803A2E48(p,fn_803A3068(p->m60));
fn_803A2CB0(p,data[0],fn_803A3068(p->m60));
return 1;
}
case 0x30001:
{

return 1;
}
case 0x30002:
{

fn_803A2E48(p,fn_803A3060(p->m60));
fn_803A2CB0(p,data[0],fn_803A3060(p->m60));
return 1;
}
case 0x30003:
{

fn_803A2E48(p,fn_803A3058(p->m60));
fn_803A2CB0(p,data[0],fn_803A3058(p->m60));
return 1;
}
case 0x30004:
{

fn_803A2E48(p,fn_803A3050(p->m60));
fn_803A2CB0(p,data[0],fn_803A3050(p->m60));
return 1;
}
case 0x30005:
{

return 1;
}
case 0x30006:
{

fn_803A2E48(p,fn_803A3034());
fn_803A2CB0(p,4,fn_803A3034());
return 1;
}
case 0x30007:
{

fn_803A2E48(p,fn_803A3018());
fn_803A2CB0(p,4,fn_803A3018());
return 1;
}
case 0x30008:
{

fn_803A2E48(p,fn_803A2FE0());
fn_803A2CB0(p,6,fn_803A2FE0());
return 1;
}
}
}else{
switch((int)event){
case 0x0:
{

p->m58 = 1;
return 1;
}
case 0x10000:
case 0x10001:
case 0x10002:
case 0x10003:
{

p->m50 +=4;
return 1;
}
case 0x10007:
case 0x10008:
case 0x10009:
case 0x1000a:
{

p->m50 +=4;
return 1;
}
case 0x10004:
case 0x10005:
case 0x10006:
case 0x1000b:
case 0x1000c:
{

p->m50 +=2;
return 1;
}
case 0x10010:
case 0x10011:
case 0x10012:
case 0x10013:
{

return 1;
}
case 0x20000:
case 0x20019:
{

fn_803A3114(p->m60);
return 1;
}
case 0x2000a:
case 0x20012:
{

fn_803A30FC(p->m60, fn_803A310C(p->m60), *(s32*)data);
fn_803A3114(p->m60);
return 1;
}
case 0x20001:
{

fn_803A3114(p->m60);
fn_803A30F0(p->m60);
fn_803A30E4(p->m60);
return 1;
}
case 0x20011:
{

fn_803A30FC(p->m60, fn_803A310C(p->m60), *(s32*)data);
fn_803A30DC(p->m60, *(s32*)data);
fn_803A3114(p->m60);
fn_803A30F0(p->m60);
fn_803A30E4(p->m60);
return 1;
}
case 0x2001a:
{

fn_803A3114(p->m60);
fn_803A30F0(p->m60);
fn_803A30D0(p->m60);
return 1;
}
case 0x20009:
{

fn_803A30FC(p->m60, fn_803A310C(p->m60), *(s32*)data);
fn_803A30DC(p->m60, *(s32*)data);
fn_803A3114(p->m60);
fn_803A30F0(p->m60);
fn_803A30D0(p->m60);
return 1;
}
case 0x20002:
case 0x2001b:
{

fn_803A3114(p->m60);
return 1;
}
case 0x2000c:
case 0x20014:
{

fn_803A30FC(p->m60, fn_803A310C(p->m60), *(s32*)data);
fn_803A3114(p->m60);
return 1;
}
case 0x20003:
{

fn_803A3114(p->m60);
fn_803A30C4(p->m60);
fn_803A30E4(p->m60);
return 1;
}
case 0x20013:
{

fn_803A30FC(p->m60, fn_803A310C(p->m60), *(s32*)data);
fn_803A30DC(p->m60, *(s32*)data);
fn_803A3114(p->m60);
fn_803A30C4(p->m60);
fn_803A30E4(p->m60);
return 1;
}
case 0x2001c:
{

fn_803A3114(p->m60);
fn_803A30C4(p->m60);
fn_803A30D0(p->m60);
return 1;
}
case 0x2000b:
{

fn_803A30FC(p->m60, fn_803A310C(p->m60), *(s32*)data);
fn_803A30DC(p->m60, *(s32*)data);
fn_803A3114(p->m60);
fn_803A30C4(p->m60);
fn_803A30D0(p->m60);
return 1;
}
case 0x20004:
{

p->m4c = *(u16*)data;
return 1;
}
case 0x20005:
{

return 1;
}
case 0x20006:
{
byte1 = data[1];
byte0 = data[0];
if (byte1 != 0) fn_8018E8DC(byte0,1,255);
else fn_8018E8DC(byte0,0,255);
return 1;
}
case 0x20007:
{

u8 id=readMessagePair(args,data);
if (fn_8018E930(id)) fn_803A30DC(p->m60,args[0]);
else fn_803A30DC(p->m60,args[1]);
return 1;
}
case 0x20008:
{
int a;
a = data[0];
byte1 = data[1];
byte2 = data[2];
byte3 = data[3];
if (fn_8018E930(a != 0 && byte1 == 1) || !fn_8018E930(a != 0 && byte1 == 0)) {
    if (byte3 != 0) fn_8018E8DC(byte2,1,255);
    else fn_8018E8DC(byte2,0,255);
}
return 1;
}
case 0x2000d:
{
s32 i;
byte5 = data[5];
args[0] = *(s32*)data;
byte4 = data[4];
byte6 = data[6];
if (byte5 == 5) {
    for (i =0;i<4;i++) {
        if (fn_8018A614(i)) {
if (byte4 == 0) {
    if (args[0] >= 100) fn_803A3228(i,args[0],0);
    else fn_802362C4(i,args[0]);
} else if (byte6 == 0) {
    if (args[0] >= 100) fn_803A3228(i,-args[0],0);
    else fn_802362C4(i,-args[0]);
} else {
    if (args[0] >= 100) fn_803A3228(i,-args[0],0);
    else fn_8023619C(i,-args[0]);
}
        }
    }
} else {
    switch ((int)byte5) {
    case 1: args[1]=0; break;
    case 2: args[1]=1; break;
    case 3: args[1]=2; break;
    case 4: args[1]=3; break;
    default: args[1]=fn_803A30BC(p->m60); break;
    }
if (byte4 == 0) {
    if (args[0] >= 100) fn_803A3228(args[1],args[0],0);
    else fn_802362C4(args[1],args[0]);
} else if (byte6 == 0) {
    if (args[0] >= 100) fn_803A3228(args[1],-args[0],0);
    else fn_802362C4(args[1],-args[0]);
} else {
    if (args[0] >= 100) fn_803A3228(args[1],-args[0],0);
    else fn_8023619C(args[1],-args[0]);
}
}
return 1;
}
case 0x2000e:
{
u32 n;
n = data[0];
if (n == 0) {
    n = fn_80237810(fn_803A30BC(p->m60));
    fn_80236554(fn_803A30BC(p->m60), (s32)n,0);
} else fn_80236554(fn_803A30BC(p->m60), (u8)n << 2,0);
return 1;
}
case 0x2000f:
{
u8 n;
n = data[0];
if (n == 0) fn_80237524(fn_803A30BC(p->m60),0x180);
else fn_80237524(fn_803A30BC(p->m60),(u8)(s8)n);
return 1;
}
case 0x20010:
{
void* obj;
byte0 = data[0];
s32 second = *(s32*)(data+5);
s32 first = *(s32*)(data+1);
byte9 = data[9];
args[1] = second;
args[0] = first;
args[2] = second;
switch (byte0) {
case 0: case 1: case 2: case 16:
    if (fn_8023EEB4(fn_8022EA0C(fn_803A30BC(p->m60))) == 'KEY0') {
        obj = fn_8015445C(fn_8023EF50(fn_8022EA0C(fn_803A30BC(p->m60))));
        if ((fn_803A3220(obj)==0 && byte0==0) || (fn_803A3220(obj)==1 && byte0==1) || (fn_803A3220(obj)==2 && byte0==2) || (fn_803A3220(obj)==9 && byte0==16)) {
            args[2] = args[0];
            if (byte9 != 0) fn_8023EE28(fn_8022EA0C(fn_803A30BC(p->m60)));
        }
    }
    break;
case 3:
    if (fn_8023EEB4(fn_8022EA0C(fn_803A30BC(p->m60))) == 'BORD') {
        args[2] = args[0];
        if (byte9 != 0) fn_8023EE28(fn_8022EA0C(fn_803A30BC(p->m60)));
    }
    break;
case 4:
    if (fn_8023EEB4(fn_8022EA0C(fn_803A30BC(p->m60))) == 'STON') {
        args[2] = args[0];
        if (byte9 != 0) fn_8023EE28(fn_8022EA0C(fn_803A30BC(p->m60)));
    }
    break;
case 5:
    if (fn_8023EEB4(fn_8022EA0C(fn_803A30BC(p->m60))) == 'HBMB') {
        args[2] = args[0];
        if (byte9 != 0) fn_8023EE28(fn_8022EA0C(fn_803A30BC(p->m60)));
    }
    break;
case 6:
    if (fn_8023EEB4(fn_8022EA0C(fn_803A30BC(p->m60))) == 'NIWA') {
        args[2] = args[0];
        if (byte9 != 0) fn_8023EE28(fn_8022EA0C(fn_803A30BC(p->m60)));
    }
    break;
case 7:
    if (fn_8023EEB4(fn_8022EA0C(fn_803A30BC(p->m60))) == 'GRAS') {
        args[2] = args[0];
        if (byte9 != 0) fn_8023EE28(fn_8022EA0C(fn_803A30BC(p->m60)));
    }
    break;
case 8: case 9: case 10:
    if (fn_8023EEB4(fn_8022EA0C(fn_803A30BC(p->m60))) == 'TUBO') {
        obj = fn_8015445C(fn_8023EF50(fn_8022EA0C(fn_803A30BC(p->m60))));
        if ((((fn_801544C8(obj)>>7)&31)==0 && byte0==10) || (((fn_801544C8(obj)>>7)&31)==1 && byte0==8) || (((fn_801544C8(obj)>>7)&31)==2 && byte0==9)) {
            args[2] = args[0];
            if (byte9 != 0) fn_8023EE28(fn_8022EA0C(fn_803A30BC(p->m60)));
        }
    }
    break;
case 11: case 12: case 13: case 14:
    if (fn_8023EEB4(fn_8022EA0C(fn_803A30BC(p->m60))) == 'PLAY') {
        if ((fn_8023ECF0(fn_8022EA0C(fn_803A30BC(p->m60)))==0 && byte0==11) || (fn_8023ECF0(fn_8022EA0C(fn_803A30BC(p->m60)))==1 && byte0==12) || (fn_8023ECF0(fn_8022EA0C(fn_803A30BC(p->m60)))==2 && byte0==13) || (fn_8023ECF0(fn_8022EA0C(fn_803A30BC(p->m60)))==3 && byte0==14)) args[2]=args[0];
    }
    break;
case 15:
    if (!fn_8023EFEC(fn_8022EA0C(fn_803A30BC(p->m60)))) args[2]=args[0];
    break;
}
fn_803A30DC(p->m60,args[2]);
return 1;
}
case 0x20015:
{

args[0]=*(s32*)data;
fn_803A30A4(p->m60,data[4],args[0]);
return 1;
}
case 0x20016:
{
byte0 =data[0];
if(byte0>5 && (u8)(s8)byte0!=11) fn_8045B030(fn_803A309C(p->m60),byte0,0);
return 1;
}
case 0x20017:
{
u8 count;
f32 random;
s32 total;
s32 n;
count = data[0];
random = fn_80154744();
total = (u8)(s8)count;
n = (s32)((f32)(u32)total*random)+1;
if (n > total) n=total;
args[0] = fn_803846A4(fn_803A3094(p->m60));
args[0] += n;
args[1] = fn_803846BC(args[0]);
fn_803A30DC(p->m60,args[1]);
return 1;
}
case 0x20018:
{

args[0]=*(s32*)(data+0);
args[1]=*(s32*)(data+4);
args[2]=*(s32*)(data+8);
args[3]=*(s32*)(data+12);
fn_803A30DC(p->m60,args[fn_8018E89C()-1]);
return 1;
}
case 0x2001d:
{

args[0]=*(s32*)(data+0);
args[1]=*(s32*)(data+4);
args[2]=*(s32*)(data+8);
if (fn_80236100(fn_803A30BC(p->m60)) >= args[0]) fn_803A30DC(p->m60,args[1]);
else fn_803A30DC(p->m60,args[2]);
return 1;
}
case 0x2001e:
{

return 1;
}
case 0x2001f:
{

return 1;
}
case 0x20020:
{

args[0]=((s32*)data)[fn_803A30BC(p->m60)];
fn_803A30DC(p->m60,args[0]);
return 1;
}
case 0x20021:
{
s32 b;
s32 a;
args[0]=*(s32*)data;
args[1]=args[0];
b =fn_803A3200();
a =fn_803A3210();
if (fn_8019CE40(a,b)) fn_803A30DC(p->m60,args[0]);
else fn_803A30DC(p->m60,args[1]);
return 1;
}
case 0x20022:
{
s32 flag;
byte0 =data[0];
flag =*(u16*)(data+1);
byte3 =data[3];
if(byte0==5){
    if(byte3!=0){
        fn_803A31AC(0,flag,1);
        fn_803A31AC(1,flag,1);
        fn_803A31AC(2,flag,1);
        fn_803A31AC(3,flag,1);
    } else {
        fn_803A31AC(0,flag,0);
        fn_803A31AC(1,flag,0);
        fn_803A31AC(2,flag,0);
        fn_803A31AC(3,flag,0);
    }
} else if(byte0>=1 && byte0<=4){
    if(byte3!=0) fn_803A31AC((u8)(byte0-1),flag,1);
    else fn_803A31AC((u8)(byte0-1),flag,0);
} else {
    if(byte3!=0) fn_803A31AC((u8)fn_803A30BC(p->m60),flag,1);
    else fn_803A31AC((u8)fn_803A30BC(p->m60),flag,0);
}
return 1;
}
case 0x20023:
{
s32 flag;
u32 who;
byte0 =data[0];
args[0]=*(s32*)(data+3);
args[1]=*(s32*)(data+7);
flag =*(u16*)(data+1);

if (byte0>=1 && byte0<=4) who=byte0-1;
else who=(u8)fn_803A30BC(p->m60);
if (fn_803A3168(who,flag)) fn_803A30DC(p->m60,args[0]);
else fn_803A30DC(p->m60,args[1]);
return 1;
}
case 0x20024:
{
u8 kind;
s32 i;
u32 param;
s32 room;
s32 obj;
byte0 =data[0];
byte1 =data[1];
byte2 =data[2];
switch ((int)byte0) {
case 1: case 2: case 3: case 4: args[0]=byte0-1; break;
case 5: args[0]=5; break;
default: args[0]=fn_803A30BC(p->m60); break;
}

if(byte2==1) kind=lbl_80475D24[byte1]; else kind=lbl_80475D44[byte1];
for(i =0;i<4;i++){
    if(fn_8018A614(i)){
        if((u32)i==(u32)args[0] || byte0==5){
            param =(fn_8022EA0C(i)<<12)|0x100|kind;
            Vec& pos = *fn_8023E724(fn_8022EA0C(i));
            room =fn_8023DE58(fn_8022EA0C(i));
            obj =fn_80154310('TKRA',room,&pos,param,-1,-1);
            fn_803A3084(p->m60,i,obj);
        }
    }
}
return 1;
}
case 0x20025:
{

args[0]=*(s32*)data;
fn_803A30A4(p->m60,0,args[0]);
fn_803A30B0(p->m60);
return 1;
}
case 0x20026:
{
args[0]=*(s32*)data;
byte4 =data[4];
byte5 =data[5];
if(!fn_803A300C()) fn_803944C8(p->m60,args[0],byte4,byte5);
return 1;
}
case 0x20027:
{

fn_803A3078(p->m60);
fn_803A2FFC();
return 1;
}
case 0x20028:
{

fn_803A2FEC();
return 1;
}
case 0x20029:
case 0x2002a:
{

return 1;
}
case 0x2002b:
{

fn_803A3070(p->m60,data[0]);
return 1;
}
case 0x2002c:
{

args[0]=*(s32*)data;
args[1]=*(s32*)(data+4);
if(fn_8013997C(fn_803A30BC(p->m60))==2) fn_803A30DC(p->m60,args[0]);
else fn_803A30DC(p->m60,args[1]);
return 1;
}
case 0x2002d:
{

fn_8023EE28(fn_8022EA0C(fn_803A30BC(p->m60)));
return 1;
}
case 0x2002e:
{

if(fn_803A30BC(p->m60)>=0 && fn_803A30BC(p->m60)<4 && fn_8018A614(fn_803A30BC(p->m60)) && fn_8013997C(fn_803A30BC(p->m60))==1 && fn_8023DE58(fn_803A30BC(p->m60))>=8) fn_80230E1C(fn_803A30BC(p->m60),0);
return 1;
}
case 0x2002f:
{

return 1;
}
case 0x20030:
{

args[0]=*(s32*)data;
args[1]=*(s32*)(data+4);
if(fn_8022CAF8(fn_803A30BC(p->m60))!=4) fn_803A30DC(p->m60,args[0]);
else fn_803A30DC(p->m60,args[1]);
return 1;
}
case 0x20031:
{

if(data[0]==0) fn_803A3144();
else fn_80458FF0(lbl_8053AF80,lbl_805431D0[data[0]],1,0);
return 1;
}
case 0x20032:
{
s32 a;
u32 param;
s32 room;
if(fn_802373EC(fn_8022EA0C(fn_803A30BC(p->m60)))!=0){
    a =fn_802373EC(fn_8022EA0C(fn_803A30BC(p->m60)));
    param =(fn_8023725C(fn_8022EA0C(fn_803A30BC(p->m60)))<<22)|a;
    Vec& pos = *fn_8023E724(fn_8022EA0C(fn_803A30BC(p->m60)));
    room =fn_8023DE58(fn_8022EA0C(fn_803A30BC(p->m60)));
    fn_80154310('LSTI',room,&pos,param,-1,-1);
    fn_802372F8(fn_8022EA0C(fn_803A30BC(p->m60)),0,1);
}
return 1;
}
case 0x20033:
{

args[0]=*(s32*)data;
args[1]=*(s32*)(data+4);
if(fn_802373EC(fn_8022EA0C(fn_803A30BC(p->m60)))==1) fn_803A30DC(p->m60,args[0]);
else fn_803A30DC(p->m60,args[1]);
return 1;
}
case 0x30000:
{

fn_803A2E48(p,fn_803A3068(p->m60));
fn_803A2CB0(p,data[0],fn_803A3068(p->m60));
return 1;
}
case 0x30001:
{

return 1;
}
case 0x30002:
{

fn_803A2E48(p,fn_803A3060(p->m60));
fn_803A2CB0(p,data[0],fn_803A3060(p->m60));
return 1;
}
case 0x30003:
{

fn_803A2E48(p,fn_803A3058(p->m60));
fn_803A2CB0(p,data[0],fn_803A3058(p->m60));
return 1;
}
case 0x30004:
{

fn_803A2E48(p,fn_803A3050(p->m60));
fn_803A2CB0(p,data[0],fn_803A3050(p->m60));
return 1;
}
case 0x30005:
{

return 1;
}
case 0x30006:
{

fn_803A2E48(p,fn_803A3034());
fn_803A2CB0(p,4,fn_803A3034());
return 1;
}
case 0x30007:
{

fn_803A2E48(p,fn_803A3018());
fn_803A2CB0(p,4,fn_803A3018());
return 1;
}
case 0x30008:
{

fn_803A2E48(p,fn_803A2FE0());
fn_803A2CB0(p,6,fn_803A2FE0());
return 1;
}
}
}
return 0;
}
}

struct MsgFont {
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void getWidthEntry(int c, void* out);
    virtual int getHeight();
};

struct MsgWidth {
    s8 a;
    u8 w;
    u8 pad[6];
};

extern "C" void fn_8039A350(void* thisObj, int c) {
    u8* p = (u8*)thisObj;
    if (c == 10) {
        p[0x201]++;
        p[0x22c]++;
        ((f32*)(p + 0x4c))[p[0x201]] = 0.0f;
        p[p[0x201] + 0x22d] = 0;
        ((f32*)(p + 0xf4))[p[0x201]] = 0.0f;
        p[0x1e8] = 0;
        s8 cur = ((s8*)(p + 0x202))[p[0x281]];
        if (cur != (s8)p[0x22c] && p[0x201] - cur >= 3) {
            p[0x281]++;
            p[p[0x281] + 0x202] = p[0x22c];
            p[p[0x281] + 0x257] = 0;
            p[0x1e8] = 1;
        }
    } else {
        MsgFont* font = *(MsgFont**)(p + 0x38);
        f32 scale = *(f32*)(p + 0x48) / font->getHeight();
        MsgWidth w;
        (*(MsgFont**)(p + 0x38))->getWidthEntry(c, &w);
        ((f32*)(p + 0x4c))[p[0x201]] += scale * (*(f32*)(p + 0x44) * (int)w.w);
        ((f32*)(p + 0xf4))[p[0x201]] += 3.0f;
        p[p[0x201] + 0x22d]++;
    }
}

// ---- from src/Game/stub_8039a510.cpp ----
// fn_8039A510 - component B vtable slot: advances a byte counter
// (this->0x281), then uses the counter as a byte offset from `this` to
// write 2 fields (a copy of this->0x22c, then a zero) at that
// dynamically-offset location. Each use re-reads the counter from
// memory rather than caching it, matching retail's own reload pattern.
extern "C" void fn_8039A510(void* thisObj) {
	u8* base = (u8*)thisObj;
	base[0x281] = base[0x281] + 1;
	base[base[0x281] + 0x202] = base[0x22c];
	base[base[0x281] + 0x257] = 0;
}


extern f32 lbl_805431DC;

extern "C" void fn_8039A540(void* thisObj) {
    u8* p = (u8*)thisObj;
    *(s32*)(p + 0x3c) = -1;
    *(s32*)(p + 0x40) = -1;
    p[0x201] = 0;
    ((f32*)(p + 0x4c))[p[0x201]] = 0.0f;
    ((f32*)(p + 0xf4))[p[0x201]] = 0.0f;
    p[p[0x201] + 0x22d] = 0;
    p[0x22c] = 0;
    p[0x281] = 0;
    p[0x282] = 0;
    for (int i = 0; i < 3; i++) {
        ((f32*)(p + 0x19c))[i] = 0.0f;
        p[0x1ee + i] = 0;
        p[0x1fe + i] = 0;
    }
    p[0x1fd] = 0;
    for (int i = 3; i < 15; i++) {
        ((f32*)(p + 0x19c))[i] = 0.0f;
        p[0x1ee + i] = 0;
    }
    ((s8*)(p + 0x202))[p[0x281]] = -1;
    p[p[0x281] + 0x257] = 0;
    p[0x1e8] = 0;
}

#pragma opt_propagation off
extern "C" void fn_8039A638(MsgProc* p, s16 n) {
    char buf[8];
    s32 cur;
    f32 half, difference, spacing, fVar4, fVar3;
    s32 bVar2;
    s32 bVar1;
    u8* e;

    buf[2] = 0;
    buf[1] = 0;
    buf[0] = 0;
    e = lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8;
    bVar1 = e[0x79];
    bVar2 = e[0x78];

    if (n == 0) {
        if (p->m2d6 != 0) {
            cur = p->cur;
            if (!p->testBit(cur)) {
                if (!(p->layout->m16c != 0 && p->testBit(cur))) {
                    MsgLayout* l = p->layout;
                    MsgFontInfo* font = l->font;
                    s32 i;
                    if ((font->flags & 0x40) == 0) {
                        fVar3 = l->baseE8;
                        fVar4 = p->posA[cur];
                    } else {
                        fVar3 = l->baseF0;
                        spacing = p->posB[cur] - lbl_805431E8;
                        fVar4 = p->posA[cur] + spacing;
                    }
                    difference = fVar3 - fVar4;
                    half = lbl_805431E4;
                    i = (s32)(difference * half + half);
                    if (i > 0) {
                        snprintf(lbl_8050E548, 0xf, lbl_80543298, i);
                        strcat(p->str2c0, lbl_8050E548);
                        strcat(p->str2c4, lbl_8050E548);
                        p->m2d0 += strlen(lbl_8050E548);
                    }
                }
            }
            p->m2d6 = 0;
        }

        if (bVar1 > 99) {
            bVar1 = 99;
        }
        s32 q = bVar1 / 10;
        bVar1 %= 10;
        if (q > 0) {
            buf[0] = q + '0';
            msgAppendChar(p, buf);
        }
        buf[0] = bVar1 + '0';
        msgAppendChar(p, buf);
        strcat(p->str2c0, "'");
        strcat(p->str2c4, "'");
        p->m2d0 += 1;

        if (bVar2 > 99) {
            bVar2 = 99;
        }
        s32 q2 = bVar2 / 10;
        buf[0] = q2 + '0';
        msgAppendChar(p, buf);
        buf[0] = bVar2 % 10 + '0';
        msgAppendChar(p, buf);
        strcat(p->str2c0, "''");
        strcat(p->str2c4, "''");
        p->m2d0 += 2;
    } else {
        if (bVar1 > 99) {
            bVar1 = 99;
        }
        s32 q = bVar1 / 10;
        s32 rem1 = bVar1 % 10;
        if (q > 0) {
            { u16 wide1 = msgToWideScan((u16)(q + '0')); p->str2c0[p->m2d0++] = wide1 >> 8; p->str2c0[p->m2d0++] = wide1; }
        }
        u16 wide;
        u32 c;
        int i;
        const MsgCharMap* entry;
        const MsgCharMap* table;
        table = lbl_80475830;
        { entry = table; c = (u16)(rem1 + '0'); for(i = 0; entry->ascii != 0xffff; ++i, ++entry) { if (c == entry->ascii) {wide=lbl_80475830[i].code; goto wideDone0;} } wide=0x1420; wideDone0: p->str2c0[p->m2d0++] = wide >> 8; p->str2c0[p->m2d0++] = wide; }
        p->str2c0[p->m2d0++] = 0x39;
        p->str2c0[p->m2d0++] = 0xe0;
        if (bVar2 > 99) {
            bVar2 = 99;
        }
        s32 rem2 = bVar2 % 10;
        s32 q2 = bVar2 / 10;
        { entry = table; c = (u16)(q2 + '0'); for(i = 0; entry->ascii != 0xffff; ++i, ++entry) { if (c == entry->ascii) {wide=lbl_80475830[i].code; goto wideDone1;} } wide=0x1420; wideDone1: p->str2c0[p->m2d0++] = wide >> 8; p->str2c0[p->m2d0++] = wide; }
        { entry = table; c = (u16)(rem2 + '0'); for(i = 0; entry->ascii != 0xffff; ++i, ++entry) { if (c == entry->ascii) {wide=lbl_80475830[i].code; goto wideDone2;} } wide=0x1420; wideDone2: p->str2c0[p->m2d0++] = wide >> 8; p->str2c0[p->m2d0++] = wide; }
        p->str2c0[p->m2d0++] = 0x3c;
        p->str2c0[p->m2d0++] = 0xa0;
    }
}
#pragma opt_propagation off
extern "C" void fn_8039ACD0(u8* param_1, s16 param_2) {
    MsgProc* p = (MsgProc*)param_1;
    char buf[8];
    s32 mins, hours;
    f32 half, difference, spacing, pos, base;
    buf[2]=0; buf[1]=0; buf[0]=0;
    s32 total=*(s32*)((u8*)lbl_8053AD78+0x44);
    hours=total/3600;
    int minutes=(total/60)%60;
    if(minutes==0) minutes=1;
    mins=minutes;
    if(param_2==0) {
        if(p->m2d6) {
            s32 cur=p->cur;
            if(!p->testBit(cur)) {
                if(!(p->layout->m16c != 0 && p->testBit(cur))) {
                    MsgLayout* l=p->layout;
                    if(!(l->font->flags&0x40)) {
                        base=l->baseE8; pos=p->posA[cur];
                    } else {
                        base=l->baseF0; spacing=p->posB[cur]-lbl_805431E8; pos=p->posA[cur]+spacing;
                    }
                    difference=base-pos;
                    half=lbl_805431E4;
                    s32 x=difference*half+half;
                    if(x>0) {
                        snprintf(lbl_8050E538,0xf,lbl_80543298,x);
                        strcat(p->str2c0,lbl_8050E538);
                        strcat(p->str2c4,lbl_8050E538);
                        p->m2d0+=strlen(lbl_8050E538);
                    }
                }
            }
            p->m2d6=0;
        }
        if(hours>0) {
            if(hours>99) { hours=99; mins=59; }
            s32 tens=hours/10, ones=hours%10;
            if(tens>0) {buf[0]=tens+'0'; msgAppendChar(p,buf);}
            buf[0]=ones+'0'; msgAppendChar(p,buf);
            strcat(p->str2c0,"'"); strcat(p->str2c4,"'"); p->m2d0++;
        }
        if(mins>59) mins=59;
        s32 tens=mins/10; mins%=10;
        if(tens>0||hours>0) {buf[0]=tens+'0';msgAppendChar(p,buf);}
        buf[0]=mins+'0';msgAppendChar(p,buf);
        strcat(p->str2c0,"''");strcat(p->str2c4,"''");p->m2d0+=2;
    } else {
        if(hours>99) {hours=99;mins=59;}
        s32 tens=hours/10, ones=hours%10;
        if(hours>0) {
            if(tens>0) {
                u16 w=msgToWideScan(tens+'0');p->str2c0[p->m2d0++]=w>>8;p->str2c0[p->m2d0++]=w;
            }
            u16 w=msgToWideScan(ones+'0');p->str2c0[p->m2d0++]=w>>8;p->str2c0[p->m2d0++]=w;
            p->str2c0[p->m2d0++]=0x39;p->str2c0[p->m2d0++]=0xe0;
        }
        if(mins>59) mins=59;
        tens=mins/10; ones=mins%10;
        if(tens>0) {u16 w=msgToWideScan(tens+'0');p->str2c0[p->m2d0++]=w>>8;p->str2c0[p->m2d0++]=w;}
        u16 w=msgToWideScan(ones+'0');p->str2c0[p->m2d0++]=w>>8;p->str2c0[p->m2d0++]=w;
        p->str2c0[p->m2d0++]=0x3c;p->str2c0[p->m2d0++]=0xa0;
    }
}
#pragma opt_propagation on
extern "C" void fn_8039B3EC(u8* self, u8 kind, s32 flag) {
    MsgProc* p = (MsgProc*)self;
    switch(kind) {
    case 1:
        p->str2c0[p->m2d0++] = 0x14;
        p->str2c0[p->m2d0++] = 0x20;
        p->str2c0[p->m2d0++] = 0x2d;
        p->str2c0[p->m2d0++] = -0x20;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = 0x40;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x60;
        p->str2c0[p->m2d0++] = 0x34;
        p->str2c0[p->m2d0++] = -0x40;
        p->str2c0[p->m2d0++] = 0x35;
        p->str2c0[p->m2d0++] = 0x0;
        p->str2c0[p->m2d0++] = 0x14;
        p->str2c0[p->m2d0++] = 0x20;
        p->str2c0[p->m2d0++] = 0x30;
        p->str2c0[p->m2d0++] = 0x0;
        p->str2c0[p->m2d0++] = 0x35;
        p->str2c0[p->m2d0++] = 0x0;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = 0x0;
        if(flag != 1) {
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x40;
        }
        break;
    case 2:
        p->str2c0[p->m2d0++] = 0x14;
        p->str2c0[p->m2d0++] = 0x20;
        p->str2c0[p->m2d0++] = 0x2d;
        p->str2c0[p->m2d0++] = -0x80;
        p->str2c0[p->m2d0++] = 0x39;
        p->str2c0[p->m2d0++] = 0x0;
        p->str2c0[p->m2d0++] = 0x34;
        p->str2c0[p->m2d0++] = -0x40;
        p->str2c0[p->m2d0++] = 0x34;
        p->str2c0[p->m2d0++] = -0x40;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = 0x40;
        if(flag != 1) {
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x40;
        }
        break;
    case 3:
        p->str2c0[p->m2d0++] = 0x14;
        p->str2c0[p->m2d0++] = 0x20;
        p->str2c0[p->m2d0++] = 0x34;
        p->str2c0[p->m2d0++] = -0x60;
        p->str2c0[p->m2d0++] = 0x34;
        p->str2c0[p->m2d0++] = -0x80;
        p->str2c0[p->m2d0++] = 0x34;
        p->str2c0[p->m2d0++] = -0x20;
        p->str2c0[p->m2d0++] = 0x34;
        p->str2c0[p->m2d0++] = -0x20;
        if(flag == 1) {
        p->str2c0[p->m2d0++] = 0x39;
        p->str2c0[p->m2d0++] = -0x80;
        } else {
        p->str2c0[p->m2d0++] = 0x35;
        p->str2c0[p->m2d0++] = -0x80;
        p->str2c0[p->m2d0++] = 0x35;
        p->str2c0[p->m2d0++] = 0x0;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x40;
        }
        break;
    case 4:
        p->str2c0[p->m2d0++] = 0x14;
        p->str2c0[p->m2d0++] = 0x20;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x20;
        p->str2c0[p->m2d0++] = 0x35;
        p->str2c0[p->m2d0++] = -0x80;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = 0x0;
        p->str2c0[p->m2d0++] = 0x35;
        p->str2c0[p->m2d0++] = 0x0;
        if(flag != 1) {
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x40;
        }
        break;
    case 5:
        p->str2c0[p->m2d0++] = 0x14;
        p->str2c0[p->m2d0++] = 0x20;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x40;
        p->str2c0[p->m2d0++] = 0x39;
        p->str2c0[p->m2d0++] = -0x80;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x40;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x20;
        p->str2c0[p->m2d0++] = 0x35;
        p->str2c0[p->m2d0++] = 0x0;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = 0x0;
        if(flag != 1) {
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x40;
        }
        break;
    case 6:
        p->str2c0[p->m2d0++] = 0x14;
        p->str2c0[p->m2d0++] = 0x20;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x20;
        p->str2c0[p->m2d0++] = 0x35;
        p->str2c0[p->m2d0++] = 0x60;
        p->str2c0[p->m2d0++] = 0x35;
        p->str2c0[p->m2d0++] = -0x80;
        p->str2c0[p->m2d0++] = 0x35;
        p->str2c0[p->m2d0++] = 0x0;
        if(flag == 1) {
        p->str2c0[p->m2d0++] = 0x35;
        p->str2c0[p->m2d0++] = 0x20;
        } else {
        p->str2c0[p->m2d0++] = 0x39;
        p->str2c0[p->m2d0++] = 0x20;
        p->str2c0[p->m2d0++] = 0x35;
        p->str2c0[p->m2d0++] = 0x0;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x40;
        }
        break;
    case 7:
        p->str2c0[p->m2d0++] = 0x14;
        p->str2c0[p->m2d0++] = 0x20;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = 0x0;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = 0x40;
        p->str2c0[p->m2d0++] = 0x35;
        p->str2c0[p->m2d0++] = -0x20;
        p->str2c0[p->m2d0++] = 0x35;
        p->str2c0[p->m2d0++] = 0x0;
        if(flag != 1) {
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x40;
        }
        break;
    case 8:
        p->str2c0[p->m2d0++] = 0x14;
        p->str2c0[p->m2d0++] = 0x20;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x60;
        p->str2c0[p->m2d0++] = 0x35;
        p->str2c0[p->m2d0++] = 0x0;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x20;
        p->str2c0[p->m2d0++] = 0x39;
        p->str2c0[p->m2d0++] = 0x0;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x60;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = 0x20;
        if(flag != 1) {
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x40;
        }
        break;
    case 9:
        p->str2c0[p->m2d0++] = 0x14;
        p->str2c0[p->m2d0++] = 0x20;
        p->str2c0[p->m2d0++] = 0x2d;
        p->str2c0[p->m2d0++] = -0x20;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = 0x40;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x60;
        p->str2c0[p->m2d0++] = 0x34;
        p->str2c0[p->m2d0++] = -0x40;
        p->str2c0[p->m2d0++] = 0x35;
        p->str2c0[p->m2d0++] = 0x0;
        p->str2c0[p->m2d0++] = 0x14;
        p->str2c0[p->m2d0++] = 0x20;
        p->str2c0[p->m2d0++] = 0x2d;
        p->str2c0[p->m2d0++] = -0x20;
        p->str2c0[p->m2d0++] = 0x34;
        p->str2c0[p->m2d0++] = -0x80;
        p->str2c0[p->m2d0++] = 0x35;
        p->str2c0[p->m2d0++] = -0x80;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x60;
        if(flag == 1) {
        p->str2c0[p->m2d0++] = 0x39;
        p->str2c0[p->m2d0++] = -0x80;
        } else {
        p->str2c0[p->m2d0++] = 0x35;
        p->str2c0[p->m2d0++] = -0x80;
        p->str2c0[p->m2d0++] = 0x35;
        p->str2c0[p->m2d0++] = 0x0;
        p->str2c0[p->m2d0++] = 0x38;
        p->str2c0[p->m2d0++] = -0x40;
        }
        break;
    case 0:
    default: break;
    }
}

// ---- small helpers near the end of the TU (0x803A2BC4-0x803A3258) ----
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D7E5C(void* mgr, s32 a, s32 b);
extern "C" void fn_802D7EB0(void* mgr, s32 a, s32 b, s32 c);
extern "C" void fn_80138B7C(void* p);
extern "C" void fn_8043D874(void* p, s32 a, s32 b, s32 c);
extern void* lbl_8053AD78;
extern void* lbl_8053AAF8;
extern void* lbl_8053AED0;
extern u8 lbl_8050EC80[];
extern u8 lbl_80529DEC[];



extern void* lbl_8053AF80;
extern void* lbl_8053AD30;
extern u8 lbl_8050DB0C[];
extern "C" void fn_80458880(void* p, s32 a, s32 b);
extern "C" u32 fn_80309C4C(void* p, s32 a, s32 b);
extern "C" u32 fn_80309D6C(void* p, s32 a, s32 b);
extern "C" s32 fn_8030AAF4(s32 a);
extern "C" s32 fn_8037E7AC(s32 a);

extern "C" void fn_803A28A8(MsgCounter* self, int c) {
    if (self->m60[0x1aa] == 0) {
        s8 hi = (u16)c >> 8;
        if (c == 10) {
            self->m54++;
            if (self->m58 == 1) {
                self->m58 = 2;
            }
        }
        if (hi) {
            self->m50++;
        }
        self->m50++;
        if (self->m5d == 0) {
            if (!(*(u16*)(*(u8**)(self->m60 + 0x3b8) + 0x28) & 0x40)) {
                self->m4c = 1;
            } else {
                self->m4c = *(s16*)(lbl_8050DB0C + 0x4c);
            }
        }
        fn_80458880(lbl_8053AF80, 8, -1);
        if (self->m58 == 2 || self->m54 >= 3 || self->m50 >= 0xff) {
            self->m4c = 99999;
            self->m60[0x3ae] = 8;
        }
    } else {
        if (c == 10) {
            self->m54++;
            if (self->m58 == 1) {
                self->m58 = 2;
            }
        }
        self->m50 += 2;
        if (self->m58 == 2 || self->m54 >= 3 || self->m50 >= 0xff) {
            self->m4c = 99999;
            self->m60[0x3ae] = 3;
        }
    }
}

extern "C" int fn_803A2A2C(MsgCounter* self) {
    u8* q = self->m60;
    if (q[0x1aa] == 0) {
        if (self->m4c == 0) {
            return 1;
        }
        if (self->m4c == 99999) {
            if (q[0x19f] != 0) {
                self->m4c = 0;
                self->m54 = 0;
                self->m50 = 0;
                self->m58 = 0;
                self->m5d = 0;
                (*(s32*)(self->m60 + 0x15c))++;
                self->m60[0x19f] = 0;
            }
        } else {
            self->m4c--;
            if (self->m5c == 0) {
                q = self->m60;
                if (q[0x19e] != 0) {
                    if (*(u16*)(*(u8**)(q + 0x3b8) + 0x28) & 0x100) {
                        if (fn_80309C4C(lbl_8053AD30, 0x100, -1) != 0 || self->m60[0x1a0] != 0 ||
                            fn_8037E7AC(*(s32*)(self->m60 + 0x160)) != 0) {
                            self->m5d = 1;
                            self->m4c = 0;
                        }
                    } else {
                        if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(*(s32*)(q + 0x160)), 0x100) != 0 ||
                            self->m60[0x1a0] != 0 || fn_8037E7AC(*(s32*)(self->m60 + 0x160)) != 0) {
                            self->m5d = 1;
                            self->m4c = 0;
                        }
                    }
                }
            } else {
                self->m5c = 0;
            }
        }
    } else {
        if (self->m4c == 0) {
            return 1;
        }
        self->m4c--;
    }
    return 0;
}

extern "C" {
void fn_803A2BC4(void* thisPtr) {
    char* p = (char*)thisPtr;
    *(u8*)(*(char**)(p + 0x60) + 0x3af) = 0;
    char* q = *(char**)(p + 0x60);
    if (*(u8*)(q + 0x1aa) == 0) {
        *(u8*)(q + 0x3ae) = 8;
    } else {
        *(u8*)(q + 0x3ae) = 3;
    }
}

void fn_803A2BF8(void* thisPtr) { *(u8*)((char*)thisPtr + 0x5c) = 1; }

void fn_803A2C04(void* thisPtr) {
    char* p = (char*)thisPtr;
    *(s32*)(p + 0x4c) = 0;
    *(s32*)(p + 0x54) = 0;
    *(s32*)(p + 0x50) = 0;
    *(s32*)(p + 0x58) = 0;
    *(u8*)(p + 0x5d) = 0;
    char* q = *(char**)(p + 0x60);
    *(s32*)(q + 0x150) = 0;
    *(u8*)(q + 0x19e) = 0xff;
    *(s32*)(*(char**)(p + 0x60) + 0x15c) = 0;
    *(u8*)(*(char**)(p + 0x60) + 0x3af) = 1;
    q = *(char**)(p + 0x60);
    *(s32*)(q + 0x16c) = 0;
    *(u8*)(q + 0x1a0) = 0;
    *(u8*)(q + 0x1a1) = 0;
    *(s32*)(q + 0x168) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x148) = -1;
    *(u8*)(*(char**)(p + 0x60) + 0x1a9) = 0;
    *(s32*)(*(char**)(p + 0x60) + 0x174) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x13c) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x140) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x144) = -1;
    q = *(char**)(p + 0x60);
    if (*(u8*)(q + 0x1aa) == 0) {
        *(u8*)(q + 0x3ae) = 7;
    } else {
        *(u8*)(q + 0x3ae) = 2;
    }
}

void fn_803A2CB0(void* thisPtr, u8 kind, s32 mode) {
    s32* w = (s32*)((char*)thisPtr + 0x50);
    switch (kind) {
    case 1: if (mode == 1) *w += 10; else *w += 11; break;
    case 2: if (mode == 1) *w += 6; else *w += 7; break;
    case 3: if (mode == 1) *w += 6; else *w += 8; break;
    case 4: if (mode == 1) *w += 5; else *w += 6; break;
    case 5: if (mode == 1) *w += 7; else *w += 8; break;
    case 6: if (mode == 1) *w += 6; else *w += 8; break;
    case 7: if (mode == 1) *w += 5; else *w += 6; break;
    case 8: if (mode == 1) *w += 7; else *w += 8; break;
    case 9: if (mode == 1) *w += 12; else *w += 14; break;
    }
    *w += 1;
}

void fn_803A2E48(void* thisPtr, s32 n) {
    s32* w = (s32*)((char*)thisPtr + 0x50);
    u8 started = 0;
    if (n < 0) {
        *w += 1;
        n *= -1;
    }
    s32 r = n % 10000;
    if (n / 10000 != 0) {
        *w += 1;
        started = 1;
    }
    s32 d = r / 1000;
    r = r % 1000;
    if (d != 0 || started) {
        *w += 1;
        started = 1;
    }
    d = r / 100;
    r = r % 100;
    if (d != 0 || started) {
        *w += 1;
        started = 1;
    }
    d = r / 10;
    if (d != 0 || started) {
        *w += 1;
    }
    *w += 1;
}

void fn_803A2F74(void* thisPtr) {
    char* p = (char*)thisPtr;
    *(s32*)(p + 0x4c) = 0;
    *(s32*)(p + 0x54) = 0;
    *(s32*)(p + 0x50) = 0;
    *(s32*)(p + 0x58) = 0;
    *(u8*)(p + 0x5d) = 0;
    (*(s32*)(*(char**)(p + 0x60) + 0x15c))++;
    char* q = *(char**)(p + 0x60);
    *(s32*)(q + 0x150) = 0;
    *(u8*)(q + 0x19e) = 0xff;
    *(s32*)(*(char**)(p + 0x60) + 0x148) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x13c) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x140) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x144) = -1;
    *(u8*)(*(char**)(p + 0x60) + 0x3ae) = 2;
}

s32 fn_803A2FE0(void) { return *(s32*)((char*)lbl_8053AD78 + 0x10c); }
void fn_803A2FEC(void) { *(s32*)((char*)lbl_8053AD78 + 0x44) = 0; }
void fn_803A2FFC(void) { *(u8*)((char*)lbl_8053AD78 + 0xe9) = 0; }
u8 fn_803A300C(void) { return *(u8*)((char*)lbl_8053AD78 + 0xe9); }
u16 fn_803A3018(void) { return *(u16*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x36); }
u16 fn_803A3034(void) { return *(u16*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x34); }
s32 fn_803A3050(void* p) { return *(s32*)((char*)p + 0x17c); }
s32 fn_803A3058(void* p) { return *(s32*)((char*)p + 0x178); }
s16 fn_803A3060(void* p) { return *(s16*)((char*)p + 0x192); }
s16 fn_803A3068(void* p) { return *(s16*)((char*)p + 0x190); }
void fn_803A3070(void* p, s32 v) { *(s32*)((char*)p + 0x174) = v; }
void fn_803A3078(void* p) { *(u8*)((char*)p + 0x3b1) = 0; }
void fn_803A3084(void* p, s32 i, s32 v) { ((s32*)((char*)p + 0x180))[i] = v; }
s32 fn_803A3094(void* p) { return *(s32*)((char*)p + 0x14c); }
s32 fn_803A309C(void* p) { return *(s32*)((char*)p + 0x3bc); }
void fn_803A30A4(void* p, u8 a, s32 b) {
    *(s32*)((char*)p + 0x150) = b;
    *(u8*)((char*)p + 0x19e) = a;
}
void fn_803A30B0(void* p) { *(u8*)((char*)p + 0x1a9) = 1; }
s32 fn_803A30BC(void* p) { return *(s32*)((char*)p + 0x160); }
void fn_803A30C4(void* p) { *(u8*)((char*)p + 0x1a0) = 3; }
void fn_803A30D0(void* p) { *(u8*)((char*)p + 0x1a1) = 1; }
void fn_803A30DC(void* p, s32 v) { *(s32*)((char*)p + 0x148) = v; }
void fn_803A30E4(void* p) { *(u8*)((char*)p + 0x1a1) = 0; }
void fn_803A30F0(void* p) { *(u8*)((char*)p + 0x1a0) = 2; }
void fn_803A30FC(void* p, s32 i, s32 v) { ((s32*)((char*)p + 0x13c))[i] = v; }
s32 fn_803A310C(void* p) { return *(s32*)((char*)p + 0x16c); }
void fn_803A3114(void* p) {
    if (*(u8*)((char*)p + 0x1a0) == 0) {
        (*(s32*)((char*)p + 0x168))++;
    }
    (*(s32*)((char*)p + 0x16c))++;
}
u8 fn_803A313C(void* p) { return *(u8*)((char*)p + 0x1aa); }
void fn_803A3144(void) { fn_80138B7C(lbl_8053AAF8); }
u8 fn_803A3168(s32 a, s32 b) { return fn_802D7E5C(fn_802D6A9C(), a, b); }
void fn_803A31AC(s32 a, s32 b, s32 c) { fn_802D7EB0(fn_802D6A9C(), a, b, c); }
s32 fn_803A3200(void) { return *(s32*)(lbl_80529DEC + 0x11c); }
s32 fn_803A3210(void) { return *(s32*)(lbl_80529DEC + 0x118); }
s32 fn_803A3220(void* p) { return *(s32*)((char*)p + 0x280); }
void fn_803A3228(s32 a, s32 b, s32 c) { fn_8043D874(lbl_8053AED0, a, b, c); }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

// Keep regional definitions that were present before source-tree consolidation.
#if defined(VERSION_G4SJ01)
extern "C" void fn_802C2CD0(int param_1) {
    *(u8*)(*(u32*)(param_1 + 0x264)) = 0;
    *(u8*)(*(u32*)(param_1 + 0x268)) = 0;
}
#endif

