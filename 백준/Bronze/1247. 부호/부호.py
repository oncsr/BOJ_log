import sys
input=sys.stdin.readline
for _ in range(3):
    n=int(input())
    s=0
    for i in range(n):
        g=int(input())
        s+=g
    if s > 0:
        print('+')
    if s == 0:
        print('0')
    if s < 0:
        print('-')