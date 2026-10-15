#include "types.h"

extern "C" {
extern void* lbl_804B1CC8[];
extern int lbl_8053AF20;
extern void __dl__FPv(void* obj);

    typedef void (*DestructorFunc)(void*, int);
}

struct VObj {
    virtual ~VObj();
};

extern "C" void* fn_8044A418(VObj** param_1, short param_2) {
    if (param_1 != 0) {
        *(void**)param_1 = &lbl_804B1CC8;
        delete param_1[1];
        param_1[1] = 0;
        for (int i = 0; i < 2; i++) {
            delete param_1[2 + i];
            param_1[2 + i] = 0;
        }
        lbl_8053AF20 = 0;
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}
