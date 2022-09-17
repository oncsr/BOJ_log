a = input().split()[1]
b, c = input().split()
d, e = input().split()
f = input().split()[0]

a, b, c, d, e, f = int(a), int(b), int(c), int(d), int(e), int(f)

print(max(a, a-b+c, a-b+c-d+e))
