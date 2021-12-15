
data = []
size = input()
size = size.split()
rowsize = int(size[0])
colsize = int(size[1])

for i in range(0, rowsize):
    strarr = input().split()
    arr = []
    for j in range (0, colsize):
        arr.append(int(strarr[j]))
    print(arr)
    data.append(arr)

##for i in range (0, rowsize):
##    arr = []
##    for j in range (0, colsize):
##        arr.append(int(input()))
##    print(arr)
##    data.append(arr)

print(data)

for i in range (0, rowsize):
    for j in range (0, colsize):
        print(data [i][j], end ="\t")
    print()
