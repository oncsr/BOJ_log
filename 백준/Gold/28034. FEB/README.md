# [28034. FEB](https://www.acmicpc.net/problem/28034)

## 문제
Bessie and Elsie are plotting to overthrow Farmer John at last! They plan it out over $N$ ($1\le N\le 2\cdot 10^5$) text messages. Their conversation can be represented by a string $S$ of length $N$ where $S_i$ is either $B$ or $E$, meaning the $i$th message was sent by Bessie or Elsie, respectively.


However, Farmer John hears of the plan and attempts to intercept their conversation. Thus, some letters of $S$ are $F$, meaning Farmer John obfuscated the message and the sender is unknown.


The 
excitement level
 of a non-obfuscated conversation is the number of times a cow double-sends - that is, the number of occurrences of substring $BB$ or $EE$ in $S$. You want to find the excitement level of the original message, but you don’t know which of Farmer John’s messages were actually Bessie’s / Elsie’s. Over all possibilities, output all possible excitement levels of $S$.

## 예제 입력 1
```
4
BEEF
```

## 예제 출력 1
```
2
1
2
```

## 예제 입력 2
```
9
FEBFEBFEB
```

## 예제 출력 2
```
2
2
3
```

## 예제 입력 3
```
10
BFFFFFEBFE
```

## 예제 출력 3
```
3
2
4
6
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 1 | C++17 / 수정 | 2648 KB | 8 ms | 1236 B | 2년 전 |
