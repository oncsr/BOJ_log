def gys(a,b):
    for i in range(2,a+1):
        if a % i == 0 and b % i == 0:
            return i
    return 1

t = int(input())
for i in range(t):
    a,b = input().split()
    a,b = min(int(a),int(b)), max(int(a),int(b))
    n = gys(a,b)
    result = 1
    while n != 1:
        a//=n
        b//=n
        result*=n
        n = gys(a,b)
    result *= (a*b)
    print(result)