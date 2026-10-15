#include "types.h"

extern "C" void __dl__FPv(void*);
extern "C" u8 lbl_804B1BE8[];
extern "C" u32 lbl_8053AF00;

struct fn_80447190_Obj {
    virtual void Release(int);
};

extern "C" void* fn_80447190(void* param_1, short param_2)
{
    void* result = param_1;
    
    if (result != 0) {
        void* addr = (void*)lbl_804B1BE8;
        *(void**)result = addr;
        
        void* ptr1 = *(void**)((u32)result + 0x4);
        if (ptr1 != 0) {
            u32 vtbl = *(u32*)ptr1;
            ((void (*)(void*, int))(*(u32*)(vtbl + 8)))(ptr1, 1);
        }
        *(u32*)((u32)result + 0x4) = 0;
        
        int i = 0;
        void* ptr = result;
        do {
            void* p2 = *(void**)((u32)ptr + 0x8);
            if (p2 != 0) {
                u32 v2 = *(u32*)p2;
                ((void (*)(void*, int))(*(u32*)(v2 + 8)))(p2, 1);
            }
            *(u32*)((u32)ptr + 0x8) = 0;
            
            void* p3 = *(void**)((u32)ptr + 0x18);
            if (p3 != 0) {
                u32 v3 = *(u32*)p3;
                ((void (*)(void*, int))(*(u32*)(v3 + 8)))(p3, 1);
            }
            i++;
            *(u32*)((u32)ptr + 0x18) = 0;
            ptr = (void*)((u32)ptr + 4);
        } while (i < 4);
        
        *(u32*)&lbl_8053AF00 = 0;
        
        if (param_2 > 0) {
            __dl__FPv(result);
        }
    }
    
    return result;
}
