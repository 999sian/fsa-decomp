// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern u32 fn_8008603C(void);
extern u32 fn_8008668C(void);
extern u8 fn_800866D4(void*, u32);
extern "C" int fn_8008665C(int, int);

extern u8 g_bit_mask_table[8];
extern s32 fn_8008668C(int);
extern "C" s32 fn_80085F0C(char* this_, s32 param_2);
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
struct VirtualSlotObj {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual u32 v03();
    virtual void v04();
    virtual u32 v05();
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
    aligned = (align + (u32)(base + pad) - 1) & mask;
    remain = (u32)end - aligned;
    count = remain / unit;
    result = p;
    if (p != 0) {
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

#pragma opt_propagation off
extern "C" s32 fn_80085F0C(char* this_, s32 param_2) {
    if (param_2 >= 0) {
        u32 words;
        u32 value;
        u32* p;
        u32 i;
        s32 bit;
        words = (*(u32*)(this_ + 0x70) + 0x1f) >> 5;
        p = *(u32**)(this_ + 0x78);
        for (i = 0; i < words; i++, p++) {
            value = *p;
            if (value != 0xffff) {
                for (bit = 0; bit < 32; bit++) {
                    if ((value & (0x80000000U >> bit)) == 0) return bit + (s32)(i << 5);
                }
            }
        }
    } else {
        u32* base;
        u32 words;
        u32* p;
        u32 i;
        s32 bit;
        base = *(u32**)(this_ + 0x78);
        words = (*(u32*)(this_ + 0x70) + 0x1f);
        p = (u32*)((u8*)base + ((words >> 3) & ~3)) - 1;
        for (i = (words >> 5) - 1; (s32)i >= 0; i--, p--) {
            if (*p != 0xffff) {
                for (bit = 31; bit >= 0; bit--) {
                    if ((*p & (0x80000000U >> bit)) == 0) return bit + (s32)(i << 5);
                }
            }
        }
    }
    return -1;
}
#pragma opt_propagation reset
extern "C" void fn_80085FF4(int param_1, s32 param_2, u32 param_3) {
    if (param_3 == 1) {
        extern s32 fn_80085F0C(char*, s32);
        fn_80085F0C((char*)param_1, param_2);
    } else if (param_2 >= 0) {
        fn_8008603C(param_1, param_3);
    } else {
        fn_800861C4(param_1, param_3);
    }
}

#pragma opt_propagation off
#pragma opt_unroll_loops off
extern "C" s32 fn_8008603C(int param_1, u32 param_2) {
    s32 count;
    u32* p;
    u32* end;
    u32* base;
    s32 best;
    s32 result;
    s32 runStart;
    u8 inRun;
    u32 word;
    s32 bit;

    inRun = 0;
    runStart = -1;
    result = -1;
    best = ~-(u32)(param_2 == 0) & 0xffff;
    base = *(u32**)(param_1 + 0x78);
    end = (u32*)((u8*)base + ((*(u32*)(param_1 + 0x70) + 0x1f) >> 3 & ~3));

    for (p = base; p <= end; p++) {
        word = (p != end) ? *p : 0xffffffff;
        if (word == 0) {
            if (!inRun) {
                runStart = ((s32)p - (s32)base) / 4 * 32;
                count = 0;
                inRun = 1;
            }
            count += 0x20;
        } else if (word != 0xffffffff || inRun) {
            for (bit = 0; bit < 32; bit++) {
                if (!(word & (0x80000000U >> bit))) {
                    if (!inRun) {
                        runStart = bit + ((s32)p - (s32)base) / 4 * 32;
                        count = 0;
                        inRun = 1;
                    }
                    count++;
                } else {
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
                }
            }
        }
    }
    if (param_2 == 0) {
        return best;
    }
    return result;
}
#pragma opt_propagation reset
extern "C" s32 fn_800861C4(int param_1, u32 param_2) {
    u8 inRun = 0;
    s32 runStart = -1;
    s32 result = -1;
    s32 best = 0xffff;
    u32* base = *(u32**)(param_1 + 0x78);
    u32* end = (u32*)((u8*)base + ((*(u32*)(param_1 + 0x70) + 0x1f) >> 3 & ~3));
    u32* p;
    s32 count = 0;
    s32 bit;

    for (p = end - 1; p >= base - 1; p--) {
        u32 word = (p != base - 1) ? *p : 0xffffffff;
        if (word == 0) {
            if (!inRun) {
                runStart = ((s32)p - (s32)base) / 4 * 32 + 31;
                count = 0;
                inRun = 1;
            }
            count += 0x20;
        } else if (word != 0xffffffff || inRun) {
            for (bit = 31; bit >= 0; bit--) {
                if (word & (0x80000000U >> bit)) {
                    if (inRun) {
                        if (count == param_2) {
                            return runStart - count + 1;
                        }
                        if (param_2 < count) {
                            if (*(u8*)(param_1 + 0x84) == 1) {
                                return runStart - param_2 + 1;
                            }
                            if (count < best) {
                                best = count;
                                result = runStart;
                            }
                        }
                        inRun = 0;
                    }
                } else {
                    if (!inRun) {
                        s32 wordOff = ((s32)p - (s32)base) / 4;
                        runStart = bit + wordOff * 32;
                        count = 0;
                        inRun = 1;
                    }
                    count++;
                }
            }
        }
    }
    if (result == -1) {
        return -1;
    }
    return result - param_2 + 1;
}
extern u8 lbl_8053B770[8];
extern "C" void fn_800863C0(void* param_1) {
    s32 idx = fn_8008668C();
    
    if (idx < 0) {
        return;
    }
    
    s32 byte_idx = idx / 8;
    u32 bit_pos = idx & 7;
    u8* data = *(u8**)((u8*)param_1 + 0x78);
    u8 mask = lbl_8053B770[bit_pos];
    u8 old_byte = data[byte_idx];
    u8 new_byte = old_byte & (mask ^ 0xff);
    data[byte_idx] = new_byte;
    
    u8 check_byte = data[byte_idx];
    if (old_byte != check_byte) {
        *(u32*)((u8*)param_1 + 0x80) += *(u32*)((u8*)param_1 + 0x6c);
    }
}

extern u8 lbl_8053B770[8];
#pragma opt_unroll_loops off
extern "C" void fn_80086438(u8* param_1) {
    extern u8 lbl_8053B770[8];
    u8* src;
    u32 n;
    u8* p;
    s32 i;
    u8 zero;

    i = 0;
    p = *(u8**)(param_1 + 0x78);
    zero = i;
    for (; i < *(s32*)(param_1 + 0x70) / 8; i++) {
        *p++ = zero;
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

extern "C" u32 fn_8008658C(void* self_) {
    u32 result = fn_8008668C();
    u8 check = fn_800866D4(self_, result);
    if (check) {
        return *(u32*)((u8*)self_ + 0x6c);
    }
    return 0;
}

extern "C" s32 fn_800865DC(void* self_) {
    s32 result = fn_8008603C((int)self_, 0);
    return *(s32*)((u8*)self_ + 0x6c) * result;
}

extern "C" void fn_80086614(void* self_) {
    u32 result = fn_8008603C((int)self_, 0);
    fn_8008665C((int)self_, result);
}

extern "C" u32 fn_80086654(int param_1) {
    return *(u32*)(param_1 + 0x80);
}

extern "C" int fn_8008665C(int param_1, int param_2) {
    if (!(param_2 >= 0 && (u32)param_2 < *(u32*)(param_1 + 0x70))) {
        return 0;
    }
    return *(int*)(param_1 + 0x7c) + *(int*)(param_1 + 0x6c) * param_2;
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
    if ((s32)param_2 < 0 || param_2 >= *(u32*)(param_1 + 0x70)) return 0;
    u8 res = lbl_8053B770[param_2 & 7] & (*(u8**)(param_1 + 0x78))[(s32)param_2 / 8];
    return (u8)((u32)(-(s32)res | res) >> 31);
}

#pragma peephole off
extern "C" void fn_80086724(char* p, s32 index) {
    extern u8 lbl_8053B770[8];
    if (index < 0 || (u32)index >= *(u32*)(p + 0x70)) return;
    (*(u8**)(p + 0x78))[index / 8] |= lbl_8053B770[index & 7];
}
#pragma peephole reset
extern "C" void JUTWarningConsole_f(const char*, ...);
extern "C" char lbl_8045E820[];
extern "C" s32 fn_80086764(char* p) {
    extern u8 lbl_8053B770[8];
    s32 n = (*(s32*)(p + 0x70) + 7) / 8;
    u8* data = *(u8**)(p + 0x78);
    s32 sum = 0;
    s32 i;

    for (i = 0; i < n; i++, data++) {
        u8 bits = *data;
        if (bits != 0xff) {
            if (bits == 0) {
                sum += *(s32*)(p + 0x6c) * 8;
            } else {
                u8* mask = lbl_8053B770;
                if ((bits & *mask++) == 0) sum += *(s32*)(p + 0x6c);
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

extern "C" char lbl_8045E854[];
extern "C" f32 lbl_8053B778;
extern "C" void JUTReportConsole_f(const char*, ...);
extern "C" void OSLockMutex(void* mutex);
extern "C" void OSUnlockMutex(void* mutex);
extern "C" void JUTReportConsole_f(const char* fmt, ...);
extern "C" u32 fn_80086890(void* self_) {
    u32 result = reinterpret_cast<VirtualSlotObj*>(self_)->v03();
    u8* p = (u8*)self_;
    OSLockMutex(p + 0x18);
    u32 total = *(u32*)(p + 0x38);
    u32 used = *(u32*)(p + 0x80);
    JUTReportConsole_f(lbl_8045E854, (f32)(total - used) / (f32)total * lbl_8053B778);
    OSUnlockMutex(p + 0x18);
    return result;
}

extern "C" u32 getTotalFreeSize__7JKRHeapFv(void *heap);
extern "C" void fn_8008693C(int param_1, int* param_2, int param_3) {
    param_2[5] = param_3;
    *param_2 = *(u32*)(param_1 + 0x38) - getTotalFreeSize__7JKRHeapFv((void*)param_1);
    int* end;
    int sum;
    sum = 0;
    end = *(int**)(param_1 + 0x7c);
    for (int* p = *(int**)(param_1 + 0x78); p < end; ++p) {
        sum += *p;
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

