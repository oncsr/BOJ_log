p=input().split()
for i in range(len(p)):
    p[i] = int(p[i])
print(min(p[0],p[1],p[2]-p[0],p[3]-p[1]))