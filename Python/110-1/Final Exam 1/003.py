# 無限輸入隨意整數直到<=0,並計算0~9出現次數
import numpy as np
numList = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
times = np.zeros(52, dtype=int)
while(1):
    sentence = str(int(input()))
    temp = sentence
    if(int(temp) < 0):
        for i in range(0, 10):
            if(i < 9):
                print(i, end='')
                print(':', end='')
                print(times[i], end=', ')
            if(i == 9):
                print(i, end='')
                print(':', end='')
                print(times[i], end='')
        break
    for i in range(0, 10):
        times[i] = times[i]+sentence.count(numList[i])
