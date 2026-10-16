#include "types.h"

struct TndrG { u8 pad[0x131df]; u8 arr[4]; };
extern "C" TndrG* fn_802D6A9C(void);
extern "C" u32 fn_800FD548(void* ring, u8 i);
extern "C" u8 fn_801CF888(void* this_, void* a, void* b, s32 c);
void* GetCurrentSlotPtr(void* thisPtr);
extern "C" f32 lbl_8053EEC8;
extern "C" void fn_800FDE38(void* p);
extern "C" void fn_801C8C84(char* this_, s32 a, s32 b);
extern "C" s16 fn_801D02E0(char* this_, void* p);
extern "C" u8 fn_800FD894(void* ring, s32 id, u8* buf, s32 n);
extern "C" s32 fn_801CD664(s32 n);
