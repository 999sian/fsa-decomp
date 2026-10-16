#include "types.h"

struct TndrG { u8 pad[0x131df]; u8 arr[4]; };
extern "C" TndrG* fn_802D6A9C(void);
extern "C" u32 fn_800FD548(void* ring, u8 i);
extern "C" u8 fn_801CF888(void* this_, void* a, void* b, s32 c);
void* GetCurrentSlotPtr(void* thisPtr);
extern "C" f32 lbl_8053EEC8;
