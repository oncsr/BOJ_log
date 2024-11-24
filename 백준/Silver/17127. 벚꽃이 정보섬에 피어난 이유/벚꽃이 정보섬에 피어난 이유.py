N=int(input())
L=[*map(int,input().split())]
s=0
for i in range(0,N):
    for j in range(i+1,N):
        for k in range(j+1,N-1):
            A,B,C,D = 1,1,1,1
            for x in range(0,i+1):
                A *= L[x]
            for x in range(i+1,j+1):
                B *= L[x]
            for x in range(j+1,k+1):
                C *= L[x]
            for x in range(k+1,N):
                D *= L[x]
            s = max(s, A+B+C+D)
print(s)