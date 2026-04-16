n=int(input())
while n != -1:
    print("N="+str(n)+":")
    g = 1
    for i in range(1,n):
        g *= i
    print(g * 2)
    n=int(input())