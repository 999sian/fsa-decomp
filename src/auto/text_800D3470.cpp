#include "types.h"
#include "JSystem/J3D/J3DTypes.h"

struct UnkDC8C {
    s16 m_a;
    s16 m_b;
    s16 m_c;
    s16 m_d;
};

struct UnkDCF8 {
    u8 m_a;
    u8 m_b;
    u8 m_c;
    u8 m_d;
};
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" int fn_800D3E48(void) { return 0x69; }

extern "C" int fn_800D3E50(void) { return 0x14f; }

extern "C" int fn_800D3E58(void) { return 0x244; }

extern "C" int fn_800D3E60(void) { return 0x3e8; }

extern "C" int fn_800D3E68(void) { return 0x8c; }

extern "C" int fn_800D3E70(void) { return 0x1e; }

extern "C" int fn_800D3E78(void) { return 0x1e; }

extern "C" int fn_800D3E80(void) { return 0x1e; }

extern "C" int fn_800D3E88(void) { return 0x1e; }

extern "C" int fn_800D3E90(void) { return 0x55; }

extern "C" void fn_800DDA9C(void* dst, const void* src) {
    *(u32*)((u8*)dst + 8) = *(const u32*)src;
}

extern "C" void fn_800DDC1C(u16* this_, s32 idx, u16 val) {
    this_[idx + 4] = val;
}

extern "C" void fn_800DDC2C(u16* this_, s32 idx, u16* src) {
    this_[idx + 4] = *src;
}

extern "C" u16 fn_800DDC40(u16* this_, s32 idx) {
    return this_[idx + 4];
}

extern "C" void fn_800DDC50(u8* this_, s32 idx, u32* src) {
    *(u32*)(this_ + 0x18 + idx * 4) = *src;
}

extern "C" void fn_800DDC64(u8* this_, s32 idx, u32* src) {
    *(u32*)(this_ + 0x18 + idx * 4) = *src;
}

extern "C" u32* fn_800DDC78(u8* this_, s32 idx) {
    return (u32*)(this_ + 0x18 + idx * 4);
}

extern "C" void fn_800DDC8C(u8* this_, s32 idx, UnkDC8C* src) {
    *(UnkDC8C*)(this_ + 0xda + idx * 8) = *src;
}

extern "C" void* fn_800DDCE4(u8* this_, s32 idx) {
    return this_ + 0xda + idx * 8;
}

extern "C" void fn_800DDCF8(u8* this_, s32 idx, UnkDCF8* src) {
    *(UnkDCF8*)(this_ + 0xfa + idx * 4) = *src;
}

extern "C" void fn_800DE05C(u16* this_, s32 idx, u16 val) {
    this_[idx + 4] = val;
}

extern "C" void fn_800DE06C(u16* this_, s32 idx, u16* src) {
    this_[idx + 4] = *src;
}

extern "C" u16 fn_800DE080(u16* this_, s32 idx) {
    return this_[idx + 4];
}

extern "C" void fn_800DE49C(u16* this_, s32 idx, u16 val) {
    this_[idx + 4] = val;
}

extern "C" void fn_800DE4AC(u16* this_, s32 idx, u16* src) {
    this_[idx + 4] = *src;
}

extern "C" u16 fn_800DE4C0(u16* this_, s32 idx) {
    return this_[idx + 4];
}

extern "C" void fn_800DE8DC(u16* this_, s32 idx, u16 val) {
    this_[idx + 4] = val;
}

extern "C" void fn_800DE8EC(u16* this_, s32 idx, u16* src) {
    this_[idx + 4] = *src;
}

extern "C" u16 fn_800DE900(u16* this_, s32 idx) {
    return this_[idx + 4];
}

extern "C" u32* fn_800DEA10(u8* this_, s32 idx) {
    return (u32*)(this_ + 0x18 + idx * 4);
}

extern "C" void fn_800DEB54(u16* this_, s32 idx, u16 val) {
    this_[idx + 4] = val;
}

extern "C" void fn_800DEB64(u16* this_, s32 idx, u16* src) {
    this_[idx + 4] = *src;
}

extern "C" u16 fn_800DEB78(u16* this_, s32 idx) {
    return this_[idx + 4];
}

extern "C" void fn_800DEB88(u8* this_, s32 idx, u32* src) {
    *(u32*)(this_ + 0x18 + idx * 4) = *src;
}

extern "C" void fn_800DEB9C(u8* this_, s32 idx, u32* src) {
    *(u32*)(this_ + 0x18 + idx * 4) = *src;
}

extern "C" u32* fn_800DEBB0(u8* this_, s32 idx) {
    return (u32*)(this_ + 0x18 + idx * 4);
}

extern "C" void fn_800DEE0C(u8* self, const J3DNBTScaleInfo* other) {
    *(J3DNBTScaleInfo*)(self + 0x5c) = *other;
}

extern "C" void fn_800DEE30(u8* self, const J3DNBTScaleInfo* other) {
    *(J3DNBTScaleInfo*)(self + 0x5c) = *other;
}

extern "C" u8* fn_800DEE54(u8* self) {
    return self + 0x5c;
}

extern "C" void fn_800DEF48(u8* self, const J3DNBTScaleInfo* other) {
    *(J3DNBTScaleInfo*)(self + 0x5c) = *other;
}

extern "C" void fn_800DEF6C(u8* self, const J3DNBTScaleInfo* other) {
    *(J3DNBTScaleInfo*)(self + 0x5c) = *other;
}

extern "C" u8* fn_800DEF90(u8* self) {
    return self + 0x5c;
}

extern "C" void fn_800DF004(void) {}

extern "C" int fn_800DF008(void) { return 0x54475054; }

extern "C" int fn_800DF014(void) { return 0x434c4f4e; }

extern "C" void fn_800DF020(u8* this_, s32 idx, u8* src) {
    s32 off = idx * 4;
    this_[off + 4] = src[0];
    this_[off + 5] = src[1];
    this_[off + 6] = src[2];
    this_[off + 7] = src[3];
}

extern "C" u32 fn_800DF3CC(u8* this_) { return *(u32*)(this_ + 0x18); }

extern "C" u32 fn_800DF3D4(u8* this_) { return *(u32*)(this_ + 0x1c); }

extern "C" void fn_800DF3DC(u8* this_, u32 val) { *(u32*)(this_ + 0x18) = val; }

extern "C" void fn_800DF3E4(u8* this_, u32 val) { *(u32*)(this_ + 0x1c) = val; }

