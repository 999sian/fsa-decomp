#include "types.h"

class J2DGrafContext;
class J2DScreen {
public:
    void draw(f32, f32, const J2DGrafContext*);
};

extern "C" void fn_8013B490(void*);
extern u8* lbl_8053AB10;
extern const f32 lbl_80543A40;

extern u8* lbl_8053AAF8;
extern u8 lbl_80529DEC[];
extern "C" u32 fn_80237774(s32 i);
extern "C" u8 fn_8022F514(s32 i);
extern "C" s32 fn_8022F3DC(s32 i);
extern "C" u32 fn_80236100(s32 i);
extern "C" void fn_80425128(u8* this_) {
    s32 i;
    s32 j;
    u32 bit;
    u32* table;

    table = (u32*)lbl_80529DEC;
    for (i = 0; i < 4; i++) {
        bit = 1 << i;
        if (lbl_8053AAF8[0x82] & (u8)bit) {
            table[0x36 + i] = fn_80237774(i);
            for (j = 0; j < 4; j++) {
                if (j != i && fn_8022F514(j) && fn_8022F3DC(j) == i) {
                    table[0x36 + j] = table[0x36 + i];
                }
            }
            this_[0x256] |= (u8)bit;
            *(u32*)(this_ + 0x168 + i * 4) = 0;
            table[0x3a + i] = fn_80236100(i);
            this_[0x257] |= (u8)bit;
            *(u32*)(this_ + 0x178 + i * 4) = 0;
        }
    }
}

extern "C" void fn_80425F24(u8* this_) {
    fn_8013B490(lbl_8053AB10);
    (*(J2DScreen**)(this_ + 0x18))->draw(lbl_80543A40, lbl_80543A40, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
}
