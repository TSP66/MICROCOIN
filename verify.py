#verify.py

from miner_good import *


FILE = open("US_TEXT.txt", "r", encoding="utf-8")
data = FILE.readline()
print("Data:", data)
FILE.close()

for i in range(10):
    blank = md2(str(i))



file2 = open('transfer_PythonC.txt', 'w', encoding='utf-8')
file3 = open('transfer_PtoC.txt', 'w', encoding='utf-8')
file3.write(str(md2(data)))
file3.close()
file2.truncate(0)
print("Hash:", str(md2(data)))
file2.write(str(md2(data)))
file2.close()
blank = md2("helloworld") #Leave this line alone, it gives time to the above lines to process
