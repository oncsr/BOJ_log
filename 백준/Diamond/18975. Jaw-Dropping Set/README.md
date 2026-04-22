# [18975. Jaw-Dropping Set](https://www.acmicpc.net/problem/18975)

## 문제
A subset $A$ of the set $\{1, 2, 3, \ldots, n\}$ is called 
interesting
 if for any pair of different integers $x, y \in A$ neither $x$ divides $y$ nor $y$ divides $x$.


An interesting subset $A$ is called 
amazing
 if it has the maximum cardinality among all interesting subsets.


Finally, an amazing subset $A$ is called 
jaw-dropping
 if it has the minimum sum of elements among all amazing subsets.


Given $n$, find the sum of elements in any jaw-dropping subset of $\{1, 2, 3, \ldots, n\}$.

## 예제 입력 1
```
7
1
2
3
4
5
6
7
```

## 예제 출력 1
```
1
1
5
5
10
10
17
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 4 | C++17 / 수정 | 2020 KB | 40 ms | 470 B | 2년 전 |
