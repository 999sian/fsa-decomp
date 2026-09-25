# Reference material

PDFs (and their `pdftotext -layout` `.txt` extractions, for grepping) live here
but are not committed — download them from https://files.decomp.dev/ .

| File | Use it for |
|---|---|
| `GekkoUserManual.pdf` | Gekko-specific instructions: paired singles (`psq_l`/`psq_st`, `ps_*`), GQRs (§2.1.2.9), locked cache, write-gather pipe (§9.4, used by GX). Needed when reading GX/J3D/JMath code. |
| `PowerPCProgEnv.pdf` | The full 32-bit PowerPC ISA: exact semantics of every instruction, SPRs, exceptions. First stop when an instruction's behaviour is unclear. |
| `IBM_PPC_Compiler_Writer's_Guide-cwg.pdf` | How compilers express C in PPC: branch-free idioms (§3.1.5), integer idioms incl. division by constants via multiply (§3.2.3), float conversion tricks (§3.3.8, the `0x43300000` int→float pattern), branch elimination (§3.3.9), scheduling (§4.3). Use it to reverse a strange instruction sequence back to the C that produced it. |
| `E500ABIUG.pdf` | EABI conventions MWCC follows: calling sequence and parameter passing (§2.2–2.3), stack frames (§2.3.5), sections and small data areas — `r13`=`_SDA_BASE_` (.sdata/.sbss), `r2`=`_SDA2_BASE_` (.sdata2/.sbss2) (§3.3), relocation types (§3.8). |

## Quick facts for matching FSA

- FSA JSystem/game code: MWCC GC/2.6 (2.5–2.7 identical), `-O4,p`, `-use_lmw_stmw on`
  (see `tools/compiler_test/`).
- Callee-saved GPRs r14–r31 are allocated from r31 downward; with `-use_lmw_stmw on`
  prologues use `stmw rN, x(r1)`. Register order differences usually mean a
  declaration-order or expression-order difference in the source — never byte-patch.
- `lis rX, 0x4330` + `stw`/`lfd`/`fsubs` against a constant = `(f32)int` conversion (CWG §3.3.8).
- `mulhw`/`mulhwu` + shifts = division/modulo by a constant (CWG §3.2.3).
- `r13`-relative = `.sdata/.sbss` globals; `r2`-relative = `.sdata2` constants (usually float literals).

## Learning resources

- Decomp Academy — interactive MWCC matching lessons graded by the real compiler:
  https://decomp-academy.dev/ (GameCube course: `/courses/gamecube-c/...`; see the
  `-O4,p`, scheduling, spurious `frsp`/`extsb`, register-colouring and switch lessons).
- MarioKartWii.com PowerPC assembly tutorial index (Wii cheat-code oriented, good ASM basics):
  https://mariokartwii.com/showthread.php?tid=1114
- decomp.wiki GameCube/Wii resources: https://decomp.wiki/platforms/gamecube-wii
- decomp.me scratches (GC/2.6 preset) for sharing single-function attempts.
