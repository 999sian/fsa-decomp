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
extern "C" s32 fn_800861C4(int, u32);
extern "C" s32 fn_8008603C(int, u32);
extern "C" char lbl_80498FB8[];
extern "C" void dispose__7JKRHeapFv(void* param_1);
extern "C" void __dt__7JKRHeapFv(void* param_1, s32 param_2);
extern "C" void __dl__FPv(void* param_1);
extern "C" void free__7JKRHeapFPvP7JKRHeap(void* p, void* heap);
struct VirtualDtorObj {
    virtual ~VirtualDtorObj();
};

extern "C" char* fn_80085BBC(char* p, u32 a2, void* a3, u32 a4, u32 a5, u32 a6, u32 a7, void* a8, u8 a9);
extern "C" char* alloc__7JKRHeapFUliP7JKRHeap(u32 size, int align, void* heap);
extern "C" u32 getMaxAllocatableSize__7JKRHeapFi(void* heap, int align);
extern "C" void* sRootHeap__7JKRHeap;
extern "C" char* fn_80085A10(u32 minSize, u32 size, u32 align, void* heap, u8 a5) {
    char* result;
    u32 mask;
    u32 unit;
    u32 n;
    u32 aligned;
    u32 remain;
    u32 count;
    u32 pad;
    char* p;
    char* base;
    char* end;

    if (align == 0) {
        align = 4;
    }
    if (align > minSize) {
        minSize = align;
    }
    mask = ~(align - 1);
    minSize = align + minSize;
    unit = mask & (minSize - 1);
    if (heap == 0) {
        heap = sRootHeap__7JKRHeap;
    }
    if (size == 0xffffffff) {
        size = getMaxAllocatableSize__7JKRHeapFi(heap, 8);
    }
    if (size < 0x88) {
        return 0;
    }
    p = alloc__7JKRHeapFUliP7JKRHeap(size, 0, heap);
    if (p == 0) {
        return 0;
    }
    base = p + 0x88;
    n = ((size - 0x88) * 8) / (unit * 8 + 1);
    n = (n + 7) & ~7;
    if (n == 0) {
        free__7JKRHeapFPvP7JKRHeap(p, 0);
        return 0;
    }
    end = p + size;
    pad = ((n >> 3) + 3) & ~3;
    result = p;
    aligned = (align + (u32)(base + pad) - 1) & mask;
    remain = (u32)end - aligned;
    count = remain / unit;
    if (result != 0) {
        result = fn_80085BBC(p, (u32)base, (void*)aligned, unit, count, remain, align, heap, a5);
    }
    if (result == 0) {
        free__7JKRHeapFPvP7JKRHeap(p, 0);
    }
    return result;
}

extern "C" void fn_80085B5C(char* p) {
    void* heap = *(void**)(*(char**)(p + 0x50) + 0xc);
    if (heap != 0) {
        ((VirtualDtorObj*)p)->~VirtualDtorObj();
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

extern "C" void fn_80085CB8(char* p) {
    extern u8 lbl_8053B770[8];
    u8* data = *(u8**)(p + 0x78);
    s32 i;
    for (i = 0; i < *(s32*)(p + 0x70) / 8; i++) {
        *data++ = 0;
    }
    if (*(s32*)(p + 0x70) & 7) {
        s32 start;
        u32 rem;
        u32 blocks;
        u8* src;
        *data = 0;
        start = *(s32*)(p + 0x70) & 7;
        src = lbl_8053B770 + start;
        rem = 8 - start;
        if (start < 8) {
            blocks = rem >> 3;
            if (blocks != 0) {
                do {
                    *data |= src[0];
                    *data |= src[1];
                    *data |= src[2];
                    *data |= src[3];
                    *data |= src[4];
                    *data |= src[5];
                    *data |= src[6];
                    *data |= src[7];
                    src += 8;
                } while (--blocks != 0);
            }
            rem &= 7;
            if (rem != 0) {
                do {
                    *data |= *src++;
                } while (--rem != 0);
            }
        }
        data++;
    }
    for (; ((u32)data & 3) != 0; data++) {
        *data = 0xff;
    }
}

extern "C" int fn_80085DEC(char* this_, u32 param_2, u32 param_3) {
    extern s32 fn_80085F0C(char*, u32);
    extern void fn_80086724(char*, s32);
    unsigned long divisor = *(u32*)(this_ + 0x6c);
    extern s32 fn_80085FF4(char*, u32, u32);
    extern s32 fn_8008665C(char*, s32);
    if (param_2 <= divisor) {
        register s32 idx = fn_80085F0C(this_, param_3);
        if (0 > idx) {
            return 0;
        }
        fn_80086724(this_, idx);
        *(s32*)(this_ + 0x80) -= *(s32*)(this_ + 0x6c);
        return fn_8008665C(this_, idx);
    }
    register long count = (param_2 + divisor - 1) / divisor;
    register long start = fn_80085FF4(this_, param_3, count);
    if (0 > start) {
        return 0;
    }
    int end = start + count;
    register u8* p = *(u8**)(this_ + 0x78) + start / 8;
    for (u32 i = start; i < end; i++) {
        if ((i & 7) == 0) {
            p = *(u8**)(this_ + 0x78) + (s32)i / 8;
        }
        *p |= g_bit_mask_table[i & 7];
    }
    *(s32*)(this_ + 0x80) -= *(s32*)(this_ + 0x6c) * count;
    return fn_8008665C(this_, start);
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

extern "C" s32 fn_8008603C(int param_1, u32 param_2) {
    u8 inRun = 0;
    s32 runStart = -1;
    s32 result = -1;
    s32 best = ~-(u32)(param_2 == 0) & 0xffff;
    u32* base = *(u32**)(param_1 + 0x78);
    u32* end = (u32*)((u8*)base + ((*(u32*)(param_1 + 0x70) + 0x1f) >> 3 & ~3));
    u32* p;
    s32 count;

    for (p = base; p <= end; p++) {
        u32 word = (p == end) ? 0xffffffff : *p;
        if (word == 0) {
            if (!inRun) {
                runStart = ((s32)p - (s32)base) / 4 * 32;
                count = 0;
                inRun = 1;
            }
            count += 0x20;
        } else if (word != 0xffffffff || inRun) {
            s32 bit;
            for (bit = 0; bit < 32; bit++) {
                if (word & (0x80000000U >> bit)) {
                    if (inRun) {
                        if (param_2 == 0) {
                            if (best < count) {
                                best = count;
                                result = runStart;
                            }
                        } else {
                            if (count == param_2) {
                                return runStart;
                            }
                            if (param_2 < count) {
                                if (*(u8*)(param_1 + 0x84) == 1) {
                                    return runStart;
                                }
                                if (count < best) {
                                    best = count;
                                    result = runStart;
                                }
                            }
                        }
                        inRun = 0;
                    }
                } else {
                    if (!inRun) {
                        runStart = bit + ((s32)p - (s32)base) / 4 * 32;
                        count = 0;
                        inRun = 1;
                    }
                    count++;
                }
            }
        }
    }
    if (param_2 == 0) {
        return best;
    }
    return result;
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

extern u8 lbl_8053B770[];
extern "C" void fn_80086438(u8* param_1) {
    extern u8 lbl_8053B770[];
    s32 i;
    s32 n;
    u8* p;
    u8* src;

    i = 0;
    p = *(u8**)(param_1 + 0x78);
    n = i;
    for (; i < *(s32*)(param_1 + 0x70) / 8; i++) {
        *p++ = n;
    }
    if (*(s32*)(param_1 + 0x70) & 7) {
        *p = 0;
        src = lbl_8053B770 + (*(s32*)(param_1 + 0x70) & 7);
        n = 8 - (*(s32*)(param_1 + 0x70) & 7);
        if ((*(s32*)(param_1 + 0x70) & 7) < 8) {
            for (i = n >> 3; i != 0; i--) {
                *p |= src[0];
                *p |= src[1];
                *p |= src[2];
                *p |= src[3];
                *p |= src[4];
                *p |= src[5];
                *p |= src[6];
                *p |= src[7];
                src += 8;
            }
            for (n &= 7; n != 0; n--) {
                *p |= *src++;
            }
        }
        p++;
    }
    for (; ((u32)p & 3) != 0; p++) {
        *p = 0xff;
    }
    *(s32*)(param_1 + 0x80) = *(s32*)(param_1 + 0x6c) * *(s32*)(param_1 + 0x70);
}

extern "C" void fn_8008657C() {
}

extern "C" void fn_80086580() {
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

extern "C" void JUTWarningConsole_f(const char*, ...);
extern "C" char lbl_8045E820[];
extern "C" s32 fn_80086764(char* p) {
    s32 sum = 0;
    s32 n = *(s32*)(p + 0x70);
    u8* data = *(u8**)(p + 0x78);
    s32 i;

    n = (n + 7) / 8;
    for (i = 0; i < n; i++, data++) {
        u8 bits = *data;
        if (bits != 0xff) {
            if (bits == 0) {
                sum += *(s32*)(p + 0x6c) * 8;
            } else {
                u8* mask = g_bit_mask_table;
                if ((bits & mask[0]) == 0) sum += *(s32*)(p + 0x6c);
                if ((bits & *++mask) == 0) sum += *(s32*)(p + 0x6c);
                if ((bits & *++mask) == 0) sum += *(s32*)(p + 0x6c);
                if ((bits & *++mask) == 0) sum += *(s32*)(p + 0x6c);
                if ((bits & *++mask) == 0) sum += *(s32*)(p + 0x6c);
                if ((bits & *++mask) == 0) sum += *(s32*)(p + 0x6c);
                if ((bits & *++mask) == 0) sum += *(s32*)(p + 0x6c);
                if ((bits & mask[1]) == 0) sum += *(s32*)(p + 0x6c);
            }
        }
    }

    if (sum != *(s32*)(p + 0x80)) {
        JUTWarningConsole_f(lbl_8045E820);
    }
    return 1;
}

extern "C" u32 getTotalFreeSize__7JKRHeapFv(void *heap);
extern "C" void fn_8008693C(int param_1, int *param_2, int param_3) {
    int *start;
    int *end;
    int sum;
    u32 n;
    u32 cnt;

    param_2[5] = param_3;
    *param_2 = *(u32 *)(param_1 + 0x38) - getTotalFreeSize__7JKRHeapFv((void *)param_1);
    sum = 0;
    end = *(int **)(param_1 + 0x7c);
    start = *(int **)(param_1 + 0x78);
    n = ((u32)end + 3 - (u32)start) >> 2;
    if (start < end) {
        cnt = n >> 3;
        if (cnt != 0) {
            do {
                sum += start[0];
                sum += start[1];
                sum += start[2];
                sum += start[3];
                sum += start[4];
                sum += start[5];
                sum += start[6];
                sum += start[7];
                start += 8;
            } while (--cnt != 0);
        }
        n &= 7;
        if (n != 0) {
            do {
                sum += *start;
                start++;
            } while (--n != 0);
        }
    }
    param_2[1] = sum;
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

