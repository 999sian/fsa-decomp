#!/bin/bash
# usage: cc.sh <donor_dir> <compiler e.g. GC/2.6> <src rel to donor> <out.o> [flags...]
P="/home/sian/Documents/FSA Decomp"
D=$1; C=$2; S=$3; O=$4; shift 4
cd "$D"
"$P/build/tools/wibo" "$P/build/compilers/$C/mwcceppc.exe" "$@" -c "$S" -o "$O" 2>&1 | grep -v "^$" | head -20
