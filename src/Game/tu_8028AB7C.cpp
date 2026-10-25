#include "types.h"


void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804A7960[];
extern "C" void fn_801EE434(void* handle);
extern "C" u8 fn_80303750(s32 i);
extern "C" u8 fn_8028B850(u8* this_);
extern "C" const f32 lbl_805404CC;
extern "C" const f32 lbl_805404C0;
extern "C" f32 lbl_805404D8;
extern "C" f32 lbl_805404F0;
extern void* lbl_8053AAF8;
extern "C" u8* fn_802D6A9C(void);
extern "C" s32 fn_80138A30(void* game);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id);
extern "C" double sin(double);
extern "C" double cos(double);
extern "C" f32 lbl_805404C4;
extern "C" f32 lbl_805404C8;
extern "C" void fn_8028AB7C(u8* this_) {
    f32 m[12];
    u8 idx[16];
    s32 i;
    f32 ang;
    f32 s0, s1, s2, c0, c1, c2;

    if (*(f32*)(this_ + 0x240) <= lbl_805404C0) {
        return;
    }
    for (i = 0; i < 16; i++) {
        idx[i] = i;
    }
    ang = lbl_805404C4 * (lbl_805404C8 * (lbl_805404CC - *(f32*)(this_ + 0x240)));
    s0 = sin(ang);
    s1 = sin(ang);
    s2 = sin(ang);
    c0 = cos(ang);
    c1 = cos(ang);
    c2 = cos(ang);
    fn_801F06F0(this_, "enemy_gc_sob.bin", *(s32*)(this_ + 0x25c) + 0x129);
}

extern "C" void detach__5ActorFv(void* this_);
extern "C" void fn_801F0D20(u8* this_, s32 id);
extern "C" void fn_801F0E34(u8* this_, u32 id, s32 flag);
extern "C" u8* fn_801902C0(void);
extern "C" void fn_8043D67C(void* p, s32 a, s32 b, s32 c);
extern "C" void* fn_8013CC50(s32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" u8 fn_8022F478(s32 i);
extern "C" u8 fn_8022C8EC(s32 i);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" u8 fn_8023B0F4(s32 i, f32* p, f32 r, s32 room, s32 flag);
extern "C" u8 fn_802317F0(s32 i, s32 a, void* p, void* q, s32 b);
extern "C" void* fn_801F26CC(u8* this_, const void* p);
extern "C" void* fn_801F856C(void);
extern "C" u8* fn_801F666C(void* a, void* b);
extern "C" void fn_801F349C(u8* obj, s32 n, f32* v);
extern "C" f32 lbl_805404D0;
extern "C" f64 lbl_805404E0;
extern void* lbl_8053AED0;
extern "C" const u8 lbl_8046C100[12];
extern "C" void fn_8028AE2C(u8* this_) {
    s32 idx;
    u8 prev;
    u8 cur;
    s32 i;
    s32 n;
    s32 cnt;
    s32 t;
    u8* obj;
    f32 rect[4];
    f32 pv[3];

    prev = this_[0x234];
    this_[0x262] = 0;
    cur = fn_8028B850(this_);
    this_[0x234] = cur;
    if (prev == 0 && this_[0x234] == 1) {
        this_[0x263] = 1;
    } else if (prev == 1 && this_[0x234] == 0) {
        this_[0x264] = 1;
    }

    idx = *(s32*)(this_ + 0x25c);
    if (idx >= 5) {
        idx = 0;
    }

    if (this_[0x234] != 0 || *(s32*)(this_ + 0x238) > 0) {
        if (*(f32*)(this_ + 0x240) < lbl_805404CC) {
            if (this_[0x263] == 1) {
                fn_801F0D20(this_, 0x2e);
                this_[0x263] = 0;
            }
            *(f32*)(this_ + 0x240) = *(f32*)(this_ + 0x240) + lbl_805404D0;
            if (*(f32*)(this_ + 0x240) >= lbl_805404CC) {
                *(f32*)(this_ + 0x240) = lbl_805404CC;
                *(s32*)(this_ + 0x248) = 10;
                if (((*(u32*)(this_ + 0x90) >> 3) & 1) == 1) {
                    fn_801F0D20(this_, 3);
                }
            }
        }
        if (*(f32*)(this_ + 0x240) >= lbl_805404CC) {
            if (this_[0x260] == 1) {
                fn_8043D67C(lbl_8053AED0, 0xe7, 0, 0);
                this_[0x260] = 0;
            }
            *(s32*)(this_ + 0x244) = *(s32*)(this_ + 0x244) + 1;
            if (*(s32*)(this_ + 0x244) >= 0x6e) {
                *(s32*)(this_ + 0x244) = 0x6e;
            }
            t = *(s32*)(this_ + 0x244);
            obj = fn_801902C0();
            if (*(s32*)(obj + 0x5ec) < 8) {
                u8* rec = obj + *(s32*)(obj + 0x5ec) * 0x28 + 0x4ac;
                *(f32*)(rec + 0x0) = *(f32*)(this_ + 0xc);
                *(f32*)(rec + 0x4) = *(f32*)(this_ + 0x10);
                *(f32*)(rec + 0x8) = *(f32*)(this_ + 0x14);
                *(s32*)(rec + 0xc) = idx;
                *(f32*)(rec + 0x10) = (f32)t;
                *(s32*)(obj + 0x5ec) = *(s32*)(obj + 0x5ec) + 1;
            }
            fn_801F0E34(this_, 0x3002d, 0);
            if (*(u8**)(this_ + 0x274) == 0) {
                *(void**)(this_ + 0x274) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_805404CC, 0x2a6, 0, 0, 0, 0, 1);
                obj = *(u8**)(this_ + 0x274);
                if (obj != 0) {
                    n = *(s32*)(this_ + 0x25c);
                    if (n == 0 || n == 5) {
                        obj[0xb8] = 0x5a;
                        obj[0xb9] = 0xf3;
                        obj[0xba] = 0xe9;
                        obj = *(u8**)(this_ + 0x274);
                        obj[0xbc] = 0x30;
                        obj[0xbd] = 0xa0;
                        obj[0xbe] = 0x5a;
                    } else if (n == 1) {
                        obj[0xb8] = 0xa0;
                        obj[0xb9] = 0xff;
                        obj[0xba] = 0x78;
                        obj = *(u8**)(this_ + 0x274);
                        obj[0xbc] = 0x40;
                        obj[0xbd] = 0x80;
                        obj[0xbe] = 0x30;
                    } else if (n == 2) {
                        obj[0xb8] = 0xff;
                        obj[0xb9] = 0x78;
                        obj[0xba] = 0x40;
                        obj = *(u8**)(this_ + 0x274);
                        obj[0xbc] = 0xff;
                        obj[0xbd] = 0xa0;
                        obj[0xbe] = 0x40;
                    } else if (n == 3) {
                        obj[0xb8] = 0;
                        obj[0xb9] = 0xa0;
                        obj[0xba] = 200;
                        obj = *(u8**)(this_ + 0x274);
                        obj[0xbc] = 0x40;
                        obj[0xbd] = 0x78;
                        obj[0xbe] = 0xa0;
                    } else if (n == 4) {
                        obj[0xb8] = 200;
                        obj[0xb9] = 0x9c;
                        obj[0xba] = 0xe5;
                        obj = *(u8**)(this_ + 0x274);
                        obj[0xbc] = 0x78;
                        obj[0xbd] = 0x30;
                        obj[0xbe] = 0xa0;
                    }
                }
            }
            if (*(u8**)(this_ + 0x278) == 0) {
                *(void**)(this_ + 0x278) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_805404CC, 0x2a7, 0, 0, 0, 0, 1);
                obj = *(u8**)(this_ + 0x278);
                if (obj != 0) {
                    n = *(s32*)(this_ + 0x25c);
                    if (n == 0 || n == 5) {
                        obj[0xb8] = 0xff;
                        obj[0xb9] = 0xff;
                        obj[0xba] = 0xff;
                        obj = *(u8**)(this_ + 0x278);
                        obj[0xbc] = 0x5a;
                        obj[0xbd] = 0xb0;
                        obj[0xbe] = 0xb1;
                    } else if (n == 1) {
                        obj[0xb8] = 0xf2;
                        obj[0xb9] = 0xff;
                        obj[0xba] = 0xc4;
                        obj = *(u8**)(this_ + 0x278);
                        obj[0xbc] = 0x49;
                        obj[0xbd] = 0xc3;
                        obj[0xbe] = 0x20;
                    } else if (n == 2) {
                        obj[0xb8] = 0xff;
                        obj[0xb9] = 0xa3;
                        obj[0xba] = 0xa3;
                        obj = *(u8**)(this_ + 0x278);
                        obj[0xbc] = 0x98;
                        obj[0xbd] = 0x2a;
                        obj[0xbe] = 0x29;
                    } else if (n == 3) {
                        obj[0xb8] = 0xa3;
                        obj[0xb9] = 0xc4;
                        obj[0xba] = 0xff;
                        obj = *(u8**)(this_ + 0x278);
                        obj[0xbc] = 0x27;
                        obj[0xbd] = 0x29;
                        obj[0xbe] = 0xa7;
                    } else if (n == 4) {
                        obj[0xb8] = 0xf1;
                        obj[0xb9] = 0xb4;
                        obj[0xba] = 0xff;
                        obj = *(u8**)(this_ + 0x278);
                        obj[0xbc] = 0x84;
                        obj[0xbd] = 0x28;
                        obj[0xbe] = 0x84;
                    }
                }
            }
        } else { return; }
    } else {
        if (*(s32*)(this_+0x244)>0) {
            --*(s32*)(this_+0x244);
            t = *(s32*)(this_ + 0x244);
            obj = fn_801902C0();
            if (*(s32*)(obj + 0x5ec) < 8) {
                u8* rec = obj + *(s32*)(obj + 0x5ec) * 0x28 + 0x4ac;
                *(f32*)(rec + 0x0) = *(f32*)(this_ + 0xc);
                *(f32*)(rec + 0x4) = *(f32*)(this_ + 0x10);
                *(f32*)(rec + 0x8) = *(f32*)(this_ + 0x14);
                *(s32*)(rec + 0xc) = idx;
                *(f32*)(rec + 0x10) = (f32)t;
                *(s32*)(obj + 0x5ec) = *(s32*)(obj + 0x5ec) + 1;
            }

        } else {
            if (this_[0x264]==1) {
                fn_801F0D20(this_,0x2F);
                this_[0x264]=0;
            }
            *(f32*)(this_+0x240)-=lbl_805404D0;
        }
        obj=*(u8**)(this_+0x274);
        if (obj!=0) {
            *(u32*)(obj+0xF4)|=1;
            *(s32*)(obj+0x24)=1;
            *(u8**)(this_+0x274)=0;
        }
        obj=*(u8**)(this_+0x278);
        if (obj!=0) {
            *(u32*)(obj+0xF4)|=1;
            *(s32*)(obj+0x24)=1;
            *(u8**)(this_+0x278)=0;
        }
        if (*(f32*)(this_+0x240)<=lbl_805404C0) *(f32*)(this_+0x240)=lbl_805404C0;
        if (*(s32*)(this_+0x244)<=0) *(s32*)(this_+0x244)=0;
        if (*(s32*)(this_+0x25C)==5 && *(s32*)(this_+0x24C)==0 &&
            *(f32*)(this_+0x240)<=lbl_805404C0 && *(s32*)(this_+0x244)<=0 &&
            *(s32*)(this_+0x23C)>0)
            detach__5ActorFv(this_);
        return;
    }
    rect[0] = *(f32*)(this_ + 0x60);
    rect[1] = *(f32*)(this_ + 0x64);
    rect[2] = *(f32*)(this_ + 0x68);
    rect[3] = *(f32*)(this_ + 0x6c);
    rect[1] += *(f32*)(this_+0x10);
    rect[0] += *(f32*)(this_+0xC);
    rect[2] += *(f32*)(this_+0xC);
    rect[3] += *(f32*)(this_+0x10);
    if (*(s32*)(this_ + 0x238) > 0) {
        *(s32*)(this_ + 0x238) = *(s32*)(this_ + 0x238) - 1;
    }
    if (*(s32*)(this_ + 0x248) <= 0) {
        for (i = 0; i < 4; i++) {
            if (fn_8022F478(i) == 0) {
                if (((u8*)lbl_8053AAF8)[0x7e] != 0 && fn_8022C8EC(i) == 0) {
                    n = (*(u32*)(this_ + 0x90) >> 24) & 7;
                    cnt = n + 7;
                    if (n == 0) {
                        cnt = 0;
                    }
                    if (fn_8023DE58(i) != cnt) {
                        continue;
                    }
                }
                n = *(s32*)(this_ + 0x25c);
                if (n < 1 || n > 4 || n == i + 1) {
                    if (fn_8023B0F4(i, rect, lbl_805404C0, *(s32*)(this_ + 4), 0) == 0 || this_[0x251] != 0) {
                        rect[0] = rect[0] - lbl_805404D0;
                        rect[1] = rect[1] - lbl_805404D0;
                        rect[2] = rect[2] + lbl_805404D0;
                        rect[3] = rect[3] + lbl_805404D0;
                        if (*(s32*)(this_ + 4) == fn_8023DE58(i) &&
                            fn_8023B0F4(i, rect, lbl_805404C0, *(s32*)(this_ + 4), 0) == 0) {
                            this_[i + 0x252] = 0;
                        }
                    } else if (this_[i + 0x252] != 1) {
                        s32 r6 = 6;
                        this_[i + 0x252] = 1;
                        if (*(s32*)(this_ + 0x25c) == 5) {
                            r6 = 0x14;
                        }
                        n = (*(u32*)(this_ + 0x90) >> 24) & 7;
                        cnt = n + 7;
                        if (n == 0) {
                            cnt = 0;
                        }
                        if (fn_802317F0(i, cnt, this_ + 0xc, this_ + 0x268, r6)) {
                            *(s32*)(this_ + 0x238) = 0xb4;
                            cnt = *(s32*)(this_ + 0x24c);
                            if ((cnt > 5 && cnt < 10) || (*(s32*)(this_ + 0x25c) == 5 && cnt == 0)) {
                                *(s32*)(this_ + 0x23c) = *(s32*)(this_ + 0x23c) + 1;
                                if (*(s32*)(this_ + 0x24c) - 5 <= *(s32*)(this_ + 0x23c)) {
                                    this_[0x251] = 1;
                                }
                                if (*(s32*)(this_ + 0x25c) == 5 && *(s32*)(this_ + 0x24c) == 0) {
                                    this_[0x251] = 1;
                                    *(s32*)(this_ + 0x24c) = 6;
                                }
                            }
                        }
                    }
                }
            }
        }
        this_[0x262] = 1;
        {
            void* o = fn_801F26CC(this_, &lbl_8046C100);
            u8* tgt = fn_801F666C(fn_801F856C(), o);
            f32 f2 = lbl_805404C0;
            f32 f3 = lbl_805404C0;
            u32 sp;
            u32 ax;
            u32 az;
            u8* tbl;
            n = (*(u32*)(this_ + 0x90) >> 24) & 7;
            cnt = n + 7;
            if (n == 0) {
                cnt = 0;
            }
            if (cnt == 0) {
                tbl = fn_802D6A9C();
                if (cnt < 8) {
                    tbl = tbl + 0xcc;
                } else {
                    tbl = tbl + 0xdc;
                }
                f2 = ((f32*)tbl)[0];
                f3 = ((f32*)tbl)[1];
            }
            if (tgt != 0 && (*(s32*)(tgt + 0x1a0) != 0x46495245 || ((*(u32*)(tgt + 0x90) >> 6) & 3) != 1) &&
                tgt[0xc4] == 0) {
                sp = *(u32*)(this_ + 0x90);
                ax = (sp >> 5) & 0x1f8;
                az = (sp >> 13) & 0x1f8;
                n = (sp >> 24) & 7;
                cnt = n + 7;
                if (n == 0) {
                    cnt = 0;
                }
                pv[2] = lbl_805404C0;
                pv[1] = lbl_805404C0 + (f32)ax + f3;
                pv[0] = lbl_805404C0 + (f32)az + f2;
                fn_801F349C(tgt, cnt, pv);
            }
        }
    } else {
        *(s32*)(this_ + 0x248) = *(s32*)(this_ + 0x248) - 1;
    }

}

extern "C" void fn_8028BA5C(u8* this_) {
    s32 i;
    this_[0x250] = 1;
    for (i = 0; i < 4; i++) {
        if (fn_80303750(i)) {
            this_[0x250] = 0;
            break;
        }
    }
    if (this_[0x250] == 1) {
        this_[0x234] = fn_8028B850(this_);
    }
    *(f32*)(this_ + 0x240) = (this_[0x234] == 1) ? lbl_805404CC : lbl_805404C0;
    *(s32*)(this_ + 0x244) = (this_[0x234] == 1) ? 0x6e : 0;
}

extern "C" void fn_8028BB14(u8* this_) {
    f32 f31, f30, f2, f3;
    u32 spawn, a, b, seed;
    s32 n, cnt, v;
    u8* tbl;
    f32* pt;
    f32 fz;

    *(f32*)(this_ + 0x64) = *(f32*)(this_ + 0x60) = lbl_805404F0;
    *(f32*)(this_ + 0x6c) = *(f32*)(this_ + 0x68) = lbl_805404D8;
    *(s32*)(this_ + 0x108) = 0;
    *(s32*)(this_ + 0x230) = 0;
    *(s32*)(this_ + 0xb0) = 3;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x248) = 0x78;
    this_[0x234] = 0;
    this_[0x251] = 0;
    *(s32*)(this_ + 0x274) = 0;
    *(s32*)(this_ + 0x278) = 0;

    v = (*(u32*)(this_ + 0x90) >> 24) & 7;
    n = v + 7;
    if (v == 0) {
        n = v;
    }
    tbl = fn_802D6A9C();
    pt = (f32*)((n < 8) ? tbl + 0xcc : tbl + 0xdc);
    f31 = pt[0];
    f30 = pt[1];

    v = (*(u32*)(this_ + 0x90) >> 24) & 7;
    n = v + 7;
    if (v == 0) {
        n = v;
    }
    if (n != 0) {
        n = *(s32*)(this_ + 4);
        tbl = fn_802D6A9C();
        pt = (f32*)((n < 8) ? tbl + 0xcc : tbl + 0xdc);
        f2 = pt[0];
        f3 = pt[1];
    } else {
        f3 = lbl_805404C0;
        f2 = f3;
    }

    spawn = *(u32*)(this_ + 0x90);
    a = (spawn >> 13) & 0x1F8;
    if (a == 0 && ((spawn >> 5) & 0x1F8) == 0) {
        fz = lbl_805404C0;
        *(f32*)(this_ + 0x268) = f31 + (*(f32*)(this_ + 0xc) - f2);
        *(f32*)(this_ + 0x26c) = f30 + (*(f32*)(this_ + 0x10) - f3);
        *(f32*)(this_ + 0x270) = fz;
    } else {
        b = (spawn >> 5) & 0x1F8;
        *(f32*)(this_ + 0x268) = lbl_805404D8 + ((f32)a + f31);
        *(f32*)(this_ + 0x26c) = lbl_805404D8 + ((f32)b + f30);
        *(f32*)(this_ + 0x270) = lbl_805404C0;
    }

    this_[0x252] = 0;
    this_[0x253] = 0;
    this_[0x254] = 0;
    this_[0x255] = 0;
    *(s32*)(this_ + 0x258) = 0;
    this_[0x250] = 0;
    this_[0x260] = 0;
    this_[0x262] = 0;
    this_[0x263] = 1;
    this_[0x264] = 0;
    *(s32*)(this_ + 0x24c) = (*(u32*)(this_ + 0x90) >> 4) & 0xF;
    *(s32*)(this_ + 0x25c) = *(u32*)(this_ + 0x90) & 7;
    if (*(s32*)(this_ + 0x25c) == 6) {
        cnt = fn_80138A30(lbl_8053AAF8);
        if (cnt < 2) {
            *(s32*)(this_ + 0x25c) = 0;
        } else {
            u8* g = (u8*)lbl_8053AAF8;
            seed = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
            *(u32*)(g + 0xb4) = seed;
            seed = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
            *(s32*)(this_ + 0x25c) = (s32)((f32)cnt * (*(f32*)&seed - lbl_805404CC)) + 1;
        }
    } else if (*(s32*)(this_ + 0x25c) == 5) {
        this_[0x260] = 1;
    }
    if (*(s32*)(this_ + 0x16c) == -1) {
        (*(void (***)(u8*))this_)[4](this_);
    }
}

extern "C" void* fn_8028BDD0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A7960;
        fn_801EE434(*(void**)((u8*)this_ + 0x274));
        fn_801EE434(*(void**)((u8*)this_ + 0x278));
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}
