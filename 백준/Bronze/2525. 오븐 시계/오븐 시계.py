a,b=input().split()
a,b=int(a),int(b)
c=int(input())
b+=c
a+=(b//60)
b%=60
if a>=24:   a-=24
print(a,b)