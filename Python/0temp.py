cnt = 1
while(cnt != 0):
    L = int(input())
    if(L <= 0):
        cnt = 0
        break
    data = input()
    each_char = data.split()
    level = 2*L - 1
    n_list = [[0 for x in range(L)]for y in range(L)]
    n = 1
    row = 0
    high = L-1
    x = 0
    y = 0
    num = 0
    orient = 0
    for i in range(1, level * level + 1):
        num = i % 3
        n_list[x][y] = each_char[num-1]
        if x + y == level - 1:
            if x > y:
                orient = 1
            else:
                orient = 2
        elif (x == y) and (y >= level / 2):
            orient = 3
        elif (x == y - 1) and (y <= level / 2):
            orient = 0
        if orient == 0:
            x += 1
        elif orient == 1:
            y += 1
        elif orient == 3:
            x -= 1
        else:
            y -= 1

    for i in range(level):
        for j in range(level):
            print('\t%02d' % n_list[i][j], end="")
        print("")


