from load import *
import collections
funcs=load()
# strings in data sections
DSECS=[(0x8045C660,0x804916A0),(0x804916A0,0x804B2140),(0x80539BC0,0x8053A280),(0x8053AFA0,0x80543F00),(0x80005600,0x80021840)]
ok=set(range(0x20,0x7f))|{9,10,13}
strings={}
for s,e in DSECS:
    b=rd(s,e-s); i=0
    while i<len(b):
        if b[i] in ok or b[i]>=0x81:
            j=i
            while j<len(b) and (b[j] in ok or b[j]>=0x80): j+=1
            if j<len(b) and b[j]==0 and j-i>=3:
                raw=b[i:j]
                try: t=raw.decode('shift-jis')
                except: t=raw.decode('latin1')
                asc=sum(1 for c in raw if 0x20<=c<0x7f)
                if asc>=len(raw)*0.5 or len(raw)>=6:
                    strings[s+i]=t
            i=j+1
        else: i+=1
# ref map: label addr -> funcs
refby=collections.defaultdict(set)
for a,f in funcs.items():
    for r in f['refs']:
        if r in byname: refby[byname[r]].add(a)
# sorted label list with sizes for containment
labels=sorted((a,max(x[2] for x in v)) for a,v in syms.items())
la=[x[0] for x in labels]
str2f={}
br=pickle.load(open(W+'/baserefs.pkl','rb'))
for sa,t in strings.items():
    fs=set(refby.get(sa,()))|set(br.get(sa,()))
    if not fs:
        i=bisect.bisect_right(la,sa)-1
        if i>=0:
            L,S=labels[i]
            if L<=sa<L+S: fs=set(refby.get(L,()))
    str2f[sa]=fs
pickle.dump((strings,str2f,dict(refby)),open(W+'/strings.pkl','wb'))
with open(W+'/../strings_by_addr.tsv','w') as o:
    o.write('str_addr\treferencing_functions\tstring\n')
    for sa in sorted(strings):
        o.write('%08X\t%s\t%s\n'%(sa,','.join('%08X'%x for x in sorted(str2f[sa])),strings[sa].replace('\n','\\n').replace('\t','\\t')))
print(len(strings), sum(1 for v in str2f.values() if v))
