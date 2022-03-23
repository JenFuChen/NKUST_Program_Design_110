# Caculator
from tkinter import *
import tkinter

from nbformat import read

root = Tk()
root.title("Caculator")
Button_1 = Button()
contentVar = tkinter.StringVar(root, '')

# 顯示運算式按鈕框
displayButton = Button(root, textvariable=contentVar,
                       width=33, height=3, bg="white")
displayButton.grid(row=0, column=0, columnspan=4)

png_papper = PhotoImage(file=r"./IMG_0730.jpeg")
papper = Button(image=png_papper)
papper.bind("<Button-1>")

root.mainloop()
