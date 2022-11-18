n=int(input())
m=[ [] for i in range(n)]
d=[ [] for i in range(n)]
for i in range(n):
    g = map(int, input().split())
    for j in g:
        d[i].append(0)
        m[i].append(j)

d[0][0] = 1
for i in range(n):
    for j in range(n):
        if i == n-1 and j == n-1:
            break
        if d[i][j] > 0:
            if i + m[i][j] < n:
                d[i+m[i][j]][j] += d[i][j]
            if j + m[i][j] < n:
                d[i][j+m[i][j]] += d[i][j]


print(d[n-1][n-1])