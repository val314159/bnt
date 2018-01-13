#!/usr/bin/env python
import sys,hashlib; from sys import argv
r = hashlib.new('RIPEMD160')
for a in argv[1:]: r.update(open(a).read())
print r.hexdigest()
