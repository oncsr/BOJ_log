# [27487. One and Two](https://www.acmicpc.net/problem/27487)

## 문제
You are given a sequence $a_1, a_2, \ldots, a_n$. Each element of $a$ is $1$ or $2$.


Find out if an integer $k$ exists so that the following conditions are met.




$1 \leq k \leq n-1$, and


$a_1 \cdot a_2 \cdot \ldots \cdot a_k = a_{k+1} \cdot a_{k+2} \cdot \ldots \cdot a_n$.




If there exist multiple $k$ that satisfy the given condition, print the smallest.

## 예제 입력 1
```
3
6
2 2 1 2 1 2
3
1 2 1
4
1 1 1 1
```

## 예제 출력 1
```
2
-1
1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 2 | C++17 / 수정 | 2020 KB | 8 ms | 490 B | 2년 전 |
