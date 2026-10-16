#include "types.h"
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/J2D/J2DPane.h"
#include "JSystem/J2D/J2DGrafContext.h"


extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7870(void*, u16);
extern "C" void fn_8013B490(void* p);
extern "C" void fn_80402E08(void* p, f32 x, f32 y);
extern "C" char* lbl_8053AB10;
extern "C" char lbl_8050DB0C[];
extern "C" void* lbl_804B1668[];
extern "C" void __dl__FPv(void* this_);

struct DtorSlot2 {
	virtual void destroy(s32 freeFlag);
};

static inline void DispatchSlot2(char* slot) {
	DtorSlot2* obj = *(DtorSlot2**)slot;
	if (obj != 0) {
		obj->destroy(1);
	}
	*(void**)slot = 0;
}
extern "C" void fn_80432638(char* this_) {
    if (*(u8*)(this_ + 0xac) != 0) {
        f32 x0 = ((J2DPane*)*(void**)(*(char**)(this_ + 0x18) + 4))->getBounds()->i.x;
        f32 x1 = *(f32*)(*(char**)(this_ + 0x18) + 8);
        f32 y0 = ((J2DPane*)*(void**)(*(char**)(this_ + 0x18) + 4))->getBounds()->i.y;
        f32 y1 = *(f32*)(*(char**)(this_ + 0x18) + 0xc);
        fn_8013B490(lbl_8053AB10);
        f32 x = x0 - x1;
        f32 y = y0 - y1;
        x += (f32) * (s16*)(lbl_8050DB0C + 0x23e);
        y += (f32) * (s16*)(lbl_8050DB0C + 0x240);
        fn_80402E08(*(void**)(this_ + 0x3c), x, y);
        ((J2DScreen*)*(void**)(this_ + 0xc))->draw(0.0f, 0.0f, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
    }
}

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
