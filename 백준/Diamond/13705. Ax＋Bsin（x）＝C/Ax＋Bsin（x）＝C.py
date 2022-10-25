from decimal import *

getcontext().prec = 100
getcontext().rounding = ROUND_HALF_UP
PI = Decimal('3.141592653589793238462643383279502884')

def power(m, i):
    if i == 0:
        return 1
    g = power(m,i//2)
    if i % 2 == 1:
        return m * g * g
    else:
        return g * g


def mysin(x):
    while x > PI * Decimal('2'):
        x = x - Decimal(str(PI * Decimal('2')))

    minus = 0
    if x > PI * 3 / 2:
        x = Decimal(str(PI * Decimal('2'))) - x
        minus = 1
    elif x > PI:
        x = x - PI
        minus = 1
    elif x > PI / 2:
        x = PI - x

    k = 15
    i = 3
    p = 6
    ans = x
    while k > 0:
        if i % 4 == 3:
            ans = ans - (power(x,i)/p)
        else:
            ans = ans + (power(x,i)/p)

        i += 1
        p *= i
        i += 1
        p *= i
        k -= 1

    if minus == 1:
        return ans * -1
    else:
        return ans


def F(a, b, c, x):
    return Decimal(str(a * x)) + Decimal(str(b * Decimal(str(mysin(x))))) - c


a, b, c = input().split()
a = Decimal(a)
b = Decimal(b)
c = Decimal(c)
p1 = Decimal('0')
p2 = Decimal('1000000')
p = (p1+p2)/Decimal('2')
while abs(F(a,b,c,p)) > 0.000000000000000000001:
    if F(a,b,c,p) < 0:
        p1 = p
    else:
        p2 = p
    p = Decimal(str(p1+p2))/Decimal('2')


print('{:.6f}'.format(p))