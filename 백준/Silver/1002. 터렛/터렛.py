n = int(input())
for i in range(n):
    x1, y1, r1, x2, y2, r2 = input().split()
    x1, y1, r1, x2, y2, r2 = int(x1), int(y1), int(r1), int(x2), int(y2), int(r2)
    l2 = (x2-x1)**2 + (y2-y1)**2
    if x1 == x2 and y1 == y2 and r1 == r2:
        print(-1)
    else:
        if l2 > (r1+r2)**2:
            print(0)
        elif l2 == (r1+r2)**2:
            print(1)
        else:
            if l2 == (r1-r2)**2:
                print(1)
            elif l2 < (r1-r2)**2:
                print(0)
            else:
                print(2)