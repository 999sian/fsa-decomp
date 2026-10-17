

extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_801EE434(void);
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(int a, int b);
extern char lbl_804AE678[];
extern "C" void __dt__5ActorFv(void* p, int how);
extern "C" void fn_80375970(int param_1) {
    if (*(unsigned int*)(param_1 + 0x230) != 0) {
        void* emitter_mgr = fn_8013C824();
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(
            *(int*)((char*)emitter_mgr + 0xc),
            *(unsigned int*)(param_1 + 0x230)
        );
        *(unsigned int*)(param_1 + 0x230) = 0;
    }
    *(char*)(param_1 + 0x11c) = 0;
}

extern "C" void* fn_80375DBC(void* param_1, short param_2) {
    if (param_1 != 0) {
        *(void**)param_1 = (void*)lbl_804AE678;
        void* val = *(void**)((char*)param_1 + 0x230);
        if (val != 0) {
            ((void (*)(void*))fn_801EE434)(val);
            *(void**)((char*)param_1 + 0x230) = 0;
        }
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_801F856C(void);
extern "C" void* fn_802D6A9C(void);
extern "C" unsigned char fn_802D800C(void* mgr, unsigned int kind);
extern "C" void fn_802A3948(void* mgr, void* pos, unsigned int room, int value, int kind);
extern unsigned int lbl_80475138[];
extern void* lbl_8053AC98;
extern "C" void fn_80375E38(int param_1) {
    int count = *(int*)((char*)fn_801F856C() + 0x1008);
    int i = 0;
    int off = 0;
    for (; i < count; i++, off += 4) {
        unsigned int p = *(unsigned int*)((char*)fn_801F856C() + off + 8);
        if (p == 0) {
            continue;
        }
        unsigned int type = *(unsigned int*)(p + 0x1a0);
        if (type != 0x53575434 && type != 0x4c4f5357) {
            continue;
        }
        if (*(int*)(param_1 + 0x170) != *(int*)(p + 0x170)) {
            continue;
        }
        unsigned int bits = *(unsigned int*)(p + 0x90);
        unsigned int* shift = lbl_80475138;
        unsigned int kind = bits >> 27;
        int j = 0;
        for (; j < 4; j++, shift++) {
            if (*(unsigned int*)(param_1 + 0x248) == ((bits >> *shift) & 0x1f)) {
                *(unsigned int*)(param_1 + 0x254) = kind;
                void* mgr = fn_802D6A9C();
                if (fn_802D800C(mgr, *(unsigned int*)(param_1 + 0x254))) {
                    fn_802A3948(lbl_8053AC98, (void*)(param_1 + 0xc), 0, *(int*)(param_1 + 4), 0x35);
                    *(unsigned int*)(param_1 + 0x234) = 2;
                    break;
                }
            }
        }
    }
}

extern void* lbl_8053AAF8;
extern "C" unsigned char fn_802D7888(void* mgr, unsigned int id);
extern "C" unsigned char fn_80138A30(void* game);
extern "C" void fn_802A3884(void* mgr, void* pos, unsigned int room, int value, int kind);
extern "C" void fn_80375F3C(int param_1) {
    unsigned char cVar5;
    int bVar2;
    void* mgr;

    *(float*)(param_1 + 0xc) += 8.0f;
    *(float*)(param_1 + 0x10) += 8.0f;
    *(float*)(param_1 + 0x3c) = 0.0f;
    *(float*)(param_1 + 0x40) = 0.0f;
    *(float*)(param_1 + 0x44) = 0.0f;
    *(float*)(param_1 + 0x60) = -8.5f;
    *(float*)(param_1 + 0x64) = -8.5f;
    *(float*)(param_1 + 0x68) = 8.5f;
    *(float*)(param_1 + 0x6c) = 8.5f;
    *(float*)(param_1 + 0x80) = -8.0f;
    *(float*)(param_1 + 0x84) = -8.0f;
    *(float*)(param_1 + 0x88) = 8.0f;
    *(float*)(param_1 + 0x8c) = 8.0f;
    *(int*)(param_1 + 0x250) = -1;
    *(unsigned int*)(param_1 + 0x24c) = *(unsigned int*)(param_1 + 0x90) & 0xfff;
    *(unsigned int*)(param_1 + 0x23c) = (*(unsigned int*)(param_1 + 0x90) >> 12) & 7;
    *(unsigned int*)(param_1 + 0x248) = *(unsigned int*)(param_1 + 0x90) >> 27;
    *(unsigned int*)(param_1 + 0x240) = (*(unsigned int*)(param_1 + 0x90) >> 25) & 3;
    *(unsigned int*)(param_1 + 0x238) = 0;
    (**(void (**)(int))(*(int*)param_1 + 0x30))(param_1);
    *(unsigned char*)(param_1 + 0x244) = 0;
    *(unsigned int*)(param_1 + 0x234) = 0;
    *(unsigned int*)(param_1 + 0x230) = 0;

    cVar5 = fn_80138A30(lbl_8053AAF8);
    bVar2 = 0;
    if (*(int*)(param_1 + 0x240) == 0) {
        bVar2 = 1;
    } else if (*(int*)(param_1 + 0x240) == 1) {
        if (cVar5 != 2) {
            bVar2 = 1;
        }
    } else if (*(int*)(param_1 + 0x240) == 2) {
        if (1 < (unsigned char)(cVar5 - 2U)) {
            bVar2 = 1;
        }
    } else if (*(int*)(param_1 + 0x240) == 3) {
        bVar2 = 1;
    }
    if (bVar2 == 1) {
        if (*(int*)(param_1 + 0x23c) >= 3) {
            mgr = fn_802D6A9C();
            if (fn_802D7888(mgr, *(unsigned int*)(param_1 + 0x248)) == 1) {
                fn_802A3948(lbl_8053AC98, (void*)(param_1 + 0xc), 0, *(int*)(param_1 + 4), 0x35);
                ((void (*)(int, int, int))(*(void***)param_1)[12])(param_1, 0xff, 1);
                if (*(int*)(param_1 + 0x23c) == 4) {
                    *(unsigned int*)(param_1 + 0x234) = 2;
                } else {
                    *(unsigned char*)(param_1 + 0x244) = 1;
                }
                return;
            }
        }
        fn_802A3884(lbl_8053AC98, (void*)(param_1 + 0xc), 0, *(int*)(param_1 + 4), 0xac);
    } else {
        fn_802A3948(lbl_8053AC98, (void*)(param_1 + 0xc), 0, *(int*)(param_1 + 4), 0x35);
        ((void (*)(int, int, int))(*(void***)param_1)[12])(param_1, 0xff, 1);
        *(unsigned int*)(param_1 + 0x234) = 2;
        *(unsigned char*)(param_1 + 0x244) = 1;
    }
}

