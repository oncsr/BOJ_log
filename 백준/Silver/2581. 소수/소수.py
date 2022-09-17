def sosu(num):
    result = 0
    for i in range(1, num):
        if num % i == 0:
            result += 1
    return result == 1


m = int(input())
n = int(input())

total = 0
mini = 0
for j in range(m,n+1):
    if sosu(j):
        total += j
        if mini == 0:   mini = j

if total == 0:  print(-1)
else:           print(total,mini,sep='\n')