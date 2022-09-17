m=[]
temp=0
for _ in range(10):
    a,b=map(int,input().split())
    m.append(temp+b-a)
    temp+=(b-a)
print(max(m))