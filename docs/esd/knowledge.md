# ESD (EverydaySimpleDev/FSA-Decomp @09725c3) knowledge harvest

Knowledge only, no code. Confidence: high = independently confirmed, med = ESD evidence convincing, low = ESD guess.

## 1. Actor 4CC IDs: our actors.csv has wrong IDs (NEW, important)

ESD names 344 of its `src/Game/<ID>_{ctor,dtor}_<addr>.cpp` files after actors. 312 agree with our `docs/gamemap/actors.csv`. 32 disagree, and for every disagreement ESD's ID is the real one.

Cause (confirmed by hand in `build/G4SE01/asm/auto_fn_801F9484_text.s`, the factory binary search): our extractor pairs each `addi rX,rY,lo` with the most recent `lis` in *file order*. But at a `bge` target, rY still holds the `lis` value from the branch source. Example: `.L_801F9E64` is reached by `bge` at 801F9E08, where r3=0x474F. So `addi 0x4C44` there gives **GOLD**, not GNLD. The case that calls fn_80203F14 is this GOLD case. It works the same way for FARY (fn_802039D4, from `lis 0x4641`) and ZORA (fn_801BB3B0). **Fix: re-run the tree decode following control flow.** GAMEMAP.md:150/154 (ZNSH) and tu_boundaries.csv (GSYA, DBRK, EZRY, ...) use these wrong IDs too.

| ours (wrong) | real | ctor | conf |
|---|---|---|---|
| BERY | BFRY | 80203778 | high (pattern) |
| BPRY | BRRY | 802027B4 | high |
| DBRK | DDRK | 80203F50 | high |
| CRTH | DETH | 802031BC | high |
| ELSK | EMSK | 801FFFE8 (dtor 802EF448) | high |
| EZRY | FARY (fairy) | 802039D4 | high (verified) |
| EZGE | FBGE | 8021D4CC | high |
| EZMR | FBMR | 801BD640 | high |
| EZOB | FBOB | 801BDBF0 | high |
| GEWP | GLWP | 801FFBB4 (dtor 801B7324) | high |
| GNL2 | GOL2 | 80201898 (dtor 802E3A48) | high |
| GNLD | GOLD | 80203F14 (dtor 8032A8E0) | high (verified) |
| GNMA | GOMA | 80200D68 | high |
| FGAS | GRAS (grass) | 802041A8 | high |
| FGVE | GRVE (grave) | 80202168 | high |
| GSYA | HAYA | 802017E4 | high |
| LITS | LOTS | 80201C2C | high |
| FOEV | LTEV | 801FFEE0 (dtor 802EFB9C) | high |
| PESW | PLSW | 80202480 | high |
| RYYA | SAYA | 80201010 (dtor 801A7B98) | high |
| SPTG | SVTG | 80200674 | high |
| SSMI | TOMI | 80200584 | high |
| ZNRA | ZORA | 801BB3B0 | high (verified) |
| ZNSH | ZOSH | 80202A48 | high |

Items to check by hand:
- dtor 802E794C: ESD says MJGR, ours says PNP2. dtor 802E7634: ESD says PNP2, ours says SEN2. These may be shared or inherited dtors, or the same decode bug. Check by hand. (low)
- SLR2 ctor 80203BF0: ESD has it, and it is missing from our actors.csv. (med, NEW)
- ESD notes that the factory (fn_801F9484, in `extab_801f9484.s`) scans a slot table of 1024 entries (stride 4, tests slot->0x8==0, returns -1 when full). It then runs a binary search over about 195 4CCs and calls `fn_8008440C(this->4, smallCode, 0)` for each resource. We know the factory. The 1024-slot and resource-lookup details may be NEW. (med)

## 2. JSystem / JMessage range 0x80077124–0x80079E64 (from oscluster_80077124.c FILE MAP)

- ESD names **"BmgMesgArchive"** (ctor/dtor/open/parseChunks) from the magics MESG/bmg1/INF1/DAT1/MID1/STR1, and **"BmcMesgArchive"** from bmc1/CLT1. Both names are invented. Our GAMEMAP already maps this range to JMessage (MESG/MGCL @800773AC). Keep the real JMessage names from the TP/TWW donors (TResourceContainer/TParse). ESD's names contradict these and should not be adopted. (known; ESD names low)
- `fn_800772F4` = Shift-JIS lead-byte check (ESD calls it "IsSjisLeadByte"). This fits the JMessage/JUTResFont locale helpers. fn_800772E4/EC are fixed returns 0/1 in the same small table. (med, maybe NEW)
- fn_800779C4..800779F4: 11 tiny shared default virtuals of one base class. Vtables lbl_80498A58/AB8/B00/B10/B20. The most-derived vtable lbl_804AF6D4 sits in a second .data cluster. (med)
- JKRAram 0x800790A8–0x80079E64: 10 functions, checked against cbr_decomp. Already known and owned by JSystem core. (known)

## 3. JKernel (oscluster_800834e8 / 80081400 / 8007b694)

ESD maps JKRDisposer ctor/dtor 0x8007E6F4/0x8007E75C, JKRHeap ctor 0x8008353C, dtor 0x80083660, initArena 0x80083774, becomeSystemHeap 0x8008381C, becomeCurrentHeap 0x8008382C, JKRDefaultMemoryErrorRoutine 0x80084338, operator new 0x80084370, JKRThread ctors 0x80085474/0x8008552C/0x800855CC, dtor 0x80085674, JKRExpHeap::create 0x800814D4 and do_free 0x80081DC8. We have already matched all of these on main (JKRExpHeap and others), so there is nothing new. ESD notes that FSA's JKRHeap vtable slot order differs from AC's. ESD's JKRDecomp::run candidate is only medium confidence. (known)

## 4. Game-code helper names (ESD guesses, low unless noted; all NEW as names)

These are descriptive names ESD gave from reading function bodies. Use them as hints only.
- 0x80139CC4 CutsceneManagerUpdate; 0x8013A1A4 SceneFinalize; 0x8013B460 SubObjectForward. These sit in the camera-cue/cutscene manager area; ESD says ctor fn_8013BFEC is the camera-cue manager. (low-med)
- 0x80134DE4 DiscErrorStateSetter. It is next to main at 0x801344C0, so this fits. (med)
- 0x804019A8 / 0x80401BA4 / 0x80401E10 EffectQueueEnqueue{Small,,2} (effect/particle request queue). (med)
- 0x800F8A30 RupeeContainerUpdate; 0x8026FCE0 Player_HasAnyStatusFlagSet. (low)
- Room flag/bitfield family: 801F471C RoomIndexPredicate, 801F4760 RoomBitQuery, 801F47CC RoomEffectHook, 802E1BA4 OffsRoomFlagDispatch, 802E1DCC RoomFlagParams, 802E7B04/802E8E60/802E9170/802EEDF0 RoomBitfield*, 802EF104 RoomStateCountdown, 802EF1B4 RoomSelectorParams. (low)
- 801F6644 Registry_GetSlotValueOrFallback; 8021F064 CompanionRegistry_GetOrInit; 8021F25C GrowableArray_PushBack; 80212AC0/80212BA0 RusaRegistry GetOrInit/Unregister. (low)
- 801F681C ClassifyBamAngleToQuadrant (s16 angle to quadrant); 801CD970 EaseTowardS16. (med, simple math)
- 803B9E2C MutexNotify; 8044BCA4 LockedSlotDtorCtor. (low)
- 801F593C SharedBaseDtor. This is an Actor-family shared base dtor inside our Actor base TU range 0x801EE24C–0x801F6058. (med)
- Per-actor helpers (Saya ForceState1..4 801A46FC..801A6108, Yasi 802DF4E4/802DF508/802DFA80, Stgn_SetParams 802F4888, Swdl 802F1574, Wave 802E73B4, Grve 802DFD48/802E0128, Zld3 801B2138, Ddgo 801AE5AC, Dmyk 802F3BD8/802F3C8C). These tell which actor TU each function belongs to. (med for TU ownership)
- Vtable-to-dtor links: lbl_804AF070 → 8038D90C, lbl_804AF490 → 80391974, lbl_804AF860 → 803A7708/803A87A8, lbl_804B15D0 → 80427F60. (med)

## 5. Not harvested
ESD docs/ holds only generic build and dtk notes, not RE notes. Many file comments point to ESD's private "project memory" notes, which are not in the repo.
