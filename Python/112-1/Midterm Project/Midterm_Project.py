# Edge Detection
# CH 7


import cv2
import numpy as np
from matplotlib import pyplot as plt
https://irs.thsrc.com.tw/IMINT/captImg/ocD3SzEE3J.jpg
https://irs.thsrc.com.tw/IMINT/captImg/kJvFeaAYza.jpg
original_image = cv2.imread("image/test1.jpg", 1)

# Blur Once
Gaussian_Blur_Image = cv2.GaussianBlur(original_image, (5, 5), 3)

# Custom Arithmetic Blur Filter 算術平均數
size = Gaussian_Blur_Image.shape  # [ rows, columns, channels ]
imgY = size[0]  # rows
imgX = size[1]  # columns
Custom_Arithmetic_Image = Gaussian_Blur_Image.copy()

for y in range(1, imgY - 1):
    for x in range(1, imgX - 1):
        # create an array includes 8 pixel of current pixel
        pixel = []
        # Mask I : 9 x 9 Square
        # ( Alternative function: Create a unrule container to collect pixel, developing... )
        pixel.append(Custom_Arithmetic_Image[y - 1][x - 1])  # 1
        pixel.append(Custom_Arithmetic_Image[y - 1][x])  # 2
        pixel.append(Custom_Arithmetic_Image[y - 1][x + 1])  # 3
        pixel.append(Custom_Arithmetic_Image[y][x - 1])  # 4
        pixel.append(Custom_Arithmetic_Image[y][x])  # 5
        pixel.append(Custom_Arithmetic_Image[y][x + 1])  # 6
        pixel.append(Custom_Arithmetic_Image[y + 1][x - 1])  # 7
        pixel.append(Custom_Arithmetic_Image[y + 1][x])  # 8
        pixel.append(Custom_Arithmetic_Image[y + 1][x + 1])  # 9

        # Function I : Get arithmetic mean
        arithmetic = 0
        for i in range(0, len(pixel) * 3):
            arithmetic += int(pixel[i // 3][i % 3])
        arithmetic = arithmetic // (len(pixel) * 3)
        Custom_Arithmetic_Image[y][x] = arithmetic

        # Function II : Get middle num( cv2.medianBlur) the same

        # for i in range(0, 9):
        #     for j in range(i + 1, 9):
        #         if pixel[i][0] > pixel[j][0]:
        #             temp = pixel[i]
        #             pixel[i] = pixel[j]
        #             pixel[j] = temp
        # mid = pixel[4]
        # Custom_Median_Image[y][x] = mid

# Blur third time
Median_Blur_image = cv2.medianBlur(Custom_Arithmetic_Image, 5)

# OTSU
image_copy = cv2.cvtColor(Median_Blur_image, cv2.COLOR_RGB2GRAY)
ret, th = cv2.threshold(image_copy, 200, 255, cv2.THRESH_OTSU)

# Sobel
x_abs = cv2.convertScaleAbs(cv2.Sobel(th, cv2.CV_64F, 1, 0, 3))
y_abs = cv2.convertScaleAbs(cv2.Sobel(th, cv2.CV_64F, 0, 1, 3))

Sobel_Image = cv2.addWeighted(x_abs, 0.5, y_abs, 0.5, 0)
Sobel_Image = cv2.cvtColor(Sobel_Image, cv2.COLOR_RGB2BGR)

# Blur fourth time
Median_Blur_image = cv2.medianBlur(th, 3)
Median_Blur_image = cv2.cvtColor(Median_Blur_image, cv2.COLOR_RGB2BGR)

# OTSU
image_copy = cv2.cvtColor(Median_Blur_image, cv2.COLOR_RGB2GRAY)
ret, th = cv2.threshold(image_copy, 200, 255, cv2.THRESH_OTSU)

# Laplacian
laplacian_image = cv2.Laplacian(th, cv2.CV_64F, ksize=3)
Laplacian_image = cv2.convertScaleAbs(laplacian_image)
Laplacian_image = cv2.cvtColor(Laplacian_image, cv2.COLOR_RGB2BGR)

cv2.imwrite("Laplacian Edge Detection.jpg", Laplacian_image)

plt.figure(figsize=(25, 5))
plt.xlabel("X", fontsize=14)  # 调整x轴标签文字大小
plt.ylabel("Y", fontsize=14)  # 调整y轴标签文字大小

plt.subplot(161)
plt.imshow(original_image)
plt.title("original")

plt.subplot(162)
plt.imshow(Custom_Arithmetic_Image)
plt.title("Custom Arithmetic Blur")

plt.subplot(163)
plt.imshow(Sobel_Image)
plt.title("Sobel")

plt.subplot(164)
plt.imshow(Median_Blur_image)
plt.title("Median Blur")

plt.subplot(165)
plt.imshow(th, "gray")
plt.title("OTSU")

plt.subplot(166)
plt.imshow(Laplacian_image)
plt.title("Laplacian Edge")

plt.savefig("Output.jpg")
plt.show()
