# [23734. Miswritten DFS](https://www.acmicpc.net/problem/23734)

## 문제
Yunee is working on a data structures assignment. Yunee wrote a function 
DFS
 that traverses a binary tree in pre-order. However, Yunee's code recursively called 
DFS
 on the left subtree twice, by mistake.




function DFS(node v):
    visit v
    if v → left exists:
        DFS(v → left)
        DFS(v → left)
    if v → right exists:
        DFS(v → right)


The pseudocode of Yunee's 
DFS
 is as above. Now consider the following example.




If we pre-order traverse the above tree, the nodes $1, 2, 3, 4, 5$ are visited in order. However, Yunee's 
DFS
 visits the nodes $1, 2, 3, 3, 4, 2, 3, 3, 4, 5$ in order.


Given a binary tree, find the $K$-th node visited by Yunee's 
DFS
. It is guaranteed that $K$ is not greater than the total number of visits. The nodes are numbered from $1$ to $N$ and the root node is always node $1$.

## 예제 입력 1
```
5 9
2 5
3 4
0 0
0 0
0 0
```

## 예제 출력 1
```
4
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 1 | C++17 / 수정 | 6588 KB | 24 ms | 938 B | 2년 전 |
