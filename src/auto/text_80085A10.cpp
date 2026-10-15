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

