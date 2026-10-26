#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "Game/ItemBase.h"
#include "dolphin/mtx.h"


extern "C" u8* lbl_804ADA98[];
extern "C" u8 lbl_80472848[];
extern "C" u8 lbl_804AD900[];
extern "C" const u8 ro_0[0x1790] = {1};
static const u8 ro_1790[0x30] = {1};
static const u32 ro_17c0[0x288 / 4] = {1};
static const u8 ro_1a48[0x50] = {1};
struct UnkRGB { u8 r, g, b; };
static const UnkRGB ro_1a98[8] = {{1, 1, 1}};
static u32 data_0[22] = {1};
static u32 data_58[22] = {1};
static u32 data_b0[22] = {1};
struct FsaActorList {
    u8 pad0[8];
    u8* actors[0x400];
    s32 count;
    s32 getCount() const { return count; }
    u8* getActor(s32 idx) const { return actors[idx]; }
};
extern "C" u8* fn_801F856C(void);
static inline FsaActorList* getActorList() { return (FsaActorList*)fn_801F856C(); }
static inline void findEndmActor(u8* param_1) {
    s32 count = getActorList()->count;
    for (s32 i = 0; i < count; i++) {
        u8* act = getActorList()->actors[i];
        if (act != NULL && *(u32*)(act + 0x1a0) == 0x454e444d && *(u8*)(act + 0x11c) == 1) {
            *(u8**)(param_1 + 0x29c) = act;
            break;
        }
    }
}
extern "C" s32 Actor_CreateByID(void* mgr, u32 fourcc, s32 room, void* pos, u32 param, s32 a, s32 b);
extern "C" u8* fn_8013CC50(s32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" s32 fn_80230498(s32 index, const JGeometry::TVec3<f32>& pos, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
extern "C" void fn_80360914(u8* p);
extern "C" u8 __vt__4EOWL[];
extern "C" void __dt__5ActorFv(void* p, s32 flag);
extern "C" void __dl__FPv(void* p);
class FsaState;
typedef void (FsaState::*FsaStateFn)();
struct FsaStateEntry {
    FsaStateFn fn;
};
extern FsaStateEntry lbl_804ADA50[];
struct FsaStateTable { FsaStateEntry states[6]; };
extern "C" u8 lbl_8050BEF8[];
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;

struct JMathSinCos { f32 sin; f32 cos; };
struct FsaCurEntry {
    s32 key;
    f32 radius;
    JGeometry::TVec3<f32> pos;
    u8 type;
};
extern "C" s32 lbl_804742A8[];
extern "C" const JMathSinCos sincosTable___5JMath[];
extern "C" u8 fn_802E948C(char* p, f32 target, s32 frames);
static inline void executeCurEntry(u8* p) {
    FsaCurEntry* entry=*(FsaCurEntry**)(p+0x298);
    s32 key=entry->key;
    if(key<0) {
        if(key==-1) fn_802E948C(*(char**)(p+0x29c),entry->pos.x,(s32)entry->pos.y);
        else *(s32*)(p+0x230)=key+5;
    } else {
        s8 kind=key;
        s32 count=getActorList()->getCount();
        for(s32 i=0;i<count;++i) {
            u8* actor=getActorList()->getActor(i);
            if(actor && *(u32*)(actor+0x1a0)==0x45455443 && kind==*(s8*)(actor+0x230)) {
                *(u8*)(actor+0x230)=0;
                break;
            }
        }
    }
}
static inline u8 advanceCurEntry(u8* p) {
    *(FsaCurEntry**)(p+0x298)+=1;
    if((*(FsaCurEntry**)(p+0x298))->key==-1000) *(FsaCurEntry**)(p+0x298)=0;
    return 1;
}
static inline u8 triggerCurEntry(u8* p) {
    executeCurEntry(p);
    *(u8*)(p+0x294)=(*(FsaCurEntry**)(p+0x298))->type;
    return advanceCurEntry(p);
}

extern "C" u8 fn_8035F3C0(u8* p);
extern "C" f32 lbl_80542A00;
extern "C" f32 lbl_80542A04;
extern "C" f32 lbl_80542A08;
extern "C" f32 lbl_80542A0C;
extern "C" f32 lbl_80542A10;
extern "C" void fn_8013CB44(u8* owner, u8* p, s32 a, s32 b, s32 c);
extern "C" void* fn_8035F360(void* param_1, s16 param_2) {
  if (param_1 != 0) {
    *(u8**)param_1 = __vt__4EOWL;
    __dt__5ActorFv(param_1, 0);
    if (param_2 > 0) {
      __dl__FPv(param_1);
    }
  }
  return param_1;
}

extern "C" u8 fn_8035F3C0(u8* p) {
    if(!p[0x294] || !*(FsaCurEntry**)(p+0x298)) return 0;
    JGeometry::TVec3f pos=*(JGeometry::TVec3f*)(p+0xc);
    pos.z=0.0f;
    JGeometry::TVec3f target;
    FsaCurEntry* entry=*(FsaCurEntry**)(p+0x298);
    if(entry->key==-1) {
        if(lbl_80542A04==entry->radius || lbl_80542A08==entry->radius) {
            target.x=entry->pos.z;
            target.y=0.0f;
            target.z=0.0f;
        } else if(lbl_80542A0C==entry->radius || lbl_80542A10==entry->radius) {
            target.y=entry->pos.z;
            target.x=0.0f;
            target.z=0.0f;
        } else return advanceCurEntry(p);
    } else target.set(entry->pos.x,entry->pos.y,entry->pos.z);
    entry=*(FsaCurEntry**)(p+0x298);
    if(entry->radius>0.0f) {
        if(PSVECDistance(&pos,&target)<(*(FsaCurEntry**)(p+0x298))->radius) return triggerCurEntry(p);
    } else if(lbl_80542A04==entry->radius) {
        if(pos.x<target.x) return triggerCurEntry(p);
    } else if(lbl_80542A08==entry->radius) {
        if(pos.x>target.x) return triggerCurEntry(p);
    } else if(lbl_80542A0C==entry->radius) {
        if(pos.y<target.y) return triggerCurEntry(p);
    } else {
        if(pos.y>target.y) return triggerCurEntry(p);
    }
    return 0;
}

extern "C" f32 __fres(f32);
extern "C" f32 lbl_80542A18;
extern "C" f32 lbl_80542A1C;
extern "C" f32 lbl_80542A20;
extern "C" f32 lbl_80542A24;
extern "C" f32 lbl_80542A28;
extern "C" f32 lbl_80542A2C;
extern "C" void fn_8035F9C8(u8* param_1) {
    if (*(s32*)(param_1 + 0x234) == 0) {
        if (lbl_804742A8[*(s32*)(param_1 + 0x240) * 2] < 0) {
            *(s32*)(param_1 + 0x240) = 0;
        }
        *(s32*)(param_1 + 0x234) = lbl_804742A8[*(s32*)(param_1 + 0x240) * 2 + 1];
        *(s32*)(param_1 + 0x23c) = lbl_804742A8[*(s32*)(param_1 + 0x240) * 2];
        *(s32*)(param_1 + 0x240) = *(s32*)(param_1 + 0x240) + 1;
    }
    if (*(f32*)(param_1 + 0x26c) > 3.0f) {
        *(f32*)(param_1 + 0x26c) = *(f32*)(param_1 + 0x26c) - 0.2f;
    }
    f32 speed = 1.3f;
    f32 inv = __fres(6.28318f * *(f32*)(param_1 + 0x26c));
    s32 step = (s32)(65536.0f * (inv * speed));
    *(s16*)(param_1 + 0x254) = *(s16*)(param_1 + 0x254) - step;
    *(f32*)(param_1 + 0x3c) = speed * sincosTable___5JMath[(*(s16*)(param_1 + 0x254) >> 5) & 0x7ff].cos;
    *(f32*)(param_1 + 0x40) = speed * sincosTable___5JMath[(*(s16*)(param_1 + 0x254) >> 5) & 0x7ff].sin;
    *(f32*)(param_1 + 0x44) = -0.2f;
    *(JGeometry::TVec3<f32>*)(param_1 + 0xc) += *(JGeometry::TVec3<f32>*)(param_1 + 0x3c);
    *(s32*)(param_1 + 0x264) = *(s32*)(param_1 + 0x264) + (s16)step;
    if (*(f32*)(param_1 + 0x26c) < 3.0f) {
        u8* c = *(u8**)(param_1 + 0x2b4);
        if (c != NULL) {
            *(u32*)(c + 0xf4) |= 1;
            *(s32*)(c + 0x24) = 1;
            *(u8**)(param_1 + 0x2b4) = NULL;
        }
        c = *(u8**)(param_1 + 0x2b8);
        if (c != NULL) {
            *(u32*)(c + 0xf4) |= 1;
            *(s32*)(c + 0x24) = 1;
            *(u8**)(param_1 + 0x2b8) = NULL;
        }
        *(u8*)(param_1 + 0x11c) = 0;
    }
}

extern "C" void fn_8035FB64(u8* param_1) {
    if (*(s32*)(param_1 + 0x234) == 0) {
        if (lbl_804742A8[*(s32*)(param_1 + 0x240) * 2] < 0) {
            *(s32*)(param_1 + 0x240) = 0;
        }
        *(s32*)(param_1 + 0x234) = lbl_804742A8[*(s32*)(param_1 + 0x240) * 2 + 1];
        *(s32*)(param_1 + 0x23c) = lbl_804742A8[*(s32*)(param_1 + 0x240) * 2];
        *(s32*)(param_1 + 0x240) = *(s32*)(param_1 + 0x240) + 1;
    }
    if (*(f32*)(param_1 + 0x26c) < 16.0f) {
        *(f32*)(param_1 + 0x26c) += 0.2f;
    }
    s32 step = (s32)(65536.0f * (__fres(6.28318f * *(f32*)(param_1 + 0x26c)) * 1.75f));
    *(s16*)(param_1 + 0x254) = *(s16*)(param_1 + 0x254) - step;
    *(f32*)(param_1 + 0x3c) = 1.75f * sincosTable___5JMath[(*(s16*)(param_1 + 0x254) >> 5) & 0x7ff].cos;
    *(f32*)(param_1 + 0x40) = 1.75f * sincosTable___5JMath[(*(s16*)(param_1 + 0x254) >> 5) & 0x7ff].sin;
    *(f32*)(param_1 + 0x44) = 0.2f;
    *(JGeometry::TVec3<f32>*)(param_1 + 0xc) += *(JGeometry::TVec3<f32>*)(param_1 + 0x3c);
    *(s32*)(param_1 + 0x264) = *(s32*)(param_1 + 0x264) + (s16)step;
    if (*(f32*)(param_1 + 0x26c) >= 16.0f) {
        fn_80360914(param_1);
    }
    *(f32*)(param_1 + 0x44) = 0.0f;
}

extern "C" void fn_8035FCD8(u8* param_1) {
  u8 done;
  s32 tbl = *(s32*)(param_1 + 0x244);
  if (*(s32*)(param_1 + 0x234) == 0) {
    s32 idx = *(s32*)(param_1 + 0x240);
    struct Entry {
      s32 m_0;
      u32 m_4;
    };
    Entry* base = (Entry*)lbl_804ADA98[tbl];
    if (base[idx].m_0 < 0) {
      done = 1;
      goto end;
    }
    *(u32*)(param_1 + 0x234) = base[idx].m_4;
    *(u32*)(param_1 + 0x23c) = base[*(s32*)(param_1 + 0x240)].m_0;
    *(s32*)(param_1 + 0x240) = *(s32*)(param_1 + 0x240) + 1;
  }
  done = 0;
end:
  if (done == 1) {
    fn_80360914(param_1);
  }
}

extern "C" s32 lbl_80474020[];
extern "C" f32 lbl_80542A14;
extern "C" f32 lbl_80542A00;
extern "C" f32 lbl_80542A04;
extern "C" f32 lbl_80542A08;
extern "C" f32 lbl_80542A0C;
extern "C" f32 lbl_80542A10;
extern "C" void fn_8035FD6C(u8* param_1) {
  u8 done;
  struct Entry {
    s32 m_0;
    u32 m_4;
  };
  s32 tbl = *(s32*)(param_1 + 0x244);
  if (*(s32*)(param_1 + 0x234) == 0) {
    s32 idx = *(s32*)(param_1 + 0x240);
    Entry* base = (Entry*)lbl_804ADA98[tbl];
    if (base[idx].m_0 < 0) {
      done = 1;
      goto end;
    }
    *(u32*)(param_1 + 0x234) = base[idx].m_4;
    *(u32*)(param_1 + 0x23c) = base[*(s32*)(param_1 + 0x240)].m_0;
    *(s32*)(param_1 + 0x240) = *(s32*)(param_1 + 0x240) + 1;
  }
  done = 0;
end:
  if (done == 1) {
    *(s32*)(param_1 + 0x278) = 0;
    *(s32*)(param_1 + 0x27c) = 0;
    f32 ang = JMath::atanTable_.atan2_(*(f32*)(param_1 + 0x28c) - *(f32*)(param_1 + 0x10),
                                       *(f32*)(param_1 + 0x288) - *(f32*)(param_1 + 0xc));
    *(s16*)(param_1 + 0x254) = (s16)(ang * lbl_80542A14);
    *(f32*)(param_1 + 0x3c) = *(f32*)(param_1 + 0x268) * sincosTable___5JMath[(*(s16*)(param_1 + 0x254) >> 5) & 0x7ff].cos;
    *(f32*)(param_1 + 0x40) = *(f32*)(param_1 + 0x268) * sincosTable___5JMath[(*(s16*)(param_1 + 0x254) >> 5) & 0x7ff].sin;
    if ((u16)*(s16*)(param_1 + 0x254) >= 0x2000 && (u16)*(s16*)(param_1 + 0x254) < 0x6000) {
      *(s32*)(param_1 + 0x274) = 3;
    } else if ((u16)*(s16*)(param_1 + 0x254) >= 0x6000 && (u16)*(s16*)(param_1 + 0x254) < 0xa000) {
      *(s32*)(param_1 + 0x274) = 1;
    } else if ((u16)*(s16*)(param_1 + 0x254) >= 0xa000 && (u16)*(s16*)(param_1 + 0x254) < 0xe000) {
      *(s32*)(param_1 + 0x274) = 2;
    } else {
      *(s32*)(param_1 + 0x274) = 0;
    }
    *(s32*)(param_1 + 0x244) = lbl_80474020[*(s32*)(param_1 + 0x274)];
    tbl = *(s32*)(param_1 + 0x244);
    *(s32*)(param_1 + 0x234) = 0;
    *(s32*)(param_1 + 0x240) = 0;
  }
  if (*(s32*)(param_1 + 0x234) == 0) {
    s32 idx = *(s32*)(param_1 + 0x240);
    Entry* base = (Entry*)lbl_804ADA98[tbl];
    if (base[idx].m_0 >= 0) {
      *(u32*)(param_1 + 0x234) = base[idx].m_4;
      *(u32*)(param_1 + 0x23c) = base[*(s32*)(param_1 + 0x240)].m_0;
      *(s32*)(param_1 + 0x240) = *(s32*)(param_1 + 0x240) + 1;
    }
  }
}

extern "C" s32 lbl_804742A8[];
extern "C" void fn_8021A570(u8* r, s32 active);
extern "C" void fn_8035FF70(u8* param_1) {
    if (*(u8*)(param_1 + 0x2b0) == 1) {
        if (*(s32*)(param_1 + 0x270) == 0) {
            fn_8021A570(param_1 + 0x2a0, 1);
        } else if (*(s32*)(param_1 + 0x234) == 0) {
            if (lbl_804742A8[*(s32*)(param_1 + 0x240) * 2] < 0) {
                *(s32*)(param_1 + 0x240) = 0;
            }
            *(s32*)(param_1 + 0x234) = lbl_804742A8[*(s32*)(param_1 + 0x240) * 2 + 1];
            *(s32*)(param_1 + 0x23c) = lbl_804742A8[*(s32*)(param_1 + 0x240) * 2];
            *(s32*)(param_1 + 0x240) = *(s32*)(param_1 + 0x240) + 1;
        }
    }
    if (*(s32*)(param_1 + 0x280) == 0) {
        fn_80360914(param_1);
    }
}

extern "C" s32 fn_801CD664(s32 n);
extern "C" f32 lbl_80542A20;
extern "C" f32 lbl_80542A24;
extern "C" f32 lbl_80542A38;
extern "C" f32 lbl_80542A3C;
extern "C" void fn_8036003C(u8* p) {
    struct Entry {
        s32 m_0;
        u32 m_4;
    };
    s32 oldState = *(s32*)(p + 0x274);
    *(s32*)(p + 0x248) = *(s32*)(p + 0x244);
    if (*(s32*)(p + 0x270) == 0) {
        s32 tbl = *(s32*)(p + 0x244);
        u8 done;
        if (*(s32*)(p + 0x234) == 0) {
            s32 idx = *(s32*)(p + 0x240);
            Entry* base = (Entry*)lbl_804ADA98[tbl];
            if (base[idx].m_0 < 0) {
                done = 1;
            } else {
                *(u32*)(p + 0x234) = base[idx].m_4;
                *(s32*)(p + 0x23c) = base[*(s32*)(p + 0x240)].m_0;
                *(s32*)(p + 0x240) = *(s32*)(p + 0x240) + 1;
                done = 0;
            }
        } else {
            done = 0;
        }
        if (done == 1 && *(u8*)(p + 0x2b0) == 1) {
            *(s32*)(p + 0x244) = lbl_80474020[*(s32*)(p + 0x274)];
            if (fn_801CD664(100) < 5 || (*(s32*)(p + 0x250) == 0 && *(s32*)(p + 0x27c) != 0 && *(s32*)(p + 0x27c) != 1 && *(f32*)(p + 0x26c) < lbl_80542A38)) {
                *(s32*)(p + 0x244) = *(s32*)(p + 0x244) + 1;
            }
            tbl = *(s32*)(p + 0x244);
            *(s32*)(p + 0x234) = 0;
            *(s32*)(p + 0x240) = 0;
            if (*(s32*)(p + 0x234) == 0) {
                s32 idx = *(s32*)(p + 0x240);
                Entry* base = (Entry*)lbl_804ADA98[tbl];
                if (base[idx].m_0 >= 0) {
                    *(u32*)(p + 0x234) = base[idx].m_4;
                    *(s32*)(p + 0x23c) = base[*(s32*)(p + 0x240)].m_0;
                    *(s32*)(p + 0x240) = *(s32*)(p + 0x240) + 1;
                }
            }
            if ((*(u32*)(p + 0x248) & 1) == 0 && (*(u32*)(p + 0x244) & 1) != 0) {
                *(s32*)(p + 0x240) = 4;
                *(s32*)(p + 0x234) = 0;
                if (*(s32*)(p + 0x234) == 0) {
                    s32 idx = *(s32*)(p + 0x240);
                    Entry* base = (Entry*)lbl_804ADA98[tbl];
                    if (base[idx].m_0 >= 0) {
                        *(u32*)(p + 0x234) = base[idx].m_4;
                        *(s32*)(p + 0x23c) = base[*(s32*)(p + 0x240)].m_0;
                        *(s32*)(p + 0x240) = *(s32*)(p + 0x240) + 1;
                    }
                }
                *(s32*)(p + 0x240) = 0;
                *(s32*)(p + 0x234) = 6;
            }
        }
    } else {
        if (*(s32*)(p + 0x250) == 9 && *(f32*)(p + 0x10) >= lbl_80542A3C) {
            *(s8*)(p + 0x24c) = -1;
            *(u8*)(p + 0x24d) = 0;
        } else {
            *(u8*)(p + 0x24c) = 1;
            *(u8*)(p + 0x24d) = 1;
        }
        if (*(s32*)(p + 0x234) == 0) {
            if (lbl_804742A8[*(s32*)(p + 0x240) * 2] < 0) {
                *(s32*)(p + 0x240) = 0;
            }
            *(s32*)(p + 0x234) = lbl_804742A8[*(s32*)(p + 0x240) * 2 + 1];
            *(s32*)(p + 0x23c) = lbl_804742A8[*(s32*)(p + 0x240) * 2];
            *(s32*)(p + 0x240) = *(s32*)(p + 0x240) + 1;
        }
    }
    if (*(s32*)(p + 0x27c) == 0) {
        *(JGeometry::TVec3<f32>*)(p + 0xc) += *(JGeometry::TVec3<f32>*)(p + 0x3c);
        if (__fabsf(*(f32*)(p + 0x288) - *(f32*)(p + 0xc)) < *(f32*)(p + 0x268) &&
            __fabsf(*(f32*)(p + 0x28c) - *(f32*)(p + 0x10)) < *(f32*)(p + 0x268)) {
            *(JGeometry::TVec3<f32>*)(p + 0xc) = *(JGeometry::TVec3<f32>*)(p + 0x288);
            fn_80360914(p);
            goto end;
        }
    } else if (*(s32*)(p + 0x27c) == 1) {
        *(JGeometry::TVec3<f32>*)(p + 0xc) += *(JGeometry::TVec3<f32>*)(p + 0x3c);
        f32 m = PSVECMag((Vec*)(p + 0x3c));
        *(f32*)(p + 0x25c) += m;
        if (*(f32*)(p + 0x25c) >= *(f32*)(p + 0x258)) {
            *(f32*)(p + 0x25c) = lbl_80542A00;
            fn_80360914(p);
            goto end;
        }
    } else if (*(s32*)(p + 0x27c) == 2 || *(s32*)(p + 0x27c) == 4) {
        JGeometry::TVec3<f32> saved = *(JGeometry::TVec3<f32>*)(p + 0xc);
        f32 inv = __fres(lbl_80542A20 * *(f32*)(p + 0x26c));
        s32 step = (s32)(lbl_80542A24 * (inv * *(f32*)(p + 0x268)));
        if (*(s32*)(p + 0x27c) == 2) {
            *(s16*)(p + 0x254) = *(s16*)(p + 0x254) + step;
        } else {
            *(s16*)(p + 0x254) = *(s16*)(p + 0x254) - step;
        }
        *(f32*)(p + 0x3c) = *(f32*)(p + 0x268) * sincosTable___5JMath[(*(s16*)(p + 0x254) >> 5) & 0x7ff].cos;
        *(f32*)(p + 0x40) = *(f32*)(p + 0x268) * sincosTable___5JMath[(*(s16*)(p + 0x254) >> 5) & 0x7ff].sin;
        *(JGeometry::TVec3<f32>*)(p + 0xc) += *(JGeometry::TVec3<f32>*)(p + 0x3c);
        *(s32*)(p + 0x264) += (s16)step;
        if (*(s32*)(p + 0x264) >= *(s32*)(p + 0x260)) {
            s16 d;
            if (*(s32*)(p + 0x27c) == 2) {
                d = (s16)(*(s32*)(p + 0x260) - *(s32*)(p + 0x264));
            } else {
                d = (s16)(*(s32*)(p + 0x264) - *(s32*)(p + 0x260));
            }
            if (d != 0) {
                *(JGeometry::TVec3<f32>*)(p + 0xc) = saved;
                *(s16*)(p + 0x254) = *(s16*)(p + 0x254) + d;
                *(f32*)(p + 0x3c) = *(f32*)(p + 0x268) * sincosTable___5JMath[(*(s16*)(p + 0x254) >> 5) & 0x7ff].cos;
                *(f32*)(p + 0x40) = *(f32*)(p + 0x268) * sincosTable___5JMath[(*(s16*)(p + 0x254) >> 5) & 0x7ff].sin;
                *(JGeometry::TVec3<f32>*)(p + 0xc) += *(JGeometry::TVec3<f32>*)(p + 0x3c);
            }
            fn_80360914(p);
            goto end;
        }
    } else {
        f32 inv = __fres(lbl_80542A20 * *(f32*)(p + 0x26c));
        s32 step = (s32)(lbl_80542A24 * (inv * *(f32*)(p + 0x268)));
        if (*(s32*)(p + 0x27c) == 3) {
            *(s16*)(p + 0x254) = *(s16*)(p + 0x254) + step;
        } else {
            *(s16*)(p + 0x254) = *(s16*)(p + 0x254) - step;
        }
        *(f32*)(p + 0x3c) = *(f32*)(p + 0x268) * sincosTable___5JMath[(*(s16*)(p + 0x254) >> 5) & 0x7ff].cos;
        *(f32*)(p + 0x40) = *(f32*)(p + 0x268) * sincosTable___5JMath[(*(s16*)(p + 0x254) >> 5) & 0x7ff].sin;
        *(JGeometry::TVec3<f32>*)(p + 0xc) += *(JGeometry::TVec3<f32>*)(p + 0x3c);
        *(s32*)(p + 0x264) += (s16)step;
        if (*(s32*)(p + 0x264) >= *(s32*)(p + 0x260)) {
            fn_80360914(p);
            goto end;
        }
    }
    {
        f32 ang = JMath::atanTable_.atan2_(*(f32*)(p + 0x40), *(f32*)(p + 0x3c));
        u16 q = (u16)(s32)(ang * lbl_80542A14);
        s32 ns;
        if (q >= 0x2000 && q < 0x6000) {
            ns = 3;
        } else if (q >= 0x6000 && q < 0xa000) {
            ns = 1;
        } else if (q >= 0xa000 && q < 0xe000) {
            ns = 2;
        } else {
            ns = 0;
        }
        *(s32*)(p + 0x274) = ns;
        if (*(s32*)(p + 0x270) == 0 && *(u8*)(p + 0x2b0) == 1 && *(s32*)(p + 0x274) != oldState) {
            s32 tbl = lbl_80474020[*(s32*)(p + 0x274)];
            *(s32*)(p + 0x244) = tbl;
            if ((*(u32*)(p + 0x248) & 1) != 1 && fn_801CD664(100) >= 5 && *(s32*)(p + 0x250) == 0 && *(s32*)(p + 0x27c) != 0 && *(s32*)(p + 0x27c) != 1 && *(f32*)(p + 0x26c) < lbl_80542A38) {
                *(s32*)(p + 0x244) = *(s32*)(p + 0x244) + 1;
            }
            tbl = *(s32*)(p + 0x244);
            if ((*(u32*)(p + 0x248) & 1) == 0) {
                *(s32*)(p + 0x234) = 0;
                *(s32*)(p + 0x240) = 0;
                if (*(s32*)(p + 0x234) == 0) {
                    s32 idx = *(s32*)(p + 0x240);
                    Entry* base = (Entry*)lbl_804ADA98[tbl];
                    if (base[idx].m_0 >= 0) {
                        *(u32*)(p + 0x234) = base[idx].m_4;
                        *(s32*)(p + 0x23c) = base[*(s32*)(p + 0x240)].m_0;
                        *(s32*)(p + 0x240) = *(s32*)(p + 0x240) + 1;
                    }
                }
                if ((*(u32*)(p + 0x244) & 1) != 0) {
                    *(s32*)(p + 0x240) = 4;
                    *(s32*)(p + 0x234) = 0;
                    if (*(s32*)(p + 0x234) == 0) {
                        s32 idx = *(s32*)(p + 0x240);
                        Entry* base = (Entry*)lbl_804ADA98[tbl];
                        if (base[idx].m_0 >= 0) {
                            *(u32*)(p + 0x234) = base[idx].m_4;
                            *(s32*)(p + 0x23c) = base[*(s32*)(p + 0x240)].m_0;
                            *(s32*)(p + 0x240) = *(s32*)(p + 0x240) + 1;
                        }
                    }
                    *(s32*)(p + 0x240) = 0;
                    *(s32*)(p + 0x234) = 6;
                }
            } else {
                Entry* base = (Entry*)lbl_804ADA98[tbl];
                if (*(s32*)(p + 0x240) == 0) {
                    *(s32*)(p + 0x23c) = base[4].m_0;
                } else {
                    *(s32*)(p + 0x23c) = base[*(s32*)(p + 0x240) - 1].m_0;
                }
            }
        }
    }
end:
    ;
}

extern "C" void fn_803613D0(u8* param_1) {
  u8* e = *(u8**)(param_1 + 0x2b4);
  if (e != 0) {
    *(u32*)(e + 0xf4) |= 1;
    *(s32*)(e + 0x24) = 1;
    *(u8**)(param_1 + 0x2b4) = 0;
  }
  e = *(u8**)(param_1 + 0x2b8);
  if (e != 0) {
    *(u32*)(e + 0xf4) |= 1;
    *(s32*)(e + 0x24) = 1;
    *(u8**)(param_1 + 0x2b8) = 0;
  }
}

extern "C" char lbl_804742F4[];
extern "C" const u16 lbl_805429F8[4];
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_801EF830(s32 room, void* pos, DrawRec* rec, s32 mask, const char* name, s32 id, s32 e);
extern "C" void fn_80361424(u8* param_1) {
    DrawRec rec;
    f32 mtx[3][4];
    u8 sel = 0;
    s32 iVar2 = *(s32*)(param_1 + 0x250);

    if (iVar2 == 1) {
        f32 y = *(f32*)(param_1 + 0x10);
        if (y >= 580.0f && y < 740.0f) {
            rec.b1c = 0;
            rec.b1d = 1;
            sel = 0;
        } else if (y >= 740.0f && y < 952.0f) {
            rec.b1c = 1;
            rec.b1d = 2;
            sel = 1;
        } else {
            rec.b1c = 1;
            rec.b1d = 2;
            sel = 0;
        }
    } else if (iVar2 == 0x10) {
        rec.b1d = 2;
    } else if (iVar2 == 0) {
        rec.b1c = 1;
        rec.b1d = 2;
    }

    rec.b1f = 0;
    {
        u32 d = (u16)*(s16*)(param_1 + 0x254) - lbl_805429F8[*(s32*)(param_1 + 0x274)];
        u32 idx = (d >> 5) & 0x7ff;
        f32 cos;
        f32 sin = sincosTable___5JMath[idx].sin;
        cos = sincosTable___5JMath[idx].cos;
        f32 negative;
        f32 zero = 0.0f;
        f32 one = 1.0f;
        mtx[2][1] = zero;
        mtx[1][1] = one;
        mtx[0][2] = sin;
        mtx[0][0] = cos;
        mtx[2][0] = negative = -sin;
        mtx[2][2] = cos;
        mtx[1][2] = zero;
        mtx[1][0] = zero;
        mtx[0][1] = zero;
        mtx[0][3] = zero;
        mtx[1][3] = zero;
        mtx[2][3] = zero;
    }
    rec.w18 = mtx;

    if (sel == 0) {
        fn_801F06F0(param_1, lbl_804742F4, *(s32*)(param_1 + 0x23c) + 0x3e0, &rec, 7, 1.0f, 1.0f);
    } else {
        fn_801F06F0(param_1, lbl_804742F4, *(s32*)(param_1 + 0x23c) + 0x3e0, &rec, -1, 1.0f, 1.0f);
        rec.b1c = 0;
        rec.b1d = 0xff;
        s32 id = *(s32*)(param_1 + 0x23c) + 0x3e0;
        if (*(u32*)(param_1 + 0x138) == 0) {
            fn_801EF830(*(s32*)(param_1 + 4), param_1 + 0xc, &rec, 0x407, lbl_804742F4, id, 0);
        }
    }
}

static inline void resetDrawRec(DrawRec& rec) {
    for (u32 i = 0; (u8)i < 0x10; i += 8) {
        rec.ids[(u8)i] = i;
        rec.ids[(u8)(i + 1)] = i + 1;
        rec.ids[(u8)(i + 2)] = i + 2;
        rec.ids[(u8)(i + 3)] = i + 3;
        rec.ids[(u8)(i + 4)] = i + 4;
        rec.ids[(u8)(i + 5)] = i + 5;
        rec.ids[(u8)(i + 6)] = i + 6;
        rec.ids[(u8)(i + 7)] = i + 7;
    }
    rec.w10 = -1; rec.w14 = 0; rec.w18 = 0;
    rec.b1c = 0; rec.b1d = 0; rec.b1e = 0; rec.b1f = 1;
    rec.b20 = 1; rec.b21 = 0; rec.b22 = 0; rec.b23 = 0;
    rec.b24 = 0; rec.b25 = 0; rec.b26 = 1; rec.w28 = 3;
    rec.b2c = 1; rec.b2d = 0; rec.b2e = 0;
    rec.w30 = -1; rec.w34 = 0; rec.w38 = 2;
}

extern "C" void fn_803616FC(u8* param_1) {
    DrawRec rec;
    f32 mtx[3][4];
    JGeometry::TVec3<f32> pos;
    rec.b1f = 0;
    pos = *(JGeometry::TVec3<f32>*)(param_1 + 0xc);
    fn_801F06F0(param_1, lbl_804742F4, 0x279, &rec, -1, 1.0f, 1.0f);
    ((u8*)&rec)[0x13] = 0xc8;
    if (*(u32*)(param_1 + 0x138) == 0)
        fn_801EF830(*(s32*)(param_1 + 4), param_1 + 0xc, &rec, 0x407, lbl_804742F4, 0x279, 0);
    resetDrawRec(rec);
    rec.b1f = 0;
    rec.b1d = 1;
    mtx[0][3] = 0.0f;
    mtx[1][3] = 0.0f;
    mtx[2][3] = 0.0f;
    f32 cos;
    f32 sin = sincosTable___5JMath[(*(s16*)(param_1 + 0x2a4) >> 5) & 0x7ff].sin;
    cos = sincosTable___5JMath[(*(s16*)(param_1 + 0x2a4) >> 5) & 0x7ff].cos;
    mtx[1][1] = 1.0f;
    mtx[0][2] = sin;
    mtx[0][0] = cos;
    mtx[2][0] = -sin;
    mtx[2][2] = cos;
    mtx[2][1] = 0.0f;
    mtx[1][2] = 0.0f;
    mtx[1][0] = 0.0f;
    mtx[0][1] = 0.0f;
    rec.w18 = mtx;
    *(f32*)(param_1 + 0x10) += -21.0f;
    fn_801F06F0(param_1, lbl_804742F4, 0x27a, &rec, -1, 1.0f, 1.0f);
    *(f32*)(param_1 + 0x10) -= -21.0f;
    ((u8*)&rec)[0x13] = 0xc8;
    *(f32*)(param_1 + 0x10) += -10.5f;
    if (*(u32*)(param_1 + 0x138) == 0)
        fn_801EF830(*(s32*)(param_1 + 4), param_1 + 0xc, &rec, 0x407, lbl_804742F4, 0x27a, 0);
    *(f32*)(param_1 + 0x10) -= -10.5f;
    *(JGeometry::TVec3<f32>*)(param_1 + 0xc) = pos;
}

extern "C" char lbl_80474308[];
extern "C" void fn_803616FC(u8* param_1);
extern const f32 lbl_80542A40;
#pragma opt_lifetimes off
extern "C" void fn_80361A78(u8* param_1) {
    if (*(u8*)(param_1 + 0x2b0) != 0) {
        if (*(s32*)(param_1 + 0x270) == 0) {
            if (*(s32*)(param_1 + 0x278) == 1) {
                fn_803616FC(param_1);
            } else if (*(s32*)(param_1 + 0x278) == 0) {
                fn_80361424(param_1);
            } else {
                DrawRec rec;
                rec.b1f = 0;
                fn_801F06F0(param_1, lbl_804742F4, *(s32*)(param_1 + 0x23c) + 0x25c, &rec, -1, 1.0f, 1.0f);
                *(u8*)((u8*)&rec + 0x13) = 200;
                s32 id = *(s32*)(param_1 + 0x23c) + 0x25c;
                if (*(u32*)(param_1 + 0x138) == 0) {
                    fn_801EF830(*(s32*)(param_1 + 4), param_1 + 0xc, &rec, 0x407, lbl_804742F4, id, 0);
                }
            }
        } else {
            DrawRec rec;
            rec.b1f = 0;
            rec.b1c = *(u8*)(param_1 + 0x24c);
            rec.b1d = *(u8*)(param_1 + 0x24d);
            fn_801F06F0(param_1, lbl_80474308, *(s32*)(param_1 + 0x238) + *(s32*)(param_1 + 0x23c), &rec, -1, 1.0f, 1.0f);
            if (*(s8*)(param_1 + 0x24c) < 0) {
                rec.b1c = 0;
            }
            s32 id = *(s32*)(param_1 + 0x238) + *(s32*)(param_1 + 0x23c);
            if (*(u32*)(param_1 + 0x138) == 0) {
                fn_801EF830(*(s32*)(param_1 + 4), param_1 + 0xc, &rec, 0x407, lbl_80474308, id, 0);
            }
        }
    }
}
#pragma opt_lifetimes reset
extern "C" void fn_80361DAC(u8* param_1) {
    if (*(s32*)(param_1 + 0x280) != 0) {
        *(s32*)(param_1 + 0x280) = *(s32*)(param_1 + 0x280) - 1;
    }
    if (*(s32*)(param_1 + 0x234) != 0) {
        *(s32*)(param_1 + 0x234) = *(s32*)(param_1 + 0x234) - 1;
    }
    do {
    } while (fn_8035F3C0(param_1) != 0);
    (((FsaState*)param_1)->*lbl_804ADA50[*(s32*)(param_1 + 0x278)].fn)();
    if (*(u8*)(param_1 + 0x2b0) == 0) {
        if (*(u8**)(param_1 + 0x2b4) != 0) {
            fn_8013CB44(*(u8**)(param_1 + 0x2b4), param_1 + 0xc, -2, -2, 1);
        }
        if (*(u8**)(param_1 + 0x2b8) != 0) {
            fn_8013CB44(*(u8**)(param_1 + 0x2b8), param_1 + 0xc, -2, -2, 1);
        }
    } else {
        if (*(u8**)(param_1 + 0x2b4) != 0) {
            fn_8013CB44(*(u8**)(param_1 + 0x2b4), param_1 + 0xc, *(s8*)(param_1 + 0x24c), *(s8*)(param_1 + 0x24d), 1);
        }
        if (*(u8**)(param_1 + 0x2b8) != 0) {
            fn_8013CB44(*(u8**)(param_1 + 0x2b8), param_1 + 0xc, *(s8*)(param_1 + 0x24c), *(s8*)(param_1 + 0x24d), 1);
        }
    }
}

extern "C" void fn_80361ECC(u8* param_1) {
    s32 i;
    *(f32*)(param_1 + 0x44) = 0.0f;
    *(f32*)(param_1 + 0x40) = 0.0f;
    *(f32*)(param_1 + 0x3c) = 0.0f;
    *(s32*)(param_1 + 0x230) = 0;
    *(s32*)(param_1 + 0x234) = 0;
    *(s32*)(param_1 + 0x238) = 0;
    *(s32*)(param_1 + 0x23c) = 0;
    *(s32*)(param_1 + 0x240) = 0;
    *(s32*)(param_1 + 0x248) = 0;
    *(s32*)(param_1 + 0x244) = 0;
    *(s16*)(param_1 + 0x254) = 0;
    *(f32*)(param_1 + 0x25c) = 0.0f;
    *(f32*)(param_1 + 0x258) = 0.0f;
    *(s32*)(param_1 + 0x264) = 0;
    *(s32*)(param_1 + 0x260) = 0;
    *(f32*)(param_1 + 0x268) = 0.0f;
    *(f32*)(param_1 + 0x26c) = 0.0f;
    *(s32*)(param_1 + 0x270) = *(u32*)(param_1 + 0x90) & 7;
    *(s32*)(param_1 + 0x274) = 0;
    *(s32*)(param_1 + 0x250) = (*(u32*)(param_1 + 0x90) >> 3) & 0x1f;
    *(u8*)(param_1 + 0x2b0) = 1;
    *(s32*)(param_1 + 0x280) = 0;
    *(f32*)(param_1 + 0x290) = 0.0f;
    *(f32*)(param_1 + 0x28c) = 0.0f;
    *(f32*)(param_1 + 0x288) = 0.0f;
    *(u8*)(param_1 + 0x294) = 0;
    *(void**)(param_1 + 0x2b4) = NULL;
    *(void**)(param_1 + 0x2b8) = NULL;
    *(void**)(param_1 + 0x29c) = NULL;

    if ((*(u32*)(param_1 + 0x90) & 0x100) == 0) {
        if (ro_1a48[*(s32*)(param_1 + 0x250)] == 1) {
            *(u8*)(param_1 + 0x2b0) = 0;
            Actor_CreateByID(fn_801F856C(), 0x454f574c, *(s32*)(param_1 + 4), param_1 + 0xc, *(u32*)(param_1 + 0x90) | 0x100, -1, -1);
            *(u32*)(param_1 + 0x298) = data_b0[*(s32*)(param_1 + 0x250)];
            *(u32*)(param_1 + 0x284) = data_58[*(s32*)(param_1 + 0x250)];
        } else {
            *(u32*)(param_1 + 0x298) = data_b0[*(s32*)(param_1 + 0x250)];
            *(u32*)(param_1 + 0x284) = data_58[*(s32*)(param_1 + 0x250)];
        }
    } else {
        *(const void**)(param_1 + 0x298) = ro_1790;
        *(u32*)(param_1 + 0x284) = data_0[*(s32*)(param_1 + 0x250)];
    }

    *(s8*)(param_1 + 0x24c) = 1;
    *(s8*)(param_1 + 0x24d) = 1;
    if (*(s32*)(param_1 + 0x270) == 0) {
        fn_80360914(param_1);
    } else {
        *(u32*)(param_1 + 0x238) = ro_17c0[*(s32*)(param_1 + 0x270) - 1];
        fn_80360914(param_1);
        if ((*(u32*)(param_1 + 0x90) & 0x100) != 0) {
            *(u8**)(param_1 + 0x2b4) = fn_8013CC50(*(s32*)(param_1 + 4), param_1 + 0xc, 1.0f, 0x32c, *(s8*)(param_1 + 0x24c), *(s8*)(param_1 + 0x24d), 0, 0, 1);
            *(u8**)(param_1 + 0x2b8) = fn_8013CC50(*(s32*)(param_1 + 4), param_1 + 0xc, 1.0f, 0x171, *(s8*)(param_1 + 0x24c), *(s8*)(param_1 + 0x24d), 0, 0, 1);
            u8* b4 = *(u8**)(param_1 + 0x2b4);
            if (b4 != NULL) {
                s32 idx = *(s32*)(param_1 + 0x270);
                b4[0xbc] = ro_1a98[idx - 1].r;
                b4[0xbd] = ro_1a98[idx - 1].g;
                b4[0xbe] = ro_1a98[idx - 1].b;
            }
        }
    }

    if ((*(u32*)(param_1 + 0x90) & 0x100) == 0) {
        if (*(s32*)(param_1 + 0x250) == 0x12) {
            Actor_CreateByID(fn_801F856C(), 0x454c4b32, *(s32*)(param_1 + 4), param_1 + 0xc, 0, -1, -1);
            static JGeometry::TVec3<f32> tbl[4] = {
                JGeometry::TVec3<f32>(-18.0f, -126.0f, 0.0f),
                JGeometry::TVec3<f32>(18.0f, -126.0f, 0.0f),
                JGeometry::TVec3<f32>(-26.0f, -156.0f, 0.0f),
                JGeometry::TVec3<f32>(26.0f, -156.0f, 0.0f),
            };
            for (i = 0; i < 4; i++) {
                Actor_CreateByID(fn_801F856C(), 0x45455443, *(s32*)(param_1 + 4), &(*(JGeometry::TVec3<f32>*)(param_1 + 0xc) + tbl[i]), ((i + 0x26) << 5) | 4 | 0x80000000, -1, -1);
            }
        } else if (*(s32*)(param_1 + 0x250) == 0x13) {
            Actor_CreateByID(fn_801F856C(), 0x45455443, *(s32*)(param_1 + 4), param_1 + 0xc, 0x10, -1, -1);
            *(s32*)(param_1 + 0x230) = 1;
            fn_80230498(0, JGeometry::TVec3<f32>(0.0f, 0.0f, 0.0f), *(s32*)(param_1 + 0x238) + *(s32*)(param_1 + 0x23c), 0xff, -0x80, -0x80, 1);
        }
        s32 count = getActorList()->getCount();
        for (i = 0; i < count; i++) {
            u8* act = getActorList()->getActor(i);
            if (act != NULL && *(u32*)(act + 0x1a0) == 0x454e444d && *(u8*)(act + 0x11c) == 1) {
                *(u8**)(param_1 + 0x29c) = act;
                break;
            }
        }
    }
}

extern "C" void fn_80362374(void) {
    u8* records = lbl_8050BEF8;
    FsaStateEntry* source = (FsaStateEntry*)(lbl_804AD900 + 0x108);
    lbl_804ADA50[0] = source[0];
    for (int i = 1; i < 6; i++) lbl_804ADA50[i] = source[i];
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, records + 0x30);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, records + 0x3c);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, records + 0x48);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, records + 0x54);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, records + 0x60);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, records + 0x6c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, records + 0x78);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, records + 0x84);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, records + 0x90);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

