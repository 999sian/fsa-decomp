#include "Game/SinitPoolChain.h"

#include "Game/actors/BOTS.h"

/* Definitions must stay in this order: the retail object emits the
 * destructor first, then v06, v03 and v01 (0x800FEDD0, 0x800FEE30,
 * 0x800FEE34, 0x800FEE38). */
BOTS::~BOTS() {}

void BOTS::v06() {}

void BOTS::v03() {}

void BOTS::v01() {}
