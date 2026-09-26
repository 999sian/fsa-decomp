// TU 0x802e72a4-0x802e7634 (actor WAVE).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Wave_EmptyHook.cpp ----
// Wave_EmptyHook - WAVE: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Wave_EmptyHook(void) {}

}

// ---- fn_802E72A8 ----
struct WaveSinkBase { void* pad0; void* pad1; };
struct WaveSink : WaveSinkBase {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void Send(u32* msg);
};

extern "C" void fn_802E72A8(char* p) {
    u32 m0 = 0x3003c;
    (*(WaveSink**)(p + 0x230))->Send(&m0);
    if (*(s32*)(p + 0x234) == 0) {
        *(s32*)(p + 0x234) = 0x3c;
        u32 m1 = 0x3003d;
        (*(WaveSink**)(p + 0x230))->Send(&m1);
    }
}

// ---- Wave_dtor_802E732C.cpp ----
extern "C" void dtor_801F593C(void* this_, int how);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A9EA8[];

struct NonPolyBase {
    void* pad0;
    void* pad1;
};

struct NotifyTarget : NonPolyBase {
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
    virtual void Notify(int arg);
};

static inline void NotifySub(void* obj, int arg) {
    if (obj) {
        ((NotifyTarget*)obj)->Notify(arg);
    }
}

extern "C" void* fn_802E732C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A9EA8;
        void* sub = *(void**)((char*)this_ + 0x230);
        if (sub) {
            NotifySub(sub, 1);
        }
        dtor_801F593C(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Wave_SetParams_802E73B4.cpp ----
// fn_802E73B4 - WAVE: setParams. Sets this->0x234=0x3c (60), allocates and
// placement-constructs an owned "wave controller" sub-object via a genuine
// `new` expression, storing the result at this->0x230 (referenced by
// update()/the destructor). The real class name/fields aren't known yet -
// the class body here is an honest byte-count placeholder (padded to the
// real sizeof, 0x5c) rather than a guessed field layout.
//
// This is the first "owned sub-object" pattern landed as real C++ - it
// required identifying fn_80084370/dtor_80084580 as this project's global
// operator new(unsigned long)/operator delete(void*) (see
// reference_fsa_operator_new_delete_identified.md) and aliasing MWCC's
// auto-generated mangled call targets to them via the LCF (see
// config/G4SE01/ldscript.tpl), since a real `new`-expression is the only
// way to get MWCC to emit the correct exception-safety DESTROYLOCAL/
// DELETEPOINTER extab entry - a hand-written pointer/malloc-style
// implementation compiles to matching .text bytes but omits this entirely.



class WaveController {
public:
    WaveController(s32 a, s32 b, s32 c);
    ~WaveController();
private:
    unsigned char pad[0x5c];
};

extern "C" void Wave_SetParams(void* this_) {
    char* p = (char*)this_;
    *(s32*)(p + 0x234) = 0x3c;
    *(WaveController**)(p + 0x230) = new WaveController(0, 0, 8);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
