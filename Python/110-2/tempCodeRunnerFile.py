# Caculator
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
Player = 1
checkWin = 0
counter = 0

Player1 = [[0, 0, 0],
           [0, 0, 0],
           [0, 0, 0]]

Player2 = [[0, 0, 0],
           [0, 0, 0],
           [0, 0, 0]]

IndexList = [['-', '-', '-'],
             ['-', '-', '-'],
             ['-', '-', '-']]


# 顯示運算式按鈕框
displayButton = Button(root, textvariable=contentVar,
                       width=23, height=3, bg="white")
displayButton.grid(row=0, column=0, columnspan=4)

contentVar.set("開始遊戲")


def FillIn(x, y, z):
    global Player, checkWin, counter
    global Player1, Player2
    print("X = ", x, ", Y = ", y, ", Index = ", z)
    if(IndexList[x][y] == '-'):
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
        contentVar.set("請按別的地方！")
    winJudge_P1()
    winJudge_P2()
    if(checkWin == 1):
        contentVar.set("【 Player 1 Win ! 】")
    if(checkWin == 2):
        contentVar.set("【 Player 2 Win ! 】")
    if(checkWin == 0 and counter == 9):
        contentVar.set("【 Tie 】")
    if(checkWin == 1 or counter == 9 or checkWin == 2 or checkWin == 3):
        counter = 0
        checkWin = 0
        for i in range(9):
            Player1[int(i/3)][i % 3] = 0
            Player2[int(i/3)][i % 3] = 0
            IndexList[int(i/3)][i % 3] = '-'
            buttonList[i].set('')


def winJudge_P1():
    global checkWin
    rowWin = [6, 15, 24]
    colWin = [12, 15, 18]
    for i in range(3):
        if(Player1[i][0] + Player1[i][1] + Player1[i][2]) == rowWin[i]:
            contentVar.set("Player 1 Win!")
            checkWin = 1
        if(Player1[0][i] + Player1[1][i] + Player1[2][i]) == colWin[i]:
            contentVar.set("Player 1 Win!")
            checkWin = 1
    if(Player1[0][0] + Player1[1][1] + Player1[2][2]) == 15:
        contentVar.set("Player 1 Win!")
        checkWin = 1
    if(Player1[0][2] + Player1[1][1] + Player1[2][0]) == 15:
        contentVar.set("Player 1 Win!")
        checkWin = 1


def winJudge_P2():
    global checkWin
    rowWin = [6, 15, 24]
    colWin = [12, 15, 18]
    for i in range(3):
        if(Player2[i][0] + Player2[i][1] + Player2[i][2]) == rowWin[i]:
            contentVar.set("Player 2 Win!")
            checkWin = 2
        if(Player2[0][i] + Player2[1][i] + Player2[2][i]) == colWin[i]:
            contentVar.set("Player 2 Win!")
            checkWin = 2
    if(Player2[0][0] + Player2[1][1] + Player2[2][2]) == 15:
        contentVar.set("Player 2 Win!")
        checkWin = 2
    if(Player2[0][2] + Player2[1][1] + Player2[2][0]) == 15:
        contentVar.set("Player 2 Win!")
        checkWin = 2


height = 4
width = 5
buttonList = list()
side = 3
for i in range(side*side):
    row = int(i/side)
    col = i % side
    buttonList.append(StringVar())
    Index = Button(root, textvariable=buttonList[i],
                   width=width, height=height,
                   command=lambda x=row, y=col, z=i: FillIn(x, y, z))
    Index.grid(row=row+1, column=col)

Button(root, text="Restart ", width=width,
       height=height, command=checkWin == 3).grid(row=7,)
Button(root, text="下一關 ", width=width, height=height,
       command=side+1).grid(row=7, column=2)
root.mainloop()
