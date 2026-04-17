# [31373. Add and Reverse](https://www.acmicpc.net/problem/31373)

## 문제
Consider a non-negative integer $x$ stored in $32$ bits of memory: $$x = b_{31} \cdot 2^{31} + b_{30} \cdot 2^{30} + \ldots + b_{2} \cdot 2^{2} + b_{1} \cdot 2^{1} + b_{0} \cdot 2^{0}$$ where each bit $b_{i}$ can take two values $0$ and $1$ independently of other bits.


We perform a sequence of operations with this integer, possibly an empty one. In one operation, we can either increase the number by one or reverse the bits constituting it: swap $31$-st bit and $0$-th bit, swap $30$-th bit and first bit, $\ldots$, swap $16$-th bit and $15$-th bit. We can perform any number of any of these two operations in any order.


What is the minimum possible number of operations required to transform a zero to the given integer $n$?


The increasing by one is carried out modulo $2^{32}$, which means that, if the current number is equal to $2^{32} - 1$, increasing it by one produces a zero.

## 예제 입력 1
```
5
```

## 예제 출력 1
```
5
```

## 예제 입력 2
```
2147483648
```

## 예제 출력 2
```
2
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 4 | C++17 / 수정 | 2020 KB | 0 ms | 335 B | 2년 전 |
