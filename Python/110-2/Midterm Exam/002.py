# 顯示按鈕位置
from tkinter import *
import tkinter
from tkmacosx import Button


root = Tk()
root.title("按鈕位置")  # 視窗標題

row = 5
Button_1 = Button()
contentVar = tkinter.StringVar(root, '')
buttonList = list()


def show(n, m):
    contentVar.set('Row = ' + str(n) + ' Column = ' + str(m))


displayButton = Button(root, fg='white', bg='#3E4149', textvariable=contentVar,
                       width=250, height=50)
displayButton.grid(row=6, column=0, columnspan=5)


def layout(n):
    height = 50
    width = 50
    for i in range(n*n):
        row = int(i/n)
        col = i % n
        buttonList.append(StringVar())
        Index = Button(root, textvariable=buttonList[i],
                       width=width, height=height,
                       command=lambda x=row, y=col: show(x, y))
        Index.grid(row=row+1, column=col)


layout(5)
root.mainloop()
