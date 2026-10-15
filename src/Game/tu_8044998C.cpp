#include "types.h"

extern "C" {
extern void* lbl_804B1CC8;
extern int lbl_8053AF20;
extern void __dl__FPv(void* obj);

typedef void (*DestructorFunc)(void*, int);
}

void fn_8044A418(void* param_1, short param_2) {
    if (param_1 != 0) {
        *(int*)param_1 = (int)&lbl_804B1CC8;
        
        int* obj = *(int**)((char*)param_1 + 0x4);
        if (obj != 0) {
            (*(void(**)(int*, int))(*(int**)obj + 0x8/sizeof(int*)))(obj, 1);
        }
        *(int*)((char*)param_1 + 0x4) = 0;
        
        for (int i = 0; i < 2; i++) {
            obj = *(int**)((char*)param_1 + 0x8 + i * 4);
            if (obj != 0) {
                (*(void(**)(int*, int))(*(int**)obj + 0x8/sizeof(int*)))(obj, 1);
            }
            *(int*)((char*)param_1 + 0x8 + i * 4) = 0;
        }
        
        lbl_8053AF20 = 0;
        
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
}
