#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801bddbc-0x801bdfcc (4 functions). split_file divides it into the game's real files.

#include "types.h"
#include "dolphin/os.h"

extern "C" void fn_801C12E4(void* p);
extern "C" void fn_801C13D0(void* p);

extern "C" int OSDisableInterrupts(void);
extern "C" int OSRestoreInterrupts(int level);
extern "C" void fn_801C12E4(void* queue);
extern "C" void fn_801C13D0(void* queue);
extern "C" BOOL fn_801BDE1C(u8* param1, u32 param2, u32 param3)
{
    BOOL enabled;
    s32 idx;
    s32 wait;

    wait = param3 & 1;
    enabled = OSDisableInterrupts();
    goto check;
    for (;;) {
        if (wait == 0) {
            OSRestoreInterrupts(enabled);
            return 0;
        }
        fn_801C12E4(param1);
check:
        if (*(s32*)(param1 + 0x14) > *(s32*)(param1 + 0x1c)) {
            break;
        }
    }
    idx = *(s32*)(param1 + 0x18) + *(s32*)(param1 + 0x1c);
    ((u32*)(*(u32*)(param1 + 0x10)))[idx % *(s32*)(param1 + 0x14)] = param2;
    *(s32*)(param1 + 0x1c) += 1;
    fn_801C13D0(param1 + 8);
    OSRestoreInterrupts(enabled);
    return 1;
}

extern "C" int fn_801BDEE4(u8* mq, void** msg, s32 flags)
{
    int enabled;

    enabled = OSDisableInterrupts();
    while (*(s32*)(mq + 0x1c) == 0) {
        if (!(flags & 1)) {
            OSRestoreInterrupts(enabled);
            return 0;
        }
        fn_801C12E4(mq + 8);
    }
    if (msg != 0) {
        *msg = (*(void***)(mq + 0x10))[*(s32*)(mq + 0x18)];
    }
    *(s32*)(mq + 0x18) = (*(s32*)(mq + 0x18) + 1) % *(s32*)(mq + 0x14);
    (*(s32*)(mq + 0x1c))--;
    fn_801C13D0(mq);
    OSRestoreInterrupts(enabled);
    return 1;
}
