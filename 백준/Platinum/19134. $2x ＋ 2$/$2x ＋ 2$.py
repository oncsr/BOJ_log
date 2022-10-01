n=int(input())
ans = 0
ans += n - n//2 + 1
n //= 2
while n > 1:
    n = (n-1)//2
    if n == 2:
        ans+=1
        break
    if n <= 1:
        break
    ans += n - (n-1)//2
    n = (n-1)//2

print(ans)