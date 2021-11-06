while True:
    try:
        num=int(input())
    except:
        break
    if(num>0):
        s =""
        s = list(map(str,input().split()))
        n=int((num*2)-1)
        n_list = [[0 for x in range(n)]for y in range(n)]
        # print(n_list)
        # print()
        low=0
        high=n-1
        count=int((num+1)/2)
        # print(cc)
        x=0
        if(num%3==0):
            cnt=2
        elif((num+1)%3==0):
            cnt=1
        else:
            cnt=0
        # print(cnt)
        # print()
        # print(count)
        while(x<count):
            for i in range(num):
                for j in range(low,high+1):
                    n_list[i][j]=s[cnt] #最外圈(x0,y0)~(x4,y0)
                for j in range(low+1,high+1):
                    n_list[j][high]=s[cnt]#最外圈(x4,y1)~(x4,y4)
                for j in range(high-1,low-1,-1):
                    n_list[high][j]=s[cnt]#最外圈(x3,y4)~(x0,y4)
                for j in range(high-1,low,-1):
                    n_list[j][low]=s[cnt]#最外圈(x0,y3)~(x0,y1)
                low=low+1
                high=high-1

            
                x+=1
            # while(x<num):
                if(cnt==0):
                    cnt=2
                else:
                    cnt=cnt-1
        for i in range(n):
            for j in range(n):
                print(n_list[i][j],' ',end='')
            print()
    else:
        break