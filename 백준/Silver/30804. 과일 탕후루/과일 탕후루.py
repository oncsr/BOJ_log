n=int(input())
a=[*map(int,input().split())]
c=[0 for _ in range(10)]
s,x,r=0,0,0
for e in range(n):
    c[a[e]]+=1
    if c[a[e]]==1:
        x+=1
    while x>2:
        c[a[s]]-=1
        if c[a[s]]==0:
            x-=1
        s+=1
    r=max(r,e-s+1)
print(r)