from Crypto import Random
from Crypto.Hash import SHA256
from Crypto.Cipher import DES
from Crypto.PublicKey import RSA

random_generator = Random.new().read
rsa_key = RSA.generate(1024, random_generator)

def hash_doc(doc):    return SHA256.new(doc)

def sign_hash(hashy): return rsa_key.sign(hashy.digest(), "n/a")
def vrfy_hash(hashy, sig):
    return rsa_key.publickey().verify(hashy.digest(), sig)

def enc_rsa(text1): return rsa_key.encrypt(text1, "n/a")[0]
def dec_rsa(garb1): return rsa_key.decrypt(garb1)

def enc_des(text,k,iv=None):
    return   DES.new(k, DES.MODE_CFB, iv).encrypt(text) if iv \
        else DES.new(k, DES.MODE_ECB    ).encrypt(text)
def dec_des(garb,k,iv=None):
    return   DES.new(k, DES.MODE_CFB, iv).decrypt(garb) if iv \
        else DES.new(k, DES.MODE_ECB    ).decrypt(garb)


text1 = 'abcdefghOne'
text2 = 'abcdefghTwo'
hash1 = hash_doc(text1)
hash2 = hash_doc(text2)
signature1 = sign_hash(hash1)
signature2 = sign_hash(hash2)
assert vrfy_hash(hash1, signature1) == True
assert vrfy_hash(hash2, signature2) == True
assert vrfy_hash(hash2, signature1) == False
assert vrfy_hash(hash1, signature2) == False


text = 'message'
garb = enc_rsa(text)
assert text != garb
ntext = dec_rsa(garb[:])
assert text == ntext


text = 'abcdefgh'
cipher_text = enc_des(text,'01234567')
assert text != cipher_text
ntext = dec_des(cipher_text,'01234567')
assert text == ntext


iv8 = Random.get_random_bytes(8)
iv8 = 'x'*8
text = 'abcdefghijklmnop'
cipher_text = enc_des(text,'01234567',iv8)
assert text != cipher_text
ntext = dec_des(cipher_text,'01234567',iv8)
assert text == ntext