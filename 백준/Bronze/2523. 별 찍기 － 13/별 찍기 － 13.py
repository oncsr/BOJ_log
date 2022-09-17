n=int(input())
i=1
while i < 2*n:
    if i <= n:  print('*'*i)
    else:       print('*'*(2*n-i))
    i+=1