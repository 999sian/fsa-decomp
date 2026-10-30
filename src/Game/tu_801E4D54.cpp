#include "types.h"
#include "sdk/stl/float.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void fn_801E4D54(u8* this_) {
    *(u32*)(this_ + 0x230) &= ~0x4000;
    this_[0x5ce] = 0;
    *(f32*)(this_ + 0x4bc) = 0.0f;
}

extern "C" void fn_801E4D74(u8* this_) {
    this_[0x5ce] = 0x32;
    *(f32*)(this_ + 0x4bc) = 255.0f;
}

extern "C" u8* fn_801F856C();
extern "C" s32 fn_801F7818(u8* this_, u32 fourcc, s32 room, u8** list, s32 max);
extern "C" s32 fn_801F666C(u8* a, s32 id);
extern "C" void fn_801D7874(u8* p);
extern "C" void fn_801D7830(u8* p);
extern "C" void fn_801EB00C(u8*, f32*, f32*);
extern "C" void fn_801E5BA8(u8*, u8*, f32*, u8);
extern "C" f32 lbl_8053F578;
extern "C" f32 lbl_8053F580;

static inline u8 hasBombSlot(u8* self, u8* actor, int flag) {
    u8* slot;
    u8 found = 0;
    int i;
    if (*(u32*)(actor + 0x1a0) == 0x48424d42) {
        i = found;
        slot = self;
        for (; i < 16; slot += 0x14, i++) {
            if (*(s32*)(slot + 0x308) == *(s32*)(actor + 0x198) && slot[flag]) {
                found = 1;
                break;
            }
        }
    }
    return found;
}

#pragma opt_lifetimes off
extern "C" void fn_801E4D88(u8* this_) {
    int cleanupIndex;
    u8* e;
    u8** actors;
    s32 i;
    u8* p;
    int id;
    s32 count;
    u8* list[0x400];
    JGeometry::TVec3<f32> pv;
    JGeometry::TVec3<f32> sum;
    JGeometry::TVec3<f32> out;
    JGeometry::TVec3<f32> zero;
    JGeometry::TVec3<f32> zero2;
    JGeometry::TVec3<f32> movePos;
    count = fn_801F7818(fn_801F856C(), 0x48424D42, *(s32*)(this_ + 4), list, -1);
    for (cleanupIndex = 0, p = this_; cleanupIndex < 16; cleanupIndex++, p += 0x14) {
        if (p[0x30c] == 0) continue;
        id = *(s32*)(p+0x308);
        if (id < 0) {
            u8* slot=p+0x308;
            fn_801D7874(slot); slot[4]=0; continue;
        }
        u8* e = (u8*)fn_801F666C(fn_801F856C(), id);
        if (e == 0) {
            u8* slot=p+0x308;
            fn_801D7874(slot); slot[4]=0; continue;
        }
        if (!e[0x11c] || *(s32*)(e+4)!=*(s32*)(this_+4) || *(u16*)(e+0x94)==1 || *(u32*)(e+0x90)) {
            u8* slot=p+0x308;
            fn_801D7874(slot); slot[4]=0; continue;
        }
        {
            s32 j;
            u8** cursor=list;
            for(j=0;j<count;cursor++,j++) {
                if (*(s32*)(e+0x198)==*(s32*)(*cursor+0x198)) break;
            }
            if(j<count) continue;
        }
        u8* slot=p+0x308;
        fn_801D7874(slot);
        slot[4]=0;
    }
    actors=list;
    for (i=0;i<count;actors++,i++) {
        e=*actors;
        if (e==0 || !e[0x11c] || *(u16*)(e+0x94)==1 || *(u32*)(e+0x90)!=0) continue;
        if(hasBombSlot(this_,e,0x30c) && hasBombSlot(this_,e,0x30d)) {
            zero.setAll(0.0f);
            *(JGeometry::TVec3<f32>*)(e+0x3c)=zero;
            s32 j;
            u8* scan=this_;
            for(j=0;j<16;scan+=0x14,j++) {
                if(*(s32*)(scan+0x308)==*(s32*)(e+0x198) && scan[0x30c] && scan[0x30d]) {
                    u8* slot=this_+j*0x14+0x308;
                    fn_801D7830(slot);
                    movePos=*(JGeometry::TVec3<f32>*)(e+0xc);
                    movePos.add(*(JGeometry::TVec3<f32>*)(slot+8));
                    if(movePos.z<0.0f) {
                        ((JGeometry::TVec3<f32>*)(slot+8))->x=0.0f;
                        ((JGeometry::TVec3<f32>*)(slot+8))->y=0.0f;
                        movePos.z=0.0f;
                        ((JGeometry::TVec3<f32>*)(slot+8))->z=0.0f;
                    }
                    *(JGeometry::TVec3<f32>*)(e+0xc)=movePos;
                    break;
                }
            }
            continue;
        }
        f32 dy=*(f32*)(this_+0x10)-*(f32*)(this_+0x1c);
        f32 dx=*(f32*)(this_+0xc)-*(f32*)(this_+0x18);
        pv.x=*(f32*)(e+0xc); pv.y=*(f32*)(e+0x10); pv.z=*(f32*)(e+0x14);
        if(hasBombSlot(this_,e,0x30c) && !hasBombSlot(this_,e,0x30d)) {
            pv.x+=dx; pv.y+=dy;
        }
        f32 x=pv.x-*(f32*)(this_+0xc);
        f32 y=pv.y-*(f32*)(this_+0x10);
        f32 range=*(f32*)(this_+0x47c);
        x=x*x;
        f32 rangeSquared=range*range;
        y=y*y;
        if(x+y <= rangeSquared) {
            fn_801EB00C(this_+0x464,&pv.x,&out.x);
            u32 flags=*(u32*)(this_+0x230)&0x4000;
            if(!flags && hasBombSlot(this_,e,0x30c) && !hasBombSlot(this_,e,0x30d)) {
                fn_801E5BA8(this_,e,&out.x,0);
            } else if(flags) {
                u8 isZero = out.isZero() != 0;
                if(isZero) continue;
                if(out.z>0.0f) {
                    zero2.setAll(0.0f);
                    *(JGeometry::TVec3<f32>*)(e+0x3c)=zero2;
                    if(!hasBombSlot(this_,e,0x30c)) {
                        s32 j;
                        u8* scan=this_;
                        for(j=0;j<16;scan+=0x14,j++) {
                            if(!scan[0x30c]) {
                                u8* slot=this_+j*0x14+0x308;
                                *(s32*)slot=*(s32*)(e+0x198);
                                slot[4]=1;
                                break;
                            }
                        }
                    }
                }
                sum.x=pv.x;sum.y=pv.y;sum.z=pv.z;
                sum.add(out);
                if(sum.z>*(f32*)(this_+0x478)) fn_801E5BA8(this_,e,&out.x,1);
                *(JGeometry::TVec3<f32>*)(e+0xc)=sum;
            }
        }
    }
}
#pragma opt_lifetimes reset
extern "C" f32 lbl_8053F578;
extern "C" s32 fn_8023F264(s32 i);
extern "C" s32 fn_80236B50(s32 i);
extern "C" s32 fn_8022D75C(s32 i);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" void fn_801D789C(u8* p);
extern "C" s32 fn_80230188(s32 i);
extern "C" void fn_80230224(s32 i, s32 b);
extern "C" s32 fn_801D08B4(u8* this_, s32 i, u8* pos, f32 range);
extern "C" f32* fn_8023E724(s32 i);
extern "C" void fn_80236074(s32 i, s32 a, s32 b);
extern "C" void fn_801EB00C(u8* a, f32* b, f32* c);
extern "C" s32 fn_802300EC(s32 i);
extern "C" s32 fn_80236BEC(s32 i);
extern "C" void fn_80230C6C(s32 i);
extern "C" void fn_80230AD4(s32 i);
extern "C" s32 fn_80230CFC(s32 i);
extern "C" void fn_8021BD18(u8* p, s32 v);
extern "C" void fn_8021BCBC(u8* p);
extern "C" void fn_80230498(s32 i, f32* v, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_8022CB94(s32 i);
extern "C" s32 fn_80238548(s32 i, s32 b, f32* p, s32 d);
extern "C" void fn_8023DFF4(s32 i, f32* v);
extern "C" void fn_8022CD48(s32 i);
extern "C" void fn_801E5754(u8* this_) {
    s32 j;
    s32 i;
    u8* p;
    u8* q;
    s32 room;
    JGeometry::TVec3<f32> pv;
    JGeometry::TVec3<f32> sum;
    JGeometry::TVec3<f32> out;
    f32 xy[2];
    f32 dx, dy;
    u8 first, second;
    s32 result;
    for (i = 0, q = this_; i < 4; i++, q += 0x18) {
        if (q[0x2a8] != 0) {
            if (!(u8)fn_8023F264(i) || (u8)fn_80236B50(i) || (u8)fn_8022D75C(i)) goto clear_slot;
            room = *(s32*)(this_ + 4);
            s32 playerRoom = fn_8023DE58(i);
            if (playerRoom != room) {
clear_slot:
                p = q + 0x2a8;
                fn_801D789C(p);
                p[0] = 0;
                if ((u8)fn_80230188(i)) fn_80230224(i, 0);
            }
        }
    }
    for (j = 0, p = this_; j < 4; j++, p += 0x18) {
        if (*(s32*)(p + 0x2ac) > 0) {
            if (*(s32*)(p + 0x2ac) > 0) --*(volatile s32*)(p + 0x2ac);
            continue;
        }
        if (!p[0x2a8] && !(u8)fn_801D08B4(this_, j, this_ + 0xc, *(f32*)(this_ + 0x47c))) continue;
        dy = *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x1c);
        dx = *(f32*)(this_ + 0xc) - *(f32*)(this_ + 0x18);
        f32* v = fn_8023E724(j);
        pv.x = v[0]; pv.y = v[1]; pv.z = v[2];
        if (p[0x2a8]) {
            pv.x += dx; pv.y += dy;
            if (*(u32*)(this_ + 0x230) & 0x4000) {
                ++*(volatile s32*)(p + 0x2b0);
                if (*(s32*)(p + 0x2b0) % 40 == 0) fn_80236074(j, 10, 0);
            }
        }
        fn_801EB00C(this_ + 0x464, &pv.x, &out.x);
        if (out.z > lbl_8053F578) {
            if ((*(u32*)(this_ + 0x230) & 0x4000) && !(u8)fn_80230188(j) &&
                (u8)fn_802300EC(j) && !(u8)fn_80236BEC(j)) {
                fn_80230C6C(j); fn_80230AD4(j); p[0x2a8] = 1;
                fn_8021BD18(p + 0x2b4, fn_80230CFC(j));
            }
            if (!(u8)fn_80230188(j)) {
                if ((*(u32*)(this_ + 0x230) & 0x4000) && !(u8)fn_80236BEC(j)) {
                    out.x += dx; out.y += dy;
                    fn_8023DFF4(j, &out.x); fn_8022CD48(j);
                }
            } else {
                sum.x = pv.x; sum.y = pv.y; sum.z = pv.z;
                sum.add(out);
                fn_8021BCBC(p + 0x2b4);
                fn_80230498(j, &sum.x, *(s32*)(p + 0x2b4), 255, -128, -128, 0);
                fn_8022CB94(j);
                first = 0; second = 0; result = 0;
                xy[0] = pv.x; xy[1] = pv.y;
                xy[0] -= out.x; xy[1] -= out.y;
                if (!(*(u32*)(this_ + 0x230) & 0x4000)) {
                    first = 1;
                    result = fn_80238548(j, 0, xy, 25);
                } else if (sum.z > *(f32*)(this_ + 0x478)) {
                    second = 1;
                    result = fn_80238548(j, *(s32*)(this_ + 0x114), xy, 23);
                }
                if (first || second) {
                    fn_80230224(j, 0);
                    fn_801D789C(p + 0x2a8);
                    p[0x2a8] = 0;
                    if ((u8)result) *(s32*)(p + 0x2ac) = 120;
                    else *(s32*)(p + 0x2ac) = 30;
                }
            }
        } else if ((*(u32*)(this_ + 0x230) & 0x4000) && !(fn_8023E724(j)[2] >= *(f32*)(this_ + 0x478)) &&
                   !(u8)fn_80236BEC(j)) {
            fn_8023DFF4(j, &out.x); fn_8022CD48(j);
        }
    }
}

extern "C" f32 lbl_8053F578;
extern "C" f32 lbl_8053F580;
extern "C" f32 lbl_8053F584;
extern "C" f32 lbl_8053F588;
extern "C" f32 lbl_8053F58C;
extern "C" f32 lbl_8053F590;
extern "C" f32 lbl_8053F594;
extern "C" f32 lbl_8053F598;
extern "C" s32 fn_801D05F8(u8* this_, u8* pos, f32 range);
extern "C" u32 fn_801D0280(u8* this_);
extern "C" f32 sincosTable___5JMath[];
extern "C" void fn_801E5BA8(u8* this_, u8* actor, f32* dir, u8 flag) {
    u8* p = this_;
    s32 id = *(s32*)(actor + 0x198);
    for (int i = 0; i < 16; i++, p += 0x14) {
        if (*(u8*)(p + 0x30c) == 0 || *(s32*)(p + 0x308) != id) {
            continue;
        }
        if (flag == 0) {
            JGeometry::TVec2<f32> v;
            v.set(dir[0], dir[1]);
            v.normalize();
            v.scale(lbl_8053F58C);
            ((JGeometry::TVec3<f32>*)(this_ + i * 0x14 + 0x310))->set(v.x, v.y, lbl_8053F590);
            *(u8*)(this_ + i * 0x14 + 0x30d) = 1;
            return;
        } else {
            JGeometry::TVec2<f32> v;
            s32 idx = fn_801D05F8(this_, this_ + 0xc, lbl_8053F594);
            if (idx >= 0 && this_[idx * 0x18 + 0x2a8] == 0) {
                u32 ang = fn_801D0280(this_);
                v.set(JMath::sincosTable_.mTable[(u16)ang >> 5].first, JMath::sincosTable_.mTable[(u16)ang >> 5].second);
            } else {
                v.set(dir[0], dir[1]);
                v.normalize();
            }
            v.scale(lbl_8053F598);
            ((JGeometry::TVec3<f32>*)(this_ + i * 0x14 + 0x310))->set(v.x, v.y, lbl_8053F588);
            *(u8*)(this_ + i * 0x14 + 0x30d) = 1;
            return;
        }
    }
}

