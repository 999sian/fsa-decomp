#include "types.h"


extern "C" u8* lbl_804ADA98[];
extern "C" void fn_80360914(u8* p);
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
