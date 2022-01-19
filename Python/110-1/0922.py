count = 0
for i in range(1,10,2):
    for j in range(1,10):
        print(i," X ", j ," = ", j*i,"\t",end="")

for i in range(2,10,2):
    for j in range(1,10,2):
        print(i," X ", j ," = ", j*i,"\t",end="")
    count+=1

for i in range(2,10,2):
    for j in range(2,10,2):
        print(i," X ", j ," = ", j*i,"\t",end="")
    print("\n")