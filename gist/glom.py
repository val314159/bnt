#!/usr/bin/python
from sys import argv as A, stdout as FO; from uuid import uuid4
def wr(n,d,u,raw): FO.write('{NL}<x{u}>{n}</x{u}>{NL}{d}'.format(
        u=u,NL=''if raw else'\n',n=n,d=d))
def glom(fns,raw=0,off=0,u=str(uuid4()).replace('-','')):
    [wr(n,open(n).read(),u,raw)for n in fns[off:]];wr('','',u,raw)
if __name__=='__main__': glom(A,A[1]=='-b',(A[1]=='-b')+1)