# [24656. Destructive Game](https://www.acmicpc.net/problem/24656)

## 문제
There are $N$ stone piles, numbered by sequential integers from $1$ to $N$. The $i$-th pile contains $a_i$ stones. Additionally, each pile $i$ has an integer $b_i$ associated with it.


Alice and Bob play the following game using those stone piles.


They are alternately performing the following operation: choose pile $i$ and a nonnegative integer $k$ such that $b_i^k$ is not greater than the current number of stones in pile $i$, and remove $b_i^k$ stones from pile $i$. If a player cannot do that on their turn, the opposite player wins.


Alice moves first. Determine who will win if both players are playing optimally.

## 예제 입력 1
```
2
10 3
7 4
```

## 예제 출력 1
```
Bob
```

## 예제 입력 2
```
16
903 5
246 38
884 12
752 10
200 17
483 6
828 27
473 21
983 35
953 36
363 35
101 3
34 23
199 8
134 2
932 28
```

## 예제 출력 2
```
Alice
```

## 예제 입력 3
```
16
35 37
852 17
789 37
848 40
351 27
59 32
271 11
395 20
610 3
631 33
543 14
256 28
48 8
277 24
748 38
109 40
```

## 예제 출력 3
```
Bob
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 3 | C++17 / 수정 | 2020 KB | 16 ms | 313 B | 4달 전 |
