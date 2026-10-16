#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8011c5b4-0x8011f1f4 (28 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_8015D29C(void*, int);
extern char lbl_80290778[];
extern u32 lbl_802FF2F4;
extern void* lbl_802C6170;
extern "C" void* fn_801E6578(void* param_1, void* param_2);
extern "C" void* fn_8015A90C(u32 size);
extern "C" void fn_80166B58(void* param_1, void* param_2);
extern "C" void fn_80166C84(void* param_1, void* param_2);
extern "C" s64 OSGetTime(void);
extern u32 lbl_802FE970;
extern "C" void fn_8011C8E8();
extern "C" void OSSetErrorHandler(u32 code, void* handler);
extern "C" void fn_80166C08(void*, int);
extern "C" void* fn_8011C5B4(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern f32 lbl_80301540;
extern "C" void fn_8011C608(void* param_1) {
    f32 v = lbl_80301540;
    *(f32*)((char*)param_1 + 0x0) = v;
    *(f32*)((char*)param_1 + 0x4) = v;
    *(f32*)((char*)param_1 + 0x8) = v;
    *(s16*)((char*)param_1 + 0xc) = 0;
}

extern "C" void fn_8011C624(void* param_1) {
    char* p = (char*)param_1;
    *(s32*)(p + 0x0) = 0;
    *(s32*)(p + 0x4) = 0;
    *(s32*)(p + 0x8) = 0;
    *(s32*)(p + 0x18) = 0;
    *(u8*)(p + 0xc) = 0;
    *(u8*)(p + 0xd) = 0;
    *(u8*)(p + 0xe) = 0;
    *(u8*)(p + 0xf) = 0;
    *(s32*)(p + 0x1c) = 0;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2c) = 0;
}

extern "C" void fn_80166C08(void*, int);
extern "C" void* fn_8011C660(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8011CB8C(u32 param_1) {
    lbl_802FE970 = param_1;
    if (param_1 != 0) {
        OSSetErrorHandler(0x10, (void*)fn_8011C8E8);
    } else {
        OSSetErrorHandler(0x10, nullptr);
    }
}

extern "C" u32 fn_8011DF90(void* param_1) {
    u32 val = *(u32*)((u8*)param_1 + 0x84);
    if (val == 0xffffffff) return 1;
    if (*(s32*)((u8*)param_1 + 0x88) >= 0) return 1;
    return ((-val) | val) >> 31;
}

extern "C" void fn_8011EA30(s32 param_1) {
    if (param_1 == 0) {
        return;
    }
    
    s64 time1 = OSGetTime();
    s64 time2 = OSGetTime();
    s64 elapsed = time2 - time1;
    
    u32 clock_speed = *(u32*)0x800000f8 >> 2;
    
    // Divisor = ((constant * (clock_speed >> 2)) >> 32) >> 6
    // Which is: (constant * clock_speed) >> 40
    s64 divisor_calc = 0x10624dd3LL * clock_speed;
    s64 divisor = divisor_calc >> 40;
    
    s64 quotient = elapsed / divisor;
    
    // Convert param to 64-bit and compare
    s64 param_s64 = (s64)(s32)param_1;
    
    if ((quotient ^ 0x8000000000000000LL) < (param_s64 ^ 0x8000000000000000LL)) {
        return;
    }
}

extern "C" u32 fn_8011EBB4(u32 param_1) {
    u32 old = lbl_802FF2F4;
    lbl_802FF2F4 = param_1;
    return old;
}

extern u32 lbl_802FF2F8;
extern "C" u32 fn_8011EBC4(u32 param_1) {
    u32 old = lbl_802FF2F8;
    lbl_802FF2F8 = param_1;
    return old;
}

extern "C" void fn_8011EBD4(void* param_1) {
    if (param_1 != nullptr) {
        void* current = lbl_802C6170;
        
        while (current != nullptr) {
            void* first_ptr = *(void**)current;
            void* val = *(void**)first_ptr;
            if (fn_801E6578(param_1, val) == nullptr) {
                return;
            }
            current = *(void**)((u8*)current + 12);
        }
        
        void* new_node = fn_8015A90C(0x14);
        if (new_node != nullptr) {
            fn_80166B58((u8*)new_node + 4, new_node);
            *(void**)new_node = param_1;
            fn_80166C84((void**)&lbl_802C6170, (u8*)new_node + 4);
        }
    }
}

extern "C" void fn_8011F174(void* param_1, u32 param_2, u16 param_3, u32 param_4, u32 param_5) {
    *(u32*)param_1 = param_2;
    *(u32*)((u8*)param_1 + 4) = param_5;
    *(u16*)((u8*)param_1 + 12) = 1;
    *(u16*)((u8*)param_1 + 14) = param_3;
    *(u8*)((u8*)param_1 + 16) = 0;
}

extern "C" void* fn_8011F194(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80290778;
        fn_8015D29C(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}
