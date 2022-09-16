def solve(n):
    r = (2*n)**0.5
    return round(r)-1

s = int(input())
if solve(s+1) != solve(s):  print(solve(s+1))
else:   print(solve(s))