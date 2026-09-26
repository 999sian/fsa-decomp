// TU 0x801f9484-0x80204638.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Gsck_ctor_801FF744.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA800[];

extern "C" void* fn_801FF744(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA800;
    return this_;
}

// ---- Mrtc_ctor_801FF780.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AD278[];

extern "C" void* fn_801FF780(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AD278;
    return this_;
}

// ---- Stgn_ctor_801FF7BC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA7A8[];

extern "C" void* fn_801FF7BC(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA7A8;
    return this_;
}

// ---- Rins_ctor_801FF7F8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AD220[];

extern "C" void* fn_801FF7F8(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AD220;
    return this_;
}

// ---- Wpwl_ctor_801FF834.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE948[];

extern "C" void* fn_801FF834(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AE948;
    return this_;
}

// ---- Pss2_ctor_801FF870.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE8F4[];

extern "C" void* fn_801FF870(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AE8F4;
    return this_;
}

// ---- Tbo2_ctor_801FF918.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA750[];

extern "C" void* fn_801FF918(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA750;
    return this_;
}

// ---- Tbgn_ctor_801FF954.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA6F8[];

extern "C" void* fn_801FF954(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA6F8;
    return this_;
}

// ---- Iceb_ctor_801FF990.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE888[];

extern "C" void* fn_801FF990(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AE888;
    return this_;
}

// ---- Dmyk_ctor_801FF9CC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA6A0[];

extern "C" void* fn_801FF9CC(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA6A0;
    return this_;
}

// ---- Jpe2_ctor_801FFA08.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AD1C8[];

extern "C" void* fn_801FFA08(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AD1C8;
    return this_;
}

// ---- Endr_ctor_801FFA44.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE830[];

extern "C" void* fn_801FFA44(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AE830;
    return this_;
}

// ---- Tfl2_ctor_801FFA80.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA628[];

extern "C" void* fn_801FFA80(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA628;
    return this_;
}

// ---- Losw_ctor_801FFABC.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049CB58[];

extern "C" void* fn_801FFABC(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049CB58;
    *(u8*)((char*)this_ + 0x24e) = 0;
    return this_;
}

// ---- Pswk_ctor_801FFB00.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE5C8[];

extern "C" void* fn_801FFB00(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AE5C8;
    return this_;
}

// ---- Sibt_ctor_801FFB3C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049CB04[];

extern "C" void* fn_801FFB3C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049CB04;
    return this_;
}

// ---- Pswb_ctor_801FFB78.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE574[];

extern "C" void* fn_801FFB78(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AE574;
    return this_;
}

// ---- Glwp_ctor_801FFBB4.cpp ----
struct Actor {
    Actor();
    ~Actor();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A39DC[];

class Glwp : public Actor {
public:
    Glwp();
};

Glwp::Glwp() : Actor() {
    *(void**)this = lbl_804A39DC;
    __construct_array((char*)this + 0x264, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Snpc_ctor_801FFC0C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AAFB8[];

extern "C" void* fn_801FFC0C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AAFB8;
    return this_;
}

// ---- Tjij_ctor_801FFC48.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE508[];

extern "C" void* fn_801FFC48(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AE508;
    return this_;
}

// ---- Mrta_ctor_801FFC84.cpp ----
struct Actor_21 {
    Actor_21();
    ~Actor_21();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_801FFCDC(void);
extern void* lbl_804ACD70[];

class Mrta : public Actor_21 {
public:
    Mrta();
};

Mrta::Mrta() : Actor_21() {
    *(void**)this = lbl_804ACD70;
    __construct_array((char*)this + 0x268, (void*)fn_801FFCDC, 0, 0x14, 4);
}

// ---- stub_801ffcdc.cpp ----
// Empty virtual-hook stub (see Game/ActorDefaultHooks.cpp).
extern "C" void fn_801FFCDC(void) {}

// ---- Swdl_ctor_801FFCE0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA590[];

extern "C" void* fn_801FFCE0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA590;
    return this_;
}

// ---- fn_801FFD1C_ctor.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE7D8[];

extern "C" void* fn_801FFD1C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AE7D8;
    return this_;
}

// ---- fn_801FFD58_ctor.cpp ----
struct Actor_25 {
    Actor_25();
    ~Actor_25();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804AE4B0[];

class fn_801FFD58_actor : public Actor_25 {
public:
    fn_801FFD58_actor();
};

fn_801FFD58_actor::fn_801FFD58_actor() : Actor_25() {
    *(void**)this = lbl_804AE4B0;
    __construct_array((char*)this + 0x264, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x294, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x2c4, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x2f4, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Elk2_ctor_801FFE04.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE338[];

extern "C" void* fn_801FFE04(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AE338;
    return this_;
}

// ---- Ptmi_ctor_801FFE40.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE780[];

extern "C" void* fn_801FFE40(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AE780;
    return this_;
}

// ---- Mrmt_ctor_801FFE7C.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049EA88[];

extern "C" void* fn_801FFE7C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049EA88;
    *(s32*)((char*)this_ + 0x230) = 0;
    *(s32*)((char*)this_ + 0x234) = -1;
    *(s32*)((char*)this_ + 0x238) = -1;
    *(s32*)((char*)this_ + 0x23c) = -1;
    *(s32*)((char*)this_ + 0x240) = -1;
    *(s32*)((char*)this_ + 0x244) = 0;
    *(s32*)((char*)this_ + 0x248) = 0;
    *(s32*)((char*)this_ + 0x24c) = 0;
    return this_;
}

// ---- Ltev_ctor_801FFEE0.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA4F0[];

extern "C" void* fn_801FFEE0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA4F0;
    *(s32*)((char*)this_ + 0x248) = -1;
    return this_;
}

// ---- Rsnp_ctor_801FFF24.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804ACD18[];

extern "C" void* fn_801FFF24(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804ACD18;
    return this_;
}

// ---- Ogst_ctor_801FFF60.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049EA00[];

extern "C" void* fn_801FFF60(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049EA00;
    *(s32*)((char*)this_ + 0x230) = 0;
    return this_;
}

// ---- Icob_ctor_801FFFA4.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049E9A8[];

extern "C" void* fn_801FFFA4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049E9A8;
    *(s32*)((char*)this_ + 0x230) = 0;
    return this_;
}

// ---- Emsk_ctor_801FFFE8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA498[];

extern "C" void* fn_801FFFE8(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA498;
    return this_;
}

// ---- Tutm_ctor_80200024.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804ACBF0[];

extern "C" void* fn_80200024(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804ACBF0;
    return this_;
}

// ---- fn_80200060_ctor.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804ACC68[];

extern "C" void* fn_80200060(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804ACC68;
    return this_;
}

// ---- Tugf_ctor_8020009C.cpp ----
struct Actor_36 {
    Actor_36();
    ~Actor_36();
};

extern "C" void fn_801EB950(void*);
extern void* lbl_804ACCC0[];

class Tugf : public Actor_36 {
public:
    Tugf();
};

Tugf::Tugf() : Actor_36() {
    *(void**)this = lbl_804ACCC0;
    fn_801EB950((char*)this + 0x230);
}

// ---- Leaf_ctor_802000E0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE2E0[];

extern "C" void* fn_802000E0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AE2E0;
    return this_;
}

// ---- Lfgn_ctor_8020011C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE288[];

extern "C" void* fn_8020011C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AE288;
    return this_;
}

// ---- Thcl_ctor_80200158.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A7C40[];

extern "C" void* fn_80200158(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A7C40;
    return this_;
}

// ---- Agbw_ctor_80200194.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA440[];

extern "C" void* fn_80200194(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA440;
    return this_;
}

// ---- Svgt_ctor_802001D0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804ACB98[];

extern "C" void* fn_802001D0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804ACB98;
    return this_;
}

// ---- Tmi2_ctor_8020020C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE728[];

extern "C" void* fn_8020020C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AE728;
    return this_;
}

// ---- Safu_ctor_80200248.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A3948[];

extern "C" void* fn_80200248(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A3948;
    return this_;
}

// ---- Fdwp_ctor_80200284.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049E8F8[];

extern "C" void* fn_80200284(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049E8F8;
    *(s32*)((char*)this_ + 0x230) = 0;
    *(s32*)((char*)this_ + 0x234) = 0;
    *(s32*)((char*)this_ + 0x238) = 0;
    *(s32*)((char*)this_ + 0x23c) = 0;
    return this_;
}

// ---- Twev_ctor_802002D4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049CA40[];

extern "C" void* fn_802002D4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049CA40;
    return this_;
}

// ---- Dwap_ctor_80200310.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C9E8[];

extern "C" void* fn_80200310(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049C9E8;
    return this_;
}

// ---- Tooi_ctor_8020034C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804ACB40[];

extern "C" void* fn_8020034C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804ACB40;
    return this_;
}

// ---- Chsw_ctor_80200388.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA3E8[];

extern "C" void* fn_80200388(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA3E8;
    return this_;
}

// ---- Tlwp_ctor_802003C4.cpp ----
struct Actor_49 {
    Actor_49();
    ~Actor_49();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A38D4[];

class Tlwp : public Actor_49 {
public:
    Tlwp();
};

Tlwp::Tlwp() : Actor_49() {
    *(void**)this = lbl_804A38D4;
    __construct_array((char*)this + 0x264, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Jwlk_ctor_8020041C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AABA8[];

extern "C" void* fn_8020041C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AABA8;
    return this_;
}

// ---- Rbpn_ctor_80200458.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049E848[];

extern "C" void* fn_80200458(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049E848;
    *(s32*)((char*)this_ + 0x230) = 0;
    *(s32*)((char*)this_ + 0x234) = 0;
    *(s32*)((char*)this_ + 0x238) = 0;
    *(s32*)((char*)this_ + 0x23c) = 0;
    *(s32*)((char*)this_ + 0x240) = 0;
    *(s32*)((char*)this_ + 0x244) = 0;
    return this_;
}

// ---- Psw2_ctor_802004B0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE230[];

extern "C" void* fn_802004B0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AE230;
    return this_;
}

// ---- Gnef_ctor_802004EC.cpp ----
struct Actor_53 {
    Actor_53();
    ~Actor_53();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_80200544(void);
extern void* lbl_804AA350[];

class Gnef : public Actor_53 {
public:
    Gnef();
};

Gnef::Gnef() : Actor_53() {
    *(void**)this = lbl_804AA350;
    __construct_array((char*)this + 0x27c, (void*)fn_80200544, 0, 0x14, 4);
}

// ---- stub_80200544.cpp ----
// Empty virtual-hook stub (see Game/ActorDefaultHooks.cpp).
extern "C" void fn_80200544(void) {}

// ---- Stpn_ctor_80200548.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA2D8[];

extern "C" void* fn_80200548(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA2D8;
    return this_;
}

// ---- Tomi_ctor_80200584.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE6D0[];

extern "C" void* fn_80200584(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AE6D0;
    return this_;
}

// ---- Medm_ctor_802005C0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE678[];

extern "C" void* fn_802005C0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AE678;
    return this_;
}

// ---- Sdsm_ctor_802005FC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA280[];

extern "C" void* fn_802005FC(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA280;
    return this_;
}

// ---- Bck2_ctor_80200638.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE620[];

extern "C" void* fn_80200638(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AE620;
    return this_;
}

// ---- Svtg_ctor_80200674.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AAB40[];

extern "C" void* fn_80200674(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AAB40;
    return this_;
}

// ---- Dnav_ctor_802006B0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804ADFE8[];

extern "C" void* fn_802006B0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804ADFE8;
    return this_;
}

// ---- Zomo_ctor_802006EC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA228[];

extern "C" void* fn_802006EC(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA228;
    return this_;
}

// ---- Zdco_ctor_80200728.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A375C[];

extern "C" void* fn_80200728(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A375C;
    return this_;
}

// ---- fn_80200764_ctor.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A3698[];

extern "C" void* fn_80200764(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A3698;
    return this_;
}

// ---- Zld3_ctor_802007A0.cpp ----
struct Actor_65 {
    Actor_65();
    ~Actor_65();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A35AC[];

class Zld3 : public Actor_65 {
public:
    Zld3();
};

Zld3::Zld3() : Actor_65() {
    *(void**)this = lbl_804A35AC;
    __construct_array((char*)this + 0x288, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Oblf_ctor_802007F8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804ACA00[];

extern "C" void* fn_802007F8(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804ACA00;
    return this_;
}

// ---- Gen3_ctor_80200834.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA1D0[];

extern "C" void* fn_80200834(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA1D0;
    return this_;
}

// ---- Egol_ctor_80200870.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A3548[];

extern "C" void* fn_80200870(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A3548;
    return this_;
}

// ---- Ynsw_ctor_802008AC.cpp ----
struct Actor_69 {
    Actor_69();
    ~Actor_69();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804AC9A8[];

class Ynsw : public Actor_69 {
public:
    Ynsw();
};

Ynsw::Ynsw() : Actor_69() {
    *(void**)this = lbl_804AC9A8;
    __construct_array((char*)this + 0x254, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Gmtb_ctor_80200904.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AAAE8[];

extern "C" void* fn_80200904(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AAAE8;
    return this_;
}

// ---- Gmbl_ctor_80200940.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AAA70[];

extern "C" void* fn_80200940(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AAA70;
    return this_;
}

// ---- Eetc_ctor_8020097C.cpp ----
struct Actor_72 {
    Actor_72();
    ~Actor_72();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804ADF28[];

class Eetc : public Actor_72 {
public:
    Eetc();
};

Eetc::Eetc() : Actor_72() {
    *(void**)this = lbl_804ADF28;
    __construct_array((char*)this + 0x27c, (void*)fn_8003B2CC, 0, 0xc, 3);
    __construct_array((char*)this + 0x2a0, (void*)fn_8003B2CC, 0, 0xc, 3);
    __construct_array((char*)this + 0x2c4, (void*)fn_8003B2CC, 0, 0xc, 3);
}

// ---- Rck2_ctor_80200A0C.cpp ----
struct Actor_73 {
    Actor_73();
    ~Actor_73();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
void fn_80200A84(void);
void fn_80200A80(void);
extern void* lbl_804AC950[];

class Rck2 : public Actor_73 {
public:
    Rck2();
};

Rck2::Rck2() : Actor_73() {
    *(void**)this = lbl_804AC950;
    __construct_array((char*)this + 0x260, (void*)fn_80200A84, 0, 0x18, 8);
    __construct_array((char*)this + 0x320, (void*)fn_80200A80, 0, 0x14, 4);
}

// ---- stub_80200a80.cpp ----
// Empty virtual-hook stubs (see Game/ActorDefaultHooks.cpp).
extern "C" {

void fn_80200A80(void) {}
void fn_80200A84(void) {}

}

// ---- Eowl_ctor_80200A88.cpp ----
struct Actor_75 {
    Actor_75();
    ~Actor_75();
};

extern "C" void InitDefaultRecord(void*);
extern void* lbl_804ADAC8[];

class Eowl : public Actor_75 {
public:
    Eowl();
};

Eowl::Eowl() : Actor_75() {
    *(void**)this = lbl_804ADAC8;
    InitDefaultRecord((char*)this + 0x2a0);
}

// ---- Dmtw_ctor_80200ACC.cpp ----
struct Actor_76 {
    Actor_76();
    ~Actor_76();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_8049E770[];

class Dmtw : public Actor_76 {
public:
    Dmtw();
};

Dmtw::Dmtw() : Actor_76() {
    *(void**)this = lbl_8049E770;
    __construct_array((char*)this + 0x25c, (void*)fn_8003B2CC, 0, 0xc, 6);
    __construct_array((char*)this + 0x2c8, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x2f8, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x3b8, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Smri_ctor_80200B78.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA9F0[];

extern "C" void* fn_80200B78(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA9F0;
    return this_;
}

// ---- Elnk_ctor_80200BB4.cpp ----
// fn_80200BB4 - "ELNK" real constructor. Base Actor ctor
// (Actor_ctor) + a DOUBLE vtable install: lbl_804A5958 is
// installed first then immediately overwritten by
// lbl_804AD858 - the confirmed base-overridden-by-derived
// multiple-inheritance pattern (see
// project_fsa_multiple_inheritance_pattern.md). lbl_804A5958 is
// shared with sibling constructors using the exact same intermediate
// vtable, meaning several of these actors share one un-landed mixin
// base class. Identified via the fn_801F9484 dispatcher sweep (see
// reference_fsa_full_dispatch_sweep.md).

extern "C" void* Actor_ctor(void* this_);
extern "C" void* lbl_804A5958[];
extern "C" void* lbl_804AD858[];

extern "C" void* Elnk_ctor(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A5958;
    *(void**)this_ = lbl_804AD858;
    return this_;
}

// ---- fn_80200BFC_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A5958[];

extern "C" void* fn_80200BFC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A5958;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Dtlk_ctor_80200C5C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804B1A48[];

extern "C" void* fn_80200C5C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804B1A48;
    return this_;
}

// ---- Tkra_ctor_80200C98.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA178[];

extern "C" void* fn_80200C98(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA178;
    return this_;
}

// ---- Okam_ctor_80200CD4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A3448[];

extern "C" void* fn_80200CD4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A3448;
    return this_;
}

// ---- Ttat_ctor_80200D10.cpp ----
struct Actor_83 {
    Actor_83();
    ~Actor_83();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A2FB0[];

class Ttat : public Actor_83 {
public:
    Ttat();
};

Ttat::Ttat() : Actor_83() {
    *(void**)this = lbl_804A2FB0;
    __construct_array((char*)this + 0x280, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Goma_ctor_80200D68.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A307C[];

extern "C" void* fn_80200D68(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A307C;
    return this_;
}

// ---- Ddgo_ctor_80200DA4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A3334[];

extern "C" void* fn_80200DA4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A3334;
    return this_;
}

// ---- Endm_ctor_80200DE0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA0FC[];

extern "C" void* fn_80200DE0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA0FC;
    return this_;
}

// ---- Lcls_ctor_80200E1C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA008[];

extern "C" void* fn_80200E1C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA008;
    return this_;
}

// ---- Glbs_ctor_80200E58.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA060[];

extern "C" void* fn_80200E58(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AA060;
    return this_;
}

// ---- Emik_ctor_80200E94.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A5958[];
extern void* lbl_804AD5B8[];

extern "C" void* fn_80200E94(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A5958;
    *(void**)this_ = lbl_804AD5B8;
    return this_;
}

// ---- Ezld_ctor_80200EDC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A5958[];
extern void* lbl_804AD6F0[];

extern "C" void* fn_80200EDC(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A5958;
    *(void**)this_ = lbl_804AD6F0;
    return this_;
}

// ---- Enpc_ctor_80200F24.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AD48C[];

extern "C" void* fn_80200F24(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AD48C;
    return this_;
}

// ---- Hbb2_ctor_80200F60.cpp ----
struct Actor_92 {
    Actor_92();
    ~Actor_92();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A2EC0[];

class Hbb2 : public Actor_92 {
public:
    Hbb2();
};

Hbb2::Hbb2() : Actor_92() {
    *(void**)this = lbl_804A2EC0;
    __construct_array((char*)this + 0x294, (void*)fn_8003B2CC, 0, 0xc, 0x28);
}

// ---- Nwok_ctor_80200FB8.cpp ----
struct Actor_93 {
    Actor_93();
    ~Actor_93();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804AC8C0[];

class Nwok : public Actor_93 {
public:
    Nwok();
};

Nwok::Nwok() : Actor_93() {
    *(void**)this = lbl_804AC8C0;
    __construct_array((char*)this + 0x290, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Saya_ctor_80201010.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A2E30[];

extern "C" void* fn_80201010(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A2E30;
    return this_;
}

// ---- Mjgr_ctor_8020104C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9FB0[];

extern "C" void* fn_8020104C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9FB0;
    return this_;
}

// ---- Htmk_ctor_80201088.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC868[];

extern "C" void* fn_80201088(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AC868;
    return this_;
}

// ---- Enbz_ctor_802010C4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A2CB0[];

extern "C" void* fn_802010C4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A2CB0;
    return this_;
}

// ---- Pnp2_ctor_80201100.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9F58[];

extern "C" void* fn_80201100(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9F58;
    return this_;
}

// ---- Sslf_ctor_8020113C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AD348[];

extern "C" void* fn_8020113C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AD348;
    return this_;
}

// ---- Bemn_ctor_80201178.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC810[];

extern "C" void* fn_80201178(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AC810;
    return this_;
}

// ---- Fobe_ctor_802011B4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC7B8[];

extern "C" void* fn_802011B4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AC7B8;
    return this_;
}

// ---- Sen2_ctor_802011F0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9F00[];

extern "C" void* fn_802011F0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9F00;
    return this_;
}

// ---- Crgn_ctor_8020122C.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049E5B8[];

extern "C" void* fn_8020122C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049E5B8;
    *(s32*)((char*)this_ + 0x230) = 1;
    *(s32*)((char*)this_ + 0x234) = 4;
    *(s32*)((char*)this_ + 0x238) = 0;
    *(s32*)((char*)this_ + 0x23c) = -1;
    *(s32*)((char*)this_ + 0x240) = 0;
    *(s32*)((char*)this_ + 0x244) = 0;
    *(s32*)((char*)this_ + 0x280) = 0;
    return this_;
}

// ---- Tenn_ctor_80201294.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A2BF4[];

extern "C" void* fn_80201294(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A2BF4;
    return this_;
}

// ---- Wave_ctor_802012D0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9EA8[];

extern "C" void* fn_802012D0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9EA8;
    return this_;
}

// ---- Form_ctor_8020130C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A7BE8[];

extern "C" void* fn_8020130C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A7BE8;
    return this_;
}

// ---- Spbg_ctor_80201348.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC760[];

extern "C" void* fn_80201348(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AC760;
    return this_;
}

// ---- Szsc_ctor_802013D8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC708[];

extern "C" void* fn_802013D8(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AC708;
    return this_;
}

// ---- Nnjn_ctor_80201414.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC6B0[];

extern "C" void* fn_80201414(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AC6B0;
    return this_;
}

// ---- Syky_ctor_80201450.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A2B18[];

extern "C" void* fn_80201450(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A2B18;
    return this_;
}

// ---- Anho_ctor_8020148C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C970[];

extern "C" void* fn_8020148C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049C970;
    return this_;
}

// ---- fn_802014C8_ctor.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9E50[];

extern "C" void* fn_802014C8(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9E50;
    return this_;
}

// ---- Fish_ctor_80201504.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC658[];

extern "C" void* fn_80201504(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AC658;
    return this_;
}

// ---- Alce_ctor_80201540.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A2AB0[];

extern "C" void* fn_80201540(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A2AB0;
    return this_;
}

// ---- Zoom_ctor_8020157C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9DF8[];

extern "C" void* fn_8020157C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9DF8;
    return this_;
}

// ---- Bgmn_ctor_802015B8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9DA0[];

extern "C" void* fn_802015B8(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9DA0;
    return this_;
}

// ---- Mgya_ctor_802015F4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C8EC[];

extern "C" void* fn_802015F4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049C8EC;
    return this_;
}

// ---- Gfbs_ctor_80201630.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049E3A8[];

extern "C" void* fn_80201630(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049E3A8;
    return this_;
}

// ---- Blz2_ctor_802016D8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9D28[];

extern "C" void* fn_802016D8(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9D28;
    return this_;
}

// ---- Sev2_ctor_80201714.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9CD0[];

extern "C" void* fn_80201714(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9CD0;
    return this_;
}

// ---- Rnsw_ctor_80201750.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049DE90[];

extern "C" void* fn_80201750(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049DE90;
    *(s32*)((char*)this_ + 0x230) = 1;
    *(s32*)((char*)this_ + 0x234) = 0;
    *(s32*)((char*)this_ + 0x238) = 0;
    *(s32*)((char*)this_ + 0x23c) = 0;
    *(s32*)((char*)this_ + 0x240) = 0;
    return this_;
}

// ---- Senp_ctor_802017A8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9C78[];

extern "C" void* fn_802017A8(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9C78;
    return this_;
}

// ---- Haya_ctor_802017E4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C858[];

extern "C" void* fn_802017E4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049C858;
    return this_;
}

// ---- Brbl_ctor_80201820.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A7B90[];

extern "C" void* fn_80201820(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A7B90;
    return this_;
}

// ---- Limt_ctor_8020185C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804B174C[];

extern "C" void* fn_8020185C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804B174C;
    return this_;
}

// ---- Gol2_ctor_80201898.cpp ----
struct Actor_126 {
    Actor_126();
    ~Actor_126();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A9C20[];

class Gol2 : public Actor_126 {
public:
    Gol2();
};

Gol2::Gol2() : Actor_126() {
    *(void**)this = lbl_804A9C20;
    __construct_array((char*)this + 0x258, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Beee_ctor_802018F0.cpp ----
struct Actor_127 {
    Actor_127();
    ~Actor_127();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804AC600[];

class Beee : public Actor_127 {
public:
    Beee();
};

Beee::Beee() : Actor_127() {
    *(void**)this = lbl_804AC600;
    __construct_array((char*)this + 0x2a4, (void*)fn_8003B2CC, 0, 0xc, 7);
    __construct_array((char*)this + 0x2f8, (void*)fn_8003B2CC, 0, 0xc, 7);
    __construct_array((char*)this + 0x34c, (void*)fn_8003B2CC, 0, 0xc, 7);
}

// ---- Pssw_ctor_80201980.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A7B38[];

extern "C" void* fn_80201980(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A7B38;
    return this_;
}

// ---- Hous_ctor_802019BC.cpp ----
struct Actor_129 {
    Actor_129();
    ~Actor_129();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_801546E4(void*);
extern void* lbl_804A7AE0[];

class Hous : public Actor_129 {
public:
    Hous();
};

Hous::Hous() : Actor_129() {
    *(void**)this = lbl_804A7AE0;
    __construct_array((char*)this + 0x2dc, (void*)fn_801546E4, 0, 0x8, 4);
}

// ---- fn_80201A14_ctor.cpp ----
struct Actor_130 {
    Actor_130();
    ~Actor_130();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A2944[];

class fn_80201A14_actor : public Actor_130 {
public:
    fn_80201A14_actor();
};

fn_80201A14_actor::fn_80201A14_actor() : Actor_130() {
    *(void**)this = lbl_804A2944;
    __construct_array((char*)this + 0x2a4, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x2d4, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Gnon_ctor_80201A88.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A25F0[];

extern "C" void* fn_80201A88(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A25F0;
    return this_;
}

// ---- Bbmb_ctor_80201AC4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC588[];

extern "C" void* fn_80201AC4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AC588;
    return this_;
}

// ---- Bbsl_ctor_80201B00.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC4D0[];

extern "C" void* fn_80201B00(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AC4D0;
    return this_;
}

// ---- fn_80201B3C_ctor.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9BC8[];

extern "C" void* fn_80201B3C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9BC8;
    return this_;
}

// ---- Gbao_ctor_80201B78.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804B16E0[];

extern "C" void* fn_80201B78(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804B16E0;
    return this_;
}

// ---- Offs_ctor_80201BB4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9B70[];

extern "C" void* fn_80201BB4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9B70;
    return this_;
}

// ---- fn_80201BF0_ctor.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC388[];

extern "C" void* fn_80201BF0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AC388;
    return this_;
}

// ---- Lots_ctor_80201C2C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC330[];

extern "C" void* fn_80201C2C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AC330;
    return this_;
}

// ---- Stbl_ctor_80201C68.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC2D8[];

extern "C" void* fn_80201C68(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AC2D8;
    return this_;
}

// ---- Dgt2_ctor_80201D00.cpp ----
struct Actor_140 {
    Actor_140();
    ~Actor_140();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A1FA0[];

class Dgt2 : public Actor_140 {
public:
    Dgt2();
};

Dgt2::Dgt2() : Actor_140() {
    *(void**)this = lbl_804A1FA0;
    __construct_array((char*)this + 0x288, (void*)fn_8003B2CC, 0, 0xc, 6);
    __construct_array((char*)this + 0x2d0, (void*)fn_8003B2CC, 0, 0xc, 0x14);
}

// ---- Rvfr_ctor_80201D74.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC250[];

extern "C" void* fn_80201D74(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AC250;
    return this_;
}

// ---- Wppa_ctor_80201DB0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC1F8[];

extern "C" void* fn_80201DB0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AC1F8;
    return this_;
}

// ---- Flyo_ctor_80201DEC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC100[];

extern "C" void* fn_80201DEC(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AC100;
    return this_;
}

// ---- Bph2_ctor_80201E28.cpp ----
struct Actor_144 {
    Actor_144();
    ~Actor_144();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A1E50[];

class Bph2 : public Actor_144 {
public:
    Bph2();
};

Bph2::Bph2() : Actor_144() {
    *(void**)this = lbl_804A1E50;
    __construct_array((char*)this + 0x2f8, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Prtc_ctor_80201E80.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9AC8[];

extern "C" void* fn_80201E80(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9AC8;
    return this_;
}

// ---- Rasn_ctor_80201EBC.cpp ----
struct Actor_146 {
    Actor_146();
    ~Actor_146();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A7A68[];

class Rasn : public Actor_146 {
public:
    Rasn();
};

Rasn::Rasn() : Actor_146() {
    *(void**)this = lbl_804A7A68;
    __construct_array((char*)this + 0x238, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Fgn2_ctor_80201F14.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A1A98[];

extern "C" void* fn_80201F14(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A1A98;
    return this_;
}

// ---- Wppr_ctor_80201F50.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC0A8[];

extern "C" void* fn_80201F50(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AC0A8;
    return this_;
}

// ---- Jpen_ctor_80201F8C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC010[];

extern "C" void* fn_80201F8C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AC010;
    return this_;
}

// ---- Wnwn_ctor_80201FC8.cpp ----
struct Actor_150 {
    Actor_150();
    ~Actor_150();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A18E0[];

class Wnwn : public Actor_150 {
public:
    Wnwn();
};

Wnwn::Wnwn() : Actor_150() {
    *(void**)this = lbl_804A18E0;
    __construct_array((char*)this + 0x294, (void*)fn_8003B2CC, 0, 0xc, 0xa);
    __construct_array((char*)this + 0x30c, (void*)fn_8003B2CC, 0, 0xc, 0xa);
}

// ---- Urac_ctor_8020203C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9A70[];

extern "C" void* fn_8020203C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9A70;
    return this_;
}

// ---- Vwmd_ctor_80202078.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9A18[];

extern "C" void* fn_80202078(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9A18;
    return this_;
}

// ---- Tkrm_ctor_802020B4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804ABAE8[];

extern "C" void* fn_802020B4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804ABAE8;
    return this_;
}

// ---- Bots_ctor_802020F0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C7F0[];

extern "C" void* fn_802020F0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049C7F0;
    return this_;
}

// ---- Tsno_ctor_8020212C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804ABA90[];

extern "C" void* fn_8020212C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804ABA90;
    return this_;
}

// ---- Grve_ctor_80202168.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A99C0[];

extern "C" void* fn_80202168(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A99C0;
    return this_;
}

// ---- Yasi_ctor_802021A4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9968[];

extern "C" void* fn_802021A4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9968;
    return this_;
}

// ---- Btin_ctor_802021E0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A927C[];

extern "C" void* fn_802021E0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A927C;
    return this_;
}

// ---- fn_8020221C_ctor.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A1888[];

extern "C" void* fn_8020221C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A1888;
    return this_;
}

// ---- fn_80202258_ctor.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A1790[];

extern "C" void* fn_80202258(void* this_) {
    Actor_ctor(this_);
    char* p = (char*)this_;
    *(void**)p = lbl_804A1790;
    *(s32*)(p + 0x234) = -1;
    return this_;
}

// ---- fn_8020229C_ctor.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A1718[];

extern "C" void* fn_8020229C(void* this_) {
    Actor_ctor(this_);
    char* p = (char*)this_;
    *(void**)p = lbl_804A1718;
    *(s32*)(p + 0x234) = -1;
    return this_;
}

// ---- Dsin_ctor_802022E0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB5D8[];

extern "C" void* fn_802022E0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AB5D8;
    return this_;
}

// ---- Grok_ctor_8020231C.cpp ----
struct Actor_163 {
    Actor_163();
    ~Actor_163();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A1630[];

class Grok : public Actor_163 {
public:
    Grok();
};

Grok::Grok() : Actor_163() {
    *(void**)this = lbl_804A1630;
    __construct_array((char*)this + 0x294, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x2c4, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Sbtn_ctor_80202390.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB580[];

extern "C" void* fn_80202390(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AB580;
    return this_;
}

// ---- Circ_ctor_802023CC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A7960[];

extern "C" void* fn_802023CC(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A7960;
    return this_;
}

// ---- Flyk_ctor_80202408.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9078[];

extern "C" void* fn_80202408(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9078;
    return this_;
}

// ---- fn_80202444_ctor.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A1318[];

extern "C" void* fn_80202444(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A1318;
    return this_;
}

// ---- Plsw_ctor_80202480.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A7908[];

extern "C" void* fn_80202480(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A7908;
    return this_;
}

// ---- Osin_ctor_802024BC.cpp ----
struct Actor_169 {
    Actor_169();
    ~Actor_169();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804AB528[];

class Osin : public Actor_169 {
public:
    Osin();
};

Osin::Osin() : Actor_169() {
    *(void**)this = lbl_804AB528;
    __construct_array((char*)this + 0x26c, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Puku_ctor_80202514.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A11B8[];

extern "C" void* fn_80202514(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A11B8;
    return this_;
}

// ---- Swbm_ctor_80202550.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A1160[];

extern "C" void* fn_80202550(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A1160;
    return this_;
}

// ---- Infr_ctor_8020258C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB4C0[];

extern "C" void* fn_8020258C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AB4C0;
    return this_;
}

// ---- Arsh_ctor_802025C8.cpp ----
extern "C" void* fn_801D30B8(void* this_);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern void* lbl_804A58B4[];
extern void* lbl_804A48B0[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

class Fn801D30B8Base {
public:
    Fn801D30B8Base();
    ~Fn801D30B8Base();
private:
    unsigned char pad[0x2b0];
};

class Arsh : public Fn801D30B8Base {
public:
    Arsh();
};

Arsh::Arsh() {
    *(void**)this = lbl_804A58B4;

    unsigned char localTemp[0x2b0];
    fn_801D30B8(localTemp);
    *(void**)localTemp = lbl_804A48B0;
    *(void**)localTemp = lbl_804A4808;
    unsigned char* q = localTemp + 0x270;
    if (q != 0) {
        if (q + 0x24 != 0) {
            *(void**)(localTemp + 0x294) = lbl_8049CC34;
        }
    }
    __dt__5ActorFv(localTemp, 0);
}

// ---- Bmty_ctor_8020264C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB464[];

extern "C" void* fn_8020264C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AB464;
    return this_;
}

// ---- Pcdm_ctor_80202688.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB3A8[];

extern "C" void* fn_80202688(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AB3A8;
    return this_;
}

// ---- Crtl_ctor_802026C4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB308[];

extern "C" void* fn_802026C4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AB308;
    return this_;
}

// ---- Rdbl_ctor_80202700.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9020[];

extern "C" void* fn_80202700(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9020;
    return this_;
}

// ---- Onof_ctor_8020273C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8FC8[];

extern "C" void* fn_8020273C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8FC8;
    return this_;
}

// ---- Ocfr_ctor_80202778.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB2B0[];

extern "C" void* fn_80202778(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AB2B0;
    return this_;
}

// ---- Brry_ctor_802027B4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB258[];

extern "C" void* fn_802027B4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AB258;
    return this_;
}

// ---- Lif2_ctor_802027F0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A78B0[];

extern "C" void* fn_802027F0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A78B0;
    return this_;
}

// ---- Wdry_ctor_8020282C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB1F0[];

extern "C" void* fn_8020282C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AB1F0;
    return this_;
}

// ---- Esry_ctor_80202868.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB170[];

extern "C" void* fn_80202868(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AB170;
    return this_;
}

// ---- Shlt_ctor_802028A4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A0FF8[];

extern "C" void* fn_802028A4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A0FF8;
    return this_;
}

// ---- Rank_ctor_802028E0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8F74[];

extern "C" void* fn_802028E0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8F74;
    return this_;
}

// ---- Hnry_ctor_8020291C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB098[];

extern "C" void* fn_8020291C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AB098;
    return this_;
}

// ---- Bldf_ctor_80202958.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8EF8[];

extern "C" void* fn_80202958(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8EF8;
    return this_;
}

// ---- Focs_ctor_80202994.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8EA0[];

extern "C" void* fn_80202994(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8EA0;
    return this_;
}

// ---- Pnpc_ctor_802029D0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8E40[];

extern "C" void* fn_802029D0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8E40;
    return this_;
}

// ---- Rail_ctor_80202A0C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C770[];

extern "C" void* fn_80202A0C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049C770;
    return this_;
}

// ---- Zosh_ctor_80202A48.cpp ----
extern "C" void* fn_801D30B8(void* this_);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern void* lbl_804A5810[];
extern void* lbl_804A48B0[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

class Fn801D30B8Base_191 {
public:
    Fn801D30B8Base_191();
    ~Fn801D30B8Base_191();
private:
    unsigned char pad[0x2b0];
};

class Zosh : public Fn801D30B8Base_191 {
public:
    Zosh();
};

Zosh::Zosh() {
    *(void**)this = lbl_804A5810;

    unsigned char localTemp[0x2b0];
    fn_801D30B8(localTemp);
    *(void**)localTemp = lbl_804A48B0;
    *(void**)localTemp = lbl_804A4808;
    unsigned char* q = localTemp + 0x270;
    if (q != 0) {
        if (q + 0x24 != 0) {
            *(void**)(localTemp + 0x294) = lbl_8049CC34;
        }
    }
    __dt__5ActorFv(localTemp, 0);
}

// ---- Door_ctor_80202ACC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8D88[];

extern "C" void* fn_80202ACC(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8D88;
    return this_;
}

// ---- Key0_ctor_80202B08.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8CD8[];

extern "C" void* fn_80202B08(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8CD8;
    return this_;
}

// ---- Lsti_ctor_80202B44.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8C80[];

extern "C" void* fn_80202B44(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8C80;
    return this_;
}

// ---- Wizr_ctor_80202B80.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A0EDC[];

extern "C" void* fn_80202B80(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A0EDC;
    return this_;
}

// ---- Swnp_ctor_80202BBC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8C28[];

extern "C" void* fn_80202BBC(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8C28;
    return this_;
}

// ---- Cksw_ctor_80202BF8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8BD0[];

extern "C" void* fn_80202BF8(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8BD0;
    return this_;
}

// ---- Tngl_ctor_80202C34.cpp ----
struct Actor_198 {
    Actor_198();
    ~Actor_198();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804B0478[];

class Tngl : public Actor_198 {
public:
    Tngl();
};

Tngl::Tngl() : Actor_198() {
    *(void**)this = lbl_804B0478;
    __construct_array((char*)this + 0x260, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Stal_ctor_80202C8C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A0CD8[];

extern "C" void* fn_80202C8C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A0CD8;
    return this_;
}

// ---- Wrtc_ctor_80202CC8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C678[];

extern "C" void* fn_80202CC8(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049C678;
    return this_;
}

// ---- Lwsw_ctor_80202D04.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8B78[];

extern "C" void* fn_80202D04(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8B78;
    return this_;
}

// ---- Bwrt_ctor_80202D40.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C718[];

extern "C" void* fn_80202D40(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049C718;
    *(u8*)((char*)this_ + 0x29c) = 0;
    return this_;
}

// ---- Bfin_ctor_80202D84.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804B0380[];

extern "C" void* fn_80202D84(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804B0380;
    return this_;
}

// ---- Wtsw_ctor_80202DC0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8B20[];

extern "C" void* fn_80202DC0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8B20;
    return this_;
}

// ---- Znsw_ctor_80202DFC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8AC8[];

extern "C" void* fn_80202DFC(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8AC8;
    return this_;
}

// ---- Lplk_ctor_80202E38.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C578[];

extern "C" void* fn_80202E38(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049C578;
    return this_;
}

// ---- Iwag_ctor_80202E74.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C46C[];

extern "C" void* fn_80202E74(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049C46C;
    return this_;
}

// ---- Oiwa_ctor_80202EB0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C4C0[];

extern "C" void* fn_80202EB0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049C4C0;
    return this_;
}

// ---- Nzmi_ctor_80202EEC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C400[];

extern "C" void* fn_80202EEC(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049C400;
    return this_;
}

// ---- Blze_ctor_80202F28.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8A50[];

extern "C" void* fn_80202F28(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8A50;
    return this_;
}

// ---- Fire_ctor_80202F64.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A89F0[];

extern "C" void* fn_80202F64(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A89F0;
    return this_;
}

// ---- Niwa_ctor_80202FA0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB8C0[];

extern "C" void* fn_80202FA0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AB8C0;
    return this_;
}

// ---- Bgwc_ctor_80202FDC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8998[];

extern "C" void* fn_80202FDC(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8998;
    return this_;
}

// ---- Dosn_ctor_80203018.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8940[];

extern "C" void* fn_80203018(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8940;
    return this_;
}

// ---- Tlk2_ctor_80203054.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AFAD8[];

extern "C" void* fn_80203054(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AFAD8;
    return this_;
}

// ---- Slr4_ctor_80203090.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A0B90[];

extern "C" void* fn_80203090(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A0B90;
    return this_;
}

// ---- Sbal_ctor_802030CC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB9C0[];

extern "C" void* fn_802030CC(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AB9C0;
    return this_;
}

// ---- Swel_ctor_80203108.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A88E8[];

extern "C" void* fn_80203108(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A88E8;
    return this_;
}

// ---- Lift_ctor_80203144.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A6F6C[];

extern "C" void* fn_80203144(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A6F6C;
    return this_;
}

// ---- Ry02_ctor_80203180.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB850[];

extern "C" void* fn_80203180(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AB850;
    return this_;
}

// ---- Deth_ctor_802031BC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A886C[];

extern "C" void* fn_802031BC(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A886C;
    return this_;
}

// ---- Swor_ctor_802031F8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8800[];

extern "C" void* fn_802031F8(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8800;
    return this_;
}

// ---- Popo_ctor_80203234.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A0868[];

extern "C" void* fn_80203234(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A0868;
    return this_;
}

// ---- Wood_ctor_80203270.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A87A8[];

extern "C" void* fn_80203270(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A87A8;
    return this_;
}

// ---- fn_802032AC_ctor.cpp ----
struct Actor_225 {
    Actor_225();
    ~Actor_225();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A0810[];

class fn_802032AC_actor : public Actor_225 {
public:
    fn_802032AC_actor();
};

fn_802032AC_actor::fn_802032AC_actor() : Actor_225() {
    *(void**)this = lbl_804A0810;
    __construct_array((char*)this + 0x29c, (void*)fn_8003B2CC, 0, 0xc, 0xa);
}

// ---- Peff_ctor_80203304.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A6E20[];

extern "C" void* fn_80203304(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A6E20;
    return this_;
}

// ---- Slsd_ctor_80203340.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A85E0[];

extern "C" void* fn_80203340(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A85E0;
    return this_;
}

// ---- Sstn_ctor_8020337C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8750[];

extern "C" void* fn_8020337C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8750;
    return this_;
}

// ---- Skul_ctor_802033B8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8588[];

extern "C" void* fn_802033B8(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8588;
    return this_;
}

// ---- Talk_ctor_802033F4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AF548[];

extern "C" void* fn_802033F4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AF548;
    return this_;
}

// ---- Trch_ctor_80203430.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8520[];

extern "C" void* fn_80203430(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8520;
    return this_;
}

// ---- Scre_ctor_8020346C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AF4C0[];

extern "C" void* fn_8020346C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AF4C0;
    return this_;
}

// ---- Spot_ctor_802034A8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A84C8[];

extern "C" void* fn_802034A8(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A84C8;
    return this_;
}

// ---- Yaji_ctor_802034E4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8470[];

extern "C" void* fn_802034E4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8470;
    return this_;
}

// ---- Bome_ctor_80203520.cpp ----
struct Actor_235 {
    Actor_235();
    ~Actor_235();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_80203594(void);
extern void* lbl_804A0738[];

class Bome : public Actor_235 {
public:
    Bome();
};

Bome::Bome() : Actor_235() {
    *(void**)this = lbl_804A0738;
    __construct_array((char*)this + 0x274, (void*)fn_80203594, 0, 0x18, 5);
    __construct_array((char*)this + 0x2ec, (void*)fn_80203594, 0, 0x18, 5);
}

// ---- stub_80203594.cpp ----
// Empty virtual-hook stub (see Game/ActorDefaultHooks.cpp).
extern "C" void fn_80203594(void) {}

// ---- Kmri_ctor_80203598.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8418[];

extern "C" void* fn_80203598(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8418;
    return this_;
}

// ---- Tflr_ctor_802035D4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A83A0[];

extern "C" void* fn_802035D4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A83A0;
    return this_;
}

// ---- Knbn_ctor_80203610.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AF428[];

extern "C" void* fn_80203610(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AF428;
    return this_;
}

// ---- Plas_ctor_8020364C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8338[];

extern "C" void* fn_8020364C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8338;
    return this_;
}

// ---- Itms_ctor_80203688.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A82A8[];

extern "C" void* fn_80203688(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A82A8;
    return this_;
}

// ---- Poon_ctor_802036C4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A06C0[];

extern "C" void* fn_802036C4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A06C0;
    return this_;
}

// ---- Skil_ctor_80203700.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8250[];

extern "C" void* fn_80203700(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8250;
    return this_;
}

// ---- Mozo_ctor_8020373C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A0668[];

extern "C" void* fn_8020373C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A0668;
    return this_;
}

// ---- Bfry_ctor_80203778.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AF338[];

extern "C" void* fn_80203778(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AF338;
    return this_;
}

// ---- Pont_ctor_802037B4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A81C8[];

extern "C" void* fn_802037B4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A81C8;
    return this_;
}

// ---- Arrw_ctor_802037F0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A05E0[];

extern "C" void* fn_802037F0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A05E0;
    return this_;
}

// ---- Trap_ctor_8020382C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A04D8[];

extern "C" void* fn_8020382C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A04D8;
    return this_;
}

// ---- Thrn_ctor_80203868.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8170[];

extern "C" void* fn_80203868(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8170;
    return this_;
}

// ---- Swev_ctor_802038A4.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8638[];

extern "C" void* fn_802038A4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8638;
    *(s32*)((char*)this_ + 0x2dc) = -1;
    return this_;
}

// ---- Ball_ctor_802038E8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB968[];

extern "C" void* fn_802038E8(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AB968;
    return this_;
}

// ---- Bpoh_ctor_80203924.cpp ----
struct Actor_252 {
    Actor_252();
    ~Actor_252();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern "C" void fn_8009711C(void*);
extern void* lbl_804A0440[];

class Bpoh : public Actor_252 {
public:
    Bpoh();
};

Bpoh::Bpoh() : Actor_252() {
    *(void**)this = lbl_804A0440;
    __construct_array((char*)this + 0x2b8, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x2f4, (void*)fn_8009711C, 0, 0x4, 3);
}

// ---- Shtr_ctor_80203998.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8118[];

extern "C" void* fn_80203998(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8118;
    return this_;
}

// ---- Fary_ctor_802039D4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A03B8[];

extern "C" void* fn_802039D4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A03B8;
    return this_;
}

// ---- Swt4_ctor_80203A10.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A80A0[];

extern "C" void* fn_80203A10(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A80A0;
    return this_;
}

// ---- Ryrn_ctor_80203A4C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8010[];

extern "C" void* fn_80203A4C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A8010;
    return this_;
}

// ---- Mtbo_ctor_80203A88.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AF018[];

extern "C" void* fn_80203A88(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AF018;
    return this_;
}

// ---- Tkyu_ctor_80203AC4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804ABA38[];

extern "C" void* fn_80203AC4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804ABA38;
    return this_;
}

// ---- Flme_ctor_80203B00.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A0330[];

extern "C" void* fn_80203B00(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A0330;
    return this_;
}

// ---- Keth_ctor_80203B3C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A02B8[];

extern "C" void* fn_80203B3C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A02B8;
    return this_;
}

// ---- Boyo_ctor_80203B78.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A0260[];

extern "C" void* fn_80203B78(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A0260;
    return this_;
}

// ---- Imup_ctor_80203BB4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A01D0[];

extern "C" void* fn_80203BB4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A01D0;
    return this_;
}

// ---- Slr2_ctor_80203BF0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A00C8[];

extern "C" void* fn_80203BF0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A00C8;
    return this_;
}

// ---- Tkta_ctor_80203C2C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049FD50[];

extern "C" void* fn_80203C2C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049FD50;
    return this_;
}

// ---- Expl_ctor_80203C68.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A7FB8[];

extern "C" void* fn_80203C68(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A7FB8;
    return this_;
}

// ---- Slr1_ctor_80203CA4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049FCA0[];

extern "C" void* fn_80203CA4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049FCA0;
    return this_;
}

// ---- Swth_ctor_80203CE0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A7F38[];

extern "C" void* fn_80203CE0(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A7F38;
    return this_;
}

// ---- Hbmb_ctor_80203D1C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F784[];

extern "C" void* fn_80203D1C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049F784;
    return this_;
}

// ---- Hino_ctor_80203D58.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F9B4[];

extern "C" void* fn_80203D58(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049F9B4;
    return this_;
}

// ---- Goal_ctor_80203D94.cpp ----
struct Actor_270 {
    Actor_270();
    ~Actor_270();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A7EB0[];

class Goal : public Actor_270 {
public:
    Goal();
};

Goal::Goal() : Actor_270() {
    *(void**)this = lbl_804A7EB0;
    __construct_array((char*)this + 0x264, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Bhrt_ctor_80203DEC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A7E58[];

extern "C" void* fn_80203DEC(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A7E58;
    return this_;
}

// ---- Dgtl_ctor_80203E28.cpp ----
struct Actor_272 {
    Actor_272();
    ~Actor_272();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_8049F6C8[];

class Dgtl : public Actor_272 {
public:
    Dgtl();
};

Dgtl::Dgtl() : Actor_272() {
    *(void**)this = lbl_8049F6C8;
    __construct_array((char*)this + 0x2c0, (void*)fn_8003B2CC, 0, 0xc, 0xa);
    __construct_array((char*)this + 0x3d8, (void*)fn_8003B2CC, 0, 0xc, 0x50);
}

// ---- Oktm_ctor_80203E9C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F5D8[];

extern "C" void* fn_80203E9C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049F5D8;
    return this_;
}

// ---- Hart_ctor_80203ED8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F4F0[];

extern "C" void* fn_80203ED8(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049F4F0;
    return this_;
}

// ---- Gold_ctor_80203F14.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB660[];

extern "C" void* fn_80203F14(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AB660;
    return this_;
}

// ---- Ddrk_ctor_80203F50.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F498[];

extern "C" void* fn_80203F50(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049F498;
    return this_;
}

// ---- Bzbr_ctor_80203F8C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F444[];

extern "C" void* fn_80203F8C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049F444;
    return this_;
}

// ---- Blck_ctor_80203FC8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A7A10[];

extern "C" void* fn_80203FC8(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A7A10;
    return this_;
}

// ---- Peac_ctor_80204004.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F3B0[];

extern "C" void* fn_80204004(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049F3B0;
    return this_;
}

// ---- Tubo_ctor_80204040.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9428[];

extern "C" void* fn_80204040(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9428;
    return this_;
}

// ---- Rock_ctor_8020407C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9480[];

extern "C" void* fn_8020407C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9480;
    return this_;
}

// ---- Warp_ctor_802040B8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A6DC8[];

extern "C" void* fn_802040B8(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A6DC8;
    return this_;
}

// ---- Bord_ctor_802040F4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A94D8[];

extern "C" void* fn_802040F4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A94D8;
    return this_;
}

// ---- Ston_ctor_80204130.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A93D0[];

extern "C" void* fn_80204130(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A93D0;
    return this_;
}

// ---- Gene_ctor_8020416C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9328[];

extern "C" void* fn_8020416C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A9328;
    return this_;
}

// ---- Gras_ctor_802041A8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A92D0[];

extern "C" void* fn_802041A8(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804A92D0;
    return this_;
}

// ---- Pooh_ctor_802041E4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F330[];

extern "C" void* fn_802041E4(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049F330;
    return this_;
}

// ---- Amos_ctor_80204220.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F260[];

extern "C" void* fn_80204220(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049F260;
    return this_;
}

// ---- Okta_ctor_8020425C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F208[];

extern "C" void* fn_8020425C(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049F208;
    return this_;
}

// ---- Rupy_ctor_80204298.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB6D8[];

extern "C" void* fn_80204298(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_804AB6D8;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
