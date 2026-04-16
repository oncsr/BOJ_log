f = [1]
for i in range(1,32):
  f.append(f[-1]*i)
  

def comb(n,k):
  return f[n] // f[k] // f[n-k]
  
N,M,K = map(int,input().split())
if K==0:
  print(comb(N+M-2,N-1))
else:
  A = (K-1)//M + 1
  B = (K-1)%M + 1
  print(comb(A+B-2,A-1) * comb(N-A+M-B,N-A))