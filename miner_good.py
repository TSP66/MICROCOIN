# pip3 install pycryptodome
from Crypto.Hash import MD2
from io import *
import binascii
#from MD2 import *

import random
import string
import sys

Info = str(sys.argv)

def md2(string):
    i = bytearray(string, 'utf-8')
    h = MD2.new()
    h.update(i)
    return(h.hexdigest())
    

counter = 0

def build(text1, text2, text3, randomletter):
    return(str(text1)+str(text2)+str(text3)+str(randomletter))

def Next():
    global counter
    counter = counter + 1
    if(counter > 255):
        counter = 0
    return(counter)

def hash_until_0_test(message):
    
    info = str(message+str(Next()))
    data = str(md2(info))
    
    while(not(data[0] == '0')):
        info = str(message+str(Next()))
        data = str(md2(info))
        print(data)
    print(data)

def hash_until_000_test(message):
    
    info = str(message+str(Next())+str(Next()))
    data = str(md2(info))
    
    while(True):
        info = str(message)
        data = str(MD2(info))
        print(data)
        if(data[0] == '0'):
            if(data[1] == '0'):
                if(data[2] == '0'):
                    break
                
    print(data)

    
def hash_until_N0(message, zeros):
    
    info = str(message)
    data = str(md2(info))
    d = 0
        
    for i in range(zeros):
        
        if(data[i] == '0'):
            d = d +1
    if(d == zeros):
        print(data)
        new_file = open("bitcoin.txt","a+")
        new_file.write(str(zeros)+info+"\n")
        
 
        
                    
def run():
    
    FILE = open("US_TEXT.txt", "r", encoding="utf-8")
    data = FILE.readline()
    #print(str(data))
    #info = md2(data)
    #print(info)
    FILE.close()
    
    transfer_text = open("transfer.txt", "w", encoding="utf-8")
    transfer_text.write(str(md2(data)))
    blank = md2("helloworld") #Leave this line alone, it gives time to the above lines to prcess
    transfer_text.close()
     

     
     
           

    

def random_character():
    pass

