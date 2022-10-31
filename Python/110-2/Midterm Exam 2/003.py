# 配對遊戲
from tkinter import *
import tkinter
import random
import time
from threading import Timer

root = Tk()
root.title("配對遊戲")
contentVar = tkinter.StringVar(root, '成功配對次數：'+str(0))
displayButton = Button(root, fg='white', bg='#3E4149', textvariable=contentVar,
                       width=50, height=2)
displayButton.grid(row=11, column=0, columnspan=10)
reset = Button(root, fg='white', bg='#CD4B1D', text='Reset',
               width=50, height=2, command=lambda: reset_btn())
reset.grid(row=12, column=0, columnspan=10)
buttonList = []
empty = []


def reset_btn():
    global buttonList, empty, token, token2, token1, counter, first, second
    buttonList = []
    empty = []
    layout()
    random_Num()
    token = 0
    token1 = -1
    token2 = -1
    counter = 0
    first = 0
    second = 0
    contentVar.set('成功配對次數：'+str(counter))


def layout():
    height = 2
    width = 5
    for i in range(100):
        row = int(i/10)
        col = i % 10
        buttonList.append(StringVar())
        empty.append(Button(root, textvariable=buttonList[i],
                            width=width, height=height, command=lambda n=i: click(n)))
        empty[i].grid(row=row+1, column=col)


layout()
temp = []
index = []
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
        buttonList[i].set('')
        index.append(n)


random_Num()

token = 0
token1 = -1
token2 = -1
counter = 0
first = 0
second = 0
first_1=0
second_2=0

def click(n):
    print("Clicked-----")
    global token1, token2, token, counter, first, second, first_1, second_2
    buttonList[n].set(str(index[n]))
    if(token == 0):
        token1 = index[n]
        first = n
        token = 1
    
    elif(token == 1 and n != first):
        token2 = index[n]
        second = n
        token = 2
    print('Token1 = ',token1,"Token2 = ", token2)
    if(token1 == token2 and first != second):
        empty[first].config(state="disabled")
        empty[second].config(state="disabled")
        token = 0
        first = 0
        second = 0
        counter += 1
        token1 = -1
        token2 = -1
    elif(first == second):
        print()
    elif((token1 != token2 and token == 2)):
        empty[first].config(state="normal")
        empty[second].config(state="normal")
        first_1=first
        second_2=second
        timeGo()
        token = 0
        token1 = -1
        token2 = -1
        first = 0
        second = 0
    contentVar.set("成功配對次數："+str(counter))
    if(counter == 50):
        contentVar.set("恭喜完成！")
        reset_btn()

def hidden():
    global first_1, second_2,buttonList
    print('Clean')
    buttonList[first_1].set('')
    buttonList[second_2].set('')
    t.cancel()

def timeGo():
    print('Time count')
    t = Timer(1, hidden)
    t.start()

t = Timer(1, hidden)
    



root.mainloop()
