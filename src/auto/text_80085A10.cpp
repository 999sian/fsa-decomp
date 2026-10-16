// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern u32 fn_8008603C(void);
extern u32 fn_8008668C(void);
extern u8 fn_800866D4(void*, u32);
extern void fn_8008665C(void*, u32);

extern u8 g_bit_mask_table[8];
extern s32 fn_8008668C(int);
extern "C" void fn_80085F0C(void);
extern "C" void fn_800861C4(int, u32);
extern "C" void fn_8008603C(int, u32);
extern "C" char lbl_80498FB8[];
extern "C" void dispose__7JKRHeapFv(void* param_1);
extern "C" void __dt__7JKRHeapFv(void* param_1, s32 param_2);
extern "C" void __dl__FPv(void* param_1);
extern "C" void free__7JKRHeapFPvP7JKRHeap(void* p, void* heap);
extern "C" void fn_80085B5C(char* p) {
    void* heap = *(void**)(*(char**)(p + 0x50) + 0xc);
    if (heap != 0) {
        (*(void (***)(char*, s32))p)[2](p, -1);
        free__7JKRHeapFPvP7JKRHeap(p, heap);
    }
}

extern "C" void __ct__7JKRHeapFPvUlP7JKRHeapb(char* p, void* start, u32 size, void* parent, u8 errorFlag);
extern "C" void fn_80085CB8(char* p);
extern "C" char* fn_80085BBC(char* p, u32 a2, void* a3, u32 a4, u32 a5, u32 a6, u32 a7, void* a8, u8 a9) {
    __ct__7JKRHeapFPvUlP7JKRHeapb(p, a3, a4 * a5, a8, a9);
    *(void**)p = lbl_80498FB8;
    *(u32*)(p + 0x6c) = a4;
    *(u32*)(p + 0x70) = a5;
    *(u32*)(p + 0x74) = a7;
    *(u32*)(p + 0x78) = a2;
    *(void**)(p + 0x7c) = a3;
    *(u8*)(p + 0x84) = 1;
    fn_80085CB8(p);
    *(u32*)(p + 0x80) = *(u32*)(p + 0x6c) * *(u32*)(p + 0x70);
    return p;
}

extern "C" void* fn_80085C50(void* param_1, s16 param_2) {
    if (param_1 != 0) {
        *(char**)param_1 = lbl_80498FB8;
        dispose__7JKRHeapFv(param_1);
        __dt__7JKRHeapFv(param_1, 0);
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80085FF4(int param_1, s32 param_2, u32 param_3) {
    if (param_3 == 1) {
        fn_80085F0C();
    } else if (param_2 >= 0) {
        fn_8008603C(param_1, param_3);
    } else {
        fn_800861C4(param_1, param_3);
    }
}

extern "C" void fn_800863C0(void* param_1) {
    s32 idx = fn_8008668C((int)param_1);
    
    if (idx < 0) {
        return;
    }
    
    s32 byte_idx = idx >> 3;
    u32 bit_pos = idx & 7;
    u8* data = *(u8**)((u8*)param_1 + 0x78);
    u8 mask = g_bit_mask_table[bit_pos];
    u8 old_byte = data[byte_idx];
    u8 new_byte = old_byte & ~mask;
    data[byte_idx] = new_byte;
    
    u8 check_byte = data[byte_idx];
    if (old_byte != check_byte) {
        *(u32*)((u8*)param_1 + 0x80) += *(u32*)((u8*)param_1 + 0x6c);
    }
}

void fn_8008657C(void) {
}

void fn_80086580(void) {
}

extern "C" s32 fn_80086584(void) {
    return -1;
}

u32 fn_8008658C(void* self_) {
    u32 result = fn_8008668C();
    u8 check = fn_800866D4(self_, result);
    if (check == 0) {
        return 0;
    } else {
        return *(u32*)((u8*)self_ + 0x6c);
    }
}

s32 fn_800865DC(void* self_) {
    s32 result = fn_8008603C();
    return *(s32*)((u8*)self_ + 0x6c) * result;
}

void fn_80086614(void* self_) {
    u32 result = fn_8008603C();
    fn_8008665C(self_, result);
}

extern "C" u32 fn_80086654(int param_1) {
    return *(u32*)(param_1 + 0x80);
}

extern "C" int fn_8008665C(int param_1, uint param_2) {
    if (param_2 < 0) {
        return 0;
    }
    u32 limit = *(u32*)(param_1 + 0x70);
    if (param_2 >= limit) {
        return 0;
    }
    int divisor = *(int*)(param_1 + 0x6c);
    int offset = *(int*)(param_1 + 0x7c);
    return offset + divisor * (int)param_2;
}

extern "C" int fn_8008668C(int param_1, u32 param_2) {
    int offset = *(int*)(param_1 + 0x7c);
    
    if ((int)(param_2 - offset) < 0) {
        return -1;
    }
    
    u32 diff = param_2 - offset;
    u32 divisor = *(u32*)(param_1 + 0x6c);
    u32 quotient = diff / divisor;
    
    if (diff != quotient * divisor) {
        return -1;
    }
    
    u32 limit = *(u32*)(param_1 + 0x70);
    if (quotient >= limit) {
        return -1;
    }
    
    return (int)quotient;
}

extern "C" u8 fn_800866D4(int param_1, u32 param_2) {
    if (!((-1 < (s32)param_2) && (param_2 < *(u32*)(param_1 + 0x70)))) {
        return 0;
    }
    
    s32 idx = ((s32)param_2 >> 3) + ((u32)((s32)param_2 < 0 && (param_2 & 7) != 0));
    u8* data = *(u8**)(param_1 + 0x78);
    u8 byte_val = data[idx];
    u8 mask = *(u8*)(0x8053B770 + (param_2 & 7));
    u8 res = byte_val & mask;
    
    return (u8)((-(s32)res | res) >> 31);
}

extern "C" int fn_80086A18(void* param_1, u32* param_2, u32* param_3) {
    int result = 1;
    if (param_2[1] != param_3[1]) {
        result = 0;
    }
    if (param_2[0] != param_3[0]) {
        return 0;
    }
    return result;
}

extern "C" u32 fn_80086A48(void) {
    return 0x554e4954;
}

extern "C" char __vt__10JSUIosBase[];
extern "C" void __dl__FPv(void* p);
extern "C" char* __dt__10JSUIosBaseFv(char* p, s16 flag) {
    if (p != 0) {
        *(void**)p = __vt__10JSUIosBase;
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

