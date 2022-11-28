# 打地鼠遊戲
from tkinter import *
import tkinter
from click import command
import random
from tkmacosx import Button
import time

root = Tk()
root.title("猜帽子")

scoreVar = tkinter.StringVar(root, '得分：')
stageVar = tkinter.StringVar(root, '關卡：' + str(1))

stageBar = Button(root, fg='white', bg='#3E4149', textvariable=stageVar,
                  width=150, height=50)
stageBar.grid(row=11, column=0, columnspan=3)

reset = Button(root, fg='white', bg='#CD4B1D', text='Reset',
               width=150, height=50, command=lambda: reset_btn())
reset.grid(row=14, column=0, columnspan=3)

scoreBar = Button(root, fg='white', bg='#22843B', textvariable=scoreVar,
                  width=150, height=50)
scoreBar.grid(row=13, column=0, columnspan=3)


scoreBar["font"] = ("arial", 12, "bold")
reset["font"] = ("arial", 12, "bold")
#stageBar["font"] = ("arial", 12, "bold")

buttonList = []
empty = []
score = 0
stage = 1
counter = 3
temp = []
index = []


def reset_btn():
    print("Reset----------")
    global buttonList, empty, stage, counter
    counter = 3
    stage += 1
    stageVar.set('關卡：' + str(stage))
    buttonList = []
    empty = []
    layout()
    random_Num()


def random_Num():
    print("Create random Gophers----------")
    global index, temp, counter
    numGophers = random.randint(0, 2)
    counter = 3
    temp = []
    index = []
    for i in range(3):
        if(i == numGophers):
            temp.append('O')
        else:
            temp.append('X')
        n = temp.pop(random.randint(0, (len(temp)-1)))
        buttonList[i].set('')
        index.append(n)


def click(n):
    print('-----Clicked----')
    global counter, score, empty
    if(index[n] == 'O'):
        index[n] = ''
        counter -= 1
        score += 1
        buttonList[n].set('O')
        empty[n].config(state="pressed")
        scoreVar.set('得分：'+str(score))
        time.sleep(0.5)
        reset_btn()
    elif(index[n] == 'X'):
        index[n] = ''
        counter -= 1
        score -= 1
        buttonList[n].set('X')
        empty[n].config(state="pressed")
        scoreVar.set('得分：'+str(score))
    if(counter == 0):
        reset_btn()


def layout():
    print("Creating Game----------")
    global empty, buttonList
    height = 50
    width = 50
    for i in range(3):
        row = int(i/3)
        col = i % 3
        buttonList.append(StringVar())
        empty.append(Button(root, textvariable=buttonList[i],
                            width=width, height=height, command=lambda n=i: click(n)))
        empty[i].grid(row=row+1, column=col)


layout()
random_Num()
root.mainloop()
