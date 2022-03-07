for i in range(3):
    data = input()
    source = data.split()
    A = int(source[0])
    B = int(source[1])
    C = int(source[2])
    if B > C:
        max = B
    elif C > B:
        max = C

    if(A == 1):
        for i in range(1, max):
            if B % i == 0 and C % i == 0 and i < 100:
                print(i, end=" ")
    elif(A == 2):
        isprinted = 0
        for i in range(max, 1000):
            if (i % B == 0) and (i % C == 0) and i < 100:
                print(i, end=" ")
                isprinted = 1
        if isprinted == 0:
            print("None")
    print()
