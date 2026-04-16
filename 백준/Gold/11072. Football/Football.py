N, M = map(int, input().split())
ways = [ 0 for _ in range(41) ]
things = input().split()
for thing in things:
    if ':' in thing:
        sep = thing.split(':')
        base = int(sep[0])
        ways[base] += 1
        for j in range(1,len(sep)):
            ways[base + int(sep[j])] += 1
    else:
        ways[int(thing)] += 1

dp = [ [ 0 for _ in range(201) ] for _ in range(201) ]
dp[0][0] = 1
for i in range(N+1):
    for j in range(M+1):
        for k in range(41):
            if i>=k:
                dp[i][j] += dp[i-k][j]*ways[k]
            if j>=k:
                dp[i][j] += dp[i][j-k]*ways[k]

dp[N][M] %= 1000000009
print(N, "vs", M, "can be achieved", dp[N][M] % 1000000009, "way", end='')
if dp[N][M] > 1: print('s')