# [28152. Power of Divisors](https://www.acmicpc.net/problem/28152)

## 문제
Consider a positive integer $n$. Let $f(n)$ be the number of positive integer divisors of $n$. For example, if $n=8$ then $f(n)=4$, since the divisors of $8$ are $1$, $2$, $4$ and $8$.


Now, consider a positive integer $x$. What is the smallest value of $n$ such that $n^{f(n)}=x$?

## 예제 입력 1
```
15625
```

## 예제 출력 1
```
25
```

## 예제 입력 2
```
64000000
```

## 예제 출력 2
```
20
```

## 예제 입력 3
```
65536
```

## 예제 출력 3
```
-1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 2 | C++17 / 수정 | 9812 KB | 96 ms | 1052 B | 2년 전 |
