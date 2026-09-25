#include "JSystem/JGadget/binary.h"

// Adapted from the Pikmin 2 decompilation (projectPiki/pikmin2).
// parseVariableUInt_16_32_following is unused (dead-stripped) in FSA.

namespace JGadget {
namespace binary {

TParse_header_block::~TParse_header_block() { }

bool TParse_header_block::parse_next(void const** ptrLocation, u32 idx) {
    u32 headerEnd, blockEnd;

    if ((ptrLocation == nullptr) || (*ptrLocation == nullptr)) {
        return false;
    }
    bool check, checkLastBlock;
    checkLastBlock = check = false;

    check = checkNext(ptrLocation, &headerEnd, idx);

    checkLastBlock = check;
    if (!(idx & 1) && (check == false)) {
        return check;
    }

    while (headerEnd > 0) {
        check = false;
        if (parseBlock_next(ptrLocation, &blockEnd, idx) && checkLastBlock) {
            check = true;
        }
        checkLastBlock = check;
        if (((idx & 2) == 0) && (check == false)) {
            return check;
        }
        headerEnd--;
    }
    return checkLastBlock;
}

} // namespace binary
} // namespace JGadget
