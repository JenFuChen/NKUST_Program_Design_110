# 003 輸入N,列出N個1-99的亂數，並找出其最小值
from random import randint
import numpy as np
f = open("input.txt",mode='r')
for line in f.readlines():
    num = int(line)
    list = np.zeros(num, dtype =int)
    for i in range(num):
        ans=(randint(1,99))
        list[i] = ans
        print(ans,end = " ")
    for i in range(len(list)):
        for j in range(0,i):
            if (list[j] >= list[i]):
                temp = list[j]
                list[j] = list[i]
                list[i] = temp
    print("=>",list[0])