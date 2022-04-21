from threading import Timer
import time

def hello():
    print("Hello World!")

t = Timer(5, hello) # 在5秒後，自動執行 hello()
t.start()

for i in [1, 2, 3, 4, 5, 6]:
    print(i)
    time.sleep(1)