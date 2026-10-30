#include "JSystem/J3D/J3DDrawBuffer.h"


extern "C" s32 OSResumeThread(void* subObj);
extern "C" void* DVDGetCurrentDiskID(void);
extern "C" void GBAInit(void);
extern "C" u32 OSGetTick(void);
extern "C" void OSInitMessageQueue(void* queue, void* msgs, s32 count);
extern "C" void OSCreateThread(void* thread, void* (*start)(void*), void* arg, void* stack, u32 size, s32 prio, u32 attr);
extern "C" void* memset(void* dst, s32 c, u32 n);
extern "C" BOOL OSSendMessage(void* mq, void* msg, s32 flags);
extern "C" int memcmp(const void* a, const void* b, u32 n);
extern "C" int GBAGetStatus(s32 chan, u8* status);
extern "C" int GBARead(s32 chan, u8* dst, u8* status);
extern "C" int GBAWrite(s32 chan, u8* src, u8* status);
struct GbaPkt {
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
    u32 f04;
    u32 f08;
    u32 f0c;
    u8 pad[0x10];
};

struct GbaChan {
    u8 mq[0x20];
    u32 msg;
    void* cb;
    GbaPkt pkt;
    u32 tick;
    u8* program;      // 0x4c
    u32 programLen;   // 0x50
    u32 deviceType;   // 0x54
    u32 probeType;    // 0x58
    s32 f5c;
    u32 crcWord;      // 0x60
    u8 gameId[4];     // 0x64
    u8 sendData[0x68]; // 0x68
    char chan;
    u8 f_d1;
    u8 f_d2;
    u8 f_d3;
    u8 status[4];
    u8 f_d8;
    u8 f_d9;
    u8 f_da;
    u8 f_db;
    u8 f_dc;
    u8 f_dd;
    u8 f_de;
    u8 f_df;
};

extern "C" void fn_80300A8C(GbaChan* c);
extern "C" void* fn_80300E1C(void* p);
extern GbaPkt lbl_804D6AB8[];
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
    u32 crc = 0;
    u32 i;

    for (u32 mask = 0x80; mask != 0; mask >>= 1) {
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
    for (u32 mask = 0x80; mask != 0; mask >>= 1) {
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

#pragma opt_strength_reduction off
extern "C" void fn_803007D0(void) {
    u8* base = (u8*)lbl_804D6AB8;
    u8* id;
    u8* ub;
    u8* ud;
    u32 off;
    u8* thread;
    u8* p;
    s32 j;
    s32 i;
    s32 crc;
    u32 tick;

    lbl_8053ACC4 = (u8*)DVDGetCurrentDiskID();
    GBAInit();
    lbl_8053ACB8 = *(Unk8053ACB8**)(lbl_80529DEC + 0x58);
    lbl_8053ACBC = (u8*)lbl_8053ACB8->vf18(0x3f3f3f3f, lbl_804711F0);
    lbl_8053ACC0 = (u8*)lbl_8053ACB8->vf30(lbl_8053ACB8->vf18(0x3f3f3f3f, lbl_804711F0));
    tick = OSGetTick();
    lbl_8053ACC8 = tick;
    *(u32*)(lbl_8053ACBC + 0xc8) = tick;

    id = lbl_8053ACC4;
    ub = lbl_8053ACBC;
    ub[0xac] = id[0];
    ub[0xad] = id[1];
    ub[0xae] = id[2];
    ub[0xaf] = id[3];
    crc = 0xe7;
    for (i = 0xa0; i < 0xbd; i++) {
        crc -= ub[i];
    }
    ub[i] = crc;

    p = base + 0x4ce0;
    thread = base + 0x80;
    off = 0x1000;
    for (j = 0; j < 4; j++) {
        ud = lbl_8053ACC0;
        ub = lbl_8053ACBC;
        memset(p, 0, 0xe0);
        p[0xd0] = j;
        *(void**)(p + 0x24) = (void*)fn_80300A8C;
        *(u8**)(p + 0x4c) = ub;
        *(u8**)(p + 0x50) = ud;
        p[0xda] = 0x1a;
        p[0xdc] = 1;
        p[0xdd] = 0;
        p[0xde] = 0;
        OSInitMessageQueue(p, p + 0x20, 1);
        OSCreateThread(thread, fn_80300E1C, p, base + 0xce0 + off, 0x1000, 8, 0);
        OSResumeThread(thread);
        off += 0x1000;
        thread += 0x318;
        p += 0xe0;
    }
}
#pragma opt_strength_reduction reset

typedef s64 OSTime;
extern "C" s32 OSReceiveMessage(void* mq, void* msg, s32 flags);
extern "C" OSTime OSGetTime(void);
extern "C" void OSCreateAlarm(void* alarm);
extern "C" void* OSGetCurrentThread(void);
extern "C" s32 OSDisableInterrupts(void);
extern "C" s32 OSRestoreInterrupts(s32 level);
extern "C" void OSSetAlarm(void* alarm, OSTime tick, s32 (*handler)(void*));
extern "C" s32 OSSuspendThread(void* thread);
extern "C" int GBAReset(s32 chan, u8* status);
extern "C" int GBAJoyBoot(s32 chan, s32 palette, s32 speed, u8* program, u32 length, u8* status);
extern "C" u32 SIProbe(s32 chan);
extern "C" s32 fn_801365A8(void);
extern "C" s32 fn_80301A88(void* this_);
extern s8 lbl_8054161C[4];
extern u8 lbl_80541618[4];
extern u32 lbl_80541620;
extern u32 lbl_80541628;

// Reads the GBA's 4-byte id into +0x64.
static inline s32 gbaReadId(GbaChan* c) {
    s32 err;
    u32 id;
    if ((err = GBAGetStatus(c->chan, c->status)) != 0) {
        return err;
    }
    if (c->status[0] != 0x28) {
        return 1;
    }
    if ((err = GBARead(c->chan, (u8*)&id, c->status)) != 0) {
        return err;
    }
    *(u32*)c->gameId = id;
    c->status[3] = 1;
    return 0;
}

// Sends the disc id to the GBA.
static inline s32 gbaWriteId(GbaChan* c) {
    s32 err;
    if ((err = GBAGetStatus(c->chan, c->status)) != 0) {
        return err;
    }
    if (c->status[0] != 0x20) {
        return 1;
    }
    if ((err = GBAWrite(c->chan, lbl_8053ACC4, c->status)) != 0) {
        return err;
    }
    if ((err = GBAGetStatus(c->chan, c->status)) != 0) {
        return err;
    }
    if (c->status[0] != 0x30) {
        return 1;
    }
    return 0;
}

// Requests the GBA's packet and reads it (8 words) into +0x28.
static inline BOOL gbaReadPacket(GbaChan* c) {
    u32 cmd = 0x04000000;
    if (GBAWrite(c->chan, (u8*)&cmd, c->status) != 0 || (c->status[0] & 0x30) != 0x30) {
        return TRUE;
    }
    for (s32 i = 0; i < 0x20; i += 4) {
        if (GBAGetStatus(c->chan, c->status) != 0 || c->status[0] != 0x38) {
            return TRUE;
        }
        if (GBARead(c->chan, (u8*)&c->pkt + i, c->status) != 0 || (c->status[0] & 0x30) != 0x30) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline BOOL gbaHandshake(GbaChan* c, u32 expected) {
    if (gbaReadId(c) == 0 && (memcmp(c->gameId, lbl_8053ACC4, 4) == 0 || *(u32*)c->gameId == expected)) {
        if (memcmp(c->gameId, lbl_8053ACC4, 4) == 0) {
            c->f5c = 0;
        }
        if (gbaWriteId(c) == 0) {
            return gbaReadPacket(c);
        }
    }
    return TRUE;
}

// Same CRC as fn_803006E8, used inline by the link thread.
static inline u8 gbaCrc(u32 data) {
    u32 crc = 0;
    u32 i;

    for (u32 mask = 0x80; mask != 0; mask >>= 1) {
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
    for (u32 mask = 0x80; mask != 0; mask >>= 1) {
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

extern "C" void fn_80300A8C(GbaChan* c) {
    BOOL b28 = 1;
    u8 saved_f02;
    u32 saved_f0c;
    u32 v25;
    BOOL b24 = 0;

    c->f_d8 = 0;
    c->f_d9 = 1;
    c->f_d3 = 3;

    v25 = c->pkt.f08;
    c->pkt.f08 = lbl_804D6AB8[c->chan].f08;

    if (c->pkt.f00 == 0) {
        if (c->pkt.f03 == 0) {
            GbaPkt* entry = &lbl_804D6AB8[c->chan];
            memset(entry, 0, sizeof(GbaPkt));
            entry->f01 = c->chan;
            entry->f03 = 1;
            entry->f04 = lbl_8053ACC8;
            lbl_804D6AB8[c->chan].f02 = c->pkt.f02;
            lbl_804D6AB8[c->chan].f0c = c->pkt.f0c;
            c->tick = OSGetTick();
            lbl_804D6AB8[c->chan].f08 = c->tick;
            OSSendMessage(c, (void*)5, 1);
        } else {
            if (memcmp(&c->pkt, &lbl_804D6AB8[c->chan], sizeof(GbaPkt)) == 0 && c->f_dd == 0 &&
                (v25 == lbl_804D6AB8[c->chan].f08 || v25 == c->tick)) {
                lbl_804D6AB8[c->chan].f08 = v25;
                c->tick = v25;
                b28 = 0;
            }
            if (b28) {
                b24 = 1;
                OSSendMessage(c, (void*)4, 1);
                c->f_dd = 0;
            }
        }
    } else {
        saved_f02 = c->pkt.f02;
        c->pkt.f02 = lbl_804D6AB8[c->chan].f02;
        saved_f0c = c->pkt.f0c;
        c->pkt.f0c = lbl_804D6AB8[c->chan].f0c;
        if (memcmp(&c->pkt, &lbl_804D6AB8[c->chan], sizeof(GbaPkt)) == 0 && c->f_dd == 0 &&
            (v25 == lbl_804D6AB8[c->chan].f08 || v25 == c->tick)) {
            lbl_804D6AB8[c->chan].f08 = v25;
            c->tick = v25;
            lbl_804D6AB8[c->chan].f02 = saved_f02;
            lbl_804D6AB8[c->chan].f0c = saved_f0c;
            b28 = 0;
        }
        if (b28) {
            OSSendMessage(c, (void*)3, 1);
            c->f_dd = 0;
        }
    }

    if (!b28 || b24) {
        if (GBAGetStatus(c->chan, c->status) == 0 && c->status[0] == 0x30) {
            u32 writeVal;
            u32 readVal;
            if (b24) {
                writeVal = v25;
            } else {
                writeVal = OSGetTick();
                lbl_804D6AB8[c->chan].f08 = writeVal;
            }
            if (GBAWrite(c->chan, (u8*)&writeVal, c->status) == 0 && (c->status[0] & 0x30) == 0x30) {
                if (GBAGetStatus(c->chan, c->status) == 0 && c->status[0] == 0x38) {
                    int err = GBARead(c->chan, (u8*)&readVal, c->status);
                    if (!b24 && err == 0 && writeVal == readVal && (c->status[0] & 0x30) == 0x30) {
                        c->tick = writeVal;
                        c->f_d8 = 1;
                        c->f_d9 = 0;
                        c->f_d3 = 0;
                        c->f_de = 1;
                    }
                }
            }
        }
    }
}

extern "C" void* fn_80300E1C(void* arg) {
    GbaChan* c = (GbaChan*)arg;
    OSTime alarm[6];
    void* msg;
    u32 dummy;
    u32 cmd;
    s32 err;
    s32 count;
    s32 writeOff;
    s32 readOff;
    OSTime timeout;
    OSTime start;

    for (;;) {
        err = OSReceiveMessage(c, &msg, 0);
        if (err == 0) {
            c->f_d1 = 0;
            OSReceiveMessage(c, &msg, 1);
            c->f_d2 = 0;
        }
        if (msg == (void*)1) {
            return NULL;
        }
        if (msg == (void*)7 && c->program == NULL) {
            msg = (void*)8;
        }
        c->msg = (u32)msg;
        writeOff = 0;
        readOff = 0;
        count = 0;
        c->f_d1 = 1;
        c->status[2] = writeOff;
        switch ((s32)msg) {
        case 3:
            timeout = (*(u32*)0x800000F8 / 4 / 1000) * 500;
            break;
        case 5:
        case 10:
            timeout = (*(u32*)0x800000F8 / 4 / 1000) * 500;
            break;
        default:
            timeout = (*(u32*)0x800000F8 / 4 / 1000) * 1000;
            break;
        }
        start = OSGetTime();
        goto check;

    wait:
        {
            u32 ticks = (*(u32*)0x800000F8 / 4 / 1000) * 15;
            OSCreateAlarm(alarm);
            ((u32*)alarm)[10] = (u32)OSGetCurrentThread();
            s32 level = OSDisableInterrupts();
            OSSetAlarm(alarm, ticks, fn_80301A88);
            OSSuspendThread((void*)((u32*)alarm)[10]);
            OSRestoreInterrupts(level);
        }
    check:
        if (c->f_d2 != 0) {
            c->f_d3 = 3;
            c->f_d8 = 0;
            c->f_d9 = 0;
            continue;
        }
        if (OSGetTime() - start > timeout) {
            if (err != 3) {
                err = 1;
            }
            c->f_d3 = err;
            c->f_d8 = 0;
            c->f_d9 = 0;
            continue;
        }
        switch ((s32)msg) {
        case 2:
            c->f_d8 = 0;
            c->f_d9 = 0;
            c->f_d3 = GBAReset(c->chan, c->status);
            continue;
        case 3:
            c->f_d8 = 0;
            c->f_d9 = 0;
            if (GBAReset(c->chan, c->status) == 0) {
                err = 3;
                goto wait;
            }
            c->f_d3 = 0;
            continue;
        case 4:
            c->f_d8 = 0;
            c->f_d9 = 0;
            if ((err = GBAGetStatus(c->chan, c->status)) != 0) {
                goto fail;
            }
            if (c->status[0] & 2) {
                goto check;
            }
            if (count == 1) {
                c->f_d3 = 0;
                continue;
            }
            cmd = 0x03000000;
            if ((err = GBAWrite(c->chan, (u8*)&cmd, c->status)) != 0) {
                goto fail;
            }
            count++;
            writeOff += 4;
            goto check;
        case 5:
        {
            u8 s;
            if ((err = GBAGetStatus(c->chan, c->status)) != 0 || ((s = c->status[0]) & 0x30) != 0x30) {
            fail:
                if (err == 0) {
                    err = 3;
                }
                c->f_d3 = err;
                c->f_d8 = 0;
                c->f_d9 = 0;
                continue;
            }
            if (count < 9) {
                u8* buf;
                if (s & 2) {
                    goto check;
                }
                if (count == 0) {
                    cmd = 0x02000000;
                    buf = (u8*)&cmd;
                } else {
                    buf = (u8*)&lbl_804D6AB8[c->chan] + (count - 1) * 4;
                }
                if ((err = GBAWrite(c->chan, buf, c->status)) != 0) {
                    goto fail;
                }
                if ((c->status[0] & 0x30) != 0x30) {
                    goto fail;
                }
                count++;
                writeOff += 4;
                goto check;
            }
            if (!(s & 8)) {
                goto check;
            }
            if ((err = GBARead(c->chan, (u8*)c + (readOff + 0x28), c->status)) != 0) {
                goto fail;
            }
            if ((c->status[0] & 0x30) != 0x30) {
                goto fail;
            }
            readOff += 4;
            if (readOff != 0x20) {
                goto check;
            }
            ((void (*)(GbaChan*, void*))c->cb)(c, msg);
            continue;
        }
        case 6:
        {
            u32 type;
            c->f_d8 = 0;
            err = 1;
            c->f_d9 = 0;
            c->f5c = err;
            c->status[3] = 0;
            type = SIProbe(c->chan);
            c->probeType = type;
            if (type == 0x80) {
                goto wait;
            }
            if (type == 0x40000) {
                c->deviceType = type;
                c->f_d3 = 0;
                continue;
            }
            if (type != 8 && type != 0x40) {
                c->deviceType = type;
            }
            c->f_d3 = 1;
            continue;
        }
        case 7:
        {
            u32 expected;
            c->f_d8 = 0;
            c->f_d9 = 1;
            c->f5c = 1;
            c->status[3] = 0;
            err = GBAJoyBoot(c->chan, lbl_8054161C[c->chan], 2, c->program, c->programLen, c->status);
            if (err == 0) {
                GbaPkt* pkt = &lbl_804D6AB8[c->chan];
                memset(pkt, 0, sizeof(GbaPkt));
                pkt->f00 = 1;
                pkt->f01 = c->chan;
                pkt->f03 = 1;
                pkt->f04 = lbl_8053ACC8;
                c->f_dc = 1;
                c->f_dd = 0;
                msg = (void*)8;
                start = OSGetTime();
                goto check;
            }
            if (err != 3) {
                goto wait;
            }
            {
                u8 s = c->status[0];
                if ((s & 0xa) == 0xa) {
                    if ((s & 0x30) == 0x10) {
                        goto wait;
                    }
                    GBARead(c->chan, (u8*)&dummy, c->status);
                    goto wait;
                }
            }
            expected = fn_801365A8() ? lbl_80541628 : lbl_80541620;
            if (gbaHandshake(c, expected)) {
                goto wait;
            }
            ((void (*)(GbaChan*, void*))c->cb)(c, msg);
            continue;
        }
        case 8:
        {
            u32 expected;
            c->f_d8 = 0;
            c->f_d9 = 1;
            c->f5c = 1;
            c->status[3] = 0;
            if ((err = GBAReset(c->chan, c->status)) != 0) {
                goto wait;
            }
            expected = fn_801365A8() ? lbl_80541628 : lbl_80541620;
            if (gbaHandshake(c, expected)) {
                goto wait;
            }
            ((void (*)(GbaChan*, void*))c->cb)(c, msg);
            continue;
        }
        case 10:
        {
            u8 s;
            if (count < c->f_da) {
                if (count == 0) {
                    if (c->f_d8 == 0) {
                        c->f_d3 = 1;
                        continue;
                    }
                    c->f_db = c->gameId[3] & 3;
                    c->f_da = lbl_80541618[c->f_db];
                    if (c->f_db != 0) {
                        if ((err = GBAGetStatus(c->chan, c->status)) != 0) {
                            goto fail;
                        }
                        s = c->status[0];
                        if ((s & ~2) != 0x30) {
                            goto fail;
                        }
                        if (s != 0x30) {
                            goto check;
                        }
                    }
                }
                if (c->f_db == 0) {
                    if ((err = GBAGetStatus(c->chan, c->status)) != 0) {
                        goto fail;
                    }
                    s = c->status[0];
                    if ((s & 0x30) != 0x30) {
                        goto fail;
                    }
                    if (s != 0x30) {
                        goto check;
                    }
                }
                if ((err = GBAWrite(c->chan, (u8*)c + (writeOff + 0x68), c->status)) != 0) {
                    goto fail;
                }
                if ((c->status[0] & ~2) != 0x30) {
                    goto fail;
                }
                count++;
                writeOff += 4;
                goto check;
            }
            if ((err = GBAGetStatus(c->chan, c->status)) != 0) {
                goto fail;
            }
            s = c->status[0];
            if ((s & 0x30) != 0x30) {
                goto fail;
            }
            if (s & 2) {
                goto check;
            }
            if ((err = GBARead(c->chan, (u8*)&c->crcWord, c->status)) != 0) {
                goto fail;
            }
            if ((c->status[0] & 0x30) != 0x30) {
                goto fail;
            }
            {
                u32 v = c->crcWord;
                if ((u8)v != gbaCrc(((v >> 16) & 0xff) | (v & 0xff00))) {
                    goto fail;
                }
            }
            c->status[2] = 1;
            c->f_d3 = 0;
            continue;
        }
        }
    }
}

#pragma opt_strength_reduction reset

extern "C" s32 fn_80301A88(void* this_) {
    return OSResumeThread(*(void**)((char*)this_ + 0x28));
}

extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" void fn_80301AAC(void)
{
    static u8 pad[0x5060];
    static u32 c0[3];
    static u32 c1[3];
    static u32 c2[3];
    static u32 c3[3];
    static u32 c4[3];
    static u32 c5[3];
    static u32 c6[3];
    static u32 c7[3];
    static u32 c8[3];
    (void)pad;
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, c0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, c1);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, c2);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, c3);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, c4);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, c5);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, c6);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, c7);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, c8);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

