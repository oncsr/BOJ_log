# [33752. LIS on Tree](https://www.acmicpc.net/problem/33752)

## 문제
You are given a tree of $n$ nodes. Each node has a non-negative integer value $v_i$.


Let a 
tree subsequence
 be a sequence of nodes $S = s_1, s_2, \dots s_k$ such that there exists vertices $u, v$ in the tree such that $S$ is a subsequence of the unique shortest path starting at $u$ and ending at $v$.


A 
tree subsequence
 is increasing if for all $1 \leq i \leq k - 1$ we have that $v_{s_i} < v_{s_{i + 1}}$ (Note that this corresponds to a 
strictly
 increasing sequence).


Find the length of the longest increasing 
tree subsequence
.

## 예제 입력 1
```
4
7 7 7 7
2 4
2 3
1 2
```

## 예제 출력 1
```
1
```

## 예제 입력 2
```
5
3 9 14 7 12
1 4
3 4
4 5
2 3
```

## 예제 출력 2
```
3
```

## 예제 입력 3
```
12
10 3 8 13 6 2 3 14 1 5 10 6
1 10
2 6
2 10
7 9
2 9
9 11
3 7
2 8
5 7
4 7
2 12
```

## 예제 출력 3
```
4
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 3 | Java 15 / 수정 | 449196 KB | 4516 ms | 8173 B | 1달 전 |
