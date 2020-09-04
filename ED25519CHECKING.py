import os
from nacl.encoding import HexEncoder
from nacl.signing import VerifyKey
import codecs
import sys

pubKey = (sys.argv[1])

sign = (sys.argv[2])



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
