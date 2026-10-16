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
extern "C" void* fn_80012970(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
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
    if (lbl_802FEBC0 == 0) {
        return 0;
    }
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
    return 0;
}

extern "C" int fn_80012D0C(int* p) {
    if (*p != 0) {
        *p = *p - 1;
    }
    return *p;
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

