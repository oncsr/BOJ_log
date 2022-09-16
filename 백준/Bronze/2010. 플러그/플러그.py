import sys
input = sys.stdin.readline
n=int(input())
a=[]
for i in range(n):
    a.append(int(input()))
print(sum(a)-(n-1))