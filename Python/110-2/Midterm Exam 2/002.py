from tkinter import *
import tkinter
from random import randint


root = Tk()
root.title("剪刀石頭布")
Button_1 = Button()
contentVar = tkinter.StringVar(root, '')
buttonList = list()

displayButton = Button(root, fg='white', bg='#3E4149', textvariable=contentVar,
                       width=30, height=2)
displayButton.grid(row=0, column=0, columnspan=3)
displayButton["font"] = ("arial", 20, "bold")

buttonList = ['Y','O','W']
computerWin = 0
userWin = 0
tie = 0

def click(user):
    global computerWin, userWin, tie
    computer = buttonList[randint(0,2)]
    if(computer == 'O'):
        if(user == 'Y'):
            computerWin += 1
        elif(user == 'O'):
            tie +=1
        elif(user == 'W'):
            userWin += 1
    if(computer == 'W'):
        if(user == 'O'):
            computerWin += 1
        elif(user == 'W'):
            tie +=1
        elif(user == 'Y'):
            userWin += 1
    if(computer == 'Y'):
        if(user == 'W'):
            computerWin += 1
        elif(user == 'Y'):
            tie +=1
        elif(user == 'O'):
            userWin += 1
    contentVar.set('You:' + user + ', Computer:' + computer +'\nYou Win:' + str(userWin))



for i in range(3):
    col = i
    get_str = buttonList[i]

    width = 7
    height = 3
    Button_1 = Button(root, text=buttonList[i], bg='#3E4149', fg='white',
                            width=width, height=height,
                            command=lambda x=get_str: click(x))
    Button_1.grid(row=1,column=col)
    Button_1["font"] = ("arial", 12, "bold")


root.mainloop()