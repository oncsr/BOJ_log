a = input()
l = []
w = []
for i in a.upper():
    if i not in l:
        l.append(i)
        w.append(1)
    else:
        w[l.index(i)] += 1

mx = 0
sub = 0
for j in w:
    if j > mx:    mx = j
    elif j > sub:    sub = j

if mx == sub:    print('?')
else:    print(l[w.index(mx)])