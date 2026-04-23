# [25114. Sequence Conversion](https://www.acmicpc.net/problem/25114)

## 문제
You are given two arrays of non-negative integers $a_1, a_2, \dots, a_N$ and $b_1, b_2, \dots, b_N$.


You can perform the following operation several times:




Choose a non-negative integer $x$ and an index $1 \leq i < N$. Then change $a_i$ to $a_i \oplus x$ and change $a_{i+1}$ to $a_{i+1} \oplus x$.




Expression $x \oplus y$ means 
bitwise xor
 of two numbers $x$ and $y$.

In binary representation, if the $i$-th digit of x and y is equal, then the $i$-th digit of $x \oplus y$ is $0$, and if not, it is $1$.

The given operation exists in all modern programming languages. For example, in 
C++
 and 
Java
, it is represented as $x\ ^{\wedge}\ y$.


You want to convert $\{a_i\}$ to $\{b_i\}$ by performing the minimum number of operations.


Find the minimum number of operations to convert $\{a_i\}$ to $\{b_i\}$.


If you cannot convert $\{a_i\}$ to $\{b_i\}$ with the given operation, print $-1$.

## 예제 입력 1
```
3
1 2 3
3 2 1
```

## 예제 출력 1
```
2
```

## 예제 입력 2
```
3
1 5 3
1 2 3
```

## 예제 출력 2
```
-1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 3 | C++17 / 수정 | 9712 KB | 272 ms | 383 B | 3년 전 |
