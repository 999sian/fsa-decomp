#!/bin/bash
# difc.sh <donor> <flagsfile> <outdir> <listfile> "<compilers>" : compile all, report files where compilers differ vs first
H=$(dirname $(readlink -f $0)); D=$1; F=$2; O=$H/out/$3; L=$4; CS=($5); mkdir -p $O
OD=/var/tmp/modtest/tc/devkitPPC/bin/powerpc-eabi-objdump
for c in "${CS[@]}"; do
  cat $L | xargs -P 16 -I{} bash -c 'b=$(basename {} .cpp); b=$(basename $b .c); '$H'/cc.sh '$H'/../'$D' GC/'$c' {} '$O'/${b}_'$c'.o $(cat '$H'/'$F') >/dev/null 2>&1'
done
for s in $(cat $L); do b=$(basename $s .cpp); b=$(basename $b .c); f=$O/${b}_${CS[0]}.o; [ -f $f ] || { echo "$b FAIL ${CS[0]}"; continue; }
  for c in "${CS[@]:1}"; do g=$O/${b}_$c.o; [ -f $g ] || { echo "$b FAIL $c"; continue; }
    cmp -s <($OD -dr $f | tail -n +4) <($OD -dr $g | tail -n +4) || echo "$b differs ${CS[0]} vs $c"; done; done
