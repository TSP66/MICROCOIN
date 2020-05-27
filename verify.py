#verify.py

from miner_good import *


FILE = open("US_TEXT.txt", "r", encoding="utf-8")
data = FILE.readline()
print("DAta:", data)
FILE.close()

file2 = open("transfer_PythonC.txt", "w")
file2.write(str(md2(data)))
blank = md2("helloworld") #Leave this line alone, it gives time to the above lines to process

file2.close()

transfer_text = open("transfer_PythonC.txt", "a")
transfer_text.write(str(md2(data)))

blank = md2("helloworld") #Leave this line alone, it gives time to the above lines to process
transfer_text.close()
