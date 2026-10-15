#include "types.h"

extern "C" {
extern void* lbl_804B1CC8;
extern int lbl_8053AF20;
extern void __dl__FPv(void* obj);

    typedef void (*DestructorFunc)(void*, int);
}

struct VObj {
    virtual ~VObj();
};

void fn_8044A418(void* param_1, short param_2) {
    if (param_1 != 0) {
        *(void**)param_1 = &lbl_804B1CC8;
        
        void** ptrArray = (void**)param_1;
        
        void* obj = ptrArray[1];  // offset 0x4
        if (obj != 0) {
            DestructorFunc destructor = (DestructorFunc)(*(void***)obj)[2];  // vtable[2] at offset 0x8
            destructor(obj, 1);
        }
        ptrArray[1] = 0;
        
        for (int i = 0; i < 2; i++) {
            obj = ptrArray[2 + i];  // offset 0x8 and 0xc
            if (obj != 0) {
                DestructorFunc destructor = (DestructorFunc)(*(void***)obj)[2];
                destructor(obj, 1);
            }
            ptrArray[2 + i] = 0;
        }
        
        lbl_8053AF20 = 0;
        
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
}
