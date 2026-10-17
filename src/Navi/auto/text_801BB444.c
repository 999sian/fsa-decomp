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
extern u32 lbl_802FF758;
extern u32 lbl_802FF75C;
extern u32 lbl_802FF760;
extern u32 lbl_802FF764;
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801bb444-0x801bbf2c (15 functions). split_file divides it into the game's real files.

extern "C" void* __OSGetExceptionHandler(s32 exception);
extern "C" void* __OSSetExceptionHandler(s32 exception, void* handler);
extern "C" void DecrementerExceptionHandler(s32 exception, void* context);
extern "C" void OSRegisterResetFunction(void* info);
extern "C" void OSInitAlarm(void) {
    if (__OSGetExceptionHandler(8) != DecrementerExceptionHandler) {
        AlarmQueue_802FF750.head = AlarmQueue_802FF750.tail = 0;
        __OSSetExceptionHandler(8, DecrementerExceptionHandler);
        OSRegisterResetFunction(&ResetFunctionInfo_8029BEC8);
    }
}

extern "C" void OSCreateAlarm(u32* p) {
    p[0] = 0;
    p[1] = 0;
}

extern "C" u64 __OSGetSystemTime(void);
extern "C" BOOL OSDisableInterrupts(void);
extern "C" BOOL OSRestoreInterrupts(BOOL level);
extern "C" void InsertAlarm(OSAlarm* alarm, u64 fire, void* handler);
extern "C" void OSSetAlarm(OSAlarm* alarm, u64 tick, void* handler) {
    BOOL enabled;
    enabled = OSDisableInterrupts();
    alarm->period = 0;
    InsertAlarm(alarm, __OSGetSystemTime() + tick, handler);
    OSRestoreInterrupts(enabled);
}

extern "C" u64 fn_801C1EB8(u64 time);
extern "C" void fn_801BB764(OSAlarm* alarm, u64 start, u64 period, void* handler) {
    BOOL enabled;
    enabled = OSDisableInterrupts();
    alarm->period = period;
    alarm->start = fn_801C1EB8(start);
    InsertAlarm(alarm, 0, handler);
    OSRestoreInterrupts(enabled);
}

extern "C" int fn_801CA8A4(OSAlarm* alarm);
extern "C" void fn_801BB7E0(OSAlarm* alarm);
extern "C" int fn_801BBB7C(int param_1) {
    int iVar1;
    OSAlarm* iVar3;
    OSAlarm* iVar2;

    if (param_1 != 0) {
        iVar3 = AlarmQueue_802FF750.head;
        iVar2 = (iVar3 != 0) ? iVar3->next : 0;
        while (iVar3 != 0) {
            iVar1 = fn_801CA8A4(iVar3);
            if (iVar1 == 0) {
                fn_801BB7E0(iVar3);
            }
            iVar3 = iVar2;
            iVar2 = (iVar2 != 0) ? iVar2->next : 0;
        }
    }
    return 1;
}

#pragma dont_inline on
extern "C" u32* fn_801BBC1C(u32* param_1, u32* param_2) {
    u32* prev = 0;
    u32* cur = param_1;
    while (cur != 0) {
        if (param_2 <= cur) {
            break;
        }
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
#pragma dont_inline reset
extern "C" u32* fn_801BBC1C(u32* param_1, u32* param_2);
extern "C" void fn_801BBDC4(int param_1, u32* param_2) {
    u32* node = (u32*)((u8*)param_2 - 0x20);
    u32* entry = (u32*)(lbl_802FF758 + param_1 * 0xc);
    u32 head = entry[2];
    if (node[1] != 0) {
        ((u32*)node[1])[0] = node[0];
    }
    if (node[0] == 0) {
        head = node[1];
    } else {
        ((u32*)node[0])[1] = node[1];
    }
    entry[2] = head;
    entry[1] = (u32)fn_801BBC1C((u32*)entry[1], node);
}

extern u32 lbl_802FE960;
extern "C" u32 fn_801BBE40(u32 param_1) {
    u32 old = lbl_802FE960;
    lbl_802FE960 = param_1;
    return old;
}

extern "C" void fn_801BBE50(u32 param_1, u32 param_2, s32 param_3) {
    u32 size = param_3 * 12;
    u32 off = 0;
    s32 i;
    lbl_802FF758 = param_1;
    lbl_802FF75C = param_3;
    for (i = 0; i < lbl_802FF75C; i++) {
        u32* entry = (u32*)(lbl_802FF758 + off);
        entry[0] = -1;
        off += 12;
        entry[2] = 0;
        entry[1] = 0;
    }
    lbl_802FF764 = param_2 & ~0x1f;
    lbl_802FE960 = -1;
    lbl_802FF760 = (lbl_802FF758 + size + 0x1f) & ~0x1f;
}

extern "C" s32 fn_801BBEC0(u32 param_1, u32 param_2) {
    s32 count = lbl_802FF75C;
    u32* entry = (u32*)lbl_802FF758;
    u32* block = (u32*)((param_1 + 0x1f) & ~0x1f);
    s32 i;
    for (i = 0; i < count; i++) {
        if ((s32)entry[0] < 0) {
            entry[0] = (param_2 & ~0x1f) - (u32)block;
            block[0] = 0;
            block[1] = 0;
            block[2] = entry[0];
            entry[1] = (u32)block;
            entry[2] = 0;
            return i;
        }
        entry += 3;
    }
    return -1;
}

