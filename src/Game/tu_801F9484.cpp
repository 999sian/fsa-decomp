// TU 0x801f9484-0x80204638.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

// Actor base (0x801F5AE0 ctor, 0x801F593C dtor); full layout lives on the  Actor branch.
struct ActorBox;
struct Actor {
    Actor();
    ~Actor();
    void setBox70(const ActorBox& box);                 /* 0x801FF630 */
    void setPos(const JGeometry::TVec3<f32>& pos);      /* 0x801FF704 */
    u8 _base[0x230];
};

extern "C" void* fn_80105BEC(void*);
extern "C" void* fn_80108168(void*);
extern "C" void* fn_8010AFC4(void*);
extern "C" void* fn_8010C00C(void*);
extern "C" void* fn_8010D7A0(void*);
extern "C" void* fn_80112070(void*);
extern "C" void* fn_801134DC(void*);
extern "C" void* fn_80115590(void*);
extern "C" void* fn_80116BE8(void*);
extern "C" void* fn_801180D0(void*);
extern "C" void* fn_8011A248(void*);
extern "C" void* fn_8011B0DC(void*);
extern "C" void* fn_8011CC2C(void*);
extern "C" void* fn_8011E6E0(void*);
extern "C" void* fn_8011FD28(void*);
extern "C" void* fn_80121164(void*);
extern "C" void* fn_801258D8(void*);
extern "C" void* fn_80127B48(void*);
extern "C" void* fn_8012A364(void*);
extern "C" void* fn_8012D848(void*);
extern "C" void* fn_8012E780(void*);
extern "C" void* fn_8012F178(void*);
extern "C" void* fn_80131AF0(void*);
extern "C" void* fn_801336B4(void*);
extern "C" void* fn_801B7DE0(void*);
extern "C" void* fn_801B94C8(void*);
extern "C" void* fn_801BA3FC(void*);
extern "C" void* fn_801BB3B0(void*);
extern "C" void* fn_801BCCF0(void*);
extern "C" void* fn_801BD640(void*);
extern "C" void* fn_801BDBF0(void*);
extern "C" void* fn_801BEB44(void*);
extern "C" void* fn_801BF5A8(void*);
extern "C" void* fn_801C0AD8(void*);
extern "C" void* fn_801C2414(void*);
extern "C" void* fn_801C573C(void*);
extern "C" void* fn_801D686C(void*);
extern "C" void* fn_801D8194(void*);
extern "C" void* fn_801DA504(void*);
extern "C" void* fn_801DBFB0(void*);
extern "C" void* fn_801DCA30(void*);
extern "C" void* fn_801DCF40(void*);
extern "C" void* fn_801E22A4(void*);
extern "C" void* fn_801E33B8(void*);
extern "C" void* fn_801E78F0(void*);
extern "C" void* fn_801E7DBC(void*);
extern "C" void* fn_801E9850(void*);
extern "C" void* fn_801ED144(void*);
extern "C" void* fn_801FFD1C(void*);
extern "C" void* fn_80200060(void*);
extern "C" void* fn_80200764(void*);
extern "C" void* fn_802014C8(void*);
extern "C" void* fn_80201B3C(void*);
extern "C" void* fn_80201BF0(void*);
extern "C" void* fn_80202444(void*);
extern "C" void* fn_80203BF0(void*);
extern "C" void* fn_80206810(void*);
extern "C" void* fn_80208BE0(void*);
extern "C" void* fn_802095C4(void*);
extern "C" void* fn_8020B0B8(void*);
extern "C" void* fn_8020BE40(void*);
extern "C" void* fn_8020CA34(void*);
extern "C" void* fn_8020F510(void*);
extern "C" void* fn_802103C0(void*);
extern "C" void* fn_80212800(void*);
extern "C" void* fn_80213BA0(void*);
extern "C" void* fn_80213FE4(void*);
extern "C" void* fn_8021A2D0(void*);
extern "C" void* fn_8021D4CC(void*);
extern "C" void* fn_8021EDC0(void*);
extern "C" void* fn_80220378(void*);
extern "C" void* fn_80222190(void*);
extern "C" void* fn_80222A58(void*);
extern "C" void* fn_8022313C(void*);
extern "C" void* fn_80224084(void*);
extern "C" void* fn_80340C60(void*);
extern "C" void* fn_8036C750(void*);

struct GSCK : public Actor {
    GSCK();
    u8 _pad[0x23c - sizeof(Actor)];
};
struct MRTC : public Actor {
    MRTC();
    u8 _pad[0x238 - sizeof(Actor)];
};
struct STGN : public Actor {
    STGN();
    u8 _pad[0x230 - sizeof(Actor)];
};
struct RINS : public Actor {
    RINS();
    u8 _pad[0x234 - sizeof(Actor)];
};
struct WPWL : public Actor {
    WPWL();
    u8 _pad[0x238 - sizeof(Actor)];
};
struct PSS2 : public Actor {
    PSS2();
    u8 _pad[0x244 - sizeof(Actor)];
};
struct TBO2 : public Actor {
    TBO2();
    u8 _pad[0x230 - sizeof(Actor)];
};
struct TBGN : public Actor {
    TBGN();
    u8 _pad[0x234 - sizeof(Actor)];
};
struct ICEB : public Actor {
    ICEB();
    u8 _pad[0x254 - sizeof(Actor)];
};
struct DMYK : public Actor {
    DMYK();
    u8 _pad[0x240 - sizeof(Actor)];
};
struct JPE2 : public Actor {
    JPE2();
    u8 _pad[0x284 - sizeof(Actor)];
};
struct ENDR : public Actor {
    ENDR();
    u8 _pad[0x230 - sizeof(Actor)];
};
struct TFL2 : public Actor {
    TFL2();
    u8 _pad[0x254 - sizeof(Actor)];
};
struct LOSW : public Actor {
    LOSW();
    u8 _pad[0x250 - sizeof(Actor)];
};
struct PSWK : public Actor {
    PSWK();
    u8 _pad[0x258 - sizeof(Actor)];
};
struct SIBT : public Actor {
    SIBT();
    u8 _pad[0x248 - sizeof(Actor)];
};
struct PSWB : public Actor {
    PSWB();
    u8 _pad[0x258 - sizeof(Actor)];
};
class GEWP : public Actor {
public:
    GEWP();
    u8 _pad[0x2a4 - sizeof(Actor)];
};
struct SNPC : public Actor {
    SNPC();
    u8 _pad[0x274 - sizeof(Actor)];
};
struct TJIJ : public Actor {
    TJIJ();
    u8 _pad[0x230 - sizeof(Actor)];
};
class MRTA : public Actor {
public:
    MRTA();
    u8 _pad[0x2e4 - sizeof(Actor)];
};
struct SWDL : public Actor {
    SWDL();
    u8 _pad[0x274 - sizeof(Actor)];
};
class fn_801FFD58_actor : public Actor {
public:
    fn_801FFD58_actor();
    u8 _pad[0x3c0 - sizeof(Actor)];
};
struct ELK2 : public Actor {
    ELK2();
    u8 _pad[0x2b8 - sizeof(Actor)];
};
struct PTMI : public Actor {
    PTMI();
    u8 _pad[0x234 - sizeof(Actor)];
};
struct MRMT : public Actor {
    MRMT();
    u8 _pad[0x250 - sizeof(Actor)];
};
struct FOEV : public Actor {
    FOEV();
    u8 _pad[0x27c - sizeof(Actor)];
};
struct RSNP : public Actor {
    RSNP();
    u8 _pad[0x234 - sizeof(Actor)];
};
struct OGST : public Actor {
    OGST();
    u8 _pad[0x234 - sizeof(Actor)];
};
struct ICOB : public Actor {
    ICOB();
    u8 _pad[0x234 - sizeof(Actor)];
};
struct ELSK : public Actor {
    ELSK();
    u8 _pad[0x238 - sizeof(Actor)];
};
struct TUTM : public Actor {
    TUTM();
    u8 _pad[0x294 - sizeof(Actor)];
};
class TUGF : public Actor {
public:
    TUGF();
    u8 _pad[0x2fc - sizeof(Actor)];
};
struct LEAF : public Actor {
    LEAF();
    u8 _pad[0x254 - sizeof(Actor)];
};
struct LFGN : public Actor {
    LFGN();
    u8 _pad[0x230 - sizeof(Actor)];
};
struct THCL : public Actor {
    THCL();
    u8 _pad[0x234 - sizeof(Actor)];
};
struct AGBW : public Actor {
    AGBW();
    u8 _pad[0x240 - sizeof(Actor)];
};
struct SVGT : public Actor {
    SVGT();
    u8 _pad[0x23c - sizeof(Actor)];
};
struct TMI2 : public Actor {
    TMI2();
    u8 _pad[0x238 - sizeof(Actor)];
};
struct SAFU : public Actor {
    SAFU();
    u8 _pad[0x270 - sizeof(Actor)];
};
struct FDWP : public Actor {
    FDWP();
    u8 _pad[0x240 - sizeof(Actor)];
};
struct TWEV : public Actor {
    TWEV();
    u8 _pad[0x2b4 - sizeof(Actor)];
};
struct DWAP : public Actor {
    DWAP();
    u8 _pad[0x240 - sizeof(Actor)];
};
struct TOOI : public Actor {
    TOOI();
    u8 _pad[0x250 - sizeof(Actor)];
};
struct CHSW : public Actor {
    CHSW();
    u8 _pad[0x244 - sizeof(Actor)];
};
class TLWP : public Actor {
public:
    TLWP();
    u8 _pad[0x2f0 - sizeof(Actor)];
};
struct JWLK : public Actor {
    JWLK();
    u8 _pad[0x290 - sizeof(Actor)];
};
struct RBPN : public Actor {
    RBPN();
    u8 _pad[0x248 - sizeof(Actor)];
};
struct PSW2 : public Actor {
    PSW2();
    u8 _pad[0x264 - sizeof(Actor)];
};
class GNEF : public Actor {
public:
    GNEF();
    u8 _pad[0x2d0 - sizeof(Actor)];
};
struct STPN : public Actor {
    STPN();
    u8 _pad[0x234 - sizeof(Actor)];
};
struct SSMI : public Actor {
    SSMI();
    u8 _pad[0x238 - sizeof(Actor)];
};
struct MEDM : public Actor {
    MEDM();
    u8 _pad[0x258 - sizeof(Actor)];
};
struct SDSM : public Actor {
    SDSM();
    u8 _pad[0x258 - sizeof(Actor)];
};
struct BCK2 : public Actor {
    BCK2();
    u8 _pad[0x24c - sizeof(Actor)];
};
struct SPTG : public Actor {
    SPTG();
    u8 _pad[0x25c - sizeof(Actor)];
};
struct DNAV : public Actor {
    DNAV();
    u8 _pad[0x278 - sizeof(Actor)];
};
struct ZOMO : public Actor {
    ZOMO();
    u8 _pad[0x23c - sizeof(Actor)];
};
struct ZDCO : public Actor {
    ZDCO();
    u8 _pad[0x278 - sizeof(Actor)];
};
class ZLD3 : public Actor {
public:
    ZLD3();
    u8 _pad[0x2c0 - sizeof(Actor)];
};
struct OBLF : public Actor {
    OBLF();
    u8 _pad[0x2a0 - sizeof(Actor)];
};
struct GEN3 : public Actor {
    GEN3();
    u8 _pad[0x254 - sizeof(Actor)];
};
struct EGOL : public Actor {
    EGOL();
    u8 _pad[0x268 - sizeof(Actor)];
};
class YNSW : public Actor {
public:
    YNSW();
    u8 _pad[0x284 - sizeof(Actor)];
};
struct GMTB : public Actor {
    GMTB();
    u8 _pad[0x258 - sizeof(Actor)];
};
struct GMBL : public Actor {
    GMBL();
    u8 _pad[0x28c - sizeof(Actor)];
};
class EETC : public Actor {
public:
    EETC();
    u8 _pad[0x31c - sizeof(Actor)];
};
class RCK2 : public Actor {
public:
    RCK2();
    u8 _pad[0x38c - sizeof(Actor)];
};
class EOWL : public Actor {
public:
    EOWL();
    u8 _pad[0x2bc - sizeof(Actor)];
};
class DMTW : public Actor {
public:
    DMTW();
    u8 _pad[0x408 - sizeof(Actor)];
};
struct SMRI : public Actor {
    SMRI();
    u8 _pad[0x258 - sizeof(Actor)];
};
struct ELNK : public Actor {
    ELNK();
    u8 _pad[0x270 - sizeof(Actor)];
};
struct DTLK : public Actor {
    DTLK();
    u8 _pad[0x238 - sizeof(Actor)];
};
struct TKRA : public Actor {
    TKRA();
    u8 _pad[0x268 - sizeof(Actor)];
};
struct OKAM : public Actor {
    OKAM();
    u8 _pad[0x284 - sizeof(Actor)];
};
class TTAT : public Actor {
public:
    TTAT();
    u8 _pad[0x2bc - sizeof(Actor)];
};
struct GNMA : public Actor {
    GNMA();
    u8 _pad[0x284 - sizeof(Actor)];
};
struct DDGO : public Actor {
    DDGO();
    u8 _pad[0x2a4 - sizeof(Actor)];
};
struct ENDM : public Actor {
    ENDM();
    u8 _pad[0x29c - sizeof(Actor)];
};
struct LCLS : public Actor {
    LCLS();
    u8 _pad[0x230 - sizeof(Actor)];
};
struct GLBS : public Actor {
    GLBS();
    u8 _pad[0x230 - sizeof(Actor)];
};
struct EMIK : public Actor {
    EMIK();
    u8 _pad[0x27c - sizeof(Actor)];
};
struct EZLD : public Actor {
    EZLD();
    u8 _pad[0x254 - sizeof(Actor)];
};
struct ENPC : public Actor {
    ENPC();
    u8 _pad[0x2a4 - sizeof(Actor)];
};
class HBB2 : public Actor {
public:
    HBB2();
    u8 _pad[0x474 - sizeof(Actor)];
};
class NWOK : public Actor {
public:
    NWOK();
    u8 _pad[0x2c4 - sizeof(Actor)];
};
struct RYYA : public Actor {
    RYYA();
    u8 _pad[0x274 - sizeof(Actor)];
};
struct MJGR : public Actor {
    MJGR();
    u8 _pad[0x274 - sizeof(Actor)];
};
struct HTMK : public Actor {
    HTMK();
    u8 _pad[0x238 - sizeof(Actor)];
};
struct ENBZ : public Actor {
    ENBZ();
    u8 _pad[0x298 - sizeof(Actor)];
};
struct PNP2 : public Actor {
    PNP2();
    u8 _pad[0x240 - sizeof(Actor)];
};
struct SSLF : public Actor {
    SSLF();
    u8 _pad[0x274 - sizeof(Actor)];
};
struct BEMN : public Actor {
    BEMN();
    u8 _pad[0x284 - sizeof(Actor)];
};
struct FOBE : public Actor {
    FOBE();
    u8 _pad[0x2a4 - sizeof(Actor)];
};
struct SEN2 : public Actor {
    SEN2();
    u8 _pad[0x23c - sizeof(Actor)];
};
struct CRGN : public Actor {
    CRGN();
    u8 _pad[0x284 - sizeof(Actor)];
};
struct TENN : public Actor {
    TENN();
    u8 _pad[0x354 - sizeof(Actor)];
};
struct WAVE : public Actor {
    WAVE();
    u8 _pad[0x238 - sizeof(Actor)];
};
struct FORM : public Actor {
    FORM();
    u8 _pad[0x258 - sizeof(Actor)];
};
struct SPBG : public Actor {
    SPBG();
    u8 _pad[0x24c - sizeof(Actor)];
};
struct SZSC : public Actor {
    SZSC();
    u8 _pad[0x234 - sizeof(Actor)];
};
struct NNJN : public Actor {
    NNJN();
    u8 _pad[0x274 - sizeof(Actor)];
};
struct SYKY : public Actor {
    SYKY();
    u8 _pad[0x2b0 - sizeof(Actor)];
};
struct ANHO : public Actor {
    ANHO();
    u8 _pad[0x284 - sizeof(Actor)];
};
struct FISH : public Actor {
    FISH();
    u8 _pad[0x274 - sizeof(Actor)];
};
struct ALCE : public Actor {
    ALCE();
    u8 _pad[0x268 - sizeof(Actor)];
};
struct ZOOM : public Actor {
    ZOOM();
    u8 _pad[0x24c - sizeof(Actor)];
};
struct BGMN : public Actor {
    BGMN();
    u8 _pad[0x260 - sizeof(Actor)];
};
struct MGYA : public Actor {
    MGYA();
    u8 _pad[0x294 - sizeof(Actor)];
};
struct GFBS : public Actor {
    GFBS();
    u8 _pad[0x230 - sizeof(Actor)];
};
struct BLZ2 : public Actor {
    BLZ2();
    u8 _pad[0x30c - sizeof(Actor)];
};
struct SEV2 : public Actor {
    SEV2();
    u8 _pad[0x28c - sizeof(Actor)];
};
struct RNSW : public Actor {
    RNSW();
    u8 _pad[0x254 - sizeof(Actor)];
};
struct SENP : public Actor {
    SENP();
    u8 _pad[0x240 - sizeof(Actor)];
};
struct GSYA : public Actor {
    GSYA();
    u8 _pad[0x2ac - sizeof(Actor)];
};
struct BRBL : public Actor {
    BRBL();
    u8 _pad[0x244 - sizeof(Actor)];
};
struct LIMT : public Actor {
    LIMT();
    u8 _pad[0x274 - sizeof(Actor)];
};
class GNL2 : public Actor {
public:
    GNL2();
    u8 _pad[0x2f8 - sizeof(Actor)];
};
class BEEE : public Actor {
public:
    BEEE();
    u8 _pad[0x3a0 - sizeof(Actor)];
};
struct PSSW : public Actor {
    PSSW();
    u8 _pad[0x230 - sizeof(Actor)];
};
class HOUS : public Actor {
public:
    HOUS();
    u8 _pad[0x3f8 - sizeof(Actor)];
};
class fn_80201A14_actor : public Actor {
public:
    fn_80201A14_actor();
    u8 _pad[0x338 - sizeof(Actor)];
};
struct GNON : public Actor {
    GNON();
    u8 _pad[0x33c - sizeof(Actor)];
};
struct BBMB : public Actor {
    BBMB();
    u8 _pad[0x26c - sizeof(Actor)];
};
struct BBSL : public Actor {
    BBSL();
    u8 _pad[0x258 - sizeof(Actor)];
};
struct GBAO : public Actor {
    GBAO();
    u8 _pad[0x244 - sizeof(Actor)];
};
struct OFFS : public Actor {
    OFFS();
    u8 _pad[0x240 - sizeof(Actor)];
};
struct LITS : public Actor {
    LITS();
    u8 _pad[0x264 - sizeof(Actor)];
};
struct STBL : public Actor {
    STBL();
    u8 _pad[0x274 - sizeof(Actor)];
};
class DGT2 : public Actor {
public:
    DGT2();
    u8 _pad[0x3cc - sizeof(Actor)];
};
struct RVFR : public Actor {
    RVFR();
    u8 _pad[0x25c - sizeof(Actor)];
};
struct WPPA : public Actor {
    WPPA();
    u8 _pad[0x234 - sizeof(Actor)];
};
struct FLYO : public Actor {
    FLYO();
    u8 _pad[0x28c - sizeof(Actor)];
};
class BPH2 : public Actor {
public:
    BPH2();
    u8 _pad[0x334 - sizeof(Actor)];
};
struct PRTC : public Actor {
    PRTC();
    u8 _pad[0x264 - sizeof(Actor)];
};
class RASN : public Actor {
public:
    RASN();
    u8 _pad[0x26c - sizeof(Actor)];
};
struct FGN2 : public Actor {
    FGN2();
    u8 _pad[0x318 - sizeof(Actor)];
};
struct WPPR : public Actor {
    WPPR();
    u8 _pad[0x27c - sizeof(Actor)];
};
struct JPEN : public Actor {
    JPEN();
    u8 _pad[0x284 - sizeof(Actor)];
};
class WNWN : public Actor {
public:
    WNWN();
    u8 _pad[0x390 - sizeof(Actor)];
};
struct URAC : public Actor {
    URAC();
    u8 _pad[0x230 - sizeof(Actor)];
};
struct VWMD : public Actor {
    VWMD();
    u8 _pad[0x234 - sizeof(Actor)];
};
struct TKRM : public Actor {
    TKRM();
    u8 _pad[0x238 - sizeof(Actor)];
};
struct BOTS : public Actor {
    BOTS();
    u8 _pad[0x248 - sizeof(Actor)];
};
struct TSNO : public Actor {
    TSNO();
    u8 _pad[0x2c0 - sizeof(Actor)];
};
struct FGVE : public Actor {
    FGVE();
    u8 _pad[0x24c - sizeof(Actor)];
};
struct YASI : public Actor {
    YASI();
    u8 _pad[0x238 - sizeof(Actor)];
};
struct BTIN : public Actor {
    BTIN();
    u8 _pad[0x25c - sizeof(Actor)];
};
struct FAGN : public Actor {
    FAGN();
    u8 _pad[0x264 - sizeof(Actor)];
};
struct GDMN : public Actor {
    GDMN();
    u8 _pad[0x274 - sizeof(Actor)];
};
struct RDVR : public Actor {
    RDVR();
    u8 _pad[0x278 - sizeof(Actor)];
};
struct DSIN : public Actor {
    DSIN();
    u8 _pad[0x248 - sizeof(Actor)];
};
class GROK : public Actor {
public:
    GROK();
    u8 _pad[0x320 - sizeof(Actor)];
};
struct SBTN : public Actor {
    SBTN();
    u8 _pad[0x240 - sizeof(Actor)];
};
struct CIRC : public Actor {
    CIRC();
    u8 _pad[0x27c - sizeof(Actor)];
};
struct FLYK : public Actor {
    FLYK();
    u8 _pad[0x244 - sizeof(Actor)];
};
struct PESW : public Actor {
    PESW();
    u8 _pad[0x250 - sizeof(Actor)];
};
class OSIN : public Actor {
public:
    OSIN();
    u8 _pad[0x29c - sizeof(Actor)];
};
struct PUKU : public Actor {
    PUKU();
    u8 _pad[0x27c - sizeof(Actor)];
};
struct SWBM : public Actor {
    SWBM();
    u8 _pad[0x260 - sizeof(Actor)];
};
struct INFR : public Actor {
    INFR();
    u8 _pad[0x26c - sizeof(Actor)];
};
extern "C" void* fn_801D30B8(void* this_);
// ItemBase-derived intermediate base (ctor fn_801D30B8, out-of-line dtor
// dtor_801D2C60 in tu_801D2C60; needs a C++ name before this TU can link).
class Fn801D30B8Base {
public:
    Fn801D30B8Base() { fn_801D30B8(this); }
    ~Fn801D30B8Base();
private:
    unsigned char pad[0x2ac];
};
class ARSH : public Fn801D30B8Base {
public:
    ARSH();
};
struct BMTY : public Actor {
    BMTY();
    u8 _pad[0x284 - sizeof(Actor)];
};
struct PCDM : public Actor {
    PCDM();
    u8 _pad[0x27c - sizeof(Actor)];
};
struct CRTL : public Actor {
    CRTL();
    u8 _pad[0x2cc - sizeof(Actor)];
};
struct RDBL : public Actor {
    RDBL();
    u8 _pad[0x248 - sizeof(Actor)];
};
struct ONOF : public Actor {
    ONOF();
    u8 _pad[0x25c - sizeof(Actor)];
};
struct OCFR : public Actor {
    OCFR();
    u8 _pad[0x258 - sizeof(Actor)];
};
struct BPRY : public Actor {
    BPRY();
    u8 _pad[0x270 - sizeof(Actor)];
};
struct LIF2 : public Actor {
    LIF2();
    u8 _pad[0x248 - sizeof(Actor)];
};
struct WDRY : public Actor {
    WDRY();
    u8 _pad[0x26c - sizeof(Actor)];
};
struct ESRY : public Actor {
    ESRY();
    u8 _pad[0x2a0 - sizeof(Actor)];
};
struct SHLT : public Actor {
    SHLT();
    u8 _pad[0x37c - sizeof(Actor)];
};
struct RANK : public Actor {
    RANK();
    u8 _pad[0x29c - sizeof(Actor)];
};
struct HNRY : public Actor {
    HNRY();
    u8 _pad[0x2bc - sizeof(Actor)];
};
struct BLDF : public Actor {
    BLDF();
    u8 _pad[0x248 - sizeof(Actor)];
};
struct FOCS : public Actor {
    FOCS();
    u8 _pad[0x244 - sizeof(Actor)];
};
struct PNPC : public Actor {
    PNPC();
    u8 _pad[0x258 - sizeof(Actor)];
};
struct RAIL : public Actor {
    RAIL();
    u8 _pad[0x230 - sizeof(Actor)];
};
// ItemBase-derived intermediate base (ctor fn_801D30B8, out-of-line dtor
// dtor_801D2C60 in tu_801D2C60; needs a C++ name before this TU can link).
class Fn801D30B8Base_191 {
public:
    Fn801D30B8Base_191() { fn_801D30B8(this); }
    ~Fn801D30B8Base_191();
private:
    unsigned char pad[0x2ac];
};
class ZNSH : public Fn801D30B8Base_191 {
public:
    ZNSH();
};
struct DOOR : public Actor {
    DOOR();
    u8 _pad[0x27c - sizeof(Actor)];
};
struct KEY0 : public Actor {
    KEY0();
    u8 _pad[0x2b8 - sizeof(Actor)];
};
struct LSTI : public Actor {
    LSTI();
    u8 _pad[0x274 - sizeof(Actor)];
};
struct WIZR : public Actor {
    WIZR();
    u8 _pad[0x30c - sizeof(Actor)];
};
struct SWNP : public Actor {
    SWNP();
    u8 _pad[0x268 - sizeof(Actor)];
};
struct CKSW : public Actor {
    CKSW();
    u8 _pad[0x238 - sizeof(Actor)];
};
class TNGL : public Actor {
public:
    TNGL();
    u8 _pad[0x2a0 - sizeof(Actor)];
};
struct STAL : public Actor {
    STAL();
    u8 _pad[0x284 - sizeof(Actor)];
};
struct WRTC : public Actor {
    WRTC();
    u8 _pad[0x250 - sizeof(Actor)];
};
struct LWSW : public Actor {
    LWSW();
    u8 _pad[0x258 - sizeof(Actor)];
};
struct BWRT : public Actor {
    BWRT();
    u8 _pad[0x2b8 - sizeof(Actor)];
};
struct BFIN : public Actor {
    BFIN();
    u8 _pad[0x248 - sizeof(Actor)];
};
struct WTSW : public Actor {
    WTSW();
    u8 _pad[0x258 - sizeof(Actor)];
};
struct ZNSW : public Actor {
    ZNSW();
    u8 _pad[0x260 - sizeof(Actor)];
};
struct LPLK : public Actor {
    LPLK();
    u8 _pad[0x268 - sizeof(Actor)];
};
struct IWAG : public Actor {
    IWAG();
    u8 _pad[0x238 - sizeof(Actor)];
};
struct OIWA : public Actor {
    OIWA();
    u8 _pad[0x260 - sizeof(Actor)];
};
struct NZMI : public Actor {
    NZMI();
    u8 _pad[0x248 - sizeof(Actor)];
};
struct BLZE : public Actor {
    BLZE();
    u8 _pad[0x2a0 - sizeof(Actor)];
};
struct FIRE : public Actor {
    FIRE();
    u8 _pad[0x294 - sizeof(Actor)];
};
struct NIWA : public Actor {
    NIWA();
    u8 _pad[0x304 - sizeof(Actor)];
};
struct BGWC : public Actor {
    BGWC();
    u8 _pad[0x234 - sizeof(Actor)];
};
struct DOSN : public Actor {
    DOSN();
    u8 _pad[0x234 - sizeof(Actor)];
};
struct TLK2 : public Actor {
    TLK2();
    u8 _pad[0x240 - sizeof(Actor)];
};
struct SLR4 : public Actor {
    SLR4();
    u8 _pad[0x2d0 - sizeof(Actor)];
};
struct SBAL : public Actor {
    SBAL();
    u8 _pad[0x270 - sizeof(Actor)];
};
struct SWEL : public Actor {
    SWEL();
    u8 _pad[0x250 - sizeof(Actor)];
};
struct LIFT : public Actor {
    LIFT();
    u8 _pad[0x240 - sizeof(Actor)];
};
struct RY02 : public Actor {
    RY02();
    u8 _pad[0x288 - sizeof(Actor)];
};
struct CRTH : public Actor {
    CRTH();
    u8 _pad[0x2b0 - sizeof(Actor)];
};
struct SWOR : public Actor {
    SWOR();
    u8 _pad[0x238 - sizeof(Actor)];
};
struct POPO : public Actor {
    POPO();
    u8 _pad[0x25c - sizeof(Actor)];
};
struct WOOD : public Actor {
    WOOD();
    u8 _pad[0x24c - sizeof(Actor)];
};
class fn_802032AC_actor : public Actor {
public:
    fn_802032AC_actor();
    u8 _pad[0x338 - sizeof(Actor)];
};
struct PEFF : public Actor {
    PEFF();
    u8 _pad[0x238 - sizeof(Actor)];
};
struct SLSD : public Actor {
    SLSD();
    u8 _pad[0x234 - sizeof(Actor)];
};
struct SSTN : public Actor {
    SSTN();
    u8 _pad[0x250 - sizeof(Actor)];
};
struct SKUL : public Actor {
    SKUL();
    u8 _pad[0x280 - sizeof(Actor)];
};
struct TALK : public Actor {
    TALK();
    u8 _pad[0x23c - sizeof(Actor)];
};
struct TRCH : public Actor {
    TRCH();
    u8 _pad[0x258 - sizeof(Actor)];
};
struct SCRE : public Actor {
    SCRE();
    u8 _pad[0x250 - sizeof(Actor)];
};
struct SPOT : public Actor {
    SPOT();
    u8 _pad[0x25c - sizeof(Actor)];
};
struct YAJI : public Actor {
    YAJI();
    u8 _pad[0x260 - sizeof(Actor)];
};
class BOME : public Actor {
public:
    BOME();
    u8 _pad[0x380 - sizeof(Actor)];
};
struct KMRI : public Actor {
    KMRI();
    u8 _pad[0x244 - sizeof(Actor)];
};
struct TFLR : public Actor {
    TFLR();
    u8 _pad[0x254 - sizeof(Actor)];
};
struct KNBN : public Actor {
    KNBN();
    u8 _pad[0x238 - sizeof(Actor)];
};
struct PLAS : public Actor {
    PLAS();
    u8 _pad[0x238 - sizeof(Actor)];
};
struct ITMS : public Actor {
    ITMS();
    u8 _pad[0x244 - sizeof(Actor)];
};
struct Poon : public Actor {
    Poon();
    u8 _pad[0x284 - sizeof(Actor)];
};
struct SKIL : public Actor {
    SKIL();
    u8 _pad[0x248 - sizeof(Actor)];
};
struct MOZO : public Actor {
    MOZO();
    u8 _pad[0x270 - sizeof(Actor)];
};
struct BERY : public Actor {
    BERY();
    u8 _pad[0x2a8 - sizeof(Actor)];
};
struct PONT : public Actor {
    PONT();
    u8 _pad[0x244 - sizeof(Actor)];
};
struct ARRW : public Actor {
    ARRW();
    u8 _pad[0x280 - sizeof(Actor)];
};
struct TRAP : public Actor {
    TRAP();
    u8 _pad[0x280 - sizeof(Actor)];
};
struct THRN : public Actor {
    THRN();
    u8 _pad[0x23c - sizeof(Actor)];
};
struct SWEV : public Actor {
    SWEV();
    u8 _pad[0x33c - sizeof(Actor)];
};
struct BALL : public Actor {
    BALL();
    u8 _pad[0x248 - sizeof(Actor)];
};
class BPOH : public Actor {
public:
    BPOH();
    u8 _pad[0x300 - sizeof(Actor)];
};
struct SHTR : public Actor {
    SHTR();
    u8 _pad[0x248 - sizeof(Actor)];
};
struct EZRY : public Actor {
    EZRY();
    u8 _pad[0x298 - sizeof(Actor)];
};
struct SWT4 : public Actor {
    SWT4();
    u8 _pad[0x254 - sizeof(Actor)];
};
struct RYRN : public Actor {
    RYRN();
    u8 _pad[0x250 - sizeof(Actor)];
};
struct MTBO : public Actor {
    MTBO();
    u8 _pad[0x23c - sizeof(Actor)];
};
struct TKYU : public Actor {
    TKYU();
    u8 _pad[0x24c - sizeof(Actor)];
};
struct FLME : public Actor {
    FLME();
    u8 _pad[0x274 - sizeof(Actor)];
};
struct KETH : public Actor {
    KETH();
    u8 _pad[0x28c - sizeof(Actor)];
};
struct BOYO : public Actor {
    BOYO();
    u8 _pad[0x278 - sizeof(Actor)];
};
struct IMUP : public Actor {
    IMUP();
    u8 _pad[0x2b4 - sizeof(Actor)];
};
struct TKTA : public Actor {
    TKTA();
    u8 _pad[0x264 - sizeof(Actor)];
};
struct EXPL : public Actor {
    EXPL();
    u8 _pad[0x23c - sizeof(Actor)];
};
struct SLR1 : public Actor {
    SLR1();
    u8 _pad[0x2c8 - sizeof(Actor)];
};
struct SWTH : public Actor {
    SWTH();
    u8 _pad[0x268 - sizeof(Actor)];
};
struct HBMB : public Actor {
    HBMB();
    u8 _pad[0x29c - sizeof(Actor)];
};
struct HINO : public Actor {
    HINO();
    u8 _pad[0x288 - sizeof(Actor)];
};
class GOAL : public Actor {
public:
    GOAL();
    u8 _pad[0x320 - sizeof(Actor)];
};
struct BHRT : public Actor {
    BHRT();
    u8 _pad[0x23c - sizeof(Actor)];
};
class DGTL : public Actor {
public:
    DGTL();
    u8 _pad[0x7c8 - sizeof(Actor)];
};
struct OKTM : public Actor {
    OKTM();
    u8 _pad[0x260 - sizeof(Actor)];
};
struct HART : public Actor {
    HART();
    u8 _pad[0x244 - sizeof(Actor)];
};
struct GNLD : public Actor {
    GNLD();
    u8 _pad[0x258 - sizeof(Actor)];
};
struct DBRK : public Actor {
    DBRK();
    u8 _pad[0x258 - sizeof(Actor)];
};
struct BZBR : public Actor {
    BZBR();
    u8 _pad[0x264 - sizeof(Actor)];
};
struct BLCK : public Actor {
    BLCK();
    u8 _pad[0x250 - sizeof(Actor)];
};
struct PEAC : public Actor {
    PEAC();
    u8 _pad[0x24c - sizeof(Actor)];
};
struct TUBO : public Actor {
    TUBO();
    u8 _pad[0x258 - sizeof(Actor)];
};
struct ROCK : public Actor {
    ROCK();
    u8 _pad[0x238 - sizeof(Actor)];
};
struct WARP : public Actor {
    WARP();
    u8 _pad[0x28c - sizeof(Actor)];
};
struct BORD : public Actor {
    BORD();
    u8 _pad[0x238 - sizeof(Actor)];
};
struct STON : public Actor {
    STON();
    u8 _pad[0x238 - sizeof(Actor)];
};
struct GENE : public Actor {
    GENE();
    u8 _pad[0x678 - sizeof(Actor)];
};
struct FGAS : public Actor {
    FGAS();
    u8 _pad[0x248 - sizeof(Actor)];
};
struct POOH : public Actor {
    POOH();
    u8 _pad[0x278 - sizeof(Actor)];
};
struct AMOS : public Actor {
    AMOS();
    u8 _pad[0x32c - sizeof(Actor)];
};
struct OKTA : public Actor {
    OKTA();
    u8 _pad[0x288 - sizeof(Actor)];
};
struct RUPY : public Actor {
    RUPY();
    u8 _pad[0x2a8 - sizeof(Actor)];
};
struct Jiji {
    Jiji();
    u8 _pad[0x27c];
};
struct WLFT {
    WLFT();
    u8 _pad[0x2a8];
};
struct fn_801070B4_actor {
    fn_801070B4_actor();
    u8 _pad[0x248];
};
struct fn_801087F4_actor {
    fn_801087F4_actor();
    u8 _pad[0x270];
};
struct fn_801092B0_actor {
    fn_801092B0_actor();
    u8 _pad[0x284];
};
extern "C" void fn_801D267C(void* p);
extern "C" void fn_8010E074(void* p);
extern "C" void dtor_80105D80(void* p, s16 f);
extern "C" void dtor_8010E004(void* p, s16 f);
extern "C" void __ct__5ActorFv(void* p);
extern "C" void __dt__5ActorFv(void* p, int f);
extern const f32 lbl_8053F830;

// Sub-object (ctor fn_801D267C, dtor dtor_80105D80; holds a J3DFrameCtrl at +0x24).
struct AnimSub {
    AnimSub() { fn_801D267C(this); }
    ~AnimSub() { dtor_80105D80(this, -1); }
    u8 pad[0x38];
};
struct AnimSubRaw {
    u8 pad[0x38];
};
// Same sub-object, viewed without a dtor.
struct AnimSubNoDtor {
    AnimSubNoDtor() { fn_801D267C(this); }
    u8 pad[0x38];
};
// Plain Actor base (0x801F5AE0 ctor / 0x801F593C dtor).
struct ActorB {
    ActorB() { __ct__5ActorFv(this); }
    ~ActorB() { __dt__5ActorFv(this, 0); }
    u8 pad[0x230];
};
struct ActorBNoDtor {
    ActorBNoDtor() { __ct__5ActorFv(this); }
    u8 pad[0x230];
};
// Actor subclass ctor 0x8010E074 (vtable lbl_8049D140, dtor 0x8010E004).
struct Base_8010E074 {
    Base_8010E074() { fn_8010E074(this); }
    ~Base_8010E074() { dtor_8010E004(this, -1); }
    u8 pad[0x230];
};

struct DMGA : Base_8010E074 {
    DMGA();
    u8 m230;
    u32 m234;
    f32 m238, m23C;
    u8 m240[0x34];
    AnimSubRaw m274;
};
struct OPGA : ActorBNoDtor {
    OPGA();
    u8 m230, m231;
    u32 m234, m238;
    s32 m23C, m240;
    AnimSubRaw m244;
    AnimSubRaw m27C;
};
struct DMNR : Base_8010E074 {
    DMNR();
    u32 m230;
    f32 m234, m238;
    u32 m23C;
};
struct Dbms {
    Dbms();
    u8 _pad[0x268];
};
struct Twtg {
    Twtg();
    u8 _pad[0x27c];
};
struct Ftgl {
    Ftgl();
    u8 _pad[0x274];
};
struct CRNV : ActorB {
    CRNV();
    u32 m230, m234;
    s32 m238;
    f32 m23C;
    AnimSubRaw m240;
    u32 m278, m27C;
};
struct Znlj {
    Znlj();
    u8 _pad[0x2c4];
};
// ---- Actor factory ----
class JKRHeap;
void* operator new(unsigned long size, JKRHeap* heap, int align);

struct QuadHalf {
    QuadHalf() {}
    f32 x, y;
};
struct Quad {
    Quad() {}
    QuadHalf a, b;
};
struct Vec4f { f32 x, y, z, w; };

// Virtual view of an actor (only slot 1 is called here).
struct ActorVt {
    virtual void v00();
    virtual void v01();
};

// Per-slot helper at ActorMgr+0x100C (0x80457840 attaches a position to it).
struct ActorSlotLink;

struct ActorMgr {
    /* 0x0000 */ u32 field_0;
    /* 0x0004 */ JKRHeap* heap;
    /* 0x0008 */ Actor* actors[0x400];
    /* 0x1008 */ s32 maxUsed;
    /* 0x100C */ ActorSlotLink* links[0x400];
    /* 0x200C */ u32 field_200C;
    /* 0x2010 */ s32 serial;
    /* 0x2014 */ s32 lastIndex;
};

extern "C" Vec4f* fn_801FF654(Actor* a);
extern "C" Vec4f* fn_801FF65C(Actor* a);
extern "C" void fn_801FF664(Actor* a, s32 v);
extern "C" void fn_801FF66C(Actor* a, u32 v);
extern "C" u32 fn_801FF674(void);
extern "C" void fn_801FF698(Actor* a, s32 v);
extern "C" void fn_801FF6A0(Actor* a, s32 v);
extern "C" void fn_801FF6A8(Actor* a, s32 v);
extern "C" void fn_801FF6B0(Actor* a, s32 v);
extern "C" void fn_801FF6B8(Actor* a, u8 v);
extern "C" void fn_801FF6C0(Actor* a, s32 v);
extern "C" void fn_801FF6C8(Actor* a, s32 v);
extern "C" void fn_801FF6D0(Actor* a, u32 v);
extern "C" void fn_801FF6D8(Actor* a, s32 v);
extern "C" void fn_801FF6E0(Actor* a, s32 v);
extern "C" void fn_801FF6E8(Actor* a, s32 v);
extern "C" void fn_801FF6F0(Actor* a, Vec* v);
extern "C" void fn_801FF720(Actor* a, s32 v);
extern "C" void fn_801FF728(Actor* a, s32 v);
extern "C" Vec* fn_801FF730(Actor* a);
extern "C" void fn_801FF738(ActorSlotLink* l);
extern "C" void fn_80457840(ActorSlotLink* l, Vec* pos);
extern "C" void fn_8018A588(Actor* a, s32 v);
extern "C" s32 fn_801F620C(ActorMgr* mgr, s32 id, u32 tag);
extern "C" void* fn_802D6A9C(void);
extern "C" u32 fn_802D39FC(void* room);
extern const f32 lbl_8053F830;

extern "C" s32 Actor_CreateByID(ActorMgr* mgr, s32 id, s32 owner, Vec* pos, u32 param, s32 a7, s32 a8) {
    s32 result = -1;
    for (s32 i = 0; i < 0x400; i++) {
        if (mgr->actors[i] != 0) {
            continue;
        }
        switch (id) {
        case 'RUPY':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) RUPY;
            break;
        case 'OKTA':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) OKTA;
            break;
        case 'AMOS':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) AMOS;
            break;
        case 'POOH':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) POOH;
            break;
        case 'GRAS':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) FGAS;
            break;
        case 'GENE':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) GENE;
            break;
        case 'STON':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) STON;
            break;
        case 'BORD':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BORD;
            break;
        case 'WARP':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) WARP;
            break;
        case 'ROCK':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ROCK;
            break;
        case 'TUBO':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TUBO;
            break;
        case 'PEAC':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) PEAC;
            break;
        case 'BLCK':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BLCK;
            break;
        case 'BZBR':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BZBR;
            break;
        case 'DDRK':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) DBRK;
            break;
        case 'GOLD':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) GNLD;
            break;
        case 'HART':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) HART;
            break;
        case 'OKTM':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) OKTM;
            break;
        case 'DGTL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) DGTL;
            break;
        case 'BHRT':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BHRT;
            break;
        case 'GOAL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) GOAL;
            break;
        case 'HINO':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) HINO;
            break;
        case 'HBMB':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) HBMB;
            break;
        case 'SWTH':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SWTH;
            break;
        case 'SLR1':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SLR1;
            break;
        case 'EXPL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) EXPL;
            break;
        case 'TKTA':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TKTA;
            break;
        case 'SLR2':
            {
                void* p = operator new(0x2c4, mgr->heap, 0);
                if (p) p = fn_80203BF0(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'IMUP':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) IMUP;
            break;
        case 'BOYO':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BOYO;
            break;
        case 'KETH':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) KETH;
            break;
        case 'FLME':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) FLME;
            break;
        case 'JIJI':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) Jiji;
            break;
        case 'TKYU':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TKYU;
            break;
        case 'MTBO':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) MTBO;
            break;
        case 'RYRN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) RYRN;
            break;
        case 'SWT4':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SWT4;
            break;
        case 'FARY':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) EZRY;
            break;
        case 'SHTR':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SHTR;
            break;
        case 'BPOH':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BPOH;
            break;
        case 'BALL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BALL;
            break;
        case 'SWEV':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SWEV;
            break;
        case 'THRN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) THRN;
            break;
        case 'TRAP':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TRAP;
            break;
        case 'ARRW':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ARRW;
            break;
        case 'PONT':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) PONT;
            break;
        case 'BFRY':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BERY;
            break;
        case 'MOZO':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) MOZO;
            break;
        case 'SKIL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SKIL;
            break;
        case 'Poon':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) Poon;
            break;
        case 'ITMS':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ITMS;
            break;
        case 'PLAS':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) PLAS;
            break;
        case 'KNBN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) KNBN;
            break;
        case 'TFLR':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TFLR;
            break;
        case 'KMRI':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) KMRI;
            break;
        case 'BOME':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BOME;
            break;
        case 'YAJI':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) YAJI;
            break;
        case 'SPOT':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SPOT;
            break;
        case 'SCRE':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SCRE;
            break;
        case 'TRCH':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TRCH;
            break;
        case 'TALK':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TALK;
            break;
        case 'SKUL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SKUL;
            break;
        case 'SSTN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SSTN;
            break;
        case 'SLSD':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SLSD;
            break;
        case 'PEFF':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) PEFF;
            break;
        case 'SLR3':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) fn_802032AC_actor;
            break;
        case 'WOOD':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) WOOD;
            break;
        case 'POPO':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) POPO;
            break;
        case 'SWOR':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SWOR;
            break;
        case 'DETH':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) CRTH;
            break;
        case 'RY02':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) RY02;
            break;
        case 'LIFT':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) LIFT;
            break;
        case 'SWEL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SWEL;
            break;
        case 'SBAL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SBAL;
            break;
        case 'SLR4':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SLR4;
            break;
        case 'TLK2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TLK2;
            break;
        case 'DOSN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) DOSN;
            break;
        case 'BGWC':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BGWC;
            break;
        case 'NIWA':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) NIWA;
            break;
        case 'FIRE':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) FIRE;
            break;
        case 'BLZE':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BLZE;
            break;
        case 'NZMI':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) NZMI;
            break;
        case 'ROPE':
            {
                void* p = operator new(0x2a8, mgr->heap, 0);
                if (p) p = fn_801B7DE0(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'OIWA':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) OIWA;
            break;
        case 'IWAG':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) IWAG;
            break;
        case 'LPLK':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) LPLK;
            break;
        case 'PAME':
            {
                void* p = operator new(0x2ac, mgr->heap, 0);
                if (p) p = fn_801B94C8(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'ZNSW':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ZNSW;
            break;
        case 'WTSW':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) WTSW;
            break;
        case 'BFIN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BFIN;
            break;
        case 'BWRT':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BWRT;
            break;
        case 'LWSW':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) LWSW;
            break;
        case 'WRTC':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) WRTC;
            break;
        case 'STAL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) STAL;
            break;
        case 'TNGL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TNGL;
            break;
        case 'CKSW':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) CKSW;
            break;
        case 'MIRA':
            {
                void* p = operator new(0x2a8, mgr->heap, 0);
                if (p) p = fn_801BA3FC(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'SWNP':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SWNP;
            break;
        case 'WIZR':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) WIZR;
            break;
        case 'LSTI':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) LSTI;
            break;
        case 'KEY0':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) KEY0;
            break;
        case 'DOOR':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) DOOR;
            break;
        case 'ZORA':
            {
                void* p = operator new(0x2ac, mgr->heap, 0);
                if (p) p = fn_801BB3B0(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'ZOSH':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ZNSH;
            break;
        case 'BOGF':
            {
                void* p = operator new(0x618, mgr->heap, 0);
                if (p) p = fn_801D686C(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'RAIL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) RAIL;
            break;
        case 'FALL':
            {
                void* p = operator new(0x2f0, mgr->heap, 0);
                if (p) p = fn_801BCCF0(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'PNPC':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) PNPC;
            break;
        case 'FOCS':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) FOCS;
            break;
        case 'BLDF':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BLDF;
            break;
        case 'HNRY':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) HNRY;
            break;
        case 'RANK':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) RANK;
            break;
        case 'SHLT':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SHLT;
            break;
        case 'ESRY':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ESRY;
            break;
        case 'TZOK':
            {
                void* p = operator new(0x388, mgr->heap, 0);
                if (p) p = fn_80206810(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'WDRY':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) WDRY;
            break;
        case 'LIF2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) LIF2;
            break;
        case 'BRRY':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BPRY;
            break;
        case 'FBMR':
            {
                void* p = operator new(0x300, mgr->heap, 0);
                if (p) p = fn_801BD640(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'FBOB':
            {
                void* p = operator new(0x2b0, mgr->heap, 0);
                if (p) p = fn_801BDBF0(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'TINK':
            {
                void* p = operator new(0x2d4, mgr->heap, 0);
                if (p) p = fn_801E22A4(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'TINB':
            {
                void* p = operator new(0x2a8, mgr->heap, 0);
                if (p) p = fn_801E33B8(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'OCFR':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) OCFR;
            break;
        case 'ONOF':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ONOF;
            break;
        case 'RDBL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) RDBL;
            break;
        case 'CRTL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) CRTL;
            break;
        case 'PCDM':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) PCDM;
            break;
        case 'BOIC':
            {
                void* p = operator new(0x340, mgr->heap, 0);
                if (p) p = fn_801DA504(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'BMTY':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BMTY;
            break;
        case 'RUSA':
            {
                void* p = operator new(0x3b4, mgr->heap, 0);
                if (p) p = fn_80212800(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'ARIJ':
            {
                void* p = operator new(0x2a8, mgr->heap, 0);
                if (p) p = fn_80213BA0(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'ARSH':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ARSH;
            break;
        case 'INFR':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) INFR;
            break;
        case 'CLOD':
            {
                void* p = operator new(0x3ac, mgr->heap, 0);
                if (p) p = fn_80105BEC(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'SWBM':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SWBM;
            break;
        case 'PUKU':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) PUKU;
            break;
        case 'OSIN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) OSIN;
            break;
        case 'BMST':
            {
                void* p = operator new(0x2b8, mgr->heap, 0);
                if (p) p = fn_801BEB44(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'LNBM':
            {
                void* p = operator new(0x2ac, mgr->heap, 0);
                if (p) p = fn_801BF5A8(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'WLFT':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) WLFT;
            break;
        case 'PLSW':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) PESW;
            break;
        case 'FGAN':
            {
                void* p = operator new(0x2e0, mgr->heap, 0);
                if (p) p = fn_80202444(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'SLK2':
            {
                void* p = operator new(0x5b4, mgr->heap, 0);
                if (p) p = fn_801C573C(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'WIND':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) fn_801070B4_actor;
            break;
        case 'FLYK':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) FLYK;
            break;
        case 'CNON':
            {
                void* p = operator new(0x294, mgr->heap, 0);
                if (p) p = fn_80108168(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'DEAL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) fn_801087F4_actor;
            break;
        case 'SITM':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) fn_801092B0_actor;
            break;
        case 'CIRC':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) CIRC;
            break;
        case 'SBTN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SBTN;
            break;
        case 'GROK':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) GROK;
            break;
        case 'DSIN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) DSIN;
            break;
        case 'RIVR':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) RDVR;
            break;
        case 'GDMN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) GDMN;
            break;
        case 'FAGN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) FAGN;
            break;
        case 'ZLDA':
            {
                void* p = operator new(0x374, mgr->heap, 0);
                if (p) p = fn_8010AFC4(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'ICCL':
            {
                void* p = operator new(0x280, mgr->heap, 0);
                if (p) p = fn_8010C00C(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'SNBL':
            {
                void* p = operator new(0x380, mgr->heap, 0);
                if (p) p = fn_8010D7A0(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'DBMS':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) Dbms;
            break;
        case 'BTIN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BTIN;
            break;
        case 'YASI':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) YASI;
            break;
        case 'GRVE':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) FGVE;
            break;
        case 'TSNO':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TSNO;
            break;
        case 'BOTS':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BOTS;
            break;
        case 'TNDR':
            {
                void* p = operator new(0x2d0, mgr->heap, 0);
                if (p) p = fn_801C0AD8(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'TKRM':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TKRM;
            break;
        case 'VWMD':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) VWMD;
            break;
        case 'URAC':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) URAC;
            break;
        case 'WNWN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) WNWN;
            break;
        case 'SLGE':
            {
                void* p = operator new(0x438, mgr->heap, 0);
                if (p) p = fn_801C2414(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'JPEN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) JPEN;
            break;
        case 'WPPR':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) WPPR;
            break;
        case 'FGN2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) FGN2;
            break;
        case 'RASN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) RASN;
            break;
        case 'PRTC':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) PRTC;
            break;
        case 'DMZL':
            {
                void* p = operator new(0x388, mgr->heap, 0);
                if (p) p = fn_80112070(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'DMMD':
            {
                void* p = operator new(0x2a4, mgr->heap, 0);
                if (p) p = fn_801134DC(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'DMCR':
            {
                void* p = operator new(0x2f0, mgr->heap, 0);
                if (p) p = fn_80115590(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'DMGF':
            {
                void* p = operator new(0x330, mgr->heap, 0);
                if (p) p = fn_80116BE8(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'DMSW':
            {
                void* p = operator new(0x2ac, mgr->heap, 0);
                if (p) p = fn_801180D0(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'BPH2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BPH2;
            break;
        case 'DMCT':
            {
                void* p = operator new(0x23c, mgr->heap, 0);
                if (p) p = fn_8011A248(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'FLYO':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) FLYO;
            break;
        case 'WPPA':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) WPPA;
            break;
        case 'RVFR':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) RVFR;
            break;
        case 'DGT2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) DGT2;
            break;
        case 'DMGL':
            {
                void* p = operator new(0x294, mgr->heap, 0);
                if (p) p = fn_8011B0DC(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'DMLK':
            {
                void* p = operator new(0x290, mgr->heap, 0);
                if (p) p = fn_8011CC2C(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'BGBL':
            {
                void* p = operator new(0x2b0, mgr->heap, 0);
                if (p) p = fn_801D8194(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'DMGA':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) DMGA;
            break;
        case 'STBL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) STBL;
            break;
        case 'LOTS':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) LITS;
            break;
        case 'ICHL':
            {
                void* p = operator new(0x2e8, mgr->heap, 0);
                if (p) p = fn_801DBFB0(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'ICWL':
            {
                void* p = operator new(0x280, mgr->heap, 0);
                if (p) p = fn_8011E6E0(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'BLZD':
            {
                void* p = operator new(0x240, mgr->heap, 0);
                if (p) p = fn_80201BF0(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'BOIT':
            {
                void* p = operator new(0x2ac, mgr->heap, 0);
                if (p) p = fn_801DCA30(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'LTZR':
            {
                void* p = operator new(0x2bc, mgr->heap, 0);
                if (p) p = fn_80340C60(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'OFFS':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) OFFS;
            break;
        case 'GBAO':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) GBAO;
            break;
        case 'BOIB':
            {
                void* p = operator new(0x2b0, mgr->heap, 0);
                if (p) p = fn_801DCF40(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'GEN2':
            {
                void* p = operator new(0x250, mgr->heap, 0);
                if (p) p = fn_80201B3C(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'BBSL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BBSL;
            break;
        case 'BBMB':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BBMB;
            break;
        case 'GNON':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) GNON;
            break;
        case 'ZLD2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) fn_80201A14_actor;
            break;
        case 'HOUS':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) HOUS;
            break;
        case 'PSSW':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) PSSW;
            break;
        case 'BEEE':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BEEE;
            break;
        case 'GOL2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) GNL2;
            break;
        case 'NAVI':
            {
                void* p = operator new(0x2d8, mgr->heap, 0);
                if (p) p = fn_8021EDC0(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'KEPO':
            {
                void* p = operator new(0x2dc, mgr->heap, 0);
                if (p) p = fn_8021A2D0(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'LIMT':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) LIMT;
            break;
        case 'BRBL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BRBL;
            break;
        case 'IPOT':
            {
                void* p = operator new(0x2b8, mgr->heap, 0);
                if (p) p = fn_801E78F0(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'FSPO':
            {
                void* p = operator new(0x2a8, mgr->heap, 0);
                if (p) p = fn_801E7DBC(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'FSOB':
            {
                void* p = operator new(0x3c4, mgr->heap, 0);
                if (p) p = fn_801E9850(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'HAYA':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) GSYA;
            break;
        case 'SENP':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SENP;
            break;
        case 'RNSW':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) RNSW;
            break;
        case 'SEV2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SEV2;
            break;
        case 'BARI':
            {
                void* p = operator new(0x258, mgr->heap, 0);
                if (p) p = fn_8011FD28(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'BLZ2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BLZ2;
            break;
        case 'FAZR':
            {
                void* p = operator new(0x3d4, mgr->heap, 0);
                if (p) p = fn_80121164(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'OPGL':
            {
                void* p = operator new(0x3d4, mgr->heap, 0);
                if (p) p = fn_801258D8(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'OPGA':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) OPGA;
            break;
        case 'GFBS':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) GFBS;
            break;
        case 'MGYA':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) MGYA;
            break;
        case 'FZRA':
            {
                void* p = operator new(0x384, mgr->heap, 0);
                if (p) p = fn_80127B48(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'BGMN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BGMN;
            break;
        case 'ZOOM':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ZOOM;
            break;
        case 'ALCE':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ALCE;
            break;
        case 'FISH':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) FISH;
            break;
        case 'DMGE':
            {
                void* p = operator new(0x244, mgr->heap, 0);
                if (p) p = fn_802014C8(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'ANHO':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ANHO;
            break;
        case 'SYKY':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SYKY;
            break;
        case 'NNJN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) NNJN;
            break;
        case 'SZSC':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SZSC;
            break;
        case 'DMNR':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) DMNR;
            break;
        case 'SPBG':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SPBG;
            break;
        case 'FORM':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) FORM;
            break;
        case 'HRMN':
            {
                void* p = operator new(0x35c, mgr->heap, 0);
                if (p) p = fn_801ED144(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'WAVE':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) WAVE;
            break;
        case 'TENN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TENN;
            break;
        case 'CRGN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) CRGN;
            break;
        case 'SEN2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SEN2;
            break;
        case 'RNBW':
            {
                void* p = operator new(0x250, mgr->heap, 0);
                if (p) p = fn_8012A364(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'FOBE':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) FOBE;
            break;
        case 'BEMN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BEMN;
            break;
        case 'FOSL':
            {
                void* p = operator new(0x2d0, mgr->heap, 0);
                if (p) p = fn_8020B0B8(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'SLMN':
            {
                void* p = operator new(0x34c, mgr->heap, 0);
                if (p) p = fn_80208BE0(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'FOBR':
            {
                void* p = operator new(0x2ac, mgr->heap, 0);
                if (p) p = fn_8020BE40(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'BRMN':
            {
                void* p = operator new(0x370, mgr->heap, 0);
                if (p) p = fn_802095C4(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'SSLF':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SSLF;
            break;
        case 'PNP2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) PNP2;
            break;
        case 'ENBZ':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ENBZ;
            break;
        case 'HTMK':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) HTMK;
            break;
        case 'MJGR':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) MJGR;
            break;
        case 'SAYA':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) RYYA;
            break;
        case 'NWOK':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) NWOK;
            break;
        case 'HBB2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) HBB2;
            break;
        case 'ENPC':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ENPC;
            break;
        case 'EZLD':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) EZLD;
            break;
        case 'EMIK':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) EMIK;
            break;
        case 'GLBS':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) GLBS;
            break;
        case 'LCLS':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) LCLS;
            break;
        case 'ENDM':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ENDM;
            break;
        case 'DDGO':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) DDGO;
            break;
        case 'GOMA':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) GNMA;
            break;
        case 'TTAT':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TTAT;
            break;
        case 'OKAM':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) OKAM;
            break;
        case 'TKRA':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TKRA;
            break;
        case 'DTLK':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) DTLK;
            break;
        case 'ELNK':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ELNK;
            break;
        case 'SMRI':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SMRI;
            break;
        case 'ZASL':
            {
                void* p = operator new(0x2b0, mgr->heap, 0);
                if (p) p = fn_8020CA34(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'DMTW':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) DMTW;
            break;
        case 'EOWL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) EOWL;
            break;
        case 'RCK2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) RCK2;
            break;
        case 'EETC':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) EETC;
            break;
        case 'TWTG':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) Twtg;
            break;
        case 'GMBL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) GMBL;
            break;
        case 'GMTB':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) GMTB;
            break;
        case 'FLOR':
            {
                void* p = operator new(0x2c4, mgr->heap, 0);
                if (p) p = fn_8020F510(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'YNSW':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) YNSW;
            break;
        case 'EGOL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) EGOL;
            break;
        case 'GEN3':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) GEN3;
            break;
        case 'OBLF':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) OBLF;
            break;
        case 'ZLD3':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ZLD3;
            break;
        case 'ZLD4':
            {
                void* p = operator new(0x344, mgr->heap, 0);
                if (p) p = fn_80200764(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'ZDCO':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ZDCO;
            break;
        case 'IBBM':
            {
                void* p = operator new(0x2b8, mgr->heap, 0);
                if (p) p = fn_802103C0(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'ZOMO':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ZOMO;
            break;
        case 'DNAV':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) DNAV;
            break;
        case 'DCR2':
            {
                void* p = operator new(0x414, mgr->heap, 0);
                if (p) p = fn_8036C750(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'SVTG':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SPTG;
            break;
        case 'BTBZ':
            {
                void* p = operator new(0x240, mgr->heap, 0);
                if (p) p = fn_8012D848(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'BCK2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) BCK2;
            break;
        case 'SDSM':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SDSM;
            break;
        case 'SLEF':
            {
                void* p = operator new(0x2a8, mgr->heap, 0);
                if (p) p = fn_80213FE4(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'MEDM':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) MEDM;
            break;
        case 'TOMI':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SSMI;
            break;
        case 'STPN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) STPN;
            break;
        case 'GNEF':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) GNEF;
            break;
        case 'PSW2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) PSW2;
            break;
        case 'RBPN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) RBPN;
            break;
        case 'JWLK':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) JWLK;
            break;
        case 'TLWP':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TLWP;
            break;
        case 'CHSW':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) CHSW;
            break;
        case 'TOOI':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TOOI;
            break;
        case 'DWAP':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) DWAP;
            break;
        case 'TWEV':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TWEV;
            break;
        case 'SNWL':
            {
                void* p = operator new(0x248, mgr->heap, 0);
                if (p) p = fn_8012E780(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'FDWP':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) FDWP;
            break;
        case 'SAFU':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SAFU;
            break;
        case 'TMI2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TMI2;
            break;
        case 'SVGT':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SVGT;
            break;
        case 'AGBW':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) AGBW;
            break;
        case 'THCL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) THCL;
            break;
        case 'LFGN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) LFGN;
            break;
        case 'LEAF':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) LEAF;
            break;
        case 'TUGF':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TUGF;
            break;
        case 'TUTL':
            {
                void* p = operator new(0x26c, mgr->heap, 0);
                if (p) p = fn_80200060(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'TUTM':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TUTM;
            break;
        case 'EMSK':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ELSK;
            break;
        case 'IFCK':
            {
                void* p = operator new(0x238, mgr->heap, 0);
                if (p) p = fn_8012F178(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'ICOB':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ICOB;
            break;
        case 'OGST':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) OGST;
            break;
        case 'RSNP':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) RSNP;
            break;
        case 'LTEV':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) FOEV;
            break;
        case 'MRMT':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) MRMT;
            break;
        case 'FBGE':
            {
                void* p = operator new(0x2ac, mgr->heap, 0);
                if (p) p = fn_8021D4CC(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'FBAL':
            {
                void* p = operator new(0x2b0, mgr->heap, 0);
                if (p) p = fn_80220378(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'PTMI':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) PTMI;
            break;
        case 'ELK2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ELK2;
            break;
        case 'FGAL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) fn_801FFD58_actor;
            break;
        case 'RCK3':
            {
                void* p = operator new(0x268, mgr->heap, 0);
                if (p) p = fn_801FFD1C(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'FTGL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) Ftgl;
            break;
        case 'SWDL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SWDL;
            break;
        case 'WPCN':
            {
                void* p = operator new(0x29c, mgr->heap, 0);
                if (p) p = fn_80131AF0(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'MRTA':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) MRTA;
            break;
        case 'TJIJ':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TJIJ;
            break;
        case 'SNPC':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SNPC;
            break;
        case 'GLWP':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) GEWP;
            break;
        case 'SPFR':
            {
                void* p = operator new(0x28c, mgr->heap, 0);
                if (p) p = fn_801336B4(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'PSWB':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) PSWB;
            break;
        case 'SIBT':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) SIBT;
            break;
        case 'PSWK':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) PSWK;
            break;
        case 'LOSW':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) LOSW;
            break;
        case 'TFL2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TFL2;
            break;
        case 'ENDR':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ENDR;
            break;
        case 'JPE2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) JPE2;
            break;
        case 'DMYK':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) DMYK;
            break;
        case 'ICEB':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) ICEB;
            break;
        case 'TBGN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TBGN;
            break;
        case 'TBO2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) TBO2;
            break;
        case 'CRNV':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) CRNV;
            break;
        case 'ZSLJ':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) Znlj;
            break;
        case 'ZSLH':
            {
                void* p = operator new(0x2d4, mgr->heap, 0);
                if (p) p = fn_80222190(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'ZSLA':
            {
                void* p = operator new(0x2c0, mgr->heap, 0);
                if (p) p = fn_80222A58(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'ZSLF':
            {
                void* p = operator new(0x2bc, mgr->heap, 0);
                if (p) p = fn_8022313C(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'ZSLD':
            {
                void* p = operator new(0x2c4, mgr->heap, 0);
                if (p) p = fn_80224084(p);
                mgr->actors[i] = (Actor*)p;
            }
            break;
        case 'PSS2':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) PSS2;
            break;
        case 'WPWL':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) WPWL;
            break;
        case 'RINS':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) RINS;
            break;
        case 'STGN':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) STGN;
            break;
        case 'MRTC':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) MRTC;
            break;
        case 'GSCK':
            mgr->actors[i] = (Actor*)new (mgr->heap, 0) GSCK;
            break;
        case 'DMCS':
        case 'FGAM':
        case 'ZSLE':
        case 'ZSLG':
            break;
        }
        if (mgr->actors[i] == 0) {
            return -1;
        }
        fn_801FF738(mgr->links[i]);
        fn_80457840(mgr->links[i], fn_801FF730(mgr->actors[i]));
        fn_801FF728(mgr->actors[i], mgr->serial);
        fn_801FF720(mgr->actors[i], i);
        mgr->actors[i]->setPos(*(JGeometry::TVec3<f32>*)pos);
        fn_801FF6F0(mgr->actors[i], pos);
        fn_801FF6E8(mgr->actors[i], id);
        fn_801FF6E0(mgr->actors[i], owner);
        fn_801FF6D8(mgr->actors[i], owner);
        fn_801FF6D0(mgr->actors[i], param);
        fn_8018A588(mgr->actors[i], fn_801F620C(mgr, id, 'life'));
        fn_801FF6C8(mgr->actors[i], fn_801F620C(mgr, id, 'atcp'));
        fn_801FF6C0(mgr->actors[i], fn_801F620C(mgr, id, 'atcn'));
        fn_801FF6B8(mgr->actors[i], fn_801F620C(mgr, id, 'dstr') != 0);
        fn_801FF6B0(mgr->actors[i], fn_801F620C(mgr, id, 'dasu'));
        fn_801FF6A8(mgr->actors[i], fn_801F620C(mgr, id, 'efsz'));
        fn_801FF6A0(mgr->actors[i], fn_801F620C(mgr, id, 'voic'));
        fn_801FF698(mgr->actors[i], a7);
        fn_801FF66C(mgr->actors[i], fn_801FF674());
        fn_801FF664(mgr->actors[i], a8);
        mgr->lastIndex = i;
        result = mgr->serial;
        mgr->serial = result + 1;
        if (mgr->maxUsed < i + 1) {
            mgr->maxUsed = i + 1;
        }
        ((ActorVt*)mgr->actors[i])->v01();
        if (fn_801FF65C(mgr->actors[i])->x == lbl_8053F830 && fn_801FF65C(mgr->actors[i])->y == lbl_8053F830 &&
            fn_801FF65C(mgr->actors[i])->z == lbl_8053F830 && fn_801FF65C(mgr->actors[i])->w == lbl_8053F830) {
            mgr->actors[i]->setBox70(*(ActorBox*)fn_801FF654(mgr->actors[i]));
        }
        break;
    }
    return result;
}

// Actor+0x60 / +0x70: two 4-float boxes (copied as two float pairs).
struct ActorBox {
    Quad q;
};
struct ActorBoxView {
    u8 pad[0x70];
    ActorBox m70;
};
void Actor::setBox70(const ActorBox& box) { ((ActorBoxView*)this)->m70 = box; }
extern "C" Vec4f* fn_801FF654(Actor* a) { return (Vec4f*)((u8*)a + 0x60); }
extern "C" Vec4f* fn_801FF65C(Actor* a) { return (Vec4f*)((u8*)a + 0x70); }
extern "C" void fn_801FF664(Actor* a, s32 v) { *(s32*)((u8*)a + 0x110) = v; }
extern "C" void fn_801FF66C(Actor* a, u32 v) { *(u32*)((u8*)a + 0x170) = v; }
extern "C" u32 fn_801FF674(void) { return fn_802D39FC(fn_802D6A9C()); }
extern "C" void fn_801FF698(Actor* a, s32 v) { *(s32*)((u8*)a + 0x16C) = v; }
extern "C" void fn_801FF6A0(Actor* a, s32 v) { *(s32*)((u8*)a + 0x190) = v; }
extern "C" void fn_801FF6A8(Actor* a, s32 v) { *(s32*)((u8*)a + 0xC0) = v; }
extern "C" void fn_801FF6B0(Actor* a, s32 v) { *(s32*)((u8*)a + 0x18C) = v; }
extern "C" void fn_801FF6B8(Actor* a, u8 v) { *(u8*)((u8*)a + 0x1A8) = v; }
extern "C" void fn_801FF6C0(Actor* a, s32 v) { *(s32*)((u8*)a + 0x118) = v; }
extern "C" void fn_801FF6C8(Actor* a, s32 v) { *(s32*)((u8*)a + 0x114) = v; }
extern "C" void fn_801FF6D0(Actor* a, u32 v) { *(u32*)((u8*)a + 0x90) = v; }
extern "C" void fn_801FF6D8(Actor* a, s32 v) { *(s32*)((u8*)a + 0x8) = v; }
extern "C" void fn_801FF6E0(Actor* a, s32 v) { *(s32*)((u8*)a + 0x4) = v; }
extern "C" void fn_801FF6E8(Actor* a, s32 v) { *(s32*)((u8*)a + 0x1A0) = v; }
extern "C" void fn_801FF6F0(Actor* a, Vec* v) { JGeometry::setTVec3f(&v->x, (f32*)((u8*)a + 0x24)); }
struct ActorPosView {
    u8 pad[0xC];
    JGeometry::TVec3<f32> pos;
    JGeometry::TVec3<f32> oldPos;
};
void Actor::setPos(const JGeometry::TVec3<f32>& v) {
    ((ActorPosView*)this)->pos = v;
    ((ActorPosView*)this)->oldPos = v;
}
extern "C" void fn_801FF720(Actor* a, s32 v) { *(s32*)((u8*)a + 0x19C) = v; }
extern "C" void fn_801FF728(Actor* a, s32 v) { *(s32*)((u8*)a + 0x198) = v; }
extern "C" Vec* fn_801FF730(Actor* a) { return (Vec*)((u8*)a + 0xC); }
extern "C" void fn_801FF738(ActorSlotLink* l) { *((u8*)l + 0x31) = 1; }

// ---- Gsck_ctor_801FF744.cpp ----
extern void* lbl_804AA800[];


GSCK::GSCK() {
    *(void**)this = lbl_804AA800;
}

// ---- Mrtc_ctor_801FF780.cpp ----
extern void* lbl_804AD278[];


MRTC::MRTC() {
    *(void**)this = lbl_804AD278;
}

// ---- Stgn_ctor_801FF7BC.cpp ----
extern void* __vt__4STGN[];


STGN::STGN() {
    *(void**)this = __vt__4STGN;
}

// ---- Rins_ctor_801FF7F8.cpp ----
extern void* lbl_804AD220[];


RINS::RINS() {
    *(void**)this = lbl_804AD220;
}

// ---- Wpwl_ctor_801FF834.cpp ----
extern void* lbl_804AE948[];


WPWL::WPWL() {
    *(void**)this = lbl_804AE948;
}

// ---- Pss2_ctor_801FF870.cpp ----
extern void* lbl_804AE8F4[];


PSS2::PSS2() {
    *(void**)this = lbl_804AE8F4;
}

// ---- Tbo2_ctor_801FF918.cpp ----
extern void* lbl_804AA750[];


TBO2::TBO2() {
    *(void**)this = lbl_804AA750;
}

// ---- Tbgn_ctor_801FF954.cpp ----
extern void* lbl_804AA6F8[];


TBGN::TBGN() {
    *(void**)this = lbl_804AA6F8;
}

// ---- Iceb_ctor_801FF990.cpp ----
extern void* lbl_804AE888[];


ICEB::ICEB() {
    *(void**)this = lbl_804AE888;
}

// ---- Dmyk_ctor_801FF9CC.cpp ----
extern void* lbl_804AA6A0[];


DMYK::DMYK() {
    *(void**)this = lbl_804AA6A0;
}

// ---- Jpe2_ctor_801FFA08.cpp ----
extern void* lbl_804AD1C8[];


JPE2::JPE2() {
    *(void**)this = lbl_804AD1C8;
}

// ---- Endr_ctor_801FFA44.cpp ----
extern void* lbl_804AE830[];


ENDR::ENDR() {
    *(void**)this = lbl_804AE830;
}

// ---- Tfl2_ctor_801FFA80.cpp ----
extern void* lbl_804AA628[];


TFL2::TFL2() {
    *(void**)this = lbl_804AA628;
}

// ---- Losw_ctor_801FFABC.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern void* lbl_8049CB58[];


LOSW::LOSW() {
    *(void**)this = lbl_8049CB58;
    *(u8*)((char*)this + 0x24e) = 0;
}

// ---- Pswk_ctor_801FFB00.cpp ----
extern void* lbl_804AE5C8[];


PSWK::PSWK() {
    *(void**)this = lbl_804AE5C8;
}

// ---- Sibt_ctor_801FFB3C.cpp ----
extern void* lbl_8049CB04[];


SIBT::SIBT() {
    *(void**)this = lbl_8049CB04;
}

// ---- Pswb_ctor_801FFB78.cpp ----
extern void* lbl_804AE574[];


PSWB::PSWB() {
    *(void**)this = lbl_804AE574;
}

// ---- Glwp_ctor_801FFBB4.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804A39DC[];


GEWP::GEWP() : Actor() {
    *(void**)this = lbl_804A39DC;
    __construct_array((char*)this + 0x264, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Snpc_ctor_801FFC0C.cpp ----
extern void* lbl_804AAFB8[];


SNPC::SNPC() {
    *(void**)this = lbl_804AAFB8;
}

// ---- Tjij_ctor_801FFC48.cpp ----
extern void* __vt__4TJIJ[];


TJIJ::TJIJ() {
    *(void**)this = __vt__4TJIJ;
}

// ---- Mrta_ctor_801FFC84.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_801FFCDC(void);
extern void* lbl_804ACD70[];


MRTA::MRTA() : Actor() {
    *(void**)this = lbl_804ACD70;
    __construct_array((char*)this + 0x268, (void*)fn_801FFCDC, 0, 0x14, 4);
}

// ---- stub_801ffcdc.cpp ----
// Empty virtual-hook stub (see Game/ActorDefaultHooks.cpp).
extern "C" void fn_801FFCDC(void) {}

// ---- Swdl_ctor_801FFCE0.cpp ----
extern void* lbl_804AA590[];


SWDL::SWDL() {
    *(void**)this = lbl_804AA590;
}

// ---- fn_801FFD1C_ctor.cpp ----
extern void* lbl_804AE7D8[];

extern "C" void* fn_801FFD1C(void* this_) {
    __ct__5ActorFv(this_);
    *(void**)this_ = lbl_804AE7D8;
    return this_;
}

// ---- fn_801FFD58_ctor.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804AE4B0[];


fn_801FFD58_actor::fn_801FFD58_actor() : Actor() {
    *(void**)this = lbl_804AE4B0;
    __construct_array((char*)this + 0x264, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x294, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x2c4, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x2f4, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Elk2_ctor_801FFE04.cpp ----
extern void* lbl_804AE338[];


ELK2::ELK2() {
    *(void**)this = lbl_804AE338;
}

// ---- Ptmi_ctor_801FFE40.cpp ----
extern void* lbl_804AE780[];


PTMI::PTMI() {
    *(void**)this = lbl_804AE780;
}

// ---- Mrmt_ctor_801FFE7C.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern void* lbl_8049EA88[];


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
extern void* lbl_804AA4F0[];


FOEV::FOEV() {
    *(void**)this = lbl_804AA4F0;
    *(s32*)((char*)this + 0x248) = -1;
}

// ---- Rsnp_ctor_801FFF24.cpp ----
extern void* lbl_804ACD18[];


RSNP::RSNP() {
    *(void**)this = lbl_804ACD18;
}

// ---- Ogst_ctor_801FFF60.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern void* lbl_8049EA00[];


OGST::OGST() {
    *(void**)this = lbl_8049EA00;
    *(s32*)((char*)this + 0x230) = 0;
}

// ---- Icob_ctor_801FFFA4.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern void* lbl_8049E9A8[];


ICOB::ICOB() {
    *(void**)this = lbl_8049E9A8;
    *(s32*)((char*)this + 0x230) = 0;
}

// ---- Emsk_ctor_801FFFE8.cpp ----
extern void* lbl_804AA498[];


ELSK::ELSK() {
    *(void**)this = lbl_804AA498;
}

// ---- Tutm_ctor_80200024.cpp ----
extern void* lbl_804ACBF0[];


TUTM::TUTM() {
    *(void**)this = lbl_804ACBF0;
}

// ---- fn_80200060_ctor.cpp ----
extern void* lbl_804ACC68[];

extern "C" void* fn_80200060(void* this_) {
    __ct__5ActorFv(this_);
    *(void**)this_ = lbl_804ACC68;
    return this_;
}

// ---- Tugf_ctor_8020009C.cpp ----

extern "C" void fn_801EB950(void*);
extern void* lbl_804ACCC0[];


TUGF::TUGF() : Actor() {
    *(void**)this = lbl_804ACCC0;
    fn_801EB950((char*)this + 0x230);
}

// ---- Leaf_ctor_802000E0.cpp ----
extern void* lbl_804AE2E0[];


LEAF::LEAF() {
    *(void**)this = lbl_804AE2E0;
}

// ---- Lfgn_ctor_8020011C.cpp ----
extern void* lbl_804AE288[];


LFGN::LFGN() {
    *(void**)this = lbl_804AE288;
}

// ---- Thcl_ctor_80200158.cpp ----
extern void* lbl_804A7C40[];


THCL::THCL() {
    *(void**)this = lbl_804A7C40;
}

// ---- Agbw_ctor_80200194.cpp ----
extern void* lbl_804AA440[];


AGBW::AGBW() {
    *(void**)this = lbl_804AA440;
}

// ---- Svgt_ctor_802001D0.cpp ----
extern void* lbl_804ACB98[];


SVGT::SVGT() {
    *(void**)this = lbl_804ACB98;
}

// ---- Tmi2_ctor_8020020C.cpp ----
extern void* lbl_804AE728[];


TMI2::TMI2() {
    *(void**)this = lbl_804AE728;
}

// ---- Safu_ctor_80200248.cpp ----
extern void* lbl_804A3948[];


SAFU::SAFU() {
    *(void**)this = lbl_804A3948;
}

// ---- Fdwp_ctor_80200284.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern void* lbl_8049E8F8[];


FDWP::FDWP() {
    *(void**)this = lbl_8049E8F8;
    *(s32*)((char*)this + 0x230) = 0;
    *(s32*)((char*)this + 0x234) = 0;
    *(s32*)((char*)this + 0x238) = 0;
    *(s32*)((char*)this + 0x23c) = 0;
}

// ---- Twev_ctor_802002D4.cpp ----
extern void* lbl_8049CA40[];


TWEV::TWEV() {
    *(void**)this = lbl_8049CA40;
}

// ---- Dwap_ctor_80200310.cpp ----
extern void* __vt__4DWAP[];


DWAP::DWAP() {
    *(void**)this = __vt__4DWAP;
}

// ---- Tooi_ctor_8020034C.cpp ----
extern void* lbl_804ACB40[];


TOOI::TOOI() {
    *(void**)this = lbl_804ACB40;
}

// ---- Chsw_ctor_80200388.cpp ----
extern void* lbl_804AA3E8[];


CHSW::CHSW() {
    *(void**)this = lbl_804AA3E8;
}

// ---- Tlwp_ctor_802003C4.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804A38D4[];


TLWP::TLWP() : Actor() {
    *(void**)this = lbl_804A38D4;
    __construct_array((char*)this + 0x264, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Jwlk_ctor_8020041C.cpp ----
extern void* lbl_804AABA8[];


JWLK::JWLK() {
    *(void**)this = lbl_804AABA8;
}

// ---- Rbpn_ctor_80200458.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern void* lbl_8049E848[];


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
extern void* lbl_804AE230[];


PSW2::PSW2() {
    *(void**)this = lbl_804AE230;
}

// ---- Gnef_ctor_802004EC.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_80200544(void);
extern void* lbl_804AA350[];


GNEF::GNEF() : Actor() {
    *(void**)this = lbl_804AA350;
    __construct_array((char*)this + 0x27c, (void*)fn_80200544, 0, 0x14, 4);
}

// ---- stub_80200544.cpp ----
// Empty virtual-hook stub (see Game/ActorDefaultHooks.cpp).
extern "C" void fn_80200544(void) {}

// ---- Stpn_ctor_80200548.cpp ----
extern void* lbl_804AA2D8[];


STPN::STPN() {
    *(void**)this = lbl_804AA2D8;
}

// ---- Tomi_ctor_80200584.cpp ----
extern void* lbl_804AE6D0[];


SSMI::SSMI() {
    *(void**)this = lbl_804AE6D0;
}

// ---- Medm_ctor_802005C0.cpp ----
extern void* lbl_804AE678[];


MEDM::MEDM() {
    *(void**)this = lbl_804AE678;
}

// ---- Sdsm_ctor_802005FC.cpp ----
extern void* lbl_804AA280[];


SDSM::SDSM() {
    *(void**)this = lbl_804AA280;
}

// ---- Bck2_ctor_80200638.cpp ----
extern void* lbl_804AE620[];


BCK2::BCK2() {
    *(void**)this = lbl_804AE620;
}

// ---- Svtg_ctor_80200674.cpp ----
extern void* lbl_804AAB40[];


SPTG::SPTG() {
    *(void**)this = lbl_804AAB40;
}

// ---- Dnav_ctor_802006B0.cpp ----
extern void* lbl_804ADFE8[];


DNAV::DNAV() {
    *(void**)this = lbl_804ADFE8;
}

// ---- Zomo_ctor_802006EC.cpp ----
extern void* lbl_804AA228[];


ZOMO::ZOMO() {
    *(void**)this = lbl_804AA228;
}

// ---- Zdco_ctor_80200728.cpp ----
extern void* lbl_804A375C[];


ZDCO::ZDCO() {
    *(void**)this = lbl_804A375C;
}

// ---- fn_80200764_ctor.cpp ----
extern void* lbl_804A3698[];

extern "C" void* fn_80200764(void* this_) {
    __ct__5ActorFv(this_);
    *(void**)this_ = lbl_804A3698;
    return this_;
}

// ---- Zld3_ctor_802007A0.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804A35AC[];


ZLD3::ZLD3() : Actor() {
    *(void**)this = lbl_804A35AC;
    __construct_array((char*)this + 0x288, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Oblf_ctor_802007F8.cpp ----
extern void* lbl_804ACA00[];


OBLF::OBLF() {
    *(void**)this = lbl_804ACA00;
}

// ---- Gen3_ctor_80200834.cpp ----
extern void* lbl_804AA1D0[];


GEN3::GEN3() {
    *(void**)this = lbl_804AA1D0;
}

// ---- Egol_ctor_80200870.cpp ----
extern void* lbl_804A3548[];


EGOL::EGOL() {
    *(void**)this = lbl_804A3548;
}

// ---- Ynsw_ctor_802008AC.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804AC9A8[];


YNSW::YNSW() : Actor() {
    *(void**)this = lbl_804AC9A8;
    __construct_array((char*)this + 0x254, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Gmtb_ctor_80200904.cpp ----
extern void* lbl_804AAAE8[];


GMTB::GMTB() {
    *(void**)this = lbl_804AAAE8;
}

// ---- Gmbl_ctor_80200940.cpp ----
extern void* lbl_804AAA70[];


GMBL::GMBL() {
    *(void**)this = lbl_804AAA70;
}

// ---- Eetc_ctor_8020097C.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804ADF28[];


EETC::EETC() : Actor() {
    *(void**)this = lbl_804ADF28;
    __construct_array((char*)this + 0x27c, (void*)fn_8003B2CC, 0, 0xc, 3);
    __construct_array((char*)this + 0x2a0, (void*)fn_8003B2CC, 0, 0xc, 3);
    __construct_array((char*)this + 0x2c4, (void*)fn_8003B2CC, 0, 0xc, 3);
}

// ---- Rck2_ctor_80200A0C.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
void fn_80200A84(void);
void fn_80200A80(void);
extern void* lbl_804AC950[];


RCK2::RCK2() : Actor() {
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

extern "C" void InitDefaultRecord(void*);
extern void* lbl_804ADAC8[];


EOWL::EOWL() : Actor() {
    *(void**)this = lbl_804ADAC8;
    InitDefaultRecord((char*)this + 0x2a0);
}

// ---- Dmtw_ctor_80200ACC.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_8049E770[];


DMTW::DMTW() : Actor() {
    *(void**)this = lbl_8049E770;
    __construct_array((char*)this + 0x25c, (void*)fn_8003B2CC, 0, 0xc, 6);
    __construct_array((char*)this + 0x2c8, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x2f8, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x3b8, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Smri_ctor_80200B78.cpp ----
extern void* lbl_804AA9F0[];


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
// base class. Identified via the Actor_CreateByID dispatcher sweep (see
// reference_fsa_full_dispatch_sweep.md).

extern "C" void* lbl_804A5958[];
extern "C" void* lbl_804AD858[];


ELNK::ELNK() {
    *(void**)this = lbl_804A5958;
    *(void**)this = lbl_804AD858;
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
extern void* lbl_804B1A48[];


DTLK::DTLK() {
    *(void**)this = lbl_804B1A48;
}

// ---- Tkra_ctor_80200C98.cpp ----
extern void* lbl_804AA178[];


TKRA::TKRA() {
    *(void**)this = lbl_804AA178;
}

// ---- Okam_ctor_80200CD4.cpp ----
extern void* lbl_804A3448[];


OKAM::OKAM() {
    *(void**)this = lbl_804A3448;
}

// ---- Ttat_ctor_80200D10.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804A2FB0[];


TTAT::TTAT() : Actor() {
    *(void**)this = lbl_804A2FB0;
    __construct_array((char*)this + 0x280, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Goma_ctor_80200D68.cpp ----
extern void* lbl_804A307C[];


GNMA::GNMA() {
    *(void**)this = lbl_804A307C;
}

// ---- Ddgo_ctor_80200DA4.cpp ----
extern void* lbl_804A3334[];


DDGO::DDGO() {
    *(void**)this = lbl_804A3334;
}

// ---- Endm_ctor_80200DE0.cpp ----
extern void* lbl_804AA0FC[];


ENDM::ENDM() {
    *(void**)this = lbl_804AA0FC;
}

// ---- Lcls_ctor_80200E1C.cpp ----
extern void* lbl_804AA008[];


LCLS::LCLS() {
    *(void**)this = lbl_804AA008;
}

// ---- Glbs_ctor_80200E58.cpp ----
extern void* lbl_804AA060[];


GLBS::GLBS() {
    *(void**)this = lbl_804AA060;
}

// ---- Emik_ctor_80200E94.cpp ----
extern void* lbl_804A5958[];
extern void* lbl_804AD5B8[];


EMIK::EMIK() {
    *(void**)this = lbl_804A5958;
    *(void**)this = lbl_804AD5B8;
}

// ---- Ezld_ctor_80200EDC.cpp ----
extern void* lbl_804A5958[];
extern void* lbl_804AD6F0[];


EZLD::EZLD() {
    *(void**)this = lbl_804A5958;
    *(void**)this = lbl_804AD6F0;
}

// ---- Enpc_ctor_80200F24.cpp ----
extern void* lbl_804AD48C[];


ENPC::ENPC() {
    *(void**)this = lbl_804AD48C;
}

// ---- Hbb2_ctor_80200F60.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804A2EC0[];


HBB2::HBB2() : Actor() {
    *(void**)this = lbl_804A2EC0;
    __construct_array((char*)this + 0x294, (void*)fn_8003B2CC, 0, 0xc, 0x28);
}

// ---- Nwok_ctor_80200FB8.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804AC8C0[];


NWOK::NWOK() : Actor() {
    *(void**)this = lbl_804AC8C0;
    __construct_array((char*)this + 0x290, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Saya_ctor_80201010.cpp ----
extern void* lbl_804A2E30[];


RYYA::RYYA() {
    *(void**)this = lbl_804A2E30;
}

// ---- Mjgr_ctor_8020104C.cpp ----
extern void* lbl_804A9FB0[];


MJGR::MJGR() {
    *(void**)this = lbl_804A9FB0;
}

// ---- Htmk_ctor_80201088.cpp ----
extern void* lbl_804AC868[];


HTMK::HTMK() {
    *(void**)this = lbl_804AC868;
}

// ---- Enbz_ctor_802010C4.cpp ----
extern void* lbl_804A2CB0[];


ENBZ::ENBZ() {
    *(void**)this = lbl_804A2CB0;
}

// ---- Pnp2_ctor_80201100.cpp ----
extern void* lbl_804A9F58[];


PNP2::PNP2() {
    *(void**)this = lbl_804A9F58;
}

// ---- Sslf_ctor_8020113C.cpp ----
extern void* lbl_804AD348[];


SSLF::SSLF() {
    *(void**)this = lbl_804AD348;
}

// ---- Bemn_ctor_80201178.cpp ----
extern void* lbl_804AC810[];


BEMN::BEMN() {
    *(void**)this = lbl_804AC810;
}

// ---- Fobe_ctor_802011B4.cpp ----
extern void* lbl_804AC7B8[];


FOBE::FOBE() {
    *(void**)this = lbl_804AC7B8;
}

// ---- Sen2_ctor_802011F0.cpp ----
extern void* lbl_804A9F00[];


SEN2::SEN2() {
    *(void**)this = lbl_804A9F00;
}

// ---- Crgn_ctor_8020122C.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern void* lbl_8049E5B8[];


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
extern void* lbl_804A2BF4[];


TENN::TENN() {
    *(void**)this = lbl_804A2BF4;
}

// ---- Wave_ctor_802012D0.cpp ----
extern void* lbl_804A9EA8[];


WAVE::WAVE() {
    *(void**)this = lbl_804A9EA8;
}

// ---- Form_ctor_8020130C.cpp ----
extern void* lbl_804A7BE8[];


FORM::FORM() {
    *(void**)this = lbl_804A7BE8;
}

// ---- Spbg_ctor_80201348.cpp ----
extern void* lbl_804AC760[];


SPBG::SPBG() {
    *(void**)this = lbl_804AC760;
}

// ---- Szsc_ctor_802013D8.cpp ----
extern void* lbl_804AC708[];


SZSC::SZSC() {
    *(void**)this = lbl_804AC708;
}

// ---- Nnjn_ctor_80201414.cpp ----
extern void* lbl_804AC6B0[];


NNJN::NNJN() {
    *(void**)this = lbl_804AC6B0;
}

// ---- Syky_ctor_80201450.cpp ----
extern void* lbl_804A2B18[];


SYKY::SYKY() {
    *(void**)this = lbl_804A2B18;
}

// ---- Anho_ctor_8020148C.cpp ----
extern void* lbl_8049C970[];


ANHO::ANHO() {
    *(void**)this = lbl_8049C970;
}

// ---- fn_802014C8_ctor.cpp ----
extern void* lbl_804A9E50[];

extern "C" void* fn_802014C8(void* this_) {
    __ct__5ActorFv(this_);
    *(void**)this_ = lbl_804A9E50;
    return this_;
}

// ---- Fish_ctor_80201504.cpp ----
extern void* lbl_804AC658[];


FISH::FISH() {
    *(void**)this = lbl_804AC658;
}

// ---- Alce_ctor_80201540.cpp ----
extern void* lbl_804A2AB0[];


ALCE::ALCE() {
    *(void**)this = lbl_804A2AB0;
}

// ---- Zoom_ctor_8020157C.cpp ----
extern void* lbl_804A9DF8[];


ZOOM::ZOOM() {
    *(void**)this = lbl_804A9DF8;
}

// ---- Bgmn_ctor_802015B8.cpp ----
extern void* lbl_804A9DA0[];


BGMN::BGMN() {
    *(void**)this = lbl_804A9DA0;
}

// ---- Mgya_ctor_802015F4.cpp ----
extern void* lbl_8049C8EC[];


MGYA::MGYA() {
    *(void**)this = lbl_8049C8EC;
}

// ---- Gfbs_ctor_80201630.cpp ----
extern void* __vt__4GFBS[];


GFBS::GFBS() {
    *(void**)this = __vt__4GFBS;
}

// ---- Blz2_ctor_802016D8.cpp ----
extern void* lbl_804A9D28[];


BLZ2::BLZ2() {
    *(void**)this = lbl_804A9D28;
}

// ---- Sev2_ctor_80201714.cpp ----
extern void* lbl_804A9CD0[];


SEV2::SEV2() {
    *(void**)this = lbl_804A9CD0;
}

// ---- Rnsw_ctor_80201750.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern void* lbl_8049DE90[];


RNSW::RNSW() {
    *(void**)this = lbl_8049DE90;
    *(s32*)((char*)this + 0x230) = 1;
    *(s32*)((char*)this + 0x234) = 0;
    *(s32*)((char*)this + 0x238) = 0;
    *(s32*)((char*)this + 0x23c) = 0;
    *(s32*)((char*)this + 0x240) = 0;
}

// ---- Senp_ctor_802017A8.cpp ----
extern void* lbl_804A9C78[];


SENP::SENP() {
    *(void**)this = lbl_804A9C78;
}

// ---- Haya_ctor_802017E4.cpp ----
extern void* lbl_8049C858[];


GSYA::GSYA() {
    *(void**)this = lbl_8049C858;
}

// ---- Brbl_ctor_80201820.cpp ----
extern void* lbl_804A7B90[];


BRBL::BRBL() {
    *(void**)this = lbl_804A7B90;
}

// ---- Limt_ctor_8020185C.cpp ----
extern void* lbl_804B174C[];


LIMT::LIMT() {
    *(void**)this = lbl_804B174C;
}

// ---- Gol2_ctor_80201898.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804A9C20[];


GNL2::GNL2() : Actor() {
    *(void**)this = lbl_804A9C20;
    __construct_array((char*)this + 0x258, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Beee_ctor_802018F0.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804AC600[];


BEEE::BEEE() : Actor() {
    *(void**)this = lbl_804AC600;
    __construct_array((char*)this + 0x2a4, (void*)fn_8003B2CC, 0, 0xc, 7);
    __construct_array((char*)this + 0x2f8, (void*)fn_8003B2CC, 0, 0xc, 7);
    __construct_array((char*)this + 0x34c, (void*)fn_8003B2CC, 0, 0xc, 7);
}

// ---- Pssw_ctor_80201980.cpp ----
extern void* lbl_804A7B38[];


PSSW::PSSW() {
    *(void**)this = lbl_804A7B38;
}

// ---- Hous_ctor_802019BC.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_801546E4(void*);
extern void* lbl_804A7AE0[];


HOUS::HOUS() : Actor() {
    *(void**)this = lbl_804A7AE0;
    __construct_array((char*)this + 0x2dc, (void*)fn_801546E4, 0, 0x8, 4);
}

// ---- fn_80201A14_ctor.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804A2944[];


fn_80201A14_actor::fn_80201A14_actor() : Actor() {
    *(void**)this = lbl_804A2944;
    __construct_array((char*)this + 0x2a4, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x2d4, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Gnon_ctor_80201A88.cpp ----
extern void* lbl_804A25F0[];


GNON::GNON() {
    *(void**)this = lbl_804A25F0;
}

// ---- Bbmb_ctor_80201AC4.cpp ----
extern void* lbl_804AC588[];


BBMB::BBMB() {
    *(void**)this = lbl_804AC588;
}

// ---- Bbsl_ctor_80201B00.cpp ----
extern void* lbl_804AC4D0[];


BBSL::BBSL() {
    *(void**)this = lbl_804AC4D0;
}

// ---- fn_80201B3C_ctor.cpp ----
extern void* lbl_804A9BC8[];

extern "C" void* fn_80201B3C(void* this_) {
    __ct__5ActorFv(this_);
    *(void**)this_ = lbl_804A9BC8;
    return this_;
}

// ---- Gbao_ctor_80201B78.cpp ----
extern void* lbl_804B16E0[];


GBAO::GBAO() {
    *(void**)this = lbl_804B16E0;
}

// ---- Offs_ctor_80201BB4.cpp ----
extern void* lbl_804A9B70[];


OFFS::OFFS() {
    *(void**)this = lbl_804A9B70;
}

// ---- fn_80201BF0_ctor.cpp ----
extern void* lbl_804AC388[];

extern "C" void* fn_80201BF0(void* this_) {
    __ct__5ActorFv(this_);
    *(void**)this_ = lbl_804AC388;
    return this_;
}

// ---- Lots_ctor_80201C2C.cpp ----
extern void* lbl_804AC330[];


LITS::LITS() {
    *(void**)this = lbl_804AC330;
}

// ---- Stbl_ctor_80201C68.cpp ----
extern void* lbl_804AC2D8[];


STBL::STBL() {
    *(void**)this = lbl_804AC2D8;
}

// ---- Dgt2_ctor_80201D00.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804A1FA0[];


DGT2::DGT2() : Actor() {
    *(void**)this = lbl_804A1FA0;
    __construct_array((char*)this + 0x288, (void*)fn_8003B2CC, 0, 0xc, 6);
    __construct_array((char*)this + 0x2d0, (void*)fn_8003B2CC, 0, 0xc, 0x14);
}

// ---- Rvfr_ctor_80201D74.cpp ----
extern void* lbl_804AC250[];


RVFR::RVFR() {
    *(void**)this = lbl_804AC250;
}

// ---- Wppa_ctor_80201DB0.cpp ----
extern void* lbl_804AC1F8[];


WPPA::WPPA() {
    *(void**)this = lbl_804AC1F8;
}

// ---- Flyo_ctor_80201DEC.cpp ----
extern void* lbl_804AC100[];


FLYO::FLYO() {
    *(void**)this = lbl_804AC100;
}

// ---- Bph2_ctor_80201E28.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804A1E50[];


BPH2::BPH2() : Actor() {
    *(void**)this = lbl_804A1E50;
    __construct_array((char*)this + 0x2f8, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Prtc_ctor_80201E80.cpp ----
extern void* lbl_804A9AC8[];


PRTC::PRTC() {
    *(void**)this = lbl_804A9AC8;
}

// ---- Rasn_ctor_80201EBC.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804A7A68[];


RASN::RASN() : Actor() {
    *(void**)this = lbl_804A7A68;
    __construct_array((char*)this + 0x238, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Fgn2_ctor_80201F14.cpp ----
extern void* lbl_804A1A98[];


FGN2::FGN2() {
    *(void**)this = lbl_804A1A98;
}

// ---- Wppr_ctor_80201F50.cpp ----
extern void* lbl_804AC0A8[];


WPPR::WPPR() {
    *(void**)this = lbl_804AC0A8;
}

// ---- Jpen_ctor_80201F8C.cpp ----
extern void* lbl_804AC010[];


JPEN::JPEN() {
    *(void**)this = lbl_804AC010;
}

// ---- Wnwn_ctor_80201FC8.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804A18E0[];


WNWN::WNWN() : Actor() {
    *(void**)this = lbl_804A18E0;
    __construct_array((char*)this + 0x294, (void*)fn_8003B2CC, 0, 0xc, 0xa);
    __construct_array((char*)this + 0x30c, (void*)fn_8003B2CC, 0, 0xc, 0xa);
}

// ---- Urac_ctor_8020203C.cpp ----
extern void* lbl_804A9A70[];


URAC::URAC() {
    *(void**)this = lbl_804A9A70;
}

// ---- Vwmd_ctor_80202078.cpp ----
extern void* lbl_804A9A18[];


VWMD::VWMD() {
    *(void**)this = lbl_804A9A18;
}

// ---- Tkrm_ctor_802020B4.cpp ----
extern void* lbl_804ABAE8[];


TKRM::TKRM() {
    *(void**)this = lbl_804ABAE8;
}

// ---- Bots_ctor_802020F0.cpp ----
extern void* __vt__4BOTS[];


BOTS::BOTS() {
    *(void**)this = __vt__4BOTS;
}

// ---- Tsno_ctor_8020212C.cpp ----
extern void* lbl_804ABA90[];


TSNO::TSNO() {
    *(void**)this = lbl_804ABA90;
}

// ---- Grve_ctor_80202168.cpp ----
extern void* lbl_804A99C0[];


FGVE::FGVE() {
    *(void**)this = lbl_804A99C0;
}

// ---- Yasi_ctor_802021A4.cpp ----
extern void* lbl_804A9968[];


YASI::YASI() {
    *(void**)this = lbl_804A9968;
}

// ---- Btin_ctor_802021E0.cpp ----
extern void* lbl_804A927C[];


BTIN::BTIN() {
    *(void**)this = lbl_804A927C;
}

// ---- fn_8020221C_ctor.cpp ----
extern void* lbl_804A1888[];


FAGN::FAGN() {
    *(void**)this = lbl_804A1888;
}

// ---- fn_80202258_ctor.cpp ----
extern void* lbl_804A1790[];


GDMN::GDMN() {
    char* p = (char*)this;
    *(void**)p = lbl_804A1790;
    *(s32*)(p + 0x234) = -1;
}

// ---- fn_8020229C_ctor.cpp ----
extern void* lbl_804A1718[];


RDVR::RDVR() {
    char* p = (char*)this;
    *(void**)p = lbl_804A1718;
    *(s32*)(p + 0x234) = -1;
}

// ---- Dsin_ctor_802022E0.cpp ----
extern void* lbl_804AB5D8[];


DSIN::DSIN() {
    *(void**)this = lbl_804AB5D8;
}

// ---- Grok_ctor_8020231C.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804A1630[];


GROK::GROK() : Actor() {
    *(void**)this = lbl_804A1630;
    __construct_array((char*)this + 0x294, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x2c4, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Sbtn_ctor_80202390.cpp ----
extern void* lbl_804AB580[];


SBTN::SBTN() {
    *(void**)this = lbl_804AB580;
}

// ---- Circ_ctor_802023CC.cpp ----
extern void* lbl_804A7960[];


CIRC::CIRC() {
    *(void**)this = lbl_804A7960;
}

// ---- Flyk_ctor_80202408.cpp ----
extern void* lbl_804A9078[];


FLYK::FLYK() {
    *(void**)this = lbl_804A9078;
}

// ---- fn_80202444_ctor.cpp ----
extern void* lbl_804A1318[];

extern "C" void* fn_80202444(void* this_) {
    __ct__5ActorFv(this_);
    *(void**)this_ = lbl_804A1318;
    return this_;
}

// ---- Plsw_ctor_80202480.cpp ----
extern void* lbl_804A7908[];


PESW::PESW() {
    *(void**)this = lbl_804A7908;
}

// ---- Osin_ctor_802024BC.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804AB528[];


OSIN::OSIN() : Actor() {
    *(void**)this = lbl_804AB528;
    __construct_array((char*)this + 0x26c, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Puku_ctor_80202514.cpp ----
extern void* lbl_804A11B8[];


PUKU::PUKU() {
    *(void**)this = lbl_804A11B8;
}

// ---- Swbm_ctor_80202550.cpp ----
extern void* lbl_804A1160[];


SWBM::SWBM() {
    *(void**)this = lbl_804A1160;
}

// ---- Infr_ctor_8020258C.cpp ----
extern void* lbl_804AB4C0[];


INFR::INFR() {
    *(void**)this = lbl_804AB4C0;
}

// ---- Arsh_ctor_802025C8.cpp ----
extern "C" void* fn_801D30B8(void* this_);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern void* lbl_804A58B4[];
extern void* lbl_804A48B0[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];



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
    __dt__5ActorFv(localTemp, 0);
}

// ---- Bmty_ctor_8020264C.cpp ----
extern void* lbl_804AB464[];


BMTY::BMTY() {
    *(void**)this = lbl_804AB464;
}

// ---- Pcdm_ctor_80202688.cpp ----
extern void* lbl_804AB3A8[];


PCDM::PCDM() {
    *(void**)this = lbl_804AB3A8;
}

// ---- Crtl_ctor_802026C4.cpp ----
extern void* lbl_804AB308[];


CRTL::CRTL() {
    *(void**)this = lbl_804AB308;
}

// ---- Rdbl_ctor_80202700.cpp ----
extern void* lbl_804A9020[];


RDBL::RDBL() {
    *(void**)this = lbl_804A9020;
}

// ---- Onof_ctor_8020273C.cpp ----
extern void* lbl_804A8FC8[];


ONOF::ONOF() {
    *(void**)this = lbl_804A8FC8;
}

// ---- Ocfr_ctor_80202778.cpp ----
extern void* lbl_804AB2B0[];


OCFR::OCFR() {
    *(void**)this = lbl_804AB2B0;
}

// ---- Brry_ctor_802027B4.cpp ----
extern void* lbl_804AB258[];


BPRY::BPRY() {
    *(void**)this = lbl_804AB258;
}

// ---- Lif2_ctor_802027F0.cpp ----
extern void* lbl_804A78B0[];


LIF2::LIF2() {
    *(void**)this = lbl_804A78B0;
}

// ---- Wdry_ctor_8020282C.cpp ----
extern void* lbl_804AB1F0[];


WDRY::WDRY() {
    *(void**)this = lbl_804AB1F0;
}

// ---- Esry_ctor_80202868.cpp ----
extern void* lbl_804AB170[];


ESRY::ESRY() {
    *(void**)this = lbl_804AB170;
}

// ---- Shlt_ctor_802028A4.cpp ----
extern void* lbl_804A0FF8[];


SHLT::SHLT() {
    *(void**)this = lbl_804A0FF8;
}

// ---- Rank_ctor_802028E0.cpp ----
extern void* lbl_804A8F74[];


RANK::RANK() {
    *(void**)this = lbl_804A8F74;
}

// ---- Hnry_ctor_8020291C.cpp ----
extern void* lbl_804AB098[];


HNRY::HNRY() {
    *(void**)this = lbl_804AB098;
}

// ---- Bldf_ctor_80202958.cpp ----
extern void* lbl_804A8EF8[];


BLDF::BLDF() {
    *(void**)this = lbl_804A8EF8;
}

// ---- Focs_ctor_80202994.cpp ----
extern void* lbl_804A8EA0[];


FOCS::FOCS() {
    *(void**)this = lbl_804A8EA0;
}

// ---- Pnpc_ctor_802029D0.cpp ----
extern void* lbl_804A8E40[];


PNPC::PNPC() {
    *(void**)this = lbl_804A8E40;
}

// ---- Rail_ctor_80202A0C.cpp ----
extern void* lbl_8049C770[];


RAIL::RAIL() {
    *(void**)this = lbl_8049C770;
}

// ---- Zosh_ctor_80202A48.cpp ----
extern "C" void* fn_801D30B8(void* this_);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern void* lbl_804A5810[];
extern void* lbl_804A48B0[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];



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
    __dt__5ActorFv(localTemp, 0);
}

// ---- Door_ctor_80202ACC.cpp ----
extern void* lbl_804A8D88[];


DOOR::DOOR() {
    *(void**)this = lbl_804A8D88;
}

// ---- Key0_ctor_80202B08.cpp ----
extern void* lbl_804A8CD8[];


KEY0::KEY0() {
    *(void**)this = lbl_804A8CD8;
}

// ---- Lsti_ctor_80202B44.cpp ----
extern void* lbl_804A8C80[];


LSTI::LSTI() {
    *(void**)this = lbl_804A8C80;
}

// ---- Wizr_ctor_80202B80.cpp ----
extern void* lbl_804A0EDC[];


WIZR::WIZR() {
    *(void**)this = lbl_804A0EDC;
}

// ---- Swnp_ctor_80202BBC.cpp ----
extern void* lbl_804A8C28[];


SWNP::SWNP() {
    *(void**)this = lbl_804A8C28;
}

// ---- Cksw_ctor_80202BF8.cpp ----
extern void* lbl_804A8BD0[];


CKSW::CKSW() {
    *(void**)this = lbl_804A8BD0;
}

// ---- Tngl_ctor_80202C34.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804B0478[];


TNGL::TNGL() : Actor() {
    *(void**)this = lbl_804B0478;
    __construct_array((char*)this + 0x260, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Stal_ctor_80202C8C.cpp ----
extern void* lbl_804A0CD8[];


STAL::STAL() {
    *(void**)this = lbl_804A0CD8;
}

// ---- Wrtc_ctor_80202CC8.cpp ----
extern void* lbl_8049C678[];


WRTC::WRTC() {
    *(void**)this = lbl_8049C678;
}

// ---- Lwsw_ctor_80202D04.cpp ----
extern void* lbl_804A8B78[];


LWSW::LWSW() {
    *(void**)this = lbl_804A8B78;
}

// ---- Bwrt_ctor_80202D40.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern void* lbl_8049C718[];


BWRT::BWRT() {
    *(void**)this = lbl_8049C718;
    *(u8*)((char*)this + 0x29c) = 0;
}

// ---- Bfin_ctor_80202D84.cpp ----
extern void* lbl_804B0380[];


BFIN::BFIN() {
    *(void**)this = lbl_804B0380;
}

// ---- Wtsw_ctor_80202DC0.cpp ----
extern void* lbl_804A8B20[];


WTSW::WTSW() {
    *(void**)this = lbl_804A8B20;
}

// ---- Znsw_ctor_80202DFC.cpp ----
extern void* lbl_804A8AC8[];


ZNSW::ZNSW() {
    *(void**)this = lbl_804A8AC8;
}

// ---- Lplk_ctor_80202E38.cpp ----
extern void* lbl_8049C578[];


LPLK::LPLK() {
    *(void**)this = lbl_8049C578;
}

// ---- Iwag_ctor_80202E74.cpp ----
extern void* lbl_8049C46C[];


IWAG::IWAG() {
    *(void**)this = lbl_8049C46C;
}

// ---- Oiwa_ctor_80202EB0.cpp ----
extern void* lbl_8049C4C0[];


OIWA::OIWA() {
    *(void**)this = lbl_8049C4C0;
}

// ---- Nzmi_ctor_80202EEC.cpp ----
extern void* lbl_8049C400[];


NZMI::NZMI() {
    *(void**)this = lbl_8049C400;
}

// ---- Blze_ctor_80202F28.cpp ----
extern void* lbl_804A8A50[];


BLZE::BLZE() {
    *(void**)this = lbl_804A8A50;
}

// ---- Fire_ctor_80202F64.cpp ----
extern void* lbl_804A89F0[];


FIRE::FIRE() {
    *(void**)this = lbl_804A89F0;
}

// ---- Niwa_ctor_80202FA0.cpp ----
extern void* lbl_804AB8C0[];


NIWA::NIWA() {
    *(void**)this = lbl_804AB8C0;
}

// ---- Bgwc_ctor_80202FDC.cpp ----
extern void* lbl_804A8998[];


BGWC::BGWC() {
    *(void**)this = lbl_804A8998;
}

// ---- Dosn_ctor_80203018.cpp ----
extern void* lbl_804A8940[];


DOSN::DOSN() {
    *(void**)this = lbl_804A8940;
}

// ---- Tlk2_ctor_80203054.cpp ----
extern void* lbl_804AFAD8[];


TLK2::TLK2() {
    *(void**)this = lbl_804AFAD8;
}

// ---- Slr4_ctor_80203090.cpp ----
extern void* lbl_804A0B90[];


SLR4::SLR4() {
    *(void**)this = lbl_804A0B90;
}

// ---- Sbal_ctor_802030CC.cpp ----
extern void* lbl_804AB9C0[];


SBAL::SBAL() {
    *(void**)this = lbl_804AB9C0;
}

// ---- Swel_ctor_80203108.cpp ----
extern void* lbl_804A88E8[];


SWEL::SWEL() {
    *(void**)this = lbl_804A88E8;
}

// ---- Lift_ctor_80203144.cpp ----
extern void* lbl_804A6F6C[];


LIFT::LIFT() {
    *(void**)this = lbl_804A6F6C;
}

// ---- Ry02_ctor_80203180.cpp ----
extern void* lbl_804AB850[];


RY02::RY02() {
    *(void**)this = lbl_804AB850;
}

// ---- Deth_ctor_802031BC.cpp ----
extern void* lbl_804A886C[];


CRTH::CRTH() {
    *(void**)this = lbl_804A886C;
}

// ---- Swor_ctor_802031F8.cpp ----
extern void* lbl_804A8800[];


SWOR::SWOR() {
    *(void**)this = lbl_804A8800;
}

// ---- Popo_ctor_80203234.cpp ----
extern void* lbl_804A0868[];


POPO::POPO() {
    *(void**)this = lbl_804A0868;
}

// ---- Wood_ctor_80203270.cpp ----
extern void* lbl_804A87A8[];


WOOD::WOOD() {
    *(void**)this = lbl_804A87A8;
}

// ---- fn_802032AC_ctor.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804A0810[];


fn_802032AC_actor::fn_802032AC_actor() : Actor() {
    *(void**)this = lbl_804A0810;
    __construct_array((char*)this + 0x29c, (void*)fn_8003B2CC, 0, 0xc, 0xa);
}

// ---- Peff_ctor_80203304.cpp ----
extern void* lbl_804A6E20[];


PEFF::PEFF() {
    *(void**)this = lbl_804A6E20;
}

// ---- Slsd_ctor_80203340.cpp ----
extern void* lbl_804A85E0[];


SLSD::SLSD() {
    *(void**)this = lbl_804A85E0;
}

// ---- Sstn_ctor_8020337C.cpp ----
extern void* lbl_804A8750[];


SSTN::SSTN() {
    *(void**)this = lbl_804A8750;
}

// ---- Skul_ctor_802033B8.cpp ----
extern void* lbl_804A8588[];


SKUL::SKUL() {
    *(void**)this = lbl_804A8588;
}

// ---- Talk_ctor_802033F4.cpp ----
extern void* lbl_804AF548[];


TALK::TALK() {
    *(void**)this = lbl_804AF548;
}

// ---- Trch_ctor_80203430.cpp ----
extern void* lbl_804A8520[];


TRCH::TRCH() {
    *(void**)this = lbl_804A8520;
}

// ---- Scre_ctor_8020346C.cpp ----
extern void* lbl_804AF4C0[];


SCRE::SCRE() {
    *(void**)this = lbl_804AF4C0;
}

// ---- Spot_ctor_802034A8.cpp ----
extern void* lbl_804A84C8[];


SPOT::SPOT() {
    *(void**)this = lbl_804A84C8;
}

// ---- Yaji_ctor_802034E4.cpp ----
extern void* lbl_804A8470[];


YAJI::YAJI() {
    *(void**)this = lbl_804A8470;
}

// ---- Bome_ctor_80203520.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_80203594(void);
extern void* lbl_804A0738[];


BOME::BOME() : Actor() {
    *(void**)this = lbl_804A0738;
    __construct_array((char*)this + 0x274, (void*)fn_80203594, 0, 0x18, 5);
    __construct_array((char*)this + 0x2ec, (void*)fn_80203594, 0, 0x18, 5);
}

// ---- stub_80203594.cpp ----
// Empty virtual-hook stub (see Game/ActorDefaultHooks.cpp).
extern "C" void fn_80203594(void) {}

// ---- Kmri_ctor_80203598.cpp ----
extern void* lbl_804A8418[];


KMRI::KMRI() {
    *(void**)this = lbl_804A8418;
}

// ---- Tflr_ctor_802035D4.cpp ----
extern void* lbl_804A83A0[];


TFLR::TFLR() {
    *(void**)this = lbl_804A83A0;
}

// ---- Knbn_ctor_80203610.cpp ----
extern void* lbl_804AF428[];


KNBN::KNBN() {
    *(void**)this = lbl_804AF428;
}

// ---- Plas_ctor_8020364C.cpp ----
extern void* lbl_804A8338[];


PLAS::PLAS() {
    *(void**)this = lbl_804A8338;
}

// ---- Itms_ctor_80203688.cpp ----
extern void* lbl_804A82A8[];


ITMS::ITMS() {
    *(void**)this = lbl_804A82A8;
}

// ---- Poon_ctor_802036C4.cpp ----
extern void* lbl_804A06C0[];


Poon::Poon() {
    *(void**)this = lbl_804A06C0;
}

// ---- Skil_ctor_80203700.cpp ----
extern void* lbl_804A8250[];


SKIL::SKIL() {
    *(void**)this = lbl_804A8250;
}

// ---- Mozo_ctor_8020373C.cpp ----
extern void* lbl_804A0668[];


MOZO::MOZO() {
    *(void**)this = lbl_804A0668;
}

// ---- Bfry_ctor_80203778.cpp ----
extern void* lbl_804AF338[];


BERY::BERY() {
    *(void**)this = lbl_804AF338;
}

// ---- Pont_ctor_802037B4.cpp ----
extern void* lbl_804A81C8[];


PONT::PONT() {
    *(void**)this = lbl_804A81C8;
}

// ---- Arrw_ctor_802037F0.cpp ----
extern void* lbl_804A05E0[];


ARRW::ARRW() {
    *(void**)this = lbl_804A05E0;
}

// ---- Trap_ctor_8020382C.cpp ----
extern void* lbl_804A04D8[];


TRAP::TRAP() {
    *(void**)this = lbl_804A04D8;
}

// ---- Thrn_ctor_80203868.cpp ----
extern void* lbl_804A8170[];


THRN::THRN() {
    *(void**)this = lbl_804A8170;
}

// ---- Swev_ctor_802038A4.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern void* lbl_804A8638[];


SWEV::SWEV() {
    *(void**)this = lbl_804A8638;
    *(s32*)((char*)this + 0x2dc) = -1;
}

// ---- Ball_ctor_802038E8.cpp ----
extern void* lbl_804AB968[];


BALL::BALL() {
    *(void**)this = lbl_804AB968;
}

// ---- Bpoh_ctor_80203924.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern "C" void fn_8009711C(void*); // weak JUtility::TColor::TColor()
extern void* lbl_804A0440[];


BPOH::BPOH() : Actor() {
    *(void**)this = lbl_804A0440;
    __construct_array((char*)this + 0x2b8, (void*)fn_8003B2CC, 0, 0xc, 4);
    __construct_array((char*)this + 0x2f4, (void*)fn_8009711C, 0, 0x4, 3);
}

// ---- Shtr_ctor_80203998.cpp ----
extern void* lbl_804A8118[];


SHTR::SHTR() {
    *(void**)this = lbl_804A8118;
}

// ---- Fary_ctor_802039D4.cpp ----
extern void* lbl_804A03B8[];


EZRY::EZRY() {
    *(void**)this = lbl_804A03B8;
}

// ---- Swt4_ctor_80203A10.cpp ----
extern void* lbl_804A80A0[];


SWT4::SWT4() {
    *(void**)this = lbl_804A80A0;
}

// ---- Ryrn_ctor_80203A4C.cpp ----
extern void* lbl_804A8010[];


RYRN::RYRN() {
    *(void**)this = lbl_804A8010;
}

// ---- Mtbo_ctor_80203A88.cpp ----
extern void* lbl_804AF018[];


MTBO::MTBO() {
    *(void**)this = lbl_804AF018;
}

// ---- Tkyu_ctor_80203AC4.cpp ----
extern void* lbl_804ABA38[];


TKYU::TKYU() {
    *(void**)this = lbl_804ABA38;
}

// ---- Flme_ctor_80203B00.cpp ----
extern void* lbl_804A0330[];


FLME::FLME() {
    *(void**)this = lbl_804A0330;
}

// ---- Keth_ctor_80203B3C.cpp ----
extern void* lbl_804A02B8[];


KETH::KETH() {
    *(void**)this = lbl_804A02B8;
}

// ---- Boyo_ctor_80203B78.cpp ----
extern void* lbl_804A0260[];


BOYO::BOYO() {
    *(void**)this = lbl_804A0260;
}

// ---- Imup_ctor_80203BB4.cpp ----
extern void* lbl_804A01D0[];


IMUP::IMUP() {
    *(void**)this = lbl_804A01D0;
}

// ---- Slr2_ctor_80203BF0.cpp ----
extern void* lbl_804A00C8[];

extern "C" void* fn_80203BF0(void* this_) {
    __ct__5ActorFv(this_);
    *(void**)this_ = lbl_804A00C8;
    return this_;
}

// ---- Tkta_ctor_80203C2C.cpp ----
extern void* lbl_8049FD50[];


TKTA::TKTA() {
    *(void**)this = lbl_8049FD50;
}

// ---- Expl_ctor_80203C68.cpp ----
extern void* lbl_804A7FB8[];


EXPL::EXPL() {
    *(void**)this = lbl_804A7FB8;
}

// ---- Slr1_ctor_80203CA4.cpp ----
extern void* lbl_8049FCA0[];


SLR1::SLR1() {
    *(void**)this = lbl_8049FCA0;
}

// ---- Swth_ctor_80203CE0.cpp ----
extern void* lbl_804A7F38[];


SWTH::SWTH() {
    *(void**)this = lbl_804A7F38;
}

// ---- Hbmb_ctor_80203D1C.cpp ----
extern void* lbl_8049F784[];


HBMB::HBMB() {
    *(void**)this = lbl_8049F784;
}

// ---- Hino_ctor_80203D58.cpp ----
extern void* lbl_8049F9B4[];


HINO::HINO() {
    *(void**)this = lbl_8049F9B4;
}

// ---- Goal_ctor_80203D94.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_804A7EB0[];


GOAL::GOAL() : Actor() {
    *(void**)this = lbl_804A7EB0;
    __construct_array((char*)this + 0x264, (void*)fn_8003B2CC, 0, 0xc, 4);
}

// ---- Bhrt_ctor_80203DEC.cpp ----
extern void* lbl_804A7E58[];


BHRT::BHRT() {
    *(void**)this = lbl_804A7E58;
}

// ---- Dgtl_ctor_80203E28.cpp ----

// (dup) extern "C" void __construct_array(void* arr, void* ctor, s32 unused, u32 elemSize, u32 count);
extern "C" void fn_8003B2CC(void*); // weak JGeometry::TVec3<f32>::TVec3()
extern void* lbl_8049F6C8[];


DGTL::DGTL() : Actor() {
    *(void**)this = lbl_8049F6C8;
    __construct_array((char*)this + 0x2c0, (void*)fn_8003B2CC, 0, 0xc, 0xa);
    __construct_array((char*)this + 0x3d8, (void*)fn_8003B2CC, 0, 0xc, 0x50);
}

// ---- Oktm_ctor_80203E9C.cpp ----
extern void* lbl_8049F5D8[];


OKTM::OKTM() {
    *(void**)this = lbl_8049F5D8;
}

// ---- Hart_ctor_80203ED8.cpp ----
extern void* lbl_8049F4F0[];


HART::HART() {
    *(void**)this = lbl_8049F4F0;
}

// ---- Gold_ctor_80203F14.cpp ----
extern void* lbl_804AB660[];


GNLD::GNLD() {
    *(void**)this = lbl_804AB660;
}

// ---- Ddrk_ctor_80203F50.cpp ----
extern void* lbl_8049F498[];


DBRK::DBRK() {
    *(void**)this = lbl_8049F498;
}

// ---- Bzbr_ctor_80203F8C.cpp ----
extern void* lbl_8049F444[];


BZBR::BZBR() {
    *(void**)this = lbl_8049F444;
}

// ---- Blck_ctor_80203FC8.cpp ----
extern void* lbl_804A7A10[];


BLCK::BLCK() {
    *(void**)this = lbl_804A7A10;
}

// ---- Peac_ctor_80204004.cpp ----
extern void* lbl_8049F3B0[];


PEAC::PEAC() {
    *(void**)this = lbl_8049F3B0;
}

// ---- Tubo_ctor_80204040.cpp ----
extern void* lbl_804A9428[];


TUBO::TUBO() {
    *(void**)this = lbl_804A9428;
}

// ---- Rock_ctor_8020407C.cpp ----
extern void* lbl_804A9480[];


ROCK::ROCK() {
    *(void**)this = lbl_804A9480;
}

// ---- Warp_ctor_802040B8.cpp ----
extern void* lbl_804A6DC8[];


WARP::WARP() {
    *(void**)this = lbl_804A6DC8;
}

// ---- Bord_ctor_802040F4.cpp ----
extern void* lbl_804A94D8[];


BORD::BORD() {
    *(void**)this = lbl_804A94D8;
}

// ---- Ston_ctor_80204130.cpp ----
extern void* lbl_804A93D0[];


STON::STON() {
    *(void**)this = lbl_804A93D0;
}

// ---- Gene_ctor_8020416C.cpp ----
extern void* lbl_804A9328[];


GENE::GENE() {
    *(void**)this = lbl_804A9328;
}

// ---- Gras_ctor_802041A8.cpp ----
extern void* lbl_804A92D0[];


FGAS::FGAS() {
    *(void**)this = lbl_804A92D0;
}

// ---- Pooh_ctor_802041E4.cpp ----
extern void* lbl_8049F330[];


POOH::POOH() {
    *(void**)this = lbl_8049F330;
}

// ---- Amos_ctor_80204220.cpp ----
extern void* lbl_8049F260[];


AMOS::AMOS() {
    *(void**)this = lbl_8049F260;
}

// ---- Okta_ctor_8020425C.cpp ----
extern void* lbl_8049F208[];


OKTA::OKTA() {
    *(void**)this = lbl_8049F208;
}

// ---- Rupy_ctor_80204298.cpp ----
extern void* lbl_804AB6D8[];


RUPY::RUPY() {
    *(void**)this = lbl_804AB6D8;
}


// ---- CRNV / DMNR / OPGA / DMGA ctors, ARSH / ZNSH deleting dtors ----
extern void* lbl_8049ED30[];
extern void* lbl_8049E500[];
extern void* lbl_8049E350[];
extern void* lbl_8049DD68[];

CRNV::CRNV() {
    *(void**)this = lbl_8049ED30;
    m230 = 0;
    m234 = 0;
    m238 = -1;
    m23C = lbl_8053F830;
    fn_801D267C(&m240);
    m278 = 0;
    m27C = 0;
}

DMNR::DMNR() {
    *(void**)this = lbl_8049E500;
    m230 = 0;
    m234 = lbl_8053F830;
    m238 = lbl_8053F830;
    m23C = 0;
}

OPGA::OPGA() {
    *(void**)this = lbl_8049E350;
    m230 = 0;
    m231 = 0;
    m234 = 0;
    m238 = 0;
    m23C = -1;
    m240 = -1;
    fn_801D267C(&m244);
    fn_801D267C(&m27C);
}

DMGA::DMGA() {
    *(void**)this = lbl_8049DD68;
    m230 = 0;
    m234 = 0;
    m238 = lbl_8053F830;
    m23C = lbl_8053F830;
    fn_801D267C(&m274);
}

// ZNSH / ARSH deleting dtors (inlined ItemBase-style dtor chain).
void operator delete(void* p);
extern "C" void* fn_802042D4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5810;
        if (this_ != 0) {
            *(void**)p = lbl_804A48B0;
            if (this_ != 0) {
                *(void**)p = lbl_804A4808;
                if (p + 0x270 != 0) {
                    if (p + 0x294 != 0) {
                        *(void**)(p + 0x294) = lbl_8049CC34;
                    }
                }
                __dt__5ActorFv(this_, 0);
            }
        }
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void* fn_80204374(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A58B4;
        if (this_ != 0) {
            *(void**)p = lbl_804A48B0;
            if (this_ != 0) {
                *(void**)p = lbl_804A4808;
                if (p + 0x270 != 0) {
                    if (p + 0x294 != 0) {
                        *(void**)(p + 0x294) = lbl_8049CC34;
                    }
                }
                __dt__5ActorFv(this_, 0);
            }
        }
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
