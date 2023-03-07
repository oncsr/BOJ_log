def solution(t, p):
    s = len(p)
    g = int(p)
    ans = 0
    for i in range(len(t)-s+1):
        n = int(t[i:i+s])
        if n <= g:
            ans+=1

    return ans