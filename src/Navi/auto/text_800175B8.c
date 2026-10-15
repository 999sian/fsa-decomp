#include "types.h"
#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800175b8-0x80018c90 (23 functions). split_file divides it into the game's real files.

extern "C" s32 fn_8001D5B8(void*, void*);
extern "C" s32 fn_8001D5F4(void*, void*);
extern "C" void fn_8001AAFC(void*);
extern "C" void fn_8001836C(void*);
extern "C" void fn_80017F88(void*);
extern "C" void cTg_Addition__FP15node_list_classP16create_tag_class(void*, void*);
extern u8 lbl_80205388[];

extern "C" void fn_8015AB1C(void*);
extern "C" void* fn_800175F4(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_8015AB1C(void*);
extern "C" void* fn_80017630(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void* fn_8001766C(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80017F5C(void* tag) {
    cTg_Addition__FP15node_list_classP16create_tag_class(lbl_80205388, tag);
}

extern "C" void cTg_SingleCutFromTree__FP16create_tag_class(void*);
extern "C" void fn_80017F88(void* tag) {
    cTg_SingleCutFromTree__FP16create_tag_class(tag);
}

extern "C" void cTg_Create__FP16create_tag_classPv(void*, void*);
extern "C" s32 fn_80017FA8(void* tag, void* data) {
    cTg_Create__FP16create_tag_classPv(tag, data);
    return 1;
}

extern "C" void fn_8001C9FC(void);
extern "C" void fn_80017FCC(void) {
    fn_8001C9FC();
}

