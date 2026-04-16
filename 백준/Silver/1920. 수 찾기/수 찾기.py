N = int(input())
arr = list(map(int, input().split()))
arr.sort()

def binary_search(s, e, k):
    if s == e:
        if arr[s] == k:
            return 1
        return 0
    m = (s + e) // 2
    if k > arr[m]:
        return binary_search(m+1, e, k)
    return binary_search(s,m,k)



M = int(input())
query = list(map(int, input().split()))

for q in query:
    print(binary_search(0,N-1,q))
