#include "types.h"

struct ActorE62 { u8 pad0[4]; u32 f4; u8 fC[4]; };
extern "C" void fn_801EE434(void* handle);
extern "C" void* fn_8013CC50(u32 id, void* pos, u32 kind, u32 a, u32 b, u32 c, u32 d, u32 e, float scale);
extern "C" void fn_801CB71C(void* a, void* b, u32 c, u32 d);
extern "C" f32 lbl_8053F5AC;
extern "C" void fn_801E62D4(char* this_) {
    void* pos = (void*)(this_ + 0xc);
    u32 id = *(u32*)(this_ + 4);
    fn_8013CC50(id, pos, 0x259, 0, 0, 0, 0, 1, 1.0f);
}

extern "C" void fn_801E631C(char* this_) {
    u32 id = *(u32*)(this_ + 4);
    fn_8013CC50(id, this_ + 0xc, 0x25a, 0, 0, 0, 0, 1, 1.0f);
    id = *(u32*)(this_ + 4);
    fn_8013CC50(id, this_ + 0xc, 0x25b, 0, 0, 0, 0, 1, 1.0f);
}

extern "C" void fn_801E6394(char* this_) {
    fn_801EE434(*(void**)(this_ + 0x2c0));
    fn_801EE434(*(void**)(this_ + 0x2c4));
    *(u32*)(this_ + 0x2c0) = 0;
    *(u32*)(this_ + 0x2c4) = 0;
}

extern "C" void fn_801E63D8(char* this_) {
    *(void**)(this_ + 0x2c0) = fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x25e, 0, 0, 0, 0, 1, 1.0f);
    *(void**)(this_ + 0x2c4) = fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x25f, 0, 0, 0, 0, 1, 1.0f);
}

