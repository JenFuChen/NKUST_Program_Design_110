from tkinter import *
from turtle import update
from tkmacosx import Button
from random import randint as rand
import tkinter as tk

root = Tk()
root.title('資料表')
root.geometry("250x300")

# Dealing Data


def loadData():
    global data
    f = open('input.txt', mode='r')
    data = []

    data = f.read().splitlines()
    f.close()
    for i in range(len(data)):
        data.insert(i, data[i].split(' '))
        if(i != len(data)):
            data.pop(i+1)
    print(data) 
##########


loadData()
# print(data)

# Set constant
height = 2
width = 5
num = 0
sex = StringVar()
token = 0

# Creating Layout
Label(root, text='學號：', height=height,
                 width=width).grid(column=0, row=0)
Label(root, text='姓名：', height=height,
      width=width).grid(column=0, row=1)
male = Radiobutton(root, text="男", variable=sex, value=1)
female = Radiobutton(root, text="女", variable=sex, value=2)
Label(root, text='系所：', height=height,
      width=width).grid(column=0, row=3)
Label(root, text='地址：', height=height,
      width=width).grid(column=0, row=4)
Label(root, text=' 電話：', height=height,
      width=width).grid(column=0, row=5)
before = Button(root, text='<<', height=50,
                width=50, command=lambda: next(1)).place(x=0, y=230)
changeB = Button(root, text='更新', height=50,
                 width=50, command=lambda: update()).place(x=50, y=230)
deleteB = Button(root, text='刪除', height=50,
                 width=50, command=lambda: delete()).place(x=100, y=230)
createB = Button(root, text='新增', height=50,
                 width=50, command=lambda: new()).place(x=150, y=230)
after = Button(root, text='>>', height=50,
               width=50, command=lambda: next(2)).place(x=200, y=230)
# reload = Button(root, text='重新載入資料', height=50,
#                 width=210, command=lambda: loading()).place(x=20, y=290)
schoolID = Entry(root)
name = Entry(root)
type1 = Entry(root)
address = Entry(root)
phone = Entry(root)
test = Entry(root)
schoolID.grid(column=1, row=0)
name.grid(column=1, row=1)
male.grid(column=0, row=2)
female.grid(column=1, row=2)
type1.grid(column=1, row=3)
address.grid(column=1, row=4)
phone.grid(column=1, row=5)


def next(token):
    global num
    if(token == 1):
        num -= 1
        if(num <= 0):
            num = num + len(data)
    elif(token == 2):
        num += 1

    if(num > len(data)-1 or num < 0):
        num = 0
    set(1)


def update():
    global token
    if(token != 2):
        token = 3
    new = []
    new.append(schoolID.get())
    new.append(name.get())
    num = sex.get()
    if(num == '1'):
        new.append("男")
    elif(num == '2'):
        new.append("女")
    new.append(type1.get())
    new.append(address.get())
    new.append(phone.get())
    space = ''
    for x in new:
        space += x + ' '
    space += '\n'
    ' '.join(map(str, space))
    print(space)
    print("----")
    updateFile(schoolID.get(), space)
    token = 1
    print()


def updateFile(old_str, new_str):
    global token
    file_data = ""
    print(old_str)
    with open('input.txt', "r", encoding="utf-8") as f:
        for line in f.readlines():
            if(token == 1):
                if (old_str in line):
                    line = line.replace(line, new_str)
            if(token == 3):
                if (old_str in line):
                    line = line.replace(line, new_str)
            file_data += line
    if(token == 2):
        new = []
        new.append(schoolID.get())
        new.append(name.get())
        num = sex.get()
        if(num == '1'):
            new.append("男")
        elif(num == '2'):
            new.append("女")
        new.append(type1.get())
        new.append(address.get())
        new.append(phone.get())
        space = '\n'
        for x in new:
            space += x + ' '
        ' '.join(map(str, space))
        file_data += space
        token = 1
    with open('input.txt', "w", encoding="utf-8") as f:
        f.write(file_data)
    loadData()


def delete():
    global token
    token = 1
    cnt = 0
    loadData()
    with open('input.txt', "r", encoding="utf-8") as f:
        for line in f.readlines():
            if (name.get() in line):
                num = cnt
            cnt += 1

    old = data[num][0]
    # space = ' '
    # for x in old:
    #     space += ' '+x
    # ' '.join(map(str, old))
    print(data[num])
    # print(space)
    updateFile(old, "")
    data.pop(num)
    loadData()
    set(1)


def new():
    global token, num
    token = 2
    set(2)


def set(choose):
    global num, schoolID, name, address, phone, type
    schoolID.delete(0, "end")
    name.delete(0, "end")
    type1.delete(0, "end")
    address.delete(0, "end")
    phone.delete(0, "end")
    if(choose == 1):
        schoolID.insert(0, data[num][0])
        name.insert(0, data[num][1])
        type1.insert(0, data[num][3])
        address.insert(0, data[num][4])
        phone.insert(0, data[num][5])
        if(data[num][2] == '男'):
            sex.set(1)
        elif(data[num][2] == '女'):
            sex.set(2)
    if(choose == 2):
        schoolID.insert(0, '')
        name.insert(0, '')
        type1.insert(0, '')
        address.insert(0, '')
        phone.insert(0, '')


set(1)
root.mainloop()
