n = int(input())
f = int(input())

n = n - n%100
for i in range(n,n+100):
    if i % f == 0:
        n = i
        break

if n % 100 < 10:
    print('0'+str(n%100))
else:
    print(n%100)