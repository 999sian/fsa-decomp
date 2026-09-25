from load import *
import bisect,csv,collections
info=pickle.load(open(W+'/info.pkl','rb'))
possible,forced,dupr=pickle.load(open(W+'/bound.pkl','rb'))
acts=[a for a in pickle.load(open(W+'/actors2.pkl','rb')) if a.get('own_lo')]
strings,str2f,refby=pickle.load(open(W+'/strings.pkl','rb'))
addrs=[f['addr'] for f in info]; idx={a:i for i,a in enumerate(addrs)}
N=len(info)
GAME0=0x800F3C10
g0=bisect.bisect_left(addrs,GAME0)
bset={}  # index -> reason
for i in range(g0,N):
    if info[i-1]['sinit']: bset[i]='after __sinit %08X'%info[i-1]['addr']
bset[g0]='game start (first actor NZMI dtor)'
acts.sort(key=lambda a:a['own_lo'])
groups=[]  # merge overlapping actors
for a in acts:
    if groups and a['own_lo']<groups[-1]['hi']:
        groups[-1]['ids'].append(a['id']); groups[-1]['hi']=max(groups[-1]['hi'],a['own_hi'])
    else: groups.append(dict(lo=a['own_lo'],hi=a['own_hi'],ids=[a['id']]))
actor_start={}
for A,B in zip(groups,groups[1:]):
    i0=bisect.bisect_left(addrs,A['hi']); i1=idx.get(B['lo'],bisect.bisect_left(addrs,B['lo']))
    if any(k in bset for k in range(i0,i1+1)): continue
    cand=[k for k in range(i0,i1+1) if possible[k]]
    k=cand[0] if cand else i1
    bset[k]='actor boundary %s|%s%s'%('/'.join(A['ids']),'/'.join(B['ids']),'' if cand else ' (no sdata2-consistent point; forced at B.lo)')
for i in range(g0,N):
    if forced[i]=='dupconst' and i not in bset: bset[i]='duplicate sdata2 constant'
ks=sorted(bset)
rows=[]
for j,k in enumerate(ks):
    e=ks[j+1] if j+1<len(ks) else N
    s_addr=addrs[k]; e_addr=info[e-1]['end']
    ids=[a['id'] for a in acts if s_addr<=a['own_lo']<e_addr]
    fl=info[k:e]
    sinit=[f['addr'] for f in fl if f['sinit']]
    strs=[]
    for f in fl:
        for sa,fs in []: pass
    rows.append(dict(start=s_addr,end=e_addr,nf=e-k,ids=ids,sinit=sinit,reason=bset[k]))
# strings per TU
f2s=collections.defaultdict(list)
for sa,fs in str2f.items():
    t=strings[sa]
    if len(t)>=5 and sum(c.isalnum() or c in ' _./%' for c in t)>len(t)*0.8:
        for f in fs: f2s[f].append(t)
for r in rows:
    ss=[]
    for f in info[idx[r['start']]:idx[r['start']]+r['nf']]:
        ss+=f2s.get(f['addr'],[])
    r['strings']=list(dict.fromkeys(ss))[:4]
pickle.dump(rows,open(W+'/tus.pkl','wb'))
print(len(rows), 'with actors',sum(1 for r in rows if r['ids']), 'multi-actor',sum(1 for r in rows if len(r['ids'])>1))
sz=[r['end']-r['start'] for r in rows]
print('median size',sorted(sz)[len(sz)//2])
