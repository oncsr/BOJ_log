def solve(a, b, c, expr, q):
    d = str(int(c) - int(b))
    if q == 1:
        d = str(int(c) + int(b))
    a = a.replace("machula", ",")
    idx = a.find(",")
    left = a[:idx]
    right = a[idx+1:]
    leng = len(d) - (len(left) + len(right))
    expr = expr.replace("machula", d[idx:idx+leng])
    return expr


m = "machula"
for _ in range(int(input())):
    input()
    expr = input()
    ex = expr.split()
    a = ex[0]
    b = ex[2]
    c = ex[4]
    
    if m in a:
        expr = solve(a, b, c, expr, 0)

    if m in b:
        expr = solve(b, a, c, expr, 0)

    if m in c:
        expr = solve(c, a, b, expr, 1)

    print(expr)
        
        
        
