# [5694. Bingo!](https://www.acmicpc.net/problem/5694)

## 문제
Albert, Charles and Mary invented a new version of the classical game Bingo. In traditional Bingo the game is presided over by a non-player known as the caller. At the beginning of the game each player is given a card containing a unique combination of numbers from 0 to N arranged in columns and rows. The caller has a bag containing N + 1 balls, numbered from 0 to N. On each turn, the caller randomly selects a ball from the bag, announces the number of the drawn ball to the players, and sets the ball aside so that it cannot be selected again. Each player searches his card for the called number and marks it if he finds it. The first player who marks a complete pre-announced pattern on the card (for example, a full horizontal line) wins a prize.


In the Albert-Charles-Mary version, on each turn, the caller draws a first ball, returns it to the bag, draws a second ball, returns it to the bag, and then calls out the absolute difference between the two ball numbers. To generate even more excitement, before the game started a possibly empty subset of balls is removed from the bag, in such a way that at least two balls remain there. They would like to know if every number from 0 to N may still be called out with the new drawing method considering the balls that were left in the bag.

## 예제 입력 1
```
6 7
2 1 3 4 0 6 5
5 4
5 3 0 1
5 3
1 5 0
0 0
```

## 예제 출력 1
```
Y
Y
N
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 1 | C++17 / 수정 | 2020 KB | 20 ms | 491 B | 3년 전 |
