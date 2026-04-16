# [19111. Two Paths](https://www.acmicpc.net/problem/19111)

## 문제
You are given an undirected graph with $n$ nodes (numbered from $1$ to $n$) and $m$ edges. Each edge has a length. The graph contains neither multiple edges nor self-loops.


Alice and Bob are now trying to play a game. Each player has to pick a path from $1$ to $n$ (not necessary a simple path). The paths have to be different.


Alice always moves first, and she is so clever that she took one of the shortest paths from $1$ to $n$. Now is Bob's turn. Bob wants to pick the shortest possible path from $1$ to $n$ which is different from Alice's path. Your task is to find the length of such path.


Two paths $S$ and $T$ are considered different if and only if they have different number of edges or there is an integer $i$ such that the $i$-th edge of $S$ differs from the $i$-th edge of $T$.

## 예제 입력 1
```
3 3
1 2 1
2 3 4
1 3 3
```

## 예제 출력 1
```
5
```

## 예제 입력 2
```
2 1
1 2 1
```

## 예제 출력 2
```
3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 2 | C++17 / 수정 | 13808 KB | 100 ms | 750 B | 1년 전 |
