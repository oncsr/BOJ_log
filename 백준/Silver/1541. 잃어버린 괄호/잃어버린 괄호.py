a = input()
result = 0
t = 0
first = True
for i in a.split('-'):
    if '+' in i:
        for j in i.split('+'):
            t += int(j)
    else:
        t = int(i)
    if first:
        result += t
        first = False
    else:
        result -= t
    t = 0
print(result)