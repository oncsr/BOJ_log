s=0
n=int(input())
g=map(float,input().split())
for i in g:
    s+=(i**3)
print(s**(1/3))