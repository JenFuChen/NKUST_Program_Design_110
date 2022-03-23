# Caculator
from re import I, L
from tkinter import *
import tkinter
from aem import con
from click import command
from sqlalchemy import column

root = Tk()
root.title("Caculator")
Index = Button()
contentVar = tkinter.StringVar(root, '')
IndexVar = tkinter.StringVar(root, '')

# 顯示運算式按鈕框
displayButton = Button(root, textvariable=contentVar,
                       width=23, height=3, bg="white")
displayButton.grid(row=0, column=0, columnspan=4)
contentVar.set("開始遊戲")

# 設定各種變數
Player = 1
checkWin = 0
counter = 0
side = 3
buttonList = list()
Player1 = []
Player2 = []
IndexList = []
# 贏的情況
rowWin = []
colWin = []
slashWin = 0


def show():
    global side
    n = side
    for i in range(n):
        for j in range(n):
            print(Player1[i][j], end=" ")
        print()
    print("--1--")
    for i in range(n):
        for j in range(n):
            print(Player2[i][j], end=" ")
        print()
    print("--2--")
    for i in range(n):
        for j in range(n):
            print(IndexList[i][j], end=" ")
        print()
    print("--3--")


def createPlay(n):
    global Player1, Player2, IndexList
    Player1 = []
    Player2 = []
    IndexList = []
    for i in range(n):
        temp = []
        for j in range(n):
            temp.append(0)
        Player1.append(temp)
        Player2.append(temp)
        IndexList.append(temp)

    for i in range(side*side):
        buttonList[i].set('')
    show()


createPlay(3)


def FillIn(token, x, y, z):
    global Player, checkWin, counter, Player1, Player2, buttonList, side
    print("(", x, ",", y, "), Index = ", z)
    show()
    if(IndexList[x][y] == 0):
        if (Player == 1):
            IndexList[x][y] = 1
            Player1[x][y] = z + 1
            buttonList[z].set('X')
            Player = 2
        elif (Player == 2):
            IndexList[x][y] = 1
            buttonList[z].set('O')
            Player2[x][y] = z + 1
            Player = 1
        content = "換玩家" + str(Player)
        contentVar.set(content)
        counter += 1
    else:
        if(token == 0):
            contentVar.set("請按別的地方！")
        elif(token == 1):
            contentVar.set("Restart")
    winJudge(Player1, 1)
    winJudge(Player2, 2)
    if(checkWin == 0 and counter == 9):
        contentVar.set("【 Tie 】")
        createPlay(side)
    if(checkWin == 1 or counter == 9 or checkWin == 2 or token == 1):
        counter = 0
        checkWin = 0
        createPlay()


def winCondition():
    temp = 0
    global rowWin, colWin, side, slashWin, checkWin
    rowWin = []
    colWin = []
    slashWin = 0
    for i in range(1, side+1):
        temp += i
    for i in range(side):
        rowWin.append(temp)
        temp += side*side
    temp = 0
    leftCorner = side*side - side + 1
    for i in range(1, leftCorner+1, side):
        temp += i
    for i in range(side):
        colWin.append(temp)
        temp += side
    temp = 0
    for i in range(1, side*side, (side+1)):
        temp += i
    SlashWin = temp
    print("rolWin ", rowWin, ", colWin ", colWin, ", slashWin ", slashWin)


def winJudge(Player, num):
    winCondition()
    global checkWin, side, rowWin, colWin, slashWin
    sumRow, sumCol, sumSlash_L, sumSlash_R = 0, 0, 0, 0
    for i in range(side):
        for j in range(side):
            sumRow = sumRow + Player[i][j]  # 橫排相加
            sumCol = sumCol + Player[j][i]  # 直排相加
            sumSlash_R = sumSlash_R + Player[i][j]  # 左斜 \
            sumSlash_L = sumSlash_L + Player[i][j-i]  # 右斜 /
        print(" R: ", sumRow, ",C: ", sumCol, ",S_L:",
              sumSlash_L, ",S_R:", sumSlash_R)
        if(sumRow == rowWin[i] or sumCol == colWin[i] or sumSlash_L == slashWin or sumSlash_R == slashWin):
            content = "Player " + str(num) + "Win!"
            contentVar.set(content)
            checkWin = num


def layout(n):
    print("關卡：", n)
    createPlay(n)
    height = 4
    width = 5
    for i in range(n*n):
        row = int(i/n)
        col = i % n
        buttonList.append(StringVar())
        Index = Button(root, textvariable=buttonList[i],
                       width=width, height=height,
                       command=lambda x=row, y=col, z=i, t=0: FillIn(t, x, y, z))
        Index.grid(row=row+1, column=col)


def expand():
    global side
    side += 1
    layout(side)


layout(side)

Button(root, text="Restart ", width=5,
       height=5, command=lambda: FillIn(1, 0, 0, 0)).grid(row=10)

Button(root, text="下一關 ", width=5, height=4,
       command=lambda: expand()).grid(row=10, column=2)


root.mainloop()
