# [30155. Crazy Malvika discovers Crazy Fibonacci function](https://www.acmicpc.net/problem/30155)

## 문제
Malvika was getting bored of the usual Fibonacci problems, and decided to add a little twist to it. She defined a new function f() with the following properties:




She'll give you two integers, A and B. f(1) is defined to be A and f(2) is B.


And for all integers x ≥ 2, f(x) = f(x-1) + f(x+1).




She'll give an integer N, and you have to find out what f(N) is. Output the answers modulo 10
9
+7.

## 예제 입력 1
```
2
10 17 3
23 17 3
```

## 예제 출력 1
```
7
1000000001
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 3 | C++17 / 수정 | 2020 KB | 52 ms | 303 B | 2년 전 |
