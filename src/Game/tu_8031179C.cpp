#define GAME_ACTOR_USE_SDK_VEC
#include "JSystem/JGeometry/Box.h"
#include "Game/Actor.h"
#include "JSystem/JMath/JMath.h"

extern "C" u8 fn_802D800C(void*, s32);
extern "C" void fn_80239914(void*, s32, void*);
extern "C" void fn_8022FEB8(f32*, s32, void*, s32, s32);
extern "C" void fn_8022FF8C(s32, f32*, s32, void*, s32, s32);
extern "C" s32 fn_8022FD8C(void*);
extern "C" u8 fn_802300EC(void);
extern "C" u16 fn_80226850(f32*, s32);
extern "C" u8 fn_8038C678(s32, s32, void*, s32, void*, s32);
extern "C" u8 fn_80388CAC(s32, void*);
extern "C" void fn_80458880(void*, s32, s32);
extern "C" void fn_802A3948(void*, void*, s32, s32, s32);
extern "C" const f32 lbl_805417B8;
extern "C" const f32 lbl_805417BC;
extern "C" const f32 lbl_805417C0;
extern "C" const f32 lbl_805417C4;
extern "C" const f32 lbl_805417C8;
extern "C" const f32 lbl_805417CC;
extern "C" const f32 lbl_805417D0;
extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053AF80;
extern "C" void* lbl_8053AC98;
extern "C" const f32 lbl_805417E0;


extern "C" char lbl_804AAB40[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" char lbl_80471488[];
extern "C" void fn_801F06F0(void*, void*, s32, s32, s32, f32, f32);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void* lbl_8053AED0;
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D8050(void*, s32, s32, s32);
extern "C" u8 fn_8023A97C(s32 i, void* area, s32 b, f32* pos);
extern "C" u16 fn_80226998(f32* pos, s32 room);
extern "C" u8 fn_8022E438(s32 i, s32 b);
extern "C" s32 fn_8022CAF8(s32 i);
extern "C" void fn_8043D67C(void* mgr, s32 id, s32 arg, s32 flag);
extern "C" u32 __cvt_fp2unsigned(f64);

static inline void tuPlayerMessage(u8* p, s32 id, s32 player) {
    if (player == *(s32*)(p + 0x250) ||
        (fn_8022E438(player, *(s32*)(p + 0x250)) && fn_8022CAF8(player) == 4)) {
        fn_8043D67C(lbl_8053AED0, id, player, 0);
    }
}
extern "C" void fn_8031179C(u8* p) {
    s32 i = 0;
    f32 pos[2];
    do {
        if (fn_8023A97C(i, p + 0x230, 0, pos) && fn_80226998(pos, 0) == 0x1b0) {
            if (*(p + 0x259) == 0) {
                tuPlayerMessage(p, 0x826, *(s32*)(p + 0x250));
            } else {
                s32 dx = ((__cvt_fp2unsigned(pos[0]) & 0xfffffff0) + 8) - (s32)*(f32*)(p + 0x240);
                s32 dy = ((__cvt_fp2unsigned(pos[1]) & 0xfffffff0) + 8) - (s32)*(f32*)(p + 0x244);
                if (dy < -0x30) {
                    tuPlayerMessage(p, 0x825, i);
                } else if (dy > 0x30) {
                    tuPlayerMessage(p, 0x826, i);
                } else if (dx < -0x30) {
                    tuPlayerMessage(p, 0x827, i);
                } else if (dx > 0x30) {
                    tuPlayerMessage(p, 0x828, i);
                } else if (dy < -0x10) {
                    tuPlayerMessage(p, 0x829, i);
                } else if (dy > 0x10) {
                    tuPlayerMessage(p, 0x82a, i);
                } else if (dx < -0x10) {
                    tuPlayerMessage(p, 0x82b, i);
                } else if (dx > 0x10) {
                    tuPlayerMessage(p, 0x82c, i);
                } else if (dy < -8) {
                    tuPlayerMessage(p, 0x82d, i);
                } else if (dy > 8) {
                    tuPlayerMessage(p, 0x82e, i);
                } else if (dx < -8) {
                    tuPlayerMessage(p, 0x82f, i);
                } else if (dx > 8) {
                    tuPlayerMessage(p, 0x830, i);
                } else {
                    fn_802D8050(fn_802D6A9C(), 0x14, 1, 0xff);
                }
            }
        }
        i++;
    } while (i < 4);
}

extern "C" void fn_80311C58(void* p) {
    fn_801F06F0(p, lbl_80471488, 0x386, 0, 0, lbl_805417C4, lbl_805417C4);
    fn_803075AC(*(void**)((u8*)p + 0x198), *(s32*)((u8*)p + 4), (u8*)p + 0xc, 0x386, 0, 2, -1, 0, 0, 0);
}

#pragma opt_lifetimes off
extern "C" void fn_80311CD0(Actor* actor) {
    JGeometry::TBox2<f32> bounds;
    JGeometry::TVec3<f32> dialog58, dialog4c, dialog40, dialog34, copy28, pos, saved10;
    f32 step, zero, fy2, fx2, fx, fy, fx1, fy1;
    s32 r30, r29, r28;
    s32 state;
    bool found;
    bounds.i.x = *(f32*)(((u8*)actor) + 0x60);
    bounds.i.y = *(f32*)(((u8*)actor) + 0x64);
    bounds.f.x = *(f32*)(((u8*)actor) + 0x68);
    bounds.f.y = *(f32*)(((u8*)actor) + 0x6c);
    bounds.addPos(*(JGeometry::TVec2<f32>*)(((u8*)actor)+0xc));
    fn_80239914(&bounds, *(s32*)(((u8*)actor) + 4), *(void**)(((u8*)actor) + 0x198));

    state = *(s32*)(((u8*)actor) + 0x24c);
    switch (state) {
    case 0:
        fn_8022FEB8(&bounds.i.x, *(s32*)(((u8*)actor) + 4), *(void**)(((u8*)actor) + 0x198), 1, 0);
        r29 = fn_8022FD8C(*(void**)(((u8*)actor) + 0x198));
        if (r29 < 0) {
            break;
        }
        if (!fn_802300EC()) {
            break;
        }
        if ((u8)fn_802D800C(fn_802D6A9C(), 0x14)) {
            void* handledialog58=*(void**)(((u8*)actor)+0x198);
            s32 roomdialog58=*(s32*)(((u8*)actor)+4);
            dialog58=*(JGeometry::TVec3<f32>*)(((u8*)actor)+0xc);
            if (fn_8038C678(r29, 0x834,handledialog58,roomdialog58,&dialog58, 0x28)) {
                *(s32*)(((u8*)actor) + 0x254) = r29;
                *(s32*)(((u8*)actor) + 0x24c) = 3;
            }
            break;
        }
        fx=*(f32*)(((u8*)actor)+0x230);
        fy=*(f32*)(((u8*)actor)+0x234);
        fx1=*(f32*)(((u8*)actor)+0x238);
        fy1=*(f32*)(((u8*)actor)+0x23c);
        f32 offsetY, offsetX, rangeY, rangeX;
        offsetX=64.0f;
        offsetY=32.0f;
        rangeX=416.0f;
        rangeY=320.0f;
        fx+=offsetX;
        fy+=offsetY;
        fx1-=offsetY;
        fy1-=offsetY;
        zero=lbl_805417CC;
        step=lbl_805417D0;
        fx2=rangeX*((JMARandFast*)((u8*)lbl_8053AAF8+0xb4))->get_ufloat_1()+fx;
        fy2=rangeY*((JMARandFast*)((u8*)lbl_8053AAF8+0xb4))->get_ufloat_1()+fy;
        for (r30 = 0; r30 < 0x14; r30++) {
            for (r28 = 0; r28 < 0x1a; r28++) {
                pos.x = fx2;
                pos.y = fy2;
                pos.z = zero;
                if (fn_80226850(&pos.x, 0) == 0x1b0) {
                    pos.x = (f32)(__cvt_fp2unsigned(pos.x) & ~0xf);
                    pos.y = (f32)(__cvt_fp2unsigned(pos.y) & ~0xf);
                    *(f32*)(((u8*)actor) + 0x240) = pos.x;
                    *(f32*)(((u8*)actor) + 0x244) = pos.y;
                    *(f32*)(((u8*)actor) + 0x248) = pos.z;
                    copy28 = pos;
                    saved10 = copy28;
                    u8* manager = (u8*)fn_802D6A9C()+0x10000;
                    *(f32*)(manager+0x3280)=saved10.x;
                    *(f32*)(manager+0x3284)=saved10.y;
                    *(f32*)(manager+0x3288)=saved10.z;
                    found = true;
                    goto searchDone;
                }
                fx2 = fx2 + step;
                if (fx2 >= fx1) {
                    fx2 = fx;
                }
            }
            fy2 = fy2 + step;
            if (fy2 >= fy1) {
                fy2 = fy;
            }
        }
        found=false;
searchDone:
        if (!found) {
            void* handledialog4c=*(void**)(((u8*)actor)+0x198);
            s32 roomdialog4c=*(s32*)(((u8*)actor)+4);
            dialog4c=*(JGeometry::TVec3<f32>*)(((u8*)actor)+0xc);
            if (fn_8038C678(r29,0x84f,handledialog4c,roomdialog4c,&dialog4c,0x28)) {
                *(s32*)(((u8*)actor)+0x254)=r29;
                *(s32*)(((u8*)actor)+0x24c)=3;
            }
        } else {
            void* handledialog40=*(void**)(((u8*)actor)+0x198);
            s32 roomdialog40=*(s32*)(((u8*)actor)+4);
            dialog40=*(JGeometry::TVec3<f32>*)(((u8*)actor)+0xc);
            if (fn_8038C678(r29,0x835,handledialog40,roomdialog40,&dialog40,8)) {
                *(s32*)(((u8*)actor)+0x250)=r29;
                *(s32*)(((u8*)actor)+0x24c)=1;
            }
        }
        break;
    case 1:
        fn_8022FF8C(*(s32*)(((u8*)actor) + 0x250), &bounds.i.x, *(s32*)(((u8*)actor) + 4), *(void**)(((u8*)actor) + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(((u8*)actor) + 0x250), *(void**)(((u8*)actor) + 0x198))) {
            *(f32*)(((u8*)actor) + 0x240) = *(f32*)(((u8*)actor) + 0x240) + lbl_805417E0;
            *(f32*)(((u8*)actor) + 0x244) = *(f32*)(((u8*)actor) + 0x244) + lbl_805417E0;
            ((u8*)actor)[0x258] = 0;
            ((u8*)actor)[0x259] = 1;
            *(s32*)(((u8*)actor) + 0x24c) = 2;
        }
        break;
    case 2:
        if ((u8)fn_802D800C(fn_802D6A9C(),0x14)==0) {
            fn_8031179C(((u8*)actor));
        } else if (((u8*)actor)[0x25a]==0) {
            fn_802A3948(lbl_8053AC98,((u8*)actor)+0x240,0,0,0x7a);
            fn_80458880(lbl_8053AF80,3,-1);
            ((u8*)actor)[0x25a]=1;
        }
        if (((u8*)actor)[0x258] == 0) {
            fn_8022FEB8(&bounds.i.x, *(s32*)(((u8*)actor) + 4), *(void**)(((u8*)actor) + 0x198), 1, 0);
            s32 player = fn_8022FD8C(*(void**)(((u8*)actor) + 0x198));
            if (player < 0) {
                break;
            }
            if (!fn_802300EC()) {
                break;
            }
            s32 message;
            if (fn_8022E438(player,*(s32*)(((u8*)actor)+0x250))) {
                if ((u8)fn_802D800C(fn_802D6A9C(),0x14)) message=0x834;
                else message=0x832;
            } else message=0x833;
            void* handledialog34=*(void**)(((u8*)actor)+0x198);
            s32 roomdialog34=*(s32*)(((u8*)actor)+4);
            dialog34=*(JGeometry::TVec3<f32>*)(((u8*)actor)+0xc);
            if (fn_8038C678(player,message,handledialog34,roomdialog34,&dialog34,8)) {
                *(s32*)(((u8*)actor)+0x254)=player;
                ((u8*)actor)[0x258]=1;
            }
        } else {
            fn_8022FF8C(*(s32*)(((u8*)actor) + 0x254), &bounds.i.x, *(s32*)(((u8*)actor) + 4), *(void**)(((u8*)actor) + 0x198), 1, 0);
            if (fn_80388CAC(*(s32*)(((u8*)actor) + 0x254), *(void**)(((u8*)actor) + 0x198))) {
                *(s32*)(((u8*)actor) + 0x254) = -1;
                ((u8*)actor)[0x258] = 0;
            }
        }
        break;
    case 3:
        fn_8022FF8C(*(s32*)(((u8*)actor) + 0x254), &bounds.i.x, *(s32*)(((u8*)actor) + 4), *(void**)(((u8*)actor) + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(((u8*)actor) + 0x254), *(void**)(((u8*)actor) + 0x198))) {
            *(s32*)(((u8*)actor) + 0x254) = -1;
            *(s32*)(((u8*)actor) + 0x24c) = 0;
        }
        break;
    }
}
#pragma opt_lifetimes reset
extern "C" Actor* fn_803122F8(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AAB40;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void*, s32);
extern "C" void fn_802D8050(void*, s32, s32, s32);
extern "C" void fn_802A3948(void*, void*, s32, s32, s32);
extern "C" void* lbl_8053AC98;
extern "C" const f32 lbl_805417E4;
extern "C" void fn_80312358(Actor* p) {
    void* base;
    *(f32*)((u8*)p + 0x60) = lbl_805417E4;
    *(f32*)((u8*)p + 0x64) = lbl_805417E4;
    *(f32*)((u8*)p + 0x68) = lbl_805417E0;
    *(f32*)((u8*)p + 0x6c) = lbl_805417E0;
    base = fn_802D6A9C();
    *(JGeometry::TBox2<f32>*)((u8*)p + 0x230) = *(JGeometry::TBox2<f32>*)((u8*)base + 0xcc);
    *(f32*)((u8*)p + 0x240) = *(f32*)((u8*)p + 0xc);
    *(f32*)((u8*)p + 0x244) = *(f32*)((u8*)p + 0x10);
    *(f32*)((u8*)p + 0x248) = *(f32*)((u8*)p + 0x14);
    *(s32*)((u8*)p + 0x24c) = 0;
    *(s32*)((u8*)p + 0x250) = -1;
    *(s32*)((u8*)p + 0x254) = -1;
    *((u8*)p + 0x258) = 0;
    *((u8*)p + 0x259) = 0;
    *((u8*)p + 0x25a) = 0;
    base = fn_802D6A9C();
    if ((u8)fn_802D800C(base, 0x14) != 0) {
        base = fn_802D6A9C();
        fn_802A3948(lbl_8053AC98, (u8*)base + 0x13280, 0, 0, 0x7a);
    } else {
        base = fn_802D6A9C();
        fn_802D8050(base, 0x15, 0, 0xff);
    }
}

extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
void fn_80312444(void) {
}

