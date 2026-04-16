# [24979. COW Operations](https://www.acmicpc.net/problem/24979)

## 문제
Bessie finds a string $s$ of length at most $2 \cdot 10^5$ containing only the three characters 'C', 'O', and 'W'. She wants to know if it's possible to turn this string into a single 'C' (her favorite letter) using the following operations:


1. Choose two adjacent equal letters and delete them.


2. Choose one letter and replace it with the other two letters in either order.


Finding the answer on the string itself isn't enough for Bessie, so she wants to know the answer for $Q$ ($1\le Q\le 2\cdot 10^5$) substrings of $s$.

## 예제 입력 1
```
COW
6
1 1
1 2
1 3
2 2
2 3
3 3
```

## 예제 출력 1
```
YNNNYN
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 1 | Java 15 / 수정 | 61124 KB | 584 ms | 1368 B | 12일 전 |
