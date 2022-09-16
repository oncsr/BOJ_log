m=int(input())
n=int(input())
if (m**0.5)%1 != 0: m = int(m**0.5)+1
else:   m = round(m**0.5)
if (n**0.5)%1 != 0: n = int(n**0.5)
else:   n = round(n**0.5)
a=[]
for i in range(m,n+1):
    a.append(i**2)
if a == []: print(-1)
else:
    print(sum(a))
    print(min(a))