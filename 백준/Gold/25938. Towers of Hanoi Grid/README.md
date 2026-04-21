# [25938. Towers of Hanoi Grid](https://www.acmicpc.net/problem/25938)

## 문제
Towers of Hanoi is a rather famous problem for computer scientists as it is an excellent exercise in recursion. For those of you unfamiliar, here is the classic problem. You are given three pegs. On the first peg, there are d disks placed in decreasing order of size (as placed on the peg). The objective of the game is to move the entire tower from the first peg to the last peg. In each move, you are only allowed to move a single disk from the top of one stack to another stack. For the entire game, no disk of larger size is ever allowed to be placed on top of a disk of smaller size. The goal of the puzzle is to move the tower in the minimum number of moves.




In our problem, we will instead have an n × n grid of pegs. The rows are numbered top to bottom from 1 to n, while the columns are similarly labeled, from left to right, 1 to n. The original tower is placed on the top left peg (1, 1). The goal is to move the tower to the bottom right peg (n, n) in the minimum number of moves possible.




Our game will have some different but related rules:




For a peg (r, c) at row r and column c, you may only move the top-most disk from peg (r, c) to peg (r + 1, c) or peg (r, c + 1), in a single move and only if such a pair of pegs exists.


Only pegs (1, 1) and/or (n, n) may have more than one disk at any time; all other pegs may contain at most one disk.


You can choose any peg for each move.


You still may never place a larger disk on a smaller disk.




Given the number of disks on the starting peg and the number n described above, determine the minimum number of moves to solve our Tower of Hanoi Grid puzzle.

## 예제 입력 1
```
3
2 2
100 8
3 100
```

## 예제 출력 1
```
Grid #1: 4

Grid #2: impossible

Grid #3: 594
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 4 | C++17 / 수정 | 2020 KB | 4 ms | 356 B | 2년 전 |
