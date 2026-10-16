#include "JSystem/JGeometry/Vec.h"

class WaveController {
public:
    WaveController(s32 a, s32 b, s32 c);
    ~WaveController();
private:
    unsigned char pad[0x5c];
};

struct WaveSubBase { u8 pad[8]; };
struct WaveSub : WaveSubBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void release(s32 how);
};

struct WaveOwner {
    void* vtbl;
    void* mpSub;
};

extern void* lbl_804A7C98;
extern void* lbl_8053AC98;
extern char* lbl_8053AB10;
extern "C" s32 fn_80226BC4(JGeometry::TVec2<f32>* pos, s32 room);
extern "C" void fn_802F9974(void* mgr, u32 room, s32 idx, u16 value);
