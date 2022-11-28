#002 輸入一數(>0)，並印出數字中為奇數的中文 例:12345 印出:一三五
while(1):
    data  = int(input())
    if(data < 0):
        break
    list = [0]
    while(data > 0):
        temp = data % 10
        data = data // 10
        list.append(temp)
    list.reverse()
    for i in range(len(list)):
        if(int(list[i]) %2 != 0):
            if(list[i] == 1):
                print('一',end = '')
            if(list[i] == 3):
                print('三',end = '')
            if(list[i] == 5):
                print('五',end = '')
            if(list[i] == 7):
                print('七',end = '')
            if(list[i] == 9):
                print('九',end = '')
    print()
