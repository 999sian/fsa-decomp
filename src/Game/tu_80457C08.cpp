
extern "C" void fn_8045787C(void*, int);

#pragma exceptions off
extern "C" void fn_80457C08(char* p, int v) {
    void (*call)(void*, int) = fn_8045787C;
    p -= 0x18;
    call(p, v);
}

void __sinit_tu_80457C08_cpp(void) {}

#pragma exceptions reset
#include "JSystem/JAudio/System/JASHeapCtrl.h"
#include "JSystem/JAudio/System/JASTrack.h"

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
