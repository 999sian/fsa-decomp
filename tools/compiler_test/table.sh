#!/bin/bash
# per-function evidence table across compilers
H=$(dirname $(readlink -f $0))
while read dir base sym addr; do
  line="$addr $sym"
  for c in 1.3.2 2.0 2.0p1 2.5 2.6 2.7; do f=$H/out/$dir/${base}_$c.o; [ -f $f ] || f=$H/out/k1/${base}_$c.o
    if [ -f $f ]; then r=$($H/cmp.py $f $sym=$addr | head -1 | grep -o 'match *[0-9]*/[0-9]*' | sed 's/match *//'); else r=-; fi
    line="$line | $c $r"; done; echo "$line"
done <<'LIST'
k1 JUTNameTab getIndex__10JUTNameTabCFPCc 8008e9f4
k1 JKRArchivePri findDirectory__10JKRArchiveCFPCcUl 8007bdd0
k1 JKRArchivePri findFsResource__10JKRArchiveCFPCcUl 8007c234
k1 JKRHeap find__7JKRHeapCFPv 80083bb0
k1 JKRSolidHeap state_register__12JKRSolidHeapCFPQ27JKRHeap6TStateUl 800853ac
k1 JUTFont setCharColor__7JUTFontFQ28JUtility6TColor 8008ccb8
k1 JUTResFont getFontCode__10JUTResFontCFi 80091d0c
k1 JUTConsole doDraw__10JUTConsoleCFQ210JUTConsole12EConsoleType 800880cc
k1 JUTPalette storeTLUT__10JUTPaletteF7_GXTlutP7ResTLUT 8008eb34
k2 J2DWindow draw__9J2DWindowFRCQ29JGeometry8TBox2<f>RCQ29JGeometry8 800a0a80
k2 J2DPane place__7J2DPaneFRCQ29JGeometry8TBox2<f> 80095bcc
k2 JAISeMgr isUsingSeqData__8JAISeMgrFRC16JAISeqDataRegion 80022e94
k2 JPAResourceManager getResource__18JPAResourceManagerCFUs 800f37a8
k2 JFWDisplay clearEfb__10JFWDisplayF8_GXColor 800e5c10
LIST
