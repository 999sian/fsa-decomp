// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800d3600-0x800d36d0 (1 functions). split_file divides it into the game's real files.

void fn_800D3600(void)
{
    extern unsigned char lbl_802C5774[];
    extern unsigned char lbl_80289490[];
    extern unsigned char lbl_802891D8[];
    extern unsigned char lbl_802C5768[];
    extern float lbl_80300F80;
    extern float lbl_80300F84;
    extern void fn_800D35B8(void);
    extern void __register_global_object(void*, void*, void*);
    unsigned int* src;
    unsigned int* dst;

    *(void**)lbl_802C5774 = lbl_80289490;
    lbl_802C5774[4] = -1;
    *(unsigned int*)(lbl_802C5774 + 8) = 0;
    lbl_802C5774[0x11] = 10;
    lbl_802C5774[0x10] = 0;
    *(float*)(lbl_802C5774 + 0xc) = lbl_80300F80;
    lbl_802C5774[0x12] = 10;
    *(float*)(lbl_802C5774 + 0x14) = lbl_80300F84;
    lbl_802C5774[0x18] = 10;
    __register_global_object(lbl_802C5774, fn_800D35B8, lbl_802C5768);

    src = (unsigned int*)(lbl_802891D8 + 0x198);
    dst = (unsigned int*)(lbl_802891D8 + 0x1bc);
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];
    dst[6] = src[6];
    dst[7] = src[7];
    dst[8] = src[8];
}
