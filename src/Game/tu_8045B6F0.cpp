#include "types.h"
#include "JSystem/JAudio/Interface/JAISound.h"
#include "JSystem/JAudio/System/JASHeapCtrl.h"
#include "JSystem/JAudio/System/JASTrack.h"

extern "C" void fn_80255AC0(char* p);
#pragma optimization_level 4
extern "C" void fn_8045B6F0(char* p) {
    fn_80255AC0(&p[-0x18]);
}

JAISoundID lbl_8052DEE0[49] = {
    0x1000002, 0x3, 0x20011, 0x20034, 0x9, 0x30009, 0x12, 0x400b9,
    0x50004, 0x5000d, 0x1000023, 0x42, 0x60000, 0x60001, 0x60002, 0x60003,
    0x60004, 0x60005, 0x60006, 0x60007, 0x60008, 0x60009, 0x6000a, 0x6000b,
    0x6000c, 0x6000d, 0x6000e, 0x6000f, 0x60010, 0x60011, 0x60012, 0x60013,
    0x60014, 0x60015, 0x60016, 0x60017, 0x60018, 0x60019, 0x6001a, 0x3a,
    0x3b, 0x6001b, 0x6001c, 0x6001d, 0x6001e, 0x6001f, 0x60020, 0x60021,
    0x60022
};

class JAIStream;
class JAISoundChild;
class JAISeq;
class JAISe;
class JASPoolObj4_FSA;

template <>
JASMemPool_MultiThreaded<JASTrack::TChannelMgr> JASPoolAllocObject_MultiThreaded<JASTrack::TChannelMgr>::memPool_;
template <>
JASMemPool_MultiThreaded<JASTrack> JASPoolAllocObject_MultiThreaded<JASTrack>::memPool_;
template <>
JASMemPool_MultiThreaded<JASChannel> JASPoolAllocObject_MultiThreaded<JASChannel>::memPool_;
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

#pragma optimization_level reset
