# [15517. Array Manipulation at Moloco (Hard)](https://www.acmicpc.net/problem/15517)

## 문제
At Moloco, management and analysis of big data is an important part of its core business solution. One day, a very complicated issue was raised by a fellow employee, and you need to help resolve it.


You are given an array 
A
 of 
n
 distinct integers that describe the raw data. You need to manipulate this array to obtain a new array 
S
 of 
n
 integers where 
S
[i] = |{j : (1 ≤ j < 
i
) ∧ (
A
[
j
] < 
A
[
i
])}|. 


For instance, if 
A
 = [10, 5, 12, 1, 11], then 
S
 = [0, 0, 2, 0, 3].

## 예제 입력 1
```
5
10
5
12
1
11
```

## 예제 출력 1
```
0
0
2
0
3
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 5 | C++17 / 수정 | 21812 KB | 768 ms | 910 B | 2년 전 |
