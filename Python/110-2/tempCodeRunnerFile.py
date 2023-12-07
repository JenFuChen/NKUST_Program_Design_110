# 顯示運算式按鈕框
displayButton = Button(root, textvariable=contentVar,
                       width=23, height=3, bg="white")
displayButton.grid(row=0, column=0, columnspan=4)
contentVar.set("開始遊戲")