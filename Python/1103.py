while True:
    try:
        L = int(input())
    except:
        break
    if (L <= 0):
        break
    data = input()
    newdata = data.split()
    level = int((L*2)-1)
    n_list = [[0 for x in range(level)]for y in range(level)]
    low = 0
    high = level-1
    square = int((L+1)/2)
    x = 0
    if(L % 3 == 0):
        cnt = 2
    elif((L+1) % 3 == 0):
        cnt = 1
    else:
        cnt = 0
    while(x < square):
        for i in range(L):
            for j in range(low, high+1):
                n_list[i][j] = newdata[cnt]
            for j in range(low+1, high+1):
                n_list[j][high] = newdata[cnt]
            for j in range(high-1, low-1, -1):
                n_list[high][j] = newdata[cnt]
            for j in range(high-1, low, -1):
                n_list[j][low] = newdata[cnt]
            low = low+1
            high = high-1
            x += 1
            if(cnt == 0):
                cnt = 2
            else:
                cnt = cnt-1
    for i in range(level):
        for j in range(level):
            print(n_list[i][j], ' ', end='')
        print()
