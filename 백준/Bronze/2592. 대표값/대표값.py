a = [0]*100
total = 0
for i in range(10):
    k = int(input())
    a[k//10] += 1
    total += k

print(total//10)
print(a.index(max(a))*10)
