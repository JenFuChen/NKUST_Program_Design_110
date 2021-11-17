#01 
f = open("input.txt",mode='r')
min = 0
for line in f.readlines():
    num = int(line)
    if min < num:
        min = num
f2 = open("output.txt",mode = 'w')
print(min,file = f2)
f.close()
f2.close()