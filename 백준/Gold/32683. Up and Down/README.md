# [32683. Up and Down](https://www.acmicpc.net/problem/32683)

## 문제
Given a sequence of integers with length $N$, find the maximum length of a subsequence that strictly increases and then strictly decreases; the last position of strictly increasing must coincide with the first position of strictly decreasing. A subsequence can be obtained from a sequence by removing some or no elements from the sequence without changing the order of the remaining elements.


For this problem, the length of the strictly increasing subsequence and the length of the strictly decreasing subsequence should be at least 2.  In particular, an empty subsequence or a subsequence of length 1 
DOES NOT
 strictly increase nor does it strictly decrease.  See the examples below for further illustration.


Some examples:




7 neither strictly increases nor strictly decreases;


1 1 1 neither strictly increases nor strictly decreases;


1 1 2 neither strictly increases nor strictly decreases;


1 2 7 strictly increases; it does not strictly decrease;


3 2 1 strictly decreases; it does not strictly increase;


8 9 3 strictly increases and then strictly decreases; this is the type of subsequence your solution needs to find.

## 예제 입력 1
```
1
7
1 2 3 4 5 6 7
```

## 예제 출력 1
```
0
```

## 예제 입력 2
```
1
6
1 2 3 3 2 1
```

## 예제 출력 2
```
5
```

## 예제 입력 3
```
1
8
1 11 2 10 4 5 2 1
```

## 예제 출력 3
```
6
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 1 | C++17 / 수정 | 4376 KB | 44 ms | 750 B | 1년 전 |
