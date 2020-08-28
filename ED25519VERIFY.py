import os
from nacl.encoding import HexEncoder
from nacl.signing import SigningKey
from nacl.signing import VerifyKey
import codecs
import sys
import pickle 

#os.system("pip3 install ed25519")

info = (sys.argv[1])
       
#alphabet = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O","P","Q","R","S","T","U","V","W","X","Y","Z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","0","1","2","3","4","6","7","8","9"]


f1 = open("PRIVATE_KEY.txt", "r")
privKey = f1.read()
print(privKey)
f1.close()
f2 = open("PUBLIC_KEY.txt", "r")
pubKey = f2.read()
print(pubKey)
f2.close()


Private_Key = SigningKey(privKey, encoder = HexEncoder)

#https://stackoverflow.com/questions/62049349/sign-and-verify-using-ed25519-in-near-protocol

Pulbic_Key = VerifyKey(pubKey, encoder=HexEncoder)

redoneinfo = bytes(info, encoding = 'utf-8')

print(str(redoneinfo))

signing = Private_Key.sign(redoneinfo)

f3 = open("SIGNATURE.txt", "wb")
f3.write(signing)
f3.close()
