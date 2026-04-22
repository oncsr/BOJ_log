# [7678. Football](https://www.acmicpc.net/problem/7678)

## 문제
Consider a single-elimination football tournament involving 2
n
 teams, denoted 1, 2, . . ., 2
n
. In each round of the tournament, all teams still in the tournament are placed in a list in order of increasing index. Then, the first team in the list plays the second team, the third team plays the fourth team, etc. The winners of these matches advance to the next round, and the losers are eliminated. After n rounds, only one team remains undefeated; this team is declared the winner.


Given a matrix P = [p
ij
] such that p
ij
 is the probability that team i will beat team j in a match determine which team is most likely to win the tournament.

## 예제 입력 1
```
2
0.0 0.1 0.2 0.3
0.9 0.0 0.4 0.5
0.8 0.6 0.0 0.6
0.7 0.5 0.4 0.0
-1
```

## 예제 출력 1
```
2
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 2 | C++17 / 수정 | 2424 KB | 16 ms | 1283 B | 2년 전 |
