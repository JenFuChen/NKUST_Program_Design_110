# 001 Read the file and sum the numbers.

f = open("input.txt", mode='r')
f2 = open("output.txt", mode='r')
sum = 0
for line in f.readlines():
    num = int(line)
    sum = sum + num
f.close()
f2 = open("output.txt", mode='w')
print(sum, file=f2)
f2.close()
