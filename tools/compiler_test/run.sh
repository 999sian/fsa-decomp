#!/bin/bash
# usage: run.sh <donor> <flagsfile> <src> <tag> <compilers...> -- cmp args
D=$1; F=$2; S=$3; TAG=$4; shift 4
CS=(); while [ "$1" != "--" ]; do CS+=("$1"); shift; done; shift
H=$(dirname $(readlink -f $0))
for c in "${CS[@]}"; do
  echo "=== $c"
  $H/cc.sh $H/../$D GC/$c $S $H/out/${TAG}_${c}.o $(cat $H/$F)
  $H/cmp.py $H/out/${TAG}_${c}.o "$@"
done
