# 讀檔並產生N個(-1~-100)亂數並加總
from random import randint
import numpy as np
f = open("input.txt", mode='r')
sum = 0
for line in f.readlines():
    num = int(line)
    if(num < 0):
        continue
    list = np.zeros(num, dtype=int)
    for i in range(num):
        ans = (randint(-100, -1))
        list[i] = ans
        print(ans, end=" ")
        sum = sum + ans
    print(sum)
f.close()
