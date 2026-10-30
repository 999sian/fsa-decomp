// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801c5d48-0x801ca8dc (109 functions). split_file divides it into the game's real files.
#include "Dolphin/dvd.h"
#include "Dolphin/os.h"
#include "sdk/Dolphin/vec.h"

BOOL __DVDPushWaitingQueue(s32 prio, DVDCommandBlock* block);

typedef struct DVDWACommand {
	s32 type;
	u32 arg0;
	u32 arg1;
	u32 arg2;
	u32 arg3;
} DVDWACommand;

extern DVDWACommand CommandList_802F79D0[];
static s32 NextCommandNumber_802FF85C;
extern "C" void fn_801C6E64(u32 a, u32 b, u32 c, u32 d);
extern "C" void fn_801C728C(u32 a, u32 b);
extern "C" void stateReady(void);

static BOOL autoInvalidation_802FE9B4 = TRUE;
static DVDCommandBlock* executing_802FF880;
static volatile BOOL PauseFlag_802FF88C = FALSE;
static volatile BOOL PausingFlag_802FF890 = FALSE;
static volatile BOOL FatalErrorFlag_802FF898 = FALSE;
extern DVDCommandBlock DummyCommandBlock_802F7AE0;
static volatile BOOL ResetRequired_802FF8B8;
static vu32 ResumeFromHere_802FF8A8;
static u32 lbl_802FF8B4;
static u32 lbl_802FF8A0;
static DVDCBCallback lbl_802FF8A4;
static BOOL StopAtNextInt_802FF818;
extern char AlarmForTimeout_802F7A38[];
extern "C" void AlarmHandlerForTimeout(OSAlarm* alarm, OSContext* context);
static DVDLowCallback Callback_802FF820;
static volatile BOOL WaitingCoverClose_802FF834;
static u32 WorkAroundType_802FF83C;
static u32 WorkAroundSeekLocation_802FF840;
static void (*lbl_802FF8C4)(DVDCommandBlock*);
static u8* IDShouldBe_802FF884;
extern s32 CurrCommand_802FF89C;
extern char lbl_802F7AC0[];
extern char BB2_802F7AA0[];
extern "C" BOOL fn_801C76C8(s32 a, u32 b, void* cb);
extern "C" void fn_801C8E54(u32 param_1);
extern "C" void stateBusy_801C943C(DVDCommandBlock* block);
extern "C" void fn_801C8D70(u32 param_1);
extern "C" void fn_801C8278(DVDCommandBlock* block);
extern "C" void fn_801C830C(void);
extern char lbl_8029D3C4[];
extern char lbl_802FE9BC[6];
extern "C" void fn_801C6FF4(void* a, s32 b, s32 c, void* cb);
extern "C" void fn_801C9060(DVDCommandBlock* block);
extern "C" void fn_801C8554(u32 result);
extern "C" void fn_801C8C24(DVDCommandBlock* block);

void DVDLowReset(void);
extern "C" BOOL fn_801CA33C(DVDCommandBlock* block, DVDCBCallback callback);
extern "C" void fn_801CA664(s32 result, DVDCommandBlock* block);
extern "C" void fn_801C12E4(OSThreadQueue* queue);
extern "C" void fn_801C13D0(OSThreadQueue* queue);
extern OSThreadQueue __DVDThreadQueue;
extern char lbl_802FE9A8[];
extern char lbl_8029D308[];
extern "C" void fn_80007AB8(const char*, int, const char*, ...);
extern "C" BOOL fn_801C9D94(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, DVDCallback callback, s32 prio);

extern "C" void cbForStateError(u32 intType);
extern "C" void __DVDStoreErrorCode(u32 code);
extern "C" BOOL DVDLowStopMotor(DVDLowCallback callback);
extern "C" void fn_801C747C(void (*callback)(u32));
extern "C" void fn_801C88E8(void);
extern "C" void fn_801C8850(u32 param_1);
extern "C" void* memcpy(void* dst, const void* src, unsigned long n);
extern "C" BOOL fn_801CAC6C(void* a, DVDDiskID* b);
extern "C" void fn_801C8B7C(DVDCommandBlock* block);
extern "C" s32 fn_801E3C54(void* a, void* b, s32 c);
extern "C" void fn_801C8C5C(u32 intType);

static BOOL issueCommand(s32 prio, DVDCommandBlock* block)
{
	BOOL level;
	BOOL result;

	if (autoInvalidation_802FE9B4 && (block->command == 1 || block->command == 4 || block->command == 5 || block->command == 14)) {
		DCInvalidateRange(block->addr, block->length);
	}

	level = OSDisableInterrupts();

	block->state = 2;
	result = __DVDPushWaitingQueue(prio, block);

	if ((executing_802FF880 == nullptr) && (PauseFlag_802FF88C == FALSE)) {
		stateReady();
	}

	OSRestoreInterrupts(level);
	return result;
}

extern u8* FstStart_802FF864;
extern s32 MaxEntryNum_802FF86C;
extern "C" float fn_801EA270(f32 x);
extern "C" float fn_801EA294(f32 x);
extern "C" void fn_801C5FDC(void* dst, s32 axis, f32 x, f32 y);

extern "C" u32 fn_801C5E74(const f32 src[3][4], f32 inv[3][4]) {
    f32 det = src[0][0] * (src[1][1] * src[2][2] - src[1][2] * src[2][1]) - src[0][1] * (src[1][0] * src[2][2] - src[1][2] * src[2][0]) + src[0][2] * (src[1][0] * src[2][1] - src[1][1] * src[2][0]);
    if (det == 0.0f) {
        return 0;
    }
    f32 inv_det = 1.0f / det;
    inv[0][0] = (src[1][1] * src[2][2] - src[1][2] * src[2][1]) * inv_det;
    inv[0][1] = (src[0][2] * src[2][1] - src[0][1] * src[2][2]) * inv_det;
    inv[0][2] = (src[0][1] * src[1][2] - src[0][2] * src[1][1]) * inv_det;
    inv[1][0] = (src[1][2] * src[2][0] - src[1][0] * src[2][2]) * inv_det;
    inv[1][1] = (src[0][0] * src[2][2] - src[0][2] * src[2][0]) * inv_det;
    inv[1][2] = (src[0][2] * src[1][0] - src[0][0] * src[1][2]) * inv_det;
    inv[2][0] = (src[1][0] * src[2][1] - src[1][1] * src[2][0]) * inv_det;
    inv[2][1] = (src[0][1] * src[2][0] - src[0][0] * src[2][1]) * inv_det;
    inv[2][2] = (src[0][0] * src[1][1] - src[0][1] * src[1][0]) * inv_det;
    inv[0][3] = -(inv[0][0] * src[0][3] + inv[0][1] * src[1][3] + inv[0][2] * src[2][3]);
    inv[1][3] = -(inv[1][0] * src[0][3] + inv[1][1] * src[1][3] + inv[1][2] * src[2][3]);
    inv[2][3] = -(inv[2][0] * src[0][3] + inv[2][1] * src[1][3] + inv[2][2] * src[2][3]);
    return 1;
}

extern "C" void fn_801C5F6C(void* dst, s32 axis, f32 v) {
    f64 pad;
    f32 a = fn_801EA270(v);
    f32 b = fn_801EA294(v);
    fn_801C5FDC(dst, axis, a, b);
}

extern "C" float fn_801EA24C(double x);
extern f32 lbl_80301E38;
extern f32 lbl_80301E3C;
extern f32 lbl_80301E40;
extern f32 lbl_80301E4C;
extern f32 lbl_80301E50;
#pragma fp_contract off
extern "C" void fn_801C64DC(float* m, float fovy, float aspect, float sx, float sy, float tx, float ty)
{
    float inv = 1.0f / fn_801EA24C(0.017453292f * (0.5f * fovy));
    m[0] = sx * (inv / aspect);
    m[1] = 0.0f;
    m[2] = -tx;
    m[3] = 0.0f;
    m[4] = 0.0f;
    m[5] = inv * sy;
    m[6] = -ty;
    m[7] = 0.0f;
    m[8] = 0.0f;
    m[9] = 0.0f;
    m[10] = -1.0f;
    m[11] = 0.0f;
}
#pragma fp_contract on
extern "C" void fn_801C65A8(float *m, float y0, float y1, float x0, float x1, float sx, float sy, float ox, float oy)
{
    float tmp;

    tmp = 1.0f / (x1 - x0);
    m[0] = (2.0f * tmp * sx);
    m[1] = 0.0f;
    m[2] = 0.0f;
    m[3] = ((-(x1 + x0) * tmp) * sx) + ox;

    tmp = 1.0f / (y0 - y1);
    m[4] = 0.0f;
    m[5] = (2.0f * tmp) * sy;
    m[6] = 0.0f;
    m[7] = ((-(y0 + y1) * tmp) * sy) + oy;

    m[8] = 0.0f;
    m[9] = 0.0f;
    m[10] = 0.0f;
    m[11] = 1.0f;
}

extern f32 lbl_80301E58;
extern f32 lbl_80301E60;
extern f32 lbl_80301E64;
extern f32 lbl_80301E68;
extern f32 lbl_80301E6C;
extern "C" void fn_801C6760(float* m, float a, float b, float c, float d) {
    float t = lbl_80301E58 / fn_801EA24C(lbl_80301E6C * (lbl_80301E68 * a));
    float u = lbl_80301E58 / (d - c);
    m[0] = t / b;
    m[1] = lbl_80301E60;
    m[2] = lbl_80301E60;
    m[3] = lbl_80301E60;
    m[4] = lbl_80301E60;
    m[5] = t;
    m[6] = lbl_80301E60;
    m[7] = lbl_80301E60;
    m[8] = lbl_80301E60;
    m[9] = lbl_80301E60;
    m[10] = -c * u;
    m[11] = u * -(d * c);
    m[12] = lbl_80301E60;
    m[13] = lbl_80301E60;
    m[14] = lbl_80301E64;
    m[15] = lbl_80301E60;
}

#pragma fp_contract reset
extern "C" void fn_801C6830(f32* m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f)
{
	f32 tmp;

	tmp = 1.0f / (r - l);
	m[0] = 2.0f * tmp;
	m[1] = 0.0f;
	m[2] = 0.0f;
	m[3] = -(r + l) * tmp;
	tmp = 1.0f / (t - b);
	m[4] = 0.0f;
	m[5] = 2.0f * tmp;
	m[6] = 0.0f;
	m[7] = -(t + b) * tmp;
	tmp = 1.0f / (f - n);
	m[8] = 0.0f;
	m[9] = 0.0f;
	m[10] = -2.0f * tmp;
	m[11] = -f * tmp;
	m[12] = 0.0f;
	m[13] = 0.0f;
	m[14] = 0.0f;
	m[15] = 1.0f;
}

extern "C" f32 fn_801C6A28(const Vec* vec1, const Vec* vec2)
{
    f32 dx = vec1->x - vec2->x;
    f32 dy = vec1->y - vec2->y;
    f32 dz = vec1->z - vec2->z;
    return dx * dx + dy * dy + dz * dz;
}

extern "C" void __DVDInitWA(void)
{
	NextCommandNumber_802FF85C = 0;
	CommandList_802F79D0[0].type = -1;
	__DVDLowSetWAType(0, 0);
	OSInitAlarm();
}

extern "C" void fn_801C6D70(void)
{
	DVDWACommand* cmd = &CommandList_802F79D0[NextCommandNumber_802FF85C];
	if (cmd->type == 1) {
		NextCommandNumber_802FF85C++;
		fn_801C6E64(cmd->arg0, cmd->arg1, cmd->arg2, cmd->arg3);
	} else if (cmd->type == 2) {
		NextCommandNumber_802FF85C++;
		fn_801C728C(cmd->arg2, cmd->arg3);
	}
}

extern "C" BOOL DVDLowWaitCoverClose(DVDLowCallback cb)
{
	vu32* di;

	Callback_802FF820 = cb;
	di = (vu32*)0xCC006000;
	WaitingCoverClose_802FF834 = TRUE;
	StopAtNextInt_802FF818 = FALSE;
	di[1] = 2;
	return TRUE;
}

extern "C" BOOL fn_801C734C(u32 param_1, DVDLowCallback cb)
{
	vu32* di;
	OSAlarm* alarm;
	u32 timeout;

	Callback_802FF820 = cb;
	StopAtNextInt_802FF818 = FALSE;
	di = (vu32*)0xCC006000;
	di[2] = 0xA8000040;
	di[3] = 0;
	di[4] = 0x20;
	di[5] = param_1;
	di[6] = 0x20;
	di[7] = 3;
	alarm = (OSAlarm*)AlarmForTimeout_802F7A38;
	timeout = (*(u32*)0x800000F8 >> 2) * 10;
	OSCreateAlarm(alarm);
	OSSetAlarm(alarm, timeout, AlarmHandlerForTimeout);
	return TRUE;
}

extern "C" BOOL DVDLowStopMotor(DVDLowCallback cb)
{
	vu32* di;
	OSAlarm* alarm;
	u32 timeout;
	f64 pad;

	Callback_802FF820 = cb;
	di = (vu32*)0xCC006000;
	StopAtNextInt_802FF818 = FALSE;
	di[2] = 0xe3000000;
	di[7] = 1;
	alarm = (OSAlarm*)AlarmForTimeout_802F7A38;
	timeout = (*(u32*)0x800000F8 >> 2) * 10;
	OSCreateAlarm(alarm);
	OSSetAlarm(alarm, timeout, AlarmHandlerForTimeout);
	return TRUE;
}

extern "C" void fn_801C747C(void (*callback)(u32))
{
	vu32* di;
	OSAlarm* alarm;
	OSTime timeout;

	Callback_802FF820 = (DVDLowCallback)callback;
	StopAtNextInt_802FF818 = FALSE;
	di = (vu32*)0xCC006000;
	di[2] = 0xe0000000;
	di[7] = 1;
	alarm = (OSAlarm*)AlarmForTimeout_802F7A38;
	timeout = (*(u32*)0x800000F8 >> 2) * 10;
	OSCreateAlarm(alarm);
	OSSetAlarm(alarm, timeout, AlarmHandlerForTimeout);
}

extern "C" BOOL fn_801C763C(u32 a, DVDLowCallback cb)
{
	vu32* di;
	OSAlarm* alarm;
	u32 timeout;
	f64 pad;

	Callback_802FF820 = cb;
	StopAtNextInt_802FF818 = FALSE;
	di = (vu32*)0xCC006000;
	di[2] = a | 0xe2000000;
	di[7] = 1;
	alarm = (OSAlarm*)AlarmForTimeout_802F7A38;
	timeout = (*(u32*)0x800000F8 >> 2) * 10;
	OSCreateAlarm(alarm);
	OSSetAlarm(alarm, timeout, AlarmHandlerForTimeout);
	return TRUE;
}

extern "C" BOOL fn_801C76C8(s32 a, u32 b, void* cb)
{
	vu32* di;
	OSAlarm* alarm;
	u32 timeout;

	Callback_802FF820 = (DVDLowCallback)cb;
	StopAtNextInt_802FF818 = FALSE;
	if (a != 0) {
		di = (vu32*)0xCC006000;
		di[2] = b | 0x10000 | 0xe4000000;
		di[7] = 1;
		alarm = (OSAlarm*)AlarmForTimeout_802F7A38;
		timeout = (*(u32*)0x800000F8 >> 2) * 10;
		OSCreateAlarm(alarm);
		OSSetAlarm(alarm, timeout, AlarmHandlerForTimeout);
	}
	return TRUE;
}

extern "C" DVDLowCallback fn_801C7834(void)
{
	DVDLowCallback callback;
	((vu32*)0xCC006000)[1] = 0;
	callback = Callback_802FF820;
	WaitingCoverClose_802FF834 = FALSE;
	Callback_802FF820 = NULL;
	return callback;
}

extern "C" void __DVDLowSetWAType(u32 type, u32 location)
{
	BOOL enabled;
	enabled = OSDisableInterrupts();
	WorkAroundType_802FF83C = type;
	WorkAroundSeekLocation_802FF840 = location;
	OSRestoreInterrupts(enabled);
}

extern char lbl_802F7A60[];
extern char AlarmForTimeout_802F7A38[];
extern "C" BOOL fn_801C7894(u32 param_1)
{
	if (param_1 == (u32)lbl_802F7A60 || param_1 == (u32)AlarmForTimeout_802F7A38) {
		return TRUE;
	}
	return FALSE;
}

extern "C" BOOL fn_801C7BF8(s32 entryNum, DVDFileInfo* fileInfo)
{
	if (entryNum >= 0 && (u32)entryNum < (u32)MaxEntryNum_802FF86C) {
		u32* entry = (u32*)(FstStart_802FF864 + entryNum * 0xc);
		BOOL isDir = (entry[0] & 0xff000000) != 0;
		if (!isDir) {
			fileInfo->startAddr = entry[1];
			fileInfo->length = entry[2];
			fileInfo->callback = NULL;
			fileInfo->cb.state = 0;
			return TRUE;
		}
	}
	return FALSE;
}

extern "C" BOOL fn_801C7EB8(char* path, u32 maxlen);
extern "C" s32 fn_801C7904(char* path);
extern char lbl_8029D2D0[];
extern "C" BOOL fn_801C7C6C(char* path, DVDFileInfo* fileInfo)
{
	char buf[0x80];
	s32 entryNum = fn_801C7904(path);
	if (entryNum < 0) {
		fn_801C7EB8(buf, 0x80);
		OSReport(lbl_8029D2D0, path, buf);
		return FALSE;
	}
	u32* entry = (u32*)(FstStart_802FF864 + entryNum * 0xc);
	if ((entry[0] & 0xff000000) == 0) {
		fileInfo->startAddr = entry[1];
		fileInfo->length = entry[2];
		fileInfo->callback = NULL;
		fileInfo->cb.state = 0;
		return TRUE;
	}
	return FALSE;
}

extern "C" s32 fn_801CA5B8(DVDCommandBlock* block);
extern "C" void fn_801C803C(s32 result, DVDFileInfo* fileInfo);
extern "C" BOOL fn_801C7D34(DVDCommandBlock* block)
{
	fn_801CA5B8(block);
	return TRUE;
}

extern u32 lbl_802FF870;
extern "C" u32 fn_801C7D58(u32 entry, char* path, u32 maxlen);
extern "C" BOOL fn_801C7EB8(char* path, u32 maxlen) {
    u32 entry = lbl_802FF870;
    u32 len = fn_801C7D58(entry, path, maxlen);
    if (len == maxlen) {
        path[maxlen - 1] = 0;
        return FALSE;
    }
    if ((*(u32*)(FstStart_802FF864 + entry * 0xc) & 0xff000000) ? TRUE : FALSE) {
        if (len == maxlen - 1) {
            path[len] = 0;
            return FALSE;
        }
        path[len] = '/';
        len++;
    }
    path[len] = 0;
    return TRUE;
}

extern "C" BOOL fn_801C7F7C(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, DVDCallback callback, s32 prio)
{
	if (offset < 0 || offset > fileInfo->length) {
		fn_80007AB8(lbl_802FE9A8, 0x2ee, lbl_8029D308);
	}
	if (offset + length < 0 || offset + length >= fileInfo->length + 0x20) {
		fn_80007AB8(lbl_802FE9A8, 0x2f4, lbl_8029D308);
	}
	fileInfo->callback = callback;
	fn_801C9D94(fileInfo, addr, length, fileInfo->startAddr + offset, fn_801C803C, prio);
	return TRUE;
}

extern "C" void fn_80007AB8(const char*, int, const char*, ...);
extern char lbl_802FE9A8[];
extern char lbl_8029D308[];
extern "C" BOOL fn_801C9D94(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, DVDCallback callback, s32 prio);
extern "C" void fn_801C803C(s32 result, DVDFileInfo* fileInfo)
{
	if (fileInfo->callback != NULL) {
		fileInfo->callback(result, fileInfo);
	}
}

extern "C" void fn_801C8184(void)
{
	fn_801C13D0(&__DVDThreadQueue);
}

extern "C" void fn_801C81A8(void) {}

static BOOL DVDInitialized_802FF8C0;
static u8* bootInfo_802FF888;
static BOOL FirstTimeInBootrom_802FF8BC;
extern "C" char* __DVDVersion;
extern "C" void __DVDFSInit(void);
extern "C" void __DVDClearWaitingQueue(void);
extern "C" void __DVDInterruptHandler(__OSInterrupt interrupt, OSContext* context);
extern "C" void __fstLoad(void);
extern "C" void DVDInit(void) {
    if (!DVDInitialized_802FF8C0) {
        OSRegisterVersion(__DVDVersion);
        DVDInitialized_802FF8C0 = TRUE;
        __DVDFSInit();
        __DVDClearWaitingQueue();
        __DVDInitWA();
        bootInfo_802FF888 = (u8*)0x80000000;
        IDShouldBe_802FF884 = (u8*)0x80000000;
        __OSSetInterruptHandler(21, __DVDInterruptHandler);
        __OSUnmaskInterrupts(0x400);
        OSInitThreadQueue(&__DVDThreadQueue);
        *(vu32*)0xCC006000 = 0x2a;
        *(vu32*)0xCC006004 = 0;
        if (*(u32*)(bootInfo_802FF888 + 0x20) == 0xE5207C22) {
            OSReport("load fst\n");
            __fstLoad();
        } else if (*(u32*)(bootInfo_802FF888 + 0x20) != 0x0D15EA5E) {
            FirstTimeInBootrom_802FF8BC = TRUE;
        }
    }
}

extern "C" void fn_801C8478(void)
{
	fn_801C747C(fn_801C8554);
}

extern "C" void fn_801C87E8(u32 param_1)
{
	if (param_1 == 0x10) {
		executing_802FF880->state = -1;
		__DVDStoreErrorCode(0x1234568);
		DVDReset();
		cbForStateError(0);
	} else if (param_1 & 1) {
		fn_801C88E8();
	} else {
		fn_801C747C(fn_801C8850);
	}
}

extern "C" void fn_801C8850(u32 param_1)
{
	if (param_1 == 0x10) {
		executing_802FF880->state = -1;
		__DVDStoreErrorCode(0x1234568);
		DVDReset();
		cbForStateError(0);
	} else {
		executing_802FF880->state = -1;
		if (param_1 & 2) {
			__DVDStoreErrorCode(0x1234567);
			DVDLowStopMotor(cbForStateError);
		} else {
			__DVDStoreErrorCode(((vu32*)0xCC006000)[8]);
			DVDLowStopMotor(cbForStateError);
		}
	}
}

extern "C" void fn_801C8B48(DVDCommandBlock* block);
#pragma dont_inline on
extern "C" void fn_801C8A68(void) {
    char* base = BB2_802F7AA0;

    switch (CurrCommand_802FF89C) {
    case 3:
        if (fn_801CAC6C(base + 0x20, executing_802FF880->id) != 0) {
            memcpy(IDShouldBe_802FF884, base + 0x20, 0x20);
            executing_802FF880->state = 1;
            DCInvalidateRange(base, 0x20);
            lbl_802FF8C4 = fn_801C8B7C;
            fn_801C8B7C(executing_802FF880);
        } else {
            DVDLowStopMotor(fn_801C8C5C);
        }
        break;
    default:
        if (fn_801E3C54(base + 0x20, IDShouldBe_802FF884, 0x20) != 0) {
            DVDLowStopMotor(fn_801C8C5C);
        } else {
            lbl_802FF8C4 = fn_801C8B48;
            fn_801C8B48(executing_802FF880);
        }
        break;
    }
}
#pragma dont_inline on
extern "C" void fn_801C8B48(DVDCommandBlock* block) {
    fn_801C76C8(((u8*)IDShouldBe_802FF884)[8], 10, fn_801C8E54);
}
#pragma dont_inline reset
extern "C" void fn_801C8C24(DVDCommandBlock* block) {
    fn_801C6FF4(BB2_802F7AA0, 0x20, 0x420, fn_801C8D70);
}

#pragma dont_inline on
extern "C" void fn_801C8D70(u32 param_1)
{
	if (param_1 == 0x10) {
		executing_802FF880->state = -1;
		__DVDStoreErrorCode(0x1234568);
		DVDReset();
		cbForStateError(0);
	} else if (param_1 & 1) {
		u32* p = (u32*)(BB2_802F7AA0 + 8);
		lbl_802FF8C4 = fn_801C8278;
		lbl_802FF8B4 = 0;
		if (*(u32*)(bootInfo_802FF888 + 0x3c) < *p) {
			fn_80007AB8(0, 0x28a, lbl_8029D3C4);
		}
		fn_801C6FF4((void*)*(u32*)(bootInfo_802FF888 + 0x38), (*p + 0x1f) & ~0x1f, *(u32*)(BB2_802F7AA0 + 4), fn_801C830C);
	} else {
		fn_801C747C(fn_801C8554);
	}
}

extern "C" void fn_801C8E54(u32 param_1)
{
	DVDCommandBlock* block;
	s32 ready;

	if (param_1 == 0x10) {
		executing_802FF880->state = DVD_STATE_FATAL_ERROR;
		__DVDStoreErrorCode(0x1234568);
		DVDReset();
		cbForStateError(0);
	} else if (param_1 & 1) {
		lbl_802FF8B4 = 0;
		ready = 0;
		if (lbl_802FF8A0 != 0) {
			ResumeFromHere_802FF8A8 = 0;
			block = executing_802FF880;
			lbl_802FF8A0 = 0;
			executing_802FF880 = &DummyCommandBlock_802F7AE0;
			block->state = DVD_STATE_CANCELED;
			if (block->callback) {
				(block->callback)(DVD_RESULT_CANCELED, block);
			}
			if (lbl_802FF8A4) {
				(lbl_802FF8A4)(0, block);
			}
			stateReady();
			ready = 1;
		}
		if (ready == 0) {
			executing_802FF880->state = DVD_STATE_BUSY;
			stateBusy_801C943C(executing_802FF880);
		}
	} else {
		fn_801C747C(fn_801C8554);
	}
}

#pragma dont_inline reset
extern "C" void AlarmHandler(void) {
    DVDReset();
    DCInvalidateRange(lbl_802F7AC0, 0x20);
    DVDCommandBlock* block = executing_802FF880;
    lbl_802FF8C4 = fn_801C9060;
    fn_801C9060(block);
}

s32 CurrCommand_802FF89C;
extern "C" void fn_801C8F94(void)
{
	char* base = BB2_802F7AA0;
	DVDCommandBlock* old;
	DVDCBCallback callback;

	switch (CurrCommand_802FF89C) {
	case 4:
	case 5:
	case 13:
	case 15:
		__DVDClearWaitingQueue();
		old = executing_802FF880;
		executing_802FF880 = (DVDCommandBlock*)(base + 0x40);
		callback = old->callback;
		if (callback != nullptr) {
			callback(-4, old);
		}
		stateReady();
		break;
	default:
		DVDReset();
		OSCreateAlarm((OSAlarm*)(base + 0x70));
		OSSetAlarm((OSAlarm*)(base + 0x70), OSMillisecondsToTicks(1150), (OSAlarmHandler)AlarmHandler);
		break;
	}
}

extern "C" void cbForStateMotorStopped(void)
{
	char* base = BB2_802F7AA0;
	DVDCommandBlock* old;
	volatile s32 state;

	*(vu32*)0xCC006004 = 0;
	executing_802FF880->state = 3;
	switch (CurrCommand_802FF89C) {
	case 4:
	case 5:
	case 13:
	case 15:
		__DVDClearWaitingQueue();
		old = executing_802FF880;
		executing_802FF880 = (DVDCommandBlock*)(base + 0x40);
		if (old->callback != nullptr) {
			old->callback(-4, old);
		}
		stateReady();
		break;
	default:
		DVDReset();
		OSCreateAlarm((OSAlarm*)(base + 0x70));
		OSSetAlarm((OSAlarm*)(base + 0x70), OSMillisecondsToTicks(1150), (OSAlarmHandler)AlarmHandler);
		break;
	}
}

BOOL fn_801C9D94(DVDCommandBlock* block, void* addr, s32 length, s32 offset, DVDCBCallback callback, s32 prio) {
    BOOL level;
    BOOL result;

    block->command = 1;
    block->addr = addr;
    block->length = length;
    block->offset = offset;
    block->transferredSize = 0;
    block->callback = callback;

    if (autoInvalidation_802FE9B4 && (block->command == 1 || block->command == 4 || block->command == 5 || block->command == 14)) {
        DCInvalidateRange(block->addr, block->length);
    }

    level = OSDisableInterrupts();

    block->state = 2;
    result = __DVDPushWaitingQueue(prio, block);

    if ((executing_802FF880 == nullptr) && (PauseFlag_802FF88C == FALSE)) {
        stateReady();
    }

    OSRestoreInterrupts(level);
    return result;
}

extern "C" BOOL DVDReadAbsAsyncForBS(DVDCommandBlock* block, void* addr, s32 length, s32 offset, DVDCBCallback callback)
{
    BOOL idle;
    block->command = 4;
    block->addr = addr;
    block->length = length;
    block->offset = offset;
    block->transferredSize = 0;
    block->callback = callback;

    idle = issueCommand(2, block);
    return idle;
}

static BOOL issueCommand(s32 prio, DVDCommandBlock* block);
extern "C" BOOL DVDReadDiskID(DVDCommandBlock* block, DVDDiskID* diskID, DVDCBCallback callback)
{
	block->command = 5;
	block->addr = diskID;
	block->length = 0x20;
	block->offset = 0;
	block->transferredSize = 0;
	block->callback = callback;
	return issueCommand(2, block);
}

extern "C" BOOL fn_801CA014(DVDCommandBlock* block, DVDCBCallback callback)
{
	BOOL idle;

	block->command = 7;
	block->callback = callback;

	idle = issueCommand(1, block);
	return idle;
}

BOOL DVDInquiryAsync(DVDCommandBlock* block, DVDDriveInfo* info, DVDCBCallback callback)
{
	BOOL idle;

	block->command         = 14;
	block->addr            = (void*)info;
	block->length          = sizeof(DVDDriveInfo);
	block->transferredSize = 0;
	block->callback        = callback;

	idle = issueCommand(2, block);

	return idle;
}

void DVDReset(void)
{
	DVDLowReset();
	__DIRegs[DI_STATUS] = 42;
	__DIRegs[DI_COVER_STATUS] = __DIRegs[DI_COVER_STATUS];
	ResetRequired_802FF8B8 = FALSE;
	ResumeFromHere_802FF8A8 = 0;
}

extern "C" u32 fn_801CA2DC(u32 param_1) {
    u32 old = autoInvalidation_802FE9B4;
    autoInvalidation_802FE9B4 = param_1;
    return old;
}

extern "C" s32 fn_801CA5B8(DVDCommandBlock* block)
{
	BOOL level;
	s32 state;
	DVDCommandBlock* local = block;

	if (fn_801CA33C(local, fn_801CA664) == 0) {
		return -1;
	}

	level = OSDisableInterrupts();
	while (TRUE) {
		state = local->state;
		if (state + 1U <= 1 || state == 10) {
			break;
		}
		if (state == 3 && (local->command - 4U <= 1 || local->command == 13 || local->command == 15)) {
			break;
		}
		fn_801C12E4(&__DVDThreadQueue);
	}
	OSRestoreInterrupts(level);
	return 0;
}

extern "C" u32 fn_801CA688(void)
{
	return 0x80000000;
}

extern "C" BOOL fn_801CA690(void) {
    BOOL enabled;
    BOOL result;
    s32 state;
    u32 coverReg;

    enabled = OSDisableInterrupts();

    if (FatalErrorFlag_802FF898) {
        state = -1;
    } else if (PausingFlag_802FF890) {
        state = 8;
    } else {
        if (executing_802FF880 == nullptr) {
            state = 0;
        } else if (executing_802FF880 == &DummyCommandBlock_802F7AE0) {
            state = 0;
        } else {
            state = executing_802FF880->state;
        }
    }

    switch (state) {
    case 1:
    case 9:
    case 10:
    case 2:
        result = TRUE;
        break;

    case -1:
    case 11:
    case 7:
    case 3:
    case 4:
    case 5:
    case 6:
        result = FALSE;
        break;

    case 0:
    case 8:
        coverReg = __DIRegs[1];
        if (((coverReg >> 2) & 1) || (coverReg & 1)) {
            result = FALSE;
        } else if (ResumeFromHere_802FF8A8 != 0) {
            result = FALSE;
        } else {
            result = TRUE;
        }
    }

    OSRestoreInterrupts(enabled);

    return result;
}

