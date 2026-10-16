#include "types.h"


extern void* lbl_8053AAF8;
extern "C" void fn_8024064C(void* p);
extern "C" s32 fn_8023DE58(void* p);
extern "C" s32 fn_8030AAF4(s32 i);
extern "C" void* fn_8008E328(s32 slot);
extern "C" u8 fn_80247534(void* p);
extern "C" void fn_80286688(u8* p) {
    if (*(s32*)((u8*)lbl_8053AAF8 + 0x4c) != 0xb && *((u8*)lbl_8053AAF8 + 0x7e) == 0 &&
        (*((u8*)lbl_8053AAF8 + 0x82) & ((1 << *(u32*)(p + 4)) & 0xff)) != 0) {
        fn_8024064C(p);
        if (fn_8023DE58(p) < 8) {
            p[0x13b8] = 0;
        } else {
            void* pad = fn_8008E328(fn_8030AAF4(*(s32*)(p + 0x11ec)));
            if (!fn_80247534(p) && pad != 0 && (*(u32*)((u8*)pad + 0x1c) & 0x10) != 0) {
                if (p[0x13b8] == 1) {
                    p[0x13b8] = 0;
                } else {
                    p[0x13b8] = 1;
                }
            }
        }
    }
}
