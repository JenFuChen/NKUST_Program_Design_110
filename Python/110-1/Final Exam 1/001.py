# 輸入三變數，對現有系統時間相加並輸出
import time
timeList = ["%H", "%M", "%S"]
nowTime = [0, 0, 0]
updateTime = [0, 0, 0]
while(1):
    data = input()
    data = data.split()
    if(int(data[0]) == 0 and int(data[1]) == 0 and int(data[2]) == 0):
        break
    print("now time:", end='')
    print(time.strftime('%H:%M:%S'))
    for i in range(3):
        nowTime[i] = int(time.strftime(timeList[i]))
    for i in range(3):
        updateTime[i] = nowTime[i] + int(data[i])
    temp2 = updateTime[2]//60  # SS
    temp1 = updateTime[1]//60  # MM
    temp0 = updateTime[0]//24  # HH
    if(updateTime[2] > 59):
        updateTime[2] = updateTime[2] - 60*temp2
        updateTime[1] = updateTime[1] + 1*temp2
    if(updateTime[1] > 59):
        updateTime[1] = updateTime[1]-60*temp1
        updateTime[0] = updateTime[0]+1*temp1
    if(updateTime[0] > 23):
        updateTime[0] = updateTime[0]-24*temp0
    print("update time:", end='')
    if(updateTime[0] < 10):
        print('0', end='')
        print(updateTime[0], end=':')
    else:
        print(updateTime[0], end=':')
    if(updateTime[1] < 10):
        print('0', end='')
        print(updateTime[1], end=':')
    else:
        print(updateTime[1], end=':')
    if(updateTime[2] < 10):
        print('0', end='')
        print(updateTime[2], end=':')
    else:
        print(updateTime[2])
