#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80019470-0x80021014 (291 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void* fn_800194F8(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_8001978C(void) {
}

extern "C" void fn_80019790(void) {
}

extern "C" void fn_8001DC20(void);
extern "C" void fn_8001A5D0(void) {
    fn_8001DC20();
}

extern "C" void fn_8001E628(void);
extern "C" void fn_8001A910(void) {
    fn_8001E628();
}

extern "C" void fn_8001DDA4(void);
extern "C" void fn_8001A930(void) {
    fn_8001DDA4();
}

extern "C" void cTg_SingleCut__FP16create_tag_class(void);
extern "C" void fn_8001A950(void) {
    cTg_SingleCut__FP16create_tag_class();
}

extern "C" void cTg_Create__FP16create_tag_classPv(void);
extern "C" void fn_8001A99C(void) {
    cTg_Create__FP16create_tag_classPv();
}

extern "C" void cTg_SingleCutFromTree__FP16create_tag_class(void);
extern "C" void fn_8001AAFC(void) {
    cTg_SingleCutFromTree__FP16create_tag_class();
}

extern "C" void fn_8001B590(void) {
    cTg_SingleCut__FP16create_tag_class();
}

extern "C" void fn_8001B0B0(void);
extern "C" void fn_8001B5D4(void) {
    fn_8001B0B0();
}

extern "C" void fn_8001B494(void);
extern "C" void fn_8001B63C(void) {
    fn_8001B494();
}

extern "C" void fn_8001B65C(void);
extern "C" void fn_8001B760(void) {
    fn_8001B65C();
}

extern "C" void fn_8001EA5C(void);
extern "C" void fn_8001BE84(void) {
    fn_8001EA5C();
}

extern "C" void fn_8001EB08(void);
extern "C" void fn_8001BEA4(void) {
    fn_8001EB08();
}

extern "C" void fn_8001EC90(void);
extern "C" void fn_8001C984(void) {
    fn_8001EC90();
}

extern "C" void fn_8001BC68(void);
extern "C" void fn_8001C9DC(void) {
    fn_8001BC68();
}

extern "C" void fn_8001B9CC(void);
extern "C" void fn_8001C9FC(void) {
    fn_8001B9CC();
}

extern "C" void fn_8001CA1C(void) {
    fn_8001B5D4();
}

extern "C" u32 fn_8001DA78(void) {
    return 2;
}

extern "C" u32 fn_8001DB08(void) {
    return 2;
}

extern "C" void cTg_IsUse__FP16create_tag_class(void);
extern "C" void fn_8001E69C(void) {
    cTg_IsUse__FP16create_tag_class();
}

extern "C" void cTg_Addition__FP15node_list_classP16create_tag_class(void);
extern "C" void fn_8001EAE8(void) {
    cTg_Addition__FP15node_list_classP16create_tag_class();
}

extern "C" void fn_8001EB08(void) {
    cTg_SingleCut__FP16create_tag_class();
}

extern "C" void fn_8001F7F0(int param_1, f32* param_2) {
    f32 t0, t1, t2;
    t0 = param_2[0], t1 = param_2[1];
    *(f32*)(param_1 + 0x30) = t0;
    t2 = param_2[2];
    *(f32*)(param_1 + 0x34) = t1;
    *(f32*)(param_1 + 0x38) = t2;
    *(u8*)(param_1 + 4) |= 0x20;
}

extern "C" void* fn_8001F818(void* param_1) {
    void* q = *(void**)((char*)param_1 + 4);
    if (q != nullptr) {
        return q;
    }
    return nullptr;
}

extern "C" u32 fn_8001F82C(void* param_1, u8 param_2) {
    if (param_2 == 0) {
        return 0;
    }
    if (param_2 > 8) {
        return 0;
    }
    return *(u32*)((char*)param_1 + param_2 * 4 + 4);
}

extern "C" void fn_80132858(void*, int);
extern char lbl_80205A6C[];
extern "C" void* fn_8001F854(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80205A6C;
        fn_80132858(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80132778(void*, int);
extern char lbl_80205B18[];
extern "C" void* fn_8001F8B4(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80205B18;
        fn_80132778(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_801329B4(void*, int);
extern char lbl_802059DC[];
extern "C" void* fn_8001FE38(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_802059DC;
        fn_801329B4(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8015AB1C(void*);
extern "C" void* fn_80020304(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void* fn_80020344(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

