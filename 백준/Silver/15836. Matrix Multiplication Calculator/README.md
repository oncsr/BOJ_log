# [15836. Matrix Multiplication Calculator](https://www.acmicpc.net/problem/15836)

## 문제
Matrix multiplication is a basic tool of linear algebra, and has numerous applications in many areas of mathematics, as well as in applied mathematics, computer graphics, physics, and engineering.


We can only multiply two matrices if their dimensions are compatible, which means the number of columns in the first matrix is the same as the number of rows in the second matrix.


If A = [a
ij
] is an m×n matrix and B = [b
ij
] is an n×q matrix, the product AB is an m×q matrix. The product AB is defined to be the m×q matrix C = [c
ij
] such that


\[c_{ij} = \sum_{k=1}^{n}{a_{ik}b_{kj}\]


Your task is to design a matrix multiplication calculator to multiply two matrices and display the output. If the matrices cannot be multiplied, display "undefined"

## 예제 입력 1
```
2 3 3 2
1 2 3
3 2 1
4 5
6 7
8 9
2 3 2 3
1 2 3
3 2 1
4 5 6
7 8 9
0 0 0 0
```

## 예제 출력 1
```
Case #1:
| 40 46 |
| 32 38 |
Case #2:
undefined
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 5 | C++17 / 수정 | 2020 KB | 0 ms | 676 B | 3년 전 |
