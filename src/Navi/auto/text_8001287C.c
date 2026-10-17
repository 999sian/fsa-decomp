#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8001287c-0x80013a30 (29 functions). split_file divides it into the game's real files.

typedef struct ThreadBlock {
    u8 thread[0x320];
    u8 stack[0x1800];
    u8 param[1];
} ThreadBlock;

struct node_class;
void cLs_SingleCut(node_class*);

struct UnkVtbl {
    void* unk0;
    void* unk4;
    void* unk8;
    int (*fnC)();
};

struct UnkObj {
    u8 pad[0x10];
    UnkVtbl* vt;
};

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_801E0D40(void*, void*, s32, s32);
extern "C" char lbl_80204AC4[];
extern "C" char lbl_80204AEC[];
extern "C" char lbl_80204AF8[];
extern "C" char lbl_802FB908[];
extern "C" char lbl_802FB90C[];
extern "C" u32 fn_8000F6A0(void);
extern "C" u32 fn_8016028C(u32, u32, u32, u32);
extern "C" void* fn_8011FD10(void);
extern "C" void fn_8011FD18(void*, void*, s32, void*, void*);
extern "C" void fn_80007AB8(void*, s32, void*);
extern "C" u32 fn_8016076C(u32, u16);
extern "C" void* fn_80012970(void* ptr, s16 param_2);
extern "C" void* fn_80012900(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80204AC4;
        fn_801E0D40((char*)ptr + 4, (void*)fn_80012970, 0x20, 0x40);
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_80012970(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" u32 fn_801C027C(void);
extern "C" void fn_8015D1F4(void* p, s32 a, s32 b);
extern "C" void fn_8015D29C(void* p, s32 a);
extern "C" void fn_80159BA4(s32 a);
extern "C" void fn_80012E50(void* p);
extern "C" void fn_8011B978(void);
extern "C" void fn_8011C280(u32 a);
extern "C" s32 lbl_802FEBC0;
extern "C" s32 lbl_802FEBC8;
extern "C" s32 lbl_802FB900;
extern "C" u8 lbl_802FF2E9;
extern "C" void (*lbl_802FF2D4)(s32);
extern "C" s32 lbl_802FF2D8;
extern "C" s32 lbl_802FF340;
extern "C" void fn_80120640(s32 a);
extern "C" void fn_80013B48(void);
extern "C" u32 fn_801D9F00(void);
extern "C" void fn_801D9EB4(void);
extern "C" void fn_801DAFF4(void);
extern "C" void fn_801DB1BC(void);
extern "C" void fn_801DB478(void);
extern "C" void fn_801200F0(void);
extern "C" void fn_801DB70C(s32 a);
extern "C" void fn_801CC8B4(s32 a);
extern "C" void fn_801CC710(void);
extern "C" void fn_801CBA20(void);
extern "C" BOOL OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(BOOL level);
extern "C" void OSCancelThread(void* thread);
extern "C" void LCDisable(void);
extern "C" void OSResetSystem(BOOL reset, u32 resetCode, BOOL forceMenu);
extern "C" void fn_800129AC(u8* self) {
    self[0x18] = 0;
    *(u32*)(self + 0x1c) = 0;
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_800129BC(s32 param_1, s32 param_2, s32 param_3) {
    u32 uVar2;
    BOOL uVar3;
    fn_80120640(lbl_802FF340);
    fn_80013B48();
    fn_8011B978();
    uVar2 = fn_801D9F00();
    uVar3 = OSDisableInterrupts();
    if (uVar2 != fn_801C027C()) {
        OSCancelThread((void*)uVar2);
        fn_801D9EB4();
    }
    fn_801DAFF4();
    fn_801DB1BC();
    fn_801DB478();
    OSRestoreInterrupts(uVar3);
    fn_801200F0();
    fn_801DB70C(0);
    fn_801CC8B4(1);
    fn_801CC710();
    fn_801CBA20();
    LCDisable();
    OSResetSystem(param_1, param_2, param_3);
    do {
        fn_801CBA20();
    } while (true);
}
#pragma pop

extern "C" void fn_80012A60(s32 param_1) {
    if (lbl_802FEBC0 == 0) {
        if (param_1 == -1) {
            fn_8011B978();
            fn_8011C280(0xf0000000);
        } else if (lbl_802FEBC8 != 0) {
            lbl_802FF2E9 = 0;
            lbl_802FF2D4 = fn_80012A60;
            lbl_802FF2D8 = 0;
            return;
        } else {
            lbl_802FB900 = param_1;
            lbl_802FEBC8 = 1;
            fn_8011B978();
            fn_8011C280(0xf0000000);
        }
        lbl_802FEBC0 = 1;
    }
}

extern "C" s32 lbl_802FEBC0;
extern "C" s32 lbl_802FEBD0;
extern "C" s32 lbl_802FED88;
extern "C" u8 lbl_802B7CA0[];
extern "C" void fn_8002F330(s32);
extern "C" BOOL fn_80019930(void);
extern "C" void fn_8001A454(void*, s32, s32, s32);
extern "C" void fn_8001A4F4(s32, s32);
extern "C" void fn_801C1174(void*);
extern "C" BOOL fn_80012AE8(void* self) {
    if (lbl_802FEBC0 != 0) {
        if (lbl_802B7CA0[0x344c] == 0) {
            fn_8002F330(0x1e);
            lbl_802FEBD0 = 0x3c;
            if (fn_80019930() == 0) {
                fn_8001A454(self, 1, 0, 0x12c);
                fn_8001A4F4(1, 0);
            }
            lbl_802FED88 = 0;
            lbl_802B7CA0[0x344c] = 1;
            return 1;
        }
    }
    return 0;
}

extern "C" int fn_80012D0C(int* p) {
    if (*p != 0) {
        *p = *p - 1;
    }
    return *p;
}

extern "C" BOOL OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(BOOL level);
extern "C" void OSCancelThread(void* thread);
extern "C" void LCDisable(void);
extern "C" void OSResetSystem(BOOL reset, u32 resetCode, BOOL forceMenu);
extern "C" void* fn_80012D28(void* param_1) {
    u8 auStack_80[0x80];
    fn_8015D1F4(auStack_80, fn_801C027C(), 0);
    fn_8015D29C(auStack_80, -1);
    fn_80159BA4(0);
    fn_80012E50(param_1);
    return nullptr;
}

extern "C" int fn_801C0884(void*, void*, void*, void*, u32, s32, u16);
extern "C" int fn_801C0EEC(void*);
extern "C" void* fn_80012D28(void*);
extern "C" u8 lbl_802A05C0[];
extern "C" void fn_80012D84(s32 prio) {
    ThreadBlock* p = (ThreadBlock*)lbl_802A05C0;
    fn_801C0884(&p->thread, (void*)fn_80012D28, &p->param, (void*)((u32)p->stack + sizeof(p->stack)), sizeof(p->stack), prio, 1);
    fn_801C0EEC(&p->thread);
}

extern "C" void fn_80012DE0(void) {
    fn_801C1174(lbl_802A05C0);
}

extern "C" char lbl_80204E88[];
extern "C" void* fn_80012E08(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)((char*)ptr + 0x10) = lbl_80204E88;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_801BDEE4(void*, int, int);
extern "C" void fn_801BDE1C(void*, int, int);
extern "C" void fn_801BE3A0(void*);
extern "C" void fn_801BE47C(void*);
extern "C" void fn_800074C0(const char*, ...);
extern "C" char lbl_80204B20[];
extern "C" char lbl_80204E78[];
extern "C" void* fn_80012F04(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)((char*)ptr + 0x10) = lbl_80204E78;
        if (ptr != nullptr) {
            *(void**)((char*)ptr + 0x10) = lbl_80204E88;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" BOOL fn_80012F60(u8* self) {
    *(u32*)(self + 0x1c) = (*(u32 (**)(u32))(self + 0x14))(*(u32*)(self + 0x18));
    self[0xc] = 1;
    return *(u32*)(self + 0x1c) != 0;
}

extern "C" char lbl_80204E3C[];
extern "C" void* fn_80012FB4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)((char*)ptr + 0x10) = lbl_80204E3C;
        if (ptr != nullptr) {
            *(void**)((char*)ptr + 0x10) = lbl_80204E88;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" char lbl_80204DFC[];
extern "C" void* fn_800132E4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)((char*)ptr + 0x10) = lbl_80204DFC;
        if (ptr != nullptr) {
            *(void**)((char*)ptr + 0x10) = lbl_80204E88;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" char lbl_80204DB8[];
extern "C" void* fn_8001345C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)((char*)ptr + 0x10) = lbl_80204DB8;
        if (ptr != nullptr) {
            *(void**)((char*)ptr + 0x10) = lbl_80204E88;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_8001362C(u8* param_1) {
    u32 mode = 2;
    if (*(u8*)(param_1 + 0x14) == 0) {
        mode = 1;
    }
    u32 t = fn_8000F6A0();
    u32 r = fn_8016028C(*(u32*)(param_1 + 0x18), *(u32*)(param_1 + 0x20), t, mode);
    *(u32*)(param_1 + 0x1c) = r;
    *(u8*)(param_1 + 0xc) = 1;
    return (-r | r) >> 31;
}

extern "C" char lbl_80204D78[];
extern "C" void* fn_800136A8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)((char*)ptr + 0x10) = lbl_80204D78;
        if (ptr != nullptr) {
            *(void**)((char*)ptr + 0x10) = lbl_80204E88;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_80013704(u8* param_1) {
    if (*(u32*)(param_1 + 0x18) == 0) {
        fn_8011FD18(fn_8011FD10(), lbl_80204AF8, 0x49a, lbl_802FB908, lbl_80204AF8 + 0x198);
        fn_80007AB8(lbl_80204AF8, 0x49a, lbl_802FB90C);
    }
    u32 r = fn_8016076C(*(u32*)(param_1 + 0x18), *(u16*)(param_1 + 0x1c));
    *(u32*)(param_1 + 0x14) = r;
    if (*(u32*)(param_1 + 0x14) == 0) {
        fn_800074C0(lbl_80204AF8 + 0x1a4);
    }
    *(u8*)(param_1 + 0xc) = 1;
    return (-*(u32*)(param_1 + 0x14) | *(u32*)(param_1 + 0x14)) >> 31;
}

extern "C" char lbl_80204D3C[];
extern "C" void* fn_8001391C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)((char*)ptr + 0x10) = lbl_80204D3C;
        if (ptr != nullptr) {
            *(void**)((char*)ptr + 0x10) = lbl_80204E88;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

