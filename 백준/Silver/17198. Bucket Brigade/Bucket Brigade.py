a = []
que = []
vis = []
for i in range(10):
    a.append(input())
    vis.append(list())
    for j in range(10):
        vis[i].append(0)
        if a[i][j] == 'B':
            que.append([i,j,0])

dx = [1,0,-1,0]
dy = [0,1,0,-1]
while len(que) > 0:
    x,y,t = que[0]
    que.pop(0)
    if a[x][y] == 'L':
        print(t-1)
        break
    for i in range(4):
        xx,yy = x+dx[i],y+dy[i]
        if xx<0 or xx>=10 or yy<0 or yy>=10 or a[xx][yy] == 'R' or vis[xx][yy]:
            continue
        que.append([xx,yy,t+1])
        vis[xx][yy]=1