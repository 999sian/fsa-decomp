#include "types.h"
struct BPOHVt {
    char pad[0x28];
    void (*fn28)(void*, s32, float, float);
};
