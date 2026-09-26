// TU 0x802BA334-0x802BA558: only the shared JAudio pool __sinit
// (docs/game/sinit_pools.md).
#include "JSystem/JAudio/JASFakeMatchFSA.h"
// Code matches 100%, but a TU whose only function is a local __sinit gets
// dead-stripped by mwld when linked (nothing references the object), so it
// stays NonMatching.
static u8 lbl_804D27D4[0x94];
