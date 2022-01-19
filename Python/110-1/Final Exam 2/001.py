# 001 讀檔逐行找出最大值，並印出其平均值
f = open("input.txt", mode='r')
sum = 0
counter = 0
for line in f.readlines():
    counter += 1
    max = 0
    line = line.strip("\n")
    source = line.split(' ')
    for i in range(0, len(source)):
        if(int(source[i]) > int(max)):
            max = source[i]
    print(max)
    sum += int(max)
print("所有最大值之平均")
print(int(sum/counter))
f.close()