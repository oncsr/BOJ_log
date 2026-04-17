# [4925. Minimum Spanning Tree](https://www.acmicpc.net/problem/4925)

## 문제
Given graph G which is a connected, weighted, undirected graph, a spanning tree T is a subgraph of G which is: (1) a tree that (2) connects all the vertices of G together. The weight of a spanning tree is the sum of the weights of the edges in that tree. A minimum spanning tree is a spanning tree: (3) whose weight is less than or equal to the weight of every other spanning tree.


Write a program that determines if a given tree T is a Minimum Spanning Tree for a given graph G.

## 예제 입력 1
```
6 
2  6 11 0 0 
0 10  0 0 
0  0  7 
3  4 
5 
3 
(6 (3 (1 2)) (4 5)) 
(3 (1 2) (6 (4 5))) 
(4 1 2 5 6) 
5
 6 6  0 6 
 6 0 10 
10 6 
10 
2 
(1 2 5 (3 4)) 
(5 4 (3 2 1)) 
0
```

## 예제 출력 1
```
1.1 YES 
1.2 YES 
1.3 NO 
2.1 YES 
2.2 YES
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Unrated | C++17 / 수정 | 8004 KB | 164 ms | 2272 B | 2년 전 |
