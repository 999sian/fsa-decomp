#include "types.h"
#include "JSystem/JGeometry/Vec.h"


extern void* lbl_8053AAF8;
extern "C" u8 fn_802413F0(void);
extern "C" u8 fn_80241E28(char* p, s32 a, char* b);
extern "C" s32 Player_GetLinkTargetIndex(char* p);
extern "C" u8 fn_80270A8C(char* p);
extern "C" u8 fn_8024B24C(char* p);
extern "C" u8 fn_802DEB58(void);
extern "C" u8 fn_802412CC(char* p);
extern "C" void fn_8024F0E8(char* p, s32 msg);
extern "C" s16 fn_8022461C(char* p, s32 a);
extern "C" u8 fn_80225BE4(char* p, s32 a);
extern "C" u8 Player_GetField_0x454(char* p);
extern "C" u8 fn_80240B84(char* p);
extern "C" u8 fn_80240D50(char* p);
extern "C" u8 fn_802412A4(char* p);
extern "C" u8 fn_80240670(char* p);
extern "C" u8 fn_80240F28(char* p);
extern "C" void fn_8013CC50(s32, void*, f32, s32, s32, s32, s32, s32, s32);
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
extern "C" void fn_802870C8(char* p);
extern "C" void fn_80265E88(char* p);
extern "C" void fn_8024CA20(char* p);
extern "C" void fn_80285E58(char* p) {
    s32 count = *(s32*)(p + 0x11f4);
    if (count > 0) {
        *(s32*)(p + 0x11f4) = count - 1;
        char* q = p;
        for (int i = 0; i < 80; i++) {
            *(s32*)(q + 0xdb0) = -1;
            *(s32*)(q + 0x1030) = -1;
            q += 4;
        }
    } else {
        fn_802870C8(p);
    }
    fn_80265E88(p);
    fn_8024CA20(p);
}

extern "C" void fn_80285F44(char* p) {
    s32 kind;

    if (fn_802413F0() && fn_80241E28(p, *(s32*)(p + 0x3b8), p + 0x14)) {
        if (Player_IsLinked(p) && !fn_80234E30(Player_GetLinkTargetIndex(p))) {
            if (fn_80270A8C(p)) {
                *(s32*)(p + 0x448) = 4;
                return;
            }
        } else {
            *(s32*)(p + 0x448) = 4;
            return;
        }
    }
    if (*(f32*)(p + 0x10) <= lbl_80540410 && lbl_80540410 < *(f32*)(p + 0x1c)) {
        ;
    }
}

extern "C" void fn_80286688(u8* p) {
    void* pad;
    s32 ok = *(s32*)((u8*)lbl_8053AAF8 + 0x4c) == 0xb;
    if (ok != 0) {
        return;
    }
    if (*((u8*)lbl_8053AAF8 + 0x7e) != 0) {
        return;
    }
    if ((*((u8*)lbl_8053AAF8 + 0x82) & ((1 << *(u32*)(p + 4)) & 0xff)) != 0) {
        fn_8024064C(p);
        if (fn_8023DE58(p) < 8) {
            p[0x13b8] = 0;
        } else {
            pad = fn_8008E328(fn_8030AAF4(*(s32*)(p + 0x11ec)));
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

extern "C" void fn_80286E10(u8* p) {
    s32 h29;
    s32 h28;
    s32 start;
    s32 h;
    if (*(s32*)(p + 0x1220) > 0) {
        return;
    }
    if (p[0x1216] == 1) {
        return;
    }
    for (s32 i = 0; i < 4; i++) {
        if (fn_8022E438(*(s32*)(p + 0x4), i)) {
            if (fn_80236B50(i)) {
                return;
            }
            if (fn_8022D75C(i)) {
                return;
            }
        }
    }
    if (Player_IsLinked((char*)p)) {
        return;
    }
    h = *(s32*)(p + 0x4);
    if (fn_802486A0((char*)p) == 4) {
        h = fn_8022EA0C(*(s32*)(p + 0x4));
    }
    if (fn_80230188(h)) {
        return;
    }
    if (*(f32*)((u8*)fn_8023E724(h) + 0x8) <= lbl_80540410) {
        return;
    }
    if (fn_8023EA28(h)) {
        return;
    }
    if (fn_80234ECC(h)) {
        return;
    }
    if (fn_80235274(h)) {
        return;
    }
    if (fn_80234CF8(h)) {
        return;
    }
    if (fn_80234C5C(h)) {
        return;
    }
    if (fn_80235744(h)) {
        return;
    }
    if (fn_802353AC(h)) {
        return;
    }
    if (fn_80233DA4(h)) {
        return;
    }
    if (fn_80233EDC(h)) {
        return;
    }
    if (fn_80234E30(h)) {
        return;
    }
    if (fn_80248970((char*)p) < 2) {
        return;
    }
    if (p[0x121e] != 0) {
        return;
    }
    if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(*(s32*)(p + 0x11ec)), 0x400) == 0) {
        return;
    }
    if (fn_802486A0((char*)p) == 4) {
        start = *(s32*)(p + 0x1224);
        h28 = fn_8022EA0C(*(s32*)(p + 0x4));
        do {
            *(s32*)(p + 0x1224) = *(s32*)(p + 0x1224) + 1;
            if (*(s32*)(p + 0x1224) >= fn_80248970((char*)p)) {
                *(s32*)(p + 0x1224) = 0;
            }
            h29 = fn_8022EA0C(*(s32*)(p + 0x4));
            if (fn_80234134() || fn_8023EA28(h29)) {
                continue;
            }
            if (fn_8022BC38(h29, fn_8023DE58((void*)h28), fn_8023E724(h28))) {
                break;
            }
        } while (start != *(s32*)(p + 0x1224));
        if (start == *(s32*)(p + 0x1224)) {
            return;
        }
        fn_80230FD0(h29, (void*)0x10010);
        if (fn_8023ED8C(h28)) {
            fn_8023ECF0(h28);
            fn_8023105C();
            fn_802310F8(h28);
        }
    } else {
        fn_80248004((char*)p, 4, 1);
    }
}
