# [26114. SubsetMex](https://www.acmicpc.net/problem/26114)

## 문제
A multiset is a collection of elements similar to a set, where elements can repeat multiple times. For example, the following is a multiset:


{0, 0, 1, 2, 2, 5, 5, 5, 8}


Given a multiset S defined on non-negative integers, and a target non-negative integer value n such that n does not belong to S, your goal is to insert n into S by using the following 3-step operation, repeatedly:




Choose a (possibly empty) subset T of S. Here, T is a set of distinct numbers that appear in S.


Erase elements of T from S. (Remove only one copy of each element.)


Insert mex(T) into S, where mex(T) is the smallest non-negative integer that does not belong to T. The name mex stands for “minimum excluded” value.




Your goal is to find the minimum number of operations to perform so that n becomes part of S.


Since the size of S may be large, it will be given in the form of a list (f
0
, …, f
n−1
) of size n, where fi represents the number of times that the number i appears in S. (Recall that n is the integer we are trying to insert into S.)

## 예제 입력 1
```
2
4
0 3 0 3
5
4 1 0 2 0
```

## 예제 출력 1
```
4
10
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 4 | C++17 / 수정 | 2020 KB | 0 ms | 533 B | 1년 전 |
