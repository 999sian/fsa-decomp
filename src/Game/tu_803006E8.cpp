#include "JSystem/J3D/J3DDrawBuffer.h"


extern "C" s32 OSResumeThread(void* subObj);
extern "C" u8 fn_803006E8(u32 data) {
    u32 mask;
    int crc;
    u32 i;

    crc = 0;
    for (mask = 0x80; mask != 0; mask >>= 1) {
        crc <<= 1;
        if (data & mask) {
            if (crc & 0x100) {
                crc ^= 0xcc;
            } else {
                crc += 1;
            }
        } else if (crc & 0x100) {
            crc ^= 0xcd;
        }
    }
    data >>= 8;
    for (mask = 0x80; mask != 0; mask >>= 1) {
        crc <<= 1;
        if (data & mask) {
            if (crc & 0x100) {
                crc ^= 0xcc;
            } else {
                crc += 1;
            }
        } else if (crc & 0x100) {
            crc ^= 0xcd;
        }
    }
    i = 0;
    do {
        crc <<= 1;
        if (crc & 0x100) {
            crc ^= 0xcd;
        }
    } while (++i < 8);
    return crc;
}

extern "C" s32 fn_80301A88(void* this_) {
    return OSResumeThread(*(void**)((char*)this_ + 0x28));
}
