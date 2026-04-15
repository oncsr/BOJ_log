import sys
from functools import cmp_to_key
input = sys.stdin.readline

def ccw(a,b,c):
    ax, ay = a
    bx, by = b
    cx, cy = c
    res = ax*by + bx*cy + cx*ay - (ax*cy + bx*ay + cx*by);
    if res > 0:
        return 1
    if res < 0:
        return -1
    return 0
    
def cmpe(a, b):
    ax, ay = a
    bx, by = b
    anum = 10
    bnum = 10
    if ax == 0:
        if ay > 0:
            anum = 2
        else:
            anum = 6
    elif ay == 0:
        if ax > 0:
            anum = 0
        else:
            anum = 4
    else:
        if ax > 0:
            if ay > 0:
                anum = 1
            else:
                anum = 7
        else:
            if ay > 0:
                anum = 3
            else:
                anum = 5
    
    if bx == 0:
        if by > 0:
            bnum = 2
        else:
            bnum = 6
    elif by == 0:
        if bx > 0:
            bnum = 0
        else:
            bnum = 4
    else:
        if bx > 0:
            if by > 0:
                bnum = 1
            else:
                bnum = 7
        else:
            if by > 0:
                bnum = 3
            else:
                bnum = 5
    
    if anum == bnum:
        return -ccw([0,0], a, b)
    return anum-bnum



N, M, K = map(int, input().split())
X, Y = map(int, input().split())

hull = []
for i in range(N):
    a, b = map(int, input().split())
    a -= X
    b -= Y
    hull.append([a,b])

tmp = []
for i in range(M):
    a, b = map(int, input().split())
    a -= X
    b -= Y
    if a == 0 and b == 0:
        K -= 1
    else:
        tmp.append([a,b])
        
if K <= 0:
    print(0)
    exit(0)

arr = sorted(tmp, key=cmp_to_key(cmpe))

t = []
e = 0
while e < N:
    p = (e+N-1)%N
    r1 = ccw([0,0], hull[p], arr[0])
    r2 = ccw([0,0], arr[0], hull[e])
    if r1 > 0 and r2 >= 0:
        break
    e+=1
e%=N

for g in arr:
    x, y = g
    while ccw([0,0], hull[(e+N-1)%N], [x,y]) <= 0 or ccw([0,0], [x,y], hull[e]) < 0:
        e = (e+1)%N
    l = 0
    r = 5000000000000000000
    m = (l+r)//2
    while l<r:
        sx, sy = hull[(e+N-1)%N]
        ex, ey = hull[e]
        res = ccw([x,y], [sx*(m+1),sy*(m+1)], [ex*(m+1),ey*(m+1)])
        if res < 0:
            l = m+1
        else:
            r = m
        m = (l+r)//2
    t.append(m)

R = sorted(t)
print(R[K-1])