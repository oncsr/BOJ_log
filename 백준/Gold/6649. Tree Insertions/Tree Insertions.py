F=[1]
s=1
for i in range(1,101):
    s*=i
    F.append(s)

N=int(input())
while N!=0:
    B=list(map(int,input().split()))
    L=[0] * 101
    R=[0] * 101
    A=[-1] * 101
    S=[1] * 101
    D=[0] * 101
    i=1
    for a in B:
        r=1
        while A[r] != -1:
            S[r]+=1
            if a < A[r]:
                if L[r] == 0:
                    L[r] = i
                    break
                else:
                    r=L[r]
            else:
                if R[r] == 0:
                    R[r] = i
                    break
                else:
                    r=R[r]
        A[i]=a
        i+=1
    
    def dfs(n):
        res=F[S[n]-1]
        if L[n]!=0:
            dfs(L[n])
            res*=D[L[n]]
            res//=F[S[L[n]]]
        if R[n]!=0:
            dfs(R[n])
            res*=D[R[n]]
            res//=F[S[R[n]]]
        D[n]=res
    
    dfs(1)
    print(D[1])
    N=int(input())