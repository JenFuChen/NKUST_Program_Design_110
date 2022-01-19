# 作業 ０５ ． 輸入3@# 要印出三角形的
cnt = int(input())
for num in range(cnt):
    data = input()
    newdata = data.split()
    L = int(newdata[0])
    T1 = newdata[1]
    T2 = newdata[2]
    for j in range(1, L+1):
        print(T1*j, end="")
        for k in range(L-j):
            print(T2, end="")
        print()
