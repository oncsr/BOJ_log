C = [1]
for i in range(1,2501):
    C.append(0)
    for j in range(0,i):
        C[i] += C[j] * C[i-1-j]
    C[i] %= 1000000007

t = int(input())
for i in range(t):
    n = int(input())
    if n % 2 == 1:
        print(0)
    else:
        print(C[n//2] % 1000000007)
