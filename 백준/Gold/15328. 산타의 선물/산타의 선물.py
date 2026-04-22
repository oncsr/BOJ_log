from decimal import *
import sys
input = sys.stdin.readline

getcontext().prec = 100
getcontext().rounding = ROUND_HALF_UP

def distance(a, b):
    p1 = Decimal(str(a[0] - b[0])) * Decimal(str(a[0] - b[0]))
    p2 = Decimal(str(a[1] - b[1])) * Decimal(str(a[1] - b[1]))
    p3 = Decimal(str(a[2] - b[2])) * Decimal(str(a[2] - b[2]))
    return (p1+p2+p3).sqrt()
    
    

T = int(input())
for _ in range(T):
    X = input()

    X = Decimal(X)

    arr = []

    for i in range(4):
        x, y, z = input().split()
        x = Decimal(x)
        y = Decimal(y)
        z = Decimal(z)
        arr.append([x,y,z])

    S = [Decimal('0'), Decimal('0'), Decimal('0')]

    D = Decimal('0')
    D = D + distance(S, arr[0])
    D = D + distance(arr[0], arr[1])
    D = D + distance(arr[1], arr[2])
    D = D + distance(arr[2], arr[3])

    if D <= X:
        print("YES")
    else:
        print("NO")