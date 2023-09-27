# Test 05

while 1:
    a = int(input("a = "))
    b = int(input("b = "))
    c = int(input("c = "))
    if a <= 0 or b <= 0 or c <= 0:
        break

    numList = [a, b, c]
    # print(numList)
    numList.sort()

    commonDivisor = [1]
    for i in range(2, numList[0] + 1):
        if numList[0] % i == 0 and numList[1] % i == 0 and numList[2] % i == 0:
            commonDivisor.append(i)

    print("[", commonDivisor[-1], ", ", end="")

    for i in range(numList[2], 10000000000000000):
        if i % numList[0] == 0 and i % numList[1] == 0 and i % numList[2] == 0:
            print(i, "]")
            break
