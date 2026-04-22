import sys
input = sys.stdin.readline
n=int(input())
arr=list(map(int, input().split()))
s=1
err=False
for i in arr:
    s *= 2
    s -= i
    if s < 0:
        err = True
        break

if err:
    print("error")
else:
    print(s%1000000007)