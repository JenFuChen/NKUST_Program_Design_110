#01 
f = open("input.txt",mode='r')
f2 = open("output.txt",mode = 'w')
for line in f.readlines():
    num = int(line)
    if (num % 5 == 0) :
        print(num,file = f2)
f.close()
f2.close()