#include "types.h"


extern void* lbl_8053AAF8;
extern "C" void fn_8024064C(void* p);
extern "C" s32 fn_8023DE58(void* p);
extern "C" s32 fn_8030AAF4(s32 i);
extern "C" void* fn_8008E328(s32 slot);
extern "C" u8 fn_80247534(void* p);
extern "C" u8 fn_8022E438(s32 h, s32 i);
extern "C" u8 fn_80236B50(s32 i);
extern "C" u8 fn_8022D75C(s32 i);
extern "C" u8 Player_IsLinked(char* p);
extern "C" s32 fn_802486A0(char* p);
extern "C" s32 fn_8022EA0C(s32 h);
extern "C" u8 fn_80230188(s32 h);
extern "C" void* fn_8023E724(s32 h);
extern "C" u8 fn_8023EA28(s32 h);
extern "C" u8 fn_80234ECC(s32 h);
extern "C" u8 fn_80235274(s32 h);
extern "C" u8 fn_80234CF8(s32 h);
extern "C" u8 fn_80234C5C(s32 h);
extern "C" u8 fn_80235744(s32 h);
extern "C" u8 fn_802353AC(s32 h);
extern "C" u8 fn_80233DA4(s32 h);
extern "C" u8 fn_80233EDC(s32 h);
extern "C" u8 fn_80234E30(s32 h);
extern "C" s32 fn_80248970(char* p);
extern "C" void* fn_80309D6C(void* p, s32 a, s32 n);
extern "C" void fn_80248004(char* p, s32 a, s32 b);
extern "C" u8 fn_80234134(void);
extern "C" u8 fn_8022BC38(s32 a, s32 b, void* c);
extern "C" void fn_80230FD0(s32 h, void* s);
extern "C" u8 fn_8023ED8C(s32 h);
extern "C" void fn_8023ECF0(s32 h);
extern "C" void fn_8023105C(void);
extern "C" void fn_802310F8(s32 h);
extern void* lbl_8053AD30;
extern f32 lbl_80540410;
void fn_802870C8();
void fn_80265E88(char* p);
void fn_8024CA20(char* p);
extern "C" void fn_802870C8();
extern "C" void fn_80265E88(char* p);
extern "C" void fn_80285E58(char* p) {
    char* q;
    if (*(s32*)(p + 0x11f4) > 0) {
        *(s32*)(p + 0x11f4) = *(s32*)(p + 0x11f4) - 1;
        q = p;
        for (int i = 0; i < 5; i++) {
            *(s32*)(q + 0xdb0) = -1;
            *(s32*)(q + 0x1030) = -1;
            *(s32*)(q + 0xdb4) = -1;
            *(s32*)(q + 0x1034) = -1;
            *(s32*)(q + 0xdb8) = -1;
            *(s32*)(q + 0x1038) = -1;
            *(s32*)(q + 0xdbc) = -1;
            *(s32*)(q + 0x103c) = -1;
            *(s32*)(q + 0xdc0) = -1;
            *(s32*)(q + 0x1040) = -1;
            *(s32*)(q + 0xdc4) = -1;
            *(s32*)(q + 0x1044) = -1;
            *(s32*)(q + 0xdc8) = -1;
            *(s32*)(q + 0x1048) = -1;
            *(s32*)(q + 0xdcc) = -1;
            *(s32*)(q + 0x104c) = -1;
            *(s32*)(q + 0xdd0) = -1;
            *(s32*)(q + 0x1050) = -1;
            *(s32*)(q + 0xdd4) = -1;
            *(s32*)(q + 0x1054) = -1;
            *(s32*)(q + 0xdd8) = -1;
            *(s32*)(q + 0x1058) = -1;
            *(s32*)(q + 0xddc) = -1;
            *(s32*)(q + 0x105c) = -1;
            *(s32*)(q + 0xde0) = -1;
            *(s32*)(q + 0x1060) = -1;
            *(s32*)(q + 0xde4) = -1;
            *(s32*)(q + 0x1064) = -1;
            *(s32*)(q + 0xde8) = -1;
            *(s32*)(q + 0x1068) = -1;
            *(s32*)(q + 0xdec) = -1;
            *(s32*)(q + 0x106c) = -1;
            q += 0x40;
        }
    } else {
        fn_802870C8();
    }
    fn_80265E88(p);
    fn_8024CA20(p);
}

extern "C" void fn_80286688(u8* p) {
    s32 ok = *(s32*)((u8*)lbl_8053AAF8 + 0x4c) != 0xb;
    if (ok && *((u8*)lbl_8053AAF8 + 0x7e) == 0 &&
        (*((u8*)lbl_8053AAF8 + 0x82) & ((1 << *(u32*)(p + 4)) & 0xff)) != 0) {
        fn_8024064C(p);
        if (fn_8023DE58(p) < 8) {
            p[0x13b8] = 0;
        } else {
            void* pad = fn_8008E328(fn_8030AAF4(*(s32*)(p + 0x11ec)));
            if (fn_80247534(p) == 0 && pad != 0 && (*(u32*)((u8*)pad + 0x1c) & 0x10) != 0) {
                if (p[0x13b8] == 1) {
                    p[0x13b8] = 0;
                } else {
                    p[0x13b8] = 1;
                }
            }
        }
    }
}
