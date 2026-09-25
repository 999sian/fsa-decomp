from load import *
import collections,glob,re,os
def isid(w):
    b=w.to_bytes(4,'big'); return all(48<=c<=57 or 65<=c<=90 or 97<=c<=122 or c==95 for c in b) and 65<=b[0]<=90
res=collections.defaultdict(list)
for f in sorted(glob.glob(ASM+"/*text.s")):
    cur=None; lis={}
    for line in open(f,errors='replace'):
        if line.startswith('.fn '): cur=line[4:].split(',')[0].strip().strip('"'); lis={}; continue
        if not line.startswith('/* '): continue
        a=int(line[3:11],16); ins=line.split('*/',1)[1].strip()
        m=re.match(r'lis (r\d+), (-?0x[0-9A-F]+|\d+)$',ins)
        if m: lis[m.group(1)]=int(m.group(2),0)&0xffff; continue
        m=re.match(r'(addi|subi|ori) (r\d+), (r\d+), (-?0x[0-9A-F]+|-?\d+)$',ins)
        if m and m.group(3) in lis:
            hi=lis[m.group(3)]; lo=int(m.group(4),0)
            if m.group(1)=='subi': lo=-lo
            v=((hi<<16)+ (lo if m.group(1)=='ori' else ((lo+0x10000)&0xffff if lo<0 else lo) - (0x10000 if (m.group(1)!='ori' and (lo&0x8000) and lo>0) else 0) ))&0xffffffff
            if m.group(1)!='ori':
                lo16=lo&0xffff; v=((hi<<16)+ (lo16-0x10000 if lo16&0x8000 else lo16))&0xffffffff
            if isid(v): res[cur].append((a,v.to_bytes(4,'big').decode()))
pickle.dump(dict(res),open(W+'/ids.pkl','wb'))
top=sorted(res.items(),key=lambda x:-len(x[1]))
for n,l in top[:40]: print(n,len(l),' '.join(sorted(set(x[1] for x in l)))[:200])
