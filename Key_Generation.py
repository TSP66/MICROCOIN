from nacl.encoding import HexEncoder
from nacl.signing import SigningKey
import codecs

privKey = SigningKey.generate()
pubKey  = privKey.verify_key

PK = privKey.encode(encoder=HexEncoder)

private_key = open("PRIVATE_KEY.txt", "w+")
private_key.write(PK.decode('utf-8'))
private_key.close()

PB = pubKey.encode(encoder=HexEncoder)

public_key = open("PUBLIC_KEY.txt", "w+")
public_key.write(PB.decode('utf-8'))
public_key.close()
