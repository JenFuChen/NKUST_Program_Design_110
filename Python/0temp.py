def adddocument():
    test = 1
    for x in range(len(data)-1, -1, -1):
        if(active[1] == data[x][0]):
            print("Exist")
            test = 2
    if(test == 1):
        data.append(active[1:5])
    # print(data)


def deletedocument():
    test = 1
    for x in range(len(data)-1, -1, -1):
        if(active[1] == data[x][0]):
            data.remove(data[x][0:4])
            test = 2
    if(test == 1):
        print("None")
    # print(data)
    print("document delete")


def changedocument(msg):
    print("document change")


def viewdocument():
    test = 1
    for x in range(len(data)-1, -1, -1):
        if(active[1] == data[x][0]):
            if(active[2] == '0'):
                print(data[x][1])
            if(active[2] == '1'):
                print(data[x][2])
            if(active[2] == '2'):
                print(data[x][3])
            test = 2
    if(test == 1):
        print("None")


data = []
while True:
    active = input()
    active = active.split()
    if(active[0] == "*"):
        break
    else:
        if(active[0] == '@'):
            adddocument()
        if(active[0] == '#'):
            deletedocument()
        if(active[0] == '!'):
            changedocument()
        if(active[0] == '$'):
            # print(data)
            viewdocument()
        if(active[0] == '1'):
            print(data)
