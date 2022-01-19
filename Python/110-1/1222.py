def addCustomer():
    check = 0
    ID = data[1]
    for i in range(len(customerData)-1, -1, -1):
        if(ID == customerData[i][0]):
            print("Exist")
            check = 1
    if(check == 0):
        customerData.append(data[1:5])


def deleteCustomer():
    check = 0
    ID = data[1]
    for i in range(len(customerData)-1, -1, -1):
        if(ID == customerData[i][0]):
            del customerData[i]
            check = 1
    if(check == 0):
        print("None")


def arrangeData():
    check = 0
    ID = data[1]
    option = int(data[2])
    index = data[3]
    for i in range(len(customerData)-1, -1, -1):
        if(ID == customerData[i][0]):
            if(option == 0):  # ID
                customerData[i][1] = index
            if(option == 1):  # phone.
                customerData[i][2] = index
            if(option == 2):  # birth
                customerData[i][3] = index
            check = 1
    if(check == 0):
        print("None")


def searchCustomer():
    check = 0
    ID = data[1]
    option = int(data[2])
    for i in range(len(customerData)-1, -1, -1):
        if(ID == customerData[i][0]):
            if(option == 0):  # ID
                print(customerData[i][1])
            if(option == 1):  # phone.
                print(customerData[i][2])
            if(option == 2):  # birth
                print(customerData[i][3])
            check = 1
    if(check == 0):
        print("None")


customerData = []
while(1):
    data = input()
    data = data.split()
    order = data[0]
    if(order == '*'):
        break
    if (order == '@'):
        addCustomer()
    if(order == "#"):
        deleteCustomer()
    if(order == "!"):
        arrangeData()
    if(order == '$'):
        searchCustomer()
# 2 Roger 0912345678 550101 測資
