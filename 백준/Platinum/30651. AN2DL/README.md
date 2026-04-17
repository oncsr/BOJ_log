# [30651. AN2DL](https://www.acmicpc.net/problem/30651)

## 문제
While wandering around Building 21, you came across a wall completely covered with numbers, arranged in a table of n rows and m columns. Soon you noticed that there was a frame leaning against the wall large enough to frame r rows and s columns of the table on the wall. And next to the frame you found a pencil and a piece of paper containing an empty table.


You are sad that the table on the piece of paper is empty, so you decided to play around with the frame to fill it.


You leaned the frame against the wall so that the number in the i-th row and j-th column is in the upper left corner, and the borders of the frame are parallel to the edges of the wall. Considering the numbers inside the frame, and since you like large numbers, you have decided to write the largest among them in the i-th row and j-th column of the table on the piece of paper.


You repeated the process for every possible position of the frame on the wall (such that the frame is entirely on the wall, and that there are exactly r × s numbers inside it), making sure that the edges of the frame are parallel to the edges of the wall.


When you were done, the table on the piece of paper was even more beautiful than the one on the wall. What numbers are in the table on the piece of paper?

## 예제 입력 1
```
3 3
1 1 2
2 3 4
4 3 2
3 3
```

## 예제 출력 1
```
4
```

## 예제 입력 2
```
3 3
1 1 2
2 3 4
4 3 2
2 1
```

## 예제 출력 2
```
2 3 4
4 3 4
```

## 예제 입력 3
```
5 5
-1 -3 -4 -2 4
-8 -7 -9 -10 11
5 2 -8 -2 1
13 -3 -2 -6 -9
11 6 2 7 4
2 3
```

## 예제 출력 3
```
-1 -2 11
5 2 11
13 2 1
13 7 7
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 3 | C++17 / 수정 | 101800 KB | 2252 ms | 1019 B | 2년 전 |
