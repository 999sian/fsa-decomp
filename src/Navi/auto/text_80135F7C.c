#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80135f7c-0x8013c97c (185 functions). split_file divides it into the game's real files.

extern void* lbl_80292BB4[];
extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_8029270C[];
extern void* lbl_80292694[];
extern "C" void* fn_80135F7C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029270C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292694;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292788[];
extern "C" void* fn_80135FD8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292788;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292694;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292800[];
extern "C" void* fn_80136034(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292800;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292694;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292878[];
extern "C" void* fn_80136090(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292878;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292694;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802928F0[];
extern "C" void* fn_801360EC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802928F0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292694;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_8013635C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292BB4;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_80136A68(void) {
    return 2;
}

extern "C" u32 fn_80136B14(void) {
    return 3;
}

extern "C" int fn_80136F18(void) {
    return 4;
}

extern "C" int fn_80137824(void) {
    return 5;
}

extern void* lbl_80292974[];
extern "C" void* fn_80139110(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292974;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292BB4;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292A08[];
extern "C" void* fn_8013916C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292A08;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292BB4;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292A64[];
extern "C" void* fn_801391C8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292A64;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292BB4;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292AC4[];
extern "C" void* fn_80139224(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292AC4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292BB4;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292B14[];
extern "C" void* fn_80139280(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292B14;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292BB4;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801396C0(u32* dst, u32* src) {
    *dst = *src;
}

extern "C" void fn_801396CC(u32* dst, u32* src) {
    *dst = *src;
}

extern char lbl_80201F70[];
extern "C" void fn_801396D8(f64* dst, f32* src) {
    *dst = *src;
}

extern "C" void fn_801396E4(f64* dst, f32* src) {
    *dst = *src;
}

extern "C" void fn_801396F0(f64* dst, f32* src) {
    *dst = *src;
}

extern "C" void fn_801396FC(f64* dst, f32* src) {
    *dst = *src;
}

extern "C" void fn_80139708(f64* dst, f32* src) {
    *dst = *src;
}

extern "C" void fn_80139714(void* param_1, void* param_2) {
    f64 v;
    u32* p = *(u32**)((char*)param_2 + 8);
    char* e = lbl_80201F70 + *p * 8;
    (*(void (**)(f64*, void*))(e + 4))(&v, p + 1);
    *(u32*)((char*)param_1 + 0x30) = *(u32*)e;
    *(f64*)((char*)param_1 + 0x38) = v;
}

extern "C" void fn_80139780(void* param_1, void* param_2) {
    *(f64*)((char*)param_1 + 0x20) = **(f32**)((char*)param_2 + 8);
}

extern void* lbl_80292CAC[];
extern "C" void* fn_80139A60(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292CAC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80167880(void*, int);
extern char lbl_80292C80[];
extern "C" void* fn_80139E0C(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80292C80;
        fn_80167880(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern void* lbl_80292F5C[];
extern "C" void* fn_8013AF0C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292F5C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80167880(void*, int);
extern char lbl_80292F24[];
extern "C" void* fn_8013AFB8(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80292F24;
        fn_80167880(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80132C50(void*, int);
extern char lbl_8029308C[];
extern "C" void* fn_8013B42C(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_8029308C;
        fn_80132C50(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80133414(void*, int);
extern char lbl_80293190[];
extern "C" void* fn_8013C91C(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80293190;
        fn_80133414(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

