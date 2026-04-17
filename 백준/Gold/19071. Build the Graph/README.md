# [19071. Build the Graph](https://www.acmicpc.net/problem/19071)

## 문제
For an undirected graph $G$ with $n$ nodes and $m$ edges, we can define the distance $\textit{dist} (i, j)$ as the length of the shortest path between nodes $i$ and $j$. The length of a path is equal to the number of edges in the path. If there is no path between $i$ and $j$, we set $\textit{dist} (i, j)$ equal to $n$.


Then, we can define $w_G$, the weight of the graph $G$, as $\sum_{i = 1}^n \sum_{j = 1}^n \text{dist} (i, j)$.


Now, given $n$ nodes and no edges initially, we will choose no more than $m$ pairs of nodes $(i, j)$ ($i \neq j$) and add an edge between the respective nodes for every chosen pair. This way, we can get an undirected graph $G$ with $n$ nodes and no more than $m$ edges.


Your task is to find the minimal possible value of $w_G$ after such construction.

## 예제 입력 1
```
4 5
```

## 예제 출력 1
```
14
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | C++17 / 수정 | 2020 KB | 0 ms | 461 B | 1년 전 |
