#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"


extern "C" char lbl_804AC100[];
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" void* fn_801F856C(void);
extern u8* lbl_8053AAF8;
extern const f32 lbl_805420E8;
extern const f32 lbl_805420EC;
extern const f32 lbl_805420F0;
extern const f32 lbl_805420F4;
extern const f32 lbl_805420F8;

static f32 fn_80339820_rnd() {
    u32* seed = (u32*)(lbl_8053AAF8 + 0xb4);
    *seed = *seed * 0x19660d + 0x3c6ef35f;
    u32 bits = (*seed >> 9) | 0x3f800000;
    return *(f32*)&bits - lbl_805420EC;
}
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_803397C0(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AC100;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

#pragma opt_propagation on
#pragma opt_common_subs off
extern "C" void fn_80339820(u8* this_) {
    JGeometry::TVec3f pos(*(JGeometry::TVec3f*)(this_ + 0xc));
    bool skip = false;
    pos.y -= pos.z;
    pos.z = lbl_805420E8;
    switch (*(s32*)(this_ + 0x24c)) {
    case 1:
        switch (*(s32*)(this_ + 0x260)) {
        case 0x75:
            *(s32*)(this_ + 0x260) = 2;
            break;
        case 0x6b:
            *(s32*)(this_ + 0x260) = 4;
            break;
        default:
            *(s32*)(this_ + 0x260) = 1;
            break;
        }
        break;
    case 5:
        if (*(s32*)(this_ + 0x260) >= 0x45) {
            *(s32*)(this_ + 0x260) -= 0x45;
        } else {
            *(s32*)(this_ + 0x260) -= 0x40;
        }
        break;
    }
    if (*(s32*)(this_ + 0x260) <= 1) {
        if (fn_80339820_rnd() < lbl_805420F0) {
            if (fn_80339820_rnd() < lbl_805420F4) {
                Actor_CreateByID(fn_801F856C(), 0x52555059, *(u32*)(this_ + 4), (f32*)&pos, 0x261400, -1, -1);
            } else {
                if (fn_80339820_rnd() < lbl_805420F8) skip = true;
                if (skip) return;
                if (fn_80339820_rnd() < lbl_805420F0) {
                    Actor_CreateByID(fn_801F856C(), 0x46415259, *(u32*)(this_ + 4), (f32*)&pos, 0, -1, -1);
                } else {
                    Actor_CreateByID(fn_801F856C(), 0x48415254, *(u32*)(this_ + 4), (f32*)&pos, 0, -1, -1);
                }
            }
        }
    } else if (*(s32*)(this_ + 0x260) == 2) {
        Actor_CreateByID(fn_801F856C(), 0x48415254, *(u32*)(this_ + 4), (f32*)&pos, 0, -1, -1);
    } else if (*(s32*)(this_ + 0x260) == 3) {
    } else if (*(s32*)(this_ + 0x260) == 4) {
        Actor_CreateByID(fn_801F856C(), 0x46415259, *(u32*)(this_ + 4), (f32*)&pos, 0, -1, -1);
    }
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
#include "Game/ItemBase.h"
extern "C" char lbl_80471D60[];
extern "C" void* lbl_8053AB10;
extern const f32 lbl_805420FC;
extern const f32 lbl_80542100;
extern const f32 lbl_80542104;
extern const f32 lbl_80542108;
extern const f32 lbl_8054210C;
extern "C" void fn_802F6CF4(void* obj, JGeometry::TVec3f* pos, void* res, DrawRec* rec);
extern "C" void fn_801F06F0(u8* a, void* res, s32 id, void* rec, s32 p5, f32 sx, f32 sy);
static inline void setRotZ_80339AEC(Mtx m, s16 angle) {
    f32 c = JMACosShort(angle);
    f32 s = JMASinShort(angle);
    m[0][0] = c;
    m[0][1] = -s;
    m[1][0] = s;
    m[1][1] = c;
    m[2][2] = 1.0f;
    m[2][1] = 0.0f;
    m[1][2] = 0.0f;
    m[2][0] = 0.0f;
    m[0][2] = 0.0f;
}
static inline void rotZa_80339AEC(Mtx m, s16 angle) {
    f32 c = JMath::sincosTable_.mTable[(u16)angle >> 5].second;
    f32 s = JMath::sincosTable_.mTable[(u16)angle >> 5].first;
    m[0][0] = c;
    m[0][1] = -s;
    m[1][0] = s;
    m[1][1] = c;
    m[2][2] = 1.0f;
    m[2][1] = 0.0f;
    m[1][2] = 0.0f;
    m[2][0] = 0.0f;
    m[0][2] = 0.0f;
}
static inline void rotYa_80339AEC(Mtx m, s16 angle) {
    f32 c = JMath::sincosTable_.mTable[(u16)angle >> 5].second;
    f32 s = JMath::sincosTable_.mTable[(u16)angle >> 5].first;
    m[0][0] = c;
    m[1][1] = 1.0f;
    m[0][2] = s;
    m[2][0] = -s;
    m[2][2] = c;
    m[2][1] = 0.0f;
    m[1][2] = 0.0f;
    m[1][0] = 0.0f;
    m[0][1] = 0.0f;
}
static inline void rotZcs_80339AEC(Mtx m, f32 c, f32 s) {
    m[0][0] = c;
    m[0][1] = -s;
    m[1][0] = s;
    m[1][1] = c;
    m[2][2] = 1.0f;
    m[2][1] = 0.0f;
    m[1][2] = 0.0f;
    m[2][0] = 0.0f;
    m[0][2] = 0.0f;
}
static inline void rotYcs_80339AEC(Mtx m, f32 c, f32 s) {
    m[0][0] = c;
    m[1][1] = 1.0f;
    m[0][2] = s;
    m[2][0] = -s;
    m[2][2] = c;
    m[2][1] = 0.0f;
    m[1][2] = 0.0f;
    m[1][0] = 0.0f;
    m[0][1] = 0.0f;
}
static inline void rotZsc_80339AEC(Mtx m, f32 s, f32 c) {
    m[0][0] = c;
    m[0][1] = -s;
    m[1][0] = s;
    m[1][1] = c;
    m[2][2] = 1.0f;
    m[2][1] = 0.0f;
    m[1][2] = 0.0f;
    m[2][0] = 0.0f;
    m[0][2] = 0.0f;
}
static inline void rotYsc_80339AEC(Mtx m, f32 s, f32 c) {
    m[0][0] = c;
    m[1][1] = 1.0f;
    m[0][2] = s;
    m[2][0] = -s;
    m[2][2] = c;
    m[2][1] = 0.0f;
    m[1][2] = 0.0f;
    m[1][0] = 0.0f;
    m[0][1] = 0.0f;
}
static inline void setRotY_80339AEC(Mtx m, s16 angle) {
    f32 c = JMACosShort(angle);
    f32 s = JMASinShort(angle);
    m[0][0] = c;
    m[1][1] = 1.0f;
    m[0][2] = s;
    m[2][0] = -s;
    m[2][2] = c;
    m[2][1] = 0.0f;
    m[1][2] = 0.0f;
    m[1][0] = 0.0f;
    m[0][1] = 0.0f;
}
extern "C" void fn_801EFD34(u8* a, void* res, void* rec, s32 n, f32 x, f32 y, f32 z);
extern "C" void PSMTXIdentity(f32 m[3][4]);
extern "C" void fn_80339AEC(u8* self) {
    struct ResMgr {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void* getRes(u32 type, const char* name);
    };
    DrawRec rec;
    Mtx rot;
    Mtx trans;
    PSMTXIdentity(rot);
    PSMTXIdentity(trans);
    rec.b1c = 1;
    rec.b1d = 1;
    if (*(s32*)(self + 0x230) != 0 && *(s32*)(self + 0x230) != 4) {
        if (*(s32*)(self + 0x254) == 1) {
            *(u8*)&rec.w14 = 0x96;
        }
        switch (*(u32*)(self + 0x24c)) {
        case 0:
        case 8: {
            PSMTXTrans(trans, -8.0f, -8.0f, 0.0f);
            rotZcs_80339AEC(rot, JMACosShort(*(s16*)(self + 0x25a)), JMASinShort(*(s16*)(self + 0x25a)));
            PSMTXConcat(rot, trans, rot);
            rec.w18 = rot;
            JGeometry::TVec3f pos(*(f32*)(self + 0xc), *(f32*)(self + 0x10), *(f32*)(self + 0x14));
            if (*(s32*)(self + 4) < 8) {
                fn_802F6CF4(((void**)lbl_8053AB10)[8], &pos, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x534d5020, "floor1_smp.bin"), &rec);
            }
            rec.b1d = 0;
            *(u8*)&rec.w14 = 0;
            ((u8*)&rec.w10)[0] = 0x28;
            ((u8*)&rec.w10)[1] = 0x28;
            ((u8*)&rec.w10)[2] = 0x28;
            f32 a = 223.0f - 0.5f * *(f32*)(self + 0x14);
            ((u8*)&rec.w10)[3] = (s32)(159.0f >= a ? 159.0f : a);
            JGeometry::TVec3f pos2(*(f32*)(self + 0xc), *(f32*)(self + 0x10), 0.0f);
            if (*(s32*)(self + 4) < 8) {
                fn_802F6CF4(((void**)lbl_8053AB10)[8], &pos2, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x534d5020, "floor1_smp.bin"), &rec);
            }
            break;
        }
        case 1:
            rotYcs_80339AEC(rot, JMACosShort(*(s16*)(self + 0x25a)), JMASinShort(*(s16*)(self + 0x25a)));
            rec.w18 = rot;
            fn_801F06F0(self, (void*)"enemy_both2_sob.bin", 0x27, &rec, 7, 1.0f, 1.0f);
            break;
        case 2: {
            rotYcs_80339AEC(rot, JMACosShort(*(s16*)(self + 0x25a)), JMASinShort(*(s16*)(self + 0x25a)));
            rec.w18 = rot;
            s32 kind = **(s8**)(self + 0x288);
            if (kind == 'r' || kind == 's' || kind == 'y') {
                fn_801EFD34(self, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x54494d47, "wood_ura.bti"), &rec, 7, 0.0f, -16.0f, 0.0f);
            } else if (kind == 'l' || kind == 'x' || kind == 'p') {
                fn_801EFD34(self, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x54494d47, "wood_yasi.bti"), &rec, 7, 0.0f, -16.0f, 0.0f);
            } else {
                fn_801EFD34(self, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x54494d47, "wood_omote.bti"), &rec, 7, 0.0f, -16.0f, 0.0f);
            }
            break;
        }
        case 3: {
            PSMTXTrans(trans, -48.0f, -48.0f, 0.0f);
            rotZcs_80339AEC(rot, JMACosShort(*(s16*)(self + 0x25a)), JMASinShort(*(s16*)(self + 0x25a)));
            PSMTXConcat(rot, trans, rot);
            rec.w18 = rot;
            JGeometry::TVec3f pos(*(f32*)(self + 0xc), *(f32*)(self + 0x10), *(f32*)(self + 0x14));
            if (*(s32*)(self + 4) < 8) {
                fn_802F6CF4(((void**)lbl_8053AB10)[8], &pos, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x534d5020, "house_smp.bin"), &rec);
            }
            rec.b1d = 0;
            *(u8*)&rec.w14 = 0;
            ((u8*)&rec.w10)[0] = 0x28;
            ((u8*)&rec.w10)[1] = 0x28;
            ((u8*)&rec.w10)[2] = 0x28;
            f32 a = 223.0f - 0.5f * *(f32*)(self + 0x14);
            ((u8*)&rec.w10)[3] = (s32)(159.0f >= a ? 159.0f : a);
            JGeometry::TVec3f pos2(*(f32*)(self + 0xc), *(f32*)(self + 0x10), 0.0f);
            if (*(s32*)(self + 4) < 8) {
                fn_802F6CF4(((void**)lbl_8053AB10)[8], &pos2, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x534d5020, "house_smp.bin"), &rec);
            }
            break;
        }
        case 4:
            rotYcs_80339AEC(rot, JMACosShort(*(s16*)(self + 0x25a)), JMASinShort(*(s16*)(self + 0x25a)));
            rec.w18 = rot;
            fn_801F06F0(self, (void*)"enemy_gc_sob.bin", 0x16d, &rec, 7, 1.0f, 1.0f);
            break;
        case 5:
            rotYcs_80339AEC(rot, JMACosShort(*(s16*)(self + 0x25a)), JMASinShort(*(s16*)(self + 0x25a)));
            rec.w18 = rot;
            fn_801F06F0(self, (void*)"enemy_both2_sob.bin", 0x21, &rec, 7, 1.0f, 1.0f);
            break;
        case 6:
        case 9: {
            PSMTXTrans(trans, -16.0f, -16.0f, 0.0f);
            rotZcs_80339AEC(rot, JMACosShort(*(s16*)(self + 0x25a)), JMASinShort(*(s16*)(self + 0x25a)));
            PSMTXConcat(rot, trans, rot);
            rec.w18 = rot;
            JGeometry::TVec3f pos(*(f32*)(self + 0xc), *(f32*)(self + 0x10), *(f32*)(self + 0x14));
            if (*(s32*)(self + 4) < 8) {
                fn_802F6CF4(((void**)lbl_8053AB10)[8], &pos, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x534d5020, "statue_smp.bin"), &rec);
            }
            rec.b1d = 0;
            *(u8*)&rec.w14 = 0;
            ((u8*)&rec.w10)[0] = 0x28;
            ((u8*)&rec.w10)[1] = 0x28;
            ((u8*)&rec.w10)[2] = 0x28;
            f32 a = 223.0f - 0.5f * *(f32*)(self + 0x14);
            ((u8*)&rec.w10)[3] = (s32)(159.0f >= a ? 159.0f : a);
            JGeometry::TVec3f pos2(*(f32*)(self + 0xc), *(f32*)(self + 0x10), 0.0f);
            if (*(s32*)(self + 4) < 8) {
                fn_802F6CF4(((void**)lbl_8053AB10)[8], &pos2, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x534d5020, "statue_smp.bin"), &rec);
            }
            break;
        }
        case 7: {
            PSMTXTrans(trans, -8.0f, -8.0f, 0.0f);
            rotZcs_80339AEC(rot, JMACosShort(*(s16*)(self + 0x25a)), JMASinShort(*(s16*)(self + 0x25a)));
            PSMTXConcat(rot, trans, rot);
            rec.w18 = rot;
            if (*(u8*)(self + 0x258) != 0) {
                JGeometry::TVec3f pos(*(f32*)(self + 0xc), *(f32*)(self + 0x10), *(f32*)(self + 0x14));
                if (*(s32*)(self + 4) < 8) {
                    fn_802F6CF4(((void**)lbl_8053AB10)[8], &pos, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x534d5020, "empty_smp.bin"), &rec);
                }
            } else {
                JGeometry::TVec3f pos(*(f32*)(self + 0xc), *(f32*)(self + 0x10), *(f32*)(self + 0x14));
                if (*(s32*)(self + 4) < 8) {
                    fn_802F6CF4(((void**)lbl_8053AB10)[8], &pos, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x534d5020, "treasure_smp.bin"), &rec);
                }
            }
            rec.b1d = 0;
            *(u8*)&rec.w14 = 0;
            ((u8*)&rec.w10)[0] = 0x28;
            ((u8*)&rec.w10)[1] = 0x28;
            ((u8*)&rec.w10)[2] = 0x28;
            f32 a = 223.0f - 0.5f * *(f32*)(self + 0x14);
            ((u8*)&rec.w10)[3] = (s32)(159.0f >= a ? 159.0f : a);
            if (*(u8*)(self + 0x258) != 0) {
                JGeometry::TVec3f pos2(*(f32*)(self + 0xc), *(f32*)(self + 0x10), 0.0f);
                if (*(s32*)(self + 4) < 8) {
                    fn_802F6CF4(((void**)lbl_8053AB10)[8], &pos2, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x534d5020, "empty_smp.bin"), &rec);
                }
            } else {
                JGeometry::TVec3f pos2(*(f32*)(self + 0xc), *(f32*)(self + 0x10), 0.0f);
                if (*(s32*)(self + 4) < 8) {
                    fn_802F6CF4(((void**)lbl_8053AB10)[8], &pos2, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x534d5020, "treasure_smp.bin"), &rec);
                }
            }
            break;
        }
        }
    }
}

extern "C" void fn_801F71A4(void* v, f32 a, f32 b, f32 c);
extern "C" bool fn_801F2618(void* this_, s32 a, s32 b);
extern "C" const f32 lbl_80542110;
extern "C" void* lbl_8053AC98;
extern "C" u16 fn_8022461C(f32*,s32);
extern "C" u16 fn_80226850(f32*,s32);
extern "C" void fn_802A381C(void*,f32*,s32,s32);
extern "C" void fn_8029D8F0(void*,f32*,s32,s32,s32);
extern "C" s32 fn_801F2718(void*,u32);
extern "C" u8* fn_801F666C(void*,s32);
extern "C" void fn_801F0E34(void*,u32,s32);
extern "C" void fn_801EEC98(void*,s32,u16*,s32*,f32*,s32*,s32,s32);
extern "C" void* fn_8013CC50(s32,void*,s32,s32,s32,s32,s32,s32,f32);
extern "C" s32 fn_801F8544(void*,u32,s32,void*,s32);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void*,s32);
extern "C" void fn_8030C210(void*,void*);
extern "C" u8 fn_801F6758(void*,s32,f32);
extern "C" u8 fn_801F2B7C(void*,s32,s32,s32);
extern "C" s32 fn_801F285C(void*,s32,s32*,s32,s32);
extern "C" void* fn_8022F340(s32);
extern "C" s32 fn_802357E0(void*);
extern "C" void fn_802359A4(void*,s32);
extern "C" void fn_801F6718(void*,void*,s32,void*,s32,s32);
extern "C" s32 fn_8023E724(s32);
extern "C" s32 fn_8023B6CC(s32);
extern "C" void fn_801F37AC(void*,s32,s32,s32,s32,s32);
extern const f32 lbl_80542114;
extern const f32 lbl_80542118;
extern const f32 lbl_8054211C;
extern const f32 lbl_80542120;
extern const f32 lbl_80542124;
extern const f32 lbl_80542128;
extern const f32 lbl_8054212C;

static inline void floorPosSet(JGeometry::TVec3f* pos, const f32 x, const f32 y, const f32 z) {
    pos->set(x, y, z);
}
extern "C" void fn_8033A658(u8* this_) {
u16 angle=0;
s32 player;
s32 hit;
bool collided=false;
u8* self=this_;
fn_801F71A4(self+0x3c, *(f32*)(self + 0x27c), lbl_80542110, lbl_805420EC);
fn_801F71A4(self+0x40, *(f32*)(self + 0x280), lbl_80542110, lbl_805420EC);
*(JGeometry::TVec3f*)(self+0xc) += *(JGeometry::TVec3f*)(self+0x3c);
if (*(s32*)(self + 0x230)==2 && *(s32*)(self + 0x238)>=*(s32*)(self + 0x264)) collided=fn_801F2618(self,0,0);
switch(*(s32*)(self + 0x230)) {
case 0:
if(*(s32*)(self + 0x238)>=*(s32*)(self + 0x270)) {
*(s32*)(self + 0x230)=1;
switch(*(s32*)(self + 0x24c)) {
case 0: fn_802A381C(lbl_8053AC98, (f32*)(self+0xc), ((Actor*)self)->field_04, 0x276); break;
case 8: fn_802A381C(lbl_8053AC98, (f32*)(self+0xc), ((Actor*)self)->field_04, 0xd); break;
case 1: if(fn_8022461C((f32*)(self+0xc), ((Actor*)self)->field_04)!=0x21) {*(u8*)(self + 0x11c)=0;break;}
*(s32*)(self + 0x260)=fn_80226850((f32*)(self+0xc), ((Actor*)self)->field_04); fn_802A381C(lbl_8053AC98, (f32*)(self+0xc), ((Actor*)self)->field_04, 0x79); break;
case 2: {s32 room=((Actor*)self)->field_04;JGeometry::TVec3f pos;pos.set(*(f32*)(self+0xc)-lbl_80542114,*(f32*)(self+0x10),lbl_805420E8);fn_8029D8F0(lbl_8053AC98,(f32*)&pos,room,1,0);break;}
case 3: {
s32 y; s32 x;f32 dy;f32 dx; f32 zero=lbl_805420E8; f32 step=lbl_80542114; f32 off=lbl_80542118;
for(x=0;x<6;x++){dx=step*x;for(y=0;y<6;y++){dy=step*y;
s32 room=((Actor*)self)->field_04;JGeometry::TVec3f pos;pos.set(*(f32*)(self+0xc)-off+dx,*(f32*)(self+0x10)-off+dy,zero);fn_802A381C(lbl_8053AC98,(f32*)&pos,room,0x1b0);
s32 room2=((Actor*)self)->field_04+1;JGeometry::TVec3f pos2;pos2.set(*(f32*)(self+0xc)-off+dx,*(f32*)(self+0x10)-off+dy,zero);fn_802A381C(lbl_8053AC98,(f32*)&pos2,room2,0);
}}break;}
case 4: {
{s32 room=((Actor*)self)->field_04; JGeometry::TVec3f pos; pos.set(*(f32*)(self + 0xc)-lbl_8054211C,*(f32*)(self + 0x10)-lbl_8054211C,lbl_805420E8);fn_802A381C(lbl_8053AC98,(f32*)&pos,room,0x272);}
{s32 room=((Actor*)self)->field_04; JGeometry::TVec3f pos; pos.set(lbl_8054211C+*(f32*)(self + 0xc),*(f32*)(self + 0x10)-lbl_8054211C,lbl_805420E8);fn_802A381C(lbl_8053AC98,(f32*)&pos,room,0x27d);}
{s32 room=((Actor*)self)->field_04; JGeometry::TVec3f pos; pos.set(*(f32*)(self + 0xc)-lbl_8054211C,lbl_8054211C+*(f32*)(self + 0x10),lbl_805420E8);fn_802A381C(lbl_8053AC98,(f32*)&pos,room,0x275);}
{s32 room=((Actor*)self)->field_04; JGeometry::TVec3f pos; pos.set(lbl_8054211C+*(f32*)(self + 0xc),lbl_8054211C+*(f32*)(self + 0x10),lbl_805420E8);fn_802A381C(lbl_8053AC98,(f32*)&pos,room,0x27a);}
break;}
case 6: {
{s32 room=((Actor*)self)->field_04; JGeometry::TVec3f pos; pos.set(*(f32*)(self + 0xc)-lbl_8054211C,*(f32*)(self + 0x10)-lbl_8054211C,lbl_805420E8);fn_802A381C(lbl_8053AC98,(f32*)&pos,room,0x273);}
{s32 room=((Actor*)self)->field_04; JGeometry::TVec3f pos; pos.set(lbl_8054211C+*(f32*)(self + 0xc),*(f32*)(self + 0x10)-lbl_8054211C,lbl_805420E8);fn_802A381C(lbl_8053AC98,(f32*)&pos,room,0x27c);}
{s32 room=((Actor*)self)->field_04; JGeometry::TVec3f pos; pos.set(*(f32*)(self + 0xc)-lbl_8054211C,lbl_8054211C+*(f32*)(self + 0x10),lbl_805420E8);fn_802A381C(lbl_8053AC98,(f32*)&pos,room,0x274);}
{s32 room=((Actor*)self)->field_04; JGeometry::TVec3f pos; pos.set(lbl_8054211C+*(f32*)(self + 0xc),lbl_8054211C+*(f32*)(self + 0x10),lbl_805420E8);fn_802A381C(lbl_8053AC98,(f32*)&pos,room,0x27b);}
break;}
case 9: {
{s32 room=((Actor*)self)->field_04; JGeometry::TVec3f pos; pos.set(*(f32*)(self + 0xc)-lbl_8054211C,*(f32*)(self + 0x10)-lbl_8054211C,lbl_805420E8);fn_802A381C(lbl_8053AC98,(f32*)&pos,room,0x361);}
{s32 room=((Actor*)self)->field_04; JGeometry::TVec3f pos; pos.set(lbl_8054211C+*(f32*)(self + 0xc),*(f32*)(self + 0x10)-lbl_8054211C,lbl_805420E8);fn_802A381C(lbl_8053AC98,(f32*)&pos,room,0x361);}
{s32 room=((Actor*)self)->field_04; JGeometry::TVec3f pos; pos.set(*(f32*)(self + 0xc)-lbl_8054211C,lbl_8054211C+*(f32*)(self + 0x10),lbl_805420E8);fn_802A381C(lbl_8053AC98,(f32*)&pos,room,0x361);}
{s32 room=((Actor*)self)->field_04; JGeometry::TVec3f pos; pos.set(lbl_8054211C+*(f32*)(self + 0xc),lbl_8054211C+*(f32*)(self + 0x10),lbl_805420E8);fn_802A381C(lbl_8053AC98,(f32*)&pos,room,0x361);}
break;}
case 5: *(s32*)(self + 0x260)=fn_80226850((f32*)(self+0xc),((Actor*)self)->field_04); if(*(s32*)(self + 0x260)<0x40 || *(s32*)(self + 0x260)>0x49){*(u8*)(self + 0x11c)=0;break;} fn_802A381C(lbl_8053AC98, (f32*)(self+0xc), ((Actor*)self)->field_04, 0x11); break;
case 7: {s32 idx=fn_801F2718(self,0x544b5241);if(idx>=0){u8* obj=fn_801F666C(fn_801F856C(),idx);if(obj) *(u8*)(obj + 0x11c)=0;}
if(fn_80226850((f32*)(self+0xc),((Actor*)self)->field_04)==0x10) *(u8*)(self + 0x258)=1;
fn_802A381C(lbl_8053AC98, (f32*)(self+0xc), ((Actor*)self)->field_04, 0x9e); break;}
}
*(s32*)(self + 0x238)=0;*(f32*)(self + 0x44)=lbl_805420EC;
} else {
switch(*(s32*)(self + 0x24c)){
case 1: if(fn_8022461C((f32*)(self+0xc),((Actor*)self)->field_04)!=0x21){if (((Actor*)self)->v13() > 0) ((Actor*)self)->v10(255,1); *(u8*)(self + 0x11c)=0; return;}break;
case 5: *(s32*)(self + 0x260)=fn_80226850((f32*)(self+0xc),((Actor*)self)->field_04);
if(*(s32*)(self + 0x260)<0x40||*(s32*)(self + 0x260)>0x49){if (((Actor*)self)->v13() > 0) ((Actor*)self)->v10(255,1); *(u8*)(self + 0x11c)=0; return;}break;
}
*(s32*)(self + 0x248)=*(s32*)(self + 0x244);
if(!*(u8*)(self + 0x278)) {
int best=0xfff;
s32 count=*(s32*)((u8*)fn_801F856C()+0x1008);
for(s32 i=0;i<count;i++) {
u8* obj=*((u8**)fn_801F856C()+i+2);
if(obj && *(u32*)(obj+0x1a0)==0x464c594f && obj) {
int value; if(*(s32*)(obj+0x230)==0||*(s32*)(obj+0x230)==4) value=*(s32*)(obj+0x248); else value=0xfff; if(value<=best) {if(*(s32*)(obj+0x230)==0||*(s32*)(obj+0x230)==4) value=*(s32*)(obj+0x248); else value=0xfff; best=value;}
}}
if(best==*(s32*)(self + 0x244)) {
*(s32*)(self + 0x244)=*(s32*)(self + 0x26c)+*(s32*)(self + 0x274);
*(s32*)(self + 0x270)=*(s32*)(self + 0x244)*60+60;
*(u8*)(self + 0x278)=1;
}
*(s32*)(self + 0x26c)=best;
}
}break;
case 1:
if(*(s32*)(self + 0x238)>=90){
fn_801F0E34(self, 0x30040, 0);
*(s32*)(self + 0x230)=2;*(s16*)(self + 0x25a)+=*(s16*)(self + 0x25c);*(s32*)(self + 0x238)=0;
fn_801EEC98(self, *(s32*)(self + 0x198), &angle, 0, 0, &player, 0, 0);
if(JMACosShort(angle)>lbl_805420E8) *(s32*)(self + 0x264)+=10;
}else if(*(s32*)(self + 0x238)>=30){
*(s16*)(self + 0x25a)+=*(s16*)(self + 0x25c);*(f32*)(self + 0x44)=lbl_805420E8;
}else{
*(s16*)(self + 0x25a)+=*(s16*)(self + 0x25c)**(s32*)(self + 0x238)/30;
*(f32*)(self + 0x84)-=*(f32*)(self + 0x44);*(f32*)(self + 0x8c)-=*(f32*)(self + 0x44);
}break;
case 2:
*(s16*)(self + 0x25a)+=*(s16*)(self + 0x25c);
switch(*(s32*)(self + 0x24c)){
case 0:case 1:case 4:case 5:case 6:case 7:case 8:case 9:
if(*(s32*)(self + 0x238)<=2){*(f32*)(self + 0x10) -= *(f32*)(self + 0x14); fn_801EEC98(self, *(s32*)(self + 0x198), &angle, 0, 0, &player, 0, 0); *(f32*)(self + 0x10) += *(f32*)(self + 0x14); *(f32*)(self + 0x27c)=lbl_80542120*JMASinShort(angle); *(f32*)(self + 0x280)=lbl_80542120*JMACosShort(angle);}break;
case 2:case 3:
if(*(s32*)(self + 0x238)%20==1 && *(s32*)(self + 0x238)<=61){*(f32*)(self + 0x10) -= *(f32*)(self + 0x14); fn_801EEC98(self, *(s32*)(self + 0x198), &angle, 0, 0, &player, 0, 0); *(f32*)(self + 0x10) += *(f32*)(self + 0x14); *(f32*)(self + 0x27c)=lbl_80542124*JMASinShort(angle); *(f32*)(self + 0x280)=lbl_80542124*JMACosShort(angle);}break;
}break;
case 3: if (((Actor*)self)->v13() > 0) ((Actor*)self)->v10(255,1);
switch(*(s32*)(self + 0x24c)){
case 0:case 8:fn_8013CC50(((Actor*)self)->field_04, self+0xc, 0x7e, 1, 0, 0, 0, 1, lbl_805420EC);fn_8013CC50(((Actor*)self)->field_04, self+0xc, 0x7f, 1, 0, 0, 0, 1, lbl_805420EC);fn_801F0E34(self, 0x30018, 0);break;
case 1:fn_8013CC50(((Actor*)self)->field_04, self+0xc, 0x357, 0, 0, 0, 0, 1, lbl_80542128);fn_801F0E34(self, 0x30002, 0);fn_80339820(self);break;
case 2:fn_8013CC50(((Actor*)self)->field_04, self+0xc, 0xad, 1, 0, 0, 0, 1, lbl_805420EC);fn_8013CC50(((Actor*)self)->field_04, self+0xc, 0xaf, 1, 0, 0, 0, 1, lbl_805420EC);fn_8013CC50(((Actor*)self)->field_04, self+0xc, 0xb0, 1, 0, 0, 0, 1, lbl_805420EC);fn_801F0E34(self, 0x30003, 0);break;
case 3:fn_8013CC50(((Actor*)self)->field_04, self+0xc, 0x82, 1, 0, 0, 0, 1, lbl_805420EC);fn_8013CC50(((Actor*)self)->field_04, self+0xc, 0x83, 1, 0, 0, 0, 1, lbl_805420EC);fn_8013CC50(((Actor*)self)->field_04, self+0xc, 0x84, 1, 0, 0, 0, 1, lbl_805420EC);
if(**(s8**)(self+0x288)=='r'||**(s8**)(self+0x288)=='s'){fn_8013CC50(((Actor*)self)->field_04, self+0xc, 0x80, 1, 0, 0, 0, 1, lbl_805420EC);}else{fn_8013CC50(((Actor*)self)->field_04, self+0xc, 0x81, 1, 0, 0, 0, 1, lbl_805420EC);}fn_801F0E34(self, 0x30003, 0);break;
case 4:fn_8013CC50(((Actor*)self)->field_04, self+0xc, 0xa7, 1, 0, 0, 0, 1, lbl_805420EC);fn_8013CC50(((Actor*)self)->field_04, self+0xc, 0xa8, 1, 0, 0, 0, 1, lbl_805420EC);fn_801F0E34(self, 0x30003, 0);break;
case 5:fn_8013CC50(((Actor*)self)->field_04, self+0xc, 0xab, 1, 0, 0, 0, 1, lbl_805420EC);fn_8013CC50(((Actor*)self)->field_04, self+0xc, 0xac, 1, 0, 0, 0, 1, lbl_805420EC);fn_801F0E34(self, 0x3000b, 0);fn_80339820(self);break;
case 6:case 9:fn_8013CC50(((Actor*)self)->field_04, self+0xc, 0x99, 1, 0, 0, 0, 1, lbl_805420EC);fn_8013CC50(((Actor*)self)->field_04, self+0xc, 0x9a, 1, 0, 0, 0, 1, lbl_805420EC);fn_801F0E34(self, 0x30003, 0);break;
case 7:fn_8013CC50(((Actor*)self)->field_04, self+0xc, 0x78, 1, 0, 0, 0, 1, lbl_805420EC);fn_8013CC50(((Actor*)self)->field_04, self+0xc, 0x79, 1, 0, 0, 0, 1, lbl_805420EC);fn_801F0E34(self, 0x30018, 0);break;
}
if(*(s32*)(self + 0x254)==1){s32 idx=fn_801F8544(fn_801F856C(),0x52555059,((Actor*)self)->field_04,self+0xc,4);if(idx>=0){
u8* obj=fn_801F666C(fn_801F856C(),idx);
if(obj){JGeometry::TVec3f vel(lbl_805420E8,lbl_805420E8,lbl_8054212C);*(JGeometry::TVec3f*)(obj+0x3c)=vel;}
}}
*(u8*)(self + 0x11c)=0;break;
case 4:if(fn_802D800C(fn_802D6A9C(),*(s32*)(self + 0x250))){*(s32*)(self + 0x230)=0;*(s32*)(self + 0x238)=0;}break;
}
if(*(s32*)(self + 0x230)!=0 && *(s32*)(self + 0x230)!=4){
f32 xpos=*(f32*)(self + 0xc); f32 ypos=*(f32*)(self + 0x10)-*(f32*)(self + 0x14); JGeometry::TVec3f pos; pos.set(xpos,ypos,lbl_805420E8);
fn_8030C210(((void**)lbl_8053AB10)[9],&pos);
*(s32*)(self + 0x240)+=*(s16*)(self + 0x25c);
if(*(s32*)(self + 0x240)>=0x8000){
*(s32*)(self + 0x240)-=0x8000;(*(s32*)(self + 0x23c))--;
if(*(s32*)(self + 0x23c)<=0){*(s32*)(self + 0x23c)=1;fn_801F0E34(self, 0x3003f, 0);}
}}
if(*(s32*)(self + 0x230)==1 || *(s32*)(self + 0x230)==2){
if(fn_801F6758(self+0xc,((Actor*)self)->field_04,lbl_80542114)){*(u8*)(self + 0x11c)=0;}
else if(collided || fn_801F2B7C(self,*(s32*)(self + 0x114),-1,*(s32*)(self + 0x268))){*(s32*)(self + 0x230)=3;}
else {
for(s32 i=0;i<4;i++){
if(i==fn_801F285C(self,0,&hit,1,-1)){
if(hit==1){
s32 value=fn_802357E0(fn_8022F340(i));
fn_802359A4(fn_8022F340(i),value);
s32 n=fn_802357E0(fn_8022F340(i));
s32 room=((Actor*)self)->field_04;
void* obj=fn_8022F340(i);
fn_801F6718(fn_801F856C(),obj,room,self+0xc,n,0);
}
s32 value=fn_8023E724(i);s32 other=fn_8023B6CC(i);
fn_801F37AC(self,other,value,0,hit,i);
*(s32*)(self + 0x230)=3;break;
}}
}}
if(*(s32*)(self + 0x230)!=4) (*(s32*)(self + 0x238))++;
}

extern "C" void* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(u8* p, s32 a, f32* b, s32 c, s32 d);
extern "C" u16 fn_8022461C(f32* a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" BOOL fn_8033B7FC(Actor* self, s32 a, f32* b) {
    s32 region = self->field_198;
    u8* base = static_cast<u8*>(fn_8020D58C());
    if (fn_8020D6AC(base + base[1] * 0x784 + 4, a, b, region, 0) == 1) {
        return 1;
    }
    u16 code = fn_8022461C(b, a);
    if (code == 0 || code == 2 || code == 0x50) {
        return 0;
    }
    if (code == 0x22 && static_cast<u8*>(fn_802D6A9C())[0x170] == 0) {
        return 0;
    }
    if (code == 0x39) {
        return 0;
    }
    if (code == 0x25 && static_cast<u8*>(fn_802D6A9C())[0x171] == 0) {
        return 0;
    }
    if (code == 4) {
        if (((s32)b[1] & 0xf) >= 8) {
            return 0;
        }
    } else if (code == 5) {
        if (((s32)b[1] & 0xf) < 8) {
            return 0;
        }
    } else if (code == 6) {
        if (((s32)b[0] & 0xf) >= 8) {
            return 0;
        }
    } else if (code == 7) {
        if (((s32)b[0] & 0xf) < 8) {
            return 0;
        }
    } else if (code == 3 || code == 0xe || code == 0xd) {
        return 0;
    }
    return 1;
}

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F78F4(void* mgr, u32 code, s32 idx);
extern "C" u8* fn_801F666C(void* mgr, s32 idx);
extern "C" void fn_8033B9D8(u8* self) {
    s32 idx = -1;
    s32 best = 0;
    u8* obj;
    s32 v;

    for (;;) {
        idx = fn_801F78F4(fn_801F856C(), 0x464c594f, idx);
        if (idx < 0) {
            break;
        }
        obj = fn_801F666C(fn_801F856C(), idx);
        if (obj == 0) {
            continue;
        }
        if (*(s32*)(obj + 0x230) == 0 || *(s32*)(obj + 0x230) == 4) {
            v = *(s32*)(obj + 0x248);
        } else {
            v = 0xfff;
        }
        if (v < *(s32*)(self + 0x26c)) {
            *(s32*)(self + 0x26c) = v;
        }
        if (best < v && v < *(s32*)(self + 0x244)) {
            best = v;
        }
    }
    if (*(s32*)(self + 0x26c) == *(s32*)(self + 0x244)) {
        *(u8*)(self + 0x278) = 1;
    }
    if (best != 0) {
        *(s32*)(self + 0x274) = *(s32*)(self + 0x244) - best;
    }
}

extern "C" void* fn_802D9C4C(void* mgr = 0);
extern const f32 lbl_8054211C, lbl_80542114, lbl_80542138, lbl_8054213C, lbl_80542140, lbl_80542144, lbl_80542148, lbl_8054214C, lbl_80542150, lbl_80542154, lbl_80542158, lbl_8054215C;
extern "C" void fn_8033BAC8(u8* self) {
    *(u32*)(self + 0x244) = *(u32*)(self + 0x90) & 0x7ff;
    *(u32*)(self + 0x250) = (*(u32*)(self + 0x90) >> 11) & 0x1f;
    *(u32*)(self + 0x24c) = (*(u32*)(self + 0x90) >> 16) & 0xf;
    *(u32*)(self + 0x254) = (*(u32*)(self + 0x90) >> 20) & 0xf;
    *(u32*)(self + 0x264) = ((*(u32*)(self + 0x90) >> 24) & 7) * 5 + 0xf;
    *(u32*)(self + 0x108) = 0;
    *(f32*)(self + 0x284) = lbl_805420E8;
    *(f32*)(self + 0x280) = lbl_805420E8;
    *(f32*)(self + 0x27c) = lbl_805420E8;
    *(f32*)(self + 0x44) = lbl_805420E8;
    *(f32*)(self + 0x40) = lbl_805420E8;
    *(f32*)(self + 0x3c) = lbl_805420E8;
    *(u16*)(self + 0x234) = 0;
    *(u32*)(self + 0x260) = 0;
    *(u32*)(self + 0x288) = 0;
    *(u32*)(self + 0x238) = 0;
    *(u32*)(self + 0x23c) = 5;
    *(u16*)(self + 0x25a) = 0;
    *(u32*)(self + 0x240) = 0x8000;
    *(u8*)(self + 0x258) = 0;
    *(u32*)(self + 0x114) = 1;
    *(u32*)(self + 0x268) = 1;
    *(u32*)(self + 0x270) = *(u32*)(self + 0x244) * 0x3c + 0x3c;
    *(u32*)(self + 0x248) = *(u32*)(self + 0x244);
    *(u8*)(self + 0x278) = 0;
    *(u32*)(self + 0x26c) = 0xfff;
    *(u32*)(self + 0x274) = 0;
    if (*(s32*)(self + 0x250) == 0) {
        *(u32*)(self + 0x230) = 0;
    } else {
        *(u32*)(self + 0x230) = 4;
    }
    switch (*(u32*)(self + 0x24c)) {
    case 0:
    case 5:
        *(JGeometry::TVec3f*)(self+0xc) += JGeometry::TVec3f(lbl_8054211C,lbl_8054211C,lbl_805420E8);
        *(f32*)(self + 0x80) = lbl_80542138;
        *(f32*)(self + 0x84) = lbl_80542138;
        *(f32*)(self + 0x88) = lbl_8054213C;
        *(f32*)(self + 0x8c) = lbl_8054213C;
        *(f32*)(self + 0x60) = lbl_80542138;
        *(f32*)(self + 0x64) = lbl_80542138;
        *(f32*)(self + 0x68) = lbl_8054213C;
        *(f32*)(self + 0x6c) = lbl_8054213C;
        *(u16*)(self + 0x25c) = 0x1000;
        *(u32*)(self + 0x114) = 2;
        break;
    case 1:
        *(f32*)(self + 0x80) = lbl_80542140;
        *(f32*)(self + 0x84) = lbl_80542140;
        *(f32*)(self + 0x88) = lbl_80542144;
        *(f32*)(self + 0x8c) = lbl_80542144;
        *(f32*)(self + 0x60) = lbl_80542140;
        *(f32*)(self + 0x64) = lbl_80542140;
        *(f32*)(self + 0x68) = lbl_80542144;
        *(f32*)(self + 0x6c) = lbl_80542144;
        *(u16*)(self + 0x25c) = 0x1000;
        *(u32*)(self + 0x114) = 2;
        break;
    case 2:
        *(JGeometry::TVec3f*)(self+0xc) += JGeometry::TVec3f(0.0f,lbl_80542114,0.0f);
        *(f32*)(self + 0x80) = lbl_80542148;
        *(f32*)(self + 0x84) = lbl_80542148;
        *(f32*)(self + 0x88) = lbl_8054214C;
        *(f32*)(self + 0x8c) = lbl_8054214C;
        *(f32*)(self + 0x60) = lbl_80542148;
        *(f32*)(self + 0x64) = lbl_80542148;
        *(f32*)(self + 0x68) = lbl_8054214C;
        *(f32*)(self + 0x6c) = lbl_8054214C;
        *(u16*)(self + 0x25c) = 0x800;
        *(void**)(self+0x288)=fn_802D9C4C(fn_802D6A9C());
        *(u32*)(self + 0x114) = 2;
        break;
    case 3:
        *(f32*)(self + 0x80) = lbl_80542150;
        *(f32*)(self + 0x84) = lbl_80542150;
        *(f32*)(self + 0x88) = lbl_80542154;
        *(f32*)(self + 0x8c) = lbl_80542154;
        *(f32*)(self + 0x60) = lbl_80542150;
        *(f32*)(self + 0x64) = lbl_80542150;
        *(f32*)(self + 0x68) = lbl_80542154;
        *(f32*)(self + 0x6c) = lbl_80542154;
        *(u16*)(self + 0x25c) = 0x400;
        *(void**)(self+0x288)=fn_802D9C4C(fn_802D6A9C());
        *(u32*)(self + 0x114) = 4;
        *(u32*)(self + 0x268) = 2;
        break;
    case 4:
        *(f32*)(self + 0x80) = lbl_80542140;
        *(f32*)(self + 0x84) = lbl_80542140;
        *(f32*)(self + 0x88) = lbl_80542144;
        *(f32*)(self + 0x8c) = lbl_80542144;
        *(f32*)(self + 0x60) = lbl_80542140;
        *(f32*)(self + 0x64) = lbl_80542140;
        *(f32*)(self + 0x68) = lbl_80542144;
        *(f32*)(self + 0x6c) = lbl_80542144;
        *(u16*)(self + 0x25c) = 0x800;
        *(u32*)(self + 0x114) = 4;
        break;
    case 6:
        *(f32*)(self + 0x80) = lbl_80542140;
        *(f32*)(self + 0x84) = lbl_80542140;
        *(f32*)(self + 0x88) = lbl_80542144;
        *(f32*)(self + 0x8c) = lbl_80542144;
        *(f32*)(self + 0x60) = lbl_80542158;
        *(f32*)(self + 0x64) = lbl_80542158;
        *(f32*)(self + 0x68) = lbl_8054215C;
        *(f32*)(self + 0x6c) = lbl_8054215C;
        *(u16*)(self + 0x25c) = 0x800;
        *(u32*)(self + 0x114) = 4;
        break;
    case 7:
    case 8:
    case 9:
        *(JGeometry::TVec3f*)(self+0xc) += JGeometry::TVec3f(lbl_8054211C,lbl_8054211C,lbl_805420E8);
        *(f32*)(self + 0x80) = lbl_80542140;
        *(f32*)(self + 0x84) = lbl_80542140;
        *(f32*)(self + 0x88) = lbl_80542144;
        *(f32*)(self + 0x8c) = lbl_80542144;
        *(f32*)(self + 0x60) = lbl_80542140;
        *(f32*)(self + 0x64) = lbl_80542140;
        *(f32*)(self + 0x68) = lbl_80542144;
        *(f32*)(self + 0x6c) = lbl_80542144;
        *(u16*)(self + 0x25c) = 0x800;
        *(u32*)(self + 0x114) = 2;
        break;
    }
}

extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void fn_8033BE5C(void) {
    static u32 c0[3], c1[3], c2[3], c3[3], c4[3], c5[3], c6[3], c7[3], c8[3];
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, c0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, c1);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, c2);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, c3);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, c4);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, c5);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, c6);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, c7);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, c8);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

