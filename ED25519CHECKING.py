import os
from nacl.encoding import HexEncoder
from nacl.signing import VerifyKey
import codecs
import sys

#pubKey = (sys.argv[1])

#signature = (sys.argv[2])



f3 = open("SIGNATURE.txt", "rb")
sign = f3.read()
f3.close()

f2 = open("PUBLIC_KEY.txt", "r")
pubKey = f2.read()
f2.close()

Pulbic_Key = VerifyKey(pubKey, encoder=HexEncoder)

f1 = open("VERIFICATION.txt", "w+")



try:
    Public_Key.verify(sign, encoder=HexEncoder)
    print("CORRECT")
    f1.write("Y")
    os.system("sync")


except:
    print("FAIL")
    f1.write("N")
    os.system("sync")

f1.close()
