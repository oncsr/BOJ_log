d = [ 0 for i in range(1001) ]
n = int(input())
for i in range(1,n+1,2):
    d[i]+=1
    for j in range(i+1,n+1):
        d[j]+=d[j-i]
print(d[n])