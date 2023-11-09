import cv2
import numpy as np
import scipy.special as sp
import matplotlib.pyplot as plt

ig = cv2.imread(r"C:\Users\lin39\Desktop\PY\IR\w5\warriors.jpg",0)

med = cv2.medianBlur(ig, 7)

ret,th = cv2.threshold(med, 240, 255, cv2.THRESH_OTSU)

med2 = cv2.medianBlur(th, 9)
# med2 = cv2.medianBlur(th, 7)

can1 = cv2.Canny(med2, 60, 100)
can2 = cv2.Canny(th, 60, 100)

cv2.imshow("med",med)
cv2.imshow("med2",med2)
cv2.imshow("can1",can1) 
cv2.imshow("can2",can2) 
cv2.imshow("gray",th)
cv2.waitKey(0)