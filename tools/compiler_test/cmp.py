#!/usr/bin/env python3
"""Compare functions from a compiled donor .o against FSA main.dol.
usage: cmp.py obj.o SYMBOL=0xADDR [SYMBOL=0xADDR ...]
SYMBOL may be a substring of the mangled name (first match). Prints match stats.
Masks: branch displacement, low 16 bits of relocated instrs (per objdump -r), sda offsets."""
import sys, struct, subprocess, re
DOL="/home/sian/Documents/FSA Decomp/orig/G4SE01/sys/main.dol"
OBJDUMP="/var/tmp/modtest/tc/devkitPPC/bin/powerpc-eabi-objdump"
d=open(DOL,'rb').read()
offs=struct.unpack('>18I',d[0:72]); addrs=struct.unpack('>18I',d[72:144]); sizes=struct.unpack('>18I',d[144:216])
def dol_words(a,n):
    for o,ad,s in zip(offs,addrs,sizes):
        if ad<=a<ad+s: return list(struct.unpack('>%dI'%n,d[o+a-ad:o+a-ad+4*n]))
    raise Exception('addr not in dol %x'%a)
def obj_funcs(obj):
    out=subprocess.run([OBJDUMP,'-dr','--no-show-raw-insn' if False else '-z',obj],capture_output=True,text=True).stdout
    funcs={};cur=None;relocs={}
    for line in out.splitlines():
        m=re.match(r'^([0-9a-f]+) <(.+)>:',line)
        if m: cur=m.group(2);funcs[cur]=[];continue
        m=re.match(r'^\s+([0-9a-f]+):\s+((?:[0-9a-f]{2} ){4})\s*(.*)',line)
        if m and cur: funcs[cur].append([int(m.group(2).replace(' ',''),16),m.group(3),False]);continue
        m=re.match(r'^\s+[0-9a-f]+: (R_PPC_\S+)\s+(\S+)',line)
        if m and cur and funcs[cur]: funcs[cur][-1][2]=True; funcs[cur][-1][1]+='  <'+m.group(1)+' '+m.group(2)+'>'
    return funcs
def norm(w,rel):
    op=w>>26
    if op==18: return w&0xfc000003
    if op==16: return w&0xffff0003
    if rel: return w&0xffff0000
    return w
def dis(ws):
    import tempfile,os
    f=tempfile.NamedTemporaryFile(delete=False); f.write(b''.join(struct.pack('>I',x) for x in ws)); f.close()
    out=subprocess.run([OBJDUMP,'-D','-b','binary','-m','powerpc:common','-EB',f.name],capture_output=True,text=True).stdout
    os.unlink(f.name)
    return [l.split('\t',2)[-1] for l in out.splitlines() if re.match(r'^\s+[0-9a-f]+:\t',l)]
def main():
    obj=sys.argv[1]; fs=obj_funcs(obj); verbose='-v' in sys.argv
    tot_ok=tot=0
    for arg in sys.argv[2:]:
        if arg=='-v': continue
        sym,addr=arg.split('='); addr=int(addr,16)
        names=[n for n in fs if n==sym] or [n for n in fs if sym in n]
        if not names: print(f'{sym}: NOT FOUND'); continue
        f=fs[names[0]]
        t=dol_words(addr,len(f)+1)
        # mask target words where relocation-like (lis/addi/lwz sda in target: hard) -> compare with obj's reloc flag
        same=sum(1 for i,(w,txt,rel) in enumerate(f) if norm(w,rel)==norm(t[i],rel))
        exact_size = (t[len(f)-1]==0x4e800020) if f else False
        tot_ok+=same; tot+=len(f)
        print(f'{names[0][:50]:50s} @{addr:08x} len {len(f):3d} match {same:3d}/{len(f)} {"FULL" if same==len(f) else ""}')
        if verbose and same!=len(f):
            td=dis(t[:len(f)])
            for i,(w,txt,rel) in enumerate(f):
                mark=' ' if norm(w,rel)==norm(t[i],rel) else '*'
                print(f'   {mark} {txt[:45]:45s} | {td[i]}')
    print(f'TOTAL {tot_ok}/{tot}')
main()
