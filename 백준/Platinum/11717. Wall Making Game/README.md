# [11717. Wall Making Game](https://www.acmicpc.net/problem/11717)

## 문제
The game Wall Making Game, a two-player board game, is all the rage.


This game is played on an H × W board. Each cell of the board is one of empty, marked, or wall. At the beginning of the game, there is no wall on the board.


In this game, two players alternately move as follows:




A player chooses one of the empty cells (not marked and not wall). If the player can’t choose a cell, he loses.


Towards each of the four directions (upper, lower, left, and right) from the chosen cell, the player changes cells (including the chosen cell) to walls until the player first reaches a wall or the outside of the board.




Note that marked cells cannot be chosen in step 1, but they can be changed to walls in step 2.


Fig.1 shows an example of a move in which a player chooses the cell at the third row and the fourth column.




fig.1: An example of a move in Wall Making Game.


Your task is to write a program that determines which player wins the game if the two players play optimally from a given initial board.

## 예제 입력 1
```
2 2
..
..
```

## 예제 출력 1
```
Second
```

## 예제 입력 2
```
2 2
X.
..
```

## 예제 출력 2
```
First
```

## 예제 입력 3
```
4 5
X....
...X.
.....
.....
```

## 예제 출력 3
```
First
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 2 | Java 11 / 수정 | 45992 KB | 640 ms | 1627 B | 1년 전 |
