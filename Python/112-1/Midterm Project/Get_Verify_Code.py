import cv2
import pytesseract
import numpy as np
from PIL import Image
from matplotlib import pyplot as plt


def save_cropped_images(cropped_images):  # 保存圖像
    paths = []
    for index, img in enumerate(cropped_images):
        path = "ig_" + str(index) + ".jpg"  # 命名為ig_0、ig_1、ig_2、ig_3
        cv2.imwrite(path, img)
        paths.append(path)
    return paths


path = "image/" + "2" + ".jpg"
originalImage = cv2.imread(path, 1)
image = cv2.imread(path, -1)
mask = cv2.imread(r"image/mask.jpg", -1)
print("Loading Files.")

length_ig = image.shape[0]
width_ig = image.shape[1]
length_mask = mask.shape[0]
width_mask = mask.shape[1]

print("Turning to Gray ...")
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

print("Median Blur ...")
median = cv2.medianBlur(gray, 3)

print("Binary...")  # To make the text white
_, th = cv2.threshold(median, 125, 255, cv2.THRESH_BINARY_INV)

# print(length_ig, width_ig)
# print(length_mask, width_mask)

print("Mask Cutting ...")
for i in range(length_mask):
    if (mask[i, width_mask - 1] == 255).any():
        x_mask = i
        break
for i in range(length_ig):
    if (th[i, width_ig - 1] == 255).any():
        x_ig = i
        break

max_x = x_ig if x_ig >= x_mask else x_mask
min_x = x_mask if x_ig >= x_mask else x_ig

max_width = width_mask if width_ig <= width_mask else width_ig
min_width = width_ig if width_ig <= width_mask else width_mask

max_length = length_mask if length_ig <= length_mask else length_ig
min_length = length_ig if length_ig <= length_mask else length_mask

mask_cut = mask[
    x_mask - min_x : x_mask - min_x + min_length - min_x,
    width_mask - min_width : width_mask,
]
th_cut = th[
    x_ig - min_x : x_ig - min_x + min_length - min_x,
    width_ig - min_width : width_ig,
]

length_cut = mask_cut.shape[0]
width_cut = mask_cut.shape[1]

th_copy = th_cut.copy()

for i in range(length_cut):
    for j in range(width_cut):
        if (mask_cut[i, j] == 255).any():
            if th_cut[i, j] == 0:
                th_copy[i, j] = 255
                # print(th_cut[i, j])
            else:
                th_copy[i, j] = 0

print("Mask Cut Finished.")

median1 = cv2.medianBlur(th_copy, 3)
kernel = np.ones((3, 3))
print("Opening Operation ...")
open = cv2.morphologyEx(median1, cv2.MORPH_OPEN, kernel, iterations=1)

# Turn to normal color
th_copy = cv2.cvtColor(th_copy, cv2.COLOR_RGB2BGR)
median1 = cv2.cvtColor(median1, cv2.COLOR_RGB2BGR)
open = cv2.cvtColor(open, cv2.COLOR_RGB2BGR)
# erode = cv2.erode(open, kernel)
result = 255 - open  # Reverse the text to black
scale = cv2.resize(result, (result.shape[1] * 1, result.shape[0] * 1))
print("Writing to file.")
cv2.imwrite("Result.jpg", scale)
# 開始切割成4份
gray_image = cv2.cvtColor(result, cv2.COLOR_BGR2GRAY)
_, binary_image = cv2.threshold(
    gray_image, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU
)  # 二值化

contours, _ = cv2.findContours(
    binary_image, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE
)  # 找輪廓

sorted_contours = sorted(contours, key=cv2.contourArea, reverse=True)[
    :4
]  # 避免存到小點點，所以取最大的四個輪廓

bounding_boxes = [cv2.boundingRect(contour) for contour in sorted_contours]  # 找出邊框

sorted_bounding_boxes = sorted(
    bounding_boxes, key=lambda b: b[0], reverse=False
)  # 這四個輪廓原本是由小排到大改成由左到右排

cropped_images = []

for idx, contour in enumerate(sorted_contours):
    x, y, w, h = sorted_bounding_boxes[idx]  # 會從 x 切到 x+w
    cropped_image = result[:, x : x + w]  # 切割圖像
    cropped_images.append(cropped_image)

cropped_image_paths = save_cropped_images(cropped_images)

# Full image detect
print("Detecting Text ...")
# 辨識文字
image = cv2.imread("Result.jpg")
text = pytesseract.image_to_string(
    image,
    lang="eng",
    config="-c tessedit_char_whitelist=0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ --psm 7",
)
print("[Single]: ", end="")
print(text)

# Cut image detect
detect_text = []
for i in range(4):
    path_ig = "ig_" + str(i) + ".jpg"
    image = cv2.imread(path_ig)
    text = pytesseract.image_to_string(
        image,
        lang="eng",
        config="-c tessedit_char_whitelist=0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ --psm 6",
    )
    print("[ig_" + str(i) + "]: " + text.replace("\n", ""), end="")
    cleaned_text = "".join(text.replace("\n", ""))
    detect_text.append(cleaned_text)
    print()
result_detect = "".join(detect_text)
print("[Cut]: ", end="")
print(result_detect)

plt.subplot(151)
plt.imshow(originalImage)
plt.title("Original")

plt.subplot(152)
plt.imshow(mask_cut)
plt.title("Mask")

plt.subplot(153)
plt.imshow(th_copy)
plt.title("Binary")

plt.subplot(154)
plt.imshow(median1)
plt.title("Median")

plt.subplot(155)
plt.imshow(result)
plt.title("Result")

plt.show()
