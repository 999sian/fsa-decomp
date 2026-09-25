#!/usr/bin/env python3
"""Count prologue pattern: after 'mflr r0', is the next instr 'stw r0,X(r1)' (1.x style) or something
else hoisted between (2.x scheduler style)?  usage: prolog.py dol [start end step]  |  prolog.py obj files..."""
import sys,struct,subprocess,re
def stats(words):
    tot=hoist=0
    for i in range(len(words)-1):
        if words[i]==0x7c0802a6:
            tot+=1
            nx=words[i+1]
            if (nx&0xffff0000)!=0x90010000: hoist+=1
    return tot,hoist
if sys.argv[1]=='dol':
    d=open("/home/sian/Documents/FSA Decomp/orig/G4SE01/sys/main.dol",'rb').read()
    o=struct.unpack('>18I',d[0:72]);a=struct.unpack('>18I',d[72:144]);s=struct.unpack('>18I',d[144:216])
    W=struct.unpack('>%dI'%(s[1]//4),d[o[1]:o[1]+s[1]]); base=a[1]
    st,en,step=[int(x,16) for x in sys.argv[2:5]]
    for x in range(st,en,step):
        t,h=stats(W[(x-base)//4:(min(en,x+step)-base)//4])
        print(f'{x:08x}-{min(en,x+step):08x}: mflr {t:5d} hoisted {h:5d} ({100*h/max(t,1):5.1f}%)')
else:
    OD="/var/tmp/modtest/tc/devkitPPC/bin/powerpc-eabi-objdump"
    T=H=0
    for f in sys.argv[1:]:
        out=subprocess.run([OD,'-d','-z',f],capture_output=True,text=True).stdout
        ws=[int(m.group(1).replace(' ',''),16) for m in re.finditer(r'^\s+[0-9a-f]+:\s+((?:[0-9a-f]{2} ){4})',out,re.M)]
        t,h=stats(ws);T+=t;H+=h
    print(f'mflr {T} hoisted {H} ({100*H/max(T,1):.1f}%)')
