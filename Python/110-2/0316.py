# Caculator
from tkinter import *
import tkinter

from sqlalchemy import column

root = Tk()
root.title("Caculator")
Index = Button()
contentVar = tkinter.StringVar(root, '')
IndexVar = tkinter.StringVar(root, '')
Player = 1

Player1 = [['-', '-', '-'],
           ['-', '-', '-'],
           ['-', '-', '-']]

Player2 = [['-', '-', '-'],
           ['-', '-', '-'],
           ['-', '-', '-']]

EmptyList = [[0, 0, 0],
             [0, 0, 0],
             [0, 0, 0]]

IndexList = [['-', '-', '-'],
             ['-', '-', '-'],
             ['-', '-', '-']]

winPatterns = [[0, 1, 2],
               [3, 4, 5],
               [6, 7, 8],
               [0, 3, 6],
               [1, 4, 7],
               [2, 5, 8],
               [0, 4, 8],
               [2, 4, 6]]

# 顯示運算式按鈕框
displayButton = Button(root, textvariable=contentVar,
                       width=23, height=3, bg="white")
displayButton.grid(row=0, column=0, columnspan=4)

contentVar.set("開始遊戲")


def isWinner(bo, le) :

    return ((bo[7] == le and bo[8] == le and bo[9] == le) or
            (bo[4] == le and bo[5] == le and bo[6] == le) or
            (bo[1] == le and bo[2] == le and bo[3] == le) or
            (bo[7] == le and bo[4] == le and bo[1] == le) or
            (bo[8] == le and bo[5] == le and bo[2] == le) or
            (bo[9] == le and bo[6] == le and bo[3] == le) or
            (bo[7] == le and bo[5] == le and bo[3] == le) or
            (bo[9] == le and bo[5] == le and bo[1] == le))


def FillIn(x, y, z):
    global Player
    global Player1, Player2, EmptyList
    print("X = ", x, ", Y = ", y, ", Index = ", z)
    if(IndexList[x][y] == '-'):
        if (Player == 1):
            Player1[x][y] = z
            IndexList[x][y] = 'X'
            Player = 2
        elif (Player == 2):
            Player2[x][y] = z
            IndexList[x][y] = 'O'
            Player = 1
        content = "換玩家" + str(Player)
        contentVar.set(content)
    else:
        contentVar.set("請按別的地方！")
    print("玩家1")
    for i in range(3):
        for j in range(3):
            print(" ", Player1[i][j], end='')
        print()
    print("玩家2")
    for i in range(3):
        for j in range(3):
            print(" ", Player2[i][j], end='')
        print()
    print("遊戲圖")
    for i in range(3):
        for j in range(3):
            print(" ", IndexList[i][j], end='')
        print()


for i in range(9):
    ButtonList = [[]]
    row = int(i/3)
    col = i % 3
    height = 4
    width = 5
    # temp = Button(root, textvariable='', width=width, height=height,
    # command=lambda x=row, y=col, z=i: FillIn(x, y, z))
    # ButtonList.append('0')
    #ButtonList[row][col].grid(row=row+1, column=col)

    Index = Button(root, textvariable=EmptyList[row][col],
                   width=width, height=height,
                   command=lambda x=row, y=col, z=i: FillIn(x, y, z))
    Index.grid(row=row+1, column=col)

root.mainloop()
