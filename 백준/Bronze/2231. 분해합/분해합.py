def splitsum(n):
    g = str(n)
    leng = len(g)
    sum = n
    for i in g:
        sum += int(i)
    return sum

n = input()
leng = len(n)
n = int(n)
no = True
for i in range(n-leng*9, n):
    if i < 1:
        continue
    if splitsum(i) == n:
        print(i)
        no = False
        break
if no:
    print(0)