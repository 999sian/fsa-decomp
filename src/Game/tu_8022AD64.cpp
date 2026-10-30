#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"

#pragma auto_inline off

struct Player;
struct PlayerManager {
    void* vtable;
    Player* players[4];
};

extern "C" PlayerManager* lbl_8053AC90;
extern "C" const f32 lbl_80540008;
extern "C" const f32 lbl_8054000C;
extern "C" const f32 lbl_80540014;
extern "C" const f32 lbl_80540018;
extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053AC98;
extern "C" void* lbl_8053AD70;
extern "C" void* lbl_8053AF80;

static inline u8 isPlayerEnabled(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (index < 0) return 0;
    if (index >= 4) return 0;
    if (lbl_8053AC90->players[index] == NULL) return 0;
    return *((u8*)lbl_8053AC90->players[index] + 0xcac);
}

extern "C" {
int fn_80240AF0(Player*);
int fn_802486A0(Player*);
int fn_80257DB4(Player*);
int fn_802416C4(Player*);
int fn_80257DB4(Player*);
int fn_8023FC08(Player*);
int fn_8023FC24(Player*);
int fn_8023FFAC(Player*);
int fn_802454C0(Player*);
int fn_802456FC(Player*);
int fn_80245938(Player*);
int fn_80245B74(Player*);
int fn_80245DB0(Player*);
int fn_80245FEC(Player*);
int fn_80246228(Player*);
u8 fn_802408C0(Player*);
int fn_802486A0(Player*);
int GetBusyLocked(Player*);
int fn_8024BB94(Player*);
int Player_GetField_0xce8(Player*);
int fn_8024FF6C(Player*);
int fn_802517E4(Player*);
int fn_80241478(Player*);
int fn_80250090(Player*);
int fn_80250ACC(Player*);
int fn_80250D30(Player*);
int fn_8024F630(Player*);
int fn_8028FC2C(Player*);
int fn_80240818(Player*);
int fn_8024AFF8(Player*);
int fn_8024B24C(Player*);
int fn_80248778(Player*);
int fn_80248970(Player*);
int Player_IsLinked(Player*);
int fn_8024C35C(Player*);
int fn_80240DCC(Player*);
int fn_8024C458(Player*);
int fn_8024E03C(Player*);
int fn_8024E060(Player*);
int Player_GetField_0x454(Player*);
int fn_8024D98C(Player*);
int fn_8024DCD0(Player*);
int fn_8025FEDC(Player*);
int fn_8025FF70(Player*);
int fn_8026000C(Player*);
int fn_802413F0(Player*);
int fn_80241230(Player*);
int fn_802412A4(Player*);
int fn_80240B84(Player*);
int fn_80240888(Player*);
int GetField_0xcfe(Player*);
int fn_80240AD4(Player*);
int fn_80240AF0(Player*);
int fn_80240AF8(Player*);
int fn_80240B00(Player*);
int fn_80240B20(Player*);
int fn_80240B5C(Player*);
int fn_80240B70(Player*);
int fn_80240D50(Player*);
int fn_80240628(Player*);
int Player_GetLinkTargetIndex(Player*);
int fn_802466B4(Player*);
int fn_80247534(Player*);
int fn_80247564(Player*);
int fn_80246904(Player*, int);
int fn_80246B10(Player*, int);
int fn_80246D1C(Player*, int);
f32 fn_80246F28(Player*);
f32 fn_8024712C(Player*);
f32 fn_80247330(Player*);
void fn_8024B9E8(Player*);
void fn_8024BAEC(Player*);
void fn_80248FF0(Player*);
void fn_8024B274(Player*);
void fn_8023FBF0(Player*);
void IncrementField_0x1224(Player*);
void fn_8023FC10(Player*, int);
void fn_80241B44(Player*, f32*);
void fn_8024B2BC(Player*, JGeometry::TVec3<f32>*);
void fn_8024E020(Player*, const JGeometry::TVec3<f32>&);
void fn_8024EFF8(Player*, int);
void fn_8024F54C(Player*, int);
void fn_8024F0E8(Player*, int);
int fn_80241E28(Player*, int, const JGeometry::TVec3<f32>&);
int fn_8025EDD4(Player*, int, const JGeometry::TVec3<f32>&);
int fn_8024DA64(Player*, int, u8);
int fn_8024D99C(Player*, const JGeometry::TVec3<f32>&, u8);
void fn_80248004(Player*, int, int);
void fn_8024B298(Player*, int, JGeometry::TVec2<f32>*);
void fn_8025EE0C(Player*, int, const JGeometry::TVec3<f32>&);
void fn_802408C8(Player*, int, const JGeometry::TVec3<f32>&);
int fn_8024B108(Player*, int);
int fn_8025AA24(Player*, int);
int fn_8025AA8C(Player*, int);
int ClaimField_0x11f4(Player*, int);
int fn_8025EF68(Player*, int);
int fn_8025EE34(Player*, int);
int fn_8025EE48(Player*, int);
int fn_8024C460(Player*, int);
int fn_8024C4C4(Player*, int);
int fn_8024C5A0(Player*, int);
int fn_8024C828(Player*, int);
int fn_8025FDD0(Player*, const JGeometry::TVec3<f32>&);
int fn_8024EFA0(Player*, u8);
int fn_80260048(Player*, int);
int fn_802600A0(Player*, int);
int fn_802426E0(Player*, int);
int fn_80242704(Player*, int);
int fn_80251BFC(Player*, int);
int fn_80240670(Player*);
int fn_8025EFFC(Player*, int, u8, u8);
int fn_8024DC00(Player*, const JGeometry::TVec3<f32>&, int, u8, u8, u8, u8);
int fn_80290070(Player*, int, const JGeometry::TVec3<f32>&, const JGeometry::TVec3<f32>&, int);
void fn_80138B7C(void*);
void fn_8029D898(void*, int);
void fn_80248DD8(Player*);
void fn_8026FC8C(Player*);
void fn_80241E64(Player*);
void fn_80242560(Player*);
void fn_80248DAC(Player*);
void fn_80248E94(Player*, int);
u8 fn_80241BA0(Player*, int, const JGeometry::TVec3<f32>&, u8);
int fn_80241DD0(Player*, int, const JGeometry::TVec3<f32>&);
void fn_8023FF90(Player*, const JGeometry::TVec3<f32>&);
bool fn_8022E438(int, int);
void SetBusyLocked(Player*);
const JGeometry::TVec2<f32>& fn_802422C4(Player*);
u8 fn_8037F1E4(int);
u8 fn_8024CA0C(Player*, int);
void fn_8024CAC8(Player*, int, int, u8, u8);
void fn_8024CD20(Player*, const JGeometry::TBox2<f32>&, int, int, u8, u8);
u8 fn_8024D058(Player*, u8);
void fn_8037AE30(void*);
void fn_8025F698(Player*, int);
void fn_802422D0(Player*);
void fn_80457F6C(void*);
int fn_80242624(Player*, const JGeometry::TVec3<f32>&);
int GetPtrField_0x4(Player*);

static inline int pIsLinked(int i) {
    if (lbl_8053AC90 == NULL) return 0;
    if (!isPlayerEnabled(i)) return 0;
    return Player_IsLinked(lbl_8053AC90->players[i]);
}
static inline int pLinkTarget(int i) {
    if (lbl_8053AC90 == NULL) return -1;
    if (!isPlayerEnabled(i)) return -1;
    return Player_GetLinkTargetIndex(lbl_8053AC90->players[i]);
}
extern "C" u8 Player_GetCapabilityFlag(Player* p);
extern "C" u8 fn_8023F264(int idx);
extern "C" int fn_80241964(Player*);
static inline u8 isEnabled2(int i) {
    if (lbl_8053AC90 == NULL) return 0;
    if (i < 0) return 0;
    if (i >= 4) return 0;
    if (lbl_8053AC90->players[i] == NULL) return 0;
    return Player_GetCapabilityFlag(lbl_8053AC90->players[i]);
}
static inline int isLinked2(int i) {
    if (lbl_8053AC90 == NULL) return 0;
    if (!isEnabled2(i)) return 0;
    return Player_IsLinked(lbl_8053AC90->players[i]);
}
static inline int linkTarget2(int i) {
    if (lbl_8053AC90 == NULL) return -1;
    if (!isEnabled2(i)) return -1;
    return Player_GetLinkTargetIndex(lbl_8053AC90->players[i]);
}
static inline int isLinked3(int i) {
    if (lbl_8053AC90 == NULL) return 0;
    if (!fn_8023F264(i)) return 0;
    return Player_IsLinked(lbl_8053AC90->players[i]);
}
static inline int linkTarget3(int i) {
    if (lbl_8053AC90 == NULL) return -1;
    if (!fn_8023F264(i)) return -1;
    return Player_GetLinkTargetIndex(lbl_8053AC90->players[i]);
}

void fn_8022AD64()
{
    fn_80138B7C(lbl_8053AAF8);
}

void fn_8022AD88()
{
    fn_8029D898(lbl_8053AC98, 0x19);
}

u8 fn_8022ADB0()
{
    if (lbl_8053AC90 == NULL) return 0;
    return *((u8*)lbl_8053AC90 + 0x73);
}

void fn_8022ADCC()
{
    if (lbl_8053AC90 == NULL) return;
    *((u8*)lbl_8053AC90 + 0x73) = 0;
}

void fn_8022ADE4()
{
    if (lbl_8053AC90 == NULL) return;
    *((u8*)lbl_8053AC90 + 0x73) = 1;
}

static inline u8 playerMgrByte(u32 offset)
{
    if (lbl_8053AC90 == NULL) return 0;
    return *((u8*)lbl_8053AC90 + offset);
}

u8 fn_8022ADFC()
{
    u8 r;
    if (lbl_8053AC90 == NULL) return 0;
    if (playerMgrByte(0x6c)) return 1;
    if (playerMgrByte(0x6d)) return 1;
    if (playerMgrByte(0x6e)) return 1;
    if (playerMgrByte(0x6f)) return 1;
    if (playerMgrByte(0x70)) return 1;
    if (playerMgrByte(0x71)) return 1;
    if (playerMgrByte(0x72)) return 1;
    return 0;
}


u8 fn_8022AF10()
{
    if (lbl_8053AC90 == NULL) return 0;
    return *((u8*)lbl_8053AC90 + 0x72);
}

void fn_8022AF2C()
{
    if (lbl_8053AC90 == NULL) return;
    *((u8*)lbl_8053AC90 + 0x72) = 0;
}

void fn_8022AF44()
{
    if (lbl_8053AC90 == NULL) return;
    *((u8*)lbl_8053AC90 + 0x72) = 1;
}

u8 fn_8022AF5C()
{
    if (lbl_8053AC90 == NULL) return 0;
    return *((u8*)lbl_8053AC90 + 0x71);
}

void fn_8022AF78()
{
    if (lbl_8053AC90 == NULL) return;
    *((u8*)lbl_8053AC90 + 0x71) = 0;
    for (int index = 0; index < 4; index++) {
        if (isPlayerEnabled(index)) {
            fn_8024D98C(lbl_8053AC90->players[index]);
            fn_8024BAEC(lbl_8053AC90->players[index]);
            fn_80248E94(lbl_8053AC90->players[index], 0);
            fn_8026FC8C(lbl_8053AC90->players[index]);
        }
    }
}

void fn_8022B064()
{
    if (lbl_8053AC90 == NULL) return;
    *((u8*)lbl_8053AC90 + 0x71) = 1;
    for (int index = 0; index < 4; index++) {
        if (isPlayerEnabled(index)) {
            fn_8024D98C(lbl_8053AC90->players[index]);
            fn_80248DD8(lbl_8053AC90->players[index]);
        }
    }
}

void fn_8022B130()
{
    if (lbl_8053AC90 == NULL) return;
    *((u8*)lbl_8053AC90 + 0x70) = 0;
}

void fn_8022B148()
{
    if (lbl_8053AC90 == NULL) return;
    *((u8*)lbl_8053AC90 + 0x70) = 1;
}

u8 fn_8022B160()
{
    if (lbl_8053AC90 == NULL) return 0;
    return *((u8*)lbl_8053AC90 + 0x6f);
}

void fn_8022B17C()
{
    if (lbl_8053AC90 == NULL) return;
    *((u8*)lbl_8053AC90 + 0x6f) = 0;
}

void fn_8022B194()
{
    if (lbl_8053AC90 == NULL) return;
    *((u8*)lbl_8053AC90 + 0x6f) = 1;
}

u8 fn_8022B1AC()
{
    if (lbl_8053AC90 == NULL) return 0;
    return *((u8*)lbl_8053AC90 + 0x6e);
}

void fn_8022B1C8()
{
    if (lbl_8053AC90 == NULL) return;
    *((u8*)lbl_8053AC90 + 0x6e) = 0;
}

void fn_8022B1E0()
{
    if (lbl_8053AC90 == NULL) return;
    *((u8*)lbl_8053AC90 + 0x6e) = 1;
}

u8 fn_8022B1F8()
{
    if (lbl_8053AC90 == NULL) return 0;
    return *((u8*)lbl_8053AC90 + 0x6d);
}

void fn_8022B214()
{
    if (lbl_8053AC90 == NULL) return;
    *((u8*)lbl_8053AC90 + 0x6d) = 0;
}

void fn_8022B22C()
{
    if (lbl_8053AC90 == NULL) return;
    *((u8*)lbl_8053AC90 + 0x6d) = 1;
}

u8 fn_8022B244()
{
    if (lbl_8053AC90 == NULL) return 0;
    return *((u8*)lbl_8053AC90 + 0x6c);
}

void fn_8022B260()
{
    if (lbl_8053AC90 == NULL) return;
    *((u8*)lbl_8053AC90 + 0x6c) = 0;
}

void fn_8022B278()
{
    if (lbl_8053AC90 == NULL) return;
    *((u8*)lbl_8053AC90 + 0x6c) = 1;
    for (int index = 0; index < 4; index++) {
        if (isPlayerEnabled(index)) {
            fn_8026FC8C(lbl_8053AC90->players[index]);
        }
    }
}

static inline int p40AF0(int i) {
    if (lbl_8053AC90 == NULL) return 0;
    if (!isPlayerEnabled(i)) return 0;
    return fn_80240AF0(lbl_8053AC90->players[i]);
}
static inline int p486A0(int i) {
    if (lbl_8053AC90 == NULL) return 0;
    if (!isPlayerEnabled(i)) return 0;
    return fn_802486A0(lbl_8053AC90->players[i]);
}
static inline int pIsLinkedU8(int i) {
    if (lbl_8053AC90 == NULL) return 0;
    if (!isPlayerEnabled(i)) return 0;
    return Player_IsLinked(lbl_8053AC90->players[i]);
}
static inline int p416C4(int i) {
    if (lbl_8053AC90 == NULL) return 0;
    if (!isPlayerEnabled(i)) return 0;
    return fn_802416C4(lbl_8053AC90->players[i]);
}

int fn_8022B334(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if ((u8)p40AF0(index)) return 0;
    if (p486A0(index) == 4) {
        if (!(u8)fn_80257DB4(lbl_8053AC90->players[index])) return 0;
    } else if (p486A0(index) == 5) {
        if ((u8)pIsLinked(index)) {
            if (p416C4(index) != 7 || !(u8)fn_8024B24C(lbl_8053AC90->players[index])) return 0;
        }
        if (!(u8)fn_80257DB4(lbl_8053AC90->players[index])) return 0;
    } else {
        for (int i = 0; i < 4; i++) {
            if (isPlayerEnabled(i) && (index == i || fn_8022E438(index, i))) {
                if (!(u8)p40AF0(i) && !(u8)fn_80257DB4(lbl_8053AC90->players[i])) return 0;
            }
        }
    }
    return 1;
}

int fn_8022B7C4(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8023FC08(lbl_8053AC90->players[index]);
    return 0;
}

void fn_8022B860(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) fn_8023FC10(lbl_8053AC90->players[index], a0);
}

void fn_8022B8EC(int index, f32* a0)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) fn_80241B44(lbl_8053AC90->players[index], a0);
}

u8 fn_8022B978(int room, const JGeometry::TVec3<f32>& position, u8 mode)
{
    if (lbl_8053AC90 == NULL) return 0;
    for (int index = 0; index < 4; index++) {
        if (isPlayerEnabled(index) && (u8)fn_80241BA0(lbl_8053AC90->players[index], room, position, mode)) return 1;
    }
    return 0;
}

u8 fn_8022BA58(int room, const JGeometry::TVec3<f32>& position)
{
    if (lbl_8053AC90 == NULL) return 0;
    for (int index = 0; index < 4; index++) {
        if (isPlayerEnabled(index) && (u8)fn_80241DD0(lbl_8053AC90->players[index], room, position)) return 1;
    }
    return 0;
}

u8 fn_8022BB48(int room, const JGeometry::TVec3<f32>& position)
{
    if (lbl_8053AC90 == NULL) return 0;
    for (int index = 0; index < 4; index++) {
        if (isPlayerEnabled(index) && (u8)fn_80241E28(lbl_8053AC90->players[index], room, position)) return 1;
    }
    return 0;
}

int fn_8022BC38(int index, int a0, const JGeometry::TVec3<f32>& a1)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80241E28(lbl_8053AC90->players[index], a0, a1);
    return 0;
}

int fn_8022BCD4(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8023FC24(lbl_8053AC90->players[index]);
    return 0;
}

void fn_8022BD70()
{
    if (lbl_8053AC90 == NULL) return;
    for (int index = 0; index < 4; index++) {
        if (isPlayerEnabled(index)) fn_80241E64(lbl_8053AC90->players[index]);
    }
}

void fn_8022BE24(int index, const JGeometry::TVec3<f32>& position)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) {
        JGeometry::TVec3<f32> copy(position);
        fn_8023FF90(lbl_8053AC90->players[index], copy);
    }
}

int fn_8022BECC(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8023FFAC(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022BF68(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_802454C0(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022C004(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_802456FC(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022C0A0(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80245938(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022C13C(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80245B74(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022C1D8(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80245DB0(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022C274(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80245FEC(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022C310(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80246228(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022C3AC(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (index < 0) return 0;
    if (index >= 4) return 0;
    if (isPlayerEnabled(index)) return fn_802466B4(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022C46C(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (index < 0) return 0;
    if (index >= 4) return 0;
    if (isPlayerEnabled(index)) return fn_80246904(lbl_8053AC90->players[index], a0);
    return 0;
}

int fn_8022C52C(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (index < 0) return 0;
    if (index >= 4) return 0;
    if (isPlayerEnabled(index)) return fn_80246B10(lbl_8053AC90->players[index], a0);
    return 0;
}

int fn_8022C5EC(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (index < 0) return 0;
    if (index >= 4) return 0;
    if (isPlayerEnabled(index)) return fn_80246D1C(lbl_8053AC90->players[index], a0);
    return 0;
}

f32 fn_8022C6AC(int index)
{
    if (lbl_8053AC90 == NULL) return lbl_80540008;
    if (index < 0) return lbl_80540008;
    if (index >= 4) return lbl_80540008;
    if (isPlayerEnabled(index)) return fn_80246F28(lbl_8053AC90->players[index]);
    return lbl_80540008;
}

f32 fn_8022C76C(int index)
{
    if (lbl_8053AC90 == NULL) return lbl_80540008;
    if (index < 0) return lbl_80540008;
    if (index >= 4) return lbl_80540008;
    if (isPlayerEnabled(index)) return fn_8024712C(lbl_8053AC90->players[index]);
    return lbl_80540008;
}

f32 fn_8022C82C(int index)
{
    if (lbl_8053AC90 == NULL) return lbl_80540008;
    if (index < 0) return lbl_80540008;
    if (index >= 4) return lbl_80540008;
    if (isPlayerEnabled(index)) return fn_80247330(lbl_8053AC90->players[index]);
    return lbl_80540008;
}

int fn_8022C8EC(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (index < 0) return 0;
    if (index >= 4) return 0;
    if (isPlayerEnabled(index)) return fn_80247534(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022C9AC(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (index < 0) return 0;
    if (index >= 4) return 0;
    if (isPlayerEnabled(index)) return fn_80247564(lbl_8053AC90->players[index]);
    return 0;
}

void fn_8022CA6C(int index, int a0, int a1)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) fn_80248004(lbl_8053AC90->players[index], a0, a1);
}

int fn_8022CAF8(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_802486A0(lbl_8053AC90->players[index]);
    return 0;
}

void fn_8022CB94(int index)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) fn_8024B9E8(lbl_8053AC90->players[index]);
}

void fn_8022CC20(int index)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) fn_8024BAEC(lbl_8053AC90->players[index]);
}

int fn_8022CCAC(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return GetBusyLocked(lbl_8053AC90->players[index]);
    return 0;
}

void fn_8022CD48(int index)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) fn_80248FF0(lbl_8053AC90->players[index]);
}

int fn_80241380(Player*);
void fn_8027FA08(Player*, JGeometry::TVec3<f32>*);
extern JGeometry::TVec3<f32> lbl_804CF460;
static inline int playerLinkReady(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (!isPlayerEnabled(index)) return 0;
    return fn_80241380(lbl_8053AC90->players[index]);
}
static inline JGeometry::TVec3<f32>& playerPosition(int index)
{
    if (lbl_8053AC90 == NULL) return *(JGeometry::TVec3<f32>*)(u32)&lbl_804CF460;
    if (!isPlayerEnabled(index)) return *(JGeometry::TVec3<f32>*)(u32)&lbl_804CF460;
    return *(JGeometry::TVec3<f32>*)((u8*)lbl_8053AC90->players[index] + 8);
}
void ClearBusyLocked(Player*);
void fn_8022CDD4(int index)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) {
        for (int i = 0; i < 4; i++) {
            if (isPlayerEnabled(i) && (index == i || fn_8022E438(index, i))) {
                ClearBusyLocked(lbl_8053AC90->players[i]);
            }
        }
    }
}

void fn_8022CF08(int owner)
{
    if (lbl_8053AC90 == NULL) return;
    for (int index = 0; index < 4; index++) {
        if (isPlayerEnabled(index) && (owner == index || fn_8022E438(owner, index))) {
            SetBusyLocked(lbl_8053AC90->players[index]);
        }
    }
}

#pragma opt_loop_invariants off
f32 fn_8022CFE8(int index)
{
    if (lbl_8053AC90 == NULL) return lbl_80540008;
    f32 maximum = lbl_80540008;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && (u8)pIsLinked(i) && (u8)playerLinkReady(i) && fn_8022E438(index, i)) {
            JGeometry::TVec3<f32> pos;
            fn_8027FA08(lbl_8053AC90->players[i], &pos);
            if ((playerPosition(i) - pos).length() > maximum) {
                maximum = (playerPosition(i) - pos).length();
            }
        }
    }
    return maximum;
}
#pragma opt_loop_invariants reset
void fn_8024BB88(Player*);
void fn_8022D36C(int index)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) {
        for (int i = 0; i < 4; i++) {
            if (isPlayerEnabled(i) && fn_8022E438(index, i)) {
                fn_8024BB88(lbl_8053AC90->players[i]);
            }
        }
    }
}

int fn_8022D498(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024BB94(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022F514(int);
int fn_8022F3DC(int);
int fn_80234004(int);

static inline int linkMode3(int i) {
    if (lbl_8053AC90 == NULL) return 0;
    if (!fn_8023F264(i)) return 0;
    return fn_802486A0(lbl_8053AC90->players[i]);
}
static inline int linkCount3(int i) {
    if (lbl_8053AC90 == NULL) return 0;
    if (!fn_8023F264(i)) return 0;
    return fn_80240888(lbl_8053AC90->players[i]);
}
static inline int linkCount1(int i) {
    if (lbl_8053AC90 == NULL) return 0;
    if (!isPlayerEnabled(i)) return 0;
    return fn_80240888(lbl_8053AC90->players[i]);
}
static inline bool sameLinkDeep(int a, int b) {
    if (lbl_8053AC90 == NULL) return 0;
    if (a < 0) return 0;
    if (a >= 4) return 0;
    if (b < 0) return 0;
    if (b >= 4) return 0;
    if (!fn_8023F264(a)) return 0;
    if (!fn_8023F264(b)) return 0;
    if (a == b) return 1;
    if ((u8)fn_8022F514(a)) {
        if (b == fn_8022F3DC(a)) return 1;
        if (fn_8022F3DC(a) == fn_8022F3DC(b)) return 1;
        else return 0;
    }
    if ((u8)fn_8022F514(b)) return fn_8022F3DC(b) == a;
    return 0;
}
static inline bool sameLinkOuter(int a, int b) {
    if (lbl_8053AC90 == NULL) return 0;
    if (a < 0) return 0;
    if (a >= 4) return 0;
    if (b < 0) return 0;
    if (b >= 4) return 0;
    if (!isEnabled2(a)) return 0;
    if (!isEnabled2(b)) return 0;
    if (a == b) return 1;
    if ((u8)isLinked3(a)) {
        if (b == linkTarget3(a)) return 1;
        if (linkTarget3(a) == linkTarget3(b)) return 1;
        else return 0;
    }
    if ((u8)isLinked3(b)) return linkTarget3(b) == a;
    return 0;
}

int fn_8022EA0C(int idx);

static inline int lastLinkedPlayer(int target)
{
    if (lbl_8053AC90 == NULL) return -1;
    if (!isEnabled2(target)) return target;
    if ((u8)isLinked3(target)) {
        target = linkTarget3(target);
        if (lbl_8053AC90 == NULL) return -1;
        if (!fn_8023F264(target)) return target;
        if ((u8)fn_8022F514(target)) target = fn_8022EA0C(fn_8022F3DC(target));
        else switch (fn_8022CAF8(target)) {
        case 4: {
            int count;
            int scan;
            scan = target;
            count = 0;
            while (count < fn_80234004(target)) {
                ++count;
                ++scan;
                while (!fn_8022E438(scan, target)) ++scan;
            }
            target = scan;
            break;
        }
        default: break;
        }
    } else switch (linkMode3(target)) {
    case 4: {
        int count;
        int scan;
        scan = target;
        count = 0;
        while (count < linkCount3(target)) {
            ++count;
            ++scan;
            while (!sameLinkDeep(scan, target)) ++scan;
        }
        target = scan;
        break;
    }
    default: break;
    }
    return target;
}

int fn_8022D534(int idx) {
    int cVar;
    int iVar;

    if (lbl_8053AC90 == NULL) return 0;
    if (!isPlayerEnabled(idx)) return 0;
    if (lbl_8053AC90 == NULL) {
        cVar = 0;
    } else if (!isPlayerEnabled(idx)) {
        cVar = 1;
    } else {
        cVar = fn_80240670(lbl_8053AC90->players[idx]);
    }
    if ((u8)cVar) {
        iVar = fn_8022EA0C(idx);
        if (lbl_8053AC90 == NULL) return 0;
        return !isPlayerEnabled(iVar) ? 0 : Player_GetField_0xce8(lbl_8053AC90->players[iVar]);
    }
    if (lbl_8053AC90 == NULL) return 0;
    return !isPlayerEnabled(idx) ? 0 : Player_GetField_0xce8(lbl_8053AC90->players[idx]);
}

int fn_8022D75C(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return Player_GetField_0xce8(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022D7F8(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024FF6C(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022D894(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_802517E4(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022D930(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80241478(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022D9CC(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80250090(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022DA68(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80250ACC(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022DB04(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80250D30(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022DBA0(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024F630(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022DC3C(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8028FC2C(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022DCD8(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80240818(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022DD74(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024AFF8(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022DE10(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024B108(lbl_8053AC90->players[index], a0);
    return 0;
}

int fn_8022DEAC(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024B24C(lbl_8053AC90->players[index]);
    return 0;
}

void fn_8022DF48(int index)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) fn_8024B274(lbl_8053AC90->players[index]);
}

// Retail returns a reference to a stack temporary on both failure paths.
const JGeometry::TVec2<f32>& fn_8022DFD4(int index)
{
    if (lbl_8053AC90 == NULL) return JGeometry::TVec2<f32>(lbl_80540008, lbl_80540008);
    if (!isPlayerEnabled(index)) return JGeometry::TVec2<f32>(lbl_80540008, lbl_80540008);
    return fn_802422C4(lbl_8053AC90->players[index]);
}

void fn_8022E088(int index, int a0, JGeometry::TVec2<f32>* a1)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) fn_8024B298(lbl_8053AC90->players[index], a0, a1);
}

void fn_8022E114(int index, JGeometry::TVec3<f32>* a0)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) fn_8024B2BC(lbl_8053AC90->players[index], a0);
}

int fn_8022E1A0(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8025AA24(lbl_8053AC90->players[index], a0);
    return 0;
}

int fn_8022E23C(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8025AA8C(lbl_8053AC90->players[index], a0);
    return 0;
}

void fn_8022E2D8(int value)
{
    if (lbl_8053AC90 == NULL) return;
    for (int index = 0; index < 4; index++) {
        if (isPlayerEnabled(index)) ClaimField_0x11f4(lbl_8053AC90->players[index], value);
    }
}

int fn_8022E39C(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return ClaimField_0x11f4(lbl_8053AC90->players[index], a0);
    return 0;
}

extern "C" bool fn_8022E438(int a, int b)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (a < 0) return 0;
    if (a >= 4) return 0;
    if (b < 0) return 0;
    if (b >= 4) return 0;
    if (!isPlayerEnabled(a)) return 0;
    if (!isPlayerEnabled(b)) return 0;
    if (a == b) return 1;
    if ((u8)pIsLinked(a)) {
        if (b == pLinkTarget(a)) return 1;
        return (u8)(pLinkTarget(a) == pLinkTarget(b));
    }
    if ((u8)pIsLinked(b)) {
        return pLinkTarget(b) == a;
    }
    return 0;
}

int fn_8022E8D4(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80248778(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022E970(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80248970(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022EA0C(int index)
{
    if (lbl_8053AC90 == NULL) return -1;
    if (!isPlayerEnabled(index)) return index;
    if ((u8)pIsLinked(index)) return lastLinkedPlayer(pLinkTarget(index));
    if (p486A0(index) != 4) return index;
    int scan = index;
    int count = 0;
    while (count < linkCount1(index)) {
        ++scan;
        ++count;
        while (!sameLinkOuter(scan, index)) ++scan;
    }
    return scan;
}

int fn_8022F340(int index)
{
    if (lbl_8053AC90 == NULL) return -1;
    if (isPlayerEnabled(index)) return fn_80240628(lbl_8053AC90->players[index]);
    return -1;
}

int fn_8022F3DC(int index)
{
    if (lbl_8053AC90 == NULL) return -1;
    if (isPlayerEnabled(index)) return Player_GetLinkTargetIndex(lbl_8053AC90->players[index]);
    return -1;
}

int fn_8022F478(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80240670(lbl_8053AC90->players[index]);
    return 1;
}

int fn_8022F514(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return Player_IsLinked(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022F5B0(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024C35C(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022F64C(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80240DCC(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022F6E8(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8025EF68(lbl_8053AC90->players[index], a0);
    return 0;
}

int fn_8022F784(int index, int a0, const JGeometry::TVec3<f32>& a1)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8025EDD4(lbl_8053AC90->players[index], a0, a1);
    return 0;
}

void fn_8022F820(int index, int a0, const JGeometry::TVec3<f32>& a1)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) fn_8025EE0C(lbl_8053AC90->players[index], a0, a1);
}

int fn_8022F8AC(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8025EE34(lbl_8053AC90->players[index], a0);
    return 0;
}

int fn_8022F948(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8025EE48(lbl_8053AC90->players[index], a0);
    return 0;
}

int fn_8022F9E4(int index, int a0, u8 a1, u8 a2)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8025EFFC(lbl_8053AC90->players[index], a0, a1, a2);
    return 0;
}

int fn_8022FA80(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024C458(lbl_8053AC90->players[index]);
    return 0;
}

int fn_8022FB1C(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024C460(lbl_8053AC90->players[index], a0);
    return 0;
}

int fn_8022FBB8(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024C4C4(lbl_8053AC90->players[index], a0);
    return 0;
}

int fn_8022FC54(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024C5A0(lbl_8053AC90->players[index], a0);
    return 0;
}

int fn_8022FCF0(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024C828(lbl_8053AC90->players[index], a0);
    return 0;
}

int fn_8022FD8C(int value)
{
    if (lbl_8053AC90 == NULL) return -1;
    for (int index = 0; index < 4; index++) {
        if (isPlayerEnabled(index) && !fn_8037F1E4(index) && fn_8024CA0C(lbl_8053AC90->players[index], value)) return index;
    }
    return -1;
}

void fn_8022FE80(int index, int room, int handle, u8 mode, u8 flags)
{
    if (lbl_8053AC90 == NULL) return;
    fn_8024CAC8(lbl_8053AC90->players[index], room, handle, mode, flags);
}

void fn_8022FEB8(const JGeometry::TBox2<f32>& bounds, int room, int handle, u8 mode, u8 flags)
{
    if (lbl_8053AC90 == NULL) return;
    for (int index = 0; index < 4; index++) {
        if (isPlayerEnabled(index)) fn_8024CD20(lbl_8053AC90->players[index], bounds, room, handle, mode, flags);
    }
}

void fn_8022FF8C(int index, const JGeometry::TBox2<f32>& bounds, int room, int handle, u8 mode, u8 flags)
{
    if (lbl_8053AC90 == NULL) return;
    fn_8024CD20(lbl_8053AC90->players[index], bounds, room, handle, mode, flags);
}

void fn_8022FFC4(int index, const JGeometry::TVec3<f32>& a0)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) fn_8024E020(lbl_8053AC90->players[index], a0);
}

int fn_80230050(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024E03C(lbl_8053AC90->players[index]);
    return 0;
}

int fn_802300EC(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024E060(lbl_8053AC90->players[index]);
    return 0;
}

int fn_80230188(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return Player_GetField_0x454(lbl_8053AC90->players[index]);
    return 0;
}

u8 fn_80230224(int index, int value)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024D058(lbl_8053AC90->players[index], value);
    return 0;
}

int fn_802302C4(int index, int a0, u8 a1)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024DA64(lbl_8053AC90->players[index], a0, a1);
    return 0;
}

int fn_80230360(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024D98C(lbl_8053AC90->players[index]);
    return 0;
}

int fn_802303FC(int index, const JGeometry::TVec3<f32>& a0, u8 a1)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024D99C(lbl_8053AC90->players[index], a0, a1);
    return 0;
}

int fn_80230498(int index, const JGeometry::TVec3<f32>& a0, int a1, u8 a2, u8 a3, u8 a4, u8 a5)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024DC00(lbl_8053AC90->players[index], a0, a1, a2, a3, a4, a5);
    return 0;
}

u8 fn_80230534(int value)
{
    if (lbl_8053AC90 == NULL) return 0;
    u8 narrowed = (u8)value;
    for (int index = 0; index < 4; index++) {
        if (isPlayerEnabled(index) && !fn_8024D058(lbl_8053AC90->players[index], narrowed)) return 0;
    }
    fn_8037AE30(lbl_8053AD70);
    return 1;
}

int fn_8023061C(int index, int a1)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (!isPlayerEnabled(index)) return 0;
    u8 flag = a1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_8022E438(index, i) && !fn_8024D058(lbl_8053AC90->players[i], flag)) return 0;
    }
    return 1;
}

void fn_8037AE00(void*);
u8 fn_8023077C()
{
    if (lbl_8053AC90 == NULL) return 0;
    for (int index = 0; index < 4; index++) {
        if (isPlayerEnabled(index) && !(u8)fn_8024E060(lbl_8053AC90->players[index])) return 0;
    }
    for (int index = 0; index < 4; index++) {
        if (isPlayerEnabled(index) && !(u8)fn_8024DCD0(lbl_8053AC90->players[index])) return 0;
    }
    fn_8037AE00(lbl_8053AD70);
    return 1;
}

int fn_802308E0(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (!isPlayerEnabled(index)) return 0;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_8022E438(index, i) && !(u8)fn_8024E060(lbl_8053AC90->players[i])) return 0;
    }
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_8022E438(index, i) && !(u8)fn_8024DCD0(lbl_8053AC90->players[i])) return 0;
    }
    return 1;
}

int fn_80230AD4(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024DCD0(lbl_8053AC90->players[index]);
    return 0;
}

int fn_80230B70(int index)
{
    if (lbl_8053AC90 == NULL) return 2;
    if (isPlayerEnabled(index) == 0) return 2;
    return *(int*)((u8*)lbl_8053AC90->players[index] + 0x3e8);
}

void fn_80230BF4(int index, int value)
{
    if (lbl_8053AC90 == NULL) return;
    if (!isPlayerEnabled(index)) return;
    Player* player = lbl_8053AC90->players[index];
    *(int*)((u8*)player + 0x3e8) = value;
    *(int*)((u8*)player + 0x3dc) = value;
}

void fn_80230C6C(int index)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) fn_8025F698(lbl_8053AC90->players[index], 0);
}

int fn_80230CFC(int index)
{
    if (lbl_8053AC90 == NULL) return 2;
    if (isPlayerEnabled(index) == 0) return 2;
    return *(int*)((u8*)lbl_8053AC90->players[index] + 0x3dc);
}

int fn_80230D80(int index, const JGeometry::TVec3<f32>& a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8025FDD0(lbl_8053AC90->players[index], a0);
    return 0;
}

int fn_80230E1C(int index, u8 a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8024EFA0(lbl_8053AC90->players[index], a0);
    return 0;
}

void fn_80230EB8(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) fn_8024EFF8(lbl_8053AC90->players[index], a0);
}

void fn_80230F44(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) fn_8024F54C(lbl_8053AC90->players[index], a0);
}

void fn_80230FD0(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) fn_8024F0E8(lbl_8053AC90->players[index], a0);
}

int fn_8023105C(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8025FEDC(lbl_8053AC90->players[index]);
    return 0;
}

int fn_802310F8(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8025FF70(lbl_8053AC90->players[index]);
    return 0;
}

int fn_80231194(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_8026000C(lbl_8053AC90->players[index]);
    return 0;
}

int fn_80231230(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80260048(lbl_8053AC90->players[index], a0);
    return 0;
}

int fn_802312CC(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_802600A0(lbl_8053AC90->players[index], a0);
    return 0;
}

void fn_80231368()
{
    if (lbl_8053AC90 == NULL) return;
    for (int index = 0; index < 4; index++) {
        if (isPlayerEnabled(index)) fn_802422D0(lbl_8053AC90->players[index]);
    }
    fn_80457F6C(lbl_8053AF80);
}

void fn_80231424()
{
    if (lbl_8053AC90 == NULL) return;
    for (int index = 0; index < 4; index++) {
        if (isPlayerEnabled(index)) fn_80242560(lbl_8053AC90->players[index]);
    }
}

int fn_802314D8(int index, const JGeometry::TVec3<f32>& position)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (!isPlayerEnabled(index)) return 0;
    JGeometry::TVec3<f32> copy(position);
    return fn_80242624(lbl_8053AC90->players[index], copy);
}

int fn_80231590(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_802426E0(lbl_8053AC90->players[index], a0);
    return 0;
}

int fn_8023162C(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80242704(lbl_8053AC90->players[index], a0);
    return 0;
}

extern JGeometry::TVec3<f32> lbl_804CF460;
int fn_802316C8(int idx, int p2, const JGeometry::TVec3<f32>& p3) {
    const JGeometry::TVec3<f32>* pos;
    if (lbl_8053AC90 == NULL) return 0;
    if (!isPlayerEnabled(idx)) return 0;
    if (lbl_8053AC90 == NULL) {
        pos = (const JGeometry::TVec3<f32>*)(u32)&lbl_804CF460;
    } else {
        if (!isPlayerEnabled(idx)) {
            pos = (const JGeometry::TVec3<f32>*)(u32)&lbl_804CF460;
        } else {
            pos = (const JGeometry::TVec3<f32>*)((u8*)lbl_8053AC90->players[idx] + 8);
        }
    }
    return fn_80290070(lbl_8053AC90->players[idx], p2, *pos, p3, 0x11);
}

int fn_802317F0(int index, int a0, const JGeometry::TVec3<f32>& a1, const JGeometry::TVec3<f32>& a2, int a3)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80290070(lbl_8053AC90->players[index], a0, a1, a2, a3);
    return 0;
}

int fn_8023188C(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_802413F0(lbl_8053AC90->players[index]);
    return 0;
}

void fn_80231928(int index)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) fn_8023FBF0(lbl_8053AC90->players[index]);
}

int fn_802319B4(int index, int a0)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80251BFC(lbl_8053AC90->players[index], a0);
    return 0;
}

u8 fn_802527B0(Player*, s32*);
static inline u8 playerMgrBusy()
{
    if (lbl_8053AC90 == NULL) return 0;
    if (playerMgrByte(0x6c)) return 1;
    if (playerMgrByte(0x6d)) return 1;
    if (playerMgrByte(0x6e)) return 1;
    if (playerMgrByte(0x6f)) return 1;
    if (playerMgrByte(0x70)) return 1;
    if (playerMgrByte(0x71)) return 1;
    if (playerMgrByte(0x72)) return 1;
    return 0;
}
static inline int playerUnavailable(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (!isPlayerEnabled(index)) return 1;
    return fn_80240670(lbl_8053AC90->players[index]);
}
static inline int playerRoom(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (!isPlayerEnabled(index)) return 0;
    return *((int*)((u8*)lbl_8053AC90->players[index] + 0x3b4));
}
int fn_80231A50(void)
{
    if (playerMgrBusy()) return -1;
    if (playerMgrByte(0x73)) return -1;
    JGeometry::TVec2<s32> value;
    value.set(0, 0);
    int selected = -1;
    for (int i = 0; i < 4; i++) {
        Player* player = lbl_8053AC90->players[i];
        if (player != NULL && isPlayerEnabled(i) && !(u8)playerUnavailable(i)) {
            s32 pos[2];
            if (!fn_802527B0(player, pos)) {
                if (selected == -1) selected = i;
                else return -1;
            } else {
                if (value.x*value.x + value.y*value.y <= (s32)(lbl_8054000C * FLT_EPSILON)) {
                    value.x = pos[0];
                    value.y = pos[1];
                } else {
                    u8 same = value.x == pos[0] && value.y == pos[1];
                    if (!same) return -1;
                }
            }
        }
    }
    if (selected < 0) return -1;
    return playerRoom(selected) < 8 ? -1 : selected;
}

u8 fn_802527B0(Player*, s32*);
void fn_80248DB8(Player*);
void* fn_802D6A9C(void);
int fn_80124600(s32*);
int fn_802DD3D4(void*, s32*);
void fn_80457F60(void*);
void fn_802DCE5C(void*, s32*);
void fn_802520C0(Player*, s32*);
int fn_8025F590(Player*);
int fn_8025F418(Player*);
int fn_80270A8C(Player*);
int fn_80270A04(Player*);
int fn_80270A58(Player*);
int fn_8025F448(Player*);
static inline int gate_Player_GetField_0x454(int i) {
 if(lbl_8053AC90==NULL) return 0;
 if(!isPlayerEnabled(i)) return 0;
 return Player_GetField_0x454(lbl_8053AC90->players[i]);
}
static inline int gate_fn_80240818(int i) {
 if(lbl_8053AC90==NULL) return 0;
 if(!isPlayerEnabled(i)) return 0;
 return fn_80240818(lbl_8053AC90->players[i]);
}
static inline int gate_Player_GetField_0xce8(int i) {
 if(lbl_8053AC90==NULL) return 0;
 if(!isPlayerEnabled(i)) return 0;
 return Player_GetField_0xce8(lbl_8053AC90->players[i]);
}
static inline int gate_GetBusyLocked(int i) {
 if(lbl_8053AC90==NULL) return 0;
 if(!isPlayerEnabled(i)) return 0;
 return GetBusyLocked(lbl_8053AC90->players[i]);
}
static inline int gate_GetField_0xcfe(int i) {
 if(lbl_8053AC90==NULL) return 0;
 if(!isPlayerEnabled(i)) return 0;
 return GetField_0xcfe(lbl_8053AC90->players[i]);
}
static inline int gate_fn_80270A58(int i) {
 if(lbl_8053AC90==NULL) return 1;
 if(!isPlayerEnabled(i)) return 1;
 return fn_80270A58(lbl_8053AC90->players[i]);
}
static inline int gate_fn_8025F448(int i) {
 if(lbl_8053AC90==NULL) return 0;
 if(!isPlayerEnabled(i)) return 0;
 return fn_8025F448(lbl_8053AC90->players[i]);
}
static inline int gate_fn_80270A04(int i) {
 if(lbl_8053AC90==NULL) return 1;
 if(!isPlayerEnabled(i)) return 1;
 return fn_80270A04(lbl_8053AC90->players[i]);
}
static inline int gate_fn_8025F590(int i) {
 if(lbl_8053AC90==NULL) return 0;
 if(!isPlayerEnabled(i)) return 0;
 return fn_8025F590(lbl_8053AC90->players[i]);
}
static inline int gate_fn_8025F418(int i) {
 if(lbl_8053AC90==NULL) return 0;
 if(!isPlayerEnabled(i)) return 0;
 return fn_8025F418(lbl_8053AC90->players[i]);
}
static inline int gate_fn_80270A8C(int i) {
 if(lbl_8053AC90==NULL) return 1;
 if(!isPlayerEnabled(i)) return 1;
 return fn_80270A8C(lbl_8053AC90->players[i]);
}
static inline u8 playerGate43f(int i) {
 if(lbl_8053AC90==NULL) return 0;
 if(!isPlayerEnabled(i)) return 0;
 return ((u8*)lbl_8053AC90->players[i])[0x43f];
}
extern "C" s32 lbl_8053A190;
static inline void clearTransitionPlayers() {
    if (lbl_8053AC90==NULL) return;
    for(int i=0;i<4;i++) {
        if(isPlayerEnabled(i)) fn_80241E64(lbl_8053AC90->players[i]);
    }
}
void fn_80231DE4(void) {
    int i;
    for(i=0;i<4;i++) {
        Player* p=lbl_8053AC90->players[i];
        if(p!=NULL && isPlayerEnabled(i)) {
            s32 local[2]; local[0]=0;local[1]=0;
            if(fn_802527B0(p,local)) {
                for(int j=0;j<4;j++) {
                    if((u8)fn_8022E438(i,j) && lbl_8053AC90!=NULL && isPlayerEnabled(j)) fn_80248DB8(lbl_8053AC90->players[j]);
                }
            }
        }
    }
    if(playerMgrBusy()) return;
    if(((u8*)lbl_8053AAF8)[0x96]) return;
    if(playerMgrByte(0x73)) return;
    fn_802D6A9C();
    JGeometry::TVec2<s32> best;
    best.set(0,0);
    for(int i=0;i<4;i++) {
        Player* p=lbl_8053AC90->players[i];
        if(p!=NULL && isPlayerEnabled(i)) {
            if((u8)gate_Player_GetField_0x454(i)) return;
            if((u8)gate_fn_80240818(i)) return;
            if((u8)gate_Player_GetField_0xce8(i)) {
                if(!playerGate43f(i)) return;
                if(*(s32*)((u8*)fn_802D6A9C()+4)!=0) return;
                switch(*(s32*)((u8*)fn_802D6A9C()+8)) { case 0: break; default: return; }
            }
            if((u8)gate_GetBusyLocked(i)) return;
            if((u8)gate_GetField_0xcfe(i)) return;
            if((u8)gate_fn_80270A58(i)) return;
            if(!(u8)gate_fn_8025F448(i)) {
                if(!(u8)fn_80251BFC(p,0x1b)) return;
                if(!(u8)playerUnavailable(i)) {
                    if(!(u8)gate_fn_80270A04(i) || ((u8*)p)[0xd2d]) {
                        s32 out[2];
                        if(!fn_802527B0(p,out)) return;
                        if(best.x*best.x+best.y*best.y<=(s32)(lbl_8054000C*FLT_EPSILON)) {
                            best.x=out[0];best.y=out[1];
                            lbl_8053A190=i;
                        } else {
                            u8 same=best.x==out[0] && best.y==out[1];
                            if(!same) return;
                        }
                    }
                }
            }
        }
    }
    switch(fn_80124600(&best.x)) {case 0:return;case 1:return;}
    if(best.x*best.x+best.y*best.y<=(s32)(lbl_8054000C*FLT_EPSILON)) return;
    if(!(u8)fn_802DD3D4(fn_802D6A9C(),&best.x)) return;
    fn_80457F60(lbl_8053AF80);
    clearTransitionPlayers();
    fn_802DCE5C(fn_802D6A9C(),&best.x);
    for(int i=0;i<4;i++) {
        Player* p=lbl_8053AC90->players[i];
        if((u8)gate_fn_8025F590(i)) {
            *(s32*)((u8*)p+0xd70)=-1;
            ((u8*)p)[0xd64]=0;
            *(u32*)((u8*)p+0xd6c)=0x4e554c4c;
        } else if((u8)gate_fn_8025F418(i)) {
            *(s32*)((u8*)p+0xd70)=-1;
            *(f32*)((u8*)p+0x10)=lbl_80540008;
        }
        if(p!=NULL && isPlayerEnabled(i) && !(u8)gate_fn_80270A8C(i)) fn_802520C0(p,&best.x);
    }
}

#define PF(p, off, T) (*(T*)((u8*)(p) + (off)))

struct RoomFlags8022 {
    u8 flag(u32 i) { return mFlags[i]; }
    u8 pad[0x131df];
    u8 mFlags[1];
};

extern "C" const f32 lbl_80540010;
extern "C" const f32 lbl_8054001C;
extern "C" const f32 lbl_80540020;
extern "C" const f32 lbl_80540024;
extern "C" const f32 lbl_80540028;
int fn_80233EDC(int);
int fn_802349EC(int);
int fn_8023EA28(int);
int fn_8023E854(int);
int fn_80236AB4(int);
int fn_8023EFEC(int);
int fn_8023ECF0(int);
int fn_8023DE58(int);
JGeometry::TVec3<f32>* fn_8023E724(int);
void fn_8023DFF4(int, JGeometry::TVec3<f32>*);
JGeometry::TBox2<f32> fn_801546F4(const void*);
void fn_80238548(int, int, void*, int);
int fn_8023B6CC(int);
int fn_8023B630(int);
int fn_8023A3DC(int);
int fn_8023A5B8(int);
void fn_802379E4(int, void*);
int fn_80270C88(Player*);
int fn_8025F55C(Player*);
int fn_80273E7C(Player*, void*, int, void*, int);
int fn_80273518(Player*, void*, int, void*);
int fn_802573E0(Player*, void*, int, void*);
int fn_80273FB8(Player*, void*, int, void*);
int fn_80256F44(Player*, void*, int, void*);
int fn_80272224(Player*, JGeometry::TBox2<f32>*, int, int, int, int);
JGeometry::TBox2<f32>& fn_80233BA0(JGeometry::TBox2<f32>& destination, const JGeometry::TBox2<f32>& source);
JGeometry::TVec3<f32> fn_80233BC4(JGeometry::TVec3<f32>& left, const JGeometry::TVec3<f32>& right);
f32 fn_80233C08(JGeometry::TVec3<f32>& value);
bool fn_80233C9C(const JGeometry::TBox2<f32>& left, const JGeometry::TBox2<f32>& right);
void fn_80232A0C(void)
{
    JGeometry::TVec3<f32> hit;
    int i;
    int j;

    if (lbl_8053AC90->players[0] != NULL) *((u8*)lbl_8053AC90->players[0] + 0xafc) = 0;
    if (lbl_8053AC90->players[1] != NULL) *((u8*)lbl_8053AC90->players[1] + 0xafc) = 0;
    if (lbl_8053AC90->players[2] != NULL) *((u8*)lbl_8053AC90->players[2] + 0xafc) = 0;
    if (lbl_8053AC90->players[3] != NULL) *((u8*)lbl_8053AC90->players[3] + 0xafc) = 0;

    for (i = 0; i < 3; i++) {
        Player* a = lbl_8053AC90->players[i];
        if (a == NULL || !isPlayerEnabled(i)) continue;
        if (PF(a, 0x1240, s32) == 3) continue;
        if ((u8)fn_80233EDC(i)) continue;
        if ((u8)fn_8022D75C(i)) continue;
        if ((u8)fn_802349EC(i)) continue;
        if ((u8)fn_8023EA28(i)) continue;
        if ((u8)fn_8023E854(i)) continue;
        if (fn_8023E724(i)->z >= lbl_80540010) continue;
        if ((u8)fn_80236AB4(i)) continue;
        int room = fn_8023DE58(i);
        if (((u8*)fn_802D6A9C())[room + 0x131df] && (u8)fn_8022F514(i)) continue;
        if (!(u8)fn_8023188C(i)) continue;
        if (PF(a, 0xd58, s32) > 0) continue;
        if (PF(a, 0xd08, s32) >= 0) continue;
        JGeometry::TBox2<f32> boxA = fn_801546F4((u8*)a + 0x4c0);
        room = fn_8023DE58(i);
        u8* mgr = (u8*)fn_802D6A9C();
        f32* off = room < 8 ? (f32*)(mgr + 0xcc) : (f32*)(mgr + 0xdc);
        boxA.addPos(-off[0], -off[1]);

        for (j = i + 1; j < 4; j++) {
            Player* b = lbl_8053AC90->players[j];
            if (b == NULL || !isPlayerEnabled(j)) continue;
            if (PF(b, 0x1240, s32) == 3) continue;
            if (fn_8022CAF8(j) != 4 && (u8)fn_8022E438(i, j)) continue;
            if ((u8)fn_8023EFEC(i) && (u8)fn_8022E438(fn_8023ECF0(i), j) && fn_8022CAF8(j) != 4) continue;
            if ((u8)fn_8023EFEC(j) && (u8)fn_8022E438(fn_8023ECF0(j), i) && fn_8022CAF8(i) != 4) continue;
            if ((u8)fn_80233EDC(j)) continue;
            if ((u8)fn_8022D75C(j)) continue;
            if ((u8)fn_802349EC(j)) continue;
            if ((u8)fn_8023EA28(j)) continue;
            if ((u8)fn_8023E854(j)) continue;
            if (fn_8023E724(j)->z >= lbl_80540010) continue;
            if ((u8)fn_80236AB4(j)) continue;
            room = fn_8023DE58(j);
            if (((u8*)fn_802D6A9C())[room + 0x131df] && (u8)fn_8022F514(j)) continue;
            if (!(u8)fn_8023188C(j)) continue;
            if (PF(b, 0xd58, s32) > 0) continue;
            if (PF(b, 0xd08, s32) >= 0) continue;
            JGeometry::TBox2<f32> boxB = fn_801546F4((u8*)b + 0x4c0);
            room = fn_8023DE58(j);
            mgr = (u8*)fn_802D6A9C();
            off = room < 8 ? (f32*)(mgr + 0xcc) : (f32*)(mgr + 0xdc);
            boxB.addPos(-off[0], -off[1]);

            for (int k = 0;; k++) {
                if (fn_8023DE58(j) != fn_8023DE58(i)) break;
                if (!fn_80233C9C(boxA, boxB)) break;
                if (PF(a, 0xd70, s32) == j) break;
                if (PF(b, 0xd70, s32) == i) break;
                if (fn_8022CAF8(i) != 4) {
                    if ((u8)fn_8022F514(j) && PF(a, 0xd70, s32) == fn_8022F3DC(j)) break;
                    if ((u8)fn_8022F514(i) && PF(b, 0xd70, s32) == fn_8022F3DC(i)) break;
                }
                JGeometry::TVec3<f32> push;
                push.x = (boxA.f.x + lbl_80540014 * (boxA.i.x - boxA.f.x)) - (boxB.f.x + lbl_80540014 * (boxB.i.x - boxB.f.x));
                push.y = (boxA.f.y + lbl_80540014 * (boxA.i.y - boxA.f.y)) - (boxB.f.y + lbl_80540014 * (boxB.i.y - boxB.f.y));
                push.z = lbl_80540008;
                if (!(push.x * push.x + push.y * push.y >= lbl_80540018) && PF(a, 0xd54, s32) <= 0 && PF(b, 0xd54, s32) <= 0) break;
                if (PF(a, 0xd54, s32) > 0) PF(a, 0xd54, s32)--;
                if (PF(b, 0xd54, s32) > 0) PF(b, 0xd54, s32)--;
                fn_80233C08(push);
                if (push.squared() <= lbl_8054000C * FLT_EPSILON) {
                    push.set(lbl_8054001C, lbl_80540008, lbl_80540008);
                } else if (push.x < lbl_80540020 && push.x > lbl_80540024) {
                    push.x = lbl_80540020;
                } else if (push.y < lbl_80540020 && push.y > lbl_80540024) {
                    push.y = lbl_80540020;
                }
                if ((u8)fn_8022CCAC(i)) {
                    JGeometry::TVec3<f32> back;
                    back.negate(push);
                    fn_8023DFF4(j, &back);
                    boxB.addPos(-push.x, -push.y);
                    PF(b, 0xafc, u8) = 1;
                } else if ((u8)fn_8022CCAC(j)) {
                    fn_8023DFF4(i, &push);
                    boxA.addPos(push.x, push.y);
                    PF(a, 0xafc, u8) = 1;
                } else if (!((u8*)lbl_8053AAF8)[0x7e] && fn_8022CAF8(i) == 4) {
                    if (i != fn_80234004(i)) {
                        fn_8023DFF4(i, &push);
                        boxA.addPos(push.x, push.y);
                        PF(a, 0xafc, u8) = 1;
                    }
                    if (j != fn_80234004(j)) {
                        JGeometry::TVec3<f32> back;
                        back.negate(push);
                        fn_8023DFF4(j, &back);
                        boxB.addPos(-push.x, -push.y);
                        PF(b, 0xafc, u8) = 1;
                    }
                } else {
                    if (!(u8)fn_80250D30(a)) {
                        fn_8023DFF4(i, &push);
                        boxA.addPos(push.x, push.y);
                        PF(a, 0xafc, u8) = 1;
                    }
                    if (!(u8)fn_80250D30(b)) {
                        JGeometry::TVec3<f32> back;
                        back.negate(push);
                        fn_8023DFF4(j, &back);
                        boxB.addPos(-push.x, -push.y);
                        PF(b, 0xafc, u8) = 1;
                    }
                }
                if (k >= 3) break;
            }
        }
    }

    for (i = 0; i < 4; i++) {
        Player* a = lbl_8053AC90->players[i];
        if (a == NULL || !isPlayerEnabled(i)) continue;
        if (PF(a, 0xbd4, u8)) continue;
        for (j = 0; j < 4; j++) {
            if (i == j) continue;
            if ((u8)fn_8022E438(i, j)) continue;
            Player* b = lbl_8053AC90->players[j];
            if (b == NULL || !isPlayerEnabled(j)) continue;
            if ((u8)Player_GetField_0x454(b)) continue;
            if ((u8)fn_80270C88(b)) continue;
            if (PF(b, 0xbd4, u8)) continue;
            f32 z = fn_8023E724(j)->z;
            if ((f32)__fabs(fn_8023E724(i)->z - z) >= lbl_80540010) continue;
            if (fn_8023DE58(j) == fn_8023DE58(i) && PF(a, 0x458, u8) == 1 && PF(b, 0x458, u8) == 1 &&
                (fn_80233C9C(PF(a, 0x4a0, JGeometry::TBox2<f32>), PF(b, 0x4a0, JGeometry::TBox2<f32>)) ||
                 fn_80233C9C(PF(a, 0x4a0, JGeometry::TBox2<f32>), PF(b, 0x4b0, JGeometry::TBox2<f32>)) ||
                 fn_80233C9C(PF(a, 0x4b0, JGeometry::TBox2<f32>), PF(b, 0x4a0, JGeometry::TBox2<f32>)))) {
                fn_80238548(i, 0, (u8*)b + 8, 0x10);
                fn_8024F0E8(a, 0x20002);
                fn_80238548(j, 0, (u8*)a + 8, 0x10);
                fn_8024F0E8(b, 0x20002);
                PF(a, 0x35c, JGeometry::TVec3<f32>) = fn_80233BC4(*fn_8023E724(i), *fn_8023E724(j));
                fn_80233C08(PF(a, 0x35c, JGeometry::TVec3<f32>));
                PF(a, 0x35c, JGeometry::TVec3<f32>).scale(lbl_80540028);
                PF(b, 0x35c, JGeometry::TVec3<f32>) = fn_80233BC4(*fn_8023E724(j), *fn_8023E724(i));
                fn_80233C08(PF(b, 0x35c, JGeometry::TVec3<f32>));
                PF(b, 0x35c, JGeometry::TVec3<f32>).scale(lbl_80540028);
                continue;
            }
            if ((u8)fn_80273E7C(a, (u8*)b + 0x4c0, PF(b, 0x3b4, s32), &hit, 1)) {
                JGeometry::TBox2<f32> box;
                fn_80233BA0(box, PF(b, 0x5ec, JGeometry::TBox2<f32>));
                if ((u8)fn_80272224(b, &box, PF(a, 0x3b4, s32), PF(a, 0x458, u8) == 1 ? PF(a, 0x3f0, s32) : PF(a, 0x3dc, s32), 1, 1)) {
                    PF(a, 0x35c, JGeometry::TVec3<f32>) = fn_80233BC4(*fn_8023E724(i), *fn_8023E724(j));
                    fn_80233C08(PF(a, 0x35c, JGeometry::TVec3<f32>));
                    PF(a, 0x35c, JGeometry::TVec3<f32>).scale(lbl_80540028);
                    PF(b, 0x35c, JGeometry::TVec3<f32>) = fn_80233BC4(*fn_8023E724(j), *fn_8023E724(i));
                    fn_80233C08(PF(b, 0x35c, JGeometry::TVec3<f32>));
                    PF(b, 0x35c, JGeometry::TVec3<f32>).scale(lbl_80540028);
                } else if (((u8*)lbl_8053AAF8)[0x7f]) {
                    fn_80238548(j, 0, fn_8023E724(i), 1);
                } else if (fn_8023B6CC(i) == 1) {
                    fn_80238548(j, 1, fn_8023E724(i), 1);
                } else {
                    fn_80238548(j, fn_8023B6CC(i) / 2, fn_8023E724(i), 1);
                }
                continue;
            }
            if (!((u8)fn_8025F590(a) && (u8)fn_8022E438(fn_8025F55C(a), PF(b, 4, s32))) &&
                (u8)fn_80273518(a, (u8*)b + 0x4c0, PF(b, 0x3b4, s32), &hit)) {
                JGeometry::TBox2<f32> box;
                fn_80233BA0(box, PF(b, 0x5ec, JGeometry::TBox2<f32>));
                if ((u8)fn_80272224(b, &box, PF(a, 0x3b4, s32), PF(a, 0x3dc, s32), 1, 0)) {
                    fn_8024F0E8(b, 0x20003);
                    fn_802379E4(i, &hit);
                } else {
                    fn_80238548(j, 0, fn_8023E724(i), 0xb);
                }
                continue;
            }
            if (PF(a, 0xb68, u8) == 1 && (u8)fn_802573E0(a, (u8*)b + 0x4c0, PF(b, 0x3b4, s32), &hit)) {
                if (((u8*)lbl_8053AAF8)[0x7f]) {
                    fn_80238548(j, 0, &hit, 1);
                } else {
                    fn_80238548(j, fn_8023B630(i) / 2, &hit, 1);
                }
                continue;
            }
            if (!playerMgrByte(0x71) && !(u8)fn_8023A3DC(j) && (u8)fn_80273FB8(a, (u8*)b + 0x4c0, PF(b, 0x3b4, s32), &hit)) {
                if (((u8*)lbl_8053AAF8)[0x7f]) {
                    fn_80238548(j, 0, fn_8023E724(i), 0x1b);
                } else {
                    fn_80238548(j, 2, fn_8023E724(i), 0x1b);
                }
                continue;
            }
            if (!playerMgrByte(0x71) && !(u8)fn_8023A3DC(j) && (u8)fn_80256F44(a, (u8*)b + 0x4c0, PF(b, 0x3b4, s32), &hit)) {
                if (((u8*)lbl_8053AAF8)[0x7f]) {
                    if ((u8)fn_8023A5B8(i)) fn_80238548(j, 0, fn_8023E724(i), 0x15);
                    else fn_80238548(j, 0, fn_8023E724(i), 0x14);
                } else {
                    if ((u8)fn_8023A5B8(i)) fn_80238548(j, 4, fn_8023E724(i), 0x15);
                    else fn_80238548(j, 2, fn_8023E724(i), 0x14);
                }
            }
        }
    }
}

JGeometry::TBox2<f32>& fn_80233BA0(JGeometry::TBox2<f32>& destination, const JGeometry::TBox2<f32>& source)
{
    destination.i.x = source.i.x;
    destination.i.y = source.i.y;
    destination.f.x = source.f.x;
    destination.f.y = source.f.y;
    return destination;
}

#pragma peephole off
#pragma opt_propagation off
JGeometry::TVec3<f32> fn_80233BC4(JGeometry::TVec3<f32>& left, const JGeometry::TVec3<f32>& right)
{
    JGeometry::TVec3<f32> difference(left);
    difference.sub(difference, right);
    return difference;
}
#pragma opt_propagation reset
#pragma peephole reset
f32 fn_80233C08(JGeometry::TVec3<f32>& value)
{
    f32 squared = value.squared();
    if (squared <= lbl_8054000C * FLT_EPSILON) return lbl_80540008;
    f32 inverse = JGeometry::TUtilf::inv_sqrt(squared);
    value.scale(inverse);
    return inverse * squared;
}

bool fn_80233C9C(const JGeometry::TBox2<f32>& left, const JGeometry::TBox2<f32>& right)
{
    JGeometry::TBox2<f32> intersection(left);
    intersection.i.setMax(right.i);
    intersection.f.setMin(right.f);
    return intersection.f.x >= intersection.i.x && intersection.f.y >= intersection.i.y;
}

u8 fn_80233D20(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return *((u8*)lbl_8053AC90->players[index] + 0x43f);
    return 0;
}

int fn_80233DA4(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80241230(lbl_8053AC90->players[index]);
    return 0;
}

int fn_80233E40(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_802412A4(lbl_8053AC90->players[index]);
    return 0;
}

int fn_80233EDC(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80240B84(lbl_8053AC90->players[index]);
    return 0;
}

void fn_80233F78(int index)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) IncrementField_0x1224(lbl_8053AC90->players[index]);
}

int fn_80234004(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80240888(lbl_8053AC90->players[index]);
    return 0;
}

int fn_802340A0(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return GetPtrField_0x4(lbl_8053AC90->players[index]);
    return index;
}

int fn_80234134(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return GetField_0xcfe(lbl_8053AC90->players[index]);
    return 0;
}

u8 fn_802341D0(int idx)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (!isPlayerEnabled(idx)) return 0;
    if (!(*((u8*)lbl_8053AAF8 + 0x82) & (u8)(1 << idx))) return 0;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && idx != i && fn_8022E438(idx, i)) {
            if (!fn_802408C0(lbl_8053AC90->players[i])) return 0;
        }
    }
    return 1;
}

int fn_8023434C(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (!isPlayerEnabled(idx)) return 0;
    if ((u8)pIsLinked(idx)) {
        idx = pLinkTarget(idx);
        if (lbl_8053AC90 == NULL) return 0;
        if (!isPlayerEnabled(idx)) return 0;
        if ((u8)isLinked2(idx)) {
            idx = linkTarget2(idx);
            if (lbl_8053AC90 == NULL) return 0;
            if (!isEnabled2(idx)) return 0;
            if ((u8)isLinked3(idx)) {
                idx = linkTarget3(idx);
                if (lbl_8053AC90 == NULL) return 0;
                if (!fn_8023F264(idx)) return 0;
                if ((u8)fn_8022F514(idx)) return fn_8023434C(fn_8022F3DC(idx));
                return fn_80241964(lbl_8053AC90->players[idx]);
            }
            return fn_80241964(lbl_8053AC90->players[idx]);
        }
        return fn_80241964(lbl_8053AC90->players[idx]);
    }
    return fn_80241964(lbl_8053AC90->players[idx]);
}

void fn_80234810()
{
    if (lbl_8053AC90 == NULL) return;
    for (int index = 0; index < 4; index++) {
        if (isPlayerEnabled(index)) fn_80248DAC(lbl_8053AC90->players[index]);
    }
}

void fn_802348C4(int index, int a0, const JGeometry::TVec3<f32>& a1)
{
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(index)) fn_802408C8(lbl_8053AC90->players[index], a0, a1);
}

int fn_80234950(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80240AD4(lbl_8053AC90->players[index]);
    return 0;
}

int fn_802349EC(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80240AF0(lbl_8053AC90->players[index]);
    return 0;
}

int fn_80234A88(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80240AF8(lbl_8053AC90->players[index]);
    return 0;
}

int fn_80234B24(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80240B00(lbl_8053AC90->players[index]);
    return 0;
}

int fn_80234BC0(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80240B20(lbl_8053AC90->players[index]);
    return 0;
}

int fn_80234C5C(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80240B5C(lbl_8053AC90->players[index]);
    return 0;
}

int fn_80234CF8(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80240B70(lbl_8053AC90->players[index]);
    return 0;
}

int fn_80234D94(int index)
{
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(index)) return fn_80240D50(lbl_8053AC90->players[index]);
    return 0;
}
}