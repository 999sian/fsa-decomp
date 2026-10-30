// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80147610-0x80147700 (1 functions). split_file divides it into the game's real files.
#include "types.h"

extern "C" u8 lbl_802D4A80[];
extern "C" u8* lbl_802FF3E0;
extern "C" u32 lbl_802D52F4[];
extern "C" u32 lbl_802D5334[];
extern "C" u8 lbl_802FF3CC[4];
extern "C" u8 lbl_802FF3BC[4];
extern "C" u32 fn_8015766C(int i);
extern "C" void fn_80157F24(int i);
extern "C" void fn_8014EAE4(u32 p);
extern "C" void fn_80158D4C(void);
extern "C" void fn_80158D14(void);
extern "C" void fn_80157F98(u32 p);

extern "C" void fn_80147610(u32 param_1)
{
    u8 id = param_1;
    u8* p = lbl_802D4A80;
    u32 off = 0;
    u32 i;

    for (i = 0; i < p[0x210]; i++) {
        u8* entry = lbl_802FF3E0 + off;
        if (entry[0x11f] == id) {
            if (*(u32*)(entry + 0xf4) != 0xffffffff) {
                fn_8014EAE4(*(u32*)(*(u8**)(entry + 0xf8) + 8));
            } else {
                if (fn_8015766C(i)) {
                    fn_80157F24(i);
                }
            }
        }
        off += 0x404;
    }
    fn_80158D4C();
    {
        u32 o = id << 2;
        *(u32*)((u8*)lbl_802D52F4 + o) = 0;
        *(u32*)((u8*)lbl_802D5334 + o) = 0;
    }
    lbl_802FF3CC[id] = 0xff;
    lbl_802FF3BC[id] = 0xff;
    fn_80158D14();
    fn_80157F98(param_1);
}
