# [28176. Maximum GCD](https://www.acmicpc.net/problem/28176)

## 문제
Grammy has an array of length $n$. She recently learned about the concept of greatest common divisor(GCD). Recall that the GCD of an array is the maximum integer $d$ such that every element in the array is divisible by $d$. Grammy thinks that the GCD of an array should be as large as possible so that the array can be beautiful. 


You want to help Grammy to make her array beautiful, so you decided to do some (possibly zero) modulo operations on each of the elements in the array. In other words, for each operation, you can choose a number $a_i$ ($1 \leq i \leq n$) in the array and choose another integer $x$, and then replace $a_i$ with $(a_i\bmod x)$. Since Grammy does not want $0$ to appear in her array, you cannot change $a_i$ into $0$ by doing the modulo operation. 


Now, your task is to calculate the maximum GCD of the array after several (possibly zero) modulo operations.

## 예제 입력 1
```
3
3 10 7
```

## 예제 출력 1
```
3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 1 | C++17 / 수정 | 2292 KB | 16 ms | 496 B | 2년 전 |
