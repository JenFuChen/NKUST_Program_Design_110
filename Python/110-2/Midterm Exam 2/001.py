# 【Finished】Keyboard
from tkinter import *
import tkinter

root = Tk()
root.title("Keyboard")
Button_1 = Button()
contentVar = tkinter.StringVar(root, '')
buttonList = list()

def createKeyboard(n):
    global buttonList
    if(n==1):
        buttonList = [
            ['a', 'b', 'c', 'd','e','f','g'],
            ['h', 'i', 'j', 'k','l','m','n'],
            ['o', 'p', 'q', 'r','s','t','u'],
            ['v', 'w', 'x', 'y','z','切換','清除']]
    elif(n==2):
        buttonList = [
            ['A', 'B', 'C', 'D','E','F','G'],
            ['H', 'I', 'J', 'K','L','M','N'],
            ['O', 'P', 'Q', 'R','S','T','U'],
            ['V', 'W', 'X', 'Y','Z','切換','清除']]
    


createKeyboard(1)
switchKB = 1
def caculateFunc(inputStr):
    global switchKB
    content = contentVar.get()
    print("get = ", inputStr, "\n")
    if(inputStr in 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'):
        content += inputStr
    elif(inputStr == '切換'):
        if(switchKB == 1):
            switchKB = 2
        elif(switchKB == 2):
            switchKB = 1
        createKeyboard(switchKB)
        layout()
    if(inputStr == '清除'):
        content = ''
    contentVar.set(content)
# 顯示運算式按鈕框
displayButton = Button(root, fg='white', bg='#3E4149', textvariable=contentVar,
                       width=32, height=2)
displayButton.grid(row=0, column=0, columnspan=7)
displayButton["font"] = ("arial", 20, "bold")

def layout():
    global buttonList
    for i in range(4):
        for j in range(len(buttonList[i])):
            col = j
            get_str = buttonList[i][j]

            width = 7
            height = 3
            rowpan = 1
            colpan =1
            Button_1 = Button(root, text=buttonList[i][j], bg='#3E4149', fg='white',
                            width=width, height=height,
                            command=lambda x=get_str: caculateFunc(x))
            Button_1.grid(row=i+1, column=col, rowspan=rowpan, columnspan=colpan)
            Button_1["font"] = ("arial", 12, "bold")

layout()
root.mainloop()
