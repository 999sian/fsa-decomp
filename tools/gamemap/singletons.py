import re,glob,collections,pickle
res=[]
for f in glob.glob('/home/sian/Documents/FSA Decomp/build/G4SE01/asm/*text.s'):
    cur=None; win=[]
    for l in open(f):
        if l.startswith('.fn '): cur=l[4:].split(',')[0]; win=[]; continue
        if not l.startswith('/* '): continue
        t=l.split('*/',1)[1].strip(); win.append(t); win=win[-14:]
        m=re.match(r'stw r\d+, (lbl_\w+)@sda21\(r0\)',t)
        if m:
            w=' ; '.join(win)
            n=re.findall(r'li r3, (0x[0-9a-f]+)\s*;[^;]*;?\s*[^;]*bl (__nw__\w+)',w)
            ct=re.findall(r'bl (fn_\w+)',w)
            if '__nw__' in w and ct:
                sz=re.findall(r'li r3, (0x[0-9a-f]+|\d+)',w)
                res.append((m.group(1),cur,sz[0] if sz else '?',ct[-1]))
d=collections.defaultdict(set)
for g,c,s,ct in res: d[g].add((c,s,ct))
pickle.dump(dict(d),open('singletons.pkl','wb'))
for g in sorted(d): print(g, sorted(d[g])[:3])
