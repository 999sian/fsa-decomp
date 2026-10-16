#include "types.h"
#include "dolphin/mtx.h"
#include "JSystem/JGeometry/Vec.h"

#pragma auto_inline off

extern u8* lbl_8053AAF8;
extern const f32 lbl_8053D93C;
extern const f32 lbl_8053D940;
extern const f32 lbl_8053D944;
extern const f32 lbl_8053D950;
extern const f32 lbl_8053D958;
extern const f32 lbl_8053D95C;
extern const f32 lbl_8053D960;
extern const f32 lbl_8053D988;

extern "C" void* fn_8013C824();
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*, void*);
extern "C" void fn_8016A7DC(void*, void*, const Vec*, s32, u8, u8, f32, f32);
extern "C" void fn_8016ADE0(void*);

extern "C" void fn_8016A2B4(u8* self) {
    if (*(void**)(self + 0x124) != 0) {
        void* manager = *(void**)((u8*)fn_8013C824() + 0xC);
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(self + 0x124));
    }
    if (*(void**)(self + 0x128) != 0) {
        void* manager = *(void**)((u8*)fn_8013C824() + 0xC);
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(self + 0x128));
    }
    if (*(void**)(self + 0x12C) != 0) {
        void* manager = *(void**)((u8*)fn_8013C824() + 0xC);
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(self + 0x12C));
    }
}

extern "C" void fn_8016A330(u8* self) {
    self[0x1EC] = 0;
    self[0x1ED] = 0;
    self[0x1EE] = 0;
    self[0x1EF] = 0;
    self[0x1F0] = 0;
    self[0x1F1] = 0;
    self[0x1F2] = 0;
    self[0x1F3] = 0;
    self[0x1F4] = 0;
    self[0x1F5] = 0;
    self[0x1C4] = 0;
    self[0x1C5] = 0;
    self[0x1C6] = 0;
    self[0x1C7] = 0;
    self[0x1C8] = 0;
    self[0x1C9] = 0;
    self[0x1CA] = 0;
    self[0x1CB] = 0;
    self[0x1CC] = 0;
    self[0x1CD] = 0;
    self[0x1CE] = 0;
    self[0x1CF] = 0;
    self[0x1D1] = 0;
    self[0x1D2] = 0;
    self[0x1D3] = 0;
    *(s32*)(self + 0x1D8) = -1;
    self[0x1DC] = 0;
    self[0x1DD] = 0;
}

extern "C" void* fn_8016A3AC() {
    return *(void**)(*(u8**)(lbl_8053AAF8 + 4) + 0x24);
}

extern "C" void fn_8016A9EC(u8* self) {
    if (self[0x1DD]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0xEC), &offset, -1, 1, 1, lbl_8053D940, lbl_8053D95C);
    }
}

extern "C" void fn_8016AA48(u8* self) {
    if (self[0x1F5]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0xE0), &offset, 1, 1, 1, lbl_8053D950, lbl_8053D960);
    }
}

extern "C" void fn_8016AAA4(u8* self) {
    if (self[0x1DC]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0xCC), &offset, 1, 1, 1, lbl_8053D950, lbl_8053D93C);
    }
}

extern "C" void fn_8016AB00(u8* self) {
    if (self[0x1F4]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0xD4), &offset, 1, 1, 1, lbl_8053D93C, lbl_8053D95C);
    }
}

extern "C" void fn_8016AB5C(u8* self) {
    if (*(s32*)(self + 0x1D8) > 0) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0xC0), &offset, 1, 1, 1, lbl_8053D93C, lbl_8053D95C);
    }
}

extern "C" void fn_8016ABB8(u8* self) {
    if (self[0x1F3]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0xB4), &offset, 1, 1, 1, lbl_8053D93C, lbl_8053D95C);
    }
}

extern "C" void fn_8016AC14(u8* self) {
    if (self[0x1F2]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0x9C), &offset, 1, 1, 1, lbl_8053D93C, lbl_8053D95C);
    }
}

extern "C" void fn_8016AC70(u8* self) {
    if (self[0x1F1]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0x90), &offset, 1, 1, 1, lbl_8053D950, lbl_8053D95C);
    }
}

extern "C" void fn_8016ACCC(u8* self) {
    if (self[0x1F0]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0x84), &offset, 1, 1, 1, lbl_8053D93C, lbl_8053D95C);
    }
}

extern "C" void fn_8016AD28(u8* self) {
    if (self[0x1EF]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0x28), &offset, 1, 1, 1, lbl_8053D93C, lbl_8053D95C);
    }
}

extern "C" void fn_8016AD84(u8* self) {
    if (self[0x1ED]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0x1C), &offset, 1, 1, 1, lbl_8053D950, lbl_8053D960);
    }
}

extern "C" void fn_8016B054(u8* self) {
    if (self[0x1D3]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0xA8), &offset, -1, 1, 1, lbl_8053D93C, lbl_8053D95C);
    }
}

extern "C" void fn_8016B8AC(u8* self) {
    if (self[0x1CB]) {
        JGeometry::TVec3<f32> offset(lbl_8053D958, lbl_8053D958 + *(f32*)(self + 0x1E4), lbl_8053D944);
        fn_8016A7DC(self, *(void**)(self + 0x34), &offset, 1, 1, 0, lbl_8053D93C, lbl_8053D988);
    }
}

extern "C" void fn_8016D284(u8* self) {
    if (self[0x1C6]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0x14), &offset, -1, 1, 1, lbl_8053D940, lbl_8053D960);
    }
}

extern "C" void fn_8016D2E0(u8* self) {
    if (self[0x1C5]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 0xC), &offset, -1, 1, 1, lbl_8053D940, lbl_8053D960);
    }
}

extern "C" void fn_8016D33C(u8* self) {
    if (self[0x1C4]) {
        Vec offset;
        offset.x = lbl_8053D958;
        offset.y = lbl_8053D958;
        offset.z = lbl_8053D944;
        fn_8016A7DC(self, *(void**)(self + 4), &offset, -1, 1, 1, lbl_8053D940, lbl_8053D960);
    }
}

// Retail keeps individual comparisons rather than folding consecutive modes.
#pragma optimization_level 3
extern "C" void fn_8016DA6C(u8* self) {
    bool enabled;
    if (lbl_8053AAF8[0x7F]) {
        s32 mode = *(s32*)(lbl_8053AAF8 + 0x4C);
        u8 selected = 0;
        if (mode == 7 || mode == 8 || mode == 9 || mode == 22 || mode == 10 || mode == 11) {
            selected = 1;
        }
        enabled = selected;
    } else {
        s32 mode = *(s32*)(lbl_8053AAF8 + 0x4C);
        u8 selected = 0;
        if (mode == 7 || mode == 8 || mode == 9 || mode == 22 || mode == 10 || mode == 11 || mode == 12) {
            selected = 1;
        }
        enabled = selected;
    }
    if (enabled) {
        fn_8016ADE0(self);
        fn_8016AD84(self);
    }
}
#pragma optimization_level 4

extern "C" void fn_8016ED88(u8* self) {
    *(void**)(self + 0x00) = 0;
    *(void**)(self + 0x14) = 0;
    *(void**)(self + 0x1C) = 0;
    *(void**)(self + 0x30) = 0;
    *(void**)(self + 0x38) = 0;
    *(void**)(self + 0x4C) = 0;
    *(void**)(self + 0x54) = 0;
    *(void**)(self + 0x68) = 0;
}

extern "C" void fn_8016EDB0(u8* self) {
    self[0x1EC] = 0;
    self[0x1ED] = 0;
    self[0x1EE] = 0;
    self[0x1EF] = 0;
    self[0x1F0] = 0;
    self[0x1F1] = 0;
    self[0x1F2] = 0;
    self[0x1F3] = 0;
    self[0x1F4] = 0;
    self[0x1F5] = 0;
    self[0x1C4] = 0;
    self[0x1C5] = 0;
    self[0x1C6] = 0;
    self[0x1C7] = 0;
    self[0x1C8] = 0;
    self[0x1C9] = 0;
    self[0x1CA] = 0;
    self[0x1CB] = 0;
    self[0x1CC] = 0;
    self[0x1CD] = 0;
    self[0x1CE] = 0;
    self[0x1CF] = 0;
    self[0x1D1] = 0;
    self[0x1D2] = 0;
    self[0x1D3] = 0;
    *(s32*)(self + 0x1D8) = -1;
    self[0x1DC] = 0;
    self[0x1DD] = 0;
    *(void**)(self + 0x130) = 0;
    *(void**)(self + 0x134) = 0;
    *(void**)(self + 0x124) = 0;
    *(void**)(self + 0x128) = 0;
    *(void**)(self + 0x12C) = 0;
    *(void**)(self + 0x13C) = 0;
    *(void**)(self + 0x138) = 0;
    *(s32*)(self + 0x1B0) = 120;
    *(s32*)(self + 0x1B8) = 60;
    self[0x1B4] = 0;
    *(void**)(self + 0x140) = 0;
    *(void**)(self + 0x154) = 0;
    *(void**)(self + 0x15C) = 0;
    *(void**)(self + 0x170) = 0;
    *(void**)(self + 0x178) = 0;
    *(void**)(self + 0x18C) = 0;
    *(void**)(self + 0x194) = 0;
    *(void**)(self + 0x1A8) = 0;
    self[0x1BC] = 0;
    *(s32*)(self + 0x1C0) = 0;
}

extern "C" void fn_8016FDE0(void) {
}

