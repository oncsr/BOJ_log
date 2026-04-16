dp=[[0 for _ in range(2551)] for _ in range(101)]

N,K=map(int,input().split())
for i in range(1,N+1):
    dp[i][i] = 1

for i in range(2,N+1):
    for j in range(i+1,2551):
        for k in range(i-2,0,-1):
            dp[i][j]+=dp[k][max(j-i,0)]

s=0
for i in range(N,0,-1):
    for j in range(K+1,2551):
        s+=dp[i][j]

print(s)