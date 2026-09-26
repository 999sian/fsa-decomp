// TU 0x801f9484-0x80204638.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// Actor base (0x801F5AE0 ctor, 0x801F593C dtor); full layout lives on the  Actor branch.
struct Actor {
    Actor();
    ~Actor();
};

// ---- Gsck_ctor_801FF744.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA800[];

struct GSCK : public Actor {
    GSCK();
};

GSCK::GSCK() {
    *(void**)this = lbl_804AA800;
}

// ---- Mrtc_ctor_801FF780.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AD278[];

struct MRTC : public Actor {
    MRTC();
};

MRTC::MRTC() {
    *(void**)this = lbl_804AD278;
}

// ---- Stgn_ctor_801FF7BC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA7A8[];

struct STGN : public Actor {
    STGN();
};

STGN::STGN() {
    *(void**)this = lbl_804AA7A8;
}

// ---- Rins_ctor_801FF7F8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AD220[];

struct RINS : public Actor {
    RINS();
};

RINS::RINS() {
    *(void**)this = lbl_804AD220;
}

// ---- Wpwl_ctor_801FF834.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE948[];

struct WPWL : public Actor {
    WPWL();
};

WPWL::WPWL() {
    *(void**)this = lbl_804AE948;
}

// ---- Pss2_ctor_801FF870.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE8F4[];

struct PSS2 : public Actor {
    PSS2();
};

PSS2::PSS2() {
    *(void**)this = lbl_804AE8F4;
}

// ---- Tbo2_ctor_801FF918.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA750[];

struct TBO2 : public Actor {
    TBO2();
};

TBO2::TBO2() {
    *(void**)this = lbl_804AA750;
}

// ---- Tbgn_ctor_801FF954.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA6F8[];

struct TBGN : public Actor {
    TBGN();
};

TBGN::TBGN() {
    *(void**)this = lbl_804AA6F8;
}

// ---- Iceb_ctor_801FF990.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE888[];

struct ICEB : public Actor {
    ICEB();
};

ICEB::ICEB() {
    *(void**)this = lbl_804AE888;
}

// ---- Dmyk_ctor_801FF9CC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA6A0[];

struct DMYK : public Actor {
    DMYK();
};

DMYK::DMYK() {
    *(void**)this = lbl_804AA6A0;
}

// ---- Jpe2_ctor_801FFA08.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AD1C8[];

struct JPE2 : public Actor {
    JPE2();
};

JPE2::JPE2() {
    *(void**)this = lbl_804AD1C8;
}

// ---- Endr_ctor_801FFA44.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE830[];

struct ENDR : public Actor {
    ENDR();
};

ENDR::ENDR() {
    *(void**)this = lbl_804AE830;
}

// ---- Tfl2_ctor_801FFA80.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA628[];

struct TFL2 : public Actor {
    TFL2();
};

TFL2::TFL2() {
    *(void**)this = lbl_804AA628;
}

// ---- Losw_ctor_801FFABC.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049CB58[];

struct LOSW : public Actor {
    LOSW();
};

LOSW::LOSW() {
    *(void**)this = lbl_8049CB58;
    *(u8*)((char*)this + 0x24e) = 0;
}

// ---- Pswk_ctor_801FFB00.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE5C8[];

struct PSWK : public Actor {
    PSWK();
};

PSWK::PSWK() {
    *(void**)this = lbl_804AE5C8;
}

// ---- Sibt_ctor_801FFB3C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049CB04[];

struct SIBT : public Actor {
    SIBT();
};

SIBT::SIBT() {
    *(void**)this = lbl_8049CB04;
}

// ---- Pswb_ctor_801FFB78.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE574[];

struct PSWB : public Actor {
    PSWB();
};

PSWB::PSWB() {
    *(void**)this = lbl_804AE574;
}

// ---- Glwp_ctor_801FFBB4.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A39DC[];

class GEWP : public Actor {
public:
    GEWP();
};

GEWP::GEWP() : Actor() {
    *(void**)this = lbl_804A39DC;
    __construct_array((char*)this + 0x264, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Snpc_ctor_801FFC0C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AAFB8[];

struct SNPC : public Actor {
    SNPC();
};

SNPC::SNPC() {
    *(void**)this = lbl_804AAFB8;
}

// ---- Tjij_ctor_801FFC48.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE508[];

struct TJIJ : public Actor {
    TJIJ();
};

TJIJ::TJIJ() {
    *(void**)this = lbl_804AE508;
}

// ---- Mrta_ctor_801FFC84.cpp ----
struct Actor_21 {
    Actor_21();
    ~Actor_21();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_801FFCDC(void);
extern void* lbl_804ACD70[];

class MRTA : public Actor_21 {
public:
    MRTA();
};

MRTA::MRTA() : Actor_21() {
    *(void**)this = lbl_804ACD70;
    __construct_array((char*)this + 0x268, (void*)fn_801FFCDC, 0, 0x14, 4);
}

// ---- stub_801ffcdc.cpp ----
// Empty virtual-hook stub (see Game/ActorDefaultHooks.cpp).
extern "C" void fn_801FFCDC(void) {}

// ---- Swdl_ctor_801FFCE0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA590[];

struct SWDL : public Actor {
    SWDL();
};

SWDL::SWDL() {
    *(void**)this = lbl_804AA590;
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

struct ELK2 : public Actor {
    ELK2();
};

ELK2::ELK2() {
    *(void**)this = lbl_804AE338;
}

// ---- Ptmi_ctor_801FFE40.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE780[];

struct PTMI : public Actor {
    PTMI();
};

PTMI::PTMI() {
    *(void**)this = lbl_804AE780;
}

// ---- Mrmt_ctor_801FFE7C.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049EA88[];

struct MRMT : public Actor {
    MRMT();
};

MRMT::MRMT() {
    *(void**)this = lbl_8049EA88;
    *(s32*)((char*)this + 0x230) = 0;
    *(s32*)((char*)this + 0x234) = -1;
    *(s32*)((char*)this + 0x238) = -1;
    *(s32*)((char*)this + 0x23c) = -1;
    *(s32*)((char*)this + 0x240) = -1;
    *(s32*)((char*)this + 0x244) = 0;
    *(s32*)((char*)this + 0x248) = 0;
    *(s32*)((char*)this + 0x24c) = 0;
}

// ---- Ltev_ctor_801FFEE0.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA4F0[];

struct FOEV : public Actor {
    FOEV();
};

FOEV::FOEV() {
    *(void**)this = lbl_804AA4F0;
    *(s32*)((char*)this + 0x248) = -1;
}

// ---- Rsnp_ctor_801FFF24.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804ACD18[];

struct RSNP : public Actor {
    RSNP();
};

RSNP::RSNP() {
    *(void**)this = lbl_804ACD18;
}

// ---- Ogst_ctor_801FFF60.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049EA00[];

struct OGST : public Actor {
    OGST();
};

OGST::OGST() {
    *(void**)this = lbl_8049EA00;
    *(s32*)((char*)this + 0x230) = 0;
}

// ---- Icob_ctor_801FFFA4.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049E9A8[];

struct ICOB : public Actor {
    ICOB();
};

ICOB::ICOB() {
    *(void**)this = lbl_8049E9A8;
    *(s32*)((char*)this + 0x230) = 0;
}

// ---- Emsk_ctor_801FFFE8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA498[];

struct ELSK : public Actor {
    ELSK();
};

ELSK::ELSK() {
    *(void**)this = lbl_804AA498;
}

// ---- Tutm_ctor_80200024.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804ACBF0[];

struct TUTM : public Actor {
    TUTM();
};

TUTM::TUTM() {
    *(void**)this = lbl_804ACBF0;
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

class TUGF : public Actor_36 {
public:
    TUGF();
};

TUGF::TUGF() : Actor_36() {
    *(void**)this = lbl_804ACCC0;
    fn_801EB950((char*)this + 0x230);
}

// ---- Leaf_ctor_802000E0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE2E0[];

struct LEAF : public Actor {
    LEAF();
};

LEAF::LEAF() {
    *(void**)this = lbl_804AE2E0;
}

// ---- Lfgn_ctor_8020011C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE288[];

struct LFGN : public Actor {
    LFGN();
};

LFGN::LFGN() {
    *(void**)this = lbl_804AE288;
}

// ---- Thcl_ctor_80200158.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A7C40[];

struct THCL : public Actor {
    THCL();
};

THCL::THCL() {
    *(void**)this = lbl_804A7C40;
}

// ---- Agbw_ctor_80200194.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA440[];

struct AGBW : public Actor {
    AGBW();
};

AGBW::AGBW() {
    *(void**)this = lbl_804AA440;
}

// ---- Svgt_ctor_802001D0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804ACB98[];

struct SVGT : public Actor {
    SVGT();
};

SVGT::SVGT() {
    *(void**)this = lbl_804ACB98;
}

// ---- Tmi2_ctor_8020020C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE728[];

struct TMI2 : public Actor {
    TMI2();
};

TMI2::TMI2() {
    *(void**)this = lbl_804AE728;
}

// ---- Safu_ctor_80200248.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A3948[];

struct SAFU : public Actor {
    SAFU();
};

SAFU::SAFU() {
    *(void**)this = lbl_804A3948;
}

// ---- Fdwp_ctor_80200284.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049E8F8[];

struct FDWP : public Actor {
    FDWP();
};

FDWP::FDWP() {
    *(void**)this = lbl_8049E8F8;
    *(s32*)((char*)this + 0x230) = 0;
    *(s32*)((char*)this + 0x234) = 0;
    *(s32*)((char*)this + 0x238) = 0;
    *(s32*)((char*)this + 0x23c) = 0;
}

// ---- Twev_ctor_802002D4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049CA40[];

struct TWEV : public Actor {
    TWEV();
};

TWEV::TWEV() {
    *(void**)this = lbl_8049CA40;
}

// ---- Dwap_ctor_80200310.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C9E8[];

struct DWAP : public Actor {
    DWAP();
};

DWAP::DWAP() {
    *(void**)this = lbl_8049C9E8;
}

// ---- Tooi_ctor_8020034C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804ACB40[];

struct TOOI : public Actor {
    TOOI();
};

TOOI::TOOI() {
    *(void**)this = lbl_804ACB40;
}

// ---- Chsw_ctor_80200388.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA3E8[];

struct CHSW : public Actor {
    CHSW();
};

CHSW::CHSW() {
    *(void**)this = lbl_804AA3E8;
}

// ---- Tlwp_ctor_802003C4.cpp ----
struct Actor_49 {
    Actor_49();
    ~Actor_49();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A38D4[];

class TLWP : public Actor_49 {
public:
    TLWP();
};

TLWP::TLWP() : Actor_49() {
    *(void**)this = lbl_804A38D4;
    __construct_array((char*)this + 0x264, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Jwlk_ctor_8020041C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AABA8[];

struct JWLK : public Actor {
    JWLK();
};

JWLK::JWLK() {
    *(void**)this = lbl_804AABA8;
}

// ---- Rbpn_ctor_80200458.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049E848[];

struct RBPN : public Actor {
    RBPN();
};

RBPN::RBPN() {
    *(void**)this = lbl_8049E848;
    *(s32*)((char*)this + 0x230) = 0;
    *(s32*)((char*)this + 0x234) = 0;
    *(s32*)((char*)this + 0x238) = 0;
    *(s32*)((char*)this + 0x23c) = 0;
    *(s32*)((char*)this + 0x240) = 0;
    *(s32*)((char*)this + 0x244) = 0;
}

// ---- Psw2_ctor_802004B0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE230[];

struct PSW2 : public Actor {
    PSW2();
};

PSW2::PSW2() {
    *(void**)this = lbl_804AE230;
}

// ---- Gnef_ctor_802004EC.cpp ----
struct Actor_53 {
    Actor_53();
    ~Actor_53();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_80200544(void);
extern void* lbl_804AA350[];

class GNEF : public Actor_53 {
public:
    GNEF();
};

GNEF::GNEF() : Actor_53() {
    *(void**)this = lbl_804AA350;
    __construct_array((char*)this + 0x27c, (void*)fn_80200544, 0, 0x14, 4);
}

// ---- stub_80200544.cpp ----
// Empty virtual-hook stub (see Game/ActorDefaultHooks.cpp).
extern "C" void fn_80200544(void) {}

// ---- Stpn_ctor_80200548.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA2D8[];

struct STPN : public Actor {
    STPN();
};

STPN::STPN() {
    *(void**)this = lbl_804AA2D8;
}

// ---- Tomi_ctor_80200584.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE6D0[];

struct SSMI : public Actor {
    SSMI();
};

SSMI::SSMI() {
    *(void**)this = lbl_804AE6D0;
}

// ---- Medm_ctor_802005C0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE678[];

struct MEDM : public Actor {
    MEDM();
};

MEDM::MEDM() {
    *(void**)this = lbl_804AE678;
}

// ---- Sdsm_ctor_802005FC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA280[];

struct SDSM : public Actor {
    SDSM();
};

SDSM::SDSM() {
    *(void**)this = lbl_804AA280;
}

// ---- Bck2_ctor_80200638.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AE620[];

struct BCK2 : public Actor {
    BCK2();
};

BCK2::BCK2() {
    *(void**)this = lbl_804AE620;
}

// ---- Svtg_ctor_80200674.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AAB40[];

struct SPTG : public Actor {
    SPTG();
};

SPTG::SPTG() {
    *(void**)this = lbl_804AAB40;
}

// ---- Dnav_ctor_802006B0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804ADFE8[];

struct DNAV : public Actor {
    DNAV();
};

DNAV::DNAV() {
    *(void**)this = lbl_804ADFE8;
}

// ---- Zomo_ctor_802006EC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA228[];

struct ZOMO : public Actor {
    ZOMO();
};

ZOMO::ZOMO() {
    *(void**)this = lbl_804AA228;
}

// ---- Zdco_ctor_80200728.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A375C[];

struct ZDCO : public Actor {
    ZDCO();
};

ZDCO::ZDCO() {
    *(void**)this = lbl_804A375C;
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

class ZLD3 : public Actor_65 {
public:
    ZLD3();
};

ZLD3::ZLD3() : Actor_65() {
    *(void**)this = lbl_804A35AC;
    __construct_array((char*)this + 0x288, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Oblf_ctor_802007F8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804ACA00[];

struct OBLF : public Actor {
    OBLF();
};

OBLF::OBLF() {
    *(void**)this = lbl_804ACA00;
}

// ---- Gen3_ctor_80200834.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA1D0[];

struct GEN3 : public Actor {
    GEN3();
};

GEN3::GEN3() {
    *(void**)this = lbl_804AA1D0;
}

// ---- Egol_ctor_80200870.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A3548[];

struct EGOL : public Actor {
    EGOL();
};

EGOL::EGOL() {
    *(void**)this = lbl_804A3548;
}

// ---- Ynsw_ctor_802008AC.cpp ----
struct Actor_69 {
    Actor_69();
    ~Actor_69();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804AC9A8[];

class YNSW : public Actor_69 {
public:
    YNSW();
};

YNSW::YNSW() : Actor_69() {
    *(void**)this = lbl_804AC9A8;
    __construct_array((char*)this + 0x254, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Gmtb_ctor_80200904.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AAAE8[];

struct GMTB : public Actor {
    GMTB();
};

GMTB::GMTB() {
    *(void**)this = lbl_804AAAE8;
}

// ---- Gmbl_ctor_80200940.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AAA70[];

struct GMBL : public Actor {
    GMBL();
};

GMBL::GMBL() {
    *(void**)this = lbl_804AAA70;
}

// ---- Eetc_ctor_8020097C.cpp ----
struct Actor_72 {
    Actor_72();
    ~Actor_72();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804ADF28[];

class EETC : public Actor_72 {
public:
    EETC();
};

EETC::EETC() : Actor_72() {
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

class RCK2 : public Actor_73 {
public:
    RCK2();
};

RCK2::RCK2() : Actor_73() {
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

class EOWL : public Actor_75 {
public:
    EOWL();
};

EOWL::EOWL() : Actor_75() {
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

class DMTW : public Actor_76 {
public:
    DMTW();
};

DMTW::DMTW() : Actor_76() {
    *(void**)this = lbl_8049E770;
    __construct_array((char*)this + 0x25c, (void*)fn_8003B2CC, 0, 0xc, 6);
    __construct_array((char*)this + 0x2c8, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x2f8, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x3b8, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Smri_ctor_80200B78.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA9F0[];

struct SMRI : public Actor {
    SMRI();
};

SMRI::SMRI() {
    *(void**)this = lbl_804AA9F0;
}

// ---- ELNK_ctor_80200BB4.cpp ----
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

struct ELNK : public Actor {
    ELNK();
};

ELNK::ELNK() {
    *(void**)this = lbl_804A5958;
    *(void**)this = lbl_804AD858;
}

// ---- fn_80200BFC_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A5958[];

extern "C" void* fn_80200BFC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A5958;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Dtlk_ctor_80200C5C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804B1A48[];

struct DTLK : public Actor {
    DTLK();
};

DTLK::DTLK() {
    *(void**)this = lbl_804B1A48;
}

// ---- Tkra_ctor_80200C98.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA178[];

struct TKRA : public Actor {
    TKRA();
};

TKRA::TKRA() {
    *(void**)this = lbl_804AA178;
}

// ---- Okam_ctor_80200CD4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A3448[];

struct OKAM : public Actor {
    OKAM();
};

OKAM::OKAM() {
    *(void**)this = lbl_804A3448;
}

// ---- Ttat_ctor_80200D10.cpp ----
struct Actor_83 {
    Actor_83();
    ~Actor_83();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A2FB0[];

class TTAT : public Actor_83 {
public:
    TTAT();
};

TTAT::TTAT() : Actor_83() {
    *(void**)this = lbl_804A2FB0;
    __construct_array((char*)this + 0x280, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Goma_ctor_80200D68.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A307C[];

struct GNMA : public Actor {
    GNMA();
};

GNMA::GNMA() {
    *(void**)this = lbl_804A307C;
}

// ---- Ddgo_ctor_80200DA4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A3334[];

struct DDGO : public Actor {
    DDGO();
};

DDGO::DDGO() {
    *(void**)this = lbl_804A3334;
}

// ---- Endm_ctor_80200DE0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA0FC[];

struct ENDM : public Actor {
    ENDM();
};

ENDM::ENDM() {
    *(void**)this = lbl_804AA0FC;
}

// ---- Lcls_ctor_80200E1C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA008[];

struct LCLS : public Actor {
    LCLS();
};

LCLS::LCLS() {
    *(void**)this = lbl_804AA008;
}

// ---- Glbs_ctor_80200E58.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AA060[];

struct GLBS : public Actor {
    GLBS();
};

GLBS::GLBS() {
    *(void**)this = lbl_804AA060;
}

// ---- Emik_ctor_80200E94.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A5958[];
extern void* lbl_804AD5B8[];

struct EMIK : public Actor {
    EMIK();
};

EMIK::EMIK() {
    *(void**)this = lbl_804A5958;
    *(void**)this = lbl_804AD5B8;
}

// ---- Ezld_ctor_80200EDC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A5958[];
extern void* lbl_804AD6F0[];

struct EZLD : public Actor {
    EZLD();
};

EZLD::EZLD() {
    *(void**)this = lbl_804A5958;
    *(void**)this = lbl_804AD6F0;
}

// ---- Enpc_ctor_80200F24.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AD48C[];

struct ENPC : public Actor {
    ENPC();
};

ENPC::ENPC() {
    *(void**)this = lbl_804AD48C;
}

// ---- Hbb2_ctor_80200F60.cpp ----
struct Actor_92 {
    Actor_92();
    ~Actor_92();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A2EC0[];

class HBB2 : public Actor_92 {
public:
    HBB2();
};

HBB2::HBB2() : Actor_92() {
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

class NWOK : public Actor_93 {
public:
    NWOK();
};

NWOK::NWOK() : Actor_93() {
    *(void**)this = lbl_804AC8C0;
    __construct_array((char*)this + 0x290, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Saya_ctor_80201010.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A2E30[];

struct RYYA : public Actor {
    RYYA();
};

RYYA::RYYA() {
    *(void**)this = lbl_804A2E30;
}

// ---- Mjgr_ctor_8020104C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9FB0[];

struct MJGR : public Actor {
    MJGR();
};

MJGR::MJGR() {
    *(void**)this = lbl_804A9FB0;
}

// ---- Htmk_ctor_80201088.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC868[];

struct HTMK : public Actor {
    HTMK();
};

HTMK::HTMK() {
    *(void**)this = lbl_804AC868;
}

// ---- Enbz_ctor_802010C4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A2CB0[];

struct ENBZ : public Actor {
    ENBZ();
};

ENBZ::ENBZ() {
    *(void**)this = lbl_804A2CB0;
}

// ---- Pnp2_ctor_80201100.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9F58[];

struct PNP2 : public Actor {
    PNP2();
};

PNP2::PNP2() {
    *(void**)this = lbl_804A9F58;
}

// ---- Sslf_ctor_8020113C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AD348[];

struct SSLF : public Actor {
    SSLF();
};

SSLF::SSLF() {
    *(void**)this = lbl_804AD348;
}

// ---- Bemn_ctor_80201178.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC810[];

struct BEMN : public Actor {
    BEMN();
};

BEMN::BEMN() {
    *(void**)this = lbl_804AC810;
}

// ---- Fobe_ctor_802011B4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC7B8[];

struct FOBE : public Actor {
    FOBE();
};

FOBE::FOBE() {
    *(void**)this = lbl_804AC7B8;
}

// ---- Sen2_ctor_802011F0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9F00[];

struct SEN2 : public Actor {
    SEN2();
};

SEN2::SEN2() {
    *(void**)this = lbl_804A9F00;
}

// ---- Crgn_ctor_8020122C.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049E5B8[];

struct CRGN : public Actor {
    CRGN();
};

CRGN::CRGN() {
    *(void**)this = lbl_8049E5B8;
    *(s32*)((char*)this + 0x230) = 1;
    *(s32*)((char*)this + 0x234) = 4;
    *(s32*)((char*)this + 0x238) = 0;
    *(s32*)((char*)this + 0x23c) = -1;
    *(s32*)((char*)this + 0x240) = 0;
    *(s32*)((char*)this + 0x244) = 0;
    *(s32*)((char*)this + 0x280) = 0;
}

// ---- Tenn_ctor_80201294.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A2BF4[];

struct TENN : public Actor {
    TENN();
};

TENN::TENN() {
    *(void**)this = lbl_804A2BF4;
}

// ---- Wave_ctor_802012D0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9EA8[];

struct WAVE : public Actor {
    WAVE();
};

WAVE::WAVE() {
    *(void**)this = lbl_804A9EA8;
}

// ---- Form_ctor_8020130C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A7BE8[];

struct FORM : public Actor {
    FORM();
};

FORM::FORM() {
    *(void**)this = lbl_804A7BE8;
}

// ---- Spbg_ctor_80201348.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC760[];

struct SPBG : public Actor {
    SPBG();
};

SPBG::SPBG() {
    *(void**)this = lbl_804AC760;
}

// ---- Szsc_ctor_802013D8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC708[];

struct SZSC : public Actor {
    SZSC();
};

SZSC::SZSC() {
    *(void**)this = lbl_804AC708;
}

// ---- Nnjn_ctor_80201414.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC6B0[];

struct NNJN : public Actor {
    NNJN();
};

NNJN::NNJN() {
    *(void**)this = lbl_804AC6B0;
}

// ---- Syky_ctor_80201450.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A2B18[];

struct SYKY : public Actor {
    SYKY();
};

SYKY::SYKY() {
    *(void**)this = lbl_804A2B18;
}

// ---- Anho_ctor_8020148C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C970[];

struct ANHO : public Actor {
    ANHO();
};

ANHO::ANHO() {
    *(void**)this = lbl_8049C970;
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

struct FISH : public Actor {
    FISH();
};

FISH::FISH() {
    *(void**)this = lbl_804AC658;
}

// ---- Alce_ctor_80201540.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A2AB0[];

struct ALCE : public Actor {
    ALCE();
};

ALCE::ALCE() {
    *(void**)this = lbl_804A2AB0;
}

// ---- Zoom_ctor_8020157C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9DF8[];

struct ZOOM : public Actor {
    ZOOM();
};

ZOOM::ZOOM() {
    *(void**)this = lbl_804A9DF8;
}

// ---- Bgmn_ctor_802015B8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9DA0[];

struct BGMN : public Actor {
    BGMN();
};

BGMN::BGMN() {
    *(void**)this = lbl_804A9DA0;
}

// ---- Mgya_ctor_802015F4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C8EC[];

struct MGYA : public Actor {
    MGYA();
};

MGYA::MGYA() {
    *(void**)this = lbl_8049C8EC;
}

// ---- Gfbs_ctor_80201630.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049E3A8[];

struct GFBS : public Actor {
    GFBS();
};

GFBS::GFBS() {
    *(void**)this = lbl_8049E3A8;
}

// ---- Blz2_ctor_802016D8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9D28[];

struct BLZ2 : public Actor {
    BLZ2();
};

BLZ2::BLZ2() {
    *(void**)this = lbl_804A9D28;
}

// ---- Sev2_ctor_80201714.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9CD0[];

struct SEV2 : public Actor {
    SEV2();
};

SEV2::SEV2() {
    *(void**)this = lbl_804A9CD0;
}

// ---- Rnsw_ctor_80201750.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049DE90[];

struct RNSW : public Actor {
    RNSW();
};

RNSW::RNSW() {
    *(void**)this = lbl_8049DE90;
    *(s32*)((char*)this + 0x230) = 1;
    *(s32*)((char*)this + 0x234) = 0;
    *(s32*)((char*)this + 0x238) = 0;
    *(s32*)((char*)this + 0x23c) = 0;
    *(s32*)((char*)this + 0x240) = 0;
}

// ---- Senp_ctor_802017A8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9C78[];

struct SENP : public Actor {
    SENP();
};

SENP::SENP() {
    *(void**)this = lbl_804A9C78;
}

// ---- Haya_ctor_802017E4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C858[];

struct GSYA : public Actor {
    GSYA();
};

GSYA::GSYA() {
    *(void**)this = lbl_8049C858;
}

// ---- Brbl_ctor_80201820.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A7B90[];

struct BRBL : public Actor {
    BRBL();
};

BRBL::BRBL() {
    *(void**)this = lbl_804A7B90;
}

// ---- Limt_ctor_8020185C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804B174C[];

struct LIMT : public Actor {
    LIMT();
};

LIMT::LIMT() {
    *(void**)this = lbl_804B174C;
}

// ---- Gol2_ctor_80201898.cpp ----
struct Actor_126 {
    Actor_126();
    ~Actor_126();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A9C20[];

class GNL2 : public Actor_126 {
public:
    GNL2();
};

GNL2::GNL2() : Actor_126() {
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

class BEEE : public Actor_127 {
public:
    BEEE();
};

BEEE::BEEE() : Actor_127() {
    *(void**)this = lbl_804AC600;
    __construct_array((char*)this + 0x2a4, (void*)fn_8003B2CC, 0, 0xc, 7);
    __construct_array((char*)this + 0x2f8, (void*)fn_8003B2CC, 0, 0xc, 7);
    __construct_array((char*)this + 0x34c, (void*)fn_8003B2CC, 0, 0xc, 7);
}

// ---- Pssw_ctor_80201980.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A7B38[];

struct PSSW : public Actor {
    PSSW();
};

PSSW::PSSW() {
    *(void**)this = lbl_804A7B38;
}

// ---- Hous_ctor_802019BC.cpp ----
struct Actor_129 {
    Actor_129();
    ~Actor_129();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_801546E4(void*);
extern void* lbl_804A7AE0[];

class HOUS : public Actor_129 {
public:
    HOUS();
};

HOUS::HOUS() : Actor_129() {
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

struct GNON : public Actor {
    GNON();
};

GNON::GNON() {
    *(void**)this = lbl_804A25F0;
}

// ---- Bbmb_ctor_80201AC4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC588[];

struct BBMB : public Actor {
    BBMB();
};

BBMB::BBMB() {
    *(void**)this = lbl_804AC588;
}

// ---- Bbsl_ctor_80201B00.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC4D0[];

struct BBSL : public Actor {
    BBSL();
};

BBSL::BBSL() {
    *(void**)this = lbl_804AC4D0;
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

struct GBAO : public Actor {
    GBAO();
};

GBAO::GBAO() {
    *(void**)this = lbl_804B16E0;
}

// ---- Offs_ctor_80201BB4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9B70[];

struct OFFS : public Actor {
    OFFS();
};

OFFS::OFFS() {
    *(void**)this = lbl_804A9B70;
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

struct LITS : public Actor {
    LITS();
};

LITS::LITS() {
    *(void**)this = lbl_804AC330;
}

// ---- Stbl_ctor_80201C68.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC2D8[];

struct STBL : public Actor {
    STBL();
};

STBL::STBL() {
    *(void**)this = lbl_804AC2D8;
}

// ---- Dgt2_ctor_80201D00.cpp ----
struct Actor_140 {
    Actor_140();
    ~Actor_140();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A1FA0[];

class DGT2 : public Actor_140 {
public:
    DGT2();
};

DGT2::DGT2() : Actor_140() {
    *(void**)this = lbl_804A1FA0;
    __construct_array((char*)this + 0x288, (void*)fn_8003B2CC, 0, 0xc, 6);
    __construct_array((char*)this + 0x2d0, (void*)fn_8003B2CC, 0, 0xc, 0x14);
}

// ---- Rvfr_ctor_80201D74.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC250[];

struct RVFR : public Actor {
    RVFR();
};

RVFR::RVFR() {
    *(void**)this = lbl_804AC250;
}

// ---- Wppa_ctor_80201DB0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC1F8[];

struct WPPA : public Actor {
    WPPA();
};

WPPA::WPPA() {
    *(void**)this = lbl_804AC1F8;
}

// ---- Flyo_ctor_80201DEC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC100[];

struct FLYO : public Actor {
    FLYO();
};

FLYO::FLYO() {
    *(void**)this = lbl_804AC100;
}

// ---- Bph2_ctor_80201E28.cpp ----
struct Actor_144 {
    Actor_144();
    ~Actor_144();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A1E50[];

class BPH2 : public Actor_144 {
public:
    BPH2();
};

BPH2::BPH2() : Actor_144() {
    *(void**)this = lbl_804A1E50;
    __construct_array((char*)this + 0x2f8, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Prtc_ctor_80201E80.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9AC8[];

struct PRTC : public Actor {
    PRTC();
};

PRTC::PRTC() {
    *(void**)this = lbl_804A9AC8;
}

// ---- Rasn_ctor_80201EBC.cpp ----
struct Actor_146 {
    Actor_146();
    ~Actor_146();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A7A68[];

class RASN : public Actor_146 {
public:
    RASN();
};

RASN::RASN() : Actor_146() {
    *(void**)this = lbl_804A7A68;
    __construct_array((char*)this + 0x238, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Fgn2_ctor_80201F14.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A1A98[];

struct FGN2 : public Actor {
    FGN2();
};

FGN2::FGN2() {
    *(void**)this = lbl_804A1A98;
}

// ---- Wppr_ctor_80201F50.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC0A8[];

struct WPPR : public Actor {
    WPPR();
};

WPPR::WPPR() {
    *(void**)this = lbl_804AC0A8;
}

// ---- Jpen_ctor_80201F8C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AC010[];

struct JPEN : public Actor {
    JPEN();
};

JPEN::JPEN() {
    *(void**)this = lbl_804AC010;
}

// ---- Wnwn_ctor_80201FC8.cpp ----
struct Actor_150 {
    Actor_150();
    ~Actor_150();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A18E0[];

class WNWN : public Actor_150 {
public:
    WNWN();
};

WNWN::WNWN() : Actor_150() {
    *(void**)this = lbl_804A18E0;
    __construct_array((char*)this + 0x294, (void*)fn_8003B2CC, 0, 0xc, 0xa);
    __construct_array((char*)this + 0x30c, (void*)fn_8003B2CC, 0, 0xc, 0xa);
}

// ---- Urac_ctor_8020203C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9A70[];

struct URAC : public Actor {
    URAC();
};

URAC::URAC() {
    *(void**)this = lbl_804A9A70;
}

// ---- Vwmd_ctor_80202078.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9A18[];

struct VWMD : public Actor {
    VWMD();
};

VWMD::VWMD() {
    *(void**)this = lbl_804A9A18;
}

// ---- Tkrm_ctor_802020B4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804ABAE8[];

struct TKRM : public Actor {
    TKRM();
};

TKRM::TKRM() {
    *(void**)this = lbl_804ABAE8;
}

// ---- Bots_ctor_802020F0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C7F0[];

struct BOTS : public Actor {
    BOTS();
};

BOTS::BOTS() {
    *(void**)this = lbl_8049C7F0;
}

// ---- Tsno_ctor_8020212C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804ABA90[];

struct TSNO : public Actor {
    TSNO();
};

TSNO::TSNO() {
    *(void**)this = lbl_804ABA90;
}

// ---- Grve_ctor_80202168.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A99C0[];

struct FGVE : public Actor {
    FGVE();
};

FGVE::FGVE() {
    *(void**)this = lbl_804A99C0;
}

// ---- Yasi_ctor_802021A4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9968[];

struct YASI : public Actor {
    YASI();
};

YASI::YASI() {
    *(void**)this = lbl_804A9968;
}

// ---- Btin_ctor_802021E0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A927C[];

struct BTIN : public Actor {
    BTIN();
};

BTIN::BTIN() {
    *(void**)this = lbl_804A927C;
}

// ---- fn_8020221C_ctor.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A1888[];

struct FAGN : public Actor {
    FAGN();
};

FAGN::FAGN() {
    *(void**)this = lbl_804A1888;
}

// ---- fn_80202258_ctor.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A1790[];

struct GDMN : public Actor {
    GDMN();
};

GDMN::GDMN() {
    char* p = (char*)this;
    *(void**)p = lbl_804A1790;
    *(s32*)(p + 0x234) = -1;
}

// ---- fn_8020229C_ctor.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A1718[];

struct RDVR : public Actor {
    RDVR();
};

RDVR::RDVR() {
    char* p = (char*)this;
    *(void**)p = lbl_804A1718;
    *(s32*)(p + 0x234) = -1;
}

// ---- Dsin_ctor_802022E0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB5D8[];

struct DSIN : public Actor {
    DSIN();
};

DSIN::DSIN() {
    *(void**)this = lbl_804AB5D8;
}

// ---- Grok_ctor_8020231C.cpp ----
struct Actor_163 {
    Actor_163();
    ~Actor_163();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A1630[];

class GROK : public Actor_163 {
public:
    GROK();
};

GROK::GROK() : Actor_163() {
    *(void**)this = lbl_804A1630;
    __construct_array((char*)this + 0x294, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x2c4, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Sbtn_ctor_80202390.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB580[];

struct SBTN : public Actor {
    SBTN();
};

SBTN::SBTN() {
    *(void**)this = lbl_804AB580;
}

// ---- Circ_ctor_802023CC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A7960[];

struct CIRC : public Actor {
    CIRC();
};

CIRC::CIRC() {
    *(void**)this = lbl_804A7960;
}

// ---- Flyk_ctor_80202408.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9078[];

struct FLYK : public Actor {
    FLYK();
};

FLYK::FLYK() {
    *(void**)this = lbl_804A9078;
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

struct PESW : public Actor {
    PESW();
};

PESW::PESW() {
    *(void**)this = lbl_804A7908;
}

// ---- Osin_ctor_802024BC.cpp ----
struct Actor_169 {
    Actor_169();
    ~Actor_169();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804AB528[];

class OSIN : public Actor_169 {
public:
    OSIN();
};

OSIN::OSIN() : Actor_169() {
    *(void**)this = lbl_804AB528;
    __construct_array((char*)this + 0x26c, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Puku_ctor_80202514.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A11B8[];

struct PUKU : public Actor {
    PUKU();
};

PUKU::PUKU() {
    *(void**)this = lbl_804A11B8;
}

// ---- Swbm_ctor_80202550.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A1160[];

struct SWBM : public Actor {
    SWBM();
};

SWBM::SWBM() {
    *(void**)this = lbl_804A1160;
}

// ---- Infr_ctor_8020258C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB4C0[];

struct INFR : public Actor {
    INFR();
};

INFR::INFR() {
    *(void**)this = lbl_804AB4C0;
}

// ---- Arsh_ctor_802025C8.cpp ----
extern "C" void* fn_801D30B8(void* this_);
extern "C" void dtor_801F593C(void* this_, int flag);
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

class ARSH : public Fn801D30B8Base {
public:
    ARSH();
};

ARSH::ARSH() {
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
    dtor_801F593C(localTemp, 0);
}

// ---- Bmty_ctor_8020264C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB464[];

struct BMTY : public Actor {
    BMTY();
};

BMTY::BMTY() {
    *(void**)this = lbl_804AB464;
}

// ---- Pcdm_ctor_80202688.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB3A8[];

struct PCDM : public Actor {
    PCDM();
};

PCDM::PCDM() {
    *(void**)this = lbl_804AB3A8;
}

// ---- Crtl_ctor_802026C4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB308[];

struct CRTL : public Actor {
    CRTL();
};

CRTL::CRTL() {
    *(void**)this = lbl_804AB308;
}

// ---- Rdbl_ctor_80202700.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9020[];

struct RDBL : public Actor {
    RDBL();
};

RDBL::RDBL() {
    *(void**)this = lbl_804A9020;
}

// ---- Onof_ctor_8020273C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8FC8[];

struct ONOF : public Actor {
    ONOF();
};

ONOF::ONOF() {
    *(void**)this = lbl_804A8FC8;
}

// ---- Ocfr_ctor_80202778.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB2B0[];

struct OCFR : public Actor {
    OCFR();
};

OCFR::OCFR() {
    *(void**)this = lbl_804AB2B0;
}

// ---- Brry_ctor_802027B4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB258[];

struct BPRY : public Actor {
    BPRY();
};

BPRY::BPRY() {
    *(void**)this = lbl_804AB258;
}

// ---- Lif2_ctor_802027F0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A78B0[];

struct LIF2 : public Actor {
    LIF2();
};

LIF2::LIF2() {
    *(void**)this = lbl_804A78B0;
}

// ---- Wdry_ctor_8020282C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB1F0[];

struct WDRY : public Actor {
    WDRY();
};

WDRY::WDRY() {
    *(void**)this = lbl_804AB1F0;
}

// ---- Esry_ctor_80202868.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB170[];

struct ESRY : public Actor {
    ESRY();
};

ESRY::ESRY() {
    *(void**)this = lbl_804AB170;
}

// ---- Shlt_ctor_802028A4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A0FF8[];

struct SHLT : public Actor {
    SHLT();
};

SHLT::SHLT() {
    *(void**)this = lbl_804A0FF8;
}

// ---- Rank_ctor_802028E0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8F74[];

struct RANK : public Actor {
    RANK();
};

RANK::RANK() {
    *(void**)this = lbl_804A8F74;
}

// ---- Hnry_ctor_8020291C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB098[];

struct HNRY : public Actor {
    HNRY();
};

HNRY::HNRY() {
    *(void**)this = lbl_804AB098;
}

// ---- Bldf_ctor_80202958.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8EF8[];

struct BLDF : public Actor {
    BLDF();
};

BLDF::BLDF() {
    *(void**)this = lbl_804A8EF8;
}

// ---- Focs_ctor_80202994.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8EA0[];

struct FOCS : public Actor {
    FOCS();
};

FOCS::FOCS() {
    *(void**)this = lbl_804A8EA0;
}

// ---- Pnpc_ctor_802029D0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8E40[];

struct PNPC : public Actor {
    PNPC();
};

PNPC::PNPC() {
    *(void**)this = lbl_804A8E40;
}

// ---- Rail_ctor_80202A0C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C770[];

struct RAIL : public Actor {
    RAIL();
};

RAIL::RAIL() {
    *(void**)this = lbl_8049C770;
}

// ---- Zosh_ctor_80202A48.cpp ----
extern "C" void* fn_801D30B8(void* this_);
extern "C" void dtor_801F593C(void* this_, int flag);
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

class ZNSH : public Fn801D30B8Base_191 {
public:
    ZNSH();
};

ZNSH::ZNSH() {
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
    dtor_801F593C(localTemp, 0);
}

// ---- Door_ctor_80202ACC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8D88[];

struct DOOR : public Actor {
    DOOR();
};

DOOR::DOOR() {
    *(void**)this = lbl_804A8D88;
}

// ---- Key0_ctor_80202B08.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8CD8[];

struct KEY0 : public Actor {
    KEY0();
};

KEY0::KEY0() {
    *(void**)this = lbl_804A8CD8;
}

// ---- Lsti_ctor_80202B44.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8C80[];

struct LSTI : public Actor {
    LSTI();
};

LSTI::LSTI() {
    *(void**)this = lbl_804A8C80;
}

// ---- Wizr_ctor_80202B80.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A0EDC[];

struct WIZR : public Actor {
    WIZR();
};

WIZR::WIZR() {
    *(void**)this = lbl_804A0EDC;
}

// ---- Swnp_ctor_80202BBC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8C28[];

struct SWNP : public Actor {
    SWNP();
};

SWNP::SWNP() {
    *(void**)this = lbl_804A8C28;
}

// ---- Cksw_ctor_80202BF8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8BD0[];

struct CKSW : public Actor {
    CKSW();
};

CKSW::CKSW() {
    *(void**)this = lbl_804A8BD0;
}

// ---- Tngl_ctor_80202C34.cpp ----
struct Actor_198 {
    Actor_198();
    ~Actor_198();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804B0478[];

class TNGL : public Actor_198 {
public:
    TNGL();
};

TNGL::TNGL() : Actor_198() {
    *(void**)this = lbl_804B0478;
    __construct_array((char*)this + 0x260, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Stal_ctor_80202C8C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A0CD8[];

struct STAL : public Actor {
    STAL();
};

STAL::STAL() {
    *(void**)this = lbl_804A0CD8;
}

// ---- Wrtc_ctor_80202CC8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C678[];

struct WRTC : public Actor {
    WRTC();
};

WRTC::WRTC() {
    *(void**)this = lbl_8049C678;
}

// ---- Lwsw_ctor_80202D04.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8B78[];

struct LWSW : public Actor {
    LWSW();
};

LWSW::LWSW() {
    *(void**)this = lbl_804A8B78;
}

// ---- Bwrt_ctor_80202D40.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C718[];

struct BWRT : public Actor {
    BWRT();
};

BWRT::BWRT() {
    *(void**)this = lbl_8049C718;
    *(u8*)((char*)this + 0x29c) = 0;
}

// ---- Bfin_ctor_80202D84.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804B0380[];

struct BFIN : public Actor {
    BFIN();
};

BFIN::BFIN() {
    *(void**)this = lbl_804B0380;
}

// ---- Wtsw_ctor_80202DC0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8B20[];

struct WTSW : public Actor {
    WTSW();
};

WTSW::WTSW() {
    *(void**)this = lbl_804A8B20;
}

// ---- Znsw_ctor_80202DFC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8AC8[];

struct ZNSW : public Actor {
    ZNSW();
};

ZNSW::ZNSW() {
    *(void**)this = lbl_804A8AC8;
}

// ---- Lplk_ctor_80202E38.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C578[];

struct LPLK : public Actor {
    LPLK();
};

LPLK::LPLK() {
    *(void**)this = lbl_8049C578;
}

// ---- Iwag_ctor_80202E74.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C46C[];

struct IWAG : public Actor {
    IWAG();
};

IWAG::IWAG() {
    *(void**)this = lbl_8049C46C;
}

// ---- Oiwa_ctor_80202EB0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C4C0[];

struct OIWA : public Actor {
    OIWA();
};

OIWA::OIWA() {
    *(void**)this = lbl_8049C4C0;
}

// ---- Nzmi_ctor_80202EEC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049C400[];

struct NZMI : public Actor {
    NZMI();
};

NZMI::NZMI() {
    *(void**)this = lbl_8049C400;
}

// ---- Blze_ctor_80202F28.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8A50[];

struct BLZE : public Actor {
    BLZE();
};

BLZE::BLZE() {
    *(void**)this = lbl_804A8A50;
}

// ---- Fire_ctor_80202F64.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A89F0[];

struct FIRE : public Actor {
    FIRE();
};

FIRE::FIRE() {
    *(void**)this = lbl_804A89F0;
}

// ---- Niwa_ctor_80202FA0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB8C0[];

struct NIWA : public Actor {
    NIWA();
};

NIWA::NIWA() {
    *(void**)this = lbl_804AB8C0;
}

// ---- Bgwc_ctor_80202FDC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8998[];

struct BGWC : public Actor {
    BGWC();
};

BGWC::BGWC() {
    *(void**)this = lbl_804A8998;
}

// ---- Dosn_ctor_80203018.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8940[];

struct DOSN : public Actor {
    DOSN();
};

DOSN::DOSN() {
    *(void**)this = lbl_804A8940;
}

// ---- Tlk2_ctor_80203054.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AFAD8[];

struct TLK2 : public Actor {
    TLK2();
};

TLK2::TLK2() {
    *(void**)this = lbl_804AFAD8;
}

// ---- Slr4_ctor_80203090.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A0B90[];

struct SLR4 : public Actor {
    SLR4();
};

SLR4::SLR4() {
    *(void**)this = lbl_804A0B90;
}

// ---- Sbal_ctor_802030CC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB9C0[];

struct SBAL : public Actor {
    SBAL();
};

SBAL::SBAL() {
    *(void**)this = lbl_804AB9C0;
}

// ---- Swel_ctor_80203108.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A88E8[];

struct SWEL : public Actor {
    SWEL();
};

SWEL::SWEL() {
    *(void**)this = lbl_804A88E8;
}

// ---- Lift_ctor_80203144.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A6F6C[];

struct LIFT : public Actor {
    LIFT();
};

LIFT::LIFT() {
    *(void**)this = lbl_804A6F6C;
}

// ---- Ry02_ctor_80203180.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB850[];

struct RY02 : public Actor {
    RY02();
};

RY02::RY02() {
    *(void**)this = lbl_804AB850;
}

// ---- Deth_ctor_802031BC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A886C[];

struct CRTH : public Actor {
    CRTH();
};

CRTH::CRTH() {
    *(void**)this = lbl_804A886C;
}

// ---- Swor_ctor_802031F8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8800[];

struct SWOR : public Actor {
    SWOR();
};

SWOR::SWOR() {
    *(void**)this = lbl_804A8800;
}

// ---- Popo_ctor_80203234.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A0868[];

struct POPO : public Actor {
    POPO();
};

POPO::POPO() {
    *(void**)this = lbl_804A0868;
}

// ---- Wood_ctor_80203270.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A87A8[];

struct WOOD : public Actor {
    WOOD();
};

WOOD::WOOD() {
    *(void**)this = lbl_804A87A8;
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

struct PEFF : public Actor {
    PEFF();
};

PEFF::PEFF() {
    *(void**)this = lbl_804A6E20;
}

// ---- Slsd_ctor_80203340.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A85E0[];

struct SLSD : public Actor {
    SLSD();
};

SLSD::SLSD() {
    *(void**)this = lbl_804A85E0;
}

// ---- Sstn_ctor_8020337C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8750[];

struct SSTN : public Actor {
    SSTN();
};

SSTN::SSTN() {
    *(void**)this = lbl_804A8750;
}

// ---- Skul_ctor_802033B8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8588[];

struct SKUL : public Actor {
    SKUL();
};

SKUL::SKUL() {
    *(void**)this = lbl_804A8588;
}

// ---- Talk_ctor_802033F4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AF548[];

struct TALK : public Actor {
    TALK();
};

TALK::TALK() {
    *(void**)this = lbl_804AF548;
}

// ---- Trch_ctor_80203430.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8520[];

struct TRCH : public Actor {
    TRCH();
};

TRCH::TRCH() {
    *(void**)this = lbl_804A8520;
}

// ---- Scre_ctor_8020346C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AF4C0[];

struct SCRE : public Actor {
    SCRE();
};

SCRE::SCRE() {
    *(void**)this = lbl_804AF4C0;
}

// ---- Spot_ctor_802034A8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A84C8[];

struct SPOT : public Actor {
    SPOT();
};

SPOT::SPOT() {
    *(void**)this = lbl_804A84C8;
}

// ---- Yaji_ctor_802034E4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8470[];

struct YAJI : public Actor {
    YAJI();
};

YAJI::YAJI() {
    *(void**)this = lbl_804A8470;
}

// ---- Bome_ctor_80203520.cpp ----
struct Actor_235 {
    Actor_235();
    ~Actor_235();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_80203594(void);
extern void* lbl_804A0738[];

class BOME : public Actor_235 {
public:
    BOME();
};

BOME::BOME() : Actor_235() {
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

struct KMRI : public Actor {
    KMRI();
};

KMRI::KMRI() {
    *(void**)this = lbl_804A8418;
}

// ---- Tflr_ctor_802035D4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A83A0[];

struct TFLR : public Actor {
    TFLR();
};

TFLR::TFLR() {
    *(void**)this = lbl_804A83A0;
}

// ---- Knbn_ctor_80203610.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AF428[];

struct KNBN : public Actor {
    KNBN();
};

KNBN::KNBN() {
    *(void**)this = lbl_804AF428;
}

// ---- Plas_ctor_8020364C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8338[];

struct PLAS : public Actor {
    PLAS();
};

PLAS::PLAS() {
    *(void**)this = lbl_804A8338;
}

// ---- Itms_ctor_80203688.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A82A8[];

struct ITMS : public Actor {
    ITMS();
};

ITMS::ITMS() {
    *(void**)this = lbl_804A82A8;
}

// ---- Poon_ctor_802036C4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A06C0[];

struct Poon : public Actor {
    Poon();
};

Poon::Poon() {
    *(void**)this = lbl_804A06C0;
}

// ---- Skil_ctor_80203700.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8250[];

struct SKIL : public Actor {
    SKIL();
};

SKIL::SKIL() {
    *(void**)this = lbl_804A8250;
}

// ---- Mozo_ctor_8020373C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A0668[];

struct MOZO : public Actor {
    MOZO();
};

MOZO::MOZO() {
    *(void**)this = lbl_804A0668;
}

// ---- Bfry_ctor_80203778.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AF338[];

struct BERY : public Actor {
    BERY();
};

BERY::BERY() {
    *(void**)this = lbl_804AF338;
}

// ---- Pont_ctor_802037B4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A81C8[];

struct PONT : public Actor {
    PONT();
};

PONT::PONT() {
    *(void**)this = lbl_804A81C8;
}

// ---- Arrw_ctor_802037F0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A05E0[];

struct ARRW : public Actor {
    ARRW();
};

ARRW::ARRW() {
    *(void**)this = lbl_804A05E0;
}

// ---- Trap_ctor_8020382C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A04D8[];

struct TRAP : public Actor {
    TRAP();
};

TRAP::TRAP() {
    *(void**)this = lbl_804A04D8;
}

// ---- Thrn_ctor_80203868.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8170[];

struct THRN : public Actor {
    THRN();
};

THRN::THRN() {
    *(void**)this = lbl_804A8170;
}

// ---- Swev_ctor_802038A4.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8638[];

struct SWEV : public Actor {
    SWEV();
};

SWEV::SWEV() {
    *(void**)this = lbl_804A8638;
    *(s32*)((char*)this + 0x2dc) = -1;
}

// ---- Ball_ctor_802038E8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB968[];

struct BALL : public Actor {
    BALL();
};

BALL::BALL() {
    *(void**)this = lbl_804AB968;
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

class BPOH : public Actor_252 {
public:
    BPOH();
};

BPOH::BPOH() : Actor_252() {
    *(void**)this = lbl_804A0440;
    __construct_array((char*)this + 0x2b8, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x2f4, (void*)fn_8009711C, 0, 0x4, 3);
}

// ---- Shtr_ctor_80203998.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8118[];

struct SHTR : public Actor {
    SHTR();
};

SHTR::SHTR() {
    *(void**)this = lbl_804A8118;
}

// ---- Fary_ctor_802039D4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A03B8[];

struct EZRY : public Actor {
    EZRY();
};

EZRY::EZRY() {
    *(void**)this = lbl_804A03B8;
}

// ---- Swt4_ctor_80203A10.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A80A0[];

struct SWT4 : public Actor {
    SWT4();
};

SWT4::SWT4() {
    *(void**)this = lbl_804A80A0;
}

// ---- Ryrn_ctor_80203A4C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A8010[];

struct RYRN : public Actor {
    RYRN();
};

RYRN::RYRN() {
    *(void**)this = lbl_804A8010;
}

// ---- Mtbo_ctor_80203A88.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AF018[];

struct MTBO : public Actor {
    MTBO();
};

MTBO::MTBO() {
    *(void**)this = lbl_804AF018;
}

// ---- Tkyu_ctor_80203AC4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804ABA38[];

struct TKYU : public Actor {
    TKYU();
};

TKYU::TKYU() {
    *(void**)this = lbl_804ABA38;
}

// ---- Flme_ctor_80203B00.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A0330[];

struct FLME : public Actor {
    FLME();
};

FLME::FLME() {
    *(void**)this = lbl_804A0330;
}

// ---- Keth_ctor_80203B3C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A02B8[];

struct KETH : public Actor {
    KETH();
};

KETH::KETH() {
    *(void**)this = lbl_804A02B8;
}

// ---- Boyo_ctor_80203B78.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A0260[];

struct BOYO : public Actor {
    BOYO();
};

BOYO::BOYO() {
    *(void**)this = lbl_804A0260;
}

// ---- Imup_ctor_80203BB4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A01D0[];

struct IMUP : public Actor {
    IMUP();
};

IMUP::IMUP() {
    *(void**)this = lbl_804A01D0;
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

struct TKTA : public Actor {
    TKTA();
};

TKTA::TKTA() {
    *(void**)this = lbl_8049FD50;
}

// ---- Expl_ctor_80203C68.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A7FB8[];

struct EXPL : public Actor {
    EXPL();
};

EXPL::EXPL() {
    *(void**)this = lbl_804A7FB8;
}

// ---- Slr1_ctor_80203CA4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049FCA0[];

struct SLR1 : public Actor {
    SLR1();
};

SLR1::SLR1() {
    *(void**)this = lbl_8049FCA0;
}

// ---- Swth_ctor_80203CE0.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A7F38[];

struct SWTH : public Actor {
    SWTH();
};

SWTH::SWTH() {
    *(void**)this = lbl_804A7F38;
}

// ---- Hbmb_ctor_80203D1C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F784[];

struct HBMB : public Actor {
    HBMB();
};

HBMB::HBMB() {
    *(void**)this = lbl_8049F784;
}

// ---- Hino_ctor_80203D58.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F9B4[];

struct HINO : public Actor {
    HINO();
};

HINO::HINO() {
    *(void**)this = lbl_8049F9B4;
}

// ---- Goal_ctor_80203D94.cpp ----
struct Actor_270 {
    Actor_270();
    ~Actor_270();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_804A7EB0[];

class GOAL : public Actor_270 {
public:
    GOAL();
};

GOAL::GOAL() : Actor_270() {
    *(void**)this = lbl_804A7EB0;
    __construct_array((char*)this + 0x264, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Bhrt_ctor_80203DEC.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A7E58[];

struct BHRT : public Actor {
    BHRT();
};

BHRT::BHRT() {
    *(void**)this = lbl_804A7E58;
}

// ---- Dgtl_ctor_80203E28.cpp ----
struct Actor_272 {
    Actor_272();
    ~Actor_272();
};

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*);
extern void* lbl_8049F6C8[];

class DGTL : public Actor_272 {
public:
    DGTL();
};

DGTL::DGTL() : Actor_272() {
    *(void**)this = lbl_8049F6C8;
    __construct_array((char*)this + 0x2c0, (void*)fn_8003B2CC, 0, 0xc, 0xa);
    __construct_array((char*)this + 0x3d8, (void*)fn_8003B2CC, 0, 0xc, 0x50);
}

// ---- Oktm_ctor_80203E9C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F5D8[];

struct OKTM : public Actor {
    OKTM();
};

OKTM::OKTM() {
    *(void**)this = lbl_8049F5D8;
}

// ---- Hart_ctor_80203ED8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F4F0[];

struct HART : public Actor {
    HART();
};

HART::HART() {
    *(void**)this = lbl_8049F4F0;
}

// ---- Gold_ctor_80203F14.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB660[];

struct GNLD : public Actor {
    GNLD();
};

GNLD::GNLD() {
    *(void**)this = lbl_804AB660;
}

// ---- Ddrk_ctor_80203F50.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F498[];

struct DBRK : public Actor {
    DBRK();
};

DBRK::DBRK() {
    *(void**)this = lbl_8049F498;
}

// ---- Bzbr_ctor_80203F8C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F444[];

struct BZBR : public Actor {
    BZBR();
};

BZBR::BZBR() {
    *(void**)this = lbl_8049F444;
}

// ---- Blck_ctor_80203FC8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A7A10[];

struct BLCK : public Actor {
    BLCK();
};

BLCK::BLCK() {
    *(void**)this = lbl_804A7A10;
}

// ---- Peac_ctor_80204004.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F3B0[];

struct PEAC : public Actor {
    PEAC();
};

PEAC::PEAC() {
    *(void**)this = lbl_8049F3B0;
}

// ---- Tubo_ctor_80204040.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9428[];

struct TUBO : public Actor {
    TUBO();
};

TUBO::TUBO() {
    *(void**)this = lbl_804A9428;
}

// ---- Rock_ctor_8020407C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9480[];

struct ROCK : public Actor {
    ROCK();
};

ROCK::ROCK() {
    *(void**)this = lbl_804A9480;
}

// ---- Warp_ctor_802040B8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A6DC8[];

struct WARP : public Actor {
    WARP();
};

WARP::WARP() {
    *(void**)this = lbl_804A6DC8;
}

// ---- Bord_ctor_802040F4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A94D8[];

struct BORD : public Actor {
    BORD();
};

BORD::BORD() {
    *(void**)this = lbl_804A94D8;
}

// ---- Ston_ctor_80204130.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A93D0[];

struct STON : public Actor {
    STON();
};

STON::STON() {
    *(void**)this = lbl_804A93D0;
}

// ---- Gene_ctor_8020416C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A9328[];

struct GENE : public Actor {
    GENE();
};

GENE::GENE() {
    *(void**)this = lbl_804A9328;
}

// ---- Gras_ctor_802041A8.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804A92D0[];

struct FGAS : public Actor {
    FGAS();
};

FGAS::FGAS() {
    *(void**)this = lbl_804A92D0;
}

// ---- Pooh_ctor_802041E4.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F330[];

struct POOH : public Actor {
    POOH();
};

POOH::POOH() {
    *(void**)this = lbl_8049F330;
}

// ---- Amos_ctor_80204220.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F260[];

struct AMOS : public Actor {
    AMOS();
};

AMOS::AMOS() {
    *(void**)this = lbl_8049F260;
}

// ---- Okta_ctor_8020425C.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049F208[];

struct OKTA : public Actor {
    OKTA();
};

OKTA::OKTA() {
    *(void**)this = lbl_8049F208;
}

// ---- Rupy_ctor_80204298.cpp ----
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_804AB6D8[];

struct RUPY : public Actor {
    RUPY();
};

RUPY::RUPY() {
    *(void**)this = lbl_804AB6D8;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
