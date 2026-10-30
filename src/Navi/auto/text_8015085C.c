// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8015085c-0x80150958 (1 functions). split_file divides it into the game's real files.
typedef struct Unk8015085C { char pad[0x1c]; unsigned long key; } Unk8015085C;

void fn_8015085C(Unk8015085C** v, int left, int right)
{
    int i, last;
    Unk8015085C* tmp;

    if (left >= right)
        return;
    tmp = v[left]; v[left] = v[(left + right) / 2]; v[(left + right) / 2] = tmp;
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (v[i]->key < v[left]->key) {
            ++last;
            tmp = v[last]; v[last] = v[i]; v[i] = tmp;
        }
    }
    tmp = v[left]; v[left] = v[last]; v[last] = tmp;
    fn_8015085C(v, left, last - 1);
    fn_8015085C(v, last + 1, right);
}
