N, M, H = map(int, input().split())
a = []
for i in range(N):
    a.append(list(map(int, input().split())))

MOD = 10007
dp = [ 0 for _ in range(H+1) ]
dp[0] = 1

for i in range(N):
    ndp = [ 0 for _ in range(H+1) ]
    a[i].append(0)
    for j in a[i]:
        for k in range(0, H-j+1):
            ndp[k+j] += dp[k]
            ndp[k+j] %= MOD
    dp = ndp

print(dp[H])