#include "dolphin/os.h"
#include "dolphin/base/PPCArch.h"
#include "JSystem/JSupport/JSUList.h"
#include "JSystem/JUtility/JUTException.h"
#include "JSystem/JUtility/JUTConsole.h"
#include "JSystem/JUtility/JUTDirectPrint.h"
#include "JSystem/JUtility/JUTExternalFB.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" void fn_8008A220(u16 param_1, OSContext* param_2, u32 param_3, u32 param_4);
extern "C" void fn_8008A4C4(unsigned int param_1);
extern "C" unsigned int lbl_8053A904;
extern "C" u32 lbl_8053A918;
extern "C" u32 lbl_8053A91C;
extern "C" u8 lbl_804BA1B0[];
extern "C" OSMessageQueue lbl_80499390;
extern "C" void fn_8008C308(s32 param_1);
extern char lbl_8045E878[];
extern "C" void* __nw__FUlP7JKRHeapi(size_t size, JKRHeap* heap, int align);
extern void* lbl_80499414[];
extern "C" void __ct__9JKRThreadFUlii(JKRThread* this_, u32 stackSize, int msgCount, int threadPriority);
JUTException* JUTException::create(JUTDirectPrint* directPrint)
{
    if (sErrorManager == nullptr) {
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

            sPreUserCallback = nullptr;
            sPostUserCallback = nullptr;
            manager->mGamePad = nullptr;
            manager->mPadPort = JUTGamePad::Port_Invalid;
            manager->mPrintWaitTime0 = 10;
            manager->mPrintWaitTime1 = 10;
            manager->mTraceSuppress = 0xffffffff;
            manager->_98 = 0;
            manager->mPrintFlags = EXPRINTFLAG_All;
        }
        sErrorManager = manager;
        sErrorManager->resume();
    }
    return sErrorManager;
}

extern "C" void fn_8008C390(JUTException* this_);
extern "C" void fn_8008BE24(JUTException* this_, u16 param_1, OSContext* param_2, u32 param_3, u32 param_4);
extern "C" void fn_8008A100(JUTException* this_)
{
    extern JUTException* lbl_8053A900;

    PPCMtmsr(PPCMfmsr() & ~0x900);
    OSInitMessageQueue(&lbl_80499390, 0, 1);
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

extern "C" void fn_8008A4C4(unsigned int param_1)
{
    __OSFpscrEnableBits = param_1;
    if (param_1 != 0) {
        OSSetErrorHandler(OS_ERROR_FPE, (OSErrorHandler)fn_8008A220);
    } else {
        OSSetErrorHandler(OS_ERROR_FPE, 0);
    }
}

extern "C" void fn_8008AFBC(JUTException* this_, u32 param_1, bool param_2);
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

