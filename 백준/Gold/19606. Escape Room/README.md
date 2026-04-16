# [19606. Escape Room](https://www.acmicpc.net/problem/19606)

## 문제
You have to determine if it is possible to escape from a room. The room is an M-by-N grid with each position (cell) containing a positive integer. The rows are numbered 1, 2, . . . , M and the columns are numbered 1, 2, . . . , N. We use (r, c) to refer to the cell in row r and column c.


You start in the top-left corner at (1, 1) and exit from the bottom-right corner at (M, N). If you are in a cell containing the value x, then you can jump to any cell (a, b) satisfying a × b = x. For example, if you are in a cell containing a 6, you can jump to cell (2, 3).


Note that from a cell containing a 6, there are up to four cells you can jump to: (2, 3), (3, 2), (1, 6), or (6, 1). If the room is a 5-by-6 grid, there isn’t a row 6 so only the first three jumps would be possible.

## 예제 입력 1
```
3
4
3 10 8 14
1 11 12 12
6 2 3 9
```

## 예제 출력 1
```
yes
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 2 | Java 11 / 수정 | 156636 KB | 892 ms | 1801 B | 7달 전 |
