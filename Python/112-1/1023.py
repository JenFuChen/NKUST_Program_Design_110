import cv2
import numpy as np
import scipy.special as sp

# Read the Image
img = cv2.imread("Pic_1.png", 0)
img2 = cv2.imread("Pic_1.png", 0)
img3 = cv2.imread("Pic_1.png", 0)
# Width and length of image
w = img.shape[0]
l = img.shape[1]
cv2.imshow("Original", img)

mean_filtered = cv2.blur(img, (3, 3))
seqs = np.linspace(0, 1, 270)
lt = np.round(sp.betainc(2.5, 2.5, seqs) * 255, 0)
for i in range(w):
    for j in range(l):
        img2[i, j] = lt[mean_filtered[i, j]]

mean_filtered1 = cv2.blur(img2, (3, 3))
cv2.imshow("1", mean_filtered1)
for i in range(w):
    for j in range(l):
        img3[i, j] = lt[mean_filtered1[i, j]]


cv2.imshow("lt3", img3)
cv2.waitKey(0)
cv2.destroyAllWindows()
