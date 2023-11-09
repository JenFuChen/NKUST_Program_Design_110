# Edge Detection
# CH 7

import cv2
import numpy as np
from matplotlib import pyplot as plt

print("LOAD FILE...")
ig = cv2.imread("1030.jpg", 0)
image = ig.copy()
image2 = cv2.imread("1030.jpg", 1)

median_5 = cv2.medianBlur(image, 5)
ret, th = cv2.threshold(median_5, 0, 255, cv2.THRESH_OTSU)

# Gray > Otsu > Laplaussion 
# gray_image = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)
# hist = cv2.equalizeHist(median_5)
# median_5 = cv2.medianBlur(median_5, 5)
# hist = cv2.equalizeHist(median_5)

# Gaussian Blur Filter
# gaussian = cv2.GaussianBlur(hist, (5, 5), 3)

# Custom Median Blur Filter
size = image2.shape  # [ rows, columns, channels ]
imgY = size[0]  # rows
imgX = size[1]  # columns
Custom_Median_Image = image2.copy()
for y in range(1, imgY - 1):
    for x in range(1, imgX - 1):
        # create a array includes 8 pixel of current pixel
        pixel = []
        # Mask I : 9 x 9 Square
        pixel.append(Custom_Median_Image[y - 1][x - 1])  # 1
        pixel.append(Custom_Median_Image[y - 1][x])  # 2
        pixel.append(Custom_Median_Image[y - 1][x + 1])  # 3
        pixel.append(Custom_Median_Image[y][x - 1])  # 4
        pixel.append(Custom_Median_Image[y][x])  # 5
        pixel.append(Custom_Median_Image[y][x + 1])  # 6
        pixel.append(Custom_Median_Image[y + 1][x - 1])  # 7
        pixel.append(Custom_Median_Image[y + 1][x])  # 8
        pixel.append(Custom_Median_Image[y + 1][x + 1])  # 9

        # Function II : Get middle num
        for i in range(0, 9):
            for j in range(i + 1, 9):
                if pixel[i][0] > pixel[j][0]:
                    temp = pixel[i]
                    pixel[i] = pixel[j]
                    pixel[j] = temp

        mid = pixel[4]

        Custom_Median_Image[y][x] = mid

ret2, th2 = cv2.threshold(Custom_Median_Image, 0, 255, cv2.THRESH_OTSU)
# Canny Filter: Edge Detection

# Canny_1 = cv2.Canny(image, 90, 100)
# Canny_2 = cv2.Canny(image, 60, 150)


image = cv2.cvtColor(ig, cv2.COLOR_BGR2RGB)
# Output the result
plt.subplot(151)
plt.imshow(image)
plt.title("Original")

plt.subplot(152)
plt.hist(image.ravel(), 256, [0, 256])
plt.plot([130, 130], [0, 2000], label=str(ret))
plt.legend()
plt.title("OTSU_Threhold")

plt.subplot(153)
plt.imshow(th, "gray")
plt.title("OTSU")


plt.subplot(154)
plt.hist(Custom_Median_Image.ravel(), 256, [0, 256])
plt.plot([130, 130], [0, 2000], label=str(ret2))
plt.legend()
plt.title("OTSU_Threhold _ 2")

plt.subplot(155)
plt.imshow(th2, "gray")
plt.title("OTSU 2")

# plt.subplot(223)
# plt.imshow(Custom_Median_Image)
# plt.title("Custom Median")

# plt.subplot(224)
# plt.imshow(Canny_2)
# plt.title("Canny 2")

plt.show()
