# 005 印出菱形
while(1):
    level = int(input())
    if(level <= 0):
        break
    L = 2*level-1
    mid = int((L - 1) / 2)
    inspa = mid * 2 - 1
    for i in range(L):
        spa = level - i - 1
        if spa >= 0:
            print(" " * spa, end='')
            print('*', end='')
        if spa < 0:
            spa = -spa
            print(" " * spa, end='')
            print('*', end='')
        if(i > 0 and i <= mid):
            for j in range(i*2-1):
                print(" ", end='')
            print('*', end='')
        if(i > 0 and i > mid and i != L-1):
            inspa = inspa - 2
            for j in range(inspa):
                print(" ", end='')
            print('*', end='')

        print()
