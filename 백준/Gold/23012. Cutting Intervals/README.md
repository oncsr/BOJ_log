# [23012. Cutting Intervals](https://www.acmicpc.net/problem/23012)

## 문제
You are given N intervals. An interval can be represented by two positive integers L
i
 and R
i
 - the interval starts at L
i
 and ends at R
i
, represented as [L
i
,R
i
]. Intervals may not be unique, so there might be multiple intervals with both equal L
i
 and equal R
i
.


You are allowed to perform a maximum of C cuts. A cut at X will cut all intervals [L,R] for which L<X and X<R. Cutting an interval at X is defined as splitting the interval into two intervals - [L,X] and [X,R]. Note that cuts can only be performed at integer points. Also, cutting at an endpoint of an interval (X=L or X=R) has no effect and does not split the interval.


You need to find the maximum number of intervals that can be obtained through a maximum of C cuts.

## 예제 입력 1
```
1
3 3
1 3
2 4
1 4
```

## 예제 출력 1
```
Case #1: 7
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 2 | C++17 / 수정 | 12272 KB | 9312 ms | 1032 B | 2년 전 |
