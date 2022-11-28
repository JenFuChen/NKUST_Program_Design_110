import math
while(1):
    data = input()
    data = data.split()
    row = int(data[0])
    if(row <= 0):
        break
    arr = []
    sum = 0
    temp = 0
    takeWhich = 0
    averageOfSum = 0
    sumOfDifference = 0
    variance = 0

    # 指定資料位置
    if(row % 2 == 0):
        takeWhich = int(row / 2)
    elif(row % 2 != 0):
        takeWhich = int((row+1) / 2)

    # 建立資料陣列並加總
    for i in range(0, row):
        arr.append(int(data[i+1]))
        sum = arr[i] + sum

    # 算數平均數
    averageOfSum = sum / row

    # 樣本標準差
    for i in range(0, row):
        temp = math.pow(arr[i] - averageOfSum, 2)
        sumOfDifference = sumOfDifference + temp

    # 變異數
    variance = sumOfDifference / row

    arr.sort()
    print(arr[takeWhich-1], int(variance))
    # print(arr)
    # print("Take = ", arr[takeWhich-1])
    # print("Variance = ", int(variance))
    # print("AverageOfSum = ", averageOfSum)
