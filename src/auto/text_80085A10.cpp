// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern u32 fn_8008603C(void);
extern u32 fn_8008668C(void);
extern u8 fn_800866D4(void*, u32);
extern void fn_8008665C(void*, u32);

extern u8 g_bit_mask_table[8];
extern s32 fn_8008668C(int);
extern void fn_80085F0C(void);
extern void fn_800861C4(int, int);
extern void fn_8008603C(int, int);
extern "C" void fn_80085F0C(void);
extern "C" void fn_800861C4(int, u32);
extern "C" void fn_8008603C(int, u32);
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

