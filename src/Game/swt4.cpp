// TU 0x802a964c-0x802aa364 (actor SWT4).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#undef GAME_ACTOR_USE_SDK_VEC

class Swt4 : public Actor {
public:
    s32 state, mode, frame, timer, delay;
    s32 switchId[4];
};

// ---- fn_802A964C_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A80A0[];

extern "C" void* fn_802A964C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A80A0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Swt4_Draw.cpp ----
// Swt4_Draw(this) - SWT4's real draw(). A pure no-op (`blr`), matching
// the SAME pattern DOOR's draw uses ([[project_fsa_door_key0_full_depth]])
// - SWT4 renders nothing itself, relying on static level geometry or
// effects triggered from elsewhere rather than an actor-drawn model.
extern "C" {

void Swt4_Draw(void) {}

extern "C" void* fn_802D6A9C();
extern "C" u8 fn_802D800C(void*, u32);
extern "C" s32 fn_802D7E1C(void*, u32);
extern "C" void fn_802D8050(void*, u32, s32, s32);
extern "C" void fn_8022E2D8(s32);
extern "C" void fn_801F0D20(void*, s32);
extern "C" u8 fn_8023077C();
extern "C" void* fn_8023E724(s32);
extern "C" void fn_80230498(s32, void*, s32, s32, s32, s32, s32);
extern "C" void fn_8030C210(void*, void*);
extern "C" void fn_80230FD0(s32, s32);
extern "C" void fn_80230E1C(s32, s32);
extern "C" u8 fn_80230534(s32);
struct Swt4ActorList {
    u32 field_00[2];
    Actor* actors[1024];
    s32 count;
};
extern "C" u8* fn_801F856C();
extern u8* lbl_8053AAF8;
extern u8* lbl_8053AB10;
#define SWT4_S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define SWT4_U32(p, o) (*(u32*)((u8*)(p) + (o)))
#define SWT4_PTR(p, o) (*(u8**)((u8*)(p) + (o)))
static inline void swt4Set(void* p, s32 value) {
    ((void (*)(void*, s32, s32))(*(void***)p)[12])(p, 0xff, value);
}
extern "C" void fn_802A96B0(Swt4* p) {
    int n = 0;
    int valid;
    s32 i;
    s32 j;
    s32 slots[4];
    switch (p->state) {
    case 0: {
        valid = 1;
        for (i = 0; i < 4; i++) {
            slots[i] = 0xff;
            if (fn_802D800C(fn_802D6A9C(), p->switchId[i])) {
                slots[i] = fn_802D7E1C(fn_802D6A9C(), p->switchId[i]);
                n++;
                if (slots[i] == 0xff) { slots[i] = i+4; valid = -1; }
            }
        }
        if (n != 4) break;
        s32 conflict = 0;
        if (lbl_8053AAF8[0x7e] == 1) {
            for (i=0;i<3;i++) {
                if (slots[i] != 0xff) {
                    for (j=i+1;j<4;j++) {
                        if (slots[j]!=0xff && p->switchId[i]!=p->switchId[j] && slots[i]==slots[j]) conflict=1;
                    }
                } else conflict=1;
            }
        } else {
            for (i=0;i<3;i++) {
                if (slots[i] != 0xff) {
                    for (j=i+1;j<4;j++) {
                        if (slots[j]!=0xff && p->switchId[i]!=p->switchId[j] && slots[i]==slots[j]) conflict=1;
                    }
                } else conflict=1;
            }
        }
        if(conflict) break;
        if(p->mode==3) {
            fn_8022E2D8(15); p->v10(0xff,1); p->state=1; break;
        }
        if(lbl_8053AAF8[0x7f]==0 || valid==-1) {
            fn_8022E2D8(15); p->v10(0xff,1);
            for(i=0;i<4;i++) fn_802D8050(fn_802D6A9C(),p->switchId[i],1,0xff);
            if(p->mode!=0) {
                if(p->mode==2) fn_801F0D20(p,3);
                p->field_11C=0;
            } else p->state=1;
            break;
        }
        if(fn_8023077C()) {
            for(i=0;i<4;i++) {
                JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)fn_8023E724(i));
                pos.x = ((s32)pos.x / 16)*16+8;
                pos.y = ((s32)pos.y / 16)*16+8;
                fn_80230498(i,&pos,0xe8,0xff,-128,-128,1);
            }
            p->state=3; p->frame=0; p->timer=30;
        } else p->state=2;
        break;
    }
    case 1: case 6: default:
        if(!fn_802D800C(fn_802D6A9C(),(p->field_90>>22)&31)) {p->v10(0xff,0);p->state=0;break;}
        if(!fn_802D800C(fn_802D6A9C(),(p->field_90>>17)&31)) {p->v10(0xff,0);p->state=0;break;}
        if(!fn_802D800C(fn_802D6A9C(),(p->field_90>>12)&31)) {p->v10(0xff,0);p->state=0;break;}
        if(!fn_802D800C(fn_802D6A9C(),(p->field_90>>7)&31)) {p->v10(0xff,0);p->state=0;}
        break;
    case 2:
        if(fn_8023077C()) {
            s32 count = ((Swt4ActorList*)fn_801F856C())->count;
            for(i=0;i<4;i++) {
                for(j=0;j<count;j++) {
                    u8* actor = (u8*)((Swt4ActorList*)fn_801F856C())->actors[j];
                    if(actor && SWT4_U32(actor,0x1a0)==0x53575448 && p->switchId[i]==(SWT4_U32(actor,0x90)>>27)) {
                        JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)fn_8023E724(i));
                        pos.x=((s32)pos.x/16)*16+8;
                        pos.y=((s32)pos.y/16)*16+8;
                        fn_80230498(i,&pos,0xe8,0xff,-128,-128,1);
                        fn_8030C210(SWT4_PTR(lbl_8053AB10,0x24),&pos);
                    }
                }
            }
            fn_8022E2D8(15);
            p->state=3; p->frame=0; p->timer=30;
        }
        break;
    case 3:
        for(i=0;i<4;i++) {
            JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)fn_8023E724(i));
            fn_8030C210(SWT4_PTR(lbl_8053AB10,0x24),&pos);
        }
        p->timer--;
        if(p->timer==0) {
            p->frame++;
            for(i=0;i<4;i++) {
                JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)fn_8023E724(i));
                fn_80230498(i,&pos,p->frame+0xdb,0xff,-128,-128,1);
                if(p->frame==1) fn_80230FD0(i,0x10001);
            }
            p->timer=2;
            if(p->frame==13) {
                p->state=4; p->timer=10;
                if(p->mode==4) {
                    if((u32)(lbl_8053AAF8[0x83]&3)==1) {
                        p->timer=120; p->delay=60;
                        for(s32 k=0;k<4;k++) if((u32)((lbl_8053AAF8[0x82]&(u8)(1<<k))!=0)==1) fn_80230E1C(k,0);
                    } else { p->timer=80; p->delay=40; }
                }
            }
        }
        break;
    case 4:
        if(p->mode==4) {
            SWT4_PTR(lbl_8053AB10,0x20)[0x216]=1;
            if(p->timer==p->delay) p->v10(0xff,1);
        } else {
            for(i=0;i<4;i++) {
                JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)fn_8023E724(i));
                fn_8030C210(SWT4_PTR(lbl_8053AB10,0x24),&pos);
            }
        }
        if(p->timer==0) {
            p->v10(0xff,1);
            for(i=0;i<4;i++) fn_802D8050(fn_802D6A9C(),p->switchId[i],1,0xff);
            p->state=5; p->timer=15;
            if(p->mode==2) fn_801F0D20(p,3);
        } else p->timer--;
        break;
    case 5:
        for(i=0;i<4;i++) {
            JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)fn_8023E724(i));
            fn_8030C210(SWT4_PTR(lbl_8053AB10,0x24),&pos);
        }
        if(p->timer==0) {
            if(fn_80230534(0)) {
                if(p->mode!=0) p->field_11C=0;
                else p->state=1;
            }
        } else p->timer--;
        break;
    case 7:
        for(i=0;i<4;i++) {
            slots[i]=0xff;
            if(fn_802D800C(fn_802D6A9C(),p->switchId[i])) {
                slots[i]=fn_802D7E1C(fn_802D6A9C(),p->switchId[i]); n++;
                if(slots[i]==0xff) slots[i]=i+4;
            }
        }
        if(n==4) {p->v10(0xff,1);p->state=1;}
        else if(n!=0) p->field_11C=0;
        break;
    }
}

}

// ---- fn_802AA0B8 ----
extern const u32 lbl_8046C850[4];

extern "C" void fn_802AA0B8(u8* this_) {
    *(u32*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0x1F;
    if (*(s32*)(this_ + 0x234) != 5) {
        *(u32*)(this_ + 0x230) = 0;
    } else {
        *(u32*)(this_ + 0x230) = 7;
    }
    const u32* sh = lbl_8046C850;
    *(u32*)(this_ + 0x244) = (*(u32*)(this_ + 0x90) >> sh[0]) & 0x1F;
    *(u32*)(this_ + 0x248) = (*(u32*)(this_ + 0x90) >> sh[1]) & 0x1F;
    *(u32*)(this_ + 0x24C) = (*(u32*)(this_ + 0x90) >> sh[2]) & 0x1F;
    *(u32*)(this_ + 0x250) = (*(u32*)(this_ + 0x90) >> sh[3]) & 0x1F;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
