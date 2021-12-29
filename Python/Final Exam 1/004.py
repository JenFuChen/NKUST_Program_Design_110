# 未完成

def box(num):
    for i in range(num):
        for j in range(num):
            print("*", end=' ')
        print()


def boxR(num1):
    for k in range(len(data)):
        box(int(data[k]))


while(1):
    data = input()
    dataTemp = data
    data = data.split()
    dataTemp = dataTemp.split()
    sum = 0
    n = 0
    for i in range(len(data)):
        sum += int(data[i])
    list1 = [[]]
    dataTemp.sort()
    if(int(dataTemp[0]) <= 0):
        break
    boxR(len(data))
