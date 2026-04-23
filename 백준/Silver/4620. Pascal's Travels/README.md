# [4620. Pascal's Travels](https://www.acmicpc.net/problem/4620)

## 문제
An n x n game board is populated with integers, one nonnegative integer per square. The goal is to travel along any legitimate path from the upper left corner to the lower right corner of the board. The integer in any one square dictates how large a step away from that location must be. If the step size would advance travel off the game board, then a step in that particular direction is forbidden. All steps must be either to the right or toward the bottom. Note that a 0 is a dead end which prevents any further progress.


Consider the 4 x 4 board shown in Figure 1, where the solid circle identifies the start position and the dashed circle identifies the target. Figure 2 shows the three paths from the start to the target, with the irrelevant numbers in each removed.




Figure 1




Figure 2

## 예제 입력 1
```
4
2331
1213
1231
3110
4
3332
1213
1232
2120
5
11101
01111
11111
11101
11101
-1
```

## 예제 출력 1
```
3
0
7
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 1 | C++17 / 수정 | 2024 KB | 0 ms | 563 B | 3년 전 |
