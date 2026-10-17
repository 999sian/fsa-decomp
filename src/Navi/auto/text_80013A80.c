#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80013a80-0x80015cc0 (55 functions). split_file divides it into the game's real files.

extern void* lbl_80204F9C[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80013F24(void* p);
extern "C" void* fn_801C027C(void);
extern "C" void fn_8015D1F4(void* p, void* q, s32 r);
extern "C" void fn_8015D29C(void* p, s32 r);
extern "C" void fn_80159BA4(s32 r);
extern "C" s32 DVDGetDriveStatus(void);
extern "C" void fn_80012DE0(void);
extern "C" void fn_801C1174(void* p);
extern "C" void OSCancelThread(void* p);
extern "C" void fn_801BB7E0(void* p);
extern "C" f32 fn_80116064(f32 x);
extern "C" void fn_80013E18(void* p);
extern u8 lbl_802A2140[];
extern u8 lbl_802A3460[];
extern u8 lbl_802FEBE0;
extern f32 lbl_802FFBB8;
extern "C" s32 fn_8002663C(void);
extern "C" void fn_80026630(void);
extern "C" void fn_800266A8(void);
extern s32 lbl_802FED98;
extern u8 lbl_802FEBE8[];
extern "C" void fn_80015B1C(void);
extern "C" void fn_80015A00(void* p);
extern "C" void fn_800265F0(u8 param_1);

struct Unk80013DA0 {
    u8 pad[0x20];
    u8 unk20;
    u8 pad21[0x24 - 0x21];
    u32 b0 : 2;
    u32 b1 : 15;
    u32 b2 : 15;
    u32 unk28;
    u8 pad2c[0x50 - 0x2c];
    u8 unk50;
    u8 unk51;
    u8 unk52;
    u8 unk53;
    u8 unk54;
    u8 unk55;
    u8 pad56;
    u8 unk57;
    u8 pad58;
    u8 unk59;
    u8 unk5a;
    u8 unk5b;
    u8 unk5c;
    u8 unk5d;
    u8 unk5e;
    u8 unk5f;
    u8 pad60[0x63 - 0x60];
    u8 unk63;
    u8 pad64[0xa8 - 0x64];
    s8 unkA8;
};
extern "C" void fn_80013B48(void) {
    if (lbl_802FEBE0) {
        OSCancelThread(lbl_802A2140);
        fn_801BB7E0(lbl_802A3460);
        lbl_802FEBE0 = 0;
    }
}

extern "C" void fn_80013B90(void) {
    u8 buf[0x74];
    fn_8015D1F4(buf, fn_801C027C(), 0);
    fn_8015D29C(buf, -1);
    fn_80159BA4(0);
    while (true) {
        if (DVDGetDriveStatus() == -1) {
            fn_80012DE0();
        }
        fn_801C1174(lbl_802A2140);
    }
}

extern "C" void fn_801C0EEC(void*);
extern "C" void fn_80013BEC(void) {
    fn_801C0EEC(lbl_802A2140);
}

extern "C" void fn_80013C14(void* self, void* p) {
    fn_80013F24(p);
}

extern "C" void fn_80013FC0(void* p);
extern "C" void fn_80013C38(void* self, void* p) {
    fn_80013FC0(p);
}

extern "C" void fn_8001404C(void* p);
extern "C" void fn_80013C5C(void* self, void* p) {
    fn_8001404C(p);
}

extern "C" void fn_800140D0(void* p);
extern "C" void fn_80013C80(void* self, void* p) {
    fn_800140D0(p);
}

extern "C" void fn_80014160(void* p);
extern "C" void fn_80013CA4(void* self, void* p) {
    fn_80014160(p);
}

extern "C" void fn_800141EC(void* p);
extern "C" void fn_80013CC8(void* self, void* p) {
    fn_800141EC(p);
}

extern "C" void fn_80014260(void* p);
extern "C" void fn_80013CEC(void* self, void* p) {
    fn_80014260(p);
}

extern "C" void fn_80014308(void* p);
extern "C" void fn_80013D10(void* self, void* p) {
    fn_80014308(p);
}

extern "C" void fn_800143E8(void* p);
extern "C" void fn_80013D34(void* self, void* p) {
    fn_800143E8(p);
}

extern "C" void fn_80014520(void* p);
extern "C" void fn_80013D58(void* self, void* p) {
    fn_80014520(p);
}

extern "C" void fn_800145F0(void* p);
extern "C" void fn_80013D7C(void* self, void* p) {
    fn_800145F0(p);
}

extern "C" void fn_80013DA0(Unk80013DA0* self, u8 a, u8 b) {
    self->unk50 = a;
    self->unk5f = b;
    self->b2 = (u32)fn_80116064(32767.0f);
    self->b1 = (u32)fn_80116064(32767.0f);
    self->b0 = self->unk50;
    fn_80013E18(self);
}

extern "C" void fn_80014390(Unk80013DA0* self) {
    fn_80015A00(self);
    self->unk51 = 0;
    self->unk54 = 0;
    self->b1 = (u32)fn_80116064(32767.0f);
    self->unk20 = 0;
}

extern "C" void fn_80014758(void) {
    if (fn_8002663C() != 0) {
        lbl_802FED98 = 0;
        fn_80026630();
        fn_800266A8();
    }
}

extern "C" s32 fn_80015574(s8* p) {
    if (p[0xa8] == 0) {
        p[0x53] = 1;
        p[0xa8]++;
    } else if (p[0xa8] != -1 && (u8)p[0x5e] < 3) {
        p[0x5e]++;
    }
    return 1;
}

extern "C" void fn_80015C24(void) {
}

extern "C" u32 fn_80015C28(u32 param) {
    union {
        u32 w;
        u8 b[4];
    } src, dst;
    src.w = param;
    dst.b[0] = src.b[3];
    dst.b[1] = src.b[2];
    dst.b[2] = src.b[1];
    dst.b[3] = src.b[0];
    return dst.w;
}

extern "C" void* fn_80015C5C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80204F9C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" s32 fn_80015CA4(s16* p) {
    s32 v = *p;
    if (v != 0) {
        *p = v - 1;
    }
    return *p;
}

