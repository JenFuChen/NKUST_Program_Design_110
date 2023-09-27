# C110152319 四子三丙 陳人輔
# 09/18 Quiz 1.1 : Triangle

while True:
    rows = input("Please input a number: ")
    # input "0" to stop
    if rows == "0":
        print()
        break
    if rows.isnumeric():
        rows = int(rows)
        space = rows
        for i in range(rows):
            print(" " * space, end="")
            print("*" * (2 * i + 1), end="")
            print()
            space = space - 1
    else:
        print("Please input positive number.")
