import re,glob,pickle,sys
out=[]
for f in glob.glob('/home/sian/Documents/FSA Decomp/build/G4SE01/asm/*text.s'):
    cur=None
    for l in open(f):
        if l.startswith('.fn '): cur=l[4:].split(',')[0]; ps=0;n=0;addr=None;fp=0;calls=[]
        elif l.startswith('/* ') and cur:
            if addr is None: addr=int(l[3:11],16)
            n+=1
            t=l.split('*/',1)[1]
            if 'psq_' in t or 'ps_' in t: ps+=1
            if re.search(r'\bf(add|sub|mul|div|madd|cmp)',t) or 'lfs' in t: fp+=1
            m=re.search(r'\bbl (\S+)',t)
            if m: calls.append(m.group(1))
        elif l.startswith('.endfn') and cur:
            out.append((addr,cur,n,ps,fp,calls)); cur=None
out.sort()
pickle.dump(out,open('feat.pkl','wb'))
