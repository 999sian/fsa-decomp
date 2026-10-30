// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014eae4-0x8014ebf4 (1 functions). split_file divides it into the game's real files.

extern "C" void fn_8014D95C(void* self);
extern "C" void fn_8014E4C8(void* self);
extern "C" void fn_80148088(s32 idx);
extern "C" void fn_80157854(s32 idx);
extern "C" u32* fn_8014D928(u32 param_1);
extern u8 lbl_802FF3B0;
extern u8* lbl_802FF3E0;
extern "C" s32 fn_8014EAE4(s32 param_1)
{
    s32 ret;
    u32 cur;
    u32* p;
    u8* e;
    u32 next;
    u8 idx;
    u64 v;

    ret = -1;
    if (lbl_802FF3B0 != 0) {
        if (param_1 == -1 || (p = fn_8014D928(param_1)) == 0) {
            cur = -1;
        } else {
            cur = p[3];
        }
        while (cur != -1) {
            idx = cur & 0xff;
            e = lbl_802FF3E0 + idx * 0x404;
            next = *(u32*)(e + 0xec);
            if (cur == *(u32*)(e + 0xf4)) {
                if (*(u32*)(e + 0x34) != 0) {
                    fn_8014D95C(e);
                    v = *(u64*)(e + 0x114);
                    v &= 0xFFFFFFFFFFFFFFFCULL;
                    *(u64*)(e + 0x114) = v;
                    *(u32*)(e + 0x110) = 0;
                    fn_8014E4C8(e);
                }
                if (e[0x11c] != 0) {
                    fn_80148088(idx);
                }
                fn_80157854(idx);
                ret = 0;
            }
            cur = next;
        }
    }
    return ret;
}
