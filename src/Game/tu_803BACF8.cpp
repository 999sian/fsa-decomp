#include "dolphin/card.h"
#include "dolphin/os.h"


extern "C" u8 lbl_8051E2C0[];
extern "C" u8 lbl_80529DEC[];
extern "C" u8 lbl_8051C1A0[];
extern "C" char lbl_80476578[];
extern "C" void* fn_804030C4(u32 tag, char* name);
extern "C" int snprintf(char* s, unsigned long n, const char* fmt, ...);

static inline u32 calcCardChecksum(u8* data) {
    u32 sum = 0;
    u16 inv = 0;
    u16* p = (u16*)data;
    s32 i = 0x7ff;
    do {
        sum += p[0];
        inv += ~p[0];
        sum += p[1];
        inv += ~p[1];
        p += 2;
    } while (--i != 0);
    return (sum << 16) | inv;
}
extern "C" void fn_803BACF8(u8* param_1, u8 param_2) {
    u32 sum = 0;
    u32 inv = 0;
    s32 i = 0x18;
    u8* base = param_1 + param_2 * 200;
    u8* p = base;

    do {
        sum += p[0]; inv += ~p[0];
        sum += p[1]; inv += ~p[1];
        sum += p[2]; inv += ~p[2];
        sum += p[3]; inv += ~p[3];
        sum += p[4]; inv += ~p[4];
        sum += p[5]; inv += ~p[5];
        sum += p[6]; inv += ~p[6];
        sum += p[7]; inv += ~p[7];
        p += 8;
    } while (--i != 0);
    *(u32*)(base + 0xc4) = inv;
    *(u32*)(base + 0xc0) = sum;
}

extern "C" u32 fn_803BADAC(u8* param_1) {
    u32 sum = 0;
    u32 inv = 0;
    s32 i = 0x18;
    u8* p = param_1;

    do {
        sum += p[0]; inv += ~p[0];
        sum += p[1]; inv += ~p[1];
        sum += p[2]; inv += ~p[2];
        sum += p[3]; inv += ~p[3];
        sum += p[4]; inv += ~p[4];
        sum += p[5]; inv += ~p[5];
        sum += p[6]; inv += ~p[6];
        sum += p[7]; inv += ~p[7];
        p += 8;
    } while (--i != 0);
    return ((sum ^ *(u32*)(param_1 + 0xc0)) | (inv ^ *(u32*)(param_1 + 0xc4))) == 0;
}

extern "C" s32 fn_803BAE68(CARDFileInfo* fileInfo) {
    u8* buf = lbl_8051E2C0;
    s32 result = CARDRead(fileInfo, buf, 0x2000, 0x2000);

    if (result == 0 || (result = CARDRead(fileInfo, buf, 0x2000, 0x4000), result == 0)) {
        *(u8*)(lbl_80529DEC + 0x244) = buf[3];
        *(u8*)(lbl_80529DEC + 0x246) = buf[4];
        result = 0;
    }
    return result;
}
