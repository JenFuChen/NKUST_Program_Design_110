# Caculator
from tkinter import *
import tkinter

root = Tk()
root.title("Caculator")
Button_1 = Button()
contentVar = tkinter.StringVar(root, '')


buttonList = [
    ['C', '//', '*', '-'],
    ['7', '8', '9', '+'],
    ['4', '5', '6'],
    ['1', '2', '3', '='],
    ['0', '.']]


def caculateFunc(inputStr):
    operation = ('+', '-', '*', '//')
    content = contentVar.get()
    print("get = ", inputStr, "\n")
    if(inputStr in '0123456789.'):
        content += inputStr
    elif(inputStr in operation):
        content += inputStr
    elif(inputStr == 'C'):
        content = ''
    elif(inputStr == '='):
        content = str(eval(content))
    contentVar.set(content)


# 顯示運算式按鈕框
displayButton = Button(root, textvariable=contentVar,
                       width=33, height=3, bg="white")
displayButton.grid(row=0, column=0, columnspan=4)

for i in range(5):
    for j in range(len(buttonList[i])):
        col = j
        get_str = buttonList[i][j]

        if((i == 1 and j == 3) or (i == 3 and j == 3)):  # + =
            rowpan = 2
            colpan = 1
            height = 9
            width = 5
        elif((i == 4 and j == 0)):  # 0
            colpan = 2
            rowpan = 1
            width = 14
            height = 4
        elif((i == 4 and j == 1)):  # ..
            col = j+1
            colpan = 1
            rowpan = 1
            width = 5
            height = 4
        else:
            colpan = 1
            rowpan = 1
            width = 5
            height = 4

        Button_1 = Button(root, text=buttonList[i][j],
                          width=width, height=height,
                          command=lambda x=get_str: caculateFunc(x), bg="orange")
        Button_1.grid(row=i+1, column=col, rowspan=rowpan, columnspan=colpan)

root.mainloop()
