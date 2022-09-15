n = int(input())
namelist = []
for i in range(n):
    namelist.append(input())
wrong = []
for i in namelist[0]:
    wrong.append(i)
temp = namelist[0]
for i in namelist:
    for j in range(len(temp)):
        if temp[j] != i[j]: wrong[j] = '?'
    temp = i
print(''.join(wrong))