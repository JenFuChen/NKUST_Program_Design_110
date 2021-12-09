def transfer(num, base):
    if num//base == 0:  # 取商
        num = str(num)
        print(num, "==")
        return num
    else:
        x = num % base
        num = num//base
        s = str(x)
        print(s, "==")
        return transfer(num, base)+s

while(1):
    data = input()
    newdata = data.split()
    N = int(newdata[0])
    B = int(newdata[1])
    if(N < 0 or B > 10 or B < 1):
        break
    print(transfer(N, B))
