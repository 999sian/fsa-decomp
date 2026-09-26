#ifndef _TYPES_H
#define _TYPES_H
#include "../../types.h"

//PIKIMIN: CLONED FROM REPO

// r2 is  8051E360
// r13 is 8051C680
#ifndef UNK_PARAMS
#ifdef M2CTX
#define UNK_PARAMS
#else
#define UNK_PARAMS void
#endif
#endif




typedef long double f128;
typedef volatile f128 vf128;

//typedef u32 size_t;

#ifndef __cplusplus
typedef u16 wchar_t;
#endif

// Basic defines to allow newer-like C++ code to be written
#ifndef TRUE
#define TRUE  1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef NULL
#define NULL  ((void*)0)
#endif
#ifndef nullptr
#define nullptr 0
#endif

// Sets specific flag to 1
#ifndef SET_FLAG
#define SET_FLAG(x, val) (x |= (val))
#endif

// Resets specific flag from (val) back to 0
#ifndef RESET_FLAG
#define RESET_FLAG(x, val) (x &= ~(val))
#endif

// Return 1 if flag is set, 0 if flag is not set
#ifndef IS_FLAG
#define IS_FLAG(x, val) (x & val)
#endif

// Array size define
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(o) (sizeof((o)) / sizeof(*(o)))
#endif

// Align X to the previous N bytes (N must be power of two)
#ifndef ALIGN_PREV
#define ALIGN_PREV(X, N) ((X) & ~((N)-1))
#endif

// Align X to the next N bytes (N must be power of two)
#ifndef ALIGN_NEXT
#define ALIGN_NEXT(X, N) ALIGN_PREV(((X) + (N)-1), N)
#endif

// True if X is aligned to N bytes, else false
#ifndef IS_ALIGNED
#define IS_ALIGNED(X, N) ((X & ((N)-1)) == 0)
#endif

// True if X is not aligned to N bytes, else false
#ifndef IS_NOT_ALIGNED
#define IS_NOT_ALIGNED(X, N) (((X) & ((N)-1)) != 0)
#endif

// Align object to num bytes (num should be power of two)
#ifndef ATTRIBUTE_ALIGN
#define ATTRIBUTE_ALIGN(num) __attribute__((aligned(num)))
#endif

// Checks if a flag is set in a bitfield
#ifndef IS_FLAG_SET
#define IS_FLAG_SET(flags, bitsFromLSB) (((flags) >> (bitsFromLSB)&1))
#endif

// For functions that return 0 on a success and -1 on failure
#define EXIT_SUCCESS 0
#define EXIT_FAILURE -1

#ifndef ASSERT_HANG
#define ASSERT_HANG(cond) \
	if (!(cond)) {        \
		while (true) { }  \
	}
#endif

// Get the maximum of two values
#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

// Get the minimum of two values
#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

// Rounds a float to a u8
#ifndef ROUND_F32_TO_U8
#define ROUND_F32_TO_U8(a) a >= 0.0f ? a + 0.5f : a - 0.5f
#endif

// Number of bytes in a kilobyte
#define KILOBYTE_BYTECOUNT 1024

#ifdef __MWERKS__
#define WEAKFUNC        __declspec(weak)
#ifndef DECL_SECT
#define DECL_SECT(name) __declspec(section name)
#endif
#define ASM             asm
#else
#define WEAKFUNC
#ifndef DECL_SECT
#define DECL_SECT(name)
#endif
#define ASM
#endif

#endif // _TYPES_H
