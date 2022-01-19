for i in range(3):
    data = input()
    newdata = data.split()
    A = int(newdata[0])
    B = int(newdata[1])
    if A == 2 and B == 1:
        print("The first man wins the game")
    elif A == 1 and B == 3:
        print("The first man wins the game")
    elif A == 3 and B == 2:
        print("The first man wins the game")
    elif A == B:
        print("A tie")
    elif A == 1 and B == 2:
        print("The second man wins the game")
    elif A == 2 and B == 3:
        print("The second man wins the game")
    elif A == 3 and B == 1:
        print("The second man wins the game")
