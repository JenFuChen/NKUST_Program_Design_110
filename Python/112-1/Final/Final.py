"""
！請使用Mac跑，部分套件轉換成windows會失效跑不起來!


組別：
C110152302 林致葳
C110152317 徐瑋辰
C110152319 陳人輔
C110152341 王彥傑
"""


import cv2
import pytesseract
import tkinter as tk
import numpy as np
import PIL.Image
import tkinter
from PIL import Image
from PIL import ImageTk
from tkinter import *
from matplotlib import pyplot as plt

max_num = 5
root = Tk()
root.title("車牌辨識")
root.geometry("800x620")
Index = Button()
contentVar = tkinter.StringVar(root, "")

displayButton = Button(
    root, textvariable=contentVar, width=15, height=1, font=("Helvetica", 30)
)
displayButton.grid(row=0, column=0, columnspan=8)


tk_img_original = None
tk_img_result = None
tk_img_recognition = None
tk_img_01 = None
tk_img_02 = None
tk_img_03 = None
tk_img_04 = None
tk_img_05 = None
tk_img_06 = None
tk_img_07 = None
tk_img_08 = None

current_image_index = 1


def load_image(index):
    global tk_img_original, tk_img_result, tk_img_recognition, tk_img_01, tk_img_02, tk_img_03, tk_img_04, tk_img_05, tk_img_06, tk_img_07, tk_img_08
    path = "image/" + str(index) + ".jpg"
    contentVar.set("第 " + str(index) + " 張圖片")
    OCR(path)

    original_image = cv2.imread(path)
    result_image = cv2.imread("Result.jpg")

    tk_img_original = ImageTk.PhotoImage(
        PIL.Image.fromarray(
            np.uint8(cv2.cvtColor(original_image, cv2.COLOR_BGR2RGB))
        ).resize((400, 300))
    )

    tk_img_result = ImageTk.PhotoImage(
        PIL.Image.fromarray(
            np.uint8(cv2.cvtColor(result_image, cv2.COLOR_BGR2RGB))
        ).resize((400, 300))
    )

    original_label.config(image=tk_img_original)
    result_label.config(image=tk_img_result)

    cropped_1 = cv2.imread("ig_0.jpg")
    tk_img_01 = ImageTk.PhotoImage(
        PIL.Image.fromarray(
            np.uint8(cv2.cvtColor(cropped_1, cv2.COLOR_BGR2RGB))
        ).resize((50, 100))
    )
    cropped_label_1.config(image=tk_img_01)103
    

    cropped_2 = cv2.imread("ig_1.jpg")
    tk_img_02 = ImageTk.PhotoImage(
        PIL.Image.fromarray(
            np.uint8(cv2.cvtColor(cropped_2, cv2.COLOR_BGR2RGB))
        ).resize((50, 100))
    )
    cropped_label_2.config(image=tk_img_02)

    cropped_3 = cv2.imread("ig_2.jpg")
    tk_img_03 = ImageTk.PhotoImage(
        PIL.Image.fromarray(
            np.uint8(cv2.cvtColor(cropped_3, cv2.COLOR_BGR2RGB))
        ).resize((50, 100))
    )
    cropped_label_3.config(image=tk_img_03)

    cropped_4 = cv2.imread("ig_3.jpg")
    tk_img_04 = ImageTk.PhotoImage(
        PIL.Image.fromarray(
            np.uint8(cv2.cvtColor(cropped_4, cv2.COLOR_BGR2RGB))
        ).resize((50, 100))
    )
    cropped_label_4.config(image=tk_img_04)

    cropped_5 = cv2.imread("ig_4.jpg")
    tk_img_05 = ImageTk.PhotoImage(
        PIL.Image.fromarray(
            np.uint8(cv2.cvtColor(cropped_5, cv2.COLOR_BGR2RGB))
        ).resize((50, 100))
    )
    cropped_label_5.config(image=tk_img_05)

    cropped_6 = cv2.imread("ig_5.jpg")
    tk_img_06 = ImageTk.PhotoImage(
        PIL.Image.fromarray(
            np.uint8(cv2.cvtColor(cropped_6, cv2.COLOR_BGR2RGB))
        ).resize((50, 100))
    )
    cropped_label_6.config(image=tk_img_06)

    cropped_7 = cv2.imread("ig_6.jpg")
    tk_img_07 = ImageTk.PhotoImage(
        PIL.Image.fromarray(
            np.uint8(cv2.cvtColor(cropped_7, cv2.COLOR_BGR2RGB))
        ).resize((50, 100))
    )
    cropped_label_7.config(image=tk_img_07)


def save_cropped_images(cropped_images):  # 保存圖像
    paths = []
    for index, img in enumerate(cropped_images):
        path = "ig_" + str(index) + ".jpg"  # 命名為ig_0、ig_1、ig_2、ig_3
        cv2.imwrite(path, img)
        paths.append(path)
    return paths


def OCR(path):
    print("----------------------------")
    global recognition_text
    # path = "image/" + str(current_image_index) + ".jpg"
    # originalImage = cv2.imread(path, 1)
    img = cv2.imread(path)
    dtr = cv2.CascadeClassifier("car_plate.xml")
    print("\n===== LOADING IMAGES =====")
    print("\n===== START PROCESS =====")
    pos = dtr.detectMultiScale(img, scaleFactor=1.2, minNeighbors=5, minSize=(50, 50))
    # print(pos)

    for x, y, w, h in pos:
        # print(x, y, h, w)
        cv2.rectangle(img, (x, y), (x + w, y + h), (50, 100, 150), 2, 4, 0)

    # cv2.imshow("Fill BOX", img)
    image = img[y + 2 : y + h - 2, x : x + w]
    # print(image.shape[0], image.shape[1])
    image = cv2.resize(image, (image.shape[1] * 300 // image.shape[0], 300))
    # print(image.shape[0], image.shape[1])
    # image = cv2.resize(image,(100,160))
    # cv2.imshow("cut", image)

    # print("Turning to Gray ...")
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    # cv2.imshow("gray",gray)
    # print("Median Blur ...")
    median = cv2.medianBlur(gray, 3)
    # cv2.imshow("median",median)
    # print("Binary...")
    _, th = cv2.threshold(median, 120, 255, cv2.THRESH_BINARY_INV)
    # cv2.imshow("threshold",th)

    cts = cv2.findContours(th, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    regs = []

    ig = image
    # 框出車牌文字
    for cs in cts[0]:
        (x, y, w, h) = cv2.boundingRect(cs)
        if h <= 250 and h >= 200:
            regs.append((x, y, w, h))
            cv2.rectangle(ig, (x, y), (x + w, y + h), (255, 0, 0), 2)
            # cv2.imshow("Contours", ig)
        # print(regs)

    sorted_regs = sorted(regs, key=lambda x: x[0])

    for x, y, w, h in sorted_regs:
        cv2.rectangle(ig, (x, y), (x + w, y + h), (255, 0, 0), 2)
    # cv2.imshow("Contours", ig)

    cv2.imwrite("Result.jpg", ig)

    cropped_images = []

    zoom = 0
    for x, y, w, h in sorted_regs:
        cropped_image = th[y - zoom : y + h + zoom, x - zoom : x + w + zoom]
        cropped_images.append(cropped_image)
    cropped_image_paths = save_cropped_images(cropped_images)

    for i in range(7):
        path = "ig_" + str(i) + ".jpg"
        old = cv2.imread(path)
        bolder = 30
        BLACK = [0, 0, 0]
        new = cv2.copyMakeBorder(
            old, bolder, bolder, bolder, bolder, cv2.BORDER_CONSTANT, value=BLACK
        )
        cv2.imwrite(path, new)

    print("\n===== PROCESS DONE =====")
    # 辨識文字
    print("\n===== DETECTING =====")
    image = cv2.imread("Result.jpg")
    full_text = pytesseract.image_to_string(
        image,
        lang="eng",
        config="-c tessedit_char_whitelist=0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ --psm 7",
    )
    print("\n[Single Line]: ", end="")
    print(full_text)

    # Cut image detect
    detect_text = []
    for i in range(7):
        path_ig = "ig_" + str(i) + ".jpg"
        image = cv2.imread(path_ig)
        if i < 3:
            text = pytesseract.image_to_string(
                image,
                lang="eng",
                config="-c tessedit_char_whitelist=ABCDEFGHIJKLMNOPQRSTUVWXYZ --psm 10",
            )
        else:
            text = pytesseract.image_to_string(
                image,
                lang="eng",
                config="-c tessedit_char_whitelist=0123456789 --psm 10",
            )
        print("[ig_" + str(i) + "]: " + text.replace("\n", ""), end="")
        cleaned_text = "".join(text.replace("\n", ""))
        detect_text.append(cleaned_text)
        print()
    result_detect = "".join(detect_text)
    print("[Cut]: ", end="")

    print(result_detect)
    print("\n===== DONE =====")
    recognition_text.config(text=result_detect)


def next_image():
    global current_image_index
    if current_image_index >= max_num:
        current_image_index = current_image_index
    else:
        current_image_index += 1
    load_image(current_image_index)


def prev_image():
    global current_image_index
    if current_image_index <= 1:
        current_image_index = current_image_index
    else:
        current_image_index -= 1
    load_image(current_image_index)


original_label = tk.Label(root)
original_label.grid(row=1, column=0, columnspan=4)

result_label = tk.Label(root)
result_label.grid(row=1, column=4, columnspan=4)


cropped_label_1 = tk.Label(root)
cropped_label_1.grid(row=2, column=0)

cropped_label_2 = tk.Label(root)
cropped_label_2.grid(row=2, column=1)

cropped_label_3 = tk.Label(root)
cropped_label_3.grid(row=2, column=2)

cropped_label_4 = tk.Label(root)
cropped_label_4.grid(row=2, column=3)

cropped_label_5 = tk.Label(root)
cropped_label_5.grid(row=2, column=4)

cropped_label_6 = tk.Label(root)
cropped_label_6.grid(row=2, column=5)

cropped_label_7 = tk.Label(root)
cropped_label_7.grid(row=2, column=6)

cropped_label_8 = tk.Label(root)
cropped_label_8.grid(row=2, column=7)


recognition_text = tk.Label(root, text="", font=("Helvetica", 30))
recognition_text.grid(row=3, column=0, columnspan=8)

prev_button = tk.Button(
    root, text="上一張", command=prev_image, width=7, height=2, font=("Helvetica", 30)
)
prev_button.grid(row=4, column=0, padx=10, pady=10, columnspan=4)

next_button = tk.Button(
    root, text="下一張", command=next_image, width=7, height=2, font=("Helvetica", 30)
)
next_button.grid(row=4, column=4, padx=10, pady=10, columnspan=4)

# 初始載入第一張圖片
load_image(current_image_index)

root.mainloop()
