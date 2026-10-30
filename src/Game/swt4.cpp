// TU 0x802a964c-0x802aa364 (actor SWT4).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

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
extern "C" u8* fn_801F856C();
extern u8* lbl_8053AAF8;
extern u8* lbl_8053AB10;
#define SWT4_S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define SWT4_U32(p, o) (*(u32*)((u8*)(p) + (o)))
#define SWT4_PTR(p, o) (*(u8**)((u8*)(p) + (o)))
static inline void swt4Set(void* p, s32 value) {
    ((void (*)(void*, s32, s32))(*(void***)p)[12])(p, 0xff, value);
}
extern "C" void fn_802A96B0(u8* this_) {
    s32 slots[4];
    s32 n = 0;
    u8* p = this_;
    switch (SWT4_S32(p, 0x230)) {
    case 0: {
        s32 valid = 1;
        for (s32 i = 0; i < 4; i++) {
            slots[i] = 0xff;
            if (fn_802D800C(fn_802D6A9C(), SWT4_U32(p,0x244+i*4))) {
                slots[i] = fn_802D7E1C(fn_802D6A9C(), SWT4_U32(p,0x244+i*4));
                n++;
                if (slots[i] == 0xff) { slots[i] = i+4; valid = -1; }
            }
        }
        if (n != 4) break;
        s32 conflict = 0;
        if (lbl_8053AAF8[0x7e] == 1) {
            for (s32 i=0;i<3;i++) {
                if (slots[i] != 0xff) {
                    for (s32 j=i+1;j<4;j++) {
                        if (slots[j]!=0xff && SWT4_U32(p,0x244+i*4)!=SWT4_U32(p,0x244+j*4) && slots[i]==slots[j]) conflict=1;
                    }
                } else conflict=1;
            }
        } else {
            for (s32 i=0;i<3;i++) {
                if (slots[i] != 0xff) {
                    for (s32 j=i+1;j<4;j++) {
                        if (slots[j]!=0xff && SWT4_U32(p,0x244+i*4)!=SWT4_U32(p,0x244+j*4) && slots[i]==slots[j]) conflict=1;
                    }
                } else conflict=1;
            }
        }
        if(conflict) break;
        if(SWT4_S32(p,0x234)==3) {
            fn_8022E2D8(15); swt4Set(p,1); SWT4_S32(p,0x230)=1; break;
        }
        if(lbl_8053AAF8[0x7f]==0 || valid==-1) {
            fn_8022E2D8(15); swt4Set(p,1);
            for(s32 i=0;i<4;i++) fn_802D8050(fn_802D6A9C(),SWT4_U32(p,0x244+i*4),1,0xff);
            if(SWT4_S32(p,0x234)!=0) {
                if(SWT4_S32(p,0x234)==2) fn_801F0D20(p,3);
                p[0x11c]=0;
            } else SWT4_S32(p,0x230)=1;
            break;
        }
        if(fn_8023077C()) {
            for(s32 i=0;i<4;i++) {
                JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)fn_8023E724(i));
                pos.x = ((s32)pos.x / 16)*16+8;
                pos.y = ((s32)pos.y / 16)*16+8;
                fn_80230498(i,&pos,0xe8,0xff,-128,-128,1);
            }
            SWT4_S32(p,0x230)=3; SWT4_S32(p,0x238)=0; SWT4_S32(p,0x23c)=30;
        } else SWT4_S32(p,0x230)=2;
        break;
    }
    case 1: case 6: default:
        if(!fn_802D800C(fn_802D6A9C(),(SWT4_U32(p,0x90)>>22)&31)) {swt4Set(p,0);SWT4_S32(p,0x230)=0;break;}
        if(!fn_802D800C(fn_802D6A9C(),(SWT4_U32(p,0x90)>>17)&31)) {swt4Set(p,0);SWT4_S32(p,0x230)=0;break;}
        if(!fn_802D800C(fn_802D6A9C(),(SWT4_U32(p,0x90)>>12)&31)) {swt4Set(p,0);SWT4_S32(p,0x230)=0;break;}
        if(!fn_802D800C(fn_802D6A9C(),(SWT4_U32(p,0x90)>>7)&31)) {swt4Set(p,0);SWT4_S32(p,0x230)=0;}
        break;
    case 2:
        if(fn_8023077C()) {
            s32 count = SWT4_S32(fn_801F856C(),0x1008);
            for(s32 i=0;i<4;i++) {
                for(s32 j=0;j<count;j++) {
                    u8* actor = SWT4_PTR(fn_801F856C(),8+j*4);
                    if(actor && SWT4_U32(actor,0x1a0)==0x53575448 && SWT4_U32(p,0x244+i*4)==(SWT4_U32(actor,0x90)>>27)) {
                        JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)fn_8023E724(i));
                        pos.x=((s32)pos.x/16)*16+8;
                        pos.y=((s32)pos.y/16)*16+8;
                        fn_80230498(i,&pos,0xe8,0xff,-128,-128,1);
                        fn_8030C210(SWT4_PTR(lbl_8053AB10,0x24),&pos);
                    }
                }
            }
            fn_8022E2D8(15);
            SWT4_S32(p,0x230)=3; SWT4_S32(p,0x238)=0; SWT4_S32(p,0x23c)=30;
        }
        break;
    case 3:
        for(s32 i=0;i<4;i++) {
            JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)fn_8023E724(i));
            fn_8030C210(SWT4_PTR(lbl_8053AB10,0x24),&pos);
        }
        SWT4_S32(p,0x23c)--;
        if(SWT4_S32(p,0x23c)==0) {
            SWT4_S32(p,0x238)++;
            for(s32 i=0;i<4;i++) {
                JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)fn_8023E724(i));
                fn_80230498(i,&pos,SWT4_S32(p,0x238)+0xdb,0xff,-128,-128,1);
                if(SWT4_S32(p,0x238)==1) fn_80230FD0(i,0x10001);
            }
            SWT4_S32(p,0x23c)=2;
            if(SWT4_S32(p,0x238)==13) {
                SWT4_S32(p,0x230)=4; SWT4_S32(p,0x23c)=10;
                if(SWT4_S32(p,0x234)==4) {
                    if((lbl_8053AAF8[0x83]&3)==1) {
                        SWT4_S32(p,0x23c)=120; SWT4_S32(p,0x240)=60;
                        for(s32 i=0;i<4;i++) if(((lbl_8053AAF8[0x82]&(u8)(1<<i))!=0)==1) fn_80230E1C(i,0);
                    } else { SWT4_S32(p,0x23c)=80; SWT4_S32(p,0x240)=40; }
                }
            }
        }
        break;
    case 4:
        if(SWT4_S32(p,0x234)==4) {
            SWT4_PTR(lbl_8053AB10,0x20)[0x216]=1;
            if(SWT4_S32(p,0x23c)==SWT4_S32(p,0x240)) swt4Set(p,1);
        } else {
            for(s32 i=0;i<4;i++) {
                JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)fn_8023E724(i));
                fn_8030C210(SWT4_PTR(lbl_8053AB10,0x24),&pos);
            }
        }
        if(SWT4_S32(p,0x23c)==0) {
            swt4Set(p,1);
            for(s32 i=0;i<4;i++) fn_802D8050(fn_802D6A9C(),SWT4_U32(p,0x244+i*4),1,0xff);
            SWT4_S32(p,0x230)=5; SWT4_S32(p,0x23c)=15;
            if(SWT4_S32(p,0x234)==2) fn_801F0D20(p,3);
        } else SWT4_S32(p,0x23c)--;
        break;
    case 5:
        for(s32 i=0;i<4;i++) {
            JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)fn_8023E724(i));
            fn_8030C210(SWT4_PTR(lbl_8053AB10,0x24),&pos);
        }
        if(SWT4_S32(p,0x23c)==0) {
            if(fn_80230534(0)) {
                if(SWT4_S32(p,0x234)!=0) p[0x11c]=0;
                else SWT4_S32(p,0x230)=1;
            }
        } else SWT4_S32(p,0x23c)--;
        break;
    case 7:
        for(s32 i=0;i<4;i++) {
            slots[i]=0xff;
            if(fn_802D800C(fn_802D6A9C(),SWT4_U32(p,0x244+i*4))) {
                slots[i]=fn_802D7E1C(fn_802D6A9C(),SWT4_U32(p,0x244+i*4)); n++;
                if(slots[i]==0xff) slots[i]=i+4;
            }
        }
        if(n==4) {swt4Set(p,1);SWT4_S32(p,0x230)=1;}
        else if(n!=0) p[0x11c]=0;
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
