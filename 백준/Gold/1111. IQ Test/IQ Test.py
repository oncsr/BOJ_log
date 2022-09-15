n = int(input())
p = input().split()
for i in range(len(p)):
    p[i] = int(p[i])

err = 0
if len(p) == 1:
    print('A')
elif len(p) == 2 and p[0] == p[1]:
    print(p[0])
elif len(p) == 2:
    print('A')
else:
    try:
        a = (p[2]-p[1]) // (p[1]-p[0])
        b = p[1] - p[0]*a
        for i in range(len(p)-1):
            if p[i]*a + b != p[i+1]:
                err += 1
        if err != 0:    print('B')
        else:   print(p[-1]*a+b)
    except ZeroDivisionError:
        c = 0
        for i in range(len(p)-1):
            if p[i] == p[i+1]:
                c += 1
        if c == len(p)-1:   print(p[0])
        else:   print('B')