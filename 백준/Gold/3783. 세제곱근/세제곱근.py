from decimal import *
getcontext().prec = 1000
getcontext().rounding = ROUND_HALF_UP

for _ in range(int(input())):
    N=Decimal(input())
    G=Decimal("1")/Decimal("3")
    res = str(round(N**G,500))
    print(res.split('.')[0]+'.'+res.split('.')[1][:10])
