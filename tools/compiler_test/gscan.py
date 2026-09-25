#!/usr/bin/env python3
"""Global discriminator scan. For every function present in both A.o and B.o (same donor TU compiled
with compiler A and B) whose masked code differs, search the whole DOL .text for FULL masked matches
of each variant. Prints hits with address so you can see which compiler built which region.
usage: gscan.py tagA tagB objdir   (objects named <base>_<tag>.o)"""
import sys,glob,os,re,struct,numpy as np,subprocess
sys.argv_=sys.argv
exec(open(os.path.join(os.path.dirname(__file__),'find.py')).read().split("args=sys.argv[1:]")[0])
A,B,D=sys.argv[1],sys.argv[2],sys.argv[3]
N=len(TW)
def fullhits(f):
    n=len(f)
    w=np.array([x[0] for x in f],dtype=np.uint32); m=np.array([mask(x[0],x[1]) for x in f],dtype=np.uint32); wm=w&m
    cand=np.nonzero((TW[:N-n]&m[0])==wm[0])[0]
    for i in range(1,n):
        if len(cand)==0: break
        cand=cand[(TW[cand+i]&m[i])==wm[i]]
    return [TBASE+4*int(c) for c in cand]
def key(f): return [ (x[0]&mask(x[0],x[1])) for x in f]
res={'A':[], 'B':[], 'both':[]}
for fa in sorted(glob.glob(f'{D}/*_{A}.o')):
    fb=fa[:-len(A)-2]+f'{B}.o'
    if not os.path.exists(fb): continue
    FA=dict(obj_funcs(fa)); FB=dict(obj_funcs(fb))
    for name in FA:
        if name not in FB or len(FA[name])<8: continue
        if key(FA[name])==key(FB[name]): continue
        ha=fullhits(FA[name]); hb=fullhits(FB[name])
        if ha or hb:
            print(f'{os.path.basename(fa)[:-len(A)-3]:22s} {name[:55]:55s} {A}:{",".join("%08x"%a for a in ha[:40])}{"..." if len(ha)>40 else ""}  {B}:{",".join("%08x"%a for a in hb[:40])}{"..." if len(hb)>40 else ""}')
