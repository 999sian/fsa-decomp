#!/usr/bin/env python3
"""Locate each function of donor .o objects in FSA main.dol and score masked match.
usage: find.py [-v] [-w WINDOW_HEX] [-a HINTADDR] obj.o [obj2.o ...]
Without -a, searches all of .text (slow-ish but numpy). Reports per-function best address+score and totals.
Scores only functions >= 6 instrs, with a unique best hit."""
import sys, struct, subprocess, re, numpy as np
DOL="/home/sian/Documents/FSA Decomp/orig/G4SE01/sys/main.dol"
OBJDUMP="/var/tmp/modtest/tc/devkitPPC/bin/powerpc-eabi-objdump"
d=open(DOL,'rb').read()
offs=struct.unpack('>18I',d[0:72]); addrs=struct.unpack('>18I',d[72:144]); sizes=struct.unpack('>18I',d[144:216])
# text section 1 (index 1) is main .text
ti=max(range(7),key=lambda i:sizes[i])
TBASE=addrs[ti]; TW=np.frombuffer(d[offs[ti]:offs[ti]+sizes[ti]],dtype='>u4').astype(np.uint32)
def obj_funcs(obj):
    out=subprocess.run([OBJDUMP,'-dr','-z',obj],capture_output=True,text=True).stdout
    funcs={};cur=None;order=[]
    for line in out.splitlines():
        m=re.match(r'^([0-9a-f]+) <(.+)>:',line)
        if m: cur=m.group(2);funcs[cur]=[];order.append(cur);continue
        m=re.match(r'^\s+([0-9a-f]+):\s+((?:[0-9a-f]{2} ){4})',line)
        if m and cur: funcs[cur].append([int(m.group(2).replace(' ',''),16),None]);continue
        m=re.match(r'^\s+[0-9a-f]+: (R_PPC_\S+)\s+(\S+)',line)
        if m and cur and funcs[cur]: funcs[cur][-1][1]=m.group(1)
    return [(n,funcs[n]) for n in order]
def mask(w,rel):
    op=w>>26
    if op==18: return 0xfc000003
    if op==16: return 0xffff0003
    if rel and 'SDA' in rel: return 0xffe00000
    if rel: return 0xffff0000
    return 0xffffffff
args=sys.argv[1:]; verbose=False; win=None; hint=None
while args and args[0].startswith('-'):
    a=args.pop(0)
    if a=='-v': verbose=True
    elif a=='-w': win=int(args.pop(0),16)
    elif a=='-a': hint=int(args.pop(0),16)
T=[0,0]
for obj in args:
    tot=[0,0]
    for name,f in obj_funcs(obj):
        n=len(f)
        if n<6: continue
        w=np.array([x[0] for x in f],dtype=np.uint32); m=np.array([mask(x[0],x[1]) for x in f],dtype=np.uint32)
        wm=w&m
        lo=0;hi=len(TW)-n
        if hint is not None and win: lo=max(0,(hint-TBASE)//4-win//4); hi=min(hi,(hint-TBASE)//4+win//4)
        # coarse filter on first 2 words then full score
        idx=np.arange(lo,hi)
        sc=np.zeros(len(idx),dtype=np.int32)
        for i in range(n): sc+=((TW[idx+i]&m[i])==wm[i])
        b=int(np.argmax(sc)); best=int(sc[b]); addr=TBASE+4*(lo+b)
        # size check: target function ends with blr at same length?
        tot[0]+=best; tot[1]+=n
        flag='FULL' if best==n else ''
        if verbose or True: print(f'  {name[:60]:60s} {addr:08x} {best:4d}/{n:<4d} {flag}')
    print(f'{obj}: {tot[0]}/{tot[1]} = {100*tot[0]/max(1,tot[1]):.1f}%')
    T[0]+=tot[0];T[1]+=tot[1]
