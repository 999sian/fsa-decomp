#include "Game/SinitPoolChain.h"

#include "Game/actors/DWAP.h"

/* Definitions must stay in this order: the retail object emits the destructor
 * first, then v06, v03 and v01 (0x8010307C, 0x801030DC, 0x801030E0,
 * 0x80103100), and the compiler-generated __sinit_DWAP_cpp last (0x80103124). */
DWAP::~DWAP() {}

void DWAP::v06() {}

void DWAP::v03() {
    detach();
}

void DWAP::v01() {
    field_238 = (field_90 >> 16) & 0xFF;
    field_23C = (field_90 >> 8) & 0xFF;
    field_230 = 0;
}
