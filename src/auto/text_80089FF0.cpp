#include "dolphin/os.h"
#include "dolphin/base/PPCArch.h"
#include "JSystem/JSupport/JSUList.h"
#include "JSystem/JUtility/JUTException.h"
#include "JSystem/JUtility/JUTConsole.h"
#include "JSystem/JUtility/JUTDirectPrint.h"
#include "JSystem/JUtility/JUTExternalFB.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" JUTConsole* lbl_8053A914;
extern "C" char lbl_8045E934[];
extern "C" BOOL fn_8008C528(char* param_1, u32 param_2, s32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u8 param_9);
extern JSUPtrList lbl_8052E894;
extern "C" u8 lbl_804BA1D0[];
extern "C" void fn_8008A220(u16 param_1, OSContext* param_2, u32 param_3, u32 param_4);
extern "C" void fn_8008A4C4(unsigned int param_1);
extern "C" unsigned int lbl_8053A904;
extern "C" unsigned int lbl_8053A908;
extern "C" JUTException* lbl_8053A900;
extern "C" void* __nw__FUlP7JKRHeapi(size_t size, JKRHeap* heap, int align);
extern "C" void __ct__9JKRThreadFUlii(JKRThread* this_, u32 stackSize, int msgCount, int threadPriority);
extern "C" u32 lbl_8053A918;
extern "C" u32 lbl_8053A91C;
extern "C" u8 lbl_804BA1B0[];
extern "C" OSMessageQueue lbl_80499390;
extern "C" void fn_8008C308(s32 param_1);
extern char lbl_8045E878[];
static int fpKind(f32 value)
{
    u32 bits = *(u32*)&value;
    s32 exp = bits & 0x7f800000;
    int kind;
    if (exp == 0x7f800000) {
        if ((bits & 0x7fffff) == 0) {
            kind = 2;
        } else {
            kind = 1;
        }
    } else if (exp < 0x7f800000 && exp == 0) {
        if ((bits & 0x7fffff) == 0) {
            kind = 3;
        } else {
            kind = 5;
        }
    } else {
        kind = 4;
    }
    return kind;
}

static void showFloat(f32 value, int col)
{
    int kind = fpKind(value);
    if (kind == 1) {
        lbl_8053A914->print_f(lbl_8045E878 + 0xd4, col);
    } else {
        kind = fpKind(value);
        if (kind == 2) {
            u8 sign = *(u8*)&value;
            if (sign & 0x80) {
                lbl_8053A914->print_f(lbl_8045E878 + 0xe8, col);
            } else {
                lbl_8053A914->print_f(lbl_8045E878 + 0xf8, col);
            }
        } else if (value == 0.0f) {
            lbl_8053A914->print_f(lbl_8045E878 + 0x108, col);
        } else {
            lbl_8053A914->print_f(lbl_8045E878 + 0x11c, col, value);
        }
    }
}
extern "C" void* __nw__FUlP7JKRHeapi(size_t size, JKRHeap* heap, int align);
extern void* lbl_80499414[];
extern "C" void __ct__9JKRThreadFUlii(JKRThread* this_, u32 stackSize, int msgCount, int threadPriority);
JUTException* JUTException::create(JUTDirectPrint* directPrint)
{
    extern void* lbl_80499414[];

    if (lbl_8053A900 == nullptr) {
        JUTException* manager = (JUTException*)__nw__FUlP7JKRHeapi(sizeof(JUTException), JKRGetSystemHeap(), 0);
        if (manager != nullptr) {
            __ct__9JKRThreadFUlii(manager, 0x4000, 0x10, 0);
            *(void**)manager = lbl_80499414;
            manager->mDirectPrint = directPrint;

            OSSetErrorHandler(OS_ERROR_DSI, (OSErrorHandler)fn_8008A220);
            OSSetErrorHandler(OS_ERROR_ISI, (OSErrorHandler)fn_8008A220);
            OSSetErrorHandler(OS_ERROR_PROGRAM, (OSErrorHandler)fn_8008A220);
            OSSetErrorHandler(OS_ERROR_ALIGNMENT, (OSErrorHandler)fn_8008A220);
            OSSetErrorHandler(OS_ERROR_PROTECTION, (OSErrorHandler)fn_8008A220);
            fn_8008A4C4(0);

            lbl_8053A904 = 0;
            lbl_8053A908 = 0;
            manager->mGamePad = nullptr;
            manager->mPadPort = JUTGamePad::Port_Invalid;
            manager->mPrintWaitTime0 = 10;
            manager->mPrintWaitTime1 = 10;
            manager->mTraceSuppress = 0xffffffff;
            manager->_98 = 0;
            manager->mPrintFlags = EXPRINTFLAG_All;
        }
        lbl_8053A900 = manager;
        lbl_8053A900->resume();
    }
    return lbl_8053A900;
}

extern "C" void fn_8008C390(JUTException* this_);
extern "C" void fn_8008BE24(JUTException* this_, u16 param_1, OSContext* param_2, u32 param_3, u32 param_4);
struct FSAPad {
    u8 _00[0x18];
    u32 _18;
    u32 _1c;
    u8 _20[0x5c];
    s16 _7c;
    u8 _7e[0x1a];
    u8 _98;
    u8 _99[0x17];
};
extern "C" u64 lbl_804993B0[4];
extern "C" void fn_8008CF54(FSAPad* this_, s32 index);
extern "C" void fn_8008D4CC(FSAPad* this_, s64 elapsed);
extern "C" void dtor_8008D028(FSAPad* this_, s16 freeFlag);
extern "C" u32 fn_8008D15C(void);
extern "C" BOOL fn_8008B8B4(JUTException* this_, u32* param_1, u32* param_2);
extern "C" void fn_8008A100(JUTException* this_)
{
    extern JUTException* lbl_8053A900;
    extern void* lbl_80539D90;

    PPCMtmsr(PPCMfmsr() & ~0x900);
    OSInitMessageQueue(&lbl_80499390, &lbl_80539D90, 1);
    while (true)
    {
        OSMessage message;
        OSReceiveMessage(&lbl_80499390, &message, 1);
        VISetPreRetraceCallback(0);
        VISetPostRetraceCallback(0);
        JUTErrorHandler callback = *(JUTErrorHandler*)message;
        u16 error = *(u16*)((u8*)message + 4);
        OSContext* context = *(OSContext**)((u8*)message + 8);
        u32 dsisr = *(u32*)((u8*)message + 0xc);
        u32 dar = *(u32*)((u8*)message + 0x10);

        if (error < OS_ERROR_MAX)
        {
            this_->mStackPointer = context->gpr[1];
        }

        this_->mFrameMemory = (JUTExternalFB*)VIGetCurrentFrameBuffer();
        if (this_->mFrameMemory == 0)
        {
            fn_8008C390(lbl_8053A900);
        }
        lbl_8053A900->mDirectPrint->changeFrameBuffer(this_->mFrameMemory);

        if (callback)
        {
            callback(error, context, dsisr, dar);
        }

        OSDisableInterrupts();

        this_->mFrameMemory = (JUTExternalFB*)VIGetCurrentFrameBuffer();
        lbl_8053A900->mDirectPrint->changeFrameBuffer(this_->mFrameMemory);
        fn_8008BE24(lbl_8053A900, error, context, dsisr, dar);
    }
}

extern "C" void fn_8008A220(u16 param_1, OSContext* param_2, u32 param_3, u32 param_4)
{
    lbl_8053A918 = PPCMfmsr();
    lbl_8053A91C = *(u32*)((u8*)param_2 + 0x194);
    OSFillFPUContext(param_2);
    OSSetErrorHandler(param_1, 0);
    if (param_1 == 0xf) {
        OSProtectRange(0, 0, 0, 3);
        OSProtectRange(1, 0, 0, 3);
        OSProtectRange(2, 0, 0, 3);
        OSProtectRange(3, 0, 0, 3);
    }
    u8* msg = lbl_804BA1B0;
    *(u32*)(msg + 0) = lbl_8053A904;
    *(u16*)(msg + 4) = param_1;
    *(u32*)(msg + 8) = (u32)param_2;
    *(u32*)(msg + 12) = param_3;
    *(u32*)(msg + 16) = param_4;
    OSSendMessage(&lbl_80499390, msg, 1);
    OSEnableScheduler();
    OSYieldThread();
}

void JUTException::panic_f(const char* file, int line, const char* fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    char buf[256];
    vsnprintf(buf, sizeof(buf) - 1, fmt, vl);
    if (lbl_8053A900 == nullptr)
    {
        OSPanic(file, line, buf);
    }
    memcpy(lbl_804BA1D0, OSGetCurrentContext(), sizeof(OSContext));
    lbl_8053A900->mStackPointer = OSGetStackPointer();

    *(u32*)(lbl_804BA1B0 + 0) = lbl_8053A904;
    *(u16*)(lbl_804BA1B0 + 4) = 0xff;
    *(u32*)(lbl_804BA1B0 + 8) = (u32)lbl_804BA1D0;
    *(u32*)(lbl_804BA1B0 + 12) = 0;
    *(u32*)(lbl_804BA1B0 + 16) = 0;

    if (lbl_8053A914 == nullptr || lbl_8053A914 && FLAG_ON(lbl_8053A914->getOutput(), JUTConsole::OUTPUT_CONSOLE))
    {
        OSReport(lbl_8045E934, buf, file, line);
    }
    if (lbl_8053A914)
    {
        lbl_8053A914->print_f(lbl_8045E934, buf, file, line);
    }
    OSSendMessage(&lbl_80499390, lbl_804BA1B0, 1);
    OSSuspendThread(OSGetCurrentThread());
    va_end(vl);
}

extern "C" void fn_8008A4C4(unsigned int param_1)
{
    __OSFpscrEnableBits = param_1;
    if (param_1 != 0) {
        OSSetErrorHandler(OS_ERROR_FPE, (OSErrorHandler)fn_8008A220);
    } else {
        OSSetErrorHandler(OS_ERROR_FPE, 0);
    }
}

extern "C" void fn_8008A50C(JUTException* this_, OSContext* context)
{
    char* fmt = lbl_8045E878;
    if (lbl_8053A914 != nullptr) {
        lbl_8053A914->print(fmt + 0x128);
        for (int i = 0; i < 10; i++) {
            showFloat((f32)context->fpr[i], i);
            lbl_8053A914->print(" ");
            showFloat((f32)context->fpr[i + 11], i + 11);
            lbl_8053A914->print(" ");
            showFloat((f32)context->fpr[i + 22], i + 22);
            lbl_8053A914->print("\n");
        }
        showFloat((f32)context->fpr[10], 10);
        lbl_8053A914->print(" ");
        showFloat((f32)context->fpr[21], 21);
        lbl_8053A914->print("\n");
    }
}

extern "C" char lbl_8053B868;
extern "C" char lbl_8053B87C;
extern "C" char lbl_8045EC1C[];

static BOOL searchSection(u32 addr, u32* id, u32* index, u32* offset, char** name)
{
    OSModuleInfo* module = *(OSModuleInfo**)0x800030C8;
    for (; module != nullptr; module = module->link.next) {
        OSSectionInfo* section = (OSSectionInfo*)module->sectionInfoOffset;
        u32 i = 0;
        for (u32 n = module->numSections; n != 0; n--) {
            u32 base = OS_SECTIONINFO_OFFSET(section->offset);
            if (section->size != 0 && base <= addr && addr < base + section->size) {
                if (id != nullptr) {
                    *id = module->id;
                }
                if (index != nullptr) {
                    *index = i;
                }
                if (offset != nullptr) {
                    *offset = addr - base;
                }
                if (name != nullptr) {
                    *name = (char*)module->nameOffset;
                }
                return TRUE;
            }
            section++;
            i++;
        }
    }
    return FALSE;
}

static bool searchPartialModule(u32 addr, u32* id, u32* index, u32* offset, char** name)
{
    if (addr == 0) {
        return false;
    }
    OSModuleInfo* module = *(OSModuleInfo**)0x800030C8;
    for (; module != nullptr; module = module->link.next) {
        OSSectionInfo* section = (OSSectionInfo*)module->sectionInfoOffset;
        for (u32 i = 0; i < module->numSections; i++, section++) {
            if (section->size != 0) {
                u32 base = OS_SECTIONINFO_OFFSET(section->offset);
                if (base <= addr && addr < base + section->size) {
                    if (id != nullptr) {
                        *id = module->id;
                    }
                    if (index != nullptr) {
                        *index = i;
                    }
                    if (offset != nullptr) {
                        *offset = addr - base;
                    }
                    if (name != nullptr) {
                        *name = (char*)module->nameOffset;
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

extern "C" BOOL fn_8008AFBC(JUTException* this_, u32 param_1, bool param_2);
extern "C" JUTConsole* lbl_8053A914;
extern "C" void fn_8008AC7C(JUTException* this_, OSContext* context)
{
    char* base = lbl_8045E878;
    if (!lbl_8053A914)
    {
        return;
    }

    u32 i;

    lbl_8053A914->print(base + 0x150);
    u32* stackPointer = (u32*)this_->mStackPointer;
    lbl_8053A914->print_f(base + 0x178);

    for (i = 0; (stackPointer != nullptr) && (stackPointer != (u32*)0xFFFFFFFF) && (i++ < 0x10);)
    {
        if (i > this_->mTraceSuppress)
        {
            lbl_8053A914->print(base + 0x198);
            return;
        }

        lbl_8053A914->print_f(base + 0x1ac, stackPointer, stackPointer[0], stackPointer[1]);
        fn_8008AFBC(this_, stackPointer[1], false);
        JUTConsoleManager::sManager->drawDirect(true);
        fn_8008C308(this_->mPrintWaitTime1);
        stackPointer = (u32*)stackPointer[0];
    }
}

extern "C" char lbl_8053B86C;
extern "C" char lbl_8053B874;
extern "C" const char* lbl_804993D0[];
extern "C" void fn_8008AD78(u32 param_1, u16 error, OSContext* context, u32 dsisr, u32 dar)
{
    char* base = lbl_8045E878;

    if (lbl_8053A914 != nullptr) {
        if (error < 0x11) {
            lbl_8053A914->print_f(base + 0x1c4, lbl_804993D0[error]);
        } else {
            lbl_8053A914->print_f(base + 0x1e4);
        }
        if (error == 0x10) {
            u32 bits = lbl_8053A91C & (((lbl_8053A91C & 0xf8) << 22) | 0x1f80700);
            if (bits & 0x20000000) {
                lbl_8053A914->print_f(base + 0x1f4);
                if (lbl_8053A91C & 0x1000000) {
                    lbl_8053A914->print_f((const char*)&lbl_8053B86C);
                }
                if (lbl_8053A91C & 0x800000) {
                    lbl_8053A914->print_f(base + 0x210);
                }
                if (lbl_8053A91C & 0x400000) {
                    lbl_8053A914->print_f(base + 0x228);
                }
                if (lbl_8053A91C & 0x200000) {
                    lbl_8053A914->print_f((const char*)&lbl_8053B874);
                }
                if (lbl_8053A91C & 0x100000) {
                    lbl_8053A914->print_f(base + 0x240);
                }
                if (lbl_8053A91C & 0x80000) {
                    lbl_8053A914->print_f(base + 0x250);
                }
                if (lbl_8053A91C & 0x400) {
                    lbl_8053A914->print_f(base + 0x264);
                }
                if (lbl_8053A91C & 0x200) {
                    lbl_8053A914->print_f(base + 0x278);
                }
                if (lbl_8053A91C & 0x100) {
                    lbl_8053A914->print_f(base + 0x290);
                }
            }
            if (bits & 0x10000000) {
                lbl_8053A914->print_f(base + 0x2ac);
            }
            if (bits & 0x8000000) {
                lbl_8053A914->print_f(base + 0x2bc);
            }
            if (bits & 0x4000000) {
                lbl_8053A914->print_f(base + 0x2d0);
            }
            if (bits & 0x2000000) {
                lbl_8053A914->print_f(base + 0x2e8);
            }
        }
        lbl_8053A914->print_f(base + 0x300, *(u32*)((u8*)context + 0x198), *(u32*)((u8*)context + 0x19c));
        lbl_8053A914->print_f(base + 0x31c, dsisr, dar);
    }
}

extern "C" BOOL fn_8008AFBC(JUTException* this_, u32 param_1, bool param_2)
{
    if (param_1 >= 0x80000000 && param_1 <= 0x82FFFFFF) {
        BOOL found = FALSE;
        char* name;
        u32 id;
        u32 index;
        u32 offset;
        u32 x14;
        u32 x10;
        char work[0x100];
        char buf[0x20];
        const char* prefix = param_2 ? (const char*)&lbl_8053B868 : (const char*)&lbl_8053B87C;
        if (param_1 != 0) {
            found = searchSection(param_1, &id, &index, &offset, &name);
        }
        if (found) {
            char* p = name;
            char* base = name;
            for (; *p != '\\0'; p++) {
                if (*p == '\\\\') {
                    base = p;
                }
            }
            if (*base == '\\\\') {
                base++;
            }
            u32 i = 0;
            while (*base != '\\0' && i < 0x20 && *base != '.') {
                buf[i] = *base;
                i++;
                base++;
            }
            buf[i] = '\\0';
            lbl_8053A914->print_f(lbl_8045EC1C, prefix, buf, offset, index);
            param_2 = false;
        }
        if (lbl_8052E894.getFirstLink() != nullptr) {
            BOOL ret;
            if (found) {
                ret = fn_8008C528(buf, offset, index, (u32)&x14, (u32)&x10, (u32)work, 0x100, 1, param_2);
            } else {
                ret = fn_8008C528(nullptr, param_1, -1, (u32)&x14, (u32)&x10, (u32)work, 0x100, 1, param_2);
            }
            if (ret == 1) {
                return 1;
            }
        }
    }
    return 0;
}

extern "C" void fn_8008B214(JUTException* this_, u32* param_2)
{
    char* base = lbl_8045E878;
    bool found = false;

    if (lbl_8053A914 != nullptr)
    {
        lbl_8053A914->print(base + 0x3bc);
        for (s32 i = 0; i < 0x1f; i++)
        {
            u32 addr = param_2[i];
            if (addr > 0x7fffffff && addr < 0x83000000)
            {
                found = true;
                lbl_8053A914->print_f(base + 0x3e8, i, addr);
                u32 flag = 1;
                bool ok = false;
                if (addr >= 0x80000000 && addr <= 0x82ffffff)
                {
                    char name[0x20];
                    u32 sectionBase = 0;
                    s32 sectionIndex = 0;
                    u32 sectionOffset = 0;
                    char* mapName = nullptr;
                    u32* module;
                    if (addr != 0)
                    {
                        for (module = *(u32**)0x800030c8; module != nullptr && !ok; module = (u32*)module[1])
                        {
                            u32* section = (u32*)module[4];
                            for (s32 j = 0; j < (s32)module[3]; j++)
                            {
                                u32 start = section[0] & 0xfffffffe;
                                if (section[1] != 0 && start <= addr && addr < start + section[1])
                                {
                                    sectionBase = *module;
                                    sectionIndex = j;
                                    sectionOffset = addr - start;
                                    mapName = (char*)module[5];
                                    ok = true;
                                    break;
                                }
                                section += 2;
                            }
                        }
                    }
                    if (ok)
                    {
                        char* p = mapName;
                        char* last = mapName;
                        for (; *p != 0; p++)
                        {
                            if (*p == '\\')
                            {
                                last = p;
                            }
                        }
                        if (*last == '\\')
                        {
                            last++;
                        }
                        s32 n = 0;
                        char* out = name;
                        while (*last != 0 && n < 0x20 && *last != '.')
                        {
                            n++;
                            *out++ = *last++;
                        }
                        *out = 0;
                        lbl_8053A914->print_f(base + 0x3a4, 0, name, sectionOffset, sectionIndex);
                        flag = 0;
                    }
                    if (lbl_8052E894.getFirstLink() != nullptr)
                    {
                        if (ok)
                        {
                            ok = fn_8008C528(name, sectionOffset, sectionIndex, 0, 0, 0, 0x100, 1, flag) == 1;
                        }
                        else
                        {
                            ok = fn_8008C528(nullptr, addr, -1, 0, 0, 0, 0x100, 1, flag) == 1;
                        }
                    }
                    else
                    {
                        ok = false;
                    }
                }
                if (!ok)
                {
                    lbl_8053A914->print(base + 0x3f8);
                }
                JUTConsoleManager::sManager->drawDirect(true);
                fn_8008C308(this_->mPrintWaitTime1);
            }
        }
        if (!found)
        {
            lbl_8053A914->print(base + 0x40c);
        }
    }
}

extern "C" void fn_8008A50C(JUTException* this_, OSContext* context);
static BOOL FindModuleSection(u32 addr, u32* moduleId, s32* sectionIndex, u32* sectionOffset, char** mapName);
extern "C" void fn_8008B508(JUTException* this_, s32 param_2, u16 param_3, OSContext* param_4, u32 param_5, u32 param_6)
{
    char* base = lbl_8045E878;

    switch (param_2)
    {
    case 1:
        if (lbl_8053A914 == nullptr)
        {
            return;
        }
        lbl_8053A914->print(base + 0x338);
        for (s32 i = 0; i < 10; i++)
        {
            lbl_8053A914->print_f(base + 0x360, i, param_4->gpr[i], i + 11, param_4->gpr[i + 11], i + 22, param_4->gpr[i + 22]);
        }
        lbl_8053A914->print_f(base + 0x388, 10, param_4->gpr[10], 21, param_4->gpr[21]);
        return;
    case 2:
        fn_8008A50C(this_, param_4);
        if (lbl_8053A914 != nullptr)
        {
            lbl_8053A914->print_f(base + 0x46c, lbl_8053A918, lbl_8053A91C);
        }
        return;
    case 3:
        fn_8008AC7C(this_, param_4);
        return;
    case 4:
        fn_8008B214(this_, (u32*)param_4);
        return;
    case 5:
        break;
    default:
        return;
    }

    if (lbl_8053A914 == nullptr)
    {
        return;
    }
    lbl_8053A914->print(base + 0x434);
    u32 addr = *(u32*)((u8*)param_4 + 0x198);
    if (addr < 0x80000000 || addr > 0x82ffffff)
    {
        return;
    }
    lbl_8053A914->print_f(base + 0x460, addr);

    u32 flag = 1;
    bool ok = false;
    BOOL found = FALSE;
    u32 moduleId;
    s32 sectionIndex;
    u32 sectionOffset;
    char* mapName;
    u32 outA;
    u32 outB;
    char name[0x20];
    u8 buf[0x100];

    if (addr >= 0x80000000 && addr <= 0x82ffffff)
    {
        found = FindModuleSection(addr, &moduleId, &sectionIndex, &sectionOffset, &mapName);
        if (found)
        {
            char* last = mapName;
            for (char* p = mapName; *p != 0; p++)
            {
                if (*p == '\\')
                {
                    last = p;
                }
            }
            if (*last == '\\')
            {
                last++;
            }
            s32 n = 0;
            char* out = name;
            while (*last != 0 && n < 0x20 && *last != '.')
            {
                n++;
                *out++ = *last++;
            }
            *out = 0;
            lbl_8053A914->print_f(base + 0x3a4, 0, name, sectionOffset, sectionIndex);
            flag = 0;
        }
        if (lbl_8052E894.getFirstLink() != nullptr)
        {
            if (found)
            {
                ok = fn_8008C528(name, sectionOffset, sectionIndex, (u32)&outA, (u32)&outB, (u32)buf, 0x100, 1, flag) == 1;
            }
            else
            {
                ok = fn_8008C528(nullptr, addr, -1, (u32)&outA, (u32)&outB, (u32)buf, 0x100, 1, flag) == 1;
            }
        }
        else
        {
            ok = false;
        }
    }
    if (!ok)
    {
        lbl_8053A914->print(base + 0x3f8);
    }
    JUTConsoleManager::sManager->drawDirect(true);
}

extern "C" BOOL fn_8008B8B4(JUTException* this_, u32* param_1, u32* param_2)
{
    BOOL result = FALSE;
    s64 start = OSGetTime();
    s64 ms;
    do {
        ms = (OSGetTime() - start) / ((*(u32*)0x800000F8 / 4) / 1000);
    } while (ms < 50);

    if (*(s32*)((u8*)this_ + 0x84) == -1) {
        FSAPad pad0;
        FSAPad pad1;
        FSAPad pad2;
        FSAPad pad3;
        fn_8008CF54(&pad0, 0);
        fn_8008CF54(&pad1, 1);
        fn_8008CF54(&pad2, 2);
        fn_8008CF54(&pad3, 3);
        fn_8008D15C();

        bool active = false;
        if (pad0._7c != -1 && pad0._98 != 0) {
            active = true;
        }
        s64 t0;
        if (active) {
            t0 = lbl_804993B0[0];
            if (t0 == 0) {
                t0 = OSGetTime();
            }
        } else {
            t0 = 0;
        }
        lbl_804993B0[0] = t0;

        active = false;
        if (pad1._7c != -1 && pad1._98 != 0) {
            active = true;
        }
        s64 t1;
        if (active) {
            t1 = lbl_804993B0[1];
            if (t1 == 0) {
                t1 = OSGetTime();
            }
        } else {
            t1 = 0;
        }
        lbl_804993B0[1] = t1;

        active = false;
        if (pad2._7c != -1 && pad2._98 != 0) {
            active = true;
        }
        s64 t2;
        if (active) {
            t2 = lbl_804993B0[2];
            if (t2 == 0) {
                t2 = OSGetTime();
            }
        } else {
            t2 = 0;
        }
        lbl_804993B0[2] = t2;

        active = false;
        if (pad3._7c != -1 && pad3._98 != 0) {
            active = true;
        }
        s64 t3;
        if (active) {
            t3 = lbl_804993B0[3];
            if (t3 == 0) {
                t3 = OSGetTime();
            }
        } else {
            t3 = 0;
        }
        lbl_804993B0[3] = t3;

        s64 e0 = lbl_804993B0[0] != 0 ? OSGetTime() - lbl_804993B0[0] : 0;
        s64 e1 = lbl_804993B0[1] != 0 ? OSGetTime() - lbl_804993B0[1] : 0;
        s64 e2 = lbl_804993B0[2] != 0 ? OSGetTime() - lbl_804993B0[2] : 0;
        s64 e3 = lbl_804993B0[3] != 0 ? OSGetTime() - lbl_804993B0[3] : 0;
        fn_8008D4CC(&pad0, e0);
        fn_8008D4CC(&pad1, e1);
        fn_8008D4CC(&pad2, e2);
        fn_8008D4CC(&pad3, e3);

        if (param_1 != nullptr) {
            *param_1 = pad0._1c | pad1._1c | pad2._1c | pad3._1c;
        }
        if (param_2 != nullptr) {
            *param_2 = pad0._18 | pad1._18 | pad2._18 | pad3._18;
        }
        result = TRUE;
        dtor_8008D028(&pad3, -1);
        dtor_8008D028(&pad2, -1);
        dtor_8008D028(&pad1, -1);
        dtor_8008D028(&pad0, -1);
    } else if (*(s32*)((u8*)this_ + 0x88) < 0) {
        if (*(s32*)((u8*)this_ + 0x84) != 0) {
            FSAPad* pad = (FSAPad*)*(s32*)((u8*)this_ + 0x84);
            fn_8008D15C();
            if (param_1 != nullptr) {
                *param_1 = pad->_1c;
            }
            if (param_2 != nullptr) {
                *param_2 = pad->_18;
            }
            result = TRUE;
        }
    } else {
        FSAPad pad;
        fn_8008CF54(&pad, *(s32*)((u8*)this_ + 0x88));
        bool active = false;
        if (pad._7c != -1 && pad._98 != 0) {
            active = true;
        }
        s64 t0;
        if (active) {
            t0 = lbl_804993B0[0];
            if (t0 == 0) {
                t0 = OSGetTime();
            }
        } else {
            t0 = 0;
        }
        lbl_804993B0[0] = t0;
        s64 e0 = lbl_804993B0[0] != 0 ? OSGetTime() - lbl_804993B0[0] : 0;
        fn_8008D4CC(&pad, e0);
        fn_8008D15C();
        if (param_1 != nullptr) {
            *param_1 = pad._1c;
        }
        if (param_2 != nullptr) {
            *param_2 = pad._18;
        }
        result = TRUE;
        dtor_8008D028(&pad, -1);
    }
    return result;
}

extern "C" void fn_8008BE24(JUTException* this_, u16 param_1, OSContext* param_2, u32 param_3, u32 param_4)
{
    char* base = lbl_8045E878;
    bool pad_enabled;
    if (this_->mGamePad == (JUTGamePad*)0xFFFFFFFF)
    {
        pad_enabled = true;
    }
    else if (this_->mPadPort >= JUTGamePad::Port1)
    {
        pad_enabled = true;
    }
    else
    {
        pad_enabled = this_->mGamePad != nullptr;
    }
    bool is_pad_enabled = !pad_enabled;
    if (!lbl_8053A900->mDirectPrint->isActive())
    {
        return;
    }
    VISetPreRetraceCallback(nullptr);
    VISetPostRetraceCallback(nullptr);
    VISetBlack(FALSE);
    VIFlush();

    if (!lbl_8053A914)
    {
        return;
    }

    if (param_1 < OS_ERROR_MAX)
    {
        lbl_8053A914->print_f(base + 0x488, this_->mFrameMemory);
    }
    else
    {
        lbl_8053A914->print_f(base + 0x4c0, this_->mFrameMemory);
    }

    int post_callback_executed = false;
    while (true)
    {
        fn_8008AD78((u32)this_, param_1, param_2, param_3, param_4);
        JUTConsoleManager::sManager->drawDirect(true);
        fn_8008C308(this_->mPrintWaitTime0);

        if ((this_->mPrintFlags & EXPRINTFLAG_GPR) != 0)
        {
            fn_8008B508(this_, JUTException::INFOPAGE_GPR, param_1, param_2, param_3, param_4);
            JUTConsoleManager::sManager->drawDirect(true);
            fn_8008C308(this_->mPrintWaitTime0);
        }
        if ((this_->mPrintFlags & EXPRINTFLAG_SRR0Map) != 0)
        {
            fn_8008B508(this_, JUTException::INFOPAGE_SRR0Map, param_1, param_2, param_3, param_4);
            JUTConsoleManager::sManager->drawDirect(true);
            fn_8008C308(this_->mPrintWaitTime0);
        }
        if ((this_->mPrintFlags & EXPRINTFLAG_GPRMap) != 0)
        {
            fn_8008B508(this_, JUTException::INFOPAGE_GPRMap, param_1, param_2, param_3, param_4);
            JUTConsoleManager::sManager->drawDirect(true);
            fn_8008C308(this_->mPrintWaitTime0);
        }
        if ((this_->mPrintFlags & EXPRINTFLAG_Float) != 0)
        {
            fn_8008B508(this_, JUTException::INFOPAGE_Float, param_1, param_2, param_3, param_4);
            JUTConsoleManager::sManager->drawDirect(true);
            fn_8008C308(this_->mPrintWaitTime0);
        }
        if ((this_->mPrintFlags & EXPRINTFLAG_Stack) != 0)
        {
            fn_8008B508(this_, JUTException::INFOPAGE_Stack, param_1, param_2, param_3, param_4);
            JUTConsoleManager::sManager->drawDirect(true);
            fn_8008C308(this_->mPrintWaitTime1);
        }

        lbl_8053A914->print(base + 0x4f0);
        JUTConsoleManager::sManager->drawDirect(true);

        if (post_callback_executed == 0 && lbl_8053A908)
        {
            BOOL enable = OSEnableInterrupts();
            post_callback_executed = true;
            ((JUTErrorHandler)lbl_8053A908)(param_1, param_2, param_3, param_4);
            OSRestoreInterrupts(enable);
        }

        if (this_->_98 == 0 || !is_pad_enabled)
        {
            break;
        }

        lbl_8053A914->mOutput &= 1;
    }

    if (!is_pad_enabled)
    {
        OSEnableInterrupts();

        u32 button;
        u32 trigger;

        int down = 0;
        int up = 0;
        do
        {
            fn_8008B8B4(this_, &trigger, &button);

            bool draw = false;
            if (trigger == 0x100)
            {
                lbl_8053A914->scroll(lbl_8053A914->mMaxLines);
                draw = true;
            }

            if (trigger == 0x200)
            {
                lbl_8053A914->scroll(-lbl_8053A914->mMaxLines);
                draw = true;
            }

            if (button == 8)
            {
                JUTConsole* console = lbl_8053A914;
                up = (down < 3) ? -1 : ((down < 5) ? -2 : ((down < 7) ? -4 : -8));

                console->scroll(up);
                draw = true;
                up = 0;
                down++;
            }
            else if (button == 4)
            {
                JUTConsole* console = lbl_8053A914;
                down = (up < 3) ? 1 : ((up < 5) ? 2 : ((up < 7) ? 4 : 8));

                console->scroll(down);
                draw = true;
                down = 0;
                up++;
            }
            else
            {
                down = 0;
                up = 0;
            }

            if (draw == true)
            {
                u32 start = VIGetRetraceCount();
                while (start == VIGetRetraceCount())
                    ;
                JUTConsoleManager::sManager->drawDirect(true);
            }

            fn_8008C308(0x1e);
        } while (true);
    }

    while (true)
    {
        lbl_8053A914->scroll(-lbl_8053A914->mMaxLines);
        JUTConsoleManager::sManager->drawDirect(true);
        fn_8008C308(2000);

        int line_offset;
        int used_line;
        u32 height;
    next:
        for (u32 i = lbl_8053A914->mHeight; i > 0; i--)
        {
            lbl_8053A914->scroll(1);
            JUTConsoleManager::sManager->drawDirect(true);

            height = lbl_8053A914->mHeight;
            JUTConsole* console = lbl_8053A914;
            line_offset = console->getLineOffset();
            used_line = console->getUsedLine();
            if ((used_line - height) + 1U <= line_offset)
            {
                break;
            }
            fn_8008C308(0x14);
        }

        fn_8008C308(3000);
        height = lbl_8053A914->mHeight;
        JUTConsole* console = lbl_8053A914;
        line_offset = console->getLineOffset();
        used_line = console->getUsedLine();
        if ((used_line - height) + 1U <= line_offset)
        {
            continue;
        }
        goto next;
    }
}

extern "C" s64 __div2i(s64 num, s64 den);
extern "C" OSTime OSGetTime(void);
extern "C" void fn_8008C308(s32 param_1) {
    OSTime start;
    s64 elapsed;

    if (param_1 != 0) {
        start = OSGetTime();
        do {
            elapsed = __div2i(OSGetTime() - start, *(u32*)0x800000f8 / 4 / 1000);
        } while (elapsed < param_1);
    }
}

extern "C" void fn_8008CA24(unsigned int* p, unsigned int a, unsigned short b, unsigned int unused, unsigned int c);
extern "C" void fn_8008C390(JUTException* this_)
{
    GXRenderModeObj* renderMode = &GXNtsc480Int;
    void* end = (void*)OSGetArenaHi();
    u16 width = ALIGN_NEXT(renderMode->fbWidth, 16);
    u16 height = renderMode->xfbHeight;
    u32 pixel_count = width * height;
    u32 size = pixel_count * 2;

    void* begin = (void*)ALIGN_PREV((u32)end - size, 32);
    void* object = (void*)ALIGN_PREV((s32)begin - sizeof(JUTExternalFB), 32);
    if (object != 0) {
        fn_8008CA24((unsigned int*)object, (unsigned int)renderMode, 1, (unsigned int)begin, size);
    }

    this_->mDirectPrint->changeFrameBuffer(begin, renderMode->fbWidth, renderMode->efbHeight);
    VIConfigure(renderMode);
    VISetNextFrameBuffer(begin);
    VISetBlack(FALSE);
    VIFlush();
    VIFlush();

    for (int i = 0; i < 3; i++) {
        u32 retraceCount = VIGetRetraceCount();
        do {
        } while (retraceCount == VIGetRetraceCount());
    }

    this_->mFrameMemory = (JUTExternalFB*)object;
}

extern "C" unsigned int lbl_8053A904;
extern "C" unsigned int fn_8008C484(unsigned int value)
{
    unsigned int old = lbl_8053A904;
    lbl_8053A904 = value;
    return old;
}

extern JSUPtrList lbl_8054BBDC;
extern "C" void* __nw__FUl(unsigned long size);
extern "C" int strcmp(const char* s1, const char* s2);
extern "C" void __ct__10JSUPtrLinkFPv(JSUPtrLink* this_, void* data);
extern "C" void fn_8008C494(char* param_1) {
    JSUPtrLink* link;
    void** entry;

    if (param_1 != 0) {
        for (link = lbl_8054BBDC.getFirstLink(); link != 0; link = link->getNext()) {
            if (strcmp(param_1, *(char**)link->getObjectPtr()) == 0) {
                return;
            }
        }
        entry = (void**)__nw__FUl(0x14);
        if (entry != 0) {
            __ct__10JSUPtrLinkFPv((JSUPtrLink*)(entry + 1), entry);
            entry[0] = param_1;
        }
        lbl_8054BBDC.append((JSUPtrLink*)(entry + 1));
    }
}

extern "C" u8 fn_8008C608(char* param_1, u32 param_2, s32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u8 param_9);
extern JSUPtrList lbl_8052E894;
extern "C" BOOL fn_8008C528(char* param_1, u32 param_2, s32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u8 param_9) {
    char buf[80];

    if (param_1 != 0) {
        strcpy(buf, param_1);
        strcat(buf, ".map");
        if (fn_8008C608(buf, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9) == 1) {
            return 1;
        }
    } else {
        JSUPtrLink* link = lbl_8052E894.getFirstLink();
        if (link != 0 && fn_8008C608(*(char**)link->getObjectPtr(), param_2, -1, param_4, param_5, param_6, param_7, param_8, param_9) == 1) {
            return 1;
        }
    }
    return 0;
}

void JUTException::createConsole(void* console_buffer, u32 console_buffer_size)
{
    if (!console_buffer || !console_buffer_size)
    {
        return;
    }

    u32 lines = JUTConsole::getLineFromObjectSize(console_buffer_size, 0x32);
    if (lines != 0)
    {
        sConsoleBuffer = console_buffer;
        sConsoleBufferSize = console_buffer_size;
        sConsole = JUTConsole::create(0x32, console_buffer, console_buffer_size);

        JUTConsoleManager* manager = JUTConsoleManager::sManager;
        manager->setDirectConsole(sConsole);

        sConsole->setFontSize(10.0, 6.0);
        sConsole->setPosition(15, 26);
        sConsole->setHeight(23);
        sConsole->setVisible(true);
        sConsole->setOutput(JUTConsole::OUTPUT_OSR_AND_CONSOLE);
    }
}

extern "C" void fn_8008CA24(unsigned int* p, unsigned int a, unsigned short b, unsigned int unused, unsigned int c)
{
    p[0] = a;
    p[1] = c;
    *(unsigned short*)((unsigned char*)p + 0xc) = 1;
    *(unsigned short*)((unsigned char*)p + 0xe) = b;
    *(unsigned char*)((unsigned char*)p + 0x10) = 0;
}

extern "C" void __dt__9JKRThreadFv(void* this_, int flag);
extern void* lbl_804B623C[];
extern "C" void dtor_80084580(void* this_);
extern "C" void __dl__FPv(void* this_);
extern "C" void* fn_8008CA44(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B623C;
        __dt__9JKRThreadFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
static BOOL FindModuleSection(u32 addr, u32* moduleId, s32* sectionIndex, u32* sectionOffset, char** mapName)
{
    u32* module;

    if (addr == 0)
    {
        return FALSE;
    }
    for (module = *(u32**)0x800030c8; module != nullptr; module = (u32*)module[1])
    {
        u32* section = (u32*)module[4];
        for (s32 j = 0; j < (s32)module[3]; j++)
        {
            u32 start = section[0] & 0xfffffffe;
            if (section[1] != 0 && start <= addr && addr < start + section[1])
            {
                if (moduleId)
                {
                    *moduleId = *module;
                }
                if (sectionIndex)
                {
                    *sectionIndex = j;
                }
                if (sectionOffset)
                {
                    *sectionOffset = addr - start;
                }
                if (mapName)
                {
                    *mapName = (char*)module[5];
                }
                return TRUE;
            }
            section += 2;
        }
    }
    return FALSE;
}
