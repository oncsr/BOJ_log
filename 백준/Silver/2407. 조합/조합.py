n,m=map(int,input().split())
if m>n//2:
    m=n-m
result=1
k=m
for i in range(k):
    result*=n
    n-=1
    if result%m==0:
        result//=m
        m-=1
for i in range(m,0,-1):
    result//=i
print(result)
