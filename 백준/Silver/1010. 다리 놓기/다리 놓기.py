def combination(a, b):
    result = 1
    j = b
    for i in range(j):
        result *= a
        a-=1
    for i in range(j):
        result //= b
        b-=1
    return result


t = int(input())
for i in range(t):
    a, b = input().split()
    a, b = int(a), int(b)
    if(a > b//2):
        a = b-a
    print(combination(b, a))
    
