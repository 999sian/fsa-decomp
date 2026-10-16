#include "types.h"

extern "C" void fn_8015D29C(void* p, s32 a);
extern "C" void* fn_8015A9A8(s32 size, void* vtbl, s32 a);
extern "C" void* fn_8015DD38(void* p, void* a, void* b, s32 c);
extern "C" void fn_8015F67C(void* p);
extern "C" void fn_80166478(void* p);
extern "C" void fn_801C0EEC(void* p);
extern "C" void* lbl_802FF540;
extern "C" void* lbl_802FF5A0;
extern "C" char lbl_80297A5C[];

typedef void (*VirtualMethod0)(void*, s16);
typedef void (*DispatchFn)(void*, void*, int, void*, void*);

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8015dbf4-0x8015ea78 (12 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80166C08(void*, int);
extern "C" void fn_8015AB1C(void*);
typedef void (*VirtualMethod0)(void*, s16);
extern "C" void* fn_8015DBF4(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_8015DC48(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

#pragma push
#pragma use_lmw_stmw off
extern u32 lbl_802FF5A4;
extern u32 lbl_802FF5A8;
extern u32 lbl_802FF5B8;
extern u32 lbl_802FF5BC;
extern u32 lbl_802FF5C0;
extern u32 lbl_802FF5C4;
extern u8 lbl_802979C8[];
extern u8 lbl_802979D8[];
extern "C" void fn_801BDDBC(void* a, void* b, s32 c);
extern "C" void fn_801BDEE4(void* a, void* b, s32 c);
extern "C" void fn_8015F248(s32 a, u32 b, u32 c, u32 d, s32 e);
extern "C" void fn_8015F400(s32 a);

extern "C" void* fn_8015DC9C(void* param_1, void* param_2, void* param_3, void* param_4, s32 param_5) {
    if (lbl_802FF5A0 == 0) {
        void* obj = fn_8015A9A8(0xa4, lbl_802FF540, 0);
        if (obj != 0) {
            obj = fn_8015DD38(obj, param_1, param_2, param_5);
        }
        lbl_802FF5A0 = obj;
    }
    fn_8015F67C(param_3);
    fn_80166478(param_4);
    fn_801C0EEC(*(void**)((u8*)lbl_802FF5A0 + 0x2c));
    return lbl_802FF5A0;
}
#pragma pop
extern "C" void* fn_8015DE54(void* param_1, s16 param_2) {
    if (param_1) {
        *(void**)param_1 = (void*)lbl_80297A5C;
        lbl_802FF5A0 = 0;
        void* obj = *(void**)((u8*)param_1 + 0x94);
        if (obj) {
            (*(VirtualMethod0*)((u8*)*(void**)obj + 8))(obj, 1);
        }
        fn_8015D29C(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8015DEE4(void) {
    s32* msg;
    s32 type;
    s32 data;
    fn_801BDDBC(&lbl_802979D8, &lbl_802979C8, 4);
    while (true) {
        fn_801BDEE4(&lbl_802979D8, &msg, 1);
        type = msg[0];
        data = msg[1];
        fn_8015AB1C(msg);
        switch (type) {
        case 1:
            fn_8015F400(data);
            break;
        }
    }
}

extern "C" u32 fn_8015E8FC(void) {
    u32 tail = lbl_802FF5A8;
    u32 head = lbl_802FF5A4;
    lbl_802FF5C0 = tail - 0x19;
    u32 size = tail - head;
    u32 left = lbl_802FF5BC;
    if (left < size) {
        size = left;
    }
    fn_8015F248(1, lbl_802FF5C4 + lbl_802FF5B8, head, (size + 0x1f) & ~0x1f, 0);
    left = lbl_802FF5BC - size;
    lbl_802FF5B8 += size;
    lbl_802FF5BC = left;
    if (left == 0) {
        lbl_802FF5C0 = head + size;
    }
    return head;
}

