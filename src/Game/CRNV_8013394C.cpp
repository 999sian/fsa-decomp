#include "types.h"
#include "JSystem/JGeometry/Box.h"

extern "C" void fn_801EE434(void* obj);
extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
void operator delete(void* p);
extern "C" void* __vt__4CRNV[];
extern void* lbl_8049CC34[];
extern f32 lbl_8053CD30;
#pragma opt_strength_reduction on
extern "C" void* fn_8013394C(u8* this_, s16 freeFlag) {
    u8* self = this_;
    s16 flag = freeFlag;
    if (self != 0) {
        s32 i;
        u8* p = self;
        *(void**)self = __vt__4CRNV;
        for (i = 0; i < 2; ++i, p += 4) {
            fn_801EE434(*(void**)(p + 0x278));
            *(void**)(p + 0x278) = 0;
        }
        if (self + 0x240 != 0) {
            if (self + 0x264 != 0) {
                *(void**)(self + 0x264) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(self, 0);
        if (flag > 0) operator delete(self);
    }
    return self;
}
#pragma opt_strength_reduction on
extern "C" void fn_8013CB44(void* obj, void* p, s32 a, s32 b, s32 c);
extern "C" void fn_801339EC(u8* this_) {
    struct Col {
        u8 r, g, b, a;
        Col(u8 r_, u8 g_, u8 b_, u8 a_) {
            r = r_;
            g = g_;
            b = b_;
            a = a_;
        }
    };
    static Col tbl[6] = {
        Col(0x2d, 0x78, 0xff, 0xff),
        Col(0xc8, 0xa0, 0x28, 0xff),
        Col(0x4b, 0xff, 0x2d, 0xff),
        Col(0x1e, 0xa0, 0xbe, 0xff),
        Col(0xff, 0x41, 0x37, 0xff),
        Col(0xdc, 0x1e, 0xdc, 0xff),
    };
    s32 i = 0;
    u8* p = this_;
    do {
        if (*(void**)(p + 0x278) != NULL) {
            fn_8013CB44(*(void**)(p + 0x278), this_ + 0xc, 0, 0, 1);
            u8* obj = *(u8**)(p + 0x278);
            Col e = tbl[*(s32*)(this_ + 0x234)];
            obj[0xbc] = e.r;
            obj[0xbd] = e.g;
            obj[0xbe] = e.b;
        }
        i++;
        p += 4;
    } while (i < 2);
}

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7A08(void* pool, s32 type);
extern "C" void* fn_801F666C(void* reg, s32 id);
extern "C" s32 fn_801F78F4(void* pool, s32 type, s32 afterId);
extern "C" void fn_801EE434(void* p);
extern "C" void detach__5ActorFv(void* actor);
extern f32 lbl_8053CD34;
extern "C" s32 fn_80133B58(void) {
    s32 ret = 1;
    s32 i;
    void** slot;
    bool ok;
    s32 id;
    char* actor;

    id = fn_801F7A08(fn_801F856C(), 0x43524e56);
    while (id != -1) {
        actor = (char*)fn_801F666C(fn_801F856C(), id);
        if (actor == NULL) {
            break;
        }
        if (*(s32*)(actor + 0x230) == 1) {
            ok = false;
        } else {
            *(s32*)(actor + 0x230) = 2;
            switch (*(s32*)(actor + 0x230)) {
            case 0:
                *(s32*)(actor + 0x238) = -1;
                break;
            case 2:
                *(f32*)(actor + 0x23c) = lbl_8053CD34;
                break;
            case 3:
                slot = (void**)(actor + 0x278);
                for (i = 0; i < 2; i++) {
                    fn_801EE434(*slot);
                    *slot = NULL;
                    slot++;
                }
                detach__5ActorFv(actor);
                break;
            }
            ok = true;
        }
        if (!ok) {
            ret = 0;
        }
        id = fn_801F78F4(fn_801F856C(), 0x43524e56, id);
    }
    return ret;
}

extern "C" void v06__5ActorFv(void* this_);
extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, void* rec, s32 a, s32 b, s32 c, f32 s0, f32 s1);
extern const char lbl_804652D8[];
extern s32 lbl_804652C0[];
extern "C" void fn_80133C6C(u8* this_) {
    u8 buf[0x3c];
    v06__5ActorFv(this_);
    *(s32*)(buf + 0x10) = -1;
    *(s32*)(buf + 0x14) = -1;
    for (u8 i = 0; i < 0x10; i += 8) {
        buf[i] = i;
        buf[(u8)(i + 1)] = i + 1;
        buf[(u8)(i + 2)] = i + 2;
        buf[(u8)(i + 3)] = i + 3;
        buf[(u8)(i + 4)] = i + 4;
        buf[(u8)(i + 5)] = i + 5;
        buf[(u8)(i + 6)] = i + 6;
        buf[(u8)(i + 7)] = i + 7;
    }
    *(s32*)(buf + 0x10) = -1;
    *(s32*)(buf + 0x14) = 0;
    *(s32*)(buf + 0x18) = 0;
    buf[0x1c] = 0;
    buf[0x1d] = 0;
    buf[0x1e] = 0;
    buf[0x1f] = 1;
    buf[0x20] = 1;
    buf[0x21] = 0;
    buf[0x22] = 0;
    buf[0x23] = 0;
    buf[0x24] = 0;
    buf[0x25] = 0;
    buf[0x26] = 1;
    *(s32*)(buf + 0x28) = 3;
    buf[0x2c] = 1;
    buf[0x2d] = 0;
    buf[0x2e] = 0;
    *(s32*)(buf + 0x30) = -1;
    *(s32*)(buf + 0x34) = 0;
    *(s32*)(buf + 0x38) = 2;
    fn_801F02BC(this_, lbl_804652D8, lbl_804652C0[*(s32*)(this_ + 0x234)] + *(s32*)(this_ + 0x250), buf, 7, 0, 0, lbl_8053CD30, lbl_8053CD30);
}

extern "C" void v03__5ActorFv(void*);
extern "C" void fn_8022FEB8(void*,s32,s32,s32,s32);
extern "C" s32 fn_8022FD8C(s32);
extern "C" bool fn_802300EC(s32);
extern "C" bool fn_8038AD24(s32,s32,s32,s32,const JGeometry::TVec3f&,s32);
extern "C" void fn_8022FF8C(s32,void*,s32,s32,s32,s32);
extern "C" bool fn_80388CAC(s32,s32);
extern "C" void fn_801CD950(f32*,f32,f32);
extern "C" void fn_80239914(void*,s32,s32);
extern "C" void fn_801D1C18(void*);
extern s32 lbl_804652A4[];
extern f32 lbl_8053CD38, lbl_8053CD3C, lbl_8053CD40, lbl_8053CD44;
#pragma opt_propagation off
#pragma opt_propagation off
static inline void crnvClearEffects(u8* p) { u32 i=0; u8* q=p; do { fn_801EE434(*(void**)(q+0x278)); i++; *(u32*)(q+0x278)=0; q+=4; } while(i<2); }
static inline void crnvSetState(u8* p, s32 state) {
*(s32*)(p+0x230)=state;
switch (*(s32*)(p+0x230)) {
case 0: *(s32*)(p+0x238)=-1; break;
case 2: *(f32*)(p+0x23c)=lbl_8053CD34; break;
case 3: {
crnvClearEffects(p);
detach__5ActorFv(p); break;
}
}
}
static inline s32 crnvTryTalk(u8* p,u32 msg) {
s32 r;

JGeometry::TBox2f box2;
JGeometry::TVec3f pos;
box2.set(*(JGeometry::TBox2f*)(p+0x60));
box2.i.x += *(f32*)(p+0xc); box2.i.y += *(f32*)(p+0x10); box2.f.x += *(f32*)(p+0xc); box2.f.y += *(f32*)(p+0x10);
fn_8022FEB8(&box2,*(s32*)(p+4),*(s32*)(p+0x198),1,0);
r=fn_8022FD8C(*(s32*)(p+0x198));
if(r<0 || r>=4) return -1;
if(!fn_802300EC(r)) return -1;
{ s32 handle=*(s32*)(p+0x198); s32 area=*(s32*)(p+4); if(fn_8038AD24(r,msg,handle,area,(pos = *(JGeometry::TVec3f*)(p+0xc),pos),0x28)) return r; }
return -1;
}
#pragma opt_propagation reset

#pragma opt_propagation off
extern "C" void fn_80133DD0(u8* p) {
v03__5ActorFv(p);
JGeometry::TBox2f box;
box.set(*(JGeometry::TBox2f*)(p+0x60));
box.i.x += *(f32*)(p+0xc); box.i.y += *(f32*)(p+0x10); box.f.x += *(f32*)(p+0xc); box.f.y += *(f32*)(p+0x10);
switch(*(s32*)(p+0x230)) {
case 0:
fn_801339EC(p);
*(s32*)(p+0x238)=crnvTryTalk(p,lbl_804652A4[*(s32*)(p+0x234)]);
if(*(s32*)(p+0x238)>=0) crnvSetState(p,1);
break;
case 1:
fn_8022FF8C(*(s32*)(p+0x238),&box,*(s32*)(p+4),*(s32*)(p+0x198),1,0);
if(fn_80388CAC(*(s32*)(p+0x238),*(s32*)(p+0x198))) crnvSetState(p,0);
break;
case 2:
fn_801CD950((f32*)(p+0x23c),lbl_8053CD38,lbl_8053CD3C);
fn_801CD950((f32*)(p+0x14),lbl_8053CD40,*(f32*)(p+0x23c));
fn_801339EC(p);
if(*(f32*)(p+0x14)>=lbl_8053CD44) crnvSetState(p,3);
break;
case 3: default: break;
}
fn_80239914(&box,*(s32*)(p+4),*(s32*)(p+0x198));
fn_801D1C18(p+0x240);
}
#pragma opt_propagation reset

extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern "C" s32 fn_8013CC50(s32 id, void* p, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern u8 lbl_80539F50[8];
extern f32 lbl_8053CD30;
extern const f32 lbl_8053CD48;
extern const f32 lbl_8053CD4C;
extern "C" void fn_8013416C(u8* param_1)
{
    v01__5ActorFv(param_1);
    *(s32*)(param_1 + 0x234) = *(u32*)(param_1 + 0x90) & 0x1f;
    *(f32*)(param_1 + 0x60) = lbl_8053CD48;
    *(f32*)(param_1 + 0x64) = lbl_8053CD48;
    *(f32*)(param_1 + 0x68) = lbl_8053CD4C;
    *(f32*)(param_1 + 0x6c) = lbl_8053CD4C;
    *(f32*)(param_1 + 0x70) = *(f32*)(param_1 + 0x60);
    *(f32*)(param_1 + 0x74) = *(f32*)(param_1 + 0x64);
    *(f32*)(param_1 + 0x78) = *(f32*)(param_1 + 0x68);
    *(f32*)(param_1 + 0x7c) = *(f32*)(param_1 + 0x6c);
    *(f32*)(param_1 + 0x80) = *(f32*)(param_1 + 0x60);
    *(f32*)(param_1 + 0x84) = *(f32*)(param_1 + 0x64);
    *(f32*)(param_1 + 0x88) = *(f32*)(param_1 + 0x68);
    *(f32*)(param_1 + 0x8c) = *(f32*)(param_1 + 0x6c);
    fn_801D2608(param_1 + 0x240, lbl_80539F50, 1);
    fn_801D22DC(param_1 + 0x240, 0, 2, 0);
    fn_801D1F14(param_1 + 0x240, lbl_8053CD34);
    if (*(u32*)(param_1 + 0x278) == 0) {
        *(s32*)(param_1 + 0x278) = fn_8013CC50(*(s32*)(param_1 + 4), param_1 + 0xc, lbl_8053CD30, 0x32c, 0, 0, 0, 0, 1);
    }
    if (*(u32*)(param_1 + 0x27c) == 0) {
        *(s32*)(param_1 + 0x27c) = fn_8013CC50(*(s32*)(param_1 + 4), param_1 + 0xc, lbl_8053CD30, 0x183, 0, 0, 0, 0, 1);
    }
}

