# 24979 - COW Operations

[문제 링크](https://www.acmicpc.net/problem/24979)

| 난이도 | 시간 제한 | 메모리 제한 |
|--------|----------|------------|
| Gold 1 | 2 초 (추가 시간 없음) | 1024 MB |

## 알고리즘 분류
- 문자열
- 애드 혹
- 누적 합
- 홀짝성
- 불변량 찾기

## 제출 결과
| 메모리 | 시간 | 언어 | 코드 길이 | 제출 일자 |
|--------|------|------|----------|----------|
| 61124 KB | 584 ms | Java 15 | 1368 B | 2026년 4월 4일 23:08:04 |

## 문제 설명
Bessie finds a string $s$ of length at most $2 \cdot 10^5$ containing only the three characters 'C', 'O', and 'W'. She wants to know if it's possible to turn this string into a single 'C' (her favorite letter) using the following operations:

1. Choose two adjacent equal letters and delete them.

2. Choose one letter and replace it with the other two letters in either order.

Finding the answer on the string itself isn't enough for Bessie, so she wants to know the answer for $Q$ ($1\le Q\le 2\cdot 10^5$) substrings of $s$.

## 입력
The next line contains $Q$.

The next $Q$ lines each contain two integers $l$ and $r$ ($1\le l\le r\le |s|$, where $|s|$ denotes the length of $s$).

## 출력
A string of length $Q$, with the $i$-th character being 'Y' if the $i$-th substring can be reduced and 'N' otherwise.
