#include "dolphin/os/OSFastCast.h"

typedef struct OSAlarm OSAlarm;
typedef struct OSAlarmQueue OSAlarmQueue;

struct OSAlarm {
    void* handler;
    u32 tag;
    u64 fire;
    OSAlarm* prev;
    OSAlarm* next;
    u64 period;
    u64 start;
};

struct OSAlarmQueue {
    OSAlarm* head;
    OSAlarm* tail;
};

extern OSAlarmQueue AlarmQueue_802FF750;
extern u32 ResetFunctionInfo_8029BEC8[];
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801bb444-0x801bbf2c (15 functions). split_file divides it into the game's real files.

extern "C" void OSCreateAlarm(u32* p) {
    p[0] = 0;
    p[1] = 0;
}

extern "C" u32* fn_801BBC1C(u32* param_1, u32* param_2) {
    u32* cur = param_1;
    u32* prev = 0;
    while (cur != 0 && cur < param_2) {
        prev = cur;
        cur = (u32*)cur[1];
    }
    param_2[1] = (u32)cur;
    param_2[0] = (u32)prev;
    if (cur != 0) {
        cur[0] = (u32)param_2;
        if ((u32*)((u8*)param_2 + param_2[2]) == cur) {
            param_2[2] += cur[2];
            cur = (u32*)cur[1];
            param_2[1] = (u32)cur;
            if (cur != 0) {
                cur[0] = (u32)param_2;
            }
        }
    }
    if (prev != 0) {
        prev[1] = (u32)param_2;
        if ((u32*)((u8*)prev + prev[2]) == param_2) {
            prev[2] += param_2[2];
            prev[1] = (u32)cur;
            if (cur != 0) {
                cur[0] = (u32)prev;
            }
        }
        return param_1;
    }
    return param_2;
}

extern u32 lbl_802FE960;
extern "C" u32 fn_801BBE40(u32 param_1) {
    u32 old = lbl_802FE960;
    lbl_802FE960 = param_1;
    return old;
}

