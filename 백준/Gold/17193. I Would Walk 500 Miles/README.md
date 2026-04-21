# [17193. I Would Walk 500 Miles](https://www.acmicpc.net/problem/17193)

## 문제
Farmer John wants to divide his $N$ cows $(N \leq 7500)$, conveniently numbered $1 \ldots N$, into $K$ non-empty groups ($2 \leq K \leq N$) such that no two cows from two different groups can interact with each other without walking some number of miles. Cow $x$ and Cow $y$ (where $1 \leq x < y \leq N$) are willing to walk $(2019201913x + 2019201949y)\text{ mod } 2019201997$ miles to see each other.


Given a division of the $N$ cows into $K$ non-empty groups, let $M$ be the minimum of the number of miles any two cows in two different groups are willing to walk to see each other. To test the cows' devotion to each other, Farmer John wants to optimally divide the $N$ cows into $K$ groups such that $M$ is as large as possible.

## 예제 입력 1
```
3 2
```

## 예제 출력 1
```
2019201769
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 2 | C++17 / 수정 | 2020 KB | 0 ms | 206 B | 2년 전 |
