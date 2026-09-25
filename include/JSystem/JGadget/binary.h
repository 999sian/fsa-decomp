#ifndef JGADGET_BINARY_H
#define JGADGET_BINARY_H

#include "types.h"

// Adapted from the Pikmin 2 decompilation (projectPiki/pikmin2).

namespace JGadget {
namespace binary {

struct TEBit {
    u32 mValue; // _00
};

struct TParseData {
    TParseData(const void* content) : mRaw(content) { }

    const void* getRaw() const { return mRaw; }
    void setRaw(const void* content) { mRaw = content; }

    const void* mRaw; // _00
};

template <int T>
struct TParseData_aligned : public TParseData {
    TParseData_aligned(const void* content) : TParseData(content) { }

    void setRaw(const void* content) { static_cast<TParseData*>(this)->setRaw(content); }
};

struct TParse_header_block {
    inline TParse_header_block() { }

    virtual ~TParse_header_block() = 0;                                // _08
    virtual bool parseHeader_next(const void**, u32* outBlock, u32) = 0; // _0C
    virtual bool parseBlock_next(const void**, u32* outData, u32) = 0;   // _10

    bool parse_next(const void**, u32);

    bool parse(const void* p1, u32 p2) { return parse_next(&p1, p2); }

    bool checkNext(const void** ptrLocation, u32* headerEnd, u32 idx) {
        bool checkNext = false;
        if (parseHeader_next(ptrLocation, headerEnd, idx)) {
            checkNext = true;
        }
        return checkNext;
    }
};

template <typename T>
struct TParseValue_raw_ {
    typedef T ParseType;
    static T parse(const void* data) { return (T) * (T*)data; }
};

template <typename T>
struct TParseValue_endian_big_ : public TParseValue_raw_<T> {
    static T parse(const void* data) { return TParseValue_raw_<T>::parse(data); }
};

template <class Parser>
struct TParseValue : public Parser {
    static typename Parser::ParseType parse(const void* data) { return Parser::parse(data); }
};

extern const void* parseVariableUInt_16_32_following(const void*, u32*, u32*, TEBit*);

} // namespace binary
} // namespace JGadget

#endif
