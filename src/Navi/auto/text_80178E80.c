#include "types.h"


extern "C" void fn_80177E84(void);
extern "C" int fn_8015FDA8(void* self, int flag);
extern "C" void fn_8018ECE4(void* a, void* b);
extern "C" void fn_8016A72C(void* p);
extern void* lbl_802FF6A0;
extern "C" void fn_8017A468(void) {
    fn_80177E84();
}

extern "C" void fn_8017A4A8(void* self) {
    if (fn_8015FDA8(self, 0) == 0) {
        void* p = lbl_802FF6A0;
        if (p != 0) {
            fn_8018ECE4(p, self);
        }
    }
}

extern "C" void fn_80178990(void);
extern "C" void fn_8017A908(void) {
    fn_80178990();
}

extern "C" int fn_80184B08(unsigned char* self, unsigned char idx) {
    unsigned char* p;
    if (idx >= 4) {
        return 0;
    }
    p = self + (idx << 2);
    return *(int*)(p + 0x148);
}

extern "C" void fn_80178990(void);
extern "C" void fn_8018903C(void) {
    fn_80178990();
}

extern void* lbl_80299504[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8018C1A0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299504;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

