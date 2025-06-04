import sys
input = sys.stdin.readline

N = int(input())
V = [ [] for _ in range(N+1) ]
c = 2
for i in input().split():
    V[int(i)].append(c)
    c+=1

C = [ 0 for _ in range(N) ]

stack = []
stack.append([1,0])
while stack:
  n,d = stack[-1]
  stack.pop(-1)
  C[d]+=1
  for i in V[n]:
    stack.append([i,d+1])

ans = 0
for i in range(2,N+1):
    res = 0
    for j in range(0,N,i):
        res += C[j]
    ans = max(ans, res)
print(ans)