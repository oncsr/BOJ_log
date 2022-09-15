def fib(n):
    if n<2:    return 1
    else:
        i=0
        j=1
        cnt=2
        m=i+j
        while n!=cnt:
            temp = m
            m += j
            j = temp
            cnt += 1
        return m

t=int(input())

for i in range(t):
    n=int(input())
    if n==0:    print(n+1,n)
    elif n==1:  print(n-1,n)
    else:
        print(fib(n-1),fib(n))