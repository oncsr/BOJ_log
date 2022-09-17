import sys
n,k=map(int,sys.stdin.readline().split())
yak=0
for i in range(1,n+1):
    if n%i==0:
        yak+=1
    if k==yak:
        print(i)
        break
if k > yak: print(0)