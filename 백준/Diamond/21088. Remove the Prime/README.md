# [21088. Remove the Prime](https://www.acmicpc.net/problem/21088)

## 문제
Two players play a game using an array of positive integers. They make alternating moves, the player who cannot make a move loses. In one move you have to choose a 
prime
 number $p$ and a non-empty segment $[l;r]$ of the array such that all numbers in this segment are divisible by $p$, and then remove 
all
 factors $p$ from each of them. Removing all factors means that we take a number and divide it by $p$ while it is divisible.


Determine who wins if both players play optimally.

## 예제 입력 1
```
3
2 8 4
```

## 예제 출력 1
```
First
```

## 예제 입력 2
```
3
2 12 3
```

## 예제 출력 2
```
Second
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 3 | C++17 / 수정 | 2296 KB | 5812 ms | 1716 B | 1년 전 |
