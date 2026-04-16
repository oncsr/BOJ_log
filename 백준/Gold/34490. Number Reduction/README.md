# [34490. Number Reduction](https://www.acmicpc.net/problem/34490)

## 문제
Busy Beaver is given a positive integer $k$ ($1 \le k \le 10^{18}$) written in base $10$. Then, he repeatedly performs the following operation:


Choose a digit in $k$ that is greater than $1$. If $k$ is divisible by that digit, divide $k$ by that digit. Repeat this process on the resulting number until either $1$ is reached or there are no more legal operations. Call $k$ 
valid
 if there exists a way to reduce it to $1$ via this operation.


Compute the number of $k$ in the range $1, \dots, N$ that are valid.

## 예제 입력 1
```
9
```

## 예제 출력 1
```
9
```

## 예제 입력 2
```
13
```

## 예제 출력 2
```
10
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 2 | Java 11 / 수정 | 49588 KB | 436 ms | 1679 B | 6달 전 |
