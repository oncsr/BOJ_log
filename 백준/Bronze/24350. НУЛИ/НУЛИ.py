def fact(n):
    s = n
    for i in range(1,n):
        s *= i
    return s


n,k=map(int,input().split())
try:
    G=str(fact(n)//(fact(k)*fact(n-k)))
    s = 0
    for i in G:
        if i == '0':
            s += 1
    print(s)
except:
    print(0)

