import sys
sys.setrecursionlimit(1000000)
N, K = map(int,input().split())
ans = max(0,N-K)*K

def g(x,d,t):
    if t<=1: return 0
    k = (t-x)//(d+1)
    if (t-x)%(d+1) == 0: k-=1
    
    res = 0
    if N >= t: res = (k+1)*x + k*d*(k+1)//2
    elif N >= t-k:
        cnt = N-(t-k)+1
        res = cnt*x + d*(k*(k+1)//2 - (k-cnt)*(k-cnt+1)//2)
    
    
    nxt = (x+(k+1)*d)%(t-k-1)
    return res + g(nxt,K//(t-k-1),t-k-1)

print(ans+g(0,1,K))