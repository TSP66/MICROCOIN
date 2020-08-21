import ed25519
import codecs

privKey, pubKey = ed25519.create_keypair()

PK = privKey.to_ascii(encoding='hex')



private_key = open("PRIVATE_KEY.txt", "w+")
private_key.write(PK.decode('utf-8'))
private_key.close()


PB = pubKey.to_ascii(encoding='hex')



public_key = open("PUBLIC_KEY.txt", "w+")
public_key.write(PB.decode('utf-8'))
public_key.close()
