# [13244. Tree](https://www.acmicpc.net/problem/13244)

## 문제
One of the most important data structures in computer science is the tree. You already dealt with binary trees in the qualification round. This problem is about general trees.


Trees are the subset of graphs that have the following 3 properties:




It is connected: for every node you can reach every other node following edges.


If an edge is removed, the graph is no longer connected. That is, some nodes cannot be reached anymore.


When an edge is added between two existing nodes A and B, a cycle is created. There is a cycle if there is more than one way to go from A to B.




Your task is to decide if a given graph is a tree or not.

## 예제 입력 1
```
2
4
3
2 1
3 4
1 3
3
3
1 2
1 2
3 2
```

## 예제 출력 1
```
tree
graph
```

## 예제 입력 2
```
2
7
5
7 2
2 4
4 3
5 6
6 1
7
6
7 2
2 4
4 3
4 5
6 5
1 6
```

## 예제 출력 2
```
graph
tree
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 4 | C++17 / 수정 | 2020 KB | 0 ms | 494 B | 1년 전 |
