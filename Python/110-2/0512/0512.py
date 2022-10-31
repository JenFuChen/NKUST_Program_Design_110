from tkinter import *
from tkmacosx import Button
from random import randint as rand
import tkinter
import random
import re

root = Tk()
root.title("猜字遊戲")

########## 處理資料 ##########
data = list()
f = open("input.txt", mode='r')
data = f.read().splitlines()
f.close()
for i in range(len(data)):
    data.insert(i, data[i].split(' '))
    if(i != len(data)):
        data.pop(i+1)
#############################

counter = 0
correctAns = []
englishContent = tkinter.StringVar(root, '')
chineseContent = tkinter.StringVar(root, '')
ansContent = tkinter.StringVar(root, '答對題數：'+str(counter))
content = StringVar()
contentFuck = StringVar(root, '')
labelWidth = 25
labelHeight = 2
buttonWidth = 100
buttonHeight = 40
fontSize = 18
fontB = 'bold'
罵人 = ['恭喜欸^^', '哇～你真棒', '真厲害呢！', '恭喜老爺賀喜夫人', '給你拍拍手']
損人 = ['北七＋＋', '這都不會？', '你這白癡==', '請加油好嗎？', '該撞牆了']

########## 點擊動作 ##########


def click(event):
    print('user Input = ', entry.get())
    print('Clicked')
    global counter, correctAns
    customAns = entry.get()
    if(customAns == correctAns):
        counter += 1
        ansContent.set('答對題數：'+str(counter))
        contentFuck.set(罵人[rand(0, 4)])
        data.pop(num)
    else:
        contentFuck.set('')
    # print(data)
    print('------------')
    randomWord()
    entry.delete(0, END)

########## 處理字串 ##########


def processString(txt):
    global randTxt
    runtime = random.randint(20, 40)
    for i in range(runtime):
        randLetter = chr(random.randint(ord('a'), ord('z')))
        txt = re.sub(randLetter, 'x', txt)
    randTxt = txt
    print("Processed String = ", randTxt)

########## 隨機挑選 ##########


def randomWord():
    print('Random----------')
    global correctAns, num
    num = random.randint(0, len(data)-1)
    correctAns = data[num][0]
    print('correctAns = ', correctAns)
    processString(correctAns)
    englishContent.set('英文：'+randTxt)
    chineseContent.set('中文：'+data[num][1])


def showAns():
    print('Show Answer')
    englishContent.set(correctAns)


########## 顯示畫面 ##########
english = Label(root, textvariable=englishContent,
                width=labelWidth, height=labelHeight)
chinese = Label(root, textvariable=chineseContent,
                width=labelWidth, height=labelHeight)
answer = Label(root, textvariable=ansContent,
               width=labelWidth, height=labelHeight)
entry = Entry(root, textvariable=content)
confirm = Button(root, text='Enter', fg='white', bg='#3E4149',
                 width=buttonWidth, height=buttonHeight, command=lambda: click())
empty = Label(root, textvariable=contentFuck, width=labelWidth, height=1)
show = Button(root, text='Show', fg='white', bg='#010101',
              width=buttonWidth, height=buttonHeight, command=lambda: showAns())

entry.bind('<Return>', click)

layout = list()
layout.append(english)
layout.append(chinese)
layout.append(answer)
layout.append(entry)
layout.append(empty)
layout.append(confirm)
layout.append(show)
for i in range(len(layout)):
    layout[i].grid(row=i)
    layout[i]["font"] = ("arial", fontSize, fontB)


randomWord()
root.mainloop()
