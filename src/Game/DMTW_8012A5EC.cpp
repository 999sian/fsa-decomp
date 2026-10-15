#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JUtility/JUTVideo.h"

extern "C" u8 fn_8012A5EC(void*);
extern "C" void fn_8022FE80(int, int, int, u8, u8);
extern "C" u8 fn_8038BD08(s32, s32, u32, JGeometry::TVec3<f32>*, s32);
extern "C" void fn_8011921C();
extern "C" void fn_80118454();
extern s32 lbl_804650C8[];
extern "C" void fn_8012B0D8(char* this_) {
    u8 result = fn_8012A5EC(this_);
    if (*(f32*)(this_ + 0x23c) == 260.0f + *(f32*)(this_ + 0x3f4) &&
        85.0f == *(f32*)(this_ + 0x248) && result == 1) {
        JGeometry::TVec3<f32> pos(
            (f32)(s32)JUTVideo::getManager()->getFbWidth() / 2.0f,
            (f32)(s32)JUTVideo::getManager()->getEfbHeight() / 2.0f,
            0.0f);
        pos.y += -16.0f;
        fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
        u32 owner = *(u32*)(this_ + 4);
        JGeometry::TVec3<f32> copy(pos);
        if (fn_8038BD08(0, lbl_804650C8[*(s32*)(this_ + 0x254)], owner, &copy, 0x22)) {
            ++*(s32*)(this_ + 0x254);
            fn_8011921C();
            fn_80118454();
            ++*(s32*)(this_ + 0x230);
        }
    }
}

extern "C" void fn_8012C030(char* this_) {
    u8 result = fn_8012A5EC(this_);
    if (*(f32*)(this_ + 0x23c) == 260.0f + *(f32*)(this_ + 0x3f4) &&
        85.0f == *(f32*)(this_ + 0x248) && result == 1) {
        JGeometry::TVec3<f32> pos(
            (f32)(s32)JUTVideo::getManager()->getFbWidth() / 2.0f,
            (f32)(s32)JUTVideo::getManager()->getEfbHeight() / 2.0f,
            0.0f);
        pos.y += -16.0f;
        fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
        u32 owner = *(u32*)(this_ + 4);
        JGeometry::TVec3<f32> copy(pos);
        if (fn_8038BD08(0, lbl_804650C8[*(s32*)(this_ + 0x254)], owner, &copy, 0x22)) {
            ++*(s32*)(this_ + 0x254);
            fn_8011921C();
            fn_80118454();
            ++*(s32*)(this_ + 0x230);
        }
    }
}

extern "C" void fn_8012C910(void* this_) {}
