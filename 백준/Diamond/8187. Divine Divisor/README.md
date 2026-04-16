# [8187. Divine Divisor](https://www.acmicpc.net/problem/8187)

## 문제
An integer N > 1 is given. We say that an integer d > 1 is a divisor of N with multiplicity k > 0 (k is integer) if d^k | N and d^(k+1) does not divide N. For example, the number N=48=16x3 has the following divisors: 2 with multiplicity 4, 3 with multiplicity 1, 4 with multiplicity 2, 6 with multiplicity 1, and so on.


We say that a number  is a divine divisor of the number N if d is a divisor of N with multiplicity k and N has no divisors with multiplicities greater than k. For example, the sole divine divisor of 48 is 2 (with multiplicity 4), and the divine divisors of 6 are: 2, 3 and 6 (each with multiplicity 1).


Your task is to determine the multiplicity of divine divisors of N and the number of its divine divisors.

## 예제 입력 1
```
3
4 3 4
```

## 예제 출력 1
```
4
1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 5 | PyPy3 / 수정 | 117240 KB | 5056 ms | 2161 B | 3달 전 |
