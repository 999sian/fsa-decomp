#ifndef JGADGET_VECTOR_H
#define JGADGET_VECTOR_H

#include "types.h"

// Adapted from the Pikmin 2 decompilation (projectPiki/pikmin2).

namespace JGadget {
namespace vector {

u32 extend_default(u32, u32, u32);

typedef u32 (*ExtendFunc)(u32, u32, u32);

} // namespace vector
} // namespace JGadget

#endif
