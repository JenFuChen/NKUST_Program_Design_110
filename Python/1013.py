#找出字串內每一字母重複次數，並以＊表示次數
import numpy as np
letters = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
times = np.zeros(52,dtype=int)
for i in range(1):
    sentence = input()
    for i in range(0,52):
        times[i] = sentence.count(letters[i])
        if times[i] != 0:
            print(letters[i],end = " ")
            for i in range(0,times[i]):
                print("*",end = "")
            print(" ",end = "")
    print()