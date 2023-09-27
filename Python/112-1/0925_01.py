# Test 01

while 1:
    rows = int(input("Please input number: "))
    if rows <= 0:
        print("EXIT")
        break
    # rows = 3 # for testing
    space = 1
    space2 = rows

    for i in range(1, 2 * rows):
        if i <= rows - 1:
            print(" " * space2, end="")
            print("*" * (2 * i - 1), end="")
            space2 = space2 - 1
        else:
            print(" " * space, end="")
            print("*" * (2 * (2 * rows - i) - 1), end="")
            space = space + 1
        print()
