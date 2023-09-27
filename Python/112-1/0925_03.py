# Test 03

while 1:

    mixString = input("Input random string of number mix letters: ")

    numList = []
    if mixString == "exit":
        break
    for i in range(len(mixString)):
        if mixString[i] in "0123456789":
            numList.append(mixString[i])
        else:
            continue

    back = -1
    for i in range(len(mixString)):
        if mixString[i] in "0123456789":
            print(numList[back], end="")
            back = back - 1
        else:
            print(mixString[i], end="")

    print()
