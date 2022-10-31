# 視窗寫法
from tkinter import *

root = Tk()
root.title("巴斯卡三角形")  # 視窗標題

num = int(input("Please input a positive number : "))
row = num + 1

list = []
for n in range(num+1):
    list.append([])
    list[n].append(1)
    for m in range(1, n):
        list[n].append(list[n - 1][m - 1] + list[n - 1][m])
    if(num != 0):
        list[n].append(1)

for i in range(row):
    for j in range(0, i+1):
        Label(root, text=str(list[i][j])).place(x=40*j + (num-i)*20, y=40*i)
        # 點好之前產生label物件，產生之後執行函式".pack"
        # 定位點 RIGHT BOTTOM LEFT TOP

root.mainloop()
