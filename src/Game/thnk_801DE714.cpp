// Game TU 801DE714-801E2540 (THNK). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void fn_801CE694(void* this_);
extern "C" u8 fn_801CD2F8(s32 owner);
extern "C" void* fn_80212AC0(void);
extern "C" void fn_80212AF0(void* registry, void* posPtr);
extern "C" void fn_801CE2BC(void);
extern "C" void fn_8021835C(void* this_);
extern "C" s32 fn_801CCF7C(void);
extern "C" void* fn_801F856C();
extern "C" s32 fn_801F750C(void* mgr, void* a, s32 b);
extern "C" s32 fn_801F7464(void* mgr, void* a, s32 b);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" s32 fn_801CD664(s32 n);
extern "C" u8 fn_801CD2F8(s32 owner);
extern "C" void* fn_8023E724(s32 idx);
extern "C" void fn_801D22DC(void* p, s32 a, s32 b, s32 c);
extern "C" void fn_801E1300(void* this_);
extern "C" s32 fn_8023DE58(s32 idx);
extern "C" u8 fn_801CD290(s32 owner);
extern "C" s32 fn_801CD354(s32 owner);
extern "C" u8 fn_801E3250(s32 owner, s32 flag);
extern "C" u8 fn_801D21F0(void* p);
extern "C" void fn_8022FE80(s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" u8 fn_801E2F40(void* this_);
extern "C" void fn_801E2EE4(void* this_);
extern "C" void fn_801F7AB8(void* base, s32 a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern f32 lbl_8053F4A4;
extern f32 lbl_8053F480;
extern void* lbl_804A51E4[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern u8 lbl_8050EC80[];
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_801D22DC(void* p, s32 a, s32 b, s32 c);
extern "C" void fn_801CE4BC(void* this_);
extern "C" void fn_801D0F40(void* this_);
extern "C" void fn_801E1E08(void* this_);
extern "C" void fn_801D22A0(void* p, s32 a, s32 b);
extern "C" void* fn_8023E724(s32 idx);
extern "C" void fn_8020D2AC(void* this_);
extern "C" u8 fn_80218538(void* this_);
extern "C" void fn_801F0E34(void* this_, u32 a, s32 b);
extern "C" void fn_8020D16C(void* this_);
extern "C" void fn_8020CFC4(void* this_);
extern "C" s32 fn_801CD664(s32 kind);
extern f32 lbl_8053F4A8;
extern f32 lbl_8053F4BC;
extern f32 lbl_8053F490;
extern f32 lbl_8053F4C0;
extern f32 lbl_8053F4C4;

extern "C" void fn_801DE714(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x248);
    if (state == 0xa) {
        fn_801CE694(this_);
    }
}

extern "C" void fn_801DE740(void* this_) {
    u8 flag = 0;
    s32 state = *(s32*)((char*)this_ + 0x248);
    switch (state) {
    case 0xb:
    case 0xc:
        flag = 1;
        break;
    }
    if (flag == 0) {
        return;
    }
    if (fn_801CD2F8(*(s32*)((char*)this_ + 0x4)) != 0) {
        return;
    }
    {
        void* registry = fn_80212AC0();
        fn_80212AF0(registry, (char*)this_ + 0xc);
    }
}

extern "C" void fn_801DE9C0(void* this_) {
    fn_801CE2BC();
    fn_8021835C(this_);
}

extern "C" void fn_801DE9F4(void* this_) {
    char* p = (char*)this_;
    if (*(u16*)(p + 0x2ce) != 0) {
        *(u16*)(p + 0x2ce) = *(u16*)(p + 0x2ce) - 1;
    }
    if (*(u16*)(p + 0x2ce) == 0) {
        if (*(s32*)(p + 0x248) == 7) {
            switch (*(s32*)(p + 0x278)) {
            case 0xf:
            case 0x10:
                fn_801D22DC(p + 0x270, *(s32*)(p + 0x98), 2, 0);
                return;
            }
        }
        fn_801CE4BC(this_);
    }
}

extern "C" void fn_801E1594(void* this_, s32 state);
extern "C" s32 fn_801F750C(void* mgr, void* a, s32 b);
extern "C" s32 fn_801F7464(void* mgr, void* a, s32 b);
extern "C" s32 fn_801F732C(void* mgr, void* a, f32 f, void* p5, void* p6, s32 c);
extern "C" u8 fn_801CC910(void* obj);
extern "C" u8 fn_801CC960(void* obj);
extern "C" u8 fn_801CC9B0(void* obj);
extern f32 lbl_8053F4B4;
extern "C" void fn_801E1300(void* this_) {
    char* p = (char*)this_;
    u8 flag = 0;
    s32 idx;
    void* obj;

    idx = *(s32*)(p + 0x2ac);
    if (idx >= 0) {
        obj = fn_801F666C(fn_801F856C(), idx);
        if (obj == 0 || fn_801CC910(obj) == 0) {
            flag = 1;
        }
    } else if ((idx = *(s32*)(p + 0x2b0)) >= 0) {
        obj = fn_801F666C(fn_801F856C(), idx);
        if (obj == 0 || fn_801CC960(obj) == 0) {
            flag = 1;
        }
    } else if ((idx = *(s32*)(p + 0x2b4)) >= 0) {
        obj = fn_801F666C(fn_801F856C(), idx);
        if (obj == 0 || fn_801CC9B0(obj) == 0) {
            flag = 1;
        }
    } else {
        *(s32*)(p + 0x2ac) = fn_801F750C(fn_801F856C(), *(void**)(p + 4), *(s32*)(p + 0x2b8));
        if (*(s32*)(p + 0x2ac) >= 0) {
            *(s32*)(p + 0x2b0) = -1;
            *(s32*)(p + 0x2b4) = -1;
        } else {
            *(s32*)(p + 0x2b0) = fn_801F7464(fn_801F856C(), *(void**)(p + 4), -1);
            if (*(s32*)(p + 0x2b0) >= 0) {
                *(s32*)(p + 0x2b4) = -1;
            } else {
                *(s32*)(p + 0x2b4) = fn_801F732C(fn_801F856C(), *(void**)(p + 4), lbl_8053F4B4, p + 0xc, p + 0xc, *(s32*)(p + 0x2b8));
            }
        }
    }
    if (flag == 0) {
        return;
    }
    *(s32*)(p + 0x2ac) = fn_801F750C(fn_801F856C(), *(void**)(p + 4), *(s32*)(p + 0x2b8));
    if (*(s32*)(p + 0x2ac) >= 0) {
        *(s32*)(p + 0x2b0) = -1;
        *(s32*)(p + 0x2b4) = -1;
    } else {
        *(s32*)(p + 0x2b0) = fn_801F7464(fn_801F856C(), *(void**)(p + 4), -1);
        if (*(s32*)(p + 0x2b0) >= 0) {
            *(s32*)(p + 0x2b4) = -1;
        } else {
            *(s32*)(p + 0x2b4) = fn_801F732C(fn_801F856C(), *(void**)(p + 4), lbl_8053F4B4, p + 0xc, p + 0xc, *(s32*)(p + 0x2b8));
        }
    }
    {
        s32 state = *(s32*)(p + 0x248);
        u8 hit = 0;
        if (state == 7) {
            goto done;
        }
        if (state < 7) {
            if (state == 0) {
                goto done;
            }
        } else if (state < 0x13) {
            if (state >= 0xf) {
                goto done;
            }
        }
        if (*(u32*)(p + 0x230) & 0x4000 || *(u16*)(p + 0x2cc) != 0) {
            goto done;
        }
        {
            s32 s = *(s32*)(p + 0x278);
            u8 near = 0;
            if (s < 0xd) {
                if (s < 3 && s >= 0) {
                    near = 1;
                }
            } else if (s < 0x11) {
                near = 1;
            }
            if (near != 0) {
                if (*(u32*)(p + 0x230) & 0x20000) {
                    if (*(u32*)(p + 0x230) & 0x100000) {
                        hit = 1;
                    }
                } else if (*(s32*)(p + 0x2bc) < 0) {
                    hit = 1;
                }
            }
        }
        if (hit) {
            fn_801E1594(this_, 7);
        }
    done:;
    }
}

extern "C" void fn_801E1594(void* this_, s32 state) {
    char* p = (char*)this_;
    switch (state) {
    case 0:
        fn_801E1E08(this_);
        break;
    case 1:
        if (*(s32*)(p + 0x248) == 0 && state == 1) {
            f32 y;
            f32 x;
            s32 idx;
            u8 flag;
            void* obj;
            char* rec;
            char* field;
            if (*(u32*)(p + 0x230) & 0x20000) {
                x = ((f32*)fn_8023E724(*(s32*)(p + 0x2a8)))[0];
                y = ((f32*)fn_8023E724(*(s32*)(p + 0x2a8)))[1];
            } else {
                obj = 0;
                idx = *(s32*)(p + 0x2ac);
                if (idx >= 0) {
                    obj = fn_801F666C(fn_801F856C(), idx);
                }
                if (obj == 0) {
                    idx = *(s32*)(p + 0x2b0);
                    if (idx >= 0) {
                        obj = fn_801F666C(fn_801F856C(), idx);
                    }
                }
                if (obj == 0) {
                    idx = *(s32*)(p + 0x2b4);
                    if (idx >= 0) {
                        obj = fn_801F666C(fn_801F856C(), idx);
                    }
                }
                x = *(f32*)((char*)obj + 0xc);
                y = *(f32*)((char*)obj + 0x10);
            }
            idx = *(s32*)(p + 0x4);
            flag = 0;
            rec = (char*)fn_802D6A9C();
            field = (idx < 8) ? (rec + 0xcc) : (rec + 0xdc);
            if (x < lbl_8053F4A8 * (*(f32*)field + *(f32*)(field + 0x8))) {
                flag = 1;
            }
            if (flag != 0) {
                idx = *(s32*)(p + 0x4);
                rec = (char*)fn_802D6A9C();
                field = (idx < 8) ? (rec + 0xcc) : (rec + 0xdc);
                *(f32*)(p + 0xc) = lbl_8053F4A4 + *(f32*)(field + 0x8);
                *(s32*)(p + 0x98) = 1;
            } else {
                idx = *(s32*)(p + 0x4);
                rec = (char*)fn_802D6A9C();
                field = (idx < 8) ? (rec + 0xcc) : (rec + 0xdc);
                *(f32*)(p + 0xc) = *(f32*)field - lbl_8053F4A4;
                *(s32*)(p + 0x98) = 0;
            }
            *(f32*)(p + 0x10) = y;
            *(f32*)(p + 0x14) = lbl_8053F4A4;
            *(f32*)(p + 0x2c4) = *(f32*)(p + 0xc);
            *(f32*)(p + 0x2c8) = *(f32*)(p + 0x10);
            *(s32*)(p + 0xb0) = 0x51303;
            *(s32*)(p + 0x250) = -1;
            if (*(s32*)(p + 0x2bc) >= 0) {
                *(f32*)(p + 0x258) = lbl_8053F490;
            } else if (*(u32*)(p + 0x230) & 0x4000) {
                *(f32*)(p + 0x258) = lbl_8053F490;
            } else {
                *(f32*)(p + 0x258) = lbl_8053F4BC;
            }
            if (*(s32*)(p + 0x248) == 0xd) {
                fn_801D22DC(p + 0x270, *(s32*)(p + 0x98) + 0xd, 0, 0);
            } else {
                fn_801D22A0(p + 0x270, *(s32*)(p + 0x98), 2);
            }
        } else {
            *(s32*)(p + 0x250) = -1;
            *(f32*)(p + 0x258) = lbl_8053F4BC;
            if (*(s32*)(p + 0x2ac) >= 0) {
                fn_801D22DC(p + 0x270, *(s32*)(p + 0x98) + 0xf, 2, 0);
            } else {
                fn_801D22A0(p + 0x270, *(s32*)(p + 0x98), 2);
            }
        }
        break;
    case 2:
        *(s32*)(p + 0x250) = -1;
        *(f32*)(p + 0x258) = lbl_8053F480;
        fn_801D22DC(p + 0x270, 2, 0, 0);
        break;
    case 3:
        *(s32*)(p + 0x250) = fn_801CD664(1) + 0x5a;
        *(f32*)(p + 0x254) = lbl_8053F480;
        *(f32*)(p + 0x258) = lbl_8053F480;
        *(u16*)(p + 0x2ce) = 0x2d;
        fn_8020D2AC(this_);
        if (!(*(u32*)(p + 0x230) & 0x4000) && fn_80218538(this_)) {
            fn_801F0E34(this_, 0x40070, 0);
        }
        break;
    case 4:
        *(s32*)(p + 0x250) = -1;
        *(f32*)(p + 0x258) = lbl_8053F480;
        fn_801D22DC(p + 0x270, *(s32*)(p + 0x98) + 3, 0, 0);
        break;
    case 5:
        *(s32*)(p + 0x250) = -1;
        *(f32*)(p + 0x258) = lbl_8053F480;
        fn_801D22DC(p + 0x270, 5, 0, 0);
        break;
    case 6:
        *(s32*)(p + 0x250) = -1;
        *(f32*)(p + 0x258) = lbl_8053F480;
        fn_801D22DC(p + 0x270, 6, 0, 0);
        break;
    case 7:
        fn_8020D16C(this_);
        *(s32*)(p + 0x250) = -1;
        *(f32*)(p + 0x258) = lbl_8053F480;
        fn_801D22DC(p + 0x270, 7, 0, 0);
        break;
    case 8:
        *(s32*)(p + 0x98) = 2;
        *(s32*)(p + 0x250) = fn_801CD664(0x259) + 0x12c;
        *(f32*)(p + 0x258) = lbl_8053F480;
        fn_801D22DC(p + 0x270, *(s32*)(p + 0x98) + 8, 0, 0);
        break;
    case 9:
        *(s32*)(p + 0x250) = -1;
        *(f32*)(p + 0x258) = lbl_8053F480;
        fn_801D22DC(p + 0x270, 0xc, 0, 0);
        break;
    case 10:
        fn_8020CFC4(this_);
        *(f32*)(p + 0x3c) = lbl_8053F480;
        *(f32*)(p + 0x40) = lbl_8053F480;
        *(f32*)(p + 0x60) = lbl_8053F4C0;
        *(f32*)(p + 0x64) = lbl_8053F4C0;
        *(f32*)(p + 0x68) = lbl_8053F4C4;
        *(f32*)(p + 0x6c) = lbl_8053F4C4;
        *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
        *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
        *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
        *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
        *(s32*)(p + 0xb0) = 0;
        *(s32*)(p + 0x250) = -1;
        *(f32*)(p + 0x254) = lbl_8053F480;
        *(f32*)(p + 0x258) = lbl_8053F480;
        fn_801D22DC(p + 0x270, 6, 0, 0);
        break;
    case 11:
        *(s32*)(p + 0x250) = -1;
        *(f32*)(p + 0x254) = lbl_8053F480;
        *(f32*)(p + 0x258) = lbl_8053F480;
        fn_801D22A0(p + 0x270, *(s32*)(p + 0x98), 2);
        break;
    case 0x12:
        fn_801F0E34(this_, 0x5001d, 0);
        *(s32*)(p + 0x24c) = 0;
        *(s32*)(p + 0x248) = state;
        break;
    }
}

extern "C" void* fn_801F856C(void);
extern "C" void detach__5ActorFv(void* this_);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" s32 fn_8032D564(void* obj, u32 arg);
extern "C" void fn_8021FDB8(void* this_);
extern "C" void fn_801E1AB4(void* this_, char flag) {
    char* p = (char*)this_;
    char bVar1 = 0;
    f32 pos[3];
    u32 uVar5;
    if (flag != 0) {
        pos[0] = *(f32*)(p + 0xc);
        pos[1] = *(f32*)(p + 0x10);
        pos[2] = *(f32*)(p + 0x14);
        uVar5 = 2;
        bVar1 = 1;
    } else {
        char* obj = 0;
        s32 idx = *(s32*)(p + 0x2ac);
        if (idx >= 0) {
            obj = (char*)fn_801F666C(fn_801F856C(), idx);
        }
        if (obj == 0 && *(s32*)(p + 0x2b0) >= 0) {
            obj = (char*)fn_801F666C(fn_801F856C(), *(s32*)(p + 0x2b0));
        }
        if (obj == 0 && *(s32*)(p + 0x2b4) >= 0) {
            obj = (char*)fn_801F666C(fn_801F856C(), *(s32*)(p + 0x2b4));
        }
        pos[0] = *(f32*)(obj + 0xc);
        pos[1] = *(f32*)(obj + 0x10);
        pos[2] = *(f32*)(obj + 0x14);
        s32 state = *(s32*)(obj + 0x230);
        uVar5 = *(u32*)(obj + 0x90);
        if (state == 0 || (u32)(state - 0xf) <= 1 || (u32)(state - 1) <= 1 || state == 9 || state == 0xd) {
            detach__5ActorFv(obj);
        }
        if (*(char*)(obj + 0x11c) == 0) {
            bVar1 = 1;
        }
    }
    if (bVar1) {
        *(u32*)(p + 0x230) &= 0xffff7fff;
        *(s32*)(p + 0x2bc) = Actor_CreateByID(fn_801F856C(), 0x52555059, *(u32*)(p + 4), pos, (uVar5 & 0xffff) | 0x10000, -1, -1);
        if (*(s32*)(p + 0x2bc) >= 0) {
            if (flag == 0 && *(s32*)(p + 0x2b0) >= 0) {
                *(u32*)(p + 0x230) |= 0x8000;
            }
            char* obj = (char*)fn_801F666C(fn_801F856C(), *(s32*)(p + 0x2bc));
            if (obj != 0) {
                obj[0x194] = 1;
                *(s32*)(p + 0x2c0) = fn_8032D564(obj, *(u32*)(obj + 0x90) & 0xff);
                if (flag != 0) {
                    fn_8021FDB8(this_);
                    f32 one = 1.0f;
                    f32 negOne = -1.0f;
                    *(f32*)(obj + 0x60) = one;
                    *(f32*)(obj + 0x64) = one;
                    *(f32*)(obj + 0x68) = negOne;
                    *(f32*)(obj + 0x6c) = negOne;
                    *(f32*)(obj + 0x70) = one;
                    *(f32*)(obj + 0x74) = one;
                    *(f32*)(obj + 0x78) = negOne;
                    *(f32*)(obj + 0x7c) = negOne;
                }
            }
        }
        *(s32*)(p + 0x2ac) = -1;
        *(s32*)(p + 0x2b0) = -1;
        *(s32*)(p + 0x2b4) = -1;
    }
}

extern "C" bool fn_801E1D7C(void* thisObj) {
	s32 v = *(s32*)((char*)thisObj + 0x248);
	return v < 0xd && v >= 0xb;
}

extern "C" bool fn_801E1D9C(void* thisObj) {
	s32 v = *(s32*)((char*)thisObj + 0x278);
	bool result = false;
	if (v == 2) { result = true; }
	return result;
}

static inline u8 thnk_isIdleSub(void* this_) {
    u8 r = 0;
    switch (*(s32*)((char*)this_ + 0x278)) {
    case 0: case 1: case 2:
    case 0xd: case 0xe: case 0xf: case 0x10:
        r = 1;
    }
    return r;
}

extern "C" u8 fn_801E1CF8(void* this_) {
    char* p = (char*)this_;
    u8 r = 0;
    switch (*(s32*)(p + 0x248)) {
    case 0:
    case 0xf: case 0x10: case 0x11: case 0x12:
        break;
    default:
        if (!(*(u32*)(p + 0x230) & 0x80000) && *(u16*)(p + 0x2cc) == 0 && thnk_isIdleSub(this_)) {
            r = 1;
        }
    }
    return r;
}

extern "C" u8 fn_801E1DB4(void* this_) {
    return thnk_isIdleSub(this_);
}

extern "C" s32 fn_801CD664(s32 kind);

extern "C" s32 fn_801E1DE8(void* this_) {
    return fn_801CCF7C();
}

extern "C" void fn_801E1E08(void* this_) {
    extern u8 lbl_8050EC80[];
    extern f32 lbl_8053F4A4;
    extern f32 lbl_8053F4C0;
    extern f32 lbl_8053F4C4;
    extern f32 lbl_8053F4C8;
    extern f32 lbl_8053F480;
    char* p = (char*)this_;
    if (*(s32*)(p + 0x2bc) >= 0) {
        if ((*(volatile u32*)(p + 0x230) & 0x80000) == 0) {
            *(u32*)(p + 0x230) |= 0x40000;
        }
        if (*(s32*)(p + 0x2bc) >= 0) {
            s32 n = *(s32*)(p + 0x2c0);
            if (n > 0) {
                if ((*(u32*)(p + 0x230) & 0x80000) == 0) {
                    char* e = (char*)lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 200;
                    *(s32*)(e + 0x2c) += n;
                    e = (char*)lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 200;
                    if (*(s32*)(e + 0x2c) < 0) {
                        *(s32*)(e + 0x2c) = 0;
                    }
                }
                *(s32*)(p + 0x2c0) = 0;
            }
            void* tmp = fn_801F856C();
            void* obj = fn_801F666C(tmp, *(s32*)(p + 0x2bc));
            if (obj != 0) {
                *(u8*)((char*)obj + 0x11c) = 0;
            }
            *(s32*)(p + 0x2bc) = -1;
        }
    }
    *(s32*)(p + 0x4) = 0;
    *(s32*)(p + 0x98) = 0;
    s32 kind = *(volatile s32*)(p + 0x4);
    char* record = (char*)fn_802D6A9C();
    char* field = (kind < 8) ? (record + 0xcc) : (record + 0xdc);
    *(f32*)(p + 0xc) = *(f32*)field - lbl_8053F4A4;
    kind = *(s32*)(p + 0x4);
    record = (char*)fn_802D6A9C();
    field = (kind < 8) ? (record + 0xcc) : (record + 0xdc);
    f32 zero = lbl_8053F4A4;
    f32 sum = lbl_8053F4C8 + *(f32*)(field + 4);
    f32 one = lbl_8053F4C0;
    f32 negOne = lbl_8053F4C4;
    *(f32*)(p + 0x10) = sum;
    *(f32*)(p + 0x14) = zero;
    *(f32*)(p + 0x54) = one;
    *(f32*)(p + 0x58) = one;
    *(f32*)(p + 0x5c) = one;
    *(f32*)(p + 0x60) = one;
    *(f32*)(p + 0x64) = one;
    *(f32*)(p + 0x68) = negOne;
    *(f32*)(p + 0x6c) = negOne;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    *(s32*)(p + 0xb0) = 0;
    *(u32*)(p + 0x230) &= 0xff841fff;
    *(s32*)(p + 0x2a8) = -1;
    *(s32*)(p + 0x2ac) = -1;
    *(s32*)(p + 0x2b0) = -1;
    *(s32*)(p + 0x2b4) = -1;
    *(s32*)(p + 0x2bc) = -1;
    *(s32*)(p + 0x2c0) = 0;
    *(s16*)(p + 0x2cc) = fn_801CD664(0x79) + 0xb4;
    *(s32*)(p + 0x2d0) = -1;
    f32 zero2 = lbl_8053F480;
    *(s16*)(p + 0x2ce) = 0;
    *(s32*)(p + 0x250) = -1;
    *(f32*)(p + 0x254) = zero2;
    *(f32*)(p + 0x258) = zero2;
}

extern "C" void fn_801E2004(void* this_) {
    char* p = (char*)this_;
    void* base = fn_801F856C();
    fn_801F7AB8(base, *(s32*)(p + 0x1a0), *(s32*)(p + 0x198));
    s32 kind = *(s32*)(p + 0x4);
    char* record = (char*)fn_802D6A9C();
    char* field = (kind < 8) ? (record + 0xcc) : (record + 0xdc);
    *(f32*)(p + 0xc) = *(f32*)field - lbl_8053F4A4;
    f32 v1 = *(f32*)(p + 0x10);
    f32 v0 = *(f32*)(p + 0xc);
    *(f32*)(p + 0x2c4) = v0;
    *(f32*)(p + 0x2c8) = v1;
}

extern "C" void fn_801D0ED0(void* this_);
extern "C" s32 fn_801CD664(s32 kind);
extern "C" void fn_801D2608(void* p, void* data, s32 n);
extern f32 lbl_8053F4C0;
extern f32 lbl_8053F4C4;
extern char lbl_804A51A0[];
extern "C" void fn_801E2080(void* this_) {
    char* p = (char*)this_;
    fn_801D0ED0(this_);
    f32 one = lbl_8053F4C0;
    f32 negOne = lbl_8053F4C4;
    *(f32*)(p + 0x80) = one;
    *(f32*)(p + 0x84) = one;
    *(f32*)(p + 0x88) = negOne;
    *(f32*)(p + 0x8c) = negOne;
    *(f32*)(p + 0x60) = one;
    *(f32*)(p + 0x64) = one;
    *(f32*)(p + 0x68) = negOne;
    *(f32*)(p + 0x6c) = negOne;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    *(s32*)(p + 0xb0) = 0;
    *(s32*)(p + 0x98) = 0;
    *(u32*)(p + 0x230) |= 0x300;
    *(s32*)(p + 0x108) = 1000;
    *(s32*)(p + 0x244) = *(s32*)(p + 0x108);
    *(u8*)(p + 0x194) = 1;
    *(s32*)(p + 0x4) = 0;
    *(s16*)(p + 0x2cc) = fn_801CD664(0x3d) + 0x3c;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    f32 zero = lbl_8053F480;
    *(f32*)(p + 0x254) = zero;
    *(f32*)(p + 0x258) = zero;
    fn_801D2608(p + 0x270, lbl_804A51A0, 0x11);
    fn_801D22DC(p + 0x270, 0, 2, 0);
}

extern "C" void* fn_801E2180(void* this_, s16 freeFlag) {
    extern u8 lbl_8050EC80[];
    char* p = (char*)this_;
    if (this_ != 0) {
        *(void**)p = lbl_804A51E4;
        if (*(s32*)(p + 0x2bc) >= 0) {
            s32 n = *(s32*)(p + 0x2c0);
            if (n > 0) {
                if ((*(u32*)(p + 0x230) & 0x80000) == 0) {
                    char* e = (char*)lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 200;
                    *(s32*)(e + 0x2c) += n;
                    e = (char*)lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 200;
                    if (*(s32*)(e + 0x2c) < 0) {
                        *(s32*)(e + 0x2c) = 0;
                    }
                }
                *(s32*)(p + 0x2c0) = 0;
            }
            void* tmp = fn_801F856C();
            void* obj = fn_801F666C(tmp, *(s32*)(p + 0x2bc));
            if (obj != 0) {
                *(u8*)((char*)obj + 0x11c) = 0;
            }
            *(s32*)(p + 0x2bc) = -1;
        }
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_801E22A4(void* this_) {
    char* p = (char*)this_;
    fn_801D0F40(this_);
    *(void**)p = lbl_804A51E4;
    *(s32*)(p + 0x2a8) = -1;
    *(s32*)(p + 0x2ac) = -1;
    *(s32*)(p + 0x2b0) = -1;
    *(s32*)(p + 0x2b4) = -1;
    *(s32*)(p + 0x2b8) = -1;
    *(s32*)(p + 0x2bc) = -1;
    *(s32*)(p + 0x2c0) = 0;
    *(f32*)(p + 0x2c4) = 0.0f;
    *(f32*)(p + 0x2c8) = 0.0f;
    *(u16*)(p + 0x2cc) = 0;
    *(u16*)(p + 0x2ce) = 0;
    *(s32*)(p + 0x2d0) = -1;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
