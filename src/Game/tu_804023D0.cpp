#include "types.h"
#include "JSystem/J2D/J2DPane.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JKernel/JKRFileLoader.h"

#pragma auto_inline off

struct PaneState {
    void* vtable;
    J2DPane* pane;
    f32 x;
    f32 y;
    f32 centerX;
    f32 centerY;
    f32 width;
    f32 height;
    s16 field20;
    s16 field22;
    s16 field24;
    s16 alphaFrame;
    u8 alpha;
};

struct ResourceState {
    u8 pad00[0x10];
    JKRFileLoader* archive10;
    u8 pad14[4];
    JKRFileLoader* archive18;
    u8 pad1C[4];
    JKRFileLoader* archive20;
    JKRFileLoader* archive24;
    JKRFileLoader* archive28;
    u8 pad2C[8];
    JKRFileLoader* archive34;
    JKRFileLoader* archive38;
    JKRFileLoader* archive3C;
    u8 pad40[0xC];
    JKRFileLoader* archive4C;
    u8 pad50[0x28];
    s32 settings78[4];
    s32 settings88[4];
    u8 pad98[0x10];
    s32 settingsA8[4];
    s32 settingsB8[4];
    u8 padC8[0x50];
    s32 stage;
    s32 room;
    u8 pad120[0xA4];
    JGeometry::TVec3f positions[4];
    u8 pad1F4[0x42];
    u8 positionMask;
};

extern ResourceState lbl_80529DEC;
extern u8* lbl_8053AAF8;
extern const u32 lbl_8048C160[];
extern const u32 lbl_8048C170[];
extern const f32 lbl_80543868;
extern const f32 lbl_8054386C;
extern "C" s32 fn_8022F340(u32 player);

extern "C" void fn_804023D0(PaneState* state, J2DPane* pane, u8 alpha) {
    pane->setAlpha((f32)alpha * ((f32)state->pane->mAlpha / (f32)state->alpha));
}

extern "C" s32 fn_80402628(PaneState* state, s16 duration, u8 startAlpha, u8 endAlpha) {
    if (state->alphaFrame < duration - 1) {
        ++state->alphaFrame;
        state->pane->setAlpha(((f32)state->alphaFrame / (f32)duration) *
                                      (f32)(endAlpha - startAlpha) + (f32)startAlpha);
    } else {
        state->field22 = duration;
        state->pane->setAlpha(endAlpha);
        return 1;
    }
    return 0;
}

extern "C" s32 fn_80402940(PaneState* state, s16 index, u8 mode, f32 a, f32 b) {
    f32 t;
    f32 y;
    f32 x;

    if (state->field22 < index - 1) {
        state->field22++;
        if (mode == 0) {
            t = (f32)(state->field22 * state->field22) / (f32)(index * index);
        } else if (mode == 1) {
            t = (f32)state->field22 / (f32)index;
        } else {
            t = (f32)((index - state->field22) * (index - state->field22)) / (f32)(index * index);
            f32 tmp = a;
            a = b;
            b = tmp;
        }
        y = state->centerY + (a + t * (b - a)) - lbl_80543868 * (state->pane->mBounds.f.y - state->pane->mBounds.i.y);
        x = state->pane->getBounds()->i.x;
        state->pane->move(x, y);
    } else {
        state->field22 = index;
        y = state->centerY + b - lbl_80543868 * (state->pane->mBounds.f.y - state->pane->mBounds.i.y);
        x = state->pane->getBounds()->i.x;
        state->pane->move(x, y);
        return 1;
    }
    return 0;
}

extern "C" void fn_80402CE0(PaneState* state, f32 sx, f32 sy) {
    f32 width = state->pane->mBounds.f.x - state->pane->mBounds.i.x;
    f32 x = state->pane->getBounds()->i.x;
    f32 height = state->pane->mBounds.f.y - state->pane->mBounds.i.y;
    f32 y = state->pane->getBounds()->i.y;
    state->pane->resize(state->width * sx, state->height * sy);
    f32 newWidth = state->pane->mBounds.f.x - state->pane->mBounds.i.x;
    f32 newHeight = state->pane->mBounds.f.y - state->pane->mBounds.i.y;
    state->pane->move(lbl_80543868 * width + x - lbl_80543868 * newWidth, lbl_80543868 * height + y - lbl_80543868 * newHeight);
}

extern "C" void fn_80402E08(PaneState* state, f32 x, f32 y) {
    J2DPane* pane = state->pane;
    pane->move((state->centerX + x) - lbl_80543868 * (pane->mBounds.f.x - pane->mBounds.i.x),
               (state->centerY + y) - lbl_80543868 * (pane->mBounds.f.y - pane->mBounds.i.y));
}

extern "C" void fn_80402E70(PaneState* state) {
    state->x = state->pane->getBounds()->i.x;
    state->y = state->pane->getBounds()->i.y;
    state->width = state->pane->mBounds.f.x - state->pane->mBounds.i.x;
    state->height = state->pane->mBounds.f.y - state->pane->mBounds.i.y;
    state->centerX = lbl_80543868 * state->width + state->x;
    state->centerY = lbl_80543868 * state->height + state->y;
}

extern "C" void fn_80402F04(PaneState* state, J2DPane* pane) {
    state->pane = pane;
    state->x = pane->getBounds()->i.x;
    state->y = pane->getBounds()->i.y;
    state->width = pane->mBounds.f.x - pane->mBounds.i.x;
    state->height = pane->mBounds.f.y - pane->mBounds.i.y;
    state->centerX = lbl_80543868 * state->width + state->x;
    state->centerY = lbl_80543868 * state->height + state->y;
    state->alpha = pane->mAlpha;
    state->field20 = 0;
    state->field22 = 0;
    state->field24 = 0;
    state->alphaFrame = 0;
}

extern "C" void fn_80402FBC(u32 player, const JGeometry::TVec3f* position) {
    s32 index = fn_8022F340(player);
    JGeometry::TVec3f value(*position);
    JGeometry::TVec3f copy(value);
    lbl_80529DEC.positions[index].set(copy);
    s32 bit = 1 << fn_8022F340(player);
    lbl_80529DEC.positionMask |= (u8)bit;
}

extern "C" u32 fn_8040305C(s32 index) {
    return lbl_8048C170[index];
}

extern "C" u32 fn_80403070(s32 index) {
    return lbl_8048C160[index];
}

extern "C" void* fn_80403084(u32 type, const char* name) {
    return lbl_80529DEC.archive4C->getResource(type, name);
}

extern "C" void* fn_804030C4(u32 type, const char* name) {
    return lbl_80529DEC.archive20->getResource(type, name);
}

extern "C" void* fn_80403104(u32 type, const char* name) {
    return lbl_80529DEC.archive3C->getResource(type, name);
}

extern "C" void* fn_80403144(u32 type, const char* name) {
    return lbl_80529DEC.archive38->getResource(type, name);
}

extern "C" void* fn_80403184(u32 type, const char* name) {
    return lbl_80529DEC.archive34->getResource(type, name);
}

extern "C" void* fn_804031C4(u32 type, const char* name) {
    return lbl_80529DEC.archive28->getResource(type, name);
}

extern "C" void* fn_80403204(u32 type, const char* name) {
    return lbl_80529DEC.archive24->getResource(type, name);
}

extern "C" void* fn_80403244(u32 type, const char* name) {
    return lbl_80529DEC.archive18->getResource(type, name);
}

extern "C" s32 fn_80403284(const char* name) {
    return lbl_80529DEC.archive10->getResSize(lbl_80529DEC.archive10->getResource(0x3F3F3F3F, name));
}

extern "C" void* fn_804032E8(u32 type, const char* name) {
    return lbl_80529DEC.archive10->getResource(type, name);
}

extern "C" void* fn_80403328(const char* name) {
    return lbl_80529DEC.archive10->getResource(0x3F3F3F3F, name);
}

extern "C" s32 fn_8040336C(s32 index) {
    if (lbl_8053AAF8[0x7F] != 0) {
        if (lbl_80529DEC.stage == 0 && lbl_80529DEC.room == 0) {
            return 0;
        }
        return lbl_80529DEC.settings88[index];
    }
    return lbl_80529DEC.settingsB8[index];
}

extern "C" s32 fn_804033D4(s32 index) {
    if (lbl_8053AAF8[0x7F] != 0) {
        return lbl_80529DEC.settings78[index];
    }
    return lbl_80529DEC.settingsA8[index];
}
