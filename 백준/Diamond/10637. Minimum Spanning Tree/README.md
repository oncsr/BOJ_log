# [10637. Minimum Spanning Tree](https://www.acmicpc.net/problem/10637)

## 문제
You are given an undirected weighted graph G with n nodes and m edges. Each edge is numbered from 1 to m.


Let G
i
 be an graph that is made by erasing i-th edge from G. Your task is to compute the cost of minimum spanning tree in G
i
 for each i.

## 예제 입력 1
```
4 6
1 2 2
1 3 6
1 4 3
2 3 1
2 4 4
3 4 5
```

## 예제 출력 1
```
8
6
7
10
6
6
```

## 예제 입력 2
```
4 4
1 2 1
1 3 10
2 3 100
3 4 1000
```

## 예제 출력 2
```
1110
1101
1011
-1
```

## 예제 입력 3
```
7 10
1 2 1
1 3 2
2 3 3
2 4 4
2 5 5
3 6 6
3 7 7
4 5 8
5 6 9
6 7 10
```

## 예제 출력 3
```
27
26
25
29
28
28
28
25
25
25
```

## 예제 입력 4
```
3 1
1 3 999
```

## 예제 출력 4
```
-1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 4 | C++17 / 수정 | 31564 KB | 384 ms | 2955 B | 2년 전 |
