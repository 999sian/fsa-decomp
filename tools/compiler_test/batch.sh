#!/bin/bash
# usage: batch.sh <donor> <flagsfile> <tag> "<compilers>" files...
# compiles each file with each compiler (parallel), then scores with find.py over JSystem region
D=$1; F=$2; TAG=$3; CS=$4; shift 4
H=$(dirname $(readlink -f $0)); mkdir -p $H/out/$TAG
for c in $CS; do for s in "$@"; do
  b=$(basename $s .cpp)
  ( $H/cc.sh $H/../$D GC/$c $s $H/out/$TAG/${b}_$c.o $(cat $H/$F) >/dev/null 2>&1 ) &
done; wait; done
for s in "$@"; do b=$(basename $s .cpp); line="$b"
  for c in $CS; do
    o=$H/out/$TAG/${b}_$c.o
    if [ -f $o ]; then r=$($H/find.py -a ${HINT:-800A0000} -w ${WIN:-80000} $o | tail -1 | sed 's/.*: //'); else r=FAIL; fi
    line="$line | $c: $r"
  done; echo "$line"
done
