def Comb(a, b):
    a = a + b - 1
    if b > a//2:
        b = a - b

    s = 1
    for i in range(a, a-b,-1):
        s *= i
    for i in range(1, b+1):
        s //= i

    return s




N,M,K,P=map(int, input().split())
s = 0

if N == 0:
    if M == 0:
        print(0)
    else:
        if K%2 == 1:
            print(0)
        else:
            print(Comb(M, K//2)%P)
else:
    if M == 0:
        print(Comb(N,K)%P)
    else:
        s = Comb(N,K)%P
        for i in range(1, K//2 + 1):
    
            s += ((Comb(M, i) % P) * (Comb(N,K-2*i) % P))%P

        print(s%P)



