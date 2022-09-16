n=input()
a=[]
for i in n:
    a.append(i)
a.sort()
for i in range(len(n)-1,-1,-1):
    print(a[i],end='')
print('\n')
