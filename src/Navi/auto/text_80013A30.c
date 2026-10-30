// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80013a30-0x80013a80 (1 functions). split_file divides it into the game's real files.

struct node_list_class;
void cLs_Create(node_list_class*);
extern "C" void fn_801BDDBC(void*, void*, int);
extern "C" void fn_801BE368(void*);
extern char lbl_802A20E0[];
extern "C" void fn_80013A30(void) {
    fn_801BDDBC(lbl_802A20E0, lbl_802A20E0 + 0x20, 1);
    fn_801BE368(lbl_802A20E0 + 0x30);
    cLs_Create((node_list_class*)(lbl_802A20E0 + 0x24));
}
