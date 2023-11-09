import numpy as np
import cv2
from matplotlib import pyplot as plt

img = cv2.imread("Pic_2.jpg", 1)  # 預設就是1不用特別加
mask = cv2.imread("mask.jpg", 0)

ns = cv2.inpaint(img, mask, 5, cv2.INPAINT_NS)  # NS、TELEA兩種方式，擇一就行
telea = cv2.inpaint(img, mask, 5, cv2.INPAINT_TELEA)


# 輸出方式1
plt.subplot(221)  # 2*2的左上角
plt.imshow(img[:, :, ::-1])
# plt.imshow這個輸出方式，通道是相反的(RGB跟cv2.imshow的是反過來的)
plt.title("orig")
plt.subplot(222)  # 2*2的右上角
plt.imshow(mask)
plt.title("mask")
plt.subplot(223)  # 2*2的左下角
plt.imshow(ns[:, :, ::-1])
plt.title("NS")
plt.subplot(224)  # 2*2的右下角
plt.imshow(telea[:, :, ::-1])
plt.title("TELEA")
plt.tight_layout()
plt.show()

# 輸出方式2
# cv2.imshow('wire',img)
# cv2.imshow('TELEA',telea)
# cv2.waitKey(0)
# cv2.destroyAllWindows()
