# Edge Detection
# CH 7

import cv2
import numpy as np
from matplotlib import pyplot as plt

original_image = cv2.imread("1030.jpg", 1)


Bilateral_image = cv2.bilateralFilter(original_image, 100, 30, 30)

Median_Blur_image = cv2.medianBlur(Bilateral_image, 7)

image_copy = cv2.cvtColor(Median_Blur_image, cv2.COLOR_RGB2GRAY)

# OTSU
ret, th = cv2.threshold(image_copy, 240, 255, cv2.THRESH_OTSU)

Median_Blur_image = cv2.medianBlur(th, 7)
Median_Blur_image = cv2.cvtColor(Median_Blur_image, cv2.COLOR_RGB2GRAY)

laplacian_image = cv2.Laplacian(Median_Blur_image, cv2.CV_64F, ksize=3)
Laplacian_image = cv2.convertScaleAbs(laplacian_image)

Laplacian_image = cv2.cvtColor(Laplacian_image, cv2.COLOR_RGB2BGR)


plt.hist(image_copy.ravel(), 256, [0, 256])


plt.subplot(151)
plt.imshow(original_image)
plt.title("original")

plt.subplot(152)
plt.imshow(Bilateral_image)
plt.title("Bilateral")


plt.subplot(153)
plt.imshow(Median_Blur_image)
plt.title("Median Blur")

plt.subplot(154)
plt.imshow(th, "gray")
plt.title("OTSU")

plt.subplot(155)
plt.imshow(Laplacian_image)
plt.title("Laplacian Edge")

plt.show()
