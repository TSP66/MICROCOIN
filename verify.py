#verify.py

from miner_good import *
import os



FILE = open("US_TEXT.txt", "r", encoding="utf-8")
data = FILE.readline()
print("Data:", data)
FILE.close()

#file2 = open('transfer_PythonC.txt', 'w', encoding='utf-8')
file3 = open('transfer_PtoC.txt', 'w', encoding='utf-8')
file3.write(str(md2(data)))
file3.close()
'''os.system("cat > transfer_PtoC.txt")
os.system(str(data))
os.system('\u0007')
'''
