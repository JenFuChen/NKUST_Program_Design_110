from tkinter import *
import tkinter
import random
import time
from threading import Timer
from tkmacosx import Button
import os
print('-------')
cwd = os.getcwd()
print(cwd)
print('------')
root = Tk()
root.title("麻阿台")
contentVar = tkinter.StringVar(root, 'ＧＯ')


displayButton = Button(root, fg='white', bg='#3E4149', textvariable=contentVar,
                       width=100, height=50, command=lambda: click())
displayButton.grid(row=3, column=3, columnspan=2)

displayButton = Button(root, fg='white', bg='#EA5532', text='Reset',
                       width=100, height=50, command=lambda: stop())
displayButton.grid(row=4, column=3, columnspan=2)

buttonList = []
empty = []
temp = []
width = 50
height = 50
cnt = 0
pictureList = [r"apple.png",
               r"betelnut.png",
               r"double7.png",
               r"grape.png",
               r"orange.png",
               r"ring.png",
               r"star.png",
               r"watermelon.png"]

# 外框陣列
squarelist = [0, 1, 2, 3, 4, 5, 6, 7,
              15, 23, 31, 39, 47, 55,
              63, 62, 61, 60, 59, 58, 57, 56,
              48, 40, 32, 24, 16, 8]

speed = [0.1, 0.3, 0.5, 0.7, 0.9]


def click():
    global time1, cnt
    print("Click\t----------")
    time1.start()
    for i in squarelist:
        cnt = i


def stop():
    time1.cancel()
    print("Stop\t----------")


runtimes = 0
before = 0
after = 0


def run():
    global time1, runtimes, before, after, s, cnt
    time1.cancel()
    runtimes += 1
    if(runtimes > 35):
        stop()
        runtimes = 0
    else:
        before = after
        if(cnt >= len(squarelist)-1):
            cnt = 0
        else:
            cnt += 1
        after = cnt
        empty[squarelist[before]].configure(bg='#FFFFFF')
        empty[squarelist[after]].configure(bg='#EA5560')

        # 控制速度
        if(runtimes > 30):
            s = 4
        elif(runtimes > 24):
            s = 3
        elif(runtimes > 18):
            s = 2
        elif(runtimes > 10):
            s = 1
        elif(runtimes > 0):
            s = 0
        time1 = Timer(speed[s], run)
        time1.start()
        print("before = ", before, "after = ", after)


time1 = Timer(speed[0], run)


def reset_btn():
    print("Reset\t----------")
    global buttonList, empty
    buttonList = []
    empty = []
    randomPic()
    layout()


def randomPic():
    for i in range(64):
        num = random.randint(0, 7)
        buttonList.append(PhotoImage(file=pictureList[num]))


def layout():
    print("Create\t----------")
    global temp, width, height, cnt
    for i in range(64):
        row = int(i/8)
        col = i % 8
        if(row == 0 or row == 7 or col == 0 or col == 7):
            empty.append(
                Button(root, image=buttonList[i], width=width, height=height))
        else:
            empty.append(Label(root))
            if(row == 3 and (col == 3 or col == 4)):
                empty[i].configure(bg='#3E4149')
            if(row == 4 and (col == 3 or col == 4)):
                empty[i].configure(bg='#EA5532')
        empty[i].grid(row=row, column=col)


reset_btn()

root.mainloop()
