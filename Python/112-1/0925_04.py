# Test 04

while 1:
    num = int(input("Please input a number : "))
    if num <= 0:
        break
    for x in range(num, 1, -1):
        isPrime = 1  # Default the num is prime
        for i in range(2, x, 1):
            if x % i == 0:
                isPrime = 0
                break
        if isPrime == 1 and x != num:
            print(x, end=", ")
            break

    for x in range(num, 1000000000):
        isPrime = 1  # Default the num is prime
        for i in range(2, x, 1):
            if x % i == 0:
                isPrime = 0
                break
        if isPrime == 1 and x != num:
            print(x)
            break
