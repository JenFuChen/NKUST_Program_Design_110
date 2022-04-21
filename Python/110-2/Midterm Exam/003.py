# 【Finished】ＯＯＸＸ 進化版
from tkinter import *
import tkinter
from click import command
from tkmacosx import Button

root = Tk()
root.title("OOXX三人版")
Index = Button()
contentVar = tkinter.StringVar(root, '')
#IndexVar = tkinter.StringVar(root, '')

# 顯示運算式按鈕框
displayButton = Button(root, textvariable=contentVar,
                       width=200, height=50, bg="white")
displayButton.grid(row=0, column=0, columnspan=4)
contentVar.set("開始遊戲")

# 設定各種變數
player = 1
counter = 0
side = 4
buttonList = list()
IndexList = []
cause = 0
start = 0


def show():
    global side
    n = side
    print("--Index--")
    for i in range(n):
        for j in range(n):
            print(IndexList[i][j], end=" \t")
        print()


def layout(n):
    print("關卡：", n)
    height = 50
    width = 50
    for i in range(n*n):
        row = int(i/n)
        col = i % n
        buttonList.append(StringVar())
        Index = Button(root, textvariable=buttonList[i],
                       width=width, height=height,
                       command=lambda x=row, y=col, z=i, t=0: FillIn(t, x, y, z))
        Index.grid(row=row+1, column=col)


def createPlay(n):
    global cause
    print("[ Reset The Game] ")
    if(cause == 1):
        print("Start Game")
    elif(cause == 2):
        print("Cause Win Judge")
    elif(cause == 3):
        print("Cause Counter")
    elif(cause == 4):
        print("Cause Token")
    global IndexList
    IndexList = []
    for i in range(n):
        temp = []
        for j in range(n):
            temp.append(0)
        IndexList.append(temp)

    for i in range(side*side):
        buttonList[i].set('')
    show()


layout(side)
createPlay(side)
show()


def FillIn(token, x, y, z):
    global player, counter, buttonList, side, start, cause
    if(start == 0):
        createPlay(side)
        start = 1
    print("(", x, ",", y, "), Index = ", z, "Player is ", player)
    if(IndexList[x][y] == 0):
        if (player == 1):
            print("Filled Player1")
            IndexList[x][y] = 1
            buttonList[z].set('X')
        elif (player == 2):
            print("Filled Player2")
            IndexList[x][y] = -1
            buttonList[z].set('O')
        elif (player == 3):
            print("Filled Player3")
            IndexList[x][y] = 10
            buttonList[z].set('!')
        if(player == 1):
            player = 2
        elif(player == 2):
            player = 3
        else:
            player = 1
        content = "換玩家" + str(player)
        contentVar.set(content)
        counter += 1
    else:
        if(token == 0):
            contentVar.set("請按別的地方！")
        elif(token == 1):
            contentVar.set("Restart")

    if(counter == side*side or token == 1):
        counter = 0
        player = 1
        if(token == 1):
            contentVar.set("Restart")
            cause = 4
        else:
            cause = 3
            contentVar.set("【 Tie 】")
        createPlay(side)

    show()
    winJudge(IndexList)


def winJudge(list):
    global side, player, cause, counter
    sumRow, sumCol, sumSlash_L, sumSlash_R = 0, 0, 0, 0
    P1_Win = side
    P2_Win = 0 - side
    P3_Win = 40

    for i in range(side):
        for j in range(side):
            sumRow = sumRow + list[i][j]  # 橫排相加
            sumCol = sumCol + list[j][i]  # 直排相加
            sumSlash_R = sumSlash_R + list[j][j]  # 左斜 \
            sumSlash_L = sumSlash_L + list[j][side-j-1]  # 右斜 /
        print("R:", sumRow, "\t C:", sumCol, "\t S_R \ :",
              sumSlash_R, "\t S_L \ :", sumSlash_L)
        if(sumRow == P1_Win or sumCol == P1_Win or sumSlash_L == P1_Win or sumSlash_R == P1_Win) and (player == 2):
            content = "Player " + str(1) + " Win!"

            contentVar.set(content)
            cause = 2
            counter = 0
            createPlay(side)
        elif(sumRow == P2_Win or sumCol == P2_Win or sumSlash_L == P2_Win or sumSlash_R == P2_Win) and (player == 3):
            content = "Player " + str(2) + " Win!"
            contentVar.set(content)
            cause = 2
            counter = 0
            createPlay(side)
        elif(sumRow == P3_Win or sumCol == P3_Win or sumSlash_L == P3_Win or sumSlash_R == P3_Win) and (player == 1):
            content = "Player " + str(3) + " Win!"
            contentVar.set(content)
            cause = 2
            counter = 0
            createPlay(side)
        sumRow, sumCol, sumSlash_L, sumSlash_R = 0, 0, 0, 0


Button(root, text="Restart ", width=5,
       height=5, command=lambda: FillIn(1, 0, 0, 0)).grid(row=10)

root.mainloop()
