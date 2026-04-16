# [31311. Very Important Edge](https://www.acmicpc.net/problem/31311)

## 문제
You are given a simple connected graph where each edge is assigned a non-negative weight. Recall that a minimum spanning tree of a graph is a connected, acyclic subset of the edges of the graph with minimum total weight. Find an edge which maximizes the minimum spanning tree weight of a given graph if that edge is deleted. It is guaranteed that the input graph remains connected after deleting any one edge.

## 예제 입력 1
```
3 3
1 2 1
2 3 2
1 3 2
```

## 예제 출력 1
```
4
```

## 예제 입력 2
```
4 5
2 3 5
1 2 2
1 3 4
1 4 2
3 4 3
```

## 예제 출력 2
```
10
```

## 예제 입력 3
```
5 7
2 5 8
1 3 19
4 5 9
1 5 15
1 2 14
3 4 16
2 4 15
```

## 예제 출력 3
```
54
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 5 | C++17 / 수정 | 70976 KB | 2880 ms | 3405 B | 1년 전 |
