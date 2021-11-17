while True:
    L = int(input())
    if(L <= 0):
        break
    data = input()
    Token = data.split()
    level = int((L*2)-1)
    for i in range(L*2):
        num = i % 3
        if(i < L):
            for k in range(0, i):
                for l in range(0, 3):
                    if(k % 3 == l):
                        print(Token[l], end=' ')
            for j in range(i, level-i):
                print(Token[num], end=' ')
            for k in range(i-1, -1, -1):
                for l in range(0, 3):
                    if(k % 3 == l):
                        print(Token[l], end=' ')
            print()
