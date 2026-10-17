#include "Game/Actor.h"


extern "C" char lbl_804A8170[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern int* lbl_8053AAF8;
extern int* lbl_8053AB10;
extern char lbl_8046C878[];
u8* fn_801F856C(void);
void fn_802FA160(int, int, int, int, int, int);
int fn_802D6A9C(void);
void fn_802D7920(int, int);

extern "C" Actor* fn_802AABFC(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804A8170;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_802AAC5C(void)
{
    return;
}

extern int* lbl_8053AAF8;
extern int* lbl_8053AB10;
extern char lbl_8046C878[];
u8* fn_801F856C(void);
void fn_802FA160(int, int, int, int, int, int);
int fn_802D6A9C(void);
void fn_802D7920(int, int);
extern "C" void fn_802AAEC0(int* param_1)
{
  param_1[0x8d] = param_1[0x24] & 0xff;
  if ((param_1[0x8d] == 0 && ((u8 (*)(int*))(*(void***)param_1)[13])(param_1)) ||
      (param_1[0x8d] != 0 && ((u8*)fn_801F856C())[0x305c] == 1)) {
    void* obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
    int ret = ((int (*)(void*, int, void*))(*(void***)obj)[6])(obj, 0x53434820, lbl_8046C878);
    fn_802FA160(*(int*)((u8*)lbl_8053AB10 + 0x20), ret, 0x180, 0, 0x40, 0xc0);
    fn_802D7920(fn_802D6A9C(), 0);
    *((u8*)param_1 + 0x11c) = 0;
  } else {
    fn_802D7920(fn_802D6A9C(), 1);
    param_1[0x8c] = 0;
    param_1[0x8e] = 0xf;
  }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
