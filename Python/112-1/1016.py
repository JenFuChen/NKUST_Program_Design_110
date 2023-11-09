import cv2
import numpy as np
import matplotlib.pyplot as plt

ig = cv2.imread("Hi.jpg")
ig2 = ig.copy()


# 把通道直方圖等化
for channel in range(3):
    ig2[:, :, channel] = cv2.equalizeHist(ig2[:, :, channel])

B = cv2.calcHist([ig2], [0], None, [256], [0, 256])
G = cv2.calcHist([ig2], [1], None, [256], [0, 256])
R = cv2.calcHist([ig2], [2], None, [256], [0, 256])

plt.plot(B)
plt.plot(G)
plt.plot(R)

cv2.imshow("Hi", ig)
cv2.imshow("Hi-fixed", ig2)
plt.show()
cv2.waitKey(0)
