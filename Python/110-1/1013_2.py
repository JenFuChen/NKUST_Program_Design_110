for num in range(1):
    sentence = input()
    list = [0]
    list2 = []
    for i in range(0, len(sentence)):
        list.append(ord(sentence[i]))

    for i in range(len(list)-1, -1, -1):
        for j in range(i):
            if list[j] > list[j+1]:
                list[j], list[j+1] = list[j+1], list[j]

    for i in range(0, len(list)):
        if(list[i] != list[i+1]):
            list2.append(list.count(list[i]))

    for i in range(0, len(list)):
        print(chr(list[i]))
