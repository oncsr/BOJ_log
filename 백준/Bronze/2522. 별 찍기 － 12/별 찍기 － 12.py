n=int(input())
for i in range(1,2*n):
    if i <= n:  print(' '*(n-i)+'*'*i)
    else:       print(' '*(i-n)+'*'*(2*n-i))