#ifndef JGADGET_SEARCH_H
#define JGADGET_SEARCH_H

#include "types.h"

// Adapted from the Pikmin 2 decompilation (projectPiki/pikmin2).

namespace JGadget {

template <typename T>
inline const T& toValueFromIndex(int idx, const T* values, u32 count, const T& fallback) {
    return (idx >= count) ? fallback : values[idx];
}

} // namespace JGadget

#endif
