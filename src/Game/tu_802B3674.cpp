#include "types.h"


extern "C" void* fn_8013C824(void);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D6BF8(void*, s32);
extern "C" void fn_8013A884(u32*);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*, void*);
extern "C" char* fn_8016A3AC(void);
extern "C" void fn_80128C58(u8);
extern "C" void fn_801EE434(void*);
extern "C" u8 fn_802DEBF8(void);
extern "C" void fn_80458FF0(void* obj, u32 id, s32 a, s32 b);
extern void* lbl_8053AF80;
extern "C" u8 fn_802DEBF8(void);
extern "C" void fn_80458FF0(void* obj, u32 id, s32 a, s32 b);
extern void* lbl_8053AF80;
extern "C" void fn_802B3674(void) {
    u32 mode = *(u32*)((char*)lbl_8053AF80 + 0x60);
    u8 busy = fn_802DEBF8();
    if (busy == 0 && mode != 0 && mode != 0x1000021 && mode != 0x1000009 && mode - 0x1000018 > 1 && mode != 0x1000001 && mode != 0x100000d && mode != 0x1000007 && mode != 0x100002e && mode != 0x1000029 && mode != 0x1000024 && mode != 0x100000e) {
        fn_80458FF0(lbl_8053AF80, 0x100000e, 0, 0);
    }
}

extern "C" void fn_80128C58(u8 a);
extern "C" void fn_802B3838(char* p) {
    u32 val;
    *(s32*)(p + 0x310) -= 4;
    if (*(s32*)(p + 0x2e0) > *(s32*)(p + 0x2f0)) {
        *(s32*)(p + 0x2e0) += *(s32*)(p + 0x318);
    } else {
        *(s32*)(p + 0x2e0) = *(s32*)(p + 0x2f0);
    }
    if (*(s32*)(p + 0x2e4) > *(s32*)(p + 0x2f4)) {
        *(s32*)(p + 0x2e4) += *(s32*)(p + 0x31c);
    } else {
        *(s32*)(p + 0x2e4) = *(s32*)(p + 0x2f4);
    }
    if (*(s32*)(p + 0x2e8) > *(s32*)(p + 0x2f8)) {
        *(s32*)(p + 0x2e8) += *(s32*)(p + 0x320);
    } else {
        *(s32*)(p + 0x2e8) = *(s32*)(p + 0x2f8);
    }
    if (*(s32*)(p + 0x310) <= *(s32*)(p + 0x314)) {
        *(s32*)(p + 0x310) = *(s32*)(p + 0x314);
        *(s32*)(p + 0x2e0) = *(s32*)(p + 0x2f0);
        *(s32*)(p + 0x2e4) = *(s32*)(p + 0x2f4);
        *(s32*)(p + 0x2e8) = *(s32*)(p + 0x2f8);
        *(s32*)(p + 0x240) = 9;
    }
    fn_80128C58((u8)*(s32*)(p + 0x310));
    val = *(u32*)(p + 0x2ec) | (*(u32*)(p + 0x2e8) << 8 | (*(u32*)(p + 0x2e0) << 24 | *(u32*)(p + 0x2e4) << 16));
    fn_8013A884(&val);
}

extern "C" void fn_802B394C(char* p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 mode) {
    *(s32*)(p + 0x240) = mode;
    if (mode == 9) {
        *(s32*)(p + 0x2e0) = a;
        *(s32*)(p + 0x2e4) = b;
        *(s32*)(p + 0x2e8) = c;
        *(s32*)(p + 0x2ec) = d;
        *(s32*)(p + 0x310) = e;
        return;
    }
    *(s32*)(p + 0x2f0) = a;
    *(s32*)(p + 0x2f4) = b;
    *(s32*)(p + 0x2f8) = c;
    *(s32*)(p + 0x2ec) = d;
    *(s32*)(p + 0x314) = e;
    *(s32*)(p + 0x318) = (*(s32*)(p + 0x2f0) - *(s32*)(p + 0x2e0)) / 4;
    *(s32*)(p + 0x31c) = (*(s32*)(p + 0x2f4) - *(s32*)(p + 0x2e4)) / 4;
    *(s32*)(p + 0x320) = (*(s32*)(p + 0x2f8) - *(s32*)(p + 0x2e8)) / 4;
    if (*(s32*)(p + 0x310) >= *(s32*)(p + 0x314)) {
        return;
    }
    *(s32*)(p + 0x240) = 0xc;
}

extern "C" void fn_802B39E8(char* p) {
    *(s32*)(p + 0x290) = 0;
    if (*(void**)(p + 0x23c) != NULL) {
        void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(p + 0x23c));
        *(void**)(p + 0x23c) = NULL;
    }
}

extern "C" void fn_802B3A3C(char* p) {
    *(s32*)(p + 0x2b8) = 0;
}

extern "C" void fn_802B3A48(char* p) {
    char* q = fn_8016A3AC();
    q[0x1ee] = 0;
    void* e = *(void**)(p + 0x234);
    if (e != NULL) {
        fn_801EE434(e);
    }
    e = *(void**)(p + 0x238);
    if (e != NULL) {
        fn_801EE434(e);
    }
    e = *(void**)(p + 0x23c);
    if (e != NULL) {
        fn_801EE434(e);
    }
    p[0x11c] = 0;
}

extern "C" void fn_802B3AB4(void) {
}

extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern char lbl_804A8638[];
extern "C" void* fn_802B51C0(void* this_, s16 how) {
    if (this_) {
        *(void**)this_ = lbl_804A8638;
        char* p = fn_8016A3AC();
        p[0x1ee] = 0;
        void* h0 = *(void**)((char*)this_ + 0x234);
        if (h0) {
            fn_801EE434(h0);
        }
        void* h1 = *(void**)((char*)this_ + 0x238);
        if (h1) {
            fn_801EE434(h1);
        }
        void* h2 = *(void**)((char*)this_ + 0x23c);
        if (h2) {
            fn_801EE434(h2);
        }
        void* sub = *(void**)((char*)this_ + 0x230);
        if (sub) {
            if (sub) {
                void* vt = *(void**)((char*)sub + 8);
                ((void (*)(void*, s32))((void**)vt)[12])(sub, 1);
            }
        }
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            ::operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802B5284(char* p) {
    u32 val;
    if (*(s32*)(p + 0x288) == 4) {
        fn_802D6BF8(fn_802D6A9C(), 0);
        *(s32*)(p + 0x288) = 0;
        *(s32*)(p + 0x2e0) = *(s32*)(p + 0x300);
        *(s32*)(p + 0x2e4) = *(s32*)(p + 0x304);
        *(s32*)(p + 0x2e8) = *(s32*)(p + 0x308);
        if (*(u32*)(p + 0x234) != 0) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x234));
            *(s32*)(p + 0x234) = 0;
        }
        if (*(u32*)(p + 0x238) != 0) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x238));
            *(s32*)(p + 0x238) = 0;
        }
        val = *(u32*)(p + 0x2ec) | (*(u32*)(p + 0x2e8) << 8 | (*(u32*)(p + 0x2e0) << 24 | *(u32*)(p + 0x2e4) << 16));
        fn_8013A884(&val);
    }
}

