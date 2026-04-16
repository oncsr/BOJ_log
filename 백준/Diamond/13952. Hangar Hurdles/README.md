# [13952. Hangar Hurdles](https://www.acmicpc.net/problem/13952)

## 문제
You are evaluating constructions plans for a giant new hangar that will house an airplane assembly line. The hangar floor can be represented as a rectangular grid consisting of n rows and n columns where every cell is either empty or blocked. The rows are numbered with integers 1 through n top to bottom, while the columns are numbered with integers 1 through n left to right.


It is important that large crates containing airplane parts can be freely moved between various locations inside the hangar. We can model a crate as a square aligned with grid cells and centered in one of the cells. Therefore, for an odd integer k, a crate of size k consists of cells in k consecutive rows and k consecutive columns. The crate can be moved up, down, left or right as long as it fits completely inside the grid and never contains a blocked cell.


You are given q pairs of cells A
k
 and B
k
 . For each pair, find the size of the largest crate that can be centered in A
k
 and then moved across the hangar floor until it’s centered in B
k
 .

## 예제 입력 1
```
7
.....#.
...#.#.
....#..
....###
....#..
#......
.......
5
2 5 5 2
2 5 3 6
2 2 6 3
2 2 6 6
1 1 7 7
```

## 예제 출력 1
```
1
0
3
1
1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 5 | C++17 / 수정 | 317776 KB | 1596 ms | 2816 B | 4달 전 |
