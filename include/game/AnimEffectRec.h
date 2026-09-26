#ifndef GAME_ANIMEFFECTREC_H
#define GAME_ANIMEFFECTREC_H

// Animated effect record shared by JIJI/TWTG/FTGL (TU 0x80316E34, slice e4).
// Include after "JSystem/JGeometry/Vec.h".

struct AnimFrame {
    u16 frame;
    s16 duration; // -1: hold, -2: loop
};

struct AnimEffectRec {
    s32 frame;                   // 0x0
    s32 mode;                    // 0x4
    u8 index;                    // 0x8
    u8 timer;                    // 0x9
    s32 player;                  // 0xc
    JGeometry::TVec3<f32> pos;   // 0x10

    ~AnimEffectRec();
};

extern "C" s32 fn_80316E34(AnimEffectRec* r);
extern "C" void fn_80316E50(AnimEffectRec* r, s32 player, const JGeometry::TVec3<f32>& pos);
extern "C" s32 fn_80316E74(AnimEffectRec* r, s32 arg);

#endif
