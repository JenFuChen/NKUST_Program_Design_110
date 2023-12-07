import cv2
import pytesseract
import numpy as np

# 設定 Tesseract OCR 的執行路徑，如果不需要可以註解掉
# pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract.exe'

# 讀取影像檔案
image = cv2.imread(r"C:\Users\lin39\Desktop\PY\IR\w7\image1.jpg")

# 將影像轉換為灰階
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# 對灰階影像進行中值模糊處理，以減少噪點
median = cv2.medianBlur(gray, 3)

# 使用不同的二值化方法處理影像
_, th2 = cv2.threshold(median, 50, 255, cv2.THRESH_BINARY)
_, th1 = cv2.threshold(median, 0, 255, cv2.THRESH_OTSU)

# 將兩種二值化影像進行權重合併，以增強文字特徵
th = cv2.addWeighted(th1, 0.8, th2, 0.2, 0)

# 使用 2x2 的核心進行膨脹操作，以填充文字區域
kernel = np.ones((2, 2))
dil = cv2.dilate(th1, kernel)

# 使用 Tesseract OCR 偵測影像中的文字框
boxes = pytesseract.image_to_boxes(dil)

# 初始化最小 x、最大 h、最大 w、最小 y 的值
min_x, max_h = image.shape[1], 0
max_w, min_y = 0, image.shape[0]

# 顯示初始化的值
print(min_x, min_y, max_w, max_h)

# 迭代處理每個文字框
for box in boxes.splitlines():
    b = box.split(" ")
    x, y, w, h = int(b[1]), int(b[2]), int(b[3]), int(b[4])

    # 顯示每個文字框的座標和大小
    print(x, y, w, h, "\n")

    # 更新最小 x、最大 h、最大 w、最小 y 的值
    min_x, max_h = min(min_x, x), max(max_h, h)
    max_w, min_y = max(max_w, w), min(min_y, y)

    # 顯示更新後的值
    print(min_x, min_y, max_w, max_h)

# 繪製矩形框以標示文字區域
cv2.rectangle(
    image,
    (min_x, image.shape[0] - min_y),
    (max_w, image.shape[0] - max_h),
    (0, 255, 0),
    2,
)

# 顯示處理後的影像
cv2.imshow("result", image)

# 等待使用者按下任意鍵後關閉視窗
cv2.waitKey(0)
cv2.destroyAllWindows()
