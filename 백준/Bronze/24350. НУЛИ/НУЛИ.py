from math import factorial as f
n,k=map(int,input().split())
print(str(f(n)//(f(k)*f(n-k))).count('0'))