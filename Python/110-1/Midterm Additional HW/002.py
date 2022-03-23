# 002 找出檔案內6 ＆ 11 的公倍數
f = open("input.txt", mode='r')
for line in f.readlines():
    num = int(line)
    if(num % 6 == 0 and num % 11 == 0):
        print(num)
f.close()
