#include "Game/SinitPoolChain.h"

#include "Game/actors/STGN.h"

extern "C" void* fn_802D6A9C();
extern "C" void fn_802D7934(void*, u32);

/* Definitions must stay in this order: the retail object emits the
 * destructor first, then v06, v03 and v01 (0x802F4820, 0x802F4880,
 * 0x802F4884, 0x802F4888). */
STGN::~STGN() {}

void STGN::v06() {}

void STGN::v03() {}

void STGN::v01() {
    fn_802D7934(fn_802D6A9C(), field_90 & 0xF);
    field_11C = 0;
}
