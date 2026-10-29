#ifndef GAME_PANE_STATE_H
#define GAME_PANE_STATE_H
#include "JSystem/J2D/J2DPane.h"
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
#endif
