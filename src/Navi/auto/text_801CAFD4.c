// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801cafd4-0x801e0c34 (354 functions). split_file divides it into the game's real files.

#include <types.h>

extern "C" int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(int state);
int lbl_802FF8F4;
extern unsigned long lbl_802FF944;
extern unsigned long lbl_802FE9F8;
extern unsigned long lbl_802FE9F4;
extern unsigned long CurrTvMode_802FF92C;
int jumptable_8029D79C[];
extern "C" int fn_801CB248(int param_1) {
    volatile int dummy;
    int r30 = param_1;
    int r31 = lbl_802FF8F4;
    int interrupt_state = OSDisableInterrupts();
    lbl_802FF8F4 = r30;
    OSRestoreInterrupts(interrupt_state);
    return r31;
}

extern int lbl_802FF8E4;
extern int lbl_802FF8EC;
extern int lbl_802F7BC8[];
extern int lbl_802FF938;
extern "C" void fn_801C12E4(int param);
extern "C" void fn_801CBA74(void* a, void* b, void* c, void* d, void* e);
extern "C" void fn_801CBD48(unsigned short a, unsigned short b, unsigned char c, unsigned short d, unsigned short e, unsigned short f, unsigned short g, unsigned short h, int param_1);
extern "C" void fn_801CB2D0(int param_1) {
    if (param_1 > 0x1a) {
        return;
    }
    ((void (*)())jumptable_8029D79C[param_1])();
}

extern "C" void fn_801CBA20(void) {
    int interrupt_state = OSDisableInterrupts();
    int original = lbl_802FF8E4;
    fn_801C12E4(lbl_802FF8EC);
    int new_val = lbl_802FF8E4;
    if (original != new_val) {
        OSRestoreInterrupts(interrupt_state);
    }
}

extern "C" void fn_801CC840(int param_1) {
    char* base = (char*)lbl_802F7BC8;
    int interrupt_state = OSDisableInterrupts();
    *(int*)(base + 0x120) = param_1;
    lbl_802FF938 = 1;
    fn_801CBA74((void*)(base + 0xf0), (void*)(base + 0x124), (void*)(base + 0x128),
               (void*)(base + 0x13c), (void*)(base + 0x140));
    OSRestoreInterrupts(interrupt_state);
}

extern "C" void fn_801CC8B4(int param_1) {
    int saved_param = param_1;
    char* base = (char*)lbl_802F7BC8;
    int interrupt_state = OSDisableInterrupts();
    *(int*)(base + 0x130) = saved_param;
    
    void* ptr_144 = *(void**)(base + 0x144);
    unsigned char* data = (unsigned char*)ptr_144;
    
    unsigned short arg1 = *(unsigned short*)(base + 0xfa);
    unsigned short arg2 = *(unsigned short*)(base + 0xf6);
    unsigned char arg3 = data[0x0];
    unsigned short arg4 = *(unsigned short*)(data + 0x2);
    unsigned short arg5 = *(unsigned short*)(data + 0x4);
    unsigned short arg6 = *(unsigned short*)(data + 0x6);
    unsigned short arg7 = *(unsigned short*)(data + 0x8);
    unsigned short arg8 = *(unsigned short*)(data + 0xa);
    
    fn_801CBD48(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, saved_param);
    OSRestoreInterrupts(interrupt_state);
}

extern unsigned long __PADSpec;
extern void* lbl_802FE9FC;
extern unsigned long lbl_802FE9F8;
extern "C" void fn_801CE218(void);
extern "C" void fn_801CE38C(void);
extern "C" void fn_801CE500(void);
extern "C" void fn_801CE1B8(unsigned long spec) {
    __PADSpec = 0;
    switch (spec) {
    case 0:
        lbl_802FE9FC = (void*)fn_801CE218;
        break;
    case 1:
        lbl_802FE9FC = (void*)fn_801CE38C;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        lbl_802FE9FC = (void*)fn_801CE500;
        break;
    }
    lbl_802FE9F8 = spec;
}

