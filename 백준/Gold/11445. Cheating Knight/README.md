# [11445. Cheating Knight](https://www.acmicpc.net/problem/11445)

## 문제
The land of the Black King is an infinitely stretching flat surface neatly divided into black and white squares, much like an infinite chessboard. The area of every square is exactly one square metre, and the squares are neatly layed out on a perfect grid. Sir Jumpsalot is a knight who lives in the land of the Black King. By law, knights may only move around by jumping from the centre of a square to the centre of another square, as long as the distance between those centres is exactly √D metres. (In the game of chess, the value of D is fixed at 5, but we will consider other values of D as well.) The value of D fixed in the law can be written as a sum of two squares, for otherwise knights would be unable to move around.


Sir Jumpsalot doesn’t like to play by the rules. While he still moves around by jumping √D metres, he doesn’t bother landing on the centre of a square every time. In other words, he sometimes lands in a corner of a square or even on the border between adjacent squares, whichever is most convenient. Reaching his destination is usually easier this way, as can be seen from the following example (travelling two squares horizontally and three vertically with the familiar value of D = 5).




a) Route for any normal, law abiding knight.




b) Route for the cheating Sir Jumpsalot.


Given that Sir Jumpsalot starts at the centre of the square with coordinates (0, 0) and has to travel to the centre of the square with coordinates (X, Y ), your task is to calculate the minimum number of jumps Sir Jumpsalot needs to reach his destination. You may safely assume that there are no obstructions in his way.

## 예제 입력 1
```
5
5 0 0
5 2 3
25 -3 -4
100 0 -100
1 2345 6789
```

## 예제 출력 1
```
0
2
1
10
7183
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | C++17 / 수정 | 2020 KB | 0 ms | 645 B | 2년 전 |
