from tkinter import *
from tkmacosx import Button
from random import randint as rand
import tkinter
import random
from threading import Timer
import time


root = Tk()
root.title('TOD')

test = []
temp = []
gameLayout = []
game = []
width = 50
height = 50
newRow = []
StringVar(root, '')
for i in range(10):
    temp.append(StringVar(root, ' '))
    for j in range(10):
        game.append(temp)

for i in range(100):
    game[int(i/10)][i % 10].set('i')




def randomLayout():
    global time1, gameLayout
    print('-----')
    # time1.cancel()
    rand_x = rand(0, 9)
    for i in range(0, 10):
        if(i == rand_x):
            newRow.append(StringVar(root, 'Z'))
        else:
            newRow.append(StringVar(root, ''))
    game.insert(0, newRow)
    game.pop()
    gameLayout = []
    time1 = Timer(1, randomLayout())
    time1.start()


time1 = Timer(1, randomLayout)


def layout():
    global gameLayout
    for i in range(100):
        row = int(i / 10)
        col = i % 10
        gameLayout.append(
            Button(root, textvariable=game[row][col], height=height, width=width).grid(row=row, column=col))


layout()
time1.start()
root.mainloop()
