# ESD tools: adopt or not

| ESD tool | Verdict |
|---|---|
| `tools/patch_obj.py` | **Do not adopt.** It byte-patches objects, which hard rule 3 forbids. |
| `tools/asm_transcribe.py`, `asm_transcribe_gnuas.py`, `data_transcribe_gnuas.py` | **Do not adopt** for matching. They produce transcription, not decompilation. |
| `tools/dedup_concat.py` | No need. It only exists to feed the transcription pipeline. |
| Per-address `oscluster_*` TU layout | Do not copy. Our TUs follow library/actor boundaries. |
| Harvest harness (ours, not ESD's: parse_config / compile_all / compare / summarize) | Worth recreating under `tools/` if we re-scan a newer ESD commit. Fix the SDA21 rA masking and `ASM`-macro detection first. |

Actor-ID lesson from knowledge.md: re-run our actor factory decoder so it follows control flow (the lis value in file order was wrong for about 24 IDs).
