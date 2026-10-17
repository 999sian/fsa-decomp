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
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 a, void* b);
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void* vf30(void* a);
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

extern "C" void fn_803007D0(void) {
    u8* base = lbl_804D6AB8;
    u8* ub;
    u8* ud;
    u32 off;
    u8* thread;
    u8* p;
    s32 i;
    s32 crc;
    u32 tick;
    void* t;
    void* fn1;
    void* fn2;

    lbl_8053ACC4 = (u8*)DVDGetCurrentDiskID();
    GBAInit();
    lbl_8053ACB8 = *(Unk8053ACB8**)(lbl_80529DEC + 0x58);
    lbl_8053ACBC = (u8*)((void* (*)(void*, u32, void*))(*(void***)lbl_8053ACB8)[6])(lbl_8053ACB8, 0x3f3f3f3f, lbl_804711F0);
    t = ((void* (*)(void*, u32, void*))(*(void***)lbl_8053ACB8)[6])(lbl_8053ACB8, 0x3f3f3f3f, lbl_804711F0);
    lbl_8053ACC0 = (u8*)((void* (*)(void*, void*))(*(void***)lbl_8053ACB8)[12])(lbl_8053ACB8, t);
    tick = OSGetTick();
    lbl_8053ACC8 = tick;
    *(u32*)(lbl_8053ACBC + 0xc8) = tick;

    lbl_8053ACBC[0xac] = lbl_8053ACC4[0];
    lbl_8053ACBC[0xad] = lbl_8053ACC4[1];
    lbl_8053ACBC[0xae] = lbl_8053ACC4[2];
    lbl_8053ACBC[0xaf] = lbl_8053ACC4[3];
    crc = 0xe7 - lbl_8053ACBC[0xa0] - lbl_8053ACBC[0xa1] - lbl_8053ACBC[0xa2] - lbl_8053ACBC[0xa3] -
          lbl_8053ACBC[0xa4] - lbl_8053ACBC[0xa5] - lbl_8053ACBC[0xa6] - lbl_8053ACBC[0xa7] -
          lbl_8053ACBC[0xa8] - lbl_8053ACBC[0xa9] - lbl_8053ACBC[0xaa] - lbl_8053ACBC[0xab] -
          lbl_8053ACBC[0xac] - lbl_8053ACBC[0xad] - lbl_8053ACBC[0xae] - lbl_8053ACBC[0xaf] -
          lbl_8053ACBC[0xb0] - lbl_8053ACBC[0xb1] - lbl_8053ACBC[0xb2] - lbl_8053ACBC[0xb3] -
          lbl_8053ACBC[0xb4] - lbl_8053ACBC[0xb5] - lbl_8053ACBC[0xb6] - lbl_8053ACBC[0xb7] -
          lbl_8053ACBC[0xb8] - lbl_8053ACBC[0xb9] - lbl_8053ACBC[0xba] - lbl_8053ACBC[0xbb];
    for (i = 0xbc; i < 0xbd; i++) {
        crc -= lbl_8053ACBC[i];
    }
    lbl_8053ACBC[0xbd] = crc;

    fn1 = (void*)fn_80300A8C;
    fn2 = (void*)fn_80300E1C;
    i = 0;
    off = 0x1000;
    ud = lbl_8053ACC0;
    ub = lbl_8053ACBC;
    p = base + 0x4ce0;
    thread = base + 0x80;
    do {
        memset(p, 0, 0xe0);
        p[0xd0] = i;
        *(void**)(p + 0x24) = fn1;
        *(u8**)(p + 0x4c) = ub;
        *(u8**)(p + 0x50) = ud;
        p[0xda] = 0x1a;
        p[0xdc] = 1;
        p[0xdd] = 0;
        p[0xde] = 0;
        OSInitMessageQueue(p, p + 0x20, 1);
        OSCreateThread(thread, (void* (*)(void*))fn2, p, base + 0xce0 + off, 0x1000, 8, 0);
        OSResumeThread(thread);
        i++;
        off += 0x1000;
        thread += 0x318;
        p += 0xe0;
    } while (i < 4);
}

extern "C" s32 fn_80301A88(void* this_) {
    return OSResumeThread(*(void**)((char*)this_ + 0x28));
}
