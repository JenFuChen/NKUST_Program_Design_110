# 配對遊戲
from tkinter import *
import tkinter
from click import command
import random
from tkmacosx import Button

root = Tk()
root.title("配對遊戲")
contentVar = tkinter.StringVar(root, '剩餘次數'+str(50))
displayButton = Button(root, fg='white', bg='#3E4149', textvariable=contentVar,
                       width=500, height=50, borderless=1)
displayButton.grid(row=11, column=0, columnspan=10)
reset = Button(root, fg='white', bg='#CD4B1D', text='Reset',
               width=500, height=50, borderless=1, command=lambda: reset_btn())
reset.grid(row=12, column=0, columnspan=10)
buttonList = []
empty = []
temp = []
index = []

def reset_btn():
    global buttonList, empty, token, token2, token1, counter, first, second
    buttonList = []
    empty = []
    layout()
    random_Num()
    token = 0
    token1 = -1
    token2 = -1
    counter = 50
    first = 0
    second = 0
    contentVar.set('剩餘次數：'+str(counter))


def layout():
    height = 50
    width = 50
    for i in range(100):
        row = int(i/10)
        col = i % 10
        buttonList.append(StringVar())
        empty.append(Button(root, textvariable=buttonList[i], borderless=1,
                            width=width, height=height, command=lambda n=i: click(n)))
        empty[i].grid(row=row+1, column=col)


layout()
# make random list


def random_Num():
    global index, temp
    temp = []
    index = []
    for i in range(10):
        for j in range(10):
            temp.append(i)
    for i in range(100):
        n = temp.pop(random.randint(0, (len(temp)-1)))
        buttonList[i].set(n)
        index.append(n)


random_Num()

token = 0
token1 = -1
token2 = -1
counter = 50
first = 0
second = 0


def click(n):
    print("Clicked-----")
    global token1, token2, token, counter, first, second
    print(index[n])
    if(token == 0):
        token1 = index[n]
        first = n
        token = 1
        print("Token1 = ", token1, "\tPlace = ", first)
    elif(token == 1):
        token2 = index[n]
        second = n
        token = 2
        print("Token2 = ", token2, "\tPlace = ", second)
    if(token1 == token2 and first != second):
        buttonList[first].set('')
        buttonList[second].set('')
        empty[first].config(state="disabled")
        empty[second].config(state="disabled")
        token = 0
        first = 0
        second = 0
        counter -= 1
        token1 = -1
        token2 = -1
    elif((token1 != token2 and token == 2) or first == second):
        empty[first].config(state="normal")
        empty[second].config(state="normal")
        token = 0
        token1 = -1
        token2 = -1
        first = 0
        second = 0
    contentVar.set("剩餘次數："+str(counter))
    if(counter == 0):
        contentVar.set("恭喜完成！")
        reset_btn()


root.mainloop()
