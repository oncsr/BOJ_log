# [32060. Doubled GCD](https://www.acmicpc.net/problem/32060)

## 문제
There are $N$ cards in a deck, numbered from $1$ to $N$, where card $i$ has a positive integer $A_i$ written on it.


You are to perform $N - 1$ moves with the cards. In each move, you select two cards of your choice from the deck. Let $x$ and $y$ be the integers written on the selected cards, respectively. Remove both selected cards, and insert a new card into the deck with $2 \cdot \gcd(x, y)$ written on it, where $\gcd(x, y)$ is the greatest common divisor of $x$ and $y$. Note that with this one move, there will be one fewer card in the deck (as you remove two cards and insert one new card).


After all $N -1$ moves have been performed, there will be exactly one card remaining. Your goal is to maximize the integer written on the last card; output this integer.

## 예제 입력 1
```
3
2 4 6
```

## 예제 출력 1
```
8
```

## 예제 입력 2
```
3
3 5 7
```

## 예제 출력 2
```
2
```

## 예제 입력 3
```
4
9 9 9 9
```

## 예제 출력 3
```
36
```

## 예제 입력 4
```
5
10 100 1000 10000 100000
```

## 예제 출력 4
```
160
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | C++17 / 수정 | 5220 KB | 48 ms | 680 B | 1년 전 |
