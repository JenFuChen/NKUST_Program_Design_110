from tkinter import *
from tkmacosx import Button
from random import randint as rand
import tkinter as tk

root = Tk()
root.title('資料表')
root.geometry("250x300")
'''
# def loading():
#     global data
#     data = []
#     f = open('input.txt', mode='r')
#     data = f.read().splitlines()
#     f.close()
#     for i in range(len(data)):
#         data.insert(i, data[i].split(' '))
#         if(i != len(data)):
#             data.pop(i+1)
'''

# Dealing Data
f = open('input.txt', mode='r')
data = f.read().splitlines()
f.close()
for i in range(len(data)):
    data.insert(i, data[i].split(' '))
    if(i != len(data)):
        data.pop(i+1)
##########

# print(data)

# Set constant
height = 2
width = 5
num = 0
sex = StringVar()

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
before = Button(root, text=' 前一筆', height=50,
                width=100, command=lambda: next(1)).place(x=20, y=230)
after = Button(root, text='下一筆', height=50,
               width=100, command=lambda: next(2)).place(x=130, y=230)
# reload = Button(root, text='重新載入資料', height=50,
#                 width=210, command=lambda: loading()).place(x=20, y=290)
schoolID = Entry(root)
name = Entry(root)
type = Entry(root)
address = Entry(root)
phone = Entry(root)
test = Entry(root)
schoolID.grid(column=1, row=0)
name.grid(column=1, row=1)
male.grid(column=0, row=2)
female.grid(column=1, row=2)
type.grid(column=1, row=3)
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
    set()


def set():
    global num, schoolID, name, address, phone, type
    schoolID.delete(0, "end")
    name.delete(0, "end")
    type.delete(0, "end")
    address.delete(0, "end")
    phone.delete(0, "end")

    schoolID.insert(0, data[num][0])
    name.insert(0, data[num][1])
    type.insert(0, data[num][3])
    address.insert(0, data[num][4])
    phone.insert(0, data[num][5])
    if(data[num][2] == '男'):
        sex.set(1)
    elif(data[num][2] == '女'):
        sex.set(2)


set()
root.mainloop()
