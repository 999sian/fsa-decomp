// TU 0x80215a94-0x8021693c.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- fn_80216238.cpp ----
extern "C" void* Hrmn_InitSlotStateType3(void* obj);
extern "C" void* Hrmn_ActivateSlotB(void* obj);
extern "C" void* Hrmn_ActivateSlotA(void* obj);

// fn_80216238 - the per-element constructor for HRMN's fn_80216178 array
// (see extab_80216178.s). Initializes an element containing TWO nested
// "cyclic counter" sub-records back to back: this->0x0 (own 2 fields,
// 0/-1) and this->0xc (a Hrmn_InitSlotStateType3-family record,
// redundantly initialized twice - the FIRST init at +0xc is immediately
// followed by a second at +0x18 with a DIFFERENT record type
// (Hrmn_ActivateSlotB, then finally Hrmn_ActivateSlotA) - the last
// write to each address is the one that persists). Also zeroes
// this->0x8/0x9/0xa.


// ---- HRMN slot table (count + 4 entries of 0x24) ----
extern "C" int fn_8023DE58(int);
extern "C" u8 fn_801CD2F8(int);
extern "C" u8 fn_801ED7B0(void*);
extern "C" void fn_8043D874(void*, s32, s32, s32);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7844(void*, s32, s32);
extern "C" void fn_802162B8(void*, s32, s32);
extern "C" void fn_801ED3DC(void*, s32, s32);
extern "C" u8 fn_801CD664(s32);
extern "C" void fn_801ED458(void*, u8);
extern "C" void fn_801ED5C8(void*);
extern "C" void fn_801ED798(void*);
extern "C" void fn_801ED7F0(void*);
extern "C" void* Hrmn_InitSlotStateType0xc(void*);
extern "C" void* fn_80138A30(void* game);
extern "C" void* Hrmn_InitSlotStateType3(void* obj);
extern s32 lbl_8046A590[];
extern void* lbl_8053AED0;
extern u8 lbl_8050EC80[];
extern u8* lbl_8053AAF8;

struct HrmnEntry {
    s32 mA;       // 0x00
    s32 mId;      // 0x04
    u8 m08;       // 0x08
    u8 m09;       // 0x09
    u8 m0A;       // 0x0a
    u8 pad0B;
    u8 mSub[0xc]; // 0x0c
    u8 mSub2[8];  // 0x18
    u8 m20;       // 0x20
    u8 m21;       // 0x21
    u8 pad22[2];
    bool isSet() const { return mId >= 0 ? true : false; }
    HrmnEntry();
};

struct HrmnSub0xc {
    HrmnSub0xc() { Hrmn_InitSlotStateType0xc(this); }
    u8 data[0xc];
};

struct HrmnTable {
    HrmnTable();
    void reset() {
        for (int i = 0; i < mCount; i++) {
            mEntry[i].mA = i;
            mEntry[i].mId = -1;
            mEntry[i].m08 = 0;
            mEntry[i].m09 = 0;
            mEntry[i].m0A = 0;
            Hrmn_InitSlotStateType3(mEntry[i].mSub);
            fn_801ED7F0(mEntry[i].mSub2);
        }
        Hrmn_InitSlotStateType0xc(mSub.data);
        mA0 = 0;
    }
    s32 mCount;          // 0x00
    HrmnEntry mEntry[4]; // 0x04
    HrmnSub0xc mSub;     // 0x94
    u8 mA0;              // 0xa0
    int countSet() const {
        int n = 0;
        for (int i = 0; i < mCount; i++) {
            if (mEntry[i].mId >= 0) {
                n++;
            }
        }
        return n;
    }
};

extern "C" int fn_80215E98(HrmnTable* t);
extern "C" void fn_80215E18(HrmnEntry* e);

extern "C" int fn_80215A94(HrmnTable* t) {
    int result = -1;
    s32 cnt = t->mCount;
    if (cnt >= 2 && cnt - 1 == t->countSet()) {
        s32 n = t->mCount;
        for (int i = 0; i < n; i++) {
            if (!t->mEntry[i].isSet()) {
                if (fn_801CD2F8(fn_8023DE58(i))) {
                    result = i;
                    break;
                }
            }
        }
    }
    return result;
}

extern "C" void fn_80215B6C(HrmnTable* t, int idx) {
    s32 id = t->mEntry[idx].mId;
    if (id >= 0 && id < 4) {
        s32 v = lbl_8046A590[id];
        if (v > 0) {
            fn_8043D874(lbl_8053AED0, t->mEntry[idx].mA, v, 0);
        }
    }
}

extern "C" void fn_80215BCC(HrmnTable* t, int idx) {
    if (t->mEntry[idx].mSub2[0] != 0 && !fn_801ED7B0(t->mEntry[idx].mSub2)) {
        lbl_8050EC80[*(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x79] = t->mEntry[idx].m20;
        lbl_8050EC80[*(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x78] = t->mEntry[idx].m21;
        fn_802D7844(fn_802D6A9C(), 1, t->mEntry[idx].mA);
    }
}

extern "C" int fn_80215C6C(HrmnTable* t, int idx) {
    int result;
    result = 0;
    if (t->mEntry[idx].mSub2[0] != 0 && !fn_801ED7B0(t->mEntry[idx].mSub2)) {
        u8* rec = lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8;
        u8 hi = rec[0x79];
        u8 lo = rec[0x78];
        if (hi == 0 && lo == 0) {
            result = 1;
        } else {
            u8 a = t->mEntry[idx].m20;
            u8 b = t->mEntry[idx].m21;
            if (a < hi || ((u8)a == hi && (u8)b < lo)) {
                result = 1;
            }
        }
    }
    return result;
}

extern "C" int fn_80215D38(HrmnTable* t) {
    int result = 1;
    for (int i = 0; i < t->mCount; i++) {
        bool ok = false;
        if (t->mEntry[i].m08 != 0 && t->mEntry[i].m0A == 0) {
            ok = true;
        }
        if (!ok) {
            result = 0;
            break;
        }
    }
    return result;
}

extern "C" void fn_80215D8C(HrmnTable* t, int idx) {
    if (t->mEntry[idx].m08 == 0 && t->mEntry[idx].m09 == 0) {
        t->mEntry[idx].m09 = 1;
    }
}

extern "C" void fn_80215DB8(HrmnTable* t) {
    for (int i = 0; i < t->mCount; i++) {
        fn_80215E18(&t->mEntry[i]);
    }
}

extern "C" void fn_80215E18(HrmnEntry* e) {
    fn_802162B8(&e->m08, e->mA, e->mId);
}

extern "C" s32 fn_80215E48(HrmnTable* t, int idx) {
    return t->mEntry[idx].mId;
}

extern "C" int fn_80215E58(HrmnTable* t, s32 id) {
    int result = -1;
    for (int i = 0; i < t->mCount; i++) {
        if (id == t->mEntry[i].mId) {
            result = i;
            break;
        }
    }
    return result;
}

extern "C" int fn_80215E98(HrmnTable* t) {
    return t->countSet();
}

extern "C" void fn_80215ECC(HrmnTable* t) {
    s32 n = t->mCount;
    HrmnTable* p = t;
    for (int i = 0; i < n; i++) {
        fn_801ED3DC(p->mEntry[0].mSub2, p->mEntry[0].mA, p->mEntry[0].mId);
        p = (HrmnTable*)((u8*)p + sizeof(HrmnEntry));
    }
}

extern "C" void fn_80215F30(HrmnTable* t) {
    s32 mode = *(s32*)(lbl_8053AAF8 + 0x4c);
    if (mode != 9 && mode != 0xb) {
        t->mA0 = fn_801CD664(10);
    }
    for (int i = 0; i < t->mCount; i++) {
        fn_801ED458(t->mEntry[i].mSub2, t->mA0);
    }
}

extern "C" void fn_80215FB8(HrmnTable* t, int idx, s32 id) {
    fn_801ED5C8(t->mEntry[idx].mSub2);
    t->mEntry[idx].mId = id;
}

extern "C" void fn_8021600C(HrmnTable* t) {
    for (int i = 0; i < t->mCount; i++) {
        fn_801ED798(t->mEntry[i].mSub2);
    }
}

extern "C" int fn_8021606C(HrmnTable* t) {
    s32 n = t->mCount;
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (t->mEntry[i].mId < 0 && fn_801ED7B0(t->mEntry[i].mSub2)) {
            result = 1;
            break;
        }
    }
    return result;
}

HrmnEntry::HrmnEntry() {
    Hrmn_InitSlotStateType3(mSub);
    m08 = 0;
    m09 = 0;
    m0A = 0;
    Hrmn_InitSlotStateType3(mSub);
    Hrmn_ActivateSlotB(mSub2);
    mA = 0;
    mId = -1;
    m08 = 0;
    m09 = 0;
    m0A = 0;
    Hrmn_InitSlotStateType3(mSub);
    Hrmn_ActivateSlotA(mSub2);
}


HrmnTable::HrmnTable() : mCount((s32)fn_80138A30(lbl_8053AAF8)) {
    reset();
}

extern "C" void fn_802160F4(HrmnTable* t) {
    for (int i = 0; i < t->mCount; i++) {
        t->mEntry[i].mA = i;
        t->mEntry[i].mId = -1;
        t->mEntry[i].m08 = 0;
        t->mEntry[i].m09 = 0;
        t->mEntry[i].m0A = 0;
        Hrmn_InitSlotStateType3(t->mEntry[i].mSub);
        fn_801ED7F0(t->mEntry[i].mSub2);
    }
    Hrmn_InitSlotStateType0xc(t->mSub.data);
    t->mA0 = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
