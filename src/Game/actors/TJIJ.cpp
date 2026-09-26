#include "Game/SinitPoolChain.h"
#include "Game/actors/TJIJ.h"

/* The three empty overrides are declared and defined in retail emission order
 * (slot 6, slot 3, slot 1, then the destructor) - Metrowerks emits out-of-line
 * member functions in declaration order, so this is what puts the three `blr`
 * stubs before the 0x60-byte destructor at 0x80372EB4. */
void TJIJ::v06() {}

void TJIJ::v03() {}

void TJIJ::v01() {}

TJIJ::~TJIJ() {}
