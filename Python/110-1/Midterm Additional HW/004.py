# 004 讀檔，找出兩數的公因公倍
import numpy as np
f = open("input.txt",mode='r')
f2 = open("output.txt",mode = 'w')
for line in f.readlines():
    num = line
    source = num.split(' ')
    n = int(source[0])
    m = int(source[1])
    if n > m :
        max = n
        min = m
    else:
        max = m
        min = n
    list = np.zeros(max, dtype =int)
    for i in range(1,max):
        if(min % i == 0 and max % i == 0):
            list[i] = i
    for i in range(len(list)):
        for j in range(0,i):
            if (list[j] >= list[i]):
                temp = list[j]
                list[j] = list[i]
                list[i] = temp
    check = 0
    for i in range(1,10000):
        if(i % min == 0 and i % max == 0 and check == 0):
            print(i,file = f2,end = " ")
            check = 1 
    print(list[-1],file = f2)
f.close()
f2.close()
