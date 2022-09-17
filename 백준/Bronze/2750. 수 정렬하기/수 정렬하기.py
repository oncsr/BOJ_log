n = int(input())
p = []
for i in range(n):
    p.append(int(input()))
p.sort()
for i in range(n):
    print(p[i])