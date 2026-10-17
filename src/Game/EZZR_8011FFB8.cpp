#include "types.h"
#include "Game/Actor.h"

class GateRegistry;
extern "C" GateRegistry* fn_80131F0C(void);
extern "C" u8* fn_80131E30(GateRegistry*, s32);

class EZZR : public Actor {
public:
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25(s32);
    u8 field_230[0x38];
};

extern "C" void fn_80123394(void*);
extern "C" void fn_80124278(void*);
extern "C" void fn_80124448(void*);
extern "C" void fn_80131EC0(GateRegistry*, void*);
extern "C" void fn_8011FFCC(void* p) {
}

extern "C" bool fn_8011FFD0(Actor* p) {
    if (*(s32*)fn_80131F0C() < 2) {
        return false;
    }
    Actor* other = (Actor*)fn_80131E30(fn_80131F0C(), 1);
    if (other == 0) {
        return false;
    }
    return p->field_198 == other->field_198;
}

extern "C" s32 fn_80120040(void* p) {
    return 1;
}

extern "C" void fn_80120048(void* p) {
    fn_80123394(p);
}

extern "C" void fn_80120068(void* p) {
    ((EZZR*)p)->v25(12);
}

extern "C" void fn_80120098(void* p) {
    ((EZZR*)p)->v25(9);
}

extern "C" void fn_801200C8(void* p) {
    ((EZZR*)p)->v25(11);
}

extern "C" void fn_80121DB0(void);
extern "C" void fn_801200F8(void)
{
	fn_80121DB0();
}

class GateRegistry;
extern "C" GateRegistry* fn_80131F0C(void);
extern "C" u8* fn_80131E30(GateRegistry*, s32);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern u8 lbl_8049DF40[];
extern f32 lbl_8053C964;
extern "C" void fn_80120118(EZZR* p) {
    fn_801D2608(p->field_230, lbl_8049DF40, 14);
    fn_801D22DC(p->field_230, 7, 2, 0);
    fn_801D1F14(p->field_230, lbl_8053C964);
}

extern "C" void fn_80120F38(int param_1)
{
    if ((*(unsigned int *)(param_1 + 0x90) & 1) != 0) {
        *(u8 *)(param_1 + 0x3c4) = 1;
    }
    *(unsigned int *)(param_1 + 0x35c) = (*(unsigned int *)(param_1 + 0x90) >> 8) & 0xff;
    *(unsigned int *)(param_1 + 0x3d0) = (*(unsigned int *)(param_1 + 0x90) >> 16) & 0xff;
}

extern "C" s32 fn_80121040(void* p)
{
	switch (*(s32*)((u8*)p + 0x33c)) {
	case 7:
	case 9:
	case 10:
	case 11:
	case 12:
		return 1;
	}
	return 0;
}

extern "C" void fn_80121074(void* p)
{
	if (*(s32*)((u8*)p + 0x33c) != 0xf) {
		fn_80124278(p);
	}
}

extern "C" void fn_80124278(void*);
extern "C" void fn_80124448(void*);
extern "C" void fn_80131EC0(GateRegistry*, void*);
extern "C" void fn_801210A0(void* p)
{
	fn_80124448(p);
	u32 flags = *(u32*)((u8*)p + 0x90);
	if ((flags >> 2) & 1) {
		*(u32*)((u8*)p + 0x344) = (flags >> 3) & 0xf;
		fn_80131EC0(fn_80131F0C(), p);
		((EZZR*)p)->v25(7);
	}
}

extern u8 lbl_8049DF78[];
extern "C" void fn_80124740(void*, s32);
extern "C" void* fn_80121104(void* p, s16 flag) {
    if (p != 0) {
        *(u8**)p = lbl_8049DF78;
        fn_80124740(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_801247C8(void*, void*, s32, s32);
extern u8 lbl_80464CC0[];
extern "C" void* fn_80121164(u8* p) {
    fn_801247C8(p, lbl_80464CC0, 0x242, 0);
    *(void**)p = lbl_8049DF78;
    *(u8*)(p + 0x3c4) = 0;
    *(s32*)(p + 0x3c8) = 0;
    *(s32*)(p + 0x3cc) = -1;
    *(s32*)(p + 0x3d0) = 0;
    return p;
}

void __sinit_EZZR_8011FFB8_cpp(void) {
}

extern "C" s32 fn_8011FFB8(void)
{
	return 0;
}

extern "C" s32 fn_8011FFC0(void)
{
	return 0;
}

extern "C" void fn_8011FFC8(void) {}
class JASGenericMemPool {
public:
    void* mRunner;
    s32 mFreeMemCount;
    s32 mTotalMemCount;
    u32 mUsedMemCount;
    JASGenericMemPool();
    ~JASGenericMemPool();
};

template <typename T>
class JASMemPool_MultiThreaded : public JASGenericMemPool {
public:
    ~JASMemPool_MultiThreaded();
};

template <typename T>
class JASMemPool : public JASGenericMemPool {
public:
    ~JASMemPool();
};

template <typename T>
class JASPoolAllocObject_MultiThreaded {
public:
    static JASMemPool_MultiThreaded<T> memPool_;
};

template <typename T>
class JASPoolAllocObject {
public:
    static JASMemPool<T> memPool_;
};

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

template <> JASMemPool_MultiThreaded<JASTrack::TChannelMgr> JASPoolAllocObject_MultiThreaded<JASTrack::TChannelMgr>::memPool_;
template <> JASMemPool_MultiThreaded<JASTrack> JASPoolAllocObject_MultiThreaded<JASTrack>::memPool_;
template <> JASMemPool_MultiThreaded<JASChannel> JASPoolAllocObject_MultiThreaded<JASChannel>::memPool_;
template <> JASMemPool<JASPoolObj3_FSA> JASPoolAllocObject<JASPoolObj3_FSA>::memPool_;
template <> JASMemPool<JASPoolObj4_FSA> JASPoolAllocObject<JASPoolObj4_FSA>::memPool_;
template <> JASMemPool<JAIStream> JASPoolAllocObject<JAIStream>::memPool_;
template <> JASMemPool<JAISoundChild> JASPoolAllocObject<JAISoundChild>::memPool_;
template <> JASMemPool<JAISeq> JASPoolAllocObject<JAISeq>::memPool_;
template <> JASMemPool<JAISe> JASPoolAllocObject<JAISe>::memPool_;
