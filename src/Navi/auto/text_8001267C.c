#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8001267c-0x80012804 (4 functions). split_file divides it into the game's real files.

extern void* lbl_802049BC[];

struct Entry_800126C8 {
    u8 data[0x18];
    u32 pad;
    u32 key;
};
struct Table_800126C8 {
    u32 unk0;
    Entry_800126C8 entries[0x40];
};
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8001267C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802049BC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800126C4(void) {}

extern char lbl_802049C8[];
extern char lbl_80204A10[];
extern char lbl_80204A4C[];
extern "C" void fn_800074C0(const char* fmt, ...);
extern "C" void fn_801E6704(void* dst, const void* src, u32 size);
extern "C" s32 fn_800126C8(Table_800126C8* self, const void* src, u32 key) {
    s32 i;
    for (i = 0; i < 0x40; i++) {
        if (self->entries[i].key == key) {
            fn_800074C0(lbl_802049C8);
            return -1;
        }
    }
    for (i = 0; i < 0x40; i++) {
        if (self->entries[i].key == 0) {
            fn_801E6704(self->entries[i].data, src, 0x18);
            self->entries[i].key = key;
            return (s8)i;
        }
    }
    fn_800074C0(lbl_80204A10);
    return -1;
}

