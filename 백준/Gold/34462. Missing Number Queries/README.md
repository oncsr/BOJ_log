# [34462. Missing Number Queries](https://www.acmicpc.net/problem/34462)

## 문제
Busy Beaver has an array of positive integers $a_1, \dots, a_N$, consisting of positive integers at most $N$. He needs to perform $Q$ operations on the array of two types:




1
 $x$ $y$: Set $a_x \leftarrow y$.


2
 $l$ $r$: Output 
any
 integer in the range $[1, N]$ that is 
not
 found in $a_l, a_{l+1}, \dots, a_r$.




Help answer all of Busy Beaver's queries! The input will be generated in such a way that an answer exists for all type 
2
 queries.

## 예제 입력 1
```
5 4
3 5 2 1 5
2 1 5
1 4 4
1 3 1
2 3 5
```

## 예제 출력 1
```
4
2
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | Java 11 / 수정 | 125380 KB | 1068 ms | 1903 B | 6달 전 |
