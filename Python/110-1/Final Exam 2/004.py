customerData = []
f = open("input.txt",mode='r',encoding = 'utf-8')
for line in f.readlines():
    data = line
    data = data.split()
    customerData.append(data[0:len(data)])
f.close()
row = len(customerData)
col = len(customerData[0])
for i in range(1,col):
    max = 0
    for j in range(1,row):
        if(int(customerData[j][i]) > int(max)):
            max = int(customerData[j][i])
            maxrow = j
    print(customerData[0][i],":",customerData[maxrow][0],max)