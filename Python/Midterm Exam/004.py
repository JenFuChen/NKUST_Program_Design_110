#04
while(1):
    num = int(input())
    if num<=0 :
        break
    T1 = '*'
    T2 = '#'
    line = num
    for i in range(num,0,-1):
        cnt = 2*i -1 - 2
        if(i==num):
            for k in range(num):
                print(T1,end = " ")
        else:
            for j in range(num-i):
                print(" ",end="")
            print('*',end = "")
            for m in range(cnt,0,-1):
                print(T2,end = "")
            if(i!=1):
                print('*',end = "")
        print()
        line = line -1