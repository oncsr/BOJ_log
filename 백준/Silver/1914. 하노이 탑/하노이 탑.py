def H(a, b, n):
    if n == 1:
        print(a, b)
        return
    o = 6-a-b
    H(a,o,n-1)
    print(a,b)
    H(o,b,n-1)


t=int(input())
print(2**t-1)
if t <= 20:
    H(1,3,t)