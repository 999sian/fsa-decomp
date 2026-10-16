#include "dolphin/os.h"
#include "JSystem/JSupport/JSUList.h"
#include "JSystem/JUtility/JUTException.h"
#include "JSystem/JUtility/JUTConsole.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" void fn_8008A220(void);
extern "C" void fn_8008A4C4(unsigned int param_1)
{
    __OSFpscrEnableBits = param_1;
    if (param_1 != 0) {
        OSSetErrorHandler(OS_ERROR_FPE, (OSErrorHandler)fn_8008A220);
    } else {
        OSSetErrorHandler(OS_ERROR_FPE, 0);
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

