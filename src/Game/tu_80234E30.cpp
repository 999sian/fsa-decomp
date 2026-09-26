// TU 0x80234e30-0x8023fbf0: player-manager wrappers (player index -> player object).
#include "types.h"

struct Player;
struct PlayerMgr {
    u8 pad0[4];
    Player* players[4];
};

extern "C" PlayerMgr* lbl_8053AC90;

static inline u8 isPlayerEnabled(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (idx < 0) return 0;
    if (idx >= 4) return 0;
    if (lbl_8053AC90->players[idx] == NULL) return 0;
    Player* p = lbl_8053AC90->players[idx];
    return *(u8*)((char*)p + 0xcac);
}
static inline Player* getPlayer(int idx) {
    if (lbl_8053AC90 == NULL) return NULL;
    return lbl_8053AC90->players[idx];
}
extern "C" {
u8 fn_8022E438(int, int);
void fn_80270D34(Player*, int);
void fn_80270DDC(Player*, int, int);
u8 fn_8024157C(Player*, int);
int Player_GetLinkedHandleOrInvalid(Player*);
void fn_80254660(Player*);
extern u8 lbl_804CF460[];
struct GameState;
extern GameState* lbl_8053AAF8;
}

extern "C" {
int Fairy_GetSubField_0x290(Player*);
int Fairy_GetSubField_0x294(Player*);
int Player_CheckField_0xc9c(Player*);
int Player_GetField_0xb9b(Player*);
int Player_HasAnyStatusFlagSet(Player*);
int fn_8023FC2C(Player*);
int fn_8023FC5C(Player*);
int fn_8023FF50(Player*);
int fn_8023FF88(Player*);
int fn_8023FFC4(Player*);
int fn_8024018C(Player*);
int fn_80240354(Player*);
int fn_80240D64(Player*);
int fn_80240DAC(Player*);
int fn_80240ED4(Player*);
int fn_80240EF4(Player*);
int fn_80240F14(Player*);
int fn_80240F28(Player*);
int fn_8024119C(Player*);
int fn_802411C4(Player*);
int fn_802411EC(Player*);
int fn_80241200(Player*);
int fn_80241258(Player*);
int fn_80241284(Player*);
int fn_802412CC(Player*);
int fn_80241380(Player*);
int fn_802413C8(Player*);
int fn_80241498(Player*);
int fn_802414DC(Player*);
int fn_80241544(Player*);
int fn_802415CC(Player*);
int fn_802416C4(Player*);
int fn_80241794(Player*);
int fn_802417CC(Player*);
int fn_80241864(Player*);
int fn_8024189C(Player*);
int fn_802418E8(Player*);
int fn_80241920(Player*);
int fn_8024322C(Player*);
int fn_80247594(Player*, int);
int fn_8024EE0C(Player*);
int fn_8024EE14(Player*);
int fn_8024EE1C(Player*);
int fn_8024F5E4(Player*);
int fn_8024FF54(Player*);
int fn_8024FF84(Player*);
int fn_802577E0(Player*);
int fn_8025F2CC(Player*);
int fn_8025F418(Player*);
int fn_8025F448(Player*);
int fn_8025F500(Player*);
int fn_8025F534(Player*);
int fn_8025F55C(Player*);
int fn_8025F590(Player*);
int fn_8025F648(Player*);
int fn_8025F668(Player*);
int fn_8025F684(Player*);
int fn_8026FC20(Player*);
int fn_802702E4(Player*);
int fn_80270310(Player*);
int fn_80270350(Player*);
int fn_80270358(Player*);
int fn_80270A04(Player*);
int fn_80270A58(Player*);
int fn_80270A8C(Player*);
int fn_80270C88(Player*);
int fn_80271038(Player*, int);
int fn_80271068(Player*, int);
int fn_80271098(Player*, int);
int fn_80272184(Player*);
int fn_802721A8(Player*);
int fn_80272224(Player*, int, int, int, int, int);
int fn_802724E0(Player*, int, int);
int fn_802729F0(Player*, int);
int fn_80272C20(Player*, int, int, int);
int fn_80272DCC(Player*, int, int, int);
int fn_80272E98(Player*, int, int);
int fn_802730D8(Player*, int, int, int, f32);
u8 fn_80256C74(Player*, int, int);
u8 fn_80256DCC(Player*, int, int, int);
u8 fn_80256F44(Player*, int, int, int);
u8 fn_802570BC(Player*, int, int, int);
u8 fn_802574CC(Player*, int, int, int);
u8 fn_80272768(Player*, int, int, int);
u8 fn_802732C4(Player*, int, int);
u8 fn_80273518(Player*, int, int, int);
u8 fn_80273C30(Player*, int, int, int, int);
u8 fn_80273D44(Player*, int, int, int, int);
u8 fn_80273FB8(Player*, int, int, int);
u8 fn_80274238(Player*, int, int, int, int);
void Fairy_SetField_0xd28(Player*, int);
void Fairy_SetSubField_0x298(Player*, int);
void Fairy_SetSubField_0x29c(Player*, int);
void fn_8024051C(Player*);
void fn_802412D4(Player*);
void fn_8024148C(Player*);
void fn_802414D0(Player*);
void fn_802416FC(Player*, int);
void fn_80241804(Player*, int);
void fn_80248DB8(Player*);
void fn_80248DCC(Player*);
void fn_8024E500(Player*);
void fn_8024E694(Player*, int, int);
void fn_8024ECCC(Player*, int);
void fn_8024ED4C(Player*, int);
void fn_80252BD0(Player*, int);
void fn_80252CF0(Player*, int);
void fn_80252F14(Player*, int);
void fn_8025F5CC(Player*);
void fn_802702EC(Player*);
void fn_80270318(Player*, int);
void fn_802708D0(Player*);
void fn_802708E8(Player*);
void fn_80270F00(Player*, int);

int fn_80234E30(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80240D64(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_80234ECC(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80240DAC(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_80234F68(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80240ED4(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_80235004(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80240EF4(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_802350A0(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80240F14(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023513C(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80240F28(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_802351D8(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_8024119C(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_80235274(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_802411C4(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_80235310(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80241258(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_802353AC(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80241284(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_80235448(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_802412CC(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_802354E4(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_802411EC(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_80235580(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80241200(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023561C(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80241380(lbl_8053AC90->players[idx]);
    return 0;
}

void fn_802356B8(int idx) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_802412D4(lbl_8053AC90->players[idx]);
}

int fn_80235744(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_802413C8(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_802357E0(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_802702E4(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023587C(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80270310(lbl_8053AC90->players[idx]);
    return 0;
}

void fn_80235918(int idx) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_802702EC(lbl_8053AC90->players[idx]);
}

void fn_802359A4(int idx, int a1) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_80270318(lbl_8053AC90->players[idx], a1);
}

int fn_80235A30(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80270350(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_80235ACC(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80270358(lbl_8053AC90->players[idx]);
    return 0;
}

void fn_80235FE8(int idx) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_8024E500(lbl_8053AC90->players[idx]);
}

void fn_80236074(int idx, int a1, int a2) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_8024E694(lbl_8053AC90->players[idx], a1, a2);
}

int fn_80236100(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_802418E8(lbl_8053AC90->players[idx]);
    return 0;
}

void fn_8023619C(int idx, int a1) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_8024ECCC(lbl_8053AC90->players[idx], a1);
}

int fn_80236228(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80241920(lbl_8053AC90->players[idx]);
    return 0;
}

void fn_802362C4(int idx, int a1) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_8024ED4C(lbl_8053AC90->players[idx], a1);
}

void fn_80236350(int idx) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_802708D0(lbl_8053AC90->players[idx]);
}

void fn_802363DC(int idx) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_802708E8(lbl_8053AC90->players[idx]);
}

void fn_80236468(int idx, int a1) {
    if (lbl_8053AC90 == NULL) return;
    if (!isPlayerEnabled(idx)) return;
    for (int i = 0; i < 4; i++) {
        if (idx == i || fn_8022E438(idx, i)) fn_80270D34(lbl_8053AC90->players[i], a1);
    }
}

void fn_80236554(int idx, int a1, int a2) {
    if (lbl_8053AC90 == NULL) return;
    if (!isPlayerEnabled(idx)) return;
    for (int i = 0; i < 4; i++) {
        if (idx == i || fn_8022E438(idx, i)) fn_80270DDC(lbl_8053AC90->players[i], a1, a2);
    }
}

int fn_80236630(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_8023FFC4(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_802366CC(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_8024018C(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_80236768(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80240354(lbl_8053AC90->players[idx]);
    return 0;
}

void fn_80236804(int idx, int a1) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_80270F00(lbl_8053AC90->players[idx], a1);
}

u8 fn_80236890() {
    if (lbl_8053AC90 == NULL) return 1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && (*(u8*)((char*)lbl_8053AAF8 + 0x82) & (u8)(1 << i))) {
            if (!(u8)fn_80270A04(lbl_8053AC90->players[i])) return 0;
        }
    }
    return 1;
}

int fn_8023697C(int idx) {
    if (lbl_8053AC90 == NULL) return -1;
    if (isPlayerEnabled(idx)) return fn_8024322C(lbl_8053AC90->players[idx]);
    return -1;
}

int fn_80236A18(int idx) {
    if (lbl_8053AC90 == NULL) return 1;
    if (isPlayerEnabled(idx)) return fn_80270A04(lbl_8053AC90->players[idx]);
    return 1;
}

int fn_80236AB4(int idx) {
    if (lbl_8053AC90 == NULL) return 1;
    if (isPlayerEnabled(idx)) return fn_80270A58(lbl_8053AC90->players[idx]);
    return 1;
}

int fn_80236B50(int idx) {
    if (lbl_8053AC90 == NULL) return 1;
    if (isPlayerEnabled(idx)) return fn_80270A8C(lbl_8053AC90->players[idx]);
    return 1;
}

int fn_80236BEC(int idx) {
    if (lbl_8053AC90 == NULL) return 1;
    if (isPlayerEnabled(idx)) return fn_80270C88(lbl_8053AC90->players[idx]);
    return 1;
}

void fn_80236C88(int idx) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_8024148C(lbl_8053AC90->players[idx]);
}

int fn_80236D14(int idx) {
    if (lbl_8053AC90 == NULL) return 1;
    if (isPlayerEnabled(idx)) return fn_80241498(lbl_8053AC90->players[idx]);
    return 1;
}

void fn_80236DB0(int idx) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_802414D0(lbl_8053AC90->players[idx]);
}

int fn_80236E3C(int idx) {
    if (lbl_8053AC90 == NULL) return 1;
    if (isPlayerEnabled(idx)) return fn_802414DC(lbl_8053AC90->players[idx]);
    return 1;
}

int fn_80237060(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80241544(lbl_8053AC90->players[idx]);
    return 0;
}

u8 fn_802370FC(int idx, int a1) {
    if (lbl_8053AC90 == NULL) return 0;
    if (!isPlayerEnabled(idx)) return 0;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_8022E438(idx, i)) {
            if (!fn_8024157C(lbl_8053AC90->players[i], a1)) return 0;
        }
    }
    return 1;
}

int fn_8023725C(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_802415CC(lbl_8053AC90->players[idx]);
    return 0;
}

u8 fn_80241618(Player*, int, int);
u8 fn_802372F8(int idx, int a1, int a2) {
    if (lbl_8053AC90 == NULL) return 0;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_8022E438(idx, i)) {
            if (!fn_80241618(lbl_8053AC90->players[i], a1, a2)) return 0;
        }
    }
    return 1;
}

int fn_802373EC(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_802416C4(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_80237488(int idx, int a1) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80247594(lbl_8053AC90->players[idx], a1);
    return 0;
}

void fn_80237524(int idx, int a1) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_802416FC(lbl_8053AC90->players[idx], a1);
}

int fn_802375B0(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80241794(lbl_8053AC90->players[idx]);
    return 0;
}

void fn_8023764C(int idx, int a1) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_80241804(lbl_8053AC90->players[idx], a1);
}

int fn_802376D8(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80241864(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_80237774(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_8024189C(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_80237810(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_802417CC(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_802378AC(int idx, int a1) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80271038(lbl_8053AC90->players[idx], a1);
    return 0;
}

int fn_80237948(int idx, int a1) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80271068(lbl_8053AC90->players[idx], a1);
    return 0;
}

int fn_802379E4(int idx, int a1) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80271098(lbl_8053AC90->players[idx], a1);
    return 0;
}

void fn_802381B8(int idx) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_80248DB8(lbl_8053AC90->players[idx]);
}

void fn_80238244(int idx) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_80248DCC(lbl_8053AC90->players[idx]);
}

void* fn_80238430(int idx) {
    if (lbl_8053AC90 == NULL) return lbl_804CF460;
    if (isPlayerEnabled(idx)) return (char*)lbl_8053AC90->players[idx] + 0x324;
    return lbl_804CF460;
}

void fn_802384BC(int idx) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_8024051C(lbl_8053AC90->players[idx]);
}

int fn_80239108(int);
u8 fn_80250030(Player*, int);
int fn_80238BC4(int a1) {
    if (fn_80239108(a1) <= 0) return -1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_80250030(lbl_8053AC90->players[i], a1)) {
            return *(int*)((char*)lbl_8053AC90->players[i] + 0x3dc);
        }
    }
    return -1;
}

int fn_80238CB4(int idx) {
    if (lbl_8053AC90 == NULL) return -1;
    if (isPlayerEnabled(idx)) return fn_8024FF84(lbl_8053AC90->players[idx]);
    return -1;
}

void fn_8024FF9C(Player*, int);
void fn_80238D50(int a1) {
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i)) fn_8024FF9C(lbl_8053AC90->players[i], a1);
    }
}

void fn_8024FFB4(Player*, int);
void fn_80238E08(int a1) {
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_80250030(lbl_8053AC90->players[i], a1)) {
            fn_8024FFB4(lbl_8053AC90->players[i], a1);
        }
    }
}

int fn_80238EDC(int idx) {
    if (lbl_8053AC90 == NULL) return -1;
    if (isPlayerEnabled(idx)) return fn_8024FF54(lbl_8053AC90->players[idx]);
    return -1;
}

int fn_8024FF6C(Player*);
int fn_80238F78(int a1) {
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && a1 == fn_8024FF6C(lbl_8053AC90->players[i])) return i;
    }
    return -1;
}

int fn_80239040(int a1) {
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && a1 == fn_8024FF84(lbl_8053AC90->players[i])) return i;
    }
    return -1;
}

u8 fn_802728AC(Player*, int, int, int);
int fn_80239470(int a1, int a2, int a3) {
    if (lbl_8053AC90 == NULL) return 0;
    int r = -1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_802728AC(lbl_8053AC90->players[i], a1, a2, a3) && r < 0) r = i;
    }
    return r;
}

int fn_80239558(int a1, int a2, int a3) {
    if (lbl_8053AC90 == NULL) return 0;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_80272768(lbl_8053AC90->players[i], a1, a2, a3)) return i;
    }
    return -1;
}

u8 fn_80239638(int a1) {
    if (lbl_8053AC90 == NULL) return 0;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && (u8)fn_802729F0(lbl_8053AC90->players[i], a1)) return 1;
    }
    return 0;
}

int fn_80239718(int idx, int a1) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_802729F0(lbl_8053AC90->players[idx], a1);
    return 0;
}

void fn_802397B4(int a1, int a2, int a3) {
    if (lbl_8053AC90 == NULL) return;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i)) fn_80272C20(lbl_8053AC90->players[i], a1, a2, a3);
    }
}

int fn_80239878(int idx, int a1, int a2, int a3) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80272C20(lbl_8053AC90->players[idx], a1, a2, a3);
    return 0;
}

int fn_802399D8(int idx, int a1, int a2, int a3) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80272DCC(lbl_8053AC90->players[idx], a1, a2, a3);
    return 0;
}

int fn_80239A74(int a1, int a2, int a3, int a4, int a5) {
    if (lbl_8053AC90 == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && (u8)fn_80272224(lbl_8053AC90->players[i], a1, a2, a3, a4, a5)) return i;
    }
    return -1;
}

int fn_80239B64(int idx, int a1, int a2, int a3, int a4, int a5) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80272224(lbl_8053AC90->players[idx], a1, a2, a3, a4, a5);
    return 0;
}

int fn_80239C00(int idx, int a1, int a2) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80272E98(lbl_8053AC90->players[idx], a1, a2);
    return 0;
}

int fn_80239C9C(int idx, int a1, int a2) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_802724E0(lbl_8053AC90->players[idx], a1, a2);
    return 0;
}

int fn_8023A1A4(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_8026FC20(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023A240() {
    if (lbl_8053AC90 == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i)) {
            int h = Player_GetLinkedHandleOrInvalid(lbl_8053AC90->players[i]);
            if (h >= 0) return h;
        }
    }
    return -1;
}

u8 fn_8023A30C() {
    if (lbl_8053AC90 == NULL) return 0;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && (u8)Player_HasAnyStatusFlagSet(lbl_8053AC90->players[i])) return 1;
    }
    return 0;
}

int fn_8023A3DC(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return Player_CheckField_0xc9c(lbl_8053AC90->players[idx]);
    return 0;
}

void* Player_GetModeSubPtr_0xb9a(Player*);
void* fn_8023A478(int idx) {
    if (lbl_8053AC90 == NULL) return lbl_804CF460;
    if (isPlayerEnabled(idx)) return Player_GetModeSubPtr_0xb9a(lbl_8053AC90->players[idx]);
    return lbl_804CF460;
}

int fn_8023A51C(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return Player_HasAnyStatusFlagSet(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023A5B8(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return Player_GetField_0xb9b(lbl_8053AC90->players[idx]);
    return 0;
}

void fn_8023A654(int idx) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) *(u8*)((char*)lbl_8053AC90->players[idx] + 0xb9f) = 1;
}

int fn_8023A6CC(int a1, int a2) {
    if (lbl_8053AC90 == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_80256C74(lbl_8053AC90->players[i], a1, a2)) return i;
    }
    return -1;
}

int fn_8023A7BC(int a1, int a2, int a3) {
    if (lbl_8053AC90 == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_80273FB8(lbl_8053AC90->players[i], a1, a2, a3)) return i;
    }
    return -1;
}

int fn_8023A89C(int a1, int a2, int a3) {
    if (lbl_8053AC90 == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_80256DCC(lbl_8053AC90->players[i], a1, a2, a3)) return i;
    }
    return -1;
}

u8 fn_8023A97C(int idx, int a1, int a2, int a3) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80256DCC(lbl_8053AC90->players[idx], a1, a2, a3);
    return 0;
}

int fn_8023AA18(int a1, int a2, int a3) {
    if (lbl_8053AC90 == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_80256F44(lbl_8053AC90->players[i], a1, a2, a3)) return i;
    }
    return -1;
}

u8 fn_8023AAF8(int idx, int a1, int a2, int a3) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80256F44(lbl_8053AC90->players[idx], a1, a2, a3);
    return 0;
}

int fn_8023AB94(int a1, int a2, int a3) {
    if (lbl_8053AC90 == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_802570BC(lbl_8053AC90->players[i], a1, a2, a3)) return i;
    }
    return -1;
}

int fn_8023AC74(int a1, int a2, int a3) {
    if (lbl_8053AC90 == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_802574CC(lbl_8053AC90->players[i], a1, a2, a3)) return i;
    }
    return -1;
}

u8 fn_802575B8(Player*, int, int, int);
int fn_8023AD54(int a1, int a2, int a3) {
    int r = -1;
    if (lbl_8053AC90 == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_802575B8(lbl_8053AC90->players[i], a1, a2, a3)) r = i;
    }
    return r;
}

u8 fn_802576CC(Player*, int, int, int);
int fn_8023AE34(int a1, int a2, int a3) {
    int r = -1;
    if (lbl_8053AC90 == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_802576CC(lbl_8053AC90->players[i], a1, a2, a3)) r = i;
    }
    return r;
}

int fn_8023AF14(int a1, int a2, int a3, f32 f) {
    if (lbl_8053AC90 == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && (u8)fn_802730D8(lbl_8053AC90->players[i], a1, a2, a3, f)) return i;
    }
    return -1;
}

int fn_8023B004(int a1, int a2) {
    if (lbl_8053AC90 == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_802732C4(lbl_8053AC90->players[i], a1, a2)) return i;
    }
    return -1;
}

int fn_8023B0F4(int idx, int a1, int a2, int a3, f32 f) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_802730D8(lbl_8053AC90->players[idx], a1, a2, a3, f);
    return 0;
}

u8 fn_8023B190(int idx, int a1, int a2) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_802732C4(lbl_8053AC90->players[idx], a1, a2);
    return 0;
}

int fn_8023B22C(int idx) {
    if (lbl_8053AC90 == NULL) return -1;
    if (isPlayerEnabled(idx)) return *(int*)((char*)lbl_8053AC90->players[idx] + 0xb18);
    return -1;
}

int fn_8023B2B0(int idx) {
    if (lbl_8053AC90 == NULL) return -1;
    if (!isPlayerEnabled(idx)) return -1;
    char* p = (char*)lbl_8053AC90->players[idx];
    int k = *(int*)(p + 0xb7c);
    if (k < 0 || k >= 3) return -1;
    return ((int*)(p + 0xb00))[k];
}

int fn_8023B358(int idx) {
    if (lbl_8053AC90 == NULL) return -1;
    if (!isPlayerEnabled(idx)) return -1;
    char* p = (char*)lbl_8053AC90->players[idx];
    int k = *(int*)(p + 0xb80);
    if (k < 0 || k >= 3) return -1;
    return ((int*)(p + 0xb0c))[k];
}

u8 fn_8023B400(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return *(u8*)((char*)lbl_8053AC90->players[idx] + 0xb78);
    return 0;
}

int fn_8023B484(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_802577E0(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023B520(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (!isPlayerEnabled(idx)) return 0;
    if (*(u8*)((char*)lbl_8053AC90->players[idx] + 0xb9b) != 0) return 0x10;
    return 8;
}

int fn_8023B5B4(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    return isPlayerEnabled(idx) ? 4 : 0;
}

int fn_8023B630(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80272184(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023B6CC(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_802721A8(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023B768(int a1, int a2, int a3) {
    if (lbl_8053AC90 == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_80273518(lbl_8053AC90->players[i], a1, a2, a3)) return i;
    }
    return -1;
}

u8 fn_8023B848(int idx, int a1, int a2, int a3) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80273518(lbl_8053AC90->players[idx], a1, a2, a3);
    return 0;
}

int fn_8023B8E4(int a1, int a2, int a3, int a4) {
    if (lbl_8053AC90 == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_80274238(lbl_8053AC90->players[i], a1, a2, a3, a4)) return i;
    }
    return -1;
}

u8 fn_8023B9CC(int idx, int a1, int a2, int a3, int a4) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_80274238(lbl_8053AC90->players[idx], a1, a2, a3, a4);
    return 0;
}

int fn_8023BA68(int a1, int a2, int a3, int a4) {
    if (lbl_8053AC90 == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_80273C30(lbl_8053AC90->players[i], a1, a2, a3, a4)) return i;
    }
    return -1;
}

int fn_8023BB50(int a1, int a2, int a3, int a4) {
    if (lbl_8053AC90 == NULL) return -1;
    for (int i = 0; i < 4; i++) {
        if (isPlayerEnabled(i) && fn_80273D44(lbl_8053AC90->players[i], a1, a2, a3, a4)) return i;
    }
    return -1;
}

int fn_8023BC38(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_8023FC2C(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023BCD4(int idx) {
    if (lbl_8053AC90 == NULL) return 255;
    if (isPlayerEnabled(idx)) return fn_8023FC5C(lbl_8053AC90->players[idx]);
    return 255;
}

int fn_8023BD70(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_8023FF50(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023BE0C(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_8023FF88(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023CA88(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_8024EE14(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023CB24(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_8024EE0C(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023CBC0(int idx) {
    if (lbl_8053AC90 == NULL) return 289;
    if (isPlayerEnabled(idx)) return fn_8024EE1C(lbl_8053AC90->players[idx]);
    return 289;
}

void fn_8023CC5C(int idx, int a1) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) Fairy_SetSubField_0x29c(lbl_8053AC90->players[idx], a1);
}

void fn_8023CCE8(int idx, int a1) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) Fairy_SetSubField_0x298(lbl_8053AC90->players[idx], a1);
}

int fn_8023CD74(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return Fairy_GetSubField_0x294(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023CE10(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return Fairy_GetSubField_0x290(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023DE58(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return *(int*)((char*)lbl_8053AC90->players[idx] + 0x3b4);
    return 0;
}

void fn_8023DEDC(int idx, int a1) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_80252BD0(lbl_8053AC90->players[idx], a1);
}

void fn_8023DF68(int idx, int a1) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_80252CF0(lbl_8053AC90->players[idx], a1);
}

void fn_8023DFF4(int idx, int a1) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_80252F14(lbl_8053AC90->players[idx], a1);
}

void fn_8023E080(int idx, int a1) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) Fairy_SetField_0xd28(lbl_8053AC90->players[idx], a1);
}

int fn_8023E10C(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return *(int*)((char*)lbl_8053AC90->players[idx] + 0xce4);
    return 0;
}

int fn_8023E190(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return *(int*)((char*)lbl_8053AC90->players[idx] + 0xce0);
    return 0;
}

void* fn_8023E214(int idx) {
    if (lbl_8053AC90 == NULL) return lbl_804CF460;
    if (isPlayerEnabled(idx)) return (char*)lbl_8053AC90->players[idx] + 0xcd4;
    return lbl_804CF460;
}

void* fn_8023E2A0(int idx) {
    if (lbl_8053AC90 == NULL) return lbl_804CF460;
    if (isPlayerEnabled(idx)) return (char*)lbl_8053AC90->players[idx] + 0xcc8;
    return lbl_804CF460;
}

void* fn_8023E32C(int idx) {
    if (lbl_8053AC90 == NULL) return lbl_804CF460;
    if (isPlayerEnabled(idx)) return (char*)lbl_8053AC90->players[idx] + 0xcb0;
    return lbl_804CF460;
}

void* fn_8024C378(Player*);
void* fn_8023E3B8(int idx) {
    if (lbl_8053AC90 == NULL) return lbl_804CF460;
    if (isPlayerEnabled(idx)) return fn_8024C378(lbl_8053AC90->players[idx]);
    return lbl_804CF460;
}

struct PlayerB { u8 pad[0x284]; u8 a284[8]; };
u8 fn_8023E45C(int idx, int j) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) {
        PlayerB* p = (PlayerB*)lbl_8053AC90->players[idx];
        return p->a284[j];
    }
    return 0;
}

void* fn_8023E4E4(int idx, int j) {
    if (lbl_8053AC90 == NULL) return lbl_804CF460;
    if (isPlayerEnabled(idx)) return (char*)lbl_8053AC90->players[idx] + 0x38 + j * 0xc;
    return lbl_804CF460;
}

void* fn_8023E578(int idx) {
    if (lbl_8053AC90 == NULL) return lbl_804CF460;
    if (isPlayerEnabled(idx)) return (char*)lbl_8053AC90->players[idx] + 0x14;
    return lbl_804CF460;
}

void* fn_8023E604(int idx) {
    if (lbl_8053AC90 == NULL) return lbl_804CF460;
    if (isPlayerEnabled(idx)) return (char*)lbl_8053AC90->players[idx] + 0x2c4;
    return lbl_804CF460;
}

void fn_8023E690(int idx, const f32* v) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) {
        f32 z = v[2];
        f32 y = v[1];
        f32 x = v[0];
        f32* p = (f32*)lbl_8053AC90->players[idx];
        p[2] = x; p[3] = y; p[4] = z;
        p[11] = x; p[12] = y; p[13] = z;
    }
}

void* fn_8023E724(int idx) {
    if (lbl_8053AC90 == NULL) return lbl_804CF460;
    if (isPlayerEnabled(idx)) return (char*)lbl_8053AC90->players[idx] + 0x8;
    return lbl_804CF460;
}

void* fn_8024145C(Player*);
void* fn_8023E7B0(int idx) {
    if (lbl_8053AC90 == NULL) return lbl_804CF460;
    if (isPlayerEnabled(idx)) return fn_8024145C(lbl_8053AC90->players[idx]);
    return lbl_804CF460;
}

int fn_8023E854(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_8024F5E4(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023E8F0(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_8025F2CC(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023E98C(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_8025F418(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023EA28(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_8025F448(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023EBB8(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_8025F500(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023EC54(int idx) {
    if (lbl_8053AC90 == NULL) return -1;
    if (isPlayerEnabled(idx)) return fn_8025F534(lbl_8053AC90->players[idx]);
    return -1;
}

int fn_8023ECF0(int idx) {
    if (lbl_8053AC90 == NULL) return -1;
    if (isPlayerEnabled(idx)) return fn_8025F55C(lbl_8053AC90->players[idx]);
    return -1;
}

int fn_8023ED8C(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_8025F590(lbl_8053AC90->players[idx]);
    return 0;
}

void fn_8023EE28(int idx) {
    if (lbl_8053AC90 == NULL) return;
    if (isPlayerEnabled(idx)) fn_8025F5CC(lbl_8053AC90->players[idx]);
}

int fn_8023EEB4(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_8025F648(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023EF50(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_8025F668(lbl_8053AC90->players[idx]);
    return 0;
}

int fn_8023EFEC(int idx) {
    if (lbl_8053AC90 == NULL) return 0;
    if (isPlayerEnabled(idx)) return fn_8025F684(lbl_8053AC90->players[idx]);
    return 0;
}

u8 fn_8023F264(int idx) {
    return isPlayerEnabled(idx);
}

void fn_8023F6C4() {
    for (int i = 0; i < 4; i++) fn_80254660(getPlayer(i));
}

u8 Player_GetCapabilityFlag(Player* p) {
    return *(u8*)((char*)p + 0xcac);
}

BOOL fn_8023F98C(GameState* g, int i) {
    return (*(u8*)((char*)g + 0x82) & (u8)(1 << i)) != 0;
}

GameState* fn_8023F9B0() {
    return lbl_8053AAF8;
}


}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
