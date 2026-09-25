from load import *
import glob,re,collections
out=collections.defaultdict(set)  # addr -> set(func addr)
for f in sorted(glob.glob(ASM+"/*text.s")):
    cur=None
    for line in open(f,errors='replace'):
        if line.startswith('.fn '): cur=None; base={}; continue
        if not (line.startswith('/* ') and '*/' in line): continue
        a=int(line[3:11],16)
        if cur is None: cur=a
        ins=line.split('*/',1)[1].strip()
        m=re.match(r'addi (r\d+), (r\d+), ("?[\w@$.<>]+"?)@l$',ins)
        if m:
            n=m.group(3).strip('"')
            if n in byname: base[m.group(1)]=byname[n]; out[byname[n]].add(cur)
            continue
        m=re.match(r'(addi|lwz|lfs|lfd|lbz|lhz|lha|stw) (r\d+|f\d+), (?:(r\d+), (-?0x[0-9A-Fa-f]+|\d+)|(-?0x[0-9A-Fa-f]+|\d+)\((r\d+)\))$',ins)
        if m:
            if m.group(1)=='addi': rb,off=m.group(3),m.group(4)
            else: rb,off=m.group(6),m.group(5)
            if rb in base:
                out[base[rb]+int(off,0)].add(cur)
            dst=m.group(2)
            if dst in base and m.group(1)!='stw': base.pop(dst,None)
            continue
        m=re.match(r'(?:mr|li|lis|lwz|addi|add|or|rlwinm|slwi|subf|mullw) (r\d+)',ins)
        if m: base.pop(m.group(1),None)
pickle.dump(dict(out),open(W+'/baserefs.pkl','wb'))
print(len(out))
