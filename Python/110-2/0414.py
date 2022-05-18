# 打地鼠遊戲
from tkinter import *
import tkinter
from click import command
import random
from tkmacosx import Button
from threading import Timer
import time


root = Tk()
root.title("打地鼠遊戲")

contentVar = tkinter.StringVar(root, '地鼠數量' + '')
scoreVar = tkinter.StringVar(root, '得分：')
stageVar = tkinter.StringVar(root, '關卡：' + str(1))

btnWidth = 500
btnHeight = 50
# 設定顯示文字區
displayButton = Button(root, fg='white', bg='#3E4149', textvariable=contentVar,
                       width=btnWidth, height=btnHeight)
displayButton.grid(row=12, column=0, columnspan=10)

stageBar = Button(root, fg='white', bg='#3E4149', textvariable=stageVar,
                  width=btnWidth, height=btnHeight)
stageBar.grid(row=11, column=0, columnspan=10)

reset = Button(root, fg='white', bg='#CD4B1D', text='Reset',
               width=btnWidth, height=btnHeight,  command=lambda: reset_btn())
reset.grid(row=14, column=0, columnspan=10)

scoreBar = Button(root, fg='white', bg='#22843B', textvariable=scoreVar,

                  width=btnWidth, height=btnHeight,)
scoreBar.grid(row=13, column=0, columnspan=10)


scoreBar["font"] = ("arial", 12, "bold")
reset["font"] = ("arial", 12, "bold")
displayButton["font"] = ("arial", 12, "bold")
#stageBar["font"] = ("arial", 12, "bold")

buttonList = []
empty = []
score = 0
stage = 1
temp = []
index = []


def reset_btn():
    print("Reset----------")
    global buttonList, empty, counter, time1, stage
    time1.cancel()
    time1 = Timer(2, reset_btn)
    stage += 1
    stageVar.set('關卡：' + str(stage))
    buttonList = []
    empty = []
    layout()
    random_Num()
    time1.start()


time1 = Timer(2, reset_btn)


def layout():
    print("Creating Game----------")
    global empty, buttonList
    height = 50
    width = 50
    for i in range(100):
        row = int(i/10)
        col = i % 10
        buttonList.append(StringVar())
        empty.append(Button(root, textvariable=buttonList[i],
                            width=width, height=height, command=click(i)))

    print("Len----------")
    print(len(buttonList))




def random_Num():
    print("Create random Gophers----------")
    global index, temp, counter
    numGophers = random.randint(1, 10)
    counter = numGophers
    contentVar.set('地鼠數量：' + str(numGophers))
    temp = []
    index = []
    for i in range(10):
        for j in range(10):
            if(i*j < numGophers and numGophers >= 0):
                temp.append('凸')
                numGophers -= 1
            else:
                temp.append('')
    for i in range(100):
        n = temp.pop(random.randint(0, (len(temp)-1)))
        buttonList[i].set(n)
        index.append(n)





def click(n):
    print('-----Clicked----')
    global counter, score
    if(index[n] == '凸'):
        counter -= 1
        score += 1
        buttonList[n].set('')
        contentVar.set('地鼠數量：' + str(counter))
        scoreVar.set('得分：'+str(score))
    if(counter == 0):
        reset_btn()


def timeReset():
    global time1
    print("【 Time Clock-------- 】")
    time1.start()


layout()
timeReset()
random_Num()

root.mainloop()
