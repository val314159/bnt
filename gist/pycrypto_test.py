#!/usr/bin/env python
import os, sys
from Crypto import Random
from Crypto.Hash import SHA224
from Crypto.Cipher import DES, AES
from Crypto.PublicKey import RSA
import cPickle as pickle
random_generator = Random.new().read
rsa_key = RSA.generate(1024, random_generator)
AES_IV = 16 * '0'
def hash_doc(doc):    return SHA224.new(doc)
def sign_hash(hashy): return rsa_key.sign(hashy.hexdigest(), "n/a")
def vrfy_hash(hashy, sig):
    return rsa_key.publickey().verify(hashy.hexdigest(), sig)
def rawsign_hash(hashy):    return rsa_key.sign(hashy, "n/a")
def rawvrfy_hash(hashy,sig):return rsa_key.publickey().verify(hashy,sig)
def load_rsa_public(fname='pub.pem'):
    global rsa_key; rsa_key = RSA.importKey(open(fname).read())
def load_rsa_private(fname='prv.pem'):
    global rsa_key; rsa_key = RSA.importKey(open(fname).read())
def save_rsa_public(fname='pub.pem'):
    return open(fname,'w').write(rsa_key.publickey().exportKey('PEM'))
def save_rsa_private(fname='prv.pem'):
    return open(fname,'w').write(rsa_key.exportKey('PEM'))
def enc_rsa(text): return rsa_key.encrypt(text, "n/a")[0]
def dec_rsa(garb): return rsa_key.decrypt(garb)
def enc_des(text,key,iv=None):
    return   DES.new(key,DES.MODE_CFB,iv).encrypt(text) if iv \
        else DES.new(key,DES.MODE_ECB   ).encrypt(text)
def dec_des(garb,key,iv=None):
    return   DES.new(key,DES.MODE_CFB,iv).decrypt(garb) if iv \
        else DES.new(key,DES.MODE_ECB   ).decrypt(garb)
def enc_aes(text,key,iv=AES_IV):
    return AES.new(key, AES.MODE_CBC, IV=iv).encrypt(text)
def dec_aes(garb,key,iv=AES_IV):
    return AES.new(key, AES.MODE_CBC, IV=iv).encrypt(garb)
def keys(): save_rsa_private(), save_rsa_public()
def sign():
    load_rsa_private()
    hash1 = hash_doc(open(sys.argv[1]).read())
    sig1 = sign_hash(hash1)
    pickle.dump(sig1,open('s1.sig','w'))
def verify():
    load_rsa_public()
    hash1 = hash_doc(open(sys.argv[1]).read())
    sig1 = pickle.load(open('s1.sig','r'))
    assert vrfy_hash(hash1, sig1) == True
def main():
    d = dict(keys=keys, sign=sign, verify=verify, test=test)
    if len(sys.argv)>1: exit( d[sys.argv.pop(1)]() )
    print 'try one of "%s"'%'", "'.join(d.keys()); exit(1)
def test1():
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
    return signature1, signature2
def test2():
    text = 'message'
    garb = enc_rsa(text)
    assert text != garb
    ntext = dec_rsa(garb[:])
    assert text == ntext
def test3():
    text = 'abcdefgh'
    cipher_text = enc_des(text,'01234567')
    assert text != cipher_text
    ntext = dec_des(cipher_text,'01234567')
    assert text == ntext
def test4():
    iv8 = Random.get_random_bytes(8)
    iv8 = 'x'*8
    text = 'abcdefghijklmnop'
    cipher_text = enc_des(text,'01234567',iv8)
    assert text != cipher_text
    ntext = dec_des(cipher_text,'01234567',iv8)
    assert text == ntext
def test(): test1(),test2(),test3(),test4()
if __name__=='__main__': main()
