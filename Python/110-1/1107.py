N = int(input())
for i in range(1, 2*N):
    # 與(n,n)
    for j in range(1, 2*N):
        y = 0
        x = 0
        if(i >= N):
            y = i - N
        else:
            y = N - i

        if(j >= N):
            x = j - N
        else:
            x = N - j
        if(y >= x):
            k = y
        else:
            k = x
        '''if(k % 3 == 0):
            print("#", end=' ')
        if(k % 3 == 1):
            print("!", end=' ')
        if(k % 3 == 2):
            print("@", end=' ')'''
        print(k, end=' ')
    print()
