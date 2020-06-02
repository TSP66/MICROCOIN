#verify.py

from miner_good import *
import socket

HOST = '127.0.0.1'  # The server's hostname or IP address
PORT = 8079        # The port used by the server


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    print("Connected")
    data = s.recv(1024)
    print("Info recived")
    hashi = bytearray(str(md2(str(data))), 'utf-8')
    s.sendall(hashi)
    print("Sent Data")
    s.close()


