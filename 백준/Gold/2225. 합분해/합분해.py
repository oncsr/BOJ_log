def combination(n, m):
    result = 1
    for i in range(m):
        result *= n
        n -= 1
    for i in range(m):
        result //= m
        m -= 1
    return result

n, m = input().split()
n, m = int(n), int(m)

a = m+n-1
b = n
if b > a // 2:  b = a - b
print(combination(a, b) % 1000000000)