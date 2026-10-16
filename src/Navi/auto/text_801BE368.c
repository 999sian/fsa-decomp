#include "dolphin/os/OSMutex.h"
#include "dolphin/os.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801be368-0x801bf0c8 (21 functions). split_file divides it into the game's real files.

extern "C" void fn_801C13D0(int);
extern "C" OSThread* fn_801C027C(void);
extern "C" void fn_801C05A0(OSThread* owner, OSPriority prio);
extern "C" void fn_801C12E4(OSMutex* mutex);
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

void fn_801BE544(int param_1)
{
    int iVar1;
    int iVar2;

    iVar2 = *(int *)(param_1 + 0x2f4);
    while (iVar2 != 0) {
        iVar1 = *(int *)(iVar2 + 0x10);
        if (iVar1 == 0) {
            *(int *)(param_1 + 0x2f8) = 0;
        }
        else {
            *(int *)(iVar1 + 0x14) = 0;
        }
        *(int *)(param_1 + 0x2f4) = iVar1;
        *(int *)(iVar2 + 0xc) = 0;
        *(int *)(iVar2 + 8) = 0;
        fn_801C13D0(iVar2);
        iVar2 = *(int *)(param_1 + 0x2f4);
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

extern "C" void fn_801BE764(int param_1)
{
    fn_801C13D0(param_1);
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

