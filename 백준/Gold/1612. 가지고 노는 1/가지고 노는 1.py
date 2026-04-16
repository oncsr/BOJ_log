n=int(input())
s = 1
c = 1
a = [0 for _ in range(n)]
while s%n != 0:
    if a[s%n]:
        print(-1)
        exit(0)
    a[s%n] = 1
    s = (s*10+1)%n
    c += 1

print(c)