// LOSW_80104C3C: .text 0x80104C3C-0x80105368 (actor LOSW)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_80104C3C_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
void operator delete(void* p);
extern void* lbl_8049CB58[];

extern "C" void* fn_80104C3C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049CB58;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- from Game/oscluster_80104c9c.cpp

extern "C" {

// fn_80104C9C(this) - LOSW's real draw(). A pure no-op (`blr`), matching
// the SAME pattern DOOR's and SWT4's draw use ([[project_fsa_door_key0_full_depth]],
// [[project_fsa_flag_switch_helpers]]) - LOSW renders nothing itself.
void fn_80104C9C(void)
{
}

} // extern "C"

// ---- from Game/fn_80104CA0.cpp

// fn_80104CA0(this): LOSW's real update() - a "4-flag consensus checker"
// tick. Advances a mod-50 counter (this->0x24c/0x24d) that triggers a
// fn_801F0D20 sound-cue (ID 3) and resets. If this->0x24e==1, skips
// straight to the tail (already resolved). Otherwise dispatches on
// this->0x240 (0-3, the "consensus mode"): modes 0/1/2 all loop over
// LOSW's own 4 group indices (this->0x230-family, stride 4) calling
// fn_802D6A9C then fn_802D800C(groupIndex) and counting matches
// (mode 0 ALSO counts a group as a "match" if its own index field is 0,
// i.e. an unused slot trivially satisfies the unanimous check): mode 0 =
// ALL 4 flags must be set (unanimous), mode 1 = AT LEAST ONE flag set
// (an OR-gate), mode 2 = a MIXED check (neither all-set nor all-clear -
// 1, 2, or 3 of 4 matched). mode<0 or mode>=3: no loop runs, consensus
// stays false. If consensus reached: calls
// fn_80104EB0(this) and, on its success, a virtual call through
// this->vtable[slot 12] (arg 0xff, 1), sets this->0x24c from a this->0x90
// flag bit, resets this->0x24d, and if this->0x244 is set, marks
// this->0x24e=1 (resolved). If NOT reached: a virtual call through
// this->vtable[slot 12] (arg 0xff, 0), resets this->0x24c/0x24d, and if
// this->0x24f was set, clears it, this->0x24a, and calls fn_80230534.
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void*, u32);
extern "C" void fn_801F0D20(char* this_, u32 code);
extern "C" void fn_80230534(s32 a);
extern "C" u8 fn_80104EB0(void* this_);

struct LoswVtable {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9();
    virtual void slot12(s32 a, s32 b);
};

extern "C" void fn_80104CA0(void* this_) {
    char* t = (char*)this_;

    if (*(u8*)(t + 0x24c)) {
        *(u8*)(t + 0x24d) = *(u8*)(t + 0x24d) + 1;
        if (*(u8*)(t + 0x24d) == 0x32) {
            fn_801F0D20(t, 3);
            *(u8*)(t + 0x24c) = 0;
        }
    }

    if (*(u8*)(t + 0x24e) == 1) {
        return;
    }

    s32 mode = *(s32*)(t + 0x240);
    s32 matchCount = 0;
    s32 consensus = 0;

    if (mode == 1) {
        goto mode1Body;
    } else if (mode >= 1) {
        goto checkMode3;
    }
    if (mode >= 0) {
        goto mode0Body;
    }
    goto dispatchDone;
checkMode3:
    if (mode >= 3) {
        goto dispatchDone;
    }
    goto mode2Body;
mode0Body:
    for (s32 i = 0; i < 4; i++) {
        void* config = fn_802D6A9C();
        u32 groupIdx = *(u32*)(t + 0x230 + i * 4);
        if (fn_802D800C(config, groupIdx) || *(s32*)(t + 0x230 + i * 4) == 0) {
            matchCount++;
        }
    }
    if (matchCount == 4) {
        consensus = 1;
    }
    goto dispatchDone;
mode1Body:
    for (s32 i = 0; i < 4; i++) {
        void* config = fn_802D6A9C();
        u32 groupIdx = *(u32*)(t + 0x230 + i * 4);
        if (fn_802D800C(config, groupIdx)) {
            matchCount++;
        }
    }
    if (matchCount != 0) {
        consensus = 1;
    }
    goto dispatchDone;
mode2Body:
    for (s32 i = 0; i < 4; i++) {
        void* config = fn_802D6A9C();
        u32 groupIdx = *(u32*)(t + 0x230 + i * 4);
        if (fn_802D800C(config, groupIdx)) {
            matchCount++;
        }
    }
    if (matchCount != 0 && matchCount != 4) {
        consensus = 1;
    }
dispatchDone:;

    if (consensus != 0) {
        if (fn_80104EB0(this_)) {
            ((LoswVtable*)this_)->slot12(0xff, 1);
            if (*(u32*)(t + 0x90) & 0x20) {
                *(u8*)(t + 0x24c) = 1;
            }
            *(u8*)(t + 0x24d) = 0;
            if (*(s32*)(t + 0x244) != 0) {
                *(u8*)(t + 0x24e) = 1;
            }
        }
    } else {
        ((LoswVtable*)this_)->slot12(0xff, 0);
        *(u8*)(t + 0x24c) = 0;
        if (*(u8*)(t + 0x24f)) {
            *(u8*)(t + 0x24f) = 0;
            *(u16*)(t + 0x24a) = 0;
            fn_80230534(0);
        }
    }
}

// ---- fn_80104EB0 / fn_80105068
extern "C" u8 fn_8023077C(void);
extern "C" u8 fn_8023F264(s32 i);
extern "C" void* fn_8023E724(s32 i);
extern "C" void fn_8030C210(void* p, void* q);
extern "C" void fn_80230498(s32 i, void* p, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_80230FD0(s32 i, s32 a);
extern u8* lbl_8053AB10;

extern "C" u8 fn_80104EB0(void* this_) {
    u8* t = (u8*)this_;
    s32 i;
    if ((*(u32*)(t + 0x90) & 0x40) == 0) {
        return 1;
    }
    switch (*(u8*)(t + 0x24F)) {
    case 0:
        if (fn_8023077C()) {
            (*(u8*)(t + 0x24F))++;
            *(u16*)(t + 0x248) = 30;
        }
        break;
    case 1:
        for (i = 0; i < 4; i++) {
            if (fn_8023F264(i)) {
                fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), fn_8023E724(i));
            }
        }
        (*(u16*)(t + 0x248))--;
        if (*(u16*)(t + 0x248) == 0) {
            (*(u16*)(t + 0x24A))++;
            for (i = 0; i < 4; i++) {
                if (fn_8023F264(i)) {
                    fn_80230498(i, fn_8023E724(i), *(u16*)(t + 0x24A) + 0xDB, 0xFF, -0x80, -0x80, 1);
                    if (*(u16*)(t + 0x24A) == 1) {
                        fn_80230FD0(i, 0x10001);
                    }
                }
            }
            *(u16*)(t + 0x248) = 2;
            if (*(u16*)(t + 0x24A) == 13) {
                (*(u8*)(t + 0x24F))++;
                *(u16*)(t + 0x248) = 50;
            }
        }
        break;
    case 2:
        (*(u16*)(t + 0x248))--;
        if (*(u16*)(t + 0x248) == 0) {
            *(u8*)(t + 0x24F) = 0;
            *(u16*)(t + 0x24A) = 0;
            fn_80230534(0);
            return 1;
        }
        break;
    }
    return 0;
}

class LOSW_Actor {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual u8 vf34();
};

static const s32 sLoswShifts[4] = {22, 17, 12, 7};

extern "C" void fn_80105068(void* this_) {
    u8* t = (u8*)this_;
    const s32* sh = sLoswShifts;
    *(u32*)(t + 0x230) = (*(u32*)(t + 0x90) >> sh[0]) & 0x1F;
    *(u32*)(t + 0x234) = (*(u32*)(t + 0x90) >> sh[1]) & 0x1F;
    *(u32*)(t + 0x238) = (*(u32*)(t + 0x90) >> sh[2]) & 0x1F;
    *(u32*)(t + 0x23C) = (*(u32*)(t + 0x90) >> sh[3]) & 0x1F;
    *(u32*)(t + 0x240) = *(u32*)(t + 0x90) & 0xF;
    *(s32*)(t + 0x244) = *(u32*)(t + 0x90) & 0x10;
    *(u8*)(t + 0x24C) = 0;
    *(u8*)(t + 0x24D) = 0;
    *(u8*)(t + 0x24F) = 0;
    *(u16*)(t + 0x24A) = 0;
    *(u16*)(t + 0x248) = 0;
    if (*(s32*)(t + 0x244) != 0) {
        if (((LOSW_Actor*)this_)->vf34()) {
            *(u8*)(t + 0x24E) = 1;
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
