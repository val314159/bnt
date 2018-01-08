import hashlib
h = hashlib.new('ripemd160')
h.update(b"Rosetta Codex")
print(h.hexdigest())
