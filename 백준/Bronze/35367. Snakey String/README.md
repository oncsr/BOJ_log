# [35367. Snakey String](https://www.acmicpc.net/problem/35367)

## 문제
A 
snakey string
 is a fancy rendering of an otherwise normal string of text. When a string is made snakey, it is placed on a 2D grid such that the following conditions are met:




The first character of the string is on the first column of the grid, the second on the second column, …, and the last on the last column.


Each character in the string occupies either the row directly above or directly below the row of the previous character.






Figure 1
: The snakey string in the sample case.


Given a snakey string, can you recover the original string?

## 예제 입력 1
```
4 8
..G.....
.I.S.U..
B...O.T.
.......H
```

## 예제 출력 1
```
BIGSOUTH
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 3 | C++17 / 수정 | 2032 KB | 0 ms | 334 B | 1달 전 |
