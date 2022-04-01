from tkinter import *
root = Tk()
# Tk 內的 Image 只能引入 PNG
logo = PhotoImage(file="Python/IMG_0730.jpeg")
Label(root, image=logo).pack(side="right")

Label(root, text="KUAS").pack(side="left")
root.mainloop()
