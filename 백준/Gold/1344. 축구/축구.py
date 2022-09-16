def comb(n):
    if n>9:
        n=18-n
    result=1
    g=18
    for i in range(n):
        result*=g
        g-=1
    for i in range(n,0,-1):
        result//=i
    return result

a=int(input())
b=int(input())
p=a/100
q=b/100

pr = 0
sosu = [2,3,5,7,11,13,17]
for i in sosu:
    pr += (comb(i)*(p**i)*((1-p)**(18-i)))
for i in sosu:
    pr += (comb(i)*(q**i)*((1-q)**(18-i)))
for i in sosu:
    for j in sosu:
        pr -= ((comb(i)*(p**i)*((1-p)**(18-i)))*(comb(j)*(q**j)*((1-q)**(18-j))))
print(pr)
