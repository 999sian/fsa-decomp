from load import *
import collections,json
funcs=load()
SEC={'rodata':(0x8045C660,0x804916A0),'data':(0x804916A0,0x804B2140),'bss':(0x804B2140,0x80539BC0),
     'sdata':(0x80539BC0,0x8053A280),'sbss':(0x8053A280,0x8053AFA0),'sdata2':(0x8053AFA0,0x80543F00),'sbss2':(0x80543F00,0x80544000)}
def secof(a):
    for k,(s,e) in SEC.items():
        if s<=a<e: return k
fl=sorted(funcs)
ctors=set(u32(a) for a in range(0x8045BD00,0x8045C640,4) if u32(a))
info=[]
for a in fl:
    f=funcs[a]
    r=collections.defaultdict(set)
    for n in f['refs']:
        if n in byname:
            t=byname[n]; s=secof(t)
            if s: r[s].add(t)
    info.append(dict(addr=a,end=f['end'],name=f['name'],refs={k:sorted(v) for k,v in r.items()},
        calls=[c[1] for c in f['calls'] if c[0]=='bl'],sinit=a in ctors,n=f['n']))
pickle.dump(info,open(W+'/info.pkl','wb'))
print(len(info))
