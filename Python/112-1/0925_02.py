# Test 02

while 1:
    decimalNum = int(input("please input a number: "))
    if decimalNum > 255 or decimalNum <= 0:
        break
    digits = len(bin(decimalNum)) - 2  # minus 2 to erase prefix "0b"
    print("0" * (8 - digits) + bin(decimalNum)[2::])
