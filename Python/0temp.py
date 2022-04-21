for M1 in range(1, 10, 2):
    for M2 in range(1, 10):
        print(M1, "*", M2, "=", M1*M2, end="\t")
    print()
n = 0
for M1 in range(2, 10, 2):
    for M2 in range(1, 10, 2):
        print(M1, "*", M2, "=", M1*M2, end="\t")
        n = n+1
        if n == 9:
            print()
            n = 0
for M1 in range(2, 10, 2):
    for M2 in range(2, 10, 2):
        print(M1, "*", M2, "=", M1*M2, end="\t")
        n += 1
        if n == 9:
            print()
            n = 0
