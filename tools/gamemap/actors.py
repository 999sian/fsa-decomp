from load import *
import json,collections
funcs=load()
fac=json.load(open(W+'/factory.json'))
byaddr={f['name']:a for a,f in funcs.items()}
def fn(n): return byname.get(n, byaddr.get(n))
def vt_of_ctor(ca):
    f=funcs.get(ca); 
    if not f: return [],[]
    vts=[byname[r] for r in f['refs'] if r in byname and 0x804916A0<=byname[r]<0x804B2140]
    bases=[c[1] for c in f['calls'] if c[0]=='bl']
    return vts,bases
def vt_entries(v):
    out=[]; a=v
    # MW vtable: [rtti ptr, offset?, fn ptrs...]; read until non-code
    w0=u32(a); w1=u32(a+4)
    a+=8
    while True:
        w=u32(a)
        if w is None or not (0x80021840<=w<0x8045BD00): break
        out.append(w); a+=4
        if len(out)>200: break
    return (w0,w1),out
rows=[]
for idb,lab,size,calls in fac:
    if not calls: rows.append(dict(id=idb,size=None,ctor=None)); continue
    ctor=fn(calls[-1])
    vts,bases=vt_of_ctor(ctor)
    d=dict(id=idb,size=size,ctor=ctor,vtables=vts,basecalls=[fn(b) for b in bases])
    if vts:
        hdr,ents=vt_entries(vts[-1])
        d['vt']=vts[-1]; d['vthdr']=hdr; d['vtent']=ents
    rows.append(d)
pickle.dump(rows,open(W+'/actors.pkl','wb'))
# method frequency to identify base methods
cnt=collections.Counter(m for r in rows for m in set(r.get('vtent',[])))
for r in rows[:5]: print(r['id'],hex(r['ctor'] or 0),[hex(x) for x in r.get('vtables',[])],[hex(x) for x in r.get('basecalls',[]) if x], len(r.get('vtent',[])))
print(collections.Counter(len(r.get('vtent',[])) for r in rows))
print(collections.Counter(r.get('basecalls',[None])[0] and hex(r['basecalls'][0]) for r in rows).most_common(20))
