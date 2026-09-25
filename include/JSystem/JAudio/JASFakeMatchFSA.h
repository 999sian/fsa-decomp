#ifndef JAUDIO_JASFAKEMATCHFSA_H
#define JAUDIO_JASFAKEMATCHFSA_H

// FSA's full set of JASPoolAllocObject memPool_ definitions, in retail order.
//
// 511 retail TUs end in an identical 0x224-byte __sinit that registers these
// nine pools (pool .bss 0x804B21AC + 0x10*i, guard .sbss 0x8053A2AC + i).
// Every TU that sees these definitions emits that __sinit; the pools, guards
// and JASMemPool<T> destructors are weak, so one copy of each is linked.
//
// Pools 3 and 4 hold two FSA classes that MKDD/TP don't have. Their real names
// are unknown; sizeof(pool 3 object) == 0x40 (allocated in the JAUStream*
// area around 0x8003D03C), pool 4 is never allocated from in main.dol. The
// placeholder names below only affect symbol names, not code.
// See docs/game/sinit_pools.md.

#include "JSystem/JAudio/System/JASHeapCtrl.h"
#include "JSystem/JAudio/System/JASTrack.h"

class JAIStream;
class JAISoundChild;
class JAISeq;
class JAISe;
class JASPoolObj3_FSA;
class JASPoolObj4_FSA;

template <>
JASMemPool_MultiThreaded<JASTrack::TChannelMgr> JASPoolAllocObject_MultiThreaded<JASTrack::TChannelMgr>::memPool_;
template <>
JASMemPool_MultiThreaded<JASTrack> JASPoolAllocObject_MultiThreaded<JASTrack>::memPool_;
template <>
JASMemPool_MultiThreaded<JASChannel> JASPoolAllocObject_MultiThreaded<JASChannel>::memPool_;
template <>
JASMemPool<JASPoolObj3_FSA> JASPoolAllocObject<JASPoolObj3_FSA>::memPool_;
template <>
JASMemPool<JASPoolObj4_FSA> JASPoolAllocObject<JASPoolObj4_FSA>::memPool_;
template <>
JASMemPool<JAIStream> JASPoolAllocObject<JAIStream>::memPool_;
template <>
JASMemPool<JAISoundChild> JASPoolAllocObject<JAISoundChild>::memPool_;
template <>
JASMemPool<JAISeq> JASPoolAllocObject<JAISeq>::memPool_;
template <>
JASMemPool<JAISe> JASPoolAllocObject<JAISe>::memPool_;

#endif
