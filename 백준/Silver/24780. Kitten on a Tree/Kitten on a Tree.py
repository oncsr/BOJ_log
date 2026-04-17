K = int(input())
s = input()
par = [0 for _ in range(101)]
while s != "-1":
    t = list(map(int, s.split()))
    for i in range(1,len(t)):
        par[t[i]] = t[0]
    s = input()

while par[K]:
    print(K, end=' ')
    K = par[K]
print(K, end='')