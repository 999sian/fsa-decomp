#include "types.h"
#include "JSystem/JGeometry/Vec.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" void fn_801D6CEC(const f32* src, f32* dst);
extern "C" u8 fn_801CD2F8(s32 id);
extern "C" void fn_801EDD0C(u8* this_);
extern "C" void fn_801F02BC(u8* a, u8* p2, void* p3, void* p4, void* p5, s32 p6, u8 p7, f32 f6, f32 f7);
extern const f32 lbl_8053F718;
extern u8 lbl_80469D30[];
extern "C" void fn_801EDC0C(u8* this_, void* p2) {
    JGeometry::TVec3<f32> local;
    JGeometry::TVec3<f32>* pos = (JGeometry::TVec3<f32>*)(this_ + 0xc);

    fn_801D6CEC((f32*)(this_ + 0x52c), (f32*)&local);
    *pos += local;
    if (*(s32*)(this_ + 0x248) == 0xb && *(s32*)(this_ + 0x24c) >= 0x3c) {
        if (*(s32*)(this_ + 0x24c) % 4 < 2) {
            pos->x += lbl_8053F718;
        } else {
            pos->x -= lbl_8053F718;
        }
    }
    if (fn_801CD2F8(*(s32*)(this_ + 0x4))) {
        fn_801F02BC(this_, lbl_80469D30, p2, 0, (void*)-1, 0, 0, lbl_8053F718, lbl_8053F718);
    } else {
        fn_801EDD0C(this_);
    }
}
