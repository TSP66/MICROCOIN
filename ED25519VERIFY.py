import os
import ed25519
import random
#import codecs
import sys

os.system("pip3 install ed25519")

info = (sys.argv[1])
       
#alphabet = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O","P","Q","R","S","T","U","V","W","X","Y","Z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","0","1","2","3","4","6","7","8","9"]


f1 = open("PRIVATE_KEY.txt", "r")
privKey = f1.read()
f1.close()
f2 = open("PUBLIC_KEY.txt", "r")
pubKey = f2.read()
f2.close()


Private_Key = ed25519.SigningKey()
Private_Key.sk_s = privKey

Pulbic_Key = ed25519.VerifyingKey()
Public_Key.vk_s = pubKey


msg = bytearray(info, "utf-8")

signature = Private_Key.sign(msg, encoding='hex')
print("Signature (64 bytes):", signature)

try:
    Pulbic_Key.verify(signature, msg, encoding='hex')
    print("The signature is valid.")
except:
    print("Invalid signature!")