# [32543. Giganotosaurus Game](https://www.acmicpc.net/problem/32543)

## 문제
Suffering from a poor internet connection, you are playing a casual game in your web browser to pass the time. You, the player, control a Giganotosaurus that is running through a linear world with obstacles (cactuses). You win the game if you reach the end of the world without hitting any cactuses.


The world consists of $n$ cells, which can either be empty or contain a cactus. You start at the leftmost cell (which is always empty) and the goal is to get past the rightmost cell. At each cell, the Giganotosaurus can either move one position to the right, or jump over some fixed number of cells. For the first jump, you skip one cell, but with each subsequent jump, you skip one additional cell compared to the previous jump. That is, the $k$th jump skips exactly $k$ cells.


You quickly master this simple game, so you pose a more interesting challenge: count how many ways there are to win the game. As an example, consider the second sample case, visualized in Figure G.1.




Figure G.1: Visualization of the second sample input, for which there are three ways to win the game.

## 예제 입력 1
```
4
....
```

## 예제 출력 1
```
8
```

## 예제 입력 2
```
4
.#..
```

## 예제 출력 2
```
3
```

## 예제 입력 3
```
7
.#...##
```

## 예제 출력 3
```
1
```

## 예제 입력 4
```
7
..#.#.#
```

## 예제 출력 4
```
0
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | C++17 / 수정 | 197464 KB | 696 ms | 553 B | 1년 전 |
