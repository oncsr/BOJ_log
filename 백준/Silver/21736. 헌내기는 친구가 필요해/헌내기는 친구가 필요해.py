n,m=map(int,input().split())
a,q=[],[]
v=[[0 for _ in range(m)] for _ in range(n)]
for i in range(n):
    a.append(input())
    for j in range(m):
        if a[i][j]=='I':
            q.append([i,j])
            v[i][j]+=1
dx=[1,0,-1,0]
dy=[0,1,0,-1]
ans=0
while len(q)>0:
    x,y=q[-1]
    if a[x][y]=='P':
        ans+=1
    q.pop()
    for k in range(4):
        xx,yy=x+dx[k],y+dy[k]
        if xx<0 or xx>=n or yy<0 or yy>=m or v[xx][yy] or a[xx][yy]=='X':
            continue
        q.append([xx,yy])
        v[xx][yy]+=1
print(ans if ans>0 else 'TT')