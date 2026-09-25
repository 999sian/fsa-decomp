#include "JSystem/JGadget/vector.h"

// Adapted from the Pikmin 2 decompilation (projectPiki/pikmin2).
// Only extend_default survives in this TU in FSA; the TVector_pointer_void
// members are not present here.

namespace JGadget {

u32 vector::extend_default(u32 capacity, u32 oldSize, u32 count) {
    return oldSize * 2;
}

} // namespace JGadget
