a, b = input().split()
x, y = int(a), int(b)
X, Y, day = 1, 1, 1
daylist = ["MON","TUE","WED","THU","FRI","SAT","SUN"]
for _ in range(1, 366):
    if ((X == 1 or X == 3 or X == 5 or X == 7 or X == 8 or X == 10) and Y == 32) or ((X == 4 or X == 6 or X == 9 or X == 11) and Y == 31) or (X == 2 and Y == 29):
        X, Y = X + 1, 1
    if X == x and Y == y:
        break
    else:
        Y += 1
        day += 1
        if day > 7:
            day = 1
print(daylist[day-1])