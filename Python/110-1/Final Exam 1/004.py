# 未完成，沒拿分ＱＱ
'''
def box(num):
    

def boxR(num1):
    for k in range(len(data)):
        for i in range(int(data[])):
            for j in range(num):
                print("*", end=' ')
            print()

while(1):
    data = input()
    dataTemp = data
    data = data.split()
    dataTemp = dataTemp.split()
    sum = 0
    n = 0
    for i in range(len(data)):
        sum += int(data[i])
    dataTemp.sort()
    if(int(dataTemp[0]) <= 0):
        break
    boxR(len(data))'''

while True:
    N = list(map(int, input().split()))
    height = max(N)
    for i in range(height):
        for column in N:
            for j in range(column):
                if(height-i < column+1):
                    print("* ", end='')
                else:
                    print("  ", end='')
        print()
