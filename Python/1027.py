# 作業 ０６ ． 剪刀石頭布，幾戰幾勝
while(1):
    cnt = int(input())
    if(cnt % 2 == 0):
        break
    num = (cnt+1)/2
    AWin = 0
    BWin = 0
    # Y     M      O
    # 剪刀   石頭    布
    while(cnt):
        data = input()
        newdata = data.split()
        A = newdata[0]
        B = newdata[1]
        # A win
        if(A == 'Y' and B == 'O'):
            AWin += 1
        elif(A == 'O' and B == 'M'):
            AWin += 1
        elif(A == 'M' and B == 'Y'):
            AWin += 1
        # B win
        if(B == 'Y' and A == 'O'):
            BWin += 1
        elif(B == 'O' and A == 'M'):
            BWin += 1
        elif(B == 'M' and A == 'Y'):
            BWin += 1
        # 輸出並跳下一個
        if(AWin > BWin and AWin >= num):
            print("The first person wins the game")
            break
        if(BWin > AWin and BWin >= num):
            print("The second person wins the game")
            break
