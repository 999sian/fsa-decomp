#include "types.h"


extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7870(void*, u16);
extern "C" void fn_80433718(char* this_) {
    char* mgr = (char*)fn_802D6A9C();
    if (*(u16*)(this_ + 0xA0) != *(u16*)(mgr + 0x131DC)) {
        *(u16*)(this_ + 0xA0) = *(u16*)((char*)fn_802D6A9C() + 0x131DC);
        *(u16*)(this_ + 0x9E) = *(u16*)((char*)fn_802D6A9C() + 0x131DC);
        if (*(u16*)(this_ + 0x9E) & 0x8000) {
            this_[0xA4] = 1;
            *(u16*)(this_ + 0x9E) = *(u16*)(this_ + 0x9E) & 0x7FFF;
            void* mgr2 = fn_802D6A9C();
            fn_802D7870(mgr2, *(u16*)(this_ + 0x9E));
        } else {
            this_[0xA4] = 0;
        }
    }
}
