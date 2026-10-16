#include "types.h"

extern "C" void fn_802D9FF4(s32, s32, s32);
extern "C" void fn_80136798(s32, s32, s32);
extern "C" void fn_8011921C(void);
extern "C" void fn_801183BC(void);
extern "C" s32 fn_802D6A9C(void);
extern "C" s32 fn_80119DD0(void);
extern "C" void fn_80119468(s32, s32, s32);
extern "C" u8 fn_803865B8(s32);
extern "C" void fn_80388EEC(s32);
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JUtility/JUTVideo.h"

extern "C" u8 fn_8012A5EC(void*);
extern "C" void fn_8022FE80(int, int, int, u8, u8);
extern "C" u8 fn_8038BD08(s32, s32, u32, JGeometry::TVec3<f32>*, s32);
extern "C" void fn_8011921C();
extern "C" void fn_80118454();
extern "C" void fn_801183BC();
extern "C" u8 fn_803865B8(s32);
extern "C" void fn_80388EEC(s32);
extern s32 lbl_804650C8[];
extern "C" void fn_80239914(void*, u32, u32);
extern "C" void fn_8012A8C0(char* this_) {
    struct Vec2 {
        f32 x, y;
    };
    struct Box {
        Vec2 min, max;
    };
    s32 i = 0;
    char* p = this_;
    Box box = {{*(f32*)(this_ + 0x60), *(f32*)(this_ + 0x64)}, {*(f32*)(this_ + 0x68), *(f32*)(this_ + 0x6c)}};
    Box orig = {{*(f32*)(this_ + 0x60), *(f32*)(this_ + 0x64)}, {*(f32*)(this_ + 0x68), *(f32*)(this_ + 0x6c)}};
    do {
        box.min.x += *(f32*)(p + 0x25c);
        box.min.y += *(f32*)(p + 0x260);
        box.max.x += *(f32*)(p + 0x25c);
        box.max.y += *(f32*)(p + 0x260);
        fn_80239914(&box, *(u32*)(this_ + 4), *(u32*)(this_ + 0x198));
        box = orig;
        i++;
        p += 0xc;
    } while (i < 6);
}

extern "C" void fn_8012B02C(char* this_) {
    fn_8012A5EC(this_);
    fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
    if (fn_803865B8(0)) {
        fn_80388EEC(0);
        fn_8011921C();
        fn_801183BC();
        *(s32*)(this_ + 0x250) = 0x604;
        ++*(s32*)(this_ + 0x230);
        *(f32*)(this_ + 0x244) = (*(f32*)(this_ + 0x23c) - (154.0f + *(f32*)(this_ + 0x3f4))) / 270.0f;
        *(f32*)(this_ + 0x24c) = (*(f32*)(this_ + 0x248) - 186.0f) / 270.0f;
    }
}

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
