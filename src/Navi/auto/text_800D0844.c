// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800d0844-0x800d0910 (1 functions). split_file divides it into the game's real files.

void fn_800D0844(void)
{
    extern unsigned char lbl_802C574C[];
    extern unsigned char lbl_802891CC[];
    extern unsigned char lbl_80288B18[];
    extern unsigned char lbl_802C5740[];
    extern float lbl_80300F30;
    extern float lbl_80300F34;
    extern void fn_800D07FC(void);
    extern void __register_global_object(void*, void*, void*);
    unsigned int* src;
    unsigned int* dst;

    *(void**)lbl_802C574C = lbl_802891CC;
    lbl_802C574C[4] = -1;
    *(unsigned int*)(lbl_802C574C + 8) = 0;
    lbl_802C574C[0x11] = 10;
    lbl_802C574C[0x10] = 0;
    *(float*)(lbl_802C574C + 0xc) = lbl_80300F30;
    lbl_802C574C[0x12] = 10;
    *(float*)(lbl_802C574C + 0x14) = lbl_80300F34;
    __register_global_object(lbl_802C574C, fn_800D07FC, lbl_802C5740);

    src = (unsigned int*)(lbl_80288B18 + 0x58c);
    dst = (unsigned int*)(lbl_80288B18 + 0x5b0);
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
