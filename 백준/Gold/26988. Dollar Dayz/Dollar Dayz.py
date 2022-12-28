d = []
n, k = map(int, input().split())
for i in range(n+1):
    d.append(0)
    
for i in range(1,k+1):
    d[i]+=1
    for j in range(i+1,n+1):
        d[j] += d[j-i]


print(d[n])
