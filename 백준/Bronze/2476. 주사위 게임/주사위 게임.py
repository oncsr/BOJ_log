n=int(input())
price = []
for i in range(n):
    k=input().split()
    a,b,c=int(k[0]),int(k[1]),int(k[2])
    if a == b and b == c:               price.append(10000+1000*a)
    elif a != b and b != c and a != c:  price.append(100*max(a,b,c))
    else:
        if a == b:  price.append(1000+100*a)
        else:       price.append(1000+100*c)
print(max(price))
