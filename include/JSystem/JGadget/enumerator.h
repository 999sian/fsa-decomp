#ifndef JGADGET_ENUMERATOR_H
#define JGADGET_ENUMERATOR_H

#include "types.h"
#include "JSystem/JGadget/linklist.h"

// Adapted from the Pikmin 2 decompilation (projectPiki/pikmin2).

namespace JGadget {

template <typename Iterator, typename T>
struct TEnumerator2 {
    inline TEnumerator2(Iterator current, Iterator end) : mCurrent(current), mEnd(end) { }

    T& operator*() {
        T& result = *mCurrent;
        ++mCurrent;
        return result;
    }

    bool isEnd() const { return mCurrent != mEnd; }
    operator bool() const { return isEnd(); }

    Iterator mCurrent; // _00
    Iterator mEnd;     // _04
};

template <typename T, int I>
struct TContainerEnumerator : public TEnumerator2<typename TLinkList<T, I>::iterator, T> {
    TContainerEnumerator(TLinkList<T, I>* list)
        : TEnumerator2<typename TLinkList<T, I>::iterator, T>(list->begin(), list->end()) { }
};

template <typename T, int I>
struct TContainerEnumerator_const : public TEnumerator2<typename TLinkList<T, I>::const_iterator, const T> {
    inline TContainerEnumerator_const(const TLinkList<T, I>* list)
        : TEnumerator2<typename TLinkList<T, I>::const_iterator, const T>(list->begin(), list->end()) { }
};

} // namespace JGadget

#endif
