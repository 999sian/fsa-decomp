import sys
rows=[l.rstrip('\n').split('\t') for l in open('docs/gamemap/strings_by_addr.tsv')][1:]
rows=[r for r in rows if len(r)==3]
def show(lo,hi,minlen=6):
    seen={}
    for sa,fs,t in rows:
        for f in fs.split(','):
            if f and lo<=int(f,16)<hi and len(t)>=minlen and sum(c.isalpha() or c in ' %' for c in t)>len(t)*0.6:
                seen.setdefault(f,[]).append(t[:80])
    for f in sorted(seen): print(f, ' || '.join(seen[f][:4]))
for a in sys.argv[1:]:
    lo,hi=[int(x,16) for x in a.split('-')]
    print('=====',hex(lo)); show(lo,hi)
