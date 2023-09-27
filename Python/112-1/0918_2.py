# C110152319 四子三丙 陳人輔
# 09/18 Quiz 1.2 : Cola bottle


while True:
    n = input("Please input a number: ")
    # input "0" to stop
    if n == "0":
        print()
        break

    if n.isnumeric():
        n = int(n)
        print("You can get : ", n + n // 2)
    else:
        print("Please input positive number.")
