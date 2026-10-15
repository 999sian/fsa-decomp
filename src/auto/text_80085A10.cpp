// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern u32 fn_8008603C(void);
extern u32 fn_8008668C(void);
extern u8 fn_800866D4(void*, u32);
extern void fn_8008665C(void*, u32);

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

extern "C" int fn_8008665C(int param_1, int param_2) {
    if (param_2 < 0) {
        return 0;
    }
    u32 limit = *(u32*)(param_1 + 0x70);
    if ((u32)param_2 >= limit) {
        return 0;
    }
    int divisor = *(int*)(param_1 + 0x6c);
    int offset = *(int*)(param_1 + 0x7c);
    return offset + divisor * param_2;
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

