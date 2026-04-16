# [7037. Walk the Talk](https://www.acmicpc.net/problem/7037)

## 문제
Farmer John has set up a puzzle for his cows to solve. At the entrance to the barn, he has laid out an H x W (1 <= H <= 30, 1 <= W <= 30) grid of letters. Before a cow can enter the barn, she must spell out a valid English word by jumping from square to square, creating a sequence of letters. She can start at any square but may only jump to a subsequent square that is located to the right and/or above the current square (i.e., neither to the left nor lower). The next square can be any distance from the current one since the cows are world-class jumpers!


No two cows may traverse the exact same path, although two cows are allowed to spell the same word via different paths.


As an example, consider this grid (presuming 'TO' and 'OX' are words):




T X X O
T X Q T
X T X Q


Four paths are valid, all spelling 'TO' (one spelling requires a 'T' from the bottom row and an 'O' from the top row). 'OX' is a valid word, but would require jumping to an 'X' square left of the 'O', which is not allowed.


Given the grid and a list of valid words, compute the number of cows that can enter the barn without any cow repeating a path. See a copy of the list 
here
.

## 예제 입력 1
```
3 4
TXXO
TXQT
XTXQ
```

## 예제 출력 1
```
4
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | C++17 / 수정 | 2192 KB | 12 ms | 18379 B | 1년 전 |
