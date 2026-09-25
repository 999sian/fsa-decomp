import re,struct,os,glob,pickle,bisect
ROOT="/home/sian/Documents/FSA Decomp"
ASM=ROOT+"/build/G4SE01/asm"
W=os.path.dirname(os.path.abspath(__file__))
dol=open(ROOT+"/build/G4SE01/main.dol",'rb').read()
off=struct.unpack('>18I',dol[0:72]);addr=struct.unpack('>18I',dol[72:144]);sz=struct.unpack('>18I',dol[144:216])
SECS=[(addr[i],addr[i]+sz[i],off[i]) for i in range(18) if sz[i]]
def rd(a,n):
    for s,e,o in SECS:
        if s<=a<e: return dol[o+a-s:o+a-s+n]
    return None
def u32(a):
    b=rd(a,4); return struct.unpack('>I',b)[0] if b and len(b)==4 else None
# symbols
syms={}   # addr->(name,sec,size,type)
byname={}
for l in open(ROOT+"/config/G4SE01/symbols.txt"):
    m=re.match(r'(\S+) = (\S+):0x([0-9A-F]+); // (.*)',l)
    if not m: continue
    n,sec,a,rest=m.group(1),m.group(2),int(m.group(3),16),m.group(4)
    t=re.search(r'type:(\w+)',rest); s=re.search(r'size:0x([0-9A-F]+)',rest)
    syms.setdefault(a,[]).append((n,sec,int(s.group(1),16) if s else 0,t.group(1) if t else ''))
    byname[n]=a
def load():
    p=W+"/cache.pkl"
    if os.path.exists(p): return pickle.load(open(p,'rb'))
    funcs={}  # addr -> dict
    for f in sorted(glob.glob(ASM+"/*.s")):
        base=os.path.basename(f)
        cur=None
        for line in open(f,errors='replace'):
            if line.startswith('.fn '):
                name=line[4:].split(',')[0].strip().strip('"')
                cur={'name':name,'file':base,'refs':[],'calls':[],'n':0}
                continue
            if line.startswith('.endfn'):
                if cur and cur.get('addr') is not None:
                    funcs[cur['addr']]=cur
                cur=None; continue
            if cur is not None and line.startswith('/* ') and '*/' in line:
                a=int(line[3:11],16)
                if 'addr' not in cur: cur['addr']=a
                cur['end']=a+4; cur['n']+=1
                ins=line.split('*/',1)[1].strip()
                m=re.match(r'(bl|b)\s+("?[^\s"]+"?)$',ins)
                if m: cur['calls'].append((m.group(1),m.group(2).strip('"')))
                for r in re.findall(r'("[^"]+"|[\w@$.<>]+)([+-]0x[0-9A-F]+)?@(ha|l|sda21|h)',ins):
                    if r[2]!='ha':
                        cur['refs'].append(r[0].strip('"'))
                        cur.setdefault('offrefs',[]).append((r[0].strip('"'),int(r[1],16) if r[1] else 0))
    pickle.dump(funcs,open(p,'wb'))
    return funcs
