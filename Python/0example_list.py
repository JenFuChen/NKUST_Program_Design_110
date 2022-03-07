# rotation test
from tkinter import *
window = Tk()
window.title("test5")
window.geometry("800x800+700+200")
n = int(input())
for i in range(1, 2*n):
    for j in range(1, 2*n):
        distx = abs(n-i)  # 絕對座標
        disty = abs(n-j)
        Label(window, text=max(distx, disty)+1,
              font=('Arial', 20)).grid(row=i, column=j)
        print("{},{}".format(distx, disty), end=' ')
    print()

mainloop()
