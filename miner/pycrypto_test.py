import os, sys
from Crypto import Random
from Crypto.Hash import SHA256
from Crypto.Cipher import DES
from Crypto.PublicKey import RSA
import cPickle as pickle

random_generator = Random.new().read
rsa_key = RSA.generate(1024, random_generator)

def hash_doc(doc):    return SHA256.new(doc)

def sign_hash(hashy): return rsa_key.sign(hashy.digest(), "n/a")

def load_rsa(fname='my.pem'):
    global rsa_key
    rsa_key = RSA.importKey(open(fname).read())
    return rsa_key

def save_rsa_public(fname='my.pem'):
    f = open(fname,'w')
    f.write(rsa_key.publickey().exportKey('PEM'))
    f.close()

def save_rsa_private(fname='my.pem'):
    f = open(fname,'w')
    f.write(rsa_key.exportKey('PEM'))
    f.close()

def load_rsa(fname='my.pem'):
    ret = RSA.importKey(open(fname).read())
    global rsa_key
    rsa_key=ret
    return ret
    return RSA.importKey(open(fname).read())

def vrfy_hash(hashy, sig):
    #print "ok then", rsa_key.publickey().exportKey('PEM')
    pk = rsa_key.publickey()
    return pk.verify(hashy.digest(), sig)

def vrfy_hash2(hashy, sig):
    pk = rsa_key2.publickey()
    return pk.verify(hashy.digest(), sig)

def vrfy_hash3(hashy, sig):
    pk = rsa_key3.publickey()
    return pk.verify(hashy.digest(), sig)

def enc_rsa(text): return rsa_key.encrypt(text, "n/a")[0]
def dec_rsa(garb): return rsa_key.decrypt(garb)

def enc_des(text,k,iv=None):
    return   DES.new(k, DES.MODE_CFB, iv).encrypt(text) if iv \
        else DES.new(k, DES.MODE_ECB    ).encrypt(text)
def dec_des(garb,k,iv=None):
    return   DES.new(k, DES.MODE_CFB, iv).decrypt(garb) if iv \
        else DES.new(k, DES.MODE_ECB    ).decrypt(garb)

text1 = 'abcdefghOne'
text2 = 'abcdefghTwo'

def test1():
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

def main1():
    signature1, signature2 = test1()
    #print '------2'
    test2(),test3(),test4()
    #print '------21'

    hash1 = hash_doc(text1)
    hash2 = hash_doc(text2)

    #print '------22'
    #xtn_str="""
    #"""
    #h = hash_doc(xtn_str)
    #s = sign_hash(h)
    #print h.hexdigest()
    #print s[0]
 
    f = open('pub.pem','w')
    f.write(rsa_key.publickey().exportKey('PEM'))
    f.close()

    f = open('prv.pem','w')
    f.write(rsa_key.exportKey('PEM'))
    f.close()

    global rsa_key2, rsa_key3
    rsa_key2 = RSA.importKey(open('prv.pem').read())
    assert vrfy_hash2(hash1, signature1) == True
    assert vrfy_hash2(hash2, signature2) == True
    assert vrfy_hash2(hash2, signature1) == False
    assert vrfy_hash2(hash1, signature2) == False

    rsa_key3 = RSA.importKey(open('pub.pem').read())
    assert vrfy_hash3(hash1, signature1) == True
    assert vrfy_hash3(hash2, signature2) == True
    assert vrfy_hash3(hash2, signature1) == False
    assert vrfy_hash3(hash1, signature2) == False

    pickle.dump(signature1,open('s1.sig','w'))
    pickle.dump(signature2,open('s2.sig','w'))
    pass

def main2():
    hash1 = hash_doc(text1)
    hash2 = hash_doc(text2)

    sig1 = pickle.load(open('s1.sig'))
    sig2 = pickle.load(open('s2.sig'))

    load_rsa('pub.pem')
    assert vrfy_hash(hash1, sig1) == True
    assert vrfy_hash(hash2, sig2) == True
    assert vrfy_hash(hash2, sig1) == False
    assert vrfy_hash(hash1, sig2) == False

if __name__=='__main__':
    d = dict(sign=main1, vrfy=main2)
    if len(sys.argv)>1: exit( d[sys.argv.pop(1)]() )
    print 'try one of "%s"'%'", "'.join(d.keys()); exit(1)
