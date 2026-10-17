#include "types.h"

extern "C" char* lbl_8053AAF8;
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802DCD0C(void* room);

extern "C" void fn_80158B3C(char* p) {
    *(u8*)(p + 0x4) = 0xff;
    *(u8*)(p + 0x5) = 0xff;
    *(u8*)(p + 0x6) = 0xff;
    *(u8*)(p + 0x7) = 0;
    *(u8*)(p + 0xc) = 0xff;
}

extern "C" char lbl_804BFB60[];
extern "C" f32 lbl_8053D440;
extern "C" f32 lbl_8053D43C;
extern "C" f32 lbl_8053D454;
extern "C" f32 lbl_8053D458;
extern "C" u32 lbl_8053D420;
extern "C" u32 lbl_8053D424;
extern "C" u32 lbl_8053D428;
extern "C" u32 lbl_8053D42C;
extern "C" void GXInitLightPos(char* light, f32 x, f32 y, f32 z);
extern "C" void GXInitLightAttn(char* light, f32 a0, f32 a1, f32 a2, f32 k0, f32 k1, f32 k2);
extern "C" void GXInitLightColor(char* light, u32* color);
extern "C" void GXLoadLightObjImm(char* light, s32 chan);
extern "C" void GXSetChanAmbColor(s32 chan, u32* color);
extern "C" void GXSetChanMatColor(s32 chan, u32* color);
extern "C" void fn_80158E88(void) {
    u32 c1;
    u32 c2;
    u32 c3;
    u32 c4;

    GXInitLightPos(lbl_804BFB60, lbl_8053D454, lbl_8053D454, lbl_8053D458);
    GXInitLightAttn(lbl_804BFB60, lbl_8053D43C, lbl_8053D440, lbl_8053D440, lbl_8053D43C, lbl_8053D440, lbl_8053D440);
    c1 = lbl_8053D420;
    GXInitLightColor(lbl_804BFB60, &c1);
    GXLoadLightObjImm(lbl_804BFB60, 1);
    GXInitLightPos(lbl_804BFB60, lbl_8053D458, lbl_8053D454, lbl_8053D458);
    c2 = lbl_8053D424;
    GXInitLightColor(lbl_804BFB60, &c2);
    GXLoadLightObjImm(lbl_804BFB60, 2);
    c3 = lbl_8053D428;
    GXSetChanAmbColor(4, &c3);
    c4 = lbl_8053D42C;
    GXSetChanMatColor(4, &c4);
}

extern "C" void fn_80159330(char* p) {
    s32 kind = *(s32*)(lbl_8053AAF8 + 0x4c);
    u8 flag = 0;
    if (kind == 0xc) {
        return;
    }
    if (*(u8*)(lbl_8053AAF8 + 0x7f) == 0) {
        switch (kind) {
        case 7:
        case 8:
        case 9:
        case 0x16:
        case 0xa:
        case 0xb:
        case 0xc:
            flag = 1;
            break;
        }
    } else {
        switch (kind) {
        case 7:
        case 8:
        case 9:
        case 0x16:
        case 0xa:
        case 0xb:
            flag = 1;
            break;
        }
    }
    if (flag) {
        if (fn_802DCD0C(fn_802D6A9C())) {
            goto end;
        }
    }
    if (*(u8*)(lbl_8053AAF8 + 0x94) == 0 && *(u8*)(lbl_8053AAF8 + 0x96) == 0) {
        *(u8*)(p + 0xd) = 0;
    }
end:
    *(u8*)(p + 0xe) = 0xff;
}

extern "C" void fn_8015945C(char* p) {
    *(u8*)(p + 0x4) = 0xff;
    *(u8*)(p + 0x5) = 0xff;
    *(u8*)(p + 0x6) = 0xff;
    *(u8*)(p + 0x7) = 0;
    *(u8*)(p + 0xc) = 0xff;
    *(u8*)(p + 0xd) = 0;
    *(u8*)(p + 0xe) = 0xff;
}

extern "C" char lbl_804A0160[];
extern "C" char lbl_80465E28[];
extern "C" char* lbl_8053AAF8;
extern "C" void __dt__10JUTTextureFv(char* p, s32 flag);
extern "C" void __dl__FPv(void* p);
extern "C" void* __nw__FUlP7JKRHeapi(u32 size, void* heap, s32 align);
extern "C" void storeTIMG__10JUTTextureFPC7ResTIMGUc(char* self, const void* timg, u8 palette);
extern "C" char* fn_80159484(char* p, s16 param_2) {
    if (p != 0) {
        *(char**)p = lbl_804A0160;
        __dt__10JUTTextureFv(*(char**)(p + 0x8), 1);
        if (param_2 > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" char* fn_801594E8(char* p, void* heap) {
    struct VObj {
        virtual void v00();
        virtual void v01();
        virtual void v02();
        virtual void v03();
        virtual void* v04(u32, void*);
    };
    char* tex;
    VObj* sub;
    void* uVar2;

    *(char**)p = lbl_804A0160;
    *(s32*)(p + 0x4) = -1;
    tex = (char*)__nw__FUlP7JKRHeapi(0x40, heap, 0);
    if (tex != 0) {
        sub = *(VObj**)(lbl_8053AAF8 + 0xa4);
        uVar2 = sub->v04(0x3f3f3f3f, lbl_80465E28);
        *(s32*)(tex + 0x28) = 0;
        storeTIMG__10JUTTextureFPC7ResTIMGUc(tex, uVar2, 0);
        *(u8*)(tex + 0x3b) = *(u8*)(tex + 0x3b) & 2;
    }
    *(char**)(p + 0x8) = tex;
    return p;
}

struct JASGenericMemPool {
    JASGenericMemPool();
    ~JASGenericMemPool();

    void* mRunner;
    int mFreeMemCount;
    int mTotalMemCount;
    u32 mUsedMemCount;
};

template <typename T>
struct JASMemPool : public JASGenericMemPool {
    JASMemPool<T>() : JASGenericMemPool() {}
    ~JASMemPool<T>() {}
};

template <typename T>
struct JASMemPool_MultiThreaded : public JASGenericMemPool {};

class JASTrack {
public:
    class TChannelMgr;
};
class JASChannel;
class JAIStream;
class JAISoundChild;
class JAISeq;
class JAISe;
class JASPoolObj3_FSA;
class JASPoolObj4_FSA;

template <typename T>
struct JASPoolAllocObject {
    static JASMemPool<T> memPool_;
};

template <typename T>
struct JASPoolAllocObject_MultiThreaded {
    static JASMemPool_MultiThreaded<T> memPool_;
};

template <>
JASMemPool_MultiThreaded<JASTrack::TChannelMgr> JASPoolAllocObject_MultiThreaded<JASTrack::TChannelMgr>::memPool_;
template <>
JASMemPool_MultiThreaded<JASTrack> JASPoolAllocObject_MultiThreaded<JASTrack>::memPool_;
template <>
JASMemPool_MultiThreaded<JASChannel> JASPoolAllocObject_MultiThreaded<JASChannel>::memPool_;
template <>
JASMemPool<JASPoolObj3_FSA> JASPoolAllocObject<JASPoolObj3_FSA>::memPool_;
template <>
JASMemPool<JASPoolObj4_FSA> JASPoolAllocObject<JASPoolObj4_FSA>::memPool_;
template <>
JASMemPool<JAIStream> JASPoolAllocObject<JAIStream>::memPool_;
template <>
JASMemPool<JAISoundChild> JASPoolAllocObject<JAISoundChild>::memPool_;
template <>
JASMemPool<JAISeq> JASPoolAllocObject<JAISeq>::memPool_;
template <>
JASMemPool<JAISe> JASPoolAllocObject<JAISe>::memPool_;
