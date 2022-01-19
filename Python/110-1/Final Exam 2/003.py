#1-100猜數字遊戲，範圍會隨輸入數字更改
from random import randint
ans = randint(1,100)
check = 0
max = 100
min = 1
times = 0
print("答案:",ans)
while(check == 0):
    print("範圍為",min,"~",max,"請輸入猜測數字")
    guess = int(input())
    if(guess > max or guess < min ):
        print("輸入數字超過範圍，請重新輸入!")
        continue
    else:
        if(guess > ans):
            max = guess
        if(guess < ans):
            min = guess
        times +=1
        if(guess == ans):
            print("正確答案!")        
            print("猜測次數為:",times)
            check = 1