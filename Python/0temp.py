def main():
    L = int(input())
    ch = input().split(" ")
    out = (L-1) % 3
    print("===============ans===================")
    if L == 1:
        return print(ch[out])
    for i in range(1, L*2):
        d = [(out-i)for i in range(i if i < L else (2*L-i-1 if i == L else 2*L-i))]
        d = d+(([d[-1]]*(2*L-1-len(d)*2)) if i != L else [0])+d[::-1]
        print(' '.join([ch[i % 3] for i in d]))
main()
