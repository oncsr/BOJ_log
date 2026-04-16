from decimal import *

getcontext().prec = 1500
getcontext().rounding = ROUND_HALF_UP

a,b = input().split()
A,B = Decimal(a),Decimal(b)
print('{:.1500f}'.format(A/B))