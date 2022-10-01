a=input()
b=input()
sa=len(a)
sb=len(b)
c=int(a)
d=int(b)
if a[0] == '0':
    c=0
if b[0] == '0':
    d=10**sb
for i in range(sa-1):
    a=a[1:sa]+a[0]
    if a[0] != '0':
        c=max(int(a),c)

for i in range(sb-1):
    b=b[1:sb]+b[0]
    if b[0] != '0':
        d=min(int(b),d)

print(c-d)
