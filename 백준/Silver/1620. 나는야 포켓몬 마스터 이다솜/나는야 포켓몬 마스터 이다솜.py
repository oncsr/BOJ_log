import sys
s = dict()
n,m=map(int,input().split())
for i in range(n):
    a=sys.stdin.readline().rstrip()
    s[i+1] = a
    s[a] = i+1

for i in range(m):
    b=sys.stdin.readline().rstrip()
    try:
        print(s[int(b)])
    except:
        print(s[b])
