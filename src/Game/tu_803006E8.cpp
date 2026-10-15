#include "JSystem/J3D/J3DDrawBuffer.h"


extern "C" s32 OSResumeThread(void* subObj);
extern "C" s32 fn_80301A88(void* this_) {
    return OSResumeThread(*(void**)((char*)this_ + 0x28));
}
