// TU 0x8045ba84-0x8045bce4.
#include "types.h"

extern "C" void fn_8030C5F0(void* obj, u32 p2, u32 p3, u32 p4, void* out);
extern "C" char* lbl_8053AB10;

extern "C" void fn_8045BA84(u32 a, void* out) {
    fn_8030C5F0(*(void**)(lbl_8053AB10 + 0x24), a, 1, 1, out);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
