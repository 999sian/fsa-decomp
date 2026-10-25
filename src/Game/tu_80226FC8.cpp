#include "types.h"
#include "sdk/stl/float.h"
struct GateBox {
    f32 x0, y0, x1, y1;
    void translate(f32 x, f32 y) { x0 += x; y0 += y; x1 += x; y1 += y; }
    void expand(f32 v) { f32 a=x0-v, b=y0-v, c=x1+v, d=y1+v; x0=a; y0=b; x1=c; y1=d; }
};
static inline s32 gateRoom(s32 param) { s32 n=(param>>24)&7; return n ? n+7 : n; }
struct GateRoomFlags { u8 pad[0x131df]; u8 flags[1]; u8 flag(s32 room) { return flags[room]; } };


extern "C" void fn_801EE434(void* p);
extern "C" void __dt__5ActorFv(void* p, int how);
extern void operator delete(void* p);
extern void* lbl_804A6DC8[];
typedef struct FsaVec3 {
    f32 x;
    f32 y;
    f32 z;
} FsaVec3;
extern void* lbl_8053AAF8;
extern void* lbl_8053AB10;
extern f32 lbl_8046AC58[];
extern void* lbl_8046ACB8[];
extern f32 lbl_8053FF74;
extern f32 lbl_8053FF84;
extern f32 lbl_8053FF88;
extern void* lbl_8053AC98;
extern f32 lbl_8053FF60;
extern f32 lbl_8053FF64;
extern f32 lbl_8053FF68;
extern f32 lbl_8053FF6C;
extern f32 lbl_8053FF70;
extern f32 lbl_8053FF78;
extern "C" u8 fn_8023EFEC(s32 idx);
extern "C" u32 fn_8023EEB4(s32 idx);
extern "C" s32 fn_8023EF50(s32 idx);
extern "C" char* fn_801F666C(void* mgr, s32 id);
extern "C" void fn_802A3948(void* mgr, f32* pos, s32 idx, u32 room, s32 n);
extern "C" void* fn_8013CC50(u32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
s32 fn_801CD664(s32 arg);
void fn_802F6CF4(void* obj, f32* pos, void* res, u8* blk);
void fn_802F6CF4(void* obj, FsaVec3* pos, void* res, u8* blk);
extern "C" void* fn_802D6A9C(void);
extern "C" void* fn_801F856C(void);
extern "C" void fn_80226FC8(void* this_, s32 idx) {
    if (*((u8*)this_ + 0x255) != 1) {
        u8* p = (u8*)this_ + idx * 4;
        void* a = *(void**)(p + 0x27c);
        if (a == 0) {
            if (fn_8023EFEC(idx) && fn_8023EEB4(idx) == 0x59415349) {
                s32 id = fn_8023EF50(idx);
                void* mgr = fn_801F856C();
                *(void**)(p + 0x27c) = fn_801F666C(mgr, id);
            }
        } else if (*((u8*)a + 0x11c) == 0) {
            *(void**)(p + 0x27c) = 0;
        } else {
            FsaVec3* vel = (FsaVec3*)((u8*)a + 0x3c);
            FsaVec3* apos = (FsaVec3*)((u8*)a + 0xc);
            FsaVec3* bpos = (FsaVec3*)((u8*)this_ + 0xc);
            FsaVec3 d;
            FsaVec3 v0, v1, v2, v3;
            u8 hit = 0;
            if (vel->z * vel->z + vel->x * vel->x + vel->y * vel->y > lbl_8053FF60 * FLT_EPSILON && apos->z < lbl_8053FF64) {
                d.x = apos->x - bpos->x;
                d.y = apos->y - bpos->y;
                d.z = apos->z - bpos->z;
                if (d.x < lbl_8053FF68 && d.y < lbl_8053FF68 && d.x < lbl_8053FF6C && d.y < lbl_8053FF6C) {
                    hit = 1;
                }
                if (hit) {
                    ((void (*)(void*))(*(void***)a)[18])(a);
                    *(void**)(p + 0x27c) = 0;
                    v0.x = bpos->x - lbl_8053FF70;
                    v0.y = bpos->y - lbl_8053FF70;
                    v0.z = lbl_8053FF74;
                    fn_802A3948(lbl_8053AC98, (f32*)&v0, idx, *(u32*)((u8*)this_ + 4), 0xc);
                    v1.x = bpos->x + lbl_8053FF70;
                    v1.y = bpos->y - lbl_8053FF70;
                    v1.z = lbl_8053FF74;
                    fn_802A3948(lbl_8053AC98, (f32*)&v1, idx, *(u32*)((u8*)this_ + 4), 0xc);
                    v2.x = bpos->x - lbl_8053FF70;
                    v2.y = bpos->y + lbl_8053FF70;
                    v2.z = lbl_8053FF74;
                    fn_802A3948(lbl_8053AC98, (f32*)&v2, idx, *(u32*)((u8*)this_ + 4), 0xc);
                    v3.x = bpos->x + lbl_8053FF70;
                    v3.y = bpos->y + lbl_8053FF70;
                    v3.z = lbl_8053FF74;
                    fn_802A3948(lbl_8053AC98, (f32*)&v3, idx, *(u32*)((u8*)this_ + 4), 0xc);
                    if (*((u8*)this_ + 0x255) == 0) {
                        fn_8013CC50(*(u32*)((u8*)this_ + 4), (u8*)this_ + 0xc, lbl_8053FF78, 0x3e3, 0, -2, 0, 0, 1);
                        *((u8*)this_ + 0x255) = 1;
                    }
                }
            }
        }
    }
}

extern "C" s32 fn_80227290(void* this_, f32 eps, u32* types, s32 handle) {
    s32 found = -1;
    s32 room = *(s32*)((u8*)this_ + 0x4);
    u8 flag = ((u8*)fn_802D6A9C())[room + 0x131df];
    s32 count = *(s32*)((u8*)fn_801F856C() + 0x1008);
    for (s32 i = 0; i < count; i++) {
        u8* a = (u8*)(*(void**)((u8*)fn_801F856C() + i * 4 + 8));
        if (a == 0 || a[0x11c] == 0 || *(s32*)(a + 0x4) != room || *(s32*)(a + 0x198) == handle) {
            continue;
        }
        if (flag == 0) {
            if (__fabs(*(f32*)((u8*)this_ + 0x14) - *(f32*)(a + 0x14)) > eps) {
                continue;
            }
            found = *(s32*)(a + 0x198);
            break;
        }
        for (u32* t = types; *t != 0x4e554c4c; t++) {
            if (*t == *(u32*)(a + 0x1a0)) {
                found = *(s32*)(a + 0x198);
                break;
            }
        }
        if (found >= 0) {
            break;
        }
    }
    return found;
}

extern "C" void fn_80227530(void* this_, f32* out) {
    FsaVec3 v0, v1, v2, v3;
    f32* box = (f32*)((u8*)this_ + 0x60);
    FsaVec3* bpos = (FsaVec3*)((u8*)this_ + 0xc);
    fn_80226FC8(this_, 0);
    out[0] = box[0];
    out[1] = box[1];
    out[2] = box[2];
    out[3] = box[3];
    out[0] = box[0] + bpos->x;
    out[1] = box[1] + bpos->y;
    out[2] = box[2] + bpos->x;
    out[3] = box[3] + bpos->y;
    if (*((u8*)lbl_8053AAF8 + 0x7e) != 0) {
        return;
    }
    v0.x = bpos->x - lbl_8053FF70;
    v0.y = bpos->y - lbl_8053FF70;
    v0.z = lbl_8053FF74;
    fn_802A3948(lbl_8053AC98, (f32*)&v0, 0, *(u32*)((u8*)this_ + 4), 0xc);
    v1.x = bpos->x + lbl_8053FF70;
    v1.y = bpos->y - lbl_8053FF70;
    v1.z = lbl_8053FF74;
    fn_802A3948(lbl_8053AC98, (f32*)&v1, 0, *(u32*)((u8*)this_ + 4), 0xc);
    if (*((u8*)this_ + 0x255) == 0) {
        fn_8013CC50(*(u32*)((u8*)this_ + 4), (u8*)this_ + 0xc, lbl_8053FF78, 0x3e3, 0, -2, 0, 0, 1);
        *((u8*)this_ + 0x255) = 1;
    }
}

extern "C" u8 fn_8022D75C(s32);
extern "C" u8 fn_8022D534(s32);
extern "C" u8 fn_8022F514(s32);
extern "C" u8 fn_8023B0F4(s32, f32*, u32, s32, f32);
extern "C" void fn_802381B8(s32);
extern "C" u8 fn_80234E30(s32);
extern "C" u8 fn_8022C8EC(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u32 fn_8022C5EC(s32,s32);
extern "C" u32 fn_8022C46C(s32,s32);
extern "C" u8 fn_8022DBA0(s32);
extern "C" u8 fn_8022F478(s32);
extern "C" s32 fn_802373EC(s32);
extern "C" s32 fn_8023725C(s32);
extern "C" u8 fn_8023513C(s32);
extern "C" u8 fn_802317F0(s32,s32,void*,void*,u32);
extern "C" s32 fn_8022CAF8(s32);
extern "C" s32 fn_8023E724(s32);
extern "C" s32 fn_8022F3DC(s32);
extern "C" u8 fn_8022BC38(s32,s32,s32);
extern "C" void fn_802348C4(s32,s32,s32);
extern "C" void fn_802278A8(void* this_, f32* out) {
    u8* p = (u8*)this_;
    for (s32 i = 0; i < 4; i++) {
        f32 y1, x1, y0, x0, x, y;
        x0 = *(f32*)(p+0x60); out[0]=x0;
        y0 = *(f32*)(p+0x64); out[1]=y0;
        x1 = *(f32*)(p+0x68); out[2]=x1;
        y1 = *(f32*)(p+0x6c); out[3]=y1;
        y = *(f32*)(p+0x10);
        x = *(f32*)(p+0xc);
        y0+=y; x0+=x; x1+=x; y1+=y;
        out[1]=y0; out[0]=x0; out[2]=x1; out[3]=y1;
        if (!fn_8022D75C(i) && fn_8022D534(i)) { p[i+0x234]=1; continue; }
        if ((*(s32*)(p+0x90)&0x7f)==0x10) return;
        if (fn_8022F514(i)) {
            s32 type=*(s32*)(p+0x90)&0x7f;
            if ((type==0 || (u32)(type-1)<=2 || type==0x17 || type==0x18) &&
                fn_8023B0F4(i,out,*(u32*)(p+4),0,lbl_8053FF70)) fn_802381B8(i);
        }
        if ((*(s32*)(p+0x90)&0x7f)==0x13 && !fn_80234E30(i)) continue;
        if (*((u8*)lbl_8053AAF8+0x7e) && !fn_8022C8EC(i)) {
            s32 room=(*(s32*)(p+0x90)>>24)&7;
            s32 id=room+7; if (!room) id=room;
            s32 current=fn_8023DE58(i);
            if (current!=id) continue;
        }
        if (fn_8023B0F4(i,out,*(u32*)(p+4),0,lbl_8053FF70)) {
            s32 mapRoom;
            if (((*(s32*)(p+0x90)&0x7f)==0x15 || (*(s32*)(p+0x90)&0x7f)==0x23) &&
                (mapRoom=*(s32*)(p+4), ((GateRoomFlags*)fn_802D6A9C())->flag(mapRoom))) {
                if (!fn_8022C5EC(i,8) && !fn_8022C5EC(i,4) && !fn_8022C46C(i,8) && !fn_8022C46C(i,4)) continue;
                if (fn_8022DBA0(i)) continue;
            } else {
                if (p[i+0x234]==1) continue;
                if (fn_8022D75C(i)) { p[i+0x234]=1; continue; }
            }
            if (fn_8022F478(i) && (*(s32*)(p+0x90)&0x7f)!=4) continue;
            if (((*(s32*)(p+0x90)&0x7f)==4 || (*(s32*)(p+0x90)&0x7f)==0x20 || (*(s32*)(p+0x90)&0x7f)==0x24) &&
                fn_802373EC(i)==1 && fn_8023725C(i)>=2 && fn_8023513C(i)) continue;
            s32 kind=*(s32*)(p+0x90)&0x7f;
            s32 room=(*(s32*)(p+0x90)>>24)&7;
            s32 id=room+7; if (!room) id=room;
            if (fn_802317F0(i,id,p+0xc,p+0x238,kind) &&
                (*(s32*)(p+0x90)&0x7f)==4 && fn_8022F514(i)) {
                s32 a=fn_8023DE58(i);
                if (((GateRoomFlags*)fn_802D6A9C())->flag(a) || fn_8022CAF8(i)==4 || fn_8022CAF8(i)==5) continue;
                int b;
                int c;
                b=fn_8023E724(i);
                c=fn_8023DE58(i);
                if (fn_8022BC38(fn_8022F3DC(i),c,b)) {
                    fn_802381B8(fn_8022F3DC(i));
                    int d;
                    int e=fn_8023E724(i); d=fn_8023DE58(i);
                    fn_802348C4(fn_8022F3DC(i),d,e);
                }
            }
        } else {
            f32 x0=out[0], y0=out[1], x1=out[2], y1=out[3];
            f32 expand=lbl_8053FF78;
            out[0]=x0-expand;
            out[1]=y0-expand;
            out[2]=x1+expand;
            out[3]=y1+expand;
            if (!fn_8023B0F4(i,out,*(u32*)(p+4),0,lbl_8053FF74)) p[i+0x234]=0;
        }
    }
}

extern "C" void fn_80227CE8(void* this_) {
    f32 d[3];
    f32 save[3];
    u8 blk[0x3c];
    u8 i;

    if ((*(s32*)((u8*)this_ + 0x90) & 0x7f) == 0x20 && *((u8*)this_ + 0x255) == 0) {
        *(s32*)(blk + 0x10) = -1;
        *(s32*)(blk + 0x14) = -1;
        for (i = 0; i < 0x10; i += 8) {
            blk[(u8)(i)] = i;
            blk[(u8)(i + 1)] = i + 1;
            blk[(u8)(i + 2)] = i + 2;
            blk[(u8)(i + 3)] = i + 3;
            blk[(u8)(i + 4)] = i + 4;
            blk[(u8)(i + 5)] = i + 5;
            blk[(u8)(i + 6)] = i + 6;
            blk[(u8)(i + 7)] = i + 7;
        }
        *(s32*)(blk + 0x10) = -1;
        *(s32*)(blk + 0x14) = 0;
        *(s32*)(blk + 0x18) = 0;
        blk[0x1c] = 0;
        blk[0x1d] = 0;
        blk[0x1e] = 0;
        blk[0x1f] = 1;
        blk[0x20] = 1;
        blk[0x21] = 0;
        blk[0x22] = 0;
        blk[0x23] = 0;
        blk[0x24] = 0;
        blk[0x25] = 0;
        blk[0x26] = 1;
        *(s32*)(blk + 0x28) = 3;
        blk[0x2c] = 1;
        blk[0x2d] = 0;
        blk[0x2e] = 0;
        *(s32*)(blk + 0x30) = -1;
        *(s32*)(blk + 0x34) = 0;
        *(s32*)(blk + 0x38) = 2;

        save[0] = *(f32*)((u8*)this_ + 0xc);
        save[1] = *(f32*)((u8*)this_ + 0x10);
        save[2] = *(f32*)((u8*)this_ + 0x14);
        d[0] = lbl_8053FF84;
        d[1] = lbl_8053FF84;
        d[2] = lbl_8053FF74;
        *(f32*)((u8*)this_ + 0xc) += d[0];
        *(f32*)((u8*)this_ + 0x10) += d[1];
        *(f32*)((u8*)this_ + 0x14) += d[2];

        if (*((u8*)this_ + 0x256) == 1 && *(s32*)((u8*)this_ + 0x278) >= 0) {
            *(f32*)((u8*)this_ + 0xc) += lbl_8046AC58[*(s32*)((u8*)this_ + 0x278)];
            *(s32*)((u8*)this_ + 0x278) += 1;
            if (*(s32*)((u8*)this_ + 0x278) >= 0x18) {
                *(s32*)((u8*)this_ + 0x278) = fn_801CD664(10) - 0x69;
            }
        }

        blk[0x24] = 1;
        blk[0x1d] = -2;
        blk[0x13] = 0xa0;
        blk[0x2c] = 0;

        if (*(s32*)((u8*)this_ + 0x4) < 8) {
            void* mgr = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
            void* res = ((void* (*)(void*, u32, void*))(*(void***)mgr)[6])(mgr, 0x534d5020, lbl_8046ACB8);
            fn_802F6CF4(((void**)lbl_8053AB10)[8], (f32*)((u8*)this_ + 0xc), res, blk);
        }

        *(f32*)((u8*)this_ + 0xc) = save[0];
        *(f32*)((u8*)this_ + 0x10) = save[1];
        *(f32*)((u8*)this_ + 0x14) = save[2];
    } else {
        *(f32*)((u8*)this_ + 0x10) = *(f32*)((u8*)this_ + 0x10) + lbl_8053FF88;
        *(f32*)((u8*)this_ + 0x10) = *(f32*)((u8*)this_ + 0x10) - lbl_8053FF88;
    }
}

extern "C" void* fn_80228AEC(void* this_, s16 freeFlag) {
    if (this_) {
        *(void**)this_ = lbl_804A6DC8;
        fn_801EE434(*(void**)((u8*)this_ + 0x24c));
        fn_801EE434(*(void**)((u8*)this_ + 0x250));
        __dt__5ActorFv(this_, 0);
        s32 f = freeFlag;
        if (f > 0) {
            operator delete(this_);
        }
    }
    return this_;
}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
