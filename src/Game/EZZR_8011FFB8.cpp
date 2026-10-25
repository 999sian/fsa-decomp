#include "types.h"
#include "Game/Actor.h"

class GateRegistry;
extern "C" GateRegistry* fn_80131F0C(void);
extern "C" u8* fn_80131E30(GateRegistry*, s32);

static inline f32 EZZR_Sqrt(f32 x) {
    if (x <= 0.0f) {
        return x;
    }
    f32 y = __frsqrte(x);
    y = 0.5f * y * (3.0f - (x * (y * y)));
    return x * y;
}

class EZZR : public Actor {
public:
    virtual void v19();
    virtual u8 v20();
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

extern "C" void fn_801220C4(void*);
extern "C" void fn_8012202C(void*);
extern "C" void fn_80121FA8(void*);
extern "C" void fn_80121D68(void*);
extern "C" s32 fn_8012285C(void*);
extern "C" s32 fn_80230CFC(s32);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7A08(void*, u32);
extern "C" void* fn_801F666C(void*, s32);
extern "C" s32 fn_801F78F4(void*, u32, s32);
extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_802D8050(void*, s32, s32, s32);
extern "C" void fn_80131EE4(void);
extern "C" void* fn_801283E8(void);
extern "C" void fn_80127ED8(void*, void*);
extern "C" void fn_80127E20(void*, void*);
extern "C" s32 fn_80123E80(u8*, s32);
extern "C" s32 Actor_CreateByID(void*, u32, u32, f32*, u32, s32, s32);
extern s32 lbl_80539F30;
extern "C" void fn_80120174(EZZR* p, s32 param) {
    s32 id;
    void* other;
    *((u8*)p + 0x330) = 0;
    switch (param) {
    case 0:
        *((u8*)p + 0x330) = 1;
        fn_801D22DC((u8*)p + 0x230, 7, 2, 0);
        break;
    case 2:
        *(s32*)((u8*)p + 0x3c8) = 0;
        *((u8*)p + 0x330) = 1;
        fn_801220C4(p);
        break;
    case 3:
        *((u8*)p + 0x330) = 1;
        break;
    case 4:
        *((u8*)p + 0x331) = 0;
        break;
    case 5: {
        s32 room;
        *((u8*)p + 0x330) = 1;
        room = *(s32*)((u8*)p + 0x4);
        if (((u8*)fn_802D6A9C())[room + 0x131df] != 0) {
            fn_801D22DC((u8*)p + 0x230, 6, 2, 0);
        } else {
            fn_801D22DC((u8*)p + 0x230, 7, 2, 0);
        }
        break;
    }
    case 7:
        *((u8*)p + 0x11e) = 1;
        break;
    case 8: {
        u32 flags;
        p->detach();
        flags = *(u32*)((u8*)p + 0x90) | 4;
        flags |= fn_8012285C(p) << 3;
        Actor_CreateByID(fn_801F856C(), 0x46415A52, *(u32*)((u8*)p + 0x4), (f32*)((u8*)p + 0xc), flags, -1, -1);
        break;
    }
    case 9:
        fn_8012202C(p);
        break;
    case 10:
        fn_80121FA8(p);
        fn_801D22DC((u8*)p + 0x230, 2, 2, 0);
        break;
    case 11:
        fn_801D22DC((u8*)p + 0x230, fn_80230CFC(fn_8012285C(p)), 2, 0);
        break;
    case 12:
        fn_801D22DC((u8*)p + 0x230, fn_80230CFC(fn_8012285C(p)), 2, 0);
        break;
    case 13: {
        Vec a = p->field_0C;
        Vec b = p->field_0C;
        id = fn_801F7A08(fn_801F856C(), 0x5241494c);
        while (id != -1) {
            other = fn_801F666C(fn_801F856C(), id);
            if (other == 0) {
                break;
            }
            {
                s32 kind = (*(u32*)((u8*)other + 0x90) >> 8) & 0xff;
                if (kind == *(s32*)((u8*)p + 0x35c)) {
                    a = *(Vec*)((u8*)other + 0xc);
                } else if (kind == *(s32*)((u8*)p + 0x3d0)) {
                    b = *(Vec*)((u8*)other + 0xc);
                }
            }
            id = fn_801F78F4(fn_801F856C(), 0x5241494c, id);
        }
        {
            f32 dx = p->field_0C.x - a.x;
            f32 dy = p->field_0C.y - a.y;
            f32 distA = EZZR_Sqrt(dx * dx + dy * dy);
            dx = p->field_0C.x - b.x;
            dy = p->field_0C.y - b.y;
            f32 distB = EZZR_Sqrt(dx * dx + dy * dy);
            if (distA > distB) {
                if (*((u8*)p + 0x3c4) != 0) {
                    fn_80127ED8(fn_801283E8(), &b);
                } else {
                    fn_80127E20(fn_801283E8(), &b);
                }
                *(s32*)((u8*)p + 0x35c) = *(s32*)((u8*)p + 0x3d0);
            } else {
                if (*((u8*)p + 0x3c4) != 0) {
                    fn_80127ED8(fn_801283E8(), &a);
                } else {
                    fn_80127E20(fn_801283E8(), &a);
                }
            }
        }
        fn_80121D68(p);
        fn_801220C4(p);
        break;
    }
    case 14:
        *(s32*)((u8*)p + 0x3c8) = 0;
        break;
    case 15: {
        s32 vid = ((s32 (**)(void*))*(void**)p)[15](p);
        fn_802D8050(fn_802D6A9C(), vid, 1, 0xff);
        *((u8*)p + 0x11e) = 0;
        *((u8*)p + 0x11d) = 0;
        *((u8*)p + 0x11c) = 0;
        lbl_80539F30 = -1;
        fn_80131F0C();
        fn_80131EE4();
        break;
    }
    }
    fn_801D1F14((u8*)p + 0x230, lbl_8053C964);
    fn_80123E80((u8*)p, param);
}

extern "C" void fn_80120570(EZZR* p) {
    f32 box[4];
    box[0] = p->field_0C.x;
    box[1] = p->field_0C.y;
    box[2] = p->field_0C.x;
    box[3] = p->field_0C.y;
}

extern "C" void fn_80120F38(int param_1)
{
    if ((*(unsigned int *)(param_1 + 0x90) & 1) != 0) {
        *(u8 *)(param_1 + 0x3c4) = 1;
    }
    *(unsigned int *)(param_1 + 0x35c) = (*(unsigned int *)(param_1 + 0x90) >> 8) & 0xff;
    *(unsigned int *)(param_1 + 0x3d0) = (*(unsigned int *)(param_1 + 0x90) >> 16) & 0xff;
}

extern "C" s32 fn_80120F68(char* p) {
    u8 r;
    s32 ret;
    s32 state = *(s32*)(p + 0x33c);
    if (state == 0 || state == 0xf) {
        return 3;
    }
    r = ((EZZR*)p)->v20();
    ret = 1;
    if (r) {
        ret = 2;
    }
    return ret;
}

extern "C" f32 fn_80121DC8(void*, s32);
extern f32 lbl_8053C9A8;
extern "C" bool fn_80120FC0(void* p) {
    s32 state = *(s32*)((u8*)p + 0x33c);
    switch (state) {
    case 7:
    case 0xb:
    case 0xc:
        return fn_80121DC8(p, fn_8012285C(p)) <= lbl_8053C9A8;
    case 0xd:
    case 0xe:
    default:
        return false;
    }
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
