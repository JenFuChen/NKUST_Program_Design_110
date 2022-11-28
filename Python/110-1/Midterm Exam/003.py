#03
from random import randint
import numpy as np
while(1):
    data = input()
    source=data.split()
    n=int(source[0])
    if n == 0:
        break
    m=int(source[1])
    list = np.zeros(m, dtype =int)
    for i in range(m):
        ans=(randint(1,100))
        list[i] = ans
        print(ans,end = " ")
    print()
    for i in range(len(list)):
        for j in range(0,i):
            if (list[j] >= list[i]):
                temp = list[j]
                list[j] = list[i]
                list[i] = temp
    check = 0
    for i in range(m):
        if (list[i] >= n and check == 0):
            print(list[i])
            check = 1
    if(check==0):
        print("None")
