#include "JSystem/J3D/J3DDrawBuffer.h"


extern "C" s32 OSResumeThread(void* subObj);
extern "C" void* DVDGetCurrentDiskID(void);
extern "C" void GBAInit(void);
extern "C" u32 OSGetTick(void);
extern "C" void OSInitMessageQueue(void* queue, void* msgs, s32 count);
extern "C" void OSCreateThread(void* thread, void* (*start)(void*), void* arg, void* stack, u32 size, s32 prio, u32 attr);
extern "C" void* memset(void* dst, s32 c, u32 n);
extern "C" void* fn_80300A8C(void* p);
extern "C" void* fn_80300E1C(void* p);
extern u8 lbl_804D6AB8[];
extern u8 lbl_804711F0[];
extern u8 lbl_80529DEC[];
extern u8* lbl_8053ACBC;
extern u8* lbl_8053ACC0;
extern u8* lbl_8053ACC4;
extern u32 lbl_8053ACC8;

class Unk8053ACB8 {
public:
    virtual void vf08();
    virtual void vf0C();
};
extern Unk8053ACB8* lbl_8053ACB8;

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

extern "C" void fn_803007A0(void) {
    lbl_8053ACB8->vf0C();
}

extern "C" s32 fn_80301A88(void* this_) {
    return OSResumeThread(*(void**)((char*)this_ + 0x28));
}
