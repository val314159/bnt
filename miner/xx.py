import hashlib
h = hashlib.new('ripemd160')
h.update(b"Rosetta Code")
print(h.hexdigest())
