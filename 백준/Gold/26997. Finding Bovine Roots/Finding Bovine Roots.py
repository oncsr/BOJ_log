from decimal import *

getcontext().prec = 100
getcontext().rounding = ROUND_HALF_UP

L = int(input())
g = input()

G = "0."+g
B = Decimal("1")
num = Decimal("2")

if int(g) == 0:
    print(1)
else:
    while True:
        val = Decimal.sqrt(num)
        st = str(val)
        if '.' not in st:
            st += ".0"
        while len(st) < L:
            st += '0'
        st = st.split('.')[1][:L]
        if st == g:
            print(num)
            break
        elif Decimal(st) > Decimal(g):
            B = B + Decimal("1")
            temp = B + Decimal(G)
            num = Decimal(int(temp*temp))
        else:
            num = num + Decimal("1")
            if Decimal(int(Decimal.sqrt(num))) > B:
                B = B + Decimal("1")
                temp = B + Decimal(G)
                num = Decimal(int(temp*temp))
            
