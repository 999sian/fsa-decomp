// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "JSystem/J2D/J2DPane.h"

#pragma exceptions off

bool J2DWindow::isUsed(const ResFONT *resource) {
    return J2DPane::isUsed(resource);
}

void J2DWindow::rewriteAlpha() {}
