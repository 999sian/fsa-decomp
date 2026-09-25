from load import *
import sys
info=pickle.load(open(W+'/info.pkl','rb'))
funcs=load()
lo,hi=[int(x,16) for x in sys.argv[1:3]]
for f in info:
    if lo<=f['addr']<hi:
        F=funcs[f['addr']]
        refs=sorted(set(r for r in F['refs'] if not r.startswith('lbl_')))
        print('%08X %4d %-14s %s | %s | %s'%(f['addr'],f['n'],f['name'][:14],'S' if f['sinit'] else ' ',' '.join(sorted(set(f['calls'])))[:110],' '.join(refs)[:60]))
