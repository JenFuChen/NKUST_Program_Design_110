num1 =  10.1
num2 = "hello"
num3 = 10
#name = input("請輸入您的名字： ")
print(type(num1))
print(type(num2))
print(type(num3))
#print("名字： ",name)
'''
f = open("test.txt","w") # w = 寫入 ; ../ 代表前一路徑的（相對）
print(1,2,3,file = f)
f.close()'''

file = open("test.txt","r") # r = 讀出 ; endcode = "UTF-8" 編碼格式
for counter in file:
    print(counter) #在後面加 end = '' 就不會換行，預設的print會換行
file.close()

# .real = 實數  ; .imag = 虛數
# ex: 10.5 ; .ral = 10 ; .imag = 0.5
