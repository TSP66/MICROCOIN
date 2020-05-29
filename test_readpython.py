file = open("text.txt", "r")
data = str(file.read())
number = int(data);
file.close()
file = open("text.txt", "w")
number = number + 1
file.write(str(number))
file.close()
