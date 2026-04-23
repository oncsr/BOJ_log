# [10186. Rummikub](https://www.acmicpc.net/problem/10186)

## 문제
In the game of Rummikub® you get tiles numbered from 1-13 of four different colors (red, blue, orange, and black). The purpose of the game is to make groups or runs from your 14 tiles. Groups are 3 or 4 of a kind of different color tile, and runs are three or more consecutive tiles of the same color. The point value of a group or run is the sum of point values of the tiles. The object is to play all of your tiles. This is like the card game gin or gin rummy. What a great program to write!


The input will have a color character (A,B, C and D) followed by a 1-2 digit number (1-13). So, a group would look like A5, B5, C5; a run would look like A5, A6, A7.


For this program, consider only the following objectives:




determine whether or not your hand can make groups or runs


determine the maximum point value of each combination




For example, the following 14 tiles:


A5 B5 C5 A6 A7 B13 A12 C1 C9 D1 D2 D3 D7 D12


can have the following groups: A5 B5 C5 (15 points) or the following runs: A5 A6 A7 (18 points) and D1 D2 D3 (6 points) So the maximum point value for a group or run is 18 points.

## 예제 입력 1
```
3
A5 B5 C5 A6 A7 B13 A12 C1 C9 D1 D2 D3 D7 D12
A1 A2 B1 B2 C5 C7 C9 C11 B6 B8 B10 B12 D3 D4
D13 C9 C13 A1 A3 A4 A5 A9 A13 B1 B2 B11 B12 B13
```

## 예제 출력 1
```
A5 A6 A7 18
NO GROUPS OR RUNS
A13 B13 C13 D13 52
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 2 | C++17 / 수정 | 2020 KB | 0 ms | 1556 B | 3년 전 |
