# [9299. Math Tutoring](https://www.acmicpc.net/problem/9299)

## 문제
You are helping a friend with the rule for taking the derivative of a polynomial, but he just can’t seem to get it! You’ve gone over many examples, and finally you decide to just write a program to compute the derivatives for him.


Recall that a polynomial of the form:


a
n
x
n
 + a
n−1
x
n−1
 + . . . + a
2
x
2
 + a
1
x + a
0


has as its derivative:


na
n
x
n−1
 + (n − 1)a
n−1
x
n−2
 + . . . + 2a
2
x + a
1


For example, the derivative of 2x
3
 − x + 3 is 6x
2
 − 1. Likewise, the derivatave of 3x
4
 + 2x
3
 + 7x
2
 + 5x + 7 is 12x
3
 + 6x
2
 + 14x + 5.


Given a polynomial, provide the derivative. We are only using polynomials of the form presented here.

## 예제 입력 1
```
4
3 2 0 -1 3
4 3 2 7 5 7
5 6 5 4 3 2 1
1 5 10
```

## 예제 출력 1
```
Case 1: 2 6 0 -1
Case 2: 3 12 6 14 5
Case 3: 4 30 20 12 6 2
Case 4: 0 5
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 2 | C++17 / 수정 | 2020 KB | 8 ms | 302 B | 3년 전 |
