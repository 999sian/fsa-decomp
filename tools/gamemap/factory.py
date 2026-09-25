import re
lines=[l.rstrip('\n') for l in open('factory.s')]
regs={}; cases=[]; labels={}
ins=[]
for l in lines:
    m=re.match(r'^(\.L_[0-9A-F]+):',l)
    if m: labels[m.group(1)]=len(ins); ins.append(('LABEL',m.group(1))); continue
    if l.startswith('/* '): ins.append((int(l[3:11],16),l.split('*/',1)[1].strip()))
last=None
for i,(a,t) in enumerate(ins):
    if a=='LABEL': continue
    m=re.match(r'lis (r\d+), (0x[0-9a-fA-F]+)$',t)
    if m: regs[m.group(1)]=int(m.group(2),16); continue
    m=re.match(r'addi (r\d+), (r\d+), (-?0x[0-9a-fA-F]+)$',t)
    if m and m.group(2) in regs:
        lo=int(m.group(3),16)&0xffff; v=((regs[m.group(2)]<<16)+(lo-0x10000 if lo&0x8000 else lo))&0xffffffff
        last=v; continue
    m=re.match(r'cmpw r29, r0$',t)
    if m: cur=last; continue
    m=re.match(r'beq (\.L_[0-9A-F]+)$',t)
    if m and cur is not None:
        cases.append((cur,m.group(1))); cur=None
out=[]
for v,lab in cases:
    i=labels[lab]; size=None; ctor=None; calls=[]
    for j in range(i+1,min(i+40,len(ins))):
        a,t=ins[j]
        if a=='LABEL': continue
        m=re.match(r'li r3, (0x[0-9a-f]+|\d+)$',t)
        if m and size is None: size=int(m.group(1),0)
        m=re.match(r'bl (\S+)',t)
        if m: calls.append(m.group(1))
        if t.startswith('b .L_801FF3B4') or t.startswith('b .L_'): break
    idb=v.to_bytes(4,'big').decode('latin1')
    out.append((idb,lab,size,calls))
import json
json.dump(out,open('factory.json','w'))
for o in sorted(out): print(o)
print(len(out))
