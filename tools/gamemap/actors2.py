from load import *
import collections,csv
funcs=load()
fl=sorted(funcs)
rows=pickle.load(open('actors.pkl','rb'))
BASEVT=[u32(0x804A5770+8+4*i) for i in range(19)]
ACTOR_BASE_CTOR=0x801F5AE0
# classes: map ctor -> (vt, entries)
def vt_entries(v):
    out=[]; a=v+8
    while True:
        w=u32(a)
        if w is None or not (0x80021840<=w<0x8045BD00): break
        out.append(w); a+=4
    return out
# how often each fn appears across actor vtables
cnt=collections.Counter()
for r in rows:
    for m in set(r.get('vtent',[])): cnt[m]+=1
# intermediate bases
basevt={}
for r in rows:
    for b in r.get('basecalls',[]):
        if b and b!=ACTOR_BASE_CTOR and b in funcs:
            f=funcs[b]
            vts=[byname[x] for x in f['refs'] if x in byname and 0x804916A0<=byname[x]<0x804B2140]
            if vts: basevt[b]=vt_entries(vts[-1])
def reach(start, own, limit=400):
    # functions called (bl) from own methods, which are adjacent (within the TU window) -> include
    return own
out=[]
for r in rows:
    if not r.get('ctor'): 
        out.append(dict(id=r['id'],note='factory case w/o ctor (unused/stub)')); continue
    ents=r.get('vtent',[])
    parent=[b for b in r.get('basecalls',[]) if b][:1]
    parent=parent[0] if parent else None
    pv=basevt.get(parent, BASEVT) if parent!=ACTOR_BASE_CTOR else BASEVT
    own=[e for i,e in enumerate(ents) if (i>=len(pv) or e!=pv[i]) and cnt[e]<=2 and e not in BASEVT]
    slots={i:e for i,e in enumerate(ents) if (i>=len(pv) or e!=pv[i])}
    lo=min(own) if own else None; hi=max(own) if own else None
    # extend hi to end of that function
    if hi: hi=funcs[hi]['end'] if hi in funcs else hi
    nf=len([a for a in fl if lo and lo<=a<hi]) if lo else 0
    out.append(dict(id=r['id'],alloc_size=r['size'],ctor=r['ctor'],parent_ctor=parent,vtable=r.get('vt'),nslots=len(ents),
        dtor=ents[0] if ents else None, setparams=slots.get(1), update=slots.get(3), draw=slots.get(6),
        own_lo=lo,own_hi=hi,nfuncs_in_range=nf,bytes=(hi-lo) if lo else 0, overridden=sorted(slots)))
pickle.dump(out,open(W+'/actors2.pkl','wb'))
H=lambda x:'%08X'%x if x else ''
with open(W+'/../actors.csv','w',newline='') as f:
    w=csv.writer(f)
    w.writerow(['id','alloc_size','ctor','parent_ctor','vtable','n_vslots','dtor','setParams(slot1)','update(slot3)','draw(slot6)','overridden_slots','method_range_start','method_range_end','range_bytes','funcs_in_range','note'])
    for o in sorted(out,key=lambda o:o.get('own_lo') or 0):
        w.writerow([o['id'],hex(o['alloc_size']) if o.get('alloc_size') else '',H(o.get('ctor')),H(o.get('parent_ctor')),H(o.get('vtable')),o.get('nslots',''),H(o.get('dtor')),H(o.get('setparams')),H(o.get('update')),H(o.get('draw')),' '.join(map(str,o.get('overridden',[]))),H(o.get('own_lo')),H(o.get('own_hi')),hex(o['bytes']) if o.get('bytes') else '',o.get('nfuncs_in_range',''),o.get('note','')])
print(len(out))
