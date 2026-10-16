// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "dolphin/os.h"

extern "C" void __ct__10JSUPtrListFb(void* self, bool doInitialize);
extern "C" void* __register_global_object(void* object, void* destructor, void* registration);
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void fn_8008E750(void);
extern "C" void fn_8008E714(void);
extern "C" void fn_8008E6F8(void);
extern "C" void fn_8008E6A4(void);
extern char lbl_8052E8A0[];
extern char lbl_804BA498[];
extern char lbl_8052EA58[];
extern char lbl_8052EB18[];
extern char lbl_8052EB58[];
extern char lbl_8052EB98[];
extern char lbl_804BA4A4[];
extern OSTime lbl_8053A948;

extern "C" void fn_8008E594(void)
{
    __ct__10JSUPtrListFb(lbl_8052E8A0, 0);
    __register_global_object(lbl_8052E8A0, (void*)fn_8008E750, lbl_804BA498);
    __construct_array(lbl_8052EA58, (void*)fn_8008E714, NULL, 0x30, 4);
    __construct_array(lbl_8052EB18, (void*)fn_8008E6F8, NULL, 0x10, 4);
    __construct_array(lbl_8052EB58, (void*)fn_8008E6F8, NULL, 0x10, 4);
    lbl_8053A948 = (OSTime)(OS_TIMER_CLOCK / 60) * 30;
    __ct__10JSUPtrListFb(lbl_8052EB98, 0);
    __register_global_object(lbl_8052EB98, (void*)fn_8008E6A4, lbl_804BA4A4);
}
