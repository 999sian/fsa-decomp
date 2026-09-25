from load import *
import collections
info=pickle.load(open(W+'/info.pkl','rb'))
N=len(info)
LOCAL=['sdata2','rodata']
# exclude labels referenced over a wide text span (shared globals)
span=collections.defaultdict(list)
for f in info:
    for s in LOCAL:
        for a in f['refs'].get(s,[]): span[a].append(f['addr'])
shared={a for a,l in span.items() if max(l)-min(l)>0x30000}
print('shared labels',len(shared))
R={s:[[a for a in f['refs'].get(s,[]) if a not in shared] for f in info] for s in LOCAL}
Wn=20
possible=[True]*(N+1)
for s in LOCAL:
    mx=[max(r) if r else 0 for r in R[s]]; mn=[min(r) if r else 1<<40 for r in R[s]]
    for k in range(1,N):
        a=max(mx[max(0,k-Wn):k]); b=min(mn[k:k+Wn])
        if not a<b: possible[k]=False
forced=[None]*(N+1)
for i,f in enumerate(info):
    if f['sinit'] and i+1<N: forced[i+1]='sinit'
def val(a):
    sz=max([x[2] for x in syms.get(a,[('',0,4,'')])]) or 4
    return rd(a,min(sz,8))
lastseen={}
dupranges=[]
for i,f in enumerate(info):
    for a in R['sdata2'][i]:
        v=val(a)
        if v in lastseen and lastseen[v][0]<a and i-lastseen[v][1]<Wn:
            j=lastseen[v][1]
            cand=[k for k in range(j+1,i+1) if possible[k]]
            if len(cand)==1 and not forced[cand[0]]: forced[cand[0]]='dupconst'
            if cand: dupranges.append((j+1,i))
        lastseen[v]=(a,i)
pickle.dump((possible,forced,dupranges),open(W+'/bound.pkl','wb'))
bad=[i for i in range(N) if forced[i]=='sinit' and not possible[i]]
print('possible',sum(possible),'forced',sum(1 for x in forced if x),'sinit-not-possible',len(bad))
for i in bad[:20]: print(hex(info[i]['addr']))
