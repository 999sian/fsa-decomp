#include "dolphin/os/OSMutex.h"
#include "dolphin/os.h"
#include "dolphin/os/OSCache.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801be368-0x801bf0c8 (21 functions). split_file divides it into the game's real files.

extern "C" void ICFlashInvalidate(void);
extern "C" void Reset(u32 resetCode);

extern "C" void fn_801C13D0(int);
extern "C" OSThread* fn_801C027C(void);
extern "C" void fn_801C05A0(OSThread* owner, OSPriority prio);
extern "C" void fn_801C12E4(OSMutex* mutex);

static u32 lbl_802FF788;
static u32 lbl_802FF78C;
static struct {
    OSResetFunctionInfo* head;
    OSResetFunctionInfo* tail;
} ResetFunctionQueue;

extern "C" void fn_801BE368(OSMutex* mutex)
{
    OSInitThreadQueue(&mutex->queue);
    mutex->thread = nullptr;
    mutex->count = 0;
}

extern "C" void fn_801BE3A0(OSMutex* mutex)
{
	BOOL enabled;
	OSThread* thread;
	OSMutex* tail;

	enabled = OSDisableInterrupts();
	thread = fn_801C027C();
	while (true) {
		if (mutex->thread == nullptr) {
			mutex->thread = thread;
			mutex->count++;
			tail = thread->queueMutex.tail;
			if (tail == nullptr) {
				thread->queueMutex.head = mutex;
			} else {
				tail->link.next = mutex;
			}
			mutex->link.prev = tail;
			mutex->link.next = nullptr;
			thread->queueMutex.tail = mutex;
			break;
		}
		if (mutex->thread == thread) {
			mutex->count++;
			break;
		}
		thread->mutex = mutex;
		fn_801C05A0(mutex->thread, thread->priority);
		fn_801C12E4(mutex);
		thread->mutex = nullptr;
	}
	OSRestoreInterrupts(enabled);
}

extern "C" s32 fn_801C03A4(OSThread* thread);
extern "C" void fn_801BE47C(OSMutex* mutex)
{
    BOOL enabled;
    OSThread* thread;
    OSMutex* prev;
    OSMutex* next;

    enabled = OSDisableInterrupts();
    thread = fn_801C027C();
    if (mutex->thread == thread) {
        if (--mutex->count == 0) {
            prev = mutex->link.next;
            next = mutex->link.prev;
            if (prev == nullptr) {
                thread->queueMutex.tail = next;
            } else {
                prev->link.prev = next;
            }
            if (next == nullptr) {
                thread->queueMutex.head = prev;
            } else {
                next->link.next = prev;
            }
            mutex->thread = nullptr;
            if (*(s32*)((u8*)thread + 0x2d0) < *(s32*)((u8*)thread + 0x2d4)) {
                *(s32*)((u8*)thread + 0x2d0) = fn_801C03A4(thread);
            }
            fn_801C13D0((int)mutex);
        }
    }
    OSRestoreInterrupts(enabled);
}

extern "C" void fn_801BE544(int param_1)
{
    int iVar1;
    int iVar2;

    iVar2 = *(int*)(param_1 + 0x2f4);
    while (iVar2 != 0) {
        iVar1 = *(int*)(iVar2 + 0x10);
        if (iVar1 == 0) {
            *(int*)(param_1 + 0x2f8) = 0;
        } else {
            *(int*)(iVar1 + 0x14) = 0;
        }
        *(int*)(param_1 + 0x2f4) = iVar1;
        *(int*)(iVar2 + 0xc) = 0;
        *(int*)(iVar2 + 8) = 0;
        fn_801C13D0(iVar2);
        iVar2 = *(int*)(param_1 + 0x2f4);
    }
}

extern "C" void fn_801C12E4(OSMutex* mutex);
extern "C" BOOL fn_801BE5B4(OSMutex* mutex)
{
	BOOL enabled;
	OSThread* thread;
	OSMutex* tail;
	BOOL locked;

	enabled = OSDisableInterrupts();
	thread = fn_801C027C();
	if (mutex->thread == nullptr) {
		mutex->thread = thread;
		mutex->count++;
		tail = thread->queueMutex.tail;
		if (tail == nullptr) {
			thread->queueMutex.head = mutex;
		} else {
			tail->link.next = mutex;
		}
		mutex->link.prev = tail;
		mutex->link.next = nullptr;
		thread->queueMutex.tail = mutex;
		locked = TRUE;
	} else if (mutex->thread == thread) {
		mutex->count++;
		locked = TRUE;
	} else {
		locked = FALSE;
	}
	OSRestoreInterrupts(enabled);
	return locked;
}

extern "C" void fn_801BE670(OSThreadQueue* queue)
{
    OSInitThreadQueue(queue);
}

#pragma dont_inline on
extern "C" void fn_801BE690(OSCond* cond, OSMutex* mutex)
{
    BOOL enabled;
    OSThread* thread;
    u32 count;
    OSMutex* prev;
    OSMutex* next;
    u32 pad[3];

    enabled = OSDisableInterrupts();
    thread = fn_801C027C();
    if (mutex->thread == thread) {
        count = mutex->count;
        mutex->count = 0;
        prev = mutex->link.next;
        next = mutex->link.prev;
        if (prev == nullptr) {
            thread->queueMutex.tail = next;
        } else {
            prev->link.prev = next;
        }
        if (next == nullptr) {
            thread->queueMutex.head = prev;
        } else {
            next->link.next = prev;
        }
        mutex->thread = nullptr;
        if (*(s32*)((u8*)thread + 0x2d0) < *(s32*)((u8*)thread + 0x2d4)) {
            *(s32*)((u8*)thread + 0x2d0) = fn_801C03A4(thread);
        }
        OSDisableScheduler();
        fn_801C13D0((int)mutex);
        OSEnableScheduler();
        fn_801C12E4((OSMutex*)cond);
        fn_801BE3A0(mutex);
        mutex->count = count;
    }
    OSRestoreInterrupts(enabled);
}
#pragma dont_inline reset
extern "C" void fn_801C13D0(int param_1);
extern "C" void fn_801BE764(int param_1)
{
	fn_801C13D0(param_1);
}

extern "C" int fn_801BE784(unsigned char** queue)
{
    unsigned char* next;
    unsigned char* thread;
    s32 maxPrio = 0;

    if (queue[0] != 0 && *(unsigned char**)(queue[0] + 0x2e4) != 0) {
        return 0;
    }
    if (queue[1] != 0 && *(unsigned char**)(queue[1] + 0x2e0) != 0) {
        return 0;
    }
    for (thread = queue[0]; thread != 0; thread = next) {
        next = *(unsigned char**)(thread + 0x2e0);
        if (next != 0 && thread != *(unsigned char**)(next + 0x2e4)) {
            return 0;
        }
        if (*(unsigned char**)(thread + 0x2e4) != 0 && thread != *(unsigned char**)(*(unsigned char**)(thread + 0x2e4) + 0x2e0)) {
            return 0;
        }
        if (*(u16*)(thread + 0x2c8) != 4) {
            return 0;
        }
        if (*(s32*)(thread + 0x2d0) < maxPrio) {
            return 0;
        }
        maxPrio = *(s32*)(thread + 0x2d0);
    }
    if (queue[2] != 0) {
        if ((s32)queue[3] <= 0) {
            return 0;
        }
    } else if ((s32)queue[3] != 0) {
        return 0;
    }
    return 1;
}

extern "C" BOOL fn_801BE884(u32 param_1)
{
    u32 iVar1;

    for (iVar1 = *(u32*)(param_1 + 0x2f0); iVar1 != 0 && (iVar1 = *(u32*)(iVar1 + 8)) != 0;
         iVar1 = *(u32*)(iVar1 + 0x2f0)) {
        if (iVar1 == param_1) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL fn_801BE784(int);
extern "C" BOOL fn_801BE8BC(u32 param_1)
{
    u32 iVar1;

    iVar1 = *(u32*)(param_1 + 0x2f4);
    while (iVar1 != 0) {
        if (*(u32*)(iVar1 + 8) != param_1) {
            return FALSE;
        }
        if (fn_801BE784(iVar1) == 0) {
            return FALSE;
        }
        iVar1 = *(u32*)(iVar1 + 0x10);
    }
    return TRUE;
}

extern s32 lbl_802FF790;
extern "C" void fn_801BE940(void)
{
    lbl_802FF790 = 1;
}

extern "C" void fn_801BEC7C(u32 param_1, u32 param_2)
{
    lbl_802FF788 = param_1;
    lbl_802FF78C = param_2;
}

extern "C" void fn_801BEC88(u32* param_1, u32* param_2)
{
    *param_1 = lbl_802FF788;
    *param_2 = lbl_802FF78C;
}

extern "C" void OSRegisterResetFunction(OSResetFunctionInfo* info)
{
    OSResetFunctionInfo* tmp;
    OSResetFunctionInfo* iter;
    OSResetFunctionInfo** tail;

    for (iter = ResetFunctionQueue.head; iter && iter->priority <= info->priority; iter = iter->next) {
        ;
    }

    if (iter == nullptr) {
        tail = &ResetFunctionQueue.head + 1;
        tmp = *tail;
        if (tmp == nullptr) {
            ResetFunctionQueue.head = info;
        } else {
            tmp->next = info;
        }
        info->prev = tmp;
        info->next = nullptr;
        *tail = info;
        return;
    }

    info->next = iter;
    tmp        = iter->prev;
    iter->prev = info;
    info->prev = tmp;
    if (tmp == nullptr) {
        ResetFunctionQueue.head = info;
        return;
    }
    tmp->next = info;
}

extern "C" void fn_801BED90(int param_1)
{
    u16* reg = (u16*)0xcc002000;

    OSDisableInterrupts();
    reg[1] = 0;
    ICFlashInvalidate();
    Reset(param_1 << 3);
}

extern "C" u32 OSGetResetCode(void)
{
    u32 code;

    if (*(u8*)0x800030e2) {
        code = *(u32*)0x800030f0 | 0x80000000;
    } else {
        code = *(u32*)0xcc003024;
        code = (code & ~7) >> 3;
    }
    return code;
}

